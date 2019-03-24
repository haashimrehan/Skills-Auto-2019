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

int turnSpeed = 105;
const int startTurnSpeed = 105;

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
 //testClaw();
  layoutOne();
}
