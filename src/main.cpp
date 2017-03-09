#include "Scheduler.h"
#include "MessagQueue.h"
#include "Filters.h"
#include "feabhOS_task.h"

#include <iostream>
#include <cassert>

int generator_run(void* arg)
{
  Generator* gen = reinterpret_cast<Generator*>(arg);
  while(true)
  {
    gen->run();
    feabhOS_task_sleep(1000);
  }
  return 1;
}


int lowpass_run(void* arg)
{
  LowPass* lp = reinterpret_cast<LowPass*>(arg);
  while(true)
  {
    lp->run();
  }
  return 1;
}


int display_run(void* arg)
{
  Display* disp = reinterpret_cast<Display*>(arg);
  while(true)
  {
    disp->run();
  }
  return 1;
}


int main()
{
  feabhOS::Scheduler::init();

  Generator generator;
  LowPass   lowpass(5);
  Display   display;

  FilterBase::queue_type pipe1;
  FilterBase::queue_type pipe2;

  generator >>= pipe1 >>= lowpass >>= pipe2 >>= display;

  generator.start();
  lowpass.start();
  display.start();

  generator.join();
  lowpass.join();
  display.join();

  feabhOS::Scheduler::start();
  // ----------------------------
  //  DO NOT PUT ANY CODE HERE!
  // ----------------------------
}