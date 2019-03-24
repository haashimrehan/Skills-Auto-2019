#include "PixyLib.h"
#include <NewPing.h>
#include <Servo.h>

//Default Parameters
void findLine(int driveSpeed = 3);

#define WHITE 0
#define BLACK 1

//Servos
Servo claw;
Servo head; //Limits Up:60 Down:30

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

int state;

void setup() {
  Serial.begin(9600);
  setupArdumoto(); // Set all pins as outputs
  claw.attach(9);
  head.attach(10);
  cam.begin();
  claw.write(0); // Start claw open
  setHead(2);
  //Line sensors
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  state = 0;
}

void loop() {
  //   setHead(7);
  //drive(0);

  //pickBlock();
 // layoutTwo();
  drive(10);
  //    turnLeft();

}


void layoutTwo() {
  /*
    Drive Forward
    Turn Left
    Look for Lines
    Align with line
    PickBlock
  */
  cam.getSpecialBlocks(RED);
  readPing();
  readLines();

  if (state == 0) {
    Serial.println(state);
    turnLeft();
    delay(600);
    drive(4);
    delay(1200);
    /*  drive(4);
      delay(1000);
      turnLeft();
      delay(1000);
      drive(4);
      delay(500);*/
    state = 1;

  } else if (state == 1) {

    Serial.println(state);
    findLine();

  } else if (state == 2) {
    Serial.println(state);
    long start = millis();
    while (millis() - start < 1100) {
      readLines();
      followLine();
    }
    drive(-2);
    delay(500);
    drive(0);
    delay(200);
    state++;


  } else if (state == 3) { // Picks Up Block

    pickBlock();
  } else if (state == 4) { // Reverse
    Serial.println(state);
    turnSpeed = 90;
    drive(-3);
    delay(1000);
    turnLeft();
    delay(2000);
    drive(5);
    delay(2000);
    state = 5;
  } else if (state == 5) {
    /* turnSpeed = 80;
      long startTime = millis();
      while (millis() - startTime < 3000) { // drive to drop off location
       pointToBlock(cam.blocks[0], 20);
      }
      drive(0);
    */
    drive(0);
    claw.write(0);
    state = 6;
  } else if (state == 6) {
    drive(0);
  } else {
    drive(-2);
  }
}
