#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <math.h>
#include <stdint.h>

#define MAX_N 100000
#define MOD 998244353

typedef long long ll;
typedef struct {
    int x, v, p;
} pipe;

typedef struct {
    int i;
    int d; // 0: LL, 1: RR, 2: RL
    ll t_n, t_d; // Fraction representation
} event;

typedef struct {
    ll p[4];
    int noLL, noRR, noRL, none;
} node;

pipe pipes[MAX_N];
event evs[MAX_N * 2];
node st[4 * MAX_N];

void setIO() {
    // Placeholder for input/output setup
}

void read_int(int *x) {
    scanf("%d", x);
}

void read_pipe(pipe *p) {
    scanf("%d %d %d", &p->x, &p->v, &p->p);
}

ll gcd(ll a, ll b) {
    while (b) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void add_event(event *ev, int i, int d, ll dx, ll dv) {
    ev->i = i;
    ev->d = d;
    ev->t_n = dx;
    ev->t_d = (d == 0) ? (pipes[i + 1].v + pipes[i].v) : dv;
}

void sort_events(event *evs, int n) {
    // Simple bubble sort for demonstration; replace with a more efficient sort if needed
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (evs[j].t_n * evs[j + 1].t_d > evs[j + 1].t_n * evs[j].t_d) {
                event temp = evs[j];
                evs[j] = evs[j + 1];
                evs[j + 1] = temp;
            }
        }
    }
}

node combine_nodes(node a, node b) {
    if (a.none) return b;
    if (b.none) return a;

    node r = b;
    memset(r.p, 0, sizeof(r.p));
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            int iF = i & 1, iB = (i >> 1) & 1;
            int jF = j & 1, jB = (j >> 1) & 1;
            if (a.noLL && !iB && !jF) continue;
            if (a.noRR && iB && jF) continue;
            if (a.noRL && iB && !jF) continue;
            r.p[iF + 2 * jB] += a.p[i] * b.p[j];
        }
    }
    return r;
}

void segment_tree_set_leaves(int N) {
    for (int i = 0; i < N; i++) {
        ll pR = pipes[i].p * 100; // Assuming 100 is the denominator
        node r = {{1 - pR, 0, 0, pR}, 0, 0, 0, 0};
        r.none = 0;
        st[N + i] = r;
    }
    for (int i = N - 1; i > 0; i--) {
        st[i] = combine_nodes(st[2 * i], st[2 * i + 1]);
    }
}

void segment_tree_replace(int i, node v, int N) {
    st[i += N] = v;
    for (i /= 2; i > 0; i /= 2) {
        st[i] = combine_nodes(st[2 * i], st[2 * i + 1]);
    }
}

node segment_tree_query(int l, int r, int N) {
    node left = {0}, right = {0};
    for (l += N, r += N; l < r; l /= 2, r /= 2) {
        if (l & 1) left = combine_nodes(left, st[l++]);
        if (r & 1) right = combine_nodes(st[--r], right);
    }
    return combine_nodes(left, right);
}

ll small_inv(int n) {
    // Placeholder for small inverse calculation
    return 1; // Replace with actual implementation
}

int main() {
    setIO();

    int N;
    read_int(&N);
    for (int i = 0; i < N; i++) {
        read_pipe(&pipes[i]);
    }

    int ev_count = 0;
    for (int i = 0; i < N - 1; i++) {
        int dx = pipes[i + 1].x - pipes[i].x;
        int dv = pipes[i + 1].v - pipes[i].v;

        add_event(&evs[ev_count++], i, 2, dx, 0); // RL event
        if (dv > 0) add_event(&evs[ev_count++], i, 0, dx, dv); // LL event
        if (dv < 0) add_event(&evs[ev_count++], i, 1, dx, -dv); // RR event
    }

    sort_events(evs, ev_count);

    segment_tree_set_leaves(N);
    ll ans = 0, prob = 1;

    for (int i = 0; i < ev_count; i++) {
        node c = st[evs[i].i];
        switch (evs[i].d) {
            case 0: c.noLL = 1; break;
            case 1: c.noRR = 1; break;
            case 2: c.noRL = 1; break;
        }
        segment_tree_replace(evs[i].i, c, N);

        node u = segment_tree_query(0, N, N);
        ll PROB = 0; // Calculate probability from u.p
        for (int j = 0; j < 4; j++) {
            PROB += u.p[j];
        }

        ans += (prob - PROB) * evs[i].t_n * small_inv(evs[i].t_d);
        prob = PROB;
    }

    printf("%lld\n", ans);

    return 0;
}
