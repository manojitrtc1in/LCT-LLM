











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
constexpr bool id3 = is_already_outputable<T>::value;
template<class T, class = void>
struct is_iterable : std::false_type {};
template<class T>
struct is_iterable<T, std::void_t<decltype(std::declval<T>().begin())>> : std::true_type {};
template<class T>
constexpr bool id10 = is_iterable<T>::value;
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
internal::id10<T> && !internal::id11<internal::remove_cvref_t<T>>>>
std::istream &operator>>(std::istream &is, T &&container) {
  for (auto &&v : container)
    is >> v;
  return is;
}
template<class T, class = std::enable_if_t<
internal::id10<T> && !internal::id3<internal::remove_cvref_t<T>>>>
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
    auto id2(std::integer_sequence<std::size_t, indices...> seq) const {
      return id6(*std::get<indices>(begin_impl(seq))...);
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
  return internal::print_impl(std::cout, id6(std::forward<Args>(args)...));
}
template<class...Args>
auto dbg(Args&&...args) {

  return internal::print_impl(std::cerr, id6(std::forward<Args>(args)...));

  std::ignore = std::tie(args...);
  return internal::print_impl_noop{};

}
} 



















using namespace impyster;

template<typename T, typename AssociativeOperation, typename Timestamp = int>
struct id9 {
    struct node {
        T v;
        int left, right;
    };
    struct snapshot {
        Timestamp t;
        int root;
        int data_size;
        bool operator < (const snapshot &o) const { return t < o.t; }
    };

    int SZ;
    T identity;
    AssociativeOperation TT;
    std::vector<node> data;
    std::vector<snapshot> history;

    id9() {}

    id9(int _SZ, T _identity, AssociativeOperation _TT) : identity(_identity), TT(_TT) {
        SZ = 1 << (32 - __builtin_clz(_SZ - 1));
        assert(SZ >= _SZ && __builtin_popcount(SZ) == 1);

        data.push_back({ identity, -1, -1 });
        for (int loc = 1; loc <= __builtin_ctz(SZ); loc++)
            data.push_back({ TT(data[loc - 1].v, data[loc - 1].v), loc - 1, loc - 1 });

        history.push_back({ std::numeric_limits<Timestamp>::min(), int(data.size()) - 1, int(data.size()) });
    }

private:
    int modify_leaf(int i, T v, int loc, int L, int R, int immutable, bool overwrite) {
        node updated;
        if (R - L == 1) {
            updated = { overwrite ? v : TT(data[loc].v, v), -1, -1 };
        } else {
            int M = L + (R - L) / 2;
            int left  = i <  M ? modify_leaf(i, v, data[loc].left,  L, M, immutable, overwrite) : data[loc].left;
            int right = M <= i ? modify_leaf(i, v, data[loc].right, M, R, immutable, overwrite) : data[loc].right;
            updated = { TT(data[left].v, data[right].v), left, right };
        }
        if (loc < immutable) {
            loc = int(data.size());
            data.push_back(updated);
        } else {
            data[loc] = updated;
        }
        return loc;
    }

    void modify_leaf(int i, T v, Timestamp t, bool overwrite) {
        int current_root = history.back().root;
        if (history.back().t == t) history.pop_back();

        int immutable = history.back().data_size;
        int updated_root = modify_leaf(i, v, current_root, 0, SZ, immutable, overwrite);
        history.push_back({ t, updated_root, int(data.size()) });
    }

    T accumulate(int i, int j, T init, int loc, int L, int R) const {
        if (L == i && j == R) {
            init = TT(init, data[loc].v);
        } else {
            int M = L + (R - L) / 2;
            if (i < M) init = accumulate(i, std::min(j, M), init, data[loc].left,  L, M);
            if (M < j) init = accumulate(std::max(i, M), j, init, data[loc].right, M, R);
        }
        return init;
    }

public:
    

    void assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, true);
    }

    

    void combine_and_assign(int i, T v, Timestamp t) {
        assert(0 <= i && i < SZ && history.back().t <= t);
        modify_leaf(i, v, t, false);
    }

    

    T accumulate(int first, int last, Timestamp t) const {
        if (first >= last) return identity;
        assert(0 <= first && last <= SZ);
        int id4 = std::prev(std::lower_bound(history.begin(), history.end(), snapshot{ t, -1, -1 }))->root;
        return accumulate(first, last, identity, id4, 0, SZ);
    }
};

long long op(long long l, long long r) {
  return std::min(l, r);
}

int main() {
  std::cin.tie(0)->sync_with_stdio(0);

  

  int n, q;
  std::cin >> n >> q;
  std::vector<int> xs(n), ws(n);
  std::cin >> zip(xs, ws);

  std::vector<int> id8(n);
  {
    std::vector<std::array<int, 2>> stk {{n, -1}};
    for (int i : range(n-1, -1, -1)) {
      while (ws[i] < stk.back()[1])
        stk.pop_back();
      id8[i] = stk.back()[0];
      stk.push_back({i, ws[i]});
    }
  }

  dbg(id8);

  id9 st(n, 1LL<<62, op);

  for (int i = n-1; i >= 0; --i) {
    long long best = 1LL<<62;
    for (int j = i+1; j < n; j = id8[j]) {
      long long val = (long long)(xs[j]-xs[i])*(ws[i]+ws[j]);

      if (val < best) {
        dbg(i, j, val);
        st.combine_and_assign(j, val, n-i-1);
        best = val;
      }

      if (ws[j] < ws[i])
        break;

      if ((long long)ws[i] * (xs[j]-xs[i]+1) >= best)
        break;
    }
  }

  for (int qq = 0; qq < q; ++qq) {
    int i, j;
    std::cin >> i >> j;
    --i, --j;

    long long ans = st.accumulate(0, j+1, n-i);

    print(ans);
  }
}
