














namespace io {
template <typename _Tp>
void id5(const _Tp &val) noexcept {
  std::cout << val;
}
template <typename _Tp>
void id5(const std::vector<_Tp> &vec) noexcept {
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << vec[i];
  }
}
template <typename _First, typename _Second>
void id5(const std::pair<_First, _Second> &p) noexcept {
  std::cout << p.first << ' ' << p.second;
}
template <typename... _Args, std::size_t... Is>
void id6(const std::tuple<_Args...> &tup,
                 std::index_sequence<0, Is...>) {
  io::id5(std::get<0>(tup));
  ((std::cout << ' ', io::id5(std::get<Is>(tup))), ...);
}
template <typename... _Args>
void id5(const std::tuple<_Args...> &tup) noexcept {
  id6(tup, std::make_index_sequence<sizeof...(_Args)>{});
}
}
namespace dbg {
template <class T>
void view(const T &e) {
  std::cerr << e;
}
template <class T, class U>
void view(const std::pair<T, U> &p) {
  std::cerr << "(" << p.first << ", " << p.second << ")";
}
template <class T>
void view(const std::vector<T> &a) {
  std::cerr << "{ ";
  for (const auto &v : a) { std::cerr << v << ", "; }
  std::cerr << "\b\b }";
}
template <class T>
void view(const std::vector<std::vector<T>> &a) {
  std::cerr << "{\n";
  for (const auto &v : a) {
    std::cerr << "\t";
    view(v);
    std::cerr << "\n";
  }
  std::cerr << "}";
}
template <class T, class U>
void view(const std::vector<std::pair<T, U>> &a) {
  std::cerr << "{\n";
  for (const auto &p : a)
    std::cerr << "\t(" << p.first << ", " << p.second << ")\n";
  std::cerr << "}";
}
template <class T, class U>
void view(const std::map<T, U> &m) {
  std::cerr << "{\n";
  for (const auto &p : m)
    std::cerr << "\t[" << p.first << "] : " << p.second << "\n";
  std::cerr << "}";
}
template <class T>
void view(const std::set<T> &s) {
  std::cerr << "{ ";
  for (auto &v : s) {
    view(v);
    std::cerr << ", ";
  }
  std::cerr << "\b\b }";
}
}
template <typename _Head, typename... _Rest>
void print(const _Head &head, const _Rest &... rest) noexcept {
  io::id5(head);
  ((std::cout << ' ', io::id5(rest)), ...);
  std::cout << '\n';
}

  std::cerr << "Line " << __LINE__ << ":: " \
            << "\033[1;32m" << 
  dbg::view(x); \
  std::cerr << '\n';
namespace algo {
namespace base {
template <typename _Tp, typename = void>
struct is_multipliable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_multipliable<_Tp,
                       std::void_t<decltype(std::declval<_Tp &>() *=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp, typename = void>
struct is_addable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_addable<_Tp, std::void_t<decltype(std::declval<_Tp &>() +=
                                            std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id24 = is_multipliable<_Tp>::value;
template <typename _Tp>
constexpr bool id1 = is_addable<_Tp>::value;
template <typename _Tp>
constexpr bool id17 = std::id17<_Tp>;
template <typename _Tp>
constexpr bool id0 = std::id0<_Tp>;
template <typename _Tp, typename _U>
constexpr bool id7 = std::id7<_Tp, _U>;
template <typename T>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<T>::operator())> {};
template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const>
{
  enum { arity = sizeof...(_Args) };
  typedef _Ret result_type;
  template <size_t i>
  struct arg {
    typedef typename std::tuple_element<i, std::tuple<_Args...>>::type type;
  };
};
template <typename _Tp, typename = void>
struct is_less_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp, typename = void>
struct is_greater_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_greater_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() >
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id15 = is_less_than_comparable<_Tp>::value;
template <typename _Tp>
constexpr bool id9 =
    is_greater_than_comparable<_Tp>::value;
template <typename _Tp, typename = void>
struct is_equality_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct is_equality_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() ==
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool id22 = is_equality_comparable<_Tp>::value;
}
}
namespace algo {
namespace base {
constexpr int id23(int n) { return __builtin_clz(n); };
constexpr int id23(long long n) { return __builtin_clzll(n); };
constexpr int id2(int n) { return __builtin_ctz(n); };
constexpr int id2(long long n) { return __builtin_ctzll(n); }
constexpr int id10(int n, int i) {
  if (std::is_constant_evaluated()) {
    return n & ((1u << i) - 1);
  } else {
    return _bzhi_u32((unsigned)n, (unsigned)i);
  }
}
constexpr long long id10(long long n, int i) {
  if (std::is_constant_evaluated()) {
    return n & ((1ull << i) - 1);
  } else {
    return _bzhi_u64((unsigned long long)n, (unsigned)i);
  }
}
constexpr int id19(int n) {
  if (std::is_constant_evaluated()) {
    return n ^ (n - 1);
  } else {
    return _blsmsk_u32((unsigned int)n);
  }
}
constexpr long long id19(long long n) {
  if (std::is_constant_evaluated()) {
    return n ^ (n - 1);
  } else {
    return _blsmsk_u64((unsigned long long)n);
  }
}
constexpr int id13(int n) { return 32 - id23(n); };
constexpr int id13(long long n) { return 64 - id23(n); };
constexpr int id20(int n) { return 1u << (31 - id23(n)); };
constexpr long long id20(long long n) {
  return 1ull << (63 - id23(n));
}
constexpr int id21(int n) {
  if (n == 0 || n == 1) { return 1; }
  return id20(n - 1) << 1;
};
constexpr long long id21(long long n) {
  if (n == 0 || n == 1) { return 1; }
  return id20(n - 1) << 1;
}
constexpr int id12(int n) { return 31 - id23(n); };
constexpr int id12(long long n) { return 63 - id23(n); };
constexpr int id25(int n) {
  if (n == 0 || n == 1) { return 0; }
  return id12(n - 1) + 1;
}
constexpr int id25(long long n) {
  if (n == 0 || n == 1) { return 0; }
  return id12(n - 1) + 1;
}
constexpr int id3(int n) { return __builtin_popcount(n); };
constexpr int id3(long long n) { return __builtin_popcountll(n); }
constexpr int id4(int n) { return __builtin_parity(n); };
}
}
namespace algo {
namespace base {
constexpr long likely(bool x) noexcept { return __builtin_expect(x, 1); }
constexpr long unlikely(bool x) noexcept { return __builtin_expect(x, 0); }
constexpr void assume(bool x) noexcept {
  if (!x) __builtin_unreachable();
}
}
}
namespace algo {
template <typename _Monoid, typename _F, typename _E>
class id18 {
public:
  id18() = delete;
  id18(int n, _F &&f, _E &&e)
      : _n(n),
        id11(base::id25(n)),
        _size(1 << id11),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {}
  id18(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : id18(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  id18(std::vector<_Monoid> &&vec, _F &&f, _E &&e) noexcept
      : id18(int(vec.size()), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator>
  id18(_InputIterator first, _InputIterator last, _F &&f, _E &&e)
      : id18((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<
            std::invoke_result_t<_E>,
            typename std::iterator_traits<_InputIterator>::value_type>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator, typename _Gen>
  id18(_InputIterator first, _InputIterator last, _F &&f, _E &&e, _Gen &&gen)
      : id18((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(std::is_same_v<std::invoke_result_t<_E>, _Monoid>);
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~id18() = default;
  void set_val(int pos, const _Monoid &val) {

    assert(0 <= pos && pos < _n);

    _tree[pos += _size] = val;
    for (int i = 1; i <= id11; ++i) { _update(pos >> i); }
  }
  _Monoid get_val(int pos) const {

    assert(0 <= pos && pos < _n);

    return _tree[pos + _size];
  }
  _Monoid query(int l, int r) const {

    assert(0 <= l && l <= r && r <= _n);

    _Monoid resl = _ef(), resr = _ef();
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = _f(resl, _tree[l++]); }
      if (r & 0x01) { resr = _f(_tree[--r], resr); }
    }
    return _f(resl, resr);
  }
  _Monoid query() const { return _tree[1]; }
  template <typename _Pred>
  int max_right(int l, _Pred &&pred) const {

    assert(0 <= l && l <= _n);
    assert(pred(_ef()));

    if (base::likely(l < _n)) {
      l += _size;
      _Monoid cur = _ef();
      do {
        l >>= base::id2(l);
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            l <<= 1;
            if (_Monoid tmp = _f(cur, _tree[l]); pred(tmp)) { cur = tmp, ++l; }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) - l);
    }
    return _n;
  }
  template <typename Pred>
  int min_left(int r, Pred &&pred) const {

    assert(0 <= r && r <= _n);

    if (base::likely(r > 0)) {
      r += _size;
      _Monoid cur = _ef();
      do {
        r >>= base::id2(r);
        r ^= (r > 1);
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            r <<= 1;
            r |= 1;
            if (_Monoid tmp = _f(_tree[r], cur); pred(tmp)) { cur = tmp, --r; }
          }
          return r + 1 - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) - r);
    }
    return 0;
  }
private:
  void _update(int v) { _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]); }
  int _n, id11, _size;
  std::vector<_Monoid> _tree;
  _F _f;
  _E _ef;
};
template <typename _F, typename _E>
id18(int, _F &&, _E &&) -> id18<std::invoke_result_t<_E>, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id18(const std::vector<_Monoid> &, _F &&, _E &&) -> id18<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id18(std::vector<_Monoid> &&, _F &&, _E &&) -> id18<_Monoid, _F, _E>;
template <typename _InputIterator, typename _F, typename _E>
id18(_InputIterator, _InputIterator, _F &&, _E &&)
    -> id18<typename std::iterator_traits<_InputIterator>::value_type, _F,
               _E>;
template <typename _InputIterator, typename _Gen, typename _F, typename _E>
id18(_InputIterator, _InputIterator, _F &&, _E &&, _Gen &&)
    -> id18<std::invoke_result_t<_Gen, typename std::iterator_traits<
                                              _InputIterator>::value_type>,
               _F, _E>;
template <typename _T, typename _X, typename _Map, typename _G>
class id14 {
public:
  id14(int n, _Map &&mapping, _G &&g)
      : _n(n),
        id11(base::id25(_n)),
        _size(1 << id11),
        _tree(_size),
        _lazy(_size),
        _marked(_size, false),
        _map(mapping),
        _g(g) {}
  id14(const std::vector<_T> &vec, _Map &&mapping, _G &&g)
      : id14((int)vec.size(), std::forward<_Map>(mapping),
                             std::forward<_G>(g)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  id14(std::vector<_T> &&vec, _Map &&mapping, _G &&g) noexcept
      : id14((int)vec.size(), std::forward<_Map>(mapping),
                             std::forward<_G>(g)) {
    std::move(vec.begin(), vec.end(), _tree.begin());
  }
  template <typename _InputIterator>
  id14(_InputIterator first, _InputIterator last,
                       _Map &&mapping, _G &&g)
      : id14((int)std::distance(first, last),
                             std::forward<_Map>(mapping), std::forward<_G>(g)) {
    std::copy(first, last, _tree.begin());
  }
  template <typename _InputIterator, typename _Gen>
  id14(_InputIterator first, _InputIterator last,
                       _Map &&mapping, _G &&g, _Gen &&gen)
      : id14((int)std::distance(first, last),
                             std::forward<_Map>(mapping), std::forward<_G>(g)) {
    std::transform(first, last, _tree.begin(), std::forward<_Gen>(gen));
  }
  ~id14() = default;
  void set_val(int pos, const _T &val) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  _T query(int pos) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos - _size];
  }
  void apply(int pos, const _X &arg) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = _map(_tree[pos - _size], arg);
  }
  void apply(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id2(l);
      const int tz_r = base::id2(r);
      for (int i = id11; i >= 1; --i) {
        if (i > tz_l) { _push(l >> i); }
        if (i > tz_r) { _push((r - 1) >> i); }
      }
      do {
        if (l & 0x01) { _apply_subtree(l++, arg); }
        if (r & 0x01) { _apply_subtree(--r, arg); }
        l >>= 1, r >>= 1;
      } while (l < r);
    }
  }
private:
  void _apply_subtree(int v, const _X &arg) {
    if (v >= _size) { _tree[v - _size] = _map(_tree[v - _size], arg); }
    if (v < _size) {
      _lazy[v] = _marked[v] ? _g(_lazy[v], arg) : arg;
      _marked[v] = true;
    }
  }
  void _push(int v) {
    if (_marked[v]) {
      _apply_subtree(v << 1, _lazy[v]);
      _apply_subtree(v << 1 | 1, _lazy[v]);
      _marked[v] = false;
    }
  }
  int _n, id11, _size;
  std::vector<_T> _tree;
  std::vector<_X> _lazy;
  std::vector<char> _marked;
  _Map _map;
  _G _g;
};
template <typename _Map, typename _G>
id14(int, _Map &&, _G &&)
    -> id14<typename base::function_traits<_Map>::result_type,
                            typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _T, typename _Map, typename _G>
id14(const std::vector<_T> &, _Map &&, _G &&)
    -> id14<_T, typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _T, typename _Map, typename _G>
id14(std::vector<_T> &&, _Map &&, _G &&)
    -> id14<_T, typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _InputIterator, typename _Map, typename _G>
id14(_InputIterator, _InputIterator, _Map &&, _G &&)
    -> id14<
        typename std::iterator_traits<_InputIterator>::value_type,
        typename base::function_traits<_G>::result_type, _Map, _G>;
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T id16(const _T &a, const _T &b) {
  return a < b ? b : a;
}
template <typename _T>
constexpr _T __mini(const _T &a, const _T &b) {
  return a < b ? a : b;
}
template <typename _T>
constexpr void __swap(_T &a, _T &b) {
  _T tp = a;
  a = b;
  b = tp;
}
template <typename _T>
constexpr void __swap(_T *a, _T *b) {
  _T tp = *a;
  *a = *b;
  *b = tp;
}
}
}
namespace algo {
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
constexpr _T max(const _T &a, const _T &b) {
  return base::id16(a, b);
}
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
constexpr _T min(const _T &a, const _T &b) {
  return base::__mini(a, b);
}
template <typename _T>
constexpr void swap(_T &a, _T &b) {
  base::__swap(a, b);
}
template <typename _T>
constexpr void swap(_T *a, _T *b) {
  base::__swap(a, b);
}
template <
    typename _InputIterator,
    typename _Value = typename std::iterator_traits<_InputIterator>::value_type,
    std::enable_if_t<base::id1<_Value>, bool> = true>
constexpr _Value sum(_InputIterator first, _InputIterator last,
                     const _Value &init = {}) {
  return std::accumulate(first, last, init);
};
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
std::vector<int> argsort(const std::vector<_T> &v) {
  std::vector<int> ind(v.size(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
int argmin(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T,
          std::enable_if_t<base::id9<_T>, bool> = true>
int argmax(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T, typename _Pred,
          std::enable_if_t<base::id17<_T>, bool> = true>
constexpr _T bisect(_T low, _T high, _Pred &&pred) {

  assert(low <= high);

  while (low < high) {
    _T mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
int lower_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
int upper_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void id8(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::transform(perm.begin(), perm.end(), perm.begin(),
                 [](int x) -> int { return ~x; });
  for (int i = 0; i < n; ++i) {
    if (perm[i] < 0) {
      int x = i, y = ~perm[i];
      do {
        int t = ~perm[y];
        perm[y] = x, x = y, y = t;
      } while (perm[y] < 0);
    }
  }
}
template <typename _T>
void permute(std::vector<_T> &vec, const std::vector<int> &perm) {
  std::vector<_T> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
template <typename _T,
          std::enable_if_t<base::id15<_T>, bool> = true>
std::vector<int> compress(const std::vector<_T> &v) {
  std::vector<int> p(v.size()), ans(v.size());
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  const int n = (int)p.size();
  for (int i = 0, k = 0; i < n; ++k) {
    int j = i;
    do {
      ans[p[j]] = k;
    } while (++j < n && !(v[p[j]] < v[p[i]]) && !(v[p[i]] < v[p[j]]));
    i = j;
  }
  return ans;
}
}
using namespace std;
using namespace std::literals;
using namespace __gnu_pbds;
template <typename _Tp, typename _Fn>
using ordered_set =
    tree<_Tp, null_type, _Fn, rb_tree_tag, tree_order_statistics_node_update>;
using uint = unsigned int;
template <typename _Key, typename _Value>
using umap = unordered_map<_Key, _Value>;
template <typename _Tp, typename _Fn = less<_Tp>>
using max_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Tp, typename _Fn = greater<_Tp>>
using min_heap = priority_queue<_Tp, vector<_Tp>, _Fn>;
template <typename _Value> using uset = unordered_set<_Value>;
using wint = long long int;






namespace {}
void solve() {
  int n,q;cin>>n>>q;
  using node=struct{int c,tl,tr;wint sum;};
  using data=struct{int t;wint x;};
  vector<vector<data>>cur(n+1,{{.t=-1,.x=0}});
  auto g=[&](const node&x,const node&y){
    int c1=x.c,c2=y.c;
    int t1=x.tr,t2=y.tl;
    int p1=algo::bisect(0,(int)cur[c1].size(),[&](int u){return cur[c1][u].t<=t1;})-1;
    int p2=algo::bisect(p1+1,(int)cur[c1].size(),[&](int u){return cur[c1][u].t<=t2;})-1;
    wint d=cur[c1][p2].x-cur[c1][p1].x;
    return node{c2,x.tl,y.tr,x.sum+y.sum+d};
  };
  algo::id14 sg(vector<node>(n+1,{.c=1,.tl=0,.tr=0,.sum=0}),g,g);
  char buf[10];
  for(int i=1;i<=q;++i){
    cin>>buf;
    if(buf[0]=='C'){
      int l,r,c;cin>>l>>r>>c;
      sg.apply(l,r+1,{.c=c,.tl=i,.tr=i,.sum=0});
    }else if(buf[0]=='A'){
      int c;
      wint x;cin>>c>>x;
      x+=cur[c].back().x;
      cur[c].emplace_back(i,x);
    }else{
      int p;cin>>p;
      node an=sg.query(p);
      int p1=algo::bisect(0,(int)cur[an.c].size(),[&](int u){return cur[an.c][u].t<an.tr;})-1;
      int p2=algo::bisect(p1+1,(int)cur[an.c].size(),[&](int u){return cur[an.c][u].t<i;})-1;
      cout<<an.sum+cur[an.c][p2].x-cur[an.c][p1].x<<'\n';
    }
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  if constexpr (MULTI) {
    int tc = 1;
    cin >> tc;
    while (tc--) {
      solve();
    }
  } else {
    solve();
  }
  return 0;
}
