


using namespace std;

constexpr int inf = 0x3f3f3f3f;
constexpr long long lnf = 0x3f3f3f3f3f3f3f3f;

namespace polynomial {
  
  constexpr int mod = 998244353, inv2 = (mod + 1) >> 1;
  
  __attribute__((__always_inline__)) __inline
  int add(int x, int y) { return (x += y) >= mod ? x - mod : x; }
  __attribute__((__always_inline__)) __inline
  void inc(int &x, int y) { (x += y) >= mod && (x -= mod); }
  __attribute__((__always_inline__)) __inline
  int sub(int x, int y) { return (x -= y) < 0 ? x + mod : x; }
  __attribute__((__always_inline__)) __inline
  void dec(int &x, int y) { (x -= y) < 0 && (x += mod); }
  __attribute__((__always_inline__)) __inline
  int mul(int x, int y) { return 1LL * x * y % mod; }
  int modpower(int x, long long y) {
    int res = 1;
    for (; y ; y >>= 1, x = mul(x, x))
      if (y & 1) res = mul(res, x);
    return res;
  }
  int inv(int a) {
    if ((a %= mod) < 0) a += mod;
    int b = mod, u = 0, v = 1;
    while (a) {
      int t = b / a;
      b -= t * a;
      swap(a, b);
      u -= t * v;
      swap(u, v);
    }
    if (u < 0) u += mod;
    return u;
  }

  using poly = vector<int>;

  namespace ntt {
    int G = -1, base = 1, max_base = -1;
    poly rev = {0, 1}, roots = {0, 1};
    void initialize() {
      int tmp = mod - 1;
      max_base = 0;
      while (tmp % 2 == 0) {
        tmp >>= 1;
        ++max_base;
      }
      G = 2;
      for (; ; ++G)
        if (modpower(G, 1 << max_base) == 1 && modpower(G, 1 << (max_base - 1)) != 1)
          break;
    }
    void make_base(int nbase) {
      if (max_base == -1) initialize();
      if (nbase <= base) return ;
      assert(nbase <= max_base);
      rev.resize(1 << nbase);
      roots.resize(1 << nbase);
      for (int i = 0; i < (1 << nbase); ++i)
        rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (nbase - 1));
      for (; base < nbase; ++base) {
        int z = modpower(G, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); ++i) {
          roots[i << 1] = roots[i];
          roots[i << 1 | 1] = mul(roots[i], z);
        }
      }
    }
    void id0(poly &a) {
      int n = (int)a.size();
      int zero = __builtin_ctz(n);
      make_base(zero);
      int shift = base - zero;
      register int i, j, k, x, y;
      for (i = 0; i < n; ++i)
        if (i < (rev[i] >> shift))
          swap(a[i], a[rev[i] >> shift]);
      for (i = 1; i < n; i <<= 1)
        for (j = 0; j < n; j += (i << 1)) {
          for (k = 0; k + 8 <= i; k += 8) {
            {
              x = a[j + (k + 0)], y = mul(a[j + (k + 0) + i], roots[i + (k + 0)]);
              a[j + (k + 0)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 0) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 1)], y = mul(a[j + (k + 1) + i], roots[i + (k + 1)]);
              a[j + (k + 1)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 1) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 2)], y = mul(a[j + (k + 2) + i], roots[i + (k + 2)]);
              a[j + (k + 2)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 2) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 3)], y = mul(a[j + (k + 3) + i], roots[i + (k + 3)]);
              a[j + (k + 3)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 3) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 4)], y = mul(a[j + (k + 4) + i], roots[i + (k + 4)]);
              a[j + (k + 4)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 4) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 5)], y = mul(a[j + (k + 5) + i], roots[i + (k + 5)]);
              a[j + (k + 5)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 5) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 6)], y = mul(a[j + (k + 6) + i], roots[i + (k + 6)]);
              a[j + (k + 6)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 6) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
            {
              x = a[j + (k + 7)], y = mul(a[j + (k + 7) + i], roots[i + (k + 7)]);
              a[j + (k + 7)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 7) + i] = (x - y < 0 ? x - y + mod : x - y);
            }
          }
          switch (i - k) {
            case 7:
              x = a[j + (k + 6)], y = mul(a[j + (k + 6) + i], roots[i + (k + 6)]);
              a[j + (k + 6)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 6) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 6:
              x = a[j + (k + 5)], y = mul(a[j + (k + 5) + i], roots[i + (k + 5)]);
              a[j + (k + 5)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 5) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 5:
              x = a[j + (k + 4)], y = mul(a[j + (k + 4) + i], roots[i + (k + 4)]);
              a[j + (k + 4)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 4) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 4:
              x = a[j + (k + 3)], y = mul(a[j + (k + 3) + i], roots[i + (k + 3)]);
              a[j + (k + 3)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 3) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 3:
              x = a[j + (k + 2)], y = mul(a[j + (k + 2) + i], roots[i + (k + 2)]);
              a[j + (k + 2)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 2) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 2:
              x = a[j + (k + 1)], y = mul(a[j + (k + 1) + i], roots[i + (k + 1)]);
              a[j + (k + 1)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 1) + i] = (x - y < 0 ? x - y + mod : x - y);
            case 1:
              x = a[j + (k + 0)], y = mul(a[j + (k + 0) + i], roots[i + (k + 0)]);
              a[j + (k + 0)] = (x + y >= mod ? x + y - mod : x + y);
              a[j + (k + 0) + i] = (x - y < 0 ? x - y + mod : x - y);
          }
        }
    }
    poly multiply(poly a, poly b) {
      int all = (int)a.size() + (int)b.size() - 1;
      int nbase = 0;
      while ((1 << nbase) < all) ++nbase;
      make_base(nbase);
      int sz = 1 << nbase;
      a.resize(sz), b.resize(sz);
      bool eql = (a == b);
      id0(a);
      if (eql) b = a;
      else id0(b);
      int invsz = inv(sz);
      for (int i = 0; i < sz; ++i)
        a[i] = mul(mul(a[i], b[i]), invsz);
      reverse(a.begin() + 1, a.end());
      id0(a);
      a.resize(all);
      return a;
    }
    poly poly_inv(poly a) {
      int n = (int)a.size();
      int m = (n + 1) >> 1;
      if (n == 1) return poly(1, inv(a[0]));
      poly b = poly_inv(poly(a.begin(), a.begin() + m));
      int all = n << 1, nbase = 0;
      while ((1 << nbase) < all) ++nbase;
      make_base(nbase);
      int sz = 1 << nbase;
      a.resize(sz), b.resize(sz);
      id0(a);
      id0(b);
      int invsz = inv(sz);
      for (int i = 0; i < sz; ++i)
        a[i] = mul(mul(sub(2, mul(a[i], b[i])), b[i]), invsz);
      reverse(a.begin() + 1, a.end());
      id0(a);
      a.resize(n);
      return a;
    }
    poly power(poly a, int k) { 

      int nbase = 0, org = (int)a.size();
      while ((1 << nbase) < org) ++nbase;
      ntt::make_base(nbase);
      int sz = 1 << nbase;
      a.resize(sz);
      ntt::id0(a);
      int invsz = inv(sz);
      for (int i = 0; i < sz; ++i)
        a[i] = mul(modpower(a[i], k), invsz);
      reverse(a.begin() + 1, a.end());
      ntt::id0(a);
      a.resize(org);
      return a;
    }
  }
  using ntt::multiply;
  using ntt::poly_inv;
  using ntt::power;
  
  poly &operator += (poly &a, const poly &b) {
    if (a.size() < b.size())
      a.resize((int)b.size());
    for (int i = 0; i < (int)b.size(); ++i)
      inc(a[i], b[i]);
    return a;
  }
  poly &operator -= (poly &a, const poly &b) {
    if (a.size() < b.size())
      a.resize((int)b.size());
    for (int i = 0; i < (int)b.size(); ++i)
      dec(a[i], b[i]);
    return a;
  }
  poly &operator *= (poly &a, const int &b) {
    for (int &i: a) i = mul(i, b);
    return a;
  }
  poly &operator *= (poly &a, const poly &b) {
    if (min<int>(a.size(), b.size()) < 128) {
      poly c = a;
      a.assign((int)c.size() + (int)b.size() - 1, 0);
      for (int i = 0; i < (int)c.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j)
          inc(a[i + j], mul(c[i], b[j]));
    }
    else
      a = multiply(a, b);
    return a;
  }
  poly &operator /= (poly &a, const poly &b) {
    int n = (int)a.size(), m = (int)b.size();
    if (n < m) a.clear();
    else {
      poly c = b;
      reverse(a.begin(), a.end());
      reverse(c.begin(), c.end());
      c.resize(n - m + 1);
      a *= poly_inv(c);
      a.erase(a.begin() + n - m + 1, a.end());
      reverse(a.begin(), a.end());
    }
    return a;
  }
  poly &operator %= (poly &a, const poly &b) {
    int n = a.size(), m = b.size();
    if (n >= m) {
      poly c = a;
      (c /= b) *= b;
      a.resize(m - 1);
      for (int i = 0; i < m - 1; ++i)
        dec(a[i], c[i]);
    }
    return a;
  }
  poly operator + (poly a, const poly &b) { return a += b; }
  poly operator - (poly a, const poly &b) { return a -= b; }
  poly operator * (poly a, const poly &b) { return a *= b; }
  poly operator / (poly a, const poly &b) { return a /= b; }
  poly operator % (poly a, const poly &b) { return a %= b; }
  poly operator - (poly a) { for (int &i: a) i = mod - i; return a; }
  poly operator * (poly a, int b) { return a *= b; }
  poly operator * (int b, poly a) { return a *= b; }
  poly derivative(const poly &a) {
    int n = (int)a.size();
    poly b(n - 1);
    for (int i = 1; i < n; ++i)
      b[i - 1] = mul(a[i], i);
    return b;
  }
  poly integral(const poly &a) {
    int n = (int)a.size();
    poly b(n + 1), invs(n + 1);
    for (int i = 1; i <= n; ++i) {
      invs[i] = (i == 1) ? 1 : mul(mod - mod / i, invs[mod % i]);
      b[i] = mul(a[i - 1], invs[i]);
    }
    return b;
  }
  
  poly poly_log(const poly &a) {
    poly b = integral(derivative(a) * poly_inv(a));
    b.resize((int)a.size());
    return b;
  }
  poly poly_exp(const poly &a) {
    poly b(1, 1);
    while (b.size() < a.size()) {
      poly c(a.begin(), a.begin() + min<int>(a.size(), b.size() << 1));
      inc(c[0], 1);
      poly d = b;
      b.resize((int)b.size() << 1);
      c -= poly_log(b);
      c *= d;
      for (int i = (int)b.size() >> 1; i < (int)b.size(); ++i)
        b[i] = c[i];
    }
    b.resize((int)a.size());
    return b;
  }
  poly poly_pow(const poly &a, int k) {
    int n = (int)a.size(), p = -1;
    poly b(n);
    for (int i = 0; i < n; ++i)
      if (a[i]) { p = i; break; }
    if (p == -1) { b[0] = !k; return b; }
    if (1LL * k * p >= n) return b;
    int ku = modpower(a[p], k), di = inv(a[p]);
    int sz = n - k * p;
    poly c(sz);
    for (int i = 0; i < sz; ++i)
      c[i] = mul(a[i + p], di);
    c = poly_log(c);
    for (int i = 0; i < sz; ++i)
      c[i] = mul(c[i], k);
    c = poly_exp(c);
    for (int i = 0; i < sz; ++i)
      b[i + k * p] = mul(c[i], ku);
    return b;
  }
  poly id1(const poly &a) {
    poly b(1, 1);
    while (b.size() < a.size()) {
      poly c(a.begin(), a.begin() + min<int>(a.size(), b.size() << 1));
      poly d = b;
      b.resize((int)b.size() << 1);
      c *= poly_inv(b);
      for (int i = (int)b.size() >> 1; i < (int)b.size(); ++i)
        b[i] = mul(c[i], inv2);
    }
    b.resize(a.size());
    return b;
  }
  
}
using namespace polynomial;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  cout << fixed << setprecision(12);
  int n;
  long long m;
  cin >> n >> m;
  poly p(n + 1);
  for (int &i: p) cin >> i;
  poly a(n + 1), b(n + 1), c(n + 1), d(n + 1);
  poly fact(n + 1);
  fact[0] = 1;
  for (int i = 1; i <= n; ++i)
    fact[i] = mul(fact[i - 1], i);
  for (int i = 0; i <= n; ++i) {
    a[i] = inv(fact[i]);
    b[i] = mul(fact[n - i], p[n - i]);
    c[i] = (i % 2 == 0) ? a[i] : mod - a[i];
  }
  poly g = a * b;
  g.resize(n + 1);
  reverse(g.begin(), g.end());
  for (int i = 0; i <= n; ++i)
    g[i] = mul(g[i], inv(fact[i]));
  for (int i = 0; i <= n; ++i) {
    int k = modpower(i + 1, m);
    g[i] = mul(g[i], inv(k));
  }
  for (int i = 0; i <= n; ++i)
    d[i] = mul(fact[n - i], g[n - i]);
  poly f = c * d;
  f.resize(n + 1);
  reverse(f.begin(), f.end());
  for (int i = 0; i <= n; ++i)
    f[i] = mul(f[i], inv(fact[i]));
  for (int i = 0; i <= n; ++i)
    cout << f[i] << " \n"[i == n];
  return 0;
}