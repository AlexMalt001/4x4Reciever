
#include "Arduino.h"
#include "serialProcess.h"


void serialProcess :: sendVars(int *arrayPtr) {
  int sendArray[3];
  for (int i = 0; i < 3; i++) {
    sendArray[i] = *(arrayPtr+i);
  }

  String sendString;
  for (int i = 0; i < 2; i++) {
    sendString = (sendString + sendArray[i] + ",");
  }
  Serial.println(sendString);
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
  bool tempBool;
  if(digitalRead(A0) == HIGH) {
    tempBool = 1;
  } else {
    tempBool = 0;
  }
  *arrayPtr = tempBool;
  *(arrayPtr+1) = analogRead(A1);
  *(arrayPtr+2) = 2;
  *(arrayPtr+3) = 2;
}
