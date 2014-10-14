
#ifndef CV_send_h
#define CV_send_h
#include <Arduino.h>


class CV_send
 {
 public:
 	CV_send(int, int, int, int);
	void openStep(int);
	void inhibit();
	void active();
	void setupCV();
	// void setPins(int, int, int, int);


 	byte clockType ;
 	int pin1;
 	int pin2;
 	int pin3;
 	int inhibitPin;
 	
 	/* data */
 };

#endif