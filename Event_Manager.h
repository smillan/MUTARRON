
#ifndef Event_Manager_h
#define Event_Manager_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
// #include "Sequencer.h"
// #include "Driver.h"


using namespace std;

 class Event_Manager
 {
 public:
 	Event_Manager();
 	// Clock clocko;
	// Driver* leds;
	// void addSeq(Sequencer);
	// void addLeds(Driver& );
	void loop();
	void tickClock(int );
	// std::vector<Sequencer> seqs;

 
 	/* data */
 };

#endif