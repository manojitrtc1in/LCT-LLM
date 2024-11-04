




extern const bool id5 = false;
extern const bool id4 = false;



























struct fast_ios {
  fast_ios() {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.precision(10);
    std::cout << std::fixed;
  };
} id0;
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
  bool is_first = true;
  for (const auto &row : t) {
    if (is_first)
      is_first = false;
    else
      out << '\n';
    out << row;
  }
  return out;
}


template<typename... Args> void pt(Args &&... args) {
  ((std::cout << args << ' '), ...);
}

template<typename First, typename... Args>
void pl(const First &first, const Args &... args) {
  std::cout << first;
  ((std::cout << ' ' << args), ...);
  std::cout << '\n';
}

template<typename... Args> void pn(const Args &... args) {
  ((std::cout << args << '\n'), ...);
}

}

inline int ri() {
  int x;
  std::cin >> x;
  return x;
}




















template<unsigned dimension, typename T>
class vec : public std::vector<vec<dimension - 1, T>> {
  using std::vector<vec<dimension - 1, T>>::vector;

 public:
  template<typename... Args>
  vec(unsigned d, Args... args)
      : std::vector<vec<dimension - 1, T>>(d, vec<dimension - 1, T>(args...)) {}
};
template<typename T> class vec<1, T> : public std::vector<T> {
  using std::vector<T>::vector;
};



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
using vii = std::vector<pii>;
template<typename T, typename U = std::less<T>>
using pq = std::priority_queue<T, std::vector<T>, U>;
template<typename... Ts> using vt = std::vector<std::tuple<Ts...>>;
template<typename T> using vv = vec<2, T>;



  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id3(r_end_, __LINE__) = b;                                  \
       i < id3(r_end_, __LINE__); ++i)

  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id3(r_end_, __LINE__) = b;                                  \
       i < id3(r_end_, __LINE__); i += c)




  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id3(r_end_, __LINE__) = b;                                  \
       i <= id3(r_end_, __LINE__); ++i)

  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id3(r_end_, __LINE__) = b;                                  \
       i <= id3(r_end_, __LINE__); i += c)


  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = b,                                                              \
           id3(r_end_, __LINE__) = a;                                  \
       i >= id3(r_end_, __LINE__); --i)

  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = b,                                                              \
           id3(r_end_, __LINE__) = a;                                  \
       i >= id3(r_end_, __LINE__); i -= c)


  for (auto id3(_iter_, __LINE__) = n;                                 \
       id3(_iter_, __LINE__) > 0; --id3(_iter_, __LINE__))













  for (auto id3(_n_, __LINE__) = n; i < id3(_n_, __LINE__); ++i)

  int id2;                                                             \
  scan(id2)

  long long id2;                                                       \
  scan(id2)

  std::string id2;                                                     \
  scan(id2)

  type name(id2);                                                      \
  scan(name)




inline void Yn(bool p) {
  std::cout << (p ? "Yes\n" : "No\n");
}
inline void YN(bool p) {
  std::cout << (p ? "YES\n" : "NO\n");
}
inline void yn(bool p) {
  std::cout << (p ? "yes\n" : "no\n");
}
template<typename Container> Container inc(Container &&c) {
  for (auto &e : c)
    ++e;
  return c;
}
template<typename Container> Container dec(Container &&c) {
  for (auto &e : c)
    --e;
  return c;
}
template<typename A, typename B> inline bool chkmin(A &a, const B &b) {
  return b < a ? a = b, true : false;
}

template<typename A, typename B> inline bool chkmax(A &a, const B &b) {
  return a < b ? a = b, true : false;
}

template<typename Container> Container rev(Container &&c) {
  std::reverse(std::begin(c), std::end(c));
  return c;
}

template<typename Container> auto max(const Container &c) {
  return *std::max_element(std::begin(c), std::end(c));
}

template<typename Container> auto min(const Container &c) {
  return *std::min_element(std::begin(c), std::end(c));
}

template<typename Container> Container iota(Container &&c, int v = 0) {
  std::iota(std::begin(c), std::end(c), v);
  return c;
}

template<typename Container, typename Compare = void *>
Container sort(Container &&c, Compare comp = nullptr) {
  if constexpr (std::is_same_v<Compare, void *>)
    std::sort(std::begin(c), std::end(c));
  else
    std::sort(std::begin(c), std::end(c), comp);
  return c;
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

template<class F> struct id1 {
  template<class... TLs> struct ref {
    id1 &self;
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
template<class F> id1(F) -> id1<F>;






using namespace io;
using namespace std;




















template<typename Value, typename Tag, typename Result> class SegTree {
  int index(int l, int r) const { return (l + r) | (l != r); }
  struct Node {
    int p = -1;
    Value val;
    Tag tag;
    void apply(int l, int r, const Tag &t) {
      tag.apply(t);
      val.apply(l, r, t);
    }
  };
  int n;
  std::vector<Node> tree;
  inline void push(int l, int r) {
    auto &t = tree[index(l, r)].tag;
    if (t.pushable()) {
      int m = (l + r) >> 1, y = index(l, m), z = index(m + 1, r);
      tree[y].val.apply(l, m, t);
      tree[y].tag.apply(t);
      tree[z].val.apply(m + 1, r, t);
      tree[z].tag.apply(t);
      t.after_push();
    }
  }
  inline void pull(int l, int r) {
    int x = index(l, r), m = (l + r) >> 1, y = index(l, m), z = index(m + 1, r);
    tree[x].val = tree[y].val + tree[z].val;
  }
  template<typename F> void build(int l, int r, const F &f) {
    if (l == r) {
      f(tree[2 * l].val, l);
      return;
    }
    int m = (l + r) >> 1;
    tree[index(l, m)].p = tree[index(m + 1, r)].p = l + r;
    build(l, m, f);
    build(m + 1, r, f);
    pull(l, r);
  }
  Result get(int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr)
      return tree[index(l, r)].val;
    int m = (l + r) >> 1;
    push(l, r);
    if (rr <= m)
      return get(l, m, ll, rr);
    if (ll > m)
      return get(m + 1, r, ll, rr);
    return get(l, m, ll, rr) + get(m + 1, r, ll, rr);
  }
  void modify(int l, int r, int ll, int rr, const Tag &t) {
    if (ll <= l && r <= rr) {
      tree[index(l, r)].apply(l, r, t);
      return;
    }
    push(l, r);
    int m = (l + r) >> 1;
    if (ll <= m)
      modify(l, m, ll, rr, t);
    if (rr > m)
      modify(m + 1, r, ll, rr, t);
    pull(l, r);
  }
  int find_first(int l, int r, int ll, int rr,
                 const std::function<bool(const Value &)> &f) {
    if (ll <= l && r <= rr)
      return f(tree[index(l, r)].val) ? find_first_knowingly(l, r, f) : -1;
    push(l, r);
    int m = (l + r) >> 1;
    int res = -1;
    if (ll <= m)
      res = find_first(l, m, ll, rr, f);
    if (rr > m && res == -1)
      res = find_first(m + 1, r, ll, rr, f);
    return res;
  }
  int find_last(int l, int r, int ll, int rr,
                const std::function<bool(const Value &)> &f) {
    if (ll <= l && r <= rr)
      return f(tree[index(l, r)].val) ? find_last_knowingly(l, r, f) : -1;
    push(l, r);
    int m = (l + r) >> 1;
    int res = -1;
    if (rr > m)
      res = find_last(m + 1, r, ll, rr, f);
    if (ll <= m && res == -1)
      res = find_last(l, m, ll, rr, f);
    return res;
  }
  int find_first_knowingly(int l, int r,
                           const std::function<bool(const Value &)> &f) {
    if (l == r)
      return l;
    push(l, r);
    int m = (l + r) >> 1;
    return f(tree[index(l, m)].val) ? find_first_knowingly(l, m, f)
                                    : find_first_knowingly(m + 1, r, f);
  }
  int find_last_knowingly(int l, int r,
                          const std::function<bool(const Value &)> &f) {
    if (l == r)
      return l;
    push(l, r);
    int m = (l + r) >> 1;
    return f(tree[index(m + 1, r)].val) ? find_last_knowingly(m + 1, r, f)
                                        : find_last_knowingly(l, m, f);
  }

 public:
  template<typename F = void (*)(Value &, int)>
  SegTree(
      int _n, const F &f = [](Value &, int) {})
      : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, n - 1, f);
  }
  Result get() { return tree[0].val; }
  Result get(int ll, int rr) {
    if (ll > rr)
      return Result{};
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return get(0, n - 1, ll, rr);
  }
  Result get(int p) {
    assert(0 <= p && p <= n - 1);
    return get(0, n - 1, p, p);
  }
  void modify(int ll, int rr, const Tag &t) {
    if (ll > rr)
      return;
    assert(0 <= ll && rr <= n - 1);
    modify(0, n - 1, ll, rr, t);
  }
  template<typename... M> void modify_leaf(int leaf, const M &... v) {
    assert(0 <= leaf && leaf < n);
    tree[2 * leaf].val.apply_to_leaf(v...);
    for (int l = leaf, r = leaf, s; (s = tree[index(l, r)].p) != -1;)
      if (s < l + r) {
        tree[s | 1] = tree[index(s - r, l - 1)] + tree[index(l, r)];
        l = s - r;
      } else {
        tree[s | 1] = tree[index(l, r)] + tree[index(r + 1, s - l)];
        r = s - l;
      }
  }
  template<typename F> void collect(int leaf, const F &f) const {
    assert(0 <= leaf && leaf < n);
    for (int i = 2 * leaf; i != -1; i = tree[i].p | 1)
      f(tree[i].tag);
  }
  

  

  int find_first(int ll, int rr, const std::function<bool(const Value &)> &f) {
    if (ll > rr)
      return -1;
    assert(0 <= ll && rr <= n - 1);
    return find_first(0, n - 1, ll, rr, f);
  }
  int find_last(int ll, int rr, const std::function<bool(const Value &)> &f) {
    if (ll > rr)
      return -1;
    assert(0 <= ll && rr <= n - 1);
    return find_last(0, n - 1, ll, rr, f);
  }
};
template<typename Result>
using segtree_t = SegTree<struct Value, struct Tag, Result>;
using segtree = segtree_t<struct Value>;












struct Tag {
  

  

  bool pushable() const { return val != 0; }
  void apply(const Tag &t) { val = t.val; }
  void after_push() { val = 0; }
  int val = 0;
};

struct Value {
  void apply_to_leaf(...) {}
  void apply(int l, int r, const Tag &t) {
    sum = 1LL * (r - l + 1) * t.val;
    mn = t.val;
  }
  ll sum = 0;
  int mn = INT_MAX;
};


Value operator+(const Value &a, const Value &b) {
  return {a.sum + b.sum, min(a.mn, b.mn)};
}

void solve() {
  INT(n, q);
  vi a(n);
  scan(a);
  segtree tree(n, [&](Value &v, int i) { v.sum = v.mn = a[i]; });
  rep (q) {
    INT(type, x, y);
    

    

    --x;
    

    if (type == 1) {
      int t =
          tree.find_first(0, n - 1, [&](const Value &v) { return v.mn < y; });
      if (t == -1)
        continue;
      tree.modify(t, x, {y});
    } else {
      int ans = 0;
      while (1) {

        auto t = tree.find_first(x, n - 1,
                                 [&](const Value &v) { return v.mn <= y; });
        if (t == -1)
          break;
        

        int tt = tree.find_first(t, n - 1, [y](const Value &v) mutable {
          if (y >= v.sum) {
            y -= v.sum;
            return false;
          }
          return true;
        });
        if (tt == -1)
          tt = n;
        debug(y, t, tt);
        ans += tt - t;
        y -= tree.get(t, tt - 1).sum;
        debug(y);
        x = tt + 1;
      }
      pl(ans);
    }
  }
}



int main() {

  freopen(FILE_IO ".in", "r", stdin);
  freopen(FILE_IO ".out", "w", stdout);

  solve();
  return 0;
}
