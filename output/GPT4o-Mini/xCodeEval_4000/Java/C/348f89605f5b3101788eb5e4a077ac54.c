#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MOD2 998244353

long long fact[1000001], invFact[1000001];

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = (i * fact[i - 1]) % MOD;
    }
    invFact[n] = power(fact[n], MOD - 2);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = (invFact[i + 1] * (i + 1)) % MOD;
    }
}

long long nCr(int n, int r) {
    if (n < r || r < 0) return 0;
    return (fact[n] * ((invFact[r] * invFact[n - r]) % MOD)) % MOD;
}

long long add(long long a, long long b) {
    return (a + b) % MOD;
}

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

long long power(long long x, long long y) {
    long long gg = 1;
    while (y > 0) {
        if (y % 2 == 1) gg = mul(gg, x);
        x = mul(x, x);
        y /= 2;
    }
    return gg;
}

long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
}

void sort(long long a[], int n) {
    qsort(a, n, sizeof(long long), cmp);
}

int cmp(const void *a, const void *b) {
    return (*(long long *)a - *(long long *)b);
}

void input(long long a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    long long a[n];
    input(a, n);
    sort(a, n);
    
    for (int i = 0; i < n / 2; i++) {
        long long temp = a[i];
        a[i] = a[n - 1 - i];
        a[n - 1 - i] = temp;
    }

    long long *pq = (long long *)malloc((k + 1) * sizeof(long long));
    for (int i = 0; i <= k; i++) {
        pq[i] = 0;
    }

    long long gg = 0;
    for (int i = 0; i < n; i++) {
        long long cur = pq[0];
        for (int j = 0; j < k; j++) {
            pq[j] = pq[j + 1];
        }
        gg += cur;
        cur += a[i];
        pq[k] = cur;
    }

    printf("%lld\n", gg);
    free(pq);
    return 0;
}
