#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define LL long long
#define INF 2147483647
#define MAXN 1005
#define MAXK 9
#define MAXDIST 77

typedef struct {
    LL dist[MAXDIST][MAXDIST];
} mat;

int x, k, n, q;
int tl;
int id[256];
mat T1;
int cc = 0;
LL c[MAXK];
int p[30], wp[30];
LL dp[MAXDIST], dp2[MAXDIST];

void init() {
    for (int i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;
        id[i] = ++cc;
    }
    for (int i = 0; i < (1 << k); i++) {
        int cnt = 0;
        for (int j = 0; j < k; ++j) {
            if (i >> j & 1) cnt++;
        }
        if (cnt != x) continue;
        int v = i >> 1;
        int u = i & 1;
        if (!u) {
            T1.dist[id[i]][id[v]] = 0;
        } else {
            for (int j = 0; j < k; j++) {
                if (v & (1 << j)) continue;
                T1.dist[id[i]][id[v ^ (1 << j)]] = c[j + 1];
            }
        }
    }
}

mat build(int pos) {
    mat ret = T1;
    for (int i = 0; i < (1 << k); i++) {
        if (!id[i]) continue;
        for (int j = 1; j <= q; j++) {
            if (p[j] <= pos && pos - p[j] < k) {
                int pp = pos - p[j];
                pp = k - 1 - pp;
                if (i >> (pp + 1) & 1) continue;
                for (int l = 0; l < (1 << k); l++) {
                    if (!id[l]) continue;
                    if (l >> pp & 1) {
                        if (ret.dist[id[i]][id[l]] != INF) ret.dist[id[i]][id[l]] += wp[j];
                    }
                }
            }
        }
    }
    return ret;
}

mat mul(mat x, mat y) {
    mat ret;
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            ret.dist[i][j] = INF;
            for (int k = 1; k <= cc; k++) {
                ret.dist[i][j] = (ret.dist[i][j] < x.dist[i][k] + y.dist[k][j]) ? ret.dist[i][j] : x.dist[i][k] + y.dist[k][j];
            }
        }
    }
    return ret;
}

void mul_mat(mat X) {
    for (int i = 1; i <= cc; i++) {
        dp2[i] = INF;
    }
    for (int i = 1; i <= cc; i++) {
        for (int j = 1; j <= cc; j++) {
            dp2[j] = (dp2[j] < dp[i] + X.dist[i][j]) ? dp2[j] : dp[i] + X.dist[i][j];
        }
    }
    for (int i = 1; i <= cc; i++) dp[i] = dp2[i];
}

mat mqp(mat x, LL p) {
    mat R;
    for (int i = 1; i <= cc; i++) R.dist[i][i] = 0;
    while (p) {
        if (p & 1) R = mul(R, x);
        x = mul(x, x);
        p >>= 1;
    }
    return R;
}

bool normal(int pos) {
    for (int i = 1; i <= q; i++) {
        if (p[i] <= pos && pos - p[i] < k) return false;
    }
    return true;
}

int main() {
    scanf("%d %d %d %d", &x, &k, &n, &q);
    n += k - x;
    for (int i = 1; i <= k; i++) {
        scanf("%lld", &c[i]);
    }
    init();
    for (int i = 1; i <= q; i++) {
        scanf("%d %d", &p[i], &wp[i]);
    }
    for (int i = 1; i <= cc; i++) dp[i] = INF;
    dp[id[(1 << x) - 1]] = 0;
    int now = k;
    while (now < n) {
        if (!normal(now + 1)) {
            mat Tra = build(now + 1);
            mul_mat(Tra);
            now++;
            continue;
        }
        int Nxt = n + 1;
        for (int i = 1; i <= q; i++) {
            if (p[i] > now) {
                Nxt = (Nxt < p[i]) ? Nxt : p[i];
            }
        }
        int di = Nxt - now - 1;
        mat Tra = mqp(T1, di);
        mul_mat(Tra);
        now = Nxt - 1;
    }
    printf("%lld\n", dp[id[(1 << x) - 1]]);
    return 0;
}
