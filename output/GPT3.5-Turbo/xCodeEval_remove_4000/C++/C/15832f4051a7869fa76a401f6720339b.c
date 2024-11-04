#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

typedef long long ll;

ll pow_mod(ll x, ll n, int m) {
    assert(0 <= n && 1 <= m);
    if(m == 1) return 0;
    unsigned int r = 1, y = (unsigned int)(x % m);
    while(n) {
        if(n & 1) r = (r * y) % m;
        y = (y * y) % m;
        n >>= 1;
    }
    return r;
}

ll inv_mod(ll x, ll m) {
    assert(1 <= m);
    ll z = x % m;
    if(z < 0) z += m;
    return z;
}

typedef struct {
    ll first;
    ll second;
} pair;

pair id0(ll a, ll b) {
    a = a % b;
    if(a == 0) return (pair) {b, 0};

    ll s = b, t = a;
    ll m0 = 0, m1 = 1;

    while(t) {
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

    if(m0 < 0) m0 += b / s;
    return (pair) {s, m0};
}

int id2(int m) {
    if(m == 2) return 1;
    if(m == 167772161) return 3;
    if(m == 469762049) return 3;
    if(m == 754974721) return 11;
    if(m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while(x % 2 == 0) x /= 2;
    for(int i = 3; (long long)(i)*i <= x; i += 2) {
        if(x % i == 0) {
            divs[cnt++] = i;
            while(x % i == 0) { x /= i; }
        }
    }
    if(x > 1) { divs[cnt++] = x; }
    for(int g = 2;; g++) {
        bool ok = true;
        for(int i = 0; i < cnt; i++) {
            if(pow_mod(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if(ok) return g;
    }
}

int primitive_root(int m) {
    return id2(m);
}

pair crt(const ll *r, const ll *m, int n) {
    ll r0 = 0, m0 = 1;
    for(int i = 0; i < n; i++) {
        ll r1 = r[i] % m[i], m1 = m[i];
        if(m0 < m1) {
            ll tmp = r0;
            r0 = r1;
            r1 = tmp;
            tmp = m0;
            m0 = m1;
            m1 = tmp;
        }
        if(m0 % m1 == 0) {
            if(r0 % m1 != r1) return (pair) {0, 0};
            continue;
        }

        ll g, im;
        pair p = id0(m0, m1);
        g = p.first;
        im = p.second;

        ll u1 = (m1 / g);

        if((r1 - r0) % g) return (pair) {0, 0};

        ll x = ((r1 - r0) / g % u1) * im % u1;

        r0 += x * m0;
        m0 *= u1;

        if(r0 < 0) r0 += m0;
    }
    return (pair) {r0, m0};
}

ll floor_sum(ll n, ll m, ll a, ll b) {
    ll ans = 0;
    if(a >= m) {
        ans += (n - 1) * n * (a / m) / 2;
        a %= m;
    }
    if(b >= m) {
        ans += n * (b / m);
        b %= m;
    }

    ll y_max = (a * n + b) / m, x_max = (y_max * m - b);
    if(y_max == 0) return ans;
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

int main() {
    int m;
    scanf("%d", &m);
    ll hh[2], aa[2], xx[2], yy[2];
    for(int i = 0; i < 2; i++) {
        scanf("%lld %lld %lld %lld", &hh[i], &aa[i], &xx[i], &yy[i]);
    }
    ll d1, c1, d2, c2;
    ll h, a, x, y;
    h = hh[0];
    a = aa[0];
    x = xx[0];
    y = yy[0];
    int id[m];
    bool out[m];
    bool f = false;
    for(int i = 0; i < m + 2; i++) {
        h = (h * x + y) % m;
        if(id[h] != -1) {
            if(!f || out[h]) {
                d1 = -1;
                break;
            }
            d1 = i + 1 - id[h];
            c1 = id[a];
            break;
        } else {
            id[h] = i + 1;
            out[h] = f;
            if(h == a) {
                f = true;
            }
        }
    }
    h = hh[1];
    a = aa[1];
    x = xx[1];
    y = yy[1];
    for(int i = 0; i < m + 2; i++) {
        h = (h * x + y) % m;
        if(id[h] != -1) {
            if(!f || out[h]) {
                d2 = -1;
                break;
            }
            d2 = i + 1 - id[h];
            c2 = id[a];
            break;
        } else {
            id[h] = i + 1;
            out[h] = f;
            if(h == a) {
                f = true;
            }
        }
    }
    for(int i = 0; i < m * 3 + 1; i++) {
        for(int j = 0; j < 2; j++) {
            hh[j] = (hh[j] * xx[j] + yy[j]) % m;
            if(hh[0] == aa[0] && hh[1] == aa[1]) {
                printf("%d\n", i + 1);
                return 0;
            }
        }
    }
    if(d1 == -1 || d2 == -1) {
        printf("-1\n");
    } else {
        pair p = crt((ll[]) {c1, c2}, (ll[]) {d1, d2}, 2);
        ll x = p.first;
        ll y = p.second;
        if(!x && !y) {
            printf("-1\n");
        } else {
            ll M = c1 > c2 ? c1 : c2;
            if(x < M) x += ((M - x - 1) / y + 1) * y;
            printf("%lld\n", x);
        }
    }
    return 0;
}
