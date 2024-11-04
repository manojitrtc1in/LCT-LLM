#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef double db;
typedef long double ldb;

typedef struct {
    int st;
    int nd;
} pair;

typedef struct {
    int value;
    int MOD_VAL;
} Modular;

typedef struct {
    int x;
    int y;
} pii;

typedef struct {
    ll x;
    ll y;
} pll;

typedef struct {
    db x;
    db y;
} pdb;

typedef struct {
    ldb x;
    ldb y;
} pldb;

typedef struct {
    int x;
    ll y;
} pil;

typedef struct {
    ll x;
    int y;
} pli;

typedef struct {
    int* arr;
    int size;
} vi;

typedef struct {
    ll* arr;
    int size;
} vl;

typedef struct {
    char* arr;
    int size;
} vs;

typedef struct {
    char* arr;
    int size;
} vc;

typedef struct {
    bool* arr;
    int size;
} vb;

typedef struct {
    db* arr;
    int size;
} vdb;

typedef struct {
    ldb* arr;
    int size;
} vldb;

typedef struct {
    pii* arr;
    int size;
} vpii;

typedef struct {
    pll* arr;
    int size;
} vpll;

typedef struct {
    pdb* arr;
    int size;
} vpdb;

typedef struct {
    pldb* arr;
    int size;
} vpldb;

typedef struct {
    pil* arr;
    int size;
} vpil;

typedef struct {
    pli* arr;
    int size;
} vpli;

typedef struct {
    vi* arr;
    int size;
} vvi;

Modular operator+(const pair* a, const pair* b);
Modular* operator+=(pair* a, const pair* b);
Modular operator-(const pair* p);
Modular operator-(const pair* a, const pair* b);
Modular* operator-=(pair* a, const pair* b);
Modular operator*(const pair* p, int mult);
Modular operator*(int mult, const pair* p);

Modular* operator+=(Modular* a, const Modular* b);
Modular* operator-=(Modular* a, const Modular* b);
Modular* operator*=(Modular* a, const Modular* b);
Modular* operator/=(Modular* a, const Modular* b);
Modular* operator++(Modular* a);
Modular* operator--(Modular* a);

Modular operator+(const Modular* a, const Modular* b);
Modular operator-(const Modular* a, const Modular* b);
Modular operator-(const Modular* a);
Modular operator*(const Modular* a, const Modular* b);
Modular operator/(const Modular* a, const Modular* b);
void operator<<(FILE* os, const Modular* m);

bool operator==(const Modular* a, const Modular* b);
bool operator!=(const Modular* a, const Modular* b);

Modular exp(Modular* a, ll k);
Modular inv(Modular* a);

Modular* Modular_init(Modular* m, ll v);
Modular* Modular_init2(Modular* m, ll a, ll b);

int scanf_t_int();
ll scanf_t_ll();
db scanf_t_db();
ldb scanf_t_ldb();
char scanf_t_char();
float scanf_t_float();
char* scanf_t_string();
char* scanf_t_string_int(int n);

void printf_t_int(const int* x, char end, FILE* out);
void printf_t_ll(const ll* x, char end, FILE* out);
void printf_t_db(const db* x, char end, FILE* out);
void printf_t_ldb(const ldb* x, char end, FILE* out);
void printf_t_float(const float* x, char end, FILE* out);
void printf_t_char(const char* x, char end, FILE* out);
void printf_t_string(const char* x, char end, FILE* out);
void printf_t_mod(const Modular* x, char end, FILE* out);
void printf_t_uint64_t(const uint64_t* x, char end, FILE* out);
void printf_t_uint32_t(const uint32_t* x, char end, FILE* out);
void printf_t_bool(const bool* x, char end, FILE* out);
void printf_t_long(const long* x, char end, FILE* out);
void printf_t_pair(const pair* x, char end, FILE* out);
void printf_t_int_arr(const int* arr, int size, char end, FILE* out);
void printf_t_ll_arr(const ll* arr, int size, char end, FILE* out);
void printf_t_db_arr(const db* arr, int size, char end, FILE* out);
void printf_t_ldb_arr(const ldb* arr, int size, char end, FILE* out);
void printf_t_float_arr(const float* arr, int size, char end, FILE* out);
void printf_t_char_arr(const char* arr, int size, char end, FILE* out);
void printf_t_string_arr(const char* arr, int size, char end, FILE* out);
void printf_t_mod_arr(const Modular* arr, int size, char end, FILE* out);

void print();
void print_int(const int* last);
void print_ll(const ll* last);
void print_db(const db* last);
void print_ldb(const ldb* last);
void print_float(const float* last);
void print_char(const char* last);
void print_string(const char* last);
void print_mod(const Modular* last);
void print_uint64_t(const uint64_t* last);
void print_uint32_t(const uint32_t* last);
void print_bool(const bool* last);
void print_long(const long* last);
void print_pair(const pair* last);
void print_int(const int* first, const int* rest);
void print_ll(const ll* first, const ll* rest);
void print_db(const db* first, const db* rest);
void print_ldb(const ldb* first, const ldb* rest);
void print_float(const float* first, const float* rest);
void print_char(const char* first, const char* rest);
void print_string(const char* first, const char* rest);
void print_mod(const Modular* first, const Modular* rest);
void print_uint64_t(const uint64_t* first, const uint64_t* rest);
void print_uint32_t(const uint32_t* first, const uint32_t* rest);
void print_bool(const bool* first, const bool* rest);
void print_long(const long* first, const long* rest);
void print_pair(const pair* first, const pair* rest);

void _dbg();
void _dbg_int(const int* last);
void _dbg_ll(const ll* last);
void _dbg_db(const db* last);
void _dbg_ldb(const ldb* last);
void _dbg_float(const float* last);
void _dbg_char(const char* last);
void _dbg_string(const char* last);
void _dbg_mod(const Modular* last);
void _dbg_uint64_t(const uint64_t* last);
void _dbg_uint32_t(const uint32_t* last);
void _dbg_bool(const bool* last);
void _dbg_long(const long* last);
void _dbg_pair(const pair* last);
void _dbg_int(const int* first, const int* rest);
void _dbg_ll(const ll* first, const ll* rest);
void _dbg_db(const db* first, const db* rest);
void _dbg_ldb(const ldb* first, const ldb* rest);
void _dbg_float(const float* first, const float* rest);
void _dbg_char(const char* first, const char* rest);
void _dbg_string(const char* first, const char* rest);
void _dbg_mod(const Modular* first, const Modular* rest);
void _dbg_uint64_t(const uint64_t* first, const uint64_t* rest);
void _dbg_uint32_t(const uint32_t* first, const uint32_t* rest);
void _dbg_bool(const bool* first, const bool* rest);
void _dbg_long(const long* first, const long* rest);
void _dbg_pair(const pair* first, const pair* rest);

void dbg();
void dbg_int(const int* last);
void dbg_ll(const ll* last);
void dbg_db(const db* last);
void dbg_ldb(const ldb* last);
void dbg_float(const float* last);
void dbg_char(const char* last);
void dbg_string(const char* last);
void dbg_mod(const Modular* last);
void dbg_uint64_t(const uint64_t* last);
void dbg_uint32_t(const uint32_t* last);
void dbg_bool(const bool* last);
void dbg_long(const long* last);
void dbg_pair(const pair* last);
void dbg_int(const int* first, const int* rest);
void dbg_ll(const ll* first, const ll* rest);
void dbg_db(const db* first, const db* rest);
void dbg_ldb(const ldb* first, const ldb* rest);
void dbg_float(const float* first, const float* rest);
void dbg_char(const char* first, const char* rest);
void dbg_string(const char* first, const char* rest);
void dbg_mod(const Modular* first, const Modular* rest);
void dbg_uint64_t(const uint64_t* first, const uint64_t* rest);
void dbg_uint32_t(const uint32_t* first, const uint32_t* rest);
void dbg_bool(const bool* first, const bool* rest);
void dbg_long(const long* first, const long* rest);
void dbg_pair(const pair* first, const pair* rest);

void in_int(int* begin, int n);
void in_ll(ll* begin, int n);
void in_db(db* begin, int n);
void in_ldb(ldb* begin, int n);
void in_float(float* begin, int n);
void in_char(char* begin, int n);
void in_string(char** begin, int n);
void in_mod(Modular* begin, int n);
void in_uint64_t(uint64_t* begin, int n);
void in_uint32_t(uint32_t* begin, int n);
void in_bool(bool* begin, int n);
void in_long(long* begin, int n);
void in_pair(pair* begin, int n);

void sv_int(vi* v, int n);
void sv_ll(vl* v, int n);
void sv_db(vdb* v, int n);
void sv_ldb(vldb* v, int n);
void sv_float(vfloat* v, int n);
void sv_char(vc* v, int n);
void sv_string(vs* v, int n);
void sv_mod(vmod* v, int n);
void sv_uint64_t(vuint64_t* v, int n);
void sv_uint32_t(vuint32_t* v, int n);
void sv_bool(vb* v, int n);
void sv_long(vl* v, int n);
void sv_pair(vpii* v, int n);

void out_int(const int* begin, const int* end, char endl, char sep, FILE* outs);
void out_ll(const ll* begin, const ll* end, char endl, char sep, FILE* outs);
void out_db(const db* begin, const db* end, char endl, char sep, FILE* outs);
void out_ldb(const ldb* begin, const ldb* end, char endl, char sep, FILE* outs);
void out_float(const float* begin, const float* end, char endl, char sep, FILE* outs);
void out_char(const char* begin, const char* end, char endl, char sep, FILE* outs);
void out_string(const char** begin, const char** end, char endl, char sep, FILE* outs);
void out_mod(const Modular* begin, const Modular* end, char endl, char sep, FILE* outs);
void out_uint64_t(const uint64_t* begin, const uint64_t* end, char endl, char sep, FILE* outs);
void out_uint32_t(const uint32_t* begin, const uint32_t* end, char endl, char sep, FILE* outs);
void out_bool(const bool* begin, const bool* end, char endl, char sep, FILE* outs);
void out_long(const long* begin, const long* end, char endl, char sep, FILE* outs);
void out_pair(const pair* begin, const pair* end, char endl, char sep, FILE* outs);

void pv_int(const vi* v, char end, char sep, FILE* outs);
void pv_ll(const vl* v, char end, char sep, FILE* outs);
void pv_db(const vdb* v, char end, char sep, FILE* outs);
void pv_ldb(const vldb* v, char end, char sep, FILE* outs);
void pv_float(const vfloat* v, char end, char sep, FILE* outs);
void pv_char(const vc* v, char end, char sep, FILE* outs);
void pv_string(const vs* v, char end, char sep, FILE* outs);
void pv_mod(const vmod* v, char end, char sep, FILE* outs);
void pv_uint64_t(const vuint64_t* v, char end, char sep, FILE* outs);
void pv_uint32_t(const vuint32_t* v, char end, char sep, FILE* outs);
void pv_bool(const vb* v, char end, char sep, FILE* outs);
void pv_long(const vl* v, char end, char sep, FILE* outs);
void pv_pair(const vpii* v, char end, char sep, FILE* outs);

void pi_int(const int* x, char end);
void pi_ll(const ll* x, char end);
void pi_db(const db* x, char end);
void pi_ldb(const ldb* x, char end);
void pi_float(const float* x, char end);
void pi_char(const char* x, char end);
void pi_string(const char* x, char end);
void pi_mod(const Modular* x, char end);
void pi_uint64_t(const uint64_t* x, char end);
void pi_uint32_t(const uint32_t* x, char end);
void pi_bool(const bool* x, char end);
void pi_long(const long* x, char end);
void pi_pair(const pair* x, char end);

ll russian(ll a, ll k, ll m);
ll fastpow(ll a, ll k, ll m);
ll slowpow(ll a, ll k, ll m);
ll id0(ll a, ll b);
ll _gcd(ll a, ll b);
ll _lcm(ll a, ll b);
ll _inv(ll a, ll p);

void print_bits(ll x, int force_len);

int main()
{   
    int t = scanf_t_int();
    while (t--)
        print(solve());

    return 0;
}

Modular operator+(const pair* a, const pair* b) { return { a->st + b->st, a->nd + b->nd }; }
Modular* operator+=(pair* a, const pair* b) { a->st += b->st; a->nd += b->nd; return a; }
Modular operator-(const pair* p) { return { -p->st, -p->nd }; }
Modular operator-(const pair* a, const pair* b) { return { a->st - b->st, a->nd - b->nd }; }
Modular* operator-=(pair* a, const pair* b) { a->st -= b->st; a->nd -= b->nd; return a; }
Modular operator*(const pair* p, int mult) { return { p->st * mult, p->nd * mult }; }
Modular operator*(int mult, const pair* p) { return { p->st * mult, p->nd * mult }; }

Modular* operator+=(Modular* a, const Modular* b) { a->value += b->value; if (a->value >= a->MOD_VAL) a->value -= a->MOD_VAL; return a; }
Modular* operator-=(Modular* a, const Modular* b) { a->value -= b->value; if (a->value < 0) a->value += a->MOD_VAL; return a; }
Modular* operator*=(Modular* a, const Modular* b) { a->value = (ll)a->value * b->value % a->MOD_VAL; return a; }
Modular* operator/=(Modular* a, const Modular* b) { return a *= inv(b); }
Modular* operator++(Modular* a) { return a += 1; }
Modular* operator--(Modular* a) { return a -= 1; }

Modular operator+(const Modular* a, const Modular* b) { return { a->value + b->value }; }
Modular operator-(const Modular* a, const Modular* b) { return a -= b; }
Modular operator-(const Modular* a) { return 0 - a; }
Modular operator*(const Modular* a, const Modular* b) { return a *= b; }
Modular operator/(const Modular* a, const Modular* b) { return a /= b; }
void operator<<(FILE* os, const Modular* m) { fprintf(os, "%d", m->value); }

bool operator==(const Modular* a, const Modular* b) { return a->value == b->value; }
bool operator!=(const Modular* a, const Modular* b) { return a->value != b->value; }

Modular exp(Modular* a, ll k)
{
    Modular res = 1;
    while (k) { if (k & 1LL) res *= *a; *a *= *a; k >>= 1; }
    return res;
}

Modular inv(Modular* a) { return exp(a, a->MOD_VAL - 2); }

Modular* Modular_init(Modular* m, ll v)
{
    m->value = v % m->MOD_VAL;
    if (m->value < 0) m->value += m->MOD_VAL;
    return m;
}

Modular* Modular_init2(Modular* m, ll a, ll b)
{
    *m += a;
    *m /= b;
    return m;
}

int scanf_t_int() { int x; scanf("%d", &x); return x; }
ll scanf_t_ll() { ll x; scanf("%lld", &x); return x; }
db scanf_t_db() { db x; scanf("%lf", &x); return x; }
ldb scanf_t_ldb() { ldb x; scanf("%Lf", &x); return x; }
char scanf_t_char() { char x; scanf(" %c", &x); return x; }
float scanf_t_float() { float x; scanf("%f", &x); return x; }
char* scanf_t_string() { char* x = malloc(8 * sizeof(char)); scanf("%s", x); return x; }
char* scanf_t_string_int(int n) { char* x = malloc((n + 7) * sizeof(char)); scanf("%s", x); return x; }

void printf_t_int(const int* x, char end, FILE* out) { fprintf(out, "%d%c", *x, end); }
void printf_t_ll(const ll* x, char end, FILE* out) { fprintf(out, "%lld%c", *x, end); }
void printf_t_db(const db* x, char end, FILE* out) { fprintf(out, "%.8lf%c", *x, end); }
void printf_t_ldb(const ldb* x, char end, FILE* out) { fprintf(out, "%.10Lf%c", *x, end); }
void printf_t_float(const float* x, char end, FILE* out) { fprintf(out, "%f%c", *x, end); }
void printf_t_char(const char* x, char end, FILE* out) { fprintf(out, "%c%c", *x, end); }
void printf_t_string(const char* x, char end, FILE* out) { fprintf(out, "%s%c", x, end); }
void printf_t_mod(const Modular* x, char end, FILE* out) { printf_t_int(&x->value, end, out); }
void printf_t_uint64_t(const uint64_t* x, char end, FILE* out) { fprintf(out, "%lu%c", *x, end); }
void printf_t_uint32_t(const uint32_t* x, char end, FILE* out) { fprintf(out, "%u%c", *x, end); }
void printf_t_bool(const bool* x, char end, FILE* out) { fprintf(out, "%d%c", *x, end); }
void printf_t_long(const long* x, char end, FILE* out) { fprintf(out, "%ld%c", *x, end); }
void printf_t_pair(const pair* x, char end, FILE* out) { printf_t_int(&x->st, ' ', out); printf_t_int(&x->nd, end, out); }
void printf_t_int_arr(const int* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_int(&arr[i], ' ', out); printf_t_int(&arr[size - 1], end, out); }
void printf_t_ll_arr(const ll* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_ll(&arr[i], ' ', out); printf_t_ll(&arr[size - 1], end, out); }
void printf_t_db_arr(const db* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_db(&arr[i], ' ', out); printf_t_db(&arr[size - 1], end, out); }
void printf_t_ldb_arr(const ldb* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_ldb(&arr[i], ' ', out); printf_t_ldb(&arr[size - 1], end, out); }
void printf_t_float_arr(const float* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_float(&arr[i], ' ', out); printf_t_float(&arr[size - 1], end, out); }
void printf_t_char_arr(const char* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_char(&arr[i], ' ', out); printf_t_char(&arr[size - 1], end, out); }
void printf_t_string_arr(const char* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_string(&arr[i], ' ', out); printf_t_string(&arr[size - 1], end, out); }
void printf_t_mod_arr(const Modular* arr, int size, char end, FILE* out) { for (int i = 0; i < size; i++) printf_t_mod(&arr[i], ' ', out); printf_t_mod(&arr[size - 1], end, out); }

void print() { printf("\n"); }

void print_int(const int* last) { printf_t_int(last, '\n'); }
void print_ll(const ll* last) { printf_t_ll(last, '\n'); }
void print_db(const db* last) { printf_t_db(last, '\n'); }
void print_ldb(const ldb* last) { printf_t_ldb(last, '\n'); }
void print_float(const float* last) { printf_t_float(last, '\n'); }
void print_char(const char* last) { printf_t_char(last, '\n'); }
void print_string(const char* last) { printf_t_string(last, '\n'); }
void print_mod(const Modular* last) { printf_t_mod(last, '\n'); }
void print_uint64_t(const uint64_t* last) { printf_t_uint64_t(last, '\n'); }
void print_uint32_t(const uint32_t* last) { printf_t_uint32_t(last, '\n'); }
void print_bool(const bool* last) { printf_t_bool(last, '\n'); }
void print_long(const long* last) { printf_t_long(last, '\n'); }
void print_pair(const pair* last) { printf_t_pair(last, '\n'); }

void print_int(const int* first, const int* rest) { printf_t_int(first, ' '); print_int(rest); }
void print_ll(const ll* first, const ll* rest) { printf_t_ll(first, ' '); print_ll(rest); }
void print_db(const db* first, const db* rest) { printf_t_db(first, ' '); print_db(rest); }
void print_ldb(const ldb* first, const ldb* rest) { printf_t_ldb(first, ' '); print_ldb(rest); }
void print_float(const float* first, const float* rest) { printf_t_float(first, ' '); print_float(rest); }
void print_char(const char* first, const char* rest) { printf_t_char(first, ' '); print_char(rest); }
void print_string(const char* first, const char* rest) { printf_t_string(first, ' '); print_string(rest); }
void print_mod(const Modular* first, const Modular* rest) { printf_t_mod(first, ' '); print_mod(rest); }
void print_uint64_t(const uint64_t* first, const uint64_t* rest) { printf_t_uint64_t(first, ' '); print_uint64_t(rest); }
void print_uint32_t(const uint32_t* first, const uint32_t* rest) { printf_t_uint32_t(first, ' '); print_uint32_t(rest); }
void print_bool(const bool* first, const bool* rest) { printf_t_bool(first, ' '); print_bool(rest); }
void print_long(const long* first, const long* rest) { printf_t_long(first, ' '); print_long(rest); }
void print_pair(const pair* first, const pair* rest) { printf_t_pair(first, ' '); print_pair(rest); }

void _dbg() {}

void _dbg_int(const int* last) { printf_t_int(last, ' ', stderr); }
void _dbg_ll(const ll* last) { printf_t_ll(last, ' ', stderr); }
void _dbg_db(const db* last) { printf_t_db(last, ' ', stderr); }
void _dbg_ldb(const ldb* last) { printf_t_ldb(last, ' ', stderr); }
void _dbg_float(const float* last) { printf_t_float(last, ' ', stderr); }
void _dbg_char(const char* last) { printf_t_char(last, ' ', stderr); }
void _dbg_string(const char* last) { printf_t_string(last, ' ', stderr); }
void _dbg_mod(const Modular* last) { printf_t_mod(last, ' ', stderr); }
void _dbg_uint64_t(const uint64_t* last) { printf_t_uint64_t(last, ' ', stderr); }
void _dbg_uint32_t(const uint32_t* last) { printf_t_uint32_t(last, ' ', stderr); }
void _dbg_bool(const bool* last) { printf_t_bool(last, ' ', stderr); }
void _dbg_long(const long* last) { printf_t_long(last, ' ', stderr); }
void _dbg_pair(const pair* last) { printf_t_pair(last, ' ', stderr); }

void _dbg_int(const int* first, const int* rest) { printf_t_int(first, ' ', stderr); _dbg_int(rest); }
void _dbg_ll(const ll* first, const ll* rest) { printf_t_ll(first, ' ', stderr); _dbg_ll(rest); }
void _dbg_db(const db* first, const db* rest) { printf_t_db(first, ' ', stderr); _dbg_db(rest); }
void _dbg_ldb(const ldb* first, const ldb* rest) { printf_t_ldb(first, ' ', stderr); _dbg_ldb(rest); }
void _dbg_float(const float* first, const float* rest) { printf_t_float(first, ' ', stderr); _dbg_float(rest); }
void _dbg_char(const char* first, const char* rest) { printf_t_char(first, ' ', stderr); _dbg_char(rest); }
void _dbg_string(const char* first, const char* rest) { printf_t_string(first, ' ', stderr); _dbg_string(rest); }
void _dbg_mod(const Modular* first, const Modular* rest) { printf_t_mod(first, ' ', stderr); _dbg_mod(rest); }
void _dbg_uint64_t(const uint64_t* first, const uint64_t* rest) { printf_t_uint64_t(first, ' ', stderr); _dbg_uint64_t(rest); }
void _dbg_uint32_t(const uint32_t* first, const uint32_t* rest) { printf_t_uint32_t(first, ' ', stderr); _dbg_uint32_t(rest); }
void _dbg_bool(const bool* first, const bool* rest) { printf_t_bool(first, ' ', stderr); _dbg_bool(rest); }
void _dbg_long(const long* first, const long* rest) { printf_t_long(first, ' ', stderr); _dbg_long(rest); }
void _dbg_pair(const pair* first, const pair* rest) { printf_t_pair(first, ' ', stderr); _dbg_pair(rest); }

void dbg() { fprintf(stderr, "[ "); _dbg(); fprintf(stderr, "]\n"); }

void dbg_int(const int* last) { fprintf(stderr, "[ "); _dbg_int(last); fprintf(stderr, "]\n"); }
void dbg_ll(const ll* last) { fprintf(stderr, "[ "); _dbg_ll(last); fprintf(stderr, "]\n"); }
void dbg_db(const db* last) { fprintf(stderr, "[ "); _dbg_db(last); fprintf(stderr, "]\n"); }
void dbg_ldb(const ldb* last) { fprintf(stderr, "[ "); _dbg_ldb(last); fprintf(stderr, "]\n"); }
void dbg_float(const float* last) { fprintf(stderr, "[ "); _dbg_float(last); fprintf(stderr, "]\n"); }
void dbg_char(const char* last) { fprintf(stderr, "[ "); _dbg_char(last); fprintf(stderr, "]\n"); }
void dbg_string(const char* last) { fprintf(stderr, "[ "); _dbg_string(last); fprintf(stderr, "]\n"); }
void dbg_mod(const Modular* last) { fprintf(stderr, "[ "); _dbg_mod(last); fprintf(stderr, "]\n"); }
void dbg_uint64_t(const uint64_t* last) { fprintf(stderr, "[ "); _dbg_uint64_t(last); fprintf(stderr, "]\n"); }
void dbg_uint32_t(const uint32_t* last) { fprintf(stderr, "[ "); _dbg_uint32_t(last); fprintf(stderr, "]\n"); }
void dbg_bool(const bool* last) { fprintf(stderr, "[ "); _dbg_bool(last); fprintf(stderr, "]\n"); }
void dbg_long(const long* last) { fprintf(stderr, "[ "); _dbg_long(last); fprintf(stderr, "]\n"); }
void dbg_pair(const pair* last) { fprintf(stderr, "[ "); _dbg_pair(last); fprintf(stderr, "]\n"); }

void dbg_int(const int* first, const int* rest) { fprintf(stderr, "[ "); _dbg_int(first, rest); fprintf(stderr, "]\n"); }
void dbg_ll(const ll* first, const ll* rest) { fprintf(stderr, "[ "); _dbg_ll(first, rest); fprintf(stderr, "]\n"); }
void dbg_db(const db* first, const db* rest) { fprintf(stderr, "[ "); _dbg_db(first, rest); fprintf(stderr, "]\n"); }
void dbg_ldb(const ldb* first, const ldb* rest) { fprintf(stderr, "[ "); _dbg_ldb(first, rest); fprintf(stderr, "]\n"); }
void dbg_float(const float* first, const float* rest) { fprintf(stderr, "[ "); _dbg_float(first, rest); fprintf(stderr, "]\n"); }
void dbg_char(const char* first, const char* rest) { fprintf(stderr, "[ "); _dbg_char(first, rest); fprintf(stderr, "]\n"); }
void dbg_string(const char* first, const char* rest) { fprintf(stderr, "[ "); _dbg_string(first, rest); fprintf(stderr, "]\n"); }
void dbg_mod(const Modular* first, const Modular* rest) { fprintf(stderr, "[ "); _dbg_mod(first, rest); fprintf(stderr, "]\n"); }
void dbg_uint64_t(const uint64_t* first, const uint64_t* rest) { fprintf(stderr, "[ "); _dbg_uint64_t(first, rest); fprintf(stderr, "]\n"); }
void dbg_uint32_t(const uint32_t* first, const uint32_t* rest) { fprintf(stderr, "[ "); _dbg_uint32_t(first, rest); fprintf(stderr, "]\n"); }
void dbg_bool(const bool* first, const bool* rest) { fprintf(stderr, "[ "); _dbg_bool(first, rest); fprintf(stderr, "]\n"); }
void dbg_long(const long* first, const long* rest) { fprintf(stderr, "[ "); _dbg_long(first, rest); fprintf(stderr, "]\n"); }
void dbg_pair(const pair* first, const pair* rest) { fprintf(stderr, "[ "); _dbg_pair(first, rest); fprintf(stderr, "]\n"); }

void in_int(int* begin, int n) { while (n--) *begin++ = scanf_t_int(); }
void in_ll(ll* begin, int n) { while (n--) *begin++ = scanf_t_ll(); }
void in_db(db* begin, int n) { while (n--) *begin++ = scanf_t_db(); }
void in_ldb(ldb* begin, int n) { while (n--) *begin++ = scanf_t_ldb(); }
void in_float(float* begin, int n) { while (n--) *begin++ = scanf_t_float(); }
void in_char(char* begin, int n) { while (n--) *begin++ = scanf_t_char(); }
void in_string(char** begin, int n) { while (n--) *begin++ = scanf_t_string(); }
void in_mod(Modular* begin, int n) { while (n--) *begin++ = scanf_t_int(); }
void in_uint64_t(uint64_t* begin, int n) { while (n--) *begin++ = scanf_t_uint64_t(); }
void in_uint32_t(uint32_t* begin, int n) { while (n--) *begin++ = scanf_t_uint32_t(); }
void in_bool(bool* begin, int n) { while (n--) *begin++ = scanf_t_int(); }
void in_long(long* begin, int n) { while (n--) *begin++ = scanf_t_ll(); }
void in_pair(pair* begin, int n) { while (n--) { begin->st = scanf_t_int(); begin->nd = scanf_t_int(); begin++; } }

void sv_int(vi* v, int n) { v->arr = malloc(n * sizeof(int)); v->size = n; in_int(v->arr, n); }
void sv_ll(vl* v, int n) { v->arr = malloc(n * sizeof(ll)); v->size = n; in_ll(v->arr, n); }
void sv_db(vdb* v, int n) { v->arr = malloc(n * sizeof(db)); v->size = n; in_db(v->arr, n); }
void sv_ldb(vldb* v, int n) { v->arr = malloc(n * sizeof(ldb)); v->size = n; in_ldb(v->arr, n); }
void sv_float(vfloat* v, int n) { v->arr = malloc(n * sizeof(float)); v->size = n; in_float(v->arr, n); }
void sv_char(vc* v, int n) { v->arr = malloc(n * sizeof(char)); v->size = n; in_char(v->arr, n); }
void sv_string(vs* v, int n) { v->arr = malloc(n * sizeof(char*)); v->size = n; in_string(v->arr, n); }
void sv_mod(vmod* v, int n) { v->arr = malloc(n * sizeof(Modular)); v->size = n; in_mod(v->arr, n); }
void sv_uint64_t(vuint64_t* v, int n) { v->arr = malloc(n * sizeof(uint64_t)); v->size = n; in_uint64_t(v->arr, n); }
void sv_uint32_t(vuint32_t* v, int n) { v->arr = malloc(n * sizeof(uint32_t)); v->size = n; in_uint32_t(v->arr, n); }
void sv_bool(vb* v, int n) { v->arr = malloc(n * sizeof(bool)); v->size = n; in_bool(v->arr, n); }
void sv_long(vl* v, int n) { v->arr = malloc(n * sizeof(long)); v->size = n; in_long(v->arr, n); }
void sv_pair(vpii* v, int n) { v->arr = malloc(n * sizeof(pii)); v->size = n; in_pair(v->arr, n); }

void out_int(const int* begin, const int* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_int(begin++, sep, outs); } printf_t_int(begin, endl, outs); }
void out_ll(const ll* begin, const ll* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_ll(begin++, sep, outs); } printf_t_ll(begin, endl, outs); }
void out_db(const db* begin, const db* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_db(begin++, sep, outs); } printf_t_db(begin, endl, outs); }
void out_ldb(const ldb* begin, const ldb* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_ldb(begin++, sep, outs); } printf_t_ldb(begin, endl, outs); }
void out_float(const float* begin, const float* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_float(begin++, sep, outs); } printf_t_float(begin, endl, outs); }
void out_char(const char* begin, const char* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_char(begin++, sep, outs); } printf_t_char(begin, endl, outs); }
void out_string(const char** begin, const char** end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_string(*begin++, sep, outs); } printf_t_string(*begin, endl, outs); }
void out_mod(const Modular* begin, const Modular* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_mod(begin++, sep, outs); } printf_t_mod(begin, endl, outs); }
void out_uint64_t(const uint64_t* begin, const uint64_t* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_uint64_t(begin++, sep, outs); } printf_t_uint64_t(begin, endl, outs); }
void out_uint32_t(const uint32_t* begin, const uint32_t* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_uint32_t(begin++, sep, outs); } printf_t_uint32_t(begin, endl, outs); }
void out_bool(const bool* begin, const bool* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_bool(begin++, sep, outs); } printf_t_bool(begin, endl, outs); }
void out_long(const long* begin, const long* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_long(begin++, sep, outs); } printf_t_long(begin, endl, outs); }
void out_pair(const pair* begin, const pair* end, char endl, char sep, FILE* outs) { if (begin == end) { fprintf(outs, "%c", endl); return; } while (begin != end - 1) { printf_t_pair(begin++, sep, outs); } printf_t_pair(begin, endl, outs); }

void pv_int(const vi* v, char end, char sep, FILE* outs) { out_int(v->arr, v->arr + v->size, end, sep, outs); }
void pv_ll(const vl* v, char end, char sep, FILE* outs) { out_ll(v->arr, v->arr + v->size, end, sep, outs); }
void pv_db(const vdb* v, char end, char sep, FILE* outs) { out_db(v->arr, v->arr + v->size, end, sep, outs); }
void pv_ldb(const vldb* v, char end, char sep, FILE* outs) { out_ldb(v->arr, v->arr + v->size, end, sep, outs); }
void pv_float(const vfloat* v, char end, char sep, FILE* outs) { out_float(v->arr, v->arr + v->size, end, sep, outs); }
void pv_char(const vc* v, char end, char sep, FILE* outs) { out_char(v->arr, v->arr + v->size, end, sep, outs); }
void pv_string(const vs* v, char end, char sep, FILE* outs) { out_string(v->arr, v->arr + v->size, end, sep, outs); }
void pv_mod(const vmod* v, char end, char sep, FILE* outs) { out_mod(v->arr, v->arr + v->size, end, sep, outs); }
void pv_uint64_t(const vuint64_t* v, char end, char sep, FILE* outs) { out_uint64_t(v->arr, v->arr + v->size, end, sep, outs); }
void pv_uint32_t(const vuint32_t* v, char end, char sep, FILE* outs) { out_uint32_t(v->arr, v->arr + v->size, end, sep, outs); }
void pv_bool(const vb* v, char end, char sep, FILE* outs) { out_bool(v->arr, v->arr + v->size, end, sep, outs); }
void pv_long(const vl* v, char end, char sep, FILE* outs) { out_long(v->arr, v->arr + v->size, end, sep, outs); }
void pv_pair(const vpii* v, char end, char sep, FILE* outs) { out_pair(v->arr, v->arr + v->size, end, sep, outs); }

void pi_int(const int* x, char end) { printf_t_int(x, end); }
void pi_ll(const ll* x, char end) { printf_t_ll(x, end); }
void pi_db(const db* x, char end) { printf_t_db(x, end); }
void pi_ldb(const ldb* x, char end) { printf_t_ldb(x, end); }
void pi_float(const float* x, char end) { printf_t_float(x, end); }
void pi_char(const char* x, char end) { printf_t_char(x, end); }
void pi_string(const char* x, char end) { printf_t_string(x, end); }
void pi_mod(const Modular* x, char end) { printf_t_mod(x, end); }
void pi_uint64_t(const uint64_t* x, char end) { printf_t_uint64_t(x, end); }
void pi_uint32_t(const uint32_t* x, char end) { printf_t_uint32_t(x, end); }
void pi_bool(const bool* x, char end) { printf_t_bool(x, end); }
void pi_long(const long* x, char end) { printf_t_long(x, end); }
void pi_pair(const pair* x, char end) { printf_t_pair(x, end); }
