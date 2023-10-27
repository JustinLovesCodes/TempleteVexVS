using namespace vex;

extern brain Brain;
// Devices
extern controller Controller1;
extern motor L1;
extern motor L2;
extern motor R1;
extern motor R2;
extern motor intakeMotorLeft;
extern motor intakeMotorRight;
extern motor clawMotor;
/*
TO ADD A DEVICE:

extern DEVICETYPE NAME;

DEVICENAME = the device it is
Ex:
motor, limit, digital_out, rotation, ext...

NAME = the name given to the device

Ex:
extern motor Motor1;
extern rotation Gryo;
extern digital_out Pneumatics;
*/


void  vexcodeInit( void );
