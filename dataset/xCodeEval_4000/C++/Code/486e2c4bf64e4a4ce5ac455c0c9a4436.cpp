






#ifdef OUT
#define NDEBUG
NDEBUG
#endif

#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>



using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;

template<class T>
using vec3d = std::vector<std::vector<std::vector<T>>>;

template<class T>
using vec4d = std::vector<std::vector<std::vector<std::vector<T>>>>;

template<class T>
vec<T> makeVec(const int n1) {
  return vec<T>(n1);
}

template<class T>
vec<T> makeVec(const int n1, const T initValue) {
  return vec<T>(n1, initValue);
}

template<class T>
vec2d<T> makeVec2d(const int n1) {
  return vec2d<T>(n1);
}

template<class T>
vec2d<T> makeVec2d(const int n1, const int n2) {
  return vec2d<T>(n1, vec<T>(n2));
}

template<class T>
vec2d<T> makeVec2d(const int n1, const int n2, const T initValue) {
  return vec2d<T>(n1, vec<T>(n2, initValue));
}

template<class T>
vec3d<T> makeVec3d(const int n1) {
  return vec3d<T>(n1);
}

template<class T>
vec3d<T> makeVec3d(const int n1, const int n2) {
  return vec3d<T>(n1, vec2d<T>(n2));
}

template<class T>
vec3d<T> makeVec3d(const int n1, const int n2, const int n3) {
  return vec3d<T>(n1, vec2d<T>(n2, vec<T>(n3)));
}

template<class T>
vec3d<T> makeVec3d(const int n1, const int n2, const int n3, const T initValue) {
  return vec3d<T>(n1, vec2d<T>(n2, vec<T>(n3, initValue)));
}

template<class T>
vec4d<T> makeVec4d(const int n1) {
  return vec4d<T>(n1);
}

template<class T>
vec4d<T> makeVec4d(const int n1, const int n2) {
  return vec4d<T>(n1, vec3d<T>(n2));
}

template<class T>
vec4d<T> makeVec4d(const int n1, const int n2, const int n3) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3)));
}

template<class T>
vec4d<T> makeVec4d(const int n1, const int n2, const int n3, const int n4) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3, vec<T>(n4))));
}

template<class T>
vec3d<T>
makeVec4d(const int n1, const int n2, const int n3, const int n4, const T initValue) {
  return vec4d<T>(n1, vec3d<T>(n2, vec2d<T>(n3, vec<T>(n4, initValue))));
}

template<class T>
void fillVec(vec<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    v[i] = value;
  }
}

template<class T>
void fillVec(vec2d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

template<class T>
void fillVec(vec3d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

template<class T>
void fillVec(vec4d<T>& v, const T value) {
  for (int i = 0; i < (int) v.size(); ++i) {
    fillVec(v[i], value);
  }
}

#define FOR(i, n) for (int i = 0; i < (n); ++i)
#define FORA(i, a, n) for (int i = (a); i < (n); ++i)

#define forn(t, i, n) for (t i = 0; i < (n); ++i)
#define foran(t, i, a, n) for (t i = (a); i < (n); ++i)
#define rforn(t, i, n) for (t i = (n) - 1; i >= 0; --i)
#define rforan(t, i, a, n) for (t i = (n) - 1; i >= (a); --i)
#define all(c) c.begin(), c.end()
#define rall(c) c.rbegin(), c.rend()
#define F0(e) [&]() {return e;}
#define F1(e) [&](size_t i1) {return e;}
#define F2(e) [&](size_t i1, size_t i2) {return e;}
#define F3(e) [&](size_t i1, size_t i2, size_t i3) {return e;}
#define F4(e) [&](size_t i1, size_t i2, size_t i3, size_t i4) {return e;}
#define F5(e) [&](size_t i1, size_t i2, size_t i3, size_t i4, size_t i5) {return e;}

template <class T = double>
T pi() {
    return acos(T(-1));
};

typedef int64_t i64;
typedef uint64_t ui64;
typedef int32_t i32;
typedef uint32_t ui32;


using namespace std;





bool __hack = std::ios::sync_with_stdio(false);


auto __hack1 = cin.tie(nullptr);



template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}

template<class T>
inline T mx(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mx(T arg, Ts... args) {
    auto arg1 = mx(args...);
    return arg > arg1 ? arg : arg1;
}

template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}

template<class T, class... Args>
inline bool rmx(T &to, Args... args) {
    auto v = mx(args...);
    if (to < v) {
        to = v;
        return true;
    }
    return false;
}

template <class T>
T gen_pow(T ret, T x, uint64_t pow) {
    while (pow) {
        if (pow & 1) {
            ret *= x;
        }
        pow /= 2;
        if (pow) {
            x *= x;
        }
    }
    return ret;
}

int parseInt(const string& s) { return stoi(s); }

i64 parseInt64(const string& s) { return stoll(s); }

template <class F, bool Rev>
struct ByComparator {
    ByComparator(F f_): f(f_) {};

    template <class T>
    bool operator()(const T& lhs, const T& rhs) {
        if (Rev) {
            return f(lhs) > f(rhs);
        } else {
            return f(lhs) < f(rhs);
        }
    }

    F f;
};

template <bool Rev = false, class F = void>
ByComparator<F, Rev> by(F f) {
    return {f};
}

template <class T>
T pop_back(vector<T>& v) {
    T ret = v.back();
    v.pop_back();
    return ret;
}

template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}

template <class T, class C, class Cmp>
T pop(priority_queue<T, C, Cmp>& v) {
    T ret = v.top();
    v.pop();
    return ret;
}

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

template <class T> using StdTree = __gnu_pbds::tree<T, __gnu_pbds::null_type, less<T>, __gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update>;

template<class T>
void updateEvery(vec<T>& v, function<void(T&)>& f) {
  for_each(all(v), f);
}

template<class T>
void addOne(vec<T>& v) {
  for_each(all(v), [] (T& el) {
    ++el;
  });
}

template<class T>
void subOne(vec<T>& v) {
  for_each(all(v), [] (T& el) {
    --el;
  });
}

vec<int> permutationPositions(const vec<int>& p) {
  vec<int> pos(p.size());
  FOR(i, p.size()) {
    pos[p[i]] = i;
  }
  return pos;
}





using namespace std;






struct Input {

    Input(istream &in) : in(&in) {}

    template<class T>
    T next() const {
        T x;
        *in >> x;
        return x;
    }

    int ni() const {
        return next<int>();
    }

    i64 ni64() const {
        return next<i64>();
    }

    string ns() const {
        return next<string>();
    }

    template<class T>
    vec<T> nVec(int n) const {
        vec<T> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
        }
        return v;
    }

    vec<int> nvi(int n) const {
        return nVec<int>(n);
    }

    vec<i64> nvi64(int n) const {
        return nVec<i64>(n);
    }

    vec<string> nvs(int n) const {
        return nVec<string>(n);
    }

    template<class T>
    void read(vec<T>& v, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
        }
    }

    template<class T, class U=T>
    void read(vec<T>& v, vec<U>& v2, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
            v2[i] = next<U>();
        }
    }

    template<class T, class U=T, class V=T>
    void read(vec<T>& v, vec<U>& v2, vec<V>& v3, int n) {
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
            v2[i] = next<U>();
            v2[i] = next<V>();
        }
    }

    istream *in;
};

Input in(cin);




class Output {

private:
ostream *out;

template<typename T>
void printSingle(const T &value) {
    *out << value;
}

template<typename T>
void printSingle(const vec<T> &v) {
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (i == 0) {
            *out << v[i];
        } else {
            *out << ' ' << v[i];
        }
    }
}

template<typename T, typename U>
void printSingle(const pair<T, U> &p) {
    *out << p.first << ' ' << p.second;
}

public:
Output(ostream &out) : out(&out) {}

inline void flush() {
    out->flush();
}

inline void setPrecision(int d) {
    *out << fixed << setprecision(d);
}

inline void print() {}

template<typename T, typename...Ts>
inline void print(const T &f, const Ts&... args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
    }
}

template<typename...Ts>
inline void println(const Ts&... args) {
    print(args...);
    *out << '\n';
}

template<typename...Ts>
inline void operator() (const Ts&... args) {
    println(args...);
}

template<typename T>
ostream& operator<< (const T& x) {
    *out << x;
    return *out;
}

};

Output out(cout);





#define ENABLE_IF(e) typename enable_if<e>::type* = nullptr

namespace template_util {
    template<class T>
    constexpr T min(T a, T b) {
        return a < b ? a : b;
    }

    template<class T>
    constexpr T max(T a, T b) {
        return a > b ? a : b;
    }

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        typedef uint64_t type;
    };

    template<>
    struct bytetype<4> {
        typedef uint32_t type;
    };

    template<>
    struct bytetype<3> {
        typedef uint32_t type;
    };

    template<>
    struct bytetype<2> {
        typedef uint16_t type;
    };

    template<>
    struct bytetype<1> {
        typedef uint8_t type;
    };

    template<>
    struct bytetype<0> {
        typedef uint8_t type;
    };

    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


#ifdef LOCAL

template<class A, class B>
void dbgPrint(const pair<A, B>& val);

template<class... Ts>
void dbgPrint(const tuple<Ts...>& val);

template<class T>
void dbgPrint(const T& val) {
    cout << val;
}

template<class T>
void dbgPrint(const vector<T>& val) {
    cout << "[";
    bool first = true;
    for (const auto& v : val) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }
        dbgPrint(v);
    }
    cout << "]";
}

template<class K, class V>
void dbgPrint(const unordered_map<K, V>& val) {
    cout << "{";
    bool first = true;
    for (const auto& it : val) {
        if (!first) {
            cout << ", ";
        } else {
            first = false;
        }
        dbgPrint(it.first);
        cout << ": ";
        dbgPrint(it.second);
    }
    cout << "}";
}

template<class A, class B>
void dbgPrint(const pair<A, B>& val) {
    cout << "<";
    dbgPrint(val.first);
    cout << ", ";
    dbgPrint(val.second);
    cout << ">";
}

template<int I>
struct dbgPrintTuple {
    template<class... Ts>
    static void print(const tuple<Ts...>& val) {
        dbgPrintTuple<I - 1>::print(val);
        cout << ", ";
        dbgPrint(get<I>(val));
    }
};

template<>
struct dbgPrintTuple<0> {
    template<class... Ts>
    static void print(const tuple<Ts...>& val) {
        dbgPrint(get<0>(val));
    }
};

template<class... Ts>
void dbgPrint(const tuple<Ts...>& val) {
    cout << "<";
    dbgPrintTuple<sizeof...(Ts) - 1>::print(val);
    cout << ">";
}

#else

#define dbg(...) ;
#define dbgPrint(...) ;

#endif

#ifdef LOCAL

template<class... Vals>
void dbg(Vals... vals);

template<class Val>
void dbg(Val val) {
    dbgPrint(val);
    cout << endl;
}

template<>
void dbg() {
    cout << endl;
}

template<class Val, class... Vals>
void dbg(Val val, Vals... vals) {
    dbgPrint(val);
    cout << " ";
    dbg(vals...);
};

#else

#define dbg(...) ;

#endif




template<typename T> static constexpr T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
template<typename T> static constexpr T wrap_pos(T a, T m) { return a < 0 ? a + m : a; }
template<typename T> static constexpr T sqr(T a) { return a * a; }


template<typename T> static constexpr T mod(T a, T m) { return wrap_pos(a % m, m); }

template<typename T>
static constexpr T inverse2(T a, T m) { return a <= 1 ? a : mod((1 - inverse2(m % a, a) * m) / a, m); }

template<typename T>
static constexpr T inverse(T a, T m) { return inverse2(mod(a, m), m); }

template<typename T, typename C, T Modulus>
class MR
{
 private:
  struct tag_plus {}; 

  struct tag_minus {}; 

  struct tag_good {}; 





  static_assert(std::numeric_limits<C>::max() / Modulus / Modulus > 0, "compute type is too small");
  static_assert(Modulus < std::numeric_limits<T>::max() / 2, "storage type is too small");

  static constexpr T reduce(T value, tag_plus)
  {
    return value >= Modulus ? value - Modulus : value;
  }

  static constexpr T reduce(T value, tag_minus)
  {
    return value < 0 ? value + Modulus : value;
  }

  static constexpr T reduce(T value, tag_good) { return value; }

 public:
  T value;
  typedef T value_type;
  typedef C compute_type;
  static constexpr T modulus = Modulus;

  constexpr MR() : value(0) {}
  constexpr MR(C value) : value(reduce(value % Modulus, tag_minus())) {}
  template<typename tag_t>
  constexpr MR(T value, tag_t tag) : value(reduce(value, tag)) {}

  MR &operator=(C value) { this->value = reduce(value % Modulus, tag_minus()); return *this; }

  constexpr MR operator +(MR b) const { return MR(value + b.value, tag_plus()); }
  constexpr MR operator -(MR b) const { return MR(value - b.value, tag_minus()); }
  constexpr MR operator *(MR b) const { return MR(C(value) * C(b.value) % Modulus, tag_good()); }
  constexpr MR operator -() const { return MR(-value, tag_minus()); }

  MR &operator +=(MR b) { value = reduce(value + b.value, tag_plus()); return *this; }
  MR &operator -=(MR b) { value = reduce(value - b.value, tag_minus()); return *this; }
  MR &operator *=(MR b) { value = C(value) * C(b.value) % Modulus; return *this; }

  constexpr bool operator==(MR b) const { return value == b.value; }
  constexpr bool operator!=(MR b) const { return value != b.value; }

  constexpr T get() const { return value; }

  

  constexpr MR inverse() const
  {
    return MR(::inverse(C(value), C(Modulus)), tag_good());
  }
  constexpr MR operator /(MR b) const { return *this * b.inverse(); }
  MR &operator /=(MR b) { return *this *= b.inverse(); }
};

template<typename T, typename C, T Modulus>
static inline std::ostream &operator<<(std::ostream &o, MR<T, C, Modulus> mr)
{
  return o << mr.get();
}

typedef MR<int, int64_t, 998244353> mr;






double EPS = 1e-10;
double PI = acos(-1.);

void setEPS(const double eps) {
  EPS = eps;
}

i64 sqr(i64 x) {
  return x * x;
}

i64 sqr(int x) {
  return x * 1LL * x;
}

double sqr(double x) {
  return x * x;
}

long double sqr(long double x) {
  return x * x;
}

bool doubleLess(double a, double b) {
  return a < b - EPS;
}

bool doubleEqual(double a, double b) {
  return fabs(a - b) < EPS;
}

bool doubleIs0(double a) {
  return fabs(a) < EPS;
}

double doubleMin(double a, double b) {
  return doubleLess(a, b) ? a : b;
}

double doubleMax(double a, double b) {
  return doubleLess(a, b) ? b : a;
}

bool doubleLessOrEqual(double a, double b) {
  return doubleEqual(a, b) || a < b;
}

bool doubleMore(double a, double b) {
  return doubleLess(b, a);
}

bool doubleMoreOrEqual(double a, double b) {
  return doubleLessOrEqual(b, a);
}

int64_t extendedGcd(int64_t a, int64_t b, int64_t& x, int64_t& y) {
  if (a == 0) {
    x = 0;
    y = 1;
    return b;
  }
  int64_t x1, y1;
  auto d = extendedGcd(b % a, a, x1, y1);
  x = y1 - (b / a) * x1;
  y = x1;
  return d;
}

int64_t modInverse(int64_t a, int64_t mod) {
  int64_t x, y;
  auto g = extendedGcd(a, mod, x, y);
  if (g != 1) {
    throw 42;
  }
  x %= mod;
  if (x < 0) {
    x += mod;
  }
  return x;
}

int doubleSign(double x) {
  if (doubleLess(x, 0)) {
    return -1;
  }
  if (doubleEqual(x, 0)) {
    return 0;
  }
  return 1;
}

template<class T>
T abs(T x) {
  return x < 0 ? -x : x;
}

template<>
double abs(double x) {
  return fabs(x);
}

double ssqrt(double x) {
  if (doubleEqual(x, 0)) {
    return 0;
  }
  if (x < 0) throw 42;
  return sqrt(x);
}

double hypot(double x, double y) {
  return ssqrt(sqr(x) + sqr(y));
}

double hypot(int x, int y) {
  return ssqrt(1. * x * x + 1. * y * y);
}

double hypot(i64 x, i64 y) {
  return ssqrt(1. * x * x + 1. * y * y);
}

template<class T>
int sign(T x) {
  if (x > 0) {
    return 1;
  }
  if (x < 0) {
    return -1;
  }
  return 0;
}




template<class T>
vector<T> getFactorials(int n) {
  vector<T> res(n);
  res[0] = T(1);
  for (int i = 1; i < n; ++i) {
    res[i] = res[i - 1] * i;
  }
  return res;
}

template<class T>
vector<T> getReverse(int n, const T MOD) {
  vector<T> res(n, 0);
  if (n > 1) {
    res[1] = 1;
  }
  for (int i = 2; i < n; ++i) {
    res[i] = (MOD - MOD / i * res[((int) (MOD % i))] % MOD) % MOD;
  }
  return res;
}



template<class T>
vector<T> getFactorials(int n, const T MOD) {
  vector<T> res(n);
  res[0] = 1;
  for (int i = 1; i < n; ++i) {
    res[i] = (T) ((res[i - 1] * 1LL * i) % MOD);
  }
  return res;
}

template<class T>
vector<T> getReverseFactorials(int n, const T MOD) {
  vector<T> revs = getReverse(n, MOD);
  vector<T> res(n);
  res[0] = 1;
  for (int i = 1; i < n; ++i) {
    res[i] = (T) ((res[i - 1] * 1LL * revs[i]) % MOD);
  }
  return res;
}

bool isSquare(int64_t number, int64_t& s) {
  s = (int64_t) round(sqrt(1. * number));
  return s * s == number;
}

template<class T>
T pow(T x, T p, const T MOD) {
  T res = 1;
  for (T i = p; i > 0; i >>= 1) {
    if (i & 1) {
      res = (T) ((res * 1LL * x) % MOD);
    }
    x = (T) ((x * 1LL * x) % MOD);
  }
  return res;
}

template<class T, class P>
T pow(T x, P p) {
  T res = 1;
  for (P i = p; i > 0; i >>= 1) {
    if (i & 1) {
      res *= x;
    }
    x *= x;
  }
  return res;
}

double pow(double x, i64 p) {
  double res = 1;
  for (i64 i = p; i > 0; i >>= 1) {
    if (i & 1) {
      res *= x;
    }
    x *= x;
  }
  return res;
}

template<class T>
bool isPrime(T x) {
  if (x == 1) {
    return false;
  }
  if (x == 2) {
    return true;
  }
  if (x % 2 == 0) {
    return false;
  }
  for (T i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}





























template<typename T>
vector<T> generatePowers(T base, int num) {
  vector<T> res(num);
  if (num != 0) {
    res[0] = T(1);
  }
  for (int i = 1; i < num; ++i) {
    res[i] = res[i - 1] * base;
  }
  return res;
}

vector<i64> generatePowers(i64 base, int num, const i64 MOD) {
  vector<i64> res(num);
  if (num != 0) {
    res[0] = 1 % MOD;
  }
  for (int i = 1; i < num; ++i) {
    res[i] = (res[i - 1] * base) % MOD;
  }
  return res;
}

i64 powerInFactorial(i64 n, i64 p) {
  i64 result = 0;
  while (n != 0) {
    result += (n /= p);
  }
  return result;
}

vector<vector<int>> getC(int n, const int MOD) {
  vector<vector<int>> C(n);
  FOR(i, n) {
    C[i] = vector<int>(i + 1);
    FOR(j, i + 1) {
      if (j == 0 || j == i) {
        C[i][j] = 1;
        if (C[i][j] >= MOD) C[i][j] -= MOD;
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
        if (C[i][j] >= MOD) C[i][j] -= MOD;
      }
    }
  }
  return C;
}

template<typename T>
vector<vector<T>> getC(int n) {
  vector<vector<T>> C(n);
  FOR(i, n) {
    C[i] = vector<T>(i + 1);
    FOR(j, i + 1) {
      if (j == 0 || j == i) {
        C[i][j] = T(1);
      } else {
        C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]);
      }
    }
  }
  return C;
}

vector<i64> getCRow(int n, const i64 MOD) {
  auto res = getReverse<i64>(n + 1, MOD);
  res[0] = 1;
  for (int i = 1; i <= n; ++i) {
    res[i] = res[i - 1] * (n - i + 1) % MOD * res[i] % MOD;
  }
  return res;
}

i64
getC(int n, int k, const i64 MOD, const vector<int64_t>& f, const vector<int64_t>& rf) {
  return f[n] * rf[k] % MOD * rf[n - k] % MOD;
}

i64 getA(
    int n, int k, const int64_t MOD, const vector<int64_t>& f,
    const vector<int64_t>& rf) {
  return f[n] * rf[n - k] % MOD;
}

vector<int> getBitPrime(int limit) {
  vector<int> is_prime((limit + 31) >> 5, -1);
  if (limit < 2) {
    return vector<int>((limit + 31) >> 5);
  }
  is_prime[0] &= -4;
  for (int i = 2; i * i < limit; ++i) {
    if ((is_prime[i >> 5] >> (i & 31) & 1) == 1) {
      for (int j = i * i; j < limit; j += i) {
        is_prime[j >> 5] &= (-1 - (1 << (j & 31)));
      }
    }
  }
  return is_prime;
}

vector<int> getPrimes(int limit) {
  auto is_prime = getBitPrime(limit);
  vector<int> result;
  result.reserve(limit);
  FOR(i, limit) {
    if ((is_prime[i >> 5] >> (i & 31) & 1) == 1) {
      result.push_back(i);
    }
  }
  return result;
}

vector<int> getDivisorTable(int limit) {
  vector<int> divisor(limit);
  for (int i = 1; i < limit; ++i) {
    divisor[i] = i;
  }
  for (int i = 2; i * i < limit; ++i) {
    if (divisor[i] == i) {
      for (int j = i * i; j < limit; j += i) {
        divisor[j] = i;
      }
    }
  }
  return divisor;
}

vector<pair<i64, int>> factorize(i64 number) {
  vector<pair<i64, int>> res;
  if (number % 2 == 0) {
    int power = 0;
    do {
      power++;
      number /= 2;
    } while (number % 2 == 0);
    res.push_back({2, power});
  }
  for (i64 i = 3; i * i <= number; i += 2) {
    if (number % i == 0) {
      int power = 0;
      do {
        power++;
        number /= i;
      } while (number % i == 0);
      res.push_back({i, power});
    }
  }
  if (number != 1) {
    res.push_back({number, 1});
  }
  return res;
}


void getDivisorsRec(
    const vector<pair<i64, int>>& prime_divisors, int index, i64 current,
    vector<i64>& result) {
  if (index == prime_divisors.size()) {
    result.push_back(current);
    return;
  }
  i64 p = prime_divisors[index].first;
  int power = prime_divisors[index].second;
  for (int i = 0; i <= power; i++) {
    getDivisorsRec(prime_divisors, index + 1, current, result);
    current *= p;
  }
}

vector<int64_t> getDivisors(int64_t number) {
  auto prime_divisors = factorize(number);
  vector<int64_t> res;
  getDivisorsRec(prime_divisors, 0, 1, res);
  return res;
}

vector<i64> squareEquationClosestIntegersInside(i64 a, i64 b, i64 c) {
  i64 d = b * b - 4LL * a * c;
  if (d < 0) {
    return {};
  }
  i64 d2 = (i64) round(ssqrt(1. * d));
  while (d2 * d2 > d) {
    d2--;
  }
  while ((d2 + 1) * (d2 + 1) <= d) {
    d2++;
  }
  d = d2;
  i64 from = (-b - d) / (2 * a);
  if (from * (2 * a) < -b - d) {
    ++from;
  }
  i64 to = (-b + d) / (2 * a);
  if (to * (2 * a) <= d - b) {
    ++to;
  }
  return {from, to};
}

vector<double> squareEquationSolve(double a, double b, double c) {
  if (doubleEqual(a, 0)) {
    if (doubleEqual(b, 0)) {
      if (doubleEqual(c, 0)) {
        return {};
      }
      return {};
    }
    return {-c / b};
  }
  double d = sqr(b) - 4.0 * a * c;
  if (doubleLess(d, 0)) {
    return {};
  }
  if (doubleEqual(d, 0)) {
    return {-b / (2. * a)};
  }
  d = ssqrt(d);
  double from = (-b - d) / (2. * a);
  double to = (-b + d) / (2. * a);
  return {from, to};
}

int64_t countLabeledTrees(int64_t n, int64_t MOD) {
  if (n == 1) {
    return 1 % MOD;
  }
  return pow<int64_t>(n + 1, n - 1, MOD);
}

int64_t countLabelTreesWithDegrees(
    int64_t n, const vector<int64_t>& degrees, const vector<int64_t>& fact,
    const vector<int64_t>& rfact, int64_t MOD) {
  int64_t res = fact[n - 2];
  for (int64_t d : degrees) {
    res *= rfact[d - 1];
    res %= MOD;
  }
  return res;
}

int64_t countLabeledForests(int64_t n, int64_t MOD) {
  if (n <= 2) {
    return 1 % MOD;
  }
  return pow<int64_t>(n, n - 2, MOD);
}

int64_t countLabeledForestsWithKComponents(int64_t n, int64_t k, int64_t MOD) {
  if (k > n) {
    return 0;
  } else if (n == k) {
    return 1 % MOD;
  } else {
    return (k * pow<int64_t>(n, n - k - 1, MOD)) % MOD;
  }
}



template <class T, class R = T>
R sumFloor(T n, T a, T b) {
    assert(gcd(a, b) == 1);
    R ret = 0;
    if (a >= b) {
        ret += R(a / b) * n * (n + 1) / 2;
        a %= b;
    }
    if (a == 0 || n == 0) {
        return ret;
    }
    T m = T(R(a) * n / b);
    ret += R(n) * m + (n / b) - sumFloor<T, R>(m, b, a);
    return ret;
};





class FSbalansirovannieRaspolozheniyaDomino {
public:
	void solve(istream& in1, ostream& out1) {
        Input in(in1);
        Output out(out1);
        auto nRows = in.ni();
        auto nCols = in.ni();
        auto n = in.ni();
        vec<int> rowTaken(nRows, 0);
        vec<int> colTaken(nCols, 0);
        int freeRows = 0, freeCols = 0;
        FOR(i, n) {
            auto r1 = in.ni() - 1;
            auto c1 = in.ni() - 1;
            auto r2 = in.ni() - 1;
            auto c2 = in.ni() - 1;
            rowTaken[r1] = rowTaken[r2] = 1;
            colTaken[c1] = colTaken[c2] = 1;
        }
        FOR(i, nRows) {
            if (!rowTaken[i]) {
                ++freeRows;
            }
        }
        FOR(i, nCols) {
            if (!colTaken[i]) {
                ++freeCols;
            }
        }

        auto calc = [&] (const vec<int>& taken, int nt) -> vec<mr> {
            int maxPairs = nt / 2;
            vec2d<mr> dp = makeVec2d<mr>(nt + 1, maxPairs + 1, 0);
            dp[0][0] = 1;
            FOR(i, nt) {
                bool canPlacePair = taken[i] == 0 && i + 1 < nt && taken[i+1] == 0;
                FOR(j, maxPairs + 1) {
                    if (dp[i][j] != 0) {
                        dp[i + 1][j] += dp[i][j];
                        if (canPlacePair && j < maxPairs) {
                            dp[i + 2][j + 1] += dp[i][j];
                        }
                    }
                }
            }
            return dp[nt];
        };

        auto dpRows = calc(rowTaken, nRows);
        auto dpCols = calc(colTaken, nCols);
        auto f = getFactorials<mr>(3601);
        vec<mr> invF(3601);
        FOR(i, 3601) {
            invF[i] = mr(1) / f[i];
        }
        mr res = 0;
        for (int cntVert = 0; cntVert <= nCols; ++cntVert) {
            FOR(cntHor, nRows + 1) {
                int leftRows = freeRows - 2 * cntVert;
                int leftCols = freeCols - 2 * cntHor;
                if (leftRows >= cntHor && leftCols >= cntVert) {
                    mr options = f[leftRows] * invF[leftRows - cntHor];
                    options = options * f[leftCols] * invF[leftCols - cntVert];
                    options = options * dpRows[cntVert] * dpCols[cntHor];
                    res += options;
                }
            }
        }
        out(res.value);
	}

	void prepare() {

	}
};

int main() {
	FSbalansirovannieRaspolozheniyaDomino solver;
	solver.prepare();
	std::istream& in(std::cin);
	std::ostream& out(std::cout);
	solver.solve(in, out);
	return 0;
}