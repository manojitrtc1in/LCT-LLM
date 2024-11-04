#include<bits/stdc++.h>
#define lson (i<<1)
#define rson (i<<1|1)
#define repeat(i, s, n) for(int i = s; i <= n; ++i)
#define foreach(i,items) for(auto &i: items)
#define downrep(i, n, s) for(int i = n; i >= s; --i)
#define lowbit(x) (x&-x)
#define bzero(x) memset(x, 0, sizeof(x))
#define bzeron(x, n) memset(x, 0, (n) * sizeof *x)
#define gcd(a,b) __gcd(a,b)
#define brkline puts("")
#define spaceout putchar(' ')
#define all(a) a.begin(),a.end()
#define pb  push_back



using i64 = long long;
using i32 = int;
const int INF = 0x3f3f3f3f;
const double tol = 1e-8;
const int P = 998244353;

int pop_count(i64 x) {
  return __builtin_popcountll(x);
}
int pop_count(int x) {
  return __builtin_popcount(x);
}

template<typename S, typename T>
bool check_and_save_min_in_lhs(S& lhs, const T& rhs) {
  return lhs < rhs ? 1 : lhs = rhs, 0;
}

template<typename S, typename T>
bool check_and_save_max_in_lhs(S& lhs, const T& rhs) {
  return lhs > rhs ? 1 : lhs = rhs, 0;
}
template<typename T>
T min_all(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T min_all(T fst_el, Args ...others) {
  return min_all(fst_el, mins(others...));
}

template<typename T>
T maxs(T ele) {
  return ele;
}

template<typename T, typename ...Args>
T maxs(T fst_el, Args ...others) {
  return max(fst_el, maxs(others...));
}

template<typename T>
void read_int(T& num) {
  bool positive = true;
  char ch; num = 0;
  while (isspace(ch = getchar()));
  if (ch == '-')  positive = false;
  else num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    num = num * 10 + ch - '0';
  if (!positive) num = -num;
}

void read_ints() {};
template <typename T, typename ...Args>
void read_ints(T& fst_el, Args&... others) { read_int(fst_el);read_ints(others...); }

template<typename T>
void int_out(T num) {
  if (num < 0) {
    putchar('-');
    num = -num;
  }
  if (num > 9)
    int_out(num / 10);
  putchar(num % 10 + '0');
}

void int_outs() { brkline; }
template<typename T, typename ...Args>
void int_outs(T fst_ele, Args ...others) {
  int_out(fst_ele);
  spaceout;
  int_outs(others...);
}

template<class T>
T qpow(T n, int k) {
  T res = 1;
  for (; k; k >>= 1, n *= n) {
    if (k & 1) {
      res *= n;
    }
  }
  return res;
}

template<int P=P>
struct ModInt {
  int x;
  ModInt(int x = 0) : x(mod(x)) {}
  int val() const {
    return x;
  }
  

  int mod(int x) {
    if (x < 0) {
      x += P;
    }
    if (x >= P) {
      x -= P;
    }
    return x;
  }
  void print(char seperator=' ') {
    printf("%d%c", x, seperator);
  }
  void println() {
    printf("%d\n", x);
  }
  ModInt operator-() const {
    return ModInt(P - x);
  }
  ModInt<> inv() const {
    assert(x != 0);
    return qpow(*this, P - 2);
  }
  ModInt<>& operator*=(const ModInt& rhs) {
    x = i64(x) * rhs.x % P;
    return *this;
  }
  ModInt& operator+=(const ModInt& rhs) {
    x = mod(x + rhs.x);
    return *this;
  }
  ModInt& operator-=(const ModInt& rhs) {
    x = mod(x - rhs.x);
    return *this;
  }
  ModInt& operator/=(const ModInt& rhs) {
    return *this *= rhs.inv();
  }
  friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res *= rhs;
    return res;
  }
  friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res += rhs;
    return res;
  }
  friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res -= rhs;
    return res;
  }
  friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) {
    ModInt res = lhs;
    res /= rhs;
    return res;
  }
};

std::vector<int> rev;


std::vector<ModInt<>> roots{ 0, 1 };

namespace fft {
  void dft(std::vector<ModInt<>>& a) {
    int n = a.size();

    if (int(rev.size()) != n) {
      int k = __builtin_ctz(n) - 1;
      rev.resize(n);
      for (int i = 0; i < n; ++i) {
        rev[i] = rev[i >> 1] >> 1 | (i & 1) << k;
      }
    }

    for (int i = 0; i < n; ++i) {
      if (rev[i] < i) {
        std::swap(a[i], a[rev[i]]);
      }
    }
    if (int(roots.size()) < n) {
      int k = __builtin_ctz(roots.size());
      roots.resize(n);
      while ((1 << k) < n) {
        ModInt e = qpow(ModInt(3), (P - 1) >> (k + 1));
        for (int i = 1 << (k - 1); i < (1 << k); ++i) {
          roots[2 * i] = roots[i];
          roots[2 * i + 1] = roots[i] * e;
        }
        ++k;
      }
    }
    for (int k = 1; k < n; k *= 2) {
      for (int i = 0; i < n; i += 2 * k) {
        for (int j = 0; j < k; j++) {
          ModInt u = a[i + j];
          ModInt v = a[i + j + k] * roots[k + j];
          a[i + j] = u + v;
          a[i + j + k] = u - v;
        }
      }
    }
  }

  void idft(std::vector<ModInt<>>& a) {
    int n = a.size();
    std::reverse(a.begin() + 1, a.end());
    dft(a);
    ModInt inv = (1 - P) / n;
    for (int i = 0; i < n; i++) {
      a[i] *= inv;
    }
  }
}

struct Poly {
  std::vector<ModInt<>> coeff;
  Poly() {}
  

  

  Poly(const std::vector<ModInt<>>& coeff) : coeff(coeff) {}
  
  int size() const {
    return coeff.size();
  }
  void resize(int n) {
    coeff.resize(n);
  }
  void reset_degree(int n){
    resize(n + 1);
  }
  void reset_degree_and_init(int n){
    coeff.assign(n + 1, 0);
  }

  ModInt<> operator[](int idx) const {
    if (idx < 0 || idx >= size()) {
      return 0;
    }
    return coeff[idx];
  }
  ModInt<>& operator[](int idx) {
    return coeff[idx];
  }
  
  Poly mulxk(int k) const {
    auto b = coeff;
    b.insert(b.begin(), k, 0);
    return Poly(b);
  }
  
  Poly modxk(int k) const {
    k = std::min(k, size());
    return Poly(std::vector<ModInt<>>(coeff.begin(), coeff.begin() + k));
  }
  
  Poly divxk(int k) const {
    if (size() <= k) {
      return Poly();
    }
    return Poly(std::vector<ModInt<>>(coeff.begin() + k, coeff.end()));
  }
  friend Poly operator+(const Poly& a, const Poly& b) {
    std::vector<ModInt<>> res(std::max(a.size(), b.size()));
    for (int i = 0; i < int(res.size()); i++) {
      res[i] = a[i] + b[i];
    }
    return Poly(res);
  }
  friend Poly operator-(const Poly& a, const Poly& b) {
    std::vector<ModInt<>> res(std::max(a.size(), b.size()));
    for (int i = 0; i < int(res.size()); i++) {
      res[i] = a[i] - b[i];
    }
    return Poly(res);
  }
  friend Poly operator*(Poly a, Poly b) {
    if (a.size() == 0 || b.size() == 0) {
      return Poly();
    }
    int sz = 1, tot = a.size() + b.size() - 1;
    while (sz < tot)
      sz *= 2;
    a.coeff.resize(sz);
    b.coeff.resize(sz);
    fft::dft(a.coeff);
    fft::dft(b.coeff);
    for (int i = 0; i < sz; ++i) {
      a.coeff[i] = a[i] * b[i];
    }
    fft::idft(a.coeff);
    a.resize(tot);
    return a;
  }
  friend Poly operator*(ModInt<> a, Poly b) {
    for (int i = 0; i < int(b.size()); i++) {
      b[i] *= a;
    }
    return b;
  }
  friend Poly operator*(Poly a, ModInt<> b) {
    for (int i = 0; i < int(a.size()); i++) {
      a[i] *= b;
    }
    return a;
  }
  Poly& operator+=(const Poly &b) {
    return (*this) = (*this) + b;
  }
  Poly& operator-=(const Poly &b) {
    return (*this) = (*this) - b;
  }
  Poly& operator*=(const Poly &b) {
    return (*this) = (*this) * b;
  }
  Poly derivate() const {
    if (coeff.empty()) {
      return Poly();
    }
    std::vector<ModInt<>> res(size() - 1);
    for (int i = 0; i < size() - 1; ++i) {
      res[i] = (i + 1) * coeff[i + 1];
    }
    return Poly(res);
  }
  Poly integral() const {
    std::vector<ModInt<>> res(size() + 1);
    for (int i = 0; i < size(); ++i) {
      res[i + 1] = coeff[i] / (i + 1);
    }
    return Poly(res);
  }
  
  Poly inverse(int m) const {
    Poly x({ coeff[0].inv() });
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly({ 2 }) - modxk(k) * x)).modxk(k);
    }
    return x.modxk(m);
  }
  Poly log(int m) const {
    return (derivate() * inverse(m)).integral().modxk(m);
  }
  Poly exp(int m) const {
    Poly x({ 1 });
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x * (Poly({ 1 }) - x.log(k) + modxk(k))).modxk(k);
    }
    return x.modxk(m);
  }
  Poly sqrt(int m) const {
    Poly x({ 1 });
    int k = 1;
    while (k < m) {
      k *= 2;
      x = (x + (modxk(k) * x.inverse(k)).modxk(k)) * ModInt<>((P + 1) / 2);
    }
    return x.modxk(m);
  }

  
  Poly mulT(Poly b) const {
    if (b.size() == 0) {
      return Poly();
    }
    int n = b.size();
    std::reverse(b.coeff.begin(), b.coeff.end());
    return ((*this) * b).divxk(n - 1);
  }


  

  

  

  

  

  

  

  

  


  

  

  

  

  

  

  

  

  

  

  

    
  

  

  

  

  

  

  

  

  

  

  

  


  

  

  

  

};

const int N = 250001;
int degree[N] = {0}, d[N] = {0};

int main() {
  int n;
  read_int(n);
  repeat(i, 2, n) {
    int u, v;
    read_ints(u, v);
    --u; --v;
    ++degree[u];
    ++degree[v];
  }

  d[degree[0]] = 1;
  repeat(i, 1, n - 1) {
    ++d[--degree[i]];
    

  }
  std::vector<ModInt<>> fac(n + 1), invfac(n + 1);
  fac[0] = 1;
  repeat(i, 1, n) fac[i] = fac[i - 1] * i;
  invfac[n] = fac[n].inv();
  downrep(i, n, 1) invfac[i - 1] = invfac[i] * i;
  auto binom = [&](int n, int m) {
    return fac[n] * invfac[m] * invfac[n - m];
  };
  
  Poly p({1}), f;
  

  downrep(i, n - 1, 1) {
    if(!d[i]) continue;
    f.reset_degree(d[i]);
    ModInt v = 1;
    repeat(j, 0, d[i]) {
      f[j] = v * binom(d[i], j);
      v *= i;
      

    }
    std::cout<<std::endl;
    p *= f;
    

    repeat(i, 0, p.size() - 1) {
      

    }
    


  }

  

  ModInt ans = 0;
  repeat(i, 0, p.size() - 1) {
    

    ans += p[i] * fac[n - i] * (i % 2 == 0 ? 1 : -1);
  }
  ans.println();

  return 0;
}