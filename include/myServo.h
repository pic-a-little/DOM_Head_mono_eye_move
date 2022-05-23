#pragma once

#include <Arduino.h>
#include <Servo.h>

#define centerHPosition ((544 + 2400) / 2)
#define maxRightHPosition (centerHPosition - 300)
#define maxLeftHPosition (centerHPosition + 300)

#define lowVPosition (1600)
#define highVPosition (2400)

// writeMicroseconds()     default min is 544, max is 2400

extern Servo myServoH;
extern int posH;
extern int servoHPin;
extern int newHAngle;

extern Servo myServoV;
extern int posV;
extern int servoVPin;     
extern int newVAngle;

extern void setupServo();