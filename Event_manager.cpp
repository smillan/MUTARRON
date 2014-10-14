#include "Event_Manager.h"
Event_Manager::Event_Manager()
{
	// clocko=clockin;
}

void Event_Manager::addSeq(Sequencer seq){
	seqs.push_back(seq);
}

void Event_Manager::addLeds(LED_driver& ledsin)
{
 leds=&ledsin;
}


void Event_Manager::tickClock(int timer)
{
	for (int i = 0; i < seqs.size(); ++i)
	{
		seqs[i].clockStep(timer);

	}
	leds->clockStep();
	// leds->openLeds();

}


void Event_Manager::loop(){
	for (int i = 0; i < seqs.size(); ++i)
	{
		seqs[i].closeGate();

	}


}