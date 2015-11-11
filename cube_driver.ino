#include <StepperMulti.h>


#include <EEPROM.h>

//#include <Stepper.h>
int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int in5Pin = 8;
int in6Pin = 7;
int in7Pin = 6;
int in8Pin = 5;
int in9Pin = 53;
int in10Pin = 52;
int in11Pin = 51;
int in12Pin = 50;
int in13Pin = 49;
int in14Pin = 48;
int in15Pin = 47;
int in16Pin = 46;

int in17Pin = 45;
int in18Pin = 44;
int in19Pin = 43;
int in20Pin = 42;
int in21Pin = 41;
int in22Pin = 40;
int in23Pin = 39;
int in24Pin = 38;
int in25Pin = 37;
int in26Pin = 36;
int in27Pin = 35;
int in28Pin = 34;
int in29Pin = 33;
int in30Pin = 32;
int in31Pin = 31;
int in32Pin = 30;


StepperMulti motor1(96, in1Pin, in2Pin, in3Pin, in4Pin);
StepperMulti motor2(96, in5Pin, in6Pin, in7Pin, in8Pin);
StepperMulti motor3(96, in9Pin, in10Pin, in11Pin, in12Pin);
StepperMulti motor4(96, in13Pin, in14Pin, in15Pin, in16Pin);

StepperMulti motor5(96, in17Pin, in18Pin, in19Pin, in20Pin);
StepperMulti motor6(96, in21Pin, in22Pin, in23Pin, in24Pin);
StepperMulti motor7(96, in25Pin, in26Pin, in27Pin, in28Pin);
StepperMulti motor8(96, in29Pin, in30Pin, in31Pin, in32Pin);

void setup()
{
  pinMode(in1Pin,OUTPUT);
  pinMode(in2Pin,OUTPUT);
  pinMode(in3Pin,OUTPUT);
  pinMode(in4Pin,OUTPUT);
  pinMode(in5Pin,OUTPUT);
  pinMode(in6Pin,OUTPUT);
  pinMode(in7Pin,OUTPUT);
  pinMode(in8Pin,OUTPUT);
  pinMode(in9Pin,OUTPUT);
  pinMode(in10Pin,OUTPUT);
  pinMode(in11Pin,OUTPUT);
  pinMode(in12Pin,OUTPUT);
  pinMode(in13Pin,OUTPUT);
  pinMode(in14Pin,OUTPUT);
  pinMode(in15Pin,OUTPUT);
  pinMode(in16Pin,OUTPUT);

  pinMode(in17Pin,OUTPUT);
  pinMode(in18Pin,OUTPUT);
  pinMode(in19Pin,OUTPUT);
  pinMode(in20Pin,OUTPUT);
  pinMode(in21Pin,OUTPUT);
  pinMode(in22Pin,OUTPUT);
  pinMode(in23Pin,OUTPUT);
  pinMode(in24Pin,OUTPUT);
  pinMode(in25Pin,OUTPUT);
  pinMode(in26Pin,OUTPUT);
  pinMode(in27Pin,OUTPUT);
  pinMode(in28Pin,OUTPUT);
  pinMode(in29Pin,OUTPUT);
  pinMode(in30Pin,OUTPUT);
  pinMode(in31Pin,OUTPUT);
  pinMode(in32Pin,OUTPUT);
  while (!Serial);
  
  Serial.begin(9600);
  motor1.setSpeed(50);
  motor2.setSpeed(50);
  motor3.setSpeed(50);
  motor4.setSpeed(50);
  
  motor5.setSpeed(50);
  motor6.setSpeed(50);
  motor7.setSpeed(50);
  motor8.setSpeed(50);
}

void loop()
{
  if (Serial.available())
  {
    int steps = Serial.parseInt();
 // motor1.setStep(steps);
  motor4.setStep(steps);
 // motor8.setStep(steps);
  }
//  motor1.moveStep();
  motor4.moveStep();
//  motor8.moveStep();
}
