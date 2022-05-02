#define cellpin A0
const float mvc=4.88;
float counts=0;
float mv=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
 counts=analogRead(cellpin);
 mv=counts*mvc;
 Serial.println(mv);
 
}
