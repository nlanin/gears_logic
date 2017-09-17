const int _MotorMoveUp = HIGH;
const int _MotorMoveDown = LOW;

const int _YES = HIGH;
const int _NO = LOW;

const int _GearOpen = 3;
const int _GearClose = 9;

int GearOpened;
int GearClosed;
int MotorMove;

double SignalFromFlySky;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(3, OUTPUT); // Сигнал - поднять шасси
  pinMode(9, OUTPUT); // Сигнал - выпустить шасси
  
  pinMode(2, INPUT); // Сигнал о выпущенном шасси. Подтянуть резистором 10кОм к GRND.
  pinMode(7, INPUT); // Сигнал о поднятом шасси. Подтянуть резистором 10кОм к GRND. 

  pinMode(10, INPUT); // Входной шим-сигнал от передатчика. LOW - выпустить шасси. HIGH - поднять шасси.

  //analogWrite(3, 0);
  //analogWrite(9, 100);


}

void loop() {
 
  if (GearOpened == _NO) 
  {
    GearOpened = digitalRead(2);
  }
  
  if (GearClosed == _NO) 
  {
    GearClosed = digitalRead(7);
  }

  if (GearClosed == _YES && GearOpened == _YES)
  {
    GearClosed = _NO;
    GearOpened = _NO;
  }
  
  MotorMove = digitalRead(10);
  SignalFromFlySky = pulseIn(10, HIGH);
  if (SignalFromFlySky < 1500)
  {
    MotorMove = _MotorMoveUp;
    //GearClosed = _NO;
  }
  else
  {
    MotorMove = _MotorMoveDown;
    //GearOpened = _NO;
  }
  
  Serial.print("GearOpened: ");
  Serial.println(GearOpened);
  Serial.print("GearClosed: ");
  Serial.println(GearClosed);
  Serial.print("MotorMove: ");
  Serial.println(MotorMove);


/*
  Serial.print("3: ");
  Serial.println(analogRead(3));
  Serial.print("9: ");
  Serial.println(analogRead(9));
  Serial.print("10: ");
  Serial.println(analogRead(10));
  Serial.print("10d: ");
  Serial.println(digitalRead(10));
*/


  if (GearClosed == _NO && MotorMove == _MotorMoveUp) { // Шасси выпущено, мотор работает на подъем шасси
    //digitalWrite(_GearOpen, _NO);
    //digitalWrite(_GearClose, _YES);

    digitalWrite(_GearOpen, _YES);
    digitalWrite(_GearClose, _NO);
    
    GearOpened = _NO;
  }
  else if (GearOpened == _YES && MotorMove == _MotorMoveDown) { // Шасси выпущено, мотор работает на выпуск шасси
    //digitalWrite(_GearOpen, _NO);
    //digitalWrite(_GearClose, _NO);

    digitalWrite(_GearOpen, _YES);
    digitalWrite(_GearClose, _YES);
  }
  else if (GearClosed == _YES && MotorMove == _MotorMoveUp) { // Шасси убрано, мотор работает на подъем шасси
    //digitalWrite(_GearOpen, _NO);
    //digitalWrite(_GearClose, _NO);

    digitalWrite(_GearOpen, _YES);
    digitalWrite(_GearClose, _YES);
  }
  else if (GearOpened == _NO && MotorMove == _MotorMoveDown) { // Шасси убрано, мотор работает на выпуск шасси
    //digitalWrite(_GearOpen, _YES);
    //digitalWrite(_GearClose, _NO);

    digitalWrite(_GearOpen, _NO);
    digitalWrite(_GearClose, _YES);
    
    GearClosed = _NO;
  }

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

//delay(100);
}



