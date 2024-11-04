
using namespace std;



using namespace std;

template <typename T>void read(T &x)
{
    x = 0;
    register int f = 1;
    register char ch = getchar();
    while(ch < '0' || ch > '9') {if(ch == '-')f = -1;ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = x * 10 + ch - '0';ch = getchar();}
    x *= f;
}

namespace Polynomial {
using Poly = std::vector<int>;
constexpr int P(998244353), G(3), L(1 << 18); 

inline void inc(int &x, int y) { (x += y) >= P ? x -= P : 0; }
inline int mod(int64_t x) { return x % P; }
inline int fpow(int x, int k = P - 2) {
  int r = 1;
  for (; k; k >>= 1, x = 1LL * x * x % P)
    if (k & 1) r = 1LL * r * x % P;
  return r;
}
 
int w[L], _ = [] {
  w[L / 2] = 1;
  for (int i = L / 2 + 1, x = fpow(G, (P - 1) / L); i < L; i++) w[i] = 1LL * w[i - 1] * x % P;
  for (int i = L / 2 - 1; i >= 0; i--) w[i] = w[i << 1];
  return 0;
}();
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


void id1(int *a, int n) {
  std::copy_n(a, n, a + n);
  idft(a + n, n);
  for (int i = 0; i < n; i++) a[n + i] = 1LL * w[n + i] * a[n + i] % P;
  dft(a + n, n);
}
int norm(int n) { return 1 << std::__lg(n * 2 - 1); }
void norm(Poly &a) {
  if (!a.empty()) a.resize(norm(a.size()));
}
void dft(Poly &a) { dft(a.data(), a.size()); }
void idft(Poly &a) { idft(a.data(), a.size()); }
inline Poly &dotEq(Poly &a, Poly b) {
  assert(a.size() == b.size());
  for (int i = 0; i < a.size(); i++) a[i] = 1LL * a[i] * b[i] % P;
  return a;
}
inline Poly dot(Poly a, Poly b) { return dotEq(a, b); }
Poly operator*(const Poly &a, const Poly &b) {
  int len = a.size() + b.size() - 1;
  if (a.size() <= 16 || b.size() <= 16) {
    Poly c(len);
    for (size_t i = 0; i < a.size(); i++)
      for (size_t j = 0; j < b.size(); j++)
        c[i + j] = (c[i + j] + 1LL * a[i] * b[j]) % P;
    return c;
  }
  int n = norm(len);
  Poly foo = a;
  foo.resize(n);
  dft(foo);
  if (&a == &b) {
    dotEq(foo, foo);
  } else {
    Poly bar = b;
    bar.resize(n);
    dft(bar);
    dotEq(foo, bar);
  }
  idft(foo);
  foo.resize(len);
  return foo;
}
Poly &operator*=(Poly &a, int b) { for (auto &x : a) x = 1LL * x * b % P; return a; }
Poly operator*(Poly a, int b) { return a *= b; }
Poly operator*(int a, Poly b) { return b *= a; }
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
std::pair<Poly, Poly> div(Poly a, Poly b) { 

  int m = b.size();
  Poly c = a / b;
  b = b * c;
  a.resize(m - 1);
  for (int i = 0; i < m - 1; i++) inc(a[i], P - b[i]);
  return {c, a};
}
Poly operator%(Poly a, Poly b) {  

  return div(a, b).second;
}
Poly sqrt(Poly a) {
  int raw = a.size();
  int d = 0;
  while (d < raw && !a[d]) d++;
  if (d == raw) return a;
  assert(~d & 1); 

  norm(a >>= d);
  int len = a.size();  
  Poly b(len), binv(1), bsqr{a[0]}, foo, bar;  

  b[0] = [](int x) {
    int ans = 0;
    for (int i = 0, w = P - 1, o = G, p = 1; i < 25; i++) {
      int v = i > 22 ? i == 23 ? 7 : 17 : 2;
      for (w /= v; fpow(x, w) != 1; x = 1LL * x * o % P) {
        (ans += p) >= P - 1 ? ans -= P - 1 : 0;
      }
      p = 1LL * p * v % P;
      o = fpow(o, v);
    }
    x = fpow(G, (P - 1 - ans) >> 1);
    return x < P - x ? x : P - x;
  }(a[0]);
  binv[0] = fpow(b[0]);  

  auto shift = [](int x) { return (x & 1 ? x + P : x) >> 1; };  

  for (int m = 1, n = 2; n <= len; m <<= 1, n <<= 1) {
    foo.resize(n), bar = binv;
    for (int i = 0; i < m; i++) {
      foo[i] = 0;
      int &x = foo[i + m] = a[i] + a[i + m] - bsqr[i];
      if (x >= P) x -= P;
      if (x < 0) x += P;
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
  assert(f.size() == g.size());
  int len = f.size(), m = 1 << std::__lg(len * 2 - 1);
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
    id1(a.data(), m);
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
int id0(Poly f, Poly g, int64_t n) {
  g = invRange(g, n - ((int)f.size() - 1), n);
  g = f * g;
  return g[f.size() - 1];
}
}  


using namespace Polynomial;

int _add(int a, int b) { a += b; return a >= P ? a - P : a; }
int _sub(int a, int b) { a -= b; return a < 0 ? a + P : a; }
int _mul(int a, int b) { return 1ll * a * b % P; }

const int N = 5e5 + 10;

int fac[N];
void init(int n) 
{
    fac[0] = 1;
    for(int i = 1; i <= n; ++ i) fac[i] = _mul(fac[i - 1], i);
}
 
int a[N], n;
 
Poly solve(int l, int r) 
{
    if (l == r) return {1, a[l]};
    int mid = l + r >> 1;
    return solve(l, mid) * solve(mid + 1, r);
}
 
int main() 
{
    init(N - 5);
    scanf("%d", &n);
    for(int i = 1; i < n; ++ i)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        a[u] ++, a[v] ++;
    }
    for(int i = 2; i <= n; ++ i) a[i] --;
    Poly res = solve(1, n);
    int ans;
    for(int i = 0; i < res.size(); ++ i)
        if(i & 1) ans = _sub(ans, _mul(res[i], fac[n - i]));
        else ans = _add(ans, _mul(res[i], fac[n - i]));
    printf("%d\n", ans);
    return 0;
}