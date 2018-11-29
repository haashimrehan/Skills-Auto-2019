#include <Pixy.h>
#include <PixyI2C.h>
#include <PixySPI_SS.h>
#include <TPixy.h>

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

int turnSpeed = 120;

//Camera
Pixy pixy;
Block blocks[10];
int midPos;
float mid = 0, sum = 0;
int high = 117 ; //Mid Range
int low = 109; // Mid Range


void setup()
{
  Serial.begin(115200);
  pixy.init();//Initializes Camera
  setupArdumoto(); // Set all pins as outputs
}

void loop() {
  for (int i = 0; i < 100; i++) {
    getSpecialBlocks(2);
  }

  pointToBlock(blocks[0], 10);
}


