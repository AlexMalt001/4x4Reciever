#ifndef load_h
#define load_h

#include "Arduino.h"


  class loader {
  public:
    void modeSet();
    void serialSetup();
};

namespace loadVarStore{
  const int th = 6;
  const int st = 11;
  const int headlightPin = 4;
  const int tiltSense = A0;
  const int lightSense = A1;
}

#endif
