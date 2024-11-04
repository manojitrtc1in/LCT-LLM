#line 1 "library/my_template.hpp"
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using u32 = unsigned int;
using u64 = unsigned long long;
using i128 = __int128;

template <class T>
using vc = vector<T>;
template <class T>
using vvc = vector<vc<T>>;
template <class T>
using vvvc = vector<vvc<T>>;
template <class T>
using vvvvc = vector<vvvc<T>>;
template <class T>
using vvvvvc = vector<vvvvc<T>>;
template <class T>
using pq = priority_queue<T>;
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;

#define vec(type, name, ...) vector<type> name(__VA_ARGS__)
#define vv(type, name, h, ...) \
  vector<vector<type>> name(h, vector<type>(__VA_ARGS__))
#define vvv(type, name, h, w, ...)   \
  vector<vector<vector<type>>> name( \
      h, vector<vector<type>>(w, vector<type>(__VA_ARGS__)))
#define vvvv(type, name, a, b, c, ...)       \
  vector<vector<vector<vector<type>>>> name( \
      a, vector<vector<vector<type>>>(       \
             b, vector<vector<type>>(c, vector<type>(__VA_ARGS__))))

#define FOR_(n) for (ll _ = 0; (_) < (ll)(n); ++(_))
#define FOR(i, n) for (ll i = 0; (i) < (ll)(n); ++(i))
#define FOR3(i, m, n) for (ll i = (m); (i) < (ll)(n); ++(i))
#define FOR_R(i, n) for (ll i = (ll)(n)-1; (i) >= 0; --(i))
#define FOR3_R(i, m, n) for (ll i = (ll)(n)-1; (i) >= (ll)(m); --(i))
#define FOR_subset(t, s) for (ll t = s; t >= 0; t = (t == 0 ? -1 : (t - 1) & s))
#define all(x) x.begin(), x.end()
#define len(x) ll(x.size())
#define elif else if

#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second

#define stoi stoll

template <typename T>
T SUM(vector<T> &A) {
  T sum = T(0);
  for (auto &&a: A) sum += a;
  return sum;
}
#define MIN(v) *min_element(all(v))
#define MAX(v) *max_element(all(v))
#define LB(c, x) distance((c).begin(), lower_bound(all(c), (x)))
#define UB(c, x) distance((c).begin(), upper_bound(all(c), (x)))
#define UNIQUE(x) sort(all(x)), x.erase(unique(all(x)), x.end())

int popcnt(int x) { return __builtin_popcount(x); }
int popcnt(u32 x) { return __builtin_popcount(x); }
int popcnt(ll x) { return __builtin_popcountll(x); }
int popcnt(u64 x) { return __builtin_popcountll(x); }


int topbit(int x) { return 31 - __builtin_clz(x); }
int topbit(u32 x) { return 31 - __builtin_clz(x); }
int topbit(ll x) { return 63 - __builtin_clzll(x); }
int topbit(u64 x) { return 63 - __builtin_clzll(x); }


int lowbit(int x) { return 31 - __builtin_clz(x); }
int lowbit(u32 x) { return 31 - __builtin_clz(x); }
int lowbit(ll x) { return 63 - __builtin_clzll(x); }
int lowbit(u64 x) { return 63 - __builtin_clzll(x); }

template <typename T, typename U>
T ceil(T x, U y) {
  return (x > 0 ? (x + y - 1) / y : x / y);
}

template <typename T, typename U>
T floor(T x, U y) {
  return (x > 0 ? x / y : (x - y + 1) / y);
}

template <typename T, typename U>
pair<T, T> divmod(T x, U y) {
  T q = floor(x, y);
  return {q, x - q * y};
}

ll binary_search(function<bool(ll)> check, ll ok, ll ng) {
  assert(check(ok));
  while (abs(ok - ng) > 1) {
    auto x = (ng + ok) / 2;
    if (check(x))
      ok = x;
    else
      ng = x;
  }
  return ok;
}

template <class T, class S>
inline bool chmax(T &a, const S &b) {
  return (a < b ? a = b, 1 : 0);
}
template <class T, class S>
inline bool chmin(T &a, const S &b) {
  return (a > b ? a = b, 1 : 0);
}

vi s_to_vi(string S, char first_char = 'a') {
  vi A(S.size());
  FOR(i, S.size()) { A[i] = S[i] - first_char; }
  return A;
}

template <typename T>
vector<T> cumsum(vector<T> &A, int off = 1) {
  int N = A.size();
  vector<T> B(N + 1);
  FOR(i, N) { B[i + 1] = B[i] + A[i]; }
  if (off == 0) B.erase(B.begin());
  return B;
}

template <typename T, typename CNT = int>
vc<CNT> bincount(vc<T> &A, int size) {
  vc<CNT> C(size);
  for (auto &&x: A) { ++C[x]; }
  return C;
}

template <typename T>
vector<int> argsort(vector<T> &A) {
  

  vector<int> ids(A.size());
  iota(all(ids), 0);
  sort(all(ids),
       [&](int i, int j) { return A[i] < A[j] || (A[i] == A[j] && i < j); });
  return ids;
}
#line 1 "library/other/io.hpp"


#include <unistd.h>

namespace detail {
template <typename T, decltype(&T::is_modint) = &T::is_modint>
std::true_type check_value(int);
template <typename T>
std::false_type check_value(long);
} 


template <typename T>
struct is_modint : decltype(detail::check_value<T>(0)) {};
template <typename T>
using is_modint_t = enable_if_t<is_modint<T>::value>;
template <typename T>
using is_not_modint_t = enable_if_t<!is_modint<T>::value>;

struct Scanner {
  FILE* fp;
  char line[(1 << 15) + 1];
  size_t st = 0, ed = 0;
  void reread() {
    memmove(line, line + st, ed - st);
    ed -= st;
    st = 0;
    ed += fread(line + ed, 1, (1 << 15) - ed, fp);
    line[ed] = '\0';
  }
  bool succ() {
    while (true) {
      if (st == ed) {
        reread();
        if (st == ed) return false;
      }
      while (st != ed && isspace(line[st])) st++;
      if (st != ed) break;
    }
    if (ed - st <= 50) {
      bool sep = false;
      for (size_t i = st; i < ed; i++) {
        if (isspace(line[i])) {
          sep = true;
          break;
        }
      }
      if (!sep) reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_same<T, string>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    while (true) {
      size_t sz = 0;
      while (st + sz < ed && !isspace(line[st + sz])) sz++;
      ref.append(line + st, sz);
      st += sz;
      if (!sz || st != ed) break;
      reread();
    }
    return true;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  bool read_single(T &ref) {
    if (!succ()) return false;
    bool neg = false;
    if (line[st] == '-') {
      neg = true;
      st++;
    }
    ref = T(0);
    while (isdigit(line[st])) { ref = 10 * ref + (line[st++] & 0xf); }
    if (neg) ref = -ref;
    return true;
  }
  template <class T, is_modint_t<T> * = nullptr>
  bool read_single(T &ref) {
    long long val = 0;
    bool f = read_single(val);
    ref = T(val);
    return f;
  }
  bool read_single(double &ref) {
    string s;
    if (!read_single(s)) return false;
    ref = std::stod(s);
    return true;
  }
  template <class T>
  bool read_single(vector<T> &ref) {
    for (auto &d: ref) {
      if (!read_single(d)) return false;
    }
    return true;
  }
  template <class T, class U>
  bool read_single(pair<T, U> &p) {
    return (read_single(p.first) && read_single(p.second));
  }
  template <class A, class B, class C>
  bool read_single(tuple<A, B, C> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)));
  }
  template <class A, class B, class C, class D>
  bool read_single(tuple<A, B, C, D> &p) {
    return (read_single(get<0>(p)) && read_single(get<1>(p))
            && read_single(get<2>(p)) && read_single(get<3>(p)));
  }
  void read() {}
  template <class H, class... T>
  void read(H &h, T &... t) {
    bool f = read_single(h);
    assert(f);
    read(t...);
  }
  Scanner(FILE *fp) : fp(fp) {}
};

struct Printer {
  Printer(FILE *_fp) : fp(_fp) {}
  ~Printer() { flush(); }

  static constexpr size_t SIZE = 1 << 15;
  FILE *fp;
  char line[SIZE], small[50];
  size_t pos = 0;
  void flush() {
    fwrite(line, 1, pos, fp);
    pos = 0;
  }
  void write(const char &val) {
    if (pos == SIZE) flush();
    line[pos++] = val;
  }
  template <class T, enable_if_t<is_integral<T>::value, int> = 0>
  void write(T val) {
    if (pos > (1 << 15) - 50) flush();
    if (val == 0) {
      write('0');
      return;
    }
    if (val < 0) {
      write('-');
      val = -val; 

    }
    size_t len = 0;
    while (val) {
      small[len++] = char(0x30 | (val % 10));
      val /= 10;
    }
    for (size_t i = 0; i < len; i++) { line[pos + i] = small[len - 1 - i]; }
    pos += len;
  }
  void write(const string &s) {
    for (char c: s) write(c);
  }
  void write(const char *s) {
    size_t len = strlen(s);
    for (size_t i = 0; i < len; i++) write(s[i]);
  }
  void write(const double &x) {
    ostringstream oss;
    oss << setprecision(12) << x;
    string s = oss.str();
    write(s);
  }
  template <class T, is_modint_t<T> * = nullptr>
  void write(T &ref) {
    write(ref.val);
  }
  template <class T>
  void write(const vector<T> &val) {
    auto n = val.size();
    for (size_t i = 0; i < n; i++) {
      if (i) write(' ');
      write(val[i]);
    }
  }
  template <class T, class U>
  void write(const pair<T, U> &val) {
    write(val.first);
    write(' ');
    write(val.second);
  }
};

Scanner scanner = Scanner(stdin);
Printer printer = Printer(stdout);

void flush() { printer.flush(); }
void print() { printer.write('\n'); }
template <class Head, class... Tail>
void print(Head &&head, Tail &&... tail) {
  printer.write(head);
  if (sizeof...(Tail)) printer.write(' ');
  print(forward<Tail>(tail)...);
}

void read() {}
template <class Head, class... Tail>
void read(Head &head, Tail &... tail) {
  scanner.read(head);
  read(tail...);
}

#define INT(...)   \
  int __VA_ARGS__; \
  read(__VA_ARGS__)
#define LL(...)   \
  ll __VA_ARGS__; \
  read(__VA_ARGS__)
#define STR(...)      \
  string __VA_ARGS__; \
  read(__VA_ARGS__)
#define DBL(...)           \
  double __VA_ARGS__; \
  read(__VA_ARGS__)

#define VEC(type, name, size) \
  vector<type> name(size);    \
  read(name)
#define VV(type, name, h, w)                     \
  vector<vector<type>> name(h, vector<type>(w)); \
  read(name)

void YES(bool t = 1) { print(t ? "YES" : "NO"); }
void NO(bool t = 1) { YES(!t); }
void Yes(bool t = 1) { print(t ? "Yes" : "No"); }
void No(bool t = 1) { Yes(!t); }
void yes(bool t = 1) { print(t ? "yes" : "no"); }
void no(bool t = 1) { yes(!t); }
#line 2 "library/nt/primetest.hpp"
struct m64 {
    using i64 = int64_t;
    using u64 = uint64_t;
    using u128 = __uint128_t;

    inline static u64 m, r, n2; 

    static void set_mod(u64 m) {
        assert(m < (1ull << 62));
        assert((m & 1) == 1);
        m64::m = m;
        n2 = -u128(m) % m;
        r = m;
        FOR (_, 5) r *= 2 - m*r;
        r = -r;
        assert(r * m == -1ull);
    }
    static u64 reduce(u128 b) { return (b + u128(u64(b) * r) * m) >> 64; }

    u64 x;
    m64() : x(0) {}
    m64(u64 x) : x(reduce(u128(x) * n2)){};
    u64 val() const { u64 y = reduce(x); return y >= m ? y-m : y; }
    m64 &operator+=(m64 y) {
        x += y.x - (m << 1);
        x = (i64(x) < 0 ? x + (m << 1) : x);
        return *this;
    }
    m64 &operator-=(m64 y) {
        x -= y.x;
        x = (i64(x) < 0 ? x + (m << 1) : x);
        return *this;
    }
    m64 &operator*=(m64 y) { x = reduce(u128(x) * y.x); return *this; }
    m64 operator+(m64 y) const { return m64(*this) += y; }
    m64 operator-(m64 y) const { return m64(*this) -= y; }
    m64 operator*(m64 y) const { return m64(*this) *= y; }
    bool operator==(m64 y) const { return (x >= m ? x-m : x) == (y.x >= m ? y.x-m : y.x); }
    bool operator!=(m64 y) const { return not operator==(y); }
    m64 pow(u64 n) const {
        m64 y = 1, z = *this;
        for ( ; n; n >>= 1, z *= z) if (n & 1) y *= z;
        return y;
    }
};

bool primetest(const uint64_t x) {
    using u64 = uint64_t;
    if (x == 2 or x == 3 or x == 5 or x == 7) return true;
    if (x % 2 == 0 or x % 3 == 0 or x % 5 == 0 or x % 7 == 0) return false;
    if (x < 121) return x > 1;
    const u64 d = (x-1) >> __builtin_ctzll(x-1);
    m64::set_mod(x);
    const m64 one(1), minus_one(x-1);
    auto ok = [&](u64 a) {
        auto y = m64(a).pow(d);
        u64 t = d;
        while (y != one and y != minus_one and t != x-1) y *= y, t <<= 1;
        if (y != minus_one and t % 2 == 0) return false;
        return true;
    };
    if (x < (1ull << 32)) {
        for (u64 a : { 2, 7, 61 }) if (not ok(a)) return false;
    } else {
        for (u64 a : { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 }) {
            if (x <= a) return true;
            if (not ok(a)) return false;
        }
    }
    return true;
}
#line 3 "library/nt/factor.hpp"

mt19937_64 rng_mt{random_device{}()};
ll rnd(ll n) { return uniform_int_distribution<ll>(0, n - 1)(rng_mt); }

ll rho(ll n, ll c) {
  m64::set_mod(n);
  assert(n > 1);
  const m64 cc(c);
  auto f = [&](m64 x) { return x * x + cc; };
  m64 x = 1, y = 2, z = 1, q = 1;
  ll g = 1;
  const ll m = 1LL << (__lg(n) / 5); 

  for (ll r = 1; g == 1; r <<= 1) {
    x = y;
    FOR(_, r) y = f(y);
    for (ll k = 0; k < r and g == 1; k += m) {
      z = y;
      FOR(_, min(m, r - k)) y = f(y), q *= x - y;
      g = gcd(q.val(), n);
    }
  }
  if (g == n)
    do {
      z = f(z);
      g = gcd((x - z).val(), n);
    } while (g == 1);
  return g;
}

ll find_prime_factor(ll n) {
  assert(n > 1);
  if (primetest(n))
    return n;
  FOR(_, 100) {
    ll m = rho(n, rnd(n));
    if (primetest(m))
      return m;
    n = m;
  }
  cerr << "failed" << endl;
  assert(false);
  return -1;
}

vc<pi> factor(ll n) {
  assert(n >= 1);
  vc<pi> pf;
  FOR3(p, 2, 100) {
    if (p * p > n)
      break;
    if (n % p == 0) {
      ll e = 0;
      do {
        n /= p, e += 1;
      } while (n % p == 0);
      pf.eb(p, e);
    }
  }
  while (n > 1) {
    ll p = find_prime_factor(n);
    ll e = 0;
    do {
      n /= p, e += 1;
    } while (n % p == 0);
    pf.eb(p, e);
  }
  sort(all(pf));
  return pf;
}
#line 1 "library/ds/fastset.hpp"
struct FastSet {
  using uint = unsigned;
  using ull = unsigned long long;

  int bsr(ull x) { return 63 - __builtin_clzll(x); }
  int bsf(ull x) { return __builtin_ctzll(x); }

  static constexpr uint B = 64;
  int n, lg;
  vc<vc<ull>> seg;
  FastSet(int _n) : n(_n) {
    do {
      seg.push_back(vc<ull>((_n + B - 1) / B));
      _n = (_n + B - 1) / B;
    } while (_n > 1);
    lg = int(seg.size());
  }
  bool operator[](int i) const { return (seg[0][i / B] >> (i % B) & 1) != 0; }
  void insert(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] |= 1ULL << (i % B);
      i /= B;
    }
  }
  void erase(int i) {
    for (int h = 0; h < lg; h++) {
      seg[h][i / B] &= ~(1ULL << (i % B));
      if (seg[h][i / B])
        break;
      i /= B;
    }
  }
  

  int next(int i) {
    for (int h = 0; h < lg; h++) {
      if (i / B == seg[h].size())
        break;
      ull d = seg[h][i / B] >> (i % B);
      if (!d) {
        i = i / B + 1;
        continue;
      }
      

      i += bsf(d);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsf(seg[g][i / B]);
      }
      return i;
    }
    return n;
  }
  

  int prev(int i) {
    if(i < 0) return -1;
    chmin(i, n - 1);
    for (int h = 0; h < lg; h++) {
      if (i == -1)
        break;
      ull d = seg[h][i / B] << (63 - i % 64);
      if (!d) {
        i = i / B - 1;
        continue;
      }
      

      i += bsr(d) - (B - 1);
      for (int g = h - 1; g >= 0; g--) {
        i *= B;
        i += bsr(seg[g][i / B]);
      }
      return i;
    }
    return -1;
  }
  void debug(){
    string s;
    FOR(i, n) s += ((*this)[i] ? '1' : '0');
    print(s);
  }
};
#line 6 "main.cpp"

void solve() {
  LL(N);
  VEC(ll, A, N);
  A.insert(A.begin(), -2);
  A.insert(A.begin(), -1);
  A.eb(-4);
  A.eb(-3);
  N = len(A);
  auto key = A;
  UNIQUE(key);
  for (auto&& a: A) a = LB(key, a);

  ll ANS = 0;

  auto calc = [&]() -> void {
    ll p = max_element(all(A)) - A.begin();
    vi B = {A.begin(), A.begin() + p};
    ll a = 0, b = 0;
    {
      vi lo, hi;
      FOR3_R(i, p, len(A)) {
        if (len(hi) == 0 || hi.back() < A[i]) hi.eb(A[i]);
        elif (len(lo) == 0 || lo.back() < A[i]) lo.eb(A[i]);
        else return;
      }
      

      

      a = lo.back(), b = hi.back();
    }
    

    vi LO(len(B), -1), HI(len(B), -1);
    {
      vi lo, hi;
      FOR(i, p) {
        if (len(hi) == 0 || hi.back() < B[i]) hi.eb(B[i]);
        elif (len(lo) == 0 || lo.back() < B[i]) lo.eb(B[i]);
        else break;
        LO[i] = (lo.empty() ? -1 : lo.back());
        HI[i] = (hi.empty() ? -1 : hi.back());
      }
    }

    

    vi dec = {b}, inc = {a};
    FOR3_R(i, 2, p) {
      if (LO[i] != -1 && HI[i] != -1) {
        

        ll b = B[i], c = B[i] ^ LO[i] ^ HI[i];
        if (inc.back() < b) {
          if (dec.back() > c) ++ANS;
          

        }
      }

      ll now = B[i];
      ll nxt = B[i - 1];
      bool ok1 = dec.back() > now;
      bool ok2 = inc.back() < now;
      if (ok1 && !ok2) {
        dec.eb(now);
        continue;
      }
      if (!ok1 && ok2) {
        inc.eb(now);
        continue;
      }
      if (!ok1 && !ok2) break;
      if (nxt < now)
        dec.eb(now);
      else
        inc.eb(now);
    }
  };

  FOR_(2) {
    reverse(all(A));
    

    calc();
  }
  print(ANS);
}

signed main() {
  

  ll T = 1;
  FOR_(T) solve();
}