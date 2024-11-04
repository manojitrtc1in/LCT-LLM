#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

long long lcm(long long a, long long b) {
    return (a * b) / gcd(a, b);
}

long long id19(long long a, long long b, long long MOD) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long long id23(long long x, long long n, long long MOD) {
    long long result = 1;
    while (n > 0) {
        if (n % 2 == 1)
            result = id19(result, x, MOD);
        x = id19(x, x, MOD);
        n /= 2;
    }
    return result;
}

long long factorials(long long n) {
    if (n == 0)
        return 1;
    return n * factorials(n - 1);
}

int main() {
    int test = 1;

    while (test-- > 0) {
        int n;
        scanf("%d", &n);
        int ar[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &ar[i][j]);
            }
        }

        long long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += ar[i][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[n - i - 1][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[(n - 1) / 2][i];
        }

        for (int i = 0; i < n; i++) {
            sum += ar[i][(n - 1) / 2];
        }
        printf("%lld\n", sum - ar[(n - 1) / 2][(n - 1) / 2] * 3);
    }

    return 0;
}
