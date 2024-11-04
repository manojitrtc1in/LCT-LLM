#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_C 20
#define MAX_N 100000

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int value;
    int MOD_VAL;
} Modular;

typedef struct {
    int x;
    int y;
} pair;

typedef struct {
    int a;
    int b;
} pair_int;

typedef struct {
    int a;
    int b;
} pair_ll;

typedef struct {
    double a;
    double b;
} pair_db;

typedef struct {
    long double a;
    long double b;
} pair_ldb;

typedef struct {
    int a;
    long long b;
} pair_int_ll;

typedef struct {
    long long a;
    int b;
} pair_ll_int;

typedef struct {
    int* arr;
    int size;
} vector_int;

typedef struct {
    long long* arr;
    int size;
} vector_ll;

typedef struct {
    char** arr;
    int size;
} vector_string;

typedef struct {
    char* arr;
    int size;
} vector_char;

typedef struct {
    double* arr;
    int size;
} vector_db;

typedef struct {
    long double* arr;
    int size;
} vector_ldb;

typedef struct {
    pii* arr;
    int size;
} vector_pii;

typedef struct {
    pair_ll* arr;
    int size;
} vector_pair_ll;

typedef struct {
    pair_db* arr;
    int size;
} vector_pair_db;

typedef struct {
    pair_ldb* arr;
    int size;
} vector_pair_ldb;

typedef struct {
    pair_int_ll* arr;
    int size;
} vector_pair_int_ll;

typedef struct {
    pair_ll_int* arr;
    int size;
} vector_pair_ll_int;

typedef struct {
    Modular* arr;
    int size;
} vector_Modular;

typedef struct {
    int value;
} mod;

typedef struct {
    int size;
    char* arr;
} string;

typedef struct {
    int x;
    int y;
} pair_int_int;

typedef struct {
    int x;
    int y;
} pair_int_ll;

typedef struct {
    int x;
    int y;
} pair_ll_int;

typedef struct {
    int x;
    int y;
} pair_ll_ll;

typedef struct {
    int x;
    int y;
} pair_db_db;

typedef struct {
    int x;
    int y;
} pair_ldb_ldb;

typedef struct {
    int x;
    int y;
} pair_int_db;

typedef struct {
    int x;
    int y;
} pair_db_int;

typedef struct {
    int x;
    int y;
} pair_int_ldb;

typedef struct {
    int x;
    int y;
} pair_ldb_int;

typedef struct {
    int x;
    int y;
} pair_db_ldb;

typedef struct {
    int x;
    int y;
} pair_ldb_db;

typedef struct {
    int x;
    int y;
} pair_int_string;

typedef struct {
    int x;
    int y;
} pair_string_int;

typedef struct {
    int x;
    int y;
} pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_ll;

typedef struct {
    int x;
    int y;
} pair_db_string;

typedef struct {
    int x;
    int y;
} pair_string_db;

typedef struct {
    int x;
    int y;
} pair_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_ldb;

typedef struct {
    int x;
    int y;
} pair_string_string;

typedef struct {
    int x;
    int y;
} pair_string_char;

typedef struct {
    int x;
    int y;
} pair_char_string;

typedef struct {
    int x;
    int y;
} pair_string_float;

typedef struct {
    int x;
    int y;
} pair_float_string;

typedef struct {
    int x;
    int y;
} pair_string_mod;

typedef struct {
    int x;
    int y;
} pair_mod_string;

typedef struct {
    int x;
    int y;
} pair_string_uint64_t;

typedef struct {
    int x;
    int y;
} pair_uint64_t_string;

typedef struct {
    int x;
    int y;
} pair_string_uint32_t;

typedef struct {
    int x;
    int y;
} pair_uint32_t_string;

typedef struct {
    int x;
    int y;
} pair_string_bool;

typedef struct {
    int x;
    int y;
} pair_bool_string;

typedef struct {
    int x;
    int y;
} pair_string_long;

typedef struct {
    int x;
    int y;
} pair_long_string;

typedef struct {
    int x;
    int y;
} pair_string_pair;

typedef struct {
    int x;
    int y;
} pair_pair_string;

typedef struct {
    int x;
    int y;
} pair_string_vector;

typedef struct {
    int x;
    int y;
} pair_vector_string;

typedef struct {
    int x;
    int y;
} pair_string_pii;

typedef struct {
    int x;
    int y;
} pair_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_pair_ll;

typedef struct {
    int x;
    int y;
} pair_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_pair_db;

typedef struct {
    int x;
    int y;
} pair_pair_db_string;

typedef struct {
    int x;
    int y;
} pair_string_pair_ldb;

typedef struct {
    int x;
    int y;
} pair_pair_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_pair_int_ll;

typedef struct {
    int x;
    int y;
} pair_pair_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_pair_ll_int;

typedef struct {
    int x;
    int y;
} pair_pair_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int;

typedef struct {
    int x;
    int y;
} pair_vector_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll;

typedef struct {
    int x;
    int y;
} pair_vector_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string;

typedef struct {
    int x;
    int y;
} pair_vector_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_char;

typedef struct {
    int x;
    int y;
} pair_vector_char_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db;

typedef struct {
    int x;
    int y;
} pair_vector_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_db;

typedef struct {
    int x;
    int y;
} pair_vector_pair_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_int_ll;

typedef struct {
    int x;
    int y;
} pair_vector_pair_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll_int;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_vector;

typedef struct {
    int x;
    int y;
} pair_vector_vector_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_Modular;

typedef struct {
    int x;
    int y;
} pair_vector_Modular_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_int;

typedef struct {
    int x;
    int y;
} pair_vector_int_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ll;

typedef struct {
    int x;
    int y;
} pair_vector_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_int;

typedef struct {
    int x;
    int y;
} pair_vector_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_ll;

typedef struct {
    int x;
    int y;
} pair_vector_ll_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_db;

typedef struct {
    int x;
    int y;
} pair_vector_db_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_db;

typedef struct {
    int x;
    int y;
} pair_vector_int_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_int;

typedef struct {
    int x;
    int y;
} pair_vector_db_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_int_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_int;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_db_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_db;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_int;

typedef struct {
    int x;
    int y;
} pair_vector_string_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ll;

typedef struct {
    int x;
    int y;
} pair_vector_string_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_string;

typedef struct {
    int x;
    int y;
} pair_vector_string_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_char;

typedef struct {
    int x;
    int y;
} pair_vector_string_char_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_char_string;

typedef struct {
    int x;
    int y;
} pair_vector_char_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pii;

typedef struct {
    int x;
    int y;
} pair_vector_string_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pair_ll;

typedef struct {
    int x;
    int y;
} pair_vector_string_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_int_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_vector_string;

typedef struct {
    int x;
    int y;
} pair_vector_vector_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_vector;

typedef struct {
    int x;
    int y;
} pair_vector_string_vector_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pii;

typedef struct {
    int x;
    int y;
} pair_vector_string_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_Modular_string;

typedef struct {
    int x;
    int y;
} pair_vector_Modular_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_int;

typedef struct {
    int x;
    int y;
} pair_vector_string_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ll;

typedef struct {
    int x;
    int y;
} pair_vector_string_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_string;

typedef struct {
    int x;
    int y;
} pair_vector_string_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_char;

typedef struct {
    int x;
    int y;
} pair_vector_string_char_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_char_string;

typedef struct {
    int x;
    int y;
} pair_vector_char_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pii;

typedef struct {
    int x;
    int y;
} pair_vector_string_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pair_ll;

typedef struct {
    int x;
    int y;
} pair_vector_string_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string_db;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_db_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string_ldb;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_ldb_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_int_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_ll_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_vector_string;

typedef struct {
    int x;
    int y;
} pair_vector_vector_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_vector;

typedef struct {
    int x;
    int y;
} pair_vector_string_vector_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pii_string;

typedef struct {
    int x;
    int y;
} pair_vector_pii_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_pii;

typedef struct {
    int x;
    int y;
} pair_vector_string_pii_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_pair_string;

typedef struct {
    int x;
    int y;
} pair_vector_pair_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_Modular_string;

typedef struct {
    int x;
    int y;
} pair_vector_Modular_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_ldb_string;

typedef struct {
    int x;
    int y;
} pair_vector_db_ldb_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ldb_db_string;

typedef struct {
    int x;
    int y;
} pair_vector_ldb_db_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_int_string;

typedef struct {
    int x;
    int y;
} pair_vector_int_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_int;

typedef struct {
    int x;
    int y;
} pair_vector_string_int_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_ll_string;

typedef struct {
    int x;
    int y;
} pair_vector_ll_string_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_string_ll;

typedef struct {
    int x;
    int y;
} pair_vector_string_ll_string;

typedef struct {
    int x;
    int y;
} pair_string_vector_db_string;

typedef struct {
    int x;
    int y;
