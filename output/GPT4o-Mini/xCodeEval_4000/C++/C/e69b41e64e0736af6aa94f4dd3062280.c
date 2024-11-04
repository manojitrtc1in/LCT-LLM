#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

#define MAXMEM (200 * 1000 * 1024)
char _memory[MAXMEM];
size_t _ptr = 0;

void* my_malloc(size_t _x) {
    _ptr += _x; 
    assert(_ptr < MAXMEM); 
    return _memory + _ptr - _x; 
}

void my_free(void* ptr) {}

typedef long long ll;
typedef struct {
    ll value;
    ll mod;
    bool have_mod;
    int l, r;
} Node;

typedef struct {
    Node* S;
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

bool intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

int create_node(TreeSegment* ts) {
    ts->S = (Node*)my_malloc(sizeof(Node) * (ts->n + 1));
    return ts->n++;
}

ll get_value(TreeSegment* ts, int i, int tl, int tr) {
    if (!ts->S[i].have_mod) return ts->S[i].value;
    return ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
}

void recalc_value(TreeSegment* ts, int i, int tl, int tr) {
    if (tl + 1 != tr) {
        int mid = (tl + tr) / 2;
        ts->S[i].value = ts->magic(
            get_value(ts, ts->S[i].l, tl, mid),
            get_value(ts, ts->S[i].r, mid, tr)
        );
    }
}

void add_mod(TreeSegment* ts, int i, int tl, int tr, ll sub) {
    if (ts->S[i].have_mod) {
        ts->S[i].mod = ts->merge_mods(ts->S[i].mod, sub, tl, tr);
    } else {
        ts->S[i].mod = sub;
        ts->S[i].have_mod = true;
    }
}

void push(TreeSegment* ts, int i, int tl, int tr) {
    if (ts->S[i].have_mod) {
        ts->S[i].value = ts->apply_mod(ts->S[i].value, ts->S[i].mod, tl, tr);
        if (tl + 1 != tr) {
            int mid = (tl + tr) / 2;
            add_mod(ts, ts->S[i].l, tl, mid, ts->S[i].mod);
            add_mod(ts, ts->S[i].r, mid, tr, ts->S[i].mod);
        }
        ts->S[i].have_mod = false;
    }
}

int init(TreeSegment* ts, int tl, int tr, ll* src) {
    int i = create_node(ts);
    if (tl + 1 == tr) {
        ts->S[i].value = src[tl];
    } else {
        int mid = (tl + tr) / 2;
        ts->S[i].l = init(ts, tl, mid, src);
        ts->S[i].r = init(ts, mid, tr, src);
        recalc_value(ts, i, tl, tr);
    }
    return i;
}

ll query(TreeSegment* ts, int i, int tl, int tr, int ql, int qr) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        return ts->S[i].value;
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr) && intersects(mid, tr, ql, qr)) {
            return ts->magic(
                query(ts, ts->S[i].l, tl, mid, ql, qr),
                query(ts, ts->S[i].r, mid, tr, ql, qr)
            );
        } else if (intersects(tl, mid, ql, qr)) {
            return query(ts, ts->S[i].l, tl, mid, ql, qr);
        } else if (intersects(mid, tr, ql, qr)) {
            return query(ts, ts->S[i].r, mid, tr, ql, qr);
        } else {
            assert(false);
        }
    }
}

void update(TreeSegment* ts, int i, int tl, int tr, int ql, int qr, ll mod) {
    push(ts, i, tl, tr);
    if (ql <= tl && tr <= qr) {
        add_mod(ts, i, tl, tr, mod);
    } else {
        int mid = (tl + tr) / 2;
        if (intersects(tl, mid, ql, qr)) {
            update(ts, ts->S[i].l, tl, mid, ql, qr, mod);    
        }
        if (intersects(mid, tr, ql, qr)) {
            update(ts, ts->S[i].r, mid, tr, ql, qr, mod);
        }
        recalc_value(ts, i, tl, tr);
    }
}

ll magic_sum(ll a, ll b) {
    return (a + b) % (1000000007);
}

ll apply_mod_identity(ll value, ll mod, int tl, int tr) {
    return mod;
}

ll merge_mod_identity(ll old, ll _new, int tl, int tr) {
    return _new;
}

int main() {
    int n, q;
    scanf("%lld %lld", &n, &q);
    ll* pos = (ll*)malloc(n * sizeof(ll));
    ll* w = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        scanf("%lld", &pos[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%lld", &w[i]);
    }

    TreeSegment ts;
    ts.n = 0;
    ts.S = (Node*)my_malloc(sizeof(Node) * n);
    ts.magic = magic_sum;
    ts.apply_mod = apply_mod_identity;
    ts.merge_mods = merge_mod_identity;
    init(&ts, 0, n, w);

    ll* subw = (ll*)malloc(n * sizeof(ll));
    for (int i = 0; i < n; i++) {
        subw[i] = (w[i] * (i - pos[i])) % (1000000007);
    }

    TreeSegment resp;
    resp.n = 0;
    resp.S = (Node*)my_malloc(sizeof(Node) * n);
    resp.magic = magic_sum;
    resp.apply_mod = apply_mod_identity;
    resp.merge_mods = merge_mod_identity;
    init(&resp, 0, n, subw);

    for (int i = 0; i < q; i++) {
        ll x, y;
        scanf("%lld %lld", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            ll _new = y;
            ts.update(&ts, ind, ind + 1, _new);
            resp.update(&resp, ind, ind + 1, (_new * (ind - pos[ind])) % (1000000007));
        } else {
            int l = x - 1, r = y;
            ll sm = ts.query(&ts, 0, 0, ts.n, l, r);

            int bestL = ts.find_right(l, [sm](ll x) {
                return x * 2 >= sm;
            }, 0);

            ll x = pos[bestL] - bestL + l;

            ll left = 0;
            if (l < bestL) {
                left = resp.query(&resp, l, bestL) + ts.query(&ts, l, bestL) * (x - l);
            }
            ll right = 0;
            if (bestL < r) {
                right = resp.query(&resp, bestL, r) + ts.query(&ts, bestL, r) * (x - l);
            }
            printf("%lld\n", floor_mod(left - right, 1000000007));
        }
    }

    free(pos);
    free(w);
    free(subw);
    free(ts.S);
    free(resp.S);
    return 0;
}
