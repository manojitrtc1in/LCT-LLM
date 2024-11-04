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

template <typename vec_t> void println_vec(const vec_t& vec) {
    for(const auto& ele : vec) {
        cout << ele << ' ';
    }
    cout << endl;
}

template<typename T, typename ...Args> void println(const T &t, const Args &...rest) { cout << t << ' '; println(rest...); }
template<typename T> void println(const vector<T>& vec) {
    for(const T& x: vec) {
        cout << x << ' ';
    }
    cout << endl;
}

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
#define up(i, b, a) for (int i = int(b); i <= int(a); ++i)
#define down(i, b, a) for (int i = int(b); i >= int(a); i--)
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
#define UP(i, l, r) for(i = decltype(i)(l); i <= decltype(i)(r); ++i)
#define DOWN(i, r, l) for (i = decltype(i)(r); i >= decltype(i)(l); --i)
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
    explicit bit(int n,
                 function<T(T,T)> bin_op,
                 T init):bin_op(bin_op) {
        a.resize((size_t)n + 1);
        for (int i = 1; i <= n; ++i) a[i] = init;
    }

    T prefix(T x, T init) {
        while (x) {
            init = bin_op(a[x], init);
            x -= x & -x;
        }
        return init;
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
    explicit r_bit(int n,
                   function<T(T,T)> bin_op,
                   T init):bin_op(move(bin_op)) {
        a.resize((size_t) n + 1);
        for (int i = 1; i <= n; ++i) a[i] = init;
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

const int mod = 1e9+7; 


inline void mul(int &x, const int y) {
    x = int(ll(x) * y % mod);
}
inline int Mul(int x, const int y) {
    return (int)(ll(x) * y % mod);
}
template <typename  T, typename U>
inline void add(T &x, const U y) {
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
    size_t n{}; 

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


string to_string(const string& s) {
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





 struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };


class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<pair<int,int>> tmp;
        queue<pair<TreeNode*,int>> que;
        vector<vector<int>> ans;

        que.push({pRoot, 0});

        auto work = [&]() {
            ans.emplace_back();
            int level = tmp.back().second;
            if (level & 1) {
                for (int i = (int)tmp.size() - 1; i >= 0; --i) {
                    ans.back().push_back(tmp[i].first);
                }
            }
            else {
                for (auto x : tmp) {
                    ans.back().push_back(x.first);
                }
            }
            tmp.clear();
        };

        while (!que.empty()) {
            auto top = que.front();
            que.pop();

            auto ptr = top.first;
            int level = top.second;

            if (!tmp.empty() && level == tmp.back().second + 1) {
                work();
            }
            tmp.emplace_back(ptr->val, level);
            if (ptr -> left != NULL) que.push({ptr -> left, level + 1});
            if (ptr -> right != NULL) que.push({ptr -> right, level + 1});
        }
        work();

        return ans;
    }

}sol;

int main() {
    FAST_READ
    cout << fixed << setprecision(1);
#ifdef LOCAL
    ifstream in("main.in");
    cin.rdbuf(in.rdbuf());
#endif
    int n, m; scan(n, m);
    vi p(n), c(n); read(p); read(c);
    int d; scan(d);

    vi a(d); read(a);
    vb left(n);
    For(x, a) {
        --x;
        left[x] = true;
    }

    function<bool(int)> dfs;
    const int maxp = 5001;
    vv<int> g(maxp);

    rng (i, 0, n) {
        if (!left[i]) {
            g[p[i]].pb(c[i]);
        }
    }

    vb vis(maxp);
    vi match(m + 1, -1);

    dfs = [&](int u) {
        if (vis[u]) return false;
        vis[u] = true;
        FOR(v, g[u]) {
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return true;
            }
        }
        return false;
    };

    int cur = 0;
    vi ans(d);

    down (i, d - 1, 0) {
        while (cur < maxp) {
                fill(all(vis), false);
                if (dfs(cur)) {
                    ++cur;
                }
                else {
                    break;
                }
        }
        ans[i] = cur;
        g[p[a[i]]].pb(c[a[i]]);
    }

    FOR(x, ans) {
        println(x);
    }







#ifdef LOCAL
    cout << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}
