







namespace {

using LL = long long;
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
template<typename T, typename U> bool enlarge(T& a, U b) { return a < b ? (a = b, true) : false; }
template<typename T, typename U> bool minify(T& a, U b) { return a > b ? (a = b, true) : false; }


template<int MOD>
struct Integral {
  int v_ = 0;

  

  Integral(int v) : v_(norm(v)) {}
  Integral(long long v) : v_(norm(v)) {}
  Integral(unsigned int v) : v_(norm(v)) {}
  Integral(unsigned long long v) : v_(norm(v)) {}
  Integral() = default;
  ~Integral() = default;

  template<typename T> T norm(T v) const {
    if constexpr(sizeof(T) > sizeof(MOD)) {
      v %= MOD;
      if (v < 0) v += MOD;
    } else {
      if (v >= MOD) v -= MOD;
      if (v < 0) v += MOD;
      if (v >= MOD || v < 0) {
        v %= MOD;
        if (v < 0) v += MOD;
      }
    }
    return v;
  }

  int val() const { return v_; }
  Integral& operator+=(const Integral& rhs) { v_ += rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator-=(const Integral& rhs) { v_ += MOD - rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator*=(const Integral& rhs) { v_ = v_ * 1LL * rhs.val() % MOD; return *this; }
  Integral& operator/=(const Integral& rhs) { v_ = v_ * 1LL * rhs.inv().val() % MOD; return *this; }
  Integral operator+(const Integral& rhs) const { Integral ret = *this; return ret += rhs; }
  Integral operator-(const Integral& rhs) const { Integral ret = *this; return ret -= rhs; }
  Integral operator*(const Integral& rhs) const { Integral ret = *this; return ret *= rhs; }
  Integral operator/(const Integral& rhs) const { Integral ret = *this; return ret /= rhs; }
  bool operator==(const Integral& rhs) const { return val() == rhs.val(); }
  bool operator!=(const Integral& rhs) const { return !(*this == rhs); }
  const Integral operator-() const { return Integral(-val()); }
  const Integral& operator++() { v_ += 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator++(int) { Integral ret = *this; ++(*this); return ret; }
  const Integral& operator--() { v_ += MOD - 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator--(int) { Integral ret = *this; --(*this); return ret; }

  Integral power(long long b) const {
    long long ret = 1 % MOD, a = v_;
    for ( ; b; b >>= 1, a = a * a % MOD) if (b & 1) ret = ret * a % MOD; return ret;
  }
  Integral inv() const { return power(MOD - 2); }

  std::string to_string() const { return std::string("{") + std::to_string(val()) + "}"; }
};

template<int MOD>
std::string to_string(const Integral<MOD>& v) {
  return v.to_string();
}

template<int MOD, bool id10 = false>
struct Binomial final {
  std::vector<Integral<MOD>> fact, inv_fact;

  explicit Binomial(int n = 0) : fact(n + 1), inv_fact(n + 1) {
    fact[0] = 1;
    for (int i = 1; i <= n; ++i) fact[i] = fact[i - 1] * i;
    inv_fact[n] = fact[n].inv();
    for (int i = n; i >= 1; --i) inv_fact[i - 1] = inv_fact[i] * i;
  }
  ~Binomial() = default;

  template<typename T>
  Integral<MOD> operator()(T a, T b) const {
    if (a < b || b < 0) return 0;
    if (a < fact.size()) return fact[a] * inv_fact[b] * inv_fact[a - b];
    if constexpr(!id10) {
      throw std::out_of_range("Binomial");
    } else {
      b = std::min(b, a - b);
      Integral<MOD> ret = 1;
      for (T i = 1; i <= b; ++i) {
        ret = ret * (a + 1 - i);
        if (i < inv_fact.size()) {
          ret = ret * inv_fact[i] * fact[i - 1];
        } else {
          ret = ret / i;
        }
      }
      return ret;
    }
  }
};

template<int MOD>
struct PowerTable final : public std::vector<Integral<MOD>> {
  PowerTable() = default;
  PowerTable(int n, const Integral<MOD>& g) {
    static_assert(sizeof(PowerTable) == sizeof(std::vector<Integral<MOD>>), "");
    this->resize(n + 1);
    this->at(0) = 1;
    this->at(1) = g;
    for (int i = 2; i < this->size(); ++i) this->at(i) = this->at(i - 1) * this->at(1);
  }
};

const int MOD = 998244353;
using Mint = Integral<MOD>;
using Binom = Binomial<MOD>;
using Power = PowerTable<MOD>;






template<int MOD>
constexpr int id13() {
  if constexpr(MOD == 998244353) return 3;
  else if constexpr(MOD == 924844033) return 5;
  assert(false);
}

template<int MOD = 998244353>
void ntt(Integral<MOD> A[], int n, int inv) {
  


  

  

  

  constexpr int primitive_root = id13<MOD>();
  Integral<MOD> w = 1, d = Integral<MOD>(primitive_root).power((MOD - 1) / n), t;
  int i, j, c, s;
  if (inv == -1) {
    for (i = 1, j = n - 1; i < j; ++i, --j) std::swap(A[i], A[j]);
    for (t = Integral<MOD>(n).inv(), i = 0; i < n; ++i) A[i] = A[i] * t;
  }
  for (s = n >> 1; s; s >>= 1, w = 1, d = d * d) {
    for (c = 0; c < s; ++c, w = w * d) {
      for (i = c; i < n; i += s << 1) {
        A[i | s] = (A[i] - (t = A[i | s])) * w;
        A[i] += t;
      }
    }
  }
  for (i = 1; i < n; ++i) {
    for (j = 0, s = i, c = n >> 1; c; c >>= 1, s >>= 1) j = j << 1 | (s & 1);
    if (i < j) std::swap(A[i], A[j]);
  }
}

template<typename T>
struct Polynomial final : public std::vector<T> {
  Polynomial() = default;
  explicit Polynomial(int n) : std::vector<T>(n) {}
  Polynomial(int n, const T& val) : std::vector<T>(n, val) {}
  Polynomial(std::initializer_list<T> initializer_list) : std::vector<T>(std::move(initializer_list)) {}
  Polynomial(std::vector<T> vec) : std::vector<T>(std::move(vec)) {}
  int size() const { return std::vector<T>::size(); }
  T get(int pos) const { return pos >= 0 && pos < size() ? (*this)[pos] : T(0); }
  T& touch(int pos) { if (pos >= size()) std::vector<T>::resize(pos + 1, T(0)); return (*this)[pos]; }
  Polynomial mod(int n) const { return Polynomial(std::vector<T>(this->data(), this->data() + std::min(n, size()))); }
};

template<typename T>
void ntt(Polynomial<T>& poly, int n, int inv) {
  if (poly.size() < n) {
    poly.resize(n, 0);
  }
  return ntt(&poly[0], n, inv);
}

template<typename T>
void norm(Polynomial<T>& p) {
  while (p.size() > 1 && p.back() == T(0)) p.pop_back();
}

template<typename T>
Polynomial<T>& operator+=(Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  lhs.resize(std::max(lhs.size(), rhs.size()), T(0));
  for (int i = 0; i < rhs.size(); ++i) lhs[i] += rhs[i];
  norm(lhs);
  return lhs;
}

template<typename T>
Polynomial<T> operator+(Polynomial<T> lhs, const Polynomial<T>& rhs) {
  return lhs += rhs;
}

template<typename T>
Polynomial<T>& operator-=(Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  lhs.resize(std::max(lhs.size(), rhs.size()), T(0));
  for (int i = 0; i < rhs.size(); ++i) lhs[i] -= rhs[i];
  norm(lhs);
  return lhs;
}

template<typename T>
Polynomial<T> operator-(Polynomial<T> lhs, const Polynomial<T>& rhs) {
  return lhs -= rhs;
}

template<typename T>
Polynomial<T> mod_len(Polynomial<T> poly, int len) {
  

  if (poly.size() > len) {
    poly.resize(len);
  }
  norm(poly);
  return poly;
}

template<typename T>
Polynomial<T> id9(Polynomial<T> poly, int len) {
  poly.resize(len, 0);
  return poly;
}

int id4(int w) {
  if (w <= 0) return 1;
  const int highbit = 31 - __builtin_clz(w);
  return (1 << (highbit + 1));
}

template<typename T>
int id7(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return id4((int)lhs.size() + (int)rhs.size() - 2);
}

template<typename T>
Polynomial<T> operator*(Polynomial<T> lhs, Polynomial<T> rhs) {
  CHECK(lhs.size() + rhs.size() > 0);
  const int L = id7(lhs, rhs);
  lhs.resize(L, 0);
  rhs.resize(L, 0);
  ntt(lhs, L, 1);
  ntt(rhs, L, 1);
  for (int i = 0; i < L; ++i) lhs[i] *= rhs[i];
  ntt(lhs, L, -1);
  norm(lhs);
  return lhs;
}

template<typename T>
Polynomial<T> operator*(T a, Polynomial<T> p) {
  for (int i = 0; i < p.size(); ++i) p[i] *= a;
  norm(p);
  return p;
}

template<typename T>
Polynomial<T> operator*(const Polynomial<T>& p, T a) {
  return a * p;
}

template<typename T>
Polynomial<T> mod_inv(Polynomial<T> poly, int len = 0) {
  

  CHECK(poly.size() >= 1 && poly[0] != 0);
  if (len == 0) len = poly.size();
  if (len > poly.size()) poly.resize(len);
  


  const int L = id4(len - 1);
  poly.resize(L, 0);
  Polynomial<T> w(L << 1), r(L << 1), saved(L << 1);
  w[0] = poly[0].inv();
  for (int len = 2; len <= L; len <<= 1) {
    std::copy(w.begin(), w.begin() + (len >> 1), r.begin());
    std::copy(poly.begin(), poly.begin() + len, saved.begin());
    ntt(saved, len, 1);
    ntt(r, len, 1);
    for (int i = 0; i < len; ++i) r[i] *= saved[i];
    ntt(r, len, -1);
    for (int i = 0; i < (len >> 1); ++i) r[i] = 0;
    std::copy(w.begin(), w.begin() + len, saved.begin());
    ntt(saved, len, 1);
    ntt(r, len, 1);
    for (int i = 0; i < len; ++i) r[i] *= saved[i];
    ntt(r, len, -1);
    for (int i = (len >> 1); i < len; ++i) w[i] = w[i] + w[i] - r[i];
  }
  return mod_len(w, len);
}

template<typename T>
Polynomial<T> div(Polynomial<T> lhs, Polynomial<T> rhs) {  

  norm(lhs);
  norm(rhs);
  if (lhs.size() < rhs.size()) return Polynomial<T>(1, T(0));
  std::reverse(lhs.begin(), lhs.end());
  std::reverse(rhs.begin(), rhs.end());
  int len = (int)lhs.size() - 1 - (int)rhs.size() + 1 + 1;
  Polynomial<T> Q = id9(lhs * mod_inv(rhs, len), len);
  std::reverse(Q.begin(), Q.end());
  norm(Q);
  return Q;
}

template<typename T>
Polynomial<T> operator%(Polynomial<T> lhs, Polynomial<T> rhs) {
  Polynomial<T> Q = div(lhs, rhs);
  return lhs - Q * rhs;
}

template<typename T>
T eval(const Polynomial<T>& poly, T a) {  

  T ret = 0;
  T w = 1;
  for (int i = 0; i < poly.size(); ++i) {
    ret += w * poly[i];
    w *= a;
  }
  return ret;
  

}

template<typename T>
std::vector<T> id11(const Polynomial<T>& poly, const std::vector<T>& a) {  

  

  int m = a.size();
  std::vector<Polynomial<T>> bucket(m * 2 - 1);
  auto get_id = [](int l, int r) -> int {
    return (l + r) | (l != r);
  };
  std::function<void(int,int)> prepare = [&](int l, int r) -> void {
    Polynomial<T>& p = bucket[get_id(l, r)];
    if (l == r) {
      p = Polynomial<T>{-a[l], 1};
      return;
    }
    int mid = (l + r) >> 1;
    prepare(l, mid);
    prepare(mid + 1, r);
    p = bucket[get_id(l, mid)] * bucket[get_id(mid + 1, r)];
  };
  prepare(0, m - 1);
  std::vector<T> result(m);
  std::function<void(int, int, Polynomial<T>)> divide = [&](int l, int r, Polynomial<T> poly) -> void {
    poly = poly % bucket[get_id(l, r)];
    if (l == r) {
      result[l] = poly.get(0);
      return;
    }
    int mid = (l + r) >> 1;
    divide(l, mid, poly);
    divide(mid + 1, r, poly);
  };
  divide(0, m - 1, poly);
  return result;
}

template<typename T>
Polynomial<T> derivate(Polynomial<T> poly) {
  if (poly.size() <= 1) {
    return Polynomial<T>(1, 0);
  }
  for (int i = 1; i < poly.size(); ++i) {
    poly[i - 1] = poly[i] * i;
  }
  poly.pop_back();
  norm(poly);
  return poly;
}

template<typename T>
Polynomial<T> integrate(Polynomial<T> poly) {
  if (poly.size() == 0) {
    return poly;
  }
  poly.emplace_back(0);
  for (int i = (int)poly.size() - 1; i > 0; --i) {
    poly[i] = poly[i - 1] / i;
  }
  poly[0] = 0;
  norm(poly);
  return poly;
}

template<typename T>
Polynomial<T> id0(Polynomial<T> poly, int len = 0) {
  

  CHECK(poly.size() >= 1 && poly[0] == 1);  

  if (len > poly.size()) poly.resize(len);
  if (poly.size() == 1) {
    return poly;
  }
  if (len == 0) len = poly.size();
  const int L = id4(len - 1);
  poly.resize(L, 0);
  Polynomial<T> buffer(1, 1), buffer1;
  for (int len = 2; len <= L; len <<= 1) {
    buffer1 = mod_inv(T(2) * buffer, len);
    ntt(buffer, len, 1);
    for (int i = 0; i < len; ++i) buffer[i] *= buffer[i];
    ntt(buffer, len, -1);
    for (int i = 0; i < len; ++i) buffer[i] += poly[i];
    buffer = id9(buffer * buffer1, len);
  }
  return mod_len(buffer, len);
}

template<typename T>
Polynomial<T> mod_ln(Polynomial<T> poly, int len = 0) {
  

  if (len == 0) len = poly.size();
  if (len > poly.size()) poly.resize(len);
  return mod_len(integrate(derivate(poly) * mod_inv(poly, len)), len);
}

template<typename T>
Polynomial<T> mod_exp(Polynomial<T> poly, int len = 0) {
  

  if (len == 0) len = poly.size();
  if (len > poly.size()) poly.resize(len);
  CHECK(poly.size() == 0 || poly[0] == 0);
  const int L = id4(len - 1);
  poly.resize(L, 0);
  Polynomial<T> p(1, 1);
  for (int len = 2; len <= L; len <<= 1) {
    Polynomial<T> q = p;
    p = id9(mod_ln(p, len), len);
    for (int i = 0; i < len; ++i) p[i] = poly[i] - p[i];
    ++p[0];
    p = mod_len(p * q, len);
  }
  return mod_len(p, len);
}

template<typename T>
Polynomial<T> id3(Polynomial<T> poly, T k, int len = 0) {
  

  CHECK(poly.size() >= 1 && poly[0] != T(0));  

  if (len == 0) len = poly.size();
  T constant = poly[0];
  if (constant != T(1)) {
    T inv_constant = T(1) / constant;
    for (int i = 0; i < poly.size(); ++i) {
      poly[i] *= inv_constant;
    }
  }
  Polynomial<T> ret = mod_exp(k * mod_ln(poly, len), len);
  if (constant != T(1)) {
    constant = constant.power(k.val());
    for (int i = 0; i < ret.size(); ++i) {
      ret[i] *= constant;
    }
  }
  return ret;
}

template<typename T>
Polynomial<T> id12(const Polynomial<T>& poly, int len = 0) {
  

  if (poly.size() < 2) return Polynomial<T>{};
  CHECK(poly[0] == T(0));
  if (len == 0) len = poly.size();
  Polynomial<T> P(len);
  std::vector<T> inv(len);
  for (int i = 1; i < len; ++i) {
    inv[i] = Mint(i).inv();
  }
  for (int i = 1; i < poly.size() && i < len; ++i) if (poly[i].val()) {
    for (int j = 1; i * j < len; ++j) {
      P[i * j] += poly[i] * inv[j];
    }
  }
  return mod_exp(P, len);
}

template<typename T>
T id2(Polynomial<T> poly, int n) {  

  if (poly.empty()) return T(0);
  CHECK(poly[0] == T(0));
  CHECK(poly.size() > 1);
  CHECK(poly[1] != T(0));
  CHECK(n > 0);
  poly.erase(poly.begin());
  return id9(id3(poly, n, n), n)[n - 1] / T(n);
}

template<typename T>
Polynomial<T> id1(const std::vector<T>& x, const std::vector<T>& y) {
  

  

  if (x.empty()) return Polynomial<T>(1, T(0));

  int m = x.size();
  std::vector<Polynomial<T>> bucket(m * 2 - 1);
  auto get_id = [](int l, int r) -> int {
    return (l + r) | (l != r);
  };
  std::function<Polynomial<T>(int,int)> calc_g = [&](int l, int r) -> Polynomial<T> {
    Polynomial<T>& p = bucket[get_id(l, r)];
    if (l == r) {
      return p = Polynomial<T>{-x[l], 1};
    }
    int mid = (l + r) >> 1;
    return p = calc_g(l, mid) * calc_g(mid + 1, r);
  };
  std::vector<T> z(m);
  std::function<void(int, int, Polynomial<T>)> mp_eval = [&](int l, int r, Polynomial<T> poly) -> void {
    poly = poly % bucket[get_id(l, r)];
    if (l == r) {
      z[l] = poly.get(0);
      return;
    }
    int mid = (l + r) >> 1;
    mp_eval(l, mid, poly);
    mp_eval(mid + 1, r, poly);
  };
  mp_eval(0, m - 1, derivate(calc_g(0, (int)x.size() - 1)));
  std::function<Polynomial<T>(int,int)> divide = [&](int l, int r) -> Polynomial<T> {
    if (l == r) {
      return Polynomial<T>(1, y[l] / z[l]);;
    }
    int mid = (l + r) >> 1;
    return divide(l, mid) * bucket[get_id(mid + 1, r)] + divide(mid + 1, r) * bucket[get_id(l, mid)];
  };
  return divide(0, (int)x.size() - 1);
}

template<typename T>
T interpolation(const std::vector<T>& x, const std::vector<T>& y, const T& p) {
  return eval(id1(x, y), p);
}

template<typename T>
Polynomial<T> id8(const Polynomial<T>& poly, T l) {
  const int n = poly.size();
  std::vector<T> x;
  for (int i = 0; i <= n; ++i) x.emplace_back(l + i);
  std::vector<T> y = id11(poly, x);
  for (int i = 1; i < y.size(); ++i) y[i] += y[i - 1];
  return id1(x, y);
}

template<typename T>
T id6(const Polynomial<T>& poly, T l, T r) {  

  

  return eval(id8(poly, l), r);
}

template<typename T, typename OnLeaf>
void id5(OnLeaf&& on_leaf, int l, int r, const Polynomial<T>& A, Polynomial<T>& B) {
  

  if (l == r) {
    on_leaf(l, r);
    return;
  }
  int mid = (l + r) >> 1;
  auto update = [&](const Polynomial<T>& A, const Polynomial<T>& B, Polynomial<T>& output) {
    Polynomial<T> P, Q;
    for (int i = l; i <= mid; ++i) P.touch(i - l) = A.get(i);
    for (int i = 0; i <= std::min(r - l, mid); ++i) Q.touch(i) = B.get(i);
    Polynomial<T> W = P * Q;
    for (int i = mid + 1; i <= r; ++i) output.touch(i) += W.get(i - l);
  };
  id5(std::forward<OnLeaf>(on_leaf), l, mid, A, B);
  update(A, B, B);
  if (l > 1) update(B, A, B);
  id5(std::forward<OnLeaf>(on_leaf), mid + 1, r, A, B);
}

using Poly = Polynomial<Integral<MOD>>;

struct Solver {

  void solve(int ca, std::istream& reader) {
    int n, m;
    reader >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      reader >> a[i];
    }
    std::vector<int> b(n);
    for (int i = 0; i < m; ++i) {
      int x;
      reader >> x; --x;
      b[x] = 1;
    }
    Mint result = 0;

    Power pw2(n, 2);

    std::vector<Mint> prefix(n);
    std::vector<Mint> suffix(n + n + 1);

    std::function<Mint(int,int)> calc = [&](int l, int r) -> Mint {
      if (l == r || l >= b.size()) return 0;
      int mid = (l + r) >> 1;
      Poly P, Q, R;
      for (int i = l; i <= mid; ++i) if (i < b.size() && b[i] == 1) {
        P.touch(i - l) = prefix[i];
        R.touch(i - l) = prefix[i] * i;
      }
      for (int i = mid + 1; i <= r; ++i) {
        assert(i < suffix.size());
        Q.touch(i - (mid + 1)) = suffix[i];
      }
      Poly PQ = P * Q;
      Poly RQ = R * Q;
      Mint ret = 0;
      for (int i = l; i <= r && i < n; ++i) {
        int index = i * 2 - l - (mid + 1);
        ret += Mint(a[i]) * (PQ.get(index) * i - RQ.get(index));
      }
      ret += calc(l, mid);
      ret += calc(mid + 1, r);
      return ret;
    };

    for (int i = 0, cnt = 0; i < n; ++i) {
      prefix[i] = 0;
      if (b[i] == 1) {
        prefix[i] = pw2[cnt];
        ++cnt;
      }
    }
    for (int i = n + n - 1, cnt = 0; i >= 0; --i) {
      cnt += i < n && b[i] == 1;
      suffix[i] = pw2[cnt];
    }
    result += calc(0, n + n - 1);
    DUMP(result);

    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    for (int i = 0, cnt = 0; i < n; ++i) {
      prefix[i] = 0;
      if (b[i] == 1) {
        prefix[i] = pw2[cnt];
        ++cnt;
      }
    }
    for (int i = n + n - 1, cnt = 0; i >= 0; --i) {
      cnt += i < n && b[i] == 1;
      suffix[i] = pw2[cnt];
    }
    result += calc(0, n + n - 1);
    DUMP(result);

    for (int i = 0, cnt = 0; i < n; ++i) {
      prefix[i] = 0;
      if (b[i] == 1) {
        prefix[i] = pw2[cnt];
        ++cnt;
      }
    }
    for (int i = n + n - 1, cnt = 0; i >= 0; --i) {
      suffix[i] = 0;
      if (i < n && b[i] == 1) {
        suffix[i] = pw2[cnt];
        ++cnt;
      }
    }
    result -= calc(0, n - 1);

    DUMP(result);

    result /= pw2[m] - 1;

    printf("%d\n", result.val());
  }
};

}  


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  

  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

