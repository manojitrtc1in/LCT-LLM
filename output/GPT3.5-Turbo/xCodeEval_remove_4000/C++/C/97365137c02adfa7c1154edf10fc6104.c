#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef double db;
typedef long double ldb;

typedef struct {
    int value;
    int MOD_VAL;
} Modular;

Modular exp(Modular a, ll k);
Modular inv(Modular a);
Modular operator+(Modular a, Modular b);
Modular operator-(Modular a, Modular b);
Modular operator-(Modular a);
Modular operator*(Modular a, Modular b);
Modular operator/(Modular a, Modular b);
bool operator==(Modular a, Modular b);
bool operator!=(Modular a, Modular b);

typedef struct {
    int first;
    int second;
} pair;

pair operator+(pair a, pair b);
pair operator-(pair a, pair b);
pair operator-(pair a);
pair operator*(pair p, int mult);
pair operator*(int mult, pair p);

typedef struct {
    int* data;
    int size;
    int capacity;
} vector;

void vector_init(vector* v);
void vector_push_back(vector* v, int value);
void vector_reserve(vector* v, int capacity);
void vector_free(vector* v);

Modular Modular_init(int value);
Modular Modular_init2(int value, int MOD);
Modular exp(Modular a, ll k);
Modular inv(Modular a);
Modular operator+=(Modular* a, Modular b);
Modular operator-=(Modular* a, Modular b);
Modular operator*=(Modular* a, Modular b);
Modular operator/=(Modular* a, Modular b);
Modular operator++(Modular* a);
Modular operator--(Modular* a);
Modular operator+(Modular a, Modular b);
Modular operator-(Modular a, Modular b);
Modular operator-(Modular a);
Modular operator*(Modular a, Modular b);
Modular operator/(Modular a, Modular b);
bool operator==(Modular a, Modular b);
bool operator!=(Modular a, Modular b);

int scanf_t_int();
ll scanf_t_ll();
db scanf_t_db();
ldb scanf_t_ldb();
char scanf_t_char();
float scanf_t_float();
char* scanf_t_string(int n);

void printf_t_int(int x, char end);
void printf_t_ll(ll x, char end);
void printf_t_db(db x, char end);
void printf_t_ldb(ldb x, char end);
void printf_t_char(char x, char end);
void printf_t_string(char* x, char end);
void printf_t_mod(Modular x, char end);
void printf_t_uint64_t(uint64_t x, char end);
void printf_t_uint32_t(uint32_t x, char end);
void printf_t_bool(bool x, char end);
void printf_t_long(long x, char end);
void printf_t_pair(pair x, char end);
void printf_t_vector(vector* v, char end);

void print();
void print_int(int last);
void print_ll(ll last);
void print_db(db last);
void print_ldb(ldb last);
void print_char(char last);
void print_string(char* last);
void print_mod(Modular last);
void print_uint64_t(uint64_t last);
void print_uint32_t(uint32_t last);
void print_bool(bool last);
void print_long(long last);
void print_pair(pair first, ...);
void print_vector(vector* first, ...);

void _dbg();
void _dbg_int(int last);
void _dbg_ll(ll last);
void _dbg_db(db last);
void _dbg_ldb(ldb last);
void _dbg_char(char last);
void _dbg_string(char* last);
void _dbg_mod(Modular last);
void _dbg_uint64_t(uint64_t last);
void _dbg_uint32_t(uint32_t last);
void _dbg_bool(bool last);
void _dbg_long(long last);
void _dbg_pair(pair first, ...);
void _dbg_vector(vector* first, ...);

void dbg();
void dbg_int(int first, ...);
void dbg_ll(ll first, ...);
void dbg_db(db first, ...);
void dbg_ldb(ldb first, ...);
void dbg_char(char first, ...);
void dbg_string(char* first, ...);
void dbg_mod(Modular first, ...);
void dbg_uint64_t(uint64_t first, ...);
void dbg_uint32_t(uint32_t first, ...);
void dbg_bool(bool first, ...);
void dbg_long(long first, ...);
void dbg_pair(pair first, ...);
void dbg_vector(vector* first, ...);

void in_int(int* begin, int n);
void in_ll(ll* begin, int n);
void in_db(db* begin, int n);
void in_ldb(ldb* begin, int n);
void in_char(char* begin, int n);
void in_float(float* begin, int n);
void in_string(char** begin, int n);

void sv_int(vector* v, int n);
void sv_ll(vector* v, int n);
void sv_db(vector* v, int n);
void sv_ldb(vector* v, int n);
void sv_char(vector* v, int n);
void sv_float(vector* v, int n);
void sv_string(vector* v, int n);

void out_int(int* begin, int* end, char endl, char sep);
void out_ll(ll* begin, ll* end, char endl, char sep);
void out_db(db* begin, db* end, char endl, char sep);
void out_ldb(ldb* begin, ldb* end, char endl, char sep);
void out_char(char* begin, char* end, char endl, char sep);
void out_float(float* begin, float* end, char endl, char sep);
void out_string(char** begin, char** end, char endl, char sep);

void pv_int(vector* v, char end, char sep);
void pv_ll(vector* v, char end, char sep);
void pv_db(vector* v, char end, char sep);
void pv_ldb(vector* v, char end, char sep);
void pv_char(vector* v, char end, char sep);
void pv_float(vector* v, char end, char sep);
void pv_string(vector* v, char end, char sep);

void pi(int x, char end);
void pl(ll x, char end);
void pd(db x, char end);
void pld(ldb x, char end);
void pf(float x, char end);
void pc(char x, char end);
void ps(char* x, char end);

ll russian(ll a, ll k, ll m);
ll fastpow(ll a, ll k, ll m);
ll slowpow(ll a, ll k, ll m);
ll id0(ll a, ll b, ll* k, ll* l);
ll _gcd(ll a, ll b);
ll _lcm(ll a, ll b);
ll _inv(ll a, ll p);

Modular exp(Modular a, ll k) {
    Modular res = Modular_init(1);
    while (k) {
        if (k & 1LL)
            res = res * a;
        a = a * a;
        k >>= 1;
    }
    return res;
}

Modular inv(Modular a) {
    return exp(a, a.MOD_VAL - 2);
}

Modular operator+(Modular a, Modular b) {
    return Modular_init(a.value + b.value);
}

Modular operator-(Modular a, Modular b) {
    return a - b;
}

Modular operator-(Modular a) {
    return Modular_init(0) - a;
}

Modular operator*(Modular a, Modular b) {
    return Modular_init(a.value * b.value);
}

Modular operator/(Modular a, Modular b) {
    return a * inv(b);
}

bool operator==(Modular a, Modular b) {
    return a.value == b.value;
}

bool operator!=(Modular a, Modular b) {
    return a.value != b.value;
}

pair operator+(pair a, pair b) {
    return (pair) { a.first + b.first, a.second + b.second };
}

pair operator-(pair a, pair b) {
    return a - b;
}

pair operator-(pair a) {
    return (pair) { -a.first, -a.second };
}

pair operator*(pair p, int mult) {
    return (pair) { p.first * mult, p.second * mult };
}

pair operator*(int mult, pair p) {
    return (pair) { p.first * mult, p.second * mult };
}

void vector_init(vector* v) {
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

void vector_push_back(vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity = v->capacity == 0 ? 1 : v->capacity * 2;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_reserve(vector* v, int capacity) {
    if (capacity > v->capacity) {
        v->capacity = capacity;
        v->data = realloc(v->data, v->capacity * sizeof(int));
    }
}

void vector_free(vector* v) {
    free(v->data);
    v->data = NULL;
    v->size = 0;
    v->capacity = 0;
}

Modular Modular_init(int value) {
    Modular m;
    m.value = value % 7;
    if (m.value < 0) {
        m.value += 7;
    }
    m.MOD_VAL = 7;
    return m;
}

Modular Modular_init2(int value, int MOD) {
    Modular m;
    m.value = value % MOD;
    if (m.value < 0) {
        m.value += MOD;
    }
    m.MOD_VAL = MOD;
    return m;
}

Modular exp(Modular a, ll k) {
    Modular res = Modular_init(1);
    while (k) {
        if (k & 1LL) {
            res = res * a;
        }
        a = a * a;
        k >>= 1;
    }
    return res;
}

Modular inv(Modular a) {
    return exp(a, a.MOD_VAL - 2);
}

Modular operator+=(Modular* a, Modular b) {
    a->value += b.value;
    if (a->value >= a->MOD_VAL) {
        a->value -= a->MOD_VAL;
    }
    return *a;
}

Modular operator-=(Modular* a, Modular b) {
    a->value -= b.value;
    if (a->value < 0) {
        a->value += a->MOD_VAL;
    }
    return *a;
}

Modular operator*=(Modular* a, Modular b) {
    a->value = (ll)a->value * b.value % a->MOD_VAL;
    return *a;
}

Modular operator/=(Modular* a, Modular b) {
    return *a *= inv(b);
}

Modular operator++(Modular* a) {
    return *a += Modular_init(1);
}

Modular operator--(Modular* a) {
    return *a -= Modular_init(1);
}

Modular operator+(Modular a, Modular b) {
    return Modular_init(a.value + b.value);
}

Modular operator-(Modular a, Modular b) {
    return a - b;
}

Modular operator-(Modular a) {
    return Modular_init(0) - a;
}

Modular operator*(Modular a, Modular b) {
    return Modular_init(a.value * b.value);
}

Modular operator/(Modular a, Modular b) {
    return a / b;
}

bool operator==(Modular a, Modular b) {
    return a.value == b.value;
}

bool operator!=(Modular a, Modular b) {
    return a.value != b.value;
}

int scanf_t_int() {
    int x;
    scanf("%d", &x);
    return x;
}

ll scanf_t_ll() {
    ll x;
    scanf("%lld", &x);
    return x;
}

db scanf_t_db() {
    db x;
    scanf("%lf", &x);
    return x;
}

ldb scanf_t_ldb() {
    ldb x;
    scanf("%Lf", &x);
    return x;
}

char scanf_t_char() {
    char x;
    scanf(" %c", &x);
    return x;
}

float scanf_t_float() {
    float x;
    scanf("%f", &x);
    return x;
}

char* scanf_t_string(int n) {
    char* s = (char*)malloc((n + 7) * sizeof(char));
    char c;
    while (isspace(c = getchar()));
    *s = c;
    int i = 1;
    while (!isspace(c = getchar())) {
        s[i++] = c;
    }
    s[i] = '\0';
    return s;
}

void printf_t_int(int x, char end) {
    printf("%d%c", x, end);
}

void printf_t_ll(ll x, char end) {
    printf("%lld%c", x, end);
}

void printf_t_db(db x, char end) {
    printf("%.8lf%c", x, end);
}

void printf_t_ldb(ldb x, char end) {
    printf("%.10Lf%c", x, end);
}

void printf_t_char(char x, char end) {
    printf("%c%c", x, end);
}

void printf_t_string(char* x, char end) {
    printf("%s%c", x, end);
}

void printf_t_mod(Modular x, char end) {
    printf_t_int(x.value, end);
}

void printf_t_uint64_t(uint64_t x, char end) {
    printf("%lu%c", x, end);
}

void printf_t_uint32_t(uint32_t x, char end) {
    printf("%u%c", x, end);
}

void printf_t_bool(bool x, char end) {
    printf("%d%c", x, end);
}

void printf_t_long(long x, char end) {
    printf("%ld%c", x, end);
}

void printf_t_pair(pair x, char end) {
    printf_t_int(x.first, ' ');
    printf_t_int(x.second, end);
}

void printf_t_vector(vector* v, char end) {
    for (int i = 0; i < v->size; i++) {
        printf_t_int(v->data[i], ' ');
    }
    printf("%c", end);
}

void print() {
    printf("\n");
}

void print_int(int last) {
    printf_t_int(last, '\n');
}

void print_ll(ll last) {
    printf_t_ll(last, '\n');
}

void print_db(db last) {
    printf_t_db(last, '\n');
}

void print_ldb(ldb last) {
    printf_t_ldb(last, '\n');
}

void print_char(char last) {
    printf_t_char(last, '\n');
}

void print_string(char* last) {
    printf_t_string(last, '\n');
}

void print_mod(Modular last) {
    printf_t_mod(last, '\n');
}

void print_uint64_t(uint64_t last) {
    printf_t_uint64_t(last, '\n');
}

void print_uint32_t(uint32_t last) {
    printf_t_uint32_t(last, '\n');
}

void print_bool(bool last) {
    printf_t_bool(last, '\n');
}

void print_long(long last) {
    printf_t_long(last, '\n');
}

void print_pair(pair first, ...) {
    va_list args;
    va_start(args, first);
    printf_t_pair(first, ' ');
    pair p;
    while ((p = va_arg(args, pair)).first != -1) {
        printf_t_pair(p, ' ');
    }
    printf_t_pair(p, '\n');
    va_end(args);
}

void print_vector(vector* first, ...) {
    va_list args;
    va_start(args, first);
    printf_t_vector(first, ' ');
    vector* v;
    while ((v = va_arg(args, vector*))->size != -1) {
        printf_t_vector(v, ' ');
    }
    printf_t_vector(v, '\n');
    va_end(args);
}

void _dbg() {
    printf("\n");
}

void _dbg_int(int last) {
    printf_t_int(last, ' ');
}

void _dbg_ll(ll last) {
    printf_t_ll(last, ' ');
}

void _dbg_db(db last) {
    printf_t_db(last, ' ');
}

void _dbg_ldb(ldb last) {
    printf_t_ldb(last, ' ');
}

void _dbg_char(char last) {
    printf_t_char(last, ' ');
}

void _dbg_string(char* last) {
    printf_t_string(last, ' ');
}

void _dbg_mod(Modular last) {
    printf_t_mod(last, ' ');
}

void _dbg_uint64_t(uint64_t last) {
    printf_t_uint64_t(last, ' ');
}

void _dbg_uint32_t(uint32_t last) {
    printf_t_uint32_t(last, ' ');
}

void _dbg_bool(bool last) {
    printf_t_bool(last, ' ');
}

void _dbg_long(long last) {
    printf_t_long(last, ' ');
}

void _dbg_pair(pair first, ...) {
    va_list args;
    va_start(args, first);
    printf_t_pair(first, ' ');
    pair p;
    while ((p = va_arg(args, pair)).first != -1) {
        printf_t_pair(p, ' ');
    }
    printf_t_pair(p, ' ');
    va_end(args);
}

void _dbg_vector(vector* first, ...) {
    va_list args;
    va_start(args, first);
    printf_t_vector(first, ' ');
    vector* v;
    while ((v = va_arg(args, vector*))->size != -1) {
        printf_t_vector(v, ' ');
    }
    printf_t_vector(v, ' ');
    va_end(args);
}

void dbg() {
    printf("[ ");
    _dbg();
    printf("]\n");
}

void dbg_int(int first, ...) {
    printf("[ ");
    _dbg_int(first);
    va_list args;
    va_start(args, first);
    int x;
    while ((x = va_arg(args, int)) != -1) {
        _dbg_int(x);
    }
    _dbg_int(x);
    va_end(args);
    printf("]\n");
}

void dbg_ll(ll first, ...) {
    printf("[ ");
    _dbg_ll(first);
    va_list args;
    va_start(args, first);
    ll x;
    while ((x = va_arg(args, ll)) != -1) {
        _dbg_ll(x);
    }
    _dbg_ll(x);
    va_end(args);
    printf("]\n");
}

void dbg_db(db first, ...) {
    printf("[ ");
    _dbg_db(first);
    va_list args;
    va_start(args, first);
    db x;
    while ((x = va_arg(args, db)) != -1) {
        _dbg_db(x);
    }
    _dbg_db(x);
    va_end(args);
    printf("]\n");
}

void dbg_ldb(ldb first, ...) {
    printf("[ ");
    _dbg_ldb(first);
    va_list args;
    va_start(args, first);
    ldb x;
    while ((x = va_arg(args, ldb)) != -1) {
        _dbg_ldb(x);
    }
    _dbg_ldb(x);
    va_end(args);
    printf("]\n");
}

void dbg_char(char first, ...) {
    printf("[ ");
    _dbg_char(first);
    va_list args;
    va_start(args, first);
    char x;
    while ((x = va_arg(args, char)) != -1) {
        _dbg_char(x);
    }
    _dbg_char(x);
    va_end(args);
    printf("]\n");
}

void dbg_string(char* first, ...) {
    printf("[ ");
    _dbg_string(first);
    va_list args;
    va_start(args, first);
    char* x;
    while ((x = va_arg(args, char*)) != NULL) {
        _dbg_string(x);
    }
    _dbg_string(x);
    va_end(args);
    printf("]\n");
}

void dbg_mod(Modular first, ...) {
    printf("[ ");
    _dbg_mod(first);
    va_list args;
    va_start(args, first);
    Modular x;
    while ((x = va_arg(args, Modular)).value != -1) {
        _dbg_mod(x);
    }
    _dbg_mod(x);
    va_end(args);
    printf("]\n");
}

void dbg_uint64_t(uint64_t first, ...) {
    printf("[ ");
    _dbg_uint64_t(first);
    va_list args;
    va_start(args, first);
    uint64_t x;
    while ((x = va_arg(args, uint64_t)) != -1) {
        _dbg_uint64_t(x);
    }
    _dbg_uint64_t(x);
    va_end(args);
    printf("]\n");
}

void dbg_uint32_t(uint32_t first, ...) {
    printf("[ ");
    _dbg_uint32_t(first);
    va_list args;
    va_start(args, first);
    uint32_t x;
    while ((x = va_arg(args, uint32_t)) != -1) {
        _dbg_uint32_t(x);
    }
    _dbg_uint32_t(x);
    va_end(args);
    printf("]\n");
}

void dbg_bool(bool first, ...) {
    printf("[ ");
    _dbg_bool(first);
    va_list args;
    va_start(args, first);
    bool x;
    while ((x = va_arg(args, bool)) != -1) {
        _dbg_bool(x);
    }
    _dbg_bool(x);
    va_end(args);
    printf("]\n");
}

void dbg_long(long first, ...) {
    printf("[ ");
    _dbg_long(first);
    va_list args;
    va_start(args, first);
    long x;
    while ((x = va_arg(args, long)) != -1) {
        _dbg_long(x);
    }
    _dbg_long(x);
    va_end(args);
    printf("]\n");
}

void dbg_pair(pair first, ...) {
    printf("[ ");
    _dbg_pair(first);
    va_list args;
    va_start(args, first);
    pair p;
    while ((p = va_arg(args, pair)).first != -1) {
        _dbg_pair(p);
    }
    _dbg_pair(p);
    va_end(args);
    printf("]\n");
}

void dbg_vector(vector* first, ...) {
    printf("[ ");
    _dbg_vector(first);
    va_list args;
    va_start(args, first);
    vector* v;
    while ((v = va_arg(args, vector*))->size != -1) {
        _dbg_vector(v);
    }
    _dbg_vector(v);
    va_end(args);
    printf("]\n");
}

void in_int(int* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_int();
    }
}

void in_ll(ll* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_ll();
    }
}

void in_db(db* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_db();
    }
}

void in_ldb(ldb* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_ldb();
    }
}

void in_char(char* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_char();
    }
}

void in_float(float* begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_float();
    }
}

void in_string(char** begin, int n) {
    for (int i = 0; i < n; i++) {
        begin[i] = scanf_t_string();
    }
}

void sv_int(vector* v, int n) {
    vector_reserve(v, n);
    in_int(v->data, n);
    v->size = n;
}

void sv_ll(vector* v, int n) {
    vector_reserve(v, n);
    in_ll(v->data, n);
    v->size = n;
}

void sv_db(vector* v, int n) {
    vector_reserve(v, n);
    in_db(v->data, n);
    v->size = n;
}

void sv_ldb(vector* v, int n) {
    vector_reserve(v, n);
    in_ldb(v->data, n);
    v->size = n;
}

void sv_char(vector* v, int n) {
    vector_reserve(v, n);
    in_char(v->data, n);
    v->size = n;
}

void sv_float(vector* v, int n) {
    vector_reserve(v, n);
    in_float(v->data, n);
    v->size = n;
}

void sv_string(vector* v, int n) {
    vector_reserve(v, n);
    in_string(v->data, n);
    v->size = n;
}

void out_int(int* begin, int* end, char endl, char sep) {
    while (begin != end) {
        printf_t_int(*begin++, sep);
    }
    printf("%c", endl);
}

void out_ll(ll* begin, ll* end, char endl, char sep) {
    while (begin != end) {
        printf_t_ll(*begin++, sep);
    }
    printf("%c", endl);
}

void out_db(db* begin, db* end, char endl, char sep) {
    while (begin != end) {
        printf_t_db(*begin++, sep);
    }
    printf("%c", endl);
}

void out_ldb(ldb* begin, ldb* end, char endl, char sep) {
    while (begin != end) {
        printf_t_ldb(*begin++, sep);
    }
    printf("%c", endl);
}

void out_char(char* begin, char* end, char endl, char sep) {
    while (begin != end) {
        printf_t_char(*begin++, sep);
    }
    printf("%c", endl);
}

void out_float(float* begin, float* end, char endl, char sep) {
    while (begin != end) {
        printf_t_float(*begin++, sep);
    }
    printf("%c", endl);
}

void out_string(char** begin, char** end, char endl, char sep) {
    while (begin != end) {
        printf_t_string(*begin++, sep);
    }
    printf("%c", endl);
}

void pv_int(vector* v, char end, char sep) {
    out_int(v->data, v->data + v->size, end, sep);
}

void pv_ll(vector* v, char end, char sep) {
    out_ll(v->data, v->data + v->size, end, sep);
}

void pv_db(vector* v, char end, char sep) {
    out_db(v->data, v->data + v->size, end, sep);
}

void pv_ldb(vector* v, char end, char sep) {
    out_ldb(v->data, v->data + v->size, end, sep);
}

void pv_char(vector* v, char end, char sep) {
    out_char(v->data, v->data + v->size, end, sep);
}

void pv_float(vector* v, char end, char sep) {
    out_float(v->data, v->data + v->size, end, sep);
}

void pv_string(vector* v, char end, char sep) {
    out_string(v->data, v->data + v->size, end, sep);
}

void pi(int x, char end) {
    printf_t_int(x, end);
}

void pl(ll x, char end) {
    printf_t_ll(x, end);
}

void pd(db x, char end) {
    printf_t_db(x, end);
}

void pld(ldb x, char end) {
    printf_t_ldb(x, end);
}

void pf(float x, char end) {
    printf_t_float(x, end);
}

void pc(char x, char end) {
    printf_t_char(x, end);
}

void ps(char* x, char end) {
    printf_t_string(x, end);
}

ll russian(ll a, ll k, ll m) {
    ll res = 0LL;
    while (k) {
        if (k & 1LL) {
            res = (res + a) % m;
        }
        a = (a + a) % m;
        k >>= 1;
    }
    return res;
}

ll fastpow(ll a, ll k, ll m) {
    ll res = 1LL;
    while (k) {
        if (k & 1LL) {
            res = (res * a) % m;
        }
        a = (a * a) % m;
        k >>= 1;
    }
    return res;
}

ll slowpow(ll a, ll k, ll m) {
    ll res = 1LL;
    while (k) {
        if (k & 1LL) {
            res = russian(res, a, m);
        }
        a = russian(a, a, m);
        k >>= 1;
    }
    return res;
}

ll id0(ll a, ll b, ll* k, ll* l) {
    if (b == 0) {
        *k = 1;
        *l = 0;
        return a;
    }
    ll res = id0(b, a % b, l, k);
    *l -= a / b * *k;
    return res;
}

ll _gcd(ll a, ll b) {
    while (b) {
        ll temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

ll _lcm(ll a, ll b) {
    return a / _gcd(a, b) * b;
}

ll _inv(ll a, ll p) {
    ll k, l;
    id0(a, p, &k, &l);
    return (k % p + p) % p;
}

int main() {
    int t = scanf_t_int();
    while (t--) {
        print(solve());
    }
    return 0;
}
