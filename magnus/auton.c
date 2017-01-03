#include "mainfile.c"
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
task doAuton(){
	motor[m2]=127;
	motor[m5]=127;
	motor[m6]=127;
	motor[m9]=127;
	motor[m3]=127;
	motor[m4]=127;
	motor[m7]=127;
	motor[m8]=127;
	wait1Msec(1500);
	motor[m2]=0;
	motor[m5]=0;
	motor[m6]=0;
	motor[m9]=0;
	motor[m3]=0;
	motor[m4]=0;
	motor[m7]=0;
	motor[m8]=0;	
}