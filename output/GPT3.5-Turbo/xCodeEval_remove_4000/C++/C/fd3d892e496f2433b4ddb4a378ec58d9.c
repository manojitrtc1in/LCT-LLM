#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1010101
#define INF 1e9

typedef long long ll;

typedef struct {
    int a;
    int b;
    int c;
} triple;

typedef struct {
    int first;
    int second;
} pair;

typedef struct {
    int a;
    int b;
    int c;
} triple_int;

typedef struct {
    int a;
    int b;
    int c;
} triple_long_long;

typedef struct {
    int a;
    int b;
    int c;
} triple_double;

typedef struct {
    int a;
    int b;
    int c;
} triple_unsigned_int;

typedef struct {
    int a;
    int b;
    int c;
} triple_unsigned_long_long;

typedef struct {
    int a;
    int b;
    int c;
} triple_unsigned_double;

typedef struct {
    int a;
    int b;
    int c;
} triple_long_double;

typedef struct {
    int a;
    int b;
    int c;
} triple_float;

typedef struct {
    int a;
    int b;
    int c;
} triple_long;

typedef struct {
    int a;
    int b;
    int c;
} triple_short;

typedef struct {
    int a;
    int b;
    int c;
} triple_unsigned_short;

typedef struct {
    int a;
    int b;
    int c;
} triple_char;

typedef struct {
    int a;
    int b;
    int c;
} triple_unsigned_char;

typedef struct {
    int a;
    int b;
    int c;
} triple_signed_char;

typedef struct {
    int a;
    int b;
    int c;
} triple_int8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_least8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_least8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_least16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_least16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_least32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_least32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_least64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_least64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_fast8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_fast8_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_fast16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_fast16_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_fast32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_fast32_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_int_fast64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uint_fast64_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_ptrdiff_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintptr_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_intmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_uintmax_t;

typedef struct {
    int a;
    int b;
    int c;
} triple_size_t;

typedef struct {
