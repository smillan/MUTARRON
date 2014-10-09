
#ifndef Clock_h
#define Clock_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include "Event_Manager.h"
// #include "Sequencer.h"


#define clockTypes 3 // 0 - INTERNAL, 1 - MIDI , 2-CV, 
#define clockInPin 9
#define clockOutPin 8
#define duration 100
#define analogInClockSpeed 7



 class Clock
 {
 public:
 	Clock();
 	unsigned long currentMillisClockOut;
 	unsigned long previousMillisClockOut;
 	unsigned long currentMillis;
 	unsigned long previousMillis;
 	Event_Manager event_Manager;
 	int clockDuration;
 	byte clockState;
 	int clockType;
 	String types[3];
 	int timer;
 	int beats;
 	int bars;
 	int step;
 	int interval;
 	int midiClockDiv;
 	int clockDiv;
 	void advance();
 	void clockUp();
 	void clockDown();
 	void clockOut();
 	void runClock();
 	void readTempo();
 	void notify();

 	/* data */
 };

#endif