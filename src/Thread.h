#ifndef THREAD_H
#define THREAD_H

#include "feabhOS_task.h"
#include "feabhOS_time.h"

//-----------------------------------------------------------------
// Thread Abstract Base class.  All working threads must
// inherit from this class and implement the pure virtual
// run() function.
//
namespace feabhOS
{
  class Thread
  {
  public:
    typedef feabhOS_stack_size_t Stack;
    typedef feabhOS_priority_t   Priority;
    
    explicit Thread (Priority prio = PRIORITY_NORMAL, Stack stackSize = STACK_NORMAL);
    virtual ~Thread ();
    
    void start();
    void join();
    
    static void sleep(duration_mSec_t period);
    static void yield();
    
  protected:
    virtual int run() = 0;
    
  private:
    Thread (const Thread&);
    Thread& operator= (const Thread&);
   
    // --------------------------------
    // Thread management data:
    //
    Stack        stack;
    Priority     priority;
    feabhOS_TASK handle;
    // --------------------------------
    
    bool created;
    static int scheduledFunction (void* threadArg);
  };
  
} // namespace feabhOS

#endif // THREAD_H
