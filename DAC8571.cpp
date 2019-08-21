#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

//address: A0=0 0x98
//address: A0=1 0x9C

#include "DAC8571.h"
#include <Wire.h>


	 void DAC8571::begin(uint8_t addr)
	 {
		 address=addr;
		 Wire.begin();		 
	 }
	 
	 void DAC8571::setVoltage(int value, bool updt)
	 {
		int valoo = value;
		if (valoo>=65535)
		{
			valoo=65535;
		}
		if (valoo<=0)
		{
			valoo=0;
		}
		Wire.beginTransmission(address);
		if (updt==true)
		{
			Wire.write(DAC8571_C_setUpdate);
		} else {
			Wire.write(DAC8571_C_set);
		}
		Wire.write(convert_value(valoo, 0));
		Wire.write(convert_value(valoo, 1));
		Wire.endTransmission();
		
	 }
	 
	 void DAC8571::update()
	 {
		Wire.beginTransmission(address);
		Wire.write(DAC8571_C_Update);
		Wire.endTransmission();
	 }
	 
	 int DAC8571::convert_value(int valoo, int bytee) 
	 {
		int tab[4];
		for (int i = 1; i>=0; i--) 
      {
			tab[i] = valoo & 0xFF;
			valoo = valoo >> 8; 
      }
    return tab[bytee];
	}
