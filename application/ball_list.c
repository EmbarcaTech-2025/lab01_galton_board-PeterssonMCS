#include <stdio.h>
#include "ball_list.h"

BALL_LIST_t* BALL_LIST_Init(void)
{
    return NULL;
}

void BALL_LIST_Add(BALL_LIST_t** head, BALL_t new_ball )
{
    BALL_LIST_t* new_node = (BALL_LIST_t*) malloc(sizeof(BALL_LIST_t));
    if (!new_node) return;

    new_node->ball = new_ball;
    new_node->next = NULL;

    if (*head == NULL) 
    {
        *head = new_node;
    } 
    else 
    {
        BALL_LIST_t* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = new_node;
    }
}