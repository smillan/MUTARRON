#include "Event_Manager.h"
Event_Manager::Event_Manager()
{
	// clocko=clockin;
}

void Event_Manager::addSeq(Sequencer seq){
	seqs.push_back(seq);
}

void Event_Manager::tickClock(int step)
{
	for (int i = 0; i < seqs.size(); ++i)
	{
		seqs[i].clockStep(step);

	}
	

}


void Event_Manager::loop(){
	for (int i = 0; i < seqs.size(); ++i)
	{
		 // seqs[i].clockStep();

	}


}