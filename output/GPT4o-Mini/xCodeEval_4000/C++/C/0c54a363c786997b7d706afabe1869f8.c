#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAXN 100000
#define MOD 1000000007

typedef long long ll;

typedef struct {
    bool have_mod;
    ll value;
    ll mod;
} Node;

typedef struct {
    Node S[2 * MAXN + 1];
    int n;
} TreeSegment;

ll floor_mod(ll a, ll b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

void init(TreeSegment *ts, ll *src, int n) {
    ts->n = n;
    for (int i = 0; i < 2 * n; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = 0;
        ts->S[i].mod = 0;
    }
    for (int i = 0; i < n; i++) {
        ts->S[i + n].value = src[i];
    }
    for (int i = n - 1; i > 0; i--) {
        ts->S[i].value = ts->S[i * 2].value + ts->S[i * 2 + 1].value;
    }
}

void push(TreeSegment *ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value += ts->S[i].mod * (tr - tl);
        if (tl + 1 != tr) {
            ts->S[i * 2].mod += ts->S[i].mod;
            ts->S[i * 2 + 1].mod += ts->S[i].mod;
        }
        ts->S[i].have_mod = false;
    }
}

ll query(TreeSegment *ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    }
    int mid = (tl + tr) / 2;
    ll res = 0;
    if (ql < mid) {
        res += query(ts, i * 2, tl, mid, ql, qr);
    }
    if (qr > mid) {
        res += query(ts, i * 2 + 1, mid, tr, ql, qr);
    }
    return res;
}

void update(TreeSegment *ts, int i, int tl, int tr, int ql, int qr, ll addend) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        ts->S[i].mod += addend;
        push(ts, i, tl, tr);
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) {
            update(ts, i * 2, tl, mid, ql, qr, addend);
        }
        if (qr > mid) {
            update(ts, i * 2 + 1, mid, tr, ql, qr, addend);
        }
        ts->S[i].value = ts->S[i * 2].value + ts->S[i * 2 + 1].value;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    ll pos[MAXN], w[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
    }

    TreeSegment ts;
    init(&ts, w, n);

    ll subw[MAXN];
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp;
    init(&resp, subw, n);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            ll _new = y;
            update(&ts, 1, 0, n, ind, ind + 1, _new);
            update(&resp, 1, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            ll sm = query(&ts, 1, 0, n, l, r);
            int bestL = l;
            while (bestL < r && query(&ts, 1, 0, n, l, bestL + 1) * 2 < sm) {
                bestL++;
            }
            ll x_val = pos[bestL] - bestL + l;

            ll left = 0;
            if (l < bestL) {
                left = query(&resp, 1, 0, n, l, bestL) + query(&ts, 1, 0, n, l, bestL) * (x_val - l);
            }
            ll right = 0;
            if (bestL < r) {
                right = query(&resp, 1, 0, n, bestL, r) + query(&ts, 1, 0, n, bestL, r) * (x_val - l);
            }
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }
    return 0;
}
