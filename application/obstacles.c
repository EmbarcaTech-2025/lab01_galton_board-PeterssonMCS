#include "obstacles.h"
#include "hal_def.h"

OBSTACLES_t** OBSTACLES_Init( OBSTACLES_CONFIG_t cfg , int* size )
{
    int index = 0;
    *size = 0;
    OBSTACLES_t** obstacles;

    for (int i = 1; i <= cfg.rows; i++) { *size += i; }

    obstacles = malloc( *size * sizeof(OBSTACLES_t *));

    for (int i = 0; i < *size; i++) 
    {
        obstacles[i] = malloc(2 * sizeof(OBSTACLES_t));
    }

    for (int row = 1; row <= cfg.rows; ++row) 
    {
        int count = row;
        for (int i = 0; i < count; ++i) 
        {
            int offset = (int)((i - (count - 1) / 2.0) * 2 * cfg.width );
            obstacles[index]->y = cfg.center + offset;
            obstacles[index]->x = row * cfg.height;
            index++;
        }
    }
    
    return obstacles;
}

void OBSTACLES_Draw( OBSTACLES_t** obstacles , int size )
{
    for( int i = 0; i < size; i++ )
    {
        D1306_DrawPixel( GET_POINTER( D1306 , OLED ) , obstacles[i]->x , obstacles[i]->y );
    }
}