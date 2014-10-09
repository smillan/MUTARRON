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
	timer=(timer+1)%(16*12);

	// Serial.print(timer);
	// Serial.print("\r\n");
}

void Clock::readTempo(){
    int clockSpeed= map(analogRead(analogInClockSpeed), 0,1023, 1, 5000);
    interval=clockSpeed;
}
void Clock::notify()
{	
	event_Manager.tickClock(timer);


}
void Clock::runClock(){
	readTempo();
	switch(clockType){
		case 0:
		{
			currentMillis = millis();
			if(currentMillis - previousMillis >= interval) {
				clockUp();
				advance();
				notify();
				// Serial.print("clocl");

				previousMillis = currentMillis;	
			}
		}
		break;
		case 1:
		
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

