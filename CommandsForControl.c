#include "TheUltimateFile.c";
#include "config.h"
void goForward(int timeInMS){//for going forward for a certain amount of time
	motor[frontRight] = -127;
	motor[backRight] =  127;
	motor[frontLeft] = 127;
	motor[backLeft] =  -127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
}
void goBackwards(int timeInMS){//for going backwards
	motor[frontRight] = 127;
	motor[backRight] = -127;
	motor[frontLeft] = -127;
	motor[backLeft] = 127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
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
}
void turnRight(int timeInMS){//for going right
	motor[frontRight] = 127;
	motor[backRight] = 127;
	motor[frontLeft] = -127;
	motor[backLeft] = -127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
}
