
#include "Arduino.h"
#include "serialProcess.h"


void serialProcess :: sendVars(int *arrayPtr) {

}

int dataProcess :: processVars(int input, int upper, int lower, int deadzone, int upperPWM, int lowerPWM) {
  int range = upper - lower;
  int presult = input - lower;
  int presult2 = (presult*100) / (range);
  Serial.println(presult2);
  int result = (presult*(upperPWM-lowerPWM))+lowerPWM;
  return result;
}

void dataProcess :: collectVars(int *arrayPtr) {

}
