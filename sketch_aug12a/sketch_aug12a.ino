void setup() {
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(38400);
}

void loop() {
  int m1 = map(analogRead(A0),0,1024, 0,255);
  int m3 = map(analogRead(A2),0,1024, 0,255);
   
    analogWrite(12, m1);
    analogWrite(13, m3);
}
