void layoutOneOld() {
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

  updateSensors();

  if (state == 0) {
    turnRight();
    delay(600);
    drive(4);
    delay(1000);
    state = 1;

  } else if (state == 1) {
    findLine();
  } else if (state == 2) { //follow line for 1100 ms
    turnRight();
    delay(400);

    long start = millis();
    while (millis() - start < 1100) {
      readLines();
      followLine();
    }

    drive(-3);
    delay(400);
    drive(0);
    delay(200);
    state++;
  } else if (state == 3) { // Picks Up Block
    pickBlock(9, 19);
  } else if (state == 4) { // Reverse
    Serial.println(state);
    drive(-3);
    delay(100);
    // FREEZE HERE (Competition)
    while (true) {
      drive(0);
    }
    turnLeft();
    delay(1020);
    drive(5);
    delay(2200);
    state = 5;
  } else if (state == 5) { //drop Block
    drive(0);
    delay(500);
    claw.write(0);
    state = 6;
  } else if (state == 6) {//turn for next block
    turnSpeed = startTurnSpeed;
    drive(-3);
    delay(600);
    turnLeft();
    if (block == YELLOW) { //make exceptions with certain blocks
      delay(1075);
    } else {
      delay(1050);
    }
    drive(4);
    if (block > 3) { //Stop once picked and dropped 3 blocks
      state = 10000;
    }
    block++; //go for next Block (Yellow > Blue > Red)
    state = 1; //Start again but with new block
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
  updateSensors();

  if (state == 0) {
    turnLeft();
    delay(600);
    drive(4);
    delay(1200);
    state = 1;
  } else if (state == 1) {
    findLine();
  } else if (state == 2) {

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
    drive(-3);
    delay(1000);
    turnLeft();
    delay(2000);
    drive(5);
    delay(2000);
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

  updateSensors();

  if (state == 0) {
    turnRight();
    delay(300);
    drive(3);
    delay(200);
    state = 1;

  } else if (state == 1) {
    findLine();
  } else if (state == 2) {

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

  updateSensors();

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
  updateSensors();

  if (state == 0) {
    turnLeft();
    delay(400);
    drive(4);
    state = 1;
  } else if (state == 1) { // Look for lines
    findLine();
  } else if (state == 2) { //Align with line for 1100ms
    turnRight();
    delay(500);

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

  updateSensors();

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
    drive(0);
    delay(500);
    claw.write(0);
    drive(0);
    state++;
  } else {
    drive(0);
  }
}
