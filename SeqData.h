
#ifndef SeqData_h
#define SeqData_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <algorithm>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

 class SeqData
 {
 public:
 	SeqData();
 	typedef struct
	   {
		// int maxVal;    
		String name;
		int min;
		int max;
		int increment;
		int value;

	   }   settings;   
	   

	typedef struct
	   {
		// int maxVal;    
		String name;
		int value;

	   }   mode;   



	typedef struct
	   {
		// int maxVal;    
		settings offset; // min, max, value
		settings count; // how many bars X8
 		settings step; // current step in numSteps *  count     
		settings repeat; // how many loops
 		settings mode;
 		settings duration;
 		settings midiChan;
 		settings clockDivision;

	   }   params;    

	// params seqParams;

	params seqParams;
	String threeChar(String);
	String getDataTop(int seq, int page);
	String getDataBottom(int page);
	virtual void setData(int page, int valueInPage, int value);
 	/* Seqdata */
 };

#endif