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
    //waitForStart();
    move(1.3);
    stopRobot(50);
    move(-0.77);
    stopRobot(50);
    turn(-90);
    stopRobot(50);
    move(1.45);
    stopRobot(50);
    turn(90);
    stopRobot(50);
    move(1.7);
    stopRobot(50);
    turn(90);
    stopRobot(50);
    move(1.06);
}
