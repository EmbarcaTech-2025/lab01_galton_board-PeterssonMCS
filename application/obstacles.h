#ifndef _OBSTACLES_H_
#define _OBSTACLES_H_

int** OBSTACLES_Init( int rows , int center , int width , int height , int* size );

void OBSTACLES_Draw( int** obstacles , int size );

#endif