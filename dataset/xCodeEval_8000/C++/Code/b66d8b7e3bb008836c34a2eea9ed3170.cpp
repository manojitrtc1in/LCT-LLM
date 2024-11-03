#pragma region Macros


#pragma GCC optimize("O3")
#pragma comment(linker, "/stack:200000000")
#ifdef ONLINE_JUDGE
#pragma GCC optimize("unroll-loops")






#endif
#pragma GCC optimize("Ofast")
#ifdef noimi
#define oj_local(a, b) b
#else
#define oj_local(a, b) a
#endif

#define LOCAL if(oj_local(0, 1))
#define OJ if(oj_local(1, 0))

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cfenv>
#include <cfloat>
#include <chrono>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdarg>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <fstream>
#include <functional>
#include <immintrin.h>
#include <initializer_list>
#include <iomanip>
#include <ios>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <streambuf>
#include <string>
#include <tuple>
#include <type_traits>
#include <typeinfo>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using ull = unsigned long long int;
using i128 = __int128_t;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ld = long double;
template <typename T> using vc = vector<T>;
template <typename T> using vvc = vector<vc<T>>;
template <typename T> using vvvc = vector<vvc<T>>;
using vi = vc<int>;
using vl = vc<ll>;
using vpi = vc<pii>;
using vpl = vc<pll>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
template <typename T> int si(const T &x) { return x.size(); }
template <class T, class S> inline bool chmax(T &a, const S &b) { return (a < b ? a = b, 1 : 0); }
template <class T, class S> inline bool chmin(T &a, const S &b) { return (a > b ? a = b, 1 : 0); }
vi iota(int n) {
    vi a(n);
    return iota(a.begin(), a.end(), 0), a;
}
template <typename T> vi iota(const vector<T> &a, bool greater = false) {
    vi res(a.size());
    iota(res.begin(), res.end(), 0);
    sort(res.begin(), res.end(), [&](int i, int j) {
        if(greater) return a[i] > a[j];
        return a[i] < a[j];
    });
    return res;
}



#define overload5(a, b, c, d, e, name, ...) name
#define overload4(a, b, c, d, name, ...) name
#define endl '\n'
#define rep0(n) for(int jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define rep1(i, n) for(ll i = 0; i < (n); ++i)
#define rep2(i, a, b) for(ll i = (a); i < (b); ++i)
#define rep3(i, a, b, c) for(ll i = (a); i < (b); i += (c))
#define rep(...) overload4(__VA_ARGS__, rep3, rep2, rep1, rep0)(__VA_ARGS__)
#define per0(n) for(int jidlsjf = 0; jidlsjf < n; ++jidlsjf)
#define per1(i, n) for(ll i = (n)-1; i >= 0; --i)
#define per2(i, a, b) for(ll i = (a)-1; i >= b; --i)
#define per3(i, a, b, c) for(ll i = (a)-1; i >= b; i -= c)
#define per(...) overload4(__VA_ARGS__, per3, per2, per1, per0)(__VA_ARGS__)
#define fore0(a) rep(a.size())
#define fore1(i, a) for(auto &&i : a)
#define fore2(a, b, v) for(auto &&[a, b] : v)
#define fore3(a, b, c, v) for(auto &&[a, b, c] : v)
#define fore4(a, b, c, d, v) for(auto &&[a, b, c, d] : v)
#define fore(...) overload5(__VA_ARGS__, fore4, fore3, fore2, fore1, fore0)(__VA_ARGS__)
#define fi first
#define se second
#define pb push_back
#define ppb pop_back
#define ppf pop_front
#define eb emplace_back
#define drop(s) cout << #s << endl, exit(0)
#define si(c) (int)(c).size()
#define lb(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define ub(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define all(c) begin(c), end(c)
#define rall(c) rbegin(c), rend(c)
#define SORT(v) sort(all(v))
#define REV(v) reverse(all(v))
#define UNIQUE(x) SORT(x), x.erase(unique(all(x)), x.end())
template <typename T = ll, typename S> T SUM(const S &v) { return accumulate(all(v), T(0)); }
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define overload2(_1, _2, name, ...) name
#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...) vector<vector<vector<type>>> name(h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)                                                                                                                         \
    vector<vector<vector<vector<type>>>> name(a, vector<vector<vector<type>>>(b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))
constexpr pii dx4[4] = {pii{1, 0}, pii{0, 1}, pii{-1, 0}, pii{0, -1}};
constexpr pii dx8[8] = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};

namespace yesno_impl {
const string YESNO[2] = {"NO", "YES"};
const string YesNo[2] = {"No", "Yes"};
const string yesno[2] = {"no", "yes"};
const string firstsecond[2] = {"second", "first"};
const string FirstSecond[2] = {"Second", "First"};
const string possiblestr[2] = {"impossible", "possible"};
void YES(bool t = 1) { cout << YESNO[t] << endl; }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { cout << YesNo[t] << endl; }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { cout << yesno[t] << endl; }
void no(bool t = 1) { yes(!t); }
void first(bool t = 1) { cout << firstsecond[t] << endl; }
void First(bool t = 1) { cout << FirstSecond[t] << endl; }
void possible(bool t = 1) { cout << possiblestr[t] << endl; }
}; 

using namespace yesno_impl;

#define INT(...)                                                                                                                                               \
    int __VA_ARGS__;                                                                                                                                           \
    IN(__VA_ARGS__)
#define LL(...)                                                                                                                                                \
    ll __VA_ARGS__;                                                                                                                                            \
    IN(__VA_ARGS__)
#define STR(...)                                                                                                                                               \
    string __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define CHR(...)                                                                                                                                               \
    char __VA_ARGS__;                                                                                                                                          \
    IN(__VA_ARGS__)
#define DBL(...)                                                                                                                                               \
    double __VA_ARGS__;                                                                                                                                        \
    IN(__VA_ARGS__)
#define VEC(type, name, size)                                                                                                                                  \
    vector<type> name(size);                                                                                                                                   \
    IN(name)
#define VEC2(type, name1, name2, size)                                                                                                                         \
    vector<type> name1(size), name2(size);                                                                                                                     \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i])
#define VEC3(type, name1, name2, name3, size)                                                                                                                  \
    vector<type> name1(size), name2(size), name3(size);                                                                                                        \
    for(int i = 0; i < size; i++) IN(name1[i], name2[i], name3[i])
#define VV(type, name, h, w)                                                                                                                                   \
    vector<vector<type>> name(h, vector<type>(w));                                                                                                             \
    IN(name)
int scan() { return getchar(); }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(string &a) { cin >> a; }
template <class T, class S> void scan(pair<T, S> &p) { scan(p.first), scan(p.second); }
template <class T> void scan(vector<T> &);
template <class T> void scan(vector<T> &a) {
    for(auto &i : a) scan(i);
}
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &...tail) {
    scan(head);
    IN(tail...);
}

template <typename T, typename S> T ceil(T x, S y) {
    assert(y);
    return (y < 0 ? ceil(-x, -y) : (x > 0 ? (x + y - 1) / y : x / y));
}

template <typename T, typename S> T floor(T x, S y) {
    assert(y);
    return (y < 0 ? floor(-x, -y) : (x > 0 ? x / y : x / y - (x % y == 0 ? 0 : 1)));
}
template <class T> T POW(T x, int n) {
    T res = 1;
    for(; n; n >>= 1, x *= x)
        if(n & 1) res *= x;
    return res;
}
template <class T, class S> T POW(T x, S n, const ll &mod) {
    T res = 1;
    x %= mod;
    for(; n; n >>= 1, x = x * x % mod)
        if(n & 1) res = res * x % mod;
    return res;
}
vector<pll> factor(ll x) {
    vector<pll> ans;
    for(ll i = 2; i * i <= x; i++)
        if(x % i == 0) {
            ans.push_back({i, 1});
            while((x /= i) % i == 0) ans.back().second++;
        }
    if(x != 1) ans.push_back({x, 1});
    return ans;
}
template <class T> vector<T> divisor(T x) {
    vector<T> ans;
    for(T i = 1; i * i <= x; i++)
        if(x % i == 0) {
            ans.pb(i);
            if(i * i != x) ans.pb(x / i);
        }
    return ans;
}
template <typename T> void zip(vector<T> &x) {
    vector<T> y = x;
    UNIQUE(y);
    for(int i = 0; i < x.size(); ++i) { x[i] = lb(y, x[i]); }
}
template <class S> void fold_in(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void fold_in(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto e : a) v.emplace_back(e);
    fold_in(v, tail...);
}
template <class S> void renumber(vector<S> &v) {}
template <typename Head, typename... Tail, class S> void renumber(vector<S> &v, Head &&a, Tail &&...tail) {
    for(auto &&e : a) e = lb(v, e);
    renumber(v, tail...);
}
template <class S, class... Args> vector<S> zip(vector<S> &head, Args &&...args) {
    vector<S> v;
    fold_in(v, head, args...);
    sort(all(v)), v.erase(unique(all(v)), v.end());
    renumber(v, head, args...);
    return v;
}
template <typename T> vector<T> RUI(const vector<T> &v) {
    vector<T> res(v.size() + 1);
    for(int i = 0; i < v.size(); i++) res[i + 1] = res[i] + v[i];
    return res;
}



template <class T, class S> bool inc(const T &x, const S &l, const S &r) { return l <= x and x < r; }

constexpr ll ten(int n) { return n == 0 ? 1 : ten(n - 1) * 10; }


ll pow2(int i) { return 1LL << i; }
int topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t); }
int topbit(ll t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }
int lowbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }
int lowbit(ll a) { return a == 0 ? 64 : __builtin_ctzll(a); }


constexpr ll mask(int n) { return (1LL << n) - 1; }




int popcount(uint64_t t) { return __builtin_popcountll(t); }
bool ispow2(int i) { return i && (i & -i) == i; }

ll rnd(ll l, ll r) { 

#ifdef noimi
    static mt19937_64 gen;
#else
    static mt19937_64 gen(chrono::steady_clock::now().time_since_epoch().count());
#endif
    return uniform_int_distribution<ll>(l, r - 1)(gen);
}
ll rnd(ll n) { return rnd(0, n); }

template <class t> void random_shuffle(vc<t> &a) { rep(i, si(a)) swap(a[i], a[rnd(0, i + 1)]); }

int in() {
    int x;
    cin >> x;
    return x;
}
ll lin() {
    unsigned long long x;
    cin >> x;
    return x;
}

template <class T, class S> pair<T, S> operator-(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi - y.fi, x.se - y.se); }
template <class T, class S> pair<T, S> operator+(const pair<T, S> &x, const pair<T, S> &y) { return pair<T, S>(x.fi + y.fi, x.se + y.se); }
template <class T> pair<T, T> operator&(const pair<T, T> &l, const pair<T, T> &r) { return pair<T, T>(max(l.fi, r.fi), min(l.se, r.se)); }
template <class T, class S> pair<T, S> operator+=(pair<T, S> &l, const pair<T, S> &r) { return l = l + r; }
template <class T, class S> pair<T, S> operator-=(pair<T, S> &l, const pair<T, S> &r) { return l = l - r; }
template <class T> bool intersect(const pair<T, T> &l, const pair<T, T> &r) { return (l.se < r.se ? r.fi < l.se : l.fi < r.se); }

template <typename T> struct edge {
    int from, to;
    T cost;
    int id;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
    edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id) {}
    constexpr bool operator<(const edge<T> &rhs) const noexcept { return cost < rhs.cost; }
    edge &operator=(const int &x) {
        to = x;
        return *this;
    }
    operator int() const { return to; }
    friend ostream operator<<(ostream &os, edge &e) { return os << e.to; }
};
template <typename T> using Edges = vector<edge<T>>;

using Tree = vector<vector<int>>;
using Graph = vector<vector<int>>;
template <class T> using Wgraph = vector<vector<edge<T>>>;
Graph getG(int n, int m = -1, bool directed = false, int margin = 1) {
    Tree res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        cin >> a >> b;
        a -= margin, b -= margin;
        res[a].emplace_back(b);
        if(!directed) res[b].emplace_back(a);
    }
    return res;
}
Graph getTreeFromPar(int n, int margin = 1) {
    Graph res(n);
    for(int i = 1; i < n; i++) {
        int a;
        cin >> a;
        res[a - margin].emplace_back(i);
    }
    return res;
}
template <class T> Wgraph<T> getWg(int n, int m = -1, bool directed = false, int margin = 1) {
    Wgraph<T> res(n);
    if(m == -1) m = n - 1;
    while(m--) {
        int a, b;
        T c;
        cin >> a >> b >> c;
        a -= margin, b -= margin;
        res[a].emplace_back(b, c);
        if(!directed) res[b].emplace_back(a, c);
    }
    return res;
}
void add(Graph &G, int x, int y) { G[x].eb(y), G[y].eb(x); }
template <class S, class T> void add(Wgraph<S> &G, int x, int y, T c) { G[x].eb(y, c), G[y].eb(x, c); }

#define TEST                                                                                                                                                   \
    INT(testcases);                                                                                                                                            \
    while(testcases--)

namespace aux {
template <typename T, unsigned N, unsigned L> struct tp {
    static void output(std::ostream &os, const T &v) {
        os << std::get<N>(v) << (&os == &cerr ? ", " : " ");
        tp<T, N + 1, L>::output(os, v);
    }
};
template <typename T, unsigned N> struct tp<T, N, N> {
    static void output(std::ostream &os, const T &v) { os << std::get<N>(v); }
};
} 

template <typename... Ts> std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
    if(&os == &cerr) { os << '('; }
    aux::tp<std::tuple<Ts...>, 0, sizeof...(Ts) - 1>::output(os, t);
    if(&os == &cerr) { os << ')'; }
    return os;
}
template <class T, class S> ostream &operator<<(ostream &os, const pair<T, S> &p) {
    if(&os == &cerr) { return os << "(" << p.first << ", " << p.second << ")"; }
    return os << p.first << " " << p.second;
}
template <class Ch, class Tr, class Container> std::basic_ostream<Ch, Tr> &operator<<(std::basic_ostream<Ch, Tr> &os, const Container &x) {
    bool f = true;
    if(&os == &cerr) os << "[";
    for(auto &y : x) {
        if(&os == &cerr)
            os << (f ? "" : ", ") << y;
        else
            os << (f ? "" : " ") << y;
        f = false;
    }
    if(&os == &cerr) os << "]";
    return os;
}

#ifdef noimi
#undef endl
void debug() { cerr << endl; }
void debug(bool) { cerr << endl; }
template <class Head, class... Tail> void debug(bool is_front, Head head, Tail... tail) {
    if(!is_front) cerr << ", ";
    cerr << head;
    debug(false, tail...);
}

#define dump(args...)                                                                                                                                          \
    {                                                                                                                                                          \
        vector<string> _debug = _split(#args, ',');                                                                                                            \
        err(true, begin(_debug), args);                                                                                                                        \
    }

vector<string> _split(const string &s, char c) {
    vector<string> v;
    stringstream ss(s);
    string x;
    while(getline(ss, x, c)) {
        if(empty(v))
            v.eb(x);
        else {
            bool flag = false;
            for(auto [c, d] : {pair('(', ')'), pair('[', ']'), pair('{', '}'), pair('<', '>')}) {
                if(count(all(v.back()), c) != count(all(v.back()), d)) flag = true;
            }
            if(flag)
                v.back() += "," + x;
            else
                v.eb(x);
        }
    }
    return move(v);
}

void err(bool, vector<string>::iterator) { cerr << endl; }
template <typename T, typename... Args> void err(bool is_front, vector<string>::iterator it, T a, Args... args) {
    if(!is_front) cerr << ", ";
    cerr << it->substr((*it)[0] == ' ', (*it).size()) << " = " << a, err(false, ++it, args...);
}



#else
#define dump(...) static_cast<void>(0)
#define dbg(...) static_cast<void>(0)
#endif
void OUT() { cout << endl; }
template <class Head, class... Tail> void OUT(const Head &head, const Tail &...tail) {
    cout << head;
    if(sizeof...(tail)) cout << ' ';
    OUT(tail...);
}

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;

template <class F> struct REC {
    F f;
    REC(F &&f_) : f(std::forward<F>(f_)) {}
    template <class... Args> auto operator()(Args &&...args) const { return f(*this, std::forward<Args>(args)...); }
};

template <class S> vector<pair<S, int>> runLength(const vector<S> &v) {
    vector<pair<S, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}
vector<pair<char, int>> runLength(const string &v) {
    vector<pair<char, int>> res;
    for(auto &e : v) {
        if(res.empty() or res.back().fi != e)
            res.eb(e, 1);
        else
            res.back().se++;
    }
    return res;
}

template <class T, class F> T bin_search(T ok, T ng, const F &f) {
    while(abs(ok - ng) > 1) {
        T mid = ok + ng >> 1;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class T, class F> T bin_search_double(T ok, T ng, const F &f, int iter = 80) {
    while(iter--) {
        T mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}

struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(11);
    }
} setup_io;

#pragma endregion

namespace segtree_impl {

namespace internal {





int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1 << x))) x++;
    return x;
}





int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} 


} 


namespace segtree_impl {

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S operator[](int k) const { return get(k); }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if(l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!f(op(sm, d[l]))) {
                while(l < size) {
                    l = (2 * l);
                    if(f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if(r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!f(op(d[r], sm))) {
                while(r < size) {
                    r = (2 * r + 1);
                    if(f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    friend std::ostream &operator<<(std::ostream &os, segtree &ls) {
        os << "{";
        for(int i = 0; i < ls._n; i++) os << ls.get(i) << (i == ls._n - 1 ? "" : ", ");
        return os << "}";
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template <typename T> T min_func(T x, T y) { return min(x, y); }
template <typename T> T max_func(T x, T y) { return max(x, y); }
template <typename T> T plus_func(T x, T y) { return x + y; }
template <typename T, int ID> T set_func(T x, T y) { return (y == ID ? x : y); }
template <typename T> T min_e() { return inf<T>; }
template <typename T> T max_e() { return -inf<T>; }
template <typename T> T plus_e() { return 0; }

template <typename T> using RST = segtree<T, plus_func<T>, plus_e<T>>;
template <typename T> using RmT = segtree<T, min_func<T>, min_e<T>>;
template <typename T> using RMT = segtree<T, max_func<T>, max_e<T>>;

} 

using segtree_impl::RmT;
using segtree_impl::RMT;
using segtree_impl::RST;
using segtree_impl::segtree;

struct BIT01 {
    int n;
    using u64 = uint64_t;
    static constexpr int B = 64;
    vector<int> a;
    vector<u64> v;
    BIT01(int sz) : a((sz + B - 1) / B + 1), v((sz + B - 1) / B + 1), n(sz) {}
    int sum(int k) {
        if(k < 0) return 0;
        if(k >= n) k = n - 1;
        int r = (k + 1) / B;
        int res = __builtin_popcountll(v[r] & ((1ULL << (k + 1 - r * B)) - 1));
        for(r; r > 0; r -= r & -r) res += a[r];
        return res;
    }
    

    void set(int x, int y) {
        int r = x / B;
        if(y ^ ((v[r] >> (x % B)) & 1)) {
            v[r] ^= 1ULL << (x % B);
            for(++r; r < a.size(); r += r & -r) a[r] += (y ? 1 : -1);
        }
    }
    int query(int l, int r) {
        if(l >= r) return 0;
        return sum(r - 1) - sum(l - 1);
    }
};



namespace lazysegtree_impl {

namespace internal {





int ceil_pow2(int n) {
    int x = 0;
    while((1U << x) < (unsigned int)(n)) x++;
    return x;
}





constexpr int bsf_constexpr(unsigned int n) {
    int x = 0;
    while(!(n & (1 << x))) x++;
    return x;
}





int bsf(unsigned int n) {
#ifdef _MSC_VER
    unsigned long index;
    _BitScanForward(&index, n);
    return index;
#else
    return __builtin_ctz(n);
#endif
}

} 


} 


namespace lazysegtree_impl {
template <class S, S (*op)(S, S), S (*e)(), class F, S (*mapping)(F, S), F (*composition)(F, F), F (*id)()> struct lazy_segtree {
  public:
    lazy_segtree() : lazy_segtree(0) {}
    explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
    explicit lazy_segtree(const std::vector<S> &v) : _n(int(v.size())) {
        log = internal::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for(int i = 0; i < _n; i++) d[size + i] = v[i];
        for(int i = size - 1; i >= 1; i--) { update(i); }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for(int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return e();

        l += size;
        r += size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while(l < r) {
            if(l & 1) sml = op(sml, d[l++]);
            if(r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for(int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for(int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if(l == r) return;

        l += size;
        r += size;

        for(int i = log; i >= 1; i--) {
            if(((l >> i) << i) != l) push(l >> i);
            if(((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while(l < r) {
                if(l & 1) all_apply(l++, f);
                if(r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for(int i = 1; i <= log; i++) {
            if(((l >> i) << i) != l) update(l >> i);
            if(((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if(l == _n) return _n;
        l += size;
        for(int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while(l % 2 == 0) l >>= 1;
            if(!g(op(sm, d[l]))) {
                while(l < size) {
                    push(l);
                    l = (2 * l);
                    if(g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if(r == 0) return 0;
        r += size;
        for(int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while(r > 1 && (r % 2)) r >>= 1;
            if(!g(op(d[r], sm))) {
                while(r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if(g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while((r & -r) != r);
        return 0;
    }

    S operator[](int k) { return get(k); }

    friend std::ostream &operator<<(std::ostream &os, lazy_segtree &ls) {
        os << "{";
        for(int i = 0; i < ls._n; i++) os << ls.get(i) << (i == ls._n - 1 ? "" : ", ");
        return os << "}";
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if(k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;
template <typename T> T min_func(T x, T y) { return min(x, y); }
template <typename T> T max_func(T x, T y) { return max(x, y); }
template <typename T> T plus_func(T x, T y) { return x + y; }
template <typename T, int ID> T set_func(T x, T y) { return (y == ID ? x : y); }
template <typename T> T min_e() { return inf<T>; }
template <typename T> T max_e() { return -inf<T>; }
template <typename T> T plus_e() { return 0; }



template <typename T> using RARm = lazy_segtree<T, min_func<T>, min_e<T>, T, plus_func<T>, plus_func<T>, plus_e<T>>;


template <typename T> using RARM = lazy_segtree<T, max_func<T>, max_e<T>, T, plus_func<T>, plus_func<T>, plus_e<T>>;




template <typename T> pair<int, T> RARS_op(pair<int, T> x, pair<int, T> y) { return T{x.first + y.first, x.second + y.second}; }
template <typename T> pair<int, T> RARS_e() { return T{0, 0}; }
template <typename T> pair<int, T> RARS_map(T f, pair<int, T> x) { return T{x.second + f * x.first, x.first}; }
template <typename T> using RARS = lazy_segtree<pair<int, T>, RARS_op<T>, RARS_e<T>, T, RARS_map<T>, plus_func<T>, plus_e<T>>;

} 


using lazysegtree_impl::lazy_segtree;
using lazysegtree_impl::RARM;
using lazysegtree_impl::RARm;
using lazysegtree_impl::RARS;

struct T {
    int mi, sum;
};

T Tf(T x, T y) {
    if(x.mi == y.mi)
        return T{x.mi, x.sum + y.sum};
    else if(x.mi > y.mi)
        swap(x, y);
    return x;
}

T Te() { return T{inf<int>, 0}; }

T Tg(int f, T x) { return T{x.mi + f, x.sum}; }

int Th(int x, int y) { return x + y; }
int eint() { return 0; }

pll min_inf() { return pll(inf<ll>, inf<ll>); }
pll max_inf() { return pll(-inf<ll>, -inf<ll>); }

#pragma once

#include <cstring>
#include <type_traits>
#include <utility>

using namespace std;

namespace fastio {
static constexpr int SZ = 1 << 17;
char inbuf[SZ], outbuf[SZ];
int in_left = 0, in_right = 0, out_right = 0;

struct Pre {
    char num[40000];
    constexpr Pre() : num() {
        for(int i = 0; i < 10000; i++) {
            int n = i;
            for(int j = 3; j >= 0; j--) {
                num[i * 4 + j] = n % 10 + '0';
                n /= 10;
            }
        }
    }
} constexpr pre;

inline void load() {
    int len = in_right - in_left;
    memmove(inbuf, inbuf + in_left, len);
    in_right = len + fread(inbuf + len, 1, SZ - len, stdin);
    in_left = 0;
}

inline void flush() {
    fwrite(outbuf, 1, out_right, stdout);
    out_right = 0;
}

inline void skip_space() {
    if(in_left + 32 > in_right) load();
    while(inbuf[in_left] <= ' ') in_left++;
}

inline void rd(char &c) {
    if(in_left + 32 > in_right) load();
    c = inbuf[in_left++];
}
template <typename T> inline void rd(T &x) {
    if(in_left + 32 > in_right) load();
    char c;
    do c = inbuf[in_left++];
    while(c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr(is_signed<T>::value == true) {
        if(c == '-') minus = true, c = inbuf[in_left++];
    }
    x = 0;
    while(c >= '0') {
        x = x * 10 + (c & 15);
        c = inbuf[in_left++];
    }
    if constexpr(is_signed<T>::value == true) {
        if(minus) x = -x;
    }
}
inline void rd() {}
template <typename Head, typename... Tail> inline void rd(Head &head, Tail &...tail) {
    rd(head);
    rd(tail...);
}

inline void wt(char c) {
    if(out_right > SZ - 32) flush();
    outbuf[out_right++] = c;
}
inline void wt(bool b) {
    if(out_right > SZ - 32) flush();
    outbuf[out_right++] = b ? '1' : '0';
}
template <typename T> inline void wt(T x) {
    if(out_right > SZ - 32) flush();
    if(!x) {
        outbuf[out_right++] = '0';
        return;
    }
    if constexpr(is_signed<T>::value == true) {
        if(x < 0) outbuf[out_right++] = '-', x = -x;
    }
    int i = 12;
    char buf[16];
    while(x >= 10000) {
        memcpy(buf + i, pre.num + (x % 10000) * 4, 4);
        x /= 10000;
        i -= 4;
    }
    if(x < 100) {
        if(x < 10) {
            outbuf[out_right] = '0' + x;
            ++out_right;
        } else {
            uint32_t q = (uint32_t(x) * 205) >> 11;
            uint32_t r = uint32_t(x) - q * 10;
            outbuf[out_right] = '0' + q;
            outbuf[out_right + 1] = '0' + r;
            out_right += 2;
        }
    } else {
        if(x < 1000) {
            memcpy(outbuf + out_right, pre.num + (x << 2) + 1, 3);
            out_right += 3;
        } else {
            memcpy(outbuf + out_right, pre.num + (x << 2), 4);
            out_right += 4;
        }
    }
    memcpy(outbuf + out_right, buf + i + 4, 12 - i);
    out_right += 12 - i;
}
inline void wt() {}
template <typename Head, typename... Tail> inline void wt(Head &&head, Tail &&...tail) {
    wt(head);
    wt(forward<Tail>(tail)...);
}
template <typename... Args> inline void wtn(Args &&...x) {
    wt(forward<Args>(x)...);
    wt('\n');
}

struct Dummy {
    Dummy() { atexit(flush); }
} dummy;

} 

using fastio::rd;
using fastio::skip_space;
using fastio::wt;
using fastio::wtn;

ll a[1 << 20];
pll aa[1 << 20];
int main() {
    int n;
    rd(n);
    rep(i, n) rd(a[i]);
    ll ans = 0;
    vi p(n);
    rep(i, n) p[i] = popcount(a[i]);
    rep(i, n) aa[i] = pair(a[i], i);

    vpi ma(n), mi(n);
    {
        vi tmp;
        rep(i, n) {
            while(!empty(tmp) and aa[tmp.back()] < aa[i]) tmp.pop_back();
            if(empty(tmp))
                ma[i].fi = 0;
            else
                ma[i].fi = tmp.back() + 1;
            tmp.eb(i);
        }
        tmp.clear();
        per(i, n, 0) {
            while(!empty(tmp) and aa[tmp.back()] < aa[i]) tmp.ppb();
            if(empty(tmp))
                ma[i].se = n;
            else
                ma[i].se = tmp.back();
            tmp.eb(i);
        }
    }
    {
        vi tmp;
        rep(i, n) {
            while(!empty(tmp) and aa[tmp.back()] > aa[i]) tmp.pop_back();
            if(empty(tmp))
                mi[i].fi = 0;
            else
                mi[i].fi = tmp.back() + 1;
            tmp.eb(i);
        }
        tmp.clear();
        per(i, n, 0) {
            while(!empty(tmp) and aa[tmp.back()] > aa[i]) tmp.ppb();
            if(empty(tmp))
                mi[i].se = n;
            else
                mi[i].se = tmp.back();
            tmp.eb(i);
        }
    }

    

    


    constexpr int B = 61;
    vv(int, idx, B);
    rep(i, n) { idx[p[i]].eb(i); }

    

    

    

    

    

    

    

    

    

    

    


    vvc<pii> add(n + 1), del(n + 1);

    vector<T> setter(n, T{0, 1});
    lazy_segtree<T, Tf, Te, int, Tg, Th, eint> seg(setter);

    rep(i, B) {
        int m = si(idx[i]);
        if(!m) continue;
        vi wa;
        fore(e, idx[i]) {
            add[mi[e].fi].eb(e, mi[e].se);
            del[e + 1].eb(e, mi[e].se);
            add[ma[e].fi].eb(e, ma[e].se);
            del[e + 1].eb(e, ma[e].se);
            ans += 1LL * (e + 1 - mi[e].fi) * (mi[e].se - e);
            ans += 1LL * (e + 1 - ma[e].fi) * (ma[e].se - e);
            

        }
        int pre = 0;
        rep(x, n + 1) {
            if(empty(add[x]) and empty(del[x])) {
                ans -= pre;
                continue;
            }
            for(auto &&[l, r] : add[x]) seg.apply(l, r, 1);
            for(auto &&[l, r] : del[x]) seg.apply(l, r, -1);
            auto t = seg.all_prod();
            pre = n - (t.mi == 0 ? t.sum : 0);
            ans -= pre;
            add[x].clear(), del[x].clear();
        }
    }

    OUT(ans);
}