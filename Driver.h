
#ifndef Driver_h
#define Driver_h
#include <Arduino.h>

// #include <Shifter.h>
// #include "Shifter_input.h"


#define SER_Pin 13 //SER_IN ds
#define RCLK_Pin 12 //L_CLOCK
#define SRCLK_Pin 11 //CLOCK shcp
// #define shifter Shifter
#define NUM_REGISTERS 3
#define N_LEDS 24


class Driver
{
public:
	Driver();
	// void setupLeds();
	// void openLed( int );
	// void openLeds(  );
	void setTempLed(int);

	// void clockStep( );
	// void checkSteps();
	// void addInput(Shifter_input&);
	// Shifter shifter ; 
	// Shifter_input* input ;
	// byte clockLeds[N_LEDS];
	// byte sequenceLeds[N_LEDS];
	unsigned long prevMillis;
	// unsigned long currentMillis;
	// void forAll();
	// void for24();


	  // shifter();

	/* data */
};
#endif