#include "Arduino.h"
#include "SoftwareSerial.h"
#include "myDFRobotDFPlayerMini.h"
#include "myServo.h"

void printDetail(uint8_t type, int value);

#define ledPin (3)

int currentMonoEyeBrightness = 255; //０＝最大輝度、２５５＝最小輝度
int nextMonoEyePower = 255;

void setup()
{
  Serial.begin(115200);
  delay(500);
  setupServo();
  setupDFPlayer();
  pinMode(ledPin,OUTPUT);
  digitalWrite(ledPin,HIGH);
  delay(3000);
}

void loop()
{
  static unsigned long timer = millis();
  myDFPlayer.play(1); // Play the first mp3

  //一度最大輝度まで光らせてから、少し輝度を落とす。
  nextMonoEyePower = 0;
  for(currentMonoEyeBrightness = 255; currentMonoEyeBrightness >= nextMonoEyePower; currentMonoEyeBrightness -=1)
  {
    analogWrite(ledPin, currentMonoEyeBrightness);
    delay(2);
  }
  delay(1000);
  nextMonoEyePower = 200;
  for (currentMonoEyeBrightness = 0; currentMonoEyeBrightness <= nextMonoEyePower; currentMonoEyeBrightness += 1)
  {
    analogWrite(ledPin, currentMonoEyeBrightness);
    delay(2);
  }

  //モノアイを左、右、中央の順で水平移動
  for (posH = centerHPosition; posH <= maxLeftHPosition; posH += 2)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServoH.writeMicroseconds(posH); // tell servo to go to position in variable 'pos'
    delay(1);                         // waits 15ms for the servo to reach the position
  }
  for (posH = maxLeftHPosition; posH >= maxRightHPosition; posH -= 2)
  {                                   // goes from 180 degrees to 0 degrees
    myServoH.writeMicroseconds(posH); // tell servo to go to position in variable 'pos'
    delay(1);                         // waits 15ms for the servo to reach the position
  }

  for (posH = maxRightHPosition; posH <= centerHPosition; posH += 2)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServoH.writeMicroseconds(posH); // tell servo to go to position in variable 'pos'
    delay(1);                         // waits 15ms for the servo to reach the position
  }

  //モノアイを上・下の順で垂直移動
  for (posV = lowVPosition; posV <= highVPosition; posV += 2)
  { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServoV.writeMicroseconds(posV); // tell servo to go to position in variable 'pos'
    delay(1);            // waits 15ms for the servo to reach the position
  }
  for (posV = highVPosition; posV >= lowVPosition; posV -= 2)
  {                      // goes from 180 degrees to 0 degrees
    myServoV.writeMicroseconds(posV);  // tell servo to go to position in variable 'pos'
    delay(1);            // waits 15ms for the servo to reach the position
  }

  //LEDを最小輝度まで落とす
  nextMonoEyePower = 255;
  for (currentMonoEyeBrightness = 0; currentMonoEyeBrightness <= nextMonoEyePower; currentMonoEyeBrightness += 1)
  {
    analogWrite(ledPin, currentMonoEyeBrightness);
    delay(2);
  }
  delay(50);
  digitalWrite(ledPin,HIGH);//analogWriteだとLEDを消しきれないのでdegitalWriteを併用。

  //小休止。
  delay(3000);

}

