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

  feabhOS_error error;
  feabhOS_TASK  gen_task;
  feabhOS_TASK  lp_task;
  feabhOS_TASK  disp_task;

  error = feabhOS_task_create(&gen_task,
                              &generator_run,
                              &generator,
                              STACK_NORMAL,
                              PRIORITY_NORMAL);
  assert(error == ERROR_OK);


  error = feabhOS_task_create(&lp_task,
                              &lowpass_run,
                              &lowpass,
                              STACK_NORMAL,
                              PRIORITY_NORMAL);
  assert(error == ERROR_OK);


  error = feabhOS_task_create(&disp_task,
                              &display_run,
                              &display,
                              STACK_NORMAL,
                              PRIORITY_NORMAL);
  assert(error == ERROR_OK);

  feabhOS::Scheduler::start();
  // ----------------------------
  //  DO NOT PUT ANY CODE HERE!
  // ----------------------------
}