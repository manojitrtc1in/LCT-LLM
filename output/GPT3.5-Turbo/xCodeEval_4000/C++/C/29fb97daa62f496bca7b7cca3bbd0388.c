#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define C 20

typedef struct {
    int value;
    int MOD_VAL;
} Modular;

Modular make_Modular(int value, int MOD_VAL) {
    Modular m;
    m.value = value;
    m.MOD_VAL = MOD_VAL;
    return m;
}

Modular operator_plus(Modular a, Modular b) {
    return make_Modular((a.value + b.value) % a.MOD_VAL, a.MOD_VAL);
}

Modular operator_minus(Modular a, Modular b) {
    return make_Modular((a.value - b.value + a.MOD_VAL) % a.MOD_VAL, a.MOD_VAL);
}

Modular operator_multiply(Modular a, Modular b) {
    return make_Modular((a.value * b.value) % a.MOD_VAL, a.MOD_VAL);
}

Modular operator_divide(Modular a, Modular b) {
    int inv = 1;
    int b_val = b.value;
    int MOD_VAL = a.MOD_VAL;
    while (b_val > 1) {
        int q = a.value / b_val;
        int t = b_val;
        b_val = a.value % b_val;
        a.value = t;
        t = inv;
        inv = MOD_VAL - q * inv;
        MOD_VAL = t;
    }
    return make_Modular((a.value * inv) % a.MOD_VAL, a.MOD_VAL);
}

Modular operator_increment(Modular a) {
    return make_Modular((a.value + 1) % a.MOD_VAL, a.MOD_VAL);
}

Modular operator_decrement(Modular a) {
    return make_Modular((a.value - 1 + a.MOD_VAL) % a.MOD_VAL, a.MOD_VAL);
}

typedef struct {
    int first;
    int second;
} pair;

pair make_pair(int first, int second) {
    pair p;
    p.first = first;
    p.second = second;
    return p;
}

pair operator_plus_pair(pair a, pair b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

pair operator_minus_pair(pair a, pair b) {
    return make_pair(a.first - b.first, a.second - b.second);
}

typedef struct {
    int* data;
    int size;
} vector;

vector make_vector(int size) {
    vector v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vector_push_back(vector* v, int value) {
    v->data[v->size++] = value;
}

int vector_get(vector* v, int index) {
    return v->data[index];
}

typedef struct {
    vector* data;
    int size;
} vvi;

vvi make_vvi(int size) {
    vvi vv;
    vv.data = (vector*)malloc(size * sizeof(vector));
    vv.size = size;
    return vv;
}

void vvi_push_back(vvi* vv, vector v) {
    vv->data[vv->size++] = v;
}

int vvi_get(vvi* vv, int index) {
    return vv->data[index];
}

typedef struct {
    int* data;
    int size;
} vi;

vi make_vi(int size) {
    vi v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vi_push_back(vi* v, int value) {
    v->data[v->size++] = value;
}

int vi_get(vi* v, int index) {
    return v->data[index];
}

typedef struct {
    char* data;
    int size;
} str;

str make_str(int size) {
    str s;
    s.data = (char*)malloc(size * sizeof(char));
    s.size = size;
    return s;
}

void str_push_back(str* s, char value) {
    s->data[s->size++] = value;
}

char str_get(str* s, int index) {
    return s->data[index];
}

typedef struct {
    int* data;
    int size;
} vb;

vb make_vb(int size) {
    vb v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vb_push_back(vb* v, int value) {
    v->data[v->size++] = value;
}

int vb_get(vb* v, int index) {
    return v->data[index];
}

typedef struct {
    Modular* data;
    int size;
} vModular;

vModular make_vModular(int size) {
    vModular v;
    v.data = (Modular*)malloc(size * sizeof(Modular));
    v.size = size;
    return v;
}

void vModular_push_back(vModular* v, Modular value) {
    v->data[v->size++] = value;
}

Modular vModular_get(vModular* v, int index) {
    return v->data[index];
}

typedef struct {
    pair* data;
    int size;
} vpair;

vpair make_vpair(int size) {
    vpair v;
    v.data = (pair*)malloc(size * sizeof(pair));
    v.size = size;
    return v;
}

void vpair_push_back(vpair* v, pair value) {
    v->data[v->size++] = value;
}

pair vpair_get(vpair* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vint;

vint make_vint(int size) {
    vint v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vint_push_back(vint* v, int value) {
    v->data[v->size++] = value;
}

int vint_get(vint* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vpii;

vpii make_vpii(int size) {
    vpii v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vpii_push_back(vpii* v, int value) {
    v->data[v->size++] = value;
}

int vpii_get(vpii* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vpli;

vpli make_vpli(int size) {
    vpli v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vpli_push_back(vpli* v, int value) {
    v->data[v->size++] = value;
}

int vpli_get(vpli* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vpldb;

vpldb make_vpldb(int size) {
    vpldb v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vpldb_push_back(vpldb* v, int value) {
    v->data[v->size++] = value;
}

int vpldb_get(vpldb* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vpil;

vpil make_vpil(int size) {
    vpil v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vpil_push_back(vpil* v, int value) {
    v->data[v->size++] = value;
}

int vpil_get(vpil* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vpl;

vpl make_vpl(int size) {
    vpl v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vpl_push_back(vpl* v, int value) {
    v->data[v->size++] = value;
}

int vpl_get(vpl* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vldb;

vldb make_vldb(int size) {
    vldb v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vldb_push_back(vldb* v, int value) {
    v->data[v->size++] = value;
}

int vldb_get(vldb* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vdb;

vdb make_vdb(int size) {
    vdb v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vdb_push_back(vdb* v, int value) {
    v->data[v->size++] = value;
}

int vdb_get(vdb* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vchar;

vchar make_vchar(int size) {
    vchar v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vchar_push_back(vchar* v, int value) {
    v->data[v->size++] = value;
}

int vchar_get(vchar* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vfloat;

vfloat make_vfloat(int size) {
    vfloat v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vfloat_push_back(vfloat* v, int value) {
    v->data[v->size++] = value;
}

int vfloat_get(vfloat* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vll;

vll make_vll(int size) {
    vll v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vll_push_back(vll* v, int value) {
    v->data[v->size++] = value;
}

int vll_get(vll* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vstring;

vstring make_vstring(int size) {
    vstring v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vstring_push_back(vstring* v, int value) {
    v->data[v->size++] = value;
}

int vstring_get(vstring* v, int index) {
    return v->data[index];
}

typedef struct {
    int* data;
    int size;
} vbool;

vbool make_vbool(int size) {
    vbool v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

void vbool_push_back(vbool* v, int value) {
    v->data[v->size++] = value;
}

int vbool_get(vbool* v, int index) {
    return v->data[index];
}

Modular make_Modular(int value) {
    return make_Modular(value, 7);
}

Modular exp_Modular(Modular a, int k) {
    Modular res = make_Modular(1);
    while (k) {
        if (k & 1) {
            res = operator_multiply(res, a);
        }
        a = operator_multiply(a, a);
        k >>= 1;
    }
    return res;
}

Modular Modular_inv(Modular a) {
    return exp_Modular(a, a.MOD_VAL - 2);
}

Modular operator_plus_Modular(Modular a, Modular b) {
    return operator_plus(a, b);
}

Modular operator_minus_Modular(Modular a, Modular b) {
    return operator_minus(a, b);
}

Modular operator_minus_Modular(Modular a) {
    return make_Modular(-a.value, a.MOD_VAL);
}

Modular operator_multiply_Modular(Modular a, Modular b) {
    return operator_multiply(a, b);
}

Modular operator_divide_Modular(Modular a, Modular b) {
    return operator_divide(a, b);
}

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef struct {
    db real;
    db imag;
} cd;

typedef struct {
    ll first;
    ll second;
} pll;

typedef struct {
    db first;
    db second;
} pdb;

typedef struct {
    ldb first;
    ldb second;
} pldb;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    ll first;
    ll second;
} pil;

typedef struct {
    ll first;
    ll second;
} pli;

typedef struct {
    int first;
    ll second;
} pil;

typedef struct {
    ll first;
    int second;
} pli;

Modular solve() {
    int n = scanf_t();
    str s = scanf_t(n);
    str t = scanf_t(n);
    int G[C];
    int g[C];
    for (int i = 0; i < C; i++) {
        G[i] = make_vi(0);
        g[i] = make_vi(0);
    }
    for (int i = 0; i < n; i++) {
        if (s.data[i] != t.data[i]) {
            int a = s.data[i] - 'a';
            int b = t.data[i] - 'a';
            vi_push_back(G[a], b);
            vi_push_back(G[b], a);
            vi_push_back(g[a], b);
        }
    }
    vi cur;
    vb vis(C);
    void dfs(int v) {
        vis.data[v] = true;
        vi_push_back(cur, v);
        for (int i = 0; i < vi_get(G[v], 0); i++) {
            int s = vi_get(G[v], i);
            if (!vis.data[s]) {
                dfs(s);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < C; i++) {
        if (!vis.data[i]) {
            cur = make_vi(0);
            dfs(i);
            int s = dag(g, cur);
            res += 2 * cur.size - 1 - s;
        }
    }
    return make_Modular(res);
}

int main() {
    int t = scanf_t();
    while (t--) {
        print(solve());
    }
    return 0;
}

int scanf_t() {
    int x;
    scanf("%d", &x);
    return x;
}

ll scanf_t() {
    ll x;
    scanf("%lld", &x);
    return x;
}

db scanf_t() {
    db x;
    scanf("%lf", &x);
    return x;
}

ldb scanf_t() {
    ldb x;
    scanf("%Lf", &x);
    return x;
}

char scanf_t() {
    char x;
    scanf(" %c", &x);
    return x;
}

float scanf_t() {
    float x;
    scanf("%f", &x);
    return x;
}

str scanf_t(int n) {
    char* x = (char*)malloc((n + 7) * sizeof(char));
    char c;
    while (isspace(c = getchar()));
    x[0] = c;
    int i = 1;
    while (!isspace(c = getchar())) {
        x[i++] = c;
    }
    x[i] = '\0';
    str res = make_str(i);
    for (int j = 0; j < i; j++) {
        str_push_back(&res, x[j]);
    }
    free(x);
    return res;
}

void printf_t(int x, char end) {
    printf("%d%c", x, end);
}

void printf_t(ll x, char end) {
    printf("%lld%c", x, end);
}

void printf_t(db x, char end) {
    printf("%.8lf%c", x, end);
}

void printf_t(ldb x, char end) {
    printf("%.10Lf%c", x, end);
}

void printf_t(float x, char end) {
    printf("%f%c", x, end);
}

void printf_t(char x, char end) {
    printf("%c%c", x, end);
}

void printf_t(str x, char end) {
    printf("%s%c", x.data, end);
}

void printf_t(char* x, char end) {
    printf("%s%c", x, end);
}

void printf_t(Modular x, char end) {
    printf_t(x.value, end);
}

void printf_t(unsigned long x, char end) {
    printf("%lu%c", x, end);
}

void printf_t(unsigned int x, char end) {
    printf("%u%c", x, end);
}

void printf_t(bool x, char end) {
    printf("%d%c", x, end);
}

void printf_t(long x, char end) {
    printf("%ld%c", x, end);
}

void printf_t(pair x, char end) {
    printf_t(x.first, ' ');
    printf_t(x.second, end);
}

void printf_t(vi x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vModular x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpair x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vint x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpii x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpli x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpldb x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpil x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpli x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vpl x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vldb x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vdb x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vchar x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vfloat x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vll x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vstring x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}

void printf_t(vbool x, char end) {
    for (int i = 0; i < x.size; i++) {
        printf_t(x.data[i], ' ');
    }
    printf("%c", end);
}
