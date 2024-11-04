#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MOD 1000000007
#define MOD2 998244353
#define MAX_N 100

long long pref[MAX_N + 1];
long long fact[MAX_N + 1];
long long invFact[MAX_N + 1];

void input(long long a[], int n) {
    for (int i = 0; i < n; i++) {
        scanf("%lld", &a[i]);
    }
}

long long mul(long long a, long long b) {
    return (a * b) % MOD;
}

long long add(long long a, long long b) {
    return (a + b) % MOD;
}

long long power(long long x, long long y) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) result = mul(result, x);
        x = mul(x, x);
        y /= 2;
    }
    return result;
}

long long modInv(long long x) {
    return power(x, MOD - 2);
}

void init(int n) {
    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = mul(i, fact[i - 1]);
    }
    invFact[n] = modInv(fact[n]);
    for (int i = n - 1; i >= 0; i--) {
        invFact[i] = mul(invFact[i + 1], i + 1);
    }
}

long long nCr(int n, int r) {
    if (n < r || r < 0) return 0;
    return mul(fact[n], mul(invFact[r], invFact[n - r]));
}

long long xor(int i, int j) {
    return pref[j + 1] ^ pref[i];
}

int main() {
    int n;
    scanf("%d", &n);
    long long a[MAX_N];
    input(a, n);
    
    if (n > 66) {
        printf("1\n");
        return 0;
    }
    
    pref[1] = a[0];
    for (int i = 1; i < n; i++) {
        pref[i + 1] = pref[i] ^ a[i];
    }
    
    int gg = 34;
    for (int c = 0; c < n - 1; c++) {
        for (int left = c; left >= 0; left--) {
            for (int right = c + 1; right < n; right++) {
                if (xor(left, c) > xor(c + 1, right)) {
                    gg = (right - left - 1 < gg) ? right - left - 1 : gg;
                }
            }
        }
    }
    
    printf("%d\n", gg == 34 ? -1 : gg);
    return 0;
}
