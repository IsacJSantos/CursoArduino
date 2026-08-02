#define pot A5
#define led1 11
#define led2 10
#define led3 9

int potValue;

void setup() 
{
  pinMode(pot, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  
  Serial.begin(9600);
}

void loop() 
{
  potValue = map(analogRead(pot), 0, 1023, 0, 255);

  analogWrite(led1, map(potValue > 85? 85: potValue,0,85,0,255));
  analogWrite(led2, map(potValue > 170? 170: potValue,0,170,0,255));
  analogWrite(led3, potValue);

  Serial.println(potValue);
  delay(100);
}