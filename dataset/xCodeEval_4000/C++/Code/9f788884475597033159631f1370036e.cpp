


#define _ __unused __attribute__((unused))


#include <algorithm>
#include <string>
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
internal::is_iterable_v<T> && !internal::is_already_inputable_v<internal::remove_cvref_t<T>>>>
IStream &operator>>(IStream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class OStream, class T, class = std::enable_if_t<
internal::is_iterable_v<T> && !internal::is_already_outputable_v<internal::remove_cvref_t<T>>>>
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





#include <iostream>
#include <string>
#include <tuple>
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

std::vector<int> a;
std::vector<int> extra;

struct Trie {
  std::vector<int> here;
  Trie *k0 = nullptr, *k1 = nullptr;

  ~Trie() {
    if (k0) delete k0;
    if (k1) delete k1;
  }

  void insert(unsigned x, int pos, int bitpos = 29) {
    here.push_back(pos);
    if (bitpos < 0) return;

    bool bit = x >> bitpos & 1;
    Trie *&k = (bit ? k1 : k0);

    if (!k) k = new Trie();
    k->insert(x, pos, bitpos-1);
  }

  unsigned qry(int i, int j, int bitpos = 29) {
    static std::vector<int> new_extra;

    if (bitpos < 0) return 0;

    if (!k0) k0 = new Trie();
    if (!k1) k1 = new Trie();

    dbg(i, j, bitpos, '|', extra).end(" - ");

    auto small = [&]() {
      new_extra.clear();
      for (int x : extra)
        if (!(x >> bitpos & 1))
          new_extra.push_back(x);
      std::swap(extra, new_extra);

      dbg("v");
      return k0->qry(i, j, bitpos-1);
    };
    auto big = [&]() {
      dbg("^");
      return k1->qry(i, j, bitpos-1) + (1U << bitpos);
    };

    int small_extra_cnt = 0;
    for (int x : extra)
      small_extra_cnt += !(x >> bitpos & 1);
    if (!k0 && small_extra_cnt >= 2)
      k0 = new Trie();

    dbg("small_extra_cnt: ", small_extra_cnt).end(' ');

    if (small_extra_cnt >= 2)
      return small();

    auto &s = k0->here;

    auto it = std::lower_bound(s.begin(), s.end(), i);
    if (it == s.end()) return big();

    if (std::next(it) == s.end() || *std::next(it) > j) {
      if (*it <= j) {
        if (small_extra_cnt) {
          dbg("1 in branch + 1 extra");
          return small();
        } else {
          dbg("1 in branch but no extra. picking it");
          extra.push_back(a[*it]);
          return big();
        }
      } else {
        return big();
      }
    }

    dbg("2 in branch");
    return small();
  }
};

void tcase() {
  int n;
  std::cin >> n;
  a.resize(n);
  std::cin >> a;

  Trie trie;
  for (int i : range(n))
    trie.insert(a[i], i);

  int q;
  std::cin >> q;
  for (int _ : range(q)) {
    int i, j;
    std::cin >> i >> j;
    --i, --j;

    extra.clear();
    print(trie.qry(i, j));
  }
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  int T;
  std::cin >> T;
  while (T--)
    tcase();
}
