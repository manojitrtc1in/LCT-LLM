#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define PLOT(...)
#define CHECK(...)
#endif

namespace {

using LL = long long;
template<typename T, typename U> bool enlarge(T& a, U b) { \
  return a < b ? (a = b, true) : false; }
template<typename T, typename U> bool minify(T& a, U b) { \
  return a > b ? (a = b, true) : false; }


template<int MOD>
struct Integral {
  int v_ = 0;

  

  Integral(int v) : v_(norm(v)) {}
  Integral(long long v) : v_(norm(v)) {}
  Integral(unsigned int v) : v_(norm(v)) {}
  Integral(unsigned long long v) : v_(norm(v)) {}
  Integral() = default;
  ~Integral() = default;

  

  template<typename T>
  explicit operator T() const {
    static_assert(std::is_same<T, bool>::value || sizeof(T) >= sizeof(v_), "");
    return T(v_);
  }

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

template<int MOD, bool kAllowBruteForce = false>
struct Binomial final {
  std::vector<Integral<MOD>> fact, inv_fact;

  explicit Binomial(int n = 0) : fact(n + 1), inv_fact(n + 1) {
    assert(n < MOD);
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
    if constexpr(!kAllowBruteForce) {
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
    for (int i = 1; i < this->size(); ++i) this->at(i) = this->at(i - 1) * g;
  }
};

const int MOD = 998244353;
using Mint = Integral<MOD>;
using Binom = Binomial<MOD>;
using Power = PowerTable<MOD>;






template<typename Edge>
struct TreeHeavyLightDecomposition {
  int n = 0;
  std::vector<std::vector<Edge>> graph;
  std::vector<int> header, dfn, rd, parent, depth, sz;
  int tim = 0;

  TreeHeavyLightDecomposition() = default;
  explicit TreeHeavyLightDecomposition(int n) : n(n), graph(n), header(n), dfn(n), rd(n), parent(n), depth(n), sz(n) {}

  void make(int root = 0) {
    get_sz(root, -1);
    rebuild(root, -1, root);
  }

  void get_sz(int u, int fa) {
    sz[u] = 1;
    for (const Edge& e : graph[u]) {
      int v = e.v;
      if (v == fa) continue;
      get_sz(v, u);
      sz[u] += sz[v];
    }
  }

  void rebuild(int u, int fa, int color) {
    rd[tim] = u;
    dfn[u] = tim++;
    parent[u] = fa;
    depth[u] = fa == -1 ? 0 : depth[fa] + 1;
    header[u] = color;
    int p = -1;
    for (const Edge& e : graph[u]) {
      int v = e.v;
      if (v == fa) continue;
      if (p == -1 || sz[v] > sz[p]) {
        p = v;
      }
    }
    if (p != -1) {
      rebuild(p, u, color);
    }
    for (const Edge& e : graph[u]) {
      int v = e.v;
      if (v == fa || v == p) continue;
      rebuild(v, u, v);
    }
  }

  int get_lca(int a, int b) {
    int ret = a;
    traverse([&ret, this](int side, int L, int R) {
      ret = this->rd[L];
    }, a, b);
    return ret;
  }

  int get_dist(int a, int b) {
    return depth[a] + depth[b] - 2 * depth[get_lca(a, b)];
  }

  

  template<typename Handler>
  Handler traverse(Handler&& handler, int a, int b, bool is_lca_included = true) {
    while (header[a] != header[b]) {
      if (depth[header[a]] > depth[header[b]]) {
        handler(0, dfn[header[a]], dfn[a]);
        a = parent[header[a]];
      } else {
        handler(1, dfn[header[b]], dfn[b]);
        b = parent[header[b]];
      }
    }
    if (dfn[a] < dfn[b]) {
      handler(1, dfn[a] + (!is_lca_included), dfn[b]);
    } else if (dfn[b] < dfn[a] || is_lca_included) {
      handler(0, dfn[b] + (!is_lca_included), dfn[a]);
    }
    return handler;
  }
};

template<typename Edge>
struct VirtualGraph {
  const std::vector<int>& dfn;

  int n;
  std::vector<std::vector<Edge>> graph;
  std::vector<int> original_points;
  std::vector<int> point_weight;

  

  

  

  static int get_index(const std::vector<int>& dfn, const std::vector<int>& points, int u) {
    const int index = std::lower_bound(points.begin(), points.end(), u, [&](int x, int y) {
      return dfn[x] < dfn[y];
    }) - points.begin();
    CHECK(index >= 0 && index < points.size());
    return index;
  }

  

  template<typename GetLca, typename GetPointWeight, typename GetEdgeWeight>
  explicit VirtualGraph(const std::vector<int>& dfn,
                        std::vector<int> points,
                        GetLca&& get_lca,
                        GetPointWeight&& get_point_weight,
                        GetEdgeWeight&& get_edge_weight) : dfn(dfn) {
    std::sort(points.begin(), points.end(), [&](int x, int y) {
      return dfn[x] < dfn[y];
    });
    points.erase(std::unique(points.begin(), points.end()), points.end());
    for (int i = (int)points.size() - 1; i > 0; --i) {
      points.emplace_back(get_lca(points[i], points[i - 1]));
    }
    std::sort(points.begin(), points.end(), [&](int x, int y) {
      return dfn[x] < dfn[y];
    });
    points.erase(std::unique(points.begin(), points.end()), points.end());

    original_points = points;
    n = original_points.size();
    graph.resize(n);
    point_weight.resize(n);

    for (int i = 0; i < points.size(); ++i) {
      point_weight[i] = get_point_weight(points[i]);
    }

    for (int i = (int)points.size() - 1; i > 0; --i) {
      int u = original_points[i];
      int v = original_points[i - 1];
      int lca = get_lca(u, v);
      graph[get_index(dfn, original_points, lca)].emplace_back(
          Edge{.v = i, .w = get_edge_weight(u, lca)});
    }
  }

  int get_index(int x) const { return get_index(dfn, original_points, x); }
  int size() const { return n; }
};




struct PrimeTable {
  std::vector<int> primes;
  std::vector<int> min_div;
  std::vector<int8_t> mu;
  std::vector<int> phi;

  PrimeTable() = default;
  explicit PrimeTable(int n) { prepare_primes(n); }

  void prepare_primes(int n) {
    primes.clear();
    min_div.assign(n + 1, 0);
    mu.assign(n + 1, 0);
    phi.assign(n + 1, 0);
    min_div[1] = mu[1] = phi[1] = 1;
    for (int i = 2; i <= n; ++i) {
      if (!min_div[i]) {
        primes.emplace_back(i);
        min_div[i] = i;
        mu[i] = -1;
        phi[i] = i - 1;
      }
      for (int p : primes) {
        if (i * p > n) break;
        min_div[i * p] = p;
        if (i % p == 0) {
          phi[i * p] = phi[i] * p;
          break;
        } else {
          mu[i * p] = -mu[i];
          phi[i * p] = phi[i] * (p - 1);
        }
      }
    }
  }

  template<typename T>
  bool is_prime(T x) const {
    if (x < 2) return false;
    if (x < min_div.size()) return min_div[x] == x;
    for (T w = 2; w * w <= x; ++w) if (x % w == 0) return false;
    return true;
  }

  template<typename T>
  std::vector<typename std::pair<T, T>> get_canonical_representation(T x) const {
    assert(x >= 1);
    std::vector<typename std::pair<T, T>> ret;  

    for (T i = 2; x >= min_div.size() && i * i <= x; ++i) if (x % i == 0) {
      T cnt = 0;
      while (x % i == 0) ++cnt, x /= i;
      ret.emplace_back(i, cnt);
    }
    while (1 < x && x < min_div.size()) {
      T p = min_div[x];
      T cnt = 0;
      while (x % p == 0) ++cnt, x /= p;
      ret.emplace_back(p, cnt);
    }
    if (x >= min_div.size() && x > 1) {
      ret.emplace_back(x, 1);
    }
    return ret;
  }

  template<typename T>
  std::vector<T> get_factors(T x) const {  

    assert(x >= 1);
    const std::vector<typename std::pair<T, T>> repr = get_canonical_representation(x);
    std::vector<T> factors;
    std::function<void(int, T)> enumerate_factors = [&](int at, T val) -> void {
      factors.emplace_back(val);
      for (int i = at; i < repr.size(); ++i) {
        T tmp = val;
        for (int j = 0; j < repr[i].second; ++j) {
          tmp *= repr[i].first;
          enumerate_factors(i + 1, tmp);
        }
      }
    };
    enumerate_factors(0, 1);
    return factors;
  }

  template<typename T>
  std::vector<T> get_factors_with_nonzero_mu(T x) const {  

    assert(x >= 1);
    const std::vector<typename std::pair<T, T>> repr = get_canonical_representation(x);
    std::vector<T> factors;
    std::function<void(int, T)> enumerate_factors = [&](int at, T val) -> void {
      factors.emplace_back(val);
      for (int i = at; i < repr.size(); ++i) {
        enumerate_factors(i + 1, val * repr[i].first);
      }
    };
    enumerate_factors(0, 1);
    return factors;
  }

  template<typename T, typename Vector = std::vector<T>>
  T get_pi(T n, Vector&& entries, Vector&& g) const {
    

    

    

    assert(((int)min_div.size() - 1) * ((int)min_div.size() - 1) >= n);
    entries.clear();
    g.clear();

    for (T i = 1; i <= n; i = n / (n / i) + 1) entries.emplace_back(n / i);
    std::reverse(entries.begin(), entries.end());
    int m = entries.size();
    g.resize(m, 0);
    for (int i = 0; i < m; ++i) g[i] = entries[i] - 1;

    int w = std::sqrt(n);
    while ((w + 1) * 1LL * (w + 1) <= n) ++w;
    std::vector<T> small(w + 1), big(w + 1);
    for (int i = 1, j = 0; i <= w; ++i) {
      while (j < m && entries[j] < i) ++j;
      assert(entries[j] == i);
      small[i] = j;
    }
    for (int i = w, j = 0; i >= 1; --i) {
      while (j < m && entries[j] < n / i) ++j;
      assert(entries[j] == n / i);
      big[i] = j;
    }
    auto get_index = [&](T x) -> int {
      return x <= w ? small[x] : big[n / x];
    };

    for (int k = 0; k < primes.size(); ++k) {
      int p = primes[k];
      if (p * 1LL * p > n) break;
      for (int i = m - 1; i >= 0 && entries[i] >= p * 1LL * p; --i) {
        g[i] += -g[get_index(entries[i] / p)] + k;
      }
    }
    return g.back();
  }
  template<typename T>
  T get_pi(T n) const { return get_pi(n, std::vector<T>{}, std::vector<T>{}); }
};

struct Edge {
  int v;
  int w = 1;
};

struct Solver {

  void solve(int ca, std::istream& reader) {
    int N;
    reader >> N;
    std::vector<std::vector<int>> buckets(200000 + 1);
    for (int i = 0; i < N; ++i) {
      int a;
      reader >> a;
      buckets[a].emplace_back(i);
    }

    TreeHeavyLightDecomposition<Edge> tree(N);
    for (int i = 0; i < N - 1; ++i) {
      int x, y;
      reader >> x >> y; --x; --y;
      tree.graph[x].emplace_back(Edge{.v = y});
      tree.graph[y].emplace_back(Edge{.v = x});
    }
    tree.make();

    Mint result = 0;

    const Mint inv2 = Mint(2).inv();

    PrimeTable pt(200000);
    for (int p : pt.primes) {
      std::vector<int> points;
      for (int i = 1; i * p < buckets.size(); ++i) {
        for (int u : buckets[i * p]) {
          points.emplace_back(u);
        }
      }
      if (points.empty()) continue;
      std::sort(points.begin(), points.end());
      VirtualGraph<Edge> vgraph(
          tree.dfn,
          points,
          [&tree](int x, int y) -> int { return tree.get_lca(x, y); },
          [&](int x) -> int {
            auto iter = std::lower_bound(points.begin(), points.end(), x);
            return iter != points.end() && *iter == x;
          },
          [&tree](int x, int lca) -> int { return tree.depth[x] - tree.depth[lca]; });

      int tot = points.size();

      auto dfs = [&](auto self, int u, int fa, int coef) -> int {
        int cnt = vgraph.point_weight[u];
        for (const Edge& e : vgraph.graph[u]) if (e.v != fa) {
          cnt += self(self, e.v, u, e.w);
        }
        result += Mint(cnt) * (cnt - 1) * inv2 * (tot - cnt) * coef;
        result += Mint(tot - cnt) * (tot - cnt - 1) * inv2 * cnt * coef;
        

        return cnt;
      };
      dfs(dfs, 0, -1, 0);
      

    }
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

