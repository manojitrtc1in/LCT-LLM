#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef long long ll;
typedef long long LL;
typedef unsigned long long ull;
typedef struct {
    long long first;
    long long second;
} pll;
typedef struct {
    long long first;
    long long second;
} pii;
typedef struct {
    pii first;
    pii second;
} ppiipii;
typedef long double ld;
typedef struct {
    int first;
    int second;
} pii;
typedef struct {
    int first;
    int second;
} mipii;
typedef struct {
    int first;
    pii second;
} vpipii;

#define maxn (int)(1.5 * 1e7)
#define inf (int)(1e9 + 7)
#define ll_inf (ll)(1e18 + 420)
#define eps (double)(1e-4)
#define N (int)(1e6 + 7)
#define MAX (int)(2e5 + 9)
#define MOD (int)(1e9 + 7)
#define pi (ld)(3.14159265359)

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
    int fuc = 1;
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

char a[128], c[128];
int b, d, t[128];
int main() {
    Random();
    scanf("%d%d", &b, &d);
    scanf("%s%s", a, c);
    int s = 0, n = strlen(c);
    for (int i = 0; c[i]; ++i) {
        int k = t[i];
        for (int j = 0; a[j]; ++j) {
            if (a[j] == c[(i + k) % n]) {
                ++k;
            }
        }
        t[i] = k;
    }
    for (int i = 0; i < b; ++i) {
        s += t[s % n];
    }
    printf("%d\n", s / n / d);
    return 0;
}
