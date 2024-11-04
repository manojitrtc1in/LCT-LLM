



using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef unordered_map<int,int> UMPII;
typedef map<int,int> MPII;
typedef set<int> SETI;
typedef stack<int> STI;
typedef multiset<int> MSETI;
typedef pair<long, long> PLL;
typedef vector<long> VL;
typedef vector<string> VS;
typedef vector<PLL> VPLL;
typedef vector<VL> VVL;
typedef map<long,long> MPLL;
typedef set<long> SETL;
typedef multiset<long> MSETL;
typedef pair<long long, long long> PLLLL;
typedef vector<ll> VLL;
typedef vector<string> VS;
typedef vector<PLLLL> VPLLLL;
typedef vector<VLL> VVLL;
typedef map<long long,long long> MPLLLL;
typedef set<long long> SETLL;
typedef multiset<long long> MSETLL;


template<class T> void _R(T &x) { cin >> x; }
void _R(int &x) { scanf("%d", &x); }
void _R(ll &x) { scanf("%lld", &x); }
void _R(double &x) { scanf("%lf", &x); }
void _R(char &x) { scanf(" %c", &x); }
void _R(char *x) { scanf("%s", x); }
void R() {}
template<class T, class... U> void R(T &head, U &... tail) { _R(head); R(tail...); }
template<class T> void _W(const T &x) { cout << x; }
void _W(const int &x) { printf("%d", x); }
void _W(const ll &x) { printf("%lld", x); }
void _W(const double &x) { printf("%.16f", x); }
void _W(const char &x) { putchar(x); }
void _W(const char *x) { printf("%s", x); }
template<class T,class U> void _W(const pair<T,U> &x) {_W(x.F); putchar(' '); _W(x.S);}
template<class T> void _W(const vector<T> &x) { for (auto i = x.begin(); i != x.end(); _W(*i++)) if (i != x.cbegin()) putchar(' '); }


void W() {}
template<class T, class... U> void W(const T &head, const U &... tail) { _W(head); putchar(sizeof...(tail) ? ' ' : '\n'); W(tail...); }

    ff (i, 0, v.size()) {                    \
        ff (j, 0, v[i].size()) {                \
            cout << v[i][j] << " ";   \
        }                             \
        cout << '\n';                 \
    }


constexpr int inf = 1E9;
constexpr ll INF = 1E18;



























int ask(const string &s) { int r; return cout << "? " << s <<endl, cin >> r, r; }


const int id0 = 400005;
ll fact[id0];
ll mult(ll a,ll b) {
    return ((a % MOD)*(b % MOD)) % MOD;
}
ll add(ll a,ll b) {
    return ((a % MOD)+(b % MOD)) % MOD;
}
ll subt(ll a,ll b) {
    ll ans = ((a % mod) - (b % mod)) % mod;
    ans %= mod;
    ans = (ans + mod) % mod;
    return ans;
}

ll exp(ll a, ll b) {
    ll ans = 1;
    ll po = a;
    while (b != 0){
        if(b % 2){
            ans = ((ans % mod) * (po % mod)) % mod;
        }
        po = ((po % mod) * (po % mod)) % mod;
        b /= 2;
    }
    return ans;
}        
ll inv(ll x) {
	return exp(x, MOD - 2); 

}
ll divide(ll x, ll y) {
	return mult(x, inv(y));
}
void factorial(void) {
	fact[0] = 1;
	for(int i = 1; i < id0; i++)
		fact[i] = mult(i, fact[i - 1]);
}






ll C(ll n, ll k) {
	if(k > n) return 0;
	return divide(fact[n], mult(fact[n - k], fact[k]));
}


ll Pow(ll a, ll n) {
    if (n == 0) return 0;
    if (n == 1) return a;
    ll c = Pow(a, n / 2) % MOD;
    if (n % 2 == 0) return (c % MOD) * (c % MOD) % MOD;
    return (c % MOD) * (c % MOD) * (a % MOD)% MOD;
}



class id1 {
    public:
    struct node {
        ll mn = -1;
        ll mx = -1;
        

        

        ll add = 0;
        ll sum_a = 0;
        ll idx;
 
        void apply(int l, int r, ll v) {
            mn = mx = v;
            

            

            add += v;
            sum_a += (ll)v * (r - l + 1);
            idx = l;
        }
    };

    node unite(const node &a, const node &b) const {
        node res;
        res.mn = min(a.mn, b.mn);
        res.mx = max(a.mx, b.mx);
        

        res.sum_a = a.sum_a + b.sum_a;
        if (a.mx > b.mx) res.idx = a.idx;
        else res.idx = b.idx;
        return res;
    }
 
    inline void push(int x, int l, int r) {
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        

        

        

        

        

        if (tree[x].add != 0) {
            tree[x + 1].apply(l, y, tree[x].add);
            tree[z].apply(y + 1, r, tree[x].add);
            tree[x].add = 0;
        }
    }
    
    inline void pull(int x, int z) {
        tree[x] = unite(tree[x + 1], tree[z]);
    }
    
    int n;
    vector<node> tree;
    
    void build(int x, int l, int r) {
        if (l == r) {
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y);
        build(z, y + 1, r);
        pull(x, z);
    }
    
    template <typename M>
    void build(int x, int l, int r, const vector<M> &v) {
        if (l == r) {
            tree[x].apply(l, r, v[l]);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        build(x + 1, l, y, v);
        build(z, y + 1, r, v);
        pull(x, z);
    }
    
    node get(int x, int l, int r, int ll, int rr) {
        if (ll <= l && r <= rr) {
            return tree[x];
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        node res{};
        if (rr <= y) {
            res = get(x + 1, l, y, ll, rr);
        } else {
            if (ll > y) {
                res = get(z, y + 1, r, ll, rr);
            } else {
                res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
            }
        }
        pull(x, z);
        return res;
    }
    
    template <typename... M>
    void modify(int x, int l, int r, int ll, int rr, const M&... v) {
        if (ll <= l && r <= rr) {
            tree[x].apply(l, r, v...);
            return;
        }
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        push(x, l, r);
        if (ll <= y) {
            modify(x + 1, l, y, ll, rr, v...);
        }
        if (rr > y) {
            modify(z, y + 1, r, ll, rr, v...);
        }
        pull(x, z);
    }
    
    int find_first_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[x + 1])) {
            res = find_first_knowingly(x + 1, l, y, f);
        } else {
            res = find_first_knowingly(z, y + 1, r, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_first(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_first_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (ll <= y) {
            res = find_first(x + 1, l, y, ll, rr, f);
        }
        if (rr > y && res == -1) {
            res = find_first(z, y + 1, r, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_last_knowingly(int x, int l, int r, const function<bool(const node&)> &f) {
        if (l == r) {
            return l;
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res;
        if (f(tree[z])) {
            res = find_last_knowingly(z, y + 1, r, f);
        } else {
            res = find_last_knowingly(x + 1, l, y, f);
        }
        pull(x, z);
        return res;
    }
    
    int find_last(int x, int l, int r, int ll, int rr, const function<bool(const node&)> &f) {
        if (ll <= l && r <= rr) {
            if (!f(tree[x])) {
                return -1;
            }
            return find_last_knowingly(x, l, r, f);
        }
        push(x, l, r);
        int y = (l + r) >> 1;
        int z = x + ((y - l + 1) << 1);
        int res = -1;
        if (rr > y) {
            res = find_last(z, y + 1, r, ll, rr, f);
        }
        if (ll <= y && res == -1) {
            res = find_last(x + 1, l, y, ll, rr, f);
        }
        pull(x, z);
        return res;
    }
    
    id1(int _n) : n(_n) {
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1);
    }
    
    template <typename M>
    id1(const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        tree.resize(2 * n - 1);
        build(0, 0, n - 1, v);
    }
    
    node get(int ll, int rr) {
        assert(0 <= ll);
        assert(ll <= rr);
        assert(rr <= n - 1);
        return get(0, 0, n - 1, ll, rr);
    }
    
    node get(int p) {
        assert(0 <= p && p <= n - 1);
        return get(0, 0, n - 1, p, p);
    }
    
    template <typename... M>
    void modify(int ll, int rr, const M&... v) {
        assert(0 <= ll);
        assert(ll <= rr);
        assert(rr <= n - 1);
        modify(0, 0, n - 1, ll, rr, v...);
    }
    
    

    

    
    int find_first(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll);
        assert(ll <= rr);
        assert(rr <= n - 1);
        return find_first(0, 0, n - 1, ll, rr, f);
    }
    
    int find_last(int ll, int rr, const function<bool(const node&)> &f) {
        assert(0 <= ll);
        assert(ll <= rr);
        assert(rr <= n - 1);
        return find_last(0, 0, n - 1, ll, rr, f);
    }
};



class dsu {
    public:
    VI p;
    VLL ml;
    VLL mr;
    VLL mx;
    VLL s;
    int n;

    dsu (int _n) : n(_n) {
        assert(n > 0);
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        ml.resize(n + 1);
        iota(ml.begin(), ml.end(), 0);
        mr.resize(n + 1);
        iota(mr.begin(), mr.end(), 0);
        mx.resize(n + 1);
        iota(mx.begin(), mx.end(), 0);
        s.resize(n + 1);
        iota(s.begin(), s.end(), 0);
    }

    template <typename M>
    dsu (const vector<M> &v) {
        n = v.size();
        assert(n > 0);
        p.resize(n + 1);
        iota(p.begin(), p.end(), 0);
        ml.resize(n + 1);
        mr.resize(n + 1);
        mx.resize(n + 1);
        s.resize(n + 1);
        ff (i, 1, n + 1) {
            ml[i] = mr[i] = mx[i] = s[i] = v[i];
        }
    }
    
    inline int find (int x) {
        return (x == p[x] ? x : (p[x] = find(p[x])));
    }
    
    inline bool unite (int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        p[x] = y;
        mx[y] = max({mx[x], mx[y], max(0LL, mr[x]) + ml[y], mr[x] + max(0LL, ml[y])});
        mr[y] = max(mr[y], max(0LL, mr[x]) + s[y]);
        ml[y] = max(ml[x], max(0LL, ml[y]) + s[x]);
        s[y] += s[x];
        return true;
    }
};




template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
    public:
    int n;
    vector<vector<T>> mat;
    F func;
    
    SparseTable(const vector<T>& a, const F& f) : func(f) {
        n = static_cast<int>(a.size());
        int max_log = 32 - __builtin_clz(n);
        mat.resize(max_log);
        mat[0] = a;
        for (int j = 1; j < max_log; j++) {
            mat[j].resize(n - (1 << j) + 1);
            for (int i = 0; i <= n - (1 << j); i++) {
                mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
            }
        }
    }
    
    T get(int from, int to) const {
        assert(0 <= from && from <= to && to <= n - 1);
        int lg = 32 - __builtin_clz(to - from + 1) - 1;
        return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
    }
};



template <typename T>
class graph {
    public:
    struct edge {
        int from;
        int to;
        T cost;
    };
    
    vector<edge> edges;
    vector<vector<int>> g;
    int n;
    
    graph(int _n) : n(_n) {
        g.resize(n);
    }
    
    virtual int add(int from, int to, T cost) = 0;
};
    
template <typename T>
class forest : public graph<T> {
    public:
    using graph<T>::edges;
    using graph<T>::g;
    using graph<T>::n;
    
    forest(int _n) : graph<T>(_n) {
    }
    
    int add(int from, int to, T cost = 1) {
        assert(0 <= from && from < n && 0 <= to && to < n);
        int id = (int) edges.size();
        assert(id < n - 1);
        g[from].push_back(id);
        g[to].push_back(id);
        edges.push_back({from, to, cost});
        return id;
    }
};
    
template <typename T>
class id2 : public forest<T> {
    public:
    using forest<T>::edges;
    using forest<T>::g;
    using forest<T>::n;
    
    vector<int> pv;
    vector<int> pe;
    vector<int> order;
    vector<int> pos;
    vector<int> end;
    vector<int> sz;
    vector<int> root;
    vector<int> depth;
    vector<T> dist;
    
    id2(int _n) : forest<T>(_n) {
    }
    
    void init() {
        pv = vector<int>(n, -1);
        pe = vector<int>(n, -1);
        order.clear();
        pos = vector<int>(n, -1);
        end = vector<int>(n, -1);
        sz = vector<int>(n, 0);
        root = vector<int>(n, -1);
        depth = vector<int>(n, -1);
        dist = vector<T>(n);
    }
    
    void clear() {
        pv.clear();
        pe.clear();
        order.clear();
        pos.clear();
        end.clear();
        sz.clear();
        root.clear();
        depth.clear();
        dist.clear();
    }
    
    private:
    void do_dfs(int v) {
        pos[v] = (int) order.size();
        order.push_back(v);
        sz[v] = 1;
        for (int id : g[v]) {
            if (id == pe[v]) {
                continue;
            }
            auto &e = edges[id];
            int to = e.from ^ e.to ^ v;
            depth[to] = depth[v] + 1;
            dist[to] = dist[v] + e.cost;
            pv[to] = v;
            pe[to] = id;
            root[to] = (root[v] != -1 ? root[v] : to);
            do_dfs(to);
            sz[v] += sz[to];
        }
        end[v] = (int) order.size() - 1;
    }
    
    void do_dfs_from(int v) {
        depth[v] = 0;
        dist[v] = T{};
        root[v] = v;
        pv[v] = pe[v] = -1;
        do_dfs(v);
    }
    
    public:
    void dfs(int v, bool clear_order = true) {
        if (pv.empty()) {
            init();
        } else {
            if (clear_order) {
                order.clear();
            }
        }
        do_dfs_from(v);
    }
    
    void dfs_all() {
        init();
        for (int v = 0; v < n; v++) {
            if (depth[v] == -1) {
                do_dfs_from(v);
            }
        }
        assert((int) order.size() == n);
    }
};
    
template <typename T>
class id3 : public id2<T> {
    public:
    using id2<T>::edges;
    using id2<T>::g;
    using id2<T>::n;
    using id2<T>::pv;
    using id2<T>::pos;
    using id2<T>::end;
    using id2<T>::depth;
    
    int h;
    vector<vector<int>> pr;
    
    id3(int _n) : id2<T>(_n) {
    }
    
    inline void build_lca() {
        assert(!pv.empty());
        int max_depth = 0;
        for (int i = 0; i < n; i++) {
            max_depth = max(max_depth, depth[i]);
        }
        h = 1;
        while ((1 << h) <= max_depth) {
            h++;
        }
        pr.resize(n);
        for (int i = 0; i < n; i++) {
            pr[i].resize(h);
            pr[i][0] = pv[i];
        }
        for (int j = 1; j < h; j++) {
            for (int i = 0; i < n; i++) {
                pr[i][j] = (pr[i][j - 1] == -1 ? -1 : pr[pr[i][j - 1]][j - 1]);
            }
        }
    }
    
    inline bool anc(int x, int y) {
        return (pos[x] <= pos[y] && end[y] <= end[x]);
    }
    
    inline int go_up(int x, int up) {
        assert(!pr.empty());
        up = min(up, (1 << h) - 1);
        for (int j = h - 1; j >= 0; j--) {
            if (up & (1 << j)) {
                x = pr[x][j];
                if (x == -1) {
                break;
                }
            }
        }
        return x;
    }
    
    inline int lca(int x, int y) {
        assert(!pr.empty());
        if (anc(x, y)) {
            return x;
        }
        if (anc(y, x)) {
            return y;
        }
        for (int j = h - 1; j >= 0; j--) {
            if (pr[x][j] != -1 && !anc(pr[x][j], y)) {
                x = pr[x][j];
            }
        }
        return pr[x][0];
    }
};

void init_code(){
    ios_base::sync_with_stdio(false);

    






}

int LIS(VL v) {
    int n = v.size();
    VI dp(n);
    dp[0] = 1;
    int ans = 0;
    ff (i, 1, n) {
        int cnt = 1;
        FF (j, i - 1, 0) {
            if (v[i] > v[j]) {
                cnt = max(cnt, dp[j] + 1);
            }
        }
        dp[i] = cnt;
    }
    ff (i, 0, n) {
        ans = max(ans, dp[i]);
    }
    return ans;
}


void solved(void)
{
    int n;
    cin >> n;
    string ans(n, '?');

    string ss;
    cin >> ss;

    int tt = n % 3;
    string s(n, 'F');
    int Q = 0;
    auto Ask = [&] (string s) {
        Q++;
        int k = 0;
        cout << s << endl;

        ff (i, 0, n) {
            if (ss[i] == s[i]) k++;
        }

        cin >> k;

        if (k == -1 || k == n) exit(0);
        if (Q == 675) exit(0);
        return k;
    };
    int t0 = Ask(s);
    if (tt == 1) {
        s[0] = 'T';
        ans[0] = 'T';
        int t = 1;
        int t1 = Ask(s);
        if (t1 - t0 == -1) {
            s[0] = 'F';
            ans[0] = 'F';
            t--;
        }
        t0 += t;
    }
    
    if (tt == 2) {
        s[1] = 'T';
        ans[1] = 'T';
        int t = 1;
        int t1 = Ask(s);
        if (t1 - t0 == -1) {
            s[1] = 'F';
            ans[1] = 'F';
            t--;
        }
        t0 += t;
        s[0] = 'T';
        ans[0] = 'T';
        t = 1;
        int t2 = Ask(s);
        if (t2 - t0 == -1) {
            s[0] = 'F';
            ans[0] = 'F';
            t--;
        }
        t0 += t;
    }
    

    

    string s4 = s;
    ff (i, tt, n) {
        s4[i + 0] = 'T';
        s4[i + 1] = 'F';
        s4[i + 2] = 'T';
        i += 2;
    }
    int t4 = Ask(s4);
    

    ff (i, tt, n) {
        

        string s3 = s;
        s3[i + 1] = 'T';
        s3[i + 2] = 'T';
        ans[i + 1] = 'T';
        ans[i + 2] = 'T';
        int t2 = Ask(s3);
        

        if (t2 - t0 == 2) {
            s3[i + 0] = 'T';
            ans[i + 0] = 'T';
            int t1 = Ask(s3);
            if (t1 - t2 == -1) {
                s3[i + 0] = 'F';
                ans[i + 0] = 'F';
            }
        }
        if (t2 - t0 == -2) {
            ans[i + 1] = 'F';
            ans[i + 2] = 'F';
            s3[i + 0] = 'T';
            ans[i + 0] = 'T';
            int t1 = Ask(s3);
            if (t1 - t2 == -1) {
                s3[i + 0] = 'F';
                ans[i + 0] = 'F';
            }
        }
        

        s3 = s4;
        if (t2 == t0) {
            

            s3[i + 0] = 'F';
            s3[i + 1] = 'T';
            s3[i + 2] = 'F';
            int t1 = Ask(s3);
            

            if (t1 - t4 == 3) {
                ans[i + 0] = 'F';
                ans[i + 1] = 'T';
                ans[i + 2] = 'F';
            } else if (t1 - t4 == -3) {
                ans[i + 0] = 'T';
                ans[i + 1] = 'F';
                ans[i + 2] = 'T';
            } else if (t1 - t4 == 1) {
                ans[i + 0] = 'T';
                ans[i + 1] = 'T';
                ans[i + 2] = 'F';
            } else {
                ans[i + 0] = 'F';
                ans[i + 1] = 'F';
                ans[i + 2] = 'T';
            }
        }
        i += 2;
        

    }
    int res = Ask(ans);
    

}

signed main()
{
    init_code();
	ll t = 1;
    

	while(t--){
        solved();
	}
}