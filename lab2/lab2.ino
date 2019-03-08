
byte byteRead;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}
void loop() {
  if (Serial.available())
  {
    byteRead = Serial.read(); 
    Serial.write(byteRead);
    byteRead++;
    Serial.write(byteRead);
  }
}
