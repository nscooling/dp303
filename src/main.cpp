#include "Scheduler.h"
#include <iostream>

int main()
{
  feabhOS::Scheduler::init();

  std::cout << "hello world" << std::endl;


  feabhOS::Scheduler::start();
  // ----------------------------
  //  DO NOT PUT ANY CODE HERE!
  // ----------------------------
}
