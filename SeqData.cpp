#include "SeqData.h"
SeqData::SeqData()
{
	
	
}
String SeqData::getDataTop(int seq, int page)
{
	String temp="";
	switch(page)
	{
		case 0:
			temp=String(seq+1);
			temp+=seqParams.mode.name;
			temp+=" ";
			temp+=seqParams.count.name;
			temp+=" ";
			temp+=seqParams.offset.name;
			temp+=" ";
			temp+=seqParams.repeat.name;
			temp+=" ";
		break;
		case 1:
			temp=String(seq+1);
			temp+=seqParams.mode.name;
			temp+=" ";
			temp+=seqParams.clockDivision.name;
			temp+=" ";
			temp+=seqParams.duration.name;
			temp+=" ";
			temp+=seqParams.midiChan.name;
			temp+=" ";
		break;

	}
	
	// Serial.print( seqParams.repeat.value);
	return  temp;

}

String SeqData::getDataBottom(int page)
{
	String temp=" ";
	switch(page)
	{
		case 0:
		temp=" ";
		temp+= threeChar( String(seqParams.mode.value) );
		temp+=" ";
		temp+= threeChar( String(seqParams.count.value) );
		temp+=" ";
		temp+= threeChar( String(seqParams.offset.value) );
		temp+=" ";
		temp+= threeChar( String(seqParams.repeat.value) );
		temp+=" ";
		break;
		case 1:
		temp=" ";
		temp+= threeChar( String(seqParams.mode.value+1) );
		temp+=" ";
		temp+= threeChar( String(seqParams.clockDivision.value) );
		temp+=" ";
		temp+= threeChar( String(seqParams.duration.value) );
		temp+=" ";
		temp+= threeChar( String(seqParams.midiChan.value+1) );
		temp+=" ";
		break;
	}
	// Serial.print( seqParams.repeat.value);
	return temp;

}






void SeqData::setData(int page, int valueInPage, int value)
{
	Serial.print(" xx ");

	switch(page)
	{	
		int temp;
		case 0:
			switch(valueInPage)
				{
					case 0:
					temp =  ( seqParams.mode.value+(seqParams.mode.increment*value))%seqParams.mode.max;
					seqParams.mode.value = max(temp, seqParams.mode.min);
					break;
					case 1:
					temp =  ( seqParams.count.value+(seqParams.count.increment*value))%seqParams.count.max;
					seqParams.count.value = max(temp, seqParams.count.min);
					seqParams.offset.max = seqParams.count.value ;
					
					break;
					case 2:
					temp =  ( seqParams.offset.value+(seqParams.offset.increment*value))%seqParams.offset.max;
					seqParams.offset.value = max(temp, seqParams.offset.min);
					break;
					case 3:
					temp =  ( seqParams.repeat.value+(seqParams.repeat.increment*value))%seqParams.repeat.max;
					seqParams.repeat.value = max(temp, seqParams.repeat.min);
					break;
				}
		break;

		case 1:
			switch(valueInPage)
				{
					case 0:
					temp = (seqParams.mode.value+(seqParams.mode.increment*value))%seqParams.mode.max;
					seqParams.mode.value = max(temp, seqParams.mode.min);
					break;
					case 1:
					temp = (seqParams.clockDivision.value+(seqParams.clockDivision.increment*value))%seqParams.clockDivision.max;
					seqParams.clockDivision.value = max(temp, seqParams.clockDivision.min);
					break;
					case 2:
					temp = (seqParams.duration.value+(seqParams.duration.increment*value))%seqParams.duration.max;
					seqParams.duration.value = max(temp, seqParams.duration.min);
					break;
					case 3:
					temp = (seqParams.midiChan.value+(seqParams.midiChan.increment*value))%seqParams.midiChan.max;
					seqParams.midiChan.value = max(temp, seqParams.midiChan.min);
					Serial.print("midiformfunc");
						Serial.print(" | ");
						Serial.print(seqParams.midiChan.value);
						Serial.print("\r\n");
					break;
				}
		break;
	}
	
	
	// Serial.print( seqParams.repeat.value);

}
String SeqData::threeChar(String str){

	while(str.length() < 3){
	  // do something repetitive 200 times
	 str+=" ";
	}
	return str;
}
