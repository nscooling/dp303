#ifndef MUTEX_H
#define MUTEX_H

#include "feabhOS_mutex.h"


namespace feabhOS
{
  class Mutex
  {
  public:
    Mutex();
    ~Mutex();
    feabhOS_error lock(duration_mSec_t timeout);
    void          unlock();

  private:
    Mutex(const Mutex&);
    Mutex& operator=(const Mutex&);

    // feabhOS-specific implementation
    //
    feabhOS_MUTEX handle;
  };


  // ---------------------------------------------------
  // ScopeLock implements the 
  // scope-locked idiom for 
  // mutexes.
  //
  class ScopeLock
  {
  public:
    ScopeLock(Mutex& mtx) : mutex(mtx) { mutex.lock(WAIT_FOREVER); }
    ~ScopeLock() { mutex.unlock(); }
    operator bool() { return true; }

  private:
    Mutex& mutex;
  };

} // namespace feabhOS  

// Neat little macro to simplify code.
// Requires the ScopeLock class to implement
// operator bool()
//
#define CRITICAL_SECTION(mtx) if(feabhOS::ScopeLock s = mtx)


#endif // MUTEX_H