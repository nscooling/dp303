#include "Mutex.h"

namespace feabhOS
{
  Mutex::Mutex() : handle(0)
  {
    feabhOS_error err;
    err = feabhOS_mutex_create(&handle);
    if(err != ERROR_OK)
    {
      // What to do here?
    }
  }
  
  
  feabhOS_error Mutex::lock(duration_mSec_t timeout)
  {
    return feabhOS_mutex_lock(&handle, timeout);
  }
  
  
  void Mutex::unlock()
  {
    feabhOS_mutex_unlock(&handle);
  }
  
  
  Mutex::~Mutex()
  {
    feabhOS_mutex_destroy(&handle);
  }

} // namespace feabhOS