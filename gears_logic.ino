void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  pinMode(6, INPUT);
  pinMode(7, INPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorVal1 = digitalRead(2);
  int sensorVal2 = digitalRead(3);
  int sensorVal3 = digitalRead(4);
  int sensorVal4 = digitalRead(5);
  int sensorVal5 = digitalRead(6);
  int sensorVal6 = digitalRead(7);
  int sensorVal7 = digitalRead(8);
  int sensorVal8 = digitalRead(9);
  
  Serial.print("sensorVal1: ");
  Serial.println(sensorVal1);
  Serial.print("sensorVal2: ");
  Serial.println(sensorVal2);
  Serial.print("sensorVal3: ");
  Serial.println(sensorVal3);
  Serial.print("sensorVal4: ");
  Serial.println(sensorVal4);
  Serial.print("sensorVal5: ");
  Serial.println(sensorVal5);
  Serial.print("sensorVal6: ");
  Serial.println(sensorVal6);
  
  Serial.print("sensorVal7: ");
  Serial.println(sensorVal7);
  Serial.print("sensorVal8: ");
  Serial.println(sensorVal8);

  if (sensorVal1 == HIGH) {
    digitalWrite(8, HIGH);
  } else {
    digitalWrite(8, LOW);
  }

  if (sensorVal2 == HIGH) {
    digitalWrite(9, HIGH);
  } else {
    digitalWrite(9, LOW);
  }

 delay(100);
}



