#include "mainfile.c"
task driving(){
	motor[FL] = vexRT[Ch3] + vexRT[Ch1] - vexRT[Ch4];
	motor[FR] = -vexRT[Ch3] - vexRT[Ch1] + vexRT[Ch4];
	motor[BL] = vexRT[Ch3] + vexRT[Ch1] + vexRT[Ch4];
	motor[BR]= -vexRT[Ch3] - vexRT[Ch1] - vexRT[Ch4];
	if(vexRT[Btn6D]==1){
		motor[L1R1]=127;
		motor[L2R2]=127;
		motor[L3R3]=127;
	}
	if(vexRT[Btn5D]==1){
		motor[L1R1]=-127;
		motor[L2R2]=-127;
		motor[L3R3]=-127;
	}
	if(vexRT[Btn6D]==0&&vexRT[Btn5D]==0){
		motor[L1R1]=0;
		motor[L2R2]=0;
		motor[L3R3]=0;
	}
	if(vexRT[Btn6U]==1){
		SensorValue[dgtl1]=1;
	}
	if(vexRT[Btn6U]==0){
		SensorValue[dgtl1]=0;
	}
}
