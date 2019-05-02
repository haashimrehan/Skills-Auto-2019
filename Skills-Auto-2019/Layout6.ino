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
    drive(3);
    delay(500);
    turnRight();
    delay(2000);
    state = 1;
  } else if (state == 1) {
    findLine();
  } else if (state == 2) {
    turnRight();
    delay(1000);

    long start = millis();
    while (millis() - start < 1100) {
      readLines();
      followLine();
    }

    drive(-2);
    delay(500);
    drive(0);
    delay(200);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock();
  } else if (state == 4) { // Reverse
    turnSpeed = 90;
    drive(-4);
    delay(7000);
    state++;
  } else if (state == 5) {
    drive(3);
    delay(300);
    turnRight();
    delay(1000);
    drive(3);
    delay(200);
    state++;
  } else if (state == 6) {
    dropBlock();
    drive(0);
    state++;
  } else {
    drive(0);
  }
}
