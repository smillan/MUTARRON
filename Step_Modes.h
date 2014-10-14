
#ifndef Step_Modes_h
#define Step_Modes_h
#include <Arduino.h>
#include <StandardCplusplus.h>
#include <serstream>
#include <string>
#include <vector>
#include <iterator>
#include <list>
using namespace std;
#define N_STEPS 2
class Step_Modes
{
 public:
	Step_Modes();

	int timer;
	int step;
	int totalSteps;
	void runMode(int, int);
	int getStep(int);
	void upF(  );
	void downF(  );
	void upndownF(  );
	void randomeroF(  );
	

	typedef struct
	{
		String name;
		int value;
	} mode; 
	  
	mode up;  
	mode down;  
	mode randomero;  
	mode upndown;  
	std::vector<int> stepSequence;

	   
};

#endif