// TODO
// fix - Robot Drives Backwards forever after picking up block
#include "PixyLib.h"
#include <NewPing.h>
#include <Servo.h>

//Default Parameters
void findLine(int driveSpeed = 3);

#define WHITE 0
#define BLACK 1

//Servos
Servo claw;
Servo head; //Limits Up: Down:

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  0
#define REVERSE 1

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 12 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 13 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

int turnSpeed = 80;

//Camera
PixyLib cam;
//Colour Signatures that are programmed in PixyMon
#define YELLOW 1
#define BLUE 2
#define RED 3
#define GREEN 5
Block blocks[10];
int midPos;
float mid = 0, sum = 0;
boolean noBlock;

//Ultrasonic Sensor
NewPing fPingSens(7, 7);
int fPing;

//Line Sensors
int lSense = 0;
int cSense = 0;
int rSense = 0;

int state = 0;

void setup() {
  Serial.begin(9600);
  setupArdumoto(); // Set all pins as outputs
  claw.attach(9);
  head.attach(10);
  cam.begin();
  claw.write(0); // Start claw open
  setHead(9);
  //head.write();//
  //Line sensors
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
}

void loop() {
testHead();
}

void layout() {
  cam.getSpecialBlocks(RED);
  readPing();

  /*
    Drive Forward
    Turn Left a little
    Look for Lines
    Align with line
    PickBlock
  */
  readLines();
  // followLine();
  //   pickBlock();

  //cam.printBlocks();
  //pointToBlock(cam.blocks[0], 20);


  if (state == 0) {
    findLine();
  } else if (state == 1) {
    followLine();
    if (cSense == BLACK) {
      drive(0);
      state = 2;
    }
  } else if (state == 2) { // Picks Up Block
    pickBlock();
  } else if (state == 3) { // Reverse
    delay(-4);
    delay(1500);
    turnLeft();
    delay(1500);
    drive(5);
    delay(2000);
    while (1) {
      drive(0);
    }
  }
  /*drive(-4);
    delay(1000);
    turnSpeed = 75;
    turnLeft();
    //   delay(1000);
    if (pointToBlock(cam.blocks[0], 20)) {
    drive(0);
    state = 4;
    }

    } else if (state == 4) {
    turnSpeed = 80;
    long startTime = millis();
    while (millis() - startTime < 3000) { // time to drive to drop off location
    pointToBlock(cam.blocks[0], 20);
    }
    drive(0);
    state = 5;
    } else if (state == 5) {
    drive(0);
    }
  */

}
