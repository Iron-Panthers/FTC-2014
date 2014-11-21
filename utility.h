#include "JoystickDriver.c"

const float MOVE_RATE = .530;
const float MOTOR_SPEED = 75;
const float RADIUS = .457; //radis in meters

void turn(float degrees)
{
    float adjTurn;

    if (degrees > 0 && degrees < 38)
    {
        adjTurn = .400;
    }
    if (degrees > 38 && degrees < 52)
    {
        adjTurn = .430;
    }
    if (degrees > 52 && degrees < 100)
    {
        adjTurn = .460;
    }
    if (degrees > 100 && degrees <= 360)
    {
        adjTurn = .470;
    }

	float rad = degrees * PI/180;
	float distance = rad * RADIUS;
	float time = distance/adjTurn;
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
    float turnRate;
    if (degrees > 0)
	{
        turnRate = 680;
    }
    if (degrees < 0)
    {
        turnRate = 740;
    }

	float rad = abs(degrees) * PI/180;
	float distance = rad * RADIUS;
	float time = distance/turnRate;
	time = time * 1000;

	if (degrees > 0)
		{
			motor[left] = MOTOR_SPEED + 5;
			motor[right] = -MOTOR_SPEED;
			wait1Msec(time);
			motor[left] = 0;
			motor[right] = 0;
		}
	else if (degrees < 0)
	{
		motor[left] = -MOTOR_SPEED - 5;
		motor[right] = MOTOR_SPEED;
		wait1Msec(time);
		motor[right] = 0;
		motor[left] = 0;
	}
}

void move(float distance)
{
	float waitTime = distance/MOVE_RATE;
	waitTime = abs(waitTime) * 1000;
	if (distance > 0)
	{
		motor[left] = MOTOR_SPEED + 5;
		motor[right] = MOTOR_SPEED;
	}
	else if (distance < 0)
	{
		motor[left] = -MOTOR_SPEED - 5;
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
		servo[servo1] = 150;
	}
	else if(joy1Btn(2))
	{
		servo[servo1] = 255;
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
    	motor[left] = quadraticJoystick(joystick.joy1_y1);
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

    if (joy1_TopHat == 2) //Right on D-Pad
    {
        motor[intakeMotor] = -10;
    }
    if (joy1_TopHat == 0) //Up on D-Pad
    {
        motor[intakeMotor] = 10;
    }
   if (joy1Btn(8) == 0 &&  joy1_TopHat == -1 )
   {
       motor[intakeMotor] = 0;
   }
}
