// Pins
int PotiPin = A0;
int switchPin = 2;
int PotiPin2 = A1;
int switchPin2 = 4;
int PWM1 = 10;
int PWM2 = 11;

// Variables
int fan1;
int fan2;
int fanSpeed;
int Switch;
int Poti;
int Switch2;
int Poti2;

void setup() {
  Serial.begin(9600);
  pinMode(switchPin, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(PotiPin, INPUT);
  pinMode(PotiPin2, INPUT);  
  pinMode(PWM1, OUTPUT);
  pinMode(PWM2, OUTPUT);
}

void loop() {
  // read data from Serial (iRacing/Python)
  if (Serial.available()) {      
    fanSpeed = Serial.read();
  }
  else{
    fanSpeed = 60;
  }

  // read in Potis and Switches
  Poti = analogRead(PotiPin);
  Switch = digitalRead(switchPin);
  Poti2 = analogRead(PotiPin2);
  Switch2 = digitalRead(switchPin2);

  // remap poti values
  Poti = map(Poti, 0, 1023, 100, 255);
  Poti2 = map(Poti2, 0, 1023, 100, 255);

  // map combined fan speed
  fan1 = map(fanSpeed, 0, 255, 60, Poti);
  fan2 = map(fanSpeed, 0, 255, 60, Poti2);

  // write data to output pins
  if (Switch==HIGH) {
    analogWrite(PWM1, fan1);
  }else{
    digitalWrite(PWM1, 0);  
  }
  
  if (Switch2==HIGH) {
    analogWrite(PWM2, fan2);
  }else{
    digitalWrite(PWM2, 0);
  }
}


