#line 1 "g.cpp"


#line 1 "/Users/denyssmirnov/open-source/ac-library/atcoder/fenwicktree.hpp"



#include <cassert>
#include <vector>

#line 1 "/Users/denyssmirnov/open-source/ac-library/atcoder/internal_type_traits.hpp"



#line 5 "/Users/denyssmirnov/open-source/ac-library/atcoder/internal_type_traits.hpp"
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



#line 8 "/Users/denyssmirnov/open-source/ac-library/atcoder/fenwicktree.hpp"

namespace atcoder {



template <class T> struct fenwick_tree {
    using U = internal::to_unsigned_t<T>;

  public:
    fenwick_tree() : _n(0) {}
    explicit fenwick_tree(int n) : _n(n), data(n) {}

    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += U(x);
            p += p & -p;
        }
    }

    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:
    int _n;
    std::vector<U> data;

    U sum(int r) {
        U s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

}  



#line 7 "g.cpp"
#pragma GCC optimize("Ofast")





#include <bits/stdc++.h>

#line 1 "/Users/denyssmirnov/open-source/ac-library/atcoder/modint.hpp"



#line 7 "/Users/denyssmirnov/open-source/ac-library/atcoder/modint.hpp"

#ifdef _MSC_VER
#include <intrin.h>
#endif

#line 1 "/Users/denyssmirnov/open-source/ac-library/atcoder/internal_math.hpp"



#line 5 "/Users/denyssmirnov/open-source/ac-library/atcoder/internal_math.hpp"

#ifdef _MSC_VER
#include <intrin.h>
#endif

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



#line 14 "/Users/denyssmirnov/open-source/ac-library/atcoder/modint.hpp"

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
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

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



#line 15 "g.cpp"

#define requires(...) typename std::enable_if<__VA_ARGS__::value, int>::type = 0

using namespace std;

template<class U, class V>
istream &operator>>(istream &is, pair<U, V> &p) { return is >> p.first >> p.second; }

template<class U, class V>
ostream &operator<<(ostream &os, const pair<U, V> &p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<class Istream, class Container, requires(is_same<Istream, istream>)>
Istream &operator>>(Istream &is, Container &container) {
  for (auto &value : container) is >> value;
  return is;
}

template<class Ostream, class Container, requires(is_same<Ostream, ostream>)>
Ostream &operator<<(Ostream &os, const Container &container) {
  auto _begin = begin(container), _end = end(container);
  for (auto it = _begin; it != _end;)
  os << "{ "[it != _begin] << *it << ",}"[++it == _end];
  return os;
}

namespace io {
  template <class ...As> struct last {};
  template <class ...As> using last_t = typename last<As...>::type;
  template <class A> struct last<A> { using type = A; };
  template <class A, class ...As> struct last<A, As...> {
    using type = typename last<As...>::type;
  };

  template <class Z>
  Z read(Z z) { cin >> z; return z; }

  template <class A, class ...As>
  last_t<As...> read(A &a, As &...as) { return cin >> a, read(as...); }

  void log_rest() {}

  template <class A, class ...As>
  void log_rest(const A &a, const As &...as) { cerr << ", " << a; log_rest(as...); }

  template<class A, class ...As>
  void log(const string &pref, const A &a, const As &...as)
  { cerr << pref << a, log_rest(as...); }
}  


#define A(xs) ::std::begin(xs), ::std::end(xs)
#define B(...) [&](auto &&lhs, auto &&rhs) { \
    return __VA_ARGS__;                      \
  }
#define U(...) [&](auto &&lhs, auto &&rhs) { \
  auto predicate = [&](auto &&x) {           \
    return __VA_ARGS__;                      \
  };                                         \
  return predicate(lhs) < predicate(rhs);    \
}
#define X  first
#define Y  second
#define PB push_back
#define EB emplace_back

#define R(...)        __VA_ARGS__ = io::read(__VA_ARGS__)
#define RC(name, ...) name(__VA_ARGS__); cin >> name

#define G3(_1, _2, _3, FUNC, ...) FUNC
#define F1(i, n)    for (typename remove_cv<decltype(n)>::type i = {}; i != n; ++i)
#define F2(i, a, b) for (typename common_type<decltype(a), decltype(b)>::type \
                         down = a > b, i = a - down; i + down != b;           \
                         down ? --i : ++i)

#define F(...) G3(__VA_ARGS__, F2, F1)(__VA_ARGS__)

#ifdef DEBUG
int recursion_depth = 0;
#  define D       for (bool _flag = true; _flag; _flag = !_flag)
#  define L(...)  (++recursion_depth,                  \
    io::log(string(recursion_depth - 1, '\t') +        \
        string(__func__) + ":" + to_string(__LINE__) + \
        " \t( "#__VA_ARGS__" ) := ",                   \
        __VA_ARGS__),                                  \
    --recursion_depth, cerr << "\n")
#  define dbg(...) [&](const string &func) -> auto && { \
      ++recursion_depth;                                \
      auto&& value = __VA_ARGS__;                       \
      --recursion_depth;                                \
      cerr << string(recursion_depth, '\t')             \
           << func << ":" << __LINE__                   \
           << " \t"#__VA_ARGS__" = " << value << endl;  \
      return forward<decltype(value)>(value);           \
    }(__func__)
#  define TEST(name)                    \
void test_##name();                     \
int test_result_##name = [] {           \
    test_##name();                      \
    cerr << #name" tests have passed!"  \
           << endl;                     \
    return 0;                           \
}();                                    \
void test_##name()
#else
#  define L(...)     while (false) cerr
#  define D          while (false)
#  define dbg(...)   (__VA_ARGS__)
#  define TEST(name) void test_##name()
#endif

template<class T>
T make_vec(T default_value) { return default_value; }

template<class T, class Arg, class ...Args>
auto make_vec(T default_value, Arg size, Args ...rest)
-> vector<decltype(make_vec(default_value, rest...))> {
  auto level = make_vec(default_value, rest...);
  return vector<decltype(level)>(size, level);
}

template<class Xs> int len(const Xs &xs) { return static_cast<int>(xs.size()); }

template <class T, class P>
auto bin_search(T l, T r, P p) -> T {
  for (T m; m = (l + r) / 2, m != l && m != r; (p(m) ? l : r) = m);
  return l;
}

using i64 = int64_t;
using f80 = long double;

using Str = string;
template<class T = int> using Vec = vector<T>;
template<class K = int, class H = hash<K>> using US = unordered_set<K, H>;
template<class K, class V, class H = hash<K>> using UM = unordered_map<K, V, H>;

template<class U = int, class V = U> using P = pair<U, V>;
using G = Vec<Vec<int>>;

using namespace atcoder;

using Mint = atcoder::modint1000000007;

mt19937 rnd;

struct Set {
  int key;
  Mint value = 0, sum = 0;
  int priority = rnd();
  Set *left = nullptr, *right = nullptr;

  Set(int key, Mint value = 0) : key(key), value(value), sum(value) {}

  static deque<Set> &storage() {
    static deque<Set> storage;
    return storage;
  }

  template <class ...As>
  static Set *new_set(As &&...as) {
    storage().emplace_back(forward<As>(as)...);
    return &storage().back();
  }
};

Mint Sum(Set *set) {
  return set ? set->sum : 0;
}

Set *Update(Set *set) {
  set->sum = set->value;
  for (auto son : {set->left, set->right}) {
    if (son) {
      set->sum += son->sum;
    }
  }
  return set;
}

Set *Merge(Set *lhs, Set *rhs) {
  if (!lhs || !rhs) return lhs ? lhs : rhs;

  if (lhs->priority < rhs->priority) {
    lhs->right = Merge(lhs->right, rhs);
    return Update(lhs);
  } else {
    rhs->left = Merge(lhs, rhs->left);
    return Update(rhs);
  }
}

P<Set *> Split(Set *set, int key) {
  if (!set) return {nullptr, nullptr};
  if (set->key < key) {
    auto [mhs, rhs] = Split(set->right, key);
    set->right = mhs;
    return {Update(set), rhs};
  } else {
    auto [lhs, mhs] = Split(set->left, key);
    set->left = mhs;
    return {lhs, Update(set)};
  }
}

Vec<Vec<>> to_buckets(const Vec<int> &as) {
  const int n = len(as);

  Vec<int> last;
  F(i, n, 0) {
    if (last.empty() || as[i] > as[last.back()]) {
      last.PB(i);
    }
  }

  Vec<Vec<>> res(len(last));
  F(i, n) {
    auto j = lower_bound(A(last), i, U(as[x])) - last.begin();
    if (j >= len(last)) {
      res.PB({i});
      continue;
    }




    if (last[j] == i) {
      res[j].PB(i);
      continue;
    }

    if (as[last[j]] == as[i]) ++j;
    if (j >= len(last) || i > last[j]) {
      res.PB({i});
      continue;
    }

    res[j].PB(i);
  }






  return res;
}

Mint solve(const Vec<int> &as) {
  const int n = len(as);

  Vec<P<>> es;
  F(i, n) es.EB(as[i], -i);
  sort(A(es));

  Vec<> bs(n);
  F(i, n) bs[-es[i].Y] = i;

  Vec<Mint> l_to_r(n), r_to_l(n);

  for (auto [s, f] : array<P<>, 2>{
    P<>{0, n},
    P<>{n, 0},
  }){
    fenwick_tree<Mint> ss(n);

    

    F(i, s, f) {
      

      


      

      

      


      l_to_r[i] = 1 + (s < f ? ss.sum(0, bs[i]) : ss.sum(bs[i]+1, n));
      ss.add(bs[i], l_to_r[i]);
      

      

      


      

      


      

    }

    

    swap(l_to_r, r_to_l);
  }

  fenwick_tree<Mint> ss(n);

  Vec<Vec<int>> indices = to_buckets(as);
  for (auto &is : indices) {
    auto end = is.back();
    r_to_l[end] = 0;
    is.pop_back();
    reverse(A(is));

    ss.add(bs[end], Mint(1));

    for (int i : is) {
      

      


      

      
      Mint gt_sum = ss.sum(bs[i]+1, n);
      ss.add(bs[i], gt_sum);
      
      

      


      r_to_l[i] -= gt_sum;
    }

    ss.add(bs[end], Mint(-1));

    for (int i : is) {
      ss.add(bs[i], -ss.sum(bs[i], bs[i]+1));
    }
    

  }

  Mint total = 0;
  F(i, n) total += l_to_r[i] * r_to_l[i];

  return total;
}

Mint stupid(const Vec<int> &as) {
  const int n = len(as);
  Mint total = 0;

  F(m, 1, 1 << n) {
    Vec<> is;
    F(i, n) if (m >> i & 1) is.PB(i);
    bool ok = true;
    if (len(is) > 1) F(i, len(is)-1) {
      if (as[is[i]] >= as[is[i+1]]) {
        ok = false;
        break;
      }
    }

    if (!ok) continue;
    if (is.back() == n-1) continue;

    const int j = max_element(is.back() + 1 + A(as)) - as.begin();
    for (int i : is) {
      if (as[i] < as[j]) {
        ++total;
      }
    }
  }

  return total;
}

TEST(stress) {
  return;
  mt19937 rnd;
  const int n = 5;

  F(_, 1'000'000) {
    Vec<int> as(n);
    for (auto &a : as) a = rnd() % 10;

    auto expected = stupid(as);
    auto actual = solve(as);

    if (expected != actual) {
      L(as);
      L(expected.val(), actual.val());
      exit(228);
    }
  }
}

signed main() {
  int R(t);
  F(_t, t) {
    L(_t);
    int R(n);
    Vec<int> RC(as, n);
    cout << solve(as).val() << '\n';
  }
}

namespace {
auto fast_io = [] {
#ifndef DEBUG
#  ifndef INTERACTIVE
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
#  endif 

#  ifdef FILES
    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);
#  endif 

#endif 

    cout << setprecision(20) << fixed;
    cerr << boolalpha << setprecision(4) << fixed;

    return 0;
}();
} 

