#ifndef MY_RAND_H
#define MY_RAND_H

#include <stdint.h>

#define MULTIPLER 75
#define MODULUS 65537
#define SEED 11152

void init_rand( float percentage );

int32_t pseurand();

#endif