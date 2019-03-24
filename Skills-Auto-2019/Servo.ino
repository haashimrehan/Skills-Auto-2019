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

