

#ifndef Shifter_input_h
#define Shifter_input_h

#include <Arduino.h>


#define NUMBER_OF_SHIFT_CHIPS  6
#define NUMBER_OF_SHIFT_CHIPS2  2

/* Width of data (how many ext lines).
*/
#define DATA_WIDTH   NUMBER_OF_SHIFT_CHIPS * 8
#define DATA_WIDTH2   NUMBER_OF_SHIFT_CHIPS2 * 8

/* Width of pulse to trigger the shift register to read and latch.
*/
#define PULSE_WIDTH_USEC   5

/* Optional delay between shift register reads.
*/
#define POLL_DELAY_MSEC   100

#define N_STEPS 48


/* You will need to change the "int" to "long" If the
 * NUMBER_OF_SHIFT_CHIPS is higher than 2.
*/
#define BYTES_VAL_T unsigned long int
#define BYTES_VAL_T2 unsigned long int
class Shifter_input
{
public:
	Shifter_input();
	BYTES_VAL_T read_shift_regs();
	BYTES_VAL_T2 read_shift_regs2();
	void display_pin_values();
	void display_pin_values2();
	void init();
	void getValues();
	BYTES_VAL_T pinValues;
	BYTES_VAL_T oldPinValues;
	BYTES_VAL_T2 pinValues2;
	BYTES_VAL_T2 oldPinValues2;
	byte selected;
	int ploadPin        ;  // Connects to Parallel load pin the 165
	int clockEnablePin  ;  // Connects to Clock Enable pin the 165
	int dataPin         ; // Connects to the Q7 pin the 165
	int clockPin        ; // Connects to the Clock pin the 165
	byte steps[N_STEPS];
	byte old_steps[N_STEPS];

	/* data */
};
#endif