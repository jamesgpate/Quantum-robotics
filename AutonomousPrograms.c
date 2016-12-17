#include "TheUltimateFile.c";
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
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(50);
		//
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(400);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(3500);
		break;
	case 1:
		displayLCDCenteredString(0, "Turn Right");
		displayLCDCenteredString(1, "is running!");
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(50);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = -127;
		motor[backLeft] = -127;
		wait1Msec(400);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(3500);
		break;
	case 2:
		displayLCDCenteredString(0, "Fence Left");
		displayLCDCenteredString(1, "is running!");
		motor[hook]=127;
		wait1Msec(100);
		motor[hook]=0;
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(900);
		//
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(850);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(5000);
		break;
	case 3:
		motor[hook]=127;
		wait1Msec(100);
		motor[hook]=0;
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(900);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = -127;
		motor[backLeft] = -127;
		wait1Msec(850);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(5000);
	case 4://auton 5
		displayLCDCenteredString(0, "Shooty");
		displayLCDCenteredString(1, "is running!");
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = -127;
		motor[backLeft] = -127;
		wait1Msec(600);
		motor[frontRight] = 80;
		motor[backRight] = 80;
		motor[frontLeft] = 80;
		motor[backLeft] = 80;
		wait1Msec(250);
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = -127;
		motor[backLeft] = -127;
		wait1Msec(200);
		motor[frontRight] = 0;
		motor[backRight] = 0;
		motor[frontLeft] = 0;
		motor[backLeft] = 0;
		wait1Msec(100);
		motor[hook]=127;
		wait1Msec(150);
		motor[hook]=0;
		break;
	default:
		displayLCDCenteredString(0, "Turn Left");
		displayLCDCenteredString(1, "is running!");
		//
		motor[hook]=127;
		wait1Msec(100);
		motor[hook]=0;
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(50);
		//
		motor[frontRight] = -127;
		motor[backRight] = -127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(450);
		//
		motor[frontRight] = 127;
		motor[backRight] = 127;
		motor[frontLeft] = 127;
		motor[backLeft] = 127;
		wait1Msec(3500);
		break;
	}
}
