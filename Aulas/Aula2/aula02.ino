void setup() {
  pinMode(13,OUTPUT); //OUTPUT = Saída - INPUT = Entrada

}

void loop() {
  digitalWrite(13,HIGH); // HIGH = Ligada(5V) - LOW = Desligada(~0V)
  delay(2000);
  digitalWrite(13,LOW);
  delay(2000);
}


