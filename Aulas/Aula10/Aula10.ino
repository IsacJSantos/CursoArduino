#define an5 A5
#define led 6

int value;

void setup() 
{
  pinMode(an5, INPUT);
  pinMode(led, OUTPUT);
    
    
  Serial.begin(9600);
}

void loop() 
{
  value = map(analogRead(an5), 0, 1023, 0, 255);
  
  analogWrite(led,value);
  Serial.println(value);
  delay(100);
}

