#define ENABLE 11

int fanSpeed;

//int PotiPin = A0;
//int switchPin = 2;
//
//int Switch;
//int Poti;
//
//int i;
//int n;
//
//int in;

void setup() {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
//  pinMode(ENABLE, OUTPUT);
//  pinMode(switchPin, INPUT);
//  pinMode(13,OUTPUT);
//  analogWrite(ENABLE, 255);
//  delay(1000); 
//  analogWrite(ENABLE, 0);
}

void loop() {
  if (Serial.available()) {      
    fanSpeed = Serial.read();
//    fanSpeed = constrain(fanSpeed, 60, 255);
    analogWrite(ENABLE, fanSpeed);
//    if (fanSpeed > 127){
//      digitalWrite(LED_BUILTIN, HIGH);
//    }
//    else{
//      digitalWrite(LED_BUILTIN, LOW);
//    }
      
  }
//  else{
//      digitalWrite(LED_BUILTIN, HIGH);
////    digitalWrite(ENABLE, 0);
//  }

  
//// PWM Pin 11
//  Poti = analogRead(PotiPin);
//  Switch = digitalRead(switchPin);
//  
//  if (Switch==HIGH) {
////    n = min(max((Poti)/4,0),255);
//    n = map(Poti,0,1023,60,255);
//  } else {
//    n = 0;
//  }
//  analogWrite(ENABLE, n);  

//// PWM Kalle
//  Poti = analogRead(PotiPin);
//  Switch = digitalRead(switchPin);
//  
//  if (Switch==HIGH) {
//    if (Poti < 20)
//    {
//      digitalWrite(13,0);
//    }
//    else
//    {
//      int y=map(Poti,0,1023,0,4000);
//      int z=map(Poti,0,1023,4000,0);
//      digitalWrite(13,1);
//      delayMicroseconds(y);
//      digitalWrite(13,0);
//      delayMicroseconds(z);
//    }
//  } else {
//    digitalWrite(13,0);
//  }  
 

//// Test iRacing
//  if (Serial.available()) {      
//    input = Serial.read();
//    
//    if (input == '1') 
//    {
//      digitalWrite(LED_BUILTIN, HIGH);
//      digitalWrite(ENABLE, 255);   // turn the LED on (HIGH is the voltage level)
//    }
//     
//    if (input == '0') 
//    {
//      digitalWrite(LED_BUILTIN, LOW);
//      digitalWrite(ENABLE, 0);   // turn the LED on (HIGH is the voltage level)
//      
//    }
//  }
//  else{
//    digitalWrite(LED_BUILTIN, LOW);
//    digitalWrite(ENABLE, 0);
//  }
}

