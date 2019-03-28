int blockL1 = 1;
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


  //cam.getSpecialBlocks(YELLOW);
  cam.getSpecialBlocks(blockL1);

  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnRight();
    delay(650);
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
    turnSpeed = startTurnSpeed;
    drive(-3);
    delay(100);
    turnLeft();
    delay(800);
    drive(5);
    delay(1700);
    state = 5;
  } else if (state == 5) { //drop Block
    drive(0);
    delay(500);
    claw.write(0);
    state = 6;
  } else if (state == 6) {//turn for next block
    turnLeft();
    delay(1000);
    drive(4);
    if (blockL1 > 3) { //Stop once picked and dropped 3 blocks
      state = 10000;
    }
    blockL1++; //go for next Block (Yellow > Blue > Red)
    state = 1; //Start again but with new block
  } else {
    drive(0);
  }
}


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
  cam.getSpecialBlocks(RED);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnRight();
    delay(300);
    drive(3);
    delay(200);
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
    delay(1500);
    drive(5);
    delay(2000);
    turnRight();
    delay(2000);
    drive(5);
    delay(3000);
    state = 5;
  } else if (state == 5) {
    drive(0);
    delay(500);
    claw.write(0);
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(0);
  }

}

void layoutFour() {
  /*
    drive forward
    Pickblock YELLOW
    Reverse
    Turn Right
    Drive Forward
    Drop off
  */
  cam.getSpecialBlocks(YELLOW);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    drive(4);
    delay(500);
    state = 1;

  } else if (state == 1) { // Picks Up Block
    pickBlock(9, 18);
  } else if (state == 2) { // Reverse
    Serial.println(state);
    turnSpeed = startTurnSpeed;
    drive(-3);
    delay(150);
    turnRight();
    delay(1000);
    drive(5);
    delay(1500);
    state = 3;
  } else if (state == 3) { //drop Block
    drive(0);
    delay(500);
    claw.write(0);
    state = 4;
  } else if (state == 4) {
    drive(0);
  } else {
    drive(-2);
  }
}

void layoutFive() {
  /*
     TL + F
     Look for lines
     align with line
     PickBlock
     Reverse + 180 Turn
     F + Drop off block
  */
  cam.getSpecialBlocks(RED);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnLeft();
    delay(400);
    drive(4);
    state = 1;
  } else if (state == 1) { // Look for lines
    findLine();
  } else if (state == 2) { //Align with line for 1100ms
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
  } else if (state == 4) { // Reverse Drive to destination
    Serial.println(state);
    turnSpeed = startTurnSpeed;
    drive(-3);
    delay(150);
    turnRight();
    delay(3000);
    drive(3);
    delay(200);
    state++;
  } else if (state == 5) { //drop Block
    drive(0);
    delay(500);
    claw.write(0);
    state++;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(-2);
  }

}

void layoutSix() {
  /*
     F + TR
     Look for lines
     Pick block
     reverse until hits back wall
     F + TR + F
     Drop Block
  */

  cam.getSpecialBlocks(YELLOW);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    drive(3);
    delay(500);
    turnRight();
    delay(2000);
    state = 1;

  } else if (state == 1) {
    Serial.println(state);
    findLine();

  } else if (state == 2) {
    Serial.println(state);
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
    Serial.println(state);
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
    drive(0);
    delay(500);
    claw.write(0);
    drive(0);
    state++;
  } else {
    drive(0);
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
    delay(500);
    claw.write(0);
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(0);
  }
}
