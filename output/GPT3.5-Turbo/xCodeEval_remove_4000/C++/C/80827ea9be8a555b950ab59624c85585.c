#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define len(arr) (sizeof(arr) / sizeof(arr[0]))
#define scan(arr) for (int i = 0; i < len(arr); i++) scanf("%d", &arr[i])
#define print printf

typedef struct {
    bool have_mod;
    int value;
    int mod;
} Node;

typedef struct {
    int *S;
    int n;
} TreeSegment;

int magic(int a, int b) {
    return a + b;
}

int apply_mod(int value, int mod, int tl, int tr) {
    return mod;
}

int merge_mods(int old, int _new, int tl, int tr) {
    return _new;
}

void init(TreeSegment *ts, int *src) {
    int n = ts->n;
    int *S = ts->S;
    for (int i = 0; i < n; i++) {
        S[i] = src[i];
    }
    for (int i = n - 1; i > 0; i--) {
        S[i] = magic(S[i << 1], S[i << 1 | 1]);
    }
}

int query(TreeSegment *ts, int ql, int qr) {
    int n = ts->n;
    int *S = ts->S;
    int res = 0;
    for (ql += n, qr += n; ql < qr; ql >>= 1, qr >>= 1) {
        if (ql & 1) res = magic(res, S[ql++]);
        if (qr & 1) res = magic(res, S[--qr]);
    }
    return res;
}

void change(TreeSegment *ts, int i, int value) {
    int n = ts->n;
    int *S = ts->S;
    S[i += n] = value;
    for (; i > 1; i >>= 1) {
        S[i >> 1] = magic(S[i], S[i ^ 1]);
    }
}

void update(TreeSegment *ts, int ql, int qr, int mod) {
    int n = ts->n;
    int *S = ts->S;
    for (ql += n, qr += n; ql < qr; ql >>= 1, qr >>= 1) {
        if (ql & 1) S[ql++] += mod;
        if (qr & 1) S[--qr] += mod;
    }
}

int find_right(TreeSegment *ts, int L, int sm) {
    int n = ts->n;
    int *S = ts->S;
    int res = L - 1;
    while (L < n) {
        int m = L << 1;
        if (sm <= S[m]) {
            sm -= S[m];
            L = m;
        } else {
            sm -= S[m];
            L = m + 1;
        }
    }
    return res;
}

int find_left(TreeSegment *ts, int R, int sm) {
    int n = ts->n;
    int *S = ts->S;
    int res = R + 1;
    while (R > 1) {
        int m = R << 1;
        if (sm <= S[m ^ 1]) {
            sm -= S[m ^ 1];
            R = m ^ 1;
        } else {
            sm -= S[m ^ 1];
            R = m;
        }
    }
    return res;
}

int floor_mod(int a, int b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    int *pos = (int*)malloc(n * sizeof(int));
    int *w = (int*)malloc(n * sizeof(int));
    scan(pos);
    scan(w);

    TreeSegment ts;
    ts.n = n;
    ts.S = (int*)malloc((2 * n) * sizeof(int));
    init(&ts, w);

    int *subw = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    resp.n = n;
    resp.S = (int*)malloc((2 * n) * sizeof(int));
    init(&resp, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x;
            int _new = y;
            ind--;
            update(&ts, ind, ind + 1, _new);
            update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x, r = y;
            l--;

            int sm = query(&ts, l, r);

            int bestL = find_right(&ts, l, sm);

            int x = pos[bestL - 1] - bestL + l;

            int left = 0;
            if (l < bestL) {
                left = query(&resp, l, bestL) + query(&ts, l, bestL) * (x - l);
            }
            int right = 0;
            if (bestL < r) {
                right = query(&resp, bestL, r) + query(&ts, bestL, r) * (x - l);
            }
            print("%d\n", floor_mod(left - right, MOD));
        }
    }

    free(pos);
    free(w);
    free(ts.S);
    free(subw);
    free(resp.S);

    return 0;
}
