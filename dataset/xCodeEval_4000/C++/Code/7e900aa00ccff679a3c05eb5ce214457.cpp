#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define elif else if
#define SZ(x) (int)((x).size())
#define ALL(a) a.begin(), a.end()
using namespace std;
using namespace __gnu_pbds;
using LL = long long;
using LD = long double;
using PII = pair<int, int>;
using PLI = pair<long long, int>;
using PLL = pair<long long, long long>;
using TI = tuple<int, int, int>;
using TL = tuple<LL, LL, LL>;
mt19937 mrand(random_device{}());
int rnd(int x) { return mrand() % x; }
int bcnt(const int64_t &a) { return __builtin_popcountll(a); }
template <class T> int blen(const T &a) { return a ? 1 + blen(a / 2) : 0; }
template <class A, class B> B conv(const A &a, B b = B()) {
    stringstream s;
    s << a, s >> b;
    return b;
}
template <class T> T inf() { return numeric_limits<T>::max() / 2; }
template <class T> T sign(const T &a) { return a == 0 ? 0 : (a < 0 ? -1 : 1); }
template <class T> T floor(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? abs(a) / abs(b) : -(abs(a) + abs(b) - 1) / abs(b);
}
template <class T> T ceil(const T &a, const T &b) {
    assert(b != 0);
    return sign(a) * sign(b) > 0 ? (abs(a) + abs(b) - 1) / abs(b) : -abs(a) / abs(b);
}
template <class T> bool chmin(T &a, T b) { return b < a ? a = b, true : false; }
template <class T> bool chmax(T &a, T b) { return b > a ? a = b, true : false; }
template <class T> auto min(const T &a) { return *min_element(ALL(a)); } 
template <class T> auto max(const T &a) { return *max_element(ALL(a)); }
template <class T> auto sum(const T &a) { return accumulate(ALL(a), (typename T::value_type)0); }
template <> auto sum(const vector<int> &a) { return accumulate(ALL(a), 0LL); }
template <> auto sum(const vector<string> &a) { return accumulate(ALL(a), string()); }
template <class T> void sort_uniq(T &a) { sort(ALL(a)); a.erase(unique(ALL(a)), a.end()); }
template <class T> auto vect(const T &v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
    return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}
 


template <typename T> void in(T &a) { cin >> a; }
template <typename A, typename... B> void in(A &a, B &... b) { in(a), in(b...); }
template <typename A, typename B> void in(pair<A, B> &p) { in(p.first, p.second); }
template <typename A, typename B, typename C> void in(tuple<A, B, C> &p) { in(get<0>(p), get<1>(p), get<2>(p)); }
template <typename T, size_t N> void in(array<T, N> &a) { for (auto &v: a) in(v); }
template <typename T> void in(vector<T> &vec) { for (auto& v: vec) in(v); }
template <typename T, size_t N>
istream& operator >>(istream& inp, array<T, N> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename T>
istream& operator >>(istream& inp, vector<T> &a) {
    for (auto &v: a) inp >> v;
    return inp;
}
template <typename A, typename B>
istream& operator >>(istream& inp, pair<A, B> &p) {
    inp >> p.first >> p.second;
    return inp;
}
template <typename A, typename B, typename C>
istream& operator >>(istream& inp, tuple<A, B, C> &p) {
    inp >> get<0>(p) >> get<1>(p) >> get<2>(p);
    return inp;
}
void ou() { cout << '\n'; }
template<typename T> void ou(const T &a) { cout << a << '\n'; }
template <typename A, typename... B> void ou(const A &a, const B &... b) {
    cout << a << ' ', ou(b...);
}
template<typename A, typename B> void ou(const pair<A, B> &p) {
    cout << p.first << ' ' << p.second << '\n';
}
template<typename A, typename B, typename C> void ou(const tuple<A, B, C> &p) {
    cout << get<0>(p) << ' ' << get<1>(p) << ' ' << get<2>(p) << '\n';
}
void ou(const vector<int> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<LL> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
void ou(const vector<double> &vec) {
    int n = SZ(vec);
    for (int i = 0; i < n; i++) cout << vec[i] << " \n"[i == n - 1];
}
template <typename A> void ou(const vector<A> &vec) {
    for (auto &v: vec) ou(v);
}
template<size_t N> void ou(const array<int, N> &a) {
    for (int i = 0; i < N; i++) cout << a[i] << " \n"[i == N - 1];
}
template<class T> inline void YES(T condition) { 
    if(condition) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}
template<class T> inline void Yes(T condition) {
    if(condition) cout << "Yes" << '\n';
    else cout << "No" << '\n';
}
 








template<class T>
using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
template<class T> T lcm(T a, T b){
    return a / gcd(a, b) * b;
}
int dx[8] = {1, 0, -1, 0, 1, 1, -1, -1};
int dy[8] = {0, 1, 0, -1, 1, -1, 1, -1};

#ifndef ATCODER_MODINT_HPP
#define ATCODER_MODINT_HPP 1

#include <cassert>
#include <numeric>
#include <type_traits>

#ifdef _MSC_VER
#include <intrin.h>
#endif

#ifndef ATCODER_INTERNAL_MATH_HPP
#define ATCODER_INTERNAL_MATH_HPP 1

#include <utility>

namespace atcoder {

namespace internal {





constexpr long long safe_mod(long long x, long long m) {
    x %= m;
    if (x < 0) x += m;
    return x;
}







struct barrett {
    unsigned int _m;
    unsigned long long im;

    

    explicit barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

    

    unsigned int umod() const { return _m; }

    

    

    

    unsigned int mul(unsigned int a, unsigned int b) const {
        

        


        

        

        

        

        

        

        

        unsigned long long z = a;
        z *= b;
#ifdef _MSC_VER
        unsigned long long x;
        _umul128(z, im, &x);
#else
        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);
#endif
        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
    if (m == 1) return 0;
    unsigned int _m = (unsigned int)(m);
    unsigned long long r = 1;
    unsigned long long y = safe_mod(x, m);
    while (n) {
        if (n & 1) r = (r * y) % _m;
        y = (y * y) % _m;
        n >>= 1;
    }
    return r;
}









constexpr bool is_prime_constexpr(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = pow_mod_constexpr(a, t, n);
        while (t != n - 1 && y != 1 && y != n - 1) {
            y = y * y % n;
            t <<= 1;
        }
        if (y != n - 1 && t % 2 == 0) {
            return false;
        }
    }
    return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);





constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
    a = safe_mod(a, b);
    if (a == 0) return {b, 0};

    

    

    

    

    long long s = b, t = a;
    long long m0 = 0, m1 = 1;

    while (t) {
        long long u = s / t;
        s -= t * u;
        m0 -= m1 * u;  


        

        

        

        


        auto tmp = s;
        s = t;
        t = tmp;
        tmp = m0;
        m0 = m1;
        m1 = tmp;
    }
    

    

    if (m0 < 0) m0 += b / s;
    return {s, m0};
}







constexpr int primitive_root_constexpr(int m) {
    if (m == 2) return 1;
    if (m == 167772161) return 3;
    if (m == 469762049) return 3;
    if (m == 754974721) return 11;
    if (m == 998244353) return 3;
    int divs[20] = {};
    divs[0] = 2;
    int cnt = 1;
    int x = (m - 1) / 2;
    while (x % 2 == 0) x /= 2;
    for (int i = 3; (long long)(i)*i <= x; i += 2) {
        if (x % i == 0) {
            divs[cnt++] = i;
            while (x % i == 0) {
                x /= i;
            }
        }
    }
    if (x > 1) {
        divs[cnt++] = x;
    }
    for (int g = 2;; g++) {
        bool ok = true;
        for (int i = 0; i < cnt; i++) {
            if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);







unsigned long long floor_sum_unsigned(unsigned long long n,
                                      unsigned long long m,
                                      unsigned long long a,
                                      unsigned long long b) {
    unsigned long long ans = 0;
    while (true) {
        if (a >= m) {
            ans += n * (n - 1) / 2 * (a / m);
            a %= m;
        }
        if (b >= m) {
            ans += n * (b / m);
            b %= m;
        }

        unsigned long long y_max = a * n + b;
        if (y_max < m) break;
        

        

        n = (unsigned long long)(y_max / m);
        b = (unsigned long long)(y_max % m);
        std::swap(m, a);
    }
    return ans;
}

}  


}  


#endif  


#ifndef ATCODER_INTERNAL_TYPE_TRAITS_HPP
#define ATCODER_INTERNAL_TYPE_TRAITS_HPP 1

#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

#ifndef _MSC_VER
template <class T>
using is_signed_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value ||
                                  std::is_same<T, __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int128 =
    typename std::conditional<std::is_same<T, __uint128_t>::value ||
                                  std::is_same<T, unsigned __int128>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using make_unsigned_int128 =
    typename std::conditional<std::is_same<T, __int128_t>::value,
                              __uint128_t,
                              unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
                                                  is_signed_int128<T>::value ||
                                                  is_unsigned_int128<T>::value,
                                              std::true_type,
                                              std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
                                                 std::is_signed<T>::value) ||
                                                    is_signed_int128<T>::value,
                                                std::true_type,
                                                std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<(is_integral<T>::value &&
                               std::is_unsigned<T>::value) ||
                                  is_unsigned_int128<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
    is_signed_int128<T>::value,
    make_unsigned_int128<T>,
    typename std::conditional<std::is_signed<T>::value,
                              std::make_unsigned<T>,
                              std::common_type<T>>::type>::type;

#else

template <class T> using is_integral = typename std::is_integral<T>;

template <class T>
using is_signed_int =
    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using is_unsigned_int =
    typename std::conditional<is_integral<T>::value &&
                                  std::is_unsigned<T>::value,
                              std::true_type,
                              std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<is_signed_int<T>::value,
                                              std::make_unsigned<T>,
                                              std::common_type<T>>::type;

#endif

template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  


#endif  


namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
    using mint = static_modint;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    static_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    static_modint(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    static_modint(T v) {
        _v = (unsigned int)(v % umod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v -= rhs._v;
        if (_v >= umod()) _v += umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        unsigned long long z = _v;
        z *= rhs._v;
        _v = (unsigned int)(z % umod());
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        if (prime) {
            assert(_v);
            return pow(umod() - 2);
        } else {
            auto eg = internal::inv_gcd(_v, m);
            assert(eg.first == 1);
            return eg.second;
        }
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static constexpr unsigned int umod() { return m; }
    static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
    using mint = dynamic_modint;

  public:
    static int mod() { return (int)(bt.umod()); }
    static void set_mod(int m) {
        assert(1 <= m);
        bt = internal::barrett(m);
    }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    dynamic_modint() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    dynamic_modint(T v) {
        _v = (unsigned int)(v % mod());
    }

    unsigned int val() const { return _v; }

    mint& operator++() {
        _v++;
        if (_v == umod()) _v = 0;
        return *this;
    }
    mint& operator--() {
        if (_v == 0) _v = umod();
        _v--;
        return *this;
    }
    mint operator++(int) {
        mint result = *this;
        ++*this;
        return result;
    }
    mint operator--(int) {
        mint result = *this;
        --*this;
        return result;
    }

    mint& operator+=(const mint& rhs) {
        _v += rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator-=(const mint& rhs) {
        _v += mod() - rhs._v;
        if (_v >= umod()) _v -= umod();
        return *this;
    }
    mint& operator*=(const mint& rhs) {
        _v = bt.mul(_v, rhs._v);
        return *this;
    }
    mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

    mint operator+() const { return *this; }
    mint operator-() const { return mint() - *this; }

    mint pow(long long n) const {
        assert(0 <= n);
        mint x = *this, r = 1;
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }
    mint inv() const {
        auto eg = internal::inv_gcd(_v, mod());
        assert(eg.first == 1);
        return eg.second;
    }

    friend mint operator+(const mint& lhs, const mint& rhs) {
        return mint(lhs) += rhs;
    }
    friend mint operator-(const mint& lhs, const mint& rhs) {
        return mint(lhs) -= rhs;
    }
    friend mint operator*(const mint& lhs, const mint& rhs) {
        return mint(lhs) *= rhs;
    }
    friend mint operator/(const mint& lhs, const mint& rhs) {
        return mint(lhs) /= rhs;
    }
    friend bool operator==(const mint& lhs, const mint& rhs) {
        return lhs._v == rhs._v;
    }
    friend bool operator!=(const mint& lhs, const mint& rhs) {
        return lhs._v != rhs._v;
    }

  private:
    unsigned int _v;
    static internal::barrett bt;
    static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt(998244353);

using modint998244353 = static_modint<998244353>;





namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  


#endif  


using mint = atcoder::modint998244353;
ostream& operator <<(ostream& out, const mint& a) {
    out << a.val(); return out;
}

struct DSU {
    int n;
    vector<int> fa;
    vector<int> sz;
    DSU(int n) : n(n), fa(n), sz(n) {
        iota(fa.begin(), fa.end(), 0);
        fill(sz.begin(), sz.end(), 1);
    };
 
    int find(int x) {
        assert (0 <= x && x < n);
        return fa[x] == x ? x : fa[x] = find(fa[x]);
    }
 
    bool merge(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return false;
        if (sz[px] > sz[py]) swap(px, py);
        fa[px] = py;
        sz[py] += sz[px];
        return true;
    }
};

const string COLOR_RESET = "\033[0m";
const string BRIGHT_GREEN = "\033[1;32m";
const string BRIGHT_RED = "\033[1;31m";
const string BRIGHT_CYAN = "\033[1;36m";
const string NORMAL_CROSSED = "\033[0;9;37m";
const string RED_BACKGROUND = "\033[1;41m";
const string NORMAL_FAINT = "\033[0;2m";
template<class A, class B> ostream& operator <<(ostream& out, const pair<A, B> &p) {
    return out << "(" << p.first << ", " << p.second << ")";
}
template<class A, class B, class C> ostream& operator <<(ostream& out, const tuple<A, B, C> &p) {
    return out << "(" << get<0>(p) << ", " << get<1>(p) << ", " << get<2>(p) << ")";
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
    out << "["; for (int i = 0; i < (int)N; i++) out << a[i] << (i == N - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const deque<T>& a) {
    out << "["; for (int i = 0; i < (int)(a.size()); i++) out << a[i] << (i == (int)(a.size()) - 1 ? "]" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream &out, const multiset<T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename T>
ostream& operator <<(ostream& out, const unordered_set<T>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << *it << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
    out << "{"; for (auto it = a.begin(); it != a.end(); it++) out << it->first << ":" << it->second << (it == --a.end() ? "}" : ", "); return out;
}
template <typename U, class Cmp>
ostream& operator <<(ostream& out, priority_queue<U, vector<U>, Cmp>& a) {
    out << "{"; bool first = true;
    priority_queue<U, vector<U>, Cmp> tmp;
    while (!a.empty()) { out << (first ? "" : ", "); out << a.top(); tmp.emplace(a.top()); a.pop(); first = 0; } out << "}";
    a = move(tmp);
    return out;
}


 
#ifdef FANZHH
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
    cerr << BRIGHT_CYAN << name << COLOR_RESET << ": " << arg1 << COLOR_RESET << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
    const char* comma = strchr(names + 1, ',');
    cerr << BRIGHT_CYAN;
    cerr.write(names, comma - names) << COLOR_RESET << ": " << arg1 << ' ';
    cerr << BRIGHT_RED << "| " << COLOR_RESET;
    __f(comma + 1, args...);
}
#else
#define trace(...) (void(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);










    int n; cin >> n;
    vector<array<int, 2>> a(n); in(a);
    auto D = [&](int i, int j) -> LL {
        auto [x1, y1] = a[i];
        auto [x2, y2] = a[j];
        return abs(x1 - x2) + abs(y1 - y2);
    };
    DSU dsu(n);
    vector<vector<LL>> d(n, vector<LL>(n, inf<LL>()));
    vector<LL> mnd(n, inf<LL>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) if (j != i) {
            d[i][j] = D(i, j);
            chmin(mnd[i], d[i][j]);
        }
    }
    auto check = [&](vector<int>& t) -> bool {
        int m = SZ(t);
        for (int i = 1; i < m; i++) if (mnd[t[i]] != mnd[t[0]]) return false;
        LL mn = mnd[t[0]];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < m; j++) if (j != i) {
                if (d[t[i]][t[j]] != mn) return false;
            }
        }
        return true;
    };
    vector<int> redu;
    vector<int> vis(n);
    for (int u = 0; u < n; u++) if (!vis[u]) {
        vis[u] = 1;
        for (int v = 0; v < n; v++) if (!vis[v] && d[u][v] == mnd[u] && d[u][v] == mnd[v]) {
            LL dd = d[u][v];
            set<int> A;
            queue<int> q;
            q.push(u); q.push(v);
            A.insert(u); A.insert(v);
            bool can = true;
            while (!q.empty() && can) {
                auto i = q.front(); q.pop();
                for (int j = 0; j < n; j++) if (!A.count(j) && d[i][j] == dd) {
                    

                    if (mnd[j] != dd) { can = false; break; }
                    for (auto x: A) can &= (d[x][j] == dd);
                    if (can) { A.insert(j); q.push(j); }
                }
            }
            trace(A, can);
            if (!can) continue;
            for (auto &x: A) vis[x] = 1;
            if (SZ(A) > 1) {
                trace(A);
                redu.push_back(SZ(A) - 1);
            }
        }
    }
    trace(redu);
    vector<mint> fac(n + 1), ifac(n + 1), C(n + 1);
    fac[0] = 1;
    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1] * mint(i);
    ifac[n] = fac[n].inv();
    for (int i = n - 1; i >= 0; i--) ifac[i] = ifac[i + 1] * mint(i + 1);
    for (int i = 0; i <= n; i++) C[i] = fac[n] * ifac[i] * ifac[n - i];
    


    vector<mint> dp(n + 1); dp[n] = 1;
    for (auto j: redu) {
        vector<mint> ndp = dp;
        for (int i = n; i >= j; i--) ndp[i - j] += dp[i];
        dp = move(ndp);
    }

    mint ans = 0;
    for (int x = 0; x <= n; x++) {
        mint cur = fac[x] * C[x];
        ans += cur * dp[x];
    }
    ou(ans.val());

    










    return 0;
}
