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

bool intersects(int tl, int tr, int ql, int qr) {
    return !(tr <= ql || qr <= tl);
}

void init(TreeSegment *ts, const ll *src, int n) {
    ts->n = n;
    for (int i = 0; i < 2 * n + 1; i++) {
        ts->S[i].have_mod = false;
        ts->S[i].value = 0;
        ts->S[i].mod = 0;
    }
    // Initialize the segment tree
    for (int i = 0; i < n; i++) {
        ts->S[i + n].value = src[i];
    }
    for (int i = n - 1; i > 0; i--) {
        ts->S[i].value = ts->magic(ts->S[i * 2].value, ts->S[i * 2 + 1].value);
    }
}

ll query(TreeSegment *ts, int l, int r) {
    // Implement the query logic
    return 0; // Placeholder
}

void update(TreeSegment *ts, int l, int r, ll mod) {
    // Implement the update logic
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
    ts.magic = [](ll a, ll b) { return a + b; };
    ts.apply_mod = [](ll value, ll mod, int tl, int tr) { return mod; };
    ts.merge_mods = [](ll old, ll _new, int tl, int tr) { return _new; };
    init(&ts, w, n);

    for (int i = 0; i < q; i++) {
        int x, y;
        scanf("%d %d", &x, &y);
        if (x < 0) {
            int ind = -x - 1;
            ll _new = y;
            update(&ts, ind, ind + 1, _new);
        } else {
            int l = x - 1, r = y;
            ll sm = query(&ts, l, r);
            // Additional logic for finding bestL and calculating left and right
            ll left = 0; // Placeholder
            ll right = 0; // Placeholder
            printf("%lld\n", floor_mod(left - right, MOD));
        }
    }
    return 0;
}
