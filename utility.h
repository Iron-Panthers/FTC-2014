const float ROBOT_RATE = 200;	//measure this to find real value
const float MOTOR_SPEED = 75;

void turnRight()
{
	motor[left] = MOTOR_SPEED;
	motor[right] = MOTOR_SPEED;
	wait1Msec(100);
}

void turnLeft()
{
	motor[left] = -75;
	motor[right] = -75;
	wait1Msec(100);
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


{

void turn(degreesToRadians)
{

}
