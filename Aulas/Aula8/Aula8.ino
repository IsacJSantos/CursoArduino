#define btnR 7
#define btnG 6
#define btnB 5

#define ledR 4
#define ledG 3
#define ledB 2

bool btnRPressed;
bool btnGPressed;
bool btnBPressed;

bool CheckBtnClicked(int, bool&);

void setup() 
{
   delay(20);
   pinMode(btnR, INPUT_PULLUP);
   pinMode(btnG, INPUT_PULLUP);
   pinMode(btnB, INPUT_PULLUP);
  
   pinMode(ledR, OUTPUT);
   pinMode(ledG, OUTPUT);
   pinMode(ledB, OUTPUT);
}

void loop() 
{
  if( CheckBtnClicked(btnR, btnRPressed))
    digitalWrite(ledR, digitalRead(ledR) == HIGH ? LOW : HIGH);

  if( CheckBtnClicked(btnG, btnGPressed))
    digitalWrite(ledG, digitalRead(ledG) == HIGH ? LOW : HIGH);

  if( CheckBtnClicked(btnB, btnBPressed))
    digitalWrite(ledB, digitalRead(ledB) == HIGH ? LOW : HIGH);
}

bool CheckBtnClicked(int btn, bool& btnPressed)
{
  if(digitalRead(btn) == LOW && !btnPressed)
  {
    btnPressed = true;
  }
  else if(digitalRead(btn) == HIGH && btnPressed)
  {
    btnPressed = false; 
    return true;
  }
  return false;
}