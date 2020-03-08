#define pirPin 2
int calibrationTime = 30;
long unsigned int lowIn;
long unsigned int pause = 1000;
boolean lockLow = true;
boolean takeLowTime = true;
int PIRValue = 0;

void setup() {
   Serial.begin(9600);
   pinMode(pirPin, INPUT);
}

void loop() {
   PIRSensor();
}

void PIRSensor() {
   
   
    if(takeLowTime){
         lowIn = millis();takeLowTime = false;
      }
      if(millis() - lowIn > pause) {

        if(digitalRead(pirPin) == HIGH) {
          Serial.println("Motion detected.");
          }
        if(digitalRead(pirPin) == LOW) {
          Serial.println("Motion not detected.");
          }
        takeLowTime = true;
      }
}
