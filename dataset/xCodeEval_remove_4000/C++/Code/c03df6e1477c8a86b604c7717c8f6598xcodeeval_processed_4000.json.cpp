































using namespace std;

using ll = long long;
using db = long double;  

using str = string;      




using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pd = pair<db, db>;








tcT > using V = vector<T>;
tcT, size_t SZ > using AR = array<T, SZ>;
using vi = V<int>;
using vb = V<bool>;
using vll = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpii = V<pii>;
using vpll = V<pll>;
using vpd = V<pd>;
using vvi = V<vi>;
using vvpii = V<vpii>;



















tcT > int lwb(V<T>& a, const T& b) {
  return int(lb(all(a), b) - bg(a));
}
tcT > int upb(V<T>& a, const T& b) {
  return int(ub(all(a), b) - bg(a));
}










const int MOD = 998244353;
const int MX = 2e5 + 5;
const ll BIG = 1e18;  

const db PI = acos((db)-1);
const int dx[4]{1, 0, -1, 0}, dy[4]{0, 1, 0, -1};  

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count());
template <class T>
using pqg = priority_queue<T, vector<T>, greater<T>>;





constexpr int pct(int x) {
  return __builtin_popcount(x);
}  

constexpr int bits(int x) {  

                             

  return x == 0 ? 0 : 31 - __builtin_clz(x);
}  

constexpr int p2(int x) {
  return 1 << x;
}
constexpr int id4(int x) {
  return p2(x) - 1;
}

ll cdiv(ll a, ll b) {
  return a / b + ((a ^ b) > 0 && a % b);
}  

ll fdiv(ll a, ll b) {
  return a / b - ((a ^ b) < 0 && a % b);
}  


tcT > bool ckmin(T& a, const T& b) {
  return b < a ? a = b, 1 : 0;
}  

tcT > bool ckmax(T& a, const T& b) {
  return a < b ? a = b, 1 : 0;
}  


tcTU > T fstTrue(T lo, T hi, U f) {
  ++hi;
  assert(lo <= hi);  

  while (lo < hi) {  

    T mid = lo + (hi - lo) / 2;
    f(mid) ? hi = mid : lo = mid + 1;
  }
  return lo;
}
tcTU > T lstTrue(T lo, T hi, U f) {
  --lo;
  assert(lo <= hi);  

  while (lo < hi) {  

    T mid = lo + (hi - lo + 1) / 2;
    f(mid) ? lo = mid : hi = mid - 1;
  }
  return lo;
}
tcT > void remDup(vector<T>& v) {  

  sort(all(v));
  v.erase(unique(all(v)), end(v));
}
tcTU > void erase(T& t, const U& u) {  

  auto it = t.find(u);
  assert(it != end(t));
  t.erase(it);
}  




inline namespace Helpers {






tcT, class = void > struct is_iterable : false_type {};
tcT > struct is_iterable<
          T,
          void_t<decltype(begin(declval<T>())), decltype(end(declval<T>()))>>
    : true_type {};
tcT > constexpr bool id8 = is_iterable<T>::value;



tcT, class = void > struct is_readable : false_type {};
tcT >
    struct is_readable<T,
                       typename std::enable_if_t<
                           is_same_v<decltype(cin >> declval<T&>()), istream&>>>
    : true_type {};
tcT > constexpr bool id0 = is_readable<T>::value;





tcT, class = void > struct is_printable : false_type {};
tcT > struct is_printable<
          T,
          typename std::enable_if_t<
              is_same_v<decltype(cout << declval<T>()), ostream&>>>
    : true_type {};
tcT > constexpr bool id1 = is_printable<T>::value;
}  


inline namespace Input {
tcT > constexpr bool id7 = !id0<T> && id8<T>;
tcTUU > void re(T& t, U&... u);
tcTU > void re(pair<T, U>& p);  




tcT > typename enable_if<id0<T>, void>::type re(T& x) {
  cin >> x;
}  

tcT > void re(complex<T>& c) {
  T a, b;
  re(a, b);
  c = {a, b};
}  

tcT > typename enable_if<id7<T>, void>::type re(
          T& i);  

tcTU > void re(pair<T, U>& p) {
  re(p.fi, p.se);
}
tcT > typename enable_if<id7<T>, void>::type re(T& i) {
  each(x, i) re(x);
}
tcTUU > void re(T& t, U&... u) {
  re(t);
  re(u...);
}  




void rv(size_t) {}
tcTUU > void rv(size_t N, V<T>& t, U&... u);
template <class... U>
void rv(size_t, size_t N2, U&... u);
tcTUU > void rv(size_t N, V<T>& t, U&... u) {
  t.rsz(N);
  re(t);
  rv(N, u...);
}
template <class... U>
void rv(size_t, size_t N2, U&... u) {
  rv(N2, u...);
}



void decrement() {}  

tcTUU > void decrement(T& t, U&... u) {
  --t;
  decrement(u...);
}

  int id5; \
  re(id5);

  ints(id5); \
  decrement(id5);
}  


inline namespace ToString {
tcT > constexpr bool id2 = !id1<T> && id8<T>;



tcT > typename enable_if<id1<T>, str>::type ts(T v) {
  stringstream ss;
  ss << fixed << setprecision(15) << v;
  return ss.str();
}  

tcT > str bit_vec(T t) {  

  str res = "{";
  id3(i, sz(t)) res += ts(t[i]);
  res += "}";
  return res;
}
str ts(V<bool> v) {
  return bit_vec(v);
}
template <size_t SZ>
str ts(bitset<SZ> b) {
  return bit_vec(b);
}  

tcTU > str ts(pair<T, U> p);  

tcT > typename enable_if<id2<T>, str>::type ts(
          T v);  

tcTU > str ts(pair<T, U> p) {
  return "(" + ts(p.f) + ", " + ts(p.s) + ")";
}
tcT > typename enable_if<id8<T>, str>::type ts_sep(T v, str sep) {
  

  bool fst = 1;
  str res = "";
  for (const auto& x : v) {
    if (!fst)
      res += sep;
    fst = 0;
    res += ts(x);
  }
  return res;
}
tcT > typename enable_if<id2<T>, str>::type ts(T v) {
  return "{" + ts_sep(v, ", ") + "}";
}



template <int, class T>
typename enable_if<!id2<T>, vs>::type id6(const T& v) {
  return {ts(v)};
}
template <int lev, class T>
typename enable_if<id2<T>, vs>::type id6(const T& v) {
  if (lev == 0 || !sz(v))
    return {ts(v)};
  vs res;
  for (const auto& t : v) {
    if (sz(res))
      res.bk += ",";
    vs tmp = id6<lev - 1>(t);
    res.ins(end(res), all(tmp));
  }
  id3(i, sz(res)) {
    str bef = " ";
    if (i == 0)
      bef = "{";
    res[i] = bef + res[i];
  }
  res.bk += "}";
  return res;
}
}  


inline namespace Output {
template <class T>
void pr_sep(ostream& os, str, const T& t) {
  os << ts(t);
}
template <class T, class... U>
void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
  pr_sep(os, sep, t);
  os << sep;
  pr_sep(os, sep, u...);
}


template <class... T>
void pr(const T&... t) {
  pr_sep(cout, "", t...);
}


void ps() {
  cout << "\n";
}
template <class... T>
void ps(const T&... t) {
  pr_sep(cout, " ", t...);
  ps();
}


template <class... T>
void dbg_out(const T&... t) {
  pr_sep(cerr, " | ", t...);
  cerr << endl;
}
void loc_info(int line, str names) {
  cerr << "Line(" << line << ") -> [" << names << "]: ";
}
template <int lev, class T>
void id9(const T& t) {
  cerr << "\n\n" << ts_sep(id6<lev>(t), "\n") << "\n" << endl;
}









const clock_t beg = clock();

}  


inline namespace FileIO {
void setIn(str s) {
  freopen(s.c_str(), "r", stdin);
}
void setOut(str s) {
  freopen(s.c_str(), "w", stdout);
}
void setIO(str s = "") {
  cin.tie(0)->sync_with_stdio(0);  

  

  

  

  if (sz(s))
    setIn(s + ".in"), setOut(s + ".out");  

}
}  


template <typename T>
T inverse(T a, T m) {
  T u = 0, v = 1;
  while (a != 0) {
    T t = m / a;
    m -= t * a;
    swap(a, m);
    u -= t * v;
    swap(u, v);
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
    if (-mod() <= x && x < mod())
      v = static_cast<Type>(x);
    else
      v = static_cast<Type>(x % mod());
    if (v < 0)
      v += mod();
    return v;
  }

  const Type& operator()() const { return value; }
  template <typename U>
  explicit operator U() const {
    return static_cast<U>(value);
  }
  constexpr static Type mod() { return T::value; }

  Modular& operator+=(const Modular& other) {
    if ((value += other.value) >= mod())
      value -= mod();
    return *this;
  }
  Modular& operator-=(const Modular& other) {
    if ((value -= other.value) < 0)
      value += mod();
    return *this;
  }
  template <typename U>
  Modular& operator+=(const U& other) {
    return *this += Modular(other);
  }
  template <typename U>
  Modular& operator-=(const U& other) {
    return *this -= Modular(other);
  }
  Modular& operator++() { return *this += 1; }
  Modular& operator--() { return *this -= 1; }
  Modular operator++(int) {
    Modular result(*this);
    *this += 1;
    return result;
  }
  Modular operator--(int) {
    Modular result(*this);
    *this -= 1;
    return result;
  }
  Modular operator-() const { return Modular(-value); }

  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, int>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {

    uint64_t x = static_cast<int64_t>(value) * static_cast<int64_t>(rhs.value);
    uint32_t xh = static_cast<uint32_t>(x >> 32), xl = static_cast<uint32_t>(x),
             d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(mod()));
    value = m;

    value = normalize(static_cast<int64_t>(value) *
                      static_cast<int64_t>(rhs.value));

    return *this;
  }
  template <typename U = T>
  typename enable_if<is_same<typename Modular<U>::Type, long long>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    long long q = static_cast<long long>(static_cast<long double>(value) *
                                         rhs.value / mod());
    value = normalize(value * rhs.value - q * mod());
    return *this;
  }
  template <typename U = T>
  typename enable_if<!is_integral<typename Modular<U>::Type>::value,
                     Modular>::type&
  operator*=(const Modular& rhs) {
    value = normalize(value * rhs.value);
    return *this;
  }

  Modular& operator/=(const Modular& other) {
    return *this *= Modular(inverse(other.value, mod()));
  }

  friend const Type& abs(const Modular& x) {
    return x.value;
  }

  template <typename U>
  friend bool operator==(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename U>
  friend bool operator<(const Modular<U>& lhs, const Modular<U>& rhs);

  template <typename V, typename U>
  friend V& operator>>(V& stream, Modular<U>& number);

 private:
  Type value;
};

template <typename T>
bool operator==(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value == rhs.value;
}
template <typename T, typename U>
bool operator==(const Modular<T>& lhs, U rhs) {
  return lhs == Modular<T>(rhs);
}
template <typename T, typename U>
bool operator==(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) == rhs;
}

template <typename T>
bool operator!=(const Modular<T>& lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(const Modular<T>& lhs, U rhs) {
  return !(lhs == rhs);
}
template <typename T, typename U>
bool operator!=(U lhs, const Modular<T>& rhs) {
  return !(lhs == rhs);
}

template <typename T>
bool operator<(const Modular<T>& lhs, const Modular<T>& rhs) {
  return lhs.value < rhs.value;
}

template <typename T>
Modular<T> operator+(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) += rhs;
}
template <typename T, typename U>
Modular<T> operator+(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) += rhs;
}

template <typename T>
Modular<T> operator-(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) -= rhs;
}
template <typename T, typename U>
Modular<T> operator-(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) -= rhs;
}

template <typename T>
Modular<T> operator*(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) *= rhs;
}
template <typename T, typename U>
Modular<T> operator*(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) *= rhs;
}

template <typename T>
Modular<T> operator/(const Modular<T>& lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(const Modular<T>& lhs, U rhs) {
  return Modular<T>(lhs) /= rhs;
}
template <typename T, typename U>
Modular<T> operator/(U lhs, const Modular<T>& rhs) {
  return Modular<T>(lhs) /= rhs;
}

template <typename T, typename U>
Modular<T> power(const Modular<T>& a, const U& b) {
  assert(b >= 0);
  Modular<T> x = a, res = 1;
  U p = b;
  while (p > 0) {
    if (p & 1)
      res *= x;
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



constexpr int md = (int)998244353;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;



mt19937_64 RNG(chrono::steady_clock::now().time_since_epoch().count());
ll myRand(ll B) {
  return (unsigned long long)RNG() % B;
}

void solve() {
  int n, k;
  re(n, k);
  vi a(n);
  re(a);
  int cnt = 0;

  id3(i, n){
    if(a[i] == 0){
      ++cnt;
    }
  }

  ll sum = accumulate(all(a), 0LL);

  if(abs(sum) > 1LL * k * cnt){
    pr("-1\n");
    return;
  }

  ll ans = 1;

  id3(start, n){
    ll cur = 0;
    ll cur_sum = sum;
    ll l = 0, r = 0;
    int left = cnt;
    id3(i, n){
      int ind = (start + i) % n;

      


      ll val =  a[ind];

      if(a[ind] == 0){
        val = min(1LL * k, (ll)(--left) * k - cur_sum);
        cur_sum += val;
      }

      cur += val;

      r = max(r, cur);
      

    }
    ans = max(ans, (r - l + 1));
  }
  pr(ans, '\n');
}

signed main() {
  setIO();
  int tt = 1;
  

  rep(tt) solve();
  

}


