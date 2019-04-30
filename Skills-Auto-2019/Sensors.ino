
void followLine() {
  //0 = white; 1 = black
  if (cSense == BLACK) {
    drive(3);
    //Serial.println("F");
  }
  else if (lSense == BLACK) {
    turnRight();
    // Serial.println("L");
  }
  else if (rSense == BLACK) {
    turnLeft();
    // Serial.println("R");
  }

}

void readPing() {
  fPingSens.ping_median(2);
  fPing = fPingSens.ping();
  fPing /= US_ROUNDTRIP_CM;
  //Serial.println(fPing);
}

void readLines() {
  lSense = digitalRead(6);
  cSense = digitalRead(5);
  rSense = digitalRead(4);


  Serial.print(lSense);
  Serial.print(" ");
  Serial.print(cSense);
  Serial.print(" ");
  Serial.print(rSense);
  Serial.println();

}

void updateSensors() {
  cam.getSpecialBlocks(block);
  readLines();
  readPing();
  // gyroUpdate();
}
