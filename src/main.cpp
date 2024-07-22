#include <Arduino.h>
#include <blink.h>
#include <blendColor.h>

void setup()
{
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  Serial.begin(9600);
  Serial.println("Hello from setup");
}

void loop()
{
  Serial.println("Hello from loop");
  blink(33, 1000);
  blink(25, 1000);
  blink(26, 1000);

  blinkCustom(33, 25, 26, 255, 255, 255); // white
  blinkCustom(33, 25, 26, 170, 0, 255);   // purple
  blinkCustom(33, 25, 26, 0, 255, 255);
  analogWrite(32, 0);
  analogWrite(25, 0);
  analogWrite(26, 0);
  delay(5000);
  analogWrite(26, 1);
}
