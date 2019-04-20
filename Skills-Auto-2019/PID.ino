void turn(int deg) {
  SetpointT = currentAngle + deg;

  while (true) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();
    Serial.print(InputT);
    Serial.print("  ");
    Serial.print(SetpointT);
    Serial.print("  ");
    Serial.print(InputT - SetpointT);
    Serial.println();
    int leftS = OutputT;
    int rightS = -OutputT;
    drive(leftS, rightS);
    //driveArdumoto(MOTOR_A, REVERSE, abs(leftS));
    //driveArdumoto(MOTOR_B, FORWARD, abs(rightS));
  }
}

void straightPID () {
  SetpointD = currentAngle;

  while (true) {
    gyroUpdate();
    InputD = currentAngle;
    drivePID.Compute();

    int leftS = 100 + OutputD;
    int rightS = 100 - OutputD;
    drive(leftS, rightS);
    //driveArdumoto(MOTOR_A, REVERSE, abs(leftS)); //Left
    //driveArdumoto(MOTOR_B, FORWARD, abs(rightS));
  }
}


void turnLeftPID(int deg) {
  if (currentAngle - deg <= 0) {
    deg = (currentAngle - deg) + 360;
  } else {
    deg = currentAngle - deg;
  }

  SetpointT = deg;
  while (currentAngle - deg) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();
    Serial.print(InputT);
    Serial.print("  ");
    Serial.print(SetpointT);
    Serial.print("  ");
    Serial.print(InputT - SetpointT);
    Serial.println();

    driveArdumoto(MOTOR_B, FORWARD, abs(OutputT));
    driveArdumoto(MOTOR_A, FORWARD, abs(OutputT));
  }
}

void turnRightPID(int deg) {
  if (currentAngle + deg >= 360) {
    deg = (currentAngle + deg) - 360;
  } else {
    deg = currentAngle + deg;
  }

  SetpointT = deg;
  while (currentAngle - deg != 0) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();
    Serial.print(InputT);
    Serial.print("  ");
    Serial.print(SetpointT);
    Serial.print("  ");
    Serial.print(InputT - SetpointT);
    Serial.println();

    driveArdumoto(MOTOR_B, REVERSE, abs(OutputT));
    driveArdumoto(MOTOR_A, REVERSE, abs(OutputT));
    //turnRight();
  }
}
