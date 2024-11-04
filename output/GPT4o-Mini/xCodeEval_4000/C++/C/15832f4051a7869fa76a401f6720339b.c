#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;
typedef struct {
    ll first;
    ll second;
} pll;

ll safe_mod(ll x, ll m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}

pll inv_gcd(ll a, ll b) {
    a = safe_mod(a, b);
    if (a == 0) return (pll){b, 0};

    ll s = b, t = a;
    ll m0 = 0, m1 = 1;

    while (t) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;

        ll tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }

    if (m0 < 0) m0 += b / s;
    return (pll){s, m0};
}

pll crt(ll *r, ll *m, int n) {
    ll r0 = 0, m0 = 1;
    for (int i = 0; i < n; i++) {
        ll r1 = safe_mod(r[i], m[i]), m1 = m[i];
        if (m0 < m1) {
            ll tmp = r0; r0 = r1; r1 = tmp;
            tmp = m0; m0 = m1; m1 = tmp;
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) return (pll){0, 0};
            continue;
        }

        pll g = inv_gcd(m0, m1);
        ll u1 = m1 / g.first;

        if ((r1 - r0) % g.first) return (pll){0, 0};

        ll x = (r1 - r0) / g.first % u1 * g.second % u1;

        r0 += x * m0;
        m0 *= u1;

        if (r0 < 0) r0 += m0;
    }
    return (pll){r0, m0};
}

ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if (a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if (b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if (y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

int main() {
    ll m;
    scanf("%lld", &m);
    ll hh[2], aa[2], xx[2], yy[2];
    for (int i = 0; i < 2; i++) {
        scanf("%lld %lld %lld %lld", &hh[i], &aa[i], &xx[i], &yy[i]);
    }

    pll F(int i) {
        ll h = hh[i], a = aa[i], x = xx[i], y = yy[i];
        ll id[m];
        for (int j = 0; j < m; j++) id[j] = -1;
        ll out[m];
        for (int j = 0; j < m; j++) out[j] = 0;
        bool f = false;
        id[h] = 0;
        for (int j = 0; j < m + 2; j++) {
            h = (h * x + y) % m;
            if (id[h] != -1) {
                if (!f || out[h]) return (pll){-1, -1};
                return (pll){j + 1 - id[h], id[a]};
            } else {
                id[h] = j + 1;
                out[h] = f;
                if (h == a) { f = true; }
            }
        }
        return (pll){-1, -1};
    }

    pll res1 = F(0);
    pll res2 = F(1);
    for (int i = 0; i < m * 3 + 1; i++) {
        for (int j = 0; j < 2; j++) {
            hh[j] = (hh[j] * xx[j] + yy[j]) % m;
        }
        if (hh[0] == aa[0] && hh[1] == aa[1]) {
            printf("%d\n", i + 1);
            exit(0);
        }
    }
    if (res1.first == -1 || res2.first == -1) {
        printf("-1\n");
    } else {
        pll res = crt((ll[]){res2.second, res1.second}, (ll[]){res2.first, res1.first}, 2);
        if (!res.first && !res.second)
            printf("-1\n");
        else {
            ll M = res1.second > res2.second ? res1.second : res2.second;
            if (res.first < M) res.first += ((M - res.first - 1) / res.second + 1) * res.second;
            printf("%lld\n", res.first);
        }
    }
    return 0;
}
