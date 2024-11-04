#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vb = vector<bool>;
using vvb = vector<vb>;
using vd = vector<double>;
using vs = vector<string>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdd = vector<pdd>;


using range_t = ll;
constexpr char IMPOSSIBLE[] = "IMPOSSIBLE";
constexpr char POSSIBLE[] = "POSSIBLE";
namespace coding {
namespace debug {
string to_string(string s) { return '"' + s + '"'; }
string to_string(const char *s) { return to_string((string)s); }
string to_string(const bool &b) { return (b ? "true" : "false"); }
string to_string(long long v) { return std::to_string(v); }
string to_string(double v) { return std::to_string(v); }
string to_string(int v) { return std::to_string(v); }
string to_string(size_t v) { return std::to_string(v); }
template <long unsigned int t>
string to_string(std::bitset<t> v) { stringstream s; s << v; return s.str(); }
template <class A, class B> string to_string(pair<A, B> p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <class IterType>
string to_string(IterType begin, IterType end, std::string sep = ", ",
                 std::string prefix = "{", std::string suffix = "}");
template <class A, class B, class... Args>
string to_string(const std::unordered_set<A, B> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, size_t N, class... Args>
string to_string(const std::array<A, N> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::vector<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::list<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::deque<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::unordered_set<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::multiset<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class B, class... Args>
string to_string(const std::unordered_map<A, B> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class B, class... Args>
string to_string(const std::map<A, B> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const std::set<A> &vec, Args... args) {
  return to_string(vec.cbegin(), vec.cend(), args...);
}
template <class A, class... Args>
string to_string(const A vec[], Args... args) {
  return to_string(vec, vec + sizeof(vec) + args...);
}
template <class IterType>
string to_string(IterType begin, IterType end, std::string sep,
                 std::string prefix, std::string suffix) {
  int first = true;
  string res = prefix;
  for (auto iter = begin; iter != end; ++iter) {
    if (!first)
      res += sep;
    first = false;
    res += to_string(*iter);
  }
  res += suffix;
  return res;
}










} 

} 

namespace coding {
namespace io {
void SetupStdinFromFile(const std::string filepath) {
  if (freopen(filepath.c_str(), "r", stdin) == nullptr) {
    cout << "Cannot hook file: " << filepath << endl;
    exit(EXIT_FAILURE);
  }
}
void SetupStdoutToFile(const std::string filepath) {
  if (freopen(filepath.c_str(), "w", stdout) == nullptr)
    exit(EXIT_FAILURE);
}
template<class T=long long>
inline T Read() {
  T x = 0;
  ll f = 1;
  char c = getchar();
  while (c < '0' || c > '9') {
    if (c == '-')
      f = -1;
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    x = (x << 1) + (x << 3) + c - '0';
    c = getchar();
  }
  return x * f;
}
void SetupQuickIO() {
  ios_base::sync_with_stdio(0);
  

  

}
template <class T> std::vector<T> ReadVector(size_t size, T shift = T()) {
  std::vector<T> result;
  while (size--) {
    T input = Read<T>();
    result.push_back(input+shift);
  }
  return result;
}
template <class T> std::vector<vector<T>> ReadMatrix(size_t row, size_t column) {
  std::vector<vector<T>> result;
  while (row--) {
    result.emplace_back(ReadVector<T>(column));
  }
  return result;
}
template <class T> void OutputVector(const vector<T>& v) {
  for (const auto& x: v) {
     cout << x << " ";
  }
  cout << endl;
}
} 

} 



int32_t CODEJAM_CASE_COUNTER = 0;
std::string CODEJAM() {
  return "Case #" + to_string(++CODEJAM_CASE_COUNTER) + ": ";
}


namespace coding {
namespace algo {
namespace math {
inline ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
template <class T> T Unit(const T &example);
template <> ll Unit(const ll &example) { return 1LL; }
template <class T> T Zero(const T &example);
template <> ll Zero(const ll &example) { return 0LL; }


template <class T> T quick_pow(T base, ll exp, ll mod) {
  T res = T(1); 

  for (; exp; exp >>= 1, base = base * base % mod)
    if (exp & 1)
      res = res * base % mod;
  return res;
}


template <class T> T quick_pow(T base, ll exp) {
  T res = Unit(base);
  for (; exp; exp >>= 1, base = base * base) {
    if (exp & 1) {
      res = res * base;
    }
  }
  return res;
}


inline ll mul_inverse(ll base, ll mod) { return quick_pow(base, mod - 2, mod); }










vector<ll> GetPrimes(const ll MAX, bool euler = true, vector<int> *phi = nullptr) {
  vector<bool> is_prime(MAX + 1, true);
  vector<ll> primes;
  if (phi) {
    assert(euler);
    phi->clear();
    phi->resize(MAX + 1, 0);
    (*phi)[1] = 1;
  }
  if (euler) {
    for (ll i = 2; i <= MAX; ++i) {
      if (is_prime[i]) {
        primes.push_back(i);
        (*phi)[i] = i - 1;
      }
      for (ll j = 0; j < primes.size() && primes[j] * i <= MAX; ++j) {
        is_prime[primes[j] * i] = false;
        if (i % primes[j]) {
          (*phi)[i * primes[j]] = (*phi)[i] * (*phi)[primes[j]];
        } else {
          (*phi)[i * primes[j]] = (*phi)[i] * primes[j];
          break;
        }
      }
    }
  } else {
    

    for (ll i = 2; i <= MAX; ++i) {
      if (is_prime[i]) {
        primes.push_back(i);
        for (ll j = i; j <= MAX; j += i)
          is_prime[j] = false;
      }
    }
  }
  return primes;
}


using ModNumberType = ll;
class ModNumber {
public:
  struct ModNumberOptions;
  ModNumber(ModNumberType value, ModNumberType mod,
            ModNumberOptions options = {.overflow_safe_mul = false})
      : mod(mod), value(value), options(options) {}
  ModNumber(const ModNumber &b) = default;
  void operator=(ModNumberType b) { value = b % mod; }
  ModNumber operator+(ModNumberType b) {
    return ModNumber((value + b) % mod, mod, options);
  }
  ModNumber operator-(ModNumberType b) {
    return ModNumber(((value - b) % mod + mod) % mod, mod, options);
  }
  ModNumber operator*(ModNumberType b) {
    if (!options.overflow_safe_mul) {
      return ModNumber((value * b) % mod, mod, options);
    } else {
      ModNumberType ret = 0;
      ModNumberType delta = value;
      while (b) {
        if (b & 1) {
          ret = (ret + delta) % mod;
          

        }
        delta = (delta + delta) % mod;
        b >>= 1;
      }
      return ModNumber(ret, mod, options);
    }
  }
  ModNumber operator/(ModNumberType b) { return (*this) * mul_inverse(b, mod); }
  ModNumber operator%(ModNumberType b) {
    assert(b == mod);
    return *this;
  }
  ModNumber operator+(const ModNumber &b) { return (*this) + b.value; }
  ModNumber operator-(const ModNumber &b) { return (*this) - b.value; }
  ModNumber operator*(const ModNumber &b) { return (*this) * b.value; }
  ModNumber operator/(const ModNumber &b) { return (*this) / b.value; }
  ModNumberType value;
  ModNumberType mod;
  struct ModNumberOptions {
    bool overflow_safe_mul = false;
  } options;
  friend ostream &operator<<(ostream &s, const ModNumber &m) {
    s << "<ModNum value=" << m.value << " mod=" << m.mod << ">";
    return s;
  }
  friend ModNumber Unit(const ModNumber &example) {
    return ModNumber(1, example.mod, example.options);
  }
  friend ModNumber Zero(const ModNumber &example) {
    return ModNumber(0, example.mod, example.options);
  }
};


template <class T> class Matrix {
public:
  Matrix(ll N, ll M, T default_value) : N(N), M(M) {
    for (int i = 0; i < N; ++i) {
      data.push_back(vector<T>(M, default_value));
    }
  }
  Matrix(ll N, ll M, vector<vector<T>> data) : N(N), M(M), data(data) {}
  Matrix(const Matrix &b) = default;
  Matrix operator+(const Matrix &b) {
    assert(N == b.N);
    assert(M == b.M);
    Matrix ret(*this);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        ret.data[i][j] = data[i][j] + b.data[i][j];
      }
    }
    return ret;
  }
  Matrix operator-(const Matrix &b) {
    assert(N == b.N);
    assert(M == b.M);
    Matrix ret(*this);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        ret.data[i][j] = data[i][j] - b.data[i][j];
      }
    }
    return ret;
  }
  Matrix operator*(const Matrix &b) {
    assert(M == b.N);
    Matrix ret(N, b.M, Zero(data[0][0]));
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < b.M; ++j) {
        for (int k = 0; k < M; ++k) {
          ret.data[i][j] = ret.data[i][j] + data[i][k] * b.data[k][j];
        }
      }
    }
    return ret;
  }
  Matrix operator%(ll mod) {
    Matrix ret(*this);
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < M; j++) {
        ret.data[i][j] = ret.data[i][j] % mod;
      }
    }
    return ret;
  }
  ll N, M;
  vector<vector<T>> data;
  friend ostream &operator<<(ostream &s, const Matrix &m) {
    s << "<Matrix " << m.N << "x" << m.M << endl;
    for (int i = 0; i < m.N; ++i) {
      for (int j = 0; j < m.M; ++j) {
        s << m.data[i][j] << "\t";
      }
      s << endl;
    }
    s << ">";
    return s;
  }
  friend Matrix Unit(const Matrix &example) {
    assert(example.N == example.M);
    auto ret = Matrix(example.N, example.M, Zero(example.data[0][0]));
    for (int i = 0; i < example.N; ++i) {
      ret.data[i][i] = Unit(example.data[0][0]);
    }
    return ret;
  }
  Matrix GetUnit() const { return Unit(*this); }
  friend Matrix Zero(const Matrix &example) {
    return Matrix(example.N, example.M, Zero(example.data[0][0]));
  }
};
static unsigned fast_mod(uint64_t x, unsigned m = 998244353) {
  return x % m;
  

  

  

  

  

  

}


int euler_phi(int n) {
  int ans = n;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0) {
      ans = ans / i * (i - 1);
      while (n % i == 0)
        n /= i;
    }
  if (n > 1)
    ans = ans / n * (n - 1);
  return ans;
}
vector<int> euler_phis(int n) {
  vector<int> phi;
  GetPrimes(n, true, &phi);
  return phi;
}
template <typename T> int sgn(T val) {
      return (T(0) < val) - (val < T(0));
}
} 

} 

} 

using coding::io::Read;
using coding::io::ReadVector;
using coding::algo::math::sgn;


int f[2001][2001][2];
int main() {
  

  ll T = Read();
  while (T--) {
    string s;
    cin >> s;
    int n = s.size();
    ;;
    const int BOB = -1;
    const int DRAW = 0;
    const int ALICE = +1;
    const int LEFT = 0, RIGHT = 1;
    

    

    

    

    

    for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      f[i][j][LEFT] = f[i][j][RIGHT] = 0;
    }
    }
    auto win=[](char a, char b) { return sgn(b-a); };
    for (int i = 0; i < n; ++i) {
      if (i > 0) f[i][i][LEFT] = win(s[i-1],s[i]);
      if (i < n-1) f[i][i][RIGHT] = win(s[i+1],s[i]);
    }
    for (int len = 2; len <= n; len ++) {
      for (int start = 0; start + len - 1 < n; ++start) {
        for (int dir = LEFT; dir <= RIGHT; ++dir) {
          int end = start+len-1;
          if (len != n) {
            if (start == 0 && dir == LEFT ) continue;
            if (end == n-1 && dir == RIGHT) continue;
            

          }
          ;;
          

          if (len % 2 == 0) {
            f[start][end][dir] = max(f[start][end-1][RIGHT], f[start+1][end][LEFT]);
          }
          else {
            char last = s[dir==LEFT?start-1:end+1];
            

                 if (s[start] < last && f[start+1][end][LEFT] <= DRAW) f[start][end][dir] = BOB;
            else if (s[start] == last && f[start+1][end][LEFT] == BOB) f[start][end][dir] = BOB;
            else if (s[end] < last && f[start][end-1][RIGHT] <= DRAW) f[start][end][dir] = BOB;
            else if (s[end] == last && f[start][end-1][RIGHT] == BOB) f[start][end][dir] = BOB;
            else if (s[start] == last && f[start+1][end][LEFT] == DRAW) f[start][end][dir] = DRAW;
            else if (s[end] == last && f[start][end-1][RIGHT] == DRAW) f[start][end][dir] = DRAW;
            else f[start][end][dir] = ALICE;
            

          }
          

          

          

          

          

          

          

          

          

          

          

          

          

          

          

          

          

          

          

        }
      }
    }
    

    

    

    

    

    

    int ans = f[0][n-1][LEFT];
    if (ans == DRAW) puts("Draw");
    else if (ans == ALICE) puts("Alice");
    else puts("Bob");
  }
  return 0;
}
