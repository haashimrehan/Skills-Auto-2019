void layoutThree() {
  /*
     Turn Right slightly
     Look for Lines
     Align with Line
     Pick up Block
     R + TL + F + TR + F + S
     Drop Block ---
     R + TR
     Look for Lines
     Pick Block
     Reverse
     Stop
  */

  if (state == 0) {
    drive(5);
    delay(1350);
    turnRightAbsolute(90);
    drive(5);
    delay(500);
    state = 1;
  } else if (state == 1) {
    findLinePID();
  } else if (state == 2) { // Face Block
    turnRightAbsolute(180);
    drive(-2);
    delay(500);
    drive(0);
    delay(200);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse
    drive(-3);
    delay(1000);
    turnLeftAbsolute(90);
    straightPID(2000);
    turnRightAbsolute(180);
    straightPID(1000);
    drive(0);
    state = 5;
  } else if (state == 5) {
    dropBlock();
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(0);
  }
}
