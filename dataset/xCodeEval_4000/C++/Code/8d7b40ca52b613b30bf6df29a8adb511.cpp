


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
typedef tuple<int, int> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
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









template <typename T>
struct SegmentTree {
    T *nodes;
    t2 *ranges;  

    ll nodecount;
    ll itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(ll itemcount, T unit, T op(T, T)) {
        ll orig_itemcount = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < orig_itemcount) this->itemcount *= 2LL;
        nodecount = this->itemcount * 2 - 1;
        nodes = new T[nodecount];
        ranges = new t2[nodecount];
        this->unit = unit;
        this->op = op;

        ll start = 0LL;
        ll end = this->itemcount;
        ll len = this->itemcount;

        rep (i, nodecount) {
            nodes[i] = unit;
            ranges[i] = t2(start, end);
            if (end >= this->itemcount) {
                len /= 2LL;
                start = 0LL;
                end = len;
            }
            else {
                start = end;
                end = start + len;
            }
        }
    }

    virtual ~SegmentTree() {
        delete [] nodes;
        delete [] ranges;
    }

    virtual void initialize(const T arr[], ll cnt) {
        memcpy(nodes + nodecount / 2LL, arr, sizeof(T) * cnt);
        rrep (i, nodecount / 2LL) {
            nodes[i] = op(nodes[i * 2LL + 1LL], nodes[i * 2LL + 2LL]);
        }
    }

    virtual void initialize(const T val) {
        T *vals = new T[sizeof(T) * itemcount];
        rep (i, itemcount) vals[i] = val;
        initialize(vals, itemcount);
        delete [] vals;
    }

    void update(ll k, T v) {
        ll idx = k + itemcount - 1LL;
        nodes[idx] = v;
        idx = (idx - 1LL) / 2LL;

        for ( ; idx >= 0; idx = (idx - 1LL) / 2LL) {
            nodes[idx] = op(nodes[idx * 2LL + 1LL],
                            nodes[idx * 2LL + 2LL]);
            if (!idx) break;
        }
    }

    

    virtual T query(ll start, ll end) const {
        return _query(start, end, 0LL);
    }

    virtual T _query(ll start, ll end, ll idx) const {
        ll rstart = get<0>(ranges[idx]);
        ll rend = get<1>(ranges[idx]);

        if (start <= rstart && rend <= end) {
            return nodes[idx];
        }
        if (rend <= start || end <= rstart) {
            return unit;
        }
        T left = _query(start, end, idx * 2LL + 1LL);
        T right = _query(start, end, idx * 2LL + 2LL);
        return op(left, right);
    }

    T query_fast(ll start, ll end) const {
        start += nodecount / 2LL;
        end += nodecount / 2LL;
        T lval = unit;
        T rval = unit;
        for ( ; start < end; start >>= 1LL, end >>= 1LL) {
            if (!(start & 1LL)) lval = op(lval, nodes[start]);
            if (!(end & 1LL)) rval = op(rval, nodes[end-1]);
            end--;
        }
        return op(lval, rval);
    }

    virtual T all() {
        return nodes[0];
    }
};




template <typename T1, typename T2>
struct SegmentTreeLazy : public SegmentTree<T1> {
    T2 *lzvals;
    bool *lzvalids;
    T2 unit_upd;
    void (*op_t1upd)(T1&, T2);
    T2 (*op_t2div)(T2);
    T2 (*op_t2mlt)(T2, ll);
    void (*op_t2upd)(T2&, T2);

    SegmentTreeLazy(ll itemcount, T1 unit_monoid, T2 unit_upd,
                    T1 op_monoid(T1, T1), void op_t1upd(T1&, T2),
                    T2 op_t2div(T2), T2 op_t2mlt(T2, ll),
                    void op_t2upd(T2&, T2))
        : SegmentTree<T1>(itemcount, unit_monoid, op_monoid) {
        this->lzvals = new T2[this->nodecount];
        this->lzvalids = new bool[this->nodecount];
        this->unit_upd = unit_upd;
        this->op_t1upd = op_t1upd;
        this->op_t2div = op_t2div;
        this->op_t2mlt = op_t2mlt;
        this->op_t2upd = op_t2upd;
        rep (i, this->nodecount) this->lzvals[i] = unit_upd;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
    }

    virtual ~SegmentTreeLazy() {
        delete [] lzvals;
        delete [] lzvalids;
    }

    virtual void initialize(const T1 arr[], ll cnt) {
        rep (i, this->nodecount) this->lzvals[i] = this->unit_upd;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
        SegmentTree<T1>::initialize(arr, cnt);
    }

    

    void eval(ll nodeidx) {
        if (!lzvalids[nodeidx]) return;

        op_t1upd(this->nodes[nodeidx], lzvals[nodeidx]);

        if (nodeidx * 2LL + 2LL < this->nodecount) {
            T2 downval = op_t2div(lzvals[nodeidx]);
            op_t2upd(lzvals[nodeidx * 2LL + 1LL], downval);
            op_t2upd(lzvals[nodeidx * 2LL + 2LL], downval);
            lzvalids[nodeidx * 2LL + 1LL] = lzvalids[nodeidx * 2LL + 2LL] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->unit_upd;
    }

    void update(ll start, ll end, T2 val) {
        _update(start, end, val, 0LL);
    }

    void _update(ll start, ll end, T2 val, ll nodeidx) {
        eval(nodeidx);

        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);
        if (end <= rstart || rend <= start) return;

        if (start <= rstart && rend <= end) {
            op_t2upd(lzvals[nodeidx], op_t2mlt(val, rend - rstart));
            lzvalids[nodeidx] = true;
            eval(nodeidx);
        }
        else {
            _update(start, end, val, nodeidx * 2LL + 1LL);
            _update(start, end, val, nodeidx * 2LL + 2LL);
            this->nodes[nodeidx] = this->op(this->nodes[nodeidx * 2LL + 1LL],
                                            this->nodes[nodeidx * 2LL + 2LL]);
        }
    }

    

    virtual T1 query(ll start, ll end) {
        return _query(start, end, 0LL);
    }

    virtual T1 _query(ll start, ll end, ll nodeidx) {
        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);

        eval(nodeidx);

        if (start <= rstart && rend <= end) {
            return this->nodes[nodeidx];
        }
        if (rend <= start || end <= rstart) {
            return this->unit;
        }
        T1 left = _query(start, end, nodeidx * 2LL + 1LL);
        T1 right = _query(start, end, nodeidx * 2LL + 2LL);
        return this->op(left, right);
    }

    T1 query_fast_lazy(int start, int end) {
        queue<ll> q;
        q.push(0);

        while (q.size()) {
            ll nodeidx = q.front(); q.pop();
            eval(nodeidx);

            int rstart = get<0>(this->ranges[nodeidx]);
            int rend = get<1>(this->ranges[nodeidx]);

            if (start <= rstart && rend <= end) continue;
            if (rend <= start || end <= rstart) continue;
            q.push((nodeidx<<1) + 1);
            q.push((nodeidx<<1) + 2);
        }

        return this->query_fast(start, end);
    }

    virtual T1 all() {
        eval(0);
        return SegmentTree<T1>::all();
    }
};




#if 0




ll op_monoid(ll x, ll y)
{
    return max(x, y);
}
void op_t1upd(ll &x, ll y)
{
    x += y;
}
ll op_t2div(ll x)
{
    return x;
}
ll op_t2mlt(ll x, ll y)
{
    return x;
}
void op_t2upd(ll& x, ll y)
{
    x += y;
}

SegmentTreeLazy<ll, ll> tree(itemcount a---- a, -1e18, 0,
                             op_monoid, op_t1upd,
                             op_t2div, op_t2mlt, op_t2upd);
tree.initialize(0);




t2 op_monoid(t2 x, t2 y)
{
    ll val1 = get<0>(x);
    ll len1 = get<1>(x);
    ll val2 = get<0>(y);
    ll len2 = get<1>(y);
    return t2(val1 + val2, len1 + len2);
}
void op_t1upd(t2& x, ll y)
{
    ll val = get<0>(x);
    ll len = get<1>(x);
    val += y * len;
    x = t2(val, len);
}
ll op_t2div(ll x)
{
    return x;
}
ll op_t2mlt(ll x, ll cnt)
{
    return x;
}
void op_t2upd(ll& x, ll y)
{
    x += y;
}

SegmentTreeLazy<t2, ll> tree(itemcount a---- a, t2(0, 0), 0,
                             op_monoid, op_t1upd,
                             op_t2div, op_t2mlt, op_t2upd);
tree.initialize(t2(0, 1));





ll op_monoid(ll x, ll y)
{
    return x + y;
}
void op_t1upd(ll &x, ll y)
{
    x += y;
}
ll op_t2div(ll x)
{
    return x / 2LL;
}
ll op_t2mlt(ll x, ll y)
{
    return x * y;
}
void op_t2upd(ll& x, ll y)
{
    x += y;
}

SegmentTreeLazy<ll, ll> tree(itemcount a---- a, 0, 0,
                             op_monoid, op_t1upd,
                             op_t2div, op_t2mlt, op_t2upd);




t2 op_monoid(t2 x, t2 y)
{
    ll val1 = get<0>(x);
    ll len1 = get<1>(x);
    ll val2 = get<0>(y);
    ll len2 = get<1>(y);
    return t2(val1 + val2, len1 + len2);
}
void op_t1upd(t2& x, ll y)
{
    if (y == -1e18) return;
    ll len = get<1>(x);
    x = t2(y * len, len);
}
ll op_t2div(ll x)
{
    return x;
}
ll op_t2mlt(ll x, ll cnt)
{
    return x;
}
void op_t2upd(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}

SegmentTreeLazy<t2, ll> tree(itemcount a---- a, t2(0, 0), -1e18,
                             op_monoid, op_t1upd,
                             op_t2div, op_t2mlt, op_t2upd);
tree.initialize(t2(0, 1));




ll op_monoid(ll x, ll y)
{
    return x + y;
}
void op_t1upd(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}
ll op_t2div(ll x)
{
    return x / 2LL;
}
ll op_t2mlt(ll x, ll cnt)
{
    return x * cnt;
}
void op_t2upd(ll& x, ll y)
{
    if (y == -1e18) return;
    x = y;
}

SegmentTreeLazy<ll, ll> tree(itemcount a---- a, 0, -1e18,
                             op_monoid, op_t1upd,
                             op_t2div, op_t2mlt, op_t2upd);

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
















#define SZK  (103LL)
#define SZN  (35002LL)

ll op_monoid(ll x, ll y)
{
    return min(x, y);
}
void op_t1upd(ll &x, ll y)
{
    x += y;
}
ll op_t2div(ll x)
{
    return x;
}
ll op_t2mlt(ll x, ll y)
{
    return x;
}
void op_t2upd(ll& x, ll y)
{
    x += y;
}

void _main()
{
    ll n; llin(n);
    ll k; llin(k);
    V<ll> alist; llina(alist, n);

    SegmentTreeLazy<ll, ll> tree(SZN, 1e18, 0, op_monoid, op_t1upd,
                                 op_t2div, op_t2mlt, op_t2upd);

    S ll dp[SZK][SZN];
    rep (i, SZK) rep (j, SZN) dp[i][j] = 1e18;
    rep (i, SZK) dp[i][0] = 0;

    srep (i, 1, k+1) {
        tree.initialize(dp[i-1], SZN);
        map<ll, ll> poss;

        rep (j, n) {
            if (poss.find(alist[j]) != poss.end()) {
                ll prev = poss[alist[j]];
                tree.update(0, prev + 1, j - prev);
            }
            poss[alist[j]] = j;
            

            dp[i][j+1] = tree.query(0, j+1);
        }
    }

    cout << dp[k][n] << endl;
}



