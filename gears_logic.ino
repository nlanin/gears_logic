const int _MotorMoveUp = HIGH;
const int _MotorMoveDown = LOW;

const int _YES = HIGH;
const int _NO = LOW;

const int _GearOpen = 4;
const int _GearClose = 6;

int GearOpened;
int GearClosed;
int MotorMove;
  
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(4, OUTPUT); // Сигнал - поднять шасси
  pinMode(6, OUTPUT); // Сигнал - выпустить шасси
  
  pinMode(5, INPUT); // Сигнал о выпущенном шасси. Подтянуть резистором 10кОм к GRND.
  pinMode(7, INPUT); // Сигнал о поднятом шасси. Подтянуть резистором 10кОм к GRND. 

  pinMode(10, INPUT); // Входной шим-сигнал от передатчика. LOW - выпустить шасси. HIGH - поднять шасси.
  

}

void loop() {
 
  GearOpened = digitalRead(5);
  GearClosed = digitalRead(7);
  MotorMove = digitalRead(9);

  Serial.print("GearOpened: ");
  Serial.println(GearOpened);
  Serial.print("GearClosed: ");
  Serial.println(GearClosed);

  if (GearOpened == _YES && MotorMove == _MotorMoveUp) { // Шасси выпущено, мотор работает на подъем шасси
    digitalWrite(_GearOpen, _NO);
    digitalWrite(_GearClose, _YES);
  }
  else if (GearOpened == _YES && MotorMove == _MotorMoveDown) { // Шасси выпущено, мотор работает на выпуск шасси
    digitalWrite(_GearOpen, _NO);
    digitalWrite(_GearClose, _NO);
  }
  else if (GearOpened == _NO && MotorMove == _MotorMoveUp) { // Шасси убрано, мотор работает на подъем шасси
    digitalWrite(_GearOpen, _NO);
    digitalWrite(_GearClose, _NO);
  }
  else if (GearOpened == _NO && MotorMove == _MotorMoveDown) { // Шасси убрано, мотор работает на выпуск шасси
    digitalWrite(_GearOpen, _YES);
    digitalWrite(_GearClose, _NO);
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

delay(100);
}



