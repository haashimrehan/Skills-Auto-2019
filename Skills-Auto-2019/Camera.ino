void pickBlock() {
  readPing();
  cam.getSpecialBlocks(block);
  if (fPing < 11 && fPing != 0) {
    claw.write(180);
    drive(3);
    delay(500);
    drive(0);
    delay(500);
    drive(-4);
    delay(1000);
    state++;
  } else {
    pointToBlock(cam.blocks[0], 18);
  }
}

void pickBlock(int distance, int blockAccuracy) {
  readPing();
  cam.getSpecialBlocks(block);
  if (frontButton == LOW) { //fPing < distance && fPing != 0) {
    claw.write(180);
    //drive(3);
    //delay(500);
    drive(0);
    delay(500);
    if (layout == 5) {
      drive(-4);
      delay(650);
    } else if (layout != 4) {
      drive(-4);
      delay(800);
    }
    state++;
  } else {
    if (layout == 2) {
      if (cam.blocks[0].x <= 80 && cam.getBlock() && (block == RED || block == BLUE)) {
        pointToBlock(cam.blocks[1], blockAccuracy);
      } else {
        pointToBlock(cam.blocks[0], blockAccuracy);
      }
    } else {
      pointToBlock(cam.blocks[0], blockAccuracy);
      // Serial.println(fPing);
    }
  }
}

void pickBlockPID(int distance) {
  if (fPing < distance && fPing != 0) {
    claw.write(180);
    drive(3);
    delay(500);
    drive(0);
    delay(500);
    drive(-4);
    delay(1000);
    state++;
  } else {
    pointToBlockPID(cam.blocks[0]);
  }
}
void pointToBlock (Block target, int hedge) {//Points to a Block that is sent in
  if (cam.getBlock()) { //Check if there is blocks
    alignRobot(target, hedge);
  } else {
    delay(20);
    if (cam.getBlock()) { //check again
      alignRobot(target, hedge);
    } else { //There are no blocks
      noBlock = true;
      Serial.println("No Block Detected");
    }
  }
}

boolean pointToBlockPID (Block target) {//Points to a Block that is sent in
  if (cam.getBlock()) { //Check if there is blocks
    return alignRobotPID(target);
  } else {
    delay(20);
    if (cam.getBlock()) { //check again
      return alignRobotPID(target);
    } else { //There are no blocks
      noBlock = true;
      Serial.println("No Block Detected");
      return false;
    }
  }
}

boolean alignRobotPID(Block target) {
  int width = 320; // pixy cam pixel width
  noBlock = false;

  // Input: target.x Block Position
  // Setpoint: width/2
  // Output: Motor Power
  SetpointB = 160;
  InputB = target.x;
  blockPID.Compute();
  /*Serial.print(InputB);
    Serial.print("  ");
    Serial.print(SetpointB);
    Serial.print("  ");
    Serial.print(OutputB);
    Serial.println();*/
  int leftS =  - OutputB;
  int rightS =   OutputB;
  drive(leftS, rightS);

  /*int straightSpeed = 15;
    int rightSpeed = straightSpeed + OutputB;
    int leftSpeed = straightSpeed - OutputB;

    driveArdumoto(MOTOR_A, REVERSE, abs(leftSpeed));
    driveArdumoto(MOTOR_B, FORWARD, abs(rightSpeed));
  */
}

void alignRobot(Block target, int hedge) {
  int width = 350; // pixy cam width
  //noBlock = false;
  turnSpeed = 70; //80
  //Serial.print(target.x);
  //Serial.print("  ");

  if (target.x > (width / 2) + hedge) {
    //Turns Right until the blocks x val is within a range
    turnRight();
    // delay(100);
    // driveArdumoto(MOTOR_B, REVERSE, 100);
    //driveArdumoto(MOTOR_A, REVERSE, 50);
    //   Serial.println("RIGHT");
  }
  else if (target.x < (width / 2) - hedge) {
    //Turns Left until the blocks x val is within a range
    //   Serial.println("LEFT");
    // driveArdumoto(MOTOR_B, FORWARD, 50);
    // driveArdumoto(MOTOR_A, FORWARD, 100);
    //drive(0,100);
    turnLeft();
    //delay(100);
  }
  else if ((target.x > (width / 2) - hedge && target.x < (width / 2) + hedge) || fPing < 18) {
    //Stops once the block is within a range
    //Serial.println("CENTER");
    driveSlow(9); //3
    //delay(300);
  }
}
