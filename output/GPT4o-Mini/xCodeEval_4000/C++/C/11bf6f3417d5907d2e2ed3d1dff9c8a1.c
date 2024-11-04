#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAXN 100005
#define MAXLGN 20

typedef struct {
    int f, s;
} pii;

typedef struct {
    pii T[2 * MAXN];
    int N;
    const pii def;
    const pii qdef;

    void init(int size) {
        N = size;
        for (int i = 1; i < 2 * N; i++) {
            T[i] = def;
        }
    }

    void update(int i, pii v) {
        for (i += N - 1; T[i].f = v.f, T[i].s = v.s; i >>= 1;) {
            T[i] = merge(T[i << 1], T[i << 1 | 1]);
        }
    }

    pii query(int l, int r) {
        pii ql = qdef, qr = qdef;
        for (l += N - 1, r += N - 1; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ql = merge(ql, T[l++]);
            if (!(r & 1)) qr = merge(T[r--], qr);
        }
        return merge(ql, qr);
    }

    pii merge(pii l, pii r) {
        return (pii){.f = l.f < r.f ? l.f : r.f, .s = l.s > r.s ? l.s : r.s};
    }
} SegmentTree;

int N, R[MAXN], ans[MAXN];
SegmentTree T[MAXLGN];
pii RANGE[MAXLGN][MAXN * 3];

void read(int *x) {
    scanf("%d", x);
}

void read_array(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }
}

void writeln(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    const pii def = {INT_MAX, -INT_MAX};
    const pii qdef = {INT_MAX, -INT_MAX};

    for (int i = 0; i < MAXLGN; i++) {
        T[i].def = def;
        T[i].qdef = qdef;
        T[i].init(3 * MAXN);
    }

    read(&N);
    read_array(R, N);
    if (N == 1) {
        printf("0\n");
        return 0;
    }

    for (int j = 0; j < 3 * N; j++) {
        RANGE[0][j] = (pii){.f = (j - R[j % N] > 0 ? j - R[j % N] : 0), .s = (j + R[j % N] < 3 * N - 1 ? j + R[j % N] : 3 * N - 1)};
        T[0].update(j, RANGE[0][j]);
    }

    for (int i = 1; i < MAXLGN; i++) {
        for (int j = 0; j < 3 * N; j++) {
            T[i].update(j, T[i - 1].query(RANGE[i - 1][j].f, RANGE[i - 1][j].s));
        }
    }

    for (int i = 0; i < N; i++) {
        ans[i] = 1;
        pii cur = (pii){.f = N + i, .s = N + i};
        for (int j = MAXLGN - 1; j >= 0; j--) {
            pii nxt = T[j].query(cur.f, cur.s);
            if (nxt.s - nxt.f + 1 < N) {
                ans[i] += 1 << j;
                cur = nxt;
            }
        }
    }

    writeln(ans, N);
    return 0;
}
