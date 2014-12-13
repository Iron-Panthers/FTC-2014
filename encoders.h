#include "JoystickDriver.c"

const float MOVE_RATE = .530; //Remeasure in imperial (inches per second)
const float MOTOR_SPEED = 75;
const float RADIUS = 18.7;  //Remeasure in imperial (inches)
const float TURN_RATE = 23; //Measure in imperial (inches)

void resetEncoders()
{
	nMotorEncoder[left] = 0;
	nMotorEncoder[right] = 0;
}

void resetDriveMotors()
{
	motor[left] = 0;
	motor[right] = 0;
}

void stopRobot(int forMilliseconds)
{
    motor[left] = 0;
    motor[right] = 0;
    wait1Msec(forMilliseconds);
}

//Wheel diameter = 3 inches
void move(float distance) //Inches
{
	resetEncoders();
	float waitTime = abs(distance) / MOVE_RATE;
	waitTime *= 1000;
	float x = abs(distance) / 3 * PI;
	nMotorEncoderTarget[left] = x;
	nMotorEncoderTarget[right] = x;
	if (distance < 0)
	{
	    motor[left] = -MOTOR_SPEED;
	    motor[right] = -MOTOR_SPEED;
    }
	else if (distance > 0)
	{
	    motor[left] = MOTOR_SPEED;
	    motor[right] = MOTOR_SPEED;
    }
    wait1Msec(waitTime);
	resetDriveMotors();
}

void turn(float degrees)
{
	resetEncoders();
	float rad = degrees * PI / 180;
	float distance = rad * RADIUS;
	float waitTime = distance / MOVE_RATE;
	float x = distance / 3 * PI;
	nMotorEncoderTarget[left] = x;
	nMotorEncoderTarget[right] = x;
	waitTime = abs(waitTime) * 1000;

	if (degrees > 0)
	{
		motor[left] = MOTOR_SPEED;
		motor[right] = 0;
		wait1Msec(waitTime);
		resetDriveMotors();
	}

	else if (degrees < 0)
	{
		motor[left] = 0;
		motor[right] = MOTOR_SPEED;
		wait1Msec(waitTime);
		resetDriveMotors();
	}
}

void turnTwoWheels(float degrees)
{
	resetEncoders();
	float rad = degrees * PI / 180;
	float distance = rad * RADIUS;
	float waitTime = distance / TURN_RATE;
	float x = distance / 3 * PI;
	nMotorEncoderTarget[left] = x;
	nMotorEncoderTarget[right] = x;
	waitTime = abs(waitTime) * 1000;

	if (degrees > 0)
	{
		motor[left] = MOTOR_SPEED;
		motor[right] = -MOTOR_SPEED;
		wait1Msec(waitTime);
		resetDriveMotors();
	}

	else if (degrees < 0)
	{
		motor[left] = -MOTOR_SPEED;
		motor[right] = MOTOR_SPEED;
		wait1Msec(waitTime);
		resetDriveMotors();
	}
}
