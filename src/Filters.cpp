#include "Filters.h"
#include <cstdlib>
#include <iostream>
#include <cassert>

using std::rand;
using std::cout;
using std::endl;


// --------------------------------------------------------------------------------------
// Generator class
//
Generator::Generator() : lowPass(0)
{
}


bool Generator::run()
{
  int value;

  value = rand() % 10;
  cout << "Generator::run - generating: " << value << endl;
  
  // Make asynchronous call to LowPass
  //
  if(lowPass != 0)
  {
    lowPass->process(value);
  }

  feabhOS::Thread::sleep(1000);

  return false;
}


void bind(Generator& g, LowPass& lp)
{
  g.lowPass = &lp;
}

// --------------------------------------------------------------------------------------
// LowPass class
//
LowPass::LowPass(int filterValue) : set_point(filterValue), display(0)
{
}


bool LowPass::run()
{
  CallFrame dispatch = msgQ.pull();
  (this->*dispatch.call)(dispatch.arg);
  return false;
}


void LowPass::process(int value)
{
  msgQ.push(CallFrame(&LowPass::process_impl, value));
}


void LowPass::process_impl(int value)
{
  if(value < set_point)
  {
    cout << "Filter::run - PASS: " << value << endl;
    display->show(value);
  }
  else
  {
    cout << "Filter::run - REMOVE: " << value << endl;
  }
}


void bind(LowPass& lp, Display& disp)
{
  lp.display = &disp;
}


// --------------------------------------------------------------------------------------
// Display class
//
Display::Display()
{
}


bool Display::run()
{
  CallFrame dispatch = msgQ.pull();
  (this->*dispatch.call)(dispatch.arg);
  return false;
}


void Display::show(int value)
{
  msgQ.push(CallFrame(&Display::show_impl, value));
}


void Display::show_impl(int value)
{
  cout << "Display::run : " << value << endl;
}