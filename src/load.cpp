
#include "Arduino.h"
#include "load.h"

using namespace loadVarStore;

void loader :: modeSet() {
  pinMode(throttle, OUTPUT);
  pinMode(steerPin, OUTPUT);
  pinMode(headlightPin, OUTPUT);
}

void loader :: serialSetup() {
  Serial.begin(9600);
}


