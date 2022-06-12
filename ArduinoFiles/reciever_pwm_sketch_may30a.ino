#include <avdweb_AnalogReadFast.h>

#define BUTTON_PIN 3
//#include <analogReadFast.h>
#define apin A0
const int t=200;
word pulseWidth[t];
word v[t];
volatile unsigned long pulseInTimeBegin = micros();
volatile unsigned long pulseInTimeEnd = micros();
volatile bool newPulseDurationAvailable = false;
 int a;
int c=0;
int f=0;
const float mvc=4.88;
 
void buttonPinInterrupt()
{
  if (digitalRead(BUTTON_PIN) == HIGH) {
    // start measuring
    pulseInTimeBegin = micros();
    if(f==0){
    v[c]=analogReadFast(apin);
    f=1;}
  }
  else {
    // stop measuring
    pulseInTimeEnd = micros();
    newPulseDurationAvailable = true;
   f=0;
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
    unsigned long pulseDuration = pulseInTimeEnd - pulseInTimeBegin;
    //Serial.println(pulseDuration);
    c+=1;
   /* if(c==500){
      Serial.println("STOPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPPP");
      }*/
    pulseWidth[c-1] =pulseDuration ;
   /* if(pulseDuration>=255000){
        Serial.println("1011");
       
        }

        else if(pulseDuration>=238000 and pulseDuration<255000){
        Serial.println("1101");}

      else if(pulseDuration>=221000 and pulseDuration<238000){
        Serial.println("1000");}

       else if(pulseDuration>=204000 and pulseDuration<221000){
        Serial.println("1111");}

        else if(pulseDuration>=187000 and pulseDuration<204000){
        Serial.println("1100");}
        
      else if(pulseDuration>=170000 and pulseDuration<187000){
        Serial.println("0011");}

       else if(pulseDuration>=153000 and pulseDuration<170000){
        Serial.println("1110");}

        else if(pulseDuration>=136000 and pulseDuration<153000){
        Serial.println("1001");}

        else if(pulseDuration>=119000 and pulseDuration<136000){
        Serial.println("1010");}

        else if(pulseDuration>=102000 and pulseDuration<119000){
        Serial.println("0001");}

        else if(pulseDuration>=85000 and pulseDuration<102000){
        Serial.println("0101");}

        else if(pulseDuration>=68000 and pulseDuration<85000){
        Serial.println("0000");}

        else if(pulseDuration>=51000 and pulseDuration<68000){
        Serial.println("0010");}

        else if(pulseDuration>=34000 and pulseDuration<51000){
        Serial.println("0100");}

        else if(pulseDuration>=17000 and pulseDuration<34000){
        Serial.println("0111");}

     else{
          Serial.println("0110");
          }*/

      
      
      
   // a=pulseDuration;
   
   
    //Serial.println(pulseDuration);
  }

   if (c==t-1) { // print 100 results
    for (int i = 0; i < t-1; i++) {
     // Serial.print(i + 1);
      //Serial.print(": ");
      //pulseWidth[99]=a;
      Serial.println(v[i]*mvc); // the pulse width in μs
    /*  if(pulseWidth[i]>=10000 and v[i]*mvc>=3500){
        Serial.println(1);
       
        }
      else{
        Serial.println(0);
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
