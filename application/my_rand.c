#include "my_rand.h"

int32_t seed = SEED;

int32_t threshold;

void init_rand( float percentage )
{
    threshold = (int32_t)( percentage * 65537 );
}

int32_t pseurand() 
{
    seed = ( seed*MULTIPLER ) % MODULUS;
    if( seed > threshold )
    {
        return 1;
    }else
    {
        return -1;
    }
}