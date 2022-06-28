#include <avdweb_AnalogReadFast.h>
#define BUTTON_PIN 2
#define apin A0
const int t=201;
word pulseWidth[t];
word v[t];
volatile unsigned long pulseInTimeBegin = micros();
volatile unsigned long pulseInTimeEnd = micros();
volatile bool newPulseDurationAvailable = false;
int a;
int c=0;
int f=0;
const float mvc=4.88;
float temp=0;
float prev=0;
 
void buttonPinInterrupt()
{
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // start measuring
    pulseInTimeBegin = micros();
   // if(f==0){
   //delayMicroseconds(10); 
    temp=analogReadFast(apin);
    if(temp>prev){
      prev=temp;}
   // f=1;
   // }
  }
  else {
    // stop measuring
    pulseInTimeEnd = micros();
    newPulseDurationAvailable = true;
    v[c]=prev;
    prev=0;
  // f=0;
  }
}

void setup() {
  for (int i = 0; i < t; i++) {
    pulseWidth[i] = 0; // clears the array
    v[i]=0;
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
    //unsigned long pulseDuration = pulseInTimeEnd - pulseInTimeBegin;
    //Serial.println(pulseDuration);
    c+=1;
    
   // pulseWidth[c-1] =pulseDuration ;
  }

   if (c==t-1) { // print 100 results
    for (int i = 0; i < t-1; i++) {
      //Serial.println(pulseWidth[i]);
      if(v[i]*mvc>3600){
      //Serial.println(v[i]*mvc);
      Serial.println(1);
      }
      else{
        Serial.println(0);
      }
     /* if(pulseWidth[i]>=1000 and v[i]*mvc>=4000){          // a 1 is a pulse whose pulse width is greater than 1 ms and has a voltage greater than 4000 mv, a 0 may have a similar pulse width , but should have a lower voltage than 4000 mv
        Serial.println(1);
       // Serial.println(pulseWidth[i]);
      
       
        }
      else{
        Serial.println(0);
       //Serial.println(pulseWidth[i]);
      
      }*/
      
      //Serial.println(" μs");
    }
   for (int i = 0; i < t; i++) {
      //Serial.println(pulseWidth[i]);
      pulseWidth[i] = 0; // clears the array
      v[i]=0;
      c=0;
    }

  }

  // do your other stuff here
}
