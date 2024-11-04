#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAXN 200000
#define MOD 1000000007

typedef long long ll;

typedef struct {
    bool have_mod;
    int l, r;
    ll value;
    ll mod;
} Node;

typedef struct {
    Node S[MAXN * 4];
    int n;
} TreeSegment;

ll floor_mod(ll a, ll b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

void init(TreeSegment *ts, int tl, int tr, ll *src) {
    int i = ts->n++;
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, tl, mid, src);
        init(ts, mid, tr, src);
        ts->S[i].value = ts->S[ts->S[i].l].value + ts->S[ts->S[i].r].value;
    }
}

void push(TreeSegment *ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value += ts->S[i].mod * (tr - tl);
        if (tl + 1 != tr) {
            ts->S[ts->S[i].l].mod += ts->S[i].mod;
            ts->S[ts->S[i].r].mod += ts->S[i].mod;
        }
        ts->S[i].have_mod = false;
    }
}

ll query(TreeSegment *ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        ll res = 0;
        if (ql < mid) res += query(ts, ts->S[i].l, tl, mid, ql, qr);
        if (mid < qr) res += query(ts, ts->S[i].r, mid, tr, ql, qr);
        return res;
    }
}

void update(TreeSegment *ts, int i, int tl, int tr, int ql, int qr, ll mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        ts->S[i].mod += mod;
        ts->S[i].have_mod = true;
    } else {
        int mid = (tl + tr) / 2;
        if (ql < mid) update(ts, ts->S[i].l, tl, mid, ql, qr, mod);
        if (mid < qr) update(ts, ts->S[i].r, mid, tr, ql, qr, mod);
        ts->S[i].value = ts->S[ts->S[i].l].value + ts->S[ts->S[i].r].value;
    }
}

int main() {
    int n, q;
    scanf("%d %d", &n, &q);
    
    int pos[MAXN], w[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%d", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    TreeSegment ts = { .n = 0 };
    init(&ts, 0, n, w);

    ll subw[MAXN];
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp = { .n = 0 };
    init(&resp, 0, n, subw);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            ll _new = y;
            update(&ts, 0, 0, n, ind, ind + 1, _new);
            update(&resp, 0, 0, n, ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            ll sm = query(&ts, 0, 0, n, l, r);
            int bestL = l; // Placeholder for find_right logic
            ll x = pos[bestL] - bestL + l;

            ll left = 0;
            if (l < bestL) {
                left = query(&resp, 0, 0, n, l, bestL) + query(&ts, 0, 0, n, l, bestL) * (x - l);
            }
            ll right = 0;
            if (bestL < r) {
                right = query(&resp, 0, 0, n, bestL, r) + query(&ts, 0, 0, n, bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }
    return 0;
}
