#include <DAC8571.h>
#include <Wire.h>

DAC8571 dac;

void setup() {
  Serial.begin(9600);
  Serial.println("Henlo!");
  //address: A0=0 0x98
  //address: A0=1 0x9C
  dac.begin(0x98);
  Serial.println("Generating a 16-bit triangle wave");
}

void loop() {
int reg;
    // Run through the full 16-bit scale for a triangle wave
    for (reg = 0; reg < 65535; reg++)
    {
      dac.setVoltage(reg, true);
    }
    for (reg = 65535; reg > 0; reg--)
    {
      dac.setVoltage(reg, true);
    }  

}
