#define ldr A0
#define led 6

int vldr = 0;

void setup() 
{
	pinMode(ldr, INPUT);
	pinMode(led, OUTPUT);
  
	Serial.begin(9600);
}

void loop() 
{
	vldr = analogRead(ldr);
  	Serial.println(vldr);
  
  	if(vldr < 250)
    	digitalWrite(led,HIGH);
    else
		digitalWrite(led,LOW);
  	
  	delay(100);
}

