#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
#endif

#include <Wire.h>

#define DAC8571_C_setUpdate (0x10)
#define DAC8571_C_set 		(0x00)
#define DAC8571_C_Update 	(0x20)


class DAC8571{
	private:
	 uint8_t address;
	 uint16_t dac_value;
	 int convert_value(uint16_t valoo, int bytee);
	
	public:
	 void begin(uint8_t addr);
	 void setVoltage(uint16_t value, bool updt);
	 void update();
};