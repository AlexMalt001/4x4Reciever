#include <Arduino.h>
#include "load.h"
#include "Servo.h"
#include "serialProcess.h"

Servo steerServo;

loader loader;
using namespace loadVarStore;

#define NO_ARGS 2

String varLabel[NO_ARGS];
String inArray[NO_ARGS];

const int LIGHT_LIMIT = 123;

int thVar;
int stVar;

void setup() {
  loader.serialSetup();
  loader.modeSet();
  steerServo.attach(st);
}

void loop() {
  steerServo.write(stVar);
  analogWrite(thVar, th);

  if(analogRead(A1) < LIGHT_LIMIT) {
    digitalWrite(headlightPin, HIGH);
  } else {
    digitalWrite(headlightPin, LOW);
  }

  if ((millis() % 50) == 0) {
    int outArray[3];
    int *outPtr;
    outPtr = &outArray[0];
    dataProcess::collectVars(outPtr);
    serialProcess::sendVars(outPtr);
    }

}

void serialEvent() {
   while (Serial.available()) {
     stVar = Serial.readStringUntil(',').toInt();
     Serial.read();
     thVar = Serial.readStringUntil('\n').toInt();
   }
}
