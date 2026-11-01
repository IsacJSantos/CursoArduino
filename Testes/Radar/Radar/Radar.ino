#include <HCSR04.h>
#include <Servo.h>
#define led 7

const int max_distance =2;

int pos = 0;
int target = 180;

Servo servo;
UltraSonicDistanceSensor distanceSensor(13, 12);

float distance = 0;
void setup () {
    pinMode(led, OUTPUT);
    servo.attach(11);
    Serial.begin(9600);
}

void loop () {
    distance = distanceSensor.measureDistanceCm();
   
    while(distance > max_distance)
    {
        digitalWrite(led, LOW);
        if(target == 180)
        {
            pos++;
            if(pos >= 180)
            {
                pos = 180;
                target = 0;
            }
        }
        else if(target == 0)
        {
            pos--;
            if(pos <= 0)
            {
                pos = 0;
                target = 180;
            }
        }
        
        servo.write(pos);
        delay(10);

        distance = distanceSensor.measureDistanceCm();
    }

    if(distance <= max_distance)
    {
        digitalWrite(led, HIGH);
        delay(500);
        digitalWrite(led, LOW);
        delay(500);
    }
   else
   {
      digitalWrite(led, LOW);
        delay(500);
   }
}
