//Drive Forward and if it finds a line, align itself to pick up block

void findLine(int driveSpeed) {
  drive(driveSpeed);

  if (lSense == BLACK || rSense == BLACK || cSense == BLACK) {
  //driveSpeed = 1;
   delay(200);
    drive(0);
    delay(1000);
    turnRight();
    delay(800);
    state = 1;
  }
}

