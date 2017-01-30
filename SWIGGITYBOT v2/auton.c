#include "mainfile.c"
float pid_Kp = 2.0;
float pid_Ki = 0.04;
float pid_Kd = 0.0;
float circOfWheelInInches = 3.25*3.14159265358979323846;
static bool pidRunning = true;
static float pidRequestedValue;
task pidLoopForForwardsandBackwards(){
	float pidSensorCurrentValuelb;
	float pidSensorCurrentValuerb;
	float pidErrorlb;
	float pidErrorrb;
	float pidLastErrorlb;
	float pidLastErrorrb;
	float pidIntegrallb;
	float pidIntegralrb;
	float pidDerivativelb;
	float pidDerivativerb;
	float pidDrivelb;
	float pidDriverb;
	SensorValue[BLI] = 0;
	SensorValue[BRI] = 0;
	while(pidRunning){
		pidSensorCurrentValuelb=SensorValue[BLI];
		pidSensorCurrentValuerb=SensorValue[BRI];
		pidErrorlb=pidSensorCurrentValuelb-pidRequestedValue;
		pidErrorrb=pidSensorCurrentValuerb-pidRequestedValue;
		if(pid_Ki!=0){
			if(abs(pidErrorlb)<50) pidIntegrallb=pidIntegrallb+pidErrorlb;
			else pidIntegrallb = 0;
			if(abs(pidErrorrb)<50) pidIntegralrb=pidIntegralrb+pidErrorrb;
			else pidIntegralrb = 0;
		}else{
			pidIntegrallb = 0;
			pidIntegralrb = 0;
		}
		pidDerivativelb = pidErrorlb-pidLastErrorlb;
		pidLastErrorlb = pidErrorlb;
		pidDerivativerb = pidErrorrb-pidLastErrorrb;
		pidLastErrorrb = pidErrorrb;
		pidDrivelb = (pid_Kp * pidErrorlb) + (pid_Ki * pidIntegrallb) + (pid_Kd * pidDerivativelb);
		pidDriverb = (pid_Kp * pidErrorrb) + (pid_Ki * pidIntegralrb) + (pid_Kd * pidDerivativerb);
		if(pidDrivelb > 127) pidDrivelb = 127;
		if(pidDrivelb < -127) pidDrivelb = -127;
		if(pidDriverb > 127) pidDriverb = 127;
		if(pidDriverb < -127)	pidDriverb = -127;
		wait1Msec(25);
		motor[BL] = motor[FR] = pidDrivelb*-1;
		motor[BR] = motor[BL] = pidDriverb;
		if(pidRequestedValue>=pidSensorCurrentValuelb&&pidRequestedValue>=pidSensorCurrentValuerb) pidRunning = false;
		wait1Msec(20);
	}
}
task auton(){
	//pidRequestedValue = (24/(circOfWheelInInches)*360);
	//startTask(pidLoopForForwardsandBackwards);
	//getMotorsWithDriveSideType(nType, nMotorList);
	//if(pidSensorCurrentValuelb)
	//20 in to cube, 45 deg rot
	SensorValue[BRI]=SensorValue[BLI]=0;
	//motor[BL] = motor[FR] = motor[BR] = motor[BL] = 127;
	wait1Msec(500);
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(24/(circOfWheelInInches)*392)&&SensorValue[BRI]<(24/(circOfWheelInInches)*392));
	wait1Msec(500);
	//do{
		//motor[FL] = -127;
		//motor[FR] = 127;
		//motor[BL] = -127;
		//motor[BR] = 127;
	//}while((SensorValue[BRI]>-(3.5/(circOfWheelInInches)*392))&&(SensorValue[BRI]>-(3.5/(circOfWheelInInches)*392)));
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	//open pneumatics
	SensorValue[pneumatics]=0;
	wait1Msec(500);
	//move forward 3 in
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(24/(circOfWheelInInches)*392)&&SensorValue[BRI]<(24/(circOfWheelInInches)*392));
	motor[FL] = -127;
	motor[FR] = 127;
	motor[BL] = -127;
	motor[BR] = 127;
	wait1Msec(2000);
	motor[FL] = 127;
	motor[FR] = -127;
	motor[BL] = 127;
	motor[BR] = -127;
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	wait1Msec(500);
	SensorValue[pneumatics]=0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	//rotate to back
	do{
		motor[BL] = motor[FR] = motor[BR] = motor[BL] = 127;
	}while(SensorValue[BRI] < (10/(circOfWheelInInches)*392) && SensorValue[BLI] < (10/(circOfWheelInInches)*392));
	wait1Msec(500);
	SensorValue[BRI]=SensorValue[BLI]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	//move backwards 25 in
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(25/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(25/(circOfWheelInInches)*392));
	//move arm up
	wait1Msec(500);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	do{
			motor[L1R1]=-90;
			motor[L2R2]=-90;
			motor[L3R3]=-90;
	}while(SensorValue[ArmEnc]>-150);
	wait1Msec(500);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	SensorValue[pneumatics]=1;
	wait1Msec(250);
	SensorValue[pneumatics]=0;
}
task auton2(){
	wait1Msec(2000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=0;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(25/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(25/(circOfWheelInInches)*392));
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	wait1Msec(500);
	SensorValue[BRI]=SensorValue[BLI]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(5/(circOfWheelInInches)*392)&&SensorValue[BRI]<(5/(circOfWheelInInches)*392));
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	wait1Msec(500);
	SensorValue[BRI]=SensorValue[BLI]=0;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(30/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(30/(circOfWheelInInches)*392));
	wait1Msec(500);
	SensorValue[pneumatics] = 1;
	wait1Msec(500);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	do{
			motor[L1R1]=-90;
			motor[L2R2]=-90;
			motor[L3R3]=-90;
	}while(SensorValue[ArmEnc]>-130);
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
			motor[L1R1]=90;
			motor[L2R2]=90;
			motor[L3R3]=90;
	}while(SensorValue[ArmEnc]<130);
	wait1Msec(2000);
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	do{
			motor[L1R1]=-90;
			motor[L2R2]=-90;
			motor[L3R3]=-90;
	}while(SensorValue[ArmEnc]>-130);
	wait1Msec(2000);
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
}
task auton3(){
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(15/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(15/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(3/(circOfWheelInInches)*392)&&SensorValue[BRI]<(3/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(15/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(15/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(3/(circOfWheelInInches)*392)&&SensorValue[BRI]<(3/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(15/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(15/(circOfWheelInInches)*392));
	/*do{
		motor[BL] = motor[FR] = motor[BR] = motor[BL] = -127;
	}while(SensorValue[BRI]> -(10/(circOfWheelInInches)*392) && SensorValue[BLI] > -(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(10/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	SensorValue[pneumatics] = 1;
	do{
		motor[FL] = -127;
		motor[FR] = 127;
		motor[BL] = -127;
		motor[BR] = 127;
	}while(SensorValue[BRI]>-(10/(circOfWheelInInches)*392)&&SensorValue[BRI]<(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(10/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	SensorValue[pneumatics]=0;
	do{
		motor[BL] = motor[FR] = motor[BR] = motor[BL] = 127;
	}while(SensorValue[BRI]< (10/(circOfWheelInInches)*392) && SensorValue[BLI] < (10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(10/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	do{
		motor[L1R1]=-90;
		motor[L2R2]=-90;
		motor[L3R3]=-90;	
	}while(SensorValue[ArmEnc]>-100);
	wait1Msec(750);
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(10/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(10/(circOfWheelInInches)*392));
	wait1Msec(1000);
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;*/
}
task auton4(){
	do{
		motor[FL] = 127;
		motor[FR] = -127;
		motor[BL] = 127;
		motor[BR] = -127;
	}while(SensorValue[BRI]<(15/(circOfWheelInInches)*392)&&SensorValue[BRI]>-(15/(circOfWheelInInches)*392));
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[FL] = 0;
	motor[FR] = 0;
	motor[BL] = 0;
	motor[BR] = 0;
	do{
		motor[L1R1]=-90;
		motor[L2R2]=-90;
		motor[L3R3]=-90;	
	}while(SensorValue[ArmEnc]>-90);
	motor[L1R1]=0;
	motor[L2R2]=0;
	motor[L3R3]=0;
	motor[BL] = motor[FR] = motor[BR] = motor[BL] = 0;
	SensorValue[BRI]=SensorValue[BLI]=SensorValue[ArmEnc]=0;
	motor[FL] = 0;
	motor[FR] = 0;
	motor[BL] = 0;
	motor[BR] = 0;
}
