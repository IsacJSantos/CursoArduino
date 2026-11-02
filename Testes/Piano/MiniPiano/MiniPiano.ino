#define buzz 9
#define btn1 2
#define btn2 3
#define btn3 4
#define btn4 5

// Definição das frequências das notas musicais
#define NOTE_A4  440 
#define NOTE_D5  587
#define NOTE_E5  659
#define NOTE_G5  784

void setup()
{
  pinMode(buzz, OUTPUT);
  
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);
  pinMode(btn3, INPUT_PULLUP);
  pinMode(btn4, INPUT_PULLUP);
}

void loop()
{
  if(digitalRead(btn1) == LOW)
  {
     tone(buzz, NOTE_A4);
     return;
  }
    
  if(digitalRead(btn2) == LOW)
  {
     tone(buzz, NOTE_D5);
     return;
  }
   
  if(digitalRead(btn3) == LOW)
  {
     tone(buzz, NOTE_E5);
     return;
  }

  if(digitalRead(btn4) == LOW)
  {
     tone(buzz, NOTE_G5);
     return;
  }
  
  noTone(buzz);
  delay(10);
}