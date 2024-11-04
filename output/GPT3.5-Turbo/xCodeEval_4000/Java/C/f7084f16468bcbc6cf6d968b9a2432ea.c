#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MOD 1000000007

int abs(int v) {
    return v > 0 ? v : -v;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a > b ? b : a;
}

long long pow(long long v, long long p) {
    long long ans = 1;
    while (p > 0) {
        if (p % 2 == 1)
            ans = (ans * v) % MOD;
        v = (v * v) % MOD;
        p = p / 2;
    }
    return ans;
}

long long inv(long long v) {
    return pow(v, MOD - 2);
}

long long gcd(long long x, long long y) {
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

int main() {
    int test = 0;
    int nt = 1;
    int WALL = -1;
    int EMPTY = -2;
    int VISITED = 1;
    int FULL = 2;
    int START = 1;
    int END = 0;
    int UNVISITED = -2;

    for (int it = 0; it < nt; it++) {
        long long n = 0;
        long long k = 0;

        scanf("%lld %lld", &n, &k);

        if (k == 1) {
            printf("%lld\n", n);
            return 0;
        }

        long long lo = 1, hi = n / 2;

        while (lo <= hi) {
            long long mid = (hi + lo) / 2;
            long long val = mid * 2 - 1;

            if (cnt(val, n) >= k) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        long long cand = hi * 2 - 1;
        if (cnt(cand, n) < k)
            cand = 0;

        lo = 1;
        hi = n / 2;

        while (lo <= hi) {
            long long mid = (hi + lo) / 2;
            long long val = mid * 2;
            if (cnt(val, n) >= k)
                lo = mid + 1;
            else
                hi = mid - 1;
        }

        cand = max(cand, hi * 2);
        printf("%lld\n", cand);
    }

    return 0;
}

long long cnt(long long v, long long n) {
    if (v > n)
        return 0;

    long long cnt = 0;
    if (v % 2 == 1) {
        long long segSize = 1;
        long long start = v;
        while (start <= n) {
            long long end = min(n, start + segSize - 1);
            cnt += end - start + 1;

            segSize *= 2;
            start *= 2;
        }

    } else {

        long long segSize = 2;
        long long start = v;
        while (start <= n) {
            long long end = min(n, start + segSize - 1);
            cnt += end - start + 1;

            segSize *= 2;
            start *= 2;
        }

    }

    return cnt;
}
