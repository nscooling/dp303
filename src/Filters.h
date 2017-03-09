#ifndef FILTERS_H
#define FILTERS_H

#include "MessagQueue.h"

class FilterBase
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
  int run();
};


class LowPass : public FilterBase
{
public:
  LowPass(int filterValue = 10);
  int run();

private:
  int set_point;
};


class Display : public FilterBase
{
public:
  Display();
  int run();
};

#endif // FILTERS_H