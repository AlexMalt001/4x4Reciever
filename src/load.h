#ifndef load_h
#define load_h

#include "Arduino.h"

  
  class loader {
  public:
    void modeSet();
    void serialSetup();
};

namespace loadVarStore{
  const int throttle = A0;
  const int steerPin = A1;
  const int headlightPin = 4;
}

#endif
