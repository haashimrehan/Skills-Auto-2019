#ifndef tl
#define tl

#if (ARDUINO >=100)
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include <TPixy.h>
#include <PixyI2C.h>
#include <Wire.h>


class PixyLib {
  public:
    //Constructor
    PixyLib();
    
    //Methods
    void begin();
    float getMidpoint (Block _blocks []);
    void getSpecialBlocks (int signiture);
    void printBlocks();

    //Objects
    bool getBlock();
    PixyI2C pixy;
    Block blocks[10];
  private:


};
#endif
