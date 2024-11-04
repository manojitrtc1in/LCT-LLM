#define LOCAL
#define _USE_MATH_DEFINES
#include <array>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <complex>
#include <cmath>
#include <numeric>
#include <bitset>
#include <functional>
#include <random>
#include <ctime>

using namespace std;

template <typename A, typename B>
ostream& operator <<(ostream& out, const pair<A, B>& a) {
  out << "(" << a.first << "," << a.second << ")";
  return out;
}
template <typename T, size_t N>
ostream& operator <<(ostream& out, const array<T, N>& a) {
  out << "["; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T>
ostream& operator <<(ostream& out, const vector<T>& a) {
  out << "["; bool first = true;
  for (auto v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "]";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const set<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename T, class Cmp>
ostream& operator <<(ostream& out, const multiset<T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& v : a) { out << (first ? "" : ", "); out << v; first = 0;} out << "}";
  return out;
}
template <typename U, typename T, class Cmp>
ostream& operator <<(ostream& out, const map<U, T, Cmp>& a) {
  out << "{"; bool first = true;
  for (auto& p : a) { out << (first ? "" : ", "); out << p.first << ":" << p.second; first = 0;} out << "}";
  return out;
}
#ifdef LOCAL
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
#else
#define trace(...) 42
#endif
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << ": " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << ": " << arg1 << " |";
  __f(comma + 1, args...);
}

template <class T> auto vect(const T& v, int n) { return vector<T>(n, v); }
template <class T, class... D> auto vect(const T& v, int n, D... m) {
  return vector<decltype(vect(v, m...))>(n, vect(v, m...));
}

using int64 = long long;
using int128 = __int128_t;
using ii = pair<int, int>;
#define SZ(x) (int)((x).size())
template <typename T> static constexpr T inf = numeric_limits<T>::max() / 2;


const int MOD = 998244353;
mt19937_64 mrand(random_device{}());
int64 rnd(int64 x) { return mrand() % x; }
int lg2(int64 x) { return sizeof(int64) * 8 - 1 - __builtin_clzll(x); }
template <class T> void out(const vector<T>& a) { for (int i = 0; i < SZ(a); ++i) cout << a[i] << " \n"[i + 1 == SZ(a)]; }
template <class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template <class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template <class T> void dedup(vector<T>& v) { sort(v.begin(), v.end()); v.erase(unique(v.begin(), v.end()), v.end()); }
void add_mod(int& x, int y) { x += y; if (x >= MOD) x -= MOD; }
void sub_mod(int& x, int y) { x += MOD - y; if (x >= MOD) x -= MOD; }

struct fast_ios {
  fast_ios() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
  };
} fast_ios_;

int64 power_mod(int64 a, int64 n, int p = MOD) {
  int64 ret = 1;
  a %= p;
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * a % p;
    a = a * a % p;
  }
  return ret;
}

const int N = 1e5 + 10;
int fact[N], ifact[N], reciprocal[N];

struct comb_init {
  comb_init() {
    reciprocal[1] = 1;
    for (int i = 2; i < N; ++i) {
      reciprocal[i] = (MOD - MOD / i) * (int64)reciprocal[MOD % i] % MOD;
    }
    fact[0] = ifact[0] = 1;
    for (int i = 1; i < N; ++i) {
      fact[i] = (int64)fact[i - 1] * i % MOD;
      ifact[i] = (int64)ifact[i - 1] * reciprocal[i] % MOD;
    }
  }
} comb_init_;

int64 comb(int64 n, int64 m) {
  if (n < m || m < 0) return 0;
  return (int64)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}









int lagrange(const vector<int>& a, int n) {
  int m = a.size();
  if (n < m) return a[n];
  int64 ret = 0;
  for (int i = 0; i < m; ++i) {
    int64 cur = (int64)ifact[i] * ifact[m - 1 - i] % MOD *
      power_mod(n + MOD - i, MOD - 2) % MOD * a[i] % MOD;
    if ((m - 1 - i) % 2) cur = MOD - cur;
    ret += cur;
  }
  ret %= MOD;
  for (int i = 0; i < m; ++i) ret = ret * (n + MOD - i) % MOD;
  return ret;
}


typedef int atom;
const int G = 3;

int64 inv_mod(int64 a) {
  return power_mod(a, MOD - 2);
}

void bit_reverse(vector<atom>& a) {
  int n = a.size();
  for (int i = 1, j = n / 2; i < n - 1; ++i) {
    if (i < j) swap(a[i], a[j]);
    int k = n / 2;
    while (j >= k) j -= k, k /= 2;
    if (j < k) j += k;
  }
}

void fft(vector<atom>& a, int flag) {
  int n = a.size();
  bit_reverse(a);
  vector<atom> wn(n);
  wn[0] = 1;
  wn[1] = power_mod(G, flag == 1 ? (MOD - 1) / n : MOD - 1 - (MOD - 1) / n);
  for (int i = 2; i < n; ++i) wn[i] = (int64)wn[i - 1] * wn[1] % MOD;
  for (int k = 2; k <= n; k <<= 1) {
    for (int i = 0; i < n; i += k) {
      int wi = 0, step = n / k;
      for (int j = i; j < i + k / 2; ++j) {
        atom u = a[j];
        atom v = (int64)wn[wi] * a[j + k / 2] % MOD;
        a[j] = (u + v) % MOD;
        a[j + k / 2] = (u + MOD - v) % MOD;
        wi += step;
      }
    }
  }
  if (flag < 0) {
    int64 inv_n = inv_mod(n);
    for (int i = 0; i < n; ++i) a[i] = a[i] * inv_n % MOD;
  }
}

namespace polynomial {

vector<int> mul(const vector<int>& f, const vector<int>& g, int cap = inf<int>) {
  int n = f.size(), m = g.size();
  int len = 1;
  while (len < n + m - 1) len <<= 1;
  vector<atom> x(len), y(len);
  copy(f.begin(), f.end(), x.begin());
  copy(g.begin(), g.end(), y.begin());
  fft(x, 1);
  fft(y, 1);
  for (int i = 0; i < len; ++i) x[i] = (int64)x[i] * y[i] % MOD;
  fft(x, -1);
  cap = min(cap, n + m - 1);
  x.resize(cap);
  return x;
}

vector<int> differential(const vector<int>& f) {
  int n = f.size();
  vector<int> ret(n);
  for (int i = 0; i < n - 1; ++i) ret[i] = (int64)f[i + 1] * (i + 1) % MOD;
  return ret;
}

void integral(vector<int>& f) {
  int n = f.size();
  for (int i = n - 1; i > 0; --i) f[i] = inv_mod(i) * f[i - 1] % MOD;
  f[0] = 0;
}



vector<int> inverse(const vector<int>& f) {
  int n = f.size();
  if (n == 1) return {(int)inv_mod(f[0])};
  vector<int> f1(f.begin(), f.begin() + (n >> 1));
  auto g = inverse(f1);
  g.resize(n);
  auto h = mul(f, g, n);
  h[0] = (2 + MOD - h[0]) % MOD;
  for (int i = 1; i < h.size(); ++i) h[i] = (MOD - h[i]) % MOD;
  return mul(h, g, n);
}

pair<vector<int>, vector<int>> div(const vector<int>& f, const vector<int>& g) {
  int n = f.size(), m = g.size();
  int k = n - m + 1;
  if (n < m) return make_pair(vector<int>{0}, f);
  int len = 1;
  while (len < m) len <<= 1;
  vector<int> fr(n), gr(len);
  copy(f.rbegin(), f.rend(), fr.begin());
  copy(g.rbegin(), g.rend(), gr.begin());
  auto h = inverse(gr);
  h = mul(fr, h);
  vector<int> d(k);
  for (int i = 0; i < k; ++i) d[i] = h[k - 1 - i];
  h = mul(g, d);
  vector<int> r(m);
  for (int i = 0; i < m; ++i) r[i] = (f[i] + MOD - h[i]) % MOD;
  int deg_r = m - 1;
  while (deg_r && r[deg_r] == 0) --deg_r;
  r.resize(deg_r + 1);
  return make_pair(d, r);
}

int64 W;
ii operator *(const ii& u, const ii& v) {
  return {((int64)u.first * v.first + (int64)u.second * v.second % MOD * W) % MOD,
          ((int64)u.first * v.second + (int64)u.second * v.first) % MOD};
}

ii power_mod(ii a, int64 n) {
  ii ret = {1, 0};
  for (; n; n >>= 1) {
    if (n & 1) ret = ret * a;
    a = a * a;
  }
  return ret;
}

int cipolla(int x) {
  int y;
  while (true) {
    y = rnd(MOD);
    W = ((int64)y * y % MOD + MOD - x) % MOD;
    if (::power_mod(W, (MOD - 1) / 2) > 1) break;
  }
  ii ret(y, 1);
  ret = power_mod(ret, (MOD + 1) / 2);
  return min(ret.first, MOD - ret.first);
}



vector<int> sqrt(const vector<int>& f) {
  int n = f.size();
  if (n == 1) return {cipolla(f[0])};
  vector<int> f1(f.begin(), f.begin() + (n >> 1));
  auto g = sqrt(f1);
  g.resize(n);
  auto h = inverse(g);
  h = mul(f, h, n);
  int64 inv2 = inv_mod(2);
  for (int i = 0; i < n; ++i) g[i] = (g[i] + h[i]) * inv2 % MOD;
  return g;
}



vector<int> log(const vector<int>& f) {
  auto g = differential(f);
  auto h = inverse(f);
  auto ret = mul(g, h);
  ret.resize(f.size());
  integral(ret);
  return ret;
}



vector<int> exp(const vector<int>& f) {
  int n = f.size();
  if (n == 1) return vector<int>{1};
  vector<int> f1(f.begin(), f.begin() + (n >> 1));
  auto g = exp(f1);
  g.resize(n);
  auto h = log(g);
  for (int i = 0; i < n; ++i) h[i] = ((i == 0) + f[i] + MOD - h[i]) % MOD;
  return mul(g, h, n);
}
}

using namespace polynomial;

template <uint32_t mod>
struct LazyMontgomeryModInt {
  using mint = LazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static constexpr u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static constexpr u32 r = get_r();
  static constexpr u32 n2 = -u64(mod) % mod;
  static_assert(r * mod == 1, "invalid, r * mod != 1");
  static_assert(mod < (1 << 30), "invalid, mod >= 2 ^ 30");
  static_assert((mod & 1) == 1, "invalid, mod % 2 == 0");

  u32 a;

  constexpr LazyMontgomeryModInt() : a(0) {}
  constexpr LazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static constexpr u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  constexpr mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  constexpr mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  constexpr mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  constexpr mint operator+(const mint &b) const { return mint(*this) += b; }
  constexpr mint operator-(const mint &b) const { return mint(*this) -= b; }
  constexpr mint operator*(const mint &b) const { return mint(*this) *= b; }
  constexpr mint operator/(const mint &b) const { return mint(*this) /= b; }
  constexpr bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  constexpr mint operator-() const { return mint() - mint(*this); }

  constexpr mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  constexpr mint inverse() const { return pow(mod - 2); }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = LazyMontgomeryModInt<mod>(t);
    return (is);
  }

  constexpr u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static constexpr u32 get_mod() { return mod; }
};

template <typename mint>
struct NTT {
  static constexpr uint32_t get_pr() {
    uint32_t _mod = mint::get_mod();
    using u64 = uint64_t;
    u64 ds[32] = {};
    int idx = 0;
    u64 m = _mod - 1;
    for (u64 i = 2; i * i <= m; ++i) {
      if (m % i == 0) {
        ds[idx++] = i;
        while (m % i == 0) m /= i;
      }
    }
    if (m != 1) ds[idx++] = m;

    uint32_t _pr = 2;
    while (1) {
      int flg = 1;
      for (int i = 0; i < idx; ++i) {
        u64 a = _pr, b = (_mod - 1) / ds[i], r = 1;
        while (b) {
          if (b & 1) r = r * a % _mod;
          a = a * a % _mod;
          b >>= 1;
        }
        if (r == 1) {
          flg = 0;
          break;
        }
      }
      if (flg == 1) break;
      ++_pr;
    }
    return _pr;
  };

  static constexpr uint32_t mod = mint::get_mod();
  static constexpr uint32_t pr = get_pr();
  static constexpr int level = __builtin_ctzll(mod - 1);
  mint dw[level], dy[level];

  void setwy(int k) {
    mint w[level], y[level];
    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
    y[k - 1] = w[k - 1].inverse();
    for (int i = k - 2; i > 0; --i)
      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
    for (int i = 3; i < k; ++i) {
      dw[i] = dw[i - 1] * y[i - 2] * w[i];
      dy[i] = dy[i - 1] * w[i - 2] * y[i];
    }
  }

  NTT() { setwy(level); }

  void fft4(vector<mint> &a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        mint ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] += ajv;
      }
    }
    int u = 1 << (2 + (k & 1));
    int v = 1 << (k - 2 - (k & 1));
    mint one = mint(1);
    mint imag = dw[1];
    while (v) {
      

      {
        int j0 = 0;
        int j1 = v;
        int j2 = j1 + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j1] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j3] = t0m2 - t1m3;
        }
      }
      

      mint ww = one, xx = one * dw[2], wx = one;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, wx = ww * xx;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v] * xx, t2 = a[j2] * ww,
               t3 = a[j2 + v] * wx;
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[j0] = t0p2 + t1p3, a[j0 + v] = t0p2 - t1p3;
          a[j2] = t0m2 + t1m3, a[j2 + v] = t0m2 - t1m3;
        }
        xx *= dw[__builtin_ctzll((jh += 4))];
      }
      u <<= 2;
      v >>= 2;
    }
  }

  void ifft4(vector<mint> &a, int k) {
    if ((int)a.size() <= 1) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    mint one = mint(1);
    mint imag = dy[1];
    while (u) {
      

      {
        int j0 = 0;
        int j1 = v;
        int j2 = v + v;
        int j3 = j2 + v;
        for (; j0 < v; ++j0, ++j1, ++j2, ++j3) {
          mint t0 = a[j0], t1 = a[j1], t2 = a[j2], t3 = a[j3];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = t0 - t1, t2m3 = (t2 - t3) * imag;
          a[j0] = t0p1 + t2p3, a[j2] = t0p1 - t2p3;
          a[j1] = t0m1 + t2m3, a[j3] = t0m1 - t2m3;
        }
      }
      

      mint ww = one, xx = one * dy[2], yy = one;
      u <<= 2;
      for (int jh = 4; jh < u;) {
        ww = xx * xx, yy = xx * imag;
        int j0 = jh * v;
        int je = j0 + v;
        int j2 = je + v;
        for (; j0 < je; ++j0, ++j2) {
          mint t0 = a[j0], t1 = a[j0 + v], t2 = a[j2], t3 = a[j2 + v];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[j0] = t0p1 + t2p3, a[j2] = (t0p1 - t2p3) * ww;
          a[j0 + v] = t0m1 + t2m3, a[j2 + v] = (t0m1 - t2m3) * ww;
        }
        xx *= dy[__builtin_ctzll(jh += 4)];
      }
      u >>= 4;
      v <<= 2;
    }
    if (k & 1) {
      u = 1 << (k - 1);
      for (int j = 0; j < u; ++j) {
        mint ajv = a[j] - a[j + u];
        a[j] += a[j + u];
        a[j + u] = ajv;
      }
    }
  }

  void ntt(vector<mint> &a) {
    if ((int)a.size() <= 1) return;
    fft4(a, __builtin_ctz(a.size()));
  }

  void intt(vector<mint> &a) {
    if ((int)a.size() <= 1) return;
    ifft4(a, __builtin_ctz(a.size()));
    mint iv = mint(a.size()).inverse();
    for (auto &x : a) x *= iv;
  }

  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    int l = a.size() + b.size() - 1;
    if (min<int>(a.size(), b.size()) <= 40) {
      vector<mint> s(l);
      for (int i = 0; i < (int)a.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];
      return s;
    }
    int k = 2, M = 4;
    while (M < l) M <<= 1, ++k;
    setwy(k);
    vector<mint> s(M), t(M);
    for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i];
    for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i];
    fft4(s, k);
    fft4(t, k);
    for (int i = 0; i < M; ++i) s[i] *= t[i];
    ifft4(s, k);
    s.resize(l);
    mint invm = mint(M).inverse();
    for (int i = 0; i < l; ++i) s[i] *= invm;
    return s;
  }

  void ntt_doubling(vector<mint> &a) {
    int M = (int)a.size();
    auto b = a;
    intt(b);
    mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));
    for (int i = 0; i < M; i++) b[i] *= r, r *= zeta;
    ntt(b);
    copy(begin(b), end(b), back_inserter(a));
  }
};

using mint = LazyMontgomeryModInt<998244353>;
using vm = vector<mint>;
NTT<mint> ntt;

vm convolution998244353_large(const vm &a, const vm &b) {
  int len = 1 << 23;
  if ((int)a.size() + (int)b.size() - 1 <= len) return ntt.multiply(a, b);
  if (a.empty() || b.empty()) return vm(max<int>(0, a.size() + b.size() - 1));
  vector<vm> as, bs;
  for (int i = 0; i < (int)a.size(); i += len / 2) {
    vm v{begin(a) + i, begin(a) + min<int>(i + len / 2, a.size())};
    v.resize(len);
    ntt.ntt(v);
    as.push_back(v);
  }
  for (int i = 0; i < (int)b.size(); i += len / 2) {
    vm v{begin(b) + i, begin(b) + min<int>(i + len / 2, b.size())};
    v.resize(len);
    ntt.ntt(v);
    bs.push_back(v);
  }
  vector<vm> cs(as.size() + bs.size() - 1, vm(len));
  for (int i = 0; i < (int)as.size(); i++) {
    for (int j = 0; j < (int)bs.size(); j++) {
      for (int k = 0; k < len; k++) {
        cs[i + j][k] += as[i][k] * bs[j][k];
      }
    }
  }
  for (auto &v : cs) ntt.intt(v);

  vector<mint> c(a.size() + b.size() - 1);
  for (int i = 0; i < (int)cs.size(); i++) {
    int offset = len / 2 * i;
    int je = min<int>(len, c.size() - offset);
    for (int j = 0; j < je; j++) {
      c[j + offset] += cs[i][j];
    }
  }
  return c;
}

const int K = 2000 + 10;
int main() {
  auto p = vect<int>(0, K, K);
  for (int i = 0; i < K; ++i) {
    p[i][0] = 1;
    for (int k = 1; k < K; ++k) {
      p[i][k] = 1LL * p[i][k - 1] * i % MOD;
    }
  }

  int cas;
  cin >> cas;
  

  while (cas--) {
    int n, m, k;
    cin >> n >> m >> k;
    

    if (m == 1) {
      cout << power_mod(n, k) << '\n';
      continue;
    }
    int t = m / 2, s = m - t;
    int u = s * power_mod(t, MOD - 2) % MOD;
    


    vector<mint> f(k + 1);
    for (int i = 0; i <= k; ++i) f[i] = i == 0 ? 1 : f[i - 1] * u;
    for (int i = 0; i <= k; ++i) f[i] = f[i] * p[i][k] * ifact[i];
    


    int iu = power_mod(1 + u, MOD - 2);
    vector<mint> g(k + 1);
    for (int i = 0; i <= k; ++i) g[i] = ifact[i];

    f = convolution998244353_large(f, g);
    f.resize(k + 1);
    


    vector<int> a(k + 1);
    for (int len = 0; len <= k; ++len) {
      a[len] = (f[len] * fact[len] * power_mod(iu, len)).get();
    }

    

    

    

    

    

    

    int ret = lagrange(a, n);
    ret = ret * power_mod(u + 1, n) % MOD;
    ret = ret * power_mod(t, n) % MOD;
    cout << ret << '\n';
  }

  return 0;
}
