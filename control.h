#include "JoystickDriver.c"
#include "utility.h"

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

	if (abs(joystick.joy1_y1) > 10) //Drivetrain
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

    if (joy1Btn(2)) //A
    {
        StartTask(lowerLockMotor);
    }

    else if (joy1Btn(3)) //B
	{
		StartTask(raiseLockMotor);
	}

	if (joy1Btn(1)) //X (raise belt)
	{
		servo[raiseBelt] = 100;
	}
	else if(joy1Btn(4)) //Y  (lower belt)
	{
		servo[raiseBelt] = 156;
	}
	else
	{
		servo[raiseBelt] = 128;
	}

	if (joystick.joy1_TopHat == 4) //D-Pad Down (Score with conveyor belt)
	{
		motor[belt = 6;
	}
	else if (joystick.joy1_TopHat == 6) //D-Pad Left (Reverse conveyor belt)
	{
		motor[belt] = -6;
	}
}
