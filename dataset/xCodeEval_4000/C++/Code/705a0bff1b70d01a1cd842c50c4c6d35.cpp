


#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

using namespace std;




#define DEBUG 0

#define pb push_back
#define V vector
#define S static

#define rep(i,n) for(ll i=0LL; i<n; ++i)
#define srep(i,s,n) for(ll i=s; i<n; ++i)
#define rrep(i,n) for(ll i=n-1LL; i>=0LL; --i)
#define cfor(i,x) for(const auto & (i) : (x))
#define ALL(a) (a).begin(),(a).end()
#define RALL(a) (a).rbegin(),(a).rend()
#define CIN(x) do { \
        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);
#if DEBUG
#define debug_print(...) _debug_print(__VA_ARGS__)
#define debug_printf(...) printf(__VA_ARGS__)
#define debug_print_time _debug_print_time
#else 

#define debug_print(...)
#define debug_printf(...)
#define debug_print_time
#endif 


typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ll128;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
typedef tuple<ll, ll, ll, ll, ll, ll> t6;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;




template <typename TT, typename T>
void incr_m(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void llinl1(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void llinl2(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void llinl3(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void llinl4(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    llinl1(v, count);
}

template <typename T>
void sort(V<T> &v)
{
    sort(v.begin(), v.end());
}

template <typename T>
void sort_reverse(V<T> &v)
{
    sort(v.begin(), v.end(), greater<T>());
}

t2 _ext_gcd(ll a, ll b, ll g)
{
    if (!b) return t2(1, 0);
    ll q = a / b;
    ll r = a % b;
    t2 sol = _ext_gcd(b, r, g);
    ll sx = get<0>(sol);
    ll sy = get<1>(sol);
    ll x = sy;
    ll y = sx - q * sy;
    return t2(x, y);
}

t2 ext_gcd(ll a, ll b)
{
    return _ext_gcd(a, b, gcd(a, b));
}



ll mod_inv(ll x, ll mod)
{
    t2 result = ext_gcd(x, mod);
    ll ret = get<0>(result);
    while (ret < 0) ret += mod;
    ret %= mod;
    return ret;
}

ll msec()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    ll ret = 0;
    ret += tv.tv_sec * 1000LL;
    ret += tv.tv_usec / 1000LL;
    return ret;
}


template <typename T>
void _debug_print(T x)
{
    cout << x << " ";
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "(" << x1 << ", " << x2 << ") ";
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ") ";
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << ") ";
}

void _debug_print(const t6 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    ll x5 = get<4>(x);
    ll x6 = get<5>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ", " << x4 << ", "<< x5 << ", " << x6 << ") ";
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
    cout << endl;
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) _debug_print(x);
    cout << endl;
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) _debug_print(x);
    cout << endl;
}

template <typename TT, typename T>
void _debug_print(const map<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "K=";
        _debug_print(k);
        cout << " V=";
        _debug_print(v);
        cout << endl;
    }
}






S ll mintmod = 998244353LL;

struct mint {
    ll x;

    mint() {
        this->x = 0;
    }

    mint(const mint &other) {
        this->x = other.x;
    }

    mint(ll x) {
        this->x = x % mintmod;
    }

    void operator=(const mint& a) {
        this->x = a.x;
    }

    void operator=(ll a) {
        this->x = a % mintmod;
    }

    void operator+=(const mint& a) {
        this->x += a.x;
        if (this->x >= mintmod) this->x -= mintmod;
    }

    void operator+=(ll a) {
        if (a < 0) this->x -= abs(a) % mintmod;
        else this->x += a;
        if (this->x < 0) this->x += mintmod;
        if (this->x >= mintmod) this->x -= mintmod;
        if (this->x >= mintmod) this->x %= mintmod;
    }

    void operator-=(const mint& a) {
        this->x -= a.x;
        if (this->x < 0) this->x += mintmod;
    }

    

    void operator-=(ll a) {
        if (a < 0) {
            this->x += abs(a) % mintmod;
            if (this->x >= mintmod) this->x -= mintmod;
            return;
        }
        this->x -= a;
        while (this->x < 0) this->x += mintmod;
    }

    void operator*=(const mint& a) {
        this->x *= a.x;
        this->x %= mintmod;
    }

    void operator*=(ll a) {
        assert(a >= 0);
        this->x *= a % mintmod;
        this->x %= mintmod;
    }

    bool operator==(const mint &a) {
        if (this->x != a.x) return false;
        return true;
    }

    bool operator==(ll a) {
        if (this->x != a % mintmod) return false;
        return true;
    }

    bool operator!=(const mint &a) {
        return !(*this == a);
    }

    bool operator!=(ll a) {
        return !(*this == a);
    }

    void inv() {
        this->x = mod_inv(this->x, mintmod);
    }
};

mint operator+(const mint& a, const mint& b) {
    mint ret = a;
    ret.x += b.x;
    if (ret.x >= mintmod) ret.x -= mintmod;
    return ret;
}

mint operator+(const mint& a, ll b) {
    mint ret = a;
    if (b < 0) ret.x -= abs(b) % mintmod;
    else ret.x += b;
    if (ret.x < 0) ret.x += mintmod;
    if (ret.x >= mintmod) ret.x -= mintmod;
    if (ret.x >= mintmod) ret.x %= mintmod;
    return ret;
}

mint operator-(const mint& a, const mint& b) {
    mint ret = a;
    ret.x -= b.x;
    if (ret.x < 0) ret.x += mintmod;
    return ret;
}



mint operator-(const mint& a, ll b) {
    mint ret = a;
    if (b < 0) {
        ret.x += abs(b) % mintmod;
        if (ret.x >= mintmod) ret.x -= mintmod;
        return ret;
    }
    ret.x -= b;
    while (ret.x < 0) ret.x += mintmod;
    return ret;
}

mint operator*(const mint& a, const mint& b) {
    mint ret = a;
    ret.x *= b.x;
    ret.x %= mintmod;
    return ret;
}

mint operator*(const mint& a, ll b) {
    assert(b >= 0);
    mint ret = a;
    ret.x *= b % mintmod;
    ret.x %= mintmod;
    return ret;
}

ostream& operator<<(ostream& os, const mint& a)
{
   os << a.x;
   return os;
}



mint mod_pow(ll base, ll exp, ll mod)
{
    mint ret = 1;

    for ( ; exp; ) {
        if (exp & 1LL) ret *= base;
        base = (base * base) % mod;
        exp >>= 1;
    }

    return ret;
}



mint mod_pow(mint base, ll exp)
{
    mint ret = 1;

    for ( ; exp; ) {
        if (exp & 1LL) ret *= base;
        base = base * base;
        exp >>= 1;
    }

    return ret;
}

void make_factorial(mint factorials[], mint inv_factorials[], ll size)
{
    factorials[0] = 1;
    srep (i, 1, size) factorials[i] = factorials[i-1] * i;

    inv_factorials[size-1] = factorials[size-1];
    inv_factorials[size-1].inv();
    rrep (i, size-1) inv_factorials[i] = inv_factorials[i+1LL] * (i+1LL);
}

#if 0
S mint factorials[XXX SZ];
S mint inv_factorials[XXX SZ];
mint binom(ll x, ll y)
{
    assert(x >= y);
    mint ret = 1;
    ret *= factorials[x];
    ret *= inv_factorials[y];
    ret *= inv_factorials[x-y];
    return ret;
}

make_factorial(factorials, inv_factorials, XXX SZ);
#endif








void _main();
int main()
{
    cout << setprecision(12);
#if !DEBUG
    ios::sync_with_stdio(false);
    cin.tie(0);
#endif

    _main();
    return 0;
}


























mint base;
mint base_inv;
mint h;
ll k;
ll lens[6] = {33, 33, 49, 81, 145, 273};
V<mint> pbases;
set<t6> oks;

void solve4()
{
    ll n = (1LL<<k);
    ll ptnend = (1LL<<(n-1LL));

    rep (ptn, ptnend) {
        queue<ll> q, nq;
        srep (i, 1, n+1) q.push(i);
        mint total = 0;
        ll pbidx = k;
        ll pptn = ptn;

        S ll ans[10000];

        rep (xx, 1000000) {
            if (q.empty()) {
                if (nq.size() >= 2) {
                    while (nq.size()) {
                        ll a = nq.front(); nq.pop();
                        q.push(a);
                    }
                    pbidx--;
                }
                else {
                    assert(nq.size() == 1);
                    ll a = nq.front(); nq.pop();
                    total += a;
                    ans[a] = 0;
                    break;
                }
            }

            assert(q.size() >= 2);

            ll a = q.front(); q.pop();
            ll b = q.front(); q.pop();
            if (pptn & 1LL) {
                total += a * pbases[pbidx];
                ans[a] = (1LL<<(pbidx-1LL));
                nq.push(b);
            }
            else {
                total += b * pbases[pbidx];
                ans[b] = (1LL<<(pbidx-1LL));
                nq.push(a);
            }

            pptn >>= 1LL;
        }

        debug_printf("----- total = %lld\n", total.x);

        if (total == h) {
            srep (i, 1, n+1) cout << ans[i]+1 << " ";
            cout << endl;
            return;
        }
    }

    cout << -1 << endl;
}
















ll ans5[100];
typedef tuple<int, int, int, int> lsss;

void set_selected(t6 &selected, ll lv, ll lose)
{
    ll s[6]; tie(s[0], s[1], s[2], s[3], s[4], s[5]) = selected;
    s[5-lv] = lose;
    selected = t6(s[0], s[1], s[2], s[3], s[4], s[5]);
}

void clear_selected(t6 &selected, ll lv)
{
    ll s[6]; tie(s[0], s[1], s[2], s[3], s[4], s[5]) = selected;
    s[5-lv] = -1;
    selected = t6(s[0], s[1], s[2], s[3], s[4], s[5]);
}

bool check_selected(const t6 &selected, ll lv)
{
    auto iter = oks.lower_bound(selected);
    if (iter == oks.end()) return false;
    ll s[6]; tie(s[0], s[1], s[2], s[3], s[4], s[5]) = selected;
    ll f[6]; tie(f[0], f[1], f[2], f[3], f[4], f[5]) = *iter;
    rep (i, 6-lv) if (s[i] != f[i]) return false;
    return true;
}

ll dddd = 0;
ll mmmm = 0;

bool dfs(t6 &selected, const V<ll> &wins, ll lv)
{
    dddd++;
    if (lv == 0) {
        assert(wins.size() == 1);
        set_selected(selected, 0, wins[0]);
        if (check_selected(selected, 0)) {
            ans5[wins[0]] = 1;
            return true;
        }
        clear_selected(selected, lv);
        return false;
    }

    ll gamecnt = (1LL<<(lv-1LL));
    ll ptns = (1LL<<gamecnt);
    S bool ngs[300];
    memset(ngs, 0, sizeof(ngs));

    rep (ptn, ptns) {
        mmmm++;
        ll pptn = ptn;
        V<ll> nwins;
        V<ll> loses;
        ll lose = 0;
        rep (i, gamecnt) {
            if (pptn & 1LL) lose += wins[i*2+1];
            else lose += wins[i*2];
            pptn >>= 1LL;
        }
        if (ngs[lose]) continue;
        set_selected(selected, lv, lose);
        if (check_selected(selected, lv)) {
            pptn = ptn;
            rep (i, gamecnt) {
                if (pptn & 1LL) {
                    nwins.pb(wins[i*2]);
                    loses.pb(wins[i*2+1]);
                }
                else {
                    nwins.pb(wins[i*2+1]);
                    loses.pb(wins[i*2]);
                }
                pptn >>= 1LL;
            }
            if (dfs(selected, nwins, lv-1)) {
                cfor (j, loses) ans5[j] = gamecnt + 1LL;
                return true;
            }
        }
        else {
            ngs[lose] = true;
        }
    }

    clear_selected(selected, lv);
    return false;
}

void solve()
{
    set<lsss> bottoms;
    rep (i, lens[5]) rep (j, lens[4]) rep (k, lens[3]) {
        mint x = 0;
        x += i * pbases[5];
        x += j * pbases[4];
        x += k * pbases[3];
        bottoms.insert(lsss(x.x, i, j, k));
    }

    rep (i, lens[0]) rep (j, lens[1]) rep (k, lens[2]) {
        mint x = 0;
        x += i * pbases[0];
        x += j * pbases[1];
        x += k * pbases[2];
        mint target = h - x;
        for (auto iter = bottoms.lower_bound(lsss(target.x, -1, -1, -1));
             iter != bottoms.end() && get<0>(*iter) == target.x;
             iter++) {
            oks.insert(t6(get<1>(*iter), get<2>(*iter), get<3>(*iter), k, j, i));
        }
    }

    debug_printf("---- oks (size=%zu)\n", oks.size());
    debug_print(oks);

    t6 selected = t6(-1, -1, -1, -1, -1, -1);
    V<ll> wins; srep (i, 1, 33) wins.pb(i);
    if (dfs(selected, wins, 5)) {
        srep (i, 1, 33) cout << ans5[i] << " ";
        cout << endl;
        return;
    }

    debug_printf("---- dddd=%lld mmmm=%lld\n", dddd, mmmm);

    cout << -1 << endl;
}

void _main()
{
    llin(k);
    ll base_orig; llin(base_orig);
    ll h_orig; llin(h_orig);

    base = base_orig;
    base_inv = base; base_inv.inv();
    h = h_orig;
    h *= base_inv;

    pbases.pb(mint(1));
    mint pnow = base;
    rep (i, 10) {
        pbases.pb(pnow);
        pnow = pnow * pnow;
    }
    debug_printf("---- pbases\n");
    debug_print(pbases);

    if (k <= 4) solve4();
    else solve();
}



