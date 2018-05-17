/*
 * Bowie Fast Logger Example
 * -------------------------
 * 
 * Test the fast logging of data to the robot's micro SD card.
 * (Only for Mega Bowie, with Teensy 3.6 and RTC)
 * 
 * Erin RobotGrrl for RobotMissions
 * April 8th, 2018
 * --> http://RobotMissions.org
 * 
 * MIT license, check LICENSE for more information
 * All text above must be included in any redistribution
 * 
 */

#include "BowieFastLogger.h"

BowieFastLogger bowielogger = BowieFastLogger();

void setup() {
  Serial.begin(9600);

  initTime(); // should always be first

  bowielogger.begin();
  bowielogger.setLoggingLed(13);
  bowielogger.initLogging();
  
}

void loop() {

  String new_data = "a, " + (int)random(0, 100);
  new_data += ", b, " + (int)random(0, 10);
  
  bowielogger.setLogData(new_data);
  bowielogger.updateLogging();

}
