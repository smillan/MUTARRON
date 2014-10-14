#include "Sequencer.h"

Sequencer::Sequencer(int pos, int nSteps, Shifter_input& input, LED_driver& leds,Cockpit& cockpitin,int gatePin, int ledpos){
	
	cockpit = &cockpitin;

	numSteps=nSteps;
	posicion=pos;
	isPlaying = false;
	ledsArray=&leds;
	nEightStepParts=numSteps/8;
	// step=0;
	currentCVout=0;
	data.seqParams.mode.name = "MOD";
	data.seqParams.mode.min = 0;
	data.seqParams.mode.max = 3;
	data.seqParams.mode.increment = 1;
	data.seqParams.mode.value = 3;

	data.seqParams.count.name = "NST";
	data.seqParams.count.min = 1;
	data.seqParams.count.max = 8;
	data.seqParams.count.increment = 1;
	data.seqParams.count.value = 1;

	data.seqParams.offset.name = "OFS";
	data.seqParams.offset.min = 0;
	data.seqParams.offset.max = data.seqParams.count.value;
	data.seqParams.offset.increment = 1;
	data.seqParams.offset.value = 0;



	data.seqParams.repeat.name = "RPT";
	data.seqParams.repeat.min = 0;
	data.seqParams.repeat.max = 3;
	data.seqParams.repeat.increment = 1;
	data.seqParams.repeat.value = 1;

	data.seqParams.clockDivision.name = "DIV";
	data.seqParams.clockDivision.min = 1;
	data.seqParams.clockDivision.max = 16;
	data.seqParams.clockDivision.increment = 1;
	data.seqParams.clockDivision.value = 1;

	data.seqParams.duration.name = "DUR";
	data.seqParams.duration.min = 0;
	data.seqParams.duration.max = 3;
	data.seqParams.duration.increment = 1;
	data.seqParams.duration.value = 3;

	

	data.seqParams.midiChan.name = "CHN";
	data.seqParams.midiChan.min = 0;
	data.seqParams.midiChan.max = 15;
	data.seqParams.midiChan.increment = 1;
	data.seqParams.midiChan.value = posicion;

	data.seqParams.step.name = "STP";
	data.seqParams.step.min = 0;
	data.seqParams.step.max = 360;
	data.seqParams.step.increment = 1;
	data.seqParams.step.value = 0;


	


	// data.seqParams.offset[1] = 0;
	// data.seqParams.offset[2]=3;
	 
	
	// step=0;
	totalSteps=nSteps*data.seqParams.count.value;
	muxStep=0;
	seqStep=0;
	shifter=&input;
	ledPos=ledpos;
	currentMillisGate=0;
	previousMillisGate=0;
	// params.a=0;

	// int pins[18]={17,18,19, 4,3,2, 7,6,5, 25,27,29, 20,21,23, 14,15,16};
	// int inhibitPins[6]={30,32,35,37,33,31};
	int pins[24]={17,18,19,30, 4,3,2,32, 7,6,5,35, 25,27,29,37, 20,21,23,33, 14,15,16, 31};
	for (int i = 0; i < (nEightStepParts); ++i)
	{	
		int tempPos=((posicion)*4)+(i*4);
		cv.push_back(CV_send(pins[tempPos],pins[tempPos]+1,pins[tempPos]+2,pins[tempPos]+3 ));

	}
	for (int i = 0; i < nSteps; ++i)
	{
		notes.push_back(36);
		triggers.push_back(shifter->steps[(posicion*8)+i]);
		// leds.push_back(input.steps[posicion+i]);
	}

}

void Sequencer::sendData(int pos)
{
	cockpit->addDataSet(data, pos);
	// cockpit
}


// void Sequencer::addCockpit(Cockpit& cockin){
// 	cockpit = &cockin;
// }

void Sequencer::globalSequence(int cnt, int offs)
{
	// count=cnt;
	// offset=offs;
	// totalSteps=numSteps*count;
	// initStep=(offset*8);
	// muxStep=(step%numSteps)-initStep;



}

void Sequencer::sendCV(){
	for (int i = 0; i < cv.size(); ++i)
	{
		if (currentCVout==i)
		{	
			cv[i].openStep(muxStep);
			cv[i].active();

		}else{

			cv[i].inhibit();

		}
	}
	
	
	
}
void Sequencer::openGate(){
	digitalWrite(gatePin, HIGH);
	currentMillisGate=millis();
}

void Sequencer::storeSeqParams(){
	  // cockpit->data.seqParams.clockDivision=1;
	// cockpit->data.seqParams.offset= data.seqParams.offset;
	// memcpy(cockpit->seqParams, seqParams, 8);
}

void Sequencer::closeGate(){
	if(currentMillisGate - previousMillisGate >= data.seqParams.duration.value) {
		digitalWrite(gatePin, LOW);
		previousMillisGate = currentMillisGate; 		  
	}
	// cockpit.se
}

void Sequencer::clockStep(int timer)
{
		if (timer%numSteps==0)
		{
 			data.seqParams=cockpit->seqsData[posicion]->seqParams;
			/* code */
		}
	totalSteps=numSteps*data.seqParams.count.value;
	initStep=(data.seqParams.offset.value*8);
	muxStep=cockpit->seqsData[posicion]->seqParams.step.value%8;
	seqStep=cockpit->seqsData[posicion]->seqParams.step.value%numSteps;
	if(seqStep>7){
		currentCVout=1;
	}else{
		currentCVout=0;
	}


	if (timer % data.seqParams.clockDivision.value==0 )
	{
			// Serial.print("clockDivision");
			// Serial.print(" | ");
			// Serial.print(data.seqParams.clockDivision.value);
			// Serial.print("\r\n");
			// Serial.print("count");
			// Serial.print(" | ");
			// Serial.print(data.seqParams.count.value);
			// Serial.print("\r\n");
			// Serial.print("pos");
			// Serial.print(" | ");
			// Serial.print(posicion);
			// Serial.print("\r\n");
			// Serial.print("step");
			// Serial.print(" | ");
			// Serial.print(data.seqParams.step.value);
			// Serial.print("\r\n");

			// Serial.print("totalSteps");
			// Serial.print(" | ");
			// Serial.print(totalSteps);
			// Serial.print("\r\n");
			// Serial.print("\r\n");
			// Serial.print("\r\n");
			// Serial.print("\r\n");
		if (data.seqParams.step.value>=initStep && data.seqParams.step.value<(initStep+numSteps))
		{
				
			if (shifter->steps[data.seqParams.step.value]==1)
			{
				
				//OPEN GATE 
				//SEND NMIDINOTE
			}
			
			sendCV();

			///RMOVE THIS FUYNCTION LATER BRO¡¡¡ this is only for 24 leds
			if(ledPos<24){
				
				int tempStep = ledPos+(muxStep+(currentCVout*8));
				ledsArray->setTempLed(tempStep);
				
			}
			// ledsArray.checkSteps(shifter.steps);
			// ledsArray.openLeds();
			
		}

		
		cockpit->seqsData[posicion]->seqParams.step.value=(cockpit->seqsData[posicion]->seqParams.step.value+1)%totalSteps;
	}
		

	
}
