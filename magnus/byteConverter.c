#include "driving.c"
extern int ledBits[8];
void byteToBits(int byte2){
	for(int i = 7; i<0; i--){
		if(byte2%2==1){
			ledBits[i] = 1;
		}
		else if(byte2%2==0) ledBits[i] = 0;
	}
}
