#define ENABLE 5

char input;

int PotiPin = A0;
int switchPin = 2;

int Switch;
int Poti;

int i;
int n;

int in;

void setup() {
  pinMode(ENABLE, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT); 
  Serial.begin(9600);
}

void loop() {

//  Poti = analogRead(PotiPin);
//  Switch = digitalRead(switchPin);
//  
//  if (Switch==HIGH) {
//    n = min(max((Poti)/4,0),255);
//  } else {
//    n = 0;
//  }
//  analogWrite(ENABLE, n);  

  if (Serial.available()) {      
    input = Serial.read();
    
    if (input == '1') 
    {
      digitalWrite(LED_BUILTIN, HIGH);
      digitalWrite(ENABLE, 255);   // turn the LED on (HIGH is the voltage level)
    }
     
    if (input == '0') 
    {
      digitalWrite(LED_BUILTIN, LOW);
      digitalWrite(ENABLE, 0);   // turn the LED on (HIGH is the voltage level)
      
    }
  }
//  else{
//    digitalWrite(LED_BUILTIN, LOW);
//    digitalWrite(ENABLE, 0);
//  }
}

