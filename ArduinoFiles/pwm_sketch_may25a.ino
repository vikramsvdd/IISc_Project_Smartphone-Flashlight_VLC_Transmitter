#define BUTTON_PIN 3
word pulseWidth[100];
volatile unsigned long pulseInTimeBegin = micros();
volatile unsigned long pulseInTimeEnd = micros();
volatile bool newPulseDurationAvailable = false;
int c=0;

void buttonPinInterrupt()
{
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // start measuring
    pulseInTimeBegin = micros();
  }
  else {
    // stop measuring
    pulseInTimeEnd = micros();
    newPulseDurationAvailable = true;
  }
}

void setup() {
  for (int i = 0; i < 100; i++) {
    pulseWidth[i] = 0; // clears the array
  }
  Serial.begin(9600);
  pinMode(BUTTON_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                  buttonPinInterrupt,
                  CHANGE);
                  }

void loop() {
  if (newPulseDurationAvailable) {
    newPulseDurationAvailable = false;
    unsigned long pulseDuration = pulseInTimeEnd - pulseInTimeBegin;
    //Serial.println(pulseDuration);
    pulseWidth[c] =pulseDuration ;
    c+=1;
    //Serial.println(c);
  }

    if (c==100) { // print 100 results
    for (int i = 0; i < 100; i++) {
     // Serial.print(i + 1);
      //Serial.print(": ");
      Serial.println(pulseWidth[i]); // the pulse width in μs
     /* if(pulseWidth[i]>5){
        Serial.println(1);
        }
      else{
        Serial.println(0);
      }*/  
      }
      //Serial.println(" μs");
    }
    
    for (int i = 0; i < 100; i++) {
      pulseWidth[i] = 0; // clears the array
    }

  }

  // do your other stuff here
