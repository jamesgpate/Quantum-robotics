#pragma config(Sensor, in1,    pot1,           sensorPotentiometer)
#pragma config(Sensor, in2,    pot2,           sensorPotentiometer)
#pragma config(Sensor, in8,    expVoltage,     sensorAnalog)
#pragma config(Sensor, dgtl1,  limit1,         sensorTouch)
#pragma config(Sensor, dgtl2,  limit2,         sensorTouch)
#pragma config(Sensor, dgtl5,  redLED1,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl6,  redLED2,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl7,  redLED3,        sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  yellowLED1,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  yellowLED2,     sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, greenLED1,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, greenLED2,      sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, greenLED3,      sensorLEDtoVCC)
#pragma config(Motor,  port2,           frontRight,    tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           backRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           frontLeft,     tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port5,           backLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           arm1,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           arm2,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           arm3,          tmotorVex393_MC29, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#pragma platform(VEX2)
#pragma competitionControl(Competition)
#include "Vex_Competition_Includes.c"
#include "AutonomousPrograms.c";
#include "driverControl.c";
#include "CommandsForControl.c";

void waitForPress(){
	while(nLCDButtons == 0){}
	wait1Msec(5);
}
void waitForRelease(){
	while(nLCDButtons != 0){}
	wait1Msec(5);
}
//
const short leftButton = 1;
const short centerButton = 2;
const short rightButton = 4;
//
int count = 0;
void pre_auton()//select auton program
{
	bStopTasksBetweenModes = true;
	clearLCDLine(0);
	clearLCDLine(1);
	//
	while(nLCDButtons != centerButton){
		switch(count){
		case 0:
			displayLCDCenteredString(0, "Autonomous 1");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				count = 3;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				count++;
			}
			break;
		case 1:
			displayLCDCenteredString(0, "Autonomous 2");
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				count++;
			}
			break;
		case 2:
			displayLCDCenteredString(0, "Autonomous 3");
			wait1Msec(500);
			displayLCDCenteredString(1, "<         Enter        >");
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				count++;
			}
			break;
		case 3:
			displayLCDCenteredString(0, "Autonomous 4");
			wait1Msec(500);
			displayLCDCenteredString(0, "<         Enter        >");
			waitForPress();
			if(nLCDButtons == leftButton){
				waitForRelease();
				count--;
			}
			else if(nLCDButtons == rightButton){
				waitForRelease();
				count = 0;
			}
			break;
		default:
			count = 0;
			break;
		}
	}
}
task autonomous()
{
	callAutonomous(count);//Runs auton program
}
task usercontrol()
{
	startTask(drivingControl); //Starts driver control
}
