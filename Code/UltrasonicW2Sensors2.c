#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <wiringPi.h> 

void Ultrasonic();
void Ultrasonic2();
#define PIN_TRIGGER 4 // GPIO
#define PIN_ECHO  6 // GPIO
#define PIN_TRIGGER2 27 // GPIO
#define PIN_ECHO2 28 // GPIO




long getMicrotime(){
  struct timeval currentTime;
  gettimeofday(&currentTime, NULL);
  
  return currentTime.tv_sec * (int)1e6 + currentTime.tv_usec;
}

int main(void)
{
	//wiringPiSetup();
	
    while(1){
		
		Ultrasonic();
		usleep(5000);
		printf("sensor 1 is asleep - \n");
		
		  
		
		Ultrasonic2();
		usleep(5000);
		printf("sensor 2 is asleep -  \n");
	  
  }

}




void Ultrasonic(){
	
	
	wiringPiSetup();
	//const int PIN_TRIGGER = 4;
	//const int PIN_ECHO = 5;
	pinMode (0, OUTPUT);
	pinMode (2, OUTPUT);

	pinMode(PIN_TRIGGER, OUTPUT);
	digitalWrite(PIN_TRIGGER, LOW);

	pinMode(PIN_ECHO, INPUT);

  
	  
	  printf("ultrasonic 1 \n\r ");
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
		//usleep(1000);
		usleep(1000);
		
		while(rangeCm <30){
		
			digitalWrite (0, HIGH);
			digitalWrite (2, HIGH); 
			delay (500) ;
			
			while(rangeCm > 30){
				digitalWrite (0, LOW);
				digitalWrite (2, LOW); 
				delay (500) ;
			}
		
			
		}	
			
}



void Ultrasonic2(){
	
wiringPiSetup();
//const int PIN_TRIGGER2  = 27;
//const int PIN_ECHO2 = 28;
pinMode (0, OUTPUT);
pinMode (2, OUTPUT);

  pinMode(PIN_TRIGGER2, OUTPUT);
  digitalWrite(PIN_TRIGGER2, LOW);

  pinMode(PIN_ECHO2, INPUT);

	  
	  printf("sensor 2 - \n\r");
	  digitalWrite(PIN_TRIGGER2, HIGH);
	  usleep(10);
	  digitalWrite(PIN_TRIGGER2, LOW);


	  int echo, previousEcho, lowHigh, highLow;
	  long startTime, stopTime, difference;
	  float rangeCm;
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
		rangeCm = difference / 58;
		printf("Start: %ld, stop: %ld, difference: %ld, range: %.2f cm\n\r\n", startTime, stopTime, difference, rangeCm);
		usleep(1000);
		
		if(rangeCm <30){
		
			digitalWrite (0, HIGH);
			digitalWrite (2, HIGH); 
			delay (500) ;
		
		}else{
			digitalWrite (0, LOW);
			digitalWrite (2, LOW); 
			delay (500) ;
		}
			
	
}








