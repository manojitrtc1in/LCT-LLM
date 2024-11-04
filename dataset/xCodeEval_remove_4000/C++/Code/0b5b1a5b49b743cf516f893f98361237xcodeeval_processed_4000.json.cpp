




namespace atcoder {

constexpr int P = 998244353;
using i64 = long long;



int norm(int x) {
  if (x < 0) {
    x += P;
  }
  if (x >= P) {
    x -= P;
  }
  return x;
}
template<class T>
T fpower(T a, i64 b) {
  T res = 1;
  for (; b; b /= 2, a *= a) {
    if (b % 2) {
      res *= a;
    }
  }
  return res;
}
struct Z {
  int x;
  Z(int x = 0) : x(norm(x)) {}
  Z(i64 x) : x(norm(x%P)) {}
  int val() const {
    return x;
  }
  Z operator-() const {
    return Z(norm(P - x));
  }
  Z inv() const {
    assert(x != 0);
    return fpower(*this, P - 2);
  }
  Z &operator*=(const Z &rhs) {
    x = i64(x) * rhs.x % P;
    return *this;
  }
  Z &operator+=(const Z &rhs) {
    x = norm(x + rhs.x);
    return *this;
  }
  Z &operator-=(const Z &rhs) {
    x = norm(x - rhs.x);
    return *this;
  }
  Z &operator/=(const Z &rhs) {
    return *this *= rhs.inv();
  }
  friend Z operator*(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res *= rhs;
    return res;
  }
  friend Z operator+(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res += rhs;
    return res;
  }
  friend Z operator-(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res -= rhs;
    return res;
  }
  friend Z operator/(const Z &lhs, const Z &rhs) {
    Z res = lhs;
    res /= rhs;
    return res;
  }
  friend std::istream &operator>>(std::istream &is, Z &a) {
    i64 v;
    is >> v;
    a = Z(v);
    return is;
  }
  friend std::ostream &operator<<(std::ostream &os, const Z &a) {
    return os << a.val();
  }
};

std::vector<int> rev;
std::vector<Z> roots{0, 1};
void dft(std::vector<Z> &a) {
  int n = a.size();

  if (int(rev.size()) != n) {
    int k = __builtin_ctz(n) - 1;
    rev.resize(n);
    for (int i = 0; i < n; i++) {
      rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
    }
  }

  for (int i = 0; i < n; i++) {
    if (rev[i] < i) {
      std::swap(a[i], a[rev[i]]);
    }
  }
  if (int(roots.size()) < n) {
    int k = __builtin_ctz(roots.size());
    roots.resize(n);
    while ((1 << k) < n) {
      Z e = fpower(Z(3), (P - 1) >> (k + 1));
      for (int i = 1 << (k - 1); i < (1 << k); i++) {
        roots[2 * i] = roots[i];
        roots[2 * i + 1] = roots[i] * e;
      }
      k++;
    }
  }
  for (int k = 1; k < n; k *= 2) {
    for (int i = 0; i < n; i += 2 * k) {
      for (int j = 0; j < k; j++) {
        Z u = a[i + j];
        Z v = a[i + j + k] * roots[k + j];
        a[i + j] = u + v;
        a[i + j + k] = u - v;
      }
    }
  }
}
void idft(std::vector<Z> &a) {
  int n = a.size();
  std::reverse(a.begin() + 1, a.end());
  dft(a);
  Z inv = (1 - P) / n;
  for (int i = 0; i < n; i++) {
    a[i] *= inv;
  }
}
struct Poly {
  std::vector<Z> a;
  Poly() {}
  Poly(const std::vector<Z> &a) : a(a) {}
  Poly(const std::initializer_list<Z> &a) : a(a) {}
  int size() const {
    return a.size();
  }
  void resize(int n) {
    a.resize(n);
  }
  Z operator[](int idx) const {
    if (idx < size()) {
      return a[idx];
    } else {
      return 0;
    }
  }
  Z &operator[](int idx) {
    return a[idx];
  }
  Poly mulxk(int k) const {
    auto b = a;
    b.insert(b.begin(), k, 0);
    return Poly(b);
  }
  Poly modxk(int k) const {
    k = std::min(k, size());
    return Poly(std::vector<Z>(a.begin(), a.begin() + k));
  }
  Poly divxk(int k) const {
    if (size() <= k) {
      return Poly();
    }
    return Poly(std::vector<Z>(a.begin() + k, a.end()));
  }
  friend Poly operator+(const Poly &a, const Poly &b) {
    std::vector<Z> res(std::max(a.size(), b.size()));
    for (int i = 0; i < int(res.size()); i++) {
      res[i] = a[i] + b[i];
    }
    return Poly(res);
  }
  friend Poly operator-(const Poly &a, const Poly &b) {
    std::vector<Z> res(std::max(a.size(), b.size()));
    for (int i = 0; i < int(res.size()); i++) {
      res[i] = a[i] - b[i];
    }
    return Poly(res);
  }
  friend Poly operator-(const Poly &a) {
    std::vector<Z> res(a.size());
    for (int i = 0; i < int(res.size()); i++) {
      res[i] = -a[i];
    }
    return Poly(res);
  }
  friend Poly operator*(Poly a, Poly b) {
    if (a.size() == 0 || b.size() == 0) {
      return Poly();
    }
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot) {
      sz *= 2;
    }
    a.a.resize(sz);
    b.a.resize(sz);
    dft(a.a);
    dft(b.a);
    for (int i = 0; i < sz; ++i) {
      a.a[i] = a[i] * b[i];
    }
    idft(a.a);
    a.resize(tot);
    return a;
  }
  friend Poly operator*(Z a, Poly b) {
    for (int i = 0; i < int(b.size()); i++) {
      b[i] *= a;
    }
    return b;
  }
  friend Poly operator*(Poly a, Z b) {
    for (int i = 0; i < int(a.size()); i++) {
      a[i] *= b;
    }
    return a;
  }
  Poly &operator+=(Poly b) {
    return (*this) = (*this) + b;
  }
  Poly &operator-=(Poly b) {
    return (*this) = (*this) - b;
  }
  Poly &operator*=(Poly b) {
    return (*this) = (*this) * b;
  }
  Poly deriv() const {
    if (a.empty()) {
      return Poly();
    }
    std::vector<Z> res(size() - 1);
    for (int i = 0; i < size() - 1; ++i) {
      res[i] = (i + 1) * a[i + 1];
    }
    return Poly(res);
  }
  Poly integr() const {
    std::vector<Z> res(size() + 1);
    for (int i = 0; i < size(); ++i) {
      res[i + 1] = a[i] / (i + 1);
    }
    return Poly(res);
  }
  Poly inv(int m) const {
    Poly x{a[0].inv()};
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly{2} - modxk(k) * x)).modxk(k);
    }
    return x.modxk(m);
  }
  Poly log(int m) const {
    return (deriv() * inv(m)).integr().modxk(m);
  }
  Poly exp(int m) const {
    Poly x{1};
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly{1} - x.log(k) + modxk(k))).modxk(k);
    }
    return x.modxk(m);
  }
  Poly pow(int k, int m) const {
    int i = 0;
    while (i < size() && a[i].val() == 0) {
      i++;
    }
    if (i == size() || 1LL * i * k >= m) {
      return Poly(std::vector<Z>(m));
    }
    Z v = a[i];
    auto f = divxk(i) * v.inv();
    return (f.log(m - i * k) * k).exp(m - i * k).mulxk(i * k) * fpower(v, k);
  }
  Poly sqrt(int m) const {
    Poly x{1};
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x + (modxk(k) * x.inv(k)).modxk(k)) * ((P + 1) / 2);
    }
    return x.modxk(m);
  }
  Poly mulT(Poly b) const {
    if (b.size() == 0) {
      return Poly();
    }
    int n = b.size();
    std::reverse(b.a.begin(), b.a.end());
    return ((*this) * b).divxk(n - 1);
  }
  std::vector<Z> eval(std::vector<Z> x) const {
    if (size() == 0) {
      return std::vector<Z>(x.size(), 0);
    }
    const int n = std::max(int(x.size()), size());
    std::vector<Poly> q(4 * n);
    std::vector<Z> ans(x.size());
    x.resize(n);
    std::function<void(int, int, int)> build = [&](int p, int l, int r) {
      if (r - l == 1) {
        q[p] = Poly{1, -x[l]};
      } else {
        int m = (l + r) / 2;
        build(2 * p, l, m);
        build(2 * p + 1, m, r);
        q[p] = q[2 * p] * q[2 * p + 1];
      }
    };
    build(1, 0, n);
    std::function<void(int, int, int, const Poly &)> work = [&](int p, int l, int r, const Poly &num) {
      if (r - l == 1) {
        if (l < int(ans.size())) {
          ans[l] = num[0];
        }
      } else {
        int m = (l + r) / 2;
        work(2 * p, l, m, num.mulT(q[2 * p + 1]).modxk(m - l));
        work(2 * p + 1, m, r, num.mulT(q[2 * p]).modxk(r - m));
      }
    };
    work(1, 0, n, mulT(q[1].inv(n)));
    return ans;
  }
};

namespace simp {
  std::vector<Z> fac, ifac, invn;
  void check(int x) {
    if (fac.empty()) {
      fac={Z(1), Z(1)};
      ifac={Z(1), Z(1)};
      invn={Z(0), Z(1)};
    }
    while (fac.size()<=x) {
      int n = fac.size(), m = fac.size() * 2;
      fac.resize(m);
      ifac.resize(m);
      invn.resize(m);
      for (int i=n;i<m;i++) {
        fac[i]=fac[i-1]*Z(i);
        invn[i]=Z(P-P/i)*invn[P%i];
        ifac[i]=ifac[i-1]*invn[i];
      }
    }
  }
  Z gfac(int x) {
    check(x); return fac[x];
  }
  Z ginv(int x) {
    check(x); return invn[x];
  }
  Z gifac(int x) {
    check(x); return ifac[x];
  }
  Z binom(int n,int m) {
    if (m < 0 || m > n) return Z(0);
    return gfac(n)*gifac(m)*gifac(n - m);
  }
}

}

using namespace std;
using i64 = long long;

const int maxn = 500050;

i64 gao(i64 a[], int n, i64 d, int typ) {
  if (n == 0) {
    return d > 0;
  }
  static i64 cp[maxn];
  cp[0] = 0;
  for (int i = 1; i <= n; ++i) {
    cp[i] = cp[i-1];
    if (i & 1) {
      cp[i] -= a[i];
    } else {
      cp[i] += a[i];
    }
  }
  static i64 suf[maxn];
  suf[n+1] = 0;
  for (int i = n; i > 0; --i) {
    suf[i] = suf[i+1] + a[i];
  }

  i64 res = 0;
  res += (-suf[1] + d > 0); 

  res += (suf[1] + d > 0); 

  i64 sum = 0;
  int st = 1;
  if (typ == 2 || typ == 4) { 

    res -= (suf[1] + d > 0); 

    st = 0;
    sum = +a[0];
  }
  int y[2] = {n, n};
  for (int i = 0; i < 2; ++i) {
    if ((y[i] & 1) ^ i) {
      if (typ == 1 || typ == 2) {
        y[i]--;
      } else {
        y[i]++;
      }
    }
  }
  for (int i = st; i < n; ++i) { 

    sum += -a[i];
    if (sum + suf[i+1] + d <= 0) {
      break;
    }

    int& Y = y[(i+1)&1];
    while (true) {
      assert(Y >= i);
      i64 tmp = sum + d + suf[Y];
      if (i & 1) {
        tmp += cp[Y-1] - cp[i];
      } else {
        tmp -= cp[Y-1] - cp[i];
      }
      if (tmp > 0) {
        break;
      }
      Y -= 2;
    }
    
    res += (Y - (i+1)) / 2 + 1;
  }
  if (typ == 1) { 

    for (int i = 1; i < n; ++i) {
      if (suf[1] - suf[i+1] - suf[i+1] + d > 0) {
        res += 1;
      }
    }
  }
  return res;
}


inline int read(){
  int x=0,f=0; char ch=getchar();
  while(!isdigit(ch)) f|=(ch==45),ch=getchar();
  while(isdigit(ch)) x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
  return f?-x:x;
}

void once() {
  int n = read();
  static i64 a[maxn];
  for (int i = 1; i <= n; ++i) {
    a[i] = read();
  }
  if (n == 1) {
    puts("1");
    return;
  }
  i64 res = gao(a+1, n-2, a[1]-a[n], 1); 

  res += gao(a+1, n-2, -a[1]-a[n], 2); 

  res += gao(a+1, n-2, a[1]+a[n], 3); 

  res += gao(a+1, n-2, -a[1]+a[n], 4); 

  printf("%lld\n", res % atcoder::P);
}

int main() {
  int tes = read();
  while (tes--) {
    once();
  }
  return 0;
}
