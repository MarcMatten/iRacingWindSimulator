int PotiPin = A0;
int switchPin = 2;

int Switch;
int Poti;

int i;
int n;



void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);

}

void loop() {

  Poti = analogRead(PotiPin);
  Switch = digitalRead(switchPin);
  
  Serial.println(Poti);
  Serial.println(Switch);
  Serial.println("======");
  
  if (Switch==HIGH) {
    n = max((Poti+1)/2,0);
  } else {
    n = 0;
  }
}

