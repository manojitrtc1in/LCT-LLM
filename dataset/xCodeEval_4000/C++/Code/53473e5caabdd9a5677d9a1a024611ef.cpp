

#define GOODOJ
#define SYNC 0
#define MUL 0

#ifdef GOODOJ
#include <bits/stdc++.h>
#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#include <chrono>
#include <random>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#else
#include <iostream>
#include <cstdio>
#include <cmath>
#include <set>
#include <queue>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
#include <deque>
#include <vector>
#include <limits>
#include <cassert>
#include <sstream>
#include <iterator>
#include <functional>
#endif
using namespace std;

#define endl '\n'
#define fep(i,b,e) for(int i=(b), i##_ = (e);i<i##_;++i)
#define rep(i,x) for(int i=0, i##_ = (x);i<i##_;++i)
#define rap(i,x) for(auto& i : (x))
#define seg(t) (t).begin(), (t).end()
#define sz(x) (int)(x).size()
#define ep emplace_back
#define mkp make_pair
#define mkt make_tuple
#define qxx(i,x) for(int i = head[x]; ~i; i = node[i].nex)
#define F first
#define S second
#define lowbit(x) ((-(x))&(x))
#define RE register
#define getchar() getchar_unlocked()
#ifdef DEBUG
void err(istream_iterator<string>){}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << ' ';
	err(++it, args...);
}
#define debug(args...) {string _s=#args;replace(seg(_s),',',' ');\
	cerr<<"DEBUG:";istringstream it(_s);\
	err(istream_iterator<string>(it), args);cerr<<endl;}
#else
#define debug(...)
#endif

template<typename T> inline bool cmax(T& a,const T& b) {return a<b?a=b,1:0;}
template<typename T> inline bool cmin(T& a,const T& b) {return a>b?a=b,1:0;}

#ifdef GOODOJ
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
typedef __gnu_pbds::priority_queue<int> pq;
#endif
typedef std::string str;
typedef vector<int> vi;
typedef long long ll;
typedef double db;
typedef pair<int, int> pa;

template<typename T>
ostream& operator << (ostream& out, const std::vector<T>& v) {
	for (auto& i : v) out << i << ' ';
	return out;
}

namespace Polynomial {
using Poly = std::vector<int>;
constexpr int P(998244353), G(3);
inline void inc(int &x, int y) { (x += y) >= P ? x -= P : 0; }
inline int mod(int64_t x) { return x % P; }
inline int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P)
    if (k & 1) r = 1LL * r * x % P;
  return r;
}
template <int N>
std::array<int, N> getOmega() {
  std::array<int, N> w;
  for (int i = N >> 1, x = fpow(G, (P - 1) / N); i; i >>= 1, x = 1LL * x * x % P) {
    w[i] = 1;
    for (int j = 1; j < i; j++) w[i + j] = 1LL * w[i + j - 1] * x % P;
  }
  return w;
}
auto w = getOmega<1 << 18>();
Poly &operator*=(Poly &a, int b) { for (auto &x : a) x = 1LL * x * b % P; return a; }
Poly operator*(Poly a, int b) { return a *= b; }
Poly operator*(int a, Poly b) { return b * a; }
Poly &operator/=(Poly &a, int b) { return a *= fpow(b); }
Poly operator/(Poly a, int b) { return a /= b; }
Poly &operator+=(Poly &a, Poly b) {
  a.resize(std::max(a.size(), b.size()));
  for (int i = 0; i < b.size(); i++) inc(a[i], b[i]);
  return a;
}
Poly operator+(Poly a, Poly b) { return a += b; }
Poly &operator-=(Poly &a, Poly b) {
  a.resize(std::max(a.size(), b.size()));
  for (int i = 0; i < b.size(); i++) inc(a[i], P - b[i]);
  return a;
}
Poly operator-(Poly a, Poly b) { return a -= b; }
Poly operator-(Poly a) { for (auto &x : a) x ? x = P - x : 0; return a; }
Poly &operator>>=(Poly &a, int x) {
  if (x >= (int)a.size()) {
    a.clear();
  } else {
    a.erase(a.begin(), a.begin() + x);
  }
  return a;
}
Poly &operator<<=(Poly &a, int x) {
  a.insert(a.begin(), x, 0);
  return a;
}
Poly operator>>(Poly a, int x) { return a >>= x; }
Poly operator<<(Poly a, int x) { return a <<= x; }
inline Poly &dotEq(Poly &a, Poly b) {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++) a[i] = 1LL * a[i] * b[i] % P;
  return a;
}
inline Poly dot(Poly a, Poly b) { return dotEq(a, b); }
void norm(Poly &a) {
  if (!a.empty()) {
    a.resize(1 << std::__lg(a.size() * 2 - 1));
  }
}
void dft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = n >> 1; k; k >>= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int y = a[i + j + k];
        a[i + j + k] = 1LL * (a[i + j] - y + P) * w[k + j] % P;
        inc(a[i + j], y);
      }
    }
  }
}
void idft(int *a, int n) {
  assert((n & n - 1) == 0);
  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i += k << 1) {
      for (int j = 0; j < k; j++) {
        int x = a[i + j], y = 1LL * a[i + j + k] * w[k + j] % P;
        a[i + j + k] = x - y < 0 ? x - y + P : x - y;
        inc(a[i + j], y);
      }
    }
  }
  for (int i = 0, inv = P - (P - 1) / n; i < n; i++)
    a[i] = 1LL * a[i] * inv % P;
  std::reverse(a + 1, a + n);
}
void dft(Poly &a) { dft(a.data(), a.size()); }
void idft(Poly &a) { idft(a.data(), a.size()); }


void dftDoubling(int *x, int n) {
  std::copy_n(x, n, x + n);
  idft(x + n, n);
  for (int i = 0; i < n; i++) x[n + i] = 1LL * w[n + i] * x[n + i] % P;
  dft(x + n, n);
}
Poly operator*(Poly a, Poly b) {
  int len = a.size() + b.size() - 1;
  if (a.size() <= 8 || b.size() <= 8) {
    Poly c(len);
    for (size_t i = 0; i < a.size(); i++)
      for (size_t j = 0; j < b.size(); j++)
        c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
    return c;
  }
  int n = 1 << std::__lg(len - 1) + 1;
  a.resize(n), b.resize(n);
  dft(a), dft(b);
  dotEq(a, b);
  idft(a);
  a.resize(len);
  return a;
}






Poly invRec(Poly a) {
  int n = a.size();
  assert((n & n - 1) == 0);
  if (n == 1) return {fpow(a[0])};
  int m = n >> 1;
  Poly b = invRec(Poly(a.begin(), a.begin() + m)), c = b;
  b.resize(n);
  dft(a), dft(b), dotEq(a, b), idft(a);
  for (int i = 0; i < m; i++) a[i] = 0;
  for (int i = m; i < n; i++) a[i] = P - a[i];
  dft(a), dotEq(a, b), idft(a);
  for (int i = 0; i < m; i++) a[i] = c[i];
  return a;
}


Poly inverse(Poly a) {
  int n = a.size();
  norm(a);
  a = invRec(a);
  a.resize(n);
  return a;
}




Poly operator/(Poly a, Poly b) {
  int n = a.size(), m = b.size();
  if (n < m) return {0};
  int k = 1 << std::__lg(n - m << 1 | 1);
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());
  a.resize(k), b.resize(k), b = invRec(b);
  a = a * b;
  a.resize(n - m + 1);
  std::reverse(a.begin(), a.end());
  return a;
}




std::pair<Poly, Poly> operator%(Poly a, Poly b) {
  int m = b.size();
  Poly c = a / b;
  b = b * c;
  a.resize(m - 1);
  for (int i = 0; i < m - 1; i++) inc(a[i], P - b[i]);
  return {c, a};
}




Poly sqrt(Poly a) {
  int raw = a.size();
  int d = 0;
  while (d < raw && !a[d]) d++;
  if (d == raw) return a;
  if (d & 1) return {};
  norm(a >>= d);
  int len = a.size();
  Poly b(len), binv(1), bsqr{a[0]}, foo, bar;  

  

  

  

  assert(a[0] == 1);
  b[0] = binv[0] = 1;
  auto shift = [](int x) { return (x & 1 ? x + P : x) >> 1; };  

  for (int m = 1, n = 2; n <= len; m <<= 1, n <<= 1) {
    foo.resize(n), bar = binv;
    for (int i = 0; i < m; i++) {
      foo[i + m] = a[i] + a[i + m] - bsqr[i];
      if (foo[i + m] >= P) foo[i + m] -= P;
      if (foo[i + m] < 0) foo[i + m] += P;
      foo[i] = 0;
    }
    binv.resize(n);
    dft(foo), dft(binv), dotEq(foo, binv), idft(foo);
    for (int i = m; i < n; i++) b[i] = shift(foo[i]);
    

    if (n == len) break;
    for (int i = 0; i < n; i++) foo[i] = b[i];
    bar.resize(n), binv = bar;
    dft(foo), dft(bar), bsqr = dot(foo, foo), idft(bsqr);
    dotEq(foo, bar), idft(foo);
    for (int i = 0; i < m; i++) foo[i] = 0;
    for (int i = m; i < n; i++) foo[i] = P - foo[i];
    dft(foo), dotEq(foo, bar), idft(foo);
    for (int i = m; i < n; i++) binv[i] = foo[i];
  }
  b <<= d / 2;
  b.resize(raw);
  return b;
}


Poly deriv(Poly a) {
  for (int i = 0; i + 1 < a.size(); i++) a[i] = (i + 1LL) * a[i + 1] % P;
  a.pop_back();
  return a;
}
std::vector<int> inv = {1, 1};
void updateInv(int n) {
  if ((int)inv.size() <= n) {
    int p = inv.size();
    inv.resize(n + 1);
    for (int i = p; i <= n; i++) inv[i] = 1LL * (P - P / i) * inv[P % i] % P;
  }
}


Poly integ(Poly a, int c = 0) {
  int n = a.size();
  updateInv(n);
  Poly b(n + 1);
  b[0] = c;
  for (int i = 0; i < n; i++) b[i + 1] = 1LL * inv[i + 1] * a[i] % P;
  return b;
}


Poly ln(Poly a) {
  int n = a.size();
  assert(a[0] == 1);
  a = inverse(a) * deriv(a);
  a.resize(n - 1);
  return integ(a);
}




Poly expNewton(Poly a) {
  int n = a.size();
  assert((n & n - 1) == 0);
  assert(a[0] == 0);
  if (n == 1) return {1};
  int m = n >> 1;
  Poly b = expNewton(Poly(a.begin(), a.begin() + m)), c;
  b.resize(n), c = ln(b);
  a.resize(n << 1), b.resize(n << 1), c.resize(n << 1);
  dft(a), dft(b), dft(c);
  for (int i = 0; i < n << 1; i++) a[i] = (1LL + P + a[i] - c[i]) * b[i] % P;
  idft(a);
  a.resize(n);
  return a;
}










Poly exp2(Poly a) {
  if (a.empty()) return {};
  assert(a[0] == 0);
  int n = a.size();
  updateInv(n);
  for (int i = 0; i + 1 < n; i++) {
    a[i] = a[i + 1] * (i + 1LL) % P;
  }
  a.pop_back();
  Poly b(n);
  b[0] = 1;
  for (int m = 1; m < n; m++) {
    int k = m & -m, l = m - k, r = std::min(m + k, n);
    Poly p(a.begin(), a.begin() + (r - l - 1));
    Poly q(b.begin() + l, b.begin() + m);
    p.resize(k * 2), q.resize(k * 2);
    dft(p), dft(q);
    dotEq(p, q);
    idft(p);
    for (int i = m; i < r; i++) inc(b[i], p[i - l - 1]);
    b[m] = 1LL * b[m] * inv[m] % P;
  }
  return b;
}






Poly exp(Poly a) {
  if (a.empty()) return {};
  assert(a[0] == 0);
  int n = a.size();
  updateInv(n);
  for (int i = 0; i + 1 < n; i++) {
    a[i] = a[i + 1] * (i + 1LL) % P;
  }
  a.pop_back();
  Poly b(n);
  b[0] = 1;
  std::vector<Poly> val_a[6], val_b(n);
  for (int m = 1; m < n; m++) {
    int k = 1, d = 0;
    while (!(m / k & 0xf)) k *= 16, d++;
    int l = m & ~(0xf * k), r = std::min(n, m + k);
    if (k == 1) {
      for (int i = m; i < r; i++) {
        for (int j = l; j < m; j++) {
          b[i] = (b[i] + 1LL * b[j] * a[i - j - 1]) % P;
        }
      }
    } else {
      assert(d < 6);
      if (val_a[d].empty()) val_a[d].resize(n);
      val_b[m] = Poly(b.begin() + (m - k), b.begin() + m);
      val_b[m].resize(k * 2);
      dft(val_b[m]);
      Poly res(k * 2);
      for (; l < m; l += k) {
        auto &p = val_a[d][m - l - k];
        if (p.empty()) {
          p = Poly(a.begin() + (m - l - k), a.begin() + (r - l - 1));
          p.resize(2 * k);
          dft(p);
        }
        auto &q = val_b[l + k];
        for (int i = 0; i < k * 2; i++) res[i] = (res[i] + 1LL * p[i] * q[i]) % P;
      }
      idft(res);
      for (int i = m; i < r; i++) inc(b[i], res[i - m + k - 1]);
    }
    b[m] = 1LL * b[m] * inv[m] % P;
  }
  return b;
}
Poly power(Poly a, int k) {
  int n = a.size();
  long long d = 0;
  while (d < n && !a[d]) d++;
  if (d == n) return a;
  a >>= d;
  int b = fpow(a[0]);
  norm(a *= b);
  a = exp(ln(a) * k) * fpow(b, P - 1 - k % (P - 1));
  a.resize(n);
  d *= k;
  for (int i = n - 1; i >= d; i--) a[i] = a[i - d];
  d = std::min(d, 1LL * n);
  for (int i = d; i; a[--i] = 0) ;
  return a;
}
Poly power(Poly a, int k1, int k2) { 

  int n = a.size();
  long long d = 0;
  while (d < n && !a[d]) d++;
  if (d == n) return a;
  a >>= d;
  int b = fpow(a[0]);
  norm(a *= b);
  a = exp(ln(a) * k2) * fpow(b, P - 1 - k1 % (P - 1));
  a.resize(n);
  d *= k1;
  for (int i = n - 1; i >= d; i--) a[i] = a[i - d];
  d = std::min(d, 1LL * n);
  for (int i = d; i; a[--i] = 0) ;
  return a;
}




int divAt(Poly f, Poly g, int64_t n) {
  int len = std::max(f.size(), g.size()), m = 1 << std::__lg(len * 2 - 1);
  f.resize(len), g.resize(len);
  for (; n; n >>= 1) {
    f.resize(m * 2), g.resize(m * 2);
    dft(f), dft(g);
    for (int i = 0; i < m * 2; i++) f[i] = 1LL * f[i] * g[i ^ 1] % P;
    for (int i = 0; i < m; i++) g[i] = 1LL * g[i * 2] * g[i * 2 + 1] % P;
    g.resize(m);
    idft(f), idft(g);
    for (int i = 0, j = n & 1; i < len; i++, j += 2) f[i] = f[j];
    f.resize(len), g.resize(len);
  }
  return f[0];
}


Poly invRange(Poly q, int64_t l, int64_t r) {
  assert(l <= r);
  assert(r - l + 1 <= 5e5);
  int len = std::max<int>(q.size(), r - l + 1), m = 1 << std::__lg(len * 2 - 1);

  std::function<Poly(Poly&, int64_t)> cal = [&](Poly &a, int64_t n) -> Poly {
    if (n == 0) {
      Poly res(len);
      int c = 0;
      for (int i = 0; i < m; i++) inc(c, a[i]);
      res.back() = 1LL * m * fpow(c) % P;
      return res;
    }
    dftDoubling(a.data(), m);
    Poly b(m * 2);
    for (int i = 0; i < m; i++) b[i] = 1LL * a[i * 2] * a[i * 2 + 1] % P;
    auto c = cal(b, n >> 1);
    std::fill(b.begin(), b.end(), 0);
    for (int i = 0, o = n & 1 ^ 1; i < len; i++) b[i * 2 ^ o] = c[i];
    dft(b);
    for (int i = 0; i < m * 2; i++) b[i] = 1LL * b[i] * a[i ^ 1] % P;
    idft(b);
    return Poly(b.begin() + len, b.begin() + len * 2);
  };

  q.resize(m * 2);
  dft(q.data(), m);
  q = cal(q, r);
  return Poly(q.end() - (r - l + 1), q.end());
}
int divAt2(Poly f, Poly g, int64_t n) {
  g = invRange(g, n - ((int)f.size() - 1), n);
  g = f * g;
  return g[f.size() - 1];
}
}  


namespace PolyEI {  


using namespace Polynomial;
class SegTree {
  std::vector<Poly> p;
  int n, raw_n;
 public:
  SegTree(std::vector<int> a) {
    raw_n = a.size();
    n = 1 << std::__lg(2 * raw_n - 1);
    p.resize(n << 1);
    for (int i = 0; i < n; i++)
      p[i + n] = Poly({1, i < raw_n ? P - a[i] : 0});
    for (int i = n - 1; i; i--) {
      int ls = i << 1, rs = ls | 1, len = p[ls].size() - 1 << 1;
      p[ls].resize(len), p[rs].resize(len);
      dft(p[ls]), dft(p[rs]), p[i] = dot(p[ls], p[rs]), idft(p[i]);
      p[i].push_back((p[i][0] - 1 + P) % P);
      p[i][0] = 1;
    }
  }
  std::vector<int> multiEval(Poly f) const {
    int m = f.size();
    if (m == 1) return std::vector<int>(raw_n, f[0]);
    Poly q = inverse(p[1]);
    std::reverse(f.begin(), f.end());
    q = q * f;
    q.resize(m);
    if (m > n) {
      q = Poly(q.end() - n, q.end());
    } else {
      q.resize(n);
      std::rotate(q.begin(), q.begin() + m, q.end());  

    }
    for (int k = n, o = 1; k > 1; k >>= 1)
      for (int i = 0; i < n; i += k, o++) {
        if (i >= raw_n) continue;
        int *a = &q[i];
        int const *l = p[o << 1].data(), *r = p[o << 1 | 1].data();
        dft(a, k);
        Poly foo(k), bar(k);
        for (int j = 0; j < k; j++) foo[j] = 1LL * a[j] * r[j] % P;
        for (int j = 0; j < k; j++) bar[j] = 1LL * a[j] * l[j] % P;
        idft(foo), idft(bar);
        std::copy(foo.end() - k / 2, foo.end(), a);
        std::copy(bar.end() - k / 2, bar.end(), a + k / 2);
      }
    q.resize(raw_n);
    return q;
  }
  Poly interpolate(std::vector<int> b) const {
    assert(b.size() == raw_n);
    Poly q(p[1].begin(), p[1].begin() + raw_n + 1);
    std::reverse(q.begin(), q.end());
    q = multiEval(deriv(q));
    for (int i = 0; i < raw_n; i++) q[i] = 1LL * fpow(q[i]) * b[i] % P;
    q.resize(n);
    for (int k = 1, h = n >> 1; k < n; k <<= 1, h >>= 1)
      for (int i = 0, o = h; i < n; i += k << 1, o++) {
        if (i >= raw_n) continue;
        int *a = &q[i], *b = &q[i + k];
        int const *l = p[o << 1].data(), *r = p[o << 1 | 1].data();
        Poly foo(k << 1), bar(k << 1);
        for (int j = 0; j < k; j++) foo[j] = a[j];
        for (int j = 0; j < k; j++) bar[j] = b[j];
        dft(foo), dft(bar);
        for (int j = 0; j < k << 1; j++)
          foo[j] = (1LL * foo[j] * r[j] + 1LL * bar[j] * l[j]) % P;
        idft(foo);
        std::copy(foo.begin(), foo.end(), a);
      }
    q.resize(raw_n);
    std::reverse(q.begin(), q.end());
    return q;
  }
};
}  


using namespace Polynomial;

#ifdef GOODOJ
constexpr
#else
const
#endif
int Ma = 1e6, inf = 0x3f3f3f3f;

void solve() {
	int n; cin >> n; vector<int> in(n);
	rep (i, n - 1) {
		int u, v; cin >> u >> v; --u, --v;
		++in[u], ++in[v];
	}
	auto cal = [&] (auto cal, int l, int r) -> Poly {
		if (r - l == 1) return {1, in[l] - (l != 0)};
		int mid((l + r) >> 1);
		return cal(cal, l, mid) * cal(cal, mid, r);
	};
	Poly p = cal(cal, 0, n);
	int ans{0};
	vector<int> fac(1, 1);
	fac.resize(n + 1);
	for (int i = 1; i <= n; i++)
		fac[i] = mod((ll)fac[i - 1] * i);
	for (int i = 0, j = 1; i <= n; i++, j = -j) {
		inc(ans, mod((ll)fac[n - i] * p[i] * j));
		ans %= P; ans += P; ans %= P;
	}
	cout << ans << endl;
}

signed main() {
#if SYNC==0
	ios::sync_with_stdio(false);
	cin.tie(0); cout<<fixed<<setprecision(6);
#endif
#if MUL==0
	solve();
#else
	int t=1; cin >> t;
	for (int qq = 0; qq < t; ++qq)
		solve();
#endif

	return 0;
}
