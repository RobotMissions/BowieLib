/*
 * Robot Missions Bowie Claw
 * ---------------------------
 *
 * Servo routines for Bowie the robot's claw.
 * Claw design by Micah Black.
 *
 * Erin RobotGrrl for Robot Missions
 * --> http://RobotMissions.org
 *
 * Using Teensy 3.6, works with Teensy 3.2
 * 
 * Erin RobotGrrl
 * April 28, 2018
 *
 * MIT license, check LICENSE for more information
 * All text above must be included in any redistribution
 *
 */

#include "Arduino.h"
#include <Streaming.h>
#ifndef Servo_h
#include <Servo.h>
#endif

#ifndef _BOWIECLAW_H_
#define _BOWIECLAW_H_

// Servo positions
#define CLAW_MAX 1000 // open
#define CLAW_HOME 1000 // mid open
#define CLAW_MIN 1800 // closed

#define SERVO_MAX_US 2500
#define SERVO_MIN_US 500

// Keys
#define SERVO_CLAW_KEY 7

class BowieClaw {

  public:
    BowieClaw();
    void begin();

    void setServoClawPin(uint8_t p);
    void initServo();

    // Callback
    void setServoInterruptCallback( void (*servoInterruptCallback)(int key, int val) );

    // Servos
    Servo claw;

    // Other
    void servoInterruption(int key, int val);

    // Claw
    void moveClaw(int pos);
    void moveClaw(int pos, int step, int del);
    void parkClaw();
    void unparkClaw();
    bool getClawParked();
    int getClawPos();
    void setClawPos(int pos);

  private:

    // Callback
    void (*_servoInterruptCallback)(int key, int val);

    // Pins
    uint8_t SERVO_CLAW;
    
    // Positions
    int claw_position;
    
    // Park positions
    bool claw_parked;

};

#endif