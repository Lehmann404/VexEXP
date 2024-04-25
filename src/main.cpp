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

motor LeftMotorBack = motor(PORT6, false);
motor LeftMotorFront = motor(PORT1, false);
motor RightMotorBack = motor(PORT10, true);
motor RightMotorFront = motor(PORT5, true);
motor flipper = motor(PORT2, true);





pwm_out laserdiode = pwm_out(Brain.ThreeWirePort.A);
bumper BumperA = bumper(Brain.ThreeWirePort.A);

controller Controller = controller();
bool flag = true;





  void flippatime(){

  //flipper.spinFor(forward, 110, degrees, 40, velocityUnits::pct, false);
  if(!flag){
  flipper.spinToPosition(110, degrees, 40, velocityUnits::pct);

  }
  if(flag){
  flipper.spinToPosition(-25, degrees, 40, velocityUnits::pct);

  }

  }





int main() {
  // Begin project code
   flipper.setPosition(0, degrees);
  // Set the deadband variable
  float deadband = 5.0;
  int counter = 0;
  


  // Main controller loop to set motor velocities to controller axis positions
  while (true) {
     Brain.Screen.printAt( 10, 50, "Counter %d", counter);
   
    if (abs(Controller.Axis3.position()) + abs(Controller.Axis1.position()) > deadband) {
      LeftMotorBack.setVelocity((Controller.Axis3.position() + Controller.Axis1.position()), percent);
      LeftMotorFront.setVelocity((Controller.Axis3.position() + Controller.Axis1.position()), percent);
      RightMotorFront.setVelocity((Controller.Axis3.position() - Controller.Axis1.position()), percent);
      RightMotorBack.setVelocity((Controller.Axis3.position() - Controller.Axis1.position()), percent);
    } else {
      LeftMotorBack.setVelocity(0, percent);
      RightMotorBack.setVelocity(0, percent);
      LeftMotorFront.setVelocity(0, percent);
      RightMotorFront.setVelocity(0, percent);
      flipper.setVelocity(0, percent);  
    }
    LeftMotorBack.spin(forward);
    RightMotorBack.spin(forward);
    LeftMotorFront.spin(forward);
    RightMotorFront.spin(forward);
    flipper.spin(forward);
    
  if (BumperA.pressing()) {
      vexSoundPlayTone(10, 100, 500);
      counter++;

     
      
      LeftMotorBack.setVelocity(0, percent);
      RightMotorBack.setVelocity(0, percent);
      LeftMotorFront.setVelocity(0, percent);
      RightMotorFront.setVelocity(0, percent);  
      
      vex::color r = vex::color( 255, 0, 0 );
      Brain.Screen.setFillColor( r );
      Brain.Screen.drawRectangle(-5, -5, 170, 170 );
       flipper.spinFor(forward, 110, degrees, 40, velocityUnits::pct, false);



      wait(2, sec);

       flipper.spinFor(reverse, 110, degrees, 40, velocityUnits::pct, false);

        } else {
      vex::color g = vex::color( 0, 255, 0 );
      

       Brain.Screen.setFillColor( g );
       Brain.Screen.drawRectangle(-5, -5, 170, 170 );

        }





    if(Controller.ButtonA.pressing()) {
      if(flag){
        flag = false;
      } else {
        flag = true;
      }
      flippatime();
    }




    wait(20, msec);
  }


}

