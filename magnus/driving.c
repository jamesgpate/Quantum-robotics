#include "mainfile.c"
task driving()
{
	while(true){
		motor[left13]=vexRT[Ch3];
		motor[left24]=-vexRT[Ch3];
		motor[right13]=vexRT[Ch2];
		motor[right24]=-vexRT[Ch2];
	}
}
