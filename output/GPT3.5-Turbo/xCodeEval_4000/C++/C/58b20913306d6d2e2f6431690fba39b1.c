#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define ull unsigned long long

typedef struct {
    ll first;
    ll second;
} pii;

typedef struct {
    ll first;
    pii second;
} ver;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return (a / gcd(a, b)) * b;
}

ll modpow(ll a, ll n, ll temp) {
    ll res = 1, y = a;
    while (n > 0) {
        if (n & 1)
            res = (res * y) % temp;
        y = (y * y) % temp;
        n /= 2;
    }
    return res % temp;
}

ll ison(ll mask, ll pos) {
    return (mask & (1 << pos));
}

ll cbit(ll n) {
    ll k = 0;
    while (n) {
        n &= (n - 1);
        k++;
    }
    return k;
}

ll nbit(ll n) {
    ll k = 0;
    while (n) {
        n /= 2;
        k++;
    }
    return k;
}

int sgn(ll x) {
    return x < 0 ? -1 : !!x;
}

void inc(ll *x, ll y) {
    *x += y;
    if (*x >= mod)
        *x -= mod;
}

void dec(ll *x, ll y) {
    *x -= y;
    if (*x < 0)
        *x += mod;
}

void chmax(ll *x, ll y) {
    if (y > *x)
        *x = y;
}

void mulm(ll *x, ll y) {
    *x *= y;
    if (*x >= mod)
        *x -= mod;
}

ll xo(ll i) {
    if ((i & 3) == 0)
        return i;
    if ((i & 3) == 1)
        return 1;
    if ((i & 3) == 2)
        return i + 1;
    return 0;
}

int main() {
    ll i, j, k, l, m, n;
    scanf("%lld", &n);
    ll tot = 0;
    for (ll i = 1; i <= n; i++) {
        ll k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        ll *tmp = (ll *)malloc(k * sizeof(ll));
        tmp[0] = a;
        for (j = 2; j <= k; j++)
            tmp[j - 1] = (tmp[j - 2] * x + y) % m;
        data[i - 1] = tmp;
    }
    set<pair<ll, pii>> q;
    for (ll i = 0; i < n; i++)
        q.insert(mpa(data[i][0], mpa(i, 0)));
    ll *ans = (ll *)malloc(tot * sizeof(ll));
    pii *sol = (pii *)malloc(tot * sizeof(pii));
    ll p = 0;
    while (ans.size() < tot) {
        set<pair<ll, pii>>::iterator it = q.lower_bound(mpa(p, mpa(-1ll, -1ll)));
        if (it == q.end())
            it = q.begin();
        ll v = (*it).ff;
        p = v;
        pii o = (*it).ss;
        ans.pb(v);
        sol.pb(mpa(v, o.ff + 1ll));
        q.erase(*it);
        if (o.ss + 1ll < data[o.ff].size())
            q.insert(mpa(data[o.ff][o.ss + 1ll], mpa(o.ff, o.ss + 1ll)));
    }

    ll bad = 0;
    for (i = 1; i < ans.size(); i++)
        if (ans[i - 1] > ans[i])
            bad++;
    printf("%lld\n", bad);
    if (tot <= 200000)
        for (i = 0; i < sol.size(); i++)
            printf("%lld %lld\n", sol[i].ff, sol[i].ss);
}
