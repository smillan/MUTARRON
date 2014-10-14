
#ifndef Control_h
#define Control_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <Bounce.h>
#include "Cockpit.h"
#define BUTTON 50
#define BUTTON2 52

using namespace std;


 class Control
 {
 public:
 	Control( Cockpit& );
 	Cockpit* cockpit;
 	// Bounce bouncer ; 
	// Bounce bouncer2 ; 
 	std::vector<Bounce> bouncerSw;
 	void controls();
 	/* data */
 };

#endif