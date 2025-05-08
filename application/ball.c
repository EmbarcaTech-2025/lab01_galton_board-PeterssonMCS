#include "my_rand.h"
#include "ball.h"
#include <stdlib.h>
#include "hal_def.h"

void BALL_CheckColision( BALL_t* ball , int x , int y )
{
    if( ball->x == x && ball->y == y )
        ball->y += pseurand()*ball->vy;
}

void BALL_Move( BALL_t* ball )
{
    ball->x += ball->vx;
    D1306_DrawPixel( GET_POINTER( D1306 , OLED ) , ball->x , ball->y );
}