#include "Filters.h"
#include <cstdlib>
#include <iostream>
#include <cassert>

using std::rand;
using std::cout;
using std::endl;

FilterBase& operator >>= (FilterBase& filter, FilterBase::queue_type& queue)
{
  filter.output = &queue;
  return filter;
}


FilterBase::queue_type& operator >>= (FilterBase::queue_type& queue, FilterBase& filter)
{
  filter.input = &queue;
  return queue;
}

// --------------------------------------------------------------------------------------
// Generator class
//
Generator::Generator()
{
}


int Generator::run()
{
  assert(output != 0);

  int value = rand() % 10;
  cout << "Generator::run - generating: " << value << endl;
  output->push(value);
  return value;
}


// --------------------------------------------------------------------------------------
// LowPass class
//
LowPass::LowPass(int filterValue) : set_point(filterValue)
{
}


int LowPass::run()
{ 
  assert(input  != 0);
  assert(output != 0);

  if(input->isEmpty()) return -1; // nothing to pull

  int value = input->pull();
  if(value < set_point)
  {
    cout << "Filter::run - PASS: " << value << endl;
    output->push(value);
  }
  else
  {
    cout << "Filter::run - REMOVE: " << value << endl;
  }
  return value;
}


// --------------------------------------------------------------------------------------
// Display class
//
Display::Display()
{
}


int Display::run()
{
  assert(input != 0);

  if(input->isEmpty()) return -1; // nothing to pull

  int value = input->pull();
  {
    cout << "Display::run : " << value << endl;
  }
  return value;
}