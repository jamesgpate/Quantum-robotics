task auton(){
	SensorValue[ArmEnc]=SensorValue[Right]=SensorValue[Left]=0;
	motor[L1R1]=motor[FL]=motor[L2R2]=motor[BL]=motor[FR]=motor[L3R3]=motor[BR]=0;
	do{
		motor[FL]=motor[BL]=127;
		motor[FR]=motor[BR]=-127;
	}while();
	SensorValue[ArmEnc]=SensorValue[Right]=SensorValue[Left]=0;
	motor[L1R1]=motor[FL]=motor[L2R2]=motor[BL]=motor[FR]=motor[L3R3]=motor[BR]=0;
	wait1Msec(300);
	do{
		motor[FL]=motor[BL]=127;
		motor[FR]=motor[BR]=127;
	}while();
	
}