#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

const int MOD7 = 1000000007;
const int MOD9 = 1000000009;
const int MODF = 998244353;

int mod = MOD7;

typedef struct {
    int n;
} modint;

modint modint_create() {
    modint m;
    m.n = 0;
    return m;
}

modint modint_create_with_value(ll n) {
    modint m;
    if (n >= 0 && n < mod) {
        m.n = n;
        return m;
    }
    n %= mod;
    if (n < 0) {
        n += mod;
    }
    m.n = n;
    return m;
}

modint modint_add(modint a, modint b) {
    modint res;
    res.n = (a.n + b.n) % mod;
    return res;
}

modint modint_sub(modint a, modint b) {
    modint res;
    res.n = (a.n - b.n + mod) % mod;
    return res;
}

modint modint_mul(modint a, modint b) {
    modint res;
    res.n = (a.n * b.n) % mod;
    return res;
}

modint modint_div(modint a, modint b) {
    modint res;
    res.n = (a.n * modint_inverse(b).n) % mod;
    return res;
}

modint modint_negate(modint a) {
    modint res;
    res.n = (mod - a.n) % mod;
    return res;
}

modint modint_inverse(modint a) {
    ll x, y;
    ll g = gcd(a.n, mod, &x, &y);
    return modint_create_with_value(x);
}

int modint_log(modint a, modint alpha) {
    // TODO: Implement modint_log
    return 0;
}

typedef struct {
    int type;
    int at;
    int dx;
    int v;
} Event;

bool event_compare(Event a, Event b) {
    return (ll)(a.dx) * b.v < (ll)(b.dx) * a.v;
}

typedef struct {
    int* data;
    int size;
} arri;

arri arri_create(int size) {
    arri a;
    a.data = (int*)malloc(size * sizeof(int));
    a.size = size;
    return a;
}

typedef struct {
    int* data;
    int size;
} vec;

vec vec_create(int size) {
    vec v;
    v.data = (int*)malloc(size * sizeof(int));
    v.size = size;
    return v;
}

typedef struct {
    vec* data;
    int size;
} arr;

arr arr_create(int size) {
    arr a;
    a.data = (vec*)malloc(size * sizeof(vec));
    a.size = size;
    return a;
}

typedef struct {
    bool* data;
    int size;
} arr2d;

arr2d arr2d_create(int rows, int cols) {
    arr2d a;
    a.data = (bool*)malloc(rows * cols * sizeof(bool));
    a.size = rows * cols;
    return a;
}

typedef struct {
    int* data;
    int size;
} arr3d;

arr3d arr3d_create(int d1, int d2, int d3) {
    arr3d a;
    a.data = (int*)malloc(d1 * d2 * d3 * sizeof(int));
    a.size = d1 * d2 * d3;
    return a;
}

typedef struct {
    int* data;
    int size;
} arr4d;

arr4d arr4d_create(int d1, int d2, int d3, int d4) {
    arr4d a;
    a.data = (int*)malloc(d1 * d2 * d3 * d4 * sizeof(int));
    a.size = d1 * d2 * d3 * d4;
    return a;
}

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} range;

typedef struct {
    int* b;
    int* e;
    int n;
} arr;

arr arr_create() {
    arr a;
    a.b = NULL;
    a.e = NULL;
    a.n = 0;
    return a;
}

arr arr_create_with_size(int n) {
    arr a;
    a.n = n;
    if (n > 0) {
        a.b = (int*)malloc(n * sizeof(int));
        a.e = a.b + n;
    } else {
        a.b = NULL;
        a.e = NULL;
    }
    return a;
}

arr arr_create_with_size_and_value(int n, int init) {
    arr a = arr_create_with_size(n);
    for (int i = 0; i < n; i++) {
        a.b[i] = init;
    }
    return a;
}

arr arr_create_with_initializer_list(int* l, int size) {
    arr a = arr_create_with_size(size);
    for (int i = 0; i < size; i++) {
        a.b[i] = l[i];
    }
    return a;
}

int arr_size(arr a) {
    return a.n;
}

int* arr_begin(arr a) {
    return a.b;
}

int* arr_end(arr a) {
    return a.e;
}

arr arr_clone(arr a) {
    arr res = arr_create_with_size(a.n);
    for (int i = 0; i < a.n; i++) {
        res.b[i] = a.b[i];
    }
    return res;
}

int arr_get(arr a, int at) {
    return a.b[at];
}

void arr_set(arr a, int at, int value) {
    a.b[at] = value;
}

bool arr_equals(arr a, arr b) {
    if (a.n != b.n) {
        return false;
    }
    for (int i = 0; i < a.n; i++) {
        if (a.b[i] != b.b[i]) {
            return false;
        }
    }
    return true;
}

typedef arr arri;

typedef struct {
    int* b;
    int* e;
    int d1;
    int d2;
    int sz;
} arr2d;

arr2d arr2d_create(int d1, int d2) {
    arr2d a;
    a.b = (int*)malloc(d1 * d2 * sizeof(int));
    a.e = a.b + d1 * d2;
    a.d1 = d1;
    a.d2 = d2;
    a.sz = d1 * d2;
    return a;
}

int arr2d_size(arr2d a) {
    return a.sz;
}

int arr2d_dim1(arr2d a) {
    return a.d1;
}

int arr2d_dim2(arr2d a) {
    return a.d2;
}

int* arr2d_begin(arr2d a) {
    return a.b;
}

int* arr2d_end(arr2d a) {
    return a.e;
}

int arr2d_get(arr2d a, int i1, int i2) {
    return a.b[i1 * a.d2 + i2];
}

void arr2d_set(arr2d a, int i1, int i2, int value) {
    a.b[i1 * a.d2 + i2] = value;
}

typedef struct {
    int* b;
    int* e;
    int d1;
    int d2;
    int d3;
    int shift;
    int sz;
} arr3d;

arr3d arr3d_create(int d1, int d2, int d3) {
    arr3d a;
    a.b = (int*)malloc(d1 * d2 * d3 * sizeof(int));
    a.e = a.b + d1 * d2 * d3;
    a.d1 = d1;
    a.d2 = d2;
    a.d3 = d3;
    a.shift = d2 * d3;
    a.sz = d1 * d2 * d3;
    return a;
}

int arr3d_size(arr3d a) {
    return a.sz;
}

int arr3d_dim1(arr3d a) {
    return a.d1;
}

int arr3d_dim2(arr3d a) {
    return a.d2;
}

int arr3d_dim3(arr3d a) {
    return a.d3;
}

int* arr3d_begin(arr3d a) {
    return a.b;
}

int* arr3d_end(arr3d a) {
    return a.e;
}

int arr3d_get(arr3d a, int i1, int i2, int i3) {
    return a.b[i1 * a.shift + i2 * a.d3 + i3];
}

void arr3d_set(arr3d a, int i1, int i2, int i3, int value) {
    a.b[i1 * a.shift + i2 * a.d3 + i3] = value;
}

typedef struct {
    int* b;
    int* e;
    int d1;
    int d2;
    int d3;
    int d4;
    int shift1;
    int shift2;
    int sz;
} arr4d;

arr4d arr4d_create(int d1, int d2, int d3, int d4) {
    arr4d a;
    a.b = (int*)malloc(d1 * d2 * d3 * d4 * sizeof(int));
    a.e = a.b + d1 * d2 * d3 * d4;
    a.d1 = d1;
    a.d2 = d2;
    a.d3 = d3;
    a.d4 = d4;
    a.shift1 = d2 * d3 * d4;
    a.shift2 = d3 * d4;
    a.sz = d1 * d2 * d3 * d4;
    return a;
}

int arr4d_size(arr4d a) {
    return a.sz;
}

int arr4d_dim1(arr4d a) {
    return a.d1;
}

int arr4d_dim2(arr4d a) {
    return a.d2;
}

int arr4d_dim3(arr4d a) {
    return a.d3;
}

int arr4d_dim4(arr4d a) {
    return a.d4;
}

int* arr4d_begin(arr4d a) {
    return a.b;
}

int* arr4d_end(arr4d a) {
    return a.e;
}

int arr4d_get(arr4d a, int i1, int i2, int i3, int i4) {
    return a.b[i1 * a.shift1 + i2 * a.shift2 + i3 * a.d4 + i4];
}

void arr4d_set(arr4d a, int i1, int i2, int i3, int i4, int value) {
    a.b[i1 * a.shift1 + i2 * a.shift2 + i3 * a.d4 + i4] = value;
}

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
} NumberIterator;

typedef struct {
    int first;
    int second;
} pii;

typedef struct {
    int v;
