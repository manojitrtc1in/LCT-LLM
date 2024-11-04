#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;

ll bpow(int a, int b, int mod) {
    ll res = a, ret = 1;
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
    asm("rdtsc" : "=A" (seed));
    srand(seed);
}

ll fact(ll n, int mod) {
    ll fuc = 1;
    for (int i = 2; i <= n; ++i) {
        fuc = fuc * i % mod;
    }
    return fuc;
}

ll Cnk(ll n, ll r, int mod) {
    r = (r < (n - r)) ? r : (n - r);
    ll ans = 1;
    for (int i = n; i >= (n - r + 1); --i) {
        ans = (ans * i) % mod;
    }
    for (int i = 1; i <= r; ++i) {
        ans = (ans * bpow(i, mod - 2, mod)) % mod;
    }
    return ans;
}

int main() {
    char a[128], c[128];
    int b, d, t[128] = {0};
    Random();

    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    int s = 0, n = strlen(c);
    for (int i = 0; c[i]; ++i) {
        int *k = &t[i];
        for (int j = 0; a[j]; ++j)
            if (a[j] == c[(i + *k) % n])
                ++(*k);
    }
    for (int i = 0; i < b; ++i)
        s += t[s % n];
    printf("%d\n", s / n / d);
}
