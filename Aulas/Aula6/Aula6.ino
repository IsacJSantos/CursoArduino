#define led 4
#define btn 3

bool btnPressed;

void OnBtnClicked();

void setup() 
{
   pinMode(led, OUTPUT);
   pinMode(btn, INPUT);
}

void loop() 
{
  delay(10);
  if(digitalRead(btn) == HIGH && !btnPressed)
  {
    btnPressed = true;
  }
  else if(digitalRead(btn) == LOW && btnPressed)
  {
    btnPressed = false;
    OnBtnClicked();
  }
}


void OnBtnClicked()
{
  if(digitalRead(led) == HIGH)
  	digitalWrite(led, LOW);  
  else
   	digitalWrite(led, HIGH);
}