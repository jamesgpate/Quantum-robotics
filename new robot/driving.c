#include "mainfile.c"
task driving(){
	motor[FL] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
	motor[FR] = vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
	motor[BL] = vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];
	motor[BR]= vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
}
