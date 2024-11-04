#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define maxn 100005
#define MOD 1000000007

int n;
int pts[maxn][2];
bool visit[maxn * 2];
bool ve[maxn * 2];
int x_start, y_start, now = 0;
typedef struct {
    int first;
    int second;
} pair;

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    int first;
    int second;
} pair_int;

typedef struct {
    int first;
    int second;
} pair_ll;

typedef struct {
    int first;
    int second;
} pair_uint;

typedef struct {
    int first;
    int second;
} pair_ull;

typedef struct {
    int first;
    int second;
} pair_char;

typedef struct {
    int first;
    int second;
} pair_double;

typedef struct {
    int first;
    int second;
} pair_long_double;

typedef struct {
    int first;
    int second;
} pair_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_int;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_char;

typedef struct {
    int first;
    int second;
} pair_unsigned_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_long;

typedef struct {
    int first;
    int second;
} pair_unsigned_long_double;

typedef struct {
    int first;
    int second;
