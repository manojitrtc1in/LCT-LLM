











namespace dbg {

}
namespace algo {
namespace detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept addable = requires(std::remove_reference_t<Tp> &a,
                           const std::remove_reference_t<Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<Function>::operator())> {
};
template <typename Function, typename ReturnType, typename... Args>
struct function_traits<ReturnType (Function::*)(Args...) const> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType (*)(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<Args...>>::type;
  };
};
template <typename Function>
using extract_return_t = typename function_traits<Function>::result_type;
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...>
    &&std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator>
    &&std::same_as<std::iter_value_t<InputIterator>, ValueType>;
template <typename Tp>
concept qword_fittable = integer<Tp> && sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <integer Tp>
struct safely_multipliable;
template <>
struct safely_multipliable<char> {
  using type = int16_t;
};
template <>
struct safely_multipliable<unsigned char> {
  using type = uint16_t;
};
template <>
struct safely_multipliable<short> {
  using type = int32_t;
};
template <>
struct safely_multipliable<int> {
  using type = int64_t;
};
template <>
struct safely_multipliable<unsigned int> {
  using type = uint64_t;
};
template <>
struct safely_multipliable<long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long> {
  using type = __uint128_t;
};
template <>
struct safely_multipliable<long long> {
  using type = __int128_t;
};
template <>
struct safely_multipliable<unsigned long long> {
  using type = __uint128_t;
};
template <typename Tp>
using safe_mul_t = typename safely_multipliable<Tp>::type;
}
}
namespace algo {
namespace detail {
constexpr long
likely(bool x) noexcept {
  return __builtin_expect(x, 1);
}
constexpr long
unlikely(bool x) noexcept {
  return __builtin_expect(x, 0);
}
constexpr void
unreachable() noexcept {
  __builtin_unreachable();
}
constexpr void
assume(bool x) noexcept {
  if (!x) unreachable();
}
}
}
namespace algo {
template <detail::less_than_comparable Tp>
std::vector<int>
argsort(const std::vector<Tp> &vec) {
  std::vector<int> ind(vec.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&](int a, int b) -> bool { return vec[a] < vec[b]; });
  return ind;
}
template <detail::less_than_comparable Tp>
void
id8(std::vector<Tp> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <detail::less_than_comparable Tp>
int
argmin(const std::vector<Tp> &vec) {
  const int n = (int)vec.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::less_than_comparable Tp>
int
argmax(const std::vector<Tp> &vec) {
  const int n = (int)vec.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (detail::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <detail::integer Tp, std::predicate<Tp> Predicate>
constexpr Tp
bisect(Tp low, Tp high, const Predicate &pred) {
  while (low < high) {
    Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <detail::less_than_comparable Tp>
int
lower_bound(const std::vector<Tp> &vec, const Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <detail::less_than_comparable Tp>
int
upper_bound(const std::vector<Tp> &vec, const Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void
inverse(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::vector<int> out(n);
  for (int i = 0; i < n; ++i) { out[perm[i]] = i; }
  perm = std::move(out);
}
template <std::semiregular Tp>
void
permute(std::vector<Tp> &vec, const std::vector<int> &perm) {
  std::vector<Tp> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
template <detail::less_than_comparable Tp>
std::vector<int>
compress(const std::vector<Tp> &vec) {
  std::vector<int> ind = argsort(vec);
  const int n = (int)vec.size();
  std::vector<int> out(n);
  for (int i = 0, c = 0; i < n; ++c) {
    int j = i;
    do {
      out[ind[j]] = c;
    } while (++j < n && !(vec[ind[j]] < vec[ind[i]]) &&
             !(vec[ind[i]] < vec[ind[j]]));
    i = j;
  }
  return out;
}
template <detail::integer Tp>
constexpr Tp
id2(Tp n) {
  return -(n & 1) | 1;
}
constexpr int
id2(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id4(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id4(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id9(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id9(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id4(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id4(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id4(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id4(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id6(Tp n) {
  return 31 - id4(n);
}
template <qword_fittable Tp>
constexpr int
id6(Tp n) {
  return 63 - id4(n);
}
template <integer Tp>
constexpr int
id7(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id6(n - 1) + 1;
}
template <dword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable Tp>
constexpr int
popcount(Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
template <typename Monoid, typename X, typename Operation, typename Map,
          typename Composition, typename Identity, typename CompositionIdentity>
class id10;
template <std::semiregular Monoid, std::semiregular X,
          detail::binary_op<Monoid> Operation,
          detail::callable<Monoid, Monoid, X> Map,
          detail::binary_op<X> Composition, detail::callable<Monoid> Identity,
          detail::callable<X> CompositionIdentity>
class id10<Monoid, X, Operation, Map, Composition, Identity,
                   CompositionIdentity> {
public:
  id10() = default;
  id10(int n, const Operation &f, const Map &mapping,
               const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : _n(n),
        id3(detail::id7(_n)),
        _size(1 << id3),
        _tree(_size << 1, ef()),
        _lazy(_size, eg()),
        _f(f),
        _map(mapping),
        _g(g),
        _ef(ef),
        _eg(eg) {}
  id10(int n, const Monoid &init, const Operation &f,
               const Map &mapping, const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : _n(n),
        id3(detail::id7(_n)),
        _size(1 << id3),
        _tree(_size << 1, init),
        _lazy(_size, eg()),
        _f(f),
        _map(mapping),
        _g(g),
        _ef(ef),
        _eg(eg) {
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  id10(const std::vector<Monoid> &vec, const Operation &f,
               const Map &mapping, const Composition &g, const Identity &ef,
               const CompositionIdentity &eg)
      : id10((int)vec.size(), f, mapping, g, ef, eg) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  void
  set(int pos, const Monoid &value) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = value;
    for (int i = 1; i <= id3; ++i) { _update(pos >> i); }
  }
  Monoid
  get(int pos) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos];
  }
  void
  apply(int pos, const X &arg) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id3; ++i) { _update(pos >> i); }
  }
  void
  apply_commutative(int pos, const X &arg) {
    pos |= _size;
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id3; ++i) { _update(pos >> i); }
  }
  void
  apply(int l, int r, const X &arg) {
    if (detail::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      for (int i = id3; i > tz_l; --i) { _push(l >> i); }
      for (int i = id3; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id3; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id3; ++i) { _update((r - 1) >> i); }
    }
  }
  void
  apply_commutative(int l, int r, const X &arg) {
    if (detail::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id3; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id3; ++i) { _update((r - 1) >> i); }
    }
  }
  Monoid
  query(int l, int r) {
    Monoid resl = _ef(), resr = _ef();
    if (detail::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      for (int i = id3; i > tz_l; --i) { _push(l >> i); }
      for (int i = id3; i > tz_r; --i) { _push((r - 1) >> i); }
      do {
        if (l & 0x01) { resl = _f(resl, _tree[l++]); }
        if (r & 0x01) { resr = _f(_tree[--r], resr); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
    return _f(resl, resr);
  }
  Monoid
  query() const noexcept {
    return _tree[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  id5(int l, const Predicate &pred) {
    if (detail::likely(l < _n)) {
      l += _size;
      for (int i = id3; i >= 1; --i) { _push(l >> i); }
      Monoid cur = _ef();
      do {
        l >>= detail::id9(l);
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            _push(l);
            l <<= 1;
            if (Monoid tmp = _f(cur, _tree[l]); pred(tmp)) { cur = tmp, ++l; }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) - l);
    }
    return _n;
  }
  template <std::predicate<Monoid> Predicate>
  int
  id1(int r, const Predicate &pred) {
    if (detail::likely(r > 0)) {
      r += _size;
      for (int i = id3; i >= 1; --i) { _push(r - 1 >> i); }
      Monoid cur = _ef();
      do {
        r >>= detail::id9(r);
        r ^= (r > 1);
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            _push(r);
            r <<= 1;
            r |= 1;
            if (Monoid tmp = _f(cur, _tree[r]); pred(tmp)) { cur = tmp, --r; }
          }
          return r + 1 - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) - r);
    }
    return 0;
  }
private:
  void
  _update(int v) {
    _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]);
  }
  void
  _apply_subtree(int v, const X &arg) {
    _tree[v] = _map(_tree[v], arg);
    if (detail::likely(v < _size)) { _lazy[v] = _g(_lazy[v], arg); }
  }
  void
  _push(int v) {
    _apply_subtree(v << 1, _lazy[v]);
    _apply_subtree(v << 1 | 1, _lazy[v]);
    _lazy[v] = _eg();
  }
  int _n, id3, _size;
  std::vector<Monoid> _tree;
  std::vector<X> _lazy;
  Operation _f;
  Map _map;
  Composition _g;
  Identity _ef;
  CompositionIdentity _eg;
};
template <std::semiregular Tp, std::semiregular X,
          detail::callable<Tp, Tp, X> Map, detail::binary_op<X> Composition,
          detail::callable<X> CompositionIdentity>
class id10<Tp, X, void, Map, Composition, void, CompositionIdentity> {
public:
  id10() = default;
  id10(int n, const Map &mapping, const Composition &g,
               const CompositionIdentity &eg)
      : _n(n),
        id3(detail::id7(_n)),
        _size(1 << id3),
        _tree(_size),
        _lazy(_size, eg()),
        _map(mapping),
        _g(g),
        _eg(eg) {}
  id10(int n, const Tp &init, const Map &mapping, const Composition &g,
               const CompositionIdentity &eg)
      : _n(n),
        id3(detail::id7(_n)),
        _size(1 << id3),
        _tree(_size, init),
        _lazy(_size, eg()),
        _map(mapping),
        _g(g),
        _eg(eg) {}
  id10(const std::vector<Tp> &vec, const Map &mapping,
               const Composition &g, const CompositionIdentity &eg)
      : id10(vec.size(), mapping, g, eg) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  void
  set(int pos, const Tp &value) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    _tree[pos ^ _size] = value;
  }
  Tp
  get(int pos) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos ^ _size];
  }
  void
  apply(int pos, const X &arg) {
    pos |= _size;
    for (int i = id3; i >= 1; --i) { _push(pos >> i); }
    _tree[pos ^ _size] = _map(_tree[pos ^ _size], arg);
  }
  void
  apply_commutative(int pos, const X &arg) {
    _tree[pos] = _map(_tree[pos], arg);
  }
  void
  apply(int l, int r, const X &arg) {
    if (detail::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = detail::id9(l);
      const int tz_r = detail::id9(r);
      for (int i = id3; i > tz_l; --i) { _push(l >> i); }
      for (int i = id3; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
    }
  }
  void
  apply_commutative(int l, int r, const X &arg) {
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { _apply_subtree(l++, arg); }
      if (r & 0x01) { _apply_subtree(--r, arg); }
    }
  }
private:
  void
  _apply_subtree(int v, const X &arg) {
    if (detail::unlikely(v & _size)) {
      _tree[v ^ _size] = _map(_tree[v ^ _size], arg);
    } else {
      _lazy[v] = _g(_lazy[v], arg);
    }
  }
  void
  _push(int v) {
    _apply_subtree(v << 1, _lazy[v]);
    _apply_subtree(v << 1 | 1, _lazy[v]);
    _lazy[v] = _eg();
  }
  int _n, id3, _size;
  std::vector<Tp> _tree;
  std::vector<X> _lazy;
  Map _map;
  Composition _g;
  CompositionIdentity _eg;
};
template <typename Operation, typename Map, typename Composition,
          typename Identity, typename CompositionIdentity>
id10(int, const Operation &, const Map &, const Composition &,
             const Identity &, const CompositionIdentity &)
    -> id10<std::invoke_result_t<Identity>,
                    std::invoke_result_t<CompositionIdentity>, Operation, Map,
                    Composition, Identity, CompositionIdentity>;
template <typename Monoid, typename Operation, typename Map,
          typename Composition, typename Identity, typename CompositionIdentity>
id10(int, const Monoid &, const Operation &, const Map &,
             const Composition &, const Identity &, const CompositionIdentity &)
    -> id10<Monoid, std::invoke_result_t<CompositionIdentity>,
                    Operation, Map, Composition, Identity, CompositionIdentity>;
template <typename Monoid, typename Operation, typename Map,
          typename Composition, typename Identity, typename CompositionIdentity>
id10(const std::vector<Monoid> &, const Operation &, const Map &,
             const Composition &, const Identity &, const CompositionIdentity &)
    -> id10<std::invoke_result_t<Identity>,
                    std::invoke_result_t<CompositionIdentity>, Operation, Map,
                    Composition, Identity, CompositionIdentity>;
template <typename Map, typename Composition, typename CompositionIdentity>
id10(int, const Map &, const Composition &, const CompositionIdentity &)
    -> id10<detail::extract_return_t<Map>,
                    std::invoke_result_t<CompositionIdentity>, void, Map,
                    Composition, void, CompositionIdentity>;
template <typename Tp, typename Map, typename Composition,
          typename CompositionIdentity>
id10(int, const Tp &, const Map &, const Composition &,
             const CompositionIdentity &)
    -> id10<Tp, std::invoke_result_t<CompositionIdentity>, void, Map,
                    Composition, void, CompositionIdentity>;
template <typename Tp, typename Map, typename Composition,
          typename CompositionIdentity>
id10(const std::vector<Tp> &, const Map &, const Composition &,
             const CompositionIdentity &)
    -> id10<Tp, std::invoke_result_t<CompositionIdentity>, void, Map,
                    Composition, void, CompositionIdentity>;
}

using std::array;
using std::vector;
using std::span;
using std::bitset;
using std::stack;
using std::queue;
using std::deque;
using std::set;
using std::map;
using std::multimap;
using std::multiset;
using std::complex;
using std::string;
using std::string_view;
using std::stringstream;
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::lcm;
using std::max;
using std::min;
using std::swap;
using std::to_string;
namespace ranges = std::ranges;
namespace views = std::views;
template <typename _Tp, typename _Fn>
using ordered_set = __gnu_pbds::tree<_Tp,
__gnu_pbds::null_type, _Fn, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using uint = unsigned int;
using wint = int64_t;
template <typename _Key, typename _Value>
using umap = std::unordered_map<_Key, _Value>;
template <typename _Value> using uset = std::unordered_set<_Value>;
template <typename _Tp, typename _Fn = std::less<_Tp>>
using max_heap = std::priority_queue<_Tp, std::vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = std::greater<_Tp>>
using min_heap = std::priority_queue<_Tp, std::vector<_Tp>, _Fn>;





inline void solve() noexcept {
  int n,q;cin>>n>>q;
  using node=struct{
    wint sum;
    int col,tl,tr;
  };
  using rec=struct{
    wint sum;
    int time;
  };
  vector<vector<rec>>record(n+1);
  algo::id10 lsg(n+1,
  node{0,1,0,0},
  [&](node x,node y){
    if(y.col==0){return x;}
    wint sum=x.sum+y.sum;
    int c=x.col,tl=x.tr,tr=y.tl;
    int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tl},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    int p2=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    if(p2>=0){
      sum+=record[c][p2].sum;
    }
    if(p1>=0){
      sum-=record[c][p1].sum;
    }
    return node{sum,y.col,x.tl,y.tr};
  },
  [&](node x,node y){
    if(x.col==0){return y;}
    if(y.col==0){return x;}
    wint sum=x.sum+y.sum;
    int c=x.col,tl=x.tr,tr=y.tl;
    int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tl},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    int p2=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
    [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
    if(p2>=0){
      sum+=record[c][p2].sum;
    }
    if(p1>=0){
      sum-=record[c][p1].sum;
    }
    return node{sum,y.col,x.tl,y.tr};
  },
  []{return node{0,0,0,0};});
  char buf[10];
  for(int time=1;time<=q;++time){
    cin>>buf;
    if(buf[0]=='C'){
      int l,r,c;cin>>l>>r>>c;
      lsg.apply(l,r+1,node{0,c,time,time});
    }else if(buf[0]=='A'){
      int c;cin>>c;
      wint x;cin>>x;
      x+=(record[c].empty())?0:record[c].back().sum;
      record[c].emplace_back(x,time);
    }else{
      int pos;cin>>pos;
      auto [sum,c,_,tr]=lsg.get(pos);
      int p1=lower_bound(record[c].begin(),record[c].end(),rec{0,tr},
      [](rec w,rec v){return w.time<v.time;})-record[c].begin()-1;
      int p2=-1+(int)record[c].size();
      if(p2>=0){
        sum+=record[c][p2].sum;
      }
      if(p1>=0){
        sum-=record[c][p1].sum;
      }
      cout<<sum<<'\n';
    }
  }
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  solve();
  return 0;
}
