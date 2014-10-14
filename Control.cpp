#include "Control.h"
Control::Control( Cockpit& cockin)
{
	cockpit= &cockin;
	int otherPins[7]={22,24,26,28,36,50,52};
	
	for(int i=0; i<8; i++){
	 pinMode(otherPins[i], INPUT);
	 // bouncerSw[i]=Bounce( otherPins[i], 5 ); 
	 
	}
	pinMode(BUTTON, INPUT);
	digitalWrite(BUTTON, HIGH);
	pinMode(BUTTON2, INPUT);
	digitalWrite(BUTTON2, HIGH);
	for (int i = 0; i < 8; ++i)
	{
		bouncerSw.push_back(Bounce( otherPins[i], 5 ));
	}
}

void Control::controls()
{
	// Get the update value
	// Turn on or off the LED
	if ( bouncerSw[5].update() ) {
	  		
		if ( bouncerSw[5].read() == HIGH) {
			cockpit->valueDown();
			
		}
   
   	}

	if ( bouncerSw[6].update() ) {
	  
		if ( bouncerSw[6].read() == HIGH) {
			cockpit->valueUp();
					}
	}

	for(int i=0; i<5; i++){
	if ( bouncerSw[i].update() ) {
	  
		if ( bouncerSw[i].read() == HIGH) {

			if(i<4){
				cockpit->selectSeq(i);
			}else if(i==4){
				cockpit->pageUp();
			}
		  
	}else{

		if(i<4){
			cockpit->selectSeq(i);
		}else if(i==4){
			cockpit->pageUp();
			Serial.print("page");
			Serial.print(" | ");
			Serial.print("\r\n");

		}


	}
   }
   }  

}