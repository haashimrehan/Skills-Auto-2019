void layoutFive() {
  /*
     TL + F
     Look for lines
     align with line
     PickBlock
     Reverse + 180 Turn
     F + Drop off block
  */

  if (state == 0) {
    turnLeftAbsolute(80);
    straightPID(2000);
    state = 1;
  } else if (state == 1) { // Look for lines
    findLinePID();
  } else if (state == 2) { //Align with line for 1100ms
    drive(-2);
    delay(100);
    drive(0);
    turnLeftAbsolute(135);
    drive(-2);
    delay(500);
    drive(0);
    delay(200);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) {
    if (block == BLUE) {
      turnRightAbsolute(0);
      straightPID(2000);
      readLines();
      while (lSense == WHITE && cSense == WHITE && rSense == WHITE) {
        readLines();
        drive(4);
      }
      drive(0);
      delay(500);
      turnRightAbsolute(85);
      straightPID(3500);
      state++;
    } else if (block == RED) {
      turnLeftAbsolute(-105);
      drive(0);
      delay(500);
      drive(4);
      delay(1000);
      drive(0);
      state++;
    }
  } else if (state == 5) { //drop Block
    dropBlock();
    if (block == BLUE) {
      state++;
    } else if (block == RED) {
      state = 7;
    }
  } else if (state == 6) { //go to red block
    block = RED;
    drive(-4);
    delay(2500);
    turnLeftAbsolute(90);
    state = 3;
  } else if (state == 7) {
    drive(0);
  } else {
    drive(0);
  }
}
