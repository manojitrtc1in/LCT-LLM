#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

ll pow_mod(ll x, ll n, int m) {
    if (n == 0) {
        return 1;
    }
    ll res = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            res = (res * x) % m;
        }
        x = (x * x) % m;
        n /= 2;
    }
    return res;
}

ll inv_mod(ll x, ll m) {
    ll a = x;
    ll b = m;
    ll x0 = 0;
    ll x1 = 1;
    while (a > 1) {
        ll q = a / b;
        ll temp = b;
        b = a % b;
        a = temp;
        temp = x0;
        x0 = x1 - q * x0;
        x1 = temp;
    }
    if (x1 < 0) {
        x1 += m;
    }
    return x1;
}

typedef struct {
    ll first;
    ll second;
} pair;

pair inv_gcd(ll a, ll b) {
    a = a % b;
    if (a == 0) {
        return (pair){b, 0};
    }
    ll s = b;
    ll t = a;
    ll m0 = 0;
    ll m1 = 1;
    while (t != 0) {
        ll u = s / t;
        s -= t * u;
        m0 -= m1 * u;
        ll temp = s;
        s = t;
        t = temp;
        temp = m0;
        m0 = m1;
        m1 = temp;
    }
    if (m0 < 0) {
        m0 += b / s;
    }
    return (pair){s, m0};
}

int is_prime(int n) {
    if (n <= 1) {
        return 0;
    }
    if (n == 2 || n == 7 || n == 61) {
        return 1;
    }
    if (n % 2 == 0) {
        return 0;
    }
    ll d = n - 1;
    while (d % 2 == 0) {
        d /= 2;
    }
    for (ll a = 2; a <= 61; a++) {
        if (a >= n) {
            break;
        }
        ll t = d;
        ll y = pow_mod(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = (y * y) % n;
            t *= 2;
        }
        if (y != n - 1 && t % 2 == 0) {
            return 0;
        }
    }
    return 1;
}

int primitive_root(int m) {
    if (m == 2) {
        return 1;
    }
    if (m == 167772161) {
        return 3;
    }
    if (m == 469762049) {
        return 3;
    }
    if (m == 754974721) {
        return 11;
    }
    if (m == 998244353) {
        return 3;
    }
    int divs[20] = {0};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) {
        x /= 2;
    }
    for (int i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        int ok = 1;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod(g, (m - 1) / divs[i], m) == 1) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            return g;
        }
    }
}

pair crt(ll* r, ll* m, int n) {
    ll r0 = 0;
    ll m0 = 1;
    for (int i = 0; i < n; i++) {
        ll r1 = r[i] % m[i];
        ll m1 = m[i];
        if (m0 < m1) {
            ll temp = r0;
            r0 = r1;
            r1 = temp;
            temp = m0;
            m0 = m1;
            m1 = temp;
        }
        if (m0 % m1 == 0) {
            if (r0 % m1 != r1) {
                return (pair){0, 0};
            }
            continue;
        }
        pair g = inv_gcd(m0, m1);
        ll u1 = m1 / g.first;
        if ((r1 - r0) % g.first) {
            return (pair){0, 0};
        }
        ll x = (r1 - r0) / g.first % u1 * g.second % u1;
        r0 += x * m0;
        m0 *= u1;
        if (r0 < 0) {
            r0 += m0;
        }
    }
    return (pair){r0, m0};
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
    ll y_max = (a * n + b) / m;
    ll x_max = y_max * m - b;
    if (y_max == 0) {
        return ans;
    }
    ans += (n - (x_max + a - 1) / a) * y_max;
    ans += floor_sum(y_max, a, m, (a - x_max % a) % a);
    return ans;
}

int main() {
    int m;
    scanf("%d", &m);
    ll hh[2], aa[2], xx[2], yy[2];
    for (int i = 0; i < 2; i++) {
        scanf("%lld %lld %lld %lld", &hh[i], &aa[i], &xx[i], &yy[i]);
    }
    ll d1, c1, d2, c2;
    ll h = hh[0], a = aa[0], x = xx[0], y = yy[0];
    int id[m];
    int out[m];
    for (int i = 0; i < m; i++) {
        id[i] = -1;
        out[i] = 0;
    }
    int f = 0;
    id[h] = 0;
    for (int i = 0; i < m + 2; i++) {
        h = (h * x + y) % m;
        if (id[h] != -1) {
            if (!f || out[h]) {
                printf("-1\n");
                return 0;
            }
            d1 = i + 1 - id[h];
            c1 = id[a];
            break;
        } else {
            id[h] = i + 1;
            out[h] = f;
            if (h == a) {
                f = 1;
            }
        }
    }
    h = hh[1];
    a = aa[1];
    x = xx[1];
    y = yy[1];
    for (int i = 0; i < m; i++) {
        id[i] = -1;
        out[i] = 0;
    }
    f = 0;
    id[h] = 0;
    for (int i = 0; i < m + 2; i++) {
        h = (h * x + y) % m;
        if (id[h] != -1) {
            if (!f || out[h]) {
                printf("-1\n");
                return 0;
            }
            d2 = i + 1 - id[h];
            c2 = id[a];
            break;
        } else {
            id[h] = i + 1;
            out[h] = f;
            if (h == a) {
                f = 1;
            }
        }
    }
    for (int i = 0; i < m * 3 + 1; i++) {
        for (int j = 0; j < 2; j++) {
            hh[j] = (hh[j] * xx[j] + yy[j]) % m;
            if (hh[0] == aa[0] && hh[1] == aa[1]) {
                printf("%d\n", i + 1);
                return 0;
            }
        }
    }
    if (d1 == -1 || d2 == -1) {
        printf("-1\n");
    } else {
        pair res = crt((ll[]){c1, c2}, (ll[]){d1, d2}, 2);
        ll x = res.first;
        ll y = res.second;
        if (!x && !y) {
            printf("-1\n");
        } else {
            ll M = c1 > c2 ? c1 : c2;
            if (x < M) {
                x += ((M - x - 1) / y + 1) * y;
            }
            printf("%lld\n", x);
        }
    }
    return 0;
}
