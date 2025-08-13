// __________________________ MOTORS && LEDs __________________________
// RIGHT SIDE
#define LN298N_IN1 7
#define LN298N_IN2 6

// LEFT SIDE
#define LN298N_IN3 5
#define LN298N_IN4 4

// LEDs
#define DRIVE_LED 8
#define REVERSE_LED 9

// __________________________ BUZZER && HC-SR04 __________________________
// Pins for buzzer
#define BUZZER_PIN 3 // Active buzzer VCC connected here, GND to Arduino GND

// Pins for HC-SR04
#define TRIG_PIN 9
#define ECHO_PIN 10

// Max detection range for beeping speed
#define MAX_DISTANCE 50 // cm
#define MIN_DISTANCE 2  // cm

// __________________________ BLUETOOTH __________________________
// HC-06

void setup()
{
  // ________ MOTORS SETUP ________
  pinMode(LN298N_IN1, OUTPUT);
  pinMode(LN298N_IN2, OUTPUT);
  pinMode(LN298N_IN3, OUTPUT);
  pinMode(LN298N_IN4, OUTPUT);

  pinMode(DRIVE_LED, OUTPUT);
  //pinMode(REVERSE_LED, OUTPUT);

  // ________ BUZZER && HC-SR04 SETUP ________
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, HIGH); // Silent at startup
  
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  
  Serial.begin(9600);
}

void loop()
{
 beeping ();
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

void beeping ()
{
    long duration;
  int distance;

  // Send trigger pulse
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Read echo time
  duration = pulseIn(ECHO_PIN, HIGH);

  // Calculate distance in cm
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= MAX_DISTANCE) {
    // Map distance to delay: closer = faster beeps
    int beepDelay = map(distance, MIN_DISTANCE, MAX_DISTANCE, 5, 1000);

    digitalWrite(BUZZER_PIN, LOW);  // Buzzer ON
    delay(50);                      // Beep length
    digitalWrite(BUZZER_PIN, HIGH); // Buzzer OFF
    delay(beepDelay);               // Delay based on distance
  } else {
    digitalWrite(BUZZER_PIN, HIGH); // Silent if far
    delay(100);
  }
}