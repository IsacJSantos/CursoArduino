#define speedPort 5
#define mla 4
#define mlb 2
#define pot A0

const int minFinalSpeed = 1;
const int maxFinalSpeed = 5;

int mSpeed = 0;
int potValue = 0;

enum class MotorState
{
  Off, Right, Left
};

void setMotorState(MotorState state);

void setup()
{
  pinMode(speedPort, OUTPUT);
  pinMode(mla, OUTPUT);
  pinMode(mlb, OUTPUT);
  pinMode(pot, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  potValue = analogRead(pot);
  
  if(potValue >= 0 && potValue <= 510)
  {
    mSpeed = 510 - potValue;
    mSpeed = map(mSpeed, 0, 510, minFinalSpeed, maxFinalSpeed);
   
    analogWrite(speedPort, mSpeed);
    setMotorState(MotorState::Left);
  }
  else if(potValue >= 512 && potValue <= 1023)
  {
    mSpeed = potValue - 512;
    mSpeed = map(mSpeed, 0, 511, minFinalSpeed, maxFinalSpeed);
    
    analogWrite(speedPort, mSpeed);
    setMotorState(MotorState::Right);
  }
  else
  {
    analogWrite(speedPort, 0);
    setMotorState(MotorState::Off);
  }
  
  Serial.println(mSpeed);
}

void setMotorState(MotorState state)
{
  switch(state)
  {
    case MotorState::Off:
      digitalWrite(mla, LOW);
      digitalWrite(mlb, LOW);
    break;
    case MotorState::Right:
      digitalWrite(mlb, HIGH);
      digitalWrite(mla, LOW);
    break;
    case MotorState::Left:
      digitalWrite(mlb, LOW);
      digitalWrite(mla, HIGH);
    break;
  }
}
