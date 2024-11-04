#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define INF 1011111111
#define LLINF 1000111000111000111LL
#define EPS (double)1e-10
#define mod 1000000007

void add(int* x, int y) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

void sub(int* x, int y) {
    *x -= y;
    if (*x < 0) *x += mod;
}

int powlog2(int v) {
    return 1 << (31 - __builtin_clz(v));
}

int solve2(int x, int y, int k, int bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        int temp = x;
        x = y;
        y = temp;
    }
    int ty = powlog2(y);
    int tx = powlog2(x);
    int res;
    int txk = (tx < k) ? tx : k;
    if (tx == ty) {
        res = txk * (long long)ty % mod * (txk + 1 + bonus * 2LL) % mod;
        int temp1 = solve2(x - tx, tx, k - tx, bonus + tx);
        add(&res, temp1);
        temp1 = solve2(y - tx, tx, k - tx, bonus + tx);
        add(&res, temp1);
        temp1 = solve2(x - tx, y - tx, k, bonus);
        add(&res, temp1);
    } else {
        res = txk * (long long)y % mod * (txk + 1 + bonus * 2LL) % mod;
        int temp1 = solve2(x - tx, y, k - tx, bonus + tx);
        add(&res, temp1);
    }
    return res;
}

long long powmod(long long x, long long n, long long m) {
    long long res = 1;
    while (n) {
        if (n & 1) res = (res * x) % m;
        x = (x * x) % m;
        n >>= 1;
    }
    return res;
}

int main() {
    int q;
    scanf("%d", &q);
    while (q--) {
        int x1, y1, x2, y2, k;
        scanf("%d %d %d %d %d", &x1, &y1, &x2, &y2, &k);
        int ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%d\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
