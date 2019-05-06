void layoutSix() {
  /*
     F + TR
     Look for lines
     Pick block
     reverse until hits back wall
     F + TR + F
     Drop Block
  */

  if (state == 0) {
    turnLeftAbsolute(45);
    straightPID(2000);

    state = 1;
  } else if (state == 1) {
    findLinePID();
  } else if (state == 2) {
    turnLeftAbsolute(90);
    drive(-3);
    delay(600);
    drive(0);
    delay(500);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse and turn
    drive(-4);
    delay(1800);//1900
    turnRightAbsolute(0);
    straightPID(4000);
    drive(0);
    state++;
  } else if (state == 5) {
    dropBlock();
    state++;
  } else if (state == 6) {
    drive(0);
    //state++;
  } else {
    drive(0);
  }
}
