/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Chance Wilson & John Stockton                             */
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

void turnToHeading( double angle, turnType direction) {
  Drivetrain.turn(direction);
  while(true) {
    Brain.Screen.print(Gyro1.heading());
    Brain.Screen.newLine();
    if(Gyro1.heading() >= angle-2 && Gyro1.heading() <= angle+2) {
      Drivetrain.stop();
      break;
    }
  }
}

void Auto() {
  int driveVelocity = 25;
  int turnVelocity = 70;

  //Getting the soccer balls
  Drivetrain.driveFor(-110, inches, driveVelocity, rpm);
  turnToHeading(90, right);
  Drivetrain.driveFor(-15, inches, driveVelocity, rpm);
  Drivetrain.driveFor(25, inches, driveVelocity, rpm);
  Drivetrain.turnFor(left, 500, degrees, turnVelocity, rpm);
  turnToHeading(90, right);
  Drivetrain.driveFor(5, inches, driveVelocity, rpm);
  Gyro1.setHeading(0, degrees);
  //Getting the footballs
  for(int i = 0; i < 3; i++) {
    //Grabbing & Dropping Ball
    Claw.rotateFor(1, sec, 1, rpm);
    Arm.startRotateFor(fwd, 360, degrees, 1, rpm);
    Drivetrain.driveFor(-45, inches, driveVelocity, rpm);
    Drivetrain.turnFor(left, 500, degrees, 5, rpm);
    Drivetrain.driveFor(25, inches, driveVelocity, rpm);
    Claw.rotateFor(-1, sec, 1, rpm);
    //Returning to start
    Drivetrain.driveFor(25, inches, driveVelocity, rpm);
    Drivetrain.turnFor(right, 500, degrees, 5, rpm);
    Arm.startRotateFor(reverse, 360, degrees, 1, rpm);
    Drivetrain.driveFor(45, inches, driveVelocity, rpm);
  }
  */
}


int main() {

 // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  while(true) {
    if(Controller1.ButtonUp.pressing()) {
      Auto();
      break;
    }
  }


}
