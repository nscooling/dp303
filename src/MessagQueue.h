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

  mutex.lock(WAIT_FOREVER);

  // Note: we must call the underlying empty()
  // function, not our thread-safe version, to
  // prevent a potential deadlock
  //
  if(queue<T>::empty())
  {
    // We must unlock the mutex, since
    // we are throwing an exception (and
    // leaving the function)
    //
    mutex.unlock();
    throw std::range_error("Queue is empty");
  }

  value = queue<T>::front();
  queue<T>::pop();
  
  mutex.unlock();

  return value;
}


template <typename T, size_t sz>
void MessageQueue<T, sz>::push(const T& value)
{
  mutex.lock(WAIT_FOREVER);

  if(queue<T>::size() == sz)
  {
    // We must unlock the mutex, since
    // we are throwing an exception (and
    // leaving the function)
    //
    mutex.unlock();
    throw std::range_error("Queue limit exceeded");
  }
  queue<T>::push(value);

  mutex.unlock();
}


template <typename T, size_t sz>
bool MessageQueue<T, sz>::isEmpty()
{
  bool is_empty;

  mutex.lock(WAIT_FOREVER);
  is_empty = queue<T>::empty();
  mutex.unlock();

  return is_empty;
}

#endif // MESSAGEQUEUE_H
