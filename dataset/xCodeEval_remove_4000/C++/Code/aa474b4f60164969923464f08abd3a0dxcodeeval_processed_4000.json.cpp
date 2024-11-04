












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
constexpr bool id8 = is_already_inputable<T>::value;
template<class T>
struct is_already_outputable : std::false_type {};
template<>
struct is_already_outputable<std::string> : std::true_type {};
template<class T>
constexpr bool id3 = is_already_outputable<T>::value;
template<class T, class = void>
struct is_iterable : std::false_type {};
template<class T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template<class T>
constexpr bool id7 = is_iterable<T>::value;
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
internal::id7<T> && !internal::id8<internal::remove_cvref_t<T>>>>
std::istream &operator>>(std::istream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class T, class = std::enable_if_t<
internal::id7<T> && !internal::id3<internal::remove_cvref_t<T>>>>
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
auto id5(Args&&...args) {
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
T id6(T val, T div) {
  if (val < 0) return -id6(-val, div);
  if (div < 0) return id6(val, -div);
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
      return iterator(this, start_ + id6(stop_-start_, step_));
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
    auto id2(std::integer_sequence<std::size_t, indices...> seq) const {
      return id5(*std::get<indices>(begin_impl(seq))...);
    }
  public:
    zip_impl(T iterables)
      : iterables_(std::move(iterables)) {}
    class iterator
      : public std::iterator<std::input_iterator_tag,
          decltype(std::declval<zip_impl>().id2(all_indices{}))> {
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
          return id5(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        auto id0(std::integer_sequence<std::size_t, indices...>) const {
          return id5(*std::get<indices>(iterators_)...);
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
  return internal::zip_impl(id5(std::forward<Args>(args)...));
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
auto id4(T &&iterable) {
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
  return internal::print_impl(std::cout, id5(std::forward<Args>(args)...));
}
template<class...Args>
auto dbg(Args&&...args) {

  return internal::print_impl(std::cerr, id5(std::forward<Args>(args)...));

  std::ignore = std::tie(args...);
  return internal::print_impl_noop{};

}
} 






















using namespace impyster;

template<int N, class W = __uint128_t>
struct bitset {
  static constexpr int bits_per_word = sizeof(W) * 8;
  static constexpr int block_cnt = (N+bits_per_word-1) / bits_per_word;
  W data[block_cnt];
  
  bitset() {}
  bitset(int) {}

  int block_id(int i) {
    return i / bits_per_word;
  }

  int bit_id(int i) {
    return i % bits_per_word;
  }

  void set() {
    for (int block = 0; block < block_cnt; ++block)
      data[block] = -W(1);
  }
  void reset() {
    for (int block = 0; block < block_cnt; ++block)
      data[block] = 0;
  }
  void set(int i) {
    data[block_id(i)] |= W(1)<<bit_id(i);
  }
  void reset(int i) {
    data[block_id(i)] &= ~(W(1)<<bit_id(i));
  }

  bitset &operator&=(const bitset & __restrict other) {
    for (int block = 0; block < block_cnt; ++block)
      data[block] &= other.data[block];
    return *this;
  }

  int first() {
    for (int block = 0; block < block_cnt; ++block) {
      if (!data[block]) continue;
      return block * bits_per_word + ctz(data[block]);
    }
    return N;
  }

  int ctz(W w) {
    if constexpr (std::is_same_v<W, unsigned>)
      return __builtin_ctz(w);
    else if constexpr (std::is_same_v<W, unsigned long long>)
      return __builtin_ctzll(w);
    else if constexpr (std::is_same_v<W, __uint128_t>)
      return (unsigned long long)w ? __builtin_ctzll((unsigned long long)w)
        : __builtin_ctzll((unsigned long long)(w >> (bits_per_word/2))) + bits_per_word/2;
    else assert(0);
  }
};

constexpr int mxN = 1e5;
using S = bitset<mxN, unsigned long long>;

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  int n, m;
  std::cin >> n >> m;

  std::vector a(n, std::make_pair(std::vector<int>(m), 0LL));
  std::cin >> a;

  sort(a, [](auto &x, auto &y){ return x.second < y.second; });

  for (auto &[is, w] : a)
    dbg(is, w).sep("- ");

  std::map<int, std::vector<int>> who;
  for (int i : range(n))
    for (int x : a[i].first)
      who[x].push_back(i);

  const int cutoff = n / 100;

  std::map<int, S> heavy;
  for (auto &[v, is] : who) {
    if ((int)is.size() < cutoff) continue;
    auto it = heavy.emplace(v, 0).first;
    it->second.set();
    for (int i : is)
      it->second.reset(i);
  }

  long long ans = 1LL<<60;

  S can;
  for (int i : range(n)) {
    can.set();

    for (int v : a[i].first) {
      if ((int)who[v].size() < cutoff) {
        for (int j : who[v])
          can.reset(j);
      } else {
        can &= heavy[v];
      }
    }

    int j = (int)can.first();
    if (j < n)
      ans = std::min(ans, a[i].second + a[j].second);
  }

  print(ans == 1LL<<60 ? -1 : ans);
}
