#ifndef _BALL_H_
#define _BALL_H_

typedef struct
{
    int x;
    int y;
    int vx;
    int vy;
}BALL_t;

void BALL_CheckColision( BALL_t* , int , int );

void BALL_Move( BALL_t* );

#endif