#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

typedef long long ll;
typedef double db;
typedef long double ldb;

#define C 20
#define INF 1000000000
#define LINF 1000000000000000000
#define M 1000000007

typedef struct {
    int value;
} Modular;

Modular create_modular(ll v) {
    Modular m;
    m.value = v % M;
    if (m.value < 0) m.value += M;
    return m;
}

Modular modular_add(Modular a, Modular b) {
    return create_modular(a.value + b.value);
}

Modular modular_sub(Modular a, Modular b) {
    return create_modular(a.value - b.value);
}

Modular modular_mul(Modular a, Modular b) {
    return create_modular((ll)a.value * b.value);
}

Modular modular_div(Modular a, Modular b) {
    return modular_mul(a, modular_inv(b));
}

Modular modular_inv(Modular a) {
    return modular_pow(a, M - 2);
}

Modular modular_pow(Modular a, ll k) {
    Modular res = create_modular(1);
    while (k) {
        if (k & 1) res = modular_mul(res, a);
        a = modular_mul(a, a);
        k >>= 1;
    }
    return res;
}

int G[C][C], masks[C];
bool dp[1 << C], vis[C];
int mask;

void dfs(int v) {
    vis[v] = true;
    mask |= 1 << v;
    // Assuming cur is a dynamic array or similar structure
    // cur.push_back(v); // Placeholder for pushing to a dynamic array
    for (int s = 0; s < C; s++) {
        if (G[v][s] && !vis[s]) {
            dfs(s);
        }
    }
}

int count() {
    int res = 0;
    for (int m = 0; m < (1 << C); m++) {
        for (int v = 0; v < C; v++) {
            if (m & (1 << v)) {
                dp[m] |= dp[m ^ (1 << v)] && ((m & masks[v] & mask) == 0);
            }
        }
        if (dp[m]) {
            // Assuming pct is defined elsewhere
            // res = max(res, pct(m)); // Placeholder for max calculation
        }
    }
    return res;
}

int solve() {
    int n;
    scanf("%d", &n);
    char s[n + 1], t[n + 1];
    scanf("%s", s);
    scanf("%s", t);

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i]) {
            int a = s[i] - 'a';
            int b = t[i] - 'a';
            G[a][b] = 1; // Assuming undirected graph
            G[b][a] = 1;
            masks[a] |= 1 << b;
        }
    }

    int res = 0;
    dp[0] = true;
    for (int i = 0; i < C; i++) {
        if (!vis[i]) {
            mask = 0;
            memset(vis, false, sizeof(vis));
            dfs(i);
            int tmp = count();
            res += 2 * (mask > 0 ? __builtin_popcount(mask) : 0) - 1 - tmp; // Placeholder for length calculation
        }
    }

    memset(vis, false, sizeof(vis));
    memset(masks, 0, sizeof(masks));
    memset(dp, false, sizeof(dp));
    memset(G, 0, sizeof(G));

    return res;
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        printf("%d\n", solve());
    }
    return 0;
}
