#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_


typedef struct
{
    int x;
    int y;
}OBSTACLES_t;

typedef struct
{
    int rows;
    int center;
    int width;
    int height;
    int x_offset;
}OBSTACLES_CONFIG_t;

OBSTACLES_t** OBSTACLES_Init( OBSTACLES_CONFIG_t , int* );

void OBSTACLES_Draw( OBSTACLES_t** , int );

#endif