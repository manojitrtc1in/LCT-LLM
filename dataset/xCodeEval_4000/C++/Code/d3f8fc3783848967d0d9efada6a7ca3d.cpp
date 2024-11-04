


#include <bits/stdc++.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;




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


typedef long long ll;
typedef unsigned long long ull;
typedef __int128_t ll128;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;
template <typename T>
using binary_search_tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;




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

void gcj_head(ll casenum)
{
    cout << "Case #" << casenum+1 << ":";
}

void gcj_head_nl(ll casenum)
{
    cout << "Case #" << casenum+1 << ":" << "\n";
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









void make_parental_relation(const V<ll> edges[], ll root, ll n,
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
        for (auto nv : edges[v]) {
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

    UnionFind(ull n) {
        parent = new ull[n+1];
        count = new ull[n+1];
        rank = new ull[n+1];
        for (ull i = 0ULL; i < n+1; ++i) {
            parent[i] = i;
            count[i] = 1;
            rank[i] = 0;
        }
    }

    ~UnionFind() {
        delete rank;
        delete count;
        delete parent;
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

void ftree(V<int> &anslist, V<t3> &e_trees, V<t3> uvxlist, ll n, ll qcnt)
{
    UnionFind uf(n+1);

    rep (i, qcnt) {
        auto [u, v, x] = uvxlist[i];
        if (uf.same(u, v)) continue;
        uf.unite(u, v);
        anslist[i] = 1;
        e_trees.pb(t3(u, v, x));
    }

    V<ll> roots;
    srep (v, 1, n+1) roots.pb(uf.root(v));
    sort(roots);
    roots.erase(unique(ALL(roots)), roots.end());

    rep (i, roots.size() - 1) {
        e_trees.pb(t3(roots[i], roots[i+1], 0));
    }
}

S ll parents[SZ];
S V<ll> children[SZ];
S ll levels[SZ];
S ll subsizes[SZ];

V<ll> fvals(V<t3> trees_x, ll n)
{
    V<ll> vals(n+1);

    for (auto [v0, v1, x] : trees_x) {
        if (parents[v0] == v1) {
            vals[v0] = x;
        }
        else {
            vals[v1] = x;
        }
    }

    return vals;
}

V<ll> fsums(V<ll> vals, ll n)
{
    V<t2> lvvs;
    srep (v, 1, n+1) lvvs.pb(t2(levels[v], v));
    sort(lvvs);

    V<ll> sums(n+1);
    sums[1] = 0;

    for (auto [lv, v] : lvvs) {
        if (v == 1) continue;
        ll pv = parents[v];
        sums[v] = (sums[pv] ^ vals[v]);
    }

    return sums;
}

V<ll> v_to_in, v_to_out;

void dfs(ll v, ll &order)
{
    v_to_in[v] = order++;
    cfor (cv, children[v]) {
        dfs(cv, order);
    }
    v_to_out[v] = order++;
}

V<ll> f_order_to_v(ll n)
{
    V<ll> order_to_v(n*2+10);
    srep (v, 1, n+1) {
        ll in = v_to_in[v];
        ll out = v_to_out[v];
        order_to_v[in] = v;
        order_to_v[out] = -v;
    }
    return order_to_v;
}

ll sumll(ll x, ll y)
{
    return x + y;
}

S ll pow_ancestor[SZ][POW_ANCESTOR_MAXSIZE];

ll fsum(SegmentTree<ll> &seg, ll v)
{
    ll in = v_to_in[v];
    return seg.query_fast(0, in + 1);
}

void _main()
{
    ll n; llin(n);
    ll qcnt; llin(qcnt);
    V<t3> uvxlist; llinl3(uvxlist, qcnt);

    V<int> anslist(qcnt);

    V<t3> trees_x;
    ftree(anslist, trees_x, uvxlist, n, qcnt);
    debug_printf("---- trees_x\n");
    debug_print(trees_x);

    V<ll> edges[SZ];
    for (auto [u, v, x] : trees_x) edges[u].pb(v);
    for (auto [u, v, x] : trees_x) edges[v].pb(u);
    make_parental_relation(edges, 1, n, parents, children, levels, subsizes);

    make_pow_ancestor(parents, n, pow_ancestor);

    V<ll> vals = fvals(trees_x, n);
    debug_printf("---- vals\n");
    debug_print(vals);
    V<ll> sums = fsums(vals, n);
    debug_printf("---- sums\n");
    debug_print(sums);

    v_to_in.resize(n+1);
    v_to_out.resize(n+1);
    ll order = 0;
    dfs(1, order);
    debug_printf("---- v_to_in\n");
    debug_print(v_to_in);
    debug_printf("---- v_to_out\n");
    debug_print(v_to_out);

    V<ll> order_to_v = f_order_to_v(n);
    debug_printf("---- order_to_v\n");
    debug_print(order_to_v);

    SegmentTree<ll> seg(n*2+10, 0, sumll);

    rep (i, qcnt) {
        auto [v0, v1, x] = uvxlist[i];
        debug_printf("------------- v0=%lld v1=%lld x=%lld\n", v0, v1, x);
        if (parents[v0] == v1) {
            anslist[i] = 1;
            continue;
        }
        if (parents[v1] == v0) {
            anslist[i] = 1;
            continue;
        }

        ll anc = get_common_ancestor(n, v0, v1, pow_ancestor, levels);
        debug_printf("---- anc=%lld\n", anc);

        ll sumv0 = fsum(seg, v0);
        ll sumv1 = fsum(seg, v1);
        ll sumanc = fsum(seg, anc);
        ll sum = sumv0 + sumv1 - sumanc * 2LL;
        if (sum) continue;

        if (!(sums[v0] ^ sums[v1] ^ x)) continue;

        anslist[i] = 1;

        while (v0 != anc) {
            seg.update(v_to_in[v0], 1);
            seg.update(v_to_out[v0], -1);
            v0 = parents[v0];
        }
        while (v1 != anc) {
            seg.update(v_to_in[v1], 1);
            seg.update(v_to_out[v1], -1);
            v1 = parents[v1];
        }
    }

    debug_printf("---- anslist\n");
    debug_print(anslist);

    rep (i, qcnt) cout << (anslist[i] ? "YES\n" : "NO\n");
}



