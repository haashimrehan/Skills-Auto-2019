#include "PixyLib.h"
#include <NewPing.h>
#include <Servo.h>

#include "I2Cdev.h"
#include "MPU6050_6Axis_MotionApps20.h"
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

#include <PID_v1.h>

//Block PID
double SetpointB, InputB, OutputB;
double KpB = 5, KiB = 0, KdB = 10;
PID blockPID(&InputB, &OutputB, &SetpointB, KpB, KiB, KdB, DIRECT);

//turningPID
double SetpointT, InputT, OutputT;
double KpT = 11, KiT = 2, KdT = 1; //10,0,1  //9,2,1
PID turnPID(&InputT, &OutputT, &SetpointT, KpT, KiT, KdT, DIRECT);

//drivePID
double SetpointD, InputD, OutputD;
double KpD = 10, KiD = 0, KdD = 1;
PID drivePID(&InputD, &OutputD, &SetpointD, KpD, KiD, KdD, DIRECT);

MPU6050 mpu;

#define WHITE 0
#define BLACK 1

//Servos
Servo claw;
Servo head; //Limits Up:60 Down:30

// Clockwise and counter-clockwise definitions.
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

const int startTurnSpeed = 105;
int turnSpeed = startTurnSpeed;

//Camera
PixyLib cam;
//Colour Signatures that are programmed in PixyMon
#define YELLOW 1
#define BLUE 2
#define RED 3
Block blocks[10];
int midPos;
float mid = 0, sum = 0;
boolean noBlock;

//Ultrasonic Sensor
NewPing fPingSens(7, 7);
int fPing; //distance from ultrasonic
int frontButton = 1;

//Line Sensors
int lSense = 0;
int cSense = 0;
int rSense = 0;

int block; // 1 Yellow; 2 Blue; 3 Red
int state;
int layout; // The layout of the field (1-6)
double currentAngle = 0;

double absoluteAngle = 0;

void setup() {
  Serial.begin(115200);
  setupArdumoto(); // Set all pins as outputs
  claw.attach(9);
  head.attach(10);
  cam.begin();
  claw.write(0); // Start claw open
  setHead(2);

  gyroSetup();
  pinMode(8, INPUT_PULLUP);
  pinMode(7, INPUT);
  //Line sensors
  pinMode(6, INPUT);
  pinMode(5, INPUT);
  pinMode(4, INPUT);
  pinMode(17, INPUT_PULLUP);
  int startButton = digitalRead(8);
  frontButton = digitalRead(17);
  state = 0;
  layout = 6;

  // Initial color block to pick up
  if (layout == 1) {
    block = YELLOW;
  } else if (layout == 2) {
    block = RED;
  } else if (layout == 3) {
    block = YELLOW; //RED;
  } else if (layout == 4) {
    block = BLUE;
  } else if (layout == 5) {
    block = BLUE;
  } else if (layout == 6) {
    block = YELLOW;
  } else {
    block = RED;
  }

  long start = millis();
  while (millis() - start < 3500 || startButton == HIGH) {
    Serial.print(".");
    startButton = digitalRead(8);
    //Serial.println(startButton);
    gyroUpdate();
  }
  absoluteAngle = currentAngle;

  initPID();
  delay(500);
}

void initPID() {
  //blockPID
  InputB = 160;
  SetpointB = 160;
  blockPID.SetMode(AUTOMATIC);
  blockPID.SetOutputLimits(-200, 200);

  //turnPID
  InputT = currentAngle;
  SetpointT = 0;
  turnPID.SetMode(AUTOMATIC);
  turnPID.SetOutputLimits(-170, 170);

  //drivePID
  InputT = currentAngle;
  SetpointT = 0;
  drivePID.SetMode(AUTOMATIC);
  drivePID.SetOutputLimits(-255, 255);
}

void loop() {

  if (layout == 1) {
    layoutOne();
  } else if (layout == 2) {
    layoutTwo();
  } else if (layout == 3) {
    layoutThree();
  } else if (layout == 4) {
    layoutFour();
  } else if (layout == 5) {
    layoutFive();
  } else if (layout == 6) {
    layoutSix();
  }
}
