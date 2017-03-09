#ifndef CONDITION_H
#define CONDITION_H

#include "Signal.h"

namespace feabhOS
{
  class Mutex;
  
  class Condition
  {
  public:
    Condition();
    ~Condition();
    feabhOS_error wait(Mutex& mutex, duration_mSec_t timeout);
    void notify();
  
  private:
    Signal signal;
    
    // not implemented
    Condition(const Condition&);
    Condition& operator=(const Condition&);
  };
}
#endif