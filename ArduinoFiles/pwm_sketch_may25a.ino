#define BUTTON_PIN 3
word pulseWidth[97];
volatile unsigned long pulseInTimeBegin = micros();
volatile unsigned long pulseInTimeEnd = micros();
 volatile bool newPulseDurationAvailable = false;
 int a;
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
  for (int i = 0; i < 97; i++) {
    pulseWidth[i] = 0; // clears the array
  }
  Serial.begin(115200);
  pinMode(BUTTON_PIN, INPUT);

  attachInterrupt(digitalPinToInterrupt(BUTTON_PIN),
                  buttonPinInterrupt,
                  CHANGE);
}

void loop() {
  if (newPulseDurationAvailable) {
    newPulseDurationAvailable = false;
    unsigned long pulseDuration = pulseInTimeEnd - pulseInTimeBegin;
   // Serial.println(pulseDuration);
    c+=1;
    pulseWidth[c-1] =pulseDuration ;
    a=pulseDuration;
   
    //Serial.println(pulseDuration);
  }

    if (c==96) { // print 100 results
    for (int i = 0; i < 96; i++) {
     // Serial.print(i + 1);
      //Serial.print(": ");
      //pulseWidth[99]=a;
      //Serial.println(pulseWidth[i]); // the pulse width in μs
      if(pulseWidth[i]>=10000){
        Serial.println(1);
        }
      else{
        Serial.println(0);
      }
      //Serial.println(" μs");
    }
    for (int i = 0; i < 97; i++) {
      pulseWidth[i] = 0; // clears the array
      c=0;
    }

  }

  // do your other stuff here
}
