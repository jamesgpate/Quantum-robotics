#include "TheUltimateFile.c";
void goForward(int timeInMS){
	motor[frontRight] = -127;
	motor[backRight] =  -127;
	motor[frontLeft] = 127;
	motor[backLeft] =  127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
}
void goBackwards(int timeInMS){
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
void turnLeft(int timeInMS){
	motor[frontRight] = 127;
	motor[backRight] =  127;
	motor[frontLeft] = -127;
	motor[backLeft] =  -127;
	wait1Msec(timeInMS);
	motor[frontRight] = 0;
	motor[backRight] =  0;
	motor[frontLeft] = 0;
	motor[backLeft] =  0;
}
void turnRight(int timeInMS){
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
