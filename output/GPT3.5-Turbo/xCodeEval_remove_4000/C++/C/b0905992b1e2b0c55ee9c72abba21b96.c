#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20000013

typedef long long li;
typedef long double ld;

typedef struct {
    int x;
    int y;
} pt;

typedef struct {
    int a;
    int b;
} pair;

typedef struct {
    int* arr;
    int size;
    int capacity;
} vector;

typedef struct {
    int* arr;
    int size;
    int capacity;
} vector_vector_int;

typedef struct {
    int* arr;
    int size;
    int capacity;
} vector_int;

typedef struct {
    int* arr;
    int size;
    int capacity;
} vector_vector_vector_int;

int INF = 1000000000;
li INF64 = 1000000000000000000;
int MOD = 1000000007;
ld EPS = 1e-9;
ld PI = 3.14159265358979323846;

char* s;
int n;

int sz(vector* v) {
    return v->size;
}

int sz_vector_vector_int(vector_vector_int* v) {
    return v->size;
}

int sz_vector_vector_vector_int(vector_vector_vector_int* v) {
    return v->size;
}

void pb(vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size++] = value;
}

void pb_vector_vector_int(vector_vector_int* v, vector_int* value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (vector_int*)realloc(v->arr, v->capacity * sizeof(vector_int));
    }
    v->arr[v->size++] = *value;
}

void pb_vector_vector_vector_int(vector_vector_vector_int* v, vector_vector_int* value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (vector_vector_int*)realloc(v->arr, v->capacity * sizeof(vector_vector_int));
    }
    v->arr[v->size++] = *value;
}

void gen(int n, vector* ord) {
    if (n == 1) {
        pb(ord, 1);
        return;
    }
    gen(n / 2, ord);
    gen((n + 1) / 2, ord);
    pb(ord, n);
}

int get(int t, int ans, vector* ord) {
    vector_int* ord_vector = (vector_int*)malloc(sizeof(vector_int));
    ord_vector->arr = (int*)malloc(t * sizeof(int));
    ord_vector->size = 0;
    ord_vector->capacity = t;
    vector_vector_int* res = (vector_vector_int*)malloc(sizeof(vector_vector_int));
    res->arr = (vector_int*)malloc(t * sizeof(vector_int));
    res->size = 0;
    res->capacity = t;
    int l = 0;
    int pr = 0;
    for (int i = 0; i < sz(ord); i++) {
        int x = ord->arr[i];
        if (x == 1) {
            pr++;
            continue;
        }
        int cnt0 = 0, cnt1 = 0;
        int r = l;
        int fl = 0;
        while (r < n) {
            if (s[r++] == '0') {
                cnt0++;
                if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                    fl = 1;
                    break;
                }
            }
            else {
                cnt1++;
                if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                    fl = 1;
                    break;
                }
            }
        }
        if (!fl) break;
        l = r;
        pr++;
    }
    if (!ans) {
        free(ord_vector->arr);
        free(ord_vector);
        free(res->arr);
        free(res);
        return sz(ord) - pr;
    }
    vector_int* L = (vector_int*)malloc((x / 2) * sizeof(vector_int));
    L->arr = (int*)malloc((x / 2) * sizeof(int));
    L->size = 0;
    L->capacity = x / 2;
    vector_int* R = (vector_int*)malloc(((x + 1) / 2) * sizeof(vector_int));
    R->arr = (int*)malloc(((x + 1) / 2) * sizeof(int));
    R->size = 0;
    R->capacity = (x + 1) / 2;
    while (cnt0 < x / 2) {
        L->arr[cnt0] = cnt0 + cnt1;
        cnt0++;
    }
    while (cnt1 < (x + 1) / 2) {
        R->arr[cnt1] = cnt0 + cnt1;
        cnt1++;
    }
    vector_int* nw = (vector_int*)malloc(sizeof(vector_int));
    nw->arr = (int*)malloc((sz_vector_vector_int(res) - 2) * sizeof(int));
    nw->size = 0;
    nw->capacity = sz_vector_vector_int(res) - 2;
    for (int i = 0; i < sz_vector_vector_int(res[sz_vector_vector_int(res) - 2]); i++) {
        pb(nw, L->arr[res[sz_vector_vector_int(res) - 2]->arr[i]]);
    }
    for (int i = 0; i < sz_vector_vector_int(res[sz_vector_vector_int(res) - 1]); i++) {
        pb(nw, R->arr[res[sz_vector_vector_int(res) - 1]->arr[i]]);
    }
    free(res->arr[sz_vector_vector_int(res) - 2].arr);
    free(res->arr[sz_vector_vector_int(res) - 1].arr);
    res->size -= 2;
    pb_vector_vector_int(res, nw);
    if (!fl) break;
    l = r;
}
free(ord_vector->arr);
free(ord_vector);
free(res->arr);
free(res);
return true;
}

void solve(vector* ord) {
    int l = 1, r = n + 1;
    int res = -1;
    while (l <= r) {
        int m = (l + r) / 2;
        if (get(m, 0, ord) == 0) {
            res = m;
            l = m + 1;
        }
        else {
            r = m - 1;
        }
    }
    get(res, 1, ord);
}

int main() {
    FILE* file = fopen("input.txt", "r");
    s = (char*)malloc(N * sizeof(char));
    fscanf(file, "%s", s);
    n = strlen(s);
    int tt = clock();
    int tc;
    fscanf(file, "%d", &tc);
    while (tc--) {
        vector* ord = (vector*)malloc(sizeof(vector));
        ord->arr = (int*)malloc(N * sizeof(int));
        ord->size = 0;
        ord->capacity = N;
        gen(n, ord);
        solve(ord);
        free(ord->arr);
        free(ord);
    }
    free(s);
    fclose(file);
    return 0;
}
