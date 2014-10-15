#include "Driver.h"

Driver::Driver() /* : shifter(SER_Pin, RCLK_Pin, SRCLK_Pin, NUM_REGISTERS)*/
{
	prevMillis=0;


}

// void Driver::setupLeds(){
// 	// init arrays
// 	for(int i=0; i<N_LEDS; i++){
// 		sequenceLeds[i]=0;   
// 		// currentLeds[i]=0;   
// 		clockLeds[i]=0;   
// 	}
// }

// void Driver::addInput(Shifter_input& shifter)
// {
// 	input=&shifter;
// }

// void Driver::checkSteps(){

// 	for (int i = 0; i < 24; ++i)
// 	{
// 		sequenceLeds[i]=input->steps[i];
		
// 	}
// }


// void Driver::for24(){
// 	int temp=0;
// 	for (int i = 0; i < N_LEDS; ++i)
// 	{
// 		temp=i;
// 		if(i>7 ){
// 			temp=i+8;
// 		}
// 		sequenceLeds[i]=input->steps[temp];
// 		shifter.setPin(i, clockLeds[i]);
		
// 	}
// }

// void Driver::forAll(){
	
// 	for (int i = 0; i < N_LEDS; ++i)
// 	{
// 		sequenceLeds[i]=input->steps[i];
// 		shifter.setPin(i, clockLeds[i]);
// 	}
// }

// void Driver::openLeds(){
// 	currentMillis=millis();

// 	shifter.clear(); //set all pins on the shift register chain to LOW
//   	shifter.write(); //send changes to the chain and display them

	
 	
// 	// forAll();
// 	for24();


//  	shifter.write(); //send changes to the chain and display them
//  	if(currentMillis - prevMillis >= 100){
// 		memcpy(clockLeds, sequenceLeds, N_LEDS);

		
// 		prevMillis = currentMillis; 
// 	}



 
// }
// void Driver::setTempLed(int led)
// {	
		
		
// 		if(sequenceLeds[led]==1){

// 			clockLeds[led]=0;

// 		}else{

// 			clockLeds[led]=1;


// 		}

		

// }



// void Driver::clockStep(){
	
// 	// memcpy(currentLeds, sequenceLeds, N_LEDS);
// 	// Serial.print("clockstep");



// 	for (int i = 0; i < N_LEDS; ++i)
// 	{		
		
// 	}
// 	// Serial.print("\r\n");
// 	// Serial.print("\r\n");
// 	// Serial.print("\r\n");

	
// }

// void Driver::openLed(int nLed){
	
//   shifter.clear(); //set all pins on the shift register chain to LOW
//   shifter.write(); //send changes to the chain and display them
//   shifter.setPin(nLed, HIGH); //set pin 1 in the chain(second pin) HIGH
  
//   shifter.write(); //send changes to the chain and display them

// }