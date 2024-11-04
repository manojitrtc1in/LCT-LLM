

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
using pii = pair<int, int>;
#define rep(i, n) if (const int _rep_n = n; true) for (int i = 0; i < _rep_n; i++)
#define rep1(i, n) if (const int _rep_n = n; true) for (int i = 1; i <= _rep_n; i++)
#define repR(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i, n) for (int i = (int)(n); i >= 1; i--)
#define loop(i, a, B) for (int i = a; i B; i++)
#define loopR(i, a, B) for (int i = a; i B; i--)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define pb push_back
#define eb emplace_back
#define fst first
#define snd second
template <class Int> auto constexpr inf_ = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf_<int32_t>;
auto constexpr INF64 = inf_<int64_t>;
auto constexpr INF   = inf_<int>;
#ifdef LOCAL
#include "debug.hpp"
#define oj_local(x, y) (y)
#else
#define dump(...) (void)(0)
#define debug if (0)
#define oj_local(x, y) (x)
#endif
template <class T, class Comp> struct pque : priority_queue<T, vector<T>, Comp> { vector<T> &data() { return this->c; } void clear() { this->c.clear(); } };
template <class T> using pque_max = pque<T, less<T>>;
template <class T> using pque_min = pque<T, greater<T>>;
template <class T, class = typename T::iterator, enable_if_t<!is_same<T, string>::value, int> = 0>
ostream& operator<<(ostream& os, T const& a) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, size_t N, enable_if_t<!is_same<T, char>::value, int> = 0>
ostream& operator<<(ostream& os, const T (&a)[N]) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = decltype(begin(declval<T&>())), class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &a) { for (auto& x : a) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T, S> const& p) { return os << p.first << " " << p.second; }
template <class T, class S> istream& operator>>(istream& is, pair<T, S>& p) { return is >> p.first >> p.second; }
template <class... T> ostream& operator<<(ostream& os, tuple<T...> const& t)
{ bool f = true; apply([&](auto&&... x) { ((os << (f ? f = false, "" : " ") << x), ...); }, t); return os; }
template <class... T> istream& operator>>(istream& is, tuple<T...>& t) { apply([&](auto&&... x) { ((is >> x), ...); }, t); return is; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint { template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); } };
#define def(name, ...) auto name = MakeFixPoint() | [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T, d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T, d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T, 0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T, d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T, d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << '\n'; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > (T)y) { x = (T)y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < (T)y) { x = (T)y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b, e, typename iterator_traits<It>::value_type{}); }
template <class T, class = decltype(begin(declval<T&>()))> constexpr auto min(T const& a) { return *min_element(begin(a), end(a)); }
template <class T, class = decltype(begin(declval<T&>()))> constexpr auto max(T const& a) { return *max_element(begin(a), end(a)); }
template <class T> constexpr T min(set<T> const& st) { assert(st.size()); return *st.begin(); }
template <class T> constexpr T max(set<T> const& st) { assert(st.size()); return *prev(st.end()); }
template <class T> constexpr T min(multiset<T> const& st) { assert(st.size()); return *st.begin(); }
template <class T> constexpr T max(multiset<T> const& st) { assert(st.size()); return *prev(st.end()); }
constexpr ll max(signed x, ll y) { return max<ll>(x, y); }
constexpr ll max(ll x, signed y) { return max<ll>(x, y); }
constexpr ll min(signed x, ll y) { return min<ll>(x, y); }
constexpr ll min(ll x, signed y) { return min<ll>(x, y); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) { return lower_bound(begin(v), end(v), x)-begin(v); }
template <class C, class T> int ubd(C const& v, T const& x) { return upper_bound(begin(v), end(v), x)-begin(v); }
constexpr ll mod(ll x, ll m) { assert(m > 0); return (x %= m) < 0 ? x+m : x; }
constexpr ll div_floor(ll x, ll y) { assert(y != 0); return x/y - ((x^y) < 0 and x%y); }
constexpr ll div_ceil(ll x, ll y) { assert(y != 0); return x/y + ((x^y) > 0 and x%y); }
constexpr int dx[] = { 1, 0, -1, 0, 1, -1, -1, 1 };
constexpr int dy[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
auto four_nbd(int n, int m) {
    static vector<pair<int, int>> v;
    return [n, m](int i, int j) {
        const int dx[] = { 1, 0, -1, 0 }, dy[] = { 0, 1, 0, -1 };
        v.clear();
        rep (dir, 4) {
            int ni = i+dx[dir], nj = j+dy[dir];
            if (0 <= ni and ni < n and 0 <= nj and nj < m) {
                v.emplace_back(ni, nj);
            }
        }
        return v;
    };
};
template <class Comp> vector<int> iota(int n, Comp comp) {
    vector<int> idx(n);
    iota(begin(idx), end(idx), 0);
    stable_sort(begin(idx), end(idx), comp);
    return idx;
}
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }
mt19937_64 seed_{random_device{}()};
template <class Int> Int rand(Int a, Int b) { return uniform_int_distribution<Int>(a, b)(seed_); }
i64 irand(i64 a, i64 b) { return rand<i64>(a, b); } 

u64 urand(u64 a, u64 b) { return rand<u64>(a, b); } 

template <class It> void shuffle(It l, It r) { shuffle(l, r, seed_); }
template <class V> V &operator--(V &v) { for (auto &x : v) --x; return v; }
template <class V> V &operator++(V &v) { for (auto &x : v) ++x; return v; }
bool next_product(vector<int> &v, int m) {
    repR (i, v.size()) if (++v[i] < m) return true; else v[i] = 0;
    return false;
}
bool next_product(vector<int> &v, vector<int> const& s) {
    repR (i, v.size()) if (++v[i] < s[i]) return true; else v[i] = 0;
    return false;
}
template <class vec> int sort_unique(vec &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
    return v.size();
}
template <class It> auto prefix_sum(It l, It r) {
    vector<typename It::value_type> s = { 0 };
    while (l != r) s.emplace_back(s.back() + *l++);
    return s;
}
template <class It> auto suffix_sum(It l, It r) {
    vector<typename It::value_type> s = { 0 };
    while (l != r) s.emplace_back(*--r + s.back());
    reverse(s.begin(), s.end());
    return s;
}
template <class T> T pop(vector<T> &a) { auto x = a.back(); a.pop_back(); return x; }
template <class T> T pop_back(vector<T> &a) { auto x = a.back(); a.pop_back(); return x; }
template <class T, class V, class C> T pop(priority_queue<T, V, C> &a) { auto x = a.top(); a.pop(); return x; }
template <class T> T pop(queue<T> &a) { auto x = a.front(); a.pop(); return x; }
template <class T> T pop_front(deque<T> &a) { auto x = a.front(); a.pop_front(); return x; }
template <class T> T pop_back(deque<T> &a) { auto x = a.back(); a.pop_back(); return x; }
template <class T> T pop_front(set<T> &a) { auto x = *a.begin(); a.erase(a.begin()); return x; }
template <class T> T pop_back(set<T> &a) { auto it = prev(a.end()); auto x = *it; a.erase(it); return x; }
template <class T> T pop_front(multiset<T> &a) { auto it = a.begin(); auto x = *it; a.erase(it); return x; }
template <class T> T pop_back(multiset<T> &a) { auto it = prev(a.end()); auto x = *it; a.erase(it); return x; }





template <uint32_t md>
class modint {
    static_assert(md < (1u<<31), "");
    using M = modint;
    using i64 = int64_t;
    uint32_t x;
public:
    static constexpr uint32_t mod = md;
    constexpr modint(i64 x = 0) : x((x%=md) < 0 ? x+md : x) { }
    constexpr i64 val() const { return x; }
    constexpr explicit operator i64() const { return x; }
    constexpr bool operator==(M r) const { return x == r.x; }
    constexpr bool operator!=(M r) const { return x != r.x; }
    constexpr M operator+() const { return *this; }
    constexpr M operator-() const { return M()-*this; }
    constexpr M& operator+=(M r) { x += r.x; x = (x < md ? x : x-md); return *this; }
    constexpr M& operator-=(M r) { x += md-r.x; x = (x < md ? x : x-md); return *this; }
    constexpr M& operator*=(M r) { x = (uint64_t(x)*r.x)%md; return *this; }
    constexpr M& operator/=(M r) { return *this *= r.inv(); }
    constexpr M operator+(M r) const { return M(*this) += r; }
    constexpr M operator-(M r) const { return M(*this) -= r; }
    constexpr M operator*(M r) const { return M(*this) *= r; }
    constexpr M operator/(M r) const { return M(*this) /= r; }
    friend constexpr M operator+(i64 x, M y) { return M(x)+y; }
    friend constexpr M operator-(i64 x, M y) { return M(x)-y; }
    friend constexpr M operator*(i64 x, M y) { return M(x)*y; }
    friend constexpr M operator/(i64 x, M y) { return M(x)/y; }
    constexpr M inv() const { assert(x > 0); return pow(md-2); }
    constexpr M pow(i64 n) const {


        if (n < 0) return inv().pow(-n);
        M v = *this, r = 1;
        for (; n > 0; n >>= 1, v *= v) if (n&1) r *= v;
        return r;
    }
#ifdef LOCAL
    friend string to_s(M r) { return to_s(r.val(), mod); }
#endif
    friend ostream& operator<<(ostream& os, M r) { return os << r.val(); }
    friend istream& operator>>(istream& is, M &r) { i64 x; is >> x; r = x; return is; }
};





constexpr int64_t MOD = 1e9+7;
using mint = modint<MOD>;
mint sign(int n) { return n & 1 ? -1 : +1; }



template <class mint> struct ModTable {
    vector<mint> fact, finv;
    void calc(int n) {
        assert(n < int(1e9));
        int old = fact.size();
        if (n < old) return;
        n += 1000;
        fact.resize(n+1);
        finv.resize(n+1);
        if (old == 0) {
            fact[0] = fact[1] = finv[0] = finv[1] = 1;
            old = 2;
        }
        for (auto i = old; i <= n; i++) fact[i] = fact[i-1] * i;
        finv[n] = mint(1) / fact[n];
        for (auto i = n-1; i >= old; i--) finv[i] = finv[i+1] * (i+1);
    }
};
ModTable<mint> mod_tab;

mint fact(int n) {


    return mod_tab.calc(n), mod_tab.fact[n];
}
mint finv(int n) {


    return mod_tab.calc(n), mod_tab.finv[n];
}
mint comb(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    mod_tab.calc(n);
    return mod_tab.fact[n] * mod_tab.finv[k] * mod_tab.finv[n-k];
}
mint perm(int n, int k) {
    assert(k >= 0); assert(n >= k);
    mod_tab.calc(n);
    return mod_tab.fact[n] * mod_tab.finv[n-k];
}




vector<mint> p2;

mint f(int n, int m) {
    if (n < 0 or m < 0) return 0;
    mint sum = 0;
    rep (q, min(n, m)+1) {
        int p = n-q + m-q;
        sum += (p+q+1) * sign(q) * p2[p+q] * fact(p+q) * finv(n-q) * finv(m-q) * finv(q);
    }
    return sum;
}

auto solve() {
    int n, m; cin >> n >> m;
    mint ans = 0;
    for (auto [x, a, b] : (int[][3]) { { +1, 0, 0 }, { +2, 0, 1 }, { +1, 1, 1 } }) {
        for (auto [y, c, d] : (int[][3]) { { +1, 0, 0 }, { +2, 0, 1 }, { +1, 1, 1 } }) {
            ans += sign(a+b+c+d) * x*y*f(n-a-b, m-c-d);
        }
    }
    cout << ans << '\n';
}

int32_t main() {
    const int MAX = 1e7 + 10;
    p2.resize(MAX+1);
    p2[0] = 1;
    rep (i, MAX) p2[i+1] = p2[i] * 2;
    fact(MAX);

    int t; cin >> t;
    while (t--) {
        solve();


        debug { cerr << endl; }
    }
}
