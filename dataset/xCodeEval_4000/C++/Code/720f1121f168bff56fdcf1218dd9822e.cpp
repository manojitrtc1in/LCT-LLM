#pragma GCC optimize(3)


#define YYF








#include <algorithm>
#include <bit>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <execution>
#include <ext/pb_ds/assoc_container.hpp>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <string_view>
#include <vector>


#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)
#define MT       \
  int T;         \
  std::cin >> T; \
  while (T--)
#ifdef yyfLocal
#define dbg(...) std::cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#define logs(x) std::cerr << (x) << std::endl
#else
#define dbg(...) 42
#define logs(x) 42
#define cerr clog
[[noreturn]] void fail_exit(int line) { exit(line); }
#define assert(expr) (static_cast<bool>(expr) ? void(0) : fail_exit(__LINE__))
#endif

using ll = int64_t;
using ull = uint64_t;
using pii = std::pair<int, int>;
using tiii = std::tuple<int, int, int>;


using namespace std::string_literals;
using namespace std::string_view_literals;

void dbg_out() { std::cerr << std::endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T) {
  std::cerr << " " << H;
  dbg_out(T...);
}

void read() {}
template <typename T, typename... Targs>
void read(T& x, Targs&... args) {
  x = 0;
  bool flag = false;
  char ch = char(std::cin.get());
  while (!isdigit(ch)) {
    if (ch == '-') flag = true;
    ch = char(std::cin.get());
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - 48;
    ch = char(std::cin.get());
  }
  if (flag) x *= -1;
  read(args...);
}

template <typename T>
void qprint(T x) {
  if (x < 0) std::cout.put('-'), x = -x;
  if (x > 9) qprint(x / 10);
  std::cout.put(char(x % 10 + 48));
}

template <char end = '\n', typename... Targs>
void print(const Targs&... args) {
  ((qprint(args), std::cout.put(' ')), ...);
  std::cout.put(end);
}

#ifdef YYF

struct SegTree {
  const static int mod = 1e9 + 7;
#define lson ((o) << 1)
#define rson ((o) << 1 | 1)
  int n, size;
  std::vector<ll> a;
  struct Info {
    ll rangeLen, tSum;
    std::pair<ll, ll> tMin = {mod, -1}, tMax = {-mod, -1};
    ll lzAdd = 0, lzMul = 1, lzVal = mod;
  };
  std::vector<Info> node;
  SegTree(const std::vector<ll>& a) : a(a) {
    n = int32_t(a.size()) - 1;
    size = n * 4;
    node.resize(size);
    this->build(1, 1, n);
  }

  void updateAdd(int o, ll val) {
    node[o].tSum = node[o].tSum + val * node[o].rangeLen % mod;
    node[o].tMax.first = (node[o].tMax.first + val) % mod;
    node[o].tMin.first = (node[o].tMin.first + val) % mod;
    node[o].lzAdd = (node[o].lzAdd + val) % mod;
  }
  void updateMul(int o, ll val) {
    node[o].tSum = val * node[o].tSum % mod;
    node[o].tMax.first = val * node[o].tMax.first % mod;
    node[o].tMin.first = val * node[o].tMin.first % mod;
    node[o].lzMul = val * node[o].lzMul % mod;
    node[o].lzAdd = val * node[o].lzAdd % mod;
  }
  void updateVal(int o, ll val) {
    node[o].tSum = val * node[o].rangeLen % mod;
    node[o].tMax.first = node[o].tMin.first = val;
    node[o].lzVal = val;
    node[o].lzMul = 1;
    node[o].lzAdd = 0;
  }

  void build(int o, int l, int r) {
    node[o].rangeLen = r - l + 1;
    if (l == r) return updateVal(o, a[l]);
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(o);
  }
  void pushup(int o) {
    node[o].tMax = std::max(node[lson].tMax, node[rson].tMax);
    node[o].tMin = std::min(node[lson].tMin, node[rson].tMin);
    node[o].tSum = (node[lson].tSum + node[rson].tSum) % mod;
  }
  void pushdown(int o) {
    if (node[o].lzVal != mod) {
      updateVal(lson, node[o].lzVal);
      updateVal(rson, node[o].lzVal);
      node[o].lzVal = mod;
    }
    if (node[o].lzMul != 1) {
      updateMul(lson, node[o].lzMul);
      updateMul(rson, node[o].lzMul);
      node[o].lzMul = 1;
    }
    if (node[o].lzAdd != 0) {
      updateAdd(lson, node[o].lzAdd);
      updateAdd(rson, node[o].lzAdd);
      node[o].lzAdd = 0;
    }
  }

  void doAdd(int o, int l, int r, int L, int R, ll x) {
    if (l >= L && r <= R) return updateAdd(o, x);
    pushdown(o);
    int mid = (l + r) >> 1;
    if (L <= mid) doAdd(lson, l, mid, L, R, x);
    if (R > mid) doAdd(rson, mid + 1, r, L, R, x);
    pushup(o);
  }
  void doMul(int o, int l, int r, int L, int R, ll x) {
    if (l >= L && r <= R) return updateMul(o, x);
    pushdown(o);
    int mid = (l + r) >> 1;
    if (L <= mid) doMul(lson, l, mid, L, R, x);
    if (R > mid) doMul(rson, mid + 1, r, L, R, x);
    pushup(o);
  }
  void doVal(int o, int l, int r, int L, int R, ll x) {
    if (l >= L && r <= R) return updateVal(o, x);
    pushdown(o);
    int mid = (l + r) >> 1;
    if (L <= mid) doVal(lson, l, mid, L, R, x);
    if (R > mid) doVal(rson, mid + 1, r, L, R, x);
    pushup(o);
  }

  ll querySum(int o, int l, int r, int L, int R) {
    if (l >= L && r <= R) return node[o].tSum;
    pushdown(o);
    int mid = (l + r) >> 1;
    ll ans = 0;
    if (L <= mid) ans += querySum(lson, l, mid, L, R);
    if (R > mid) ans += querySum(rson, mid + 1, r, L, R);
    ans %= mod;
    return ans;
  }
  std::pair<ll, ll> queryMax(int o, int l, int r, int L, int R) {
    if (l >= L && r <= R) return node[o].tMax;
    pushdown(o);
    int mid = (l + r) >> 1;
    std::pair<ll, ll> ans = {-mod, -1};
    if (L <= mid) ans = std::max(ans, queryMax(lson, l, mid, L, R));
    if (R > mid) ans = std::max(ans, queryMax(rson, mid + 1, r, L, R));
    return ans;
  }
  std::pair<ll, ll> queryMin(int o, int l, int r, int L, int R) {
    if (l >= L && r <= R) return node[o].tMin;
    pushdown(o);
    int mid = (l + r) >> 1;
    std::pair<ll, ll> ans = {mod, -1};
    if (L <= mid) ans = std::min(ans, queryMin(lson, l, mid, L, R));
    if (R > mid) ans = std::min(ans, queryMin(rson, mid + 1, r, L, R));
    return ans;
  }
#undef lson
#undef rson
};

struct ODT_Map {
  const static int mod = 1e9 + 7;
  const int n;
  

  

  

  std::map<int, int> map;
  ODT_Map(int n) : n(n) { map[-1] = 0, map[0] = 0, map[n + 1] = 0; }
  void split(int x) {
    auto it = std::prev(map.upper_bound(x));  

    map[x] = it->second;
  }
  void assign(int l, int r, int val) {
    r = r + 1;  

    split(l), split(r);
    for (auto it = map.find(l); it->first != r; it = map.erase(it))
      ;
    map[l] = val;
  }
  void add(int l, int r, int val) {
    r = r + 1;
    split(l), split(r);
    for (auto it = map.find(l); it->first != r; it = std::next(it))
      (it->second += val) %= mod;
  }
  int getRangeLen(int l, int r) {
    r = r + 1;
    split(l), split(r);
    int res = 0;
    for (auto it = map.find(l); it->first != r; it = std::next(it))
      res += std::next(it)->first - it->first;
    return res;
  }
  int rangeSum(int l, int r) {
    r = r + 1;
    split(l), split(r);
    int res = 0;
    for (auto it = map.find(l); it->first != r; it = std::next(it)) {
      int cnt = std::next(it)->first - it->first;
      res = int((res + 1ll * cnt * it->second) % mod);
    }
    return res;
  }
  void copy(int l1, int r1, int l2, int r2) {
    r1 = r1 + 1, r2 = r2 + 1;
    split(l1), split(r1), split(l2), split(r2);
    int dis = l2 - l1;
    for (auto it = map.find(l1); it->first != r1; it = std::next(it))
      assign(it->first + dis, std::next(it)->first - 1 + dis, it->second);
  }
  void swap(int l1, int r1, int l2, int r2) {
    r1 = r1 + 1, r2 = r2 + 1;
    split(l1), split(r1), split(l2), split(r2);
    int dis = l2 - l1;
    std::vector<tiii> v;
    for (auto it = map.find(l2); it->first != r2; it = std::next(it)) {
      int nowL = it->first, nowR = std::next(it)->first - 1, nowV = it->second;
      v.push_back({nowL - dis, nowR - dis, nowV});
    }
    for (auto it = map.find(l1); it->first != r1; it = std::next(it))
      assign(it->first + dis, std::next(it)->first - 1 + dis, it->second);
    for (auto [L, R, V] : v) assign(L, R, V);
  }
  void reverse(int l, int r) {
    r = r + 1;
    split(l), split(r);
    std::vector<tiii> v;
    for (auto it = map.find(l); it->first != r; it = std::next(it)) {
      int nowL = it->first, nowR = std::next(it)->first - 1, nowV = it->second;
      v.push_back({nowL, nowR, nowV});
    }
    for (auto [L, R, V] : v) assign(l + r - R - 1, l + r - L - 1, V);
  }
  ll getKth(int l, int r, int k) {
    r = r + 1;
    split(l), split(r);
    std::vector<std::pair<ll, int>> vec;  

    for (auto it = map.find(l); it->first != r; it = std::next(it)) {
      int cnt = std::next(it)->first - it->first;  

      vec.push_back({it->second, cnt});
    }
    std::sort(vec.begin(), vec.end());
    for (const auto& [num, cnt] : vec) {
      k -= cnt;
      if (k <= 0) return num;
    }
    return -1;
  }
};

void solution() {
  int n, m;
  read(n, m);
  std::vector<int> a(n + 1);
  for (int i = 1; i <= n; ++i) read(a[i]);
  std::vector<int> preMin(n + 1, 1e9);
  for (int i = 1; i <= n; ++i) preMin[i] = std::min(preMin[i - 1], a[i]);
  std::set<int, std::less<int>> head;
  

  

  for (int i = 1; i <= n; ++i)
    if (head.empty() || a[i] < a[*head.rbegin()]) head.insert(i);
  

  

  

  

  

  


  std::vector<int> ans(m + 1);
  for (int i = 1; i <= m; ++i) {
    int k, d;
    read(k, d);
    a[k] -= d;
    if (a[k] < 0) a[k] = 0;
    auto brute = [&]() {
      int ans = 0;
      for (int j = 1; j <= n; ++j) {
        int k = j;
        while (k + 1 <= n && a[k + 1] >= a[j]) ++k;
        ++ans;
        j = k;
      }
      return ans;
    };
    auto std = [&]() {
      auto it = head.upper_bound(k);
      if (it != head.begin()) {
        it = std::prev(it);
        if (a[k] < a[*it]) head.insert(k);
        if (*it == k) assert(head.contains(k));
      } else {
        head.insert(k);
      }
      while (true) {
        it = head.upper_bound(k);
        if (it == head.end()) break;
        if (a[*it] >= a[k])
          head.erase(it);
        else
          break;
      }
      return int(head.size());
    };
    

    

    ans[i] = (1ll * n * m < 1ll * 52000 * 52000) ? brute() : std();
  }
  for (int i = 1; i <= m; ++i) std::cout << ans[i] << " \n"[i == m];
}

#endif

signed main() {
#ifdef yyfLocal
  logs(std::string_view(__FILE__).substr(
      std::string_view(__FILE__).rfind("\\") + 1));
  freopen("testdata.in", "r", stdin);
  

#endif
#ifndef yyfLocal
  freopen("testdata.log", "w", stderr);
#endif
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cout.tie(nullptr);
  MT solution();
#ifdef yyfLocal
  std::clog << "\ntime: " << std::fixed << std::setprecision(3)
            << clock() * 1000.0 / CLOCKS_PER_SEC << "ms\n";
#endif
}








