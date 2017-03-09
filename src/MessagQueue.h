#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <queue>

#include "Mutex.h"
#include "Signal.h"

using std::queue;

template <typename T, size_t sz>
class MessageQueue : private std::queue<T>
{
public:
  typedef T value_type;

  MessageQueue() : queue<T>(), mutex(), hasData(), hasSpace() {}

  T pull();
  void push(const T& value);
  bool isEmpty();

private:
  feabhOS::Mutex mutex;
  feabhOS::Signal hasData;
  feabhOS::Signal hasSpace;
};

template <typename T, size_t sz>
T MessageQueue<T, sz>::pull()
{
  T value;

  CRITICAL_SECTION(mutex)
  {
    while(queue<T>::empty())
    {
      mutex.unlock();
      hasData.wait(WAIT_FOREVER);
      mutex.lock(WAIT_FOREVER);
    }

    value = queue<T>::front();
    queue<T>::pop();

    hasSpace.notifyAll();
  }
  return value;
}


template <typename T, size_t sz>
void MessageQueue<T, sz>::push(const T& value)
{
  CRITICAL_SECTION(mutex)
  {
    while(queue<T>::size() == sz)
    {
      mutex.unlock();
      hasSpace.wait(WAIT_FOREVER);
      mutex.lock(WAIT_FOREVER);
    }

    queue<T>::push(value);

    hasData.notifyAll();
  }
}


template <typename T, size_t sz>
bool MessageQueue<T, sz>::isEmpty()
{
  bool is_empty;

  CRITICAL_SECTION(mutex)
  {
    // ScopeLock handles the unlocking
    // of the mutex on exit
    //
    is_empty = queue<T>::empty();
  }
  return is_empty;
}

#endif // MESSAGEQUEUE_H
