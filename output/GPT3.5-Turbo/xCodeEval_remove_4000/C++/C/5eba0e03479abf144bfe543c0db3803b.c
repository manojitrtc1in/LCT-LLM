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
    int first;
    int second;
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

int sz(vector* v) {
    return v->size;
}

void push_back(vector* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size++] = value;
}

void vector_init(vector* v, int capacity) {
    v->arr = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_vector_int_init(vector_vector_int* v, int capacity) {
    v->arr = (int*)malloc(capacity * sizeof(int));
    v->size = 0;
    v->capacity = capacity;
}

void vector_vector_int_push_back(vector_vector_int* v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->arr = (int*)realloc(v->arr, v->capacity * sizeof(int));
    }
    v->arr[v->size++] = value;
}

void ostream_operator_left_shift_pair_int_int(FILE* out, pair* a) {
    fprintf(out, "(%d, %d)", a->first, a->second);
}

void ostream_operator_left_shift_vector_int(FILE* out, vector* v) {
    fprintf(out, "[");
    for (int i = 0; i < v->size; i++) {
        if (i) fprintf(out, ", ");
        fprintf(out, "%d", v->arr[i]);
    }
    fprintf(out, "]");
}

int rnd(int seed) {
    return seed;
}

const int INF = 1000000000;
const li INF64 = 1000000000000000000;
const int MOD = 1000000007;
const ld EPS = 1e-9;
const ld PI = 3.14159265358979323846;

char s[N];
int n;

int read() {
    if (scanf("%s", s) != 1)
        return 0;
    n = strlen(s);
    return 1;
}

vector ord;

void gen(int n) {
    if (n == 1) {
        push_back(&ord, 1);
        return;
    }
    gen(n / 2);
    gen((n + 1) / 2);
    push_back(&ord, n);
}

void solve() {
    for (int t = n + 1; t >= 1; --t) {
        vector_init(&ord, 2 * n + 13);
        gen(t);
        int l = 0;
        int pr = 0;
        for (int i = 0; i < ord.size; i++) {
            int x = ord.arr[i];
            if (x == 1) {
                ++pr;
                continue;
            }
            int cnt0 = 0, cnt1 = 0;
            int r = l;
            int fl = 0;
            while (r < n) {
                if (s[r++] == '0') {
                    ++cnt0;
                    if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                        fl = 1;
                        break;
                    }
                }
                else {
                    ++cnt1;
                    if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                        fl = 1;
                        break;
                    }
                }
            }
            if (!fl) break;
            l = r;
            ++pr;
        }
        if (l != n || pr != ord.size) continue;
        vector_vector_int res;
        vector_vector_int_init(&res, 2 * n + 13);
        l = 0;
        for (int i = 0; i < ord.size; i++) {
            int x = ord.arr[i];
            if (x == 1) {
                vector_vector_int_push_back(&res, 0);
                continue;
            }
            int cnt0 = 0, cnt1 = 0;
            int r = l;
            int fl = 0;
            vector L, R;
            vector_init(&L, x / 2);
            vector_init(&R, (x + 1) / 2);
            while (r < n) {
                if (s[r++] == '0') {
                    L.arr[cnt0] = cnt0 + cnt1;
                    ++cnt0;
                    if (cnt0 == x / 2 && cnt1 < (x + 1) / 2) {
                        fl = 1;
                        break;
                    }
                }
                else {
                    R.arr[cnt1] = cnt0 + cnt1;
                    ++cnt1;
                    if (cnt1 == (x + 1) / 2 && cnt0 < x / 2) {
                        fl = 1;
                        break;
                    }
                }
            }
            while (cnt0 < x / 2) L.arr[cnt0] = cnt0 + cnt1, ++cnt0;
            while (cnt1 < (x + 1) / 2) R.arr[cnt1] = cnt0 + cnt1, ++cnt1;
            vector nw;
            vector_init(&nw, L.size + R.size);
            for (int i = 0; i < res.size - 2; i++) {
                push_back(&nw, L.arr[res.arr[i]]);
            }
            for (int i = 0; i < res.size - 1; i++) {
                push_back(&nw, R.arr[res.arr[i]]);
            }
            res.size -= 2;
            vector_vector_int_push_back(&res, nw.size);
            if (!fl) break;
            l = r;
        }
        printf("%d\n", t);
        for (int i = 0; i < res.arr[0]; i++) {
            printf("%d ", res.arr[i] + 1);
        }
        puts("");
        break;
    }
}

int main() {
    freopen("input.txt", "r", stdin);

    int tt = clock();

    int tc;
    scanf("%d", &tc);
    while (tc--) {
        while (read()) {
            solve();
        }
    }

    return 0;
}
