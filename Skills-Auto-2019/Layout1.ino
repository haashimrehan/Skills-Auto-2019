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

  // updateSensors();

  if (state == 0) {
    turnRightAbsolute(40);
    //turnRightPID(40);
    // turn(40);
    straightPID(2000);
    state++;

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
    //turnRightPID(90);
    //   turn(90);
    delay(200);
    drive(-3);
    delay(700);
    drive(0);
    delay(1250);
    state++;
  } else if (state == 3) { // Picks Up Block
    readPing();
    cam.getSpecialBlocks(block);
    pickBlock(9, 18); //9, 18
    //  pickBlockPID(9);
  } else if (state == 4) { // Reverse. Face Drop Direction
    //Serial.println(state);
    drive(-2);
    delay(75);
    drive(0);
    delay(700);
    if (block == YELLOW) {
      turnLeftAbsolute(-55);
    } else if (block == BLUE) {
      turnLeftAbsolute(40);
    } else if (block == RED) {
      turnLeftAbsolute(130);
    }
    drive(0);
    delay(800);
    //   delay(200);
    //turn(-90);
    drive(5);
    delay(2500);
    state = 5;
  } else if (state == 5) { //drop Block
    drive(0);
    delay(500);
    claw.write(0);
    state = 6;
  } else if (state == 6) {//turn for next block
    // turnSpeed = startTurnSpeed;
    drive(-3);
    delay(600);
    if (block == YELLOW) {
      turnLeftAbsolute(40);
    } else if (block == BLUE) {
      turnLeftAbsolute(130);
    } else if (block == RED) {
      turnLeftAbsolute(-13);
    }

    // turnLeftPID(90);

    drive(0);
    delay(1000);

    // turnLeft();
    /*if (block == YELLOW) { //make exceptions with certain blocks
      delay(1075);
      } else {
      delay(1050);
      }*/
    straightPID(2000);
    //    drive(3);
    if (block > 3) { //Stop once picked and dropped 3 blocks
      state = 10000;
    }
    block++; //go for next Block (Yellow > Blue > Red)
    state = 1; //Start again but with new block
  } else if (state > 6) {
    drive(0);
  }
}
