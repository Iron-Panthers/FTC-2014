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

int sign(int num)
{
    if (num > 0)
        return 1;
    else if (num < 0)
        return -1;
    else
        return 0;
}

float quadraticJoystick (float x)
{
	float y = .0119 * x * x - .2834 * x;
	return sign(x) > 0 ? y : -y;
}

void joystickControl()
{
	getJoystickSettings(joystick);
	if (joy1Btn(3))
	{
		servo[servo1] = 140;
	}
	else if(joy1Btn(2))
	{
		servo[servo1] = 182;
	}

	//Continuous rotation servo
	if (joy1Btn(1))
	{
		servo[servo2] = 100;
	}
	else if(joy1Btn(4))
	{
		servo[servo2] = 156;
	}
	else
	{
		servo[servo2] = 128;
	}

	//Conveyor belt motor
	if (joystick.joy1_TopHat == 4)
	{
		motor[extender] = 10;
	}
	else if (joystick.joy1_TopHat == 6)
	{
		motor[extender] = -10;
	}
	else
	{
		motor[extender] = 0;
	}

	//Drivetrain
	if (abs(joystick.joy1_y1) > 10)
	{
    	motor[left] = -(quadraticJoystick(joystick.joy1_y1));
	}
	else
	{
		motor[left] = 0;
	}
	if (abs(joystick.joy1_y2) > 10)
	{
	    motor[right] = quadraticJoystick(joystick.joy1_y2);
    }
    else
    {
      motor[right] = 0;
    }

    //Intake Motor
    if ((joy1Btn(8)) && (motor[intakeMotor] == 0)) //Toggle intake motor if right on D-Pad
    {
        motor[intakeMotor] = 10;
    }
    else if ((joy1Btn(8)) && (motor[intakeMotor] == 10))
    {
        motor[intakeMotor] = 0;
    }
    if (joy1_TopHat == 0) //Up on D-Pad
    {
        motor[intakeMotor] = 10;
    }
    if (joy1_TopHat == 2) //Right on D-Pad
    {
        motor[intakeMotor] = -10;
    }
   if ((joy1Btn(8)) == 0 &&  joy1_TopHat == -1 ))
   {
       motor[intakeMotor] = 0;
   }
}
