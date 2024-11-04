#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 128
#define MOD 1000000007

long long bpow(int a, int b, int mod) {
    long long res = a, ret = 1;
    while (b > 0) {
        if (b % 2)
            ret = (ret * res) % mod;
        res = (res * res) % mod;
        b /= 2;
    }
    return ret % mod;
}

void Random() {
    unsigned int seed;
    seed = (unsigned int)clock();
    srand(seed);
}

long long fact(long long n, int mod) {
    long long fuc = 1;
    for (int i = 2; i <= n; ++i) {
        fuc = fuc * i % mod;
    }
    return fuc;
}

long long Cnk(long long n, long long r, int mod) {
    r = (r < n - r) ? r : n - r;
    long long ans = 1;
    for (int i = n; i >= (n - r + 1); --i) {
        ans = (ans * i) % mod;
    }
    for (int i = 1; i <= r; ++i) {
        ans = (ans * bpow(i, mod - 2, mod)) % mod;
    }
    return ans;
}

int main() {
    Random();

    int b, d;
    char a[MAX_SIZE], c[MAX_SIZE];
    int t[MAX_SIZE] = {0};
    
    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    
    int s = 0, n = strlen(c);
    for (int i = 0; c[i]; ++i) {
        int *k = &t[i];
        for (int j = 0; a[j]; ++j) {
            if (a[j] == c[(i + *k) % n])
                ++(*k);
        }
    }
    
    for (int i = 0; i < b; ++i)
        s += t[s % n];
    
    printf("%d\n", s / n / d);
    return 0;
}
