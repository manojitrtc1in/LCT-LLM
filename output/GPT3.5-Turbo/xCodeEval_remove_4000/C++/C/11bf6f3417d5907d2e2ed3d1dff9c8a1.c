#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAXN 100005
#define id0 20

typedef struct {
    int f;
    int s;
} pii;

typedef struct {
    int N;
    pii T[2 * MAXN];
    pii def;
    pii qdef;
} SegmentTree_SAM_RQ;

SegmentTree_SAM_RQ T[id0];
pii RANGE[id0][3 * MAXN];

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

void init(SegmentTree_SAM_RQ* st, int size) {
    st->N = size;
    for (int i = 1; i < 2 * st->N; i++) {
        st->T[i] = st->def;
    }
}

void update(SegmentTree_SAM_RQ* st, int i, pii v) {
    for (i += st->N, st->T[i] = applyVal(st->T[i], v); i >>= 1;) {
        st->T[i] = merge(st->T[i << 1], st->T[i << 1 | 1]);
    }
}

pii query(SegmentTree_SAM_RQ* st, int l, int r) {
    pii ql = st->qdef, qr = st->qdef;
    for (l += st->N, r += st->N; l <= r; l >>= 1, r >>= 1) {
        if (l & 1) {
            ql = merge(ql, st->T[l++]);
        }
        if (!(r & 1)) {
            qr = merge(st->T[r--], qr);
        }
    }
    return merge(ql, qr);
}

void readInt(int* x) {
    scanf("%d", x);
}

void readIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void writeInt(int x) {
    printf("%d", x);
}

void writeIntArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int N;
    int R[MAXN], ans[MAXN];

    readInt(&N);
    readIntArray(R, N);
    if (N == 1) {
        writeInt(0);
        printf("\n");
        return 0;
    }
    for (int i = 0; i < id0; i++) {
        init(&T[i], 3 * N);
    }
    for (int j = 0; j < 3 * N; j++) {
        update(&T[0], j, RANGE[0][j] = mp((j - R[j % N] >= 0) ? (j - R[j % N]) : 0, (j + R[j % N] < 3 * N) ? (j + R[j % N]) : (3 * N - 1)));
    }
    for (int i = 1; i < id0; i++) {
        for (int j = 0; j < 3 * N; j++) {
            update(&T[i], j, RANGE[i][j] = query(&T[i - 1], RANGE[i - 1][j].f, RANGE[i - 1][j].s));
        }
    }
    for (int i = 0; i < N; i++) {
        ans[i] = 1;
        pii cur = mp(N + i, N + i);
        for (int j = id0 - 1; j >= 0; j--) {
            pii nxt = query(&T[j], cur.f, cur.s);
            if (nxt.s - nxt.f + 1 < N) {
                ans[i] += 1 << j;
                cur = nxt;
            }
        }
    }
    writeIntArray(ans, N);
    return 0;
}
