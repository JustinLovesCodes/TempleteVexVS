#include "vex.h"

using namespace vex;

brain Brain;

/*
NAME = Name of the Device

CONTROLLERTYPE = Original or Secondary
Original = primary
Secondary = partner

PORT = The port the device was being pluged into
Ex:
PORT1, PORT8, PORT12, PORT20

MOTORTYPE = Normal vs Speed vs Tourque motors
Normal = ratio18_1
Speed = ratio6_1
Tourque = ratio36_1

DIRECTION = Forward(Normal) vs Reverse
Forward(Normal) = false
Reverse = normal

3WIREPORT = The 3 wire port the device was being pluged into
Ex:
Brain.ThreeWirePort.A, Brain.ThreeWirePort.E, Brain.ThreeWirePort.H
---------------------------------------------------------------------------------------
CONTROLLER
controller NAME = (CONTROLLERTYPE);

MOTOR
motor NAME = motor(PORT, MOTORTYPE, DIRECTION);

INTERNAL(GYROSCOPE)
internal NAME = internal(PORT);

ROTATIONAL(SHAFT ENCODERS but BETTER)
rotational NAME = rotational(PORT, DIRECTION);

LIMIT SWITCH
limit NAME = limit(3WIREPORT);

ENCODER(SHAFT ENCODER)
encoder NAME = encoder(3WIREPORT);
!WARNING!
Because encoders use 2 three wire port, there are 4 diffrent combination
Brain.ThreeWirePort.A & Brain.ThreeWirePort.B = Brain.ThreeWirePort.A
Brain.ThreeWirePort.C & Brain.ThreeWirePort.D = Brain.ThreeWirePort.C
Brain.ThreeWirePort.E & Brain.ThreeWirePort.F = Brain.ThreeWirePort.E
Brain.ThreeWirePort.G & Brain.ThreeWirePort.H = Brain.ThreeWirePort.G

PNEUMATICS
digital_in NAME = digital_in(3WIREPORT);
*/


void vexcodeInit( void ) {
  // nothing to initialize
}
