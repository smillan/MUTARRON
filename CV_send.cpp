#include "CV_send.h"
CV_send::CV_send(int muxpin1,int muxpin2,int muxpin3,int inhibit ) 
{
	pin1=muxpin1;
	pin2=muxpin2;
	pin3=muxpin3;
	inhibitPin=inhibit;	
	setupCV();

	
}

void CV_send::openStep(int nStep)
{
	
    int r0 = bitRead(nStep,0);    // use this with arduino 0013 (and newer versions)     
    int r1 = bitRead(nStep,1);    // use this with arduino 0013 (and newer versions)     
    int r2 = bitRead(nStep,2);
    digitalWrite(pin1, r0);
    digitalWrite(pin2, r1);
    digitalWrite(pin3, r2);
    
}

void CV_send::inhibit( )
{
	 digitalWrite(inhibitPin, HIGH);
   
}

// void CV_send::setPins(int muxpin1,int muxpin2,int muxpin3,int inhibit )
// {
// 	pin1=muxpin1;
// 	pin2=muxpin2;
// 	pin3=muxpin3;
// 	inhibitPin=inhibit;
// 	setupCV();
// }

void CV_send::active()
{
	 digitalWrite(inhibitPin, LOW);
}

void CV_send::setupCV()
{	
	pinMode(pin1, OUTPUT);
	pinMode(pin2, OUTPUT);
	pinMode(pin3, OUTPUT);
	pinMode(inhibitPin, OUTPUT);


}