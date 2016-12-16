#include "TheUltimateFile.c";
#include "config.h"
#include "CommandsForControl.c";
/*
    This file is part of the Quantum Robotics robot code.

    The Quantum Robotics robot code is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    The Quantum Robotics robot code is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with the Quantum Robotics robot code.  If not, see <http://www.gnu.org/licenses/>.
*/
//Please give credit if you are using this
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
	}
}
