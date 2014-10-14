#include "Step_Modes.h"
using namespace std;

Step_Modes::Step_Modes()
{
	totalSteps=8;	  
	up.name="UP";
	up.value=0;

	down.name="DOWN";
	down.value=1;

	upndown.name="UPND";
	upndown.value=2;

	randomero.name="RNDM";
	randomero.value=3;
	for (int i = 0; i < N_STEPS; ++i)
	{
		// stepSequence[i]=(i%N_STEPS);
	}
	   
}
void Step_Modes::upF()
{
	for (int i = 0; i < N_STEPS; ++i)
	{
		stepSequence[i]=i%totalSteps;
	}
}

void Step_Modes::downF()
{
	for (int i = 0; i < N_STEPS; ++i)
	{
		stepSequence[i]=totalSteps-(i%totalSteps);
	}
}
void Step_Modes::randomeroF()
{
	for (int i = 0; i < N_STEPS; ++i)
	{
		stepSequence[i]=random(totalSteps);
		
	}
}

void Step_Modes::upndownF()
{ 	int temp=0;
	for (int i = 0; i < N_STEPS; ++i)
	{
		if(i%3==0){
			temp++;
		}else{
			temp--;
		}
		stepSequence[i]=temp%totalSteps;;
	}
}


void Step_Modes::runMode(int mode, int total)
{	
	totalSteps = mode;
	int tempStep=step;
	switch(mode)
	{	
		//UP
		case 0:
			upF();
		break;
		case 1:
			downF();
		break;
		case 2:
			upndownF();
		break;
		case 3:
			randomeroF();
		break;

		// return tempStep;
	}
}

int Step_Modes::getStep(int step){
	Serial.print(" | ");
	Serial.print("stepSequence");
	Serial.print(stepSequence[step%N_STEPS]);
	return stepSequence[step%N_STEPS];

}

