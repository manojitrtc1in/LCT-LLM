#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100000

typedef long long int ll;

ll min(ll a, ll b) {
    return (a < b) ? a : b;
}

ll max(ll a, ll b) {
    return (a > b) ? a : b;
}

void main() {
    ll n, k;
    scanf("%lld %lld", &n, &k);
    ll c[MAX_SIZE], pf[MAX_SIZE];
    ll c_size = 0, pf_size = 0;
    for (ll i = 0; i < n; ++i) {
        ll v;
        scanf("%lld", &v);
        if (v < 0)
            c[c_size++] = -v;
        else
            pf[pf_size++] = v;
    }

    for (ll i = 0; i < pf_size; ++i) {
        for (ll j = i + 1; j < pf_size; ++j) {
            if (pf[i] < pf[j]) {
                ll temp = pf[i];
                pf[i] = pf[j];
                pf[j] = temp;
            }
        }
    }

    ll ini = 0;
    ll base = 0;
    for (ll i = 0; i < pf_size; ++i) {
        base += ini;
        ini += pf[i];
    }

    for (ll i = 0; i < c_size; ++i) {
        for (ll j = i + 1; j < c_size; ++j) {
            if (c[i] < c[j]) {
                ll temp = c[i];
                c[i] = c[j];
                c[j] = temp;
            }
        }
    }

    if (!k) {
        for (ll i = c_size - 1; i >= 0; --i) {
            base += ini;
            ini -= c[i];
        }
        printf("%lld\n", base);
        return;
    }

    ll cs[MAX_SIZE + 1];
    for (ll i = 0; i < c_size; ++i) {
        cs[i + 1] = cs[i] + (i / (k + 1) * c[i]);
    }

    ll sf[MAX_SIZE + 1], sf2[MAX_SIZE + 1];
    for (ll i = c_size - 1; i >= 0; --i) {
        sf[i] = sf[i + 1] + c[i];
        sf2[i] = sf2[i + 1] + c[i] * i;
    }

    ll ans = -1e18;
    for (ll j = 0; j <= c_size; ++j) {
        if (j * (k + 1) < c_size) continue;
        ll cd = (c_size - j) / k + ((c_size - j) % k != 0);
        ll tp = j - cd;
        ll now = ini * j;
        now -= sf2[c_size - tp] + sf[tp] * (cd - (c_size - tp));
        now -= cs[c_size - tp];
        ans = max(ans, now);
    }

    ans += base;
    printf("%lld\n", ans);
}
