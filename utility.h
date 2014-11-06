void turnRight()
{
	motor[left] = 75;
	motor[right] = 75;
	wait1Msec(100);
}

void turnLeft()
{
	motor[left] = -75;
	motor[right] = -75;
	wait1Msec(100);
}
