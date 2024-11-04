
using namespace std;
















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
bool id1(S& lhs, const T& rhs) {
  return lhs < rhs ? 1 : lhs = rhs, 0;
}

template<typename S, typename T>
bool id0(S& lhs, const T& rhs) {
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
  if (ch == '-')	positive = false;
  else num = ch - '0';
  while ((ch = getchar()) >= '0' && ch <= '9')
    num = num * 10 + ch - '0';
  if (!positive) num = -num;
}

void id3() {};
template <typename T, typename ...Args>
void id3(T& fst_el, Args&... others) { read_int(fst_el);id3(others...); }

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

void id2() { brkline; }
template<typename T, typename ...Args>
void id2(T fst_ele, Args ...others) {
  int_out(fst_ele);
  spaceout;
  id2(others...);
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

template<int P = P>
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
    else if (x >= P) {
      x -= P;
    }
    return x;
  }
  void print(char seperator = ' ') {
    printf("%d%c", x, seperator);
  }
  void println() {
    printf("%d\n", x);
  }
  ModInt operator-() const {
    return ModInt(P - x);
  }
  ModInt<P> inv() const {
    assert(x != 0);
    return qpow(*this, P - 2);
  }
  ModInt<P>& operator*=(const ModInt& rhs) {
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

const int K = 13;
ModInt<> c[K][K][K], f[1 << (K - 1)][K << 1][K][K], dp[K][K << 1][K][K];

void init() {
  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < K; ++j) {
      for (int k = 0; k < K; ++k) {
        c[i][j][k] = 0;
      }
    }
  }
  for (int i = 0; i < (1 << (K - 1)); ++i) {
    for (int j = 0; j < 2 * K; ++j) {
      for (int k = 0; k < K; ++k) {
        for (int t = 0; t < K; ++t) {
          f[i][j][k][t] = 0;
        }
      }
    }
  }

  for (int i = 0; i < K; ++i) {
    for (int j = 0; j < 2 * K; ++j) {
      for (int k = 0; k < K; ++k) {
        for (int t = 0; t < K; ++t) {
          dp[i][j][k][t] = 0;
        }
      }
    }
  }

}

std::vector<ModInt<>> invfac(K + 1);

void init_fac(int n, int mod) {
  invfac[0] = 1;
  for (int i = 1; i <= n; ++i)
    invfac[i] = qpow(ModInt<>(i), mod - 2);
}

ModInt<> binom(int n, int k) {
  if (n < 0 || n < k || k < 0) return 0;
  ModInt<> res = 1;
  for (int i = n; i > n - k; i--)
    res *= i;
  for (int i = 1; i <= k; i++)
    res *= invfac[i];
  return res;
}














































































































































































































































































































void resetf(int g) {
  for (int i = 0; i < (1 << g); ++i)
    for (int j = 0;j < K; ++j)
      for (int k = 0;k < K; ++k)
        for (int t = 0;t <= g; ++t)
          f[i][j][k][t] = 0;
}

void precal() {
  init();
  

  for (int g = 2; g < K; ++g) {
    resetf(g);

    f[0][0][0][0] = 1;
    for (int S = 0;S < (1 << g); ++S) {
      int bc = __builtin_popcount(S) + 1;
      for (int c1 = 0;c1 < K; ++c1)
        for (int c2 = 0;c2 < K; ++c2)
          for (int lst = 0;lst <= g; ++lst) {
            if (!f[S][c1][c2][lst].val()) continue;

            

            int mx = 0;
            for (int i = 1;i <= g; ++i)
              if ((S >> (i - 1)) & 1)
                mx = i;
            

            for (int p = 1;p <= g; ++p)
              if (!((S >> (p - 1)) & 1)) {
                

                if (max(mx, p) > bc || bc == g) {
                  

                  int h = c1 + (lst > p);
                  

                  int t = c2 + __builtin_popcount(S & ((1 << g) - (1 << p)));
                  if (h < K && t < K)
                    f[S | (1 << (p - 1))][h][t][p] += f[S][c1][c2][lst];
                }
              }
          }
    }
    for (int h = 1;h < K; ++h)
      for (int t = 1;t < K; ++t)
        for (int p = 1;p <= g; ++p) {
          c[g][h][t] += f[(1 << g) - 1][h][t][p];
        }
  }
  

  

  

  

  

  

  

  

  

  


  dp[0][0][0][0] = 1;
  for (int i = 0; i < K; ++i)
    for (int j = 0; j < 2 * K; ++j)
      for (int a = 0; a < K - 2; ++a)
        for (int b = 0; b < K - 2; ++b) {
          if (dp[i][j][a][b].val() == 0) continue;
          for (int g = 2; g < K; ++g)
            for (int h = 1; h < K - 1; ++h)
              for (int t = 1; t < K - 1; ++t) {
                if (j + g >= 2 * K || a + h > K - 2 || b + t > K - 2) continue;
                dp[i + 1][j + g][a + h][b + t] += dp[i][j][a][b] * c[g][h][t];
              }
        }
}

void solve(int case_t) {
  int n, k, x;
  id3(n, k, x);
  if (k == 0 && x == 0) {
    puts("1");
    return;
  }
  ModInt<> ans = 0;
  for (int i = 1; i < K; ++i)
    for (int j = 1; j < 2 * K; ++j)
      if (dp[i][j][x][k].val() != 0) {
        ans += dp[i][j][x][k] * binom(n - j + i, i);
      }
  ans.println();
}

int main() {
  init_fac(K, P);
  precal();
  int t = 1;
  read_int(t);
  repeat(i, 1, t) {
    solve(i);
  }
  return 0;
}