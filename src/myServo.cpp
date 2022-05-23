#include "myservo.h"

Servo myServoH;
Servo myServoV;

#define servoHPin (9)
#define servoVPin (8)

int posH = centerHPosition;
int newHAngle = centerHPosition;

int posV = lowVPosition;
int newVAngle = lowVPosition;

void setupServo()
{
    myServoH.attach(servoHPin);
    myServoV.attach(servoVPin);

    myServoH.writeMicroseconds(centerHPosition);
    delay(100);
    myServoV.writeMicroseconds(lowVPosition);
    delay(100);

    Serial.println("Done setupServo");
}