#include "Sequencer.h"
Sequencer::Sequencer(int pos, int nSteps, Shifter_input input, LED_driver leds){
	// extClock = clock;
	numSteps=nSteps;
	posicion=pos;
 	isPlaying = false;
 	clockDivision=1;
 	ledsArray=leds;
 	step=0;
 	offset=2;
 	count=4;
 	repeat=1;
 	totalSteps=nSteps*count;
 	muxStep=0;

	// int pins[18]={17,18,19, 4,3,2, 7,6,5, 25,27,29, 20,21,23, 14,15,16};
	// int inhibitPins[6]={30,32,35,37,33,31};
	int pins[24]={17,18,19,30, 4,3,2,32, 7,6,5,35, 25,27,29,37, 20,21,23,33, 14,15,16, 31};
	for (int i = 0; i < (numSteps/8); ++i)
	{	
		int tempPos=((posicion)*4)+(i*4);
		cv.push_back(CV_send(pins[tempPos],pins[tempPos]+1,pins[tempPos]+2,pins[tempPos]+3 ));

	}
	for (int i = 0; i < nSteps; ++i)
	{
		notes.push_back(36);
		triggers.push_back(input.steps[posicion+i]);
		// leds.push_back(input.steps[posicion+i]);
	}

}

void Sequencer::sendCV(CV_send cv){
	// cv.openStep(step);
}

void Sequencer::globalSequence(int cnt, int offs)
{
	count=cnt;
	offset=offs;
	totalSteps=numSteps*count;
	initStep=(offset*8);
	muxStep=(step%numSteps)-initStep;



}

void Sequencer::link(){


}

void Sequencer::clockStep(int timer){
	totalSteps=numSteps*count;
	initStep=(offset*8);
	muxStep=(step%numSteps);
	
	if (timer%clockDivision==0 )
	{
		
		// cv[0].openStep(muxStep);
		if (step>initStep && step<(initStep+numSteps))
		{
			Serial.print("openStep");
			Serial.print((" | "));
			Serial.print(muxStep);
			Serial.print(("\r\n"));
		}

		Serial.print("muxStep");
		Serial.print((" | "));
		Serial.print(muxStep);
		Serial.print(("\r\n"));

		Serial.print("step");
		Serial.print((" | "));
		Serial.print(step);
		Serial.print(("\r\n"));

		Serial.print("totalSteps");
		Serial.print((" | "));
		Serial.print(totalSteps);
		Serial.print(("\r\n"));

		Serial.print("initStep");
		Serial.print((" | "));
		Serial.print(initStep);
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		Serial.print(("\r\n"));
		step=(step+1)%totalSteps;
	}
	// int pins[24]={17,18,19,30, 4,3,2,32, 7,6,5,35, 25,27,29,37, 20,21,23,33, 14,15,16, 31};
	
	// int inhibitPins[6]={30,32,35,37,33,31};
	// Serial.print("posicion");
	// Serial.print(("\r\n"));
	// Serial.print(posicion);
	// Serial.print(("\r\n"));
	// for (int i = 0; i < (numSteps/8); ++i)
	// {	
	// 	Serial.print("i");
	// 	Serial.print(("\r\n"));
	// 	Serial.print(i*4);
	// 	Serial.print(("\r\n"));
	// 	Serial.print((((posicion)*4)+i));
	// 	Serial.print((" | "));
	// 	Serial.print(pins[(((posicion)*4)+(i*4))]);
	// 	Serial.print((" | "));
	// 	Serial.print(pins[(((posicion)*4)+(i*4))+1]);
	// 	Serial.print((" | "));
	// 	Serial.print(pins[(((posicion)*4)+(i*4))+2]);
	// 	Serial.print((" | "));
	// 	Serial.print(pins[(((posicion)*4)+(i*4))+3]);

	
	// 	Serial.print(("\r\n"));

		
	// 	// cv.push_back( CV_send( pins[(((posicion)*3)+i)], pins[(((posicion)*3)+i)+1], pins[(((posicion)*3)+i)+2], inhibitPins[(posicion+i)]) );
	// }
	// Serial.print(("\r\n"));
		
	// 	Serial.print(posicion);
	// 	Serial.print(("\r\n"));
	// 	Serial.print(("\r\n"));
		

	
}
