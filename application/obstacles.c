#include "obstacles.h"
#include "hal_def.h"

int** OBSTACLES_Init( int rows , int center , int width , int height , int* size )
{
    int index = 0;
    *size = 0;
    int** obstacles;

    for (int i = 1; i <= rows; i++) { *size += i; }

    obstacles = malloc(*size * sizeof(int *));

    for (int i = 0; i < *size; i++) 
    {
        obstacles[i] = malloc(2 * sizeof(int));
    }

    for (int row = 1; row <= rows; ++row) 
    {
        int count = row;
        for (int i = 0; i < count; ++i) 
        {
            int offset = (int)((i - (count - 1) / 2.0) * 2 * width );
            obstacles[index][1] = center + offset;
            obstacles[index][0] = row * height;
            index++;
        }
    }
    
    return obstacles;
}

void OBSTACLES_Draw( int** obstacles , int size )
{
    for( int i = 0; i < size; i++ )
    {
        D1306_DrawPixel( GET_POINTER( D1306 , OLED ) , obstacles[i][0] , obstacles[i][1] );
    }
}