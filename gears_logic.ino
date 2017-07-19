void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  
  pinMode(5, INPUT);
  pinMode(7, INPUT);
  
  //pinMode(7, OUTPUT);
  //pinMode(8, OUTPUT);
  //pinMode(9, OUTPUT); 
  //pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(3, HIGH);
  //digitalWrite(5, HIGH);
  //digitalWrite(4, LOW);
  //digitalWrite(6, LOW);
  int GearOpened = digitalRead(5);
  int GearClosed = digitalRead(7);


  Serial.print("GearOpened: ");
  Serial.println(GearOpened);
  Serial.print("GearClosed: ");
  Serial.println(GearClosed);
  

/*  if (GearOpened == HIGH) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (sensorVal2 == HIGH) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }
*/

delay(100);
}



