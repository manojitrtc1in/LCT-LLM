#define md 1000000007
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
#define INTEGERONLY
#ifdef IALL
  #define int long long
#endif
namespace Template {
  #define FOR(i, x, y) for(int i = (x); i <= (y); ++i)
  #define FORD(i, x, y) for(int i = (x); i >= (y); --i)
  #define MASK(i) (1LL << (i))
  #define COUNT(x) __builtin_popcountll(x)
  #define BIT(x, i) (((x) >> (i)) & 1)
  #define pb push_back
  #define eb emplace_back
  #define Size(v) (int)v.size()
  typedef long long ll;
  typedef long double ld;
  typedef vector<int> vi;
  typedef vector<long long> vll;
  typedef vector<pair<int, int>> vii;
  typedef pair<int, int> ii;
  template <typename T>
  using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
  const double pi = acos(-1);
  struct Point {
    ll x, y;
    Point(): x{0}, y{0} {}
    Point(ll a, ll b): x{a}, y{b} {}
    bool operator<(const Point& other) const {
      return make_pair(x, y) < make_pair(other.x, other.y);
    }
    Point operator-(const Point& other) const {
      return Point(x - other.x, y - other.y);
    }
    ll operator*(const Point& other) const {
      return (x * other.y - y * other.x);
    }
    ll operator%(const Point& other) const {
      return (x * other.x + y * other.y);
    }
    double len() {
      return sqrt((double)x * x + y * y);
    }
  };
  double angle(const Point & a, const Point & b, const Point & c) {return atan2((a - b) * (c - b), (a - b) % (c - b));}
  double dist(const Point & a, const Point & b) {return (b - a).len();}
  ll area2(const Point & a, const Point & b, const Point & c) {return abs((b - a) * (c - a));}
  bool obtuse(const Point & a, const Point & b, const Point & c) {return abs(angle(a, b, c)) > pi / 2;}
  ll eval(Point a, Point b, Point c) {return (b - a) * (c - b);}
  bool cw(Point a, Point b, Point c) {return eval(a, b, c) < 0;}
  bool ccw(Point a, Point b, Point c) {return eval(a, b, c) > 0;}
  void convex_hull(vector<Point> & a) {
    if (Size(a) == 1) return;
    sort(a.begin(), a.end());
    Point p1 = a[0], p2 = a.back();
    vector<Point> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < Size(a); ++i) {
      if (i == Size(a) - 1 || cw(p1, a[i], p2)) {
        while (Size(up) >= 2 && !cw(up[Size(up) - 2], up[Size(up) - 1], a[i])) {
          up.pop_back();
        }
        up.push_back(a[i]);
      }
      if (i == Size(a) - 1 || ccw(p1, a[i], p2)) {
        while (Size(down) >= 2 && !ccw(down[Size(down) - 2], down[Size(down) - 1], a[i])) {
          down.pop_back();
        }
        down.push_back(a[i]);
      }
    }
    a.clear();
    

    for (int i = 0; i < Size(up); ++i) a.pb(up[i]);
    for (int i = Size(down) - 2; i > 0; --i) a.pb(down[i]);
  }
  double area(vector<Point> & temp) {
    int n = Size(temp);
    double res = 0;
    for (int i = 0; i < n - 1; ++i) {
      

      res += temp[i] * temp[i + 1];
    }
    res += temp[n - 1] * temp[0];
    return abs(res) / 2.0;
  }
  ll raw_dist(const Point& a, const Point& b) {
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y);
  }
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
  mt19937 mt_rng(chrono::steady_clock::now().time_since_epoch().count());
  ll randint(ll a, ll b) {
    return uniform_int_distribution<ll>(a, b)(mt_rng);
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
    #ifdef IALL
      #undef int
    #endif
    Modular operator++(int) { Modular result(*this); *this += 1; return result; }
    Modular operator--(int) { Modular result(*this); *this -= 1; return result; }
    Modular operator-() const { return Modular(-value); }
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, int>::value, Modular>::type& operator*=(const Modular& rhs) {
    #ifdef IALL
      #define int long long
    #endif
  #ifdef _WIN32
      uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
      uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x), d, m;
      asm(
        "divl %4; \n\t"
        : "=a" (d), "=d" (m)
        : "d" (xh), "a" (xl), "r" (mod())
      );
      value = m;
  #else
      value = normalize(static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value));
  #endif
      return *this;
    }
    #ifdef IALL
      #define int long long
    #endif
    template <typename U = T>
    typename enable_if<is_same<typename Modular<U>::Type, ll>::value, Modular>::type& operator*=(const Modular& rhs) {
      ll q = static_cast<ll>(static_cast<ld>(value) * rhs.value / mod());
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
    typename common_type<typename Modular<T>::Type, ll>::type x;
    stream >> x;
    number.value = Modular<T>::normalize(x);
    return stream;
  }
  using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
  inline void set_precision(const int& x) {cout << fixed << setprecision(x);}
  #ifdef INTEGERONLY
    inline void read(Mint & x) {char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=x*10+c-48;if(nega) x=-x;}
    inline void writep(const Mint & _x){int x=(int)_x;if(x>9) writep(x/10);putchar(x%10+48);}
    inline void write(const Mint & _x) {int x=(int)_x;if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
    inline void writeln(const Mint & x) {write(x);putchar('\n');}
    inline void sysout(const Mint & x) {cout << x;}
    template <typename T> inline void read(T &x){char c;bool nega=0;while((!isdigit(c=getchar()))&&(c!='-'));if(c=='-'){nega=1;c=getchar();}x=c-48;while(isdigit(c=getchar())) x=(x<<3)+(x<<1)+c-48;if(nega) x=-x;}
    template <typename T> inline void writep(const T & x){if(x>9) writep(x/10);putchar(x%10+48);}
    template <typename T> inline void write(T x){if(x<0){putchar('-');x=-x;}writep(x);putchar(' ');}
    template <typename T> inline void writeln(const T & x){write(x);putchar('\n');}
    template<class H, class... T> inline void read(H& h, T&... t) {
      read(h);
      read(t...);
    }
    template<class H, class... T> inline void write(const H& h, const T&... t) { 
      write(h);
      write(t...);
    }
    template<class H, class... T> inline void writeln(const H& h, const T&... t) {
      write(h);
      write(t...);
      putchar('\n');
    }
  #endif
  #ifndef INTEGERONLY
    template<typename T> inline void read(T& x) {cin >> x;}
    template<typename T> inline void write(const T& x) {cout << x << ' ';}
    template<typename T> inline void writeln(const T& x) {cout << x << '\n';}
    template<typename H, typename... T> inline void read(H& h, T&... t) {
      read(h);
      read(t...);
  }
  template<typename H, typename... T> inline void write(const H& h, const T&... t) {
    write(h);
    write(t...);
  }
  template<typename H, typename... T> inline void writeln(const H& h, const T&... t) {
    write(h);
    write(t...);
    cout << '\n';
  }
  #endif
  template <typename T>
  __attribute__((always_inline)) void chmax(T& a, const T& b) {a=a<b?b:a;}
  template<typename T>
  __attribute__((always_inline)) void chmin(T& a, const T& b) {a=a<b?a:b;}
  void debug_out() {cerr << endl;}
  template <typename Head, typename... Tail>
  void debug_out(Head H, Tail... T) {
    cerr << " " << std::to_string(H);
    debug_out(T...);
  }
  #define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
}
using namespace Template;

ll n, m;
Mint cur;
bool quit = false;

Mint get(ll l, ll r) {
	return Mint(l + r) * (r - l + 1) / 2;
}

inline void solve(ll l, ll r) {
	if (quit) return;
	if (r >= m) {
		r = m;
		quit = true;
	}
	ll val = n / l;
	cur -= Mint(val) * get(l, r);
}

inline void decompose_into_segments(ll i) {
	ll k = 1;
	while (k <= i) {
		if (quit) return;
		ll first = k;
		ll q = i / k;
		ll second = i / q;
		k = second + 1;
		solve(first, second);
	}
}


int32_t main() {
    #define filename ""
    if (fopen(filename".INP", "r")) {
        freopen(filename".INP", "r", stdin);
        freopen(filename".OUT", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    read(n, m);
    

    cur = Mint(n)*min(n, m);
    decompose_into_segments(n);
    if (n < m) cur += Mint(n) * (m - n);

    write(cur);

    return 0;
}