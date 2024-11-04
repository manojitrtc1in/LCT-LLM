#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>

#define MOD 1000000007
#define MAX 1000000

long facts[MAX], factInvs[MAX];

void precomp() {
    facts[0] = factInvs[0] = 1;
    for (int i = 1; i < MAX; i++) {
        facts[i] = (facts[i - 1] * i) % MOD;
    }
    factInvs[MAX - 1] = modInv(facts[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--) {
        factInvs[i] = (factInvs[i + 1] * (i + 1)) % MOD;
    }
}

long modInv(long x) {
    return modpow(x, MOD - 2);
}

long modpow(long a, long b) {
    if (b == 0) return 1;
    long x = modpow(a, b / 2);
    x = (x * x) % MOD;
    if (b % 2 == 1) {
        return (x * a) % MOD;
    }
    return x;
}

long mul(long a, long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long add(long a, long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

long sub(long a, long b) {
    return ((a % MOD) - (b % MOD)) % MOD;
}

int lowerBound(int key, int* a, int size) {
    int s = 0, e = size - 1, ans = -1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (a[m] >= key) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return ans == -1 ? s : ans;
}

int upperBound(int key, int* a, int size) {
    int s = 0, e = size - 1, ans = -1;
    while (s <= e) {
        int m = s + (e - s) / 2;
        if (a[m] > key) {
            ans = m;
            e = m - 1;
        } else {
            s = m + 1;
        }
    }
    return ans == -1 ? s : ans;
}

void solve() {
    char s[100001], t[100001];
    scanf("%s %s", s, t);
    int n = strlen(s);
    int m = strlen(t);
    int pre[m], suf[m];
    
    for (int i = 0, j = 0; i < m; i++) {
        while (s[j] != t[i]) j++;
        pre[i] = j++;
    }
    for (int i = m - 1, j = n - 1; i >= 0; i--) {
        while (s[j] != t[i]) j--;
        suf[i] = j--;
    }
    
    int ans = fmax(suf[0], n - 1 - pre[m - 1]);
    for (int i = 0; i < m - 1; i++) {
        ans = fmax(ans, suf[i + 1] - 1 - pre[i]);
    }
    printf("%d\n", ans);
}

int main() {
    precomp();
    int test = 1;
    while (test-- > 0) solve();
    return 0;
}
