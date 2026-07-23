#define ledVermelho 8
#define ledAmarelo 9
#define ledVerde 10

enum class Signal
{
  Red, Yellow, Green
};

void SetLeds(Signal s);

void setup() {
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
}

void loop() {
  SetLeds(Signal::Green);
  delay(7000);
  SetLeds(Signal::Yellow);
  delay(2000);
  SetLeds(Signal::Green);
  delay(9000);
}

void SetLeds(Signal s)
{
  digitalWrite(ledVermelho, s == Signal::Red ? HIGH : LOW);
  digitalWrite(ledAmarelo, s == Signal::Yellow ? HIGH : LOW);
  digitalWrite(ledVerde, s == Signal::Green ? HIGH : LOW);
}