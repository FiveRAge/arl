bool reading = false;
String headY = "";
String headCY = "";
String headZ = "";
String headCZ = "";
String mess[2] ="";
String oldmessleft ="";
String oldmessright ="";
void setup() {
  delay(100);
  pinMode(22, INPUT_PULLUP);
  pinMode(23, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(29, INPUT_PULLUP);
  pinMode(30, INPUT_PULLUP);
  pinMode(31, INPUT_PULLUP);
  pinMode(28, INPUT_PULLUP);
  pinMode(40, INPUT_PULLUP);
  pinMode(41, INPUT_PULLUP);
  pinMode(5, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  delay(100);
  analogWrite(7, 50);
  // Open Serial2 communications and wait for port to open:
  Serial.begin(115200);
  Serial2.begin(115200);
  Serial2.println("Goodnight moon!");
  
}
int i = 0;
char data;
void loop() { // run over and over
  mess[0]="";
  mess[1]="";
  while (Serial2.available()) {
    data = char(int(Serial2.read()));
    if (data == '>') {  i = 0;reading = false;}
    if (reading == true){
      if (data == ':'){i = 1;}
      mess[i] += data;
      }
    if (data == '<') {  reading = true;}
    //Serial.print(mess[1]);
    delay(1);
  }
  //Serial.print(digitalRead(22));
  if (digitalRead(22) == 0){
   headCY = "left";
   Serial.print("warn YLeft");
   //Serial2.print("<stop:YLeft>");
    }else{
  if (digitalRead(23) == 0){
   headCY = "right";
   Serial.print("warn YRight");
   //Serial2.print("<stop:YRight>");
    } else {headCY="";}}
  
  if (digitalRead(40) == 0){
   headCZ = "left";
   Serial.print("warn ZLeft");
   //Serial2.print("<stop:ZLeft>");
    }
  
  if (digitalRead(41) == 0){
   headCZ = "right";
   Serial.print("warn ZRight");
   //Serial2.print("<stop:ZRight>");
    }
//  j=0;
//  for (i=0;i<5;i++)
//  {
//    j+=digitalRead(28);
//    if (j>=3)tmpres=1)
//      else tmpres=0;
//  }
if (mess[0] == "clear"){
  oldmessleft = "";
  oldmessright = "";
   Serial2.print("<data:clear>");
  
  }
  if (digitalRead(28) == 0 && oldmessleft != "LAUp"){
   oldmessleft = "LAUp";
   Serial.print("<stop:LAUp>");
   Serial2.print("<stop:LAUp>");
    }
  
  if (digitalRead(29) == 0&& oldmessleft != "LADown"){
   oldmessleft = "LADown";
   Serial.print("<stop:LADown>");
   Serial2.print("<stop:LADown>");
    }
  
  if (digitalRead(30) == 0&& oldmessright != "RAUp"){
   oldmessright = "RAUp";
   Serial.print("<stop:RAUp>");
   Serial2.print("<stop:RAUp>");
    }
  
  if (digitalRead(31) == 0&& oldmessright != "RADown"){
   oldmessright = "RADown";
   Serial.print("<stop:RADown>");
   Serial2.print("<stop:RADown>");
    }

    
if (mess[0] == "turn1"){
    if (mess[1] == ":0"){
      headY  = "right";
      //Serial.print("right");
      analogWrite(11, 0);
      digitalWrite(10, 8);
      } 
     if (mess[1] == ":1"){
      headY  = "left";
          //Serial.print("left");
      analogWrite(11, 0);
      digitalWrite(10, 0);
      }
    }
  if (mess[0] == "turn2"){
    if (mess[1] == ":1"){
      headZ  = "left";
          //Serial.print("Zleft");
      analogWrite(9, 0);
      digitalWrite(8, 8);
      }
     if (mess[1] == ":0"){
      headZ  = "right";
          //Serial.print("ZRIGHT");
      analogWrite(9, 0);
      digitalWrite(8, 0);
      }
    }
  if (headCY != headY){
    if (mess[0] == "speed1"){




























































































      
    if (mess[1] != 0){
      analogWrite(11, 8);
      } else {
         analogWrite(11, 0);
         
      }
      }
  } else {
      analogWrite(11, 0);
  }
  if (headCZ != headZ){
  if (mess[0] == "speed2"){
    if (mess[1] != 0){
      analogWrite(9, 8);
      } else {
      analogWrite(9, 0);
      }
    }
  } else {
      analogWrite(9, 0);
  }

  
  if (mess[0] == "stop1"){
      analogWrite(11, 0);
    }
  if (mess[0] == "stop2"){
      analogWrite(9, 0);
    }
   
}

