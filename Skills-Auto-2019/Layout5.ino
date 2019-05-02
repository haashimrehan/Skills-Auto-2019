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
    turnLeftAbsolute(45);
    straightPID(2000);
    state = 1;
  } else if (state == 1) { // Look for lines
    findLinePID();
  } else if (state == 2) { //Align with line for 1100ms
    drive(-2);
    delay(100);
    drive(0);
    turnLeftAbsolute(90);
    drive(-2);
    delay(500);
    drive(0);
    delay(200);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse Drive to destination

    drive(-3);
    delay(300);
    turnRightAbsolute(90);
    drive(3);
    delay(200);
    state++;
  } else if (state == 5) { //drop Block
    dropBlock();
    state++;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(0);
  }
}
