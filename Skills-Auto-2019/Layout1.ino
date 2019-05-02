void layoutOne() {
  /*
     Turn Right
     drive forward
     Look for lines
     Pickblock YELLOW
     Reverse
     Turn left
     Drive forward
     Drop off
  */

  if (state == 0) {
    turnRightAbsolute(40);
    straightPID(2000);
    state = 1;

  } else if (state == 1) {
    findLinePID();
  } else if (state == 2) { //Face block Direction
    drive(-2);
    delay(100);
    drive(0);

    if (block == YELLOW) {
      turnRightAbsolute(130);
    } else if (block == BLUE) {
      turnRightAbsolute(45);
    } else if (block == RED) {
      turnRightAbsolute(-45);
    }

    delay(200);
    drive(-3);
    delay(700);
    drive(0);
    delay(1250);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 18); //9, 18
  } else if (state == 4) { // Reverse. Face Drop Direction
    //Serial.println(state);
    drive(-2);
    delay(75);
    drive(0);
    delay(700);

    if (block == YELLOW) {
      turnLeftAbsolute(-55);
    } else if (block == BLUE) {
      turnLeftAbsolute(30);
    } else if (block == RED) {
      turnLeftAbsolute(120);
    }

    drive(0);
    delay(800);
    drive(5);
    if (block == YELLOW) {
      delay(2400);
    } else if (block == BLUE) {
      delay(2500);
    } else if (block == RED) {
      delay(2500);
    }

    state = 5;
  } else if (state == 5) { //drop Block
    dropBlock();
    state = 6;
  } else if (state == 6) {//turn for next block
    drive(-3);
    delay(600);
    if (block == YELLOW) {
      turnLeftAbsolute(35);
    } else if (block == BLUE) {
      turnLeftAbsolute(125);
    } else if (block == RED) {
      while (true) {
        drive(0);
      } // turnLeftAbsolute(-13);
    }

    drive(0);
    delay(1000);

    straightPID(2000);

    if (block > 3) { //Stop once picked and dropped 3 blocks
      state = 100;
    }
    block++; //go for next Block (Yellow > Blue > Red)
    state = 1; //Start again but with new block
  } else if (state > 6) {
    while (true) {
      drive(0);
    }
  }
}
