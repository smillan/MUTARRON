
#ifndef Event_Manager_h
#define Event_Manager_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include "Sequencer.h"

using namespace std;

 class Event_Manager
 {
 public:
 	Event_Manager();
 	// Clock clocko;
	std::vector<Sequencer> seqs;
	void addSeq(Sequencer);
	void loop();
	void tickClock(int );

 
 	/* data */
 };

#endif