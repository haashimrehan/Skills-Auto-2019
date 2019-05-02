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
    drive(4);
    delay(500);
    state = 1;
  } else if (state == 1) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 2) { // Reverse
    turnSpeed = startTurnSpeed;
    drive(-3);
    delay(150);
    turnRight();
    delay(1000);
    drive(5);
    delay(1500);
    state = 3;
  } else if (state == 3) { //drop Block
    dropBlock();
    state = 4;
  } else if (state == 4) {
    drive(0);
  } else {
    drive(-2);
  }
}
