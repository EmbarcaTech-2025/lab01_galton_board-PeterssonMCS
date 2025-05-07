#include "my_rand.h"
#include "ball.h"
#include <stdlib.h>
#include "hal_def.h"

BALL_t* BALL_Init( int x , int y , int vx , int vy )
{
    BALL_t* ball = malloc( sizeof(BALL_t) );
    ball->x = x;
    ball->y = y;
    ball->vx = vx;
    ball->vy = vy;
    return ball;
}

void BALL_Free( BALL_t* ball )
{
    free(ball);
}

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