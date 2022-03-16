#define cellpin A0
const float mvc=4.88/1000;
float counts=0;
float mv=0;
int wave=12;
float waves=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(wave, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(wave, LOW);
  //Serial.println(digitalRead(wave));
  counts=analogRead(cellpin);
  mv=counts*mvc;
  Serial.println(mv);
  delay(1000);
  digitalWrite(wave, HIGH);
  //Serial.println(digitalRead(wave));
  counts=analogRead(cellpin);
  mv=counts*mvc;
  Serial.println(mv);
  delay(1000);


  }
  
