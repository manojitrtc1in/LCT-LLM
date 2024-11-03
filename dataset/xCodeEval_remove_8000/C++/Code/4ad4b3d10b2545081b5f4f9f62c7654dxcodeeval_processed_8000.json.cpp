static_assert(R"("

void main(int) {
  int n;
  scan(n);
  vla a(n, vla(n, 0));
  for (int i : rep(n)) {
    for (int _ : rep(n)) {
      int c;
      scan(c);
      --c;
      ++a[i][c];
    }
  }
  vector<vla<int>> ans;
  ans.reserve(n * (n - 1) / 2);
  while (true) {
    int pos = a.find([](vla<int> const& ai) { return ai.any_of(1 < _1); });
    if (pos == n) { break; }
    ans.emplace_back(n);
    {
      int p = -1;
      for (int i : rep(pos, n)) {
        int j = a[i].find(1 < _1);
        p = ans.back()[i] = j < n ? j : p;
      }
      for (int i : rep(pos)) {
        int j = a[i].find(1 < _1);
        p = ans.back()[i] = j < n ? j : p;
      }
    }
    for (int i : rep(n)) {
      int j = ans.back()[i];
      --a[i][j];
      ++a[i + 1 < n ? i + 1 : 0][j];
    }
  }
  println(sz(ans) + n * (n - 1) / 2);
  for (auto&& e : ans) { println(e.map(_1 + 1)); }
  for (int i : rep(n)) {
    for (int j : rep1(i).rev()) { println(rep(j, j + n).map(_1 % n + 1)); }
  }
}

")");




















namespace r7h {

using namespace std;

void main(int);

}  









  []<class... Ts_>(Ts_&&... xs_) -> decltype(auto) { return FN(static_cast<Ts_&&>(xs_)...); }


  [&]<class T1_ = void*, class id4 = void*>([[maybe_unused]] T1_&& _1 = nullptr, [[maybe_unused]] id4&& _2 = nullptr) \
      -> decltype(auto) { \
    return __VA_ARGS__; \
  }

namespace r7h {

template <class F>
class fix : F {
 public:
  explicit fix(F f) : F(move(f)) {}

  template <class... Ts>
  decltype(auto) operator()(Ts&&... xs) const {
    return F::operator()(ref(*this), forward<Ts>(xs)...);
  }
};

template <class T>
decay_t<T> id9(T&& x) {
  return forward<T>(x);
}

template <class T>
auto id10(remove_reference_t<T>& x) {
  if constexpr (is_reference_v<T> && !is_placeholder_v<decay_t<T>>) {
    return ref(x);
  } else {
    return move(x);
  }
}

template <class T, class D = decay_t<T>>
bool const id5 = is_placeholder_v<D> || is_bind_expression_v<D>;


  template <class T, enable_if_t<id5<T>>* = nullptr> \
  auto operator OP(T&& x) { \
    return bind([]<class T_>(T_&& x_) -> decltype(auto) { return OP forward<T_>(x_); }, id10<T>(x)); \
  }


  template <class T1, class T2, enable_if_t<id5<T1> || id5<T2>>* = nullptr> \
  auto operator OP(T1&& x, T2&& y) { \
    auto f = []<class T1_, class id4>(T1_&& x_, id4&& y_) -> decltype(auto) { \
      return forward<T1_>(x_) OP forward<id4>(y_); \
    }; \
    return bind(move(f), id10<T1>(x), id10<T2>(y)); \
  }

BINARY_LAMBDA(+=)
BINARY_LAMBDA(-=)
BINARY_LAMBDA(*=)
BINARY_LAMBDA(/=)
BINARY_LAMBDA(%=)
BINARY_LAMBDA(&=)
BINARY_LAMBDA(|=)
BINARY_LAMBDA(^=)
BINARY_LAMBDA(<<=)
BINARY_LAMBDA(>>=)

UNARY_LAMBDA(++)
UNARY_LAMBDA(--)

UNARY_LAMBDA(+)
UNARY_LAMBDA(-)
BINARY_LAMBDA(+)
BINARY_LAMBDA(-)
BINARY_LAMBDA(*)
BINARY_LAMBDA(/)
BINARY_LAMBDA(%)

UNARY_LAMBDA(~)
BINARY_LAMBDA(&)
BINARY_LAMBDA(|)
BINARY_LAMBDA(^)
BINARY_LAMBDA(<<)
BINARY_LAMBDA(>>)

BINARY_LAMBDA(==)
BINARY_LAMBDA(!=)
BINARY_LAMBDA(<)
BINARY_LAMBDA(>)
BINARY_LAMBDA(<=)
BINARY_LAMBDA(>=)

UNARY_LAMBDA(!)
BINARY_LAMBDA(&&)
BINARY_LAMBDA(||)




using namespace placeholders;

using i8 = signed char;
using u8 = unsigned char;
using i16 = short;
using u16 = unsigned short;
using i32 = int;
using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128;
using u128 = unsigned __int128;

template <int> struct signed_int;
template <int> struct unsigned_int;


  template <> struct signed_int<N> { using type = i
  template <> struct unsigned_int<N> { using type = u

INT_TYPE(8)
INT_TYPE(16)
INT_TYPE(32)
INT_TYPE(64)
INT_TYPE(128)



template <int N> using id3 = typename signed_int<N>::type;
template <int N> using id0 = typename unsigned_int<N>::type;

template <class T>
auto operator++(T& x, int) -> decltype(++x, T(x)) {
  T ret = x;
  ++x;
  return ret;
}

template <class T>
auto operator--(T& x, int) -> decltype(--x, T(x)) {
  T ret = x;
  --x;
  return ret;
}


  template <class T1, class T2, class T = common_type_t<T1, T2>> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(declval<T&>() OP
    T ret = T(x); \
    ret OP
    return ret; \
  }

BINARY_ARITH_OP(+)
BINARY_ARITH_OP(-)
BINARY_ARITH_OP(*)
BINARY_ARITH_OP(/)
BINARY_ARITH_OP(%)
BINARY_ARITH_OP(&)
BINARY_ARITH_OP(|)
BINARY_ARITH_OP(^)
BINARY_ARITH_OP(<<)
BINARY_ARITH_OP(>>)




  template <class T1, class T2> \
  auto operator OP(T1 const& x, T2 const& y) -> decltype(E) { \
    return E; \
  }

COMPARISON_OP(!=, !(x == y))
COMPARISON_OP(>, y < x)
COMPARISON_OP(<=, !(y < x))
COMPARISON_OP(>=, !(x < y))



namespace scan_impl {



bool scan(char& c) { return scanf(" %c", &c) != EOF; }

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c;; s += c) {
    c = char(getchar());
    if (c <= ' ') {
      ungetc(c, stdin);
      break;
    }
  }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? getchar() : c) & 15;
  while (true) {
    if (int t = getchar(); '0' <= t && t <= '9') {
      (u *= 10) += t & 15;
    } else {
      ungetc(t, stdin);
      break;
    }
  }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  return scanf(is_same_v<T, float> ? "%f" : is_same_v<T, double> ? "%lf" : "%Lf", &x) != EOF;
}



char buf[1 << 15];
char* ptr = buf;
char* last = buf;

bool scan(char& c) {
  for (;; ++ptr) {
    if (last - ptr < 64) {
      last = move(ptr, last, buf);
      ptr = buf;
      last += read(STDIN_FILENO, last, end(buf) - last - 1);
      *last = '\0';
    }
    if (ptr == last) { return false; }
    if (' ' < *ptr) {
      c = *ptr++;
      return true;
    }
  }
}

bool scan(string& s) {
  char c;
  if (!scan(c)) { return false; }
  for (s = c; ' ' < *ptr; s += c) { scan(c); }
  return true;
}

template <class T>
enable_if_t<is_integral_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  make_unsigned_t<decltype(+x)> u = (c == '-' ? *ptr++ : c) & 15;
  while ('0' <= *ptr && *ptr <= '9') { (u *= 10) += *ptr++ & 15; }
  x = T(c == '-' ? -u : u);
  return true;
}

template <class T>
enable_if_t<is_floating_point_v<T>, bool> scan(T& x) {
  char c;
  if (!scan(c)) { return false; }
  int n;
  sscanf(--ptr, is_same_v<T, float> ? "%f%n" : is_same_v<T, double> ? "%lf%n" : "%Lf%n", &x, &n);
  ptr += n;
  return true;
}



template <class R>
auto scan(R&& r) -> decltype(begin(r), end(r), true) {
  return all_of(begin(r), end(r), LIFT(scan));
}

template <class... Ts>
enable_if_t<sizeof...(Ts) != 1, bool> scan(Ts&&... xs) {
  return (... && scan(forward<Ts>(xs)));
}

}  


using scan_impl::scan;

namespace print_impl {



template <char = 0>
void print(char c) {
  if (c) { putchar(c); }
  if (c == '\n') { fflush(stdout); }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  char buf[64];
  char* ptr = to_chars(buf, end(buf), +x).ptr;
  for_each(buf, ptr, LIFT(print));
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  printf(is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}



char buf[1 << 15];
char* ptr = buf;

__attribute__((destructor)) void flush() {
  if (write(STDOUT_FILENO, buf, ptr - buf) == -1) { abort(); }
  ptr = buf;
}

template <char = 0>
void print(char c) {
  if (end(buf) - ptr < 64) { flush(); }
  if (c) { *ptr++ = c; }
}

template <char = 0, class T>
enable_if_t<is_integral_v<T>> print(T x) {
  print('\0');
  ptr = to_chars(ptr, end(buf), +x).ptr;
}

template <char = 0, class T>
enable_if_t<is_floating_point_v<T>> print(T x) {
  print('\0');
  ptr += snprintf(ptr, end(buf) - ptr, is_same_v<T, float> ? "%.6f" : is_same_v<T, double> ? "%.15f" : "%.18Lf", x);
}



template <char = 0>
void print(char const*);

template <char Sep = ' ', class R>
auto print(R&& r) -> void_t<decltype(begin(r), end(r))> {
  [[maybe_unused]] char c = '\0';
  for (auto&& e : r) {
    if constexpr (!is_same_v<decay_t<decltype(e)>, char>) { print(exchange(c, Sep)); }
    print(e);
  }
}

template <char = 0>
void print(char const* s) {
  print(string_view(s));
}

template <char Sep = ' ', class... Ts>
enable_if_t<sizeof...(Ts) != 1> print(Ts&&... xs) {
  [[maybe_unused]] char c = '\0';
  (..., (print(exchange(c, Sep)), print(forward<Ts>(xs))));
}

}  


using print_impl::print;

template <char Sep = ' ', char End = '\n', class... Ts>
void println(Ts&&... xs) {
  print<Sep>(forward<Ts>(xs)...);
  print(End);
}

template <class T, class N, class Op>
T power1(T x, N n, Op op) {
  assert(1 <= n);
  for (; ~n & 1; n >>= 1) { x = op(x, x); }
  T ret = x;
  while (n >>= 1) {
    x = op(x, x);
    if (n & 1) { ret = op(move(ret), x); }
  }
  return ret;
}

template <class T, class N>
T power(T x, N n) {
  if (n == 0) { return T{1}; }
  if (n < 0) { return T{1} / power1(move(x), -n, multiplies()); }
  return power1(move(x), n, multiplies());
}

template <class T>
T div_floor(T x, T y) {
  return T(x / y - ((x ^ y) < 0 && x % y));
}

template <class T>
T id7(T x, T y) {
  return T(x / y + (0 <= (x ^ y) && x % y));
}

template <class T, class U = T>
bool chmin(T& x, U&& y) {
  return y < x ? x = forward<U>(y), true : false;
}

template <class T, class U = T>
bool chmax(T& x, U&& y) {
  return x < y ? x = forward<U>(y), true : false;
}

template <class T>
T const inf_v = numeric_limits<T>::max() / 2;

int const inf = inf_v<int>;

mt19937_64 mt(_rdtsc());

template <class T>
T rand(T a, T b) {
  if constexpr (is_integral_v<T>) {
    return uniform_int_distribution(a, b)(mt);
  } else {
    return uniform_real_distribution(a, b)(mt);
  }
}







TC(D, class C, class R) class iter_base {
  D& derived() & { return static_cast<D&>(*this); }
  D const& derived() const& { return static_cast<D const&>(*this); }

 public:
  using iterator_category = C;
  using value_type = decay_t<R>;
  using difference_type = int;
  using pointer = void;
  using reference = R;



  R operator*() const { return derived().deref(); }
  REQUIRE(RAIT) R operator[](int n) const { return *(derived() + n); }

  D& operator++() & {
    derived().inc();
    return derived();
  }
  REQUIRE(BIT) D& operator--() & {
    derived().dec();
    return derived();
  }
  REQUIRE(RAIT) D& operator+=(int n) & {
    derived().advance(n);
    return derived();
  }
  REQUIRE(RAIT) D& operator-=(int n) & {
    derived().advance(-n);
    return derived();
  }

  REQUIRE(RAIT) friend D operator+(D const& x, int n) {
    D ret = x;
    ret += n;
    return ret;
  }
  REQUIRE(RAIT) friend D operator+(int n, D const& x) { return x + n; }
  REQUIRE(RAIT) friend D operator-(D const& x, int n) {
    D ret = x;
    ret -= n;
    return ret;
  }
  REQUIRE(RAIT) friend int operator-(D const& x, D const& y) { return y.dist_to(x); }

  friend bool operator==(D const& x, D const& y) { return x.equal(y); }
  REQUIRE(RAIT) friend bool operator<(D const& x, D const& y) { return x - y < 0; }


};

struct int_iter : iter_base<int_iter, RAIT, int> {
  int v;
  int_iter() = default;
  int_iter(int v) : v(v) {}
  int deref() const { return v; }
  bool equal(int_iter const& x) const { return v == x.v; }
  void inc() & { ++v; }
  void dec() & { --v; }
  void advance(int n) & { v += n; }
  int dist_to(int_iter const& x) const { return x.v - v; }
};

TC(R) auto sz(R&& r) -> decltype(int(size(forward<R>(r)))) { return int(size(forward<R>(r))); }

TC(R) using iter_t = decltype(begin(declval<R const&>()));
TC(R) using range_cat = typename iterator_traits<iter_t<R>>::iterator_category;
TC(R) using range_ref = typename iterator_traits<iter_t<R>>::reference;

TC() class view_base;


  class CLS : public view_base<CLS<__VA_ARGS__>> { \
    friend class CLS::view_base;

    id8(int size() const { return __VA_ARGS__; }) \
  };

TC(R, class F)
VIEW(filtered, R, F)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, BIT>, range_ref<R>> {
    filtered const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      do { ++i; } while (i != end(p->r) && !invoke(p->f, *i));
    }
    void dec() & {
      do { --i; } while (!invoke(p->f, *i));
    }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, find_if(begin(r), end(r), ref(f))}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit filtered(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) filtered(R&&, F) -> filtered<R, F>;

TC(R, class F)
VIEW(mapped, R, F)
  using ref = invoke_result_t<F const&, range_ref<R>>;

  struct iter : iter_base<iter, common_type_t<range_cat<R>, RAIT>, ref> {
    mapped const* p;
    iter_t<R> i;
    ref deref() const { return invoke(p->f, *i); }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & { ++i; }
    void dec() & { --i; }
    void advance(int n) & { i += n; }
    int dist_to(iter const& x) const { return int(x.i - i); }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit mapped(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END(sz(r))

TC(R, class F) mapped(R&&, F) -> mapped<R, F>;

TC(R)
VIEW(taken, R)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, range_ref<R>> {
    iter_t<R> i;
    int n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return n == x.n; }
    void inc() & {
      --n;
      if (n) { ++i; }
    }
  };

  R r;
  int n;

  auto b() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r);
    } else {
      return iter{{}, n ? begin(r) : end(r), n};
    }
  }
  auto e() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r) + size();
    } else {
      return iter{{}, end(r), 0};
    }
  }

 public:
  explicit taken(R&& r, int n) : r(forward<R>(r)), n(max<int>(n, 0)) { assert(0 <= n); }
VIEW_END(min(n, sz(r)))

TC(R) taken(R&&, int) -> taken<R>;

TC(R, class F)
VIEW(id1, R, F)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, range_ref<R>> {
    id1 const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      ++i;
      if (i != end(p->r) && !invoke(p->f, *i)) { i = end(p->r); }
    }
  };

  R r;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, begin(r) == end(r) || !invoke(f, *begin(r)) ? end(r) : begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit id1(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) id1(R&&, F) -> id1<R, F>;

TC(R)
VIEW(dropped, R)
  R r;
  int n;

  auto b() const {
    if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
      return begin(r) + min(n, sz(r));
    } else {
      auto ret = begin(r);
      for (int t = n; t-- && ret != end(r);) { ++ret; }
      return ret;
    }
  }
  auto e() const { return end(r); }

 public:
  explicit dropped(R&& r, int n) : r(forward<R>(r)), n(max<int>(n, 0)) { assert(0 <= n); }
VIEW_END(max(sz(r), n) - n)

TC(R) dropped(R&&, int) -> dropped<R>;

TC(R, class F)
VIEW(id2, R, F)
  R r;
  [[no_unique_address]] F f;

  auto b() const { return find_if_not(begin(r), end(r), ref(f)); }
  auto e() const { return end(r); }

 public:
  explicit id2(R&& r, F f) : r(forward<R>(r)), f(move(f)) {}
VIEW_END()

TC(R, class F) id2(R&&, F) -> id2<R, F>;

TC(R)
VIEW(reversed, R)
  R r;

  auto b() const { return make_reverse_iterator(end(r)); }
  auto e() const { return make_reverse_iterator(begin(r)); }

 public:
  explicit reversed(R&& r) : r(forward<R>(r)) {}
VIEW_END(sz(r))

TC(R) reversed(R&&) -> reversed<R>;
TC(R) reversed(reversed<R>&) -> reversed<reversed<R>&>;
TC(R) reversed(reversed<R> const&) -> reversed<reversed<R> const&>;
TC(R) reversed(reversed<R>&&) -> reversed<reversed<R>>;

TC(R)
VIEW(sliced, R)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  R r;
  int start;
  int stop;

  auto b() const { return next(begin(r), start); }
  auto e() const { return next(begin(r), stop); }

 public:
  explicit sliced(R&& r, int start, int stop) : r(forward<R>(r)) {
    int n = sz(this->r);
    if (start < 0) { start += n; }
    if (stop < 0) { stop += n; }
    this->start = clamp<int>(start, 0, n);
    this->stop = clamp(stop, this->start, n);
  }
VIEW_END(stop - start)

TC(R) sliced(R&&, int, int) -> sliced<R>;

TC(R)
VIEW(strided, R)
  struct iter : iter_base<iter, range_cat<R>, range_ref<R>> {
    strided const* p;
    iter_t<R> i;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & {
      if constexpr (is_convertible_v<range_cat<R>, RAIT>) {
        i += min(p->s, int(end(p->r) - i));
      } else {
        for (int t = p->s; t-- && i != end(p->r);) { ++i; }
      }
    }
    void dec() & {
      if (i == end(p->r)) {
        int n = sz(p->r);
        std::advance(i, (n - 1) / p->s * p->s - n);
      } else {
        std::advance(i, -p->s);
      }
    }
    void advance(int n) & {
      if (n < 0) {
        dec();
        ++n;
      }
      i += min(p->s * n, int(end(p->r) - i));
    }
    int dist_to(iter const& x) const {
      int d = int(x.i - i);
      return d < 0 ? div_floor(d, p->s) : id7(d, p->s);
    }
  };

  R r;
  int s;

  iter b() const { return {{}, this, begin(r)}; }
  iter e() const { return {{}, this, end(r)}; }

 public:
  explicit strided(R&& r, int s) : r(forward<R>(r)), s(max<int>(s, 1)) { assert(1 <= s); }
VIEW_END(id7(sz(r), s))

TC(R) strided(R&&, int) -> strided<R>;

TC(R, class T, class Op)
VIEW(scanned, R, T, Op)
  static_assert(is_convertible_v<range_cat<R>, FIT>);

  struct iter : iter_base<iter, common_type_t<range_cat<R>, FIT>, T> {
    scanned const* p;
    T v;
    iter_t<R> i;
    T deref() const { return v; }
    bool equal(iter const& x) const { return i == x.i && p == x.p; }
    void inc() & {
      if (i == end(p->r)) {
        p = nullptr;
      } else {
        v = invoke(p->op, move(v), *i);
        ++i;
      }
    }
  };

  R r;
  T init;
  [[no_unique_address]] Op op;

  iter b() const { return {{}, this, init, begin(r)}; }
  iter e() const { return {{}, nullptr, {}, end(r)}; }

 public:
  explicit scanned(R&& r, T init, Op op) : r(forward<R>(r)), init(move(init)), op(move(op)) {}
VIEW_END(sz(r) + 1)

TC(R, class T, class Op) scanned(R&&, T, Op) -> scanned<R, T, Op>;

TC(R)
VIEW(sampled, R)
  struct iter : iter_base<iter, common_type_t<range_cat<R>, IIT>, range_ref<R>> {
    iter_t<R> i;
    int rest;
    int n;
    range_ref<R> deref() const { return *i; }
    bool equal(iter const& x) const { return i == x.i; }
    void skip() & {
      while (rest && n <= rand<int>(0, --rest)) { ++i; }
      --n;
    }
    void inc() & {
      ++i;
      skip();
    }
  };

  R r;
  int n;

  iter b() const {
    iter ret{{}, begin(r), sz(r), n};
    ret.skip();
    return ret;
  }
  iter e() const { return {{}, end(r), 0, 0}; }

 public:
  explicit sampled(R&& r, int n) : r(forward<R>(r)), n(clamp<int>(n, 0, sz(this->r))) { assert(0 <= n); }
VIEW_END(min(n, sz(r)))

TC(R) sampled(R&&, int) -> sampled<R>;

TC(D) class view_base {
  D& derived() { return static_cast<D&>(*this); }
  D const& derived() const { return static_cast<D const&>(*this); }

 public:
  auto begin() { return derived().b(); }
  auto begin() const { return derived().b(); }
  auto end() { return derived().e(); }
  auto end() const { return derived().e(); }
  bool empty() const { return begin() == end(); }
  explicit operator bool() const { return begin() != end(); }
  int size() const { return int(end() - begin()); }
  decltype(auto) front() { return *begin(); }
  decltype(auto) front() const { return *begin(); }
  decltype(auto) back() { return *prev(end()); }
  decltype(auto) back() const { return *prev(end()); }
  decltype(auto) operator[](int n) { return begin()[n]; }
  decltype(auto) operator[](int n) const { return begin()[n]; }


  SIG & { return CLS(derived() id8(,) __VA_ARGS__); } \
  SIG const& { return CLS(derived() id8(,) __VA_ARGS__); } \
  SIG && { return CLS(static_cast<D&&>(*this) id8(,) __VA_ARGS__); }

  WRAP(TC(F) auto filter(F f), filtered, move(f))
  WRAP(TC(F) auto map(F f), mapped, move(f))
  WRAP(template <int N> auto elements(), mapped, LIFT(get<N>))
  WRAP(auto keys(), mapped, LIFT(get<0>))
  WRAP(auto values(), mapped, LIFT(get<1>))
  WRAP(auto take(int n), taken, n)
  WRAP(TC(F) auto take_while(F f), id1, move(f))
  WRAP(auto drop(int n), dropped, n)
  WRAP(TC(F) auto drop_while(F f), id2, move(f))
  WRAP(auto rev(), reversed)
  WRAP(auto slice(int l, int r), sliced, l, r)
  WRAP(auto stride(int s), strided, s)
  WRAP(TC(T, class Op = plus<>) auto scan(T init, Op op = {}), scanned, move(init), move(op))
  WRAP(auto sample(int n), sampled, n)




  SIG { \
    using Res = decltype(std::FN(begin(), end() id8(,) __VA_ARGS__)); \
    if constexpr (is_void_v<Res>) { \
      std::FN(begin(), end() id8(,) __VA_ARGS__); \
      return derived(); \
    } else { \
      auto res = std::FN(begin(), end() id8(,) __VA_ARGS__); \
      if constexpr (is_same_v<decltype(res), decltype(begin())>) { \
        return int(distance(begin(), move(res))); \
      } else { \
        return int(res); \
      } \
    } \
  }

  WRAP(TC(F) bool all_of(F f) const, all_of, ref(f))
  WRAP(TC(F) bool any_of(F f) const, any_of, ref(f))
  WRAP(TC(F) int count(F f) const, count_if, ref(f))
  WRAP(TC(F) int find(F f) const, find_if, ref(f))
  WRAP(TC(F) int adjacent_find(F f) const, adjacent_find, ref(f))

  WRAP(TC(F) int remove(F f), remove_if, ref(f))
  WRAP(D& reverse(), reverse)
  WRAP(D& shuffle(), shuffle, mt)
  WRAP(TC(C = equal_to<>) int unique(C comp = {}), unique, ref(comp))

  WRAP(TC(F) bool is_partitioned(F f) const, is_partitioned, ref(f))
  WRAP(TC(F) int partition(F f), partition, ref(f))
  WRAP(TC(F) int stable_partition(F f), stable_partition, ref(f))
  WRAP(TC(F) int partition_point(F f) const, partition_point, ref(f))

  WRAP(TC(C = less<>) bool is_sorted(C comp = {}) const, is_sorted, ref(comp))
  WRAP(TC(C = less<>) int is_sorted_until(C comp = {}) const, is_sorted_until, ref(comp))
  WRAP(TC(C = less<>) D& sort(C comp = {}), sort, ref(comp))
  WRAP(TC(C = less<>) D& stable_sort(C comp = {}), stable_sort, ref(comp))

  WRAP(TC(T, class C = less<>) int lower_bound(T const& val, C comp = {}) const, lower_bound, val, ref(comp))
  WRAP(TC(T, class C = less<>) int upper_bound(T const& val, C comp = {}) const, upper_bound, val, ref(comp))
  WRAP(TC(T) bool binary_search(T const& val) const, binary_search, val)

  WRAP(int min_element() const, min_element)
  WRAP(int max_element() const, max_element)

  WRAP(bool next_permutation(), next_permutation)
  WRAP(bool prev_permutation(), prev_permutation)

  WRAP(TC(T, class Op = plus<>) T fold(T init, Op op = {}) const, accumulate, move(init), ref(op))



  TC(F) D& each(F f) {
    for (auto&& e : derived()) {
      if constexpr (is_invocable_v<F&, decltype(e)>) {
        invoke(f, e);
      } else {
        invoke(f);
      }
    }
    return derived();
  }

  TC(F) auto max_right(F f) const { return *prev(std::partition_point(next(begin()), end(), ref(f))); }
  TC(F) auto min_left(F f) const { return *std::partition_point(begin(), prev(end()), not_fn(ref(f))); }

  TC(Op = plus<>)
  auto fold1(Op op = {}) const { return accumulate(next(begin()), end(), front(), ref(op)); }

  template <TC(...) class C = vector>
  auto to() const {
    return C(begin(), end());
  }

  TC(C) auto to() const { return C(begin(), end()); }
};

TC(D1, class D2) bool operator==(view_base<D1> const& x, view_base<D2> const& y) {
  return equal(begin(x), end(x), begin(y), end(y));
}

TC(D1, class D2) bool operator<(view_base<D1> const& x, view_base<D2> const& y) {
  return lexicographical_compare(begin(x), end(x), begin(y), end(y));
}

TC(R)
VIEW(all, R)
  R r;

  auto b() const { return begin(r); }
  auto e() const { return end(r); }

 public:
  explicit all(R&& r) : r(forward<R>(r)) {}
VIEW_END(sz(r))

TC(R) all(R&&) -> all<R>;
TC(T) all(initializer_list<T>) -> all<initializer_list<T>>;

TC(I)
VIEW(range, I)
  I first;
  I last;

  I b() const { return first; }
  I e() const { return last; }

 public:
  explicit range(I first, I last) : first(move(first)), last(move(last)) {}
VIEW_END()

TC(G)
VIEW(generation, G)
  using T = decay_t<invoke_result_t<G const&>>;

  struct iter : iter_base<iter, IIT, T> {
    generation const* p;
    T v;
    T deref() const { return v; }
    bool equal(iter const& x) const { return p == x.p; }
    void inc() & { v = invoke(p->gen); }
  };

  [[no_unique_address]] G gen;

  iter b() const { return {{}, this, invoke(gen)}; }
  iter e() const { return {{}, nullptr, {}}; }

 public:
  explicit generation(G gen) : gen(move(gen)) {}
VIEW_END(numeric_limits<int>::max())

TC(T) auto rand_view(T a, T b) {
  return generation([a, b] { return rand(a, b); });
}

TC(T, class F)
VIEW(iteration, T, F)
  struct iter : iter_base<iter, FIT, T> {
    iteration const* p;
    T v;
    T deref() const { return v; }
    bool equal(iter const& x) const { return p == x.p; }
    void inc() & { v = invoke(p->f, move(v)); }
  };

  T init;
  [[no_unique_address]] F f;

  iter b() const { return {{}, this, init}; }
  iter e() const { return {{}, nullptr, {}}; }

 public:
  explicit iteration(T init, F f) : init(move(init)), f(move(f)) {}
VIEW_END(numeric_limits<int>::max())









auto rep(int l, int r) { return range<int_iter>(min(l, r), r); }

auto rep(int n) { return rep(0, n); }

auto rep(int l, int r, int s) {
  assert(1 <= s);
  return iteration(l, _1 + id9(s)).take_while(_1 < id9(r));
}

auto rep1(int l, int r) { return rep(l, r + 1); }

auto rep1(int n) { return rep(1, n + 1); }

auto rep1(int l, int r, int s) {
  assert(1 <= s);
  return rep(l, r + 1, s);
}

template <int D>
auto mdrep(array<int, D> l, array<int, D> r) {
  assert(rep(D).all_of(LAMBDA(l[_1] < r[_1])));
  auto f = [l, r](auto i) {
    for (int d = D - 1; ++i[d] == r[d] && d; --d) { i[d] = l[d]; }
    return i;
  };
  return iteration(l, move(f)).take_while([r = r[0]](auto&& i) { return i[0] < r; });
}

template <int D>
auto mdrep(array<int, D> n) {
  assert(all(n).all_of(0 < _1));
  return mdrep<D>({}, n);
}

template <class T>
class vla : public view_base<vla<T>> {
  friend class vla::view_base;

  int n;
  T* a;

  T* b() { return a; }
  T const* b() const { return a; }
  T* e() { return a + n; }
  T const* e() const { return a + n; }

 public:
  vla() : n(0), a(nullptr) {}
  explicit vla(int n) : n(n), a(new T[n]) {}
  explicit vla(int n, T const& val) : vla(n) { fill_n(a, n, val); }
  explicit vla(initializer_list<T> il) : vla(sz(il)) { copy_n(il.begin(), n, a); }
  template <class R>
  explicit vla(R&& r, bool reverse = false) : vla(sz(r)) {
    if (reverse) {
      copy_n(begin(r), n, rbegin());
    } else {
      copy_n(begin(r), n, a);
    }
  }
  ~vla() { delete[] a; }

  vla(vla const& x) : vla(x.n) { copy_n(x.a, n, a); }
  vla(vla&& x) noexcept : vla() { *this = move(x); }
  vla& operator=(vla const& x) { return *this = vla(x); }
  vla& operator=(vla&& x) noexcept {
    swap(n, x.n);
    swap(a, x.a);
    return *this;
  }

  T& operator[](int i) {
    assert(0 <= i && i < n);
    return a[i];
  }
  T const& operator[](int i) const {
    assert(0 <= i && i < n);
    return a[i];
  }

  template <class U, enable_if_t<id5<U>>* = nullptr>
  auto operator[](U&& x) {
    return bind([](vla& a, int i) -> T& { return a[i]; }, ref(*this), id10<U>(x));
  }
  template <class U, enable_if_t<id5<U>>* = nullptr>
  auto operator[](U&& x) const {
    return bind([](vla const& a, int i) -> T const& { return a[i]; }, ref(*this), id10<U>(x));
  }

  auto rbegin() { return make_reverse_iterator(a + n); }
  auto rbegin() const { return make_reverse_iterator(a + n); }
  auto rend() { return make_reverse_iterator(a); }
  auto rend() const { return make_reverse_iterator(a); }
};

template <class T>
class id6 : public view_base<id6<T>> {
  friend class id6::view_base;

  template <bool Const>
  struct iter : iter_base<iter<Const>, random_access_iterator_tag, range<conditional_t<Const, T const, T>*>> {
    conditional_t<Const, id6 const, id6>* p;
    int i;
    auto deref() const { return (*p)[i]; }
    bool equal(iter const& x) const { return i == x.i; }
    void inc() & { ++i; }
    void dec() & { --i; }
    void advance(int n) & { i += n; }
    int dist_to(iter const& x) const { return x.i - i; }
  };

  vla<int> pos;
  vla<T> a;
  vector<pair<int, T>> buf;

  iter<false> b() { return {{}, this, 0}; }
  iter<true> b() const { return {{}, this, 0}; }
  iter<false> e() { return {{}, this, size()}; }
  iter<true> e() const { return {{}, this, size()}; }

 public:
  id6() = default;
  explicit id6(int n, int m = 0) : pos(n + 1, 0) { buf.reserve(pos[n] = m); }
  template <class... Rs>
  explicit id6(int n, Rs&&... rs) : pos(n + 1, 0) {
    (..., [&](auto&& r) {
      for (auto&& [i, e] : r) { ++pos[i]; }
    }(rs));
    partial_sum(pos.begin(), pos.end(), pos.begin());
    a = vla<T>(exchange(pos[n], 0));
    if (n) { rotate(pos.begin(), pos.end() - 2, pos.end()); }
    pos[0] = 0;
    (..., [&](auto&& r) {
      for (auto&& [i, e] : r) { a[pos[i + 1]++] = e; }
    }(rs));
  }

  void add(int i, T val) {
    assert(0 <= i && i < size());
    ++pos[i];
    buf.emplace_back(i, move(val));
    if (sz(buf) == pos[size()]) {
      pos[size()] = 0;
      build();
    }
  }
  void build() {
    partial_sum(pos.begin(), pos.end(), pos.begin());
    for (a = vla<T>(sz(buf)); !empty(buf); buf.pop_back()) { a[--pos[buf.back().first]] = move(buf.back().second); }
    vector<pair<int, T>>().swap(buf);
  }

  auto operator[](int i) {
    assert(0 <= i && i < size());
    return range(a.begin() + pos[i], a.begin() + pos[i + 1]);
  }
  auto operator[](int i) const {
    assert(0 <= i && i < size());
    return range(a.begin() + pos[i], a.begin() + pos[i + 1]);
  }

  int size() const { return sz(pos) - 1; }
};

}  


int main() {
  int t = 1;
  if (MULTI_CASES) { r7h::scan(t); }
  r7h::rep(t).each(r7h::main);
  assert(!r7h::scan(t));
}

namespace r7h {

void main(int) {
  int n;
  scan(n);
  vla a(n, vla(n, 0));
  for (int i : rep(n)) {
    for (int _ : rep(n)) {
      int c;
      scan(c);
      --c;
      ++a[i][c];
    }
  }
  vector<vla<int>> ans;
  ans.reserve(n * (n - 1) / 2);
  while (true) {
    int pos = a.find([](vla<int> const& ai) { return ai.any_of(1 < _1); });
    if (pos == n) { break; }
    ans.emplace_back(n);
    {
      int p = -1;
      for (int i : rep(pos, n)) {
        int j = a[i].find(1 < _1);
        p = ans.back()[i] = j < n ? j : p;
      }
      for (int i : rep(pos)) {
        int j = a[i].find(1 < _1);
        p = ans.back()[i] = j < n ? j : p;
      }
    }
    for (int i : rep(n)) {
      int j = ans.back()[i];
      --a[i][j];
      ++a[i + 1 < n ? i + 1 : 0][j];
    }
  }
  println(sz(ans) + n * (n - 1) / 2);
  for (auto&& e : ans) { println(e.map(_1 + 1)); }
  for (int i : rep(n)) {
    for (int j : rep1(i).rev()) { println(rep(j, j + n).map(_1 % n + 1)); }
  }
}

}  

