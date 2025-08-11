// RIGHT SIDE
#define LN298N_IN1 7
#define LN298N_IN2 6

// LEFT SIDE
#define LN298N_IN3 5
#define LN298N_IN4 4

#define DRIVE_LED 8
void setup()
{
  pinMode(LN298N_IN1, OUTPUT);
  pinMode(LN298N_IN2, OUTPUT);
  pinMode(LN298N_IN3, OUTPUT);
  pinMode(LN298N_IN4, OUTPUT);

  pinMode(DRIVE_LED, OUTPUT);
  //pinMode(REVERSE_LED, OUTPUT);
}

void loop()
{
 testCar();
}

void drive()
{
  digitalWrite(LN298N_IN1, HIGH);
  digitalWrite(LN298N_IN2, LOW);
  digitalWrite(LN298N_IN3, HIGH);
  digitalWrite(LN298N_IN4, LOW);

  digitalWrite(DRIVE_LED, LOW);
}

void stopCar()
{
  digitalWrite(LN298N_IN1, LOW);
  digitalWrite(LN298N_IN2, LOW);
  digitalWrite(LN298N_IN3, LOW);
  digitalWrite(LN298N_IN4, LOW);

  digitalWrite(DRIVE_LED, HIGH);
}

void rightTurn()
{
  digitalWrite(LN298N_IN1, HIGH);
  digitalWrite(LN298N_IN2, LOW);
  digitalWrite(LN298N_IN3, LOW);
  digitalWrite(LN298N_IN4, HIGH);
}

void leftTurn()
{
  digitalWrite(LN298N_IN1, LOW);
  digitalWrite(LN298N_IN2, HIGH);
  digitalWrite(LN298N_IN3, HIGH);
  digitalWrite(LN298N_IN4, LOW);
}


// TEST
void testCar()
{
  drive();
  delay(1000);

  stopCar();
  delay(1000);

  leftTurn();
  delay(1000);

  rightTurn();
  delay(1000);
}
