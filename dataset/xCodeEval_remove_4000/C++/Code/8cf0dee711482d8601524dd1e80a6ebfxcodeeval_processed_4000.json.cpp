












namespace io {
template <typename _Tp>
void id7(const _Tp &val) noexcept {
  std::cout << val;
}
template <typename _Tp>
void id7(const std::vector<_Tp> &vec) noexcept {
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << vec[i];
  }
}
template <typename _First, typename _Second>
void id7(const std::pair<_First, _Second> &p) noexcept {
  std::cout << p.first << ' ' << p.second;
}
template <typename... _Args, std::size_t... Is>
void id8(const std::tuple<_Args...> &tup,
                 std::index_sequence<0, Is...>) {
  io::id7(std::get<0>(tup));
  ((std::cout << ' ', io::id7(std::get<Is>(tup))), ...);
}
template <typename... _Args>
void id7(const std::tuple<_Args...> &tup) noexcept {
  id8(tup, std::make_index_sequence<sizeof...(_Args)>{});
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
  io::id7(head);
  ((std::cout << ' ', io::id7(rest)), ...);
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
constexpr bool id25 = is_multipliable<_Tp>::value;
template <typename _Tp>
constexpr bool id1 = is_addable<_Tp>::value;
template <typename _Tp>
constexpr bool id17 = std::id17<_Tp>;
template <typename _Tp>
constexpr bool id0 = std::id0<_Tp>;
template <typename _Tp, typename _U>
constexpr bool id9 = std::id9<_Tp, _U>;
template <typename _Fn>
struct function_traits : public function_traits<decltype(
                             &std::remove_reference_t<_Fn>::operator())> {};
template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Ret, typename... _Args>
struct function_traits<_Ret (*)(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Fn>
using invoke_result_t = typename function_traits<_Fn>::result_type;
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
constexpr bool id14 = is_less_than_comparable<_Tp>::value;
template <typename _Tp>
constexpr bool id10 =
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
constexpr bool id23 = is_equality_comparable<_Tp>::value;
}
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T id15(const _T &a, const _T &b) {
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
namespace base {
constexpr long likely(bool x) noexcept { return __builtin_expect(x, 1); }
constexpr long unlikely(bool x) noexcept { return __builtin_expect(x, 0); }
constexpr void unreachable() noexcept { __builtin_unreachable(); }
constexpr void assume(bool x) noexcept {
  if (!x) __builtin_unreachable();
}
}
}
namespace algo {
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
constexpr _T max(const _T &a, const _T &b) {
  return base::id15(a, b);
}
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
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
          std::enable_if_t<base::id14<_T>, bool> = true>
std::vector<int> argsort(const std::vector<_T> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
void id19(std::vector<_T> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
int argmin(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T,
          std::enable_if_t<base::id10<_T>, bool> = true>
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
          std::enable_if_t<base::id14<_T>, bool> = true>
int lower_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
int upper_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void inverse(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::vector<int> out(n);
  for (int i = 0; i < n; ++i) { out[perm[i]] = i; }
  perm = std::move(out);
}
template <typename _T>
void permute(std::vector<_T> &vec, const std::vector<int> &perm) {
  std::vector<_T> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
template <typename _T,
          std::enable_if_t<base::id14<_T>, bool> = true>
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
template <typename _T, std::enable_if_t<base::id17<_T>, bool> = true>
constexpr int id5(_T n) {
  return -(n & 1) | 1;
}
template <>
constexpr int id5<bool>(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace base {
constexpr int id24(int n) { return __builtin_clz(n); };
constexpr int id24(long long n) { return __builtin_clzll(n); };
constexpr int id2(int n) { return __builtin_ctz(n); };
constexpr int id2(long long n) { return __builtin_ctzll(n); }
constexpr int id13(int n) { return 32 - id24(n); };
constexpr int id13(long long n) { return 64 - id24(n); };
constexpr int id20(int n) { return 1u << (31 - id24(n)); };
constexpr long long id20(long long n) {
  return 1ull << (63 - id24(n));
}
constexpr int id22(int n) {
  if (n == 0 || n == 1) { return 1; }
  return id20(n - 1) << 1;
};
constexpr long long id22(long long n) {
  if (n == 0 || n == 1) { return 1; }
  return id20(n - 1) << 1;
}
constexpr int id12(int n) { return 31 - id24(n); };
constexpr int id12(long long n) { return 63 - id24(n); };
constexpr int id26(int n) {
  if (n == 0 || n == 1) { return 0; }
  return id12(n - 1) + 1;
}
constexpr int id26(long long n) {
  if (n == 0 || n == 1) { return 0; }
  return id12(n - 1) + 1;
}
constexpr int id4(int n) { return __builtin_popcount(n); };
constexpr int id4(long long n) { return __builtin_popcountll(n); }
constexpr int id6(int n) { return __builtin_parity(n); };
}
}
namespace algo {
template <typename _Monoid, typename _X, typename _F, typename _G,
          typename _Map, typename _EF, typename _EG>
class id21 {
public:
  id21(int n, _F &&f, _G &&g, _Map &&mapping, _EF &&ef, _EG &&eg)
      : _n(n),
        id11(base::id26(_n)),
        _size(1 << id11),
        _tree(_size << 1, ef()),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {}
  id21(int n, const _Monoid &init, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : _n(n),
        id11(base::id26(_n)),
        _size(1 << id11),
        _tree(_size << 1, init),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {}
  id21(const std::vector<_Monoid> &vec, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : id21((int)vec.size(), std::forward<_F>(f), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EF>(ef),
                     std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~id21() = default;
  void set(int pos, const _Monoid &val) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = val;
    for (int i = 1; i <= id11; ++i) { _update(pos >> i); }
  }
  _Monoid get(int pos) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos];
  }
  void apply(int pos, const _X &arg) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id11; ++i) { _update(pos >> i); }
  }
  void apply_commutative(int pos, const _X &arg) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id11; ++i) { _update(pos >> i); }
  }
  void apply(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id2(l);
      const int tz_r = base::id2(r);
      for (int i = id11; i > tz_l; --i) { _push(l >> i); }
      for (int i = id11; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id11; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id11; ++i) { _update((r - 1) >> i); }
    }
  }
  void apply_commutative(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id2(l);
      const int tz_r = base::id2(r);
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id11; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id11; ++i) { _update((r - 1) >> i); }
    }
  }
  _Monoid query(int l, int r) {

    assert(0 <= l && l <= r && r <= _n);

    _Monoid resl = _ef(), resr = _ef();
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id2(l);
      const int tz_r = base::id2(r);
      for (int i = id11; i > tz_l; --i) { _push(l >> i); }
      for (int i = id11; i > tz_r; --i) { _push((r - 1) >> i); }
      do {
        if (l & 0x01) { resl = _f(resl, _tree[l++]); }
        if (r & 0x01) { resr = _f(_tree[--r], resr); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
    return _f(resl, resr);
  }
  _Monoid query() const noexcept { return _tree[1]; }
  template <typename _Pred>
  int id16(int l, _Pred &&pred) {

    assert(0 <= l && l <= _n);
    assert(pred(_ef()));

    if (base::likely(l < _n)) {
      l += _size;
      for (int i = id11; i >= 1; --i) { _push(l >> i); }
      _Monoid cur = _ef();
      do {
        l >>= base::id2(l);
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            _push(l);
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
  template <typename _Pred>
  int id3(int r, _Pred &&pred) {

    assert(0 <= r && r <= _n);
    assert(pred(_ef()));

    if (base::likely(r > 0)) {
      r += _size;
      for (int i = id11; i >= 1; --i) { _push(r - 1 >> i); }
      _Monoid cur = _ef();
      do {
        r >>= base::id2(r);
        r ^= (r > 1);
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            _push(r);
            r <<= 1;
            r |= 1;
            if (_Monoid tmp = _f(cur, _tree[r]); pred(tmp)) { cur = tmp, --r; }
          }
          return (r + 1) - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) - r);
    }
    return 0;
  }
private:
  void _update(int v) { _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]); }
  void _apply_subtree(int v, const _X &arg) {
    _tree[v] = _map(_tree[v], arg);
    if (base::likely(v < _size)) { _lazy[v] = _g(_lazy[v], arg); }
  }
  void _push(int v) {
    _apply_subtree(v << 1, _lazy[v]);
    _apply_subtree(v << 1 | 1, _lazy[v]);
    _lazy[v] = _eg();
  }
  int _n, id11, _size;
  std::vector<_Monoid> _tree;
  std::vector<_X> _lazy;
  _F _f;
  _G _g;
  _Map _map;
  _EF _ef;
  _EG _eg;
};
template <typename _T, typename _X, typename _G, typename _Map, typename _EG>
class id21<_T, _X, void, _G, _Map, void, _EG> {
public:
  id21(int n, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        id11(base::id26(_n)),
        _size(1 << id11),
        _tree(_size),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  id21(int n, const _T &init, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        id11(base::id26(_n)),
        _size(1 << id11),
        _tree(_size, init),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  id21(const std::vector<_T> &vec, _G &&g, _Map &&mapping, _EG &&eg)
      : id21(vec.size(), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  void set(int pos, const _T &val) {

    assert(0 <= pos && pos < _n);

    pos += _size;
    for (int i = id11; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  _T get(int pos) {

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
  void apply_commutative(int pos, const _X &arg) {

    assert(0 <= pos && pos < _n);

    _tree[pos] = _map(_tree[pos], arg);
  }
  void apply(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id2(l);
      const int tz_r = base::id2(r);
      for (int i = id11; i > tz_l; --i) { _push(l >> i); }
      for (int i = id11; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
    }
  }
  void apply_commutative(int l, int r, const _X &arg) {

    assert(0 <= l && l <= r && r <= _n);

    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { _apply_subtree(l++, arg); }
      if (r & 0x01) { _apply_subtree(--r, arg); }
    }
  }
private:
  void _apply_subtree(int v, const _X &arg) {
    if (base::unlikely(v >= _size)) {
      _tree[v - _size] = _map(_tree[v - _size], arg);
    } else {
      _lazy[v] = _g(_lazy[v], arg);
    }
  }
  void _push(int v) {
    _apply_subtree(v << 1, _lazy[v]);
    _apply_subtree(v << 1 | 1, _lazy[v]);
    _lazy[v] = _eg();
  }
  int _n, id11, _size;
  std::vector<_T> _tree;
  std::vector<_X> _lazy;
  _G _g;
  _Map _map;
  _EG _eg;
};
template <typename _F, typename _G, typename _Map, typename _EF, typename _EG>
id21(int, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> id21<base::invoke_result_t<_EF>, base::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
id21(int, const _Monoid &, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> id21<_Monoid, base::invoke_result_t<_EG>, _F, _G, _Map, _EF,
                    _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
id21(const std::vector<_Monoid> &, _F &&, _G &&, _Map &&, _EF &&,
             _EG &&)
    -> id21<base::invoke_result_t<_EF>, base::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _G, typename _Map, typename _EG>
id21(int, _G &&, _Map &&, _EG &&)
    -> id21<base::invoke_result_t<_Map>, base::invoke_result_t<_EG>,
                    void, _G, _Map, void, _EG>;
template <typename _T, typename _G, typename _Map, typename _EG>
id21(int, const _T &, _G &&, _Map &&, _EG &&)
    -> id21<_T, base::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
template <typename _T, typename _G, typename _Map, typename _EG>
id21(const std::vector<_T> &vec, _G &&, _Map &&, _EG &&)
    -> id21<_T, base::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
}
namespace algo {
template <typename _Monoid, typename _F, typename _E>
class id18 {
public:
  id18() = delete;
  id18(int n, _F &&f, _E &&e)
      : _n(n),
        id11(base::id26(n)),
        _size(1 << id11),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_F, _Monoid, _Monoid>, _Monoid>,
        "_F doesn't match the signature of the form "
        "'_Monoid(_Monoid,_Monoid)'");
    static_assert(std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
                  "_E doesn't match the signature of the form '_Monoid()'");
  }
  id18(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : id18(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator>
  id18(_InputIterator first, _InputIterator last, _F &&f, _E &&e)
      : id18((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator, typename _Gen>
  id18(_InputIterator first, _InputIterator last, _F &&f, _E &&e, _Gen &&gen)
      : id18((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~id18() = default;
  void set(int pos, const _Monoid &val) {

    assert(0 <= pos && pos < _n);

    _tree[pos += _size] = val;
    for (int i = 1; i <= id11; ++i) { _update(pos >> i); }
  }
  _Monoid get(int pos) const {

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
  int id16(int l, _Pred &&pred) const {

    assert(0 <= l && l <= _n);
    assert(pred(_ef()));

    static_assert(
        std::is_same_v<std::invoke_result_t<_Pred, _Monoid>, bool>,
        "Predicate function returning other than bool is not allowed.");
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
  template <typename _Pred>
  int id3(int r, _Pred &&pred) const {

    assert(0 <= r && r <= _n);

    static_assert(
        std::is_same_v<std::invoke_result_t<_Pred, _Monoid>, bool>,
        "Predicate function returning other than bool is not allowed.");
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
          return (r + 1) - _size;
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
template <typename _InputIterator, typename _F, typename _E>
id18(_InputIterator, _InputIterator, _F &&, _E &&)
    -> id18<typename std::iterator_traits<_InputIterator>::value_type, _F,
               _E>;
template <typename _InputIterator, typename _Gen, typename _F, typename _E>
id18(_InputIterator, _InputIterator, _F &&, _E &&, _Gen &&)
    -> id18<std::invoke_result_t<_Gen, typename std::iterator_traits<
                                              _InputIterator>::value_type>,
               _F, _E>;
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






namespace {
}
inline void solve() {
  int n,q;cin>>n>>q;
  auto f=[](int x,int y){return x+y;};
  auto g=[](int x,int y){return y==-1?x:y;};
  auto ef=[]{return 0;};
  auto eg=[]{return -1;};
  algo::id21 lsg(n,1,f,g,g,ef,eg);
  vector ans(n,false);
  algo::id18 sg(n,[](int x,int y){return algo::min(x,y);},[&]{return n;});
  for(int i=0;i<q;++i){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      if(x==0){lsg.apply(l-1,r,0);}
      else{
        int v=sg.get(l-1);
        sg.set(l-1,algo::min(v,r-1));
      }
    }else{
      int p;cin>>p;
      if(ans[p-1]){print("YES");}
      else if(lsg.get(p-1)==0){print("NO");}
      else{
        int lb=lsg.id3(p-1,[](int x){return x<1;});
        int rb=lsg.id16(p,[](int x){return x<1;});
        if(sg.query(lb,p)<rb){ans[p-1]=true;print("YES");}
        else{print("N/A");}
      }
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
