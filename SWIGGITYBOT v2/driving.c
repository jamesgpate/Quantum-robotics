#include "mainfile.c"
extern task MotorSlewRateTask();
extern task LCDstuff();
task driving(){
	int c2 = 0, c3 = 0, threshold = 15;
	int p1, p2, tick, count2=0;
	bLCDBacklight = true;
	string mainBattery, backupBattery;
	SensorValue[BLI] = 0;
	SensorValue[BRI] = 0;
	SensorValue[ArmEnc] = 0;
	//startTask(MotorSlewRateTask);
	startTask(LCDstuff);
	while(true){
		c2 = vexRT[Ch2];
		c3 = vexRT[Ch3];
		if(abs(c2)<=threshold) c2 = 0;
		if(abs(c3)<=threshold) c3 = 0;
		motor[FR]=motor[BR]=-c2;
		motor[FL]=motor[BL]=c3;
		if(vexRT[Btn5D]==1){
			motor[L1R1]=127;
			motor[L2R2]=127;
			motor[L3R3]=127;
		}else if(vexRT[Btn6D]==1){
			motor[L1R1]=-127;
			motor[L2R2]=-127;
			motor[L3R3]=-127;
		}else if(vexRT[Btn8D]==1){
			motor[L1R1]=-30;
			motor[L2R2]=-30;
			motor[L3R3]=-30;
		}else if(vexRT[Btn8R]==1){
			motor[L1R1]=-60;
			motor[L2R2]=-60;
			motor[L3R3]=-60;
		}else if(vexRT[Btn8U]==1){
			motor[L1R1]=-90;
			motor[L2R2]=-90;
			motor[L3R3]=-90;
		}else if(vexRT[Btn6D]==0&&vexRT[Btn5D]==0&&vexRT[Btn8D]==0&&vexRT[Btn8R]==0&&vexRT[Btn8U]==0){
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
		if(SensorValue[ArmEnc]>=220) motor[L1R1]=motor[L2R2]=motor[L2R2]=0;
				if(count2==0){//display battery level
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0, 0, "Primary: ");
			sprintf(mainBattery, "%1.2f%c", nImmediateBatteryLevel/1000.0,'V');
			displayNextLCDString(mainBattery);
			displayLCDString(1, 0, "Backup: ");
			sprintf(backupBattery, "%1.2f%c", BackupBatteryLevel/1000.0, 'V');
			displayNextLCDString(backupBattery);
		}else if(count2==1){//disp ports 2 and 3
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port2:");
			displayLCDNumber(0,7,motor[port2]);
			displayLCDString(1,0,"Port3:");
			displayLCDNumber(1,7,motor[port2]);
		}else if(count2==2){//disp ports 4 and 5
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port4:");
			displayLCDNumber(0,7,motor[port4]);
			displayLCDString(1,0,"Port5:");
			displayLCDNumber(1,7,motor[port5]);
		}else if(count2==3){//disp ports 6 and 7
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port6:");
			displayLCDNumber(0,7,motor[port6]);
			displayLCDString(1,0,"Port7:");
			displayLCDNumber(1,7,motor[port7]);
		}else if(count2==4){//disp ports 8 and 9
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Port8:");
			displayLCDNumber(0,7,motor[port8]);
			displayLCDString(1,0,"Port9:");
			displayLCDNumber(0,7,motor[port9]);
		}else if(count2==5){//disp exp batt
			clearLCDLine(0);
			clearLCDLine(1);
			displayLCDString(0,0,"Hello :)");

		}
		tick++;//cycling LCD Info
		if(tick>=10000){
			tick=0;
			count2++;
		}
		if(count2==6) count2=0;
	}
}
task LCDstuff(){
	while(!false){
		clearLCDLine(1);
		clearLCDLine(0);
		displayNextLCDNumber(SensorValue[ArmEnc]);
		displayNextLCDChar(',');
		displayNextLCDNumber(SensorValue[BRI]);
		displayNextLCDChar(',');
		displayNextLCDNumber(SensorValue[BLI]);

	}
}
