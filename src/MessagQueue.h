#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include <queue>
#include <exception>
#include <stdexcept>

using std::queue;

template <typename T, size_t sz>
class MessageQueue : private std::queue<T>
{
public:
  typedef T value_type;

  MessageQueue() : queue<T>() {}

  T pull();
  void push(const T& value);
  bool isEmpty();
};


template <typename T, size_t sz>
T MessageQueue<T, sz>::pull()
{
  T value;
  
  if(queue<T>::empty())
  {
    throw std::range_error("Message queue is empty");
  }

  value = queue<T>::front();
  queue<T>::pop();
 
  return value;
}


template <typename T, size_t sz>
void MessageQueue<T, sz>::push(const T& value)
{
  if(queue<T>::size() == sz)
  {
    throw std::range_error("Message queue is full");
  }

  queue<T>::push(value);
}


template <typename T, size_t sz>
bool MessageQueue<T, sz>::isEmpty()
{
  return queue<T>::empty();
}

#endif // MESSAGEQUEUE_H
