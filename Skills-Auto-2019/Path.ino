//Drive Forward and if it finds a line, align itself to pick up block

void findLine() {
  drive(3);
  readLines();
  if (lSense == BLACK || rSense == BLACK || cSense == BLACK) {
    //driveSpeed = 1;
    readLines();
    /*delay(100);
      drive(0);
      delay(1000);
      turnRight();
      delay(700);
    */
    drive(0);
    delay(1000);
    state++;
  }
}

void findLinePID() {
  readLines();
  gyroUpdate();
  SetpointD = currentAngle;

  while (cSense == WHITE && rSense == WHITE && lSense == WHITE) {
    readLines();
    gyroUpdate();
    InputD = currentAngle;
    drivePID.Compute();

    int leftS = 100 + OutputD;
    int rightS = 100 - OutputD;
    drive(leftS, rightS);
  }
  drive(0);
  delay(1000);
  state++;
}
