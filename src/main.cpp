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
    if(Gyro1.heading() >= angle-1 && Gyro1.heading() <= angle+1) {
      Drivetrain.stop();
      break;
    }
  }
}

void Auto() {
  int driveVelocity = 25;
  int distBetweenFootballs = 1; //This will need to be fiddled with, but it corresponds to the distance b/t the footballs on the wooden thingy

  //Getting the soccer balls
  Drivetrain.driveFor(110, inches, driveVelocity, rpm);
  turnToHeading(-90, left);
  Drivetrain.driveFor(15, inches, driveVelocity, rpm);
  //Reset to start getting the footballs
  Drivetrain.driveFor(-15, inches, driveVelocity, rpm);
  turnToHeading(0, right);
  Drivetrain.driveFor(5, inches, driveVelocity, rpm);
  //Getting the footballs
  for(int i = 0; i < 3; i++) {
    //Grabbing & Dropping Ball
    Claw.rotateFor(1, sec, 1, rpm); //Grab Ball
    Arm.startRotateFor(fwd, 360, degrees, 1, rpm); //Move arm up into position
    Drivetrain.driveFor(-45, inches, driveVelocity, rpm); //back up to the basket
    turnToHeading(-90, left); //Turn toward the basket
    Drivetrain.driveFor(25+(i*distBetweenFootballs), inches, driveVelocity, rpm); //Drive up to the basket
    Claw.rotateFor(-1, sec, 1, rpm); //Release ball
    //Returning to start
    Drivetrain.driveFor(-25-(i*distBetweenFootballs), inches, driveVelocity, rpm);
    turnToHeading(0, right);
    Arm.startRotateFor(reverse, 360, degrees, 1, rpm);
    Drivetrain.driveFor(45, inches, driveVelocity, rpm);
  }
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

  //hi andrew
  while(true) {
    Brain.Screen.print("EAT BUTTS DWEEBS");
    Brain.Screen.newLine();
  }

}
