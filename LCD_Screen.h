
#ifndef LCD_Screen_h
#define LCD_Screen_h
#include <Arduino.h>

 class LCD_Screen
 {
 public:
 	LCD_Screen();
 	String info_string_top;
 	String info_string_bottom;
 	void getSequence16(byte* , String  );
 	void defaulto();
 
 	/* data */
 };

#endif