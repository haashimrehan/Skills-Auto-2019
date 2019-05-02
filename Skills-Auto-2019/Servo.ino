void setHead(int angle) {
  //Lower 30, Higher 60
  head.write(map(angle, 0, 10, 30, 60));
}

void dropBlock() {
  drive(0);
  delay(500);
  claw.write(0);
}
