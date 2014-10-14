#include "LED_driver.h"

LED_driver::LED_driver() : shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS)
{
	prevMillis=0;


}

void LED_driver::setupLeds(){
	// init arrays
	for(int i=0; i<N_LEDS; i++){
		sequenceLeds[i]=0;   
		currentLeds[i]=0;   
		clockLeds[i]=0;   
	}
}

void LED_driver::addInput(Shifter_input& shifter)
{
	input=&shifter;
}

void LED_driver::checkSteps(){

	for (int i = 0; i < 24; ++i)
	{
		sequenceLeds[i]=input->steps[i];
		
	}
}


void LED_driver::for24(){
	int temp=0;
	for (int i = 0; i < N_LEDS; ++i)
	{
		temp=i;
		if(i>7 ){
			temp=i+8;
		}
		sequenceLeds[i]=input->steps[temp];
		shifter.setPin(i, clockLeds[i]);
		
	}
}

void LED_driver::forAll(){
	
	for (int i = 0; i < N_LEDS; ++i)
	{
		sequenceLeds[i]=input->steps[i];
		shifter.setPin(i, clockLeds[i]);
	}
}

void LED_driver::openLeds(){
	currentMillis=millis();

	shifter.clear(); //set all pins on the shift register chain to LOW
  	shifter.write(); //send changes to the chain and display them

	
 	
	// forAll();
	for24();


 	shifter.write(); //send changes to the chain and display them
 	if(currentMillis - prevMillis >= 100){
		memcpy(clockLeds, sequenceLeds, N_LEDS);

		
		prevMillis = currentMillis; 
	}



 
}
void LED_driver::setTempLed(int led)
{	
		
		
		if(sequenceLeds[led]==1){

			clockLeds[led]=0;

		}else{

			clockLeds[led]=1;


		}

		// Serial.print("currentLeds");
		// Serial.print(" | ");
		// Serial.print(led);
		// Serial.print("\r\n");
		// for (int i = 0; i < 24; ++i)
		// {
		// 	/* code */
		// 	Serial.print(" | ");
		// 	Serial.print(currentLeds[i]);
		// }
		
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");

		// Serial.print("sequenceLeds");
		// Serial.print("\r\n");
		// for (int i = 0; i < 24; ++i)
		// {
		// 	/* code */
		// 	Serial.print(" | ");
		// 	Serial.print(sequenceLeds[i]);
		// }
		
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");
		// Serial.print("\r\n");


}



void LED_driver::clockStep(){
	
	// memcpy(currentLeds, sequenceLeds, N_LEDS);
	// Serial.print("clockstep");



	for (int i = 0; i < N_LEDS; ++i)
	{		
		// Serial.print(" | ");
		// Serial.print(currentLeds[i]);

		// if(currentLeds[i]==1)
		// {
		// 	if (sequenceLeds[i]==1)
		// 	{
		// 		currentLeds[i]=0;
		// 		Serial.print(" | ");
		// 		Serial.print(" turnoff ");
		// 		Serial.print(i);

		// 	}else{
		// 		Serial.print(" | ");
		// 		Serial.print(" turnon ");
		// 		Serial.print(i);
		// 		currentLeds[i]=1;

		// 	}
		// }else{

		// 	currentLeds[i]=sequenceLeds[i];

		// }
	}
	// Serial.print("\r\n");
	// Serial.print("\r\n");
	// Serial.print("\r\n");

	
}

void LED_driver::openLed(int nLed){
	
  shifter.clear(); //set all pins on the shift register chain to LOW
  shifter.write(); //send changes to the chain and display them
  shifter.setPin(nLed, HIGH); //set pin 1 in the chain(second pin) HIGH
  
  shifter.write(); //send changes to the chain and display them

}