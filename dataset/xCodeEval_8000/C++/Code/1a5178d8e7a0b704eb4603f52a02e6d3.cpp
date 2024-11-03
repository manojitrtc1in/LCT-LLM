


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
#define rfrep(i,f,n) for(ll i=n-1LL; i>=f; --i)
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


typedef int ll;
typedef unsigned int ull;
typedef tuple<ll, ll> t2;
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

template <typename T1, typename T2>
void _debug_print(tuple<T1, T2> x)
{
    T1 x1 = get<0>(x);
    T2 x2 = get<1>(x);
    cout << "(" << x1 << ", " << x2 << ") ";
}

template <typename T1, typename T2, typename T3>
void _debug_print(tuple<T1, T2, T3> x)
{
    T1 x1 = get<0>(x);
    T2 x2 = get<1>(x);
    T3 x3 = get<2>(x);
    cout << "(" << x1 << ", " << x2 << ", " << x3 << ") ";
}

template <typename T1, typename T2, typename T3, typename T4>
void _debug_print(tuple<T1, T2, T3, T4> x)
{
    T1 x1 = get<0>(x);
    T2 x2 = get<1>(x);
    T3 x3 = get<2>(x);
    T4 x4 = get<3>(x);
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

    virtual void initialize(const T1 val) {
        T1 *vals = new T1[sizeof(T1) * this->itemcount];
        rep (i, this->itemcount) vals[i] = val;
        initialize(vals, this->itemcount);
        delete [] vals;
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













#define POW_ANCESTOR_MAXSIZE   20






void make_pow_ancestor(const ll parent[], ll n,
                       ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE])
{
    rep (i, n+1) pow_ancestor[i][0] = parent[i];

    for (ll pow2 = 1; pow2 < POW_ANCESTOR_MAXSIZE; ++pow2) {
        rep (i, n+1) {
            ll prev = pow_ancestor[i][pow2-1];
            pow_ancestor[i][pow2] = pow_ancestor[prev][pow2-1];
        }
    }
}

ll get_common_ancestor(ll n, ll x, ll y,
                       const ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE],
                       const ll level[])
{
    if (level[x] < level[y]) {
        ll diff = level[y] - level[x];
        for ( ; diff; ) {
            ll bit = diff & -diff;
            y = pow_ancestor[y][(int)log2(bit)];
            diff -= bit;
        }
    }
    else {
        ll diff = level[x] - level[y];
        for ( ; diff; ) {
            ll bit = diff & -diff;
            x = pow_ancestor[x][(int)log2(bit)];
            diff -= bit;
        }
    }

    if (x == y) return x;

    rrep (i, (int)log2(n)+1) {
        if (pow_ancestor[x][i] != pow_ancestor[y][i]) {
            x = pow_ancestor[x][i];
            y = pow_ancestor[y][i];
        }
    }

    return pow_ancestor[x][0];
}





struct HLD {
    ll n;
    ll *v_to_order;
    ll *order_to_v;
    ll *droots;
    const ll *parents;
    const V<ll> *children;
    const ll *levels;
    const ll *subsizes;

    HLD(const ll *parents, const V<ll> *children, const ll *levels, const ll *subsizes, ll n, ll root) {
        this->n = n;
        this->v_to_order = new ll[n+3];
        this->order_to_v = new ll[n+3];
        this->droots = new ll[n+3];
        this->parents = parents;
        this->children = children;
        this->levels = levels;
        this->subsizes = subsizes;

        ll order = 0;
        _dfs(root, order, root);
    }

    ~HLD() {
        delete [] this->droots;
        delete [] this->v_to_order;
        delete [] this->order_to_v;
    }

    void _dfs(ll v, ll &order, ll droot) {
        v_to_order[v] = order;
        order_to_v[order] = v;
        order++;
        droots[v] = droot;

        if (children[v].empty()) return;

        ll maxcnt = -1;
        ll maxcv = -1;
        for (auto cv : children[v]) {
            if (maxcnt < subsizes[cv]) {
                maxcnt = subsizes[cv];
                maxcv = cv;
            }
        }

        _dfs(maxcv, order, droot);

        for (auto cv : children[v]) {
            if (cv == maxcv) continue;
            _dfs(cv, order, cv);
        }
    }

    

    

    V<t2> ranges(ll v0, ll v1, const ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE]) {
        ll av = get_common_ancestor(n, v0, v1, pow_ancestor, levels);
        V<t2> cand;
        V<ll> svs;
        svs.pb(v0); svs.pb(v1);

        for (auto v : svs) {
            while (true) {
                ll nv = droots[v];
                if (levels[nv] <= levels[av]) {
                    cand.pb(t2(v_to_order[av], v_to_order[v]));
                    break;
                }
                cand.pb(t2(v_to_order[nv], v_to_order[v]));
                v = parents[nv];
            }
        }

        sort(cand);
        assert(cand.size());
        t2 prange = cand[0];
        V<t2> ret;

        for (auto range : cand) {
            ll pleft, pright; tie(pleft, pright) = prange;
            ll left, right; tie(left, right) = range;
            assert(pleft <= pright);
            assert(left <= right);
            if (pright < left) {
                ret.pb(prange);
                prange = range;
                continue;
            }

            if (pleft <= left && right <= pright) {
                ;
            }
            else if (left <= pleft && pright <= right) {
                prange = range;
            }
            else {
                assert(false);
            }
        }

        ret.pb(prange);

        return ret;
    }
};








void make_parental_relation(const V<t2> edges[], ll root, ll n,
                            ll parents[], V<ll> children[], ll levels[], ll subsizes[])
{
    queue<ll> q;
    bool *checked = new bool[n+1];
    memset(checked, 0, sizeof(bool) * (n+1));
    V<ll> leaves;

    q.push(root);
    checked[root] = true;
    parents[root] = root;
    levels[root] = 0LL;

    while(q.size()) {
        ll v = q.front(); q.pop();
        bool leaf = true;
        for (auto [nv, nx] : edges[v]) {
            if (checked[nv]) continue;
            leaf = false;
            q.push(nv);
            checked[nv] = true;
            parents[nv] = v;
            children[v].pb(nv);
            levels[nv] = levels[v] + 1LL;
        }
        if (leaf) leaves.pb(v);
    }

    ll *rrefs = new ll[n+1];
    rep (v, n+1) rrefs[v] = children[v].size();
    rep (v, n+1) subsizes[v] = 1;
    assert(q.empty());
    for (auto v : leaves) q.push(v);

    while (q.size()) {
        ll v = q.front(); q.pop();
        ll pv = parents[v];
        if (v == pv) continue;
        subsizes[pv] += subsizes[v];
        rrefs[pv]--;
        if (rrefs[pv]) continue;
        q.push(pv);
    }

    delete [] rrefs;
    delete [] checked;
}





struct UnionFind
{
    ull *parent, *count, *rank;

    UnionFind() {
        create(1);
    }

    UnionFind(ull n) {
        create(n);
    }

    ~UnionFind() {
        clear();
    }

    void create(ull n) {
        parent = new ull[n+1];
        count = new ull[n+1];
        rank = new ull[n+1];
        for (ull i = 0ULL; i < n+1; ++i) {
            parent[i] = i;
            count[i] = 1;
            rank[i] = 0;
        }
    }

    void clear() {
        delete rank;
        delete count;
        delete parent;
    }

    void resize(ull n) {
        clear();
        create(n);
    }

    ull root(ull i) {
        if (parent[i] == i) return i;
        parent[i] = root(parent[i]);
        return parent[i];
    }

    void unite(ull i, ull j) {
        ull rooti = root(i);
        ull rootj = root(j);

        if (rooti == rootj) return;

        if (rank[rootj] < rank[rooti]) {
            parent[i] = parent[j] = parent[rootj] = rooti;
            count[rooti] += count[rootj];
        }
        else {
            parent[i] = parent[j] = parent[rooti] = rootj;
            count[rootj] += count[rooti];
            if (rank[rootj] == rank[rooti]) rank[rootj]++;
        }
    }

    bool same(ull i, ull j) {
        return root(i) == root(j);
    }
};















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











































#define SZ (300010LL)

ll n;
ll qcnt;
V<t3> uvxlist;
UnionFind uf;
set<ll> roots;
map<ll, V<t3>> root_to_uvxlist;
map<t2, ll> orig_vs;
set<t2> connected;




set<ll> froots(V<t3> uvxlist, ll n, ll qcnt)
{
    set<ll> roots;
    uf.resize(n+1);
    for (auto [u, v, x] : uvxlist) uf.unite(u, v);
    srep (v, 1, n+1) roots.insert(uf.root(v));
    return roots;
}

void ftransv()
{
    V<ll> rends(n+1);
    V<ll> trans(n+1);
    srep (v, 1, n+1) {
        ll root = uf.root(v);
        trans[v] = rends[root]++;
    }

    V<t3> emp;
    cfor (root, roots) root_to_uvxlist[root] = emp;

    for (auto [u, v, x] : uvxlist) {
        ll root  = uf.root(u);
        root_to_uvxlist[root].pb(t3(trans[u], trans[v], x));
    }

    srep (v, 1, n+1) {
        ll root = uf.root(v);
        orig_vs[t2(root, trans[v])] = v;
    }
}




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

void fcate(V<t3> &uvxs_tree, V<t3> &uvxs_other, const V<t3> &uvxlist_orig, ll vend)
{
    UnionFind uff(vend);

    for (auto [u, v, x] : uvxlist_orig) {
        if (uff.same(u, v)) uvxs_other.pb(t3(u, v, x));
        else uvxs_tree.pb(t3(u, v, x));
        uff.unite(u, v);
    }
}

V<ll> fxvs(const V<t2> edges[], ll vend)
{
    V<ll> xvs(vend);
    rep (i, vend) xvs[i] = -1;
    queue<ll> q;

    q.push(0);
    xvs[0] = 0;

    while (q.size()) {
        ll v = q.front(); q.pop();
        for (auto [nv, nx] : edges[v]) {
            if (xvs[nv] >= 0) continue;
            q.push(nv);
            xvs[nv] = (xvs[v] ^ nx);
        }
    }

    return xvs;
}

V<t2> trans_ranges(HLD &hld, const V<t2> &ranges_orig, const ll levels[])
{
    ll minlv = 1e9;
    ll minr = -1;
    for (auto [r0, r1] : ranges_orig) {
        ll u = hld.order_to_v[r0];
        ll v = hld.order_to_v[r1];
        if (levels[u] < minlv) {
            minlv = levels[u];
            minr = r0;
        }
        if (levels[v] < minlv) {
            minlv = levels[v];
            minr = r1;
        }
    }

    V<t2> ranges;
    for (auto [r0, r1] : ranges_orig) {
        if (r0 == minr) r0++;
        else if (r1 == minr) r1--;
        if (r0 > r1) continue;
        ranges.pb(t2(r0, r1));
    }

    return ranges;
}

void add_connected(ll root, ll v0, ll v1)
{
    ll ov0 = orig_vs[t2(root, v0)];
    ll ov1 = orig_vs[t2(root, v1)];
    connected.insert(t2(ov0, ov1));
    connected.insert(t2(ov1, ov0));
}

void solve(ll root)
{
    if (root_to_uvxlist[root].empty()) return;

    debug_printf("---------------------------------------------- solve\n");

    ll vend = 0;
    for (auto [u, v, x] : root_to_uvxlist[root]) vend = max(vend, u+1);
    for (auto [u, v, x] : root_to_uvxlist[root]) vend = max(vend, v+1);

    V<t3> uvxs_tree, uvxs_other;
    fcate(uvxs_tree, uvxs_other, root_to_uvxlist[root], vend);
    debug_printf("-------------- uvxs_tree\n");
    debug_print(uvxs_tree);
    debug_printf("-------------- uvxs_other\n");
    debug_print(uvxs_other);

    S V<t2> edges[SZ];
    rep (v, vend) edges[v].clear();
    for (auto [u, v, x] : uvxs_tree) {
        edges[u].pb(t2(v, x));
        edges[v].pb(t2(u, x));
        add_connected(root, u, v);
    }

    S ll parents[SZ];
    S V<ll> children[SZ]; rep (i, vend) children[i].clear();
    S ll levels[SZ];
    S ll subsizes[SZ];
    make_parental_relation(edges, 0, vend, parents, children, levels, subsizes);

    V<ll> xvs = fxvs(edges, vend);
    debug_printf("-------- xvs\n");
    debug_print(xvs);

    S ll pow_ancestor[SZ][POW_ANCESTOR_MAXSIZE];
    make_pow_ancestor(parents, n, pow_ancestor);

    S SegmentTreeLazy<ll, ll> tree(SZ, -1e9, 0, op_monoid, op_t1upd, op_t2div, op_t2mlt, op_t2upd);
    tree.initialize(0);

    HLD hld(parents, children, levels, subsizes, vend, 0);
    debug_printf("------------ hld v_to_order\n");
    debug_print(hld.v_to_order, vend);

    for (auto [u, v, x] : uvxs_other) {
        if ((xvs[u] ^ xvs[v]) == x) continue;

        V<t2> ranges_orig = hld.ranges(u, v, pow_ancestor);
        V<t2> ranges = trans_ranges(hld, ranges_orig, levels);
        debug_printf("---- ranges\n");
        debug_print(ranges);

        bool ng = false;
        for (auto [r0, r1] : ranges) {
            if (tree.query(r0, r1+1)) {
                ng = true;
                break;
            }
        }

        if (!ng) {
            add_connected(root, u, v);
            for (auto [r0, r1] : ranges) tree.update(r0, r1+1, 1);
        }
    }

}




void _main()
{
    llin(n);
    llin(qcnt);
    llinl3(uvxlist, qcnt);

    roots = froots(uvxlist, n, qcnt);
    debug_printf("------------------------- roots\n");
    debug_print(roots);

    ftransv();
    debug_printf("------------------------ root_to_uvxlist\n");
    debug_print(root_to_uvxlist);
    debug_printf("----------------------- orig_vs\n");
    debug_print(orig_vs);

    cfor (r, roots) {
        solve(r);
    }

    debug_printf("--------------------------- connected\n");
    debug_print(connected);

    string ansstr;
    for (auto [u, v, x] : uvxlist) {
        if (connected.find(t2(u, v)) == connected.end()) ansstr += "NO\n";
        else ansstr += "YES\n";
    }
    cout << ansstr;
}



