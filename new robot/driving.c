#include "mainfile.c"
task driving(){
	int c1 = 0, c3 = 0, c4 = 0, threshold = 15;
	while(true){
		c1 = vexRT[Ch1];
		c3 = vexRT[Ch3];
		c4 = vexRT[Ch4];
		if(abs(c4)<=threshold) c4 = 0;
		if(abs(c1)<=threshold) c1 = 0;
		if(abs(c3)<=threshold) c3 = 0;
		motor[FL] = c3 + c1 + c4;
		motor[FR] = -c3 + c1 + c4;
		motor[BL] = c3 + c1 - c4;
		motor[BR] = -c3 + c1 - c4;
		if(vexRT[Btn5D]==1){
			motor[L1R1]=127;
			motor[L2R2]=127;
			motor[L3R3]=127;
		}else	if(vexRT[Btn6D]==1){
			motor[L1R1]=-127;
			motor[L2R2]=-127;
			motor[L3R3]=-127;
		}else if(vexRT[Btn6D]==0&&vexRT[Btn5D]==0){
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
		clearLCDLine(0);
		clearLCDLine(1);
		displayNextLCDNumber(SensorValue[pot1]);
	}
}
