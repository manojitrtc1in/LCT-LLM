



#include <algorithm>
#include <istream>
#include <ostream>
#include <type_traits>
#include <tuple>
#include <utility>
#include <vector>
namespace impyster {
namespace internal {
template<class T>
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;
template<class T>
struct unref_tuple {
  using type = T;
};
template<class...Ts>
struct unref_tuple<std::tuple<Ts...>> {
  using type = std::tuple<typename unref_tuple<remove_cvref_t<Ts>>::type...>;
};
template<class T>
using unref_tuple_t = typename unref_tuple<T>::type;
template<class T>
struct is_already_inputable : public std::false_type {};
template<>
struct is_already_inputable<std::string> : public std::true_type {};
template<class T>
constexpr bool is_already_inputable_v = is_already_inputable<T>::value;
template<class T>
struct is_already_outputable : std::false_type {};
template<>
struct is_already_outputable<std::string> : std::true_type {};
template<class T>
constexpr bool is_already_outputable_v = is_already_outputable<T>::value;
template<class T, class = void>
struct is_iterable : std::false_type {};
template<class T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template<class T>
constexpr bool is_iterable_v = is_iterable<T>::value;
template<int I, class...Ts>
void read_tuple(std::istream &is, std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    is >> std::get<I>(t);
    read_tuple<I+1>(is, t);
  }
}
template<int I, class...Ts>
void read_tuple(std::istream &is, const std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    is >> std::get<I>(t);
    read_tuple<I+1>(is, t);
  }
}
template<int I, class...Ts>
void print_tuple(std::ostream &os, const std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    if constexpr (I)
      os << ' ';
    os << std::get<I>(t);
    print_tuple<I+1>(os, t);
  }
}
} 

template<class T, class = std::enable_if_t<
internal::is_iterable_v<T> && !internal::is_already_inputable_v<internal::remove_cvref_t<T>>>>
std::istream &operator>>(std::istream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class T, class = std::enable_if_t<
internal::is_iterable_v<T> && !internal::is_already_outputable_v<internal::remove_cvref_t<T>>>>
std::ostream &operator<<(std::ostream &os, T &&container) {
  for (auto &&v : container)
    os << v << ' ';
  return os;
}
template<class...Ts>
std::istream &operator>>(std::istream &is, std::tuple<Ts...> &t) {
  internal::read_tuple<0>(is, t);
  return is;
}
template<class...Ts>
std::istream &operator>>(std::istream &is, const std::tuple<Ts...> &t) {
  internal::read_tuple<0>(is, t);
  return is;
}
template<class...Ts>
std::ostream &operator<<(std::ostream &os, const std::tuple<Ts...> &t) {
  internal::print_tuple<0>(os, t);
  return os;
}
template<class T, class U>
std::istream &operator>>(std::istream &is, std::pair<T, U> &p) {
  return is >> std::tie(p.first, p.second);
}
template<class T, class U>
std::ostream &operator<<(std::ostream &os, std::pair<T, U> &p) {
  return os << std::tie(p.first, p.second);
}
struct unref_tuple {
  template<class...Args>
  auto operator()(const std::tuple<Args...> &t) const {
    return std::tuple<std::remove_reference_t<Args>...>(t);
  }
};
template<class T>
auto make_vec(T &&iterable) {
  using value_type = internal::remove_cvref_t<decltype(*std::declval<T>().begin())>;
  return std::vector<internal::unref_tuple_t<value_type>>(iterable.begin(), iterable.end());
}
template<class...Args>
auto tie_or_copy(Args&&...args) {
  return std::tuple<Args...>(std::forward<Args>(args)...);
}
template<class T>
auto sort(T &c) {
  return std::sort(c.begin(), c.end());
}
template<class T, class F>
auto sort(T &c, F f) {
  return std::sort(c.begin(), c.end(), std::forward<F>(f));
}
} 







#include <cassert>
#include <iterator>
namespace impyster {
template<class T>
T round_away_from_zero_to_multiple(T val, T div) {
  if (val < 0) return -round_away_from_zero_to_multiple(-val, div);
  if (div < 0) return round_away_from_zero_to_multiple(val, -div);
  return (val + div - 1) / div * div;
}
template<class T>
class range {
  public:
    range(T start, T stop, T step)
      : start_(start), stop_(wrong_direction(start, stop, step) ? start : stop), step_(step) {}
    range(T start, T stop)
      : range(start, stop, 1) {}
    range(T stop)
      : range(0, stop) {}
    class iterator : public std::iterator<std::input_iterator_tag, T> {
      public:
        iterator() : range_(0), current_(0) {}
        iterator(const range * r, T current) : range_(r), current_(current) {}
        T operator*() const {
          return current_;
        }
        friend bool operator!=(const iterator &l, const iterator &r) {
          return l.current_ != r.current_;
        }
        friend bool operator==(const iterator &l, const iterator &r) {
          return l.current_ == r.current_;
        }
        auto &operator++() {
          current_ += range_->step_;
          return *this;
        }
        auto operator++(int) {
          auto cpy = this;
          current_ += range_->step_;
          return cpy;
        }
      private:
        const range * range_;
        T current_;
    };
    auto begin() const {
      return iterator(this, start_);
    }
    auto end() const {
      return iterator(this, start_ + round_away_from_zero_to_multiple(stop_-start_, step_));
    }
  private:
    static bool wrong_direction(T start, T stop, T step) {
      if (start < stop && step < 0) return true;
      if (start > stop && step > 0) return true;
      return false;
    }
    const T start_, stop_, step_;
};
} 





#include <iterator>
#include <tuple>
#include <utility>
namespace impyster {
namespace internal {
template<class T>
class zip_impl {
  private:
    T iterables_;
    using all_indices = decltype(std::make_index_sequence<std::tuple_size_v<T>>());
    using eat = int[];
    template<std::size_t...indices>
    auto begin_impl(std::integer_sequence<std::size_t, indices...>) const {
      return std::make_tuple(std::get<indices>(iterables_).begin()...);
    }
    template<std::size_t...indices>
    auto end_impl(std::integer_sequence<std::size_t, indices...>) const {
      return std::make_tuple(std::get<indices>(iterables_).end()...);
    }
    template<std::size_t...indices>
    auto get_iter_value(std::integer_sequence<std::size_t, indices...> seq) const {
      return tie_or_copy(*std::get<indices>(begin_impl(seq))...);
    }
  public:
    zip_impl(T iterables)
      : iterables_(std::move(iterables)) {}
    class iterator
      : public std::iterator<std::input_iterator_tag,
          decltype(std::declval<zip_impl>().get_iter_value(all_indices{}))> {
      public:
        iterator() {}
        template<class U>
        iterator(U iterators) : iterators_(std::move(iterators)) {}
        auto operator*() {
          return deref_impl(all_indices{});
        }
        auto operator*() const {
          return deref_impl(all_indices{});
        }
        friend auto operator!=(const iterator &l, const iterator &r) {
          return neq_impl(l, r, all_indices{});
        }
        friend auto operator==(const iterator &l, const iterator &r) {
          return !neq_impl(l, r, all_indices{});
        }
        auto &operator++() {
          incr_impl(all_indices{});
          return *this;
        }
        auto operator++(int) {
          auto cpy = *this;
          incr_impl(all_indices{});
          return cpy;
        }
      private:
        decltype(std::declval<zip_impl>().begin_impl(all_indices{})) iterators_;
        template<std::size_t...indices>
        auto deref_impl(std::integer_sequence<std::size_t, indices...>) {
          return tie_or_copy(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        auto deref_impl(std::integer_sequence<std::size_t, indices...>) const {
          return tie_or_copy(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        void incr_impl(std::integer_sequence<std::size_t, indices...>) {
          std::ignore = eat{(++std::get<indices>(iterators_), 0)...};
        }
        template<std::size_t...indices>
        static bool neq_impl(const iterator &l, const iterator &r,
            std::integer_sequence<std::size_t, indices...>) {
          return (true && ... && (std::get<indices>(l.iterators_) != std::get<indices>(r.iterators_)));
        }
    };
    auto begin() const {
      return iterator(begin_impl(all_indices{}));
    }
    auto end() const {
      return iterator(end_impl(all_indices{}));
    }
};
} 

template<class...Args>
auto zip(Args&&...args) {
  return internal::zip_impl(tie_or_copy(std::forward<Args>(args)...));
}
} 



#include <limits>
namespace impyster {
template<class T>
auto enumerate(T &&iterable) {
  return zip(
    range(std::numeric_limits<long long>::max()/2),
    std::forward<T>(iterable)
  );
}
template<class T>
auto enumerate_after(T &&iterable) {
  return zip(
    std::forward<T>(iterable),
    range(std::numeric_limits<long long>::max()/2)
  );
}
} 





namespace impyster {
namespace internal {
template<class F, class T>
class map_impl {
 private:
  F func_;
  T iterable_;
 public:
  map_impl(F &&func, T &&iterable)
    : func_(func), iterable_(std::forward<T>(iterable)) {}
  using inner_iterator = decltype(iterable_.begin());
  struct iterator : public inner_iterator {
    F *func_ = nullptr;
    auto operator*() {
      return (*func_)(inner_iterator::operator*());
    }
  };
  auto begin() {
    iterator it{iterable_.begin()};
    it.func_ = &func_;
    return it;
  }
  auto end() {
    iterator it{iterable_.end()};
    it.func_ = &func_;
    return it;
  }
};
} 

template<class F, class...Ts>
auto map(F &&func, Ts&&...iterables) {
  static_assert(sizeof...(Ts));
  if constexpr (sizeof...(Ts) == 1)
    return internal::map_impl(std::forward<F>(func), std::forward<Ts>(iterables)...);
  else
    return internal::map_impl(
      [f=std::forward<F>(func)](auto t) { return std::apply(f, t); },
      zip(std::forward<Ts>(iterables)...)
    );
}
} 





#include <iostream>
#include <ostream>
#include <string>
#include <tuple>
namespace impyster {
namespace internal {
template<class T>
class print_impl {
  public:
    print_impl(std::ostream &os, T args)
      : os_(os), args_(std::move(args)), sep_(" "), end_("\n") {}
    ~print_impl() {
      print_tail<0>();
      os_ << end_;
    }
    template<class S>
    void sep(S &&new_sep) {
      sep_ = std::forward<S>(new_sep);
    }
    template<class S>
    void end(S &&new_end) {
      end_ = std::forward<S>(new_end);
    }
  private:
    template<int I>
    void print_tail() {
      if constexpr (I < std::tuple_size_v<T>) {
        if constexpr (I)
          os_ << sep_;
        os_ << std::get<I>(args_);
        print_tail<I+1>();
      }
    }
    std::ostream &os_;
    T args_;
    std::string sep_, end_;
};
struct print_impl_noop {
  template<class S> void sep(S &&) {}
  template<class S> void end(S &&) {}
};
} 

template<class...Args>
auto print(Args&&...args) {
  return internal::print_impl(std::cout, tie_or_copy(std::forward<Args>(args)...));
}
template<class...Args>
auto dbg(Args&&...args) {
#ifdef ENABLE_DEBUG
  return internal::print_impl(std::cerr, tie_or_copy(std::forward<Args>(args)...));
#else
  std::ignore = std::tie(args...);
  return internal::print_impl_noop{};
#endif
}
} 







#include <cassert>
#include <type_traits>
#include <vector>
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
      while (it != end(s))
        st.values[st.offset + k++] = *it++;
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
    auto [s, j] = walk_pre_impl(i, cond, {}, 1, 0, offset-1);
    return {s, std::min(j, n-1)};
  }
  template<class Cond>
  std::pair<S, int> walk_suf(int j, const Cond &cond) {
    return walk_suf_impl(j, cond, {}, 1, 0, offset-1);
  }
  template<class Cond>
  std::pair<S, int> walk_pre_impl(int i, const Cond &cond, S pre, int I, int l, int r) {
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
      auto [lv, l_after] = walk_pre_impl(i, cond, pre, 2*I, l, mid-1);
      if (l_after != mid-1) return {lv, l_after};
      return walk_pre_impl(i, cond, lv, 2*I+1, mid, r);
    }
    return walk_pre_impl(i, cond, pre, 2*I+1, mid, r);
  }
  template<class Cond>
  std::pair<S, int> walk_suf_impl(int j, const Cond &cond, S suf, int I, int l, int r) {
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
      auto [rv, r_first] = walk_suf_impl(j, cond, suf, 2*I+1, mid, r);
      if (r_first != mid) return {rv, r_first};
      return walk_suf_impl(j, cond, rv, 2*I, l, mid-1);
    }
    return walk_suf_impl(j, cond, suf, 2*I, l, mid-1);
  }
};




#include <istream>
#include <ostream>
template<typename T>
struct modnum {
  using Int = typename T::type;
  using Int2 = typename T::prod_type;
  Int val;
  modnum() = default;
  modnum(const Int2 &_val) : val(Int((_val%T::MOD+T::MOD)%T::MOD)) {}
  modnum &operator++() { if (++val == T::MOD) val = 0; return *this; }
  modnum &operator--() { if (val-- == 0) val += T::MOD; return *this; }
  modnum &operator++(int) { auto ret = *this; ++*this; return ret; }
  modnum &operator--(int) { auto ret = *this; --*this; return ret; }
  modnum &operator+=(const modnum &o) { if ((val += o.val) >= T::MOD) val -= T::MOD; return *this; }
  modnum &operator-=(const modnum &o) { if ((val -= o.val) < 0) val += T::MOD; return *this; }
  modnum &operator*=(const modnum &o) { val = Int((Int2)val*o.val%T::MOD); return *this; }
  modnum &operator/=(const modnum &o) { *this *= o.inv(); return *this; }
  friend modnum operator+(const modnum &a, const modnum &b) { auto ret = a; return ret += b; }
  friend modnum operator-(const modnum &a, const modnum &b) { auto ret = a; return ret -= b; }
  friend modnum operator*(const modnum &a, const modnum &b) { auto ret = a; return ret *= b; }
  friend modnum operator/(const modnum &a, const modnum &b) { auto ret = a; return ret /= b; }
  friend bool operator==(const modnum &a, const modnum &b) { return a.val == b.val; }
  friend bool operator!=(const modnum &a, const modnum &b) { return a.val != b.val; }
  modnum pow(long long e) const {
    modnum b = *this, a = 1;
    while (e) {
      if (e&1) a *= b;
      b *= b;
      e >>= 1;
    }
    return a;
  }
  modnum inv() const { return pow(T::MOD-2); }
  friend std::istream &operator>>(std::istream &is, modnum &x) { Int v; is >> v; x = v; return is; }
  friend std::ostream &operator<<(std::ostream &os, const modnum &x) { return os << x.val; }
};
template<long long M>
struct static_mod_t {
  using type = int;
  using prod_type = long long;
  static constexpr type MOD = M;
};
template<int ID>
struct var_mod_t {
  using type = long long;
  using prod_type = __int128_t;
  static type MOD;
};
template<int ID>
typename var_mod_t<ID>::type var_mod_t<ID>::MOD = 1;
template<int MOD = (int)1e9+7>
using static_mint = modnum<static_mod_t<MOD>>;
template<int ID = 0>
using var_mint = modnum<var_mod_t<ID>>;




#include <random>
#include <chrono>
std::mt19937 rng(std::chrono::steady_clock::now().time_since_epoch().count());
struct r_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  uint64_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM = rng();
    return splitmix64(x + FIXED_RANDOM);
  }
};


 
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
 
using namespace impyster;


using mint = static_mint<998244353>;
 
const int mxV = (int)2e5+1;
 
mint fac[mxV], ifac[mxV];
 
mint C(int n, int k) {
  if (0 > k) return 0;
  if (k > n) return 0;
 
  return fac[n] * ifac[k] * ifac[n-k];
}

struct S {
  mint s = 0;
  void pull(S l, S r) {
    s = l.s + r.s;
  }
};

int brute(std::vector<int> a, const std::vector<int> &b) {
  int ans = 0;
  sort(a);
  do {
    ans += a < b;
  } while (std::next_permutation(a.begin(), a.end()));
  return ans;
}
 
int main() {
  std::cin.tie(0)->sync_with_stdio(0);
 
  int n, m;
  std::cin >> n >> m; 
 
  std::vector<int> s(n), t(m);
  std::cin >> s >> t; 
 
  std::vector<int> suf_cnt(mxV);
  for (int x : s)
    ++suf_cnt[x];
  std::vector<int> pre_cnt(mxV);
 
  fac[0] = ifac[0] = 1;
  for (int i : range(1, mxV)) {
    fac[i] = fac[i-1] * i;
    ifac[i] = 1 / fac[i];
  }
 
  mint ans = 0;
 
  SegTree st(mxV, S{});
  for (int x : s) {
    mint was = st(x)->s;
    st(x) = {(was+1)};
  }
 
  mint pre_ways = 1;
 
  for (int i : range(std::min(n, m))) {
    int v = t[i];
    
    {
      mint suf_ways = fac[n-i-1];
      mint pick_ways = st(0, v-1)->s;
      dbg(pre_ways, suf_ways, pick_ways);
      ans += pre_ways * suf_ways * pick_ways;
    }

    if (!suf_cnt[v]) {
      pre_ways = 0;
      break;
    }

    pre_ways *= ifac[pre_cnt[v]+suf_cnt[v]] * fac[suf_cnt[v]];
    --suf_cnt[v];
    ++pre_cnt[v];
    pre_ways *= fac[pre_cnt[v]+suf_cnt[v]] * ifac[suf_cnt[v]];

    {
      mint pick_ways = suf_cnt[v];
      st(v) = {pick_ways};
    }
  }

  if (n < m) {
    dbg(pre_ways);
    ans += pre_ways;
  }

  std::vector<int> scnt(mxV);
  for (int x : s)
    ++scnt[x];
  for (int cnt : scnt)
    ans *= ifac[cnt];

#ifdef ENABLE_DEBUG
  int bans = brute(s, t);

  dbg(ans, bans);
  assert(ans == bans);
#endif

  print(ans);
}
