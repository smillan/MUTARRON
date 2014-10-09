#include "LED_driver.h"

LED_driver::LED_driver() : shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS)
{
	prevMillis=0;


}

void LED_driver::setupLeds(){
	for(int i=0; i<N_LEDS; i++){
		sequenceLeds[i]=1;   
		currentLeds[i]=1;   
	}
}

void LED_driver::checkSteps(Shifter_input input){
	for (int i = 0; i < 24; ++i)
	{
		sequenceLeds[i]=input.steps[i];
	}
}

void LED_driver::openLeds(){
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  for(int i=0; i<N_LEDS; i++){ 
    shifter.setPin(i, currentLeds[i]);
	// if( step==i){
	// 	  //set pin 1 in the chain(second pin) HIGH
	// }	
  }
  
  shifter.write(); //send changes to the chain and display them
  if(currentMillis - prevMillis >= 400){
		memcpy(currentLeds, sequenceLeds, N_LEDS);
		prevMillis = currentMillis; 
	}
}

void LED_driver::clockStep(int step){
	currentMillis=millis();
	memcpy(currentLeds, sequenceLeds, N_LEDS);
	if (sequenceLeds[step]==1)
	{
		currentLeds[step]=0;
	}else{
		currentLeds[step]=1;


	}
	
}

void LED_driver::openLed(int nLed){
	
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  shifter.setPin(nLed, HIGH); //set pin 1 in the chain(second pin) HIGH
  
  shifter.write(); //send changes to the chain and display them

}