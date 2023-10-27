/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       winst                                                     */
/*    Created:      10/2/2023, 4:19:43 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/
int intake(){  
    //Intake Code
  if(Controller1.ButtonL1.pressing()){
      intakeMotorLeft.spin(forward);
      intakeMotorRight.spin(forward);
  } else if(Controller1.ButtonL2.pressing()){
      intakeMotorLeft.spin(reverse);
      intakeMotorRight.spin(reverse);
  } else{
      intakeMotorLeft.stop();
      intakeMotorRight.stop();
  }
  int claw(){
    if(Controller1.ButtonR1.pressing()){
      clawMotor.spin(forward);
    } else if(Controller1.ButtonR2.pressing()){
      clawMotor.spin(reverse);
    } else {
        clawMotor.stop();
    }
  }
void pre_auton(void) {

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  vexcodeInit();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {


}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    intake();
    claw();
      
    int axis3_value = Controller1.Axis3.position(percent);
    int axis1_value = Controller1.Axis1.position(percent);
    
    if (axis3_value >= 0){
      L1.spin(reverse, axis3_value + axis1_value * 0.2, pct);
      L2.spin(forward, axis3_value + axis1_value * 0.2, pct);
      R1.spin(reverse, axis3_value - axis1_value * 0.2, pct);
      R2.spin(reverse, axis3_value - axis1_value * 0.2, pct);
    } else {
      L1.spin(reverse, axis3_value - axis1_value * 0.2, pct);
      L2.spin(forward, axis3_value - axis1_value * 0.2, pct);
      R1.spin(reverse, axis3_value + axis1_value * 0.2, pct);
      R2.spin(forward, axis3_value + axis1_value * 0.2, pct);
    }
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
