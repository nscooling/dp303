#ifndef THREAD_H
#define THREAD_H

#include "feabhOS_task.h"
#include "feabhOS_time.h"

namespace feabhOS
{
  class IRunnable
  {
  public:
    virtual bool run() = 0;
    virtual ~IRunnable() {}
  };


  class Thread
  {
  public:
    enum Priority
    {
      LowestPriority  = PRIORITY_LOWEST,
      LowPriority     = PRIORITY_LOW,
      NormalPriority  = PRIORITY_NORMAL,
      HighPriority    = PRIORITY_HIGH,
      HighestPriority = PRIORITY_HIGHEST,
      DefaultPriority = NormalPriority
    };

    enum Stack
    {
      TinyStack    = STACK_TINY,
      SmallStack   = STACK_SMALL,
      NormalStack  = STACK_NORMAL,
      LargeStack   = STACK_LARGE,
      HugeStack    = STACK_HUGE,
      DefaultStack = NormalStack
    };

    // ----------------------------------------
    // Thread operations.
    //
    Thread();
    Thread(Priority prio);
    Thread(Stack stacksize);
    Thread(Priority prio, Stack stacksize);
    virtual ~Thread();

    feabhOS_error start(IRunnable& obj);
    void join();

    static void sleep(duration_mSec_t period);
    static void yield();

  private:
    // ---------------------------------------------------------------
    // This function is in the form required by
    // FeabhOS for thread creation.
    //
    static int scheduledFunction(void* arg);
    virtual void schedulePolicy();

    // ---------------------------------------------------------------
    // Disable copying
    Thread(const Thread&);
    Thread& operator= (const Thread&);

    // ---------------------------------------------------------------
    // The object to be run
    //
    IRunnable* pRunObject;

    // ---------------------------------------------------------------
    // Thread management data:
    //
    feabhOS_TASK handle;
    Stack        stack;
    Priority     priority;
    bool         done;
    bool         created;
    // ---------------------------------------------------------------
  };
}

//////////////////////////////////////////////////////////////////////////////////////////////////

namespace no_feabhOS
{
  class IRunnable
  {
  public:
    virtual bool run() = 0;
    virtual ~IRunnable() {}
  };


  class Thread
  {
  public:
    enum Priority
    {
      LowestPriority = PRIORITY_LOWEST,
      LowPriority = PRIORITY_LOW,
      NormalPriority = PRIORITY_NORMAL,
      HighPriority = PRIORITY_HIGH,
      HighestPriority = PRIORITY_HIGHEST,
      DefaultPriority = NormalPriority
    };

    enum Stack
    {
      TinyStack = STACK_TINY,
      SmallStack = STACK_SMALL,
      NormalStack = STACK_NORMAL,
      LargeStack = STACK_LARGE,
      HugeStack = STACK_HUGE,
      DefaultStack = NormalStack
    };

    // ----------------------------------------
    // Thread operations.
    //
    Thread();
    Thread(Priority prio);
    Thread(Stack stacksize);
    Thread(Priority prio, Stack stacksize);
    virtual ~Thread();

    feabhOS_error start(IRunnable& obj);
    void join();

    static void sleep(duration_mSec_t period);
    static void yield();

  private:
    // ---------------------------------------------------------------
    // Disable copying
    Thread(const Thread&);
    Thread& operator= (const Thread&);
  };
}

#endif // THREAD_H
