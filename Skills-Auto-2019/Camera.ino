/*
 * Signatures
 * 1: Yellow Cube
 * 2: Blue Cube
 * 3: Red Cube
 */


float getMidpoint (Block _blocks []) {//Returns the midpoint of the top two blocks in an array
  float midpoint = (_blocks [0].x + _blocks [1].x) * 2;
  return midpoint;
}

boolean pointToBlock (Block target, int hedge) {//Points to a Block that is sent in
  int width = 320; // pixy cam width
  if (target.x > width / 2 + hedge) {
    //Turns Left until the blocks x val is within a range
    turnRight();
    Serial.print("RIGHT");
  }
  else if (target.x < width / 2 - hedge) {
    //Turns Right until the blocks x val is within a range
    turnLeft();
    Serial.print("LEFT");
  }
  else if (target.x > width / 2 - hedge && target.x < width / 2 + hedge) {
    //Stops once the block is within a range
    Serial.print("CENTER");
  //  drive(0);
    return true;
  }
  return false;
}

void getSpecialBlocks (int signiture) { //1-7
  //Block blocks [pixy.getBlocks()] = {NULL};//Makes an Array of Blocks
  //Block blocks [pixy.getBlocks()];//Makes an Array of Blocks
  int numYellow = 0;//Ctr to count how many blocks it has seen
  for (int i = 0; i < pixy.getBlocks(); i++) {
    if (pixy.blocks[i].signature == signiture) {//Checks if signiture of current block matches signiture sent in
      //Pushes  Block into array created earlier
      blocks [numYellow] = (pixy.blocks[i]);
      numYellow++;
    }
  }

  Block swap;
  boolean sorted ;
  while (!sorted) {
    //Bubble Sorts Blocks By x val. widest
    sorted = true;
    for (int i = 0; i < pixy.getBlocks(); i++) {
      if (!blocks [i + 1].x == NULL) {//Breaks Out if next block is null
        if (blocks [i].width > blocks [i + 1].width) {
          //Swaps the index of blocks one is larger then the next one
          swap = blocks [i];
          blocks [i + 1] = blocks [i];
          blocks [i + 1] = swap;
          sorted = false;
        }
      }
    }
  }
  //return blocks;
}
