#define relayPin 2
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 2000;
boolean lockLow = true;
boolean takeLowTime = true;
int PIRValue = 0;
boolean flag = true;

void setup() {
   Serial.begin(9600);
   pinMode(relayPin, OUTPUT);
}

void loop() {
   RelaySensor();
}

void RelaySensor() {
   
   if(takeLowTime){
         lowIn = millis();takeLowTime = false;
      }
      if(millis() - lowIn > pause) {
        toggle();
        takeLowTime = true;
        Serial.println("Toggled");
      }
}

void toggle(){
  if(flag) {
    digitalWrite(relayPin, HIGH);
    flag = false;
  }
  else {
    digitalWrite(relayPin, LOW);
    flag = true;
  }
}
