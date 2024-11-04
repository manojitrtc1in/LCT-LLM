








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
constexpr bool id11 = is_already_inputable<T>::value;
template<class T>
struct is_already_outputable : std::false_type {};
template<>
struct is_already_outputable<std::string> : std::true_type {};
template<class T>
constexpr bool id5 = is_already_outputable<T>::value;
template<class T, class = void>
struct is_iterable : std::false_type {};
template<class T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template<class T>
constexpr bool id10 = is_iterable<T>::value;
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
internal::id10<T> && !internal::id11<internal::remove_cvref_t<T>>>>
IStream &operator>>(IStream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class OStream, class T, class = std::enable_if_t<
internal::id10<T> && !internal::id5<internal::remove_cvref_t<T>>>>
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
auto id7(Args&&...args) {
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
T id8(T val, T div) {
  if (val < 0) return -id8(-val, div);
  if (div < 0) return id8(val, -div);
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
      return iterator(this, start_ + id8(stop_-start_, step_));
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
    auto id4(std::integer_sequence<std::size_t, indices...> seq) const {
      return id7(*std::get<indices>(begin_impl(seq))...);
    }
  public:
    zip_impl(T iterables)
      : iterables_(std::move(iterables)) {}
    class iterator
      : public std::iterator<std::input_iterator_tag,
          decltype(std::declval<zip_impl>().id4(all_indices{}))> {
      public:
        iterator() {}
        template<class U>
        iterator(U iterators) : iterators_(std::move(iterators)) {}
        auto operator*() {
          return id1(all_indices{});
        }
        auto operator*() const {
          return id1(all_indices{});
        }
        friend auto operator!=(const iterator &l, const iterator &r) {
          return neq_impl(l, r, all_indices{});
        }
        friend auto operator==(const iterator &l, const iterator &r) {
          return !neq_impl(l, r, all_indices{});
        }
        auto &operator++() {
          id2(all_indices{});
          return *this;
        }
        auto operator++(int) {
          auto cpy = *this;
          id2(all_indices{});
          return cpy;
        }
      private:
        decltype(std::declval<zip_impl>().begin_impl(all_indices{})) iterators_;
        template<std::size_t...indices>
        auto id1(std::integer_sequence<std::size_t, indices...>) {
          return id7(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        auto id1(std::integer_sequence<std::size_t, indices...>) const {
          return id7(*std::get<indices>(iterators_)...);
        }
        template<std::size_t...indices>
        void id2(std::integer_sequence<std::size_t, indices...>) {
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
  return internal::zip_impl(id7(std::forward<Args>(args)...));
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
auto id6(T &&iterable) {
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
  return internal::print_impl(std::cout, id7(std::forward<Args>(args)...));
}
template<class...Args>
auto dbg(Args&&...args) {

  return internal::print_impl(std::cerr, id7(std::forward<Args>(args)...));

  std::ignore = std::tie(args...);
  return internal::print_impl_noop{};

}
} 










unsigned long long modmul(unsigned long long a,
                          unsigned long long b,
                          unsigned long long M) {
  long long ret = a * b - M * (unsigned long long)(1.L / M * a * b);
  return ret + M * (ret < 0) - M * (ret >= (long long)M);
}
unsigned long long modpow(unsigned long long b, unsigned long long e, unsigned long long mod) {
  unsigned long long ans = 1;
  for (; e; b = modmul(b, b, mod), e /= 2)
    if (e & 1) ans = modmul(ans, b, mod);
  return ans;
}
long long steps = 0;
bool isPrime(unsigned long long n) {
  if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
  unsigned long long A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
                s = __builtin_ctzll(n-1), d = n >> s;
  for (unsigned long long a : A) {   

    unsigned long long p = modpow(a%n, d, n), i = s;
    while (p != 1 && p != n - 1 && a % n && i--)
      p = modmul(p, p, n), ++steps;
    if (p != n-1 && i != s) return 0;
  }
  return 1;
}
unsigned long long pollard(unsigned long long n) {
  auto f = [n](unsigned long long x) { return modmul(x, x, n) + 1; };
  unsigned long long x = 0, y = 0, t = 30, prd = 2, i = 1, q;
  while (t++ % 40 || std::gcd(prd, n) == 1) {
    ++steps;
    if (x == y) x = ++i, y = f(x);
    if ((q = modmul(prd, std::max(x,y) - std::min(x,y), n))) prd = q;
    x = f(x), y = f(f(y));
  }
  return std::gcd(prd, n);
}
std::vector<unsigned long long> factor(unsigned long long n) {
  if (n == 1) return {};
  if (isPrime(n)) return {n};
  unsigned long long x = pollard(n);
  auto l = factor(x), r = factor(n / x);
  l.insert(l.end(), r.begin(), r.end());
  return l;
}





template<int N>
struct id9 {
  static constexpr int size = N+1;
  static constexpr int max_primes = int(1.6 * N / (int)std::__lg(N+1))+ 10;
  int *id3;
  int *primes;
  int prime_cnt = 0;
  id9() {
    id3 = new int[size/2];
    primes = new int[max_primes];
    for (int i=3; i <= N; i += 2) {
      if (id3[i/2] == 0) {
        id3[i/2] = i;
        primes[prime_cnt++] = i;
      }
      for (int j=0; j < prime_cnt && primes[j] <= id3[i/2] && i*primes[j] <= N; ++j)
        id3[i * primes[j] / 2] = primes[j];
    }
  }
  ~id9() {
    delete[] id3;
    delete[] primes;
  }
  std::vector<int> factor(int x) {
    std::vector<int> res;
    while (x > 1) {
      res.push_back(id3[x/2]);
      x /= res.back();
    }
    return res;
  }
};


















using namespace impyster;

id9<(int)7e7> sieve;

unsigned long long id12(unsigned long long n) {
  n >>= __builtin_ctzll(n);
  assert(n%2);
  if (n == 1) return 1;

  if (n >= sieve.size) {
    static std::map<unsigned long long, unsigned long long> memo;
    auto [it, placed] = memo.emplace(n, 0);
    if (placed) {
      auto facs = factor(n);
      it->second = *min_element(facs.begin(), facs.end());
    }
    return it->second;
  }
  return sieve.id3[n/2];
}

long long id0(long long n) {
  long long lo = 1, hi = n;
  while (lo != hi) {
    __int128_t ce = lo + (hi-lo+1)/2;
    __int128_t v = ce * (ce+1) / 2;
    if (v > n) hi = (long long)ce-1;
    else lo = (long long)ce;
  }
  return lo;
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  

  


  

  

  

  


  

  

  

  

  
  int T;
  std::cin >> T;
  while (T--) {
    long long n;
    std::cin >> n;

    long long maxk = id0(n);

    long long p = 2;
    bool found = false;

    while (p <= maxk) {
      if (n%p == p/2) {
        print(p);
        found = true;
        break;
      }

      p <<= 1;
    }

    if (found)
      continue;

    long long o = id12(n);
    dbg(n, o);

    if (o != 1 && o <= maxk) {
      print(o);
      continue;
    }

    if (!found)
      print(-1);
  }
}