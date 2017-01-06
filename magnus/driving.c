#include "mainfile.c"
#include "byteConverter.c"
/*
This file is part of the Quantum Robotics robot code.

The Quantum Robotics robot code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

The Quantum Robotics robot code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with the Quantum Robotics robot code.  If not, see <http://www.gnu.org/licenses/>.
*/
//Please give credit if you are using this
int ledBits[8] = {0,0,0,0,0,0,0,0};
task driving()
{
	while(true){
		motor[m2]=vexRT[Ch3];
		motor[m5]=vexRT[Ch3];
		motor[m6]=vexRT[Ch3];
		motor[m9]=vexRT[Ch3];
		motor[m3]=vexRT[Ch2];
		motor[m4]=vexRT[Ch2];
		motor[m7]=vexRT[Ch2];
		motor[m8]=vexRT[Ch2];
		if(vexRT[Btn5D]==1) motor[m1]=127;
		else if(vexRT[Btn5U]==1) motor[m1]=-127;
		if(vexRT[Btn6D]==1) motor[m10]=127;
		else if(vexRT[Btn6U]==1) motor[m10]=-127;
		byteToBits(motor[m2]);
		SensorValue[d1]=ledBits[0];
		SensorValue[d2]=ledBits[1];
		SensorValue[d3]=ledBits[2];
		SensorValue[d4]=ledBits[3];
		SensorValue[d5]=ledBits[4];
		SensorValue[d6]=ledBits[5];
		SensorValue[d7]=ledBits[6];
		SensorValue[d8]=ledBits[7];
	}
}
