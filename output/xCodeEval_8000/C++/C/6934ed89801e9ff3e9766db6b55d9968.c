#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

#define MAX_64 (0x7fffffffffffffffLL)
#define MAX_32 (0x7fffffff)
#define PRICE_MAX MAX_64

#define MAXLINE       100 

#define ARC_FIELDS      5 

#define NODE_FIELDS     2 

#define P_FIELDS        3 

#define PROBLEM_TYPE "min" 


#define UNFEASIBLE          2
#define ALLOCATION_FAULT    5
#define PRICE_OFL           6



#define UPDT_FREQ      0.4
#define UPDT_FREQ_S    30
#define SCALE_DEFAULT  12.0


#define PRICE_OUT_START  1
#define CUT_OFF_POWER    0.44
#define CUT_OFF_COEF     1.5
#define CUT_OFF_POWER2   0.75
#define CUT_OFF_COEF2    1
#define CUT_OFF_GAP      0.8
#define CUT_OFF_MIN      12
#define CUT_OFF_INCREASE 4

#define TIME_FOR_PRICE_IN1    2
#define TIME_FOR_PRICE_IN2    4
#define TIME_FOR_PRICE_IN3    6

#define MAX_CYCLES_CANCELLED 0
#define START_CYCLE_CANCEL   100

#define MAX( x, y ) ( ( (x) > (y) ) ?  x : y )
#define MIN( x, y ) ( ( (x) < (y) ) ? x : y )
