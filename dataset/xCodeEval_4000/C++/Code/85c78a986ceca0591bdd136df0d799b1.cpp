

#ifndef ALGO_UTILS
#define ALGO_UTILS
#include <algorithm>
#include <bitset>
#include <cassert>
#include <climits>
#include <cmath>
#include <cstring>

#include <iostream>
#include <sstream>
#include <tuple>
using std::to_string;
std::string to_string(const std::string &s) { return '"' + s + '"'; }

std::string to_string(const char *s) { return to_string((std::string) s); }

std::string to_string(bool b) { return (b ? "true" : "false"); }

template<size_t N>
std::string to_string(const std::bitset<N> &bs) {
  return bs.to_string();
}


template<typename A>
std::string to_string(const A &v);
template<typename... Args>
std::string to_string(std::tuple<Args...> const &t);

template<typename A, typename B>
std::string to_string(const std::pair<A, B> &p) {
  return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}

template<typename A>
std::string to_string(const A &v) {
  bool first = true;
  std::string res = "{";
  for (const auto &x : v) {
    if (!first) { res += ", "; }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}

namespace aux {
template<std::size_t...>
struct seq {};

template<std::size_t N, std::size_t... Is>
struct gen_seq : gen_seq<N - 1, N - 1, Is...> {};

template<std::size_t... Is>
struct gen_seq<0, Is...> : seq<Is...> {};

template<class Ch, class Tr, class Tuple, std::size_t... Is>
void print_tuple(std::basic_ostream<Ch, Tr> &os, Tuple const &t, seq<Is...>) {
  using swallow = int[];
  (void) swallow{0, (void(os << (Is == 0 ? "" : ", ") << std::get<Is>(t)), 0)...};
}
}


template<typename... Args>
std::string to_string(std::tuple<Args...> const &t) {
  std::ostringstream os;
  os << "(";
  aux::print_tuple(os, t, aux::gen_seq<sizeof...(Args)>());
  os << ")";
  return os.str();
}

void debug_out() { std::cerr << std::endl; }

template<typename Head, typename... Tail>
void debug_out(const Head &H, const Tail &... T) {
  std::cerr << " " << to_string(H);
  debug_out(T...);
}

#if defined LOCAL
#define debug(...) std::cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif

#ifndef JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#define JHELPER_EXAMPLE_PROJECT_LIBRARY_IO_HPP_
#include <iomanip>

#include <vector>
struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
  };
} fast_ios_;

template<typename T, typename U>
std::istream &operator>>(std::istream &in, std::pair<T, U> &p) {
  in >> p.first >> p.second;
  return in;
}

template<typename T>
std::istream &operator>>(std::istream &stream, std::vector<T> &vec) {
  for (auto &x : vec) stream >> x;
  return stream;
}



void scan() {}

template<class T, class... Args>
void scan(T &a, Args &... rest) {
  std::cin >> a;
  scan(rest...);
}

template<typename T>
std::ostream &operator<<(std::ostream &out, const std::vector<T> &vec) {
  bool first = true;
  for (const T &t : vec) {
    if (first) first = false;
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
  for (const auto &row : t) { out << row << '\n'; }
  return out;
}

template<typename T>
void print(const T &t) {
  std::cout << t << ' ';
}

template<typename T, typename... Args>
void print(const T &t, const Args &... rest) {
  print(t);
  print(rest...);
}

template<typename T>
void println(const T &t) {
  std::cout << t << '\n';
}

template<typename T, typename... Args>
void println(const T &t, const Args &... rest) {
  print(t);
  println(rest...);
}
#endif


#include <map>
#include <numeric>
#include <queue>
#include <set>
constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
class grid {
  int n, m;
 public:
  grid(int row, int col) {
    assert(row > 0 && col > 0);
    n = row;
    m = col;
  }
  bool cover(int i, int j) const {
    return i >= 0 and i < n && j >= 0 && j < m;
  }
};
template<typename A, typename B>
bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B>
bool chkmax(A &a, const B &b) {
  return b > a ? a = b, true : false;
}

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
template<typename T>
class vv {
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
#define UNIQ(vec) (vec).erase(std::unique(ALL(vec)), std::end(vec))
#define LB(cont, x) int(std::lower_bound(ALL(cont), x) - std::begin(cont))
#define UB(cont, x) int(std::upper_bound(ALL(cont), x) - std::begin(cont))
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename T>
struct reversion_wrapper {
  T &iterable;
};
template<typename T>
auto begin(reversion_wrapper<T> w) {
  return std::rbegin(w.iterable);
}
template<typename T>
auto end(reversion_wrapper<T> w) {
  return std::rend(w.iterable);
}
template<typename T>
reversion_wrapper<T> reverse(T &&iterable) {
  return {iterable};
}
template<typename T, typename U>
T ceil(T x, U y) {
  assert(y > 0);
  if (x > 0)
    x += y - 1;
  return x / y;
}

template<typename T, typename U>
T floor(T x, U y) {
  assert(y > 0);
  if (x < 0)
    x -= y - 1;
  return x / y;
}
#endif

using namespace std;




class segtree {
  struct node {
    

    

    int max = 0;
    int add = 0;
    void apply(int l, int r, int v) {
      max += v;
      add += v;
    }
  };
  node unite(const node &a, const node &b) const {
    node res;
    res.max = max(a.max, b.max);
    return res;
  }
  inline void push(int x, int l, int r) {
    

    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    

    

    if (tree[x].add != 0) {
      tree[x + 1].apply(l, y, tree[x].add);
      tree[z].apply(y + 1, r, tree[x].add);
      tree[x].add = 0;
    }
  }
  inline void pull(int x, int z) {
    tree[x] = unite(tree[x + 1], tree[z]);
  }
  int n;
  vector<node> tree;
  void build(int x, int l, int r) {
    if (l == r) {
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
  template<typename M>
  void build(int x, int l, int r, const vector<M> &v) {
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
  node get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x];
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    node res{};
    if (rr <= y) {
      res = get(x + 1, l, y, ll, rr);
    } else {
      if (ll > y) {
        res = get(z, y + 1, r, ll, rr);
      } else {
        res = unite(get(x + 1, l, y, ll, rr), get(z, y + 1, r, ll, rr));
      }
    }
    pull(x, z);
    return res;
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
                 const function<bool(const node &)> &f) {
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
                const function<bool(const node &)> &f) {
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
                           const function<bool(const node &)> &f) {
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
                          const function<bool(const node &)> &f) {
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
  segtree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
  }
  template<typename M>
  segtree(const vector<M> &v) {
    n = v.size();
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, v);
  }
  template<typename Callable>
  segtree(int _n, const Callable &f) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1, f);
  }
  node get() {
    return get(0, 0, n - 1, 0, n - 1);
  }
  node get(int ll, int rr) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, 0, n - 1, ll, rr);
  }
  node get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, 0, n - 1, p, p);
  }
  template<typename... M>
  void modify(int ll, int rr, const M &... v) {
    if (ll > rr)
      return;
    assert(0 <= ll && rr <= n - 1);
    modify(0, 0, n - 1, ll, rr, v...);
  }
  

  

  int find_first(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
  int find_last(int ll, int rr, const function<bool(const node &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};
class CWorldOfDarkraftBattleForAzathoth {
 public:
  static void solve(istream &, ostream &) {
    int n, m, p;
    scan(n, m, p);
    vpii w(n);
    scan(w);
    sort(ALL(w));

    vi b(m), cb(m);
    rng (i, m)
      scan(b[i], cb[i]);
    vi armor(m);
    iota(ALL(armor), 0);
    sort(ALL(armor), [&](int i, int j) { return b[i] < b[j]; });
    segtree tree(m, [&](int i) { return -cb[armor[i]]; });
    For (x, armor)
      x = b[x];

    vector<tuple<int, int, int>> monster;
    rep (p) {
      int x, y, z;
      scan(x, y, z);
      monster.eb(x, y, z);
    }
    sort(ALL(monster));
    int i = 0;
    int ans = INT_MIN;
    FOR (x, w) {
      while (i < p && get<0>(monster[i]) < x.first) {
        tree.modify(UB(armor, get<1>(monster[i])), m - 1, get<2>(monster[i]));
        ++i;
      }
      auto t = tree.get();
      chkmax(ans, -x.second + tree.get().max);
    }
    println(ans);
  }
};



int main() {
  CWorldOfDarkraftBattleForAzathoth solver;
  auto& in = std::cin;
  auto& out = std::cout;
  solver.solve(in, out);
  return 0;
}
