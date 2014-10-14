
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <Bounce.h>

#include <Wire.h>

#include <Shifter.h>
#include "Clock.h"
#include "Control.h"

#include "Event_Manager.h"
#include "Cockpit.h"

#include "Shifter_input.h"
#include "CV_send.h"
#include "Sequencer.h"

#include "LCD_Screen.h"
#include "LED_driver.h"
#include <LiquidCrystal.h>
using namespace std;
namespace std
{

}
//shift in for step input
Shifter_input input;
//LCD
LiquidCrystal lcd(38, 40, 42, 44, 46, 48);
LCD_Screen info;
Cockpit cockpit(lcd);
// Shitf out for led driving
LED_driver leds;
// LED_driver * ledpoint= &leds;

//The one that whispers to the sequencers
Event_Manager eventManager;
//ClOkCK
Clock timer;
Control control(cockpit);



//Tracing interval fro Serial.print
unsigned long prevMillis=0;
int interval=80;
int cnt=0;

void setup()
{
	input.init();
	input.getValues();
	input.addCockpit(cockpit);
	//init screen
	info.defaulto();
	//add the input to the leds so they know about the sequence.
	leds.addInput(input);
	///add the leds to the EventManager so they can be triggered by the same clock
	eventManager.addLeds(leds);
	// eventManager.addSeq();
	//ADD SEQUENCERS TO THE LIST 
	eventManager.addSeq(Sequencer(0,8, input, leds, cockpit ,53, 0));
	eventManager.addSeq(Sequencer(1,8, input, leds, cockpit ,51, 60));
	eventManager.addSeq(Sequencer(2,16, input, leds, cockpit ,34, 8));
	eventManager.addSeq(Sequencer(3,16, input, leds, cockpit ,10, 60));
	for(int i=0; i<eventManager.seqs.size(); i++){
	    	// eventManager.seqs[i].addCockpit(cockpit);
	    	// eventManager.seqs[i].sendData(eventManager.seqs[i]);
	}
	//add the eventManager to the clock so it can be triggered
 	timer.eventManager=eventManager;

	Serial.begin(9600);
	//INIT SEQUENCE
	lcd.begin(16, 2);
	for(int i=0; i<24; i++){
	    leds.openLed(i);
	    delay(5);
	}
	// leds.openLed(0);
	// leds.clockStep();
	// Print a message to the LCD.
	lcd.print("PROPER BOLLOCKS!");
	lcd.setCursor(0,1);
	// Serial.print("seq1");
	// Serial.print("\r\n");

	// Serial.print(seq[0].cv[0].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[0].cv[0].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[0].cv[0].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[0].cv[0].inhibitPin);
	// Serial.print("\r\n");
	
	// Serial.print("seq2");
	// Serial.print("\r\n");

	// Serial.print(seq[1].cv[0].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[1].cv[0].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[1].cv[0].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[0].inhibitPin);
	// Serial.print("\r\n");

	// Serial.print("seq3");
	// Serial.print("\r\n");
	
	// Serial.print(seq[2].cv[0].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[0].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[0].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[0].inhibitPin);
	// Serial.print("\r\n");

	// Serial.print(seq[2].cv[1].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[1].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[1].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[2].cv[1].inhibitPin);
	// Serial.print("\r\n");

	// Serial.print("seq4");
	// Serial.print("\r\n");

	// Serial.print(seq[3].cv[0].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[0].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[0].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[0].inhibitPin);
	// Serial.print("\r\n");

	// Serial.print(seq[3].cv[1].pin1);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[1].pin2);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[1].pin3);
	// Serial.print("\r\n");
	// Serial.print(seq[3].cv[1].inhibitPin);
	// Serial.print("\r\n");
	


}
void loop()
{	
	// Run clock
	timer.runClock();
	//always refresh inputs
	input.getValues();
	control.controls();
	// trace();
	//always udtape the led states
	// leds.checkSteps();
	//refresh leds
	leds.openLeds();
	// update Screen
	// info.getSequence16( input.steps, String(input.selected+1) );
	// writeScreen();
	for(int i=0; i<eventManager.seqs.size(); i++){
	    	// eventManager.seqs[i].addCockpit(cockpit);
	    	eventManager.seqs[i].sendData(i);
	}
	
}

void writeScreen(){
	lcd.clear();
	lcd.setCursor(0,0);
	lcd.print(info.info_string_top);
	lcd.setCursor(0,1);
	lcd.print(info.info_string_bottom);
	

}

void	trace(){

	unsigned long currentMillis=millis();
	if(currentMillis - prevMillis >= interval){
		// seq.clockStep();
		////////////TRACe HERE////////////
		// leds.clockStep(cnt=(cnt+1)%24);
		for(int i=0; i<4; i++){
		    // seq[i].clockStep(timer);
		}
		// for(int i=0; i<48; i++){
		//     byte step=input.steps[i];
		//     Serial.print(" ");
		//     Serial.print(step);


		// 	}
		// Serial.print("\r\n");

		/////
		prevMillis = currentMillis;   
	    
	}

}