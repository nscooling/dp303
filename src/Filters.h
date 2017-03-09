#ifndef FILTERS_H
#define FILTERS_H

#include "MessagQueue.h"
#include "Thread.h"

class FilterBase : public feabhOS::IRunnable
{
public:
  typedef MessageQueue<int, 16> queue_type;

  FilterBase() : input(0), output(0) {}

protected:
  queue_type* input;
  queue_type* output;

  friend FilterBase&             operator >>= (FilterBase& filter, FilterBase::queue_type& queue);
  friend FilterBase::queue_type& operator >>= (FilterBase::queue_type& queue, FilterBase& filter);
};


class Generator : public FilterBase
{
public:
  Generator();
  virtual bool run();
};


class LowPass : public FilterBase
{
public:
  LowPass(int filterValue = 10);
  virtual bool run();

private:
  int set_point;
};


class Display : public FilterBase
{
public:
  Display();
  virtual bool run();
};

#endif // FILTERS_H