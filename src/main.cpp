/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\chanc                                            */
/*    Created:      Thu Jan 21 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;


void Auto() {

  //Getting the soccer balls
  Drivetrain.driveFor(-55, inches, 5, rpm);
  Drivetrain.turnFor(left, 90, degrees, 5, rpm);
  Drivetrain.driveFor(-15, inches, 5, rpm);
  Drivetrain.driveFor(25, inches, 5, rpm);
  Drivetrain.turnFor(left, 90, degrees, 5, rpm);
  Drivetrain.driveFor(5, inches, 5, rpm);

  //Getting the footballs
  for(int i = 0; i < 3; i++) {
    //Grabbing & Dropping Ball
    Claw.rotateFor(1, sec, 1, rpm);
    Arm.startRotateFor(fwd, 360, degrees, 1, rpm);
    Drivetrain.driveFor(-45, inches, 5, rpm);
    Drivetrain.turnFor(left, 90, degrees, 5, rpm);
    Drivetrain.driveFor(25, inches, 5, rpm);
    Claw.rotateFor(-1, sec, 1, rpm);
    //Returning to start
    Drivetrain.driveFor(25, inches, 5, rpm);
    Drivetrain.turnFor(right, 90, degrees, 5, rpm);
    Arm.startRotateFor(reverse, 360, degrees, 1, rpm);
    Drivetrain.driveFor(45, inches, 5, rpm);
  }

}


int main() {

 // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true) {
    if(Brain.Screen.pressing()) Auto();
  }

}
