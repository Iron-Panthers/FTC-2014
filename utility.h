#include "JoystickDriver.c"

const float ROBOT_RATE = 200;	//measure this to find real value
const float MOTOR_SPEED = 75;
const float RADIUS = 5; //measure this to find real value

void turn(float degrees)
{
	float rad = degrees * PI/180;
	float distance = rad * RADIUS;
	float time = distance/ROBOT_RATE;
	time = time * 1000;

	if (degrees > 0)
	{
		motor[left] = MOTOR_SPEED;
		motor[right] = 0;
	    wait1Msec(time);
		motor[left] = 0;
		motor[right] = 0;
	}
	else if (degrees < 0)
	{
		motor[left] = 0;
		motor[right] = MOTOR_SPEED;
		wait1Msec(time);
		motor[right] = 0;
		motor[left] = 0;
	}
}

void turnTwoWheels(float degrees)
{
	float rad = degrees * PI/180;
	float distance = rad * RADIUS;
	float time = distance/ROBOT_RATE;
	time = time * 1000;

	if (degrees > 0)
		{
			motor[left] = MOTOR_SPEED;
			motor[right] = -MOTOR_SPEED;
			wait1Msec(time);
			motor[left] = 0;
			motor[right] = 0;
		}
	else if (degrees < 0)
	{
		motor[left] = -MOTOR_SPEED;
		motor[right] = MOTOR_SPEED;
		wait1Msec(time);
		motor[right] = 0;
		motor[left] = 0;
	}
}

void move(float distance)
{
	float waitTime = distance/ROBOT_RATE;
	waitTime = abs(waitTime) * 1000;
	if (distance > 0)
	{
		motor[left] = MOTOR_SPEED;
		motor[right] = MOTOR_SPEED;
	}
	else if (distance < 0)
	{
		motor[left] = -MOTOR_SPEED;
		motor[right] = -MOTOR_SPEED;
	}
	wait1Msec(waitTime);
	motor[left] = 0;
	motor[right] = 0;
}

float quadraticJoystick (float x)
{
	float y = .0119 * x * x - .2834 * x;
	return y;
}

void joystickControl()
{
	getJoystickSettings(joystick);
	if (joy1Btn(3))
	{
		servo[lockServo] = 182;
	}
	else if(joy1Btn(4))
	{
		servo[lockServo] = 140;
	}

	if (joy1Btn(1))
	{
		motor[motorD] = -10;
	}
	else if(joy1Btn(2))
	{
		motor[motorD] = 10;
	}
	else
	{
		motor[motorD] = 0;
	}

	if (abs(joystick.joy1_y1) >  10 || abs(joystick.joy1_y2) > 10)
	{
    motor[left] = quadraticJoystick(joystick.joy1_y1);
    motor[right] = quadraticJoystick(joystick.joy1_y2);
	}
	else
	{
		motor[left] = 0;
		motor[right] = 0;
	}
}
