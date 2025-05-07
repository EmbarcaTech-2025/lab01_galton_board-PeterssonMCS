#include <stdio.h>
#include "linked_list.h"
/*
BallNode_t* AddBall(BallNode_t** head) 
{
    BallNode_t* newNode = malloc(sizeof(BallNode_t));
    newNode->ball = BALL_Init( 1, 1 ); // Assume it sets vx, vy elsewhere
    newNode->next = *head;
    *head = newNode;
    return newNode;
}

void FreeAllBalls(BallNode_t* head) 
{
    BallNode_t* temp;
    while (head != NULL) 
    {
        temp = head;
        BALL_Free(head->ball);
        head = head->next;
        free(temp);
    }
}

void UpdateBalls(BallNode_t** head) 
{
    BallNode_t* current = *head;
    BallNode_t* prev = NULL;

    while (current != NULL) 
    {
        BALL_Move(current->ball); // Update y
        printf("%d %d\n", current->ball->x, current->ball->y);
        if( current->ball->y >= GROUND_Y ) 
        {
            BALL_Free(current->ball);
            BallNode_t* toDelete = current;

            if (prev == NULL) 
            {
                *head = current->next;
                current = *head;
            } 
            else
            {
                prev->next = current->next;
                current = prev->next;
            }

            free(toDelete);
        } else {
            prev = current;
            current = current->next;
        }
    }
}
*/