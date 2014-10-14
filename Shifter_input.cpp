#include "Shifter_input.h"

Shifter_input::Shifter_input()
{
	 ploadPin        = 43;  // Connects to Parallel load pin the 165
	 clockEnablePin  = 45;  // Connects to Clock Enable pin the 165
	 dataPin         = 47; // Connects to the Q7 pin the 165
	 clockPin        = 41; // Connects to the Clock pin the 165


}



BYTES_VAL_T Shifter_input::read_shift_regs()
{
    long bitVal;
    BYTES_VAL_T bytesVal = 0;

    /* Trigger a parallel Load to la tch the state of the data lines,
    */
    digitalWrite(clockEnablePin, HIGH);
    digitalWrite(ploadPin, LOW);
    delayMicroseconds(PULSE_WIDTH_USEC);
    digitalWrite(ploadPin, HIGH);
    digitalWrite(clockEnablePin, LOW);

    /* Loop to read each bit value from the serial2 out line
     * of the SN74HC165N.
    */
    for(int i = 0; i < DATA_WIDTH; i++)
    {
        bitVal = digitalRead(dataPin);

        /* Set the corresponding bit in bytesVal.
        */
        bytesVal |= (bitVal << ((DATA_WIDTH-1) - i));

        /* Pulse the Clock (rising edge shifts the next bit).
        */
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(PULSE_WIDTH_USEC);
        digitalWrite(clockPin, LOW);
    }

    return(bytesVal);
}

BYTES_VAL_T2 Shifter_input::read_shift_regs2()
{
    long bitVal;
    BYTES_VAL_T2 bytesVal = 0;

    /* Trigger a parallel Load to la tch the state of the data lines,
    */
    digitalWrite(clockEnablePin, HIGH);
    digitalWrite(ploadPin, LOW);
    delayMicroseconds(PULSE_WIDTH_USEC);
    digitalWrite(ploadPin, HIGH);
    digitalWrite(clockEnablePin, LOW);

    /* Loop to read each bit value from the serial2 out line
     * of the SN74HC165N.
    */
    for(int i = 0; i < DATA_WIDTH2; i++)
    {
        bitVal = digitalRead(dataPin);

        /* Set the corresponding bit in bytesVal.
        */
        bytesVal |= (bitVal << ((DATA_WIDTH2-1) - i));

        /* Pulse the Clock (rising edge shifts the next bit).
        */
        digitalWrite(clockPin, HIGH);
        delayMicroseconds(PULSE_WIDTH_USEC);
        digitalWrite(clockPin, LOW);
    }

    return(bytesVal);
}


void Shifter_input::display_pin_values()
{
    
// Serial.print("Values1");
// 	Serial.print("\r\n");
   	memcpy(old_steps, steps, sizeof(steps));
		
    for(int i = 0; i < DATA_WIDTH; i++)
    {
        
        int invert;
        if((pinValues >> i) & 1){
            // Serial2.print(" 1Pin-");
            if(i<16){
                 // steps[32]=1;
                 // steps[33]=1;
                 steps[i+32]=1;
            }else if(i>15 && i<32){
                steps[i]=1;
                
            };
            // Serial2.print("\r\n");
        }else{
            if(i<16){
                 steps[i+32]=0;
            }else if(i>15 && i<32){
                steps[i]=0;
            };
           
        }
        //erial.print("\r\n");
    }
    

   // Serial2.print("\r\n");
}

void Shifter_input::display_pin_values2()
{
	// Serial.print("Values2");
	// Serial.print("\r\n");
   	memcpy(old_steps, steps, sizeof(steps));

    for(int i = 0; i < DATA_WIDTH2; i++)
    {
        
        if((pinValues2 >> i) & 1){
            steps[i]=1;
        }else{
//            Serial2.print("LOW");
            steps[i]=0;

        }
        //erial.print("\r\n");
    }
    

   // Serial2.print("\r\n");
}

void Shifter_input::init()
{
    // Serial1.begin(9600);

    /* Initialize our digital pins...
    */
    pinMode(ploadPin, OUTPUT);
    pinMode(clockEnablePin, OUTPUT);
    pinMode(clockPin, OUTPUT);
    pinMode(dataPin, INPUT);

    digitalWrite(clockPin, LOW);
    digitalWrite(ploadPin, HIGH);

    /* Read in and display the pin states at startup.
    */
    pinValues = read_shift_regs();
    pinValues2 = read_shift_regs2();
   
    oldPinValues = pinValues;
    oldPinValues2 = pinValues2;

    for(int i=0; i<48; i++){
        steps[i]=0;
    }
    getValues();
    display_pin_values();
    display_pin_values2();
}	
void Shifter_input::addCockpit(Cockpit& cockpitin)
{
    cockpit=&cockpitin;
}

void Shifter_input::getValues()
{	
	// Serial.print("getVsls");
	// Serial.print("\r\n");
    /* Read the state of all zones.
    */
    pinValues = read_shift_regs();
    pinValues2 = read_shift_regs2();
    // pinValues2 = read_shift_regs2();

    /* If there was a chage in state, display which ones changed.
    */
    
    if(pinValues != oldPinValues)
    {
        Serial.print("*Pin value change detected*\r\n");
        
       
        display_pin_values();
        
        selectStep();
        oldPinValues = pinValues;
    }
      if(pinValues2 != oldPinValues2)
    {
        Serial.print("*Pin value change detected in 2*\r\n");
        
        display_pin_values2();
        // for(int i=0; i<48; i++){
        //     Serial2.print("| ");
        //     Serial2.print(steps[i]);
        // }
        selectStep();
        oldPinValues2 = pinValues2;
    }
   

    // delay(POLL_DELAY_MSEC);
}
void Shifter_input::selectStep()
{
     for (int i = 0; i < sizeof(old_steps); ++i)
        {
            if(steps[i]!= old_steps[i]) selected = i;
        }
        cockpit->selectedStep = selected;
        cockpit->update();
}
