#ifdef _DEBUG
#define _GLIBCXX_DEBUG 1
#else
#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>


namespace algo {
template <typename _Tp, typename = void> struct is_multipliable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_multipliable<_Tp,
                       std::void_t<decltype(std::declval<_Tp &>() *=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool is_multipliable_v = is_multipliable<_Tp>::value;

template <typename _Tp> constexpr bool is_integral_v = std::is_integral_v<_Tp>;
template <typename T>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<T>::operator())> {};





template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const>


{
  enum { arity = sizeof...(_Args) };
  


  typedef _Ret result_type;

  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, std::tuple<_Args...>>::type type;
    

    

  };
};
template <typename _Tp, typename = void> struct less_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool is_less_than_comparable_v = less_than_comparable<_Tp>::value;
} 


namespace algo {
template <typename _T> constexpr _T __binpow(_T a, int b) {
  _T res(1);
  while (b) {
    if (b & 0x01) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename _T> constexpr _T __binpow(_T a, int b, const _T &init) {
  _T res = init;
  while (b) {
    if (b & 0x01) {
      res *= a;
    }
    a *= a;
    b >>= 1;
  }
  return res;
}
template <typename _T> constexpr _T __gcd(_T a, _T b) {
  while (b) {
    _T tp = a;
    a = b;
    b = tp % a;
  }
  return a;
}
template <typename _T>
constexpr std::pair<_T, _T> __euclidean_extended(_T a, _T b) {
  _T x0 = 1, y0 = 0, x1 = 0, y1 = 1;
  while (b) {
    const _T q = a / b;
    _T tp = x0;
    x0 = x1, x1 = tp - q * x1, tp = y0, y0 = y1, y1 = tp - q * y1, tp = a,
    a = b, b = tp - q * b;
  }
  return std::make_pair(x0, a);
}
template <typename _T> constexpr _T __binpow_mod(_T a, _T b, const _T mod) {
  _T ans(1);
  a %= mod;
  while (b) {
    if (b & 0x01) {
      ans = ans * 1ll * a % mod;
    }
    a = a * 1ll * a % mod;
    b >>= 1;
  }
  return ans;
}




constexpr int __euler_phi(int n) {
  int ans = n;
  if (!(n & 0x01)) {
    ans >>= 1;
    do {
      n >>= 1;
    } while (!(n & 0x01));
  }
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) {
      ans -= ans / i;
      do {
        n /= i;
      } while (n % i == 0);
    }
  }
  if (n > 1) {
    ans -= ans / n;
  }
  return ans;
}




int __discrete_log(int a, int b, int m) {
  a %= m;
  if (a < 0)
    a += m;
  b %= m;
  if (b < 0)
    b += m;
  const int n = (int)std::sqrt(m) + 1;
  const int an = __binpow_mod(a, n, m);
  std::unordered_map<int, int> f2;
  for (int q = 0, now = b; q <= n; ++q) {
    f2[now] = q;
    now = now * 1ll * a % m;
  }
  for (int p = 1, cur = 1; p <= n; ++p) {
    cur = cur * 1ll * an % m;
    if (f2.find(cur) != f2.end()) {
      return n * p - f2[cur];
    }
  }
  return -1;
}















constexpr int __primitive_root(int n) {
  int phi_n = __euler_phi(n);
  const int phi = phi_n;
  std::array<int, 21> divs = {};
  int cnt = 0;
  if (!(phi_n & 0x01)) {
    divs[cnt++] = 2;
    do {
      phi_n >>= 1;
    } while (!(phi_n & 0x01));
  }
  for (int i = 3; i * i <= phi_n; i += 2) {
    if (phi_n % i == 0) {
      divs[cnt++] = i;
      do {
        phi_n /= i;
      } while (phi_n % i == 0);
    }
  }
  if (phi_n > 1) {
    divs[cnt++] = phi_n;
  }
  for (int g = 1; g < n; ++g) {
    bool found = true;
    for (int p = 0; p < cnt; ++p) {
      if (__binpow_mod(g, phi / divs[p], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) {
      return g;
    }
  }
  return n == 1 ? n : -1;
}


constexpr int __primitive_root_prime(int n) {
  switch (n) {
  case 2:
    return 1;
  case 167772161:
    return 3;
  case 469762049:
    return 3;
  case 754974721:
    return 11;
  case 998244353:
    return 3;
  case 1000000007:
    return 5;
  case 1000000009:
    return 13;
  }
  std::array<int, 21> divs = {2};
  int cnt = 1;
  int x = n - 1 >> 1;
  while (!(x & 0x01))
    x >>= 1;
  for (int i = 3; i * i <= x; i += 2) {
    if (x % i == 0) {
      divs[cnt++] = i;
      do {
        x /= i;
      } while (x % i == 0);
    }
  }
  if (x > 1) {
    divs[cnt++] = x;
  }
  for (int g = 2; g <= n; ++g) {
    bool found = true;
    for (int i = 0; i < cnt; ++i) {
      if (__binpow_mod(g, (n - 1) / divs[i], n) == 1) {
        found = false;
        break;
      }
    }
    if (found) {
      return g;
    }
  }
  __builtin_unreachable();
}






int __discrete_root(int a, int b, int n) {
  const int g = __primitive_root(n);
  const int ga = __binpow_mod(g, a, n);
  const int y = __discrete_log(ga, b, n);
  return y != -1 ? __binpow_mod(g, y, n) : -1;
}
} 

namespace algo {


constexpr int __count_lz(int n) { return __builtin_clz(n); };
constexpr int __count_lz(long long n) { return __builtin_clzl(n); };


constexpr int __count_tz(int n) { return __builtin_ctz(n); };
constexpr int __count_tz(long long n) { return __builtin_ctzl(n); }


constexpr int __bit_width(int n) { return 32 - __builtin_clz(n); };
constexpr int __bit_width(long long n) { return 64 - __builtin_clzl(n); };


constexpr int __bit_floor(int n) { return 1u << (31 - __count_lz(n)); };
constexpr long long __bit_floor(long long n) {
  return 1ull << (63 - __count_lz(n));
}


constexpr int __bit_ceil(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return __bit_floor(n - 1) << 1;
};
constexpr long long __bit_ceil(long long n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return __bit_floor(n - 1) << 1;
}


constexpr int __log2_floor(int n) { return 31 - __count_lz(n); };
constexpr int __log2_floor(long long n) { return 63 - __count_lz(n); };


constexpr int __log2_ceil(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return __log2_floor(n - 1) + 1;
}
constexpr int __log2_ceil(long long n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return __log2_floor(n - 1) + 1;
}


constexpr int __popcount(int n) { return __builtin_popcount(n); };
constexpr int __popcount(long long n) { return __builtin_popcountl(n); }


constexpr int __bit_parity(int n) { return __builtin_parity(n); };
} 

namespace algo {
template <typename _T> constexpr _T __max_v(const _T &a, const _T &b) {
  return a < b ? b : a;
}
template <typename _T> constexpr _T __min_v(const _T &a, const _T &b) {
  return a < b ? a : b;
}
} 

namespace algo {

template <typename _T,
          std::enable_if_t<algo::is_multipliable_v<_T>, bool> = true>
constexpr _T binpow(_T a, int b) {
#ifdef _DEBUG
  assert(b >= 0);
#endif
  return __binpow(a, b);
}
template <typename _T, typename _U,
          std::enable_if_t<algo::is_multipliable_v<_T> &&
                               std::is_convertible_v<_U, _T>,
                           bool> = true>
constexpr _T binpow(_T a, int b, _U ini) {
#ifdef _DEBUG
  assert(b >= 0);
#endif
  return __binpow(a, b, ini);
}
template <typename _T, std::enable_if_t<algo::is_integral_v<_T>, bool> = true>
constexpr _T gcd(_T a, _T b) {
  return __gcd(a, b);
}

template <typename _T, std::enable_if_t<is_integral_v<_T>, bool> = true>
constexpr std::pair<_T, _T> euclidean_extended(_T a, _T b) {
  return __euclidean_extended(a, b);
}

template <typename _T, std::enable_if_t<is_integral_v<_T>, bool> = true>
constexpr _T euler_phi(_T n) {
  _T ans = n;
  for (_T i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      ans -= ans / i;
      do {
        n /= i;
      } while (n % i == 0);
    }
  }
  if (n > 1)
    ans -= ans / n;
  return ans;
}


std::vector<int> sieve_till_n(int n) {
  constexpr int block = 30807;
  std::vector<int> primes;
  const int rn = (int)std::sqrt(n);
  std::vector<char> is_prime(rn + 2, true);
  for (int i = 2; i <= rn; ++i) {
    if (is_prime[i]) {
      primes.push_back(i);
      for (int j = i * i; j <= rn; j += i) {
        is_prime[j] = false;
      }
    }
  }
  std::vector<int> ans;
  std::array<char, block> blk;
  blk.fill(true);
  blk[0] = blk[1] = false;
  for (int k = 0; k * block <= n; ++k) {
    const int start = k * block;
    for (auto &&p : primes) {
      for (int j = __max_v((start + p - 1) / p, p) * p - start; j < block;
           j += p) {
        blk[j] = false;
      }
    }
    for (int i = 0; i < block && start + i <= n; ++i) {
      if (blk[i]) {
        ans.push_back(start + i);
      }
      blk[i] = true;
    }
  }
  return ans;
}

constexpr bool check_composite(int n, int a, int d, int s) {
  int x = __binpow_mod(a, d, n);
  if (x == 1 || x == n - 1) {
    return false;
  }
  for (int r = 1; r < s; ++r) {
    x = x * 1ll * x % n;
    if (x == n - 1) {
      return false;
    }
  }
  return true;
}
constexpr bool prime_test(int n) {
  if (n >= 2) {
    const int r = __count_tz(n - 1);
    const int d = (n - 1) >> r;
    const int primes[] = {2, 3, 5, 7};
    if (n == 2 || n == 3 || n == 5 || n == 7) {
      return true;
    }
    if (check_composite(n, 2, d, r) || check_composite(n, 3, d, r) ||
        check_composite(n, 5, d, r) || check_composite(n, 7, d, r)) {
      return false;
    }
    return true;
  } else {
    return false;
  }
}

constexpr int primitive_root(int n) { return __primitive_root(n); }

int discrete_log(int a, int b, int n) { return __discrete_log(a, b, n); }

int discrete_root(int a, int b, int n) {
#ifdef _DEBUG
  assert(prime_test(n));
#endif
  return __discrete_root(a, b, n);
}
} 


namespace algo {

template <typename _T, std::enable_if_t<is_integral_v<_T>, bool> = true>
constexpr _T binpow_mod(_T a, _T b, const _T m) {
#ifdef _DEBUG
  assert(b >= 0);
#endif
  return __binpow_mod(a, b, m);
}

template <typename _T, std::enable_if_t<is_integral_v<_T>, bool> = true>
constexpr _T inv_mod(_T a, _T m) {
#ifdef _DEBUG
  assert(__gcd(a, m) == 1);
#endif
  _T ans = __euclidean_extended(a, m).first % m;
  if (ans < 0)
    ans += m;
  return ans;
}

template <int _MOD> struct modint {
  constexpr modint() = default;
  template <typename _U, std::enable_if_t<is_integral_v<_U>, bool> = true>
  constexpr modint(const _U &val) : _M_val(static_cast<int>(val % _MOD)) {
    if (_M_val < 0)
      _M_val += _MOD;
  }
  constexpr modint(const modint &other) : _M_val(other.val()) {}
  constexpr modint &operator=(const modint &other) {
    _M_val = other.val();
    return *this;
  }
  constexpr modint &operator+=(const modint &rhs) {
    _M_val += rhs.val();
    if (_M_val >= _MOD) {
      _M_val -= _MOD;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint &rhs) {
    return operator+=(_MOD - rhs.val());
  }
  constexpr modint &operator*=(const modint &rhs) {
    _M_val = (int)val() * 1ll * rhs.val() % _MOD;
    return *this;
  }
  constexpr modint &operator/=(const modint &rhs) {
    return operator*=(rhs.inv());
  }
  constexpr friend bool operator<(const modint &lhs, const modint &rhs) {
    return lhs.val() < rhs.val();
  }
  constexpr friend bool operator>(const modint &lhs, const modint &rhs) {
    return rhs < lhs;
  }
  constexpr friend bool operator<=(const modint &lhs, const modint &rhs) {
    return !(lhs > rhs);
  }
  constexpr friend bool operator>=(const modint &lhs, const modint &rhs) {
    return !(lhs < rhs);
  }
  constexpr friend bool operator==(const modint &lhs, const modint &rhs) {
    return lhs.val() == rhs.val();
  }
  constexpr friend bool operator!=(const modint &lhs, const modint &rhs) {
    return !(lhs == rhs);
  }
  constexpr friend modint operator+(modint lhs, const modint &rhs) {
    lhs += rhs;
    return lhs;
  }
  constexpr friend modint operator-(modint lhs, const modint &rhs) {
    lhs -= rhs;
    return lhs;
  }
  constexpr friend modint operator*(modint lhs, const modint &rhs) {
    lhs *= rhs;
    return lhs;
  }
  constexpr friend modint operator/(modint lhs, const modint &rhs) {
    lhs /= rhs;
    return lhs;
  }
  constexpr int val() const { return _M_val; }
  constexpr int mod() const { return _MOD; }
  constexpr modint inv() const {
    return __euclidean_extended(val(), mod()).first;
  }
  constexpr modint pow(int x) const {
    modint ret(1), mul(val());
#ifdef _DEBUG
    assert(x >= 0);
#endif
    while (x > 0) {
      if (x & 0x01)
        ret *= mul;
      mul *= mul, x >>= 1;
    }
    return ret;
  }
  friend std::ostream &operator<<(std::ostream &os, const modint &mt) {
    os << mt.val();
    return os;
  }

private:
  int _M_val = {};
};
} 

using namespace std;
using namespace std::literals;
using namespace __gnu_pbds;
template <typename _Tp, typename _Fn>
using ordered_set =
    tree<_Tp, null_type, _Fn, rb_tree_tag, tree_order_statistics_node_update>;
using uint = unsigned int;
template <typename _Key, typename _Value>
using umap = unordered_map<_Key, _Value>;
template <typename _Tp, typename _Fn = less<_Tp>>
using max_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = greater<_Tp>>
using min_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Value> using uset = unordered_set<_Value>;
using wint = long long int;
#define DBG(x)                                                                 \
  cerr << "\033[1;32m" << #x << "\033[0m = "                                   \
       << "\033[1;34m" << x << "\033[0m\n";
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI true
#define BITSIZE 21



namespace {} 




void solve() {
  int n,m;cin>>n>>m;
  vector adj(n,vector<int>{});
  int s,t;cin>>s>>t;
  s--,t--;
  for(int i=0;i<m;++i){
    int u,v;cin>>u>>v;
    --u,--v;
    adj[u].push_back(v),adj[v].push_back(u);
  }
  vector dist(n,-1);
  vector vis(n,false);
  vector<array<algo::modint<MOD>,2>>dp(n,{{0,0}});
  vector<int>cur={t};
  dist[t]=0;
  vis[t]=true;
  dp[t][0]=1;
  int level=0;
  while(cur.size()){
    for(auto&&u:cur){
      for(auto&&v:adj[u]){
        if(dist[v]==-1){
          dp[v][0]+=dp[u][0];
        }else if(dist[v]==dist[u]){
          dp[v][1]+=dp[u][0];
        }
      }
    }
    vector<int>nxt;
    for(auto&&u:cur){
      for(auto&&v:adj[u]){
        if(dist[v]==-1){
          dp[v][1]+=dp[u][1];
          if(!vis[v]){
            vis[v]=true;
            nxt.push_back(v);
          }
        }
      }
    }
    level++;
    for(auto&&v:nxt){
      dist[v]=level;
    }
    cur=move(nxt);
  }
  cout<<dp[s][0]+dp[s][1]<<'\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  if constexpr (MULTI) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}