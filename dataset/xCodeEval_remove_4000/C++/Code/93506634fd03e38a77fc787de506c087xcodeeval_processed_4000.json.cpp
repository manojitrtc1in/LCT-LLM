






using namespace std;



























namespace std {
    template<class T>
    T begin(std::pair<T, T> p)
    {
        return p.first;
    }
    template<class T>
    T end(std::pair<T, T> p)
    {
        return p.second;
    }
}



template<class Iterator>
std::reverse_iterator<Iterator> id2(Iterator it)
{
    return std::reverse_iterator<Iterator>(it);
}


template<class Range>
std::pair<std::reverse_iterator<decltype(begin(std::declval<Range>()))>, std::reverse_iterator<decltype(begin(std::declval<Range>()))>> id1(Range &&r)
{
    return std::make_pair(id2(::begin(r)), id2(::end(r)));
}




namespace io{
    template<typename T> void println(const T &t) { cout << t << '\n'; }
    template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }

    template<typename T> void print(const T &t) { cout << t << ' '; }

    template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t; print(rest...); }



    template<class T> void scan(T &t) { cin >> t; }
    template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
}
using namespace io;

namespace alias{
    using ll = long long;
    using ull = unsigned long long;
    using vec = vector<ll>;
    using mat = vector<vec>;
    using pii = pair<int, int>;
    using pdd = pair<double, double>;
    using pip = pair<int, pii>;
    using szt = size_t;
    using vi = vector<int>;
    using vl = vector<ll>;
    using vb = vector<bool>;
    using vpii = vector<pii>;
    using vvi = vector<vi>;
    using pli = pair<ll,int>;
    using wg = vector<vpii>; 

    using pll = pair<long long, long long>;
}
using namespace alias;

template<class T> inline T min(T a, T b, T c){return min(min(a, b), c);}
template<class T> inline T max(T a, T b, T c){return max(max(a, b), c);}
template<class T> void Min(T &a, const T &b){ a = min(a, b); }
template<class T> void Max(T &a, const T &b){ a = max(a, b); }
namespace util{
    template<class T> int sign(const T &a) { return a == 0 ? 0 : a > 0 ? 1 : -1; }
    

    template<class V, class Cont>
    int get_rank(const V &k, const Cont &a){
        return std::lower_bound(all(a), k) - a.begin();
    }
    

    void rotate(double &x, double &y, double theta) {
        double tx = cos(theta) * x - sin(theta) * y;
        double ty = sin(theta) * x + cos(theta) * y;
        x = tx, y = ty;
    }
    int length(ll x){return snprintf(nullptr, 0, "%lld", x);}
    vi get_d(ll x){
        vi res;
        while(x) {
            res.pb(x%10);
            x /= 10;
        }
        reverse(all(res));
        return res;
    }
    template <class T> T parity(const T &a){
        return a & 1;
    }
    auto bo=[](int x){
        bitset<10> a(x);
        cout << a << endl;
    };
    template <class T>
    void out (const vector<T> &a){
        std::copy(a.begin(), a.end(), std::ostream_iterator<T>(std::cout, ", "));
        cout << endl;
    }
    using order_statistic_tree = __gnu_pbds::tree<
            int,
            __gnu_pbds::null_type,
            greater<int>,
            __gnu_pbds::rb_tree_tag,
            __gnu_pbds::tree_order_statistics_node_update>;
}



const double pi = acos(-1);
const ll mod = 1e9+7;


template<class T>
inline void add_mod(T &a, const T &b) {
    a += b;
    if (a >= mod) a -= mod;
}
template<class T>
inline void sub_mod(T &a, const T &b){
    a -= b;
    if (a < 0) a += mod;
}



mat operator*(const mat &a, const mat &b) {
    mat c(a.size(), vec(b[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            if (a[i][j]) { 

                for (size_t k = 0; k < b[0].size(); k++) {
                    add_mod(c[i][k], a[i][j] * b[j][k] % mod);
                }
            }
        }
    }
    return c;
}

vec operator*(const mat &a, const vec &b) {
    vec c(a.size());
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < a[0].size(); j++) {
            add_mod(c[i], a[i][j] * b[j] % mod);
        }
    }
    return c;
}

mat pow(mat a, ull n) {
    mat res(a.size(), vec(a[0].size()));
    for (size_t i = 0; i < a.size(); i++) {
        res[i][i] = 1;
    }
    while (n) {
        if (n & 1) {
            res = res * a;
        }
        a = a * a;
        n >>= 1;
    }
    return res;
}







































ll POW(ll x, ll n, int mod = mod){
    ll res = 1;
    for (; n; n /= 2, x *= x, x %= mod) {
        if (n & 1) {
            res *= x;
            res %= mod;
        }
    }
    return res;
}

namespace nt{
    ll INV(ll x) {
        return POW(x, mod - 2);
    }

    ll inv(ll x){
        return x == 1? 1: (mod - mod/x * inv(mod%x) % mod);
    }
    vi sieve(int n) { 

        vi minp(n+1);
        vi P;
        rng(i, 2, n+1) {
            if(!minp[i]) {
                P.pb(i);
                minp[i] = i; 

            }
            FOR(p, P) {
                if(p > minp[i] || p * i > n) break;
                minp[p*i] = p;
            }
        }
        return P;
    }
}








namespace ds{
    struct dsu{
        vector<int> par;
        explicit dsu(int n){
            par.resize(n);
            rng(i, 0, n){
                par[i] = i;
            }
        }
        bool same(int x, int y){
            return root(x) == root(y);
        }
        int root(int x){
            return par[x] == x ? x : par[x] = root(par[x]);
        }
        void unite(int x, int y){
            x = root(x);
            y = root(y);
            par[x] = y;
        }
    };
    template <typename T>
    struct bit {
        vector<T> a;
        explicit bit(int n, int v = 0) {
            a.resize(n + 1);
            if(v != 0) {
                for (int i = 1; i <= n; ++i) a[i] = v;
            }
        }

        T sum(T x) {
            T res = 0;
            while (x) {
                res += a[x];
                x -= x & -x;
            }
            return res;
        }

        T sum(int l, int r) {
            if (l > r) return 0;
            return sum(r) - sum(l - 1);
        }

        void add(int x, T v) {
            while (x < a.size()) {
                a[x] += v;
                x += x & -x;
            }
        }
        void clear(){
            fill(a.begin(), a.end(), 0);
        }
    };

    template<typename Key, typename Compare = std::less<Key>>
    struct mono_queue{
        mono_queue() = default;
        explicit mono_queue(int max_size):window(max_size){}
        int window = INT_MAX; 

        int cnt = 0;
        deque<pair<Key,int>> q;
        Compare cmp = Compare();
        void push_back(const Key &k){
            while(!q.empty() && !cmp(q.back().first, k)){
                q.pop_back();
            }
            q.emplace_back(k, cnt++);
            while(q.back().second - q.front().second >= window){
                q.pop_front();
            }
        }

        decltype(q.front()) front(){
            return q.front();
        }

        decltype(q.back()) back(){
            return q.back();
        }

        size_t size()const{
            return q.size();
        }
        void clear(){
            q.clear();
            cnt = 0;
        }
    };
}
using namespace  ds;

template<class node>
struct segment_tree{
    vector<node> a;
    using tag = typename node::lazy_tag;
    segment_tree() = default;
    inline int lson(int i){return i*2;}
    inline int rson(int i){return i*2+1;}
    template<class T>
    void build(int i, int l, int r, const T *arr){
        if(l==r){
            a[i] = node(arr[l]);
        }
        else{
            int mid = (l+r)/2;
            build(lson(i), l, mid, arr);
            build(rson(i), mid+1, r, arr);
            a[i].put_up(a[lson(i)], a[rson(i)]);
        }
    }

    template<class T>
    segment_tree(const T *arr, int n){
        a.resize(4*(ull)n);
        build(1, 1, n, arr); 

    }

    void push_down(int i){
        a[lson(i)].put_tag(a[i].tag);
        a[rson(i)].put_tag(a[i].tag);
        a[i].tag = {};
    }

    template<class T> using UnaryFunction = std::function<T(const node &)>;
    template<class T> using MergeFunction = std::function<T(T,T)>;

    template<typename T>
    T query(int i, int l, int r, int ql, int qr, const UnaryFunction<T> &get_res, const MergeFunction<T> &merge){
        if(l > qr || r < ql) return {};
        if(ql <= l && r <= qr){
            return get_res(a[i]);
        }
        int mid = (l+r)/2;
        push_down(i);
        return merge(query(lson(i), l, mid, ql, qr, get_res, merge), query(rson(i), mid+1, r, ql, qr, get_res, merge));
    }

    virtual void maintain(int i, int l, int r){}; 


    void change(int i, int l, int r, int ql, int qr, const tag &tag){
        if(l > qr || r < ql) return;
        if(l >= ql && r <= qr){
            a[i].put_tag(tag);
            maintain(i, l, r);
        }
        else{
            int mid = (l+r)/2;
            push_down(i);
            change(lson(i), l, mid, ql, qr, tag);
            change(rson(i), mid+1, r, ql, qr, tag);
            a[i].put_up(a[lson(i)], a[rson(i)]);
        }
    }
};

struct node{
    using lazy_tag = int;
    int min; int sum; lazy_tag tag;
    node()=default;
    void put_up(const node &l, const node &r){
    }
    void put_tag(const lazy_tag &ft) {

    }
};

template <class node>
struct tree : segment_tree<node>{
    using segment_tree<node>::a; 

    using segment_tree<node>::lson;
    using segment_tree<node>::rson;
    using segment_tree<node>::query;
    using segment_tree<node>::push_down;
    tree()= default;
    template<typename T>
    tree(const T *arr, int n):segment_tree<node>(arr, n){}

    

    void maintain(int i, int l, int r) override {
    }
};

template<typename T> T ceil(const T a, const T b) {
    T c = a / b;
    return c + (c * b != a);
}

struct dinic {
    struct arc {
        int to, rcap, next;

        arc() = default;

        arc(int to, int rcap, int next) : to(to), rcap(rcap), next(next) {}
    };

    vector<arc> e;

    void add_arc(int u, int v, int cap) {
        e.emplace_back(v, cap, head[u]);
        head[u] = (int) e.size() - 1;
        e.emplace_back(u, 0, head[v]);
        head[v] = (int) e.size() - 1;
    }

    int n;
    vector<int> head;

    dinic(int n) : n(n){
        head.resize((size_t) n); 

        level.resize((size_t) n );
        iter.resize((size_t) n);
        fill(head.begin(), head.end(), -1);
    }

    vector<int> level;

    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.push(s);
        for (int u; !que.empty();) {
            u = que.front(), que.pop();
            for (int i = head[u]; i != -1; i = e[i].next) {
                int &v = e[i].to;
                if (e[i].rcap > 0 && level[v] < 0) {
                    level[v] = level[u] + 1;
                    que.push(v);
                }
            }
        }
    }

    vector<int> iter;

    int dfs(int u, int t, int f) {

        if (u == t) return f;
        

        for (int &i = iter[u]; i != -1; i = e[i].next) {
            int &v = e[i].to, &r = e[i].rcap;
            if (r > 0 && level[u] < level[v]) {
                int d = dfs(v, t, min(f, r));
                if (d > 0) {
                    r -= d;
                    e[i ^ 1].rcap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    int max_flow(int s, int t){
        const int INF=1<<30;
        for(int flow=0;;){
            bfs(s);
            if(level[t]<0) return flow;
            iter = head;
            for(int f; (f=dfs(s, t, INF)); flow+=f);
        }
    }
};


void add_mod(ll &a, ll b, ll mod) {
    a += b;
    if(a >= mod) a -= mod;
}


template <class G>
struct lca {
    int n; 

    const G &g;
    int lg;
    vi dep;
    vvi fa;

    lca(int n, const G &g, int root) : n(n), g(g), lg(32 - __builtin_clz(n)) {
        dep.assign(n + 1, 0);
        fa.assign(lg, vi(n + 1));
        dfs(root, 0);
    }

    int query(int u, int v) {
        if (dep[u] < dep[v]) swap(u, v);

        int dif = dep[u] - dep[v];

        rng (i, 0, lg) {
            if (dif & 1 << i) u = fa[i][u];
        }

        if (u == v) return u;

        dwn (i, lg - 1, 0) {
            if (fa[i][u] != fa[i][v]) {
                u = fa[i][u];
                v = fa[i][v];
            }
        }
        return fa[0][u];
    }

    void dfs(int u, int f) {
        rng (i, 1, lg) {
            fa[i][u] = fa[i - 1][fa[i - 1][u]];
        }
        FOR (v, g[u]) {
            if (v != f) {
                fa[0][v] = u;
                dep[v] = dep[u] + 1;
                dfs(v, u);
            }
        }
    }
};

struct id0 {
    vector<int> size;
    vector<bool> used;
    vector<int> fa; 

    int n;
    const vector<vector<int>> &g; 


    int centroid, cmx; 

    void dfs(int u, int f, int n) { 

        size[u] = 1;
        int mx = 0;
        for (auto &v: g[u]) {
            if (v != f && !used[v]) {
                dfs(v, u, n);
                size[u] += size[v];
                Max(mx, size[v]);
            }
        }
        Max(mx, n - size[u]);
        if (mx < cmx) {
            centroid = u;
            cmx = mx;
        }
    }

    void divide(int u, int n, int c) { 

        cmx = INT_MAX;
        dfs(u, 0, n);
        fa[centroid] = c; 

        used[centroid] = true;
        

        c = centroid;
        FOR(v, g[c]) { 

            if (!used[v]) {
                int m = size[v] < size[c] ? size[v] : n - size[c]; 

                divide(v, m, c);
            }
        }
    }

    id0(int n, const vector<vector<int>> &g) : n(n), g(g) {
        used.assign(n + 1, false);
        size.resize(n + 1);
        fa.resize(n + 1);
        divide(1, n, 0); 

    }
};
struct que{
    priority_queue<int> dis, del;
    int top() {
        while (!del.empty() && dis.top() == del.top()) {
            dis.pop();
            del.pop();
        }
        return dis.empty() ? -1 : dis.top();
    }

    void pop() {
        while (!del.empty() && dis.top() == del.top()) {
            dis.pop();
            del.pop();
        }
        if (!dis.empty()) dis.pop();
    }

    void erase(int x) {
        del.push(x);
    }

    void push(int x) {
        dis.push(x);
    }

    size_t size() {
        return dis.size() - del.size();
    }

    int query() {
        if (size() < 2) return -1;
        int t1 = top();
        pop();
        int t2 = top();
        push(t1);
        return t1 + t2;
    }
};

const ll LINF = LLONG_MAX/10;
const int INF = INT_MAX/10;
const double eps = 1e-7;

const int M = 2e5+5;
const int N = 2e3+5;


string ask(int x) {
    println(x, 1);
    fflush(stdout);
    string c;
    cin >> c;
    return c;
}



int main() {


    freopen("main.in", "r", stdin);





    int n;
    cin >> n;

    int l = 0, r = 1000000000;

    auto cl = ask(l);

    rep(n-1) {
        int x = l + (r-l) / 2;
        auto c = ask(x);
        if (c == cl)
            l = x;
        else r = x;
    }

    println(l, 0, r, 2);
    fflush(stdout);






    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";

    return 0;
}
