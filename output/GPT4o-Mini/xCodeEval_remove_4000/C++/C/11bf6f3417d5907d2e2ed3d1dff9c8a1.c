#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdint.h>
#include <stdbool.h>

#define MAXN 100005
#define id0 20

typedef struct {
    int f, s;
} pii;

pii RANGE[id0][3 * MAXN];
int R[MAXN], ans[MAXN];

typedef struct {
    pii T[2 * MAXN];
    int N;
    const pii def;
    const pii qdef;

    void (*init)(struct SegmentTree_SAM_RQ*, int);
    void (*update)(struct SegmentTree_SAM_RQ*, int, pii);
    pii (*query)(struct SegmentTree_SAM_RQ*, int, int);
} SegmentTree_SAM_RQ;

void merge(pii l, pii r, pii* result) {
    result->f = (l.f < r.f) ? l.f : r.f;
    result->s = (l.s > r.s) ? l.s : r.s;
}

void applyVal(pii* l, pii r) {
    *l = r;
}

void init(SegmentTree_SAM_RQ* tree, int size) {
    tree->N = size;
    for (int i = 1; i < 2 * tree->N; i++) {
        tree->T[i] = tree->def;
    }
}

void update(SegmentTree_SAM_RQ* tree, int i, pii v) {
    for (i += tree->N - 1; i > 0; i >>= 1) {
        applyVal(&tree->T[i], v);
        merge(tree->T[i << 1], tree->T[i << 1 | 1], &tree->T[i]);
    }
}

pii query(SegmentTree_SAM_RQ* tree, int l, int r) {
    pii ql = tree->qdef, qr = tree->qdef;
    for (l += tree->N - 1, r += tree->N - 1; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) {
            merge(ql, tree->T[l++], &ql);
        }
        if (!(r & 1)) {
            merge(tree->T[r--], qr, &qr);
        }
    }
    pii result;
    merge(ql, qr, &result);
    return result;
}

int main() {
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++) {
        scanf("%d", &R[i]);
    }
    
    if (N == 1) {
        printf("0\n");
        return 0;
    }

    SegmentTree_SAM_RQ T[id0];
    for (int i = 0; i < id0; i++) {
        T[i].def = (pii){INT_MAX, -INT_MAX};
        T[i].qdef = (pii){INT_MAX, -INT_MAX};
        T[i].init = init;
        T[i].update = update;
        T[i].query = query;
        T[i].init(&T[i], 3 * N);
    }

    for (int j = 0; j < 3 * N; j++) {
        RANGE[0][j] = (pii){max(0, j - R[j % N]), min(3 * N - 1, j + R[j % N])};
        T[0].update(&T[0], j, RANGE[0][j]);
    }

    for (int i = 1; i < id0; i++) {
        for (int j = 0; j < 3 * N; j++) {
            RANGE[i][j] = T[i - 1].query(&T[i - 1], RANGE[i - 1][j].f, RANGE[i - 1][j].s);
            T[i].update(&T[i], j, RANGE[i][j]);
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i] = 1;
        pii cur = (pii){N + i, N + i};
        for (int j = id0 - 1; j >= 0; j--) {
            pii nxt = T[j].query(&T[j], cur.f, cur.s);
            if (nxt.s - nxt.f + 1 < N) {
                ans[i] += 1 << j;
                cur = nxt;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
