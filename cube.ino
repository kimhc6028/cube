#include <Stepper.h>

int in1Pin = 12;
int in2Pin = 11;
int in3Pin = 10;
int in4Pin = 9;
int in5Pin = 8;
int in6Pin = 7;
int in7Pin = 6;
int in8Pin = 5;
int in9Pin = 4;
int in10Pin = 3;
int in11Pin = 2;
int in12Pin = 1;
int in13Pin = 25;
int in14Pin = 24;
int in15Pin = 23;
int in16Pin = 22;

Stepper motor1(96,in1Pin, in2Pin, in3Pin, in4Pin);
Stepper motor2(96,in5Pin, in6Pin, in7Pin, in8Pin);
Stepper motor3(96,in9Pin, in10Pin, in11Pin, in12Pin);
Stepper motor4(96,in13Pin, in14Pin, in15Pin, in16Pin);

void setup()
{
    Serial.begin(9600);
    pinMode(in1Pin, OUTPUT);
    pinMode(in2Pin, OUTPUT);
    pinMode(in3Pin, OUTPUT);
    pinMode(in4Pin, OUTPUT);
    pinMode(in5Pin, OUTPUT);
    pinMode(in6Pin, OUTPUT);
    pinMode(in7Pin, OUTPUT);
    pinMode(in8Pin, OUTPUT);
    pinMode(in9Pin, OUTPUT);
    pinMode(in10Pin, OUTPUT);
    pinMode(in11Pin, OUTPUT);
    pinMode(in12Pin, OUTPUT);
    pinMode(in13Pin, OUTPUT);
    pinMode(in14Pin, OUTPUT);
    pinMode(in15Pin, OUTPUT);
    pinMode(in16Pin, OUTPUT);
    
    motor1.setSpeed(50);
    motor2.setSpeed(50);
    motor3.setSpeed(50);
    motor4.setSpeed(50);
}

void loop()
{
  if (Serial.available())
  {
 //     int steps = Serial.parseInt();
  //    motor1.step(steps);
    int choose_rotate = Serial.parseInt();
    switch(choose_rotate)
    {
      case(1):
        motor1.step(24);
        break;
      case(2):
        motor2.step(24);
        break;  
      case(3):
        motor3.step(24);
        break;
      case(4):
        motor4.step(24);
        break;
  }
  }
}
