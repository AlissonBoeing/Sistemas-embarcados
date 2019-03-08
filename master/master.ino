void setup() {
  // put your setup code here, to run once:
Serial1.begin(9600);
pinMode(13, OUTPUT);
}
byte nume;
void loop() {
  // put your main code here, to run repeatedly:

  
    nume = Serial1.read();

    if(nume == 1){
    digitalWrite(13, HIGH);
  
    } else {
    digitalWrite(13, LOW);
    }
}
