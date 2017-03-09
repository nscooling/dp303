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
  
} // namespace feabhOS  

#endif // MUTEX_H