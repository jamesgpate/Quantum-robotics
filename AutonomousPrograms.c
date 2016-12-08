#include "TheUltimateFile.c";
#include "CommandsForControl.c";
void callAutonomous(int count){
	switch(count){
	case 0:
		displayLCDCenteredString(0, "Autonomous 1");
		displayLCDCenteredString(1, "is running!");
		//
		goForward(350);
		//
		turnLeft(150);
		//
		goForward(3500);
		break;
	case 1:
		displayLCDCenteredString(0, "Autonomous 2");
		displayLCDCenteredString(1, "is running!");
		//
		goForward(350);
		//
		turnRight(150);
		//
		goForward(3500);
		break;
	case 2:
		displayLCDCenteredString(0, "Autonomous 3");
		displayLCDCenteredString(1, "is running!");
		goForward(500);
		//
		turnLeft(200);
		//
		goForward(4000);
		break;
	case 3:
		displayLCDCenteredString(0, "Autonomous 4");
		displayLCDCenteredString(1, "is running!");
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
