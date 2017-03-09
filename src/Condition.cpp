#include "Condition.h"
#include "Mutex.h"
#include "Signal.h"

namespace feabhOS
{
  Condition::Condition() :
    signal()
  {
  }
  
  feabhOS_error Condition::wait(Mutex& mutex, duration_mSec_t timeout)
  {
    feabhOS_error err;
    mutex.unlock();
    err = signal.wait(timeout);
    mutex.lock(WAIT_FOREVER);
    return err;
  }
  
  void Condition::notify()
  {
    signal.notifyAll();
  }
  
  Condition::~Condition()
  {
  }
} // namespace feabhOS