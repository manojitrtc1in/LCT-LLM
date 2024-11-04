#include <bits/stdc++.h>
#ifdef ALGO
#include "el_psy_congroo.hpp"
#else
#define DUMP(...)
#define CHECK(...)
#endif


#define REP(i, s, n) for (int i = int(s); i < int(n); ++i)
#define PER(i, s, n) for (int i = int(n) - 1; i >= int(s); --i)

namespace {

using LL = long long;
LL gcd(LL a, LL b) { return b == 0 ? a : gcd(b, a % b); }
template<typename T, typename U> bool enlarge(T& a, U b) { return a < b ? (a = b, true) : false; }
template<typename T, typename U> bool minify(T& a, U b) { return a > b ? (a = b, true) : false; }

template<typename T, int num_dimensions>
struct MultiDimensionalVector {
  using type = std::vector<typename MultiDimensionalVector<T, num_dimensions - 1>::type>;

  static type create() { return type{}; }
  template<typename... Args>
  static type create(int dim, Args&&... args) {
    return type(dim, MultiDimensionalVector<T, num_dimensions - 1>::create(std::forward<Args>(args)...));
  }
};

template<typename T>
struct MultiDimensionalVector<T, 0> {
  using type = T;

  static type create() { return T{}; }
  static type create(T value) { return std::move(value); }
};

template<typename T, int num_dimensions>
using MDV = MultiDimensionalVector<T, num_dimensions>;

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
    static_assert(sizeof(T) >= sizeof(v_), "");
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
    this->at(1) = g;
    for (int i = 2; i < this->size(); ++i) this->at(i) = this->at(i - 1) * this->at(1);
  }
};

const int MOD = 998244353;
using Mint = Integral<MOD>;
using Binom = Binomial<MOD>;
using Power = PowerTable<MOD>;

Binomial<MOD, true> binom(200);



int table[12 + 1][11 + 1][11 + 1];  


Mint dp[11 + 1][22 + 1][11 + 1][11 + 1];

void initialize() {
  table[2][1][1] = 1;
  table[3][2][1] = 2;
  table[3][3][2] = 1;
  table[4][3][1] = 3;
  table[4][3][2] = 1;
  table[4][4][1] = 1;
  table[4][4][2] = 4;
  table[4][5][2] = 3;
  table[4][6][3] = 1;
  table[5][4][1] = 4;
  table[5][4][2] = 4;
  table[5][5][1] = 2;
  table[5][5][2] = 12;
  table[5][5][3] = 2;
  table[5][6][1] = 2;
  table[5][6][2] = 12;
  table[5][6][3] = 4;
  table[5][7][2] = 9;
  table[5][7][3] = 6;
  table[5][8][2] = 3;
  table[5][8][3] = 6;
  table[5][9][3] = 4;
  table[5][10][4] = 1;
  table[6][5][1] = 5;
  table[6][5][2] = 10;
  table[6][5][3] = 1;
  table[6][6][1] = 3;
  table[6][6][2] = 28;
  table[6][6][3] = 13;
  table[6][7][1] = 4;
  table[6][7][2] = 35;
  table[6][7][3] = 29;
  table[6][7][4] = 1;
  table[6][8][1] = 3;
  table[6][8][2] = 35;
  table[6][8][3] = 41;
  table[6][8][4] = 4;
  table[6][9][1] = 1;
  table[6][9][2] = 30;
  table[6][9][3] = 44;
  table[6][9][4] = 7;
  table[6][10][2] = 17;
  table[6][10][3] = 45;
  table[6][10][4] = 7;
  table[6][11][2] = 8;
  table[6][11][3] = 30;
  table[6][11][4] = 11;
  table[7][6][1] = 6;
  table[7][6][2] = 20;
  table[7][6][3] = 6;
  table[7][7][1] = 4;
  table[7][7][2] = 55;
  table[7][7][3] = 50;
  table[7][7][4] = 3;
  table[7][8][1] = 6;
  table[7][8][2] = 80;
  table[7][8][3] = 118;
  table[7][8][4] = 18;
  table[7][9][1] = 6;
  table[7][9][2] = 95;
  table[7][9][3] = 186;
  table[7][9][4] = 48;
  table[7][10][1] = 6;
  table[7][10][2] = 101;
  table[7][10][3] = 230;
  table[7][10][4] = 85;
  table[7][10][5] = 2;
  table[7][11][1] = 2;
  table[7][11][2] = 94;
  table[7][11][3] = 260;
  table[7][11][4] = 113;
  table[7][11][5] = 4;
  table[8][7][1] = 7;
  table[8][7][2] = 35;
  table[8][7][3] = 21;
  table[8][7][4] = 1;
  table[8][8][1] = 5;
  table[8][8][2] = 96;
  table[8][8][3] = 145;
  table[8][8][4] = 26;
  table[8][9][1] = 8;
  table[8][9][2] = 155;
  table[8][9][3] = 358;
  table[8][9][4] = 124;
  table[8][9][5] = 3;
  table[8][10][1] = 9;
  table[8][10][2] = 207;
  table[8][10][3] = 616;
  table[8][10][4] = 313;
  table[8][10][5] = 16;
  table[8][11][1] = 11;
  table[8][11][2] = 250;
  table[8][11][3] = 859;
  table[8][11][4] = 567;
  table[8][11][5] = 53;
  table[9][8][1] = 8;
  table[9][8][2] = 56;
  table[9][8][3] = 56;
  table[9][8][4] = 8;
  table[9][9][1] = 6;
  table[9][9][2] = 154;
  table[9][9][3] = 350;
  table[9][9][4] = 126;
  table[9][9][5] = 4;
  table[9][10][1] = 10;
  table[9][10][2] = 268;
  table[9][10][3] = 898;
  table[9][10][4] = 552;
  table[9][10][5] = 48;
  table[9][11][1] = 12;
  table[9][11][2] = 389;
  table[9][11][3] = 1654;
  table[9][11][4] = 1404;
  table[9][11][5] = 204;
  table[9][11][6] = 1;
  table[10][9][1] = 9;
  table[10][9][2] = 84;
  table[10][9][3] = 126;
  table[10][9][4] = 36;
  table[10][9][5] = 1;
  table[10][10][1] = 7;
  table[10][10][2] = 232;
  table[10][10][3] = 742;
  table[10][10][4] = 448;
  table[10][10][5] = 43;
  table[10][11][1] = 12;
  table[10][11][2] = 427;
  table[10][11][3] = 1967;
  table[10][11][4] = 1887;
  table[10][11][5] = 357;
  table[10][11][6] = 6;
  table[11][10][1] = 10;
  table[11][10][2] = 120;
  table[11][10][3] = 252;
  table[11][10][4] = 120;
  table[11][10][5] = 10;
  table[11][11][1] = 8;
  table[11][11][2] = 333;
  table[11][11][3] = 1428;
  table[11][11][4] = 1302;
  table[11][11][5] = 252;
  table[11][11][6] = 5;
  table[12][11][1] = 11;
  table[12][11][2] = 165;
  table[12][11][3] = 462;
  table[12][11][4] = 330;
  table[12][11][5] = 55;
  table[12][11][6] = 1;


  dp[0][0][0][0] = 1;

  REP(i, 0, 11) {
    REP(j, 0, 22 + 1) {
      REP(k, 0, 11 + 1) {
        REP(r, 0, 11 + 1) if (dp[i][j][k][r].val()) {
          for (int len = 2; j + len <= 22; ++len) {
            for (int x = len - 1; x + k <= 11; ++x) {
              for (int y = 1; y + r <= 11; ++y) if (table[len][x][y]) {
                dp[i + 1][j + len][k + x][r + y] += dp[i][j][k][r] * table[len][x][y];
              }
            }
          }
        }
      }
    }
  }
}

void print_table() {
  auto table = MDV<int, 3>::create(12 + 1, 11 + 1, 11 + 1, 0);  


  REP(len, 2, 12 + 1) {
    std::vector<int> perm(len);
    std::iota(perm.begin(), perm.end(), 0);
    do {
      bool valid = true;
      REP(sp, 0, len - 1) {
        valid &= *std::max_element(perm.begin(), perm.begin() + sp + 1) > *min_element(perm.begin() + sp + 1, perm.end());
        if (!valid) break;
      }
      if (!valid) continue;
      int x = 0, y = 0;
      REP(i, 0, len - 1) {
        REP(j, i + 1, len) {
          x += perm[i] > perm[j];
        }
        y += perm[i] > perm[i + 1];
      }
      if (x <= 11 && y <= 11) {
        table[len][x][y]++;
      }
    } while (std::next_permutation(perm.begin(), perm.end()));

    REP(j, 0, table[len].size()) REP(k, 0, table[len][j].size()) if (table[len][j][k]) {
      printf("table[%d][%d][%d] = %d,\n", len, j, k, table[len][j][k]);
    }
  }
}

struct Solver {

  void solve(int ca, std::istream& reader) {
    

    

    



    int n, k, x;
    reader >> n >> k >> x;

    Mint result = 0;
    REP(cnt, 1, x + 1) {
      REP(len, cnt * 2, k * 2 + 1) {
        if (len > n) break;
        result += dp[cnt][len][k][x] * binom(n - len + cnt, cnt);
      }
    }
    printf("%d\n", result.val());
  }
};

}  


int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::istream& reader = std::cin;

  


  initialize();

  int cas = 1;
  reader >> cas;
  for (int ca = 1; ca <= cas; ++ca) {
    auto solver = std::make_unique<Solver>();
    solver->solve(ca, reader);
  }
}

