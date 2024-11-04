#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <stdint.h>

#define MAXN 100005
#define MOD 1000000007

int n;
int pts[MAXN][2];
bool visit[MAXN * 2];
bool ve[MAXN * 2];
int x_start, y_start, now = 0;
typedef struct {
    int first;
    int second;
} pair;

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
} pair_float;

typedef struct {
    int first;
    int second;
} pair_short;

typedef struct {
    int first;
    int second;
} pair_ushort;

typedef struct {
    int first;
    int second;
} pair_uint8;

typedef struct {
    int first;
    int second;
} pair_int8;

typedef struct {
    int first;
    int second;
} pair_uint16;

typedef struct {
    int first;
    int second;
} pair_int16;

typedef struct {
    int first;
    int second;
} pair_uint32;

typedef struct {
    int first;
    int second;
} pair_int32;

typedef struct {
    int first;
    int second;
} pair_uint64;

typedef struct {
    int first;
    int second;
} pair_int64;

typedef struct {
    int first;
    int second;
} pair_size_t;

typedef struct {
    int first;
    int second;
} pair_ptrdiff_t;

typedef struct {
    int first;
    int second;
} pair_intptr_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_t;

typedef struct {
    int first;
    int second;
} pair_intmax_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
    int first;
    int second;
} pair_uint64_t;

typedef struct {
    int first;
    int second;
} pair_int_least8_t;

typedef struct {
    int first;
    int second;
} pair_uint_least8_t;

typedef struct {
    int first;
    int second;
} pair_int_least16_t;

typedef struct {
    int first;
    int second;
} pair_uint_least16_t;

typedef struct {
    int first;
    int second;
} pair_int_least32_t;

typedef struct {
    int first;
    int second;
} pair_uint_least32_t;

typedef struct {
    int first;
    int second;
} pair_int_least64_t;

typedef struct {
    int first;
    int second;
} pair_uint_least64_t;

typedef struct {
    int first;
    int second;
} pair_int_fast8_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast8_t;

typedef struct {
    int first;
    int second;
} pair_int_fast16_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast16_t;

typedef struct {
    int first;
    int second;
} pair_int_fast32_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast32_t;

typedef struct {
    int first;
    int second;
} pair_int_fast64_t;

typedef struct {
    int first;
    int second;
} pair_uint_fast64_t;

typedef struct {
    int first;
    int second;
} pair_intptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintptr_fast_t;

typedef struct {
    int first;
    int second;
} pair_intmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_uintmax_fast_t;

typedef struct {
    int first;
    int second;
} pair_int8_t;

typedef struct {
    int first;
    int second;
} pair_uint8_t;

typedef struct {
    int first;
    int second;
} pair_int16_t;

typedef struct {
    int first;
    int second;
} pair_uint16_t;

typedef struct {
    int first;
    int second;
} pair_int32_t;

typedef struct {
    int first;
    int second;
} pair_uint32_t;

typedef struct {
    int first;
    int second;
} pair_int64_t;

typedef struct {
