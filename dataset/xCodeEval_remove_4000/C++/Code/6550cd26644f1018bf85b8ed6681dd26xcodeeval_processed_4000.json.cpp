

using namespace std;
using i64 = long long;

template<i64 M>
constexpr i64 id1(i64 val) {
    i64 a = M, b = val;
    i64 x = 0, u = 1;
    while (b) {
        i64 t = a / b;
        swap(a -= t * b, b);
        swap(x -= t * u, u);
    }
    return x < 0 ? x + M : x;
}

template<i64 M>
struct modint {
  i64 a;
  constexpr modint(const i64 x = 0) noexcept: a((x % M + M) % M) {}
  constexpr i64 value() const noexcept { return a; }
  constexpr modint inv() const noexcept { return modint(id1<M>(a)); }
  constexpr modint pow(i64 r) const noexcept {
    modint ans(1);
    modint aa = *this;
    while(r) {
      if(r & 1) {
        ans *= aa;
      }
      aa *= aa;
      r >>= 1;
    }
    return ans;
  }
  constexpr modint& operator+=(const modint r) noexcept {
    a += r.a;
    if(a >= M) a -= M;
    return *this;
  }
  constexpr modint& operator=(const i64 r) {
    a = (r % M + M) % M;
    return *this;
  }
  constexpr modint& operator-=(const modint r) noexcept {
    a -= r.a;
    if(a < 0) a += M;
    return *this;
  }
  constexpr modint& operator*=(const modint r) noexcept {
    a = a * r.a % M;
    return *this;
  }
  constexpr modint& operator/=(modint r) noexcept {
    i64 ex = M - 2;
    while(ex) {
      if(ex & 1) {
        *this *= r;
      }
      r *= r;
      ex >>= 1;
    }
    return *this;
  }

  constexpr modint operator+(const modint r) const {
    return modint(*this) += r;
  }
  constexpr modint operator-(const modint r) const {
    return modint(*this) -= r;
  }
  constexpr modint operator*(const modint r) const {
    return modint(*this) *= r;
  }
  constexpr modint operator/(const modint r) const {
    return modint(*this) /= r;
  }

  constexpr bool operator!=(const modint r) const {
    return this->value() != r.value();
  }

};

constexpr i64 NTT_PRIMES[][2] = {
    {1224736769, 3}, 

    {1053818881, 7}, 

    {1051721729, 6}, 

    {1045430273, 3}, 

    {1012924417, 5}, 

    {1007681537, 3}, 

    {1004535809, 3}, 

    {998244353, 3},  

    {985661441, 3},  

    {976224257, 3},  

    {975175681, 17}, 

    {962592769, 7},  

    {950009857, 7},  

    {943718401, 7},  

    {935329793, 3},  

    {924844033, 5},  

    {469762049, 3},  

    {167772161, 3},  

};

template<const i64 mod, const i64 primitive>
vector<modint<mod>> id5(vector<modint<mod>> a) {
  i64 n = a.size();
  vector<modint<mod>> b(a.size());
  auto unit_i = modint<mod>(primitive).pow((mod - 1) / 4);
  for(i64 s = 1, m = n; s < n; s <<= 1, m >>= 1) {
    if(m == 2) {
      for(i64 j = 0;j < s;j++) {
        auto x = a[j + 0];
        auto y = a[j + s];
        b[j + 0] = x + y;
        b[j + s] = x - y;
      }
    }
    else {
      modint<mod> zi1 = 1;
      modint<mod> zi2 = 1;
      modint<mod> zi3 = 1;
      i64 m1 = m >> 2;
      i64 m2 = m >> 1;
      i64 m3 = m1 | m2;
      modint<mod> zeta = modint<mod>(primitive).pow((mod - 1) / m);
      for(i64 i = 0;i < m1;i++) {
        for(i64 j = 0;j < s;j++) {
          auto w = a[j + s * (i + 0)];
          auto x = a[j + s * (i + m1)];
          auto y = a[j + s * (i + m2)];
          auto z = a[j + s * (i + m3)];
          auto wy1 = w + y;
          auto wy2 = w - y;
          auto xz1 = x + z;
          auto xz2 = (x - z) * unit_i;
          b[j + s * (4 * i + 0)] =  wy1 + xz1;
          b[j + s * (4 * i + 1)] = (wy2 + xz2) * zi1;
          b[j + s * (4 * i + 2)] = (wy1 - xz1) * zi2;
          b[j + s * (4 * i + 3)] = (wy2 - xz2) * zi3;
        }
        zi1 = zi1 * zeta;
        zi2 = zi1 * zi1;
        zi3 = zi1 * zi2;
      }
      s <<= 1;
      m >>= 1;
    }
    swap(a, b);
  }
  return a;
}

template<const i64 mod, const i64 primitive>
vector<modint<mod>> id3(vector<modint<mod>> a) {
  i64 n = a.size();
  vector<modint<mod>> b(a.size());
  auto unit_i = modint<mod>(primitive).pow((mod - 1) / 4).inv();
  i64 s = n;
  i64 m = 1;
  if(__builtin_ctzll(n) & 1) {
    s >>= 1;
    m <<= 1;
    for(i64 j = 0;j < s;j++) {
      auto x = a[j + 0];
      auto y = a[j + s];
      b[j + 0] = x + y;
      b[j + s] = x - y;
    }
    swap(a, b);
  }
  for(; s >>= 2, m <<= 2, s >= 1;) {
    {
      modint<mod> zi1 = 1;
      modint<mod> zi2 = 1;
      modint<mod> zi3 = 1;
      i64 m1 = m >> 2;
      i64 m2 = m >> 1;
      i64 m3 = m1 | m2;
      modint<mod> zeta = modint<mod>(primitive).pow((mod - 1) / m).inv();
      for(i64 i = 0;i < m1;i++) {
        for(i64 j = 0;j < s;j++) {
          auto w = a[j + s * (4 * i + 0)];
          auto x = a[j + s * (4 * i + 1)] * zi1;
          auto y = a[j + s * (4 * i + 2)] * zi2;
          auto z = a[j + s * (4 * i + 3)] * zi3;
          auto wy1 = w + y;
          auto wy2 = x + z;
          auto xz1 = w - y;
          auto xz2 = (x - z) * unit_i;
          b[j + s * (i + 0)]  = wy1 + wy2;
          b[j + s * (i + m1)] = xz1 + xz2;
          b[j + s * (i + m2)] = wy1 - wy2;
          b[j + s * (i + m3)] = xz1 - xz2;
        }
        zi1 = zi1 * zeta;
        zi2 = zi1 * zi1;
        zi3 = zi1 * zi2;
      }
    }
    swap(a, b);
  }
  auto inv_n = modint<mod>(n).pow(mod - 2);
  for(int i = 0;i < n;i++) a[i] *= inv_n;
  return a;
}

template<const i64 mod, const i64 primitive>
vector<modint<mod>> id0(vector<modint<mod>> a) {
  i64 n = a.size(); vector<modint<mod>> b(a.size()); for(i64 s = 1; s < n; s <<= 1) { i64 m = n / 2 / s;
    modint<mod> zeta = modint<mod>(primitive).pow((mod - 1) / (m << 1));
    modint<mod> zi = 1;
    for(i64 i = 0;i < m;i++) {
      for(i64 j = 0;j < s;j++) {
        auto x = a[j + s * (i + 0)];
        auto y = a[j + s * (i + m)];
        b[j + s * (2 * i + 0)] = x + y;
        b[j + s * (2 * i + 1)] = (x - y) * zi;
      }
      zi = zi * zeta;
    }
    swap(a, b);
  }
  return a;
}

template<const i64 mod, const i64 primitive>
vector<modint<mod>> id2(vector<modint<mod>> a) {
  i64 n = a.size();
  vector<modint<mod>> b(a.size());
  for(i64 s = n; s >>= 1, s >= 1;) {
    i64 m = n / 2 / s;
    modint<mod> zeta = modint<mod>(primitive).pow((mod - 1) / (m << 1)).pow(mod - 2);
    modint<mod> zi = 1;
    for(i64 i = 0;i < m;i++) {
      for(i64 j = 0;j < s;j++) {
        auto x = a[j + s * (2 * i + 0)];
        auto y = a[j + s * (2 * i + 1)] * zi;
        b[j + s * (i + 0)] = x + y;
        b[j + s * (i + m)] = x - y;
      }
      zi = zi * zeta;
    }
    swap(a, b);
  }
  auto inv_n = modint<mod>(n).pow(mod - 2);
  for(int i = 0;i < n;i++) a[i] *= inv_n;
  return a;
}



namespace niu {
  char cur;
  struct FIN {
    static inline bool is_blank(char c) { return c <= ' '; }
    inline char next() { return cur = _getc_nolock(stdin); }
    inline char peek() { return cur; }
    inline void skip() { while(is_blank(next())){} }

    FIN& operator>>(inttype& n) { \
      bool sign = 0; \
      n = 0; \
      skip(); \
      while(!is_blank(peek())) { \
        if(peek() == '-') sign = 1; \
        else n = (n << 1) + (n << 3) + (peek() & 0b1111); \
        next(); \
      } \
      if(sign) n = -n; \
      return *this; \
    }
intin(int)
intin(long long)
  } fin;

  char tmp[128];
  struct FOUT {
    static inline bool is_blank(char c) { return c <= ' '; }
    inline void push(char c) { _putc_nolock(c, stdout); }
    FOUT& operator<<(char c) { push(c); return *this; }
    FOUT& operator<<(const char* s) { while(*s) push(*s++); return *this; }

    FOUT& operator<<(inttype n) { \
      if(n) { \
        char* p = tmp + 127; bool neg = 0; \
        if(n < 0) neg = 1, n = -n; \
        while(n) *--p = (n % 10) | 0b00110000, n /= 10; \
        if(neg) *--p = '-'; \
        return (*this) << p; \
      } \
      else { \
        push('0'); \
        return *this; \
      } \
    }
intout(int)
intout(long long)
  } fout;
}



using i64 = long long;

template<class T>
void id4(std::vector<T>& fact, std::vector<T>& finv, std::vector<T>& bin) {
  std::size_t N = fact.size();
  fact[0] = T(1);
  bin[0] = T(1);
  for(int i = 1;i < N;i++) {
    fact[i] = fact[i - 1] * T(i);
    bin[i] = bin[i - 1] * T(2);
  }
  finv[N - 1] = T(1) / fact[N - 1];
  for(int i = N - 1; i --> 0;) {
    finv[i] = finv[i + 1] * T(i + 1);
  }
}

int MAX = 300001;
using fp = modint<998244353>;

int main() {
  using niu::fin;
  using niu::fout;

  i64 N, K;
  fin >> N >> K;
  N++;
  vector<int> a(N);
  for(int i = 0;i < N - 1;i++) {
    fin >> a[i];
  }
  a[N - 1] = MAX;
  vector<int> b(K);
  for(int i = 0;i < K;i++) {
    fin >> b[i];
  }
  sort(begin(a), end(a));
  sort(begin(b), end(b));

  vector<fp> ans(1200001);
  int j = 0;
  int p = 0;
  int q = 0;
  vector<fp> fact(MAX), finv(MAX), bin(MAX);
  id4(fact, finv, bin);
  for(int i = 0;i < N; i++) {
    if(i < N - 1 && a[i] == a[i + 1]) continue;
    while(j < K && b[j] <= a[i]) {
      int len = 2;
      while(len < p + q + 1) len *= 2;
      vector<fp> f(len);
      vector<fp> g(len);
      for(int i = 0; i <= p; i++) {
        f[i] = fact[p] * finv[i] * finv[p - i] * bin[i];
      }
      for(int i = 0; i <= q; i++) {
        g[i] = fact[q] * finv[i] * finv[q - i];
      }
      f = id5<998244353, 3>(std::move(f));
      g = id5<998244353, 3>(std::move(g));
      for(int i = 0;i < len;i++) {
        f[i] *= g[i];
      }
      f = id3<998244353, 3>(std::move(f));
      for(int i = 0;i <= p + q; i++) {
        if(ans.size() <= 2 * (b[j] + i + 1)) break;
        ans[2 * (b[j] + i + 1)] += f[i];
      }
      j++;
    }
    if(0 < i && a[i - 1] == a[i]) q += 2;
    else p++;
  }
  int Q;
  fin >> Q;
  for(int i = 0;i < Q;i++) {
    int q;
    fin >> q;
    fout << ans[q].value() << "\n";
  }
}
