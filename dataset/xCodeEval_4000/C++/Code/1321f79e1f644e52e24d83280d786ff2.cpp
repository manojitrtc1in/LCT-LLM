

#ifndef ALGO_UTILS
#define ALGO_UTILS
#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <cstring>
#include <map>
#include <numeric>
#include <set>
#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#include <iostream>
#include <vector>
#include <tuple>
struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} fast_ios_;
namespace io {
template<typename... Ts>
std::istream &operator>>(std::istream &in, std::tuple<Ts...> &t);
template<typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec)
    stream >> x;
  return stream;
}

template<typename... Ts>
std::istream &operator>>(std::istream &in, const std::tuple<Ts...> &t) {
  std::apply([&in](auto &... args) { ((in >> args), ...); }, t);
  return in;
}

template<class... Args> void scan(Args &... args) {
  ((std::cin >> args), ...);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first)
      first = false;
    else
      out << ' ';
    out << t;
  }
  return out;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &out, const std::pair<T, U> &p) {
  out << p.first << ' ' << p.second;
  return out;
}

template<typename T>
std::ostream &operator<<(std::ostream &out,
                         const std::vector<std::vector<T>> &t) {
  for (const auto &row : t) {
    out << row << '\n';
  }
  return out;
}

template<typename... Args> void print(Args &&... args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void println(const First &first, const Args &... args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}
}

using io::scan;
using io::print;
using io::println;
inline int ri() {
  int x;
  std::cin >> x;
  return x;
}
#endif









#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_ALIAS_HPP_
#include <string>
#include <cassert>
#include <queue>
using ll = long long;
using ull = unsigned long long;
using vl = std::vector<ll>;
using vb = std::vector<bool>;
using vi = std::vector<int>;
using vs = std::vector<std::string>;
using pii = std::pair<int, int>;
using pli = std::pair<ll, int>;
using pil = std::pair<int, ll>;
using pll = std::pair<ll, ll>;
using vpii = std::vector<pii>;
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> class vv {
  std::vector<std::vector<T>> data;

 public:
  explicit vv(int n) {
    assert(n > 0);
    data.assign(n, std::vector<T>{});
  }
  vv(int n, int m, T init = T{}) {
    assert(n > 0 && m > 0);
    data.assign(n, std::vector<T>(m, init));
  }
  std::vector<T> &operator[](size_t i) {
    assert(i < data.size());
    return data[i];
  }
  void fill(T val) {
    for (auto &row : data)
      std::fill(row.begin(), row.end(), val);
  }
  friend std::istream &operator>>(std::istream &in, vv<T> &val) {
    return in >> val.data;
  }
  friend std::ostream &operator<<(std::ostream &out, const vv<T> &val) {
    return out << val.data;
  }
  friend auto begin(vv<T> &val) { return val.data.begin(); }
  friend auto end(vv<T> &val) { return val.data.end(); }
  friend auto rbegin(vv<T> &val) { return val.data.rbegin(); }
  friend auto rend(vv<T> &val) { return val.data.rend(); }
};

#define rng3(i, a, b)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type i = a; i < b; ++i)
#define rng2(i, n) rng3(i, 0, n)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define rng(...) GET_MACRO(__VA_ARGS__, rng3, rng2)(__VA_ARGS__)
#define up(i, a, b)                                                            \
  for (std::common_type<decltype(a), decltype(b)>::type i = a; i <= b; ++i)
#define down(i, b, a)                                                          \
  for (std::common_type<decltype(a), decltype(b)>::type i = b; i >= a; i--)
#define TOKENPASTE(x, y) x##y
#define TOKENPASTE2(x, y) TOKENPASTE(x, y)
#define rep(n)                                                                 \
  for (auto TOKENPASTE2(_iter_, __LINE__) = n;                                 \
       TOKENPASTE2(_iter_, __LINE__) > 0; --TOKENPASTE2(_iter_, __LINE__))
#define FOR(x, cont) for (const auto &x : cont)
#define For(x, cont) for (auto &x : cont)
#define ALL(x) begin(x), end(x)


#define RALL(x) rbegin(x), rend(x)
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ep emplace
#define SZ(x) (int) (x).size()
#define UNIQ(vec)                                                              \
  sort(ALL(vec)), (vec).erase(std::unique(ALL(vec)), std::end(vec))
#define LB(cont, x) int(std::lower_bound(ALL(cont), x) - std::begin(cont))
#define UB(cont, x) int(std::upper_bound(ALL(cont), x) - std::begin(cont))
#define rp(...) return println(__VA_ARGS__)
#define adv(i, n)                                                              \
  for (auto TOKENPASTE2(_n_, __LINE__) = n; i < TOKENPASTE2(_n_, __LINE__); ++i)
#endif


void rg(int m, vv<int> &g) {
  for (int i = 0, a, b; i < m; ++i) {
    std::cin >> a >> b;
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
}
inline void yes() {
  std::cout << "Yes\n";
}
inline void no() {
  std::cout << "No\n";
}
inline void Yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
inline void YN(bool p) {
  std::cout << (p ? "YES\n" : "NO\n");
}
inline void yn(bool p) {
  std::cout << (p ? "yes\n" : "no\n");
}
template<typename T> T &inc(T &cont) {
  for (auto &e : cont)
    ++e;
  return cont;
}
template<typename T> T &dec(T &cont) {
  for (auto &e : cont)
    --e;
  return cont;
}
template<typename A, typename B> bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> bool chkmax(A &a, const B &b) {
  return b > a ? a = b, true : false;
}

template<typename T> struct reversion_wrapper { T &iterable; };
template<typename T> auto begin(reversion_wrapper<T> w) {
  using std::rbegin;
  return rbegin(w.iterable);
}
template<typename T> auto end(reversion_wrapper<T> w) {
  using std::rend;
  return rend(w.iterable);
}
template<typename T> reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}
template<typename T, typename U> T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U> T floor(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
}

template<class...> struct typelist {};

template<class T, class... Ts>
constexpr bool any_same = (std::is_same_v<T, Ts> || ...);

template<class F> struct y_combinator {
  template<class... TLs> struct ref {
    y_combinator &self;
    template<class... Args> decltype(auto) operator()(Args &&... args) const {
      using G = std::conditional_t<any_same<typelist<Args...>, TLs...>,
                                   ref<TLs...>, ref<TLs..., typelist<Args...>>>;
      return self.f(G{self}, std::forward<Args>(args)...);
    }
  };
  F f;
  template<class... Args> decltype(auto) operator()(Args &&... args) {
    return ref<>{*this}(std::forward<Args>(args)...);
  }
};
template<class F> y_combinator(F) -> y_combinator<F>;
#ifndef debug
#define debug(...) 42
#endif
#endif








#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_SEGTREE_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_SEGTREE_HPP_
#include <functional>






template<typename Value, typename Tag> class SegTree {
  struct Node {
    Value val;
    Tag tag;
    template<typename... M> void apply(int l, int r, const M &... v) {
      Tag delta{v...};
      tag += delta;
      val.apply(delta, l, r);
    }
  };
  const Tag empty_tag;
  int n;
  std::vector<Node> tree;
  inline void push(int x, int l, int r) {
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    

    

    if (tree[x].tag) {
      tree[x + 1].val.apply(tree[x].tag, l, y);
      tree[x + 1].tag += tree[x].tag;
      tree[z].val.apply(tree[x].tag, y + 1, r);
      tree[z].tag += tree[x].tag;
      tree[x].tag = empty_tag;
    }
  }
  inline void pull(int x, int z) {
    tree[x].val = tree[x + 1].val + tree[z].val;
  }
  void build(int x, int l, int r) {
    if (l == r) {
      tree[x].val.apply(l);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
  template<typename M>
  void build(int x, int l, int r, const std::vector<M> &v) {
    if (l == r) {
      tree[x].apply(l, r, v[l]);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, v);
    build(z, y + 1, r, v);
    pull(x, z);
  }
  template<typename Callable>
  void build(int x, int l, int r, const Callable &f) {
    if (l == r) {
      tree[x].apply(l, r, f(l));
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y, f);
    build(z, y + 1, r, f);
    pull(x, z);
  }
  Value get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x].val;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    Value res;
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = get(x + 1, l, y, ll, rr) + get(z, y + 1, r, ll, rr);
      }
    }
    pull(x, z);
    return res;
  }
  template<typename... M>
  void modify_leaf(int x, int l, int r, int p, const M &... v) {
    if (l == r) {
      tree[x].val.apply(p, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (p <= y)
      modify_leaf(x + 1, l, y, p, v...);
    else
      modify_leaf(z, y + 1, r, p, v...);
    pull(x, z);
  }
  template<typename... M>
  void modify(int x, int l, int r, int ll, int rr, const M &... v) {
    if (ll <= l && r <= rr) {
      tree[x].apply(l, r, v...);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (ll <= y) {
      modify(x + 1, l, y, ll, rr, v...);
    }
    if (rr > y) {
      modify(z, y + 1, r, ll, rr, v...);
    }
    pull(x, z);
  }
  int find_first(int x, int l, int r, int ll, int rr,
                 const std::function<bool(const Node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_first_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (ll <= y) {
      res = find_first(x + 1, l, y, ll, rr, f);
    }
    if (rr > y && res == -1) {
      res = find_first(z, y + 1, r, ll, rr, f);
    }
    pull(x, z);
    return res;
  }
  int find_last(int x, int l, int r, int ll, int rr,
                const std::function<bool(const Node &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x])) {
        return -1;
      }
      return find_last_knowingly(x, l, r, f);
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res = -1;
    if (rr > y) {
      res = find_last(z, y + 1, r, ll, rr, f);
    }
    if (ll <= y && res == -1) {
      res = find_last(x + 1, l, y, ll, rr, f);
    }
    pull(x, z);
    return res;
  }

 public:
  int find_first_knowingly(int x, int l, int r,
                           const std::function<bool(const Node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1])) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    pull(x, z);
    return res;
  }

  int find_last_knowingly(int x, int l, int r,
                          const std::function<bool(const Node &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z])) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    pull(x, z);
    return res;
  }
  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
  template<typename M> SegTree(const std::vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
  template<typename Callable> SegTree(int _n, const Callable &f) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, f);
  }
  Value get() { return tree[0].val; }
  Value get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
  Value get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
  template<typename... M> void modify(int ll, int rr, const M &... v) {
    if (ll > rr)
      return;
    assert(0 <= ll && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
  template<typename... M> void modify_leaf(int p, const M &... v) {
    assert(0 <= p && p < n);
    modify_leaf(0, 0, n - 1, p, v...);
  }
  

  

  int find_first(int ll, int rr, const std::function<bool(const Node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
  int find_last(int ll, int rr, const std::function<bool(const Node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};
struct Value;
struct Tag;
using segtree = SegTree<Value, Tag>;
#endif


struct Tag {
  Tag() = default;
  

  int add = 0;
  operator bool() { return add; }
  Tag &operator+=(const Tag &other) {
    add += other.add;
    return *this;
  }
};

const int INF = 1e9;
struct Value {
  

  int max = -INF;
  void apply(int i) { max += i - 1; }
  void apply(int i, int v) { max += v; }
  void apply(const Tag &tag, int l, int r) { max += tag.add; }
};
Value operator+(const Value &a, const Value &b) {
  return {std::max(a.max, b.max)};
}
using namespace std;
void solve() {
  int n, k, m;
  scan(n, k, m);
  int N = n + max(k - 1, n - k) + 1;
  segtree t(N);
  vi cnt(N);
  set<pii> s;
  rep (m) {
    int x, y;
    scan(x, y);
    int ny = y + abs(k - x);
    auto iter = s.find({x, y});
    if (iter == s.end()) {
      s.ep(x, y);
      if (cnt[ny] == 0)
        t.modify_leaf(ny, INF);
      ++cnt[ny];
      t.modify(0, ny, 1);
    } else {
      s.erase(iter);
      --cnt[ny];
      if (cnt[ny] == 0)
        t.modify_leaf(ny, -INF);
      t.modify(0, ny, -1);
    }
    println(max(n, t.get().max) - n);
  }
}



class GPawns {
 public:
  static void solve(istream &, ostream &) { ::solve(); }
};

#define in std::cin
#define out std::cout
int main() {
  GPawns solver;
  solver.solve(in, out);
  return 0;
}
