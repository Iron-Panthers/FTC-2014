#include "JoystickDriver.c"

const float MOVE_RATE = .530;
const float MOTOR_SPEED = 75;
const float RADIUS = .457; //radius in meters

void GoalServo(bool lock)
{
    if (lock==true)
    {
<<<<<<< HEAD
        servo[servo1] = 160;
=======
        motor[goal] = _____;
>>>>>>> origin/master
    }
    else
    {
        servo[goal] = ____;
    }

}



void stopRobot(int forMilliseconds)
{
    motor[left] = 0;
    motor[right] = 0;
    wait1Msec(forMilliseconds);
}

void turn(float degrees)
{
    float adjTurn;

    if (abs(degrees) > 0 && abs(degrees) < 38)
    {
        adjTurn = .400;
    }
    if (abs(degrees) > 38 && abs(degrees) < 52)
    {
        adjTurn = .430;
    }
    if (abs(degrees) > 52 && abs(degrees) < 100)
    {
        adjTurn = .460;
    }
    if (abs(degrees) > 100 && abs(degrees) <= 360)
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
		motor[left] = -MOTOR_SPEED;
	    motor[right] = -MOTOR_SPEED;
	}
	wait1Msec(waitTime);
	motor[left] = 0;
	motor[right] = 0;
}


void slowMove(float distance)
{
    const float MOVE_RATE_SLOW = MOVE_RATE / 4;
    const float MOTOR_SPEED_SLOW = MOTOR_SPEED / 4;
	float waitTime = distance/MOVE_RATE_SLOW;
	waitTime = abs(waitTime) * 1000;
	if (distance > 0)
	{
		motor[left] = MOTOR_SPEED_SLOW + 5;
		motor[right] = MOTOR_SPEED_SLOW;
	}
	else if (distance < 0)
	{
		motor[left] = -MOTOR_SPEED_SLOW - 5;
	    motor[right] = -MOTOR_SPEED_SLOW;
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

bool usingToggle = false;
bool usingToggleBelt = false;
void joystickControl()
{
	getJoystickSettings(joystick);

	//Lock Servo

	if (joy1Btn(2)) //A
	{
		motor[lockMotor] = 172;
	}
	else if(joy1Btn(3)) //B
	{
		motor[lockMotor] = 255;
	}

	//Continuous rotation servo
	if (joy1Btn(1)) //X
	{
		servo[servo2] = 100;
	}
	else if(joy1Btn(4)) //Y
	{
		servo[servo2] = 156;
	}
	else
	{
		servo[servo2] = 128;
	}

	//conveyer belt toggle
    if (time1[T2] > 250)
    {
        if ((joy1Btn(5)) && (motor[extender] < 5)) //Toggle intake motor if right on D-Pad
        {
            usingToggleBelt = true;
            motor[extender] = 6;
        }
        else if ((joy1Btn(5)) && (motor[extender] > 5))
        {
            usingToggleBelt = false;
            motor[extender] = 0;
        }
        time1[T2] = 0;
    }
	//Conveyor belt motor
	if (joystick.joy1_TopHat == 4) //D-Pad Down
	{
	    usingToggleBelt = false;
		motor[extender] = 6;
	}
	else if (joystick.joy1_TopHat == 6) //D-Pad Left
	{
	    usingToggleBelt = false;
		motor[extender] = -6;
	}
	else if ((!joy1Btn(5)) && joystick.joy1_TopHat != 6 && joystick.joy1_TopHat != 4 && !usingToggleBelt )
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
    if (time1[T1] > 250)
    {
        if ((joy1Btn(6)) && (motor[intakeMotor] < 5)) //Toggle intake motor if right on D-Pad
        {
            usingToggle = true;
            motor[intakeMotor] = 10;
        }
        else if ((joy1Btn(6)) && (motor[intakeMotor] > 5))
        {
            usingToggle = false;
            motor[intakeMotor] = 0;
        }
        time1[T1] = 0;
    }
    if ((joystick.joy1_TopHat) == 0) //Up on D-Pad
    {
        usingToggle = false;
        motor[intakeMotor] = 10;
    }
    else if ((joystick.joy1_TopHat) == 2) //Right on D-Pad
    {
        usingToggle = false;
        motor[intakeMotor] = -10;
    }
    else if ((!joy1Btn(6)) && joystick.joy1_TopHat == -1 && !usingToggle )
    {
        motor[intakeMotor] = 0;
    }

}

<<<<<<< HEAD
enum CompareChoices {
    Btn,
    TopHat,
    Toggle
}

typedef struct {
    CompareChoices choice;
    int compareValue;

    int motorOrServoArray[];
    int motorOrServoIndex;

    int setToValue;

    int motorToggleArray[];
    int motorToggleIndex;
    bool isToggling;
} Conditional;

Conditional conds;

void checkConditionals()
{
    switch (conds.choice)
    {
    case Btn:
        if (joy1Btn(compareValue))
        {
            motorOrServoArray[motorOrServoIndex] = setToValue;
        }
        break;
    case TopHat:
        if (joystick.joy1_TopHat == compareValue)
        {
            motorOrServoArray[motorOrServoIndex] = setToValue;
        }
        break;
    case Toggle:
        if ((joystick.joy1_TopHat) == compareValue) //Up on D-Pad
	    {
	        usingToggle = false;
	        motor[intakeMotor] = 10;
	    }
	    else if ((joystick.joy1_TopHat) == 2) //Right on D-Pad
	    {
	        usingToggle = false;
	        motor[intakeMotor] = -10;
	    }
	    else if ((!joy1Btn(6)) && joystick.joy1_TopHat == -1 && !usingToggle )
	    {
	        motor[intakeMotor] = 0;
	    }

    }
=======
typedef struct{
	int value;
	int comparison[];
	TPCJoystick surfaces;
	bool bToggle;
	bool isMotor;
	tMotor motorName;
	TServoIndex servoName;
}Conditional;

void joystickControl(Conditional cond)
{
	if (Time1[T1] > 250)
	{
		if (cond.surfaces == 8) // if btn 8 is pressed
	  {
	  	if ((cond.bToggle && (motor[cond.motorName] < cond.comparison[1])) || (!cond.bToggle && (motor[cond.motorName] > cond.comparison[1])
	  	{
	  		motor[cond.motorName] = cond.value;
	  		condlbToggle = !cond.bToggle;
	  		time1[T1] = 0;
	  	}
	  }
	}
	if (joystick.cond.surfaces == cond.comparison)
	{
		if (isMotor)
		{
			motor[cond.motorName] = cond.value;
		}else{
			servo[cond.servoName] = cond.value;
	  }
	}
}
>>>>>>> 189bf7145a3ef1092addf52e810c228df39249dc
}
