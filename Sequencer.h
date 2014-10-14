//8 steps

#ifndef Sequencer_h
#define Sequencer_h
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <list>
#include <Arduino.h>
#include "Shifter_input.h"
#include "LED_driver.h"
#include "CV_send.h"
#include "Cockpit.h"
#include "SeqData.h"
using namespace std;

class Sequencer
 {
 public:
 	Sequencer(int, int, Shifter_input&, LED_driver&,Cockpit&, int, int);
 	bool isPlaying;
	int posicion; // global order for sequencers
	int gatePin;
 	
	// int pins[18];
	int numSteps; // total phisycal steps
 	int initStep; //  start point with offset
	int totalSteps; // numSteps * bars
 	int muxStep; //the one to send to the IC 4051
 	int seqStep; // step for checking CV out if it's 16 part seq
 	int currentCVout; // if it's 16 parts select the IC to send CV
 	int nEightStepParts; // checks if it is a 8 or 16 part seq
 	int step;
 	int ledPos; // this is for removal on final version hardware
 	SeqData data;
 	Shifter_input* shifter ; 
 	LED_driver* ledsArray ;
 	void sendCV();
 	void clockStep(int);
	void globalSequence(int, int );
	void closeGate();
	void openGate();
	void storeSeqParams();
	int midiChan;
	std::vector<CV_send> cv;
	std::vector<int> notes;
	std::vector<int> vels;
	std::vector<int> durs;
	std::vector<int> triggers;
	String paramsTxt;
	// std::vector<int> params;
 	unsigned long currentMillisGate;
 	unsigned long previousMillisGate;
 	Cockpit* cockpit;
 	// void addCockpit(Cockpit&);
 	void sendData(int);
 	/* data */
 };

#endif