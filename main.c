#include <stdio.h>
#include "pico/stdlib.h"
#include "hal_def.h"
#include "pOS.h"
#include "application/ball_list.h"
#include "application/obstacles.h"
#include "application/bins.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

#define BIN_HEIGHT 50
#define STOP_HEIGHT ( SCREEN_WIDTH - BIN_HEIGHT )

#define BALL_START 27

BALL_LIST_t* ball_list;
GPIO_t* button_a;

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
    BALL_LIST_t** current_ptr = &ball_list;

    while (*current_ptr != NULL) 
    {
        BALL_LIST_t* current = *current_ptr;
        BALL_t* ball = &current->ball;

        BALL_Move(ball);

        for (int i = 0; i < size_obstacles; i++) 
        {
            BALL_CheckColision(ball, obstacles[i]->x, obstacles[i]->y);
        }

        if (ball->x >= STOP_HEIGHT) 
        {
            BINS_AddBall(bins, size_bins, ball->y);
            *current_ptr = current->next;
            free(current);
        } 
        else 
        {
            current_ptr = &((*current_ptr)->next);
        }
    }
}

void Read_Button()
{
    if( !GPIO_GetInput( button_a ) )
    {
        BALL_t new_ball = {
            .x = 0,
            .y = BALL_START,
            .vx = 1,
            .vy = 1
        };
        BALL_LIST_Add( &ball_list , new_ball );
    }
}

int main()
{
    stdio_init_all();

    HAL_Init();

    int width = 1;

    GPIO_CONFIG_t gpio_cfg = {
        .direction = 0,
        .logic = 1,
        .mode = 1,
        .pin = 5
    };

    OBSTACLES_CONFIG_t obstacles_cfg = {
        .rows = 31,
        .center = 32,
        .width = width,
        .height = 2
    };

    BINS_CONFIG_t bins_cfg = { 
        .x = STOP_HEIGHT, 
        .width = width, 
        .height = BIN_HEIGHT
    };

    size_bins = SCREEN_HEIGHT/( bins_cfg.width ) + 1;

    ball_list = BALL_LIST_Init();

    bins = BINS_Init( bins_cfg , size_bins );

    obstacles = OBSTACLES_Init( obstacles_cfg , &size_obstacles );

    button_a = GPIO_Init( gpio_cfg );
    
    OS_CreateTask( 200 , Update_Screen );
    OS_CreateTask( 100 , Read_Button );
    OS_CreateTask( 50 , Move_Ball );

    while (true)
    {
        OS_Run();
    }
}
