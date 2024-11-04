#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define REP(i, n) for(int i = 0; i < (n); i++)
#define FOR_1(i, a, b) for(int i = (a); i <= (b); i++)
#define PB push_back
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
typedef double DB;
typedef int VI;
typedef struct {
    int *data;
    int size;
    int capacity;
} Vector;

void vector_init(Vector *v) {
    v->size = 0;
    v->capacity = 10;
    v->data = (int *)malloc(v->capacity * sizeof(int));
}

void vector_push_back(Vector *v, int value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int *)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size++] = value;
}

void vector_clear(Vector *v) {
    v->size = 0;
}

void vector_free(Vector *v) {
    free(v->data);
}

int D[3 * 360360];
Vector adj[360360];

inline int id1(int a, int b) {
    return a * b / __gcd(a, b);
}

LL a, b, k; 
int aa, bb, lcm;

inline int f(int s, int t) {
    return D[t];
}

void bfs() {
    int s = aa; 
    memset(D, 0x3f, sizeof(D)); 
    D[0] = 0;

    REP(i, 3 * lcm) {
        int u = (s - i) % lcm; 
        if (u < 0) u += lcm;

        int Du = D[i];
        if (Du == 0x3f3f3f3f) continue;

        for (int ii = 0; ii < SZ(adj[u]); ii++) {
            checkMin(D[i + adj[u].data[ii]], Du + 1);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    scanf("%lld %lld %lld", &a, &b, &k);

    lcm = 1; 
    FOR_1(i, 2, k) {
        lcm = id1(lcm, i);
    }

    REP(i, lcm) {
        vector_push_back(&adj[i], 1);
        FOR_1(j, 2, k) if (i % j) vector_push_back(&adj[i], i % j);
    }

    LL tt = (a - b) / lcm;
    aa = a % lcm; 
    bb = b % lcm;

    LL step = 0x3f3f3f3f; 
    int h;

    bfs();

    bb = (aa - bb + 3 * lcm) % lcm;

    tt *= (LL)(D[bb + lcm] - D[bb]);
    printf("%d\n", D[bb] + tt);

    for (int i = 0; i < lcm; i++) {
        vector_free(&adj[i]);
    }

    return 0;
}
