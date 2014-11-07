const float ROBOT_RATE = 200;	//measure this to find real value
const float MOTOR_SPEED = 75;
const float RADIUS = 5; //measure this to find real value

void turn(float degrees)
{
	float rad = degrees * PI/180;
	float distance = rad * RADIUS;
	float time = distance/ROBOT_SPEED;
	time = time * 1000;

	if (degrees > 0)
		{
			motor[left] = ROBOT_SPEED;
			motor[right] = 0;
			wait1Msec(time);
			motor[left] = 0;
		}
	else if (degrees < 0)
	{
		motor[left] = 0;
		motor[right] = ROBOT_SPEED;
		wait1Msec(time);
		motor[right] = 0;
	}
}

void move(float distance)
{
	int waitTime = distance/ROBOT_RATE;
	waitTime = waitTime * 1000;
	motor[left] = MOTOR_SPEED;
	motor[right] = MOTOR_SPEED;
	wait1Msec(waitTime);
	motor[left] = 0;
	motor[right] = 0;
}
