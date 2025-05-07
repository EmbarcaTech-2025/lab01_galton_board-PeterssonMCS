#include "my_rand.h"

int32_t seed = SEED;

int32_t pseurand() 
{
    seed = ( seed*MULTIPLER ) % MODULUS;
    if( seed > 32768 )
    {
        return 1;
    }else
    {
        return -1;
    }
}