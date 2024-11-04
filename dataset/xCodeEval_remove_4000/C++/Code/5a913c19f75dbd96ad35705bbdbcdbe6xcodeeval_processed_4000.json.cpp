

















using namespace std;

using LL = long long;

template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a; swap(a, m);
    u -= t * v; swap(u, v);
  }
  assert(m == 1);
  return u;
}
 
template <typename T>
class Modular {
 public:
  using Type = typename decay<decltype(T::value)>::type;
 
  constexpr Modular() : value() {}
  template <typename U>
  Modular(const U& x) {
    value = normalize(x);
  }
 
  template <typename U>
  static Type normalize(const U& x) {
    Type v;
    if (-mod() <= x && x < mod()) v = static_cast<Type>(x);
    else v = static_cast<Type>(x % mod());
    if (v < 0) v += mod();
    return v;
  }
 
  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const { return static_cast<U>(value); }
  constexpr static Type mod() { return T::value; }
 
  Modular& operator+=(const Modular& other) { if ((value += other.value) >= mod()) value -= mod(); return *this; }
  Modular& operator-=(const Modular& other) { if ((value -= other.value) < 0) value += mod(); return *this; }
  template <typename U> Modular& operator+=(const U& other) { return *this += Modular(other); }
  template <typename U> Modular& operator-=(const U& other) { return *this -= Modular(other); }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) { Modular result(*this); *this += 1; return result; }
  Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
  Modular operator-() const { return Modular(-value); }
 
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
    asm(
      "divl %4; \n\t"
      : "=a" (d), "=d" (m)
      : "d" (xh), "a" (xl), "r" (mod())
    );
    value = m;

    value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value, Modular>::type& operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) * rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value, Modular>::type& operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }
 
  Modular& operator/=(const Modular& other) { return *this *= Modular(inverse(other.value, mod())); }
 
  friend const Type& abs(const Modular& x) { return x.value; }
 
  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);
 
  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);
 
 private:
  Type value;
};
 
template <typename T> bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value == rhs.value; }
template <typename T, typename U> bool operator==(const Modular<T>& lhs, U rhs) { return lhs == Modular<T>(rhs); }
template <typename T, typename U> bool operator==(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) == rhs; }
 
template <typename T> bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(const Modular<T>& lhs, U rhs) { return !(lhs == rhs); }
template <typename T, typename U> bool operator!=(U lhs, const Modular<T>& rhs) { return !(lhs == rhs); }
 
template <typename T> bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) { return lhs.value < rhs.value; }
 
template <typename T> Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) += rhs; }
template <typename T, typename U> Modular<T> operator+(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) += rhs; }
 
template <typename T> Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) -= rhs; }
template <typename T, typename U> Modular<T> operator-(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) -= rhs; }
 
template <typename T> Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) *= rhs; }
template <typename T, typename U> Modular<T> operator*(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) *= rhs; }
 
template <typename T> Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(const Modular<T>& lhs, U rhs) { return Modular<T>(lhs) /= rhs; }
template <typename T, typename U> Modular<T> operator/(U lhs, const Modular<T>& rhs) { return Modular<T>(lhs) /= rhs; }
 
template<typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1) res *= x;
    x *= x;
    p >>= 1;
  }
  return res;
}
 
template <typename T>
bool IsZero(const Modular<T>& number) {
  return number() == 0;
}
 
template <typename T>
string to_string(const Modular<T>& number) {
  return to_string(number());
}
 


template <typename U, typename T>
U& operator<<(U& stream, const Modular<T>& number) {
  return stream << number();
}
 


template <typename U, typename T>
U& operator>>(U& stream, Modular<T>& number) {
  typename common_type<typename Modular<T>::Type, long long>::type x;
  stream >> x;
  number.value = Modular<T>::normalize(x);
  return stream;
}
 
using ModType = int;
 
struct VarMod { static ModType value; };
ModType VarMod::value;
ModType& md = VarMod::value;
using Mint = Modular<VarMod>;

namespace atcoder {









struct dsu {
public:
  dsu() : _n(0) {}
  dsu(int n) : _n(n), parent_or_size(n, -1), cnt(n, 0), val(n, 0) {}

  void set_val(vector<int>& val_) {
    val = move(val_);
  }

  int get_val(int a) {
    assert(0 <= a && a < _n);
    return val[leader(a)];
  }

  int merge(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    int x = leader(a), y = leader(b);
    if (x == y) {
      ++cnt[x];
      return x;
    }
    if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
    parent_or_size[x] += parent_or_size[y];
    parent_or_size[y] = x;
    cnt[x] = cnt[x] + cnt[y] + 1;
    val[x] = val[x] * val[y];
    return x;
  }

  bool same(int a, int b) {
    assert(0 <= a && a < _n);
    assert(0 <= b && b < _n);
    return leader(a) == leader(b);
  }

  int leader(int a) {
    assert(0 <= a && a < _n);
    if (parent_or_size[a] < 0) return a;
    return parent_or_size[a] = leader(parent_or_size[a]);
  }

  int size(int a) {
    assert(0 <= a && a < _n);
    return -parent_or_size[leader(a)];
  }

  int edge(int a) {
    assert(0 <= a && a < _n);
    return cnt[leader(a)];
  }

  std::vector<std::vector<int>> groups() {
    std::vector<int> leader_buf(_n), group_size(_n);
    for (int i = 0; i < _n; i++) {
      leader_buf[i] = leader(i);
      group_size[leader_buf[i]]++;
    }
    std::vector<std::vector<int>> result(_n);
    for (int i = 0; i < _n; i++) {
      result[i].reserve(group_size[i]);
    }
    for (int i = 0; i < _n; i++) {
      result[leader_buf[i]].push_back(i);
    }
    result.erase(
      std::remove_if(result.begin(), result.end(),
                     [&](const std::vector<int>& v) { return v.empty(); }),
      result.end());
    return result;
  }

private:
  int _n;
  

  

  std::vector<int> parent_or_size;
  vector<int> cnt, val;
};

}  


const int MAXN = 2010;

int x[MAXN][MAXN];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  md = 998244353;
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; ++i) cin >> s[i];
  if (n % 2 == 0 && m % 2 == 0) {
    Mint ans = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '?') ans *= 2;
      }
    }
    cout << ans << endl;
  } else
  if (n % 2 == 1 && m % 2 == 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (s[i][j] == '?') x[i][j] = 0;
        if (s[i][j] == '0') x[i][j] = 1;
        if (s[i][j] == '1') x[i][j] = -1;
      }
    }    
    bool zero = false, one = false;
    for (int i = 0; i < n; ++i) {
      int val = 1;
      for (int j = 0; j < m; ++j) val *= x[i][j];
      if (val == 0) continue;
      if (val == 1) zero = true; else one = true;
    }
    for (int j = 0; j < m; ++j) {
      int val = 1;
      for (int i = 0; i < n; ++i) val *= x[i][j];
      if (val == 0) continue;
      if (val == 1) zero = true; else one = true;
    }
    if (zero && one) {
      cout << 0 << endl;
      return 0;
    }
    vector<int> val(n + m, 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (x[i][j] == -1) val[i] *= -1;
      }
    }
    for (int j = 0; j < m; ++j) {
      for (int i = 0; i < n; ++i) {
        if (x[i][j] == -1) val[n + j] *= -1;
      }
    }
    atcoder::dsu dsu(n + m);
    dsu.set_val(val);

    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (x[i][j] == 0) {
          dsu.merge(i, n + j);
        }
      }
    }

    Mint ans0 = 0, ans1 = 0;
    if (!one) {
      

      ans0 = 1;
      for (int i = 0; i < n + m; ++i) {
        if (dsu.leader(i) != i) continue;
        if (dsu.size(i) % 2 == 0) {
          if (dsu.get_val(i) == 1) {
            for (int j = 0; j < dsu.edge(i) - dsu.size(i) + 1; ++j) ans0 *= 2;
          } else {
            ans0 = 0;
            break;
          }
        } else {
          if (dsu.get_val(i) == 1) {
            for (int j = 0; j < dsu.edge(i) - dsu.size(i) + 1; ++j) ans0 *= 2;
          } else {
            ans0 = 0;
            break;
          }
        }
      }
    }
    if (!zero) {
      

      ans1 = 1;
      for (int i = 0; i < n + m; ++i) {
        if (dsu.leader(i) != i) continue;
        if (dsu.size(i) % 2 == 0) {
          if (dsu.get_val(i) == 1) {
            for (int j = 0; j < dsu.edge(i) - dsu.size(i) + 1; ++j) ans1 *= 2;
          } else {
            ans1 = 0;
            break;
          }
        } else {
          if (dsu.get_val(i) == -1) {
            for (int j = 0; j < dsu.edge(i) - dsu.size(i) + 1; ++j) ans1 *= 2;
          } else {
            ans1 = 0;
            break;
          }
        }
      }
    }
    cout << ans0 + ans1 << endl;
  } else {
    if (m % 2 == 0) {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == '?') x[j][i] = 0;
          if (s[i][j] == '0') x[j][i] = 1;
          if (s[i][j] == '1') x[j][i] = -1;
        }
      }
      swap(n, m);
    } else {
      for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
          if (s[i][j] == '?') x[i][j] = 0;
          if (s[i][j] == '0') x[i][j] = 1;
          if (s[i][j] == '1') x[i][j] = -1;
        }
      }
    }
    bool zero = false, one = false;
    Mint ans = 1;
    for (int i = 0; i < n; ++i) {
      int val = 1, cnt = 0;
      for (int j = 0; j < m; ++j) {
        val *= x[i][j];
        if (x[i][j] == 0) ++cnt;
      }
      for (int j = 0; j + 1 < cnt; ++j) ans *= 2;
      if (val == 0) continue;
      if (val == 1) zero = true; else one = true;
    }
    if (zero && one) {
      cout << 0 << endl;
    } else 
    if (zero || one) {
      cout << ans << endl;
    } else {
      cout << ans + ans << endl;
    }
  }
  return 0;
}