#pragma GCC optimize("O3")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ordered_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <class key, class value, class cmp = std::less<key>>
using ordered_map =
    tree<key, value, cmp, rb_tree_tag, tree_order_statistics_node_update>;





struct custom_hash {  

  static uint64_t splitmix64(uint64_t x) {
    

    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }
  size_t operator()(pair<int64_t, int64_t> Y) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(Y.first * 31 + Y.second + FIXED_RANDOM);
  }
};

template <class T>
ostream& operator<<(ostream& os, vector<T> V) {
  os << "[ ";
  for (auto v : V) os << v << " ";
  return os << "]";
}
template <class T>
ostream& operator<<(ostream& os, set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, unordered_set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, multiset<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class T>
ostream& operator<<(ostream& os, ordered_set<T> S) {
  os << "{ ";
  for (auto s : S) os << s << " ";
  return os << "}";
}
template <class L, class R>
ostream& operator<<(ostream& os, pair<L, R> P) {
  return os << "(" << P.first << "," << P.second << ")";
}
template <class L, class R>
ostream& operator<<(ostream& os, map<L, R> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R, class chash = std::hash<R>>
ostream& operator<<(ostream& os, unordered_map<L, R, chash> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}
template <class L, class R, class chash = std::hash<R>>
ostream& operator<<(ostream& os, gp_hash_table<L, R, chash> M) {
  os << "{ ";
  for (auto m : M) os << "(" << m.first << ":" << m.second << ") ";
  return os << "}";
}

#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
#else
#define trace(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

inline int64_t random_long(long long l, long long r) {
  uniform_int_distribution<int64_t> generator(l, r);
  return generator(rng);
}
inline int64_t random_long() {
  uniform_int_distribution<int64_t> generator(LLONG_MIN, LLONG_MAX);
  return generator(rng);
}




#define ll long long
#define LL long long
#define ld long double
#define all(v) v.begin(), v.end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define pii pair<ll, ll>
#define pb push_back
#define S second
#define F first
#define die() return 0;

#define fmd 998244353
#define M 100011
#define N 10

#define RBTTYPE int
#define ordered_set                                    \
  tree<RBTTYPE, null_type, less<RBTTYPE>, rb_tree_tag, \
       tree_order_statistics_node_update>



typedef unsigned long long ULL;
const long long Inf = 1e18;
const long long INF64 = 3e18;

ll mod = 0;

inline int add(int x, int y) {
  x += y;
  if (x >= mod) x -= mod;
  return x;
}
inline int sub(int x, int y) {
  x -= y;
  if (x < 0) x += mod;
  return x;
}
inline int mul(int x, int y) { return (((long long)x) * y) % mod; }
inline int powr(int a, ll b) {
  int x = 1 % mod;
  while (b) {
    if (b & 1) x = mul(x, a);
    a = mul(a, a);
    b >>= 1;
  }
  return x;
}
inline ll gcd(ll a, ll b) {
  if (a < b) swap(a, b);
  if (b == 0) return a;
  return gcd(b, a % b);
}
template <typename T>
T pw(T a, ll b) {
  T ans{1};
  while (b) {
    while (!(b & 1)) b >>= 1, a = (a * a);
    ans = (ans * a), --b;
  }
  return ans;
}

using ht = gp_hash_table<ll, ll, custom_hash>;

class RangeSumProd {
 public:
  int n;
  vector<ll> t;
  vector<ll> lz;
  RangeSumProd(int z) {
    t = vector<ll>(4 * z + 11, 0);
    lz = vector<ll>(4 * z + 11, 1);
  }
  void updatePoint(int n, int s, int e, int i, int va) {
    if (lz[n] != 1) {
      ll val = lz[n];
      t[n] = mul(t[n], val);
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], val);
        lz[2 * n + 1] = mul(lz[2 * n + 1], val);
      }
      lz[n] = 1;
    }
    if (s > e) return;
    if (s == e) {
      t[n] = va % mod;
      return;
    }
    int m = (s + e) / 2;
    if (i <= m) {
      updatePoint(2 * n, s, m, i, va);
    } else {
      updatePoint(2 * n + 1, m + 1, e, i, va);
    }
    t[n] = add(t[2 * n], t[2 * n + 1]);
  }
  void updateProd(int n, int s, int e, int l, int r, ll va) {
    if (lz[n] != 1) {
      ll val = lz[n];
      t[n] = mul(t[n], val);
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], val);
        lz[2 * n + 1] = mul(lz[2 * n + 1], val);
      }
      lz[n] = 1;
    }
    if (s > e || l > e || s > r) return;
    if (s >= l and e <= r) {
      t[n] = mul(t[n], va);
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], va);
        lz[2 * n + 1] = mul(lz[2 * n + 1], va);
      }
      lz[n] = 1;
      return;
    }
    int m = (s + e) / 2;
    updateProd(2 * n, s, m, l, r, va);
    updateProd(2 * n + 1, m + 1, e, l, r, va);
    t[n] = add(t[2 * n], t[2 * n + 1]);
  }
  int query(int n, int s, int e, int l, int r) {
    if (lz[n] != 1) {
      ll va = lz[n];
      t[n] = mul(t[n], va);
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], va);
        lz[2 * n + 1] = mul(lz[2 * n + 1], va);
      }
      lz[n] = 1;
    }
    if (s > e || l > e || s > r) return 0;
    if (s >= l and e <= r) return t[n];
    int m = (s + e) / 2;
    return add(query(2 * n, s, m, l, r), query(2 * n + 1, m + 1, e, l, r));
  }
};

class RangeProd {
 public:
  int n;
  vector<ll> t;
  vector<ll> lz;
  RangeProd(int z) {
    t = vector<ll>(4 * z + 11, 1);
    lz = vector<ll>(4 * z + 11, 1);
  }
  void update(int n, int s, int e, int l, int r, ll va) {
    if (lz[n] != 1) {
      t[n] = mul(t[n], powr(lz[n], e - s + 1));
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], lz[n]);
        lz[2 * n + 1] = mul(lz[2 * n + 1], lz[n]);
      }
      lz[n] = 1;
    }
    if (s > e || l > e || s > r) return;
    if (s >= l and e <= r) {
      t[n] = mul(t[n], powr(va, e - s + 1));
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], va);
        lz[2 * n + 1] = mul(lz[2 * n + 1], va);
      }
      lz[n] = 1;
      return;
    }
    int m = (s + e) / 2;
    update(2 * n, s, m, l, r, va);
    update(2 * n + 1, m + 1, e, l, r, va);
    t[n] = mul(t[2 * n], t[2 * n + 1]);
  }
  int query(int n, int s, int e, int l, int r) {
    if (lz[n] != 1) {
      t[n] = mul(t[n], powr(lz[n], e - s + 1));
      if (s != e) {
        lz[2 * n] = mul(lz[2 * n], lz[n]);
        lz[2 * n + 1] = mul(lz[2 * n + 1], lz[n]);
      }
      lz[n] = 1;
    }
    if (s > e || l > e || s > r) return 1;
    if (s >= l and e <= r) return t[n];
    int m = (s + e) / 2;
    return mul(query(2 * n, s, m, l, r), query(2 * n + 1, m + 1, e, l, r));
  }
};

class RangeSum {
 public:
  int n;
  vector<ll> t;
  vector<ll> lz;
  RangeSum(int z) {
    t = vector<ll>(4 * z + 11, 0);
    lz = vector<ll>(4 * z + 11, 0);
  }
  void updateRange(int n, int s, int e, int l, int r, ll va) {
    if (lz[n]) {
      t[n] += (lz[n] * (e - s + 1));
      if (s != e) {
        lz[2 * n] += lz[n];
        lz[2 * n + 1] += lz[n];
      }
      lz[n] = 0;
    }
    if (s > e || l > e || s > r) return;
    if (s >= l and e <= r) {
      t[n] += (va * (e - s + 1));
      if (s != e) {
        lz[2 * n] += va;
        lz[2 * n + 1] += va;
      }
      lz[n] = 0;
      return;
    }
    int m = (s + e) / 2;
    updateRange(2 * n, s, m, l, r, va);
    updateRange(2 * n + 1, m + 1, e, l, r, va);
    t[n] = t[2 * n] + t[2 * n + 1];
  }
  int query(int n, int s, int e, int l, int r) {
    if (lz[n]) {
      t[n] += (lz[n] * (e - s + 1));
      if (s != e) {
        lz[2 * n] += lz[n];
        lz[2 * n + 1] += lz[n];
      }
      lz[n] = 0;
    }
    if (s > e || l > e || s > r) return 0;
    if (s >= l and e <= r) return t[n];
    int m = (s + e) / 2;
    return query(2 * n, s, m, l, r) + query(2 * n + 1, m + 1, e, l, r);
  }
};
vector<int> prime;
vector<RangeSum> pr;

int uppp(int l, int r, int x, int n, int pp = 1) {
  for (int i = 0; i < prime.size(); ++i) {
    if (prime[i] > x) break;
    if (x % prime[i] == 0) {
      int c = 0;
      while (x % prime[i] == 0) {
        x /= prime[i];
        ++c;
      }
      pr[i].updateRange(1, 0, n - 1, l, r, pp * c);
    }
  }
  return x;
}

tuple<LL, LL, LL> extendedEuclid(LL a, LL b) {
  if (!b) {
    return make_tuple(1, 0, a);
  }
  auto [x1, y1, g] = extendedEuclid(b, a % b);
  LL x = y1;
  LL y = x1 - y1 * (a / b);
  return make_tuple(x, y, g);
}

ll iv[M];
int solve() {
  ll n, i, j, k, m, x, y, z;
  cin >> n >> mod;
  x = mod;
  for (i = 2; i * i <= x; ++i) {
    if (x % i == 0) {
      prime.pb(i);
      while (x % i == 0) x /= i;
    }
  }
  if (x > 1) prime.pb(x);
  for (i = 0; i < prime.size(); ++i) {
    RangeSum s(n + 1);
    pr.pb(s);
  }
  RangeProd copr(n + 1);
  RangeSumProd man(n + 1);
  for (i = 0; i < n; ++i) {
    cin >> x;
    man.updatePoint(1, 0, n - 1, i, x);
    int p = uppp(i, i, x, n);
    copr.update(1, 0, n - 1, i, i, p);
  }
  for (int i = 1; i < M; ++i) {
    if (gcd(i, mod) == 1) {
      auto tup = extendedEuclid(i, mod);
      ll x0 = get<0>(tup);
      x0 %= mod;
      x0 = (x0 + mod) % mod;
      iv[i] = x0;
    }
  }
  cin >> m;
  while (m--) {
    int q;
    int l, r, x;
    cin >> q;
    

    

    

    

    

    

    

    

    

    

    

    

    

    if (q == 1) {
      cin >> l >> r >> x;
      l--;
      r--;
      man.updateProd(1, 0, n - 1, l, r, x);
      int cp = uppp(l, r, x, n);
      copr.update(1, 0, n - 1, l, r, cp);

    } else if (q == 2) {
      int p, x;
      cin >> p >> x;
      p--;
      int cp = uppp(p, p, x, n, -1);
      copr.update(1, 0, n - 1, p, p, iv[cp]);
      int c = copr.query(1, 0, n - 1, p, p);
      for (i = 0; i < prime.size(); ++i) {
        int cnt = pr[i].query(1, 0, n - 1, p, p);
        c = mul(c, powr(prime[i], cnt));
        if (!c) break;
      }
      man.query(1, 0, n - 1, p, p);
      man.updatePoint(1, 0, n - 1, p, c);
    } else {
      cin >> l >> r;
      l--;
      r--;
      int p = man.query(1, 0, n - 1, l, r);
      cout << p << "\n";
    }
  }

  die();
}
void prec() { int go = 0; }




int main() {
#ifndef ONLINE_JUDGE
  double _tBeg = clock();
#endif
  

  

  


  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

#ifdef FILE_INPUT
  char* inputFile = "input.txt";
  char* outputFile = "output.txt";
  freopen(inputFile, "r", stdin);
  freopen(outputFile, "w", stdout);
#endif

  int t;
  t = 1;
  prec();
  


  int _case = 1;
  while (t--) {
    

    solve();
  }

#ifndef ONLINE_JUDGE
  double _tEnd = clock();
  

#endif

  die();
}