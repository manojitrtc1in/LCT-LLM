#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <assert.h>
#include <string.h>

#define MOD 998244353
#define INFLL ((1LL << 62) - 1)
#define INF ((1 << 30) - 1)

typedef long long int64;
typedef struct {
    int x;
} ModInt;

ModInt modint_init(int64 y) {
    ModInt m;
    m.x = (y >= 0 ? y % MOD : (MOD - (-y) % MOD) % MOD);
    return m;
}

ModInt modint_add(ModInt a, ModInt b) {
    a.x += b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

ModInt modint_sub(ModInt a, ModInt b) {
    a.x += MOD - b.x;
    if (a.x >= MOD) a.x -= MOD;
    return a;
}

ModInt modint_mul(ModInt a, ModInt b) {
    unsigned long long x = (unsigned long long) a.x * b.x;
    unsigned xh = (unsigned) (x >> 32), xl = (unsigned) x, d, m;
    asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (MOD));
    return (ModInt) {m};
}

ModInt modint_div(ModInt a, ModInt b) {
    // Implementing modular inverse using Extended Euclidean Algorithm
    int a_val = a.x, b_val = MOD, u = 1, v = 0, t;
    while (b_val > 0) {
        t = a_val / b_val;
        int temp = a_val; a_val -= t * b_val; b_val = temp;
        temp = u; u -= t * v; v = temp;
    }
    return modint_mul(a, (ModInt) {u});
}

typedef struct {
    int num, dom;
} Fraction;

Fraction fraction_init(int n, int d) {
    assert(d != 0);
    if (d < 0) {
        n *= -1; d *= -1;
    }
    int gcd = (int) abs(n);
    while (gcd != 0) {
        int temp = d % gcd;
        d = gcd;
        gcd = temp;
    }
    return (Fraction) {n / d, d};
}

typedef struct {
    int right, type;
} Node;

typedef struct {
    Fraction key;
    Node *nodes;
    size_t size;
    size_t capacity;
} Event;

typedef struct {
    Event *events;
    size_t size;
    size_t capacity;
} EventMap;

void event_map_init(EventMap *map) {
    map->size = 0;
    map->capacity = 10;
    map->events = malloc(map->capacity * sizeof(Event));
}

void event_map_add(EventMap *map, Fraction key, Node node) {
    if (map->size == map->capacity) {
        map->capacity *= 2;
        map->events = realloc(map->events, map->capacity * sizeof(Event));
    }
    Event *event = &map->events[map->size++];
    event->key = key;
    event->nodes = malloc(10 * sizeof(Node));
    event->size = 0;
    event->capacity = 10;
    event->nodes[event->size++] = node;
}

void event_map_free(EventMap *map) {
    for (size_t i = 0; i < map->size; i++) {
        free(map->events[i].nodes);
    }
    free(map->events);
}

typedef struct {
    ModInt A[4][4];
} Matrix;

Matrix matrix_init() {
    Matrix mat;
    memset(mat.A, 0, sizeof(mat.A));
    return mat;
}

Matrix matrix_identity() {
    Matrix mat = matrix_init();
    for (int i = 0; i < 4; i++) {
        mat.A[i][i] = modint_init(1);
    }
    return mat;
}

Matrix matrix_mul(Matrix a, Matrix b) {
    Matrix c = matrix_init();
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                c.A[i][j] = modint_add(c.A[i][j], modint_mul(a.A[i][k], b.A[k][j]));
            }
        }
    }
    return c;
}

typedef struct {
    Matrix *seg;
    size_t size;
    size_t capacity;
} SegmentTree;

void segment_tree_init(SegmentTree *tree, size_t n) {
    tree->size = 0;
    tree->capacity = n * 2;
    tree->seg = malloc(tree->capacity * sizeof(Matrix));
}

void segment_tree_set(SegmentTree *tree, int k, Matrix x) {
    tree->seg[k + tree->capacity / 2] = x;
}

void segment_tree_build(SegmentTree *tree) {
    for (int k = tree->capacity / 2 - 1; k > 0; k--) {
        tree->seg[k] = matrix_mul(tree->seg[2 * k], tree->seg[2 * k + 1]);
    }
}

Matrix segment_tree_query(SegmentTree *tree, int a, int b) {
    Matrix L = matrix_identity(), R = matrix_identity();
    for (a += tree->capacity / 2, b += tree->capacity / 2; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = matrix_mul(L, tree->seg[a++]);
        if (b & 1) R = matrix_mul(tree->seg[--b], R);
    }
    return matrix_mul(L, R);
}

void segment_tree_free(SegmentTree *tree) {
    free(tree->seg);
}

int main() {
    int N;
    scanf("%d", &N);
    int *X = malloc(N * sizeof(int));
    int *V = malloc(N * sizeof(int));
    ModInt *P = malloc(N * sizeof(ModInt));
    ModInt *Q = malloc(N * sizeof(ModInt));

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &X[i], &V[i]);
        int p;
        scanf("%d", &p);
        P[i] = modint_div(modint_init(p), modint_init(100));
        Q[i] = modint_sub(modint_init(1), P[i]);
    }

    EventMap ev;
    event_map_init(&ev);
    for (int i = 1; i < N; i++) {
        if (V[i - 1] < V[i]) {
            Node node = {i, 0};
            Fraction key = fraction_init(X[i - 1] - X[i], V[i - 1] - V[i]);
            event_map_add(&ev, key, node);
        }
        Node node = {i, 2};
        Fraction key = fraction_init(X[i] - X[i - 1], V[i - 1] + V[i]);
        event_map_add(&ev, key, node);
        if (V[i - 1] > V[i]) {
            Node node = {i, 1};
            Fraction key = fraction_init(X[i - 1] - X[i], V[i] - V[i - 1]);
            event_map_add(&ev, key, node);
        }
    }

    Matrix e = matrix_identity();
    SegmentTree seg;
    segment_tree_init(&seg, N);
    for (int i = 0; i < N; i++) {
        Matrix u = matrix_identity();
        u.A[0][0] = Q[i];
        u.A[1][0] = Q[i];
        u.A[2][2] = Q[i];
        u.A[3][2] = Q[i];
        u.A[0][1] = P[i];
        u.A[1][1] = P[i];
        u.A[2][3] = P[i];
        u.A[3][3] = P[i];
        segment_tree_set(&seg, i, u);
    }
    segment_tree_build(&seg);

    ModInt ret = modint_init(0);

    for (size_t i = 0; i < ev.size; i++) {
        Event *event = &ev.events[i];
        for (size_t j = 0; j < event->size; j++) {
            Node tt = event->nodes[j];
            Matrix now = seg.seg[tt.right];
            if (tt.type == 0) {
                now.A[0][0] = modint_init(0);
                now.A[0][2] = Q[tt.right];
            } else if (tt.type == 1) {
                now.A[1][1] = modint_init(0);
                now.A[1][3] = P[tt.right];
            } else {
                now.A[1][0] = modint_init(0);
                now.A[1][2] = Q[tt.right];
            }
            segment_tree_set(&seg, tt.right, now);
        }
        Matrix uku = seg.seg[1];
        ModInt sum = modint_add(uku.A[0][2], uku.A[0][3]);
        ret = modint_add(ret, modint_div(modint_init(event->key.num), modint_init(event->key.dom)));
        for (size_t j = 0; j < event->size; j++) {
            Node tt = event->nodes[j];
            Matrix now = seg.seg[tt.right];
            if (tt.type == 0) {
                now.A[0][2] = modint_init(0);
                now.A[2][2] = modint_init(0);
            } else if (tt.type == 1) {
                now.A[1][3] = modint_init(0);
                now.A[3][3] = modint_init(0);
            } else {
                now.A[1][2] = modint_init(0);
                now.A[3][2] = modint_init(0);
            }
            segment_tree_set(&seg, tt.right, now);
        }
    }

    printf("%d\n", ret.x);
    
    free(X);
    free(V);
    free(P);
    free(Q);
    segment_tree_free(&seg);
    event_map_free(&ev);
    return 0;
}
