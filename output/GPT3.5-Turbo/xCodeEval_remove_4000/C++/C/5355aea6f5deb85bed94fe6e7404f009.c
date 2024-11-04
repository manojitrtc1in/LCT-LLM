#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 200000

typedef long long ll;

ll abs(ll a) {
    return a > 0 ? a : -a;
}

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

ll lcm(ll a, ll b) {
    return a / gcd(a, b) * b;
}

ll modpow(ll a, ll n, ll temp) {
    ll res = 1, y = a;
    while (n > 0) {
        if (n & 1) {
            res = (res * y) % temp;
        }
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

ll mod = 1000000007;

int sgn(ll x) {
    return x < 0 ? -1 : !!x;
}

const double eps = 1e-7;
const double pi = 3.14159265358979323846;

void inc(ll *x, ll y) {
    *x += y;
    if (*x >= mod) {
        *x -= mod;
    }
}

void dec(ll *x, ll y) {
    *x -= y;
    if (*x < 0) {
        *x += mod;
    }
}

void chmax(ll *x, ll y) {
    if (y > *x) {
        *x = y;
    }
}

void mulm(ll *x, ll y) {
    *x *= y;
    if (*x >= mod) {
        *x -= mod;
    }
}

ll xo(ll i) {
    if ((i & 3) == 0) {
        return i;
    }
    if ((i & 3) == 1) {
        return 1;
    }
    if ((i & 3) == 2) {
        return i + 1;
    }
    return 0;
}

typedef struct {
    ll first;
    ll second;
} pii;

typedef struct {
    ll first;
    pii second;
} ver;

int compare(const void *a, const void *b) {
    return (*(ll *)a - *(ll *)b);
}

int main() {
    ll i, j, k, l, m, n;
    scanf("%lld", &n);
    ll tot = 0;
    ll data[MAX_SIZE][MAX_SIZE];
    for (i = 1; i <= n; i++) {
        ll k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        ll tmp[MAX_SIZE];
        tmp[0] = a;
        for (j = 2; j <= k; j++) {
            tmp[j - 1] = (tmp[j - 2] * x + y) % m;
        }
        for (j = 0; j < k; j++) {
            data[i - 1][j] = tmp[j];
        }
    }
    ll q[MAX_SIZE][3];
    ll q_size = 0;
    for (i = 0; i < n; i++) {
        q[q_size][0] = data[i][0];
        q[q_size][1] = i;
        q[q_size][2] = 0;
        q_size++;
    }
    qsort(q, q_size, sizeof(ll) * 3, compare);
    ll ans[MAX_SIZE];
    pii sol[MAX_SIZE];
    ll p = 0;
    ll ans_size = 0;
    while (ans_size < tot) {
        ll v = q[p][0];
        p = v;
        pii o;
        o.first = q[p][1];
        o.second = q[p][2];
        ans[ans_size] = v;
        sol[ans_size].first = v;
        sol[ans_size].second.first = o.first + 1;
        ans_size++;
        p++;
        if (o.second + 1 < n) {
            q[q_size][0] = data[o.first][o.second + 1];
            q[q_size][1] = o.first;
            q[q_size][2] = o.second + 1;
            q_size++;
        }
    }
    ll bad = 0;
    for (i = 1; i < ans_size; i++) {
        if (ans[i - 1] > ans[i]) {
            bad++;
        }
    }
    printf("%lld\n", bad);
    if (tot <= 200000) {
        for (i = 0; i < ans_size; i++) {
            printf("%lld %lld\n", sol[i].first, sol[i].second.first);
        }
    }
    return 0;
}
