#include "Scheduler.h"
#include "MessagQueue.h"
#include "Filters.h"

#include <iostream>

int main()
{
  feabhOS::Scheduler::init();

  Generator generator;
  LowPass   lowpass(5);
  Display   display;

  FilterBase::queue_type pipe1;
  FilterBase::queue_type pipe2;

  generator >>= pipe1 >>= lowpass >>= pipe2 >>= display;

  while(true)
  {
    generator.run();
    lowpass.run();
    display.run();
  }

  feabhOS::Scheduler::start();
  // ----------------------------
  //  DO NOT PUT ANY CODE HERE!
  // ----------------------------
}