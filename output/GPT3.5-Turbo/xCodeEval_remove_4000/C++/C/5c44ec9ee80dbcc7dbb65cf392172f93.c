#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define maxn 100005
#define MOD 1000000007

int n;
int pts[maxn][2];
bool visit[maxn * 2];
int g[maxn * 2][maxn * 2];

typedef struct {
    int first;
    int second;
} Pair;

int gcd(int a, int b) {
    while (a != 0) {
        b %= a;
        if (b == 0)
            return a;
        a %= b;
    }
    return b;
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int id1(int a, int b, int *x, int *y) {
    if (b == 0) {
        *x = 1;
        *y = 0;
        return a;
    }
    int g = id1(b, a % b, y, x);
    *y -= (a / b) * (*x);
    return g;
}

int mul_mod(int a, int b, int m) {
    long long p = a;
    p = (p * b) % m;
    return (int)p;
}

int pow_mod(int a, int p, int m) {
    int r;
    a %= m;
    for (r = 1; p; p >>= 1) {
        if (p & 1) r = mul_mod(r, a, m);
        a = mul_mod(a, a, m);
    }
    return r;
}

int inv_mod(int a, int m) {
    int x, y;
    id1(a, m, &x, &y);
    if (x < 0)
        return x + m;
    return x;
}

int id7(int u, int v, int m) {
    int r = u + v;
    if (r >= m) r -= m;
    return r;
}

int id3(int u, int v, int m) {
    int r = u - v;
    if (r < 0) r += m;
    return r;
}

int div_mod(int u, int v, int m) {
    int g = gcd(v, m);
    int mm = m / g;
    return mul_mod(u / g, inv_mod(v / g, mm), mm);
}

int id0(int a, int b, int *r) {
    int q = a / b;
    *r = a % b;
    if (*r < 0) {
        if (b < 0)
            q += 1, *r -= b;
        else
            q -= 1, *r += b;
    }
    return q;
}

void dfs(int u, int *ret) {
    ret[0] = 1;
    ret[1] = 0;
    visit[u] = true;
    for (int v = 0; v < maxn * 2; v++) {
        if (g[u][v] && !visit[v]) {
            int p[2];
            dfs(v, p);
            ret[0] += p[0];
            ret[1] += p[1];
        }
    }
}

int main() {
    scanf("%d", &n);

    int trans[2][maxn];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &pts[i][0], &pts[i][1]);
        for (int j = 0; j < 2; j++) {
            trans[j][pts[i][j]] = 0;
        }
    }
    int cnt = 0;
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < maxn; i++) {
            if (trans[j][i] == 0) {
                trans[j][i] = cnt++;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        int x = trans[0][pts[i][0]];
        int y = trans[1][pts[i][1]];
        g[x][y] = 1;
        g[y][x] = 1;
    }
    int ans = 1;
    for (int i = 0; i < cnt; i++) {
        if (!visit[i]) {
            int p[2];
            dfs(i, p);
            int vers = p[0];
            int edgs = p[1] / 2;
            if (edgs == vers - 1) {
                ans = mul_mod(ans, pow_mod(2, vers, MOD) - 1, MOD);
            } else {
                ans = mul_mod(ans, pow_mod(2, vers, MOD), MOD);
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
