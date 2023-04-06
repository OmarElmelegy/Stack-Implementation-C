#ifndef STD_TYPES
#define STD_TYPES

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;
typedef signed char sint8_t;
typedef signed short sint16_t;
typedef signed int sint32_t;

typedef enum return_status{
    R_NOK,
    R_OK
}return_status_t;



#endif