#include "hal_def.h"
#include <stdio.h>

const int kPinList[PIN_LIST_MAX] = { 
    #define MACRO( NAME , PIN ) PIN,
    PIN_LIST( MACRO )
    #undef MACRO 
};

HAL_LIST(GEN_VAR)
HAL_LIST(GET_VAR)

void HAL_Init()
{
    HAL_LIST( HAL_INIT )
}

bool periodic_callback( struct repeating_timer* timer )
{
    OS_Tick();
    return true;
}

GEN_CFG( TIMER )
{
    bool success = false;
    switch( id )
    {
        case TIMER_OS_ID:
            cfg->type = TIMER_PERIODIC;
            cfg->timeout = 1;
            cfg->periodic_callback = periodic_callback;
            cfg->alarm_callback = NULL;
            success = true;
        break;
        default:
            success = false;
        break;
    }
    return success;
}

GEN_CFG( D1306 )
{
    bool success = false;
    switch( id )
    {
        case D1306_OLED_ID:
            cfg->external_vcc = false;
            cfg->width = 128;
            cfg->height = 64;
            cfg->i2c_cfg.address = 0x3C;
            cfg->i2c_cfg.frequency = 400*1000;
            cfg->i2c_cfg.i2c_id = 1;
            cfg->i2c_cfg.pin_sda = kPinList[DISPLAY_SDA_ID];
            cfg->i2c_cfg.pin_sdl = kPinList[DISPLAY_SCL_ID];
            success = true;
        break;
        default:
            success = false;
        break;
    }
    return success;
}