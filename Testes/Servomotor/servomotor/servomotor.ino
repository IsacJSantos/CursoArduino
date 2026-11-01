#include <Servo.h>

#define pot A1
#define servoPort 2

Servo servo;
int potValue = 0;

void setup()
{
  servo.attach(servoPort);
  pinMode(pot, INPUT);
  Serial.begin(9600);
}

void loop()
{
  potValue = map(analogRead(pot),0,1023,0,180);
  Serial.println(potValue);
  servo.write(potValue);
  delay(100);
}