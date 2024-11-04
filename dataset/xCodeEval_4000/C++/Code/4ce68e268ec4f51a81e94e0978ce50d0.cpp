#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds;
using namespace std;
#ifdef LOCAL
template <typename A, typename B> string to_string(pair<A, B> p);
template <typename A, typename B, typename C> string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D> string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {return '"' + s + '"';}
string to_string(const char* s) {return to_string((string) s);}
string to_string(bool b) {return (b ? "true" : "false");}
string to_string(vector<bool> v) {bool first = true;string res = "{";for (int i = 0; i < static_cast<int>(v.size()); i++) {if (!first) {res += ", ";}first = false;res += to_string(v[i]);}res += "}";return res;}
template <size_t N>string to_string(bitset<N> v) {string res = "";for (size_t i = 0; i < N; i++) {res += static_cast<char>('0' + v[i]);}return res;}
template <typename A>string to_string(A v) {bool first = true;string res = "{";for (const auto &x : v) {if (!first) {res += ", ";}first = false;res += to_string(x);}res += "}";return res;}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A, typename B, typename C>string to_string(tuple<A, B, C> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>string to_string(tuple<A, B, C, D> p) {return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";}
void debug_out() { cerr << "\n"; }
template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) {cerr << " " << to_string(H);debug_out(T...);}
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#define trace(a, n) cerr << #a << "[" << n <<  "] = ["; for (int i = 0; i < n; i++) cerr << a[i] << ", "; cerr << "]\n"
#else
#define debug(...) 42
#define trace(a, n) 42
#endif
#define double long double
#define sz(x) (int)x.size()
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define eb emplace_back
#define ff first
#define ss second
#define lb lower_bound
#define ub upper_bound
#define uint unsigned int
#define pi pair<int, int>
const int infi = 1e9;
const long long infl = 1e18;
const int md = 998244353;
const double PI = 3.14159265358979323846;
template <typename Map>bool map_compare (Map const &lhs, Map const &rhs) { return lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin());}
template <class T, class Cmp = less<T>> using oset = tree<T, null_type, Cmp, rb_tree_tag, tree_order_statistics_node_update>;
auto seed = chrono::high_resolution_clock::now().time_since_epoch().count();
mt19937_64 rng(seed);
int modpow(int x, int n) { int res = 1; while (n > 0) { if (n % 2) res = (res * x) % md; x = (x * x) % md; n /= 2; } return res; }
int inv(int x) {return modpow(x, md-2);}
long long log_2 (long long n) { return (n > 1ll)? 1ll + log_2(n/2): 0ll;}
long long log_10 (long long n) { return (n > 1ll)? 1ll + log_10(n/10): 0ll;}
inline void add(int& a, int b) {a = ((a % md) + (b % md)) % md;}
inline void sub(int& a, int b) {a = ((a % md) - (b % md) + md) % md;}
inline void mul(int& a, int b) {a = ((a % md) * (b % md)) % md;}
int gcd(int a, int b) { int r; while (b) { r = a % b; a = b; b = r;} return a; }
int randint (int limit = md) { uniform_int_distribution<int> dis(0, limit); return dis(rng); }
double random (double limit = (double)md) { uniform_real_distribution<double> dis((double)0, limit); return dis(rng); }

template <class T>
struct cmp {
  bool operator() (const T& x, const T& y) const {
    return x > y;
  }
  typedef T first_argument_type;
  typedef T second_argument_type;
  typedef bool result_type;
};

const int maxn = 1e2 + 14, lg = 15;
const int base = 1000000000;
const int base_digits = 9; 

struct bigint {
  vector<int> a;
  int sign;

  int size(){
    if(a.empty())return 0;
    int ans=(a.size()-1)*base_digits;
    int ca=a.back();
    while(ca)
      ans++,ca/=10;
    return ans;
  }

  bigint operator ^(const bigint &v){
    bigint ans=1,a=*this,b=v;
    while(!b.isZero()){
      if(b%2)
        ans*=a;
      a*=a,b/=2;
    }
    return ans;
  }

  string to_string(){
    stringstream ss;
    ss << *(this);
    string s;
    ss >> s;
    return s;
  }

  int sumof(){
    string s = to_string();
    int ans = 0;
    for(auto c : s)  ans += c - '0';
    return ans;
  }

  bigint() :
    sign(1) {
  }
 
  bigint(long long v) {
    *this = v;
  }
 
  bigint(const string &s) {
    read(s);
  }
 
  void operator=(const bigint &v) {
    sign = v.sign;
    a = v.a;
  }
 
  void operator=(long long v) {
    sign = 1;
    a.clear();
    if (v < 0)
      sign = -1, v = -v;
    for (; v > 0; v = v / base)
      a.push_back(v % base);
  }
 
  bigint operator+(const bigint &v) const {
    if (sign == v.sign) {
      bigint res = v;
 
      for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
        if (i == (int) res.a.size())
          res.a.push_back(0);
        res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
        carry = res.a[i] >= base;
        if (carry)
          res.a[i] -= base;
      }
      return res;
    }
    return *this - (-v);
  }
 
  bigint operator-(const bigint &v) const {
    if (sign == v.sign) {
      if (abs() >= v.abs()) {
        bigint res = *this;
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
          res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
          carry = res.a[i] < 0;
          if (carry)
            res.a[i] += base;
        }
        res.trim();
        return res;
      }
      return -(v - *this);
    }
    return *this + (-v);
  }
 
  void operator*=(int v) {
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
      if (i == (int) a.size())
        a.push_back(0);
      long long cur = a[i] * (long long) v + carry;
      carry = (int) (cur / base);
      a[i] = (int) (cur % base);
    }
    trim();
  }
 
  bigint operator*(int v) const {
    bigint res = *this;
    res *= v;
    return res;
  }
 
  void operator*=(long long v) {
    if (v < 0)
      sign = -sign, v = -v;
    if(v > base){
      *this = *this * (v / base) * base + *this * (v % base);
      return ;
    }
    for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
      if (i == (int) a.size())
        a.push_back(0);
      long long cur = a[i] * (long long) v + carry;
      carry = (int) (cur / base);
      a[i] = (int) (cur % base);
    }
    trim();
  }
 
  bigint operator*(long long v) const {
    bigint res = *this;
    res *= v;
    return res;
  }
 
  friend pair<bigint, bigint> divmod (const bigint &a1, const bigint &b1) {
    int norm = base / (b1.a.back() + 1);
    bigint a = a1.abs() * norm;
    bigint b = b1.abs() * norm;
    bigint q, r;
    q.a.resize(a.a.size());
 
    for (int i = a.a.size() - 1; i >= 0; i--) {
      r *= base;
      r += a.a[i];
      int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
      int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
      int d = ((long long) base * s1 + s2) / b.a.back();
      r -= b * d;
      while (r < 0)
        r += b, --d;
      q.a[i] = d;
    }
 
    q.sign = a1.sign * b1.sign;
    r.sign = a1.sign;
    q.trim();
    r.trim();
    return make_pair(q, r / norm);
  }
 
  bigint operator/(const bigint &v) const {
    return divmod(*this, v).first;
  }
 
  bigint operator%(const bigint &v) const {
    return divmod(*this, v).second;
  }
 
  void operator/=(int v) {
    if (v < 0)
      sign = -sign, v = -v;
    for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
      long long cur = a[i] + rem * (long long) base;
      a[i] = (int) (cur / v);
      rem = (int) (cur % v);
    }
    trim();
  }
 
  bigint operator/(int v) const {
    bigint res = *this;
    res /= v;
    return res;
  }
 
  int operator%(int v) const {
    if (v < 0)
      v = -v;
    int m = 0;
    for (int i = a.size() - 1; i >= 0; --i)
      m = (a[i] + m * (long long) base) % v;
    return m * sign;
  }
 
  void operator+=(const bigint &v) {
    *this = *this + v;
  }

  void operator-=(const bigint &v) {
    *this = *this - v;
  }

  void operator*=(const bigint &v) {
    *this = *this * v;
  }

  void operator/=(const bigint &v) {
    *this = *this / v;
  }

  bigint& operator++() {
    *this += bigint(1ll);
    return (*this);
  }

  bigint operator++(int) {
    bigint temp(*this);
    operator++();
    return temp;
  }

  bigint& operator--() {
    *this -= bigint(1ll);
    return (*this);
  }

  bigint operator--(int) {
    bigint temp(*this);
    operator--();
    return temp;
  }
 
  bool operator<(const bigint &v) const {
    if (sign != v.sign)
      return sign < v.sign;
    if (a.size() != v.a.size())
      return a.size() * sign < v.a.size() * v.sign;
    for (int i = a.size() - 1; i >= 0; i--)
      if (a[i] != v.a[i])
        return a[i] * sign < v.a[i] * sign;
    return false;
  }
 
  bool operator>(const bigint &v) const {
    return v < *this;
  }

  bool operator<=(const bigint &v) const {
    return !(v < *this);
  }

  bool operator>=(const bigint &v) const {
    return !(*this < v);
  }

  bool operator==(const bigint &v) const {
    return !(*this < v) && !(v < *this);
  }

  bool operator!=(const bigint &v) const {
    return *this < v || v < *this;
  }

  bool operator==(bool) const {
    return *this != bigint(0ll);
  }

  bool operator!=(bool) const {
    return *this == bigint(0ll);
  }
 
  void trim() {
    while (!a.empty() && !a.back())
      a.pop_back();
    if (a.empty())
      sign = 1;
  }
 
  bool isZero() const {
    return a.empty() || (a.size() == 1 && !a[0]);
  }
 
  bigint operator-() const {
    bigint res = *this;
    res.sign = -sign;
    return res;
  }
 
  bigint abs() const {
    bigint res = *this;
    res.sign *= res.sign;
    return res;
  }
 
  long long longValue() const {
    long long res = 0;
    for (int i = a.size() - 1; i >= 0; i--)
      res = res * base + a[i];
    return res * sign;
  }

  bool operator==(const bigint& a) {
    if (a != bigint(0)) return true;
    return false;
  }
 
  friend bigint gcd(const bigint &a, const bigint &b) {
    return b.isZero() ? a : gcd(b, a % b);
  }

  friend bigint lcm(const bigint &a, const bigint &b) {
    return a / gcd(a, b) * b;
  }
 
  void read(const string &s) {
    sign = 1;
    a.clear();
    int pos = 0;
    while (pos < (int) s.size() && (s[pos] == '-' || s[pos] == '+')) {
      if (s[pos] == '-')
        sign = -sign;
      ++pos;
    }
    for (int i = s.size() - 1; i >= pos; i -= base_digits) {
      int x = 0;
      for (int j = max(pos, i - base_digits + 1); j <= i; j++)
        x = x * 10 + s[j] - '0';
      a.push_back(x);
    }
    trim();
  }
 
  friend istream& operator>>(istream &stream, bigint &v) {
    string s;
    stream >> s;
    v.read(s);
    return stream;
  }
 
  friend ostream& operator<<(ostream &stream, const bigint &v) {
    if (v.sign == -1)
      stream << '-';
    stream << (v.a.empty() ? 0 : v.a.back());
    for (int i = (int) v.a.size() - 2; i >= 0; --i)
      stream << setw(base_digits) << setfill('0') << v.a[i];
    return stream;
  }
 
  static vector<int> convert_base(const vector<int> &a, int old_digits, int new_digits) {
    vector<long long> p(max(old_digits, new_digits) + 1);
    p[0] = 1;
    for (int i = 1; i < (int) p.size(); i++)
      p[i] = p[i - 1] * 10;
    vector<int> res;
    long long cur = 0;
    int cur_digits = 0;
    for (int i = 0; i < (int) a.size(); i++) {
      cur += a[i] * p[cur_digits];
      cur_digits += old_digits;
      while (cur_digits >= new_digits) {
        res.push_back(int(cur % p[new_digits]));
        cur /= p[new_digits];
        cur_digits -= new_digits;
      }
    }
    res.push_back((int) cur);
    while (!res.empty() && !res.back())
      res.pop_back();
    return res;
  }
 
  typedef vector<long long> vll;
 
  static vll karatsubaMultiply(const vll &a, const vll &b) {
    int n = a.size();
    vll res(n + n);
    if (n <= 32) {
      for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
          res[i + j] += a[i] * b[j];
      return res;
    }
 
    int k = n >> 1;
    vll a1(a.begin(), a.begin() + k);
    vll a2(a.begin() + k, a.end());
    vll b1(b.begin(), b.begin() + k);
    vll b2(b.begin() + k, b.end());
 
    vll a1b1 = karatsubaMultiply(a1, b1);
    vll a2b2 = karatsubaMultiply(a2, b2);
 
    for (int i = 0; i < k; i++)
      a2[i] += a1[i];
    for (int i = 0; i < k; i++)
      b2[i] += b1[i];
 
    vll r = karatsubaMultiply(a2, b2);
    for (int i = 0; i < (int) a1b1.size(); i++)
      r[i] -= a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      r[i] -= a2b2[i];
 
    for (int i = 0; i < (int) r.size(); i++)
      res[i + k] += r[i];
    for (int i = 0; i < (int) a1b1.size(); i++)
      res[i] += a1b1[i];
    for (int i = 0; i < (int) a2b2.size(); i++)
      res[i + n] += a2b2[i];
    return res;
  }
 
  bigint operator*(const bigint &v) const {
    vector<int> a6 = convert_base(this->a, base_digits, 6);
    vector<int> b6 = convert_base(v.a, base_digits, 6);
    vll a(a6.begin(), a6.end());
    vll b(b6.begin(), b6.end());
    while (a.size() < b.size())
      a.push_back(0);
    while (b.size() < a.size())
      b.push_back(0);
    while (a.size() & (a.size() - 1))
      a.push_back(0), b.push_back(0);
    vll c = karatsubaMultiply(a, b);
    bigint res;
    res.sign = sign * v.sign;
    for (int i = 0, carry = 0; i < (int) c.size(); i++) {
      long long cur = c[i] + carry;
      res.a.push_back((int) (cur % 1000000));
      carry = (int) (cur / 1000000);
    }
    res.a = convert_base(res.a, 6, base_digits);
    res.trim();
    return res;
  }

  bigint log_2(const bigint& n) {
    return (n > bigint(1ll))? bigint(1ll) + log_2(n / bigint(2ll)): bigint(0ll);
  }

  bigint log_10(const bigint& n) {
    return (n > bigint(1ll))? bigint(1ll) + log_2(n / bigint(10ll)): bigint(0ll);
  }
};

string to_string(bigint n) {
  return n.to_string();
}

#undef int

signed main() {
#ifdef READ_FILE
  freopen("input.txt", "r", stdin);
#endif
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  cout << fixed << setprecision(10);
  bigint a, b;
  cin >> a >> b;
  debug(a, b);
  if (a < b) cout << "<\n";
  else if (a > b) cout << ">\n";
  else cout << "=\n";
  return 0;
}