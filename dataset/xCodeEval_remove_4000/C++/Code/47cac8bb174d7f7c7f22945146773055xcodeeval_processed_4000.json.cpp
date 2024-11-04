







namespace {

template<typename T>
struct SparseTable {
  std::vector<std::vector<T>> u;
  std::vector<int> lg;
  void build(const std::vector<T>& a) {
    int n = a.size(), L = 1;
    while ((1 << L) <= n) ++L;
    std::vector<std::vector<T>>(n, std::vector<T>(L)).swap(u);
    lg.resize(n + 1);
    lg[0] = -1;
    for (int i = 1; i < lg.size(); ++ i) lg[i] = lg[i >> 1] + 1;
    for (int i = 0; i < n; ++ i) u[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++ j) {
      for (int i = 0; i + (1 << j) <= n; ++ i) {
        u[i][j] = std::min(u[i][j - 1], u[i + (1 << (j - 1))][j - 1]);
      }
    }
  }
  T ask(int a, int b) const {  

    if (a > b || a < 0 || b >= u.size()) throw;
    int k = lg[b - a + 1];
    return std::min(u[a][k], u[b - (1 << k) + 1][k]);
  }
};

using String = std::vector<int>;

struct SuffixArray {
  int n;
  String str;
  std::vector<int> sa, rank;

  

  std::vector<int> lcp;

  SparseTable<int> st;

  

  SuffixArray(const String& _s) : n(_s.size()), str(_s), sa(n + 1), rank(n + 1) {
    for (int i = 0; i <= n; ++i) {
      sa[i] = i;
      rank[i] = i < n ? str[i] : -1;
    }
    std::vector<int> tmp(n + 1);
    for (int k = 1; k <= n; k <<= 1) {
      

      auto compare_sa = [=](int i, int j) {
        if (rank[i] != rank[j])
          return rank[i] < rank[j];
        else {
          int ri = i + k <= n ? rank[i + k] : -1;
          int rj = j + k <= n ? rank[j + k] : -1;
          return ri < rj;
        }
      };
      std::sort(sa.begin(), sa.end(), compare_sa);
      tmp[sa[0]] = 0;
      for (int i = 1; i <= n; i++) {
        tmp[sa[i]] = tmp[sa[i - 1]] + (compare_sa(sa[i - 1], sa[i]) ? 1 : 0);
      }
      rank.swap(tmp);
    }
    for (int i = 0; i <= n; ++i) rank[sa[i]] = i;

    lcp.resize(n + 1, 0);
    int h = 0;
    for (int i = 0; i < n; ++i) {
      int j = sa[rank[i] - 1];
      if (h > 0) --h;
      for (; j + h < n && i + h < n; ++h) {
        if (str[j + h] != str[i + h]) break;
      }
      lcp[rank[i] - 1] = h;
    }
  }

  int compare(const String& lhs, int pos, int len, const String& rhs) const {
    for (int i = pos; i < pos + len; ++i) {
      if (i >= lhs.size()) {
        return i - pos >= rhs.size() ? 0 : -1;
      }
      if (i - pos >= rhs.size()) {
        return 1;
      }
      if (lhs[i] != rhs[i - pos]) {
        return lhs[i] - rhs[i - pos];
      }
    }
    return len < rhs.size() ? -1 : 0;
  }

  template <typename Compare> int binary_search(const String& t) const {
    int lb = -1, ub = n + 1;
    while (ub - lb > 1) {
      int mid = (ub + lb) / 2;
      if (Compare()(compare(str, sa[mid], t.size(), t), 0))
        lb = mid;
      else
        ub = mid;
    }
    return ub;
  }

  

  bool contains(const String& t) const {
    int lb = 0, ub = n;
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (compare(str, sa[mid], t.size(), t) < 0)
        lb = mid;
      else
        ub = mid;
    }
    return compare(str, sa[ub], t.size(), t) == 0;
  }

  void prepare_lcp_rmq() {
    st.build(lcp);
  }

  

  int get_lcp(int x, int y) const {
    if (x == y) return n - x;
    if (rank[x] > rank[y]) std::swap(x, y);
    return st.ask(rank[x], rank[y] - 1);
  }

  int lower_bound(const String& t) const { return binary_search<std::less<int>>(t); }
  int upper_bound(const String& t) const { return binary_search<std::less_equal<int>>(t); }
};



int example(const String& s) {
  SuffixArray sa(s);
  return s.size() - *std::max_element(sa.lcp.begin(), sa.lcp.end());
}

template<int MOD>
struct Integral {
  int v_ = 0;

  template<typename T> Integral(T v) : v_(norm(v)) {  

    static_assert(std::is_integral<T>::value, "input should be an integral.");
  }
  Integral() = default;
  ~Integral() = default;

  template<typename T> T norm(T v) const {
    if constexpr(std::is_same<long long, T>::value) {
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
  Integral& operator += (const Integral& rhs) { v_ += rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator -= (const Integral& rhs) { v_ += MOD - rhs.val(); if (v_ >= MOD) v_ -= MOD; return *this; }
  Integral& operator *= (const Integral& rhs) { v_ = v_ * 1LL * rhs.val() % MOD; return *this; }
  Integral& operator /= (const Integral& rhs) { v_ = v_ * 1LL * rhs.inv().val() % MOD; return *this; }
  Integral operator + (const Integral& rhs) const { Integral ret = *this; return ret += rhs; }
  Integral operator - (const Integral& rhs) const { Integral ret = *this; return ret -= rhs; }
  Integral operator * (const Integral& rhs) const { Integral ret = *this; return ret *= rhs; }
  Integral operator / (const Integral& rhs) const { Integral ret = *this; return ret /= rhs; }
  bool operator == (const Integral& rhs) const { return val() == rhs.val(); }
  bool operator != (const Integral& rhs) const { return !(*this == rhs); }
  const Integral operator - () const { return Integral(-val()); }
  const Integral& operator ++ () { v_ += 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator ++ (int) { Integral ret = *this; ++(*this); return ret; }
  const Integral& operator -- () { v_ += MOD - 1; if (v_ >= MOD) v_ -= MOD; return *this; }
  const Integral operator -- (int) { Integral ret = *this; --(*this); return ret; }

  Integral power(long long b) const {
    long long ret = 1 % MOD, a = v_;
    for ( ; b; b >>= 1, a = a * a % MOD) if (b & 1) ret = ret * a % MOD; return ret;
  }
  Integral inv() const { return power(MOD - 2); }
};

template<int MOD>
std::string to_string(const Integral<MOD>& v) {
  return std::string("{") + std::to_string(v.val()) + "}";
}

template<int MOD, bool id7 = false>
struct Binomial {
  std::vector<Integral<MOD>> factor, inv_factor;

  explicit Binomial(int n = 0) : factor(n + 1), inv_factor(n + 1) {
    factor[0] = 1;
    for (int i = 1; i <= n; ++i) factor[i] = factor[i - 1] * i;
    inv_factor[n] = factor[n].inv();
    for (int i = n; i >= 1; --i) inv_factor[i - 1] = inv_factor[i] * i;
  }
  ~Binomial() = default;

  template<typename T>
  Integral<MOD> operator () (T a, T b) const {
    if (a < b || b < 0) return 0;
    if (a < factor.size()) return factor[a] * inv_factor[b] * inv_factor[a - b];
    if constexpr(!id7) {
      throw std::out_of_range("Binomial");
    } else {
      b = std::min(b, a - b);
      Integral<MOD> ret = 1;
      for (T i = 1; i <= b; ++i) ret = ret * (a + 1 - i) / i;
      return ret;
    }
  }
};

template<int MOD>
struct PowerTable : public std::vector<Integral<MOD>> {
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

Binom binom(300000);



template<int MOD = 998244353, int id1 = 3>
void ntt(Integral<MOD> A[], int n, int inv) {
  


  

  

  

  Integral<MOD> w = 1, d = Integral<MOD>(id1).power((MOD - 1) / n), t;
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
using Polynomial = std::vector<T>;

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
Polynomial<T> operator + (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  Polynomial<T> ret = lhs;
  ret.resize(std::max(lhs.size(), rhs.size()), T(0));
  for (int i = 0; i < rhs.size(); ++i) ret[i] += rhs[i];
  norm(ret);
  return ret;
}

template<typename T>
Polynomial<T> operator - (const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  Polynomial<T> ret = lhs;
  ret.resize(std::max(lhs.size(), rhs.size()), T(0));
  for (int i = 0; i < rhs.size(); ++i) ret[i] -= rhs[i];
  norm(ret);
  return ret;
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
Polynomial<T> id6(Polynomial<T> poly, int len) {
  poly.resize(len, 0);
  return poly;
}

int id4(int w) {
  if (w <= 0) return 1;
  const int highbit = 31 - __builtin_clz(w);
  return (1 << highbit) << ((1 << highbit) != w);
}

template<typename T>
int id5(const Polynomial<T>& lhs, const Polynomial<T>& rhs) {
  return id4((int)lhs.size() + (int)rhs.size() - 1);
}

template<typename T>
Polynomial<T> operator * (Polynomial<T> lhs, Polynomial<T> rhs) {
  CHECK(lhs.size() + rhs.size() > 0);
  const int L = id5(lhs, rhs);
  lhs.resize(L, 0);
  rhs.resize(L, 0);
  ntt(lhs, L, 1);
  ntt(rhs, L, 1);
  for (int i = 0; i < L; ++i) {
    lhs[i] *= rhs[i];
  }
  ntt(lhs, L, -1);
  norm(lhs);
  return lhs;
}

template<typename T>
Polynomial<T> operator * (T a, Polynomial<T> p) {
  for (int i = 0; i < p.size(); ++i) p[i] *= a;
  norm(p);
  return p;
}

template<typename T>
Polynomial<T> mod_inv(Polynomial<T> poly, int len = 0) {
  

  CHECK(poly.size() >= 1 && poly[0] != 0);
  if (len == 0) len = poly.size();
  if (len > poly.size()) poly.resize(len);
  


  const int L = id4(len);
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
  const int L = id4(len);
  poly.resize(L, 0);
  Polynomial<T> buffer(1, 1), buffer1;
  for (int len = 2; len <= L; len <<= 1) {
    buffer1 = mod_inv(T(2) * buffer, len);
    ntt(buffer, len, 1);
    for (int i = 0; i < len; ++i) buffer[i] *= buffer[i];
    ntt(buffer, len, -1);
    for (int i = 0; i < len; ++i) buffer[i] += poly[i];
    buffer = id6(buffer * buffer1, len);
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
  const int L = id4(len);
  poly.resize(L, 0);
  Polynomial<T> p(1, 1);
  for (int len = 2; len <= L; len <<= 1) {
    Polynomial<T> q = p;
    p = id6(mod_ln(p, len), len);
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
T id2(Polynomial<T> poly, int n) {  

  if (poly.empty()) return T(0);
  CHECK(poly[0] == T(0));
  CHECK(poly.size() > 1);
  CHECK(poly[1] != T(0));
  CHECK(n > 0);
  poly.erase(poly.begin());
  return id6(id3(poly, n, n), n)[n - 1] / T(n);
}

using Poly = Polynomial<Integral<MOD>>;

struct Solver {
  int n, m, k;
  std::vector<std::vector<int>> A;

  Mint solve() {
    using EdgeSet = std::set<int>;
    std::vector<EdgeSet> prev(k), next(k);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j + 1 < A[i].size(); ++j) {
        int x = A[i][j];
        int y = A[i][j + 1];
        prev[y].emplace(x);
        next[x].emplace(y);
      }
    }

    std::vector<bool> bad(k);
    std::queue<int> que;
    for (int i = 0; i < k; ++i) {
      if (prev[i].size() > 1 || next[i].size() > 1) {
        bad[i] = true;
        que.emplace(i);
      }
    }

    while (!que.empty()) {
      int u = que.front(); que.pop();
      for (int v : prev[u]) {
        if (!bad[v]) {
          bad[v] = true;
          que.emplace(v);
        }
      }
      for (int v : next[u]) {
        if (!bad[v]) {
          bad[v] = true;
          que.emplace(v);
        }
      }
    }

    


    Poly poly(m + 1);
    for (int i = 0; i < k; ++i) if (!bad[i] && prev[i].empty()) {
      int len = 1;
      for (int x = i; !next[x].empty(); x = *next[x].begin()) {
        ++len;
      }
      poly[len]++;
    }

    return mod_inv(Poly(1, 1) - poly, m + 1)[m];
  }

  void solve(int ca, std::istream& reader) {
    reader >> n >> m >> k;
    A.resize(n);
    for (int i = 0; i < n; ++i) {
      int len;
      reader >> len;
      A[i].resize(len);
      for (int j = 0; j < len; ++j) {
        reader >> A[i][j]; --A[i][j];
      }
    }
    printf("%d\n", solve().val());
  }
};

}  


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  int cas = 1;
  

  for (int ca = 1; ca <= cas; ++ca) {
    Solver().solve(ca, reader);
  }
}

