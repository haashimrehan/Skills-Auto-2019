void pickBlock() {
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
    pointToBlock(cam.blocks[0], blockAccuracy);
  }
}

boolean pointToBlock (Block target, int hedge) {//Points to a Block that is sent in
  if (cam.getBlock()) { //Check if there is blocks
    return alignRobot(target, hedge);
  } else {
    delay(20);
    if (cam.getBlock()) { //check again
      return alignRobot(target, hedge);
    } else { //There are no blocks
      noBlock = true;
      Serial.println("No Block Detected");
      return false;
    }
  }
}

boolean alignRobot(Block target, int hedge) {
  int width = 320; // pixy cam width
  noBlock = false;
  turnSpeed = 70;
  if (target.x > width / 2 + hedge) {
    //Turns Right until the blocks x val is within a range
    turnRight();
    //  Serial.println("RIGHT");
  }
  else if (target.x < width / 2 - hedge) {
    //Turns Left until the blocks x val is within a range
    //Serial.println("LEFT");
    turnLeft();
  }
  else if (target.x > width / 2 - hedge && target.x < width / 2 + hedge) {
    //Stops once the block is within a range
    //Serial.println("CENTER");
    drive(2);
    return true;
  }
  return false;
}
