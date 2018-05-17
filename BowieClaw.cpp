#include "BowieClaw.h"

BowieClaw::BowieClaw() {

}

void BowieClaw::begin() {
  claw_position = CLAW_HOME;
  claw_parked = false;
}

void BowieClaw::setServoClawPin(uint8_t p) {
  SERVO_CLAW = p;
}

void BowieClaw::initServo() {
  pinMode(SERVO_CLAW, OUTPUT);
  claw.attach(SERVO_CLAW);
}

void BowieClaw::setServoInterruptCallback( void (*servoInterruptCallback)(int key, int val) ) {
  _servoInterruptCallback = servoInterruptCallback;
}

void BowieClaw::servoInterruption(int key, int val) {
  // TODO: fix this from repeating messages
  //_servoInterruptCallback(key, val);
}


// - Claw
void BowieClaw::moveClaw(int pos) {
  moveClaw(pos, 1, 6);
}

void BowieClaw::moveClaw(int pos, int step, int del) {

  claw_parked = false;

  //unparkEnd();

  int prev_pos = getClawPos();
  if(prev_pos > pos) { // going towards END_MIN
    for(int i=prev_pos; i>pos; i-=step) {
      //Serial << "S" << i << endl;
      claw.writeMicroseconds(i);
      claw_position = i;
      delay(del);
      servoInterruption(SERVO_CLAW_KEY, i);
    }
  } else if(prev_pos <= pos) { // going towards END_MAX
    for(int i=prev_pos; i<pos; i+=step) {
      //Serial << "S" << i << endl;
      claw.writeMicroseconds(i);
      claw_position = i;
      delay(del);
      servoInterruption(SERVO_CLAW_KEY, i);
    }
  }
  claw_position = pos;
  claw.writeMicroseconds(pos);
  delay(del);
  servoInterruption(SERVO_CLAW_KEY, pos);

}

void BowieClaw::parkClaw() {
  if(claw_parked) return;
  moveClaw(CLAW_HOME);
  claw.detach();
  claw_parked = true;
}

void BowieClaw::unparkClaw() {
  if(!claw_parked) return;
  claw.attach(SERVO_CLAW);
  claw_parked = false;
  moveClaw(CLAW_HOME);
}

bool BowieClaw::getClawParked() {
  return claw_parked;
}

int BowieClaw::getClawPos() {
  return claw_position;
}

void BowieClaw::setClawPos(int pos) {
  claw_position = pos;
}

