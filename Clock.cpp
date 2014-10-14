#include "Clock.h"
Clock::Clock()
{
	clockState=LOW;
	timer=0;
	clockType=0;
	types[0]="INTERNAL";
	types[1]="MIDI";
	types[2 ]="CV";;
	pinMode(clockOutPin,OUTPUT);
	pinMode(clockInPin,INPUT);
	clockDuration=100;
	previousMillis=0;

}

void Clock::advance(){
	timer++;

	// Serial.print(timer);
	// Serial.print("\r\n");
}

void Clock::readTempo(){
    int clockSpeed= map(analogRead(analogInClockSpeed), 0,1023, 10, 5000);
    interval=clockSpeed;
}
void Clock::notify()
{	
	eventManager.tickClock(timer);


}
void Clock::runClock(){
				// Serial.print("timer");
				// Serial.print(" | ");
				// Serial.print(timer);
				// Serial.print("\r\n");
				// Serial.print("clockType");
				// Serial.print(" | ");
				// Serial.print(clockType);
				// Serial.print("\r\n");
				// Serial.print("\r\n");
				// Serial.print("\r\n");
	readTempo();
	//advance();
	switch(clockType){
		case 0:
		
			currentMillis = millis();
			if(currentMillis - previousMillis >= interval) {
				clockUp();
				advance();
				notify();
				// Serial.print("timerIN");
				// Serial.print("\r\n");
				// Serial.print(timer);
				// Serial.print("\r\n");

				previousMillis = currentMillis;	
			}
		
		break;
		case 1:
				// Serial.print("interval");
				// Serial.print(" | ");
				// Serial.print(interval);
				// Serial.print("\r\n");
				// Serial.print("clockType1");
				// Serial.print(" | ");
				// Serial.print(clockType);
				// Serial.print("\r\n");
		
		break;
	}
 }

void Clock::clockOut(){
	digitalWrite(clockOutPin, clockState);
}

void Clock::clockUp(){
  		clockState = HIGH;
		// digitalWrite(clockOutPin, clockState);
		clockOut();
		// currentMillisClockOutClock = millis();
}
void Clock::clockDown(){
		 currentMillisClockOut = millis();
		 if(currentMillisClockOut - previousMillisClockOut >= clockDuration) {
				clockState = LOW;
				clockOut();
				previousMillisClockOut = currentMillisClockOut; 
				}
}

