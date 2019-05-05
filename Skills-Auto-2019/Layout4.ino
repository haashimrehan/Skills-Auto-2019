void layoutFour() {
  /*
    drive forward
    Pickblock YELLOW
    Reverse
    Turn Right
    Drive Forward
    Drop off
  */

  if (state == 0) {
    turnLeftAbsolute(20);
    drive(4);
    delay(1000);
    state = 1;
  } else if (state == 1) { // find line
    findLinePID();
  } else if (state == 2) { // turn and Reverse. face block
    if (block == BLUE) {
      turnRightAbsolute(0);
    } else if (block == YELLOW) {
      turnRightAbsolute(-90);
    }
    drive(-2);
    delay(800);
    drive(0);
    state++;
  } else if (state == 3) { //pick Block
    pickBlock(9, 18);
  } else if (state == 4) {
    if (block == YELLOW) {
      state = 9;
    } else {
      drive(-4);
      delay(600);
      drive(0);
      delay(500);
      turnLeftAbsolute(90);
      straightPID(1800);
      state++;
    }
  } else if (state == 5) {
    findLinePID();
  } else if (state == 6) { // Drop Blue Block
    turnLeftAbsolute(175);
    straightPID(5600);
    drive(0);
    delay(500);
    state++;
  } else if (state == 7) {
    dropBlock();
    delay(500);
    if (block == BLUE) {
      state++;
    } else if (block == YELLOW) {
      state = 10;
    }
  } else if (state == 8) {
    block = YELLOW;
    drive(-5);
    delay(3000);
    drive(4);
    delay(100);
    state = 1;
  } else if (state == 9) { //drive to yellow square
    drive(-4);
    delay(2100);
    readLines();
    while (lSense == WHITE && cSense == WHITE && rSense == WHITE) {
      readLines();
      drive(-4);
    }

    drive(0);
    delay(500);
    turnLeftAbsolute(169);
    drive(4);
    delay(2900);
    state = 7;
  } else if (state == 10) {
    drive(0);
  }
}
