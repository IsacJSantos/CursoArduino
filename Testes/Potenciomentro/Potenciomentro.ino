#define pot A5

int leds[4] = {11,10,9,6};
const int ledArrSize = 4;
float LEDPOSV;

void SetLed(int potValue, int pin, int pinIndex);

void setup() 
{
  LEDPOSV = 255 / ledArrSize;

  pinMode(pot, INPUT);
  for(int i = 0; i < ledArrSize;i++)
  {
    pinMode(leds[i], OUTPUT);
  }
  
  Serial.begin(9600);
  Serial.println(LEDPOSV);
}

void loop() 
{
 int potValue = map(analogRead(pot), 0, 1023, 0, 255);

  for(int i = 0; i < ledArrSize;i++)
  {
   SetLed(potValue, leds[i], i);
  }
}

void SetLed(int potValue, int pin, int pinIndex)
{
  int clampedPotValue = potValue;
  float currentLedV = LEDPOSV * (pinIndex+1);
  float minValue = abs(LEDPOSV - currentLedV);
  float maxValue = currentLedV + LEDPOSV;
 
  if(clampedPotValue < minValue)
    clampedPotValue = minValue;
  else if(clampedPotValue > maxValue)
    clampedPotValue = maxValue;

  float distance = abs(currentLedV - clampedPotValue);

  float multiplier = map(distance, 0, LEDPOSV, 100, 0);
  
  if(multiplier > 100)
    multiplier = 100;
  else if(multiplier < 0)
    multiplier = 0;
  
  multiplier /= 100;
  analogWrite(pin, 255 * multiplier);
}