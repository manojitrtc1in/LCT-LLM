









template<class S, class F = std::nullptr_t>
struct SegTree {
  template<class T>
  struct check_beats {
    struct c1 { char x[1]; };
    struct c2 { char x[2]; };
    template <typename C> static c1 test(decltype(&C::can_lazy)) ;
    template <typename C> static c2 test(...);    
    enum { value = sizeof(test<T>(0)) == sizeof(c1) };
  };
  static constexpr bool is_lazy = !std::is_same<F, std::nullptr_t>::value;
  static constexpr bool is_beats = check_beats<F>::value;
  int n, offset;
  std::vector<S> values;
  std::vector<F> lazy;
  SegTree() {}
  SegTree(int n_) : n(n_), offset(2<<std::__lg(n-1)) {
    values.resize(2*offset);
    if constexpr (is_lazy) lazy.resize(offset);
  }
  SegTree(int n_, S) : SegTree(n_) {}
  SegTree(int n_, S, F) : SegTree(n_) {}
  struct RangeReference {
    SegTree &st;
    const int i, j;
    RangeReference(SegTree &st_, int i_, int j_) : st(st_), i(i_), j(j_) {}
    template<typename Container>
    auto &operator=(const Container &s) {
      if constexpr (is_lazy) st.push_all(i, j, 1, 0, st.offset-1);
      int k = i;
      auto it = begin(s);
      while (it != end(s)) {
        if constexpr (std::is_same_v<const std::remove_reference_t<decltype(*it)>, const S>)
          st.values[st.offset + k++] = *it++;
        else
          st.values[st.offset + k++] = {*it++};
      }
      assert(k == j+1);
      int I = i+st.offset, J = j+st.offset;
      while ((I /= 2) && (J /= 2))
        for (k = I; k <= J; ++k)
          st.values[k].pull(st.values[2*k], st.values[2*k+1]);
      return *this;
    }
    auto &operator=(S s) {
      if constexpr (is_lazy) st.push_all(i, j, 1, 0, st.offset-1);
      for (int k = i; k <= j; ++k)
        st.values[st.offset+k] = s;
      int I = i+st.offset, J = j+st.offset;
      while ((I /= 2) && (J /= 2))
        for (int k = I; k <= J; ++k)
          st.values[k].pull(st.values[2*k], st.values[2*k+1]);
      return *this;
    }
    auto &operator*=(F f) {
      static_assert(is_lazy);
      st.upd(i, j, f, 1, 0, st.offset-1);
      return *this;
    }
    S operator*() {
      return st.qry(i, j, 1, 0, st.offset-1);
    }
    struct SHolder {
      S value;
      S *operator->() {
        return &value;
      }
    };
    auto operator->() {
      return SHolder{**this};
    }
  };
  auto operator()(int i) {
    return RangeReference(*this, i, i);
  }
  auto operator()(int i, int j) {
    return RangeReference(*this, i, j);
  }
  int push(int I, int l, int r) {
    static_assert(is_lazy);
    assert(I > 0);
    assert(I < offset);
    lazy[I].apply(values[2*I]);
    lazy[I].apply(values[2*I+1]);
    if (2*I < offset) {
      lazy[I].apply(lazy[2*I]);
      lazy[I].apply(lazy[2*I+1]);
    }
    lazy[I] = F();
    return l + (r-l+1)/2;
  }
  void push_all(int i, int j, int I, int l, int r) {
    static_assert(is_lazy);
    if (l == r) return;
    int mid = push(I, l, r);
    if (i < mid) push_all(i, j, 2*I, l, mid-1);
    if (j >= mid) push_all(i, j, 2*I+1, mid, r);
  }
  S qry(int i, int j, int I, int l, int r) {
    if (i > j) return {};
    assert(!(i > r || j < l));
    if (i <= l && j >= r) return values[I];
    int mid;
    if constexpr (is_lazy) mid = push(I, l, r);
    else mid = l + (r-l+1)/2;
    S res; res.pull(
        (i < mid ? qry(i, j, 2*I, l, mid-1) : S()),
        (j >= mid ? qry(i, j, 2*I+1, mid, r) : S())
    );
    return res;
  }
  static bool can_lazy(F &f, S &s) {
    if constexpr (is_beats)
      return f.can_lazy(s);
    return true;
  }
  void upd(int i, int j, F f, int I, int l, int r) {
    static_assert(is_lazy);
    assert(!(i > r || j < l));
    if (i <= l && j >= r && can_lazy(f, values[I])) {
      f.apply(values[I]);
      if (I < offset)
        f.apply(lazy[I]);
      return;
    }
    assert(l != r);
    int mid = push(I, l, r);
    if (i < mid) upd(i, j, f, 2*I, l, mid-1);
    if (j >= mid) upd(i, j, f, 2*I+1, mid, r);
    values[I].pull(values[2*I], values[2*I+1]);
  }
  template<class Cond>
  std::pair<S, int> walk_pre(int i, const Cond &cond) {
    auto [s, j] = id8(i, cond, {}, 1, 0, offset-1);
    return {s, std::min(j, n-1)};
  }
  template<class Cond>
  std::pair<S, int> id1(int j, const Cond &cond) {
    return id3(j, cond, {}, 1, 0, offset-1);
  }
  template<class Cond>
  std::pair<S, int> id8(int i, const Cond &cond, S pre, int I, int l, int r) {
    assert(i <= r);
    if (i <= l) {
      S s;
      s.pull(pre, values[I]);
      if (cond(s))
        return {s, r};
      if (l == r)
        return {pre, l-1};
    }
    int mid;
    if constexpr (is_lazy) mid = push(I, l, r);
    else mid = l + (r-l+1)/2;
    if (i < mid) {
      auto [lv, l_after] = id8(i, cond, pre, 2*I, l, mid-1);
      if (l_after != mid-1) return {lv, l_after};
      return id8(i, cond, lv, 2*I+1, mid, r);
    }
    return id8(i, cond, pre, 2*I+1, mid, r);
  }
  template<class Cond>
  std::pair<S, int> id3(int j, const Cond &cond, S suf, int I, int l, int r) {
    assert(j >= l);
    if (j >= r) {
      S s;
      s.pull(values[I], suf);
      if (cond(s))
        return {s, l};
      if (l == r)
        return {suf, r+1};
    }
    int mid;
    if constexpr (is_lazy) mid = push(I, l, r);
    else mid = l + (r-l+1)/2;
    if (j >= mid) {
      auto [rv, r_first] = id3(j, cond, suf, 2*I+1, mid, r);
      if (r_first != mid) return {rv, r_first};
      return id3(j, cond, rv, 2*I, l, mid-1);
    }
    return id3(j, cond, suf, 2*I, l, mid-1);
  }
};







using i8 = int8_t;
using u8 = uint8_t;
using i16 = int16_t;
using u16 = uint16_t;
using i32 = int32_t;
using u32 = uint32_t;
using i64 = int64_t;
using u64 = uint64_t;
using i128 = __int128_t;
using u128 = __uint128_t;




std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct r_hash {
  static u64 splitmix64(u64 x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  template<class T>
  u64 operator()(const T &x) const;
  u64 operator()(u64 x) const {
    static const u64 id5 = rng();
    return splitmix64(x + id5);
  }
};

template<class...Ts>
struct overloaded : Ts... { using Ts::operator()...; };
template<class... Ts>
overloaded(Ts...) -> overloaded<Ts...>;

template<class Fun>
class id4 {
	Fun fun_;
public:
	template<class T>
	explicit id4(T &&fun): fun_(std::forward<T>(fun)) {}
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
template<class Fun>
decltype(auto) id6(Fun &&fun) {
	return id4<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;








struct IOPre {
  static constexpr int TEN = 10, SZ = TEN * TEN * TEN * TEN;
  std::array<char, 4 * SZ> num;
  constexpr IOPre() : num{} {
    for (int i = 0; i < SZ; i++) {
      int n = i;
      for (int j = 3; j >= 0; j--) {
        num[i * 4 + j] = static_cast<char>(n % TEN + '0');
        n /= TEN;
      }
    }
  }
};
struct IO {






  static constexpr int SZ = 1 << 17, LEN = 32, TEN = 10, HUNDRED = TEN * TEN,
                       THOUSAND = HUNDRED * TEN, id9 = THOUSAND * TEN,
                       MAGIC_MULTIPLY = 205, MAGIC_SHIFT = 11, MASK = 15,
                       id0 = 12, SIXTEEN = 16;
  static constexpr IOPre io_pre = {};
  std::array<char, SZ> input_buffer, output_buffer;
  int id2, id11, id7;
  IO()
      : input_buffer{},
        output_buffer{},
        id2{},
        id11{},
        id7{} {}
  IO(const IO&) = delete;
  IO(IO&&) = delete;
  IO& operator=(const IO&) = delete;
  IO& operator=(IO&&) = delete;
  ~IO() { flush(); }
  template <class T>
  struct is_char {
    static constexpr bool value = std::is_same_v<T, char>;
  };
  template <class T>
  struct is_bool {
    static constexpr bool value = std::is_same_v<T, bool>;
  };
  template <class T>
  struct is_string {
    static constexpr bool value =
        std::is_same_v<T, std::string> || std::is_same_v<T, const char*> ||
        std::is_same_v<T, char*> || std::is_same_v<std::decay_t<T>, char*>;
    ;
  };
  template <class T, class D = void>
  struct is_custom {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_custom<T, std::void_t<typename T::internal_value_type>> {
    static constexpr bool value = true;
  };
  template <class T>
  struct is_default {
    static constexpr bool value = is_char<T>::value || is_bool<T>::value ||
                                  is_string<T>::value || std::is_integral_v<T>;
  };
  template <class T, class D = void>
  struct is_iterable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_iterable<
      T, typename std::void_t<decltype(std::begin(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T, class D = void, class E = void>
  struct is_applyable {
    static constexpr bool value = false;
  };
  template <class T>
  struct is_applyable<T, std::void_t<typename std::tuple_size<T>::type>,
                      std::void_t<decltype(std::get<0>(std::declval<T>()))>> {
    static constexpr bool value = true;
  };
  template <class T>
  static constexpr bool id10 = (is_iterable<T>::value ||
                                         is_applyable<T>::value) &&
                                        (!is_default<T>::value);
  template <typename T, typename U>
  struct any_needs_newline {
    static constexpr bool value = false;
  };
  template <typename T>
  struct any_needs_newline<T, std::index_sequence<>> {
    static constexpr bool value = false;
  };
  template <typename T, std::size_t I, std::size_t... Is>
  struct any_needs_newline<T, std::index_sequence<I, Is...>> {
    static constexpr bool value =
        id10<decltype(std::get<I>(std::declval<T>()))> ||
        any_needs_newline<T, std::index_sequence<Is...>>::value;
  };
  inline void load() {
    memmove(std::begin(input_buffer), std::begin(input_buffer) + id2,
            id11 - id2);
    id11 =
        id11 - id2 +
        static_cast<int>(fread_unlocked(
            std::begin(input_buffer) + id11 - id2, 1,
            SZ - id11 + id2, stdin));
    id2 = 0;
  }
  inline void read_char(char& c) {
    if (id2 + LEN > id11) load();
    c = input_buffer[id2++];
  }
  inline void read_string(std::string& x) {
    char c;
    while (read_char(c), c < '!') continue;
    x = c;
    while (read_char(c), c >= '!') x += c;
  }
  template <class T>
  inline std::enable_if_t<std::is_integral_v<T>, void> read_int(T& x) {
    if (id2 + LEN > id11) load();
    char c = 0;
    do c = input_buffer[id2++];
    while (c < '-');
    [[maybe_unused]] bool minus = false;
    if constexpr (std::is_signed<T>::value == true)
      if (c == '-') minus = true, c = input_buffer[id2++];
    x = 0;
    while (c >= '0')
      x = x * TEN + (c & MASK), c = input_buffer[id2++];
    if constexpr (std::is_signed<T>::value == true)
      if (minus) x = -x;
  }
  inline void skip_space() {
    if (id2 + LEN > id11) load();
    while (input_buffer[id2] <= ' ') id2++;
  }
  inline void flush() {
    fwrite_unlocked(std::begin(output_buffer), 1, id7, stdout);
    id7 = 0;
  }
  inline void write_char(char c) {
    if (id7 > SZ - LEN) flush();
    output_buffer[id7++] = c;
  }
  inline void write_bool(bool b) {
    if (id7 > SZ - LEN) flush();
    output_buffer[id7++] = b ? '1' : '0';
  }
  inline void write_string(const std::string& s) {
    for (auto x : s) write_char(x);
  }
  inline void write_string(const char* s) {
    while (*s) write_char(*s++);
  }
  inline void write_string(char* s) {
    while (*s) write_char(*s++);
  }
  template <typename T>
  inline std::enable_if_t<std::is_integral_v<T>, void> write_int(T x) {
    if (id7 > SZ - LEN) flush();
    if (!x) {
      output_buffer[id7++] = '0';
      return;
    }
    if constexpr (std::is_signed<T>::value == true)
      if (x < 0) output_buffer[id7++] = '-', x = -x;
    int i = id0;
    std::array<char, SIXTEEN> buf{};
    while (x >= id9) {
      memcpy(std::begin(buf) + i,
             std::begin(io_pre.num) + (x % id9) * 4, 4);
      x /= id9;
      i -= 4;
    }
    if (x < HUNDRED) {
      if (x < TEN) {
        output_buffer[id7++] = static_cast<char>('0' + x);
      } else {
        std::uint32_t q =
            (static_cast<std::uint32_t>(x) * MAGIC_MULTIPLY) >> MAGIC_SHIFT;
        std::uint32_t r = static_cast<std::uint32_t>(x) - q * TEN;
        output_buffer[id7] = static_cast<char>('0' + q);
        output_buffer[id7 + 1] = static_cast<char>('0' + r);
        id7 += 2;
      }
    } else {
      if (x < THOUSAND) {
        memcpy(std::begin(output_buffer) + id7,
               std::begin(io_pre.num) + (x << 2) + 1, 3),
            id7 += 3;
      } else {
        memcpy(std::begin(output_buffer) + id7,
               std::begin(io_pre.num) + (x << 2), 4),
            id7 += 4;
      }
    }
    memcpy(std::begin(output_buffer) + id7,
           std::begin(buf) + i + 4, id0 - i);
    id7 += id0 - i;
  }
  template <typename T_>
  IO& operator<<(T_&& x) {
    using T =
        typename std::remove_cv<typename std::remove_reference<T_>::type>::type;
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    if constexpr (is_custom<T>::value) {
      write_int(x.get());
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_bool<T>::value) {
        write_bool(x);
      } else if constexpr (is_string<T>::value) {
        write_string(x);
      } else if constexpr (is_char<T>::value) {
        write_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        write_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      using E = decltype(*std::begin(x));
      constexpr char sep = id10<E> ? '\n' : ' ';
      int i = 0;
      for (const auto& y : x) {
        if (i++) write_char(sep);
        operator<<(y);
      }
    } else if constexpr (is_applyable<T>::value) {
      constexpr char sep =
          (any_needs_newline<
              T, std::make_index_sequence<std::tuple_size_v<T>>>::value)
              ? '\n'
              : ' ';
      int i = 0;
      std::apply(
          [this, &sep, &i](auto const&... y) {
            (((i++ ? write_char(sep) : void()), this->operator<<(y)), ...);
          },
          x);
    }
    return *this;
  }
  template <typename T>
  IO& operator>>(T& x) {
    static_assert(is_custom<T>::value or is_default<T>::value or
                  is_iterable<T>::value or is_applyable<T>::value);
    static_assert(!is_bool<T>::value);
    if constexpr (is_custom<T>::value) {
      typename T::internal_value_type y;
      read_int(y);
      x = y;
    } else if constexpr (is_default<T>::value) {
      if constexpr (is_string<T>::value) {
        read_string(x);
      } else if constexpr (is_char<T>::value) {
        read_char(x);
      } else if constexpr (std::is_integral_v<T>) {
        read_int(x);
      }
    } else if constexpr (is_iterable<T>::value) {
      for (auto& y : x) operator>>(y);
    } else if constexpr (is_applyable<T>::value) {
      std::apply([this](auto&... y) { ((this->operator>>(y)), ...); }, x);
    }
    return *this;
  }
  IO* tie(std::nullptr_t) { return this; }
  void sync_with_stdio(bool) {}
};
namespace std {
IO io;
}  






using namespace std;
using std::cerr;
using std::cin;
using std::cout;

constexpr int BITS = 32;

struct S {
  array<u32, BITS> h{};
  S() { h.fill(0); }
  S(int x) {
    u64 w = r_hash{}(u64(x));
    for (u32 &c : h) {
      c = w & 1;
      w >>= 1;
    }
  }

  void pull(const S &l, const S &r) {
    for (int i = 0; i < BITS; ++i) h[i] = l.h[i] + r.h[i];
  }
};

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  SegTree st(n, S{});
  {
    vector<int> a(n);
    for (int &x : a) cin >> x;
    st(0, n - 1) = a;
  }

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int i, x;
      cin >> i >> x;
      --i;
      st(i) = {x};
    } else if (t == 2) {
      int l, r, k;
      cin >> l >> r >> k;
      --l, --r;
      bool ok = true;
      auto h = st(l, r)->h;
      for (u32 c : h) ok &= c % k == 0;
      cout << (ok ? "YES" : "NO") << '\n';
    }
  }
}
