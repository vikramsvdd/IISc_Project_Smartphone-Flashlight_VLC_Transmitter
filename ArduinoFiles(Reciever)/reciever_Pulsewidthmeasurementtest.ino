#define cellpin A0
const float mvc=4.88;
float counts=0;
float mv=0;
int ctr=0;
long int t1,t2;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

 }

  



void loop() {
  // put your main code here, to run repeatedly:
 counts=analogRead(cellpin);
 mv=counts*mvc;
/* if(mv>19.52){
 Serial.println(mv);}*/
 if(mv>19.52 && ctr==0){
  
 t1 = millis();
 ctr=1;                                          // ctr is used for detecting edges
 
}
if(mv<19.52 && ctr==1){
  
  
  t2=millis();
  Serial.print("The on-pulse duration in ms is ");
  Serial.println(t2-t1);
  Serial.println(mv);
  ctr,t1,t2=0,0,0;
  
  
  
  
  
  }

  if(mv<19.52 && ctr==0){
    Serial.println("NOTHING");}

}

