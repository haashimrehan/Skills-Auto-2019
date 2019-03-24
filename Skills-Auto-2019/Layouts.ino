void layoutOne() {
  /*
     Turn Right
     drive forward
     Look for lines
     Pickblock YELLOW
     Reverse
     Turn left
     Drive foward
     Drop off
  */
  cam.getSpecialBlocks(YELLOW);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnRight();
    delay(600);
    drive(4);
    delay(1000);
    state = 1;

  } else if (state == 1) {

    Serial.println(state);
    findLine();


  } else if (state == 2) { //follow line for 1100 ms

    turnRight();
    delay(500);
    Serial.println(state);
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
    pickBlock(9, 18);
  } else if (state == 4) { // Reverse
    Serial.println(state);
    turnSpeed = 90;
    drive(-3);
    delay(1000);
    turnLeft();
    delay(2000);
    drive(5);
    delay(2000);
    state = 5;
  } else if (state == 5) {
    drive(0);
    claw.write(0);
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(-2);
  }
}


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
  cam.getSpecialBlocks(RED);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnLeft();
    delay(600);
    drive(4);
    delay(1200);
    /*  drive(4);
      delay(1000);
      turnLeft();
      delay(1000);
      drive(4);
      delay(500);*/
    state = 1;

  } else if (state == 1) {

    Serial.println(state);
    findLine();

  } else if (state == 2) {
    Serial.println(state);
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
    Serial.println(state);
    turnSpeed = 90;
    drive(-3);
    delay(1000);
    turnLeft();
    delay(2000);
    drive(5);
    delay(2000);
    state = 5;
  } else if (state == 5) {
    /* turnSpeed = 80;
      long startTime = millis();
      while (millis() - startTime < 3000) { // drive to drop off location
       pointToBlock(cam.blocks[0], 20);
      }
      drive(0);
    */
    drive(0);
    claw.write(0);
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(-2);
  }
}
