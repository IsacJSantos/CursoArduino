#define btnR 7
#define btnG 6
#define btnB 5

#define ledR 4
#define ledG 3
#define ledB 2

class Button
{
public:
  Button(int pin);
  bool CheckBtnClicked();
private:
  int pin;
  bool pressed;
};

Button buttonR {btnR};
Button buttonG {btnG};
Button buttonB {btnB};

void setup() 
{
   pinMode(ledR, OUTPUT);
   pinMode(ledG, OUTPUT);
   pinMode(ledB, OUTPUT);
}

void loop() 
{
  delay(20); // To avoid contact bounce

  if(buttonR.CheckBtnClicked())
    digitalWrite(ledR, digitalRead(ledR) == HIGH ? LOW : HIGH);

  if(buttonG.CheckBtnClicked())
    digitalWrite(ledG, digitalRead(ledG) == HIGH ? LOW : HIGH);

  if(buttonB.CheckBtnClicked())
    digitalWrite(ledB, digitalRead(ledB) == HIGH ? LOW : HIGH);
}

Button::Button(int pin):pin{pin}
{
   pinMode(pin, INPUT_PULLUP);
}

bool Button::CheckBtnClicked()
{

  if(digitalRead(pin) == LOW && !pressed)
  {
     pressed = true;
  }
  else if(digitalRead(pin) == HIGH && pressed)
  {
    pressed = false; 
    return true;
  }
  return false;
}

