#include <bits/stdc++.h>

using ll = long long;

using namespace std;

const int mod = 998244353, G = 3;
int norm(int x) { return x >= mod ? x - mod : x; }
int reduce(int x) { return x < 0 ? x + mod : x; }
int neg(int x) { return x ? mod - x : 0; }
void add(int &x, int y) { if ((x += y - mod) < 0) x += mod; }
void sub(int &x, int y) { if ((x -= y) < 0) x += mod; }
void fam(int &x, int y, int z) { x = (x + (ll)y * z) % mod; }
int mpow(int a, int b) {
  int ret = 1;
  for (; b; b >>= 1) {
    if (b & 1) ret = (ll)ret * a % mod;
    a = (ll)a * a % mod;
  }
  return ret;
}

const int BRUTE_N2_LIMIT = 50;

struct NumberTheory {
  typedef pair<int, int> P2_Field;
  mt19937 rng;
  NumberTheory(): rng(chrono::steady_clock::now().time_since_epoch().count()) {}
  void exGcd(int a, int b, int &x, int &y) {
    if (!b) {
      x = 1, y = 0;
      return;
    }
    exGcd(b, a % b, y, x), y -= a / b * x;
  }
  int inv(int a, int p = mod) {
    int x, y;
    exGcd(a, p, x, y);
    if (x < 0)
      x += p;
    return x;
  }
  template<class Integer>
  bool quadRes(Integer a, Integer b) {
    if (a <= 1)
      return 1;
    while (a % 4 == 0)
      a /= 4;
    if (a % 2 == 0)
      return (b % 8 == 1 || b % 8 == 7) == quadRes(a / 2, b);
    return ((a - 1) % 4 == 0 || (b - 1) % 4 == 0) == quadRes(b % a, a);
  }
  int sqrt(int x, int p = mod) {
    if (p == 2 || x <= 1)
      return x;
    int w, v, k = (p + 1) / 2;
    do
      w = rng() % p;
    while (quadRes(v = ((ll)w * w - x + p) % p, p));
    P2_Field res(1, 0), a(w, 1);
    for (; k; k >>= 1) {
      if (k & 1)
        res = P2_Field(((ll)res.first * a.first + (ll)res.second * a.second % p * v) % p, ((ll)res.first * a.second + (ll)res.second * a.first) % p);
      a = P2_Field(((ll)a.first * a.first + (ll)a.second * a.second % p * v) % p, 2LL * a.first * a.second % p);
    }
    return min(res.first, p - res.first);
  }
} nt;

namespace Simple {
  int n = 1;
  vector<int> fac({1, 1}), ifac({1, 1}), inv({0, 1});
  void build(int m) {
    n = m;
    fac.resize(n + 1), ifac.resize(n + 1), inv.resize(n + 1);
    inv[1] = 1;
    for (int i = 2; i <= n; ++i)
      inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
    fac[0] = ifac[0] = 1;
    for (int i = 1; i <= n; ++i)
      fac[i] = (ll)fac[i - 1] * i % mod,
      ifac[i] = (ll)ifac[i - 1] * inv[i] % mod;
  }
  void check(int k) {
    int m = n;
    if (k > m) {
      while (k > m)
        m <<= 1;
      build(m);
    }
  }
  int gfac(int k) {
    check(k);
    return fac[k];
  }
  int gifac(int k) {
    check(k);
    return ifac[k];
  }
  int ginv(int k) {
    check(k);
    return inv[k];
  }
}

struct SimpleSequence {
  function<int(int)> func;
  SimpleSequence(const function<int(int)> &func): func(func) {}
  int operator[](int k) const {
    return func(k);
  }
} gfac(Simple::gfac), gifac(Simple::gifac), ginv(Simple::ginv);

int binom(int n, int m) {
  if (m > n || m < 0)
    return 0;
  return (ll)gfac[n] * gifac[m] % mod * gifac[n - m] % mod;
}

namespace NTT {
  int L = -1;
  vector<int> root;
  void init(int l) {
    L = l;
    root.resize((1 << L) + 1);
    int n = 1 << L, *w = root.data();
    w[0] = 1, w[1 << L] = mpow(31, 1 << (21 - L));
    for (int i = L; i; --i)
      w[1 << (i - 1)] = (ll)w[1 << i] * w[1 << i] % mod;
    for (int i = 1; i < n; ++i)
      w[i] = (ll)w[i & (i - 1)] * w[i & -i] % mod;
  }
  void DIF(int *a, int l) {
    int n = 1 << l;
    for (int len = n >> 1; len; len >>= 1)
      for (int *j = a, *o = root.data(); j != a + n; j += len << 1, ++o)
        for (int *k = j; k != j + len; ++k) {
          int r = (ll)*o * k[len] % mod;
          k[len] = reduce(*k - r), add(*k, r);
        }
  }
  void DIT(int *a, int l) {
    int n = 1 << l;
    for (int len = 1; len < n; len <<= 1)
      for (int *j = a, *o = root.data(); j != a + n; j += len << 1, ++o)
        for (int *k = j; k != j + len; ++k) {
          int r = norm(*k + k[len]);
          k[len] = (ll)*o * (*k - k[len] + mod) % mod, *k = r;
        }
  }
  void fft(int *a, int lgn, int d = 1) {
    if (L < lgn)
      init(lgn);
    int n = 1 << lgn;
    if (d == 1)
      DIF(a, lgn);
    else {
      DIT(a, lgn), reverse(a + 1, a + n);
      int nInv = mod - (mod - 1) / n;
      for (int i = 0; i < n; ++i)
        a[i] = (ll)a[i] * nInv % mod;
    }
  }
}

struct poly {
  vector<int> a;
  poly(ll v = 0): a(1) {
    if ((v %= mod) < 0)
      v += mod;
    a[0] = v;
  }
  poly(const poly &o): a(o.a) {}
  poly(const vector<int> &o): a(o) {}
  poly(initializer_list<int> o): a(o) {}
  int operator[](int k) const { return k < a.size() ? a[k] : 0; }
  int &operator[](int k) {
    if (k >= a.size())
      a.resize(k + 1);
    return a[k];
  }
  int deg() const { return (int)a.size() - 1; }
  void redeg(int d) { a.resize(d + 1); }
  int size() const {return a.size(); }
  void resize(int s) { a.resize(s); }
  poly slice(int d) const {
    if (d < a.size())
      return vector<int>(a.begin(), a.begin() + d + 1);
    vector<int> ret = a;
    ret.resize(d + 1);
    return ret;
  }
  poly shift(int k) const {
    if (size() + k <= 0)
      return 0;
    vector<int> ret(size() + k);
    for (int i = max(0, k); i < ret.size(); ++i)
      ret[i] = a[i - k];
    return ret;
  }
  int *base() { return a.data(); }
  const int *base() const { return a.data(); }
  poly println(FILE *fp = stdout) const {
    for (int i = 0; i < a.size(); ++i)
      fprintf(fp, "%d%c", a[i], " \n"[i == a.size() - 1]);
    return *this;
  }

  poly &operator+=(const poly &o) {
    if (o.size() > a.size())
      a.resize(o.size());
    for (int i = 0; i < o.size(); ++i)
      add(a[i], o[i]);
    return *this;
  }
  poly operator+(const poly &o) const { poly ret(a); ret += o; return ret; }
  poly operator-() const {
    poly ret = a;
    for (int i = 0; i < a.size(); ++i)
      ret[i] = neg(ret[i]);
    return ret;
  }
  poly &operator-=(const poly &o) { return operator+=(-o); }
  poly operator-(const poly &o) { return operator+(-o); }
  poly operator*(const poly &) const;
  poly operator/(const poly &) const;
  poly operator%(const poly &) const;
  poly &operator*=(const poly &o) { *this = operator*(o); return *this; }
  poly &operator/=(const poly &o) { *this = operator/(o); return *this; }
  poly &operator%=(const poly &o) { *this = operator%(o); return *this; }
  poly deriv() const;
  poly integ() const;
  poly inv() const;
  poly sqrt() const;
  poly ln() const;
  poly exp() const;
  poly srcExp() const;
  pair<poly, poly> sqrti() const;
  pair<poly, poly> expi() const;
  poly quo(const poly &) const;
  pair<poly, poly> iquo() const;
  pair<poly, poly> div(const poly &) const;
  poly taylor(int k) const;
  poly pow(int k) const;
  poly exp(int k) const;
};

poly zeroes(int d) { return vector<int>(d + 1); }

namespace NTT { void fft(poly &a, int lgn, int d = 1) { fft(a.base(), lgn, d); } }

using NTT::fft;

struct SemiRelaxedConvolution {
  static const int LG = 19;
  static const int B = 16;
  void run(int *f, const int *g, int n, const function<void(int)> &relax) {
    vector<vector<int>> save(LG + 1);
    function<void(int, int)> divideConquer = [&](int l, int r) {
      if (r - l <= BRUTE_N2_LIMIT) {
        for (int i = l + 1; i <= r; ++i) {
          for (int j = l; j < i; ++j)
            fam(f[i], f[j], g[i - j]);
          relax(i);
        }
        return ;
      }
      int d = (r - l) / B + 1, lgd = 0, lg;
      while ((1 << lgd) <= d * 2)
        ++lgd;
      d = (1 << (lgd - 1)) - 1, lg = (r - l + d - 1) / d;

      vector<int> dft = save[lgd];
      dft.resize(lg << (lgd + 1));
      for (int i = lg << lgd; i < (lg << (lgd + 1)); ++i)
        dft[i] = 0;
      int ef = lg;
      for (int i = 0; i < lg; ++i) {
        if ((i << lgd) < save[lgd].size())
          continue;
        if ((i + 2) * d >= l)
          --ef;
        for (int j = 0; j <= d * 2; ++j)
          dft[(i << lgd) + j] = g[i * d + j];
        fft(dft.data() + (i << lgd), lgd);
      }
      if (save[lgd].size() < (ef << lgd))
        save[lgd] = vector<int>(dft.begin(), dft.begin() + (ef << lgd));
      for (int i = 0; i < lg; ++i) {
        if (i)
          fft(dft.data() + ((lg + i) << lgd), lgd, -1);
        for (int j = 1; j <= min(d, r - l - i * d); ++j)
          add(f[l + i * d + j], dft[((lg + i) << lgd) + d + j]);
        divideConquer(l + i * d, min(l + (i + 1) * d, r));
        if (i + 1 < lg) {
          for (int j = 0; j < d; ++j)
            dft[((lg + i) << lgd) + j] = f[l + i * d + j];
          for (int j = d; j < (1 << lgd); ++j)
            dft[((lg + i) << lgd) + j] = 0;
          fft(dft.data() + ((lg + i) << lgd), lgd);
        }
        for (int j = i + 1; j < lg; ++j)
          for (int k = 0; k < (1 << lgd); ++k)
            fam(dft[((lg + j) << lgd) + k], dft[((j - i - 1) << lgd) + k], dft[((lg + i) << lgd) + k]);
      }
    };
    relax(0), divideConquer(0, n);
  }
} src;

poly poly::srcExp() const {
  int n = deg();
  poly f, g;
  f.redeg(n), g.redeg(n);
  for (int i = 0; i <= n; ++i)
    g[i] = (ll)a[i] * i % mod;
  src.run(f.base(), g.base(), n, [&](int i) {
    if (i == 0)
      f[i] = 1;
    else
      f[i] = (ll)f[i] * ginv[i] % mod;
  });
  return f;
}

struct Newton {
  void inv(const poly &f, const poly &dftf, poly &g, const poly &dftg, int t) {
    int n = 1 << t;
    poly prod = dftf;
    for (int i = 0; i < (n << 1); ++i)
      prod[i] = (ll)prod[i] * dftg[i] % mod;
    fft(prod, t + 1, -1);
    memset(prod.base(), 0, sizeof(int) << t);
    fft(prod, t + 1);
    for (int i = 0; i < (n << 1); ++i)
      prod[i] = (ll)prod[i] * dftg[i] % mod;
    fft(prod, t + 1, -1);
    for (int i = 0; i < n; ++i)
      prod[i] = 0;
    g -= prod;
  }
  void inv(const poly &f, const poly &dftf, poly &g, int t) {
    poly dftg(g);
    dftg.resize(2 << t);
    fft(dftg, t + 1);
    inv(f, dftf, g, dftg, t);
  }
  void inv(const poly &f, poly &g, int t) {
    poly dftf(f), dftg(g);
    dftf.resize(2 << t), dftg.resize(2 << t);
    fft(dftf, t + 1), fft(dftg, t + 1);
    inv(f, dftf, g, dftg, t);
  }
  void sqrt(const poly &f, poly &g, poly &dftg, poly &h, int t) {
    for (int i = 0; i < (1 << t); ++i)
      dftg[i] = (ll)dftg[i] * dftg[i] % mod;
    fft(dftg, t, -1);
    dftg -= f;
    for (int i = 0; i < (1 << t); ++i)
      add(dftg[i | (1 << t)], dftg[i]),
      dftg[i] = 0;
    fft(dftg, t + 1);
    poly tmp = h;
    tmp.resize(2 << t);
    fft(tmp, t + 1);
    for (int i = 0; i < (2 << t); ++i)
      tmp[i] = (ll)tmp[i] * dftg[i] % mod;
    fft(tmp, t + 1, -1);
    memset(tmp.base(), 0, sizeof(int) << t);
    g -= tmp * ginv[2];
  }
  void exp(const poly &f, poly &g, poly &dftg, poly &h, int t) {
    poly dfth = h;
    fft(dfth, t);
    poly dg = g.deriv().slice((1 << t) - 1);
    fft(dg, t);
    poly tmp = zeroes((1 << t) - 1);
    for (int i = 0; i < (1 << t); ++i)
      tmp[i] = (ll)dftg[i] * dfth[i] % mod,
      dg[i] = (ll)dg[i] * dfth[i] % mod;
    fft(tmp, t, -1), fft(dg, t, -1);
    sub(tmp[0], 1);
    dg.resize(2 << t);
    poly df0 = f.deriv().slice((1 << t) - 1);
    df0[(1 << t) - 1] = 0;
    for (int i = 0; i < (1 << t); ++i)
      dg[i | (1 << t)] = reduce(dg[i] - df0[i]);
    memcpy(dg.base(), df0.base(), sizeof(int) * ((1 << t) - 1));
    tmp.resize(2 << t), fft(tmp, t + 1);
    df0.resize(2 << t), fft(df0, t + 1);
    for (int i = 0; i < (2 << t); ++i)
      df0[i] = (ll)df0[i] * tmp[i] % mod;
    fft(df0, t + 1, -1);
    for (int i = 0; i < (1 << t); ++i)
      df0[i | (1 << t)] = df0[i],
      df0[i] = 0;
    dg = (dg - df0).integ().slice((2 << t) - 1) - f;
    fft(dg, t + 1);
    for (int i = 0; i < (2 << t); ++i)
      tmp[i] = (ll)dg[i] * dftg[i] % mod;
    fft(tmp, t + 1, -1);
    g.resize(2 << t);
    for (int i = 1 << t; i < (2 << t); ++i)
      g[i] = neg(tmp[i]);
  }
} nit;

struct Transposition {
  vector<int> _mul(int l, vector<int> res, const poly &b) {
    vector<int> tmp(1 << l);
    memcpy(tmp.begin().base(), b.a.begin().base(), sizeof(int) * (b.deg() + 1));
    reverse(tmp.begin() + 1, tmp.end());
    fft(tmp.begin().base(), l, 1);
    for (int i = 0; i < (1 << l); ++i)
      res[i] = res[i] * (ll)tmp[i] % mod;
    fft(res.begin().base(), l, -1);
    return res;
  }
  poly bfMul(const poly &a, const poly &b) {
    int n = a.deg(), m = b.deg();
    poly ret = zeroes(n - m);
    for (int i = 0; i <= n - m; ++i)
      for (int j = 0; j <= m; ++j)
        ret[i] = (ret[i] + a[i + j] * (ll)b[j]) % mod;
    return ret;
  }
  poly mul(const poly &a, const poly &b) {
    if (a.deg() < b.deg()) return 0;
    if (a.deg() <= BRUTE_N2_LIMIT) return bfMul(a, b);
    int l = 0;
    while ((1 << l) <= a.deg()) ++l;
    vector<int> res(1 << l);
    memcpy(res.begin().base(), a.a.begin().base(), sizeof(int) * (a.deg() + 1));
    fft(res.begin().base(), l, 1);
    res = _mul(l, res, b);
    res.resize(a.deg() - b.deg() + 1);
    return res;
  }
  pair<poly, poly> mul2(const poly &a, const poly &b1, const poly &b2) {
    if (a.deg() <= BRUTE_N2_LIMIT) return make_pair(bfMul(a, b1), bfMul(a, b2));
    int l = 0;
    while ((1 << l) <= a.deg()) ++l;
    vector<int> fa(1 << l);
    memcpy(fa.begin().base(), a.a.begin().base(), sizeof(int) * (a.deg() + 1));
    fft(fa.begin().base(), l, 1);
    vector<int> res1 = _mul(l, fa, b1), res2 = _mul(l, fa, b2);
    res1.resize(a.deg() - b1.deg() + 1);
    res2.resize(a.deg() - b2.deg() + 1);
    return make_pair(res1, res2);
  }
  vector<int> ls, rs, pos;
  vector<poly> p, q;
  void _build(int n) {
    ls.assign(n * 2 - 1, 0);
    rs.assign(n * 2 - 1, 0);
    p.assign(n * 2 - 1, 0);
    q.assign(n * 2 - 1, 0);
    pos.resize(n);
    int cnt = 0;
    function<int(int, int)> dfs = [&](int l, int r) {
      if (l == r) {
        pos[l] = cnt;
        return cnt++;
      }
      int ret = cnt++;
      int mid = (l + r) >> 1;
      ls[ret] = dfs(l, mid);
      rs[ret] = dfs(mid + 1, r);
      return ret;
    };
    dfs(0, n - 1);
  }
  vector<int> _eval(vector<int> f, const vector<int> &x) {
    int n = f.size();
    _build(n);
    for (int i = 0; i < n; ++i)
      q[pos[i]] = {1, neg(x[i])};
    for (int i = n * 2 - 2; i >= 0; --i)
      if (ls[i])
        q[i] = q[ls[i]] * q[rs[i]];
    f.resize(n * 2);
    p[0] = mul(f, q[0].inv());
    for (int i = 0; i < n * 2 - 1; ++i)
      if (ls[i])
        tie(p[ls[i]], p[rs[i]]) = mul2(p[i], q[rs[i]], q[ls[i]]);
    vector<int> ret(n);
    for (int i = 0; i < n; ++i)
      ret[i] = p[pos[i]][0];
    return ret;
  }
  vector<int> eval(const poly &f, const vector<int> &x) {
    int n = f.deg() + 1, m = x.size();
    vector<int> tmpf = f.a, tmpx = x;
    tmpf.resize(max(n, m));
    tmpx.resize(max(n, m));
    vector<int> ret = _eval(tmpf, tmpx);
    ret.resize(m);
    return ret;
  }
  poly inter(const vector<int> &x, const vector<int> &y) {
    int n = x.size();
    _build(n);
    for (int i = 0; i < n; ++i)
      q[pos[i]] = {1, norm(mod - x[i])};
    for (int i = n * 2 - 2; i >= 0; --i)
      if (ls[i])
        q[i] = q[ls[i]] * q[rs[i]];
    poly tmp = q[0];
    reverse(tmp.a.begin(), tmp.a.end());
    vector<int> f = tmp.deriv().a;
    f.resize(n * 2);
    p[0] = mul(f, q[0].inv());
    for (int i = 0; i < n * 2 - 1; ++i)
      if (ls[i])
        tie(p[ls[i]], p[rs[i]]) = mul2(p[i], q[rs[i]], q[ls[i]]);
    for (int i = 0; i < n; ++i)
      p[pos[i]] = nt.inv(p[pos[i]][0]) * (ll)y[i] % mod;
    for (int i = 0; i < n * 2 - 1; ++i)
      reverse(q[i].a.begin(), q[i].a.end());
    for (int i = n * 2 - 2; i >= 0; --i)
      if (ls[i])
        p[i] = p[ls[i]] * q[rs[i]] + p[rs[i]] * q[ls[i]];
    return p[0];
  }
} tp;

poly poly::operator*(const poly &o) const {
  int n = deg(), m = o.deg();
  if (n <= 10 || m <= 10 || n + m <= BRUTE_N2_LIMIT) {
    poly ret = zeroes(n + m);
    for (int i = 0; i <= n; ++i)
      for (int j = 0; j <= m; ++j)
        fam(ret[i + j], a[i], o[j]);
    return ret;
  }
  n += m;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  poly ret = a, tmp = o;
  ret.resize(1 << l), tmp.resize(1 << l);
  fft(ret, l), fft(tmp, l);
  for (int i = 0; i < (1 << l); ++i)
    ret[i] = (ll)ret[i] * tmp[i] % mod;
  fft(ret, l, -1);
  return ret.slice(n);
}
poly poly::inv() const {
  poly g = nt.inv(a[0]);
  for (int t = 0; (1 << t) <= deg(); ++t)
    nit.inv(slice((2 << t) - 1), g, t);
  g.redeg(deg());
  return g;
}
poly poly::taylor(int k) const {
  int n = deg();
  poly f = zeroes(n), g = zeroes(n);
  for (int i = 0, pw = 1; i <= n; ++i)
    f[n - i] = (ll)a[i] * gfac[i] % mod,
    g[i] = (ll)pw * gifac[i] % mod,
    pw = (ll)pw * k % mod;
  f *= g;
  for (int i = 0; i <= n; ++i)
    g[i] = (ll)f[n - i] * gifac[i] % mod;
  return g;
}
poly poly::pow(int k) const {
  if (k == 0)
    return 1;
  if (k == 1)
    return *this;
  int n = deg() * k;
  int l = 0;
  while ((1 << l) <= n)
    ++l;
  poly ret = a;
  ret.resize(1 << l), fft(ret, l);
  for (int i = 0; i < (1 << l); ++i)
    ret[i] = mpow(ret[i], k);
  fft(ret, -1);
  return ret.slice(n);
}
poly poly::deriv() const {
  if (deg() == 0)
    return 0;
  vector<int> ret(deg());
  for (int i = 0; i < deg(); ++i)
    ret[i] = (ll)a[i + 1] * (i + 1) % mod;
  return ret;
}
poly poly::integ() const {
  vector<int> ret(size() + 1);
  for (int i = 0; i <= deg(); ++i)
    ret[i + 1] = (ll)a[i] * ginv[i + 1] % mod;
  return ret;
}
poly poly::quo(const poly &o) const {
  if (o.deg() == 0)
    return (ll)a[0] * nt.inv(o[0]) % mod;
  poly g = nt.inv(o[0]);
  int t = 0, n;
  for (n = 1; (n << 1) <= o.deg(); ++t, n <<= 1)
    nit.inv(o.slice((n << 1) - 1), g, t);
  poly dftg = g;
  dftg.resize(n << 1), fft(dftg, t + 1);
  poly eps1 = o;
  eps1.resize(n << 1), fft(eps1, t + 1);
  for (int i = 0; i < (n << 1); ++i)
    eps1[i] = (ll)eps1[i] * dftg[i] % mod;;
  fft(eps1, t + 1, -1);
  for (int i = 0; i < n; ++i)
    eps1[i] = eps1[i + n],
    eps1[i + n] = 0;
  fft(eps1, t + 1);
  poly h0 = slice(n - 1);
  h0.resize(n << 1), fft(h0, t + 1);
  poly h0g0 = zeroes((n << 1) - 1);
  for (int i = 0; i < (n << 1); ++i)
    h0g0[i] = (ll)h0[i] * dftg[i] % mod;
  fft(h0g0, t + 1, -1);
  poly h0eps1 = zeroes((n << 1) - 1);
  for (int i = 0; i < (n << 1); ++i)
    h0eps1[i] = (ll)h0[i] * eps1[i] % mod;
  fft(h0eps1, t + 1, -1);
  for (int i = 0; i < n; ++i)
    h0eps1[i] = reduce(operator[](i + n) - h0eps1[i]);
  memset(h0eps1.base() + n, 0, sizeof(int) << t);
  fft(h0eps1, t + 1);
  for (int i = 0; i < (n << 1); ++i)
    h0eps1[i] = (ll)h0eps1[i] * dftg[i] % mod;
  fft(h0eps1, t + 1, -1);
  for (int i = 0; i < n; ++i)
    h0eps1[i + n] = h0eps1[i],
    h0eps1[i] = 0;
  return (h0g0 + h0eps1).slice(o.deg());
}
poly poly::ln() const {
  if (deg() == 0)
    return 0;
  return deriv().quo(slice(deg() - 1)).integ();
}
pair<poly, poly> poly::sqrti() const {
  poly g = nt.sqrt(a[0]), h = nt.inv(a[0]), dftg = g;
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.sqrt(slice((2 << t) - 1), g, dftg, h, t);
    dftg = g, fft(dftg, t + 1);
    nit.inv(g, dftg, h, t);
  }
  return make_pair(g.slice(deg()), h.slice(deg()));
}
poly poly::sqrt() const {
  poly g = nt.sqrt(a[0]), h = nt.inv(a[0]), dftg = g;
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.sqrt(slice((2 << t) - 1), g, dftg, h, t);
    if ((2 << t) <= deg()) {
      dftg = g, fft(dftg, t + 1);
      nit.inv(g, dftg, h, t);
    }
  }
  return g.slice(deg());
}
pair<poly, poly> poly::expi() const {
  poly g = 1, h = 1, dftg = {1, 1};
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.exp(slice((2 << t) - 1), g, dftg, h, t);
    dftg = g, dftg.resize(4 << t);
    fft(dftg, t + 2);
    poly f2n = dftg.slice((2 << t) - 1);
    nit.inv(g, f2n, h, t);
  }
  return make_pair(g.slice(deg()), h.slice(deg()));
}
poly poly::exp() const {
  poly g = 1, h = 1, dftg = {1, 1};
  for (int t = 0; (1 << t) <= deg(); ++t) {
    nit.exp(slice((2 << t) - 1), g, dftg, h, t);
    if ((2 << t) <= deg()) {
      dftg = g, dftg.resize(4 << t);
      fft(dftg, t + 2);
      poly f2n = dftg.slice((2 << t) - 1);
      nit.inv(g, f2n, h, t);
    }
  }
  return g.slice(deg());
}
poly poly::exp(int k) const {
  int lead, lz = 0;
  while (lz < deg() && !a[lz])
    ++lz;
  if (lz == deg() && !a[lz])
    return *this;
  lead = a[lz];
  if ((ll)lz * k > deg())
    return zeroes(deg());
  poly part = poly(vector<int>(a.begin() + lz, a.begin() + deg() - lz * (k - 1) + 1)) * nt.inv(lead);
  part = (part.ln() * k).exp() * mpow(lead, k);
  vector<int> ret(deg() + 1);
  memcpy(ret.data() + lz * k, part.base(), sizeof(int) * (deg() - lz * k + 1));
  return ret;
}
poly poly::operator/(const poly &o) const {
  int n = deg(), m = o.deg();
  if (n < m)
    return 0;
  poly ta(vector<int>(a.rbegin(), a.rend())), tb(vector<int>(o.a.rbegin(), o.a.rend()));
  ta.redeg(n - m), tb.redeg(n - m);
  poly q = ta.quo(tb);
  return vector<int>(q.a.rbegin(), q.a.rend());
}
pair<poly, poly> poly::div(const poly &o) const {
  if (deg() < o.deg())
    return make_pair(0, *this);
  int n = deg(), m = o.deg();
  poly q = operator/(o), r;
  int l = 0;
  while ((1 << l) < o.deg())
    ++l;
  int t = (1 << l) - 1;
  poly tmp = zeroes(t);
  r = zeroes(t);
  for (int i = 0; i <= m; ++i)
    add(r[i & t], o[i]);
  for (int i = 0; i <= n - m; ++i)
    add(tmp[i & t], q[i]);
  fft(r, l), fft(tmp, l);
  for (int i = 0; i <= t; ++i)
    tmp[i] = (ll)tmp[i] * r[i] % mod;
  fft(tmp, l, -1);
  memset(r.base(), 0, sizeof(int) << l);
  for (int i = 0; i <= n; ++i)
    add(r[i & t], a[i]);
  for (int i = 0; i < m; ++i)
    sub(r[i], tmp[i]);
  return make_pair(q, r.slice(m - 1));
}
poly poly::operator%(const poly &o) const {
  return div(o).second;
}

const int N = 1e5;

int n, k, p;
int a[N + 5];
int coeLeft[N + 5][2], coeRight[N + 5][2], coe[N + 5];
poly f;
int ans;

int main() {
  scanf("%d%d%d", &n, &k, &p);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i), ++a[i];
  coeLeft[0][0] = coeRight[n + 1][0] = 1;
  for (int i = 1; i <= n; ++i)
    coeLeft[i][0] = ((ll)a[i] * coeLeft[i - 1][0] + 1) % mod,
    coeLeft[i][1] = ((ll)a[i] * (coeLeft[i - 1][0] + coeLeft[i - 1][1]) - coeLeft[i - 1][0] + mod) % mod;
  for (int i = n; i; --i)
    coeRight[i][0] = ((ll)a[i] * coeRight[i + 1][0] + 1) % mod,
    coeRight[i][1] = ((ll)a[i] * (coeRight[i + 1][0] + coeRight[i + 1][1]) - coeRight[i + 1][0] + mod) % mod;
  for (int i = 1; i <= n; ++i)
    coe[i] = ((ll)(coeLeft[i - 1][0] + coeLeft[i - 1][1]) * (coeRight[i + 1][0] + coeRight[i + 1][1]) + (ll)(mod - coeLeft[i - 1][1]) * coeRight[i + 1][1]) % mod;
  f.redeg(k);
  for (int i = 0; i <= k; ++i) f[i] = (ll)p * gifac[i] % mod;
  sub(f[0], 1);
  f = f.inv();
  reverse(f.base(), f.base() + k + 1);
  for (int i = 0; i <= k; ++i) f[i] = (ll)f[i] * gfac[k] % mod * gifac[i] % mod;
  auto res = tp.eval(f, vector<int>(a + 1, a + n + 1));
  for (int i = 1; i <= n; ++i)
    ans = (ans + ((ll)mpow(p, a[i]) * res[i - 1] - f[0] + mod) % mod * coe[i]) % mod;
  printf("%d\n", ans);
}