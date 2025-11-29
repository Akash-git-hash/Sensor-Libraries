#ifndef PWM_DRIVER_H
#define PWM_DRIVER_H

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

// Sensor Address
#define PCA9634_I2C_ADDRESS 0x07

// Control Registers 
#define MODE_1 0x00
#define MODE_2 0x01

// PWM Registers
#define PWM_0 0x02
#define PWM_1 0x03
#define PWM_2 0x04
#define PWM_3 0x05
#define PWM_4 0x06
#define PWM_5 0x07
#define PWM_6 0x08
#define PWM_7 0x09

#define GRP_PWM 0x0A
#define GRP_FREQ 0x0B

// Output Control Registers
#define OUT_0 0x0C
#define OUT_1 0x0D

typedef union 
{
    struct {
        uint8_t ALLCALL : 1;
        uint8_t SUB3    : 1;
        uint8_t SUB2    : 1;
        uint8_t SUB1    : 1;
        uint8_t SLEEP   : 1;
        uint8_t AI0     : 1;
        uint8_t AI1     : 1;
        uint8_t AI2     : 1;
    };
   uint8_t SND;
} MODE1;

typedef union 
{
    struct {
        uint8_t OUTNE   : 2;
        uint8_t OUTDRV  : 1;
        uint8_t OCH     : 1;
        uint8_t INVRT   : 1;
        uint8_t DMBLNK  : 1;
        uint8_t         : 1;
        uint8_t         : 1;
    };
    uint8_t SND;
} MODE2;

/*
 00 == LED OFF
 01 == LED ON
 10 == LED BLINK using PWM0
 11 == LED BLINK using PWM1
 */

typedef union 
{
    struct {
        uint8_t DEV1 : 2;
        uint8_t DEV2 : 2;
        uint8_t DEV3 : 2;
        uint8_t DEV4 : 2;
    };
    uint8_t SND;
} LEDOUT0;

typedef union 
{
    struct {
        uint8_t DEV5 : 2;
        uint8_t DEV6 : 2;
        uint8_t DEV7 : 2;
        uint8_t DEV8 : 2;
    };
    uint8_t SND;
} LEDOUT1;

typedef union 
{    
    struct {
        
        uint8_t bit0: 1;
        uint8_t bit1: 1;
        uint8_t bit2: 1;
        uint8_t bit3: 1;
        uint8_t bit4: 1;
        uint8_t bit5: 1;
        uint8_t bit6: 1;
        uint8_t bit7: 1;
    }; 
    uint8_t SND;
} PWM0;

int8_t driverInit();
int8_t setOutput();
int8_t setDuty();

#endif