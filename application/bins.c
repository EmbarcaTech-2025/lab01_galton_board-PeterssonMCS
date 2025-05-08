#include "bins.h"
#include "hal_def.h"
#include <stdlib.h>

BINS_t** BINS_Init(BINS_CONFIG_t cfg, int size)
{
    BINS_t** bins = malloc(sizeof(BINS_t*) * size);

    int y = -1;
    for (int i = 0; i < size; i++)
    {
        bins[i] = malloc(sizeof(BINS_t));
        bins[i]->balls = 0;
        bins[i]->x = cfg.x;
        bins[i]->width = 2*cfg.width - 1;
        bins[i]->height = cfg.height;
        bins[i]->y = y;
        y = y + 2*cfg.width;
    }

    return bins;
}

void BINS_Draw(BINS_t** bins, int size)
{
    for (int i = 0; i < size; i++)
    {
        /* BIN DEBUG
        for (int x = bins[i]->x; x < bins[i]->x + bins[i]->height; ++x)
        {
            D1306_DrawPixel(GET_POINTER(D1306, OLED), x, bins[i]->y);
            D1306_DrawPixel(GET_POINTER(D1306, OLED), x, bins[i]->y + bins[i]->width + 1);
        }

        for (int y = bins[i]->y; y <= bins[i]->y + bins[i]->width; ++y)
        {
            D1306_DrawPixel(GET_POINTER(D1306, OLED), bins[i]->x + bins[i]->height, y);
        }
        */
        if( bins[i]->balls )
        {
            for ( int b = 0; b < bins[i]->balls ; b++ )
            {
                int cols = bins[i]->width;
                int ball_x = bins[i]->x + bins[i]->height - 1 - ( b / cols);
                int ball_y = bins[i]->y + ( b % cols ) + 1;
                D1306_DrawPixel(GET_POINTER(D1306, OLED), ball_x, ball_y);
            }
        }
    }
}

void BINS_AddBall(BINS_t** bins, int size, int pos)
{
    for (int i = 0; i < size; i++)
    {
        int bin_start = bins[i]->y;
        int bin_end = bins[i]->y + bins[i]->width + 1;

        if( pos > bin_start && pos <= bin_end )
        {
            int capacity = bins[i]->width * bins[i]->height;
            if (bins[i]->balls < capacity)
            {
                bins[i]->balls++;
            }
            break;
        }
    }
}