#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_def.h"
#include "pOS.h"
#include "application/ball.h"
#include "application/obstacles.h"

BALL_t* ball;
int size_obstacles;
int** obstacles;

void Update_Screen()
{
    D1306_Show( GET_POINTER( D1306 , OLED ) );
    D1306_Clear( GET_POINTER( D1306 , OLED ) );
    OBSTACLES_Draw( obstacles , size_obstacles );
}

void Move_Ball()
{
    BALL_Move( ball );
    for (int i = 0; i < size_obstacles ; i++)
    {
        BALL_CheckColision( ball , obstacles[i][0] , obstacles[i][1] );
    }
}

int main()
{
    stdio_init_all();

    HAL_Init();

    ball = BALL_Init( 0 , 32 , 1 , 2 );

    obstacles = OBSTACLES_Init( 15 , 32 , 2 , 5 , &size_obstacles );

    OS_CreateTask( 200 , Update_Screen );

    OS_CreateTask( 200 , Move_Ball );

    while (true) 
    {
        OS_Run();
    }
}
