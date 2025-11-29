#include "PWM_DRIVER.h"

int8_t driverInit()
{
    MODE1 MODE1_SELECT;
    MODE2 MODE2_SELECT;
    
    MODE1_SELECT.SLEEP = 0;
    MODE2_SELECT.OUTDRV = 1;
    MODE2_SELECT.OCH = 1;
    MODE2_SELECT.OUTNE = 1;

    // I2C_send(MODE_1, MODE1_SELECT.SND);
    printf("Waking up.....\r\n");
        
    // I2C_send(MODE_2, MODE2_SELECT.SND);
    printf("Initialized.\r\n");
}


int8_t setOutput()
{
    LEDOUT0 OUT0_SELECT;
    LEDOUT1 OUT1_SELECT;

    /*
    00 == OFF
    01 == ON
    10 == ON using PWM0
    11 == ON using PWM1
    */

    OUT0_SELECT.SND = 0;
    OUT1_SELECT.SND = 0;

    OUT0_SELECT.DEV1 = 0x02;
    OUT0_SELECT.DEV2 = 0x00;
    OUT0_SELECT.DEV3 = 0x00;
    OUT0_SELECT.DEV4 = 0x00;
    
    OUT1_SELECT.DEV5 = 0x00;
    OUT1_SELECT.DEV6 = 0x00;
    OUT1_SELECT.DEV7 = 0x00;
    OUT1_SELECT.DEV8 = 0x00;
    
    // I2C_send(OUT_0, OUT0_SELECT.SND);

    // I2C_send(OUT_1, OUT1_SELECT.SND);
   
}

int8_t setDuty()
{
    PWM0 dutycycle;
    dutycycle.SND = 0;
    dutycycle.SND = 127; // 50% Duty Cycle 
    
    // I2C_send(PWM_0, dutycycle.SND);
}