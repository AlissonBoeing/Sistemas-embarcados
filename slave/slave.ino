void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(13, OUTPUT);
}
byte nume;
void loop() {
  // put your main code here, to run repeatedly:

    if(Serial.available()){
    nume = Serial.read();
    if(nume == 1){
    digitalWrite(13, HIGH);
    } else {
    digitalWrite(13, LOW);
    }
    }
    
}
