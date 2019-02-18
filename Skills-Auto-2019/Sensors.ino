
void followLine() {
  //0 = white; 1 = black
  if (cSense == 1) {
    drive(3);
    //Serial.println("F");
  }
else if (lSense == 1) {
    turnRight();
   // Serial.println("L");
  }
  else if (rSense == 1) {
    turnLeft();
   // Serial.println("R");
  }

}

void readPing() {
  fPing = fPingSens.ping();
  fPing /= US_ROUNDTRIP_CM;
  // Serial.println(fPing);
}

void readLines() {
  lSense = digitalRead(6);
  cSense = digitalRead(5);
  rSense = digitalRead(4);

  /*
    Serial.print(lSense);
    Serial.print(" ");
    Serial.print(cSense);
    Serial.print(" ");
    Serial.print(rSense);
    Serial.println();*/
}
