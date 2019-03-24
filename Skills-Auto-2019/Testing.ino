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
