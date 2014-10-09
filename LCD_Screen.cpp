#include "LCD_Screen.h"
LCD_Screen::LCD_Screen()
{
	 info_string_top="PROPER LssLOCKZ!";
 	info_string_bottom="      sdfdsg      ";

}
void LCD_Screen::getSequence16(byte *sequence, String id){
	String temp="";
	for (int i = 0; i < 16; ++i)
	{
		if (sequence[i]==0)
		{
			 temp+="_";
		}else{
			 temp+="X";
		}
 		

		/* code */
	}
	info_string_top=temp;
 	info_string_bottom=id;
}
void LCD_Screen::defaulto(){

 	info_string_top="PROPER BOLLOCKZ!";
 	info_string_bottom+="                ";
	

}