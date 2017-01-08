#include "driving.c"
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

//An attempt at displaying information through binary on our robot
extern int ledBits[8];
void byteToBits(int byte2){
	for(int i = 7; i<0; i--){
		if(byte2%2==1){
			ledBits[i] = 1;
		}
		else if(byte2%2==0) ledBits[i] = 0;
	}
}
