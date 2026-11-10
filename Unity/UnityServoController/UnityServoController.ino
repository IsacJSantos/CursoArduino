#include <Servo.h>

#define servoPin 4

Servo servo;
String receivedMessage;
int receivedAngle = 0;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  if(Serial.available()){
    receivedMessage = Serial.readStringUntil('\n');
    receivedAngle = receivedMessage.toInt();
    Serial.println(receivedAngle);
  }
}
