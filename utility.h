#include "drivers/hitechnic-superpro.h"

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
