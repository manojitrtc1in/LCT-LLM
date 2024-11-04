#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

#define mod 1000000007

void add(long long *x, long long y) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

void sub(long long *x, long long y) {
    *x -= y;
    if (*x < 0) *x += mod;
}

long long solve2(long long x, long long y, long long k, long long bonus) {
    if (x <= 0 || y <= 0 || k <= 0) return 0;
    if (x < y) {
        long long temp = x;
        x = y;
        y = temp;
    }
    long long ty = 1;
    while (ty * 2 <= y) {
        ty *= 2;
    }
    long long tx = 1;
    while (tx * 2 <= x) {
        tx *= 2;
    }
    long long res;
    long long txk = (tx < k) ? tx : k;
    if (tx == ty) {
        res = (txk * (txk + 1) % mod * ty + bonus * txk * 2 % mod * ty) % mod;
        add(&res, solve2(x - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(y - tx, tx, k - tx, bonus + tx));
        add(&res, solve2(x - tx, y - tx, k, bonus));
    } else {
        res = (txk * (txk + 1) % mod * y + bonus * txk * 2 % mod * y) % mod;
        add(&res, solve2(x - tx, y, k - tx, bonus + tx));
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
        long long ans = solve2(x2, y2, k) - solve2(x1 - 1, y2, k) - solve2(x2, y1 - 1, k) + solve2(x1 - 1, y1 - 1, k);
        ans %= mod;
        if (ans < 0) {
            ans += mod;
        }
        printf("%lld\n", ans * powmod(2LL, mod - 2, mod) % mod);
    }
    return 0;
}
