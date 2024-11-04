
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include "bits/stdc++.h"
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
#define faster            ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define ll                long long
#define pb                push_back
#define eb                emplace_back
#define ppb               pop_back
#define pf                push_front
#define ppf               pop_front
#define all(x)            (x).begin(),(x).end()
#define rall(x)           (x).rbegin(),(x).rend()
#define uniq(v)           (v).erase(unique(all(v)),(v).end()) 

#define sz(x)             (ll)((x).size())
#define sq(x)             ((x)*(x))
#define re                resize
#define ff                first
#define ss                second
#define vi                vector<int>
#define vs                vector<string>
#define vl                vector<ll>
#define vvl               vector<vector<ll>>
#define vvi               vector<vector<int>>
#define vd                vector<double>
#define vs                vector<string>          
#define pii               pair<int,int>
#define pll               pair<ll,ll>
#define mii               map<int,int>
#define mll               map<ll,ll>
#define uii               unordered_map<int,int>
#define ln                "\n"
#define pr(x)             cout<<(x)<<ln;
#define printarr(a)       for(int i=0;i<a.size();i++){cout<<a[i]<<" ";if(i==a.size()-1)cout<<ln;}
#define rep(i, a, b)      for (int i=a; i<(b); i++)
#define rep0(i, a)        for (int i=0; i<(a); i++)
#define repd(i,a,b)       for (int i = (b)-1; i >= a; i--)
#define repd0(i,a)        for (int i = (a)-1; i >= 0; i--)
#define mem1(a)           memset(a,-1,sizeof(a))
#define mem0(a)           memset(a,0,sizeof(a))
#define ppc               __builtin_popcount
#define ppcll             __builtin_popcountll
#define ppcz              __builtin_clz 

#define lld               long double
#define ar                array
#define ra(a,n)           for(int i=0;i<n;i++)cin>>a[i];
#define google(i)         cout<<"Case #"<<i<<": ";      
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}
template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
const long long inf=1e18;
const ll mod=1000000007; 


const double PI = acos(-1.0);
vector<ll> sieve(int n) {int*arr = new int[n + 1](); vector<ll> vect; for (int i = 2; i <= n; i++)if (arr[i] == 0) {vect.push_back(i); for (int j = 2 * i; j <= n; j += i)arr[j] = 1;} return vect;}
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
 

 
constexpr int md = (int) 1e9 + 7;
using Mint = Modular<std::integral_constant<decay<decltype(md)>::type, md>>;
 
vector<Mint> fact(1, 1);
vector<Mint> inv_fact(1, 1);
 
































      
















































































vl segtree, lazy;
 
void build(ll v, ll tl, ll tr) {
    if (tl == tr) {
        

        segtree[v] = 0;
        return;
    }
    if (tl > tr) return;
    ll m = (tl + tr) / 2;
    build(2 * v, tl, m);
    build(2 * v + 1, m + 1, tr);
    segtree[v] = min(segtree[2 * v], segtree[2 * v + 1]);
}
 
ll range(ll v, ll tl, ll tr, ll l, ll r) {
    if (lazy[v]) {
        segtree[v] += lazy[v];
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        lazy[v] = 0;
    }
    if (tl == l && tr == r) return segtree[v];
    if (l > r) return 0;
    ll tm = (tl + tr) / 2;
    return min(range(2 * v, tl, tm, l, min(r, tm)), range(2 * v + 1, tm + 1, tr, max(l, tm + 1), r));
}
 
void update(ll v, ll tl, ll tr, ll l, ll r, ll val) {
    if (lazy[v]) {
        segtree[v] += lazy[v];
        lazy[2 * v] += lazy[v];
        lazy[2 * v + 1] += lazy[v];
        lazy[v] = 0;
    }
    if (l > r) return;
 
    if (l == tl && r == tr) {
        segtree[v] += val;
        lazy[2 * v] += val;
        lazy[2 * v + 1] += val;
        return;
    }
    ll tm = (tl + tr) / 2;
    update(2 * v, tl, tm, l, min(tm, r), val);
    update(2 * v + 1, tm + 1, tr, max(l, tm + 1), r, val);
    segtree[v] = min(segtree[2 * v], segtree[2 * v + 1]);
 
}
void solve(int tc=1){
  int n,m;
  cin>>n>>m;
  vl l(n+1),r(n+1);
  vector<pll>w(n+1);
  rep(i,1,n+1){
    cin>>l[i]>>r[i];
    cin>>w[i].ff;
    w[i].ss=i;
  }
  segtree.re(4*(m+1));
  lazy.re(8*(m+1));
  build(1,1,m-1);
  sort(all(w));
  ll ans=inf;
  ll mn;
  int j=0;
  for(int i=1;i<=n;i++){
    mn=range(1,1,m-1,1,m-1);
    while(mn<=0 and j<n){
      j++;
      update(1,1,m-1,l[w[j].ss],r[w[j].ss]-1,1LL);
      debug(segtree);
      mn=range(1,1,m-1,1,m-1);
    }
    debug(mn);
    if(mn>0){
      ans=min(ans,w[j].ff-w[i].ff);
    }
      update(1,1,m-1,l[w[i].ss],r[w[i].ss]-1,-1LL);
  }
  pr(ans)
  }
signed main() { 
    faster;
          #ifndef ONLINE_JUDGE
               freopen("input.txt", "r", stdin);
               freopen("output.txt", "w", stdout);
          #endif
    ll tt=1;
    

    
    for(ll i=1;i<=tt;i++){
      solve( i);
      

    } 
    return 0;
}


