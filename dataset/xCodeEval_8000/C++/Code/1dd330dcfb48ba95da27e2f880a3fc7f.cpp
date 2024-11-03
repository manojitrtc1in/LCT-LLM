


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
typedef tuple<int, int, int, int> t4;
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





void make_parental_relation(const V<t2> edges[], int root, int n,
                            int parents[], V<int> children[], int levels[], int subsizes[])
{
    queue<int> q;
    bool *checked = new bool[n+1];
    memset(checked, 0, sizeof(bool) * (n+1));
    V<int> leaves;

    q.push(root);
    checked[root] = true;
    parents[root] = root;
    levels[root] = 0LL;

    while(q.size()) {
        int v = q.front(); q.pop();
        bool leaf = true;
        for (auto ni : edges[v]) {
            int nv = get<0>(ni);
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

    int *rrefs = new int[n+1];
    rep (v, n+1) rrefs[v] = children[v].size();
    rep (v, n+1) subsizes[v] = 1;
    assert(q.empty());
    for (auto v : leaves) q.push(v);

    while (q.size()) {
        int v = q.front(); q.pop();
        int pv = parents[v];
        if (v == pv) continue;
        subsizes[pv] += subsizes[v];
        rrefs[pv]--;
        if (rrefs[pv]) continue;
        q.push(pv);
    }

    delete [] rrefs;
    delete [] checked;
}





#define POW_ANCESTOR_MAXSIZE   20






void make_pow_ancestor(const int parent[], int n,
                       int (*pow_ancestor)[POW_ANCESTOR_MAXSIZE])
{
    rep (i, n+1) pow_ancestor[i][0] = parent[i];

    for (int pow2 = 1; pow2 < POW_ANCESTOR_MAXSIZE; ++pow2) {
        rep (i, n+1) {
            int prev = pow_ancestor[i][pow2-1];
            pow_ancestor[i][pow2] = pow_ancestor[prev][pow2-1];
        }
    }
}

S int lgmap[1048586];

int get_common_ancestor(int log2n, int x, int y,
                       const int (*pow_ancestor)[POW_ANCESTOR_MAXSIZE],
                       const int level[])
{
    if (level[x] < level[y]) {
        int diff = level[y] - level[x];
        for ( ; diff; ) {
            int bit = diff & -diff;
            y = pow_ancestor[y][lgmap[bit]];
            diff ^= bit;
        }
    }
    else {
        int diff = level[x] - level[y];
        for ( ; diff; ) {
            int bit = diff & -diff;
            x = pow_ancestor[x][lgmap[bit]];
            diff ^= bit;
        }
    }

    if (x == y) return x;

    rrep (i, log2n+1) {
        if (pow_ancestor[x][i] != pow_ancestor[y][i]) {
            x = pow_ancestor[x][i];
            y = pow_ancestor[y][i];
        }
    }

    return pow_ancestor[x][0];
}










struct HLD {
    int n;
    int log2n;
    int *v_to_order;
    int *droots;
    const int *parents;
    const V<int> *children;
    const int *levels;
    const int *subsizes;

    HLD(const int *parents, const V<int> *children, const int *levels, const int *subsizes, int n, int root, int qcnt) {
        this->n = n;
        this->log2n = log2(n);
        this->v_to_order = new int[n+1];
        this->droots = new int[n+1];
        this->parents = parents;
        this->children = children;
        this->levels = levels;
        this->subsizes = subsizes;

        int order = 0;
        _dfs(root, order, root);
    }

    ~HLD() {
        delete [] this->droots;
        delete [] this->v_to_order;
    }

    void _dfs(int v, int &order, int droot) {
        v_to_order[v] = order++;
        droots[v] = droot;

        if (children[v].empty()) return;

        int maxcnt = -1;
        int maxcv = -1;
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

    

    V<t2> ranges(int av, int v0, int v1, const int (*pow_ancestor)[POW_ANCESTOR_MAXSIZE]) {
        V<t2> cand;
        V<int> svs;
        svs.pb(v0); svs.pb(v1);

        for (auto v : svs) {
            while (true) {
                int nv = droots[v];
                if (levels[nv] <= levels[av]) {
                    cand.pb(t2(v_to_order[av], v_to_order[v]));
                    break;
                }
                cand.pb(t2(v_to_order[nv], v_to_order[v]));
                v = parents[nv];
            }
        }

        sort(cand);
        

        t2 prange = cand[0];
        V<t2> ret;

        for (const auto &range : cand) {
            int pleft, pright; tie(pleft, pright) = prange;
            int left, right; tie(left, right) = range;
            

            

            if (pright < left) {
                ret.pb(prange);
                prange = range;
                continue;
            }

            if (left <= pleft && pright <= right) {
                prange = range;
            }
        }

        ret.pb(prange);

        return ret;
    }
};







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








template <typename T>
struct SegmentTree {
    T *nodes;
    t2 *ranges;  

    int nodecount;
    int itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(int itemcount, T unit, T op(T, T)) {
        int orig_itemcount = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < orig_itemcount) this->itemcount *= 2LL;
        nodecount = this->itemcount * 2 - 1;
        nodes = new T[nodecount];
        ranges = new t2[nodecount];
        this->unit = unit;
        this->op = op;

        int start = 0LL;
        int end = this->itemcount;
        int len = this->itemcount;

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
        debug_printf("---- del 1\n");
        delete [] nodes;
        delete [] ranges;
    }

    virtual void initialize(const T arr[], int cnt) {
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

    void update(int k, T v) {
        int idx = k + itemcount - 1LL;
        nodes[idx] = v;
        idx = (idx - 1LL) / 2LL;

        for ( ; idx >= 0; idx = (idx - 1LL) / 2LL) {
            nodes[idx] = op(nodes[idx * 2LL + 1LL],
                            nodes[idx * 2LL + 2LL]);
            if (!idx) break;
        }
    }

    

    virtual T query(int start, int end) const {
        return _query(start, end, 0LL);
    }

    virtual T _query(int start, int end, int idx) const {
        int rstart = get<0>(ranges[idx]);
        int rend = get<1>(ranges[idx]);

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

    T query_fast(int start, int end) const {
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
    T2 (*op_t2mlt)(T2, int);
    void (*op_t2upd)(T2&, T2);

    SegmentTreeLazy(int itemcount, T1 unit_monoid, T2 unit_upd,
                    T1 op_monoid(T1, T1), void op_t1upd(T1&, T2),
                    T2 op_t2div(T2), T2 op_t2mlt(T2, int),
                    void op_t2upd(T2&, T2), int qcnt)
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
        debug_printf("---- del 2\n");
        delete [] lzvals;
        delete [] lzvalids;
    }

    virtual void initialize(const T1 arr[], int cnt) {
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

    

    void eval(int nodeidx) {
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

    void update(int start, int end, T2 val) {
        _update(start, end, val, 0LL);
    }

    void _update(int start, int end, T2 val, int nodeidx) {
        eval(nodeidx);

        int rstart = get<0>(this->ranges[nodeidx]);
        int rend = get<1>(this->ranges[nodeidx]);
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

    

    virtual T1 query(int start, int end) {
        return _query(start, end, 0LL);
    }

    virtual T1 _query(int start, int end, int nodeidx) {
        int rstart = get<0>(this->ranges[nodeidx]);
        int rend = get<1>(this->ranges[nodeidx]);

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
















#define SZ (500010LL)

int op_monoid(int x, int y)
{
    return x + y;
}
void op_t1upd(int& x, int y)
{
    if (y == -1e18) return;
    x = y;
}
int op_t2div(int x)
{
    return x / 2LL;
}
int op_t2mlt(int x, int cnt)
{
    return x * cnt;
}
void op_t2upd(int& x, int y)
{
    if (y == -1e9) return;
    x = y;
}

ll n;
ll qcnt;
V<t3> qlist;
S V<int> rqis[SZ][2];  

S bool ans[SZ];

void f(ll root)
{
    


    debug_printf("------------------ root=%lld\n", root);

    debug_printf("---- msec 0 : %lld\n", msec());

    set<int> ovs;
    for (const auto &qi : rqis[root][1]) {
        int u, v, x; tie(u, v, x) = qlist[qi];
        ovs.insert(u);
        ovs.insert(v);
    }


    debug_printf("---- msec 1 : %lld\n", msec());

    S int vconv[SZ];
    int init = 0;
    for (auto ov : ovs) vconv[ov] = init++;
    int vcnt = init;
    debug_printf("---- vcnt=%d\n", vcnt);

    debug_printf("---- msec 2 : %lld\n", msec());

    V<t4> queries;
    for (const auto &qi : rqis[root][0]) {
        

        int u, v, x; tie(u, v, x) = qlist[qi];
        queries.pb(t4(vconv[u], vconv[v], x, qi));
    }
    

    


    debug_printf("---- msec 3 : %lld\n", msec());

    S V<t2> edges[SZ]; rep (i, vcnt+1) edges[i].clear();
    for (const auto &qi : rqis[root][1]) {
        

        ans[qi] = true;
        int u, v, x; tie(u, v, x) = qlist[qi];
        int v0 = vconv[u];
        int v1 = vconv[v];
        edges[v0].pb(t2(v1, x));
        edges[v1].pb(t2(v0, x));
        

    }

    debug_printf("---- msec 4 : %lld\n", msec());

    S int parents[SZ];
    S V<int> children[SZ]; rep (i, vcnt+1) children[i].clear();
    S int levels[SZ];
    S int subsizes[SZ];
    make_parental_relation(edges, 0, vcnt, parents, children, levels, subsizes);

    debug_printf("---- msec 5 : %lld\n", msec());

    S char types[SZ]; rep (i, vcnt+1) types[i] = -1;
    queue<int> tq;
    types[0] = 0;
    tq.push(0);

    debug_printf("---- msec 6 : %lld\n", msec());

    while (tq.size()) {
        int v = tq.front(); tq.pop();
        for (const auto &ni : edges[v]) {
            int nv, x; tie(nv, x) = ni;
            if (types[nv] >= 0) continue;
            types[nv] = (types[v] ^ x);
            tq.push(nv);
        }
    }
    

    

    


    debug_printf("---- msec 7 : %lld\n", msec());

    S int pow_ancestor[SZ][POW_ANCESTOR_MAXSIZE];
    make_pow_ancestor(parents, vcnt, pow_ancestor);

    debug_printf("---- msec 8 : %lld\n", msec());

    HLD hld(parents, children, levels, subsizes, vcnt, 0, qcnt);
    debug_printf("---- msec 9 : %lld\n", msec());
    SegmentTreeLazy<int, int> tree(vcnt, 0, -1e9,
                                 op_monoid, op_t1upd,
                                 op_t2div, op_t2mlt, op_t2upd, qcnt);
    debug_printf("---- msec 10 : %lld\n", msec());
    debug_printf("---- queries size=%zu\n", queries.size());

    for (const auto &item : queries) {
        int v0, v1, x, qi; tie(v0, v1, x, qi) = item;
        int av = get_common_ancestor(hld.log2n, v0, v1, pow_ancestor, levels);
        V<t2> rlist = hld.ranges(av, v0, v1, pow_ancestor);

        

            

            

            

        


        

        

        int order_av = hld.v_to_order[av];

        

        

        

        


        if ((types[v0] ^ types[v1]) == x) continue;

        


        bool ng = false;
        for (const auto &r : rlist) {
            int left, right; tie(left, right) = r;
            

            

            

                

                

            

            if (left == order_av) left++;
            if (left > right) continue;
            if (tree.query(left, right+1)) {
                

                    

                

                ng = true;
                break;
            }
            

        }

        if (ng) continue;
        ans[qi] = true;

        for (const auto &r : rlist) {
            int left, right; tie(left, right) = r;
            

            

            

                

                

            

            if (left == order_av) left++;
            if (left > right) continue;
            tree.update(left, right+1, 1);
        }
    }

    debug_printf("---- msec 11 : %lld\n", msec());
}

void _main()
{
    debug_printf("---- msec main 0 : %lld\n", msec());

    llin(n);
    llin(qcnt);
    llinl3(qlist, qcnt);

    debug_printf("---- msec main 1 : %lld\n", msec());

    int lgmap0 = 1;
    int lgmap1 = 0; 
    rep (i, 20) lgmap[1<<i] = i;

    memset(ans, 0, sizeof(ans));

    debug_printf("---- msec main 2 : %lld\n", msec());

    UnionFind uf(n+1);
    S char is_tree[SZ] = {};
    rep (i, qcnt) {
        int u, v, x; tie(u, v, x) = qlist[i];
        if (uf.same(u, v)) continue;
        uf.unite(u, v);
        is_tree[i] = 1;
    }

    debug_printf("---- msec main 3 : %lld\n", msec());

    set<int> roots;
    srep (v, 1, n+1) roots.insert(uf.root(v));

    debug_printf("---- msec main 4 : %lld\n", msec());

    rep (i, qcnt) {
        ll u, v, x; tie(u, v, x) = qlist[i];
        ll root = uf.root(u);
        rqis[root][is_tree[i]].pb(i);
    }

    debug_printf("---- msec main 5 : %lld\n", msec());

    for (auto r : roots) f(r);

    debug_printf("---- msec main 6 : %lld\n", msec());

    

    


    string ansstr;
    rep (i, qcnt) ansstr += (ans[i] ? "YES\n" : "NO\n");
    cout << ansstr;

    debug_printf("---- msec main 7 : %lld\n", msec());
}



