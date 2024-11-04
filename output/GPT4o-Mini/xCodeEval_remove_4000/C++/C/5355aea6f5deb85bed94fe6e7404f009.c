#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <set>

typedef long long ll;
typedef struct {
    ll first;
    struct {
        ll first;
        ll second;
    } second;
} pii;

typedef struct {
    ll *data;
    size_t size;
    size_t capacity;
} vector_ll;

void vector_ll_init(vector_ll *v) {
    v->size = 0;
    v->capacity = 10;
    v->data = (ll *)malloc(v->capacity * sizeof(ll));
}

void vector_ll_push_back(vector_ll *v, ll value) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (ll *)realloc(v->data, v->capacity * sizeof(ll));
    }
    v->data[v->size++] = value;
}

void vector_ll_free(vector_ll *v) {
    free(v->data);
}

ll gcd(ll a, ll b) {
    while (b) {
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
        if (n & 1) res = (res * y) % temp;
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

void inc(ll *x, ll y, ll mod) {
    *x += y;
    if (*x >= mod) *x -= mod;
}

void dec(ll *x, ll y, ll mod) {
    *x -= y;
    if (*x < 0) *x += mod;
}

void chmax(ll *x, ll y) {
    if (y > *x) *x = y;
}

void mulm(ll *x, ll y, ll mod) {
    *x *= y;
    if (*x >= mod) *x -= mod;
}

ll xo(ll i) {
    if ((i & 3) == 0) return i;
    if ((i & 3) == 1) return 1;
    if ((i & 3) == 2) return i + 1;
    return 0;
}

int main() {
    ll n;
    scanf("%lld", &n);
    ll tot = 0;
    vector_ll *data = (vector_ll *)malloc(n * sizeof(vector_ll));
    for (ll i = 0; i < n; i++) {
        ll k, a, x, y, m;
        scanf("%lld %lld %lld %lld %lld", &k, &a, &x, &y, &m);
        tot += k;
        vector_ll_init(&data[i]);
        vector_ll_push_back(&data[i], a);
        for (ll j = 2; j <= k; j++) {
            ll value = (data[i].data[data[i].size - 1] * x + y) % m;
            vector_ll_push_back(&data[i], value);
        }
    }

    std::set<pii> q;
    for (ll i = 0; i < n; i++) {
        pii temp = {data[i].data[0], {i, 0}};
        q.insert(temp);
    }

    vector_ll ans;
    vector_ll sol;
    vector_ll_init(&ans);
    vector_ll_init(&sol);
    ll p = 0;

    while (ans.size < tot) {
        auto it = q.lower_bound({p, {-1, -1}});
        if (it == q.end()) it = q.begin();
        ll v = it->first;
        p = v;
        pii o = it->second;
        vector_ll_push_back(&ans, v);
        vector_ll_push_back(&sol, {v, o.first + 1});
        q.erase(it);
        if (o.second + 1 < data[o.first].size) {
            pii new_elem = {data[o.first].data[o.second + 1], {o.first, o.second + 1}};
            q.insert(new_elem);
        }
    }

    ll bad = 0;
    for (ll i = 1; i < ans.size; i++) {
        if (ans.data[i - 1] > ans.data[i]) bad++;
    }
    printf("%lld\n", bad);
    if (tot <= 200000) {
        for (ll i = 0; i < sol.size; i++) {
            printf("%lld %lld\n", sol.data[i].first, sol.data[i].second);
        }
    }

    for (ll i = 0; i < n; i++) {
        vector_ll_free(&data[i]);
    }
    free(data);
    vector_ll_free(&ans);
    vector_ll_free(&sol);
    return 0;
}
