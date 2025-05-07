#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

#include "ball.h"
#include <stdlib.h>

#define GROUND_Y 0

typedef struct BallNode {
    BALL_t* ball;
    struct BallNode* next;
} BallNode_t;

#endif