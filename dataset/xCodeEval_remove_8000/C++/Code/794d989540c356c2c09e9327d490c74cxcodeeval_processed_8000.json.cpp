
















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
constexpr bool id9 = is_already_inputable<T>::value;
template<class T>
struct is_already_outputable : std::false_type {};
template<>
struct is_already_outputable<std::string> : std::true_type {};
template<class T>
constexpr bool id4 = is_already_outputable<T>::value;
template<class T, class = void>
struct is_iterable : std::false_type {};
template<class T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template<class T>
constexpr bool id8 = is_iterable<T>::value;
template<int I, class IStream, class...Ts>
void read_tuple(IStream &is, std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    is >> std::get<I>(t);
    read_tuple<I+1>(is, t);
  }
}
template<int I, class IStream, class...Ts>
void read_tuple(IStream &is, const std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    is >> std::get<I>(t);
    read_tuple<I+1>(is, t);
  }
}
template<int I, class OStream, class...Ts>
void print_tuple(OStream &os, const std::tuple<Ts...> &t) {
  if constexpr (I < sizeof...(Ts)) {
    if constexpr (I)
      os << ' ';
    os << std::get<I>(t);
    print_tuple<I+1>(os, t);
  }
}
} 

template<class IStream, class T, class = std::enable_if_t<
internal::id8<T> && !internal::id9<internal::remove_cvref_t<T>>>>
IStream &operator>>(IStream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class OStream, class T, class = std::enable_if_t<
internal::id8<T> && !internal::id4<internal::remove_cvref_t<T>>>>
OStream &operator<<(OStream &os, T &&container) {
  for (auto &&v : container)
    os << v << ' ';
  return os;
}
template<class IStream, class...Ts>
IStream &operator>>(IStream &is, std::tuple<Ts...> &t) {
  internal::read_tuple<0>(is, t);
  return is;
}
template<class IStream, class...Ts>
IStream &operator>>(IStream &is, const std::tuple<Ts...> &t) {
  internal::read_tuple<0>(is, t);
  return is;
}
template<class OStream, class...Ts>
OStream &operator<<(OStream &os, const std::tuple<Ts...> &t) {
  internal::print_tuple<0>(os, t);
  return os;
}
template<class IStream, class T, class U>
IStream &operator>>(IStream &is, std::pair<T, U> &p) {
  return is >> std::tie(p.first, p.second);
}
template<class OStream, class T, class U>
OStream &operator<<(OStream &os, std::pair<T, U> &p) {
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
auto id6(Args&&...args) {
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









namespace impyster {
template<class T>
T id7(T val, T div) {
  if (val < 0) return -id7(-val, div);
  if (div < 0) return id7(val, -div);
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
      return iterator(this, start_ + id7(stop_-start_, step_));
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
    auto id3(std::integer_sequence<std::size_t, indices...> seq) const {
      return id6(*std::get<indices>(begin_impl(seq))...);
    }
  public:
    zip_impl(T iterables)
      : iterables_(std::move(iterables)) {}
    class iterator
      : public std::iterator<std::input_iterator_tag,
          decltype(std::declval<zip_impl>().id3(all_indices{}))> {
      public:
        iterator() {}
        template<class U>
        iterator(U iterators) : iterators_(std::move(iterators)) {}
        auto operator*() {
          return id0(all_indices{});
        }
        auto operator*() const {
          return id0(all_indices{});
        }
        friend auto operator!=(const iterator &l, const iterator &r) {
          return neq_impl(l, r, all_indices{});
        }
        friend auto operator==(const iterator &l, const iterator &r) {
          return !neq_impl(l, r, all_indices{});
        }
        auto &operator++() {
          id1(all_indices{});
          return *this;
        }
        auto operator++(int) {
          auto cpy = *this;
          id1(all_indices{});
          return cpy;
        }
      private:
        decltype(std::declval<zip_impl>().begin_impl(all_indices{})) iterators_;
        template<std::size_t...indices>
        auto id0(std::integer_sequence<std::size_t, indices...>) {
          return id6(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        auto id0(std::integer_sequence<std::size_t, indices...>) const {
          return id6(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        void id1(std::integer_sequence<std::size_t, indices...>) {
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
  return internal::zip_impl(id6(std::forward<Args>(args)...));
}
} 




namespace impyster {
template<class T>
auto enumerate(T &&iterable) {
  return zip(
    range(std::numeric_limits<long long>::max()/2),
    std::forward<T>(iterable)
  );
}
template<class T>
auto id5(T &&iterable) {
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
  F func_;
  T iterable_;
 public:
  map_impl(F &&func, T &&iterable)
    : func_(std::forward<F>(func)), iterable_(std::forward<T>(iterable)) {}
  using inner_iterator = decltype(iterable_.begin());
  struct iterator : public inner_iterator {
    std::remove_reference_t<F> *func_ = nullptr;
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
    return internal::map_impl<F, Ts...>(std::forward<F>(func), std::forward<Ts>(iterables)...);
  else
    return internal::map_impl(
      [f=std::forward<F>(func)](auto t) { return std::apply(f, t); },
      zip(std::forward<Ts>(iterables)...)
    );
}
} 








namespace impyster {
namespace internal {
template<class OStream, class T>
class print_impl {
  public:
    print_impl(OStream &os, T args)
      : os_(os), args_(std::move(args)), sep_(" "), end_("\n") {}
    ~print_impl() {
      print_tail<0>();
      os_ << end_;
    }
    template<class S>
    print_impl &sep(S &&new_sep) {
      sep_ = std::forward<S>(new_sep);
      return *this;
    }
    template<class S>
    print_impl &end(S &&new_end) {
      end_ = std::forward<S>(new_end);
      return *this;
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
    OStream &os_;
    T args_;
    std::string sep_, end_;
};
struct print_impl_noop {
  template<class S> print_impl_noop &sep(S &&) { return *this; }
  template<class S> print_impl_noop &end(S &&) { return *this; }
};
} 

template<class...Args>
auto print(Args&&...args) {
  return internal::print_impl(std::cout, id6(std::forward<Args>(args)...));
}
template<class...Args>
auto dbg(Args&&...args) {

  return internal::print_impl(std::cerr, id6(std::forward<Args>(args)...));

  std::ignore = std::tie(args...);
  return internal::print_impl_noop{};

}
} 




struct {
  template<class T>
  operator T() {
    T x;
    std::cin >> x;
    return x;
  }
} in;








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
  template<class IStream>
  friend IStream &operator>>(IStream &is, modnum &x) { Int v; is >> v; x = v; return is; }
  template<class OStream>
  friend OStream &operator<<(OStream &os, const modnum &x) { return os << x.val; }
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










using namespace impyster;
using mint = static_mint<998244353>;

constexpr int mxK = 11;





mint unsep[mxK + 1 + 1][mxK + 1][mxK + 1] = {
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 3, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 2, 12, 2, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 2, 12, 4, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 9, 6, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 3, 6, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 4, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 5, 10, 1, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 3, 28, 13, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 4, 35, 29, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 3, 35, 41, 4, 0, 0, 0, 0, 0, 0, 0},
     {0, 1, 30, 44, 7, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 17, 45, 7, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 8, 30, 11, 0, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 20, 6, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 4, 55, 50, 3, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 80, 118, 18, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 95, 186, 48, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 101, 230, 85, 2, 0, 0, 0, 0, 0, 0},
     {0, 2, 94, 260, 113, 4, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 7, 35, 21, 1, 0, 0, 0, 0, 0, 0, 0},
     {0, 5, 96, 145, 26, 0, 0, 0, 0, 0, 0, 0},
     {0, 8, 155, 358, 124, 3, 0, 0, 0, 0, 0, 0},
     {0, 9, 207, 616, 313, 16, 0, 0, 0, 0, 0, 0},
     {0, 11, 250, 859, 567, 53, 0, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 8, 56, 56, 8, 0, 0, 0, 0, 0, 0, 0},
     {0, 6, 154, 350, 126, 4, 0, 0, 0, 0, 0, 0},
     {0, 10, 268, 898, 552, 48, 0, 0, 0, 0, 0, 0},
     {0, 12, 389, 1654, 1404, 204, 1, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 9, 84, 126, 36, 1, 0, 0, 0, 0, 0, 0},
     {0, 7, 232, 742, 448, 43, 0, 0, 0, 0, 0, 0},
     {0, 12, 427, 1967, 1887, 357, 6, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 10, 120, 252, 120, 10, 0, 0, 0, 0, 0, 0},
     {0, 8, 333, 1428, 1302, 252, 5, 0, 0, 0, 0, 0}},
    {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
     {0, 11, 165, 462, 330, 55, 1, 0, 0, 0, 0, 0}}};







mint chunked[mxK + 1][2 * mxK + 1][mxK + 1][mxK + 1];

mint small_inv[mxK + 1], big_inv[2 * mxK + 1];

mint C(int n, int k) {
  


  if (0 > k) return 0;
  if (k > n) return 0;

  mint res = 1;
  for (int v : range(n - k + 1, n + 1)) res *= v;
  for (int v : range(1, k + 1)) res *= small_inv[v];

  return res;
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  for (int k : range(mxK + 1)) small_inv[k] = mint(1) / k;

  if constexpr (0) {
    std::vector<int> p;

    print("{");
    for (int n : range(mxK + 1 + 1)) {
      if (n >= 2) {
        p.resize(n);
        iota(p.begin(), p.end(), 1);
        std::swap(p[0], p[1]);

        int total_here = 0;

        do {
          assert(p[0] != 1);
          if (p.back() == n) continue;

          bool ok = true;
          int pre_max = 0;
          for (int i : range(n - 1)) {
            pre_max = std::max(pre_max, p[i]);
            ok &= pre_max > i + 1;
          }

          if (!ok) continue;

          int id10 = 0;
          for (int i : range(1, n)) id10 += p[i - 1] > p[i];

          int inversions = 0;
          for (int i : range(n))
            for (int j : range(i + 1, n)) inversions += p[i] > p[j];

          if (inversions > mxK) continue;

          ++unsep[n][inversions][id10];
          ++total_here;

        } while (next_permutation(p.begin(), p.end()));
      }

      print().end('{');
      for (int k : range(mxK + 1)) {
        print().end('{');
        for (int x : range(mxK + 1)) {
          print(unsep[n][k][x]).end(",}"[x == mxK]);
        }
        print(",}"[k == mxK]);
      }

      print(",}"[n == mxK + 1]);
    }
  }

  chunked[0][0][0][0] = 1;
  for (int c : range(mxK)) {
    for (int was_n : range(2 * mxK + 1)) {
      for (int was_k : range(mxK + 1)) {
        for (int was_x : range(mxK + 1)) {
          for (int use_n : range(mxK + 1 + 1)) {
            if (was_n + use_n > 2 * mxK) break;

            for (int use_k : range(mxK + 1)) {
              if (was_k + use_k > mxK) break;

              for (int use_x : range(mxK + 1)) {
                if (was_x + use_x > mxK) break;

                chunked[c + 1][was_n + use_n][was_k + use_k][was_x + use_x] +=
                    chunked[c][was_n][was_k][was_x] *
                    unsep[use_n][use_k][use_x];
              }
            }
          }
        }
      }
    }
  }

  std::vector<int> id2(mxK);

  int T = in;
  while (T--) {
    int n = in, k = in, x = in;

    for (int i : range(2 * mxK+1))
      big_inv[i] = mint(1) / (n - i);

    mint ans = 0;
    for (int c : range(mxK + 1)) {
      mint ch = C(n, c);

      for (int u : range(c, std::min(n, 2 * mxK) + 1)) {
        mint f = chunked[c][u][k][x];
        ans += ch * f;

        ch *= big_inv[u - c];
        ch *= n - u;
      }
    }
    print(ans);
  }
}
