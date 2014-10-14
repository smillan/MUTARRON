#include "Cockpit.h"
Cockpit::Cockpit(LiquidCrystal& LCD_Screen)
{
	LCD = &LCD_Screen;
	// input = &inputin;
	selectedSequencer=0;
	page =0;
	count =0;
	valueInPage=0;
	cursor[0]=0;
	cursor[1]=0;
}
void Cockpit::addDataSet(SeqData& datain, int pos)
{	
	 // temp 
	// sequencerData datad;
	// datad = &datain;
	seqsData[pos]=&datain;
	// seqsData[pos]=datad;
}


void Cockpit::update(){

	// String temp="";
	// for (int i = 0; i < 16; ++i)
	// {
	// 	if (input->steps[i]!=1)
	// 	{
	// 		 temp+="_";
	// 	}else{
	// 		 temp+="X";
	// 	}
 		

	// 	/* code */
	// }
	// Serial.print(seqsData[selectedSequencer]->seqParams.repeat.value);
	// Serial.print(seqsData[selectedSequencer].data->getDataTop(selectedSequencer));
	// Serial.print(seqsData[selectedSequencer].data->getDataBottom(selectedSequencer));
	String temp =seqsData[selectedSequencer]->getDataTop(selectedSequencer, page);
	String tempb =seqsData[selectedSequencer]->getDataBottom(page );
 	LCD_write(temp, tempb);
	LCD->setCursor(cursor[0], cursor[1]);

	LCD->blink();

}


// void Cockpit::setSequence(int*)
void Cockpit::LCD_write(String st1, String st2)
{

	LCD->setCursor(0,0);
	LCD->print(st1);
	LCD->setCursor(0,1);
	LCD->print(st2);

}

// void Cockpit::storeSeqParams(params& paramsin)
// {
//   // Serial.print((byte)&paramsin.clockDivision);

// }


void Cockpit::selectSeq(int seq)
{
	selectedSequencer=seq;
	// LCD_write("sokdhg", String(selectedSequencer));
	update();
}
void Cockpit::pageUp()
{	
	count++;
	valueInPage=(count)%4;
	if (valueInPage==0) page++;
	page=page%2;
	cursor[0] = 1+(valueInPage*4);
	cursor[1] = 1;
	LCD->setCursor(cursor[0], cursor[1]);
	update();
	// Serial.print("page");
	// Serial.print(" | ");
	// Serial.print(page);
	// Serial.print("valueInPage");
	// Serial.print(" | ");
	// Serial.print(valueInPage);
	// Serial.print("\r\n");

// LCD_write("sokdhg", "sgsdgh");

}
void Cockpit::pageDown()
{
LCD_write("sokdhg", "sgsdgh");

}
void Cockpit::valueUp()
{
	seqsData[selectedSequencer]->setData(page, valueInPage,1);
	Serial.print("step");
			Serial.print(" | ");
			Serial.print(seqsData[selectedSequencer]->seqParams.step.value);
			Serial.print("\r\n");

	update();



}
void Cockpit::valueDown()
{
	seqsData[selectedSequencer]->setData(page, valueInPage,-1);
	update();



}
