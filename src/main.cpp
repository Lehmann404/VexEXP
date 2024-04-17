/*----------------------------------------------------------------------------------------*/
/*                                                                                        */
/*    Project:          Split Arcade                                                      */
/*    Module:           main.cpp                                                          */
/*    Author:           VEX                                                               */
/*    Description:      The Left up/down Controller Axis (3) will drive the robot         */
/*                      forward and backwards.                                            */
/*                      The Right left/right Controller Axis (1) will turn the robot      */
/*                      left and right.                                                   */
/*                      The deadband variable prevents drift when the Controller's        */
/*                      joystick is released.                                             */
/*                                                                                        */
/*    Configuration:    Left Motor in Port 6                                              */
/*                      Right Motor in Port 10                                            */
/*                      Controller                                                        */
/*                                                                                        */
/*----------------------------------------------------------------------------------------*/

// Include the VEX Library
#include "vex.h"

// Allows for easier use of the VEX Library
using namespace vex;

// Brain should be defined by default
brain Brain;

// Robot configuration code.
inertial BrainInertial = inertial();

motor LeftMotor = motor(PORT6, false);
motor RightMotor = motor(PORT10, true);
pwm_out laserdiode = pwm_out(Brain.ThreeWirePort.A);

controller Controller = controller();

  void spin(){

    LeftMotor.setVelocity(100, percent);
    RightMotor.setVelocity(-100, percent);

    wait(0.5, sec);

      LeftMotor.setVelocity(0, percent);
      RightMotor.setVelocity(0, percent);

  wait(0.5, sec);

       LeftMotor.setVelocity(-100, percent);
    RightMotor.setVelocity(100, percent);

    wait(0.5, sec);

      LeftMotor.setVelocity(0, percent);
      RightMotor.setVelocity(0, percent);

        wait(0.5, sec);

       LeftMotor.setVelocity(100, percent);
    RightMotor.setVelocity(-100, percent);

    wait(0.5, sec);

      LeftMotor.setVelocity(0, percent);
      RightMotor.setVelocity(0, percent);

  }





int main() {
  // Begin project code
  
  // Set the deadband variable
  float deadband = 5.0;


  // Main controller loop to set motor velocities to controller axis positions
  while (true) {
    if (abs(Controller.Axis3.position()) + abs(Controller.Axis1.position()) > deadband) {
      LeftMotor.setVelocity((Controller.Axis3.position() + Controller.Axis1.position()), percent);
      RightMotor.setVelocity((Controller.Axis3.position() - Controller.Axis1.position()), percent);
    } else {
      LeftMotor.setVelocity(0, percent);
      RightMotor.setVelocity(0, percent);
    }
    LeftMotor.spin(forward);
    RightMotor.spin(forward);
    
  if (Controller.ButtonA.pressing()) {
            spin();
        }

if (Controller.ButtonR2.pressing()) {
            spin();
        }

    wait(20, msec);
  }
}



