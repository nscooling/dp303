#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <queue>
#include <limits>
#include <exception>
#include <stdexcept>

#include "Mutex.h"

using std::queue;

template <typename T, size_t sz>
class MessageQueue : private std::queue<T>
{
public:
  typedef T value_type;

  MessageQueue() : queue<T>(), mutex() {}

  T pull();
  void push(const T& value);
  bool isEmpty();

private:
  feabhOS::Mutex mutex;
};

template <typename T, size_t sz>
T MessageQueue<T, sz>::pull()
{
  T value;

  CRITICAL_SECTION(mutex)
  {
    if(queue<T>::empty())
    {
      // Mutex is unlocked by ScopeLock if exception
      // if thrown
      //
      throw std::out_of_range("Queue limit exceeded");
    }

    value = queue<T>::front();
    queue<T>::pop();
  }
  return value;
}


template <typename T, size_t sz>
void MessageQueue<T, sz>::push(const T& value)
{
  CRITICAL_SECTION(mutex)
  {
    if(queue<T>::size() == sz)
    {
      throw std::out_of_range("Queue limit exceeded");
    }
    queue<T>::push(value);
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
