#include "Thread.h"
#include "Scheduler.h"

#include <cassert>

namespace feabhOS
{
  Thread::Thread() :
    pRunObject(0),
    handle(0),
    stack(DefaultStack),
    priority(DefaultPriority),
    done(true),
    created(false)
  {
  }


  Thread::Thread(Thread::Priority prio) :
    pRunObject(0),
    handle(0),
    stack(DefaultStack),
    priority(prio),
    done(true),
    created(false)
  {
  }


  Thread::Thread(Thread::Stack stacksize) :
    pRunObject(0),
    handle(0),
    stack(stacksize),
    priority(DefaultPriority),
    done(true),
    created(false)
  {
  }


  Thread::Thread(Thread::Priority prio, Thread::Stack stacksize) :
    pRunObject(0),
    handle(0),
    stack(stacksize),
    priority(prio),
    done(true),
    created(false)
  {
  }


  Thread::~Thread()
  {
    if(created)
    {
      if(!done)
      {
        // TO DO:
        // There should be some error recorded here
        // as we've terminated the thread prematurely - 
        // it's going out of scope, but still running!
        assert(false);
      }
      feabhOS_task_destroy(&handle);
    }
  }


  feabhOS_error Thread::start(IRunnable& obj)
  {
    feabhOS_error error;

    // Check to see if start has already been called on this thread
    // object.  Return an error if this is the case - 
    // otherwise, the original OS thread would be leaked!
    //
    if(created) return ERROR_STUPID;

    pRunObject = &obj;

    error = feabhOS_task_create(&handle,
                                &Thread::scheduledFunction,
                                reinterpret_cast<Thread*>(this),
                                static_cast<feabhOS_stack_size_t>(stack),
                                static_cast<feabhOS_priority_t>(priority));

    created = (error == ERROR_OK);
    return error;
  }
 

  int Thread::scheduledFunction(void* arg)
  {
    Thread* thisThread = (reinterpret_cast<Thread*>(arg));
    thisThread->schedulePolicy();
    return 1;
  }


  void Thread::schedulePolicy()
  {
    do
    {
      done = pRunObject->run();
    } while(!done);
  }


  void Thread::join()
  {
    if(!created)
    {
      // A thread that has not been started is assumed
      // to be finished (that is, already joined)
      //
      return;
    }
    else
    {
      feabhOS_task_join(&handle);
    } 
  }


  void Thread::sleep(duration_mSec_t period)
  {
    feabhOS_task_sleep(period);
  }


  void Thread::yield()
  {
    feabhOS_task_yield();
  }
}

