/*
 * Bowie Claw Example
 * --------------------
 * 
 * Test the movement of the robot's claw, specifically
 * for the scoop boundaries.
 * Claw design by Micah Black.
 * 
 * Erin RobotGrrl for RobotMissions
 * April 28th, 2018
 * --> http://RobotMissions.org
 * 
 * MIT license, check LICENSE for more information
 * All text above must be included in any redistribution
 * 
 */

#include <Streaming.h>
#include "BowieClaw.h"

#define SERVO_CLAW 24

BowieClaw bowieclaw = BowieClaw();

void clawInterrupt(int key, int val);

void setup() {
  Serial.begin(9600);

  bowieclaw.begin();
  bowieclaw.setServoClawPin(SERVO_CLAW);
  
  bowieclaw.setServoInterruptCallback(clawInterrupt);

  bowieclaw.initServo();

}

void loop() {

  // claw up
  Serial << "CLAW_MIN" << endl;
  bowieclaw.moveClaw(CLAW_MIN);
  delay(1000);
  
  // claw home
  Serial << "CLAW_HOME" << endl;
  bowieclaw.moveClaw(CLAW_HOME);
  delay(1000);
  
  // claw down
  Serial << "CLAW_MAX" << endl;
  bowieclaw.moveClaw(CLAW_MAX);
  delay(1000);
  
  // claw home
  Serial << "CLAW_HOME" << endl;
  bowieclaw.moveClaw(CLAW_HOME);
  delay(1000);
  
}

void clawInterrupt(int key, int val) {
  // This will be called any time there is a long
  // duration movement - in between the delays.
  // This is a good place to check for serial
  // messages. Val = the position.
  
  if(key == SERVO_CLAW_KEY) {
    // It's the scoop!
  }
}

