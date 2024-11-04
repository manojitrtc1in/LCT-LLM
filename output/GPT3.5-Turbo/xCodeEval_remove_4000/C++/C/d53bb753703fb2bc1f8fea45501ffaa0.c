#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef struct { db real, imag; } cd;
typedef char* str;

typedef struct { int first, second; } pii;
typedef struct { ll first, second; } pll;
typedef struct { db first, second; } pdb;
typedef struct { ldb first, second; } pldb;
typedef struct { int first; ll second; } pil;
typedef struct { ll first; int second; } pli;

typedef int* vi;
typedef ll* vl;
typedef str* vs;
typedef char* vc;
typedef db* vdb;
typedef ldb* vldb;
typedef pii* vpii;
typedef pll* vpll;
typedef pdb* vpdb;
typedef pldb* vpldb;
typedef pil* vpil;
typedef pli* vpli;

typedef struct {
    int value;
    int MOD_VAL;
} mod;

mod Modular(int MOD) {
    mod m;
    m.value = 0;
    m.MOD_VAL = MOD;
    return m;
}

mod ModularExp(mod a, ll k) {
    mod res;
    res.value = 1;
    while (k) {
        if (k & 1LL)
            res.value = (res.value * a.value) % a.MOD_VAL;
        a.value = (a.value * a.value) % a.MOD_VAL;
        k >>= 1;
    }
    return res;
}

mod ModularInv(mod a) {
    return ModularExp(a, a.MOD_VAL - 2);
}

mod ModularAdd(mod a, mod b) {
    mod res;
    res.value = (a.value + b.value) % a.MOD_VAL;
    return res;
}

mod ModularSub(mod a, mod b) {
    mod res;
    res.value = (a.value - b.value + a.MOD_VAL) % a.MOD_VAL;
    return res;
}

mod ModularMul(mod a, mod b) {
    mod res;
    res.value = (a.value * b.value) % a.MOD_VAL;
    return res;
}

mod ModularDiv(mod a, mod b) {
    return ModularMul(a, ModularInv(b));
}

mod ModularInc(mod a) {
    return ModularAdd(a, Modular(1));
}

mod ModularDec(mod a) {
    return ModularSub(a, Modular(1));
}

typedef int* (*scanf_t)();
typedef void (*printf_t)();

int* scanf_t_int() {
    int* x = (int*)malloc(sizeof(int));
    scanf("%d", x);
    return x;
}

ll* scanf_t_ll() {
    ll* x = (ll*)malloc(sizeof(ll));
    scanf("%lld", x);
    return x;
}

db* scanf_t_db() {
    db* x = (db*)malloc(sizeof(db));
    scanf("%lf", x);
    return x;
}

ldb* scanf_t_ldb() {
    ldb* x = (ldb*)malloc(sizeof(ldb));
    scanf("%Lf", x);
    return x;
}

char* scanf_t_char() {
    char* x = (char*)malloc(sizeof(char));
    scanf(" %c", x);
    return x;
}

float* scanf_t_float() {
    float* x = (float*)malloc(sizeof(float));
    scanf("%f", x);
    return x;
}

str* scanf_t_string() {
    str* x = (str*)malloc(sizeof(str));
    int size = 8;
    *x = (str)malloc(size * sizeof(char));
    char c;
    while (isspace(c = getchar()));
    **x = c;
    int i = 1;
    while (!isspace(c = getchar())) {
        (*x)[i++] = c;
        if (i == size) {
            *x = (str)realloc(*x, size *= 2);
        }
    }
    (*x)[i] = '\0';
    return x;
}

str scanf_t_string_int(int n) {
    str x = (str)malloc((n + 7) * sizeof(char));
    scanf("%s", x);
    return x;
}

void printf_t_int(int* x) {
    printf("%d", *x);
}

void printf_t_ll(ll* x) {
    printf("%lld", *x);
}

void printf_t_db(db* x) {
    printf("%.8lf", *x);
}

void printf_t_ldb(ldb* x) {
    printf("%.10Lf", *x);
}

void printf_t_char(char* x) {
    printf("%c", *x);
}

void printf_t_float(float* x) {
    printf("%f", *x);
}

void printf_t_string(str* x) {
    printf("%s", *x);
}

void printf_t_mod(mod* x) {
    printf("%d", x->value);
}

void printf_t_uint64_t(uint64_t* x) {
    printf("%lu", *x);
}

void printf_t_uint32_t(uint32_t* x) {
    printf("%u", *x);
}

void printf_t_bool(bool* x) {
    printf("%d", *x);
}

void printf_t_long(long* x) {
    printf("%ld", *x);
}

void printf_t_pair_int_int(pii* x) {
    printf_t_int(&(x->first));
    printf(" ");
    printf_t_int(&(x->second));
}

void printf_t_int_int(int* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_ll_ll(ll* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_ll(&(x[i]));
        printf(" ");
    }
}

void printf_t_db_db(db* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_db(&(x[i]));
        printf(" ");
    }
}

void printf_t_ldb_ldb(ldb* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_ldb(&(x[i]));
        printf(" ");
    }
}

void printf_t_char_char(char* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_char(&(x[i]));
        printf(" ");
    }
}

void printf_t_float_float(float* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_float(&(x[i]));
        printf(" ");
    }
}

void printf_t_string_string(str* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_string(&(x[i]));
        printf(" ");
    }
}

void printf_t_mod_mod(mod* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_mod(&(x[i]));
        printf(" ");
    }
}

void printf_t_uint64_t_uint64_t(uint64_t* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_uint64_t(&(x[i]));
        printf(" ");
    }
}

void printf_t_uint32_t_uint32_t(uint32_t* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_uint32_t(&(x[i]));
        printf(" ");
    }
}

void printf_t_bool_bool(bool* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_bool(&(x[i]));
        printf(" ");
    }
}

void printf_t_long_long(long* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_long(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
        printf_t_pair_int_int(&(x[i]));
        printf(" ");
    }
}

void printf_t_int_int_int_int_int_int_int_int_int_int_int_int_int(pii* x, int n) {
    for (int i = 0; i < n; i++) {
