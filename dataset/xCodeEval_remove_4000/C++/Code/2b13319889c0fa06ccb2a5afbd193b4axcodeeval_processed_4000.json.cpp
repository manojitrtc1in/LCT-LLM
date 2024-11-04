







using namespace std;
















        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);












typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ll128;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;




template <typename TT, typename T>
void id11(map<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
}

void llin(ll &a)
{
    CIN(a);
}

void id7(V<ll> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void id3(V<t2> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void id13(V<t3> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void id8(V<t4> &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(V<ll> &v, ll count)
{
    id7(v, count);
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

t2 id4(ll a, ll b, ll g)
{
    if (!b) return t2(1, 0);
    ll q = a / b;
    ll r = a % b;
    t2 sol = id4(b, r, g);
    ll sx = get<0>(sol);
    ll sy = get<1>(sol);
    ll x = sy;
    ll y = sx - q * sy;
    return t2(x, y);
}

t2 id2(ll a, ll b)
{
    return id4(a, b, gcd(a, b));
}



ll mod_inv(ll x, ll mod)
{
    t2 result = id2(x, mod);
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









struct mint {
    ll x;
    ll mod;

    mint() {
        this->x = 0;
        this->mod = 0;
    }

    mint(ll x, ll mod) {
        this->x = x;
        this->x %= mod;
        this->mod = mod;
    }

    mint operator=(const mint& a) {
        this->x = a.x;
        this->mod = a.mod;
        return *this;
    }

    mint operator=(ll a) {
        this->x = a;
        this->x %= this->mod;
        return *this;
    }

    mint operator+=(const mint& a) {
        if (!this->mod) this->mod = a.mod;
        assert(this->mod == a.mod);
        this->x += a.x;
        if (this->x >= this->mod) this->x -= this->mod;
        return *this;
    }

    mint operator+=(ll a) {
        assert(a >= 0);
        this->x += a;
        if (this->x >= this->mod) this->x -= this->mod;
        if (this->x >= this->mod) this->x %= this->mod;
        return *this;
    }

    mint operator-=(const mint& a) {
        if (!this->mod) this->mod = a.mod;
        assert(this->mod == a.mod);
        this->x -= a.x;
        if (this->x < 0) this->x += this->mod;
        return *this;
    }

    

    mint operator-=(ll a) {
        assert(a >= 0);
        this->x -= a;
        while (this->x < 0) this->x += this->mod;
        return *this;
    }

    mint operator*=(const mint& a) {
        if (!this->mod) this->mod = a.mod;
        assert(this->mod == a.mod);
        this->x *= a.x;
        this->x %= this->mod;
        return *this;
    }

    mint operator*=(ll a) {
        assert(a >= 0);
        this->x *= a;
        this->x %= this->mod;
        return *this;
    }

    bool operator==(const mint &a) {
        if (this->mod != a.mod) return false;
        if (this->x != a.x) return false;
        return true;
    }

    bool operator==(ll a) {
        if (this->x != a) return false;
        return true;
    }

    bool operator!=(const mint &a) {
        return !(*this ==a);
    }

    bool operator!=(ll a) {
        return !(*this ==a);
    }

    void inv() {
        this->x = mod_inv(this->x, this->mod);
    }
};

mint operator+(const mint& a, const mint& b) {
    assert(a.mod == b.mod);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x += b.x;
    if (ret.x >= ret.mod) ret.x -= ret.mod;
    return ret;
}

mint operator+(const mint& a, ll b) {
    assert(b >= 0);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x += b;
    if (ret.x >= ret.mod) ret.x -= ret.mod;
    if (ret.x >= ret.mod) ret.x %= ret.mod;
    return ret;
}

mint operator-(const mint& a, const mint& b) {
    assert(a.mod == b.mod);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x -= b.x;
    if (ret.x < 0) ret.x += a.mod;
    return ret;
}



mint operator-(const mint& a, ll b) {
    assert(b >= 0);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x -= b;
    while (ret.x < 0) ret.x += a.mod;
    return ret;
}

mint operator*(const mint& a, const mint& b) {
    assert(a.mod == b.mod);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x *= b.x;
    ret.x %= ret.mod;
    return ret;
}

mint operator*(const mint& a, ll b) {
    assert(b >= 0);
    mint ret(0, a.mod);
    ret.x = a.x;
    ret.x *= b % ret.mod;
    ret.x %= ret.mod;
    return ret;
}

ostream& operator<<(ostream& os, const mint& a)
{
    os << a.x;
    return os;
};



mint mod_pow(ll base, ll exp, ll mod)
{
    mint ret(1LL, mod);

    for ( ; exp; ) {
        if (exp & 1LL) ret *= base;
        base = (base * base) % ret.mod;
        exp >>= 1;
    }

    return ret;
}



mint mod_pow(mint base, ll exp)
{
    mint ret(1LL, base.mod);

    for ( ; exp; ) {
        if (exp & 1LL) ret *= base;
        base = base * base;
        exp >>= 1;
    }

    return ret;
}

void id6(mint factorials[], mint inv_factorials[], ll size, ll mod)
{
    factorials[0].x = 1LL;
    rep (i, size) factorials[i].mod = mod;
    srep (i, 1, size) factorials[i] = factorials[i-1] * i;

    inv_factorials[size-1] = factorials[size-1];
    inv_factorials[size-1].inv();
    rep (i, size) inv_factorials[i].mod = mod;
    rrep (i, size-1) inv_factorials[i] = inv_factorials[i+1LL] * (i+1LL);
}


S mint factorials[XXX SZ];
S mint inv_factorials[XXX SZ];
id6(factorials, inv_factorials, XXX SZ, MOD);
mint binom(ll x, ll y, ll mod)
{
    assert(x >= y);
    mint ret(1, mod);
    ret *= factorials[x];
    ret *= inv_factorials[y];
    ret *= inv_factorials[x-y];
    return ret;
}












void _main();
int main()
{
    cout << setprecision(12);

    ios::sync_with_stdio(false);
    cin.tie(0);


    _main();
    return 0;
}
















mint id1(const V<ll> &alist, ll n)
{
    assert(n <= 20);

    mint ans(0, MOD);
    V<string> ss;

    rep (ptn, (1LL<<n)) {
        V<ll> cis, pis;
        rep (i, n) {
            if (ptn & (1LL<<i)) pis.pb(i);
            else cis.pb(i);
        }

        bool ng = false;

        ll prev = -1e18;
        rep (i, (ll)cis.size()-1) {
            ll diff = cis[i+1] - cis[i];
            if (diff < prev) ng = true;
            prev = diff;
        }

        prev = 1e18;
        rep (i, (ll)pis.size()-1) {
            ll diff = pis[i+1] - pis[i];
            if (diff > prev) ng = true;
            prev = diff;
        }

        ll psum = 0;
        for (auto i : pis) psum += alist[i];
        ll csum = 0;
        for (auto i : cis) csum += alist[i];
        if (psum <= csum) ng = true;

        if (ng) continue;

        string s(n, 'X');
        for (auto pi : pis) s[pi] = 'P';
        for (auto ci : cis) s[ci] = 'C';
        ss.pb(s);
        ans += 1LL;
    }

    sort(ss);
    debug_printf("---- id1 list\n");
    debug_print(ss);
    return ans;
}

V<ll> sums;
V<ll> hsums[2];

mint fpp(const V<ll> &alist, ll n)
{
    mint ret(0, MOD);

    ll left = 2;
    ll right = n;
    ll ok = n;
    while (left <= right) {
        ll now = (left + right) / 2LL;
        ll psum = sums[now];
        ll csum = sums[n] - sums[now];
        if (psum > csum) {
            ok = min(ok, now);
            right = now - 1LL;
        }
        else {
            left = now + 1LL;
        }
    }

    ret = n - ok + 1LL;

    debug_printf("---- fpp=%lld\n", ret.x);
    return ret;
}

mint id9(const V<ll> &alist, ll n)
{
    ll psum = alist[0] + alist[n-1];
    ll csum = sums[n-1] - sums[1];
    mint ret(0, MOD);
    if (psum > csum) ret = mint(1, MOD);
    debug_printf("---- id9=%lld\n", ret.x);
    return ret;
}

mint id12(const V<ll> &alist, ll n)
{
    mint ret(0, MOD);

    srep (psi, 2, n-1) {
        ll pbase = alist[0] + alist[n-1];
        ll cbase = sums[psi] - sums[1];

        ll left = psi;
        ll right = n-1;
        ll ok = -1;
        while (left <= right) {
            ll now = (left + right) / 2LL;
            ll pincr = hsums[psi&1LL][now] - hsums[psi&1LL][psi];
            pincr += sums[n-1] - sums[now];
            ll cincr = hsums[!(psi&1LL)][now] - hsums[!(psi&1LL)][psi];
            if (pbase + pincr > cbase + cincr) {
                ok = max(ok, now);
                left = now + 1LL;
            }
            else {
                right = now - 1LL;
            }
        }

        if (ok < 0) continue;
        ll len = ok - psi;
        ret += len / 2LL + 1LL;
    }

    debug_printf("---- id12=%lld\n", ret.x);
    return ret;
}

mint id0(const V<ll> &alist, ll n)
{
    ll psum = alist[0];
    ll csum = sums[n] - sums[1];
    mint ret(0, MOD);
    if (psum > csum) ret = mint(1, MOD);
    debug_printf("---- id0=%lld\n", ret.x);
    return ret;
}

mint id5(const V<ll> &alist, ll n)
{
    ll psum = alist[0] + alist[n-2];
    ll csum = sums[n-2] - sums[1] + alist[n-1];
    mint ret(0, MOD);
    if (psum > csum) ret = mint(1, MOD);
    debug_printf("---- id5=%lld\n", ret.x);
    return ret;
}

mint id10(const V<ll> &alist, ll n)
{
    mint ret(0, MOD);

    srep (psi, 2, n-2) {
        ll pbase = alist[0] + alist[n-2];
        ll cbase = sums[psi] - sums[1] + alist[n-1];

        ll left = psi;
        ll right = n-2;
        ll ok = -1;
        while (left <= right) {
            ll now = (left + right) / 2LL;
            ll pincr = hsums[psi&1LL][now] - hsums[psi&1LL][psi];
            pincr += sums[n-2] - sums[now];
            ll cincr = hsums[!(psi&1LL)][now] - hsums[!(psi&1LL)][psi];
            if (pbase + pincr > cbase + cincr) {
                ok = max(ok, now);
                left = now + 1LL;
            }
            else {
                right = now - 1LL;
            }
        }

        if (ok < 0) continue;
        ll len = ok - psi;
        ret += len / 2LL + 1LL;
    }

    debug_printf("---- id10=%lld\n", ret.x);
    return ret;
}

mint fcccp(const V<ll> &alist, ll n)
{
    ll psum = alist[n-1];
    ll csum = sums[n] - psum;
    mint ret(0, MOD);
    if (psum > csum) ret = 1;
    return ret;
}

mint fcxp(const V<ll> &alist, ll n)
{
    mint ret(0, MOD);

    srep (psi, 1, n-1) {
        ll pbase = alist[n-1];
        ll cbase = sums[psi];

        ll left = psi;
        ll right = n-1;
        ll ok = -1;
        while (left <= right) {
            ll now = (left + right) / 2LL;
            ll pincr = hsums[psi&1LL][now] - hsums[psi&1LL][psi];
            pincr += sums[n-1] - sums[now];
            ll cincr = hsums[!(psi&1LL)][now] - hsums[!(psi&1LL)][psi];
            if (pbase + pincr > cbase + cincr) {
                ok = max(ok, now);
                left = now + 1LL;
            }
            else {
                right = now - 1LL;
            }
        }

        if (ok < 0) continue;
        ll len = ok - psi;
        ret += len / 2LL + 1LL;
    }

    debug_printf("---- fcxp=%lld\n", ret.x);
    return ret;
}

mint id14(const V<ll> &alist, ll n)
{
    ll psum = alist[n-2];
    ll csum = sums[n] - psum;
    mint ret(0LL, MOD);
    if (psum > csum) ret = 1;
    return ret;
}

mint id15(const V<ll> &alist, ll n)
{
    mint ret(0, MOD);

    srep (psi, 1, n-2) {
        ll pbase = alist[n-2];
        ll cbase = sums[psi] + alist[n-1];

        ll left = psi;
        ll right = n-2;
        ll ok = -1;
        while (left <= right) {
            ll now = (left + right) / 2LL;
            ll pincr = hsums[psi&1LL][now] - hsums[psi&1LL][psi];
            pincr += sums[n-2] - sums[now];
            ll cincr = hsums[!(psi&1LL)][now] - hsums[!(psi&1LL)][psi];
            if (pbase + pincr > cbase + cincr) {
                ok = max(ok, now);
                left = now + 1LL;
            }
            else {
                right = now - 1LL;
            }
        }

        debug_printf("psi=%lld ok=%lld\n", psi, ok);
        if (ok < 0) continue;
        ll len = ok - psi;
        ret += len / 2LL + 1LL;
    }

    debug_printf("--- id15=%lld\n", ret.x);
    return ret;
}

void solve()
{
    ll n; llin(n);
    V<ll> alist; llina(alist, n);

    debug_printf("--------------------------------------- solve\n");

    


    if (n == 1) {
        cout << 1 << endl;
        return;
    }
    if (n == 2) {
        if (alist[0] == alist[1]) cout << 1 << endl;
        else cout << 2 << endl;
        return;
    }
    if (n <= 6) {
        cout << id1(alist, n) << endl;
        return;
    }

    


    sums.clear();
    ll sum = 0;
    sums.pb(sum);
    for (auto a : alist) {
        sum += a;
        sums.pb(sum);
    }

    rep (i, 2) hsums[i].clear();
    ll hsum[2] = {};
    rep (i, 2) hsums[i].pb(hsum[i]);
    rep (i, n) {
        hsum[i&1LL] += alist[i];
        rep (j, 2) hsums[j].pb(hsum[j]);
    }
    rep (i, 2) {
        debug_printf("---- hsums[%lld]\n", i);
        debug_print(hsums[i]);
    }

    mint ans(0, MOD);

    


    

    ans += fpp(alist, n);

    

    ans += id9(alist, n);

    

    ans += id12(alist, n);

    

    ans += id0(alist, n);

    

    ans += id5(alist, n);

    

    ans += id10(alist, n);

    


    

    ans += fcccp(alist, n);

    

    ans += fcxp(alist, n);

    

    ans += id14(alist, n);

    

    ans += id15(alist, n);

    if (n < 20) debug_printf("---- id1=%lld\n", id1(alist, n));

    debug_printf("---ans\n");
    cout << ans << endl;
}

void _main()
{
    ll t; llin(t);
    rep (i, t) solve();
}



