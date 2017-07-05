#define ENABLE 5

int PotiPin = A0;
int switchPin = 2;

int Switch;
int Poti;

int i;
int n;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {

  Poti = analogRead(PotiPin);
  Switch = digitalRead(switchPin);
  
  if (Switch==HIGH) {
    n = min(max((Poti)/4,0),255);
  } else {
    n = 0;
  }
  analogWrite(ENABLE, n);  
}

