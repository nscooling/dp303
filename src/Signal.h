#ifndef SIGNAL_H
#define SIGNAL_H

#include "feabhOS_signal.h"

namespace feabhOS
{
  class Signal
  {
  public:
    Signal();
    ~Signal();
    feabhOS_error wait(duration_mSec_t timeout);
    void          notifyOne();
    void          notifyAll();
  
  private:
    feabhOS_SIGNAL handle;
    
    // not implemented
    Signal(const Signal&);
    Signal& operator=(const Signal&);
  };

} // namespace feabhOS

#endif // SIGNAL_H