/**
* @file gyro-l3gd20h.cpp
* @brief Implementation of the L3GD20H gyro chip for ARM embed projects
* @author Jan-Willem Smaal <usenet@gispen.org>
* @date 7/9/2020 
*/

#include "vl53l0x.h"

TimeOfFlight::TimeOfFlight()
{
    x = 0; 
    y = 0; 
    z = 0; 
    temperature = 0; 
 
 #if 0 
    i2c.start ();
    i2c.write(VL530L0X_WRITE_PATTERN_SDO);
    i2c.write(CTRL_REG1);
    i2c.write(0x3F);
    //i2c.write()
    i2c.stop();
#endif 

}


uint8_t TimeOfFlight::ReadRegister(enum vl530l0x_register reg)
{
    uint8_t tmp;
    
#if 0 
    i2c.start();
    i2c.write(VL530L0X_WRITE_PATTERN_SDO);
    i2c.write(reg);

    i2c.start();
    i2c.write(VL530L0X_READ_PATTERN_SDO);
    tmp = i2c.read(0);
    i2c.stop();
#endif 
    return tmp;
}

/**
* Read the register X and store in the class member. 
* @author Jan-Willem Smaal <usenet@gispen.org>
* @param void 
* @date 7/9/2020
*/
int16_t TimeOfFlight::ReadX(void)
{
    uint16_t tmp;
    
#if 0 
    tmp = TimeOfFlight::ReadRegister(OUT_X_L);
    tmp = tmp + (TimeOfFlight::ReadRegister(OUT_X_H)<<8);
    x = tmp;
#endif 

    return tmp;
}


/* EOF  */