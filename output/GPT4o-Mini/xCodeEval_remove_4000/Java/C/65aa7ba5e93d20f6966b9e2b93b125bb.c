#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MOD 1000000007
#define MAX 1000000

long facts[MAX], id11[MAX];

void precomp() {
    id11[0] = facts[0] = 1;
    for (int i = 1; i < MAX; i++)
        facts[i] = (facts[i - 1] * i) % MOD;
    id11[MAX - 1] = modInv(facts[MAX - 1]);
    for (int i = MAX - 2; i >= 0; i--)
        id11[i] = (id11[i + 1] * (i + 1)) % MOD;
}

long modInv(long x) {
    return exp(x, MOD - 2);
}

long exp(long base, long e) {
    if (e == 0) return 1;
    long half = exp(base, e / 2);
    if (e % 2 == 0) return (half * half) % MOD;
    return (half * (half * base % MOD)) % MOD;
}

long mul(long a, long b) {
    return ((a % MOD) * (b % MOD)) % MOD;
}

long add(long a, long b) {
    return ((a % MOD) + (b % MOD)) % MOD;
}

long sub(long a, long b) {
    return ((a % MOD) - (b % MOD) + MOD) % MOD;
}

int maxRight(int x, int* a, int size) {
    int l = -1, r = size;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (a[m] <= x) {
            l = m;
        } else {
            r = m;
        }
    }
    return l + 1;
}

int minLeft(int x, int* a, int size) {
    int l = -1, r = size;
    while (r - l > 1) {
        int m = l + (r - l) / 2;
        if (a[m] < x) {
            l = m;
        } else {
            r = m;
        }
    }
    return r + 1;
}

int lowerBound(int key, int* a, int size) {
    int s = 0, e = size - 1;
    if (e == -1) {
        return 0;
    }
    int ans = -1;
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
    int s = 0, e = size - 1;
    if (e == -1) {
        return 0;
    }
    int ans = -1;
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
