#pragma config(Hubs,  S4, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S4,     ,               sensorI2CMuxController)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S4_C1_1,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C1_2,     left,          tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S4_C2_1,     extender,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S4_C2_2,     intakeMotor,   tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S4_C3_1,    servo1,               tServoStandard)
#pragma config(Servo,  srvo_S4_C3_2,    servo2,               tServoContinuousRotation)
#pragma config(Servo,  srvo_S4_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S4_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S4_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S4_C3_6,    servo6,               tServoNone)
#include "utility.h"

task main()
{
    waitForStart();
    servo[servo2] = 15 ;
   closeGoalServo(false);
   wait1Msec(2000);
    move(-0.7);
    slowMove(-0.4);
    closeGoalServo(true);
    stopRobot(300);
    turn(50);
    stopRobot(50);
    move(2.3);
    servo[servo2] = 128;
    stopRobot(50);
    turn(60);
    stopRobot(50);
    move(0.3);
    motor[extender] = 10;
    wait1Msec(8000);
    motor[extender] = 0;


}
