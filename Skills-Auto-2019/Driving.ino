void drive(int speed) {
  int leftDir = 0;
  int rightDir = 0;
  if (speed < 0) {
    leftDir = FORWARD;
    rightDir = REVERSE;
  } else if (speed > 0) {
    leftDir = REVERSE;
    rightDir = FORWARD;
  }

  int newSpeedA = map(speed, -10, 10, -255, 255);
  int newSpeedB = map(speed, -10, 10, -255, 255);
  //int leftDir = 0;
  //int rightDir = 0;

  driveArdumoto(MOTOR_A, leftDir, abs(newSpeedA));
  driveArdumoto(MOTOR_B, rightDir, abs(newSpeedB));
  //  robot.setSpeed('A', -abs(newSpeedA));
  //  robot.setSpeed('B', abs(newSpeedB));
}


// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
  }
}

void turnLeft() {
  driveArdumoto(MOTOR_A, FORWARD, turnSpeed);
  driveArdumoto(MOTOR_B, FORWARD, turnSpeed);
}

void turnRight() {
  driveArdumoto(MOTOR_B, REVERSE, turnSpeed);
  driveArdumoto(MOTOR_A, REVERSE, turnSpeed);
}


// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
  driveArdumoto(motor, 0, 0);
}

// setupArdumoto initialize all pins
void setupArdumoto()
{
  // All pins should be setup as outputs:
  pinMode(PWMA, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(DIRA, OUTPUT);
  pinMode(DIRB, OUTPUT);

  // Initialize all pins as low:
  digitalWrite(PWMA, LOW);
  digitalWrite(PWMB, LOW);
  digitalWrite(DIRA, LOW);
  digitalWrite(DIRB, LOW);
}
