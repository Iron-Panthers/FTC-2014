#include "JoystickDriver.c"
#include "drivers/hitechnic-superpro.h"

//int data = HTSPBreadADC(HTSPB, 0, 10);
//potentiometer up is 20 down 38

const int DOWN =  38;
const int UP = 20;

int potValue()
{
    return HTSPBreadADC(HTSPB, 0, 10);
}

task lowerLockMotor()
{
    while (potValue() >= 20)
        motor[goalLock] = -50;

    motor[goalLock] = 0;
}
task raiseLockMotor()
{
    while (potValue() <= 38)
        motor[goalLock] = 50;

    motor[goalLock] = 0;
}
