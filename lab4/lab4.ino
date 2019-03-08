void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(A5, INPUT);
}
float val;
void loop() {
  val = RMS(30);
  Serial.print("Digital: ");
  Serial.print(val);
  Serial.println("Analogico: ");
  Serial.print(((5.0*val)/1023.0));
}

float RMS(int repeat) {
int i = 0;
float valores[repeat];
  while(i < repeat) {
  valores[i] = analogRead(A5);
  i = i + 1;
  }
  i = 0;
 float acumulado = 0;
  while(i<repeat){
    acumulado = acumulado + (valores[i]*valores[i]);
    i = i + 1;
  }
  acumulado = acumulado/repeat;

  return sqrt(acumulado);
  
}

