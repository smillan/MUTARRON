
#ifndef Cockpit_h
#define Cockpit_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <list>
#include <string>
#include <vector>
#include <iterator>
#include <LiquidCrystal.h>

#include "SeqData.h"
// #include "Event_Manager.h"

using namespace std;

 class Cockpit
 {
 public:
 	Cockpit(LiquidCrystal&);
 	LiquidCrystal* LCD;
 	// Shifter_input* input;
 	String info_string_top;
 	String info_string_bottom;
 	void update();
 	int selectedStep;
 	int selectedSequencer;
 	void LCD_write(String, String);
 	void pageUp();
 	void pageDown();
 	void valueUp();
 	void valueDown();
 	void selectSeq(int);
 	
 	
	std::vector<SeqData*> seqsData;

	void addDataSet(SeqData&, int);
	int count;
	int page;
	int valueInPage;
	int cursor[2];
 	// void storeSeqParams(params&);

	// void set
 	/* data */
 };

#endif