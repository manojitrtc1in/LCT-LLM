







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
using priority_queue_incr = priority_queue<T, V<T>, greater<T>>;




template <typename TT, typename T>
T get_m(M<TT, T> &m, TT k, T default_value)
{
    if (m.find(k) == m.end()) return m[k] = default_value;
    return m[k];
}

template <typename TT, typename T>
void id17(M<TT, T> &m, TT k)
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
        deque<V<ll>> q;
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
        ll id14 = itemcount;
        this->itemcount = 1LL;
        while (this->itemcount < id14) this->itemcount *= 2LL;
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

    

    T query(ll start, ll end) const {
        return _query(start, end, 0LL);
    }

    T _query(ll start, ll end, ll idx) const {
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

void llin(ll &a)
{
    CIN(a);
}

void id12(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a;
        CIN(a);
        v.push_back(a);
    }
}

void id5(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b;
        CIN(a >> b);
        v.push_back(t2(a, b));
    }
}

void id18(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b, c;
        CIN(a >> b >> c);
        v.push_back(t3(a, b, c));
    }
}

void id13(auto &v, ll count)
{
    for (ll i = 0LL; i < count ; ++i) {
        ll a, b, c, d;
        CIN(a >> b >> c >> d);
        v.push_back(t4(a, b, c, d));
    }
}

void llina(auto &v, ll count)
{
    id12(v, count);
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

ll id20(ll x, ll y, ll mod)
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

void id3(V<ll> &retlist, ll x)
{
    for (ll i = 1LL; i < sqrt(x) + 3LL; ++i) {
        if (x % i == 0LL) {
            retlist.push_back(i);
            retlist.push_back(x / i);
        }
    }
}



void id23(V<ll> &retlist, ll x)
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
    V<ll> factors, id0;

    id23(factors, x);

    for (auto factor : factors) {
        if (factor > 1) id0.pb(factor);
    }

    return id0.size() == 1 && x == id0[0];
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

ull id4(ll x, ll y, ll mod)
{
    if (y > x / 2LL) y = x - y;

    ll ret = 1;

    for (ll i = 0LL; i < y; ++i) {
        ret = (ret * x--) % mod;
        ret = (ret * mod_inv(i + 1LL, mod)) % mod;
    }

    return ret;
}

void id7(ll perms[], ll perm_invs[], ll size, ll mod)
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

void id10(const V<t2> &id6, V<ll> edgelist[])
{
    for (auto src : id6) {
        ll a = get<0>(src);
        ll b = get<1>(src);
        edgelist[a].pb(b);
        edgelist[b].pb(a);
    }
}


S ll parents[n+1];
S V<ll> children[n+1];
S ll levels[n+1];

void id11(const V<ll> edgelist[], ll root, ll n,
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

void id21(const ll child_count[], const ll parents[],
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

void id1(const V<ll> children[], const ll subtree_sizes[],
                   ll root, ll n, V<ll> &centroids)
{
    queue<ll> q;
    q.push(root);

    while (!q.empty()) {
        ll now = q.front(); q.pop();
        bool id19 = true;
        for (auto child : children[now]) {
            q.push(child);
            if (subtree_sizes[child] > n / 2LL) id19 = false;
        }
        if (n - subtree_sizes[now] > n / 2LL) id19 = false;
        if (id19) centroids.pb(now);
    }

    assert(centroids.size() == 1LL || centroids.size() == 2LL);
}





void id22(const ll parent[], ll n,
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

ll id2(ll n, ll x, ll y,
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

void id16(const string &pattern, ll kmp_next[])
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



void id9(const string &text, const string &pattern, const ll kmp_next[],
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

void id8(const char *prefix)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    struct tm *tm = localtime(&tv.tv_sec);
    printf("-- %s %02d:%02d:%02d.%06ld\n",
           prefix, tm->tm_hour, tm->tm_min, tm->tm_sec, tv.tv_usec);
}




ll calc(const ll cnts[2005][2005], 
        const ll id15[2005][2005], 
        ll h, ll w, ll x, ll y)
{
    h *= 2LL;
    w *= 2LL;
    ll xx = (x / h) * h;
    ll yy = (y / w) * w;

    ll ret = (xx * y + x * yy - xx * yy) / 2LL;
    if (x == 9 && y == 4) debug_printf("ret1=%lld\n", ret);
    ll remx = x - xx;
    ll remy = y - yy;

    bool rev = false;

    ll xr = ((x - 1) / h) * 2LL + 1;
    if (x == 9 && y == 4) debug_printf("xr=%lld\n", xr);
    while (xr > 1LL) {
        ll xrpow = 1LL;
        while (xrpow < xr) xrpow *= 2LL;
        xrpow /= 2LL;
        xr -= xrpow;
        rev = !rev;
    }

    ll yr = ((y - 1) / w) * 2LL + 1;
    if (x == 9 && y == 4) debug_printf("yr=%lld\n", yr);
    while (yr > 1LL) {
        ll yrpow = 1LL;
        while (yrpow < yr) yrpow *= 2LL;
        yrpow /= 2LL;
        yr -= yrpow;
        rev = !rev;
    }

    if (rev) ret += id15[remx][remy];
    else ret += cnts[remx][remy];
    if (x == 9 && y == 4) debug_printf("ret2=%lld rev=%d\n", ret, rev);
    return ret;
}

void _main();
int main()
{
    cout << setprecision(12);
    _main();
    return 0;
}

void _main()
{
    ll h; llin(h);
    ll w; llin(w);
    ll qcnt; llin(qcnt);
    S V<string> grid;
    rep (i, h) {
        string tmp; CIN(tmp);
        grid.pb(tmp);
    }
    S V<t4> qlist; id13(qlist, qcnt);

    S V<string> grid2;
    for (auto line : grid) {
        string inv;
        for (auto c : line) inv += ((c == '0') ? '1' : '0');
        grid2.pb(line + inv);
    }
    S V<string> grid4;
    for (auto line : grid2) grid4.pb(line);
    for (auto line : grid2) {
        string inv;
        for (auto c : line) inv += ((c == '0') ? '1' : '0');
        grid4.pb(inv);
    }

    debug_printf("---- grid4\n");
    debug_print(grid4);

    S ll cnts[2005][2005];
    S ll id15[2005][2005];
    memset(cnts, 0, sizeof(cnts));
    memset(id15, 0, sizeof(id15));
    rep (hh, h*2) rep (ww, w*2) {
        cnts[hh+1][ww+1] = cnts[hh+1][ww] + cnts[hh][ww+1] - cnts[hh][ww];
        if (grid4[hh][ww] == '1') cnts[hh+1][ww+1]++;
        id15[hh+1][ww+1] = id15[hh+1][ww] + id15[hh][ww+1] - id15[hh][ww];
        if (grid4[hh][ww] == '0') id15[hh+1][ww+1]++;
    }

    debug_printf("---- cnts\n");
    rep (hh, h*2+1) {
        rep (ww, w*2+1) {
            debug_printf("%lld ", cnts[hh][ww]);
        }
        debug_printf("\n");
    }

    debug_printf("---- id15\n");
    rep (hh, h*2+1) {
        rep (ww, w*2+1) {
            debug_printf("%lld ", id15[hh][ww]);
        }
        debug_printf("\n");
    }

    for (auto q : qlist) {
        ll x1 = get<0>(q);
        ll y1 = get<1>(q);
        ll x2 = get<2>(q);
        ll y2 = get<3>(q);
        ll area1 = calc(cnts, id15, h, w, x1-1, y1-1);
        ll area2 = calc(cnts, id15, h, w, x1-1, y2);
        ll area3 = calc(cnts, id15, h, w, x2, y1-1);
        ll area4 = calc(cnts, id15, h, w, x2, y2);
        debug_printf("area = %lld - %lld - %lld + %lld\n",
                     area4, area3, area2, area1);
        cout << area4 - area3 - area2 + area1 << endl;
    }
}



