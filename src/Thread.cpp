// TIPO.cpp
//
// Implementation of Thread-Is-Polymorphic-Object


#include "Thread.h"

namespace feabhOS
{

  Thread::Thread (Priority prio, Stack stackSize) : 
    stack(stackSize),
    priority (prio),
    created(false),
    handle(0)
  { 
  }
  
  
  Thread::~Thread()
  {
    if(created)
    {
      feabhOS_task_destroy(&handle);
    }
  }
  
  
  void Thread::start()
  {
    feabhOS_error error;
    
    error = feabhOS_task_create(&handle, 
                                &Thread::scheduledFunction, 
                                static_cast<void*>(this),
                                stack,
                                priority);
    
    created = (error == ERROR_OK);
  }


  void Thread::join()
  {
    feabhOS_task_join(&handle);
  }
    
  
  int Thread::scheduledFunction(void* threadArg)
  {
    Thread* self = reinterpret_cast<Thread*>(threadArg);
    
    int exitCode = self->run();
    return exitCode;
  }
  
  
  void Thread::sleep(duration_mSec_t period)
  {
    feabhOS_task_sleep(period);
  }
  
  
  void Thread::yield()
  {
    feabhOS_task_yield();
  }
  
} // namespace feabhOS


