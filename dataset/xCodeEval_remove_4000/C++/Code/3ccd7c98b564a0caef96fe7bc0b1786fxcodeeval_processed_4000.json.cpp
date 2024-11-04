






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




    return id3;                      \
  }

  auto predicate = [&](auto &&x) {           \
    return id3;                      \
  };                                         \
  return predicate(lhs) < predicate(rhs);    \
}











                         down = a > b, i = a - down; i + down != b;           \
                         down ? --i : ++i)




int id2 = 0;


    io::log(string(id2 - 1, '\t') +        \
        string(__func__) + ":" + to_string(__LINE__) + \
        " \t( "
        id3),                                  \
    --id2, cerr << "\n")

      ++id2;                                \
      auto&& value = id3;                       \
      --id2;                                \
      cerr << string(id2, '\t')             \
           << func << ":" << __LINE__                   \
           << " \t"
      return forward<decltype(value)>(value);           \
    }(__func__)

void test_
int test_result_
    test_
    cerr << 
           << endl;                     \
    return 0;                           \
}();                                    \
void test_







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

        unsigned long long x;
        _umul128(z, im, &x);

        unsigned long long x =
            (unsigned long long)(((unsigned __int128)(z)*im) >> 64);

        unsigned int v = (unsigned int)(z - x * _m);
        if (_m <= v) v += _m;
        return v;
    }
};







constexpr long long id9(long long x, long long n, int m) {
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









constexpr bool id8(int n) {
    if (n <= 1) return false;
    if (n == 2 || n == 7 || n == 61) return true;
    if (n % 2 == 0) return false;
    long long d = n - 1;
    while (d % 2 == 0) d /= 2;
    constexpr long long bases[3] = {2, 7, 61};
    for (long long a : bases) {
        long long t = d;
        long long y = id9(a, t, n);
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
template <int n> constexpr bool is_prime = id8(n);





constexpr std::pair<long long, long long> id1(long long a, long long b) {
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







constexpr int id5(int m) {
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
            if (id9(g, (m - 1) / divs[i], m) == 1) {
                ok = false;
                break;
            }
        }
        if (ok) return g;
    }
}
template <int m> constexpr int primitive_root = id5(m);







unsigned long long id0(unsigned long long n,
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









namespace atcoder {

namespace internal {


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



template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  


}  





namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  


template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct id7 : internal::static_modint_base {
    using mint = id7;

  public:
    static constexpr int mod() { return m; }
    static mint raw(int v) {
        mint x;
        x._v = v;
        return x;
    }

    id7() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id7(T v) {
        long long x = (long long)(v % (long long)(umod()));
        if (x < 0) x += umod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id7(T v) {
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
            auto eg = internal::id1(_v, m);
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

template <int id> struct id6 : internal::modint_base {
    using mint = id6;

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

    id6() : _v(0) {}
    template <class T, internal::is_signed_int_t<T>* = nullptr>
    id6(T v) {
        long long x = (long long)(v % (long long)(mod()));
        if (x < 0) x += mod();
        _v = (unsigned int)(x);
    }
    template <class T, internal::is_unsigned_int_t<T>* = nullptr>
    id6(T v) {
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
        auto eg = internal::id1(_v, mod());
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
template <int id> internal::barrett id6<id>::bt(998244353);

using modint998244353 = id7<998244353>;
using modint1000000007 = id7<1000000007>;
using modint = id6<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<id6<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  


}  





using Mint = atcoder::modint1000000007;

Mint solve(int k, int m, Vec<int> as) {
  const int n = len(as);
  if (k == 1) {
    return Mint(n) * m * (Mint(n) * m - 1) + 1;
  }

  as[0] %= k;
  F(i, 1, n) {
    as[i] += as[i-1];
    as[i] %= k;
  }
  i64 s = as.back();
  as.insert(as.begin(), 0);
  as.pop_back();

  Vec<int> last(k, -1);
  Vec<int> next(n, -1);

  F(i, n) {
    if (last[as[i]] != -1) {
      next[last[as[i]]] = i;
    }
    last[as[i]] = i;
  }

  if (s % k == 0) {
    Vec<int> cnt(k);
    for (auto a : as) ++cnt[a];

    Mint result = 0;
    F(i, k) {
      result += Mint(m) * m * cnt[i] * cnt[i];
    }

    result -= Mint(n) * m - 1;
    return result;
  }

  Vec<int> idx(k, -1);
  F(i, n) if (idx[as[i]] == -1) idx[as[i]] = i;

  

  Vec<P<>> steps(k, {-1, -1});

  const int ks = k - s;
  F(i, k) {
    if (steps[i] != P<>{-1, -1}) continue;
    int jmp = 1, rem = (i + ks) % k;
    while ( idx[rem] == -1) {
      ++jmp;
      rem += ks;
      if (rem >= k) {
        rem -= k;
      }
    }

    const int id4 = jmp;












    const int dest = idx[rem];

    rem = static_cast<int>(i);
    F(j, id4) {
      steps[rem] = {jmp - j, dest};
      rem += ks;
      rem %= k;
    }
  }

  Vec<P<>> zero(n);
  F(i, n) {
    if (next[i] != -1) {
      zero[i] = {0, next[i]};
    } else {
      zero[i] = steps[as[i]];
    }
  }

  L(zero);

  Vec<Vec<P<>>> bins(1, zero);
  while (true) {
    Vec<P<>> next_(n);
    F(i, n) {
      auto [shift_1, mid_idx] = bins.back()[i];
      auto [shift_2, end_idx] = bins.back()[mid_idx];
      next_[i] = {shift_1 + shift_2, end_idx};
      next_[i].X = min<int>(next_[i].X, m+1);
    }
    bins.PB(next_);
    if (all_of(A(next_), [&](auto &&x) { return x.X > m; })) {
      break;
    }
  }

  Mint result = 0;
  F(i, n) {
    int l = 0, j = i;
    i64 ans = 0;

    F(level, len(bins), 0) {
      auto[shift, index] = bins[level][j];
      if (shift + l < m || (shift + l == m && index <= i)) {
        l += shift;
        j = index;
        ans |= 1ll << level;
      }
    }

    while (true) {
      auto[shift, index] = zero[j];
      l += shift;
      j = index;

      if (l > m || (l == m && j > i)) break;
      ++ans;
    }

    result += Mint(m) * ans;
  }

  if (m % k == 0) {
    result -= Mint(n) * m - 1;
  }

  return result;
}

Mint stupid(i64 k, int m, const Vec<int> &as) {
  Vec<i64> total;
  F(_, m) total.insert(total.end(), A(as));

  Mint ans = 0;
  F(i, len(total)) {
    i64 s = total[i] % k;
    if (s == 0) {
      ++ans;
    }

    for (int j = (i+1) % len(total); j != i; ++j %= len(total)) {
      s += total[j];
      s %= k;

      if (s == 0) {
        ++ans;
      }
    }
  }

  i64 s = accumulate(A(total), 0ll) % k;
  if (s == 0) {
    ans -= len(total) - 1;
  }

  return ans;
}

TEST(stress) {
  mt19937 gen(239);
  Vec<int> ks{1, 2, 3, 5, 7, 11, 13};

  F(_, 10'000) {
    const int k = ks[gen() % len(ks)];
    const int n = 1 + gen() % 10;
    const int m = 1 + gen() % 10;

    Vec<int> as(n);
    auto dist = uniform_int_distribution(0, 20);

    for (auto &a: as) a = gen() % 1'000;

    auto expected = stupid(k, m, as);
    auto actual = solve(k, m, as);

    if (expected != actual) {
      L(expected.val(), actual.val());
      L(k, m, as);
      exit(239);
    }

    if (_ % 10'000 == 9'999) {
      L(_, "tests passed");
    }
  }
}

int main() {
  int R(n, m, k);
  Vec<int> RC(as, n);

  cout << solve(k, m, as).val();
}

namespace {
auto fast_io = [] {


    ios::sync_with_stdio(false);
    cin.tie(nullptr);



    freopen(FILES".in", "r", stdin);
    freopen(FILES".out", "w", stdout);




    cout << setprecision(8) << fixed;
    cerr << boolalpha << setprecision(4) << fixed;

    return 0;
}();
} 

