void testCamera() {
  cam.getSpecialBlocks(RED);
  cam.printBlocks();
}

void testClaw() { //180 close. 0 open.
  for (int pos = 0; pos <= 180; pos += 1) {
    claw.write(pos);
    delay(15);
  }
  for (int pos = 180; pos >= 0; pos -= 1) {
    claw.write(pos);
    delay(15);
  }
}

void testHead() {
  for (int i = 0; i <= 10; i++) {
    setHead(i);
    delay(1000);
  }
}

void testDriving() {
  drive(10);
  delay(2000);
  turnLeft();
  delay(2000);
  turnRight();
  delay(2000);
  drive(-10);
  delay(2000);
}
