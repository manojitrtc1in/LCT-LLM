#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 100005
#define MAXLGN 20

typedef struct {
    int f;
    int s;
} pii;

typedef struct {
    int N;
    pii T[MAXN * 6];
    pii def;
    pii qdef;
} SegmentTree_SAM_RQ;

SegmentTree_SAM_RQ T[MAXLGN];
pii RANGE[MAXLGN][MAXN * 6];

pii mp(int a, int b) {
    pii p;
    p.f = a;
    p.s = b;
    return p;
}

pii merge(pii l, pii r) {
    pii p;
    p.f = (l.f < r.f) ? l.f : r.f;
    p.s = (l.s > r.s) ? l.s : r.s;
    return p;
}

pii applyVal(pii l, pii r) {
    return r;
}

void init(SegmentTree_SAM_RQ *tree, int size) {
    tree->N = size;
    for (int i = 1; i < 2 * tree->N; i++) {
        tree->T[i] = tree->def;
    }
}

void update(SegmentTree_SAM_RQ *tree, int i, pii v) {
    for (i += tree->N - 1; i > 0; i >>= 1) {
        tree->T[i] = applyVal(tree->T[i], v);
    }
}

pii query(SegmentTree_SAM_RQ *tree, int l, int r) {
    pii ql = tree->qdef;
    pii qr = tree->qdef;
    for (l += tree->N, r += tree->N; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ql = merge(ql, tree->T[l++]);
        }
        if (!(r & 1)) {
            qr = merge(tree->T[r--], qr);
        }
    }
    return merge(ql, qr);
}

int main() {
    int N;
    int R[MAXN];
    int ans[MAXN];
    int i, j;

    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        scanf("%d", &R[i]);
    }
    if (N == 1) {
        printf("0\n");
        return 0;
    }
    for (i = 0; i < MAXLGN; i++) {
        init(&T[i], 3 * N);
    }
    for (j = 0; j < 3 * N; j++) {
        update(&T[0], j, RANGE[0][j] = mp((j - R[j % N] < 0) ? 0 : j - R[j % N], (j + R[j % N] >= 3 * N) ? 3 * N - 1 : j + R[j % N]));
    }
    for (i = 1; i < MAXLGN; i++) {
        for (j = 0; j < 3 * N; j++) {
            update(&T[i], j, RANGE[i][j] = query(&T[i - 1], RANGE[i - 1][j].f, RANGE[i - 1][j].s));
        }
    }
    for (i = 0; i < N; i++) {
        ans[i] = 1;
        pii cur = mp(N + i, N + i);
        for (j = MAXLGN - 1; j >= 0; j--) {
            pii nxt = query(&T[j], cur.f, cur.s);
            if (nxt.s - nxt.f + 1 < N) {
                ans[i] += 1 << j;
                cur = nxt;
            }
        }
    }
    for (i = 0; i < N; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");
    return 0;
}
