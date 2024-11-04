

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define int ll
#define double ld
#define rep(i,n) for (int i = 0; i < (int)(n); i++)
#define rep1(i,n) for (int i = 1; i <= (int)(n); i++)
#define repR(i,n) for (int i = (int)(n)-1; i >= 0; i--)
#define rep1R(i,n) for (int i = (int)(n); i >= 1; i--)
#define loop(i,a,B) for (int i = a; i B; i++)
#define loopR(i,a,B) for (int i = a; i B; i--)
#define all(x) begin(x), end(x)
#define allR(x) rbegin(x), rend(x)
#define rng(x,l,r) begin(x) + (l), begin(x) + (r)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fst first
#define snd second
template <class Int> auto constexpr inf = numeric_limits<Int>::max()/2-1;
auto constexpr INF32 = inf<int32_t>;
auto constexpr INF64 = inf<int64_t>;
auto constexpr INF   = inf<int>;
#ifdef LOCAL
#include "debug.hpp"
#else
#define dump(...) (void)(0)
#define say(x) (void)(0)
#define debug if (0)
#endif
template <class T, class Comp> struct pque : priority_queue<T, vector<T>, Comp> {
    vector<T> &data() { return this->c; }
    void clear() { this->c.clear(); }
};
template <class T> using pque_max = pque<T, less<T>>;
template <class T> using pque_min = pque<T, greater<T>>;
template <class T, class = typename T::iterator, enable_if_t<!is_same<T, string>::value, int> = 0>
ostream& operator<<(ostream& os, T const& a) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, size_t N, enable_if_t<!is_same<T, char>::value, int> = 0>
ostream& operator<<(ostream& os, const T (&a)[N]) { bool f = true; for (auto const& x : a) os << (f ? "" : " ") << x, f = false; return os; }
template <class T, class = decltype(begin(declval<T&>())), class = typename enable_if<!is_same<T, string>::value>::type>
istream& operator>>(istream& is, T &a) { for (auto& x : a) is >> x; return is; }
template <class T, class S> ostream& operator<<(ostream& os, pair<T,S> const& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <class T, class S> istream& operator>>(istream& is, pair<T,S>& p) { return is >> p.first >> p.second; }
struct IOSetup { IOSetup() { cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(15); } } iosetup;
template <class F> struct FixPoint : private F {
    constexpr FixPoint(F&& f) : F(forward<F>(f)) {}
    template <class... T> constexpr auto operator()(T&&... x) const { return F::operator()(*this, forward<T>(x)...); }
};
struct MakeFixPoint { template <class F> constexpr auto operator|(F&& f) const { return FixPoint<F>(forward<F>(f)); } };
#define MFP MakeFixPoint()|
#define def(name, ...) auto name = MFP [&](auto &&name, __VA_ARGS__)
template <class T, size_t d> struct vec_impl {
    using type = vector<typename vec_impl<T,d-1>::type>;
    template <class... U> static type make_v(size_t n, U&&... x) { return type(n, vec_impl<T,d-1>::make_v(forward<U>(x)...)); }
};
template <class T> struct vec_impl<T,0> { using type = T; static type make_v(T const& x = {}) { return x; } };
template <class T, size_t d = 1> using vec = typename vec_impl<T,d>::type;
template <class T, size_t d = 1, class... Args> auto make_v(Args&&... args) { return vec_impl<T,d>::make_v(forward<Args>(args)...); }
template <class T> void quit(T const& x) { cout << x << endl; exit(0); }
template <class T, class U> constexpr bool chmin(T& x, U const& y) { if (x > y) { x = y; return true; } return false; }
template <class T, class U> constexpr bool chmax(T& x, U const& y) { if (x < y) { x = y; return true; } return false; }
template <class It> constexpr auto sumof(It b, It e) { return accumulate(b, e, typename iterator_traits<It>::value_type{}); }
template <class T> int sz(T const& x) { return x.size(); }
template <class C, class T> int lbd(C const& v, T const& x) { return lower_bound(begin(v), end(v), x)-begin(v); }
template <class C, class T> int ubd(C const& v, T const& x) { return upper_bound(begin(v), end(v), x)-begin(v); }
const int dx[] = { 1,0,-1,0 };
const int dy[] = { 0,1,0,-1 };
constexpr int popcnt(ll x) { return __builtin_popcountll(x); }


template <class Int> Int rand(Int a, Int b) { static mt19937_64 mt{random_device{}()}; return uniform_int_distribution<Int>(a,b)(mt); }
i64 irand(i64 a, i64 b) { return rand<i64>(a,b); }
u64 urand(u64 a, u64 b) { return rand<u64>(a,b); }




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
        assert(not (x == 0 && n == 0));
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
mint sgn(int n) { return n%2 == 0 ? +1 : -1; }


template <uint32_t mod>
struct ModTable {
    vector<uint32_t> fact = {1,1}, finv = {1,1}, inv = {0,1};
    void calc(int n) {
        int old = fact.size();
        if (n < old) return;
        fact.resize(n+1);
        finv.resize(n+1);
        inv.resize(n+1);
        for (uint32_t i = old; i <= n; i++) {
            fact[i] = uint64_t(fact[i-1])*i % mod;
            inv[i] = mod - uint64_t(inv[mod%i])*(mod/i) % mod;
            finv[i] = uint64_t(finv[i-1])*inv[i] % mod;
        }
    }
};
ModTable<MOD> mod_tab;

modint<MOD> fact(int n) {
    assert(0 <= n);
    return mod_tab.calc(n), mod_tab.fact[n];
}
modint<MOD> finv(int n) {
    assert(0 <= n);
    return mod_tab.calc(n), mod_tab.finv[n];
}
modint<MOD> C(int n, int k) {
    if (n < 0 || k < 0 || n < k) return 0;
    return fact(n)*finv(k)*finv(n-k);
}
modint<MOD> P(int n, int k) {
    assert(k >= 0); assert(n >= k);
    return fact(n)*finv(n-k);
}





template <class T>
struct Compress {
    vector<T> v;
    bool ok = false;
    void add(T const& x) { ok = false; v.push_back(x); }
    template <class V>
    void add(V const& u) { ok = false; copy(all(u), back_inserter(v)); }
    template <class... Ts>
    void add(Ts const&... xs) { (int[]){(add(xs),0)...}; }
    void init() { sort(all(v)); v.erase(unique(all(v)), v.end()); ok = true; }
    int size() const { return v.size(); }
    T operator[](int i) const { assert(ok); return v[i]; }
    int find(T const& x) const { assert(ok); auto it = lower_bound(all(v),x); assert(*it == x); return it-v.begin(); }
    void set(T& x) const { x = find(x); }
    template <class V>
    void set(V& u) const { for (auto &x : u) x = find(x); }
    template <class... Ts>
    void set(Ts&... xs) const { (int[]){(set(xs),0)...}; }
};






void reord_impl(vector<int> const&) { }
template <class C, class... Args>
void reord_impl(vector<int> const& idx, C& v, Args&&... args) {
    auto t = v;
    rep (i,v.size()) t[i] = v[idx[i]];
    swap(v,t);
    reord_impl(idx, forward<Args>(args)...);
}
template <class Comp, class C, class... Args,
          class = decltype(declval<Comp>()(0,0))>
void reord(Comp comp, C& v, Args&&... args) {
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), comp);
    reord_impl(idx, v, args...);
}
template <class C, class... Args>
void reord(C& v, Args&&... args) {
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return v[i] < v[j]; });
    reord_impl(idx, v, args...);
}
template <class C, class... Args>
void reordR(C& v, Args&&... args) {
    vector<int> idx(v.size());
    iota(idx.begin(), idx.end(), 0);
    sort(idx.begin(), idx.end(), [&](int i, int j) { return v[i] > v[j]; });
    reord_impl(idx, v, args...);
}





struct CountTypes {
    vector<int> cnt;
    int num;
    CountTypes(int n = 0) : cnt(n), num(0) {}
    void clear() { fill(cnt.begin(), cnt.end(), 0); num = 0; };
    int get() const { return num; }
    void add(int x) {
        assert(0 <= x && (int)cnt.size());
        if (cnt[x]++ == 0) num++;
    }
    void del(int x) {
        assert(0 <= x && (int)cnt.size());
        assert(cnt[x] > 0);
        if (--cnt[x] == 0) num--;
    }
};




struct LowerLeftRegion {
    map<int, int> ht;
    int area;
    LowerLeftRegion() : ht{ {0, INF}, {INF, 0} }, area(0) {}
    void add(int x, int y) {
        assert(x >= 0); assert(y >= 0);
        if (x == 0 || y == 0) return;
        auto it = ht.lower_bound(x);
        if (y <= it->second) return;
        auto jt = prev(it);
        while (true) {
            area += (x - jt->first) * (min(jt->second, y) - it->second);
            if (y <= jt->second) break;
            it = jt--;
        }
        ht.erase(it, ht.upper_bound(x));
        ht[x] = y;
    }
};



int k,L;
Compress<int> X, Y;

mint solve(vector<int> x, vector<int> y, vector<int> c) {
    int n = x.size();
    if (n == 0) return 0;
    reord(x,y,c);
    dump(x,y,c);
    LowerLeftRegion llr;
    {
        CountTypes ct(k);
        vector<vector<int>> w(X.size());
        rep (i,n) w[x[i]].eb(i);
        int r = 0;
        rep (i,X.size()) {
            while (r < X.size() && ct.get() < k) {
                for (auto j : w[r]) ct.add(c[j]);
                r++;
            }
            assert(r > 0);
            int val = (ct.get() == k ? X[r-1]+1 : L+1);
            int l = (i == 0 ? 0 : X[i-1]+1);
            llr.add(L-l, val);
            for (auto j : w[i]) ct.del(c[j]);
        }
        dump(llr.ht);
    }

    reord(y,x,c);
    vector<map<int,int>> cnt(k);
    rep (i,n) cnt[c[i]][X[x[i]]]++;

    auto del = [&](int i) {
        

        auto &map = cnt[c[i]];
        auto it = map.find(X[x[i]]);
        assert(it != map.end() && it->snd > 0);
        if (--(it->snd) > 0) return;

        int l = (it == map.begin() ? 0 : prev(it)->fst + 1);
        auto jt = next(it);
        int val = (jt == map.end() ? L : jt->fst) + 1;
        llr.add(L-l, val);
        

        

        map.erase(it);
    };

    mint ans = 0;
    int prev_Y = -1;
    int l = 0;
    rep (i,Y.size()) {
        int len_Y = Y[i]-prev_Y;
        while (l < n && y[l] < i) del(l++);
        if (l == n) break;
        mint val = ((L+1)*L - mint(llr.area)) * len_Y;
        dump(i, len_Y, val);
        ans += val;
        prev_Y = Y[i];
    }
    return ans;
}

int32_t main() {
    int n; cin >> n >> k >> L;
    vector<int> x(n), y(n), c(n);
    rep (i,n) cin >> x[i] >> y[i] >> c[i], --c[i];

    X.add(x, 0LL, L), X.init(), X.set(x);
    Y.add(y, 0LL, L), Y.init(), Y.set(y);
    dump(X.v, Y.v);
    reord(y,x,c);

    mint ans = 0;
    rep (j,Y.size()-1) {
        int r = ubd(y, j);
        dump(j,Y[j],Y[j+1]);
        auto res = solve({rng(x,0,r)}, {rng(y,0,r)}, {rng(c,0,r)});
        dump(j,Y[j],Y[j+1],res);
        debug { cerr << endl; }
        ans += res * (Y[j+1]-Y[j]);
    }
    cout << ans << endl;

}
