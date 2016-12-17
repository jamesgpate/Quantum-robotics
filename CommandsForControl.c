#include "TheUltimateFile.c";
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
void goForward(int timeInMS){//for going forward for a certain amount of time
	motor[frontRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = 127;
	motor[backLeft] = 127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
	return;
}
void goBackwards(int timeInMS){//for going backwards
	motor[frontRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = -127;
	motor[backLeft] = -127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
	return;
}
void turnLeft(int timeInMS){//for going left
	motor[frontRight] = -127;
	motor[backRight] = -127;
	motor[frontLeft] = 127;
	motor[backLeft] = 127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
	return;
}
void turnRight(int timeInMS){//for going right
	motor[frontRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = 127;
	motor[backLeft] = 127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
	return;
}
