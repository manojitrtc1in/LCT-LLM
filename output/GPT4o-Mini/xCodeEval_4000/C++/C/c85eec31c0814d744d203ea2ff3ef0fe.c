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
    ll value;
    ll mod;
} Node;

typedef struct {
    Node S[2 * MAXN + 1];
    int n;
    ll (*magic)(ll, ll);
    ll (*apply_mod)(ll, ll, int, int);
    ll (*merge_mods)(ll, ll, int, int);
} TreeSegment;

ll floor_mod(ll a, ll b) {
    if (a % b == 0) return 0;
    if (a >= 0 && b >= 0) return a % b;
    if (a <= 0 && b <= 0) return a % b;
    return abs(b) - (abs(a) % abs(b));
}

bool __intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

ll __get_value(TreeSegment *ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void __recalc_value(TreeSegment *ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = ts->magic(
            __get_value(ts, i + 1, tl, mid),
            __get_value(ts, i + (mid - tl) * 2, mid, tr)
        );
    }
}

void __add_mod(TreeSegment *ts, int i, int tl, int tr, ll sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = true;
    }
}

void __push(TreeSegment *ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            __add_mod(ts, i + 1, tl, mid, ts->S[i].mod);
            __add_mod(ts, i + (mid - tl) * 2, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = false;
    }
}

void init(TreeSegment *ts, int i, int tl, int tr, ll *src) {
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        init(ts, i + 1, tl, mid, src);
        init(ts, i + (mid - tl) * 2, mid, tr, src);
        __recalc_value(ts, i, tl, tr);
    }
}

ll __query(TreeSegment *ts, int i, int tl, int tr, int ql, int qr) {
    __push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr) && __intersects(mid, tr, ql, qr)) {
            return ts->magic(
                __query(ts, i + 1, tl, mid, ql, qr),
                __query(ts, i + (mid - tl) * 2, mid, tr, ql, qr)
            );
        } else if (__intersects(tl, mid, ql, qr)) {
            return __query(ts, i + 1, tl, mid, ql, qr);
        } else {
            return __query(ts, i + (mid - tl) * 2, mid, tr, ql, qr);
        }
    }
}

void __change(TreeSegment *ts, int i, int tl, int tr, int j, ll _new) {
    __push(ts, i, tl, tr);
    if (tl + 1 == tr) {
        ts->S[i].value = _new;
    } else {
        int m = (tl + tr) / 2;
        if (j < m) {
            __change(ts, ts->S[i].l, tl, m, j, _new);
        } else {
            __change(ts, ts->S[i].r, m, tr, j, _new);
        }
        __recalc_value(ts, i, tl, tr);
    }
}

void __update(TreeSegment *ts, int i, int tl, int tr, int ql, int qr, ll mod) {
    __push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        __add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (__intersects(tl, mid, ql, qr)) {
            __update(ts, i + 1, tl, mid, ql, qr, mod);
        }
        if (__intersects(mid, tr, ql, qr)) {
            __update(ts, i + (mid - tl) * 2, mid, tr, ql, qr, mod);
        }
        __recalc_value(ts, i, tl, tr);
    }
}

TreeSegment create_tree_segment(int n, ll def, ll (*magic)(ll, ll), ll (*apply_mod)(ll, ll, int, int), ll (*merge_mods)(ll, ll, int, int)) {
    TreeSegment ts;
    ts.n = n;
    ts.magic = magic;
    ts.apply_mod = apply_mod;
    ts.merge_mods = merge_mods;
    ll *src = (ll *)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        src[i] = def;
    }
    init(&ts, 0, 0, n, src);
    free(src);
    return ts;
}

int main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    ll pos[MAXN], w[MAXN];
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
    }

    TreeSegment ts = create_tree_segment(n, 0, [](ll a, ll b) { return a + b; }, [](ll value, ll mod, int, int) { return mod; }, [](ll old, ll _new, int, int) { return _new; });

    ll subw[MAXN];
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % MOD;
    }

    TreeSegment resp = create_tree_segment(n, 0, [](ll a, ll b) { return (a + b) % MOD; }, [](ll value, ll mod, int, int) { return mod; }, [](ll old, ll _new, int, int) { return _new; });

    for (int i = 0; i < q; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            ll _new = y;
            ts.update(ind, ind + 1, _new);
            resp.update(ind, ind + 1, (_new * (ind - pos[ind])) % MOD);
        } else {
            int l = x - 1, r = y;
            ll sm = ts.query(l, r);
            int bestL = ts.find_right(l, [sm](ll x) { return x * 2 >= sm; }, 0);
            ll x = pos[bestL] - bestL + l;

            ll left = 0;
            if (l < bestL) {
                left = resp.query(l, bestL) + ts.query(l, bestL) * (x - l);
            }
            ll right = 0;
            if (bestL < r) {
                right = resp.query(bestL, r) + ts.query(bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }
    return 0;
}
