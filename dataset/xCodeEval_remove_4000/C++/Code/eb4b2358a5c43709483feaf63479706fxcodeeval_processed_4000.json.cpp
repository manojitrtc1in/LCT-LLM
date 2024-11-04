

 

 
using namespace std;
 







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
 

 
constexpr int md = 123;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 

 
namespace factorizer {
 
template <typename T>
struct FactorizerVarMod { static T value; };
template <typename T>
T FactorizerVarMod<T>::value;
 
template <typename T>
bool IsPrime(T n, const vector<T>& bases) {
  if (n < 2) {
    return false;
  }
  vector<T> id1 = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
  for (const T& x : id1) {
    if (n % x == 0) {
      return n == x;
    }
  }
  if (n < 31 * 31) {
    return true;
  }
  int s = 0;
  T d = n - 1;
  while ((d & 1) == 0) {
    d >>= 1;
    s++;
  }
  FactorizerVarMod<T>::value = n;
  for (const T& a : bases) {
    if (a % n == 0) {
      continue;
    }
    Modular<FactorizerVarMod<T>> cur = a;
    cur = power(cur, d);
    if (cur == 1) {
      continue;
    }
    bool witness = true;
    for (int r = 0; r < s; r++) {
      if (cur == n - 1) {
        witness = false;
        break;
      }
      cur *= cur;
    }
    if (witness) {
      return false;
    }
  }
  return true;
}
 
bool IsPrime(int64_t n) {
  return IsPrime(n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}
 
bool IsPrime(int32_t n) {
  return IsPrime(n, {2, 7, 61});
}
 



 
vector<int> least = {0, 1};
vector<int> primes;
int id8 = 1;
 
void id3(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
    for (int x : primes) {
      if (x > least[i] || i * x > n) {
        break;
      }
      least[i * x] = x;
    }
  }
  id8 = n;
}
 
void id2(int n) {
  n = max(n, 1);
  least.assign(n + 1, 0);
  for (int i = 2; i * i <= n; i++) {
    if (least[i] == 0) {
      for (int j = i * i; j <= n; j += i) {
        if (least[j] == 0) {
          least[j] = i;
        }
      }
    }
  }
  primes.clear();
  for (int i = 2; i <= n; i++) {
    if (least[i] == 0) {
      least[i] = i;
      primes.push_back(i);
    }
  }
  id8 = n;
}
 
void id7(int n) {
  id3(n);
}
 
template <typename T>
vector<pair<T, int>> MergeFactors(const vector<pair<T, int>>& a, const vector<pair<T, int>>& b) {
  vector<pair<T, int>> c;
  int i = 0;
  int j = 0;
  while (i < (int) a.size() || j < (int) b.size()) {
    if (i < (int) a.size() && j < (int) b.size() && a[i].first == b[j].first) {
      c.emplace_back(a[i].first, a[i].second + b[j].second);
      ++i;
      ++j;
      continue;
    }
    if (j == (int) b.size() || (i < (int) a.size() && a[i].first < b[j].first)) {
      c.push_back(a[i++]);
    } else {
      c.push_back(b[j++]);
    }
  }
  return c;
}
 
template <typename T>
vector<pair<T, int>> id4(const T& n, const T& c) {
  if (n <= 1) {
    return {};
  }
  if ((n & 1) == 0) {
    return MergeFactors({{2, 1}}, id4(n / 2, c));
  }
  if (IsPrime(n)) {
    return {{n, 1}};
  }
  FactorizerVarMod<T>::value = n;
  Modular<FactorizerVarMod<T>> x = 2;
  Modular<FactorizerVarMod<T>> saved = 2;
  T power = 1;
  T lam = 1;
  while (true) {
    x = x * x + c;
    T g = __gcd((x - saved)(), n);
    if (g != 1) {
      return MergeFactors(id4(g, c + 1), id4(n / g, c + 1));
    }
    if (power == lam) {
      saved = x;
      power <<= 1;
      lam = 0;
    }
    lam++;
  }
  return {};
}
 
template <typename T>
vector<pair<T, int>> Rho(const T& n) {
  return id4(n, static_cast<T>(1));
}
 
template <typename T>
vector<pair<T, int>> Factorize(T x) {
  if (x <= 1) {
    return {};
  }
  if (x <= id8) {
    vector<pair<T, int>> ret;
    while (x > 1) {
      if (!ret.empty() && ret.back().first == least[x]) {
        ret.back().second++;
      } else {
        ret.emplace_back(least[x], 1);
      }
      x /= least[x];
    }
    return ret;
  }
  if (x <= static_cast<int64_t>(id8) * id8) {
    vector<pair<T, int>> ret;
    if (!IsPrime(x)) {
      for (T i : primes) {
        T t = x / i;
        if (i > t) {
          break;
        }
        if (x == t * i) {
          int cnt = 0;
          while (x % i == 0) {
            x /= i;
            cnt++;
          }
          ret.emplace_back(i, cnt);
          if (IsPrime(x)) {
            break;
          }
        }
      }
    }
    if (x > 1) {
      ret.emplace_back(x, 1);
    }
    return ret;
  }
  return Rho(x);
}
 
template <typename T>
vector<T> id9(const vector<pair<T, int>>& factors) {
  vector<T> id0 = {1};
  for (auto& p : factors) {
    int sz = (int) id0.size();
    for (int i = 0; i < sz; i++) {
      T cur = id0[i];
      for (int j = 0; j < p.second; j++) {
        cur *= p.first;
        id0.push_back(cur);
      }
    }
  }
  sort(id0.begin(), id0.end());
  return id0;
}
 
}  

 




 
inline int64_t id5(int x, int y, int pow, int rotate) {
	if (pow == 0) {
		return 0;
	}
	int hpow = 1 << (pow-1);
	int seg = (x < hpow) ? (
		(y < hpow) ? 0 : 3
	) : (
		(y < hpow) ? 1 : 2
	);
	seg = (seg + rotate) & 3;
	const int rotateDelta[4] = {3, 0, 0, 1};
	int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
	int nrot = (rotate + rotateDelta[seg]) & 3;
	int64_t id6 = int64_t(1) << (2*pow - 2);
	int64_t ans = seg * id6;
	int64_t add = id5(nx, ny, pow-1, nrot);
	ans += (seg == 1 || seg == 2) ? add : (id6 - add - 1);
	return ans;
}

set<int> st; 
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i <= 100; ++i) {
        st.insert(i*i); 
    }

    int tt;
    cin >> tt; 
    
    while (tt--) {
        int x, y; 
        cin >> x >> y; 
        if (!(x^y||x^0)) {
            cout << 0 << "\n"; 
        } else {
            cout << (st.find(x*x+y*y)==st.end()?2:1) << "\n"; 
        }
    }
}