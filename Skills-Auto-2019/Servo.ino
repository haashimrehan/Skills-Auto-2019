void setHead(int angle) {
  //Lower 30, Higher 60
  head.write(map(angle, 0, 10, 30, 60));
}

void testHead() {
  for (int i = 0; i <= 10; i++) {
    setHead(i);
    delay(1000);
  }
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
