#ifndef _BALL_LIST_H_
#define _BALL_LIST_H_

#include "ball.h"
#include <stdlib.h>

struct BallNode
{
    BALL_t ball;
    struct BallNode* next;
};

typedef struct BallNode BALL_LIST_t;

BALL_LIST_t* BALL_LIST_Init(void);

void BALL_LIST_Add( BALL_LIST_t** , BALL_t );

#endif