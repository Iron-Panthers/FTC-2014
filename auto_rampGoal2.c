#pragma config(Hubs,  S3, HTMotor,  HTMotor,  HTServo,  none)
#pragma config(Sensor, S1,     HTSPB,          sensorI2CCustom9V)
#pragma config(Sensor, S2,     ultra,          sensorSONAR)
#pragma config(Sensor, S3,     HTSPB,          sensorNone)
#pragma config(Sensor, S4,     touch,          sensorTouch)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop, encoder)
#pragma config(Motor,  mtr_S3_C1_1,     left,          tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C1_2,     right,         tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_1,     goalLock,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S3_C2_2,     belt,          tmotorTetrix, openLoop)
#pragma config(Servo,  srvo_S3_C3_1,    servo1,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_2,    servo2,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_3,    servo3,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_4,    servo4,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_5,    servo5,               tServoNone)
#pragma config(Servo,  srvo_S3_C3_6,    raiseBelt,            tServoContinuousRotation)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "utility.h"
#include "encoders.h"

task main ()
{
    motor[left] = -75;
    motor[right] = -75;
    timer[T1] = 0;

    bool touched = false;
    while (!touched)
    {
        touched = SensorValue[touch];
        if (time1[T1] > 3000 || touched)
            break;
    }
    if (touched)
        StartTask(lowerLockMotor);

    motor[left] = -25;
    motor[right] = -25;





}
