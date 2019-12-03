/**********************************************************************
* Filename    : motor.c
* Description : Controlling a motor.
* Author      : Robot
* E-mail      : support@sunfounder.com
* website     : www.sunfounder.com
* Date        : 2014/08/27
**********************************************************************/
#include <wiringPi.h>
#include  <stdio.h>

#define MotorPin1    4
#define MotorPin2    5
#define MotorEnable  6

int main(void)
{
	if(wiringPiSetup() == -1){ //when initialize wiring failed,print messageto screen
		printf("setup wiringPi failed !");
		return 1; 
	}
	
	pinMode(MotorPin1, OUTPUT);
	pinMode(MotorPin2, OUTPUT);
	pinMode(MotorEnable, OUTPUT);

	int i;

	while(1){
		digitalWrite(MotorEnable, HIGH);
		digitalWrite(MotorPin1, HIGH);
		digitalWrite(MotorPin2, LOW);
		for(i=0;i<3;i++){
			delay(1000);
		}

		digitalWrite(MotorEnable, LOW);
			delay(1000);

		digitalWrite(MotorEnable, HIGH);
		digitalWrite(MotorPin1, LOW);
		digitalWrite(MotorPin2, HIGH);
		for(i=0;i<3;i++){
			delay(1000);
		}

		digitalWrite(MotorEnable, LOW);
                        delay(1000);

	}

	return 0;
}
