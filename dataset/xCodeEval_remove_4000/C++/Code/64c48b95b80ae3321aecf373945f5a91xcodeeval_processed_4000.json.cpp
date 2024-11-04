


extern constexpr bool id3 = false;



























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
    return io::operator>>(in, val.data);
  }
  friend std::ostream &operator<<(std::ostream &out, const vv<T> &val) {
    return io::operator<<(out, val.data);
  }
  friend auto begin(vv<T> &val) { return val.data.begin(); }
  friend auto end(vv<T> &val) { return val.data.end(); }
  friend auto rbegin(vv<T> &val) { return val.data.rbegin(); }
  friend auto rend(vv<T> &val) { return val.data.rend(); }
};



  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id2(r_end_, __LINE__) = b;                                  \
       i < id2(r_end_, __LINE__); ++i)




  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = a,                                                              \
           id2(r_end_, __LINE__) = b;                                  \
       i <= id2(r_end_, __LINE__); ++i)

  for (std::common_type<decltype(a), decltype(b)>::type                        \
           i = b,                                                              \
           id2(r_end_, __LINE__) = a;                                  \
       i >= id2(r_end_, __LINE__); --i)

  for (auto id2(_iter_, __LINE__) = n;                                 \
       id2(_iter_, __LINE__) > 0; --id2(_iter_, __LINE__))














  for (auto id2(_n_, __LINE__) = n; i < id2(_n_, __LINE__); ++i)






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
  return a < b ? a = b, true : false;
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
      tree[x].val.init_leaf(l);
      return;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    build(x + 1, l, y);
    build(z, y + 1, r);
    pull(x, z);
  }
  Value get(int x, int l, int r, int ll, int rr) {
    if (ll <= l && r <= rr) {
      return tree[x].val;
    }
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    push(x, l, r);
    if (rr <= y)
      return get(x + 1, l, y, ll, rr);
    if (ll > y)
      return get(z, y + 1, r, ll, rr);
    return get(x + 1, l, y, ll, rr) + get(z, y + 1, r, ll, rr);
  }
  template<typename... M>
  void modify_leaf(int x, int l, int r, int p, const M &... v) {
    if (l == r) {
      tree[x].val.apply_to_leaf(v...);
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
                 const std::function<bool(const Value &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x].val)) {
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
    return res;
  }
  int find_last(int x, int l, int r, int ll, int rr,
                const std::function<bool(const Value &)> &f) {
    if (ll <= l && r <= rr) {
      if (!f(tree[x].val)) {
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
    return res;
  }
  int find_first_knowingly(int x, int l, int r,
                           const std::function<bool(const Value &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[x + 1].val)) {
      res = find_first_knowingly(x + 1, l, y, f);
    } else {
      res = find_first_knowingly(z, y + 1, r, f);
    }
    return res;
  }
  int find_last_knowingly(int x, int l, int r,
                          const std::function<bool(const Value &)> &f) {
    if (l == r) {
      return l;
    }
    push(x, l, r);
    int y = (l + r) >> 1;
    int z = x + ((y - l + 1) << 1);
    int res;
    if (f(tree[z].val)) {
      res = find_last_knowingly(z, y + 1, r, f);
    } else {
      res = find_last_knowingly(x + 1, l, y, f);
    }
    return res;
  }

 public:
  SegTree(int _n) : n(_n) {
    assert(n > 0);
    tree.resize(2 * n - 1);
    build(0, 0, n - 1);
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
  

  

  int find_first(int ll, int rr, const std::function<bool(const Value &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_first(0, 0, n - 1, ll, rr, f);
  }
  int find_last(int ll, int rr, const std::function<bool(const Value &)> &f) {
    assert(0 <= ll && ll <= rr && rr <= n - 1);
    return find_last(0, 0, n - 1, ll, rr, f);
  }
};
using segtree = SegTree<class Value, class Tag>;





struct Tag {
  Tag() = default;
  

  operator bool() const { return reversed; }
  Tag &operator+=(const Tag &other) {
    reversed ^= 1;
    return *this;
  }
  int reversed = 0;
};
string s;
struct Value {
  

  void init_leaf(int i) {
    len = l_len = r_len = 1;
    max_face = max_back = l_face = l_back = r_face = r_back = 0;
    if (s[i] == '>')
      l_dir = r_dir = 1;
    else
      l_dir = r_dir = -1;
    

  }
  void apply_to_leaf(...) {}
  void apply(const Tag &tag, int l, int r) {
    l_dir = -l_dir;
    r_dir = -r_dir;
    swap(max_face, max_back);
    swap(l_face, l_back);
    swap(r_face, r_back);
  }
  bool one_dir() const { return l_len == len; }
  int len;
  int l_dir, l_len, r_dir, r_len;
  int l_face, l_back, r_face, r_back;
  int max_face, max_back;
};


Value operator+(const Value &a, const Value &b) {
  Value c;
  c.len = a.len + b.len;
  c.l_dir = a.l_dir, c.r_dir = b.r_dir;
  c.l_len = a.one_dir() and a.l_dir == b.l_dir ? a.l_len + b.l_len : a.l_len;
  c.r_len = b.one_dir() and a.r_dir == b.r_dir ? a.r_len + b.r_len : b.r_len;
  c.l_face = a.l_face;
  if (a.l_dir == 1 && a.max_back == 0) {
    if (b.l_dir == -1)
      

      c.l_face = a.len + b.l_len;
    else if (a.r_dir == 1 and b.l_face > 0)
      

      c.l_face = a.len + b.l_face;
  }
  c.r_face = b.r_face;
  if (b.r_dir == -1 and b.max_back == 0) {
    

    if (a.r_dir == 1)
      c.r_face = b.len + a.r_len;
    

    else if (b.l_dir == -1 and a.r_face > 0)
      c.r_face = b.len + a.r_face;
  }
  c.l_back = a.l_back;
  if (a.l_dir == -1 and a.max_face == 0) {
    

    if (b.l_dir == 1)
      c.l_back = a.len + b.l_len;
    

    else if (b.l_back > 0 and a.r_dir == -1)
      c.l_back = a.len + b.l_back;
  }
  c.r_back = b.r_back;
  if (b.r_dir == 1 and b.max_face == 0) {
    

    if (a.r_dir == -1)
      c.r_back = b.len + a.r_len;
    

    else if (a.r_back > 0 and b.l_dir == 1)
      c.r_back = b.len + a.r_back;
  }
  c.max_face = max(a.max_face, b.max_face);
  if (a.r_dir == 1 and b.l_dir == -1)
    chkmax(c.max_face, a.r_len + b.l_len);
  else if (a.r_dir == -1 and b.l_dir == -1 and a.r_face > 0)
    chkmax(c.max_face, a.r_face + b.l_len);
  else if (a.r_dir == 1 and b.l_dir == 1 and b.l_face > 0)
    chkmax(c.max_face, a.r_len + b.l_face);
  c.max_back = max(a.max_back, b.max_back);
  if (a.r_dir == -1 and b.l_dir == 1)
    chkmax(c.max_back, a.r_len + b.l_len);
  else if (a.r_dir == 1 and b.l_dir == 1 and a.r_back > 0)
    chkmax(c.max_back, a.r_back + b.l_len);
  else if (a.r_dir == -1 and b.l_dir == -1 and b.l_back > 0)
    chkmax(c.max_back, a.r_len + b.l_back);
  return c;
}

void solve() {
  INT(n, q);
  scan(s);
  debug(n, q, s);
  segtree t(n);
  rep (q) {
    INT(l, r);
    --l, --r;
    

    

    

    

    

    


    t.modify(l, r);
    auto res = t.get(l, r);
    debug(res.max_face, res.max_back);
    int ans = res.max_face;
    if (res.l_dir == -1)
      chkmax(ans, res.l_len);
    if (res.r_dir == 1)
      chkmax(ans, res.r_len);
    pn(ans);
  }
}



int main() {
  solve();
  return 0;
}
