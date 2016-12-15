#include "TheUltimateFile.c";
#include "config.h"
#include "CommandsForControl.c";
void callAutonomous(int count){
	switch(count){
	case 0:
		displayLCDCenteredString(0, "Turn Left");
		displayLCDCenteredString(1, "is running!");
		//
		motor[hook]=127;
		wait1Msec(100);
		goForward(350);
		//
		turnLeft(150);
		//
		goForward(3500);
		break;
	case 1:
		displayLCDCenteredString(0, "Turn Right");
		displayLCDCenteredString(1, "is running!");
		//
		motor[hook]=127;
		wait1Msec(100);
		goForward(350);
		//
		turnRight(150);
		//
		goForward(3500);
		break;
	case 2:
		displayLCDCenteredString(0, "Fence Left");
		displayLCDCenteredString(1, "is running!");
		motor[hook]=127;
		wait1Msec(100);
		goForward(500);
		//
		turnLeft(200);
		//
		goForward(4000);
		break;
	case 3:
		displayLCDCenteredString(0, "Fence Right");
		displayLCDCenteredString(1, "is running!");
		motor[hook]=127;
		wait1Msec(100);
		goForward(500);
		//
		turnRight(200);
		//
		goForward(4000);
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
	}
}
