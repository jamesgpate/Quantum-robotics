#include "TheUltimateFile.c";
void callAutonomous(int count){
	switch(count){
	case 0:
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "is running!");
			//
		motor[frontRight] = -127;
		motor[backRight] =  -127;
		motor[frontLeft] = 127;
		motor[backLeft] =  127;
			//
		wait1Msec(350);
			//
		motor[frontRight] = 127;
		motor[backRight] =  127;
		motor[frontLeft] = -127;
		motor[backLeft] =  -127;
			//
		wait1Msec(2);
			//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] =  127;
		break;
	case 1:
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "is running!");
			//
		motor[frontRight] = 127;
		motor[backRight] =  127;
		motor[frontLeft] = -127;
		motor[backLeft] =  -127;
			//
		wait1Msec(350);
			//
		motor[frontRight] = -127;
		motor[backRight] =  -127;
		motor[frontLeft] = 127;
		motor[backLeft] =  127;
			//
		wait1Msec(2);
			//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] =  127;
		break;
	case 2:
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "is running!");
		break;
	case 3:
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "is running!");
	default:
		displayLCDCenteredString(0, "No valid choice");
		displayLCDCenteredString(1, "was made!");
	}
}
