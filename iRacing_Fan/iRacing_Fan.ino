//#define ENABLE 11

int fanSpeed;

int PotiPin = A0;
int switchPin = 1;
int PotiPin2 = A1;
int switchPin2 = 2;

int fan1;
int fan2;

int Switch;
int Poti;
int Switch2;
int Poti2;
//int T;
//int fPWM;

void setup() {
  Serial.begin(9600);
//  pinMode(ENABLE, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(PotiPin, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(PotiPin2, INPUT);

//  fPWM = 300; // Hz
//  T=1000000/fPWM; // µs 
  
}

void loop() {
//// My Code  ======================================
  if (Serial.available()) {      
    fanSpeed = Serial.read();
//    fanSpeed = constrain(fanSpeed, 60, 255);
//    analogWrite(ENABLE, fanSpeed);

  }
// =================================================


//// PWM Kalle =====================================
  Poti = analogRead(PotiPin);
  Switch = digitalRead(switchPin);
  Poti2 = analogRead(PotiPin2);
  Switch2 = digitalRead(switchPin2);

  Poti = map(Poti, 0, 1023, 100, 255);
  Poti2 = map(Poti2, 0, 1023, 100, 255);

  fan1 = map(fanSpeed, 0, 255, 0, Poti);
  fan2 = map(fanSpeed, 0, 255, 0, Poti2);

  if (Switch==HIGH) {
    analogWrite(10, fan1);
  }else{
    digitalWrite(10, 0);   
  }
  
  if (Switch2==HIGH) {
    analogWrite(11, fan2);
  }else{
    digitalWrite(11, 0);
  }



  
//  if (Switch==HIGH) {
//    if (Poti < 20)
//    {
//      digitalWrite(13,0);
//      digitalWrite(12,0);
//    }
//    else
//    {
//      int y=map(Poti,0,1023,0,T);
//      int z=map(Poti,0,1023,T,0);
//      digitalWrite(13,1);
//      digitalWrite(12,1);
//      delayMicroseconds(y);
//      digitalWrite(13,0);
//      digitalWrite(12,0);
//      delayMicroseconds(z);
//    }
//  } else {
//    digitalWrite(13,0);
//    digitalWrite(12,0);
//  }  

//  Serial.println(Switch);
//  Serial.println(Poti);
//  Serial.println('===');
//  delay(1000);
// =================================================
}

//void PWM(int pwmPin, int Value, int ValueMin, int ValueMax, int T){
//  if (Poti < 20)
//    {
//      digitalWrite(pwmPin,0);
//    }
//  else
//    {
//      int y=map(Value,ValueMin,ValueMax,0,T);
//      int z=map(Value,ValueMin,ValueMax,T,0);
//      digitalWrite(pwmPin,1);
//      delayMicroseconds(y);
//      digitalWrite(pwmPin,0);
//      delayMicroseconds(z);
//    }
//}

