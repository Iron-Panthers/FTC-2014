#pragma config(Motor,  motorB,          piano,         tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          tuna,          tmotorNXT, PIDControl, encoder)

task main ()
{}

void crossingGuard()
{
        nMotorEncoder[piano] = 0;
        while(nMotorEncoder[piano] < 360)
    {
        motor[piano] = 75;
        motor[tuna] = 75;
    }
    motor[piano] = 0;
    motor[tuna] = 0;
}
