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
    turnLeftAbsolute(20);
    straightPID(1200);
    state = 1;
  } else if (state == 1) { // Find Line
    findLinePID();
  } else if (state == 2) { // Face block Direction
    drive(-2);
    delay(100);
    drive(0);
    
    if (block == RED) {
      turnRightAbsolute(40);
    }

    delay(200);
    drive(-3);
    delay(700);
    drive(0);
    delay(1250);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse and Face drop direction

    drive(-3);
    delay(1000);
    turnLeftAbsolute(45);
    straightPID(3000);

    state = 5;
  } else if (state == 5) { // Drop Block
    dropBlock();
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(0);
  }
}
