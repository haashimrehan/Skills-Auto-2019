void layoutTwo() {
  /*
    turnLeft
    driveForward
    Look for Lines
    Align with line
    PickBlock RED
    Reverse
    Turneft
    drive forward
    DropOff
  */

  if (state == 0) { // Turn left and drive to line
    setHead(1);
    turnLeft();
    delay(100);
    //turnLeftAbsolute(10);
    drive(5);
    delay(1500);
    //straightPID(1200);
    state = 1;
  } else if (state == 1) { // Find Line
    findLinePID();
  } else if (state == 2) { // Face block Direction
    drive(-2);
    delay(100);
    drive(0);

    if (block == RED) {
      turnRightAbsolute(55);
    } if (block == BLUE) {
      turnRightAbsolute(-138);
      if ((absoluteAngle - 138) - currentAngle > 4 || (absoluteAngle - 138) - currentAngle < -4) {
        turnRightAbsolute(-138);
      }
    } if (block == YELLOW) {
      turnRightAbsolute(-138);
      if ((absoluteAngle - 138) - currentAngle > 4 || (absoluteAngle - 138) - currentAngle < -4) {
        turnRightAbsolute(-138);
      }
    }

    drive(0);
    delay(500);

    delay(200);
    drive(-3);
    delay(700);
    drive(0);
    delay(1250);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse and Face drop direction

    drive(-4);
    delay(1200);
    drive(0);
    delay(500);
    if (block == RED) {
      turnLeftAbsolute(32);
    } else if (block == BLUE) {
      turnRightAbsolute(-38);
    } else if (block == YELLOW) {
      turnLeftAbsolute(-138);
    }

    drive(0);
    delay(500);
    drive(5);
    if (block == RED) {
      delay(3000);
    } else if (block == BLUE) {
      delay(1100);
    } else if (block == YELLOW) {
      delay(1100);
    }


    drive(0);
    delay(100);
    //straightPID(3000);

    state = 5;
  } else if (state == 5) { // Drop Red Block
    dropBlock();
    if (block == RED) {
      state = 6;
    } else if (block == BLUE) {
      state = 7;
    }
  } else if (state == 6) {// go to blue block
    block = BLUE;
    setHead(0);
    drive(-3);
    delay(700);
    turnRightAbsolute(38);
    drive(0);
    delay(500);
    drive(5);
    delay(3450);
    drive(0);
    delay(500);
    turnRightAbsolute(135);
    drive(0);
    delay(500);
    drive(3);
    delay(200);
    state = 1;
  } else if (state == 7) { //go to yellow Block
    block = YELLOW;
    drive(-5);
    delay(4000);
    turnLeftAbsolute(135);
    drive(0);
    delay(500);
    drive(3);
    delay(2000);
    turnRightAbsolute(-45);
    state = 1;
  } else {
    drive(0);
  }
}
