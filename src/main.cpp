#include <Arduino.h>
#include "load.h"
#include "Servo.h"
#include "serialProcess.h"

Servo steerServo;
//test
loader loader;
using namespace loadVarStore;

#define NO_ARGS 2

String varLabel[NO_ARGS];
String inArray[NO_ARGS];

const int LIGHT_LIMIT = 123;

int st;
int th;

void setup() {
  Serial.begin(9600);
  loader.serialSetup();
  steerServo.attach(6);
  pinMode(11, OUTPUT);
  pinMode(A1, INPUT);
}

void loop() {
  steerServo.write(st);
  analogWrite(th, 11);

  if(analogRead(A1) < LIGHT_LIMIT) {
    digitalWrite(headlightPin, HIGH);
  } else {
    digitalWrite(headlightPin, LOW);
  }
  if ((millis() % 50) == 0) {
    int outArray[4];
    int *outPtr;
    outPtr = &outArray[0];
    dataProcess::collectVars(outPtr);
  }
}

void serialEvent() {
   while (Serial.available()) {
     th = Serial.readStringUntil(',').toInt();
     Serial.read();
     String hurrah = Serial.readStringUntil('\n');
     st = Serial.readStringUntil('\n').toInt();
   }
}
