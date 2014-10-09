
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>

#include <Wire.h>

#include <Shifter.h>
#include "Event_Manager.h"

#include "Shifter_input.h"
#include "CV_send.h"
#include "Sequencer.h"
#include "Clock.h"

#include "LCD_Screen.h"
#include "LED_driver.h"
#include <LiquidCrystal.h>
using namespace std;
namespace std
{
  // ohserialstream cout(Serial);
}
Shifter_input input;
LiquidCrystal lcd(38, 40, 42, 44, 46, 48);
LCD_Screen info;
LED_driver leds;
Event_Manager eventManager;
Clock timer;
// Sequencer seq = Sequencer(0,8, input, leds);
// Sequencer seq[4]={,Sequencer(1,8, input, leds),Sequencer(2,16, input, leds),Sequencer(4,16, input, leds)};
// Sequencer seq = Sequencer(0,8);

unsigned long prevMillis=0;
int interval=80;
int cnt=0;
void setup()
{
	info.defaulto();
	eventManager.addSeq(Sequencer(0,8, input, leds));
	// eventManager.addSeq(Sequencer(1,8, input, leds));
	// eventManager.addSeq(Sequencer(2,16, input, leds));
	// eventManager.addSeq(Sequencer(4,16, input, leds));
 	timer.event_Manager=eventManager;

	info.defaulto();
	Serial.begin(9600);
	input.init();
	input.getValues();
	lcd.begin(16, 2);
	for(int i=0; i<24; i++){
	    leds.openLed(i);
	    delay(5);
	}
	leds.openLed(0);
	leds.clockStep(0);
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
	timer.runClock();
	input.getValues();
	trace();
	leds.checkSteps(input);
	leds.openLeds();
	info.getSequence16( input.steps, String(input.selected+1) );
	// eventManager.loop();
	writeScreen();
	
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