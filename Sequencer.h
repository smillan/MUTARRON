//8 steps

#ifndef Sequencer_h
#define Sequencer_h

#include <vector>
#include <iterator>
#include <Arduino.h>
#include "Shifter_input.h"
#include "LED_driver.h"
#include "CV_send.h"
// #include "Clock.h"
using namespace std;

class Sequencer
 {
 public:
 	Sequencer(int, int, Shifter_input, LED_driver);
 	bool isPlaying;
 	int offset;
 	int count;
 	int step;
	int pins[18];
	int numSteps;
	int totalSteps;
	int posicion;
 	int muxStep;
 	int initStep;
 	int repeat;
 	// int notes;
 	// int triggers;
 	// Clock extClock;
 	byte clockDivision;
 	byte clockType ;
 	// Shifter shifter ; 
 	LED_driver ledsArray ;
 	void sendCV(CV_send);
 	void clockStep(int);
	void globalSequence(int, int );
	void link();

	std::vector<CV_send> cv;
	std::vector<int> notes;
	std::vector<int> triggers;
 	

 	/* data */
 };

#endif