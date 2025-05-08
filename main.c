#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_def.h"
#include "pOS.h"
#include "application/ball.h"
#include "application/obstacles.h"
#include "application/bins.h"

BALL_t* ball;

int size_obstacles;
OBSTACLES_t** obstacles;

int size_bins;
BINS_t** bins;

void Update_Screen()
{
    D1306_Show( GET_POINTER( D1306 , OLED ) );
    D1306_Clear( GET_POINTER( D1306 , OLED ) );
    OBSTACLES_Draw( obstacles , size_obstacles );
    BINS_Draw( bins , size_bins );
}

void Move_Ball()
{
    BALL_Move( ball );
    for (int i = 0; i < size_obstacles ; i++)
    {
        BALL_CheckColision( ball , obstacles[i]->x , obstacles[i]->y );
    }
    if( ball->x >= 108 )
    {
        BINS_AddBall( bins , size_bins , ball->y );
        ball->x = 0 ;
        ball->y = 32;
    }
}

int main()
{
    stdio_init_all();

    HAL_Init();

    int width = 1;

    ball = BALL_Init( 0 , 32 , 1 , width );

    OBSTACLES_CONFIG_t obstacles_cfg = {
        .rows = 31,
        .center = 32,
        .width = width,
        .height = 2
    };

    obstacles = OBSTACLES_Init( obstacles_cfg , &size_obstacles );

    BINS_CONFIG_t bins_cfg = { 
        .x = 88 , 
        .width = width, 
        .height = 40
    };

    size_bins = 64/( bins_cfg.width ) + 1;

    bins = BINS_Init( bins_cfg , size_bins );

    OS_CreateTask( 200 , Update_Screen );

    OS_CreateTask( 2 , Move_Ball );

    while (true)
    {
        OS_Run();
    }
}
