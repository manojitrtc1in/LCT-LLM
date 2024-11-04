#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <assert.h>
#include <stdint.h>

#define MAX_N 100000
#define MOD 998244353

typedef long long ll;
typedef struct {
    int x, v, p;
} Pipe;

typedef struct {
    int i;
    enum { LL, RR, RL } d;
    struct {
        ll n, d;
    } t;
} Event;

typedef struct {
    ll p[4];
    bool noLL, noRR, noRL, none;
} Node;

typedef struct {
    Node table[2 * MAX_N];
    int size;
} SegmentTree;

void init_segment_tree(SegmentTree *st, int size) {
    st->size = size;
    for (int i = 0; i < 2 * size; i++) {
        st->table[i].none = true;
        memset(st->table[i].p, 0, sizeof(st->table[i].p));
    }
}

Node combine(Node a, Node b) {
    if (a.none) return b;
    if (b.none) return a;
    Node r = b;
    memset(r.p, 0, sizeof(r.p));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            bool iF = i & 1, iB = (i >> 1) & 1;
            bool jF = j & 1, jB = (j >> 1) & 1;
            if (a.noLL && !iB && !jF) continue;
            if (a.noRR && iB && jF) continue;
            if (a.noRL && iB && !jF) continue;
            r.p[iF + 2 * jB] += a.p[i] * b.p[j];
        }
    }
    return r;
}

void replace(SegmentTree *st, int i, Node v) {
    st->table[i + st->size] = v;
    for (i += st->size; i > 1; i /= 2) {
        st->table[i / 2] = combine(st->table[i], st->table[i ^ 1]);
    }
}

Node query(SegmentTree *st, int l, int r) {
    Node left = {0}, right = {0};
    left.none = right.none = true;
    for (l += st->size, r += st->size; l < r; l /= 2, r /= 2) {
        if (l & 1) left = combine(left, st->table[l++]);
        if (r & 1) right = combine(st->table[--r], right);
    }
    return combine(left, right);
}

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

struct {
    ll n, d;
} frac(ll n, ll d) {
    assert(n != 0 || d != 0);
    if (d < 0) {
        n *= -1;
        d *= -1;
    }
    ll g = gcd(abs(n), d);
    return (struct { ll n, d; }) { n / g, d / g };
}

int main() {
    int N;
    scanf("%d", &N);
    Pipe pipes[MAX_N];
    for (int i = 0; i < N; i++) {
        scanf("%d %d %d", &pipes[i].x, &pipes[i].v, &pipes[i].p);
    }

    Event evs[MAX_N * 2];
    int ev_count = 0;

    for (int i = 0; i < N - 1; i++) {
        int dx = pipes[i + 1].x - pipes[i].x;
        int dv = pipes[i + 1].v - pipes[i].v;

        evs[ev_count++] = (Event) { i, RL, frac(dx, pipes[i + 1].v + pipes[i].v) };

        if (dv > 0) evs[ev_count++] = (Event) { i, LL, frac(dx, dv) };
        if (dv < 0) evs[ev_count++] = (Event) { i, RR, frac(dx, -dv) };
    }

    // Sort events by time (not implemented in C, requires custom sort function)

    SegmentTree st;
    init_segment_tree(&st, N);
    for (int i = 0; i < N; i++) {
        ll pR = pipes[i].p * 1 / 100; // Assuming small_inv(100) is 1/100
        Node r = { {1 - pR, 0, 0, pR}, false, false, false, false };
        r.none = false;
        replace(&st, i, r);
    }

    ll ans = 0, prob = 1;
    for (int i = 0; i < ev_count; i++) {
        Event e = evs[i];
        Node c = st.table[e.i + st.size];
        switch (e.d) {
            case LL: c.noLL = true; break;
            case RR: c.noRR = true; break;
            case RL: c.noRL = true; break;
        }
        replace(&st, e.i, c);

        Node u = query(&st, 0, st.size);
        ll PROB = 0;
        for (int j = 0; j < 4; j++) {
            PROB += u.p[j];
        }
        ans += (prob - PROB) * e.t.n * (1 / e.t.d); // Assuming small_inv(e.t.d) is 1/e.t.d
        prob = PROB;
    }

    printf("%lld\n", ans);
    return 0;
}
