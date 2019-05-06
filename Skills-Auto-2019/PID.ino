void straightPID (int timeToDrive) {
  int startTime = millis();
  SetpointD = currentAngle;

  while (millis() - startTime <= timeToDrive) {
    gyroUpdate();
    InputD = currentAngle;
    drivePID.Compute();

    int leftS = 100 + OutputD;
    int rightS = 100 - OutputD;
    drive(leftS, rightS);
  }
}

void turnLeftAbsolute(int deg) {
  gyroUpdate();
  int startTime = millis();
  if (absoluteAngle - deg <= 0) {
    deg = (absoluteAngle - deg) + 360;
  } else if (absoluteAngle - deg >= 360) {
    deg = absoluteAngle + deg;
  } else {
    deg = absoluteAngle - deg;
  }

  SetpointT = deg;
  int timeToTurn = abs(deg) * 22;
  while (SetpointT - InputT > 1 || SetpointT - InputT < - 1) { //millis() - startTime <= timeToTurn) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();


    /*
      Serial.print(InputT);
      Serial.print("  ");
      Serial.print(SetpointT);
      Serial.print("  ");
      Serial.print(InputT - SetpointT);
      Serial.println();
    */
    driveArdumoto(MOTOR_B, FORWARD, abs(OutputT));
    driveArdumoto(MOTOR_A, FORWARD, abs(OutputT));
  }
  drive(0);
}

void turnRightAbsolute(int deg) {
  gyroUpdate();
  int startTime = millis();
  if (absoluteAngle + deg >= 360) {
    deg = (absoluteAngle + deg) - 360;
  } else if ((absoluteAngle + deg) <= 0) {
    deg = (absoluteAngle - deg) + 360;
  } else {
    deg = absoluteAngle + deg;
  }

  SetpointT = deg;
  int timeToTurn = abs(deg) * 22;
  while (SetpointT - InputT > 1 || SetpointT - InputT < - 1) { //millis() - startTime <= timeToTurn) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();
    /*   Serial.print(InputT);
       Serial.print("  ");
       Serial.print(SetpointT);
       Serial.print("  ");
       Serial.print(InputT - SetpointT);
       Serial.println();*/

    driveArdumoto(MOTOR_B, REVERSE, abs(OutputT));
    driveArdumoto(MOTOR_A, REVERSE, abs(OutputT));
    //turnRight();
  }
  drive(0);
}

void turnLeftPID(int deg) {
  gyroUpdate();
  //int startTime = millis();
  if (currentAngle - deg <= 0) {
    deg = (currentAngle - deg) + 360;
  } else {
    deg = currentAngle - deg;
  }

  SetpointT = deg;
  // int timeToTurn = abs(deg) * 22;
  while (SetpointT - InputT > 1 || SetpointT - InputT < - 1) { //millis() - startTime <= timeToTurn) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();


    /*
      Serial.print(InputT);
      Serial.print("  ");
      Serial.print(SetpointT);
      Serial.print("  ");
      Serial.print(InputT - SetpointT);
      Serial.println();
    */
    driveArdumoto(MOTOR_B, FORWARD, abs(OutputT));
    driveArdumoto(MOTOR_A, FORWARD, abs(OutputT));
  }
  drive(0);
}

void turnRightPID(int deg) {
  gyroUpdate();
  int startTime = millis();
  if (currentAngle + deg >= 360) {
    deg = (currentAngle + deg) - 360;
  } else {
    deg = currentAngle + deg;
  }

  SetpointT = deg;
  int timeToTurn = abs(deg) * 22;
  while (SetpointT - InputT > 1 || SetpointT - InputT < - 1) { //millis() - startTime <= timeToTurn) {
    gyroUpdate();
    InputT = currentAngle;
    turnPID.Compute();
    /*   Serial.print(InputT);
       Serial.print("  ");
       Serial.print(SetpointT);
       Serial.print("  ");
       Serial.print(InputT - SetpointT);
       Serial.println();*/

    driveArdumoto(MOTOR_B, REVERSE, abs(OutputT));
    driveArdumoto(MOTOR_A, REVERSE, abs(OutputT));
    //turnRight();
  }
  drive(0);
}


void turn(int deg) {
  if (deg > 0) {
    turnRightPID(deg);
  } else if (deg < 0) {
    turnLeftPID(deg);
  }
}
