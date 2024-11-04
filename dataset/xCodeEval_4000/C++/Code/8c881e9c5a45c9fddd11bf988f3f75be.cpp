#ifdef LOCAL




#endif


#include <bits/stdc++.h>

using namespace std;
#define sq(x) (x)*(x) 

#define FAST_READ ios::sync_with_stdio(false); cin.tie(nullptr);
#ifdef LOCAL
#define see(x) cout  <<"<DBG> " << #x << ": " << (x) << endl
#endif
#ifndef LOCAL
#define see(x)
#endif
#define LSON(x) ((x) * 2)
#define RSON(x) ((x) * 2 + 1)
template<typename A, typename B>
void Min(A &a, const B &b){
    if (b < a) a = b;
}
template<typename A, typename B>
void Max(A &a, const B &b){
    if (b > a) a = b;
}

#if __cplusplus < 201402L
template<class Iterator>
std::reverse_iterator<Iterator> make_reverse_iterator(Iterator it)
{
    return std::reverse_iterator<Iterator>(it);
}
#endif

template <typename iter_t>
struct iter_pair {
    iter_t _beg, _end;
    iter_t begin(){return _beg;}
    iter_t end(){return _end;}
};

template<class cont> iter_pair<reverse_iterator<decltype(begin(declval<cont>()))>>
reverse(cont &&r) {
    return {make_reverse_iterator(end(r)), make_reverse_iterator(begin(r))};
}

template<typename T> void dprintln(const T &t) { cout << t << endl; } 

template<typename T, typename ...Args> void dprintln(const T &t, const Args &...rest) { cout << t << ' '; dprintln(rest...); }
template<typename T> void println(const T &t) { cout << t << '\n'; }
template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }

template<typename T> void print(const T &t) { cout << t << ' '; }

template<typename T, typename ...Args> void print(const T &t, const Args &...rest) { cout << t << ' '; print(rest...); }



template<class T> void scan(T &t) { cin >> t; }
template<class T, class ...Args> void scan(T &a, Args &...rest) { cin >> a; scan(rest...); }
template <typename T> void read(vector<T> &vec) {for(auto &x: vec) cin >> x;}
using ull = unsigned long long;
using ll = long long;
using ul = unsigned long;
using vl = vector<ll>;
using vi = vector<int>;
using pii = pair<int,int>;
using vb = vector<bool>;
using vpii = vector<pii>;
template <typename int_t>
inline int_t lowbit(int_t x) {return x & -x;}
#define rng(i, a, b) for(int i = (int)(a); i < (int)(b); ++i)
#define down(i, b, a) for (int i = (b); i >= (a); i--)
#define rep(n) for(int _ = 0, __ = (int)n; _ < __; _++)
#define stp(i, a, b, c) for (int i = (a); i < (b); i += (c))
#define FOR(x, cont) for (const auto &x: cont)
#define INC(init, x, y) for (init; x <= y; ++x)
#define For(x, cont) for (auto &x: cont)
#define all(x) begin(x), end(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define SZ(x) (int)(x).size()
#define UP(i, l, r) for(i = l; i <= r; ++i)
#define DOWN(i, r, l) for (i = r; i >= l; --i)
#define Dec(a, b) for (; a >= b; --a)
template <typename T, typename Comp = less<T>>
using pq = priority_queue<T, vector<T>, Comp>;
#define popcnt(x) __builtin_popcountll((x))
#define SET(arr, v) memset(arr, (v), sizeof (arr))
#define UNIQ(vec) (vec).erase(unique(all(vec)), end(vec))
#define LB(cont, x) int(lower_bound(all(cont), x) - begin(cont))
#define UB(cont, x) int(upper_bound(all(cont), x) - begin(cont))
#define AI(name, n, m) vv<int> name(n, vi(m));
#define AL(name, n, m) vv<ll> name(size_t(n), vl(size_t(m)));
auto bet = [](const ll x, const ll y, const ll i) {
    return x <= i && i <= y;
};

template<typename T1, typename T2>
T1 ceil(T1 x, T2 y) { 

    return (x + y - 1) / y;
}


inline int h_bit(unsigned long long x) {
    return sizeof(unsigned long long) * 8 - 1 - __builtin_clzll(x);
}

int pow2(int x){ 

    return 1 << (h_bit((ull)x) + (x != lowbit(x)));
}



template <typename T>
struct bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    explicit bit(int n,  function<T(T,T)> bin_op = [](const T &a, const T &b){return max(a, b);}, int v = 0):bin_op(bin_op){
        a.resize((ul)n + 1);
        for (int i = 1; i <= n; ++i) a[i] = v;
    }

    T prefix(T x) {
        T res = 0;
        while (x) {
            res = bin_op(res, a[x]);


            x -= x & -x;
        }
        return res;
    }

    T sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void modify(int x, T v) {
        while (x < a.size()) {
            a[x] = bin_op(a[x], v);
            x += x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), 0);
    }
};

template <typename T>
struct r_bit {
    vector<T> a;
    function<T(T,T)> bin_op;
    explicit r_bit(int n,  function<T(T,T)> bin_op = [](const T &a, const T &b){return max(a, b);}, int v = 0):bin_op(bin_op){
        a.resize((ul)n + 1);
        for (int i = 1; i <= n; ++i) a[i] = v;
    }

    T suffix(int x, T init) {
        while (x < SZ(a)) {
            init = bin_op(init, a[x]);


            x += x & -x;
        }
        return init;
    }

    T sum(int l, int r) {
        if (l > r) return 0;
        return sum(r) - sum(l - 1);
    }

    void modify(int x, T v) {
        while (x > 0) {
            a[x] = bin_op(a[x], v);
            x -= x & -x;
        }
    }
    void clear(){
        fill(a.begin(), a.end(), 0);
    }
};



vi get_prime(int n) {
    vi minp((ul)n + 1), p;
    for (int i = 2; i <= n; i++) {
        if (!minp[i]) {
            minp[i] = i;
            p.pb(i);
        }
        FOR(x, p) {
            if (x <= minp[i] && x * i <= n)
                minp[x * i] = x;
            else break;
        }
    }
    return p;
}

const int mod = 998244353; 


inline void mul(int &x, const int y) {
    x = int(ll(x) * y % mod);
}
inline int Mul(int x, const int y) {
    return (int)(ll(x) * y % mod);
}
inline void add(int &x, const int y) {
    x += y;
    if (x >= mod) x -= mod;
}
inline int Add(int x, int y) {
    x += y;
    if (x >= mod) x -= mod;
    return x;
}
inline int Sub(int x, int y) {
    x -= y; if (x < 0) x += mod;
    return x;
}
inline ll submod(ll x, ll y) {
    return x >= y ? x - y : x - y + mod;
}
inline ll addmod(ll x, ll y) {
    x += y;
    return x >= mod ? x - mod : x;
}

inline void sub_mod(ll &x, const ll y) {
    x -= y;
    if (x < 0) x += mod;
}


template<typename T> using vv = vector<vector<T>>;
template <typename T1, typename T2 = T1> using vp = vector<pair<T1,T2>>;
template<typename T, int n> using va = vector<array<T,n>>;

#ifdef __GNUC__
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T>
using rank_tree = __gnu_pbds::tree<
        T,
        __gnu_pbds::null_type,
        less<T>,
        __gnu_pbds::rb_tree_tag,
        __gnu_pbds::tree_order_statistics_node_update>;
#endif



struct UF{
    vi par, sz;
    int n_tree;
    explicit UF(int n) { 

        par.assign(n, 0);
        sz.assign(n, 1);
        rng (i, 0, n) par[i] = i;
        n_tree = n;
    }
    int n_cluster() const {
        return n_tree;
    }
    int size(int x) {
        return sz[root(x)];
    }
    int root(int x) {
        return x == par[x] ? x : par[x] = root(par[x]);
    }
    bool unite(int x, int y) {
        int rx = root(x), ry = root(y);
        if(rx != ry) {
            par[rx] = ry;
            --n_tree;
            sz[ry] += sz[rx];
            return true;
        }
        return false;
    }
};

int fp (int x, ll n) { 

    if(n < 0) {
        x = fp(x, mod - 2);
        n = -n;
    }
    int ans = 1;
    while(n){
        if(n&1) mul(ans, x);
        n /= 2;
        mul(x, x);
    }
    return ans;
}

using idx_t = long;
template <typename  T, typename Compare = std::less<T>>
struct ST{
    size_t n; 

    vv<T> a;
    ST()=default;
    template <typename ptr_t>
    ST(ptr_t beg, ptr_t end):n(end-beg){
        a.resize((size_t)h_bit(n)+1); 

        a[0].assign(beg, end);
        rng (i, 0, SZ(a)-1) {
            a[i+1].resize(n);
            rng(j, 0, n - (1 << i)) {
                a[i+1][j] = min(a[i][j], a[i][j+(1<<i)], Compare());
            }
            rng(j, n-(1 << i), n) {
                a[i+1][j] = a[i][j];
            }
        }
    }

    T query(idx_t l, idx_t r) { 

        int i = h_bit(r - l + 1ul);
        return min(a[i][l], a[i][r+1-(1<<i)], Compare());
    }
};

vi get_popcnt(int n) {
    vi res((ul)n + 1);
    rng (i, 0, n) {
        if (i * 2 <= n) res[i * 2] = res[i];
        if ((i & 1) == 0) res[i + 1] = res[i] + 1;
    }
    return res;
}



using poly = vector<int>;

void bit_reverse_swap(vector<int> &a) {
    int n = SZ(a);
    for (int i = 1, j = n >> 1, k; i < n - 1; i++) {
        if (i < j) swap(a[i], a[j]);
        

        for (k = n >> 1; j >= k; j -= k, k >>= 1);    

        j += k;
    }
}

void FFT(vector<int> &a, int type) {
    bit_reverse_swap(a);
    int n = SZ(a);
    for (int i = 2; i <= n; i *= 2) {
        const auto wi = fp(3, type * (mod - 1) / i); 

        for (int j = 0; j < n; j += i) {
            auto w(1);
            for (int k = j, h = i >> 1; k < j + h; k++) {
                auto t = Mul(w, a[k + h]), u = a[k];
                a[k] = Add(u, t);
                a[k + h] = Sub(u, t);
                mul(w, wi);
            }
        }
    }
    const int inv = fp(n, -1);
    if (type == -1) for (auto &x : a) mul(x, inv);
}

void fp(poly &a, const int n) {
    a.resize((ul)pow2((SZ(a)-1) * n + 1));
    FFT(a, 1);
    for(auto &x: a) x = fp(x, n);
    FFT(a, -1);
}


string to_string(string s) {
    return '"' + s + '"';
}

string to_string(const char* s) {
    return to_string((string) s);
}

string to_string(bool b) {
    return (b ? "true" : "false");
}

template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto &x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}

void debug_out() { cerr << endl; }

template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}

#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif







int main() {
    FAST_READ
#ifdef LOCAL
    cout << fixed << setprecision(10);
    ifstream in("main.in");
    cin.rdbuf(in.rdbuf());
#endif

    int n, k; scan(n, k); vi a(n); read(a);
    vv<int> g(n + 1);
    r_bit<int> b(n + 1, [](int x, int y){return min(x, y);}, n);





    down (i, n - 1, 0) {
         int fa = b.suffix(a[i] + 1, n);
         debug(i, fa);
         g[fa].pb(i);
         b.modify(a[i], i);
    }

    function<void(int)> dfs;
    int dfs_clock = 0;
    vi l(n + 1), r(n + 1);
    dfs = [&](int u) {
        l[u] = ++dfs_clock;
        FOR(v, g[u]) {
            dfs(v);
        }
        r[u] = dfs_clock;
    };

    dfs(n);
    rng (i, 0, n + 1) {


    }

    struct node {
        int add, max;
    };

    vector<node> tree(4 * (n + 1));

    auto push_up = [&](int pos) {
        assert(pos * 2 + 1 < SZ(tree));
        tree[pos].max = max(tree[pos * 2].max, tree[pos * 2 + 1].max);
    };

    auto push_down = [&](int pos) {
        auto t = tree[pos].add;
        assert(pos * 2 + 1 < SZ(tree));
        tree[LSON(pos)].max += t;
        tree[LSON(pos)].add += t;
        tree[RSON(pos)].max += t;
        tree[RSON(pos)].add += t;
        tree[pos].add = 0;
    };

    function<void(int,int,int,int,int,int)> modify;
    modify = [&](int pos, int l, int r, int ql, int qr, int delta) {
        if (ql > r || qr < l) return;
        if (ql <= l && r <= qr) {
            tree[pos].max += delta;
            tree[pos].add += delta;
            return;
        }

        int mid = (l + r) / 2;
        if (tree[pos].add) {
            push_down(pos);
        }
        modify(pos * 2, l, mid, ql, qr, delta);
        modify(pos * 2 + 1, mid + 1, r, ql, qr, delta);
        push_up(pos);
    };






    rng (i, 0, k - 1) {
        debug(l[i], r[i]);
        modify(1, 1, n + 1, l[i], r[i], 1);
    }

    rng (i, k - 1, n) {
        modify(1, 1, n + 1, l[i], r[i], 1);
        print(tree[1].max);
        modify(1, 1, n + 1, l[i - k + 1], r[i - k + 1], -1);
    }




    cout << endl;



#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
