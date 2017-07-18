void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(2, INPUT);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  //pinMode(9, OUTPUT); 
  //pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(3, HIGH);
  //digitalWrite(5, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(6, LOW);
  int GearOpened = digitalRead(3);
  int GearClosed = digitalRead(5);


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



