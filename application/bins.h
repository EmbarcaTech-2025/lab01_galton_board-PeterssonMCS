#ifndef _BINS_H_
#define _BINS_H_

typedef struct
{
    int balls;
    int x;
    int y;
    int width;
    int height;
}BINS_t;

typedef struct
{
    int x;
    int y;
    int width;
    int height;
}BINS_CONFIG_t;

BINS_t** BINS_Init( BINS_CONFIG_t , int );

void BINS_Draw( BINS_t** , int );

void BINS_AddBall( BINS_t** , int , int );

#endif