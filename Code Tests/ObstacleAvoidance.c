//This code works

#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h>

int Ultrasonic1();
int Ultrasonic2();
int Ultrasonic3();
int motorSetup();
int motorTurnRight();
int motorTurnLeft();
int motorStop();
#define PIN_TRIGGER 4 // GPIO
#define PIN_ECHO  5 // GPIO

#define PIN_TRIGGER2 26 // GPIO
#define PIN_ECHO2 27 // GPIO

#define PIN_TRIGGER_3 28 // GPIO
#define PIN_ECHO_3 29 // GPIO

#define MotorPin1    0
#define MotorPin2    2
#define MotorEnable  3

#define Motor2Pin1    21
#define Motor2Pin2    22
#define Motor2Enable  23


long getMicrotime(){
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(void)
{
  while(1){
	  wiringPiSetup();
	
	  
	  printf("in main");
		Ultrasonic1();
		delay(500);
		printf("sensor 1 is asleep \n\r");
	  
	
		Ultrasonic2();
		delay(500);
		printf("sensor 2 is asleep \n\r");
		
		Ultrasonic3();
		delay(500);
		printf("sensor 3 is asleep \n\r");
	  
	  
  }

}




int Ultrasonic1 (){

	motorSetup();
	pinMode(PIN_TRIGGER, OUTPUT);
	digitalWrite(PIN_TRIGGER, LOW);

	pinMode(PIN_ECHO, INPUT);

	  
	  printf("sensor 1 - ");
	  digitalWrite(PIN_TRIGGER, HIGH);
	  usleep(10);
	  digitalWrite(PIN_TRIGGER, LOW);


	  int echo, previousEcho, lowHigh, highLow; 
	  long startTime, stopTime, difference;
	  float rangeCm;
	  lowHigh = highLow = echo = previousEcho = 0;
	  while(0 == lowHigh || highLow == 0) {
		previousEcho = echo;
		echo = digitalRead(PIN_ECHO);
		if(0 == lowHigh && 0 == previousEcho && 1 == echo) {
		  lowHigh = 1;
		  startTime = getMicrotime();
		}
		if(1 == lowHigh && 1 == previousEcho && 0 == echo) {
		  highLow = 1;
		  stopTime = getMicrotime();
		}
	  }

		difference = stopTime - startTime;
		rangeCm = difference / 58;
		printf("Start: %ld, stop: %ld, difference: %ld, range: %.2f cm\n\r\n", startTime, stopTime, difference, rangeCm);
		usleep(1000);
		
		if(rangeCm <30){
		
			motorTurnRight();
		
		}else{
			
			motorStop();       
   
		}	
	
	
	
}



int Ultrasonic2(){
	
	motorSetup();

	pinMode(PIN_TRIGGER2, OUTPUT);
	digitalWrite(PIN_TRIGGER2, LOW);

	pinMode(PIN_ECHO2, INPUT);

	  
	  printf("sensor 2 - ");
	  digitalWrite(PIN_TRIGGER2, HIGH);
	  usleep(10);
	  digitalWrite(PIN_TRIGGER2, LOW);


	  int echo, previousEcho, lowHigh, highLow;
	  long startTime, stopTime, difference;
	  float rangeCm2;
	  lowHigh = highLow = echo = previousEcho = 0;
	  while(0 == lowHigh || highLow == 0) {
		previousEcho = echo;
		echo = digitalRead(PIN_ECHO2);
		if(0 == lowHigh && 0 == previousEcho && 1 == echo) {
		  lowHigh = 1;
		  startTime = getMicrotime();
		}
		if(1 == lowHigh && 1 == previousEcho && 0 == echo) {
		  highLow = 1;
		  stopTime = getMicrotime();
		}
	  }

		difference = stopTime - startTime;
		rangeCm2 = difference / 58;
		printf("Start: %ld, stop: %ld, difference: %ld, range: %.2f cm\n\r\n", startTime, stopTime, difference, rangeCm2);
		usleep(1000);
		
		if(rangeCm2 <30){
			
			motorTurnLeft();
		
		}else{
			
			motorStop();      
   
		}	
	
}

int Ultrasonic3 (){

	motorSetup();
	pinMode(PIN_TRIGGER_3, OUTPUT);
	digitalWrite(PIN_TRIGGER_3, LOW);

	pinMode(PIN_ECHO_3, INPUT);

	  
	  printf("sensor 3 - ");
	  digitalWrite(PIN_TRIGGER_3, HIGH);
	  usleep(10);
	  digitalWrite(PIN_TRIGGER_3, LOW);


	  int echo, previousEcho, lowHigh, highLow; 
	  long startTime, stopTime, difference;
	  float rangeCm3;
	  lowHigh = highLow = echo = previousEcho = 0;
	  while(0 == lowHigh || highLow == 0) {
		previousEcho = echo;
		echo = digitalRead(PIN_ECHO_3);
		if(0 == lowHigh && 0 == previousEcho && 1 == echo) {
		  lowHigh = 1;
		  startTime = getMicrotime();
		}
		if(1 == lowHigh && 1 == previousEcho && 0 == echo) {
		  highLow = 1;
		  stopTime = getMicrotime();
		}
	  }

		difference = stopTime - startTime;
		rangeCm3 = difference / 58;
		printf("Start: %ld, stop: %ld, difference: %ld, range: %.2f cm\n\r\n", startTime, stopTime, difference, rangeCm3);
		usleep(1000);
		
		if(rangeCm3 <30){
		
			motorTurnRight();
			motorTurnLeft();
			
		
		}else{
			
			motorStop();       
   
		}	
	
	
	
}

int motorSetup(){
	pinMode(MotorPin1, OUTPUT);
	pinMode(MotorPin2, OUTPUT);
	pinMode(MotorEnable, OUTPUT);
	pinMode(Motor2Pin1, OUTPUT);
	pinMode(Motor2Pin2, OUTPUT);
	pinMode(Motor2Enable, OUTPUT);	
}

int motorTurnRight(){
	digitalWrite(MotorEnable, HIGH);
	digitalWrite(Motor2Enable, HIGH);
	
	digitalWrite(MotorPin1, HIGH);
	digitalWrite(MotorPin2, LOW);
	delay(700);
	
	digitalWrite(Motor2Pin1, HIGH);
	//digitalWrite(Motor2Pin2, LOW);
	digitalWrite(MotorPin1, HIGH);
	
	delay(3000);
	
}

int motorTurnLeft(){
	digitalWrite(MotorEnable, HIGH);
	digitalWrite(Motor2Enable, HIGH);
	
	digitalWrite(MotorPin1, LOW);
	digitalWrite(Motor2Pin1, HIGH);
	delay(700);
	
	digitalWrite(Motor2Pin1, HIGH);
	digitalWrite(MotorPin1, HIGH);
	
	delay(3000);
	
}

int motorStop(){
		digitalWrite(MotorPin1, LOW);
		digitalWrite(MotorPin2, LOW);
		digitalWrite(Motor2Pin1, LOW);
		digitalWrite(Motor2Pin2, LOW);
	
}




