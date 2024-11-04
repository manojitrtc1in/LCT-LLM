







using namespace std;


















        assert(!cin.eof()); \
        cin >> x; \
        assert(!cin.fail()); \
} while(0);












typedef long long ll;
typedef unsigned long long ull;
typedef tuple<ll, ll> t2;
typedef tuple<ll, ll, ll> t3;
typedef tuple<ll, ll, ll, ll> t4;
typedef tuple<ll, ll, ll, ll, ll> t5;
template <typename T>
using priority_queue_incr = priority_queue<T, V<T>, greater<T> >;




template <typename TT, typename T>
T get_m(M<TT, T> &m, TT k, T default_value)
{
    if (m.find(k) == m.end()) return m[k] = default_value;
    return m[k];
}

template <typename TT, typename T>
void id20(M<TT, T> &m, TT k)
{
    if (m.find(k) == m.end()) m[k] = 0;
    m[k]++;
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

struct UnionFindM
{
    M<ull, ull> parent, count, rank;

    ull root(ull i) {
        ull parent_i = get_m(parent, i, i);
        if (parent_i == i) return i;
        return parent[i] = root(parent_i);
    }

    void unite(ull i, ull j) {
        ull rooti = root(i);
        ull rootj = root(j);

        if (rooti == rootj) return;

        if (get_m(rank, rootj, 0ULL) < get_m(rank, rooti, 0ULL)) {
            parent[i] = parent[j] = parent[rootj] = rooti;
            count[rooti] = get_m(count, rooti, 1ULL) + get_m(count, rootj, 1ULL);
        }
        else {
            parent[i] = parent[j] = parent[rooti] = rootj;
            count[rootj] = get_m(count, rootj, 1ULL) + get_m(count, rooti, 1ULL);
            if (get_m(rank, rootj, 0ULL) == get_m(rank, rooti, 0ULL)) rank[rootj]++;
        }
    }

    bool same(ull i, ull j) {
        return root(i) == root(j);
    }
};

struct BIT
{
    ll *tree;
    ll size;

    BIT(ll n, ll init) {
        tree = new ll[n+1];
        size = n;
        this->init(init);
    }

    void init(ll init) {
        memset(tree, 0, sizeof(ll) * (size+1));
        rep (i0, size) {
            ll idx = i0 + 1LL;
            while (idx <= size) {
                tree[idx] += init;
                idx += (idx & (-idx));
            }
        }
    }

    

    void add(ll idx, ll x) {
        assert(idx > 0LL);
        while (idx <= size) {
            tree[idx] += x;
            idx += (idx & (-idx));
        }
    }

    

    ll sum(ll idx) {
        assert(idx > 0LL);
        ll ret = 0LL;
        while (idx > 0LL) {
            ret += tree[idx];
            idx -= (idx & (-idx));
        }
        return ret;
    }
};

struct MaxFlow {
    V<ll> links[1005];
    ll capacities[1005][1005];
    ll nodes;

    MaxFlow(ll nodes) {
        

        

        rep (i, nodes+2LL) links[i].clear();
        memset(capacities, 0, sizeof(capacities));
        this->nodes = nodes;
    }

    void add_path(ll a, ll b, ll capacity) {
        links[a].pb(b);
        links[b].pb(a);
        capacities[a][b] = capacity;
        capacities[b][a] = 0LL;
    }

    ll solve(void) {
        deque<V<ll> > q;
        ll ret = 0LL;

        for ( ; ; q.clear()) {

            V<ll> start;
            start.pb(0);
            q.push_front(start);

            bool checked[nodes+2];
            memset(checked, 0, sizeof(checked));

            V<ll> found;

            for ( ; !(q.empty()); ) {
                V<ll> path = q.front(); q.pop_front();
                ll last = path[path.size()-1];

                if (checked[last]) continue;
                if (last == nodes+1) {
                    found = path;
                    break;
                }

                checked[last] = true;
                for (auto next : (links[last])) {
                    if (capacities[last][next] == 0) continue;
                    V<ll> newpath(path);
                    newpath.pb(next);
                    q.push_front(newpath);
                }
            }

            if (found.size() == 0) {
                break;
            }
            else {
                ll flowcount = capacities[found[0]][found[1]];
                rep (i, found.size()-1) {
                    ll src = found[i];
                    ll dst = found[i+1];
                    flowcount = min(flowcount, capacities[src][dst]);
                }
                rep (i, found.size()-1) {
                    ll src = found[i];
                    ll dst = found[i+1];
                    capacities[src][dst] -= flowcount;
                    capacities[dst][src] += flowcount;
                }
                ret += flowcount;
            }
        }

        return ret;
    }
};

template <typename T>
struct SegmentTree {
    T *nodes;
    t2 *ranges;  

    ll nodecount;
    ll itemcount;
    T unit;
    T (*op)(T, T);

    SegmentTree(ll itemcount, T unit, T op(T, T)) {
        ll id18 = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < id18) this->itemcount *= 2LL;
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

};































template <typename T>
struct id17 : public SegmentTree<T> {
    T *lzvals;
    bool *lzvalids;
    ll id2;
    void (*id25)(T&, T);
    T (*op_div)(T);
    T (*id9)(T, T);

    id17(ll itemcount, T unit, T id2,
                    T op(T, T), void id25(T&, T), T op_div(T), T id9(T, T))
        : SegmentTree<T>(itemcount, unit, op) {
        this->lzvals = new T[this->nodecount];
        this->lzvalids = new bool[this->nodecount];
        this->id2 = id2;
        this->id25 = id25;
        this->op_div = op_div;
        this->id9 = id9;
        memset(this->lzvalids, 0, sizeof(bool) * this->nodecount);
    }

    

    void eval(ll nodeidx) {
        if (!lzvalids[nodeidx]) return;

        id25(this->nodes[nodeidx], lzvals[nodeidx]);

        if (nodeidx * 2LL + 2LL < this->nodecount) {
            ll downval = op_div(lzvals[nodeidx]);
            id25(lzvals[nodeidx * 2LL + 1LL], downval);
            id25(lzvals[nodeidx * 2LL + 2LL], downval);
            lzvalids[nodeidx * 2LL + 1LL] = lzvalids[nodeidx * 2LL + 2LL] = true;
        }

        lzvalids[nodeidx] = false;
        lzvals[nodeidx] = this->id2;
    }

    void update(ll start, ll end, ll val) {
        _update(start, end, val, 0LL);
    }

    void _update(ll start, ll end, ll val, ll nodeidx) {
        eval(nodeidx);

        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);
        if (end <= rstart || rend <= start) return;

        if (start <= rstart && rend <= end) {
            id25(lzvals[nodeidx], id9(val, rend - rstart));
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

    

    virtual T query(ll start, ll end) {
        return _query(start, end, 0LL);
    }

    virtual T _query(ll start, ll end, ll nodeidx) {
        ll rstart = get<0>(this->ranges[nodeidx]);
        ll rend = get<1>(this->ranges[nodeidx]);

        eval(nodeidx);

        if (start <= rstart && rend <= end) {
            return this->nodes[nodeidx];
        }
        if (rend <= start || end <= rstart) {
            return this->unit;
        }
        T left = _query(start, end, nodeidx * 2LL + 1LL);
        T right = _query(start, end, nodeidx * 2LL + 2LL);
        return this->op(left, right);
    }
};

void llin(ll &a)
{
    CIN(a);
}

void id15(auto &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void id7(auto &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void id21(auto &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void id16(auto &v, ll count)
{
    for (ll i = 0LL; i < count; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(auto &v, ll count)
{
    id15(v, count);
}

template <typename T>
T min(const V<T> v)
{
    T ret = v[0];
    for (auto i : v) ret = min(ret, i);
    return ret;
}

template <typename T>
T max(const V<T> v)
{
    T ret = v[0];
    for (auto i : v) ret = max(ret, i);
    return ret;
}

ll absll(ll x)
{
    if (x < 0) return -x;
    return x;
}

ll id23(ll x, ll y, ll mod)
{
    ll ret = 0LL;
    x %= mod;

    while (y) {
        if (y & 1LL) {
            ret += x;
            ret %= mod;
        }
        y >>= 1;
        x <<= 1;
        x %= mod;
    }

    return ret;
}



ll mod_pow(ll base, ll exp, ll mod)
{
    ll ret = 1LL;

    for ( ; exp; ) {
        if (exp & 1LL) {
            ret *= base;
            ret %= mod;
        }
        base = (base * base) % mod;
        exp >>= 1;
    }

    return ret;
}



ll mod_inv(ll x, ll mod)
{
    

    return mod_pow(x, mod - 2LL, mod);
}

ll gcm(ll x, ll y)
{
    while (y != 0) {
        ll z = x % y;
        x = y;
        y = z;
    }
    return x;
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

void id5(V<ll> &retlist, ll x)
{
    for (ll i = 1LL; i < sqrt(x) + 3LL; ++i) {
        if (x % i == 0LL) {
            retlist.push_back(i);
            retlist.push_back(x / i);
        }
    }
}



void id28(V<ll> &retlist, ll x)
{
    retlist.pb(1LL);
    for (ll i = 2LL; i < (ll)(sqrt(x)) + 3LL; ++i) {
        while (x % i == 0LL) {
            retlist.pb(i);
            x /= i;
        }
    }
    retlist.pb(x);
}

bool is_prime(ll x)
{
    V<ll> factors, id1;

    id28(factors, x);

    for (auto factor : factors) {
        if (factor > 1) id1.pb(factor);
    }

    return id1.size() == 1 && x == id1[0];
}

template <typename T>
void intersection(const set<T> &a, const set<T> &b,
                  set<T> &result)
{
    set_intersection(ALL(a), ALL(b), inserter(result, result.end()));
}

ull combination(ll x, ll y)
{
    if (y > x / 2LL) y = x - y;

    ull ret = 1LL;
    for (ll i = 0LL; i < y; ++i) {
        ret *= x--;
        ret /= (i + 1LL);
    }

    return ret;
}

ull id6(ll x, ll y, ll mod)
{
    if (y > x / 2LL) y = x - y;

    ll ret = 1;

    for (ll i = 0LL; i < y; ++i) {
        ret = (ret * x--) % mod;
        ret = (ret * mod_inv(i + 1LL, mod)) % mod;
    }

    return ret;
}

void id10(ll perms[], ll perm_invs[], ll size, ll mod)
{
    perms[0] = 1LL;
    srep (i, 1, size) {
        perms[i] = perms[i-1] * i;
        perms[i] %= mod;
    }

    rep (i, size) {
        perm_invs[i] = mod_inv(perms[i], mod);
    }
}


S V<ll> edgelist[n+1];

void id13(const V<t2> &id8, V<ll> edgelist[])
{
    for (auto src : id8) {
        ll a = get<0>(src);
        ll b = get<1>(src);
        edgelist[a].pb(b);
        edgelist[b].pb(a);
    }
}


S ll parents[n+1];
S V<ll> children[n+1];
S ll levels[n+1];

void id14(const V<ll> edgelist[], ll root, ll n,
                            ll parents[], V<ll> children[], ll levels[])
{
    queue<ll> q;
    bool checked[n+1];

    memset(checked, 0, sizeof(checked));

    q.push(root);
    checked[root] = true;
    parents[root] = root;
    levels[root] = 0LL;

    for ( ; !(q.empty()); ) {
        ll now = q.front(); q.pop();
        for (auto next : edgelist[now]) {
            if (checked[next]) continue;
            q.push(next);
            checked[next] = true;
            parents[next] = now;
            children[now].pb(next);
            levels[next] = levels[now] + 1LL;
        }
    }
}

void id26(const ll child_count[], const ll parents[],
                        ll subtree_sizes[], ll n)
{
    ll remain_count[n+1LL];
    memcpy(remain_count, child_count, sizeof(remain_count));

    queue<ll> q;
    srep (node, 1LL, n+1LL) {
        subtree_sizes[node] = 1LL;
        if (remain_count[node] > 0) continue;
        q.push(node);
    }

    while (!q.empty()) {
        ll node = q.front(); q.pop();
        ll parent = parents[node];
        if (node == parent) continue;
        remain_count[parent]--;
        subtree_sizes[parent] += subtree_sizes[node];
        if (remain_count[parent] == 0LL) q.push(parent);
    }
}

void id3(const V<ll> children[], const ll subtree_sizes[],
                   ll root, ll n, V<ll> &centroids)
{
    queue<ll> q;
    q.push(root);

    while (!q.empty()) {
        ll now = q.front(); q.pop();
        bool id22 = true;
        for (auto child : children[now]) {
            q.push(child);
            if (subtree_sizes[child] > n / 2LL) id22 = false;
        }
        if (n - subtree_sizes[now] > n / 2LL) id22 = false;
        if (id22) centroids.pb(now);
    }

    assert(centroids.size() == 1LL || centroids.size() == 2LL);
}





void id27(const ll parent[], ll n,
                       ll (*pow_ancestor)[POW_ANCESTOR_MAXSIZE])
{
    rep (i, n) pow_ancestor[i+1][0] = parent[i+1];

    for (int pow2 = 1; pow(2, pow2) <= n; ++pow2) {
        rep (i0, n) {
            int i = i0+1;
            ll prev = pow_ancestor[i][pow2-1];
            pow_ancestor[i][pow2] = pow_ancestor[prev][pow2-1];
        }
    }
}

ll id4(ll n, ll x, ll y,
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

void id19(const string &pattern, ll kmp_next[])
{
    kmp_next[0] = -1LL;

    ll plen = pattern.size();
    ll prefix_end = -1;

    rep (suffix_end, pattern.size()) {
        while (prefix_end >= 0 && pattern[suffix_end] != pattern[prefix_end]) {
            prefix_end = kmp_next[prefix_end];
        }
        kmp_next[suffix_end+1] = ++prefix_end;
    }

    kmp_next[0] = 0LL;
}



void id12(const string &text, const string &pattern, const ll kmp_next[],
                V<ll> &founds)
{
    ll text_size = text.size();
    ll pattern_size = pattern.size();
    ll text_start = 0LL;
    ll pattern_idx = 0LL;

    assert(pattern_size <= text_size);

    for ( ; ; ) {
        if (text_start + pattern_idx >= text_size) break;
        if (pattern_idx >= pattern_size) break;

        if (text[text_start+pattern_idx] == pattern[pattern_idx]) {
            pattern_idx++;
            if (pattern_idx == pattern_size) {
                founds.pb(text_start);
                pattern_idx = kmp_next[pattern_idx];
                text_start += (pattern_size - pattern_idx);
            }
        }

        else {
            text_start += (pattern_idx - kmp_next[pattern_idx]);
            pattern_idx = kmp_next[pattern_idx];
            if (pattern_idx == 0LL && text[text_start] != pattern[0]) {
                text_start++;
            }
        }
    }
}

void z_algorithm(ll matchcounts[], const string &str)
{
    ll n = str.size();
    ll base_idx = 0LL;
    memset(matchcounts, 0, sizeof(ll) * n);

    srep (idx, 1LL, n) {

        ll checked_len = base_idx + matchcounts[base_idx];

        if (idx + matchcounts[idx-base_idx] < checked_len) {
            matchcounts[idx] = matchcounts[idx-base_idx];
            continue;
        }

        ll start = max(0LL, base_idx + matchcounts[base_idx] - idx);
        matchcounts[idx] = start;
        srep (cmp, start, n-idx) {
            if (str[cmp] == str[idx+cmp]) matchcounts[idx]++;
            else break;
        }
        base_idx = idx;

    }

    matchcounts[0] = n;
}

double xy_distance(double x1, double y1, double x2, double y2)
{
    double xx = (x1 - x2) * (x1 - x2);
    double yy = (y1 - y2) * (y1 - y2);
    return sqrt(xx + yy);
}

double heron(double a, double b, double c)
{
    double s = (a + b + c) / 2.;
    double ret = 1.;
    ret *= s;
    ret *= (s - a);
    ret *= (s - b);
    ret *= (s - c);
    ret = sqrt(ret);
    return ret;
}

double id0(double rad)
{
    while (rad < -PI) rad += 2. * PI;
    while (rad > PI) rad -= 2. * PI;
    return rad;
}

void _debug_print(auto x)
{
    cout << x << endl;
}

void _debug_print(const t2 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    cout << "-- " << x1 << " -- " << x2 << endl;
}

void _debug_print(const t3 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    cout << "-- " << x1 << " -- " << x2 << " -- " << x3 << endl;
}

void _debug_print(const t4 &x)
{
    ll x1 = get<0>(x);
    ll x2 = get<1>(x);
    ll x3 = get<2>(x);
    ll x4 = get<3>(x);
    cout << "-- " << x1 << " -- " << x2
         << " -- " << x3 << " -- " << x4 << endl;
}

template <typename T>
void _debug_print(T xarray[], ll n)
{
    rep (i, n) _debug_print(xarray[i]);
}

template <typename T>
void _debug_print(const V<T> &xlist)
{
    for (auto x : xlist) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename T>
void _debug_print(const set<T> &xset)
{
    for (auto x : xset) {
        cout << "-- ";
        _debug_print(x);
    }
}

template <typename TT, typename T>
void _debug_print(const M<TT, T> &xlist)
{
    for (auto x : xlist) {
        TT k = x.first;
        T v = x.second;
        cout << "====" << endl;
        cout << "K=";
        _debug_print(k);
        cout << "V=";
        _debug_print(v);
    }
}

void id11(const char *prefix)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm *tm = localtime(&tv.tv_sec);
    printf("-- %s %02d:%02d:%02d.%06ld\n",
           prefix, tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec);
}




ll op(ll x, ll y) {
    return max(x, y);
}
void id25(ll &x, ll y) {
    x += y;
}
ll op_div(ll x) {
    return x;
}
ll id9(ll x, ll y) {
    return x;
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

void _main()
{
    debug_print_time("xx0");

    ll n; llin(n);
    ll m; llin(m);
    ll p; llin(p);
    S V<t2> weapons; id7(weapons, n);
    S V<t2> armors; id7(armors, m);
    S V<t3> monsters; id21(monsters, p);

    debug_print_time("xx1");

    sort(weapons);

    debug_print_time("xx2");

    S V<t2> id24;
    for (auto pc : armors) {
        ll p = get<0>(pc);
        ll c = get<1>(pc);
        id24.pb(t2(c, p));
    }
    sort(id24);

    debug_print_time("xx3");

    id17<ll> tree((ll)1e6+10, -1e18, 0, op, id25, op_div, id9);

    debug_print_time("xx4");

    ll maxp = -1e18;
    for (auto cp : id24) {
        ll c = get<0>(cp);
        ll p = get<1>(cp);
        if (p <= maxp) continue;
        maxp = p;
        tree.update(p, p+1LL, (ll)1e18-c);
    }

    debug_print_time("xx5");

    ll ans = -1e18;
    ll midx = 0LL;
    sort(monsters);

    debug_print_time("xx6");

    for (auto weapon : weapons) {
        ll wp = get<0>(weapon);
        ll wc = get<1>(weapon);
        debug_printf("-------- wp=%lld wc=%lld\n", wp, wc);
        while (midx < p) {
            if (get<0>(monsters[midx]) >= wp) break;
            ll mp = get<1>(monsters[midx]);
            ll mc = get<2>(monsters[midx]);
            debug_printf("---- mp=%lld mc=%lld\n", mp, mc);
            tree.update(mp+1LL, (ll)1e6+10LL, mc);
            midx++;
        }
        debug_printf("---- cand=%lld\n", tree.query(0LL, (ll)1e6+10LL) - wc);
        ans = max(ans, tree.query(0LL, (ll)1e6+10LL) - wc);
    }

    debug_print_time("xx7");
    debug_printf("---- ans\n");
    cout << ans << endl;
}


