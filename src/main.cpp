#include "Scheduler.h"
#include "MessagQueue.h"
#include "Filters.h"
#include "feabhOS_task.h"


int main()
{
  feabhOS::Scheduler::init();

  Generator generator;
  LowPass   lowpass(5);
  Display   display;

  bind(generator, lowpass);
  bind(lowpass, display);

  feabhOS::Thread gen_thread;
  feabhOS::Thread lp_thread;
  feabhOS::Thread disp_thread;
  
  gen_thread.start(generator);
  lp_thread.start(lowpass);
  disp_thread.start(display);

  gen_thread.join();
  lp_thread.join();
  disp_thread.join();

  feabhOS::Scheduler::start();
  // ----------------------------
  //  DO NOT PUT ANY CODE HERE!
  // ----------------------------
}
