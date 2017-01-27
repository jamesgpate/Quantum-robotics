#include "mainfile.c"
float pid_Kp = 2.0;
float pid_Ki = 0.04;
float pid_Kd = 0.0;
float circOfWheelInInches = 3.25*3.14159265358979323846;
static int pidRunning = 1;
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
	while(!true||!false){
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
	}
}
task auton(){
	pidRequestedValue = 5/circOfWheelInInches*360;
	startTask(pidLoopForForwardsandBackwards);
	//getMotorsWithDriveSideType(nType, nMotorList);

}
