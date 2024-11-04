#ifdef _DEBUG
#define _GLIBCXX_DEBUG 1
#else
#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC optimize("O3,inline,unroll-loops")
#endif
#include <immintrin.h>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
namespace io {
template <typename _Tp>
void __printel(const _Tp &val) noexcept {
  std::cout << val;
}
template <typename _Tp>
void __printel(const std::vector<_Tp> &vec) noexcept {
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) {
    if (i) std::cout << ' ';
    std::cout << vec[i];
  }
}
template <typename _First, typename _Second>
void __printel(const std::pair<_First, _Second> &p) noexcept {
  std::cout << p.first << ' ' << p.second;
}
template <typename... _Args, std::size_t... Is>
void __print_tup(const std::tuple<_Args...> &tup,
                 std::index_sequence<0, Is...>) {
  io::__printel(std::get<0>(tup));
  ((std::cout << ' ', io::__printel(std::get<Is>(tup))), ...);
}
template <typename... _Args>
void __printel(const std::tuple<_Args...> &tup) noexcept {
  __print_tup(tup, std::make_index_sequence<sizeof...(_Args)>{});
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
  io::__printel(head);
  ((std::cout << ' ', io::__printel(rest)), ...);
  std::cout << '\n';
}
#define debug(x) \
  std::cerr << "Line " << __LINE__ << ":: " \
            << "\033[1;32m" << #x << "\033[0m = "; \
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
constexpr bool is_multipliable_v = is_multipliable<_Tp>::value;
template <typename _Tp>
constexpr bool is_addable_v = is_addable<_Tp>::value;
template <typename _Tp>
constexpr bool is_integral_v = std::is_integral_v<_Tp>;
template <typename _Tp>
constexpr bool is_signed_v = std::is_signed_v<_Tp>;
template <typename _Tp, typename _U>
constexpr bool is_convertible_v = std::is_convertible_v<_Tp, _U>;
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
constexpr bool is_less_than_comparable_v = is_less_than_comparable<_Tp>::value;
template <typename _Tp>
constexpr bool is_greater_than_comparable_v =
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
constexpr bool is_equality_comparable_v = is_equality_comparable<_Tp>::value;
}
}
namespace algo {
namespace base {
template <typename _T>
constexpr _T __maxi(const _T &a, const _T &b) {
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
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
constexpr _T max(const _T &a, const _T &b) {
  return base::__maxi(a, b);
}
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
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
    std::enable_if_t<base::is_addable_v<_Value>, bool> = true>
constexpr _Value sum(_InputIterator first, _InputIterator last,
                     const _Value &init = {}) {
  return std::accumulate(first, last, init);
};
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
std::vector<int> argsort(const std::vector<_T> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
void sort_unique_erase(std::vector<_T> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
int argmin(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T,
          std::enable_if_t<base::is_greater_than_comparable_v<_T>, bool> = true>
int argmax(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <typename _T, typename _Pred,
          std::enable_if_t<base::is_integral_v<_T>, bool> = true>
constexpr _T bisect(_T low, _T high, _Pred &&pred) {
#ifdef _DEBUG
  assert(low <= high);
#endif
  while (low < high) {
    _T mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
int lower_bound(const std::vector<_T> &vec, const _T &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
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
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
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
template <typename _T, std::enable_if_t<base::is_integral_v<_T>, bool> = true>
constexpr int pow_m1(_T n) {
  return -(n & 1) | 1;
}
template <>
constexpr int pow_m1<bool>(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace base {
constexpr int __count_lz(int n) { return __builtin_clz(n); };
constexpr int __count_lz(long long n) { return __builtin_clzll(n); };
constexpr int __count_tz(int n) { return __builtin_ctz(n); };
constexpr int __count_tz(long long n) { return __builtin_ctzll(n); }
constexpr int __bit_width(int n) { return 32 - __count_lz(n); };
constexpr int __bit_width(long long n) { return 64 - __count_lz(n); };
constexpr int __bit_floor(int n) { return 1u << (31 - __count_lz(n)); };
constexpr long long __bit_floor(long long n) {
  return 1ull << (63 - __count_lz(n));
}
constexpr int __bit_ceil(int n) {
  if (n == 0 || n == 1) { return 1; }
  return __bit_floor(n - 1) << 1;
};
constexpr long long __bit_ceil(long long n) {
  if (n == 0 || n == 1) { return 1; }
  return __bit_floor(n - 1) << 1;
}
constexpr int __log2_floor(int n) { return 31 - __count_lz(n); };
constexpr int __log2_floor(long long n) { return 63 - __count_lz(n); };
constexpr int __log2_ceil(int n) {
  if (n == 0 || n == 1) { return 0; }
  return __log2_floor(n - 1) + 1;
}
constexpr int __log2_ceil(long long n) {
  if (n == 0 || n == 1) { return 0; }
  return __log2_floor(n - 1) + 1;
}
constexpr int __popcount(int n) { return __builtin_popcount(n); };
constexpr int __popcount(long long n) { return __builtin_popcountll(n); }
constexpr int __bit_parity(int n) { return __builtin_parity(n); };
}
}
namespace algo {
template <typename _Monoid, typename _X, typename _F, typename _G,
          typename _Map, typename _EF, typename _EG>
class lazy_segtree {
public:
  lazy_segtree(int n, _F &&f, _G &&g, _Map &&mapping, _EF &&ef, _EG &&eg)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size << 1, ef()),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {}
  lazy_segtree(int n, const _Monoid &init, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size << 1, init),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {}
  lazy_segtree(const std::vector<_Monoid> &vec, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : lazy_segtree((int)vec.size(), std::forward<_F>(f), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EF>(ef),
                     std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~lazy_segtree() = default;
  void set(int pos, const _Monoid &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = val;
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  _Monoid get(int pos) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos];
  }
  void apply(int pos, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  void apply_commutative(int pos, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  void apply(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i > tz_l; --i) { _push(l >> i); }
      for (int i = _lg2; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= _lg2; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= _lg2; ++i) { _update((r - 1) >> i); }
    }
  }
  void apply_commutative(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= _lg2; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= _lg2; ++i) { _update((r - 1) >> i); }
    }
  }
  _Monoid query(int l, int r) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    _Monoid resl = _ef(), resr = _ef();
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i > tz_l; --i) { _push(l >> i); }
      for (int i = _lg2; i > tz_r; --i) { _push((r - 1) >> i); }
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
  int bisect_right(int l, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= l && l <= _n);
    assert(pred(_ef()));
#endif
    if (base::likely(l < _n)) {
      l += _size;
      for (int i = _lg2; i >= 1; --i) { _push(l >> i); }
      _Monoid cur = _ef();
      do {
        l >>= base::__count_tz(l);
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
  int bisect_left(int r, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= r && r <= _n);
    assert(pred(_ef()));
#endif
    if (base::likely(r > 0)) {
      r += _size;
      for (int i = _lg2; i >= 1; --i) { _push(r - 1 >> i); }
      _Monoid cur = _ef();
      do {
        r >>= base::__count_tz(r);
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
  int _n, _lg2, _size;
  std::vector<_Monoid> _tree;
  std::vector<_X> _lazy;
  _F _f;
  _G _g;
  _Map _map;
  _EF _ef;
  _EG _eg;
};
template <typename _T, typename _X, typename _G, typename _Map, typename _EG>
class lazy_segtree<_T, _X, void, _G, _Map, void, _EG> {
public:
  lazy_segtree(int n, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  lazy_segtree(int n, const _T &init, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size, init),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  lazy_segtree(const std::vector<_T> &vec, _G &&g, _Map &&mapping, _EG &&eg)
      : lazy_segtree(vec.size(), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  void set(int pos, const _T &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  _T get(int pos) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos - _size];
  }
  void apply(int pos, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = _map(_tree[pos - _size], arg);
  }
  void apply_commutative(int pos, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    _tree[pos] = _map(_tree[pos], arg);
  }
  void apply(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i > tz_l; --i) { _push(l >> i); }
      for (int i = _lg2; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
    }
  }
  void apply_commutative(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
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
  int _n, _lg2, _size;
  std::vector<_T> _tree;
  std::vector<_X> _lazy;
  _G _g;
  _Map _map;
  _EG _eg;
};
template <typename _F, typename _G, typename _Map, typename _EF, typename _EG>
lazy_segtree(int, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> lazy_segtree<base::invoke_result_t<_EF>, base::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
lazy_segtree(int, const _Monoid &, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> lazy_segtree<_Monoid, base::invoke_result_t<_EG>, _F, _G, _Map, _EF,
                    _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
lazy_segtree(const std::vector<_Monoid> &, _F &&, _G &&, _Map &&, _EF &&,
             _EG &&)
    -> lazy_segtree<base::invoke_result_t<_EF>, base::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _G, typename _Map, typename _EG>
lazy_segtree(int, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<base::invoke_result_t<_Map>, base::invoke_result_t<_EG>,
                    void, _G, _Map, void, _EG>;
template <typename _T, typename _G, typename _Map, typename _EG>
lazy_segtree(int, const _T &, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<_T, base::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
template <typename _T, typename _G, typename _Map, typename _EG>
lazy_segtree(const std::vector<_T> &vec, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<_T, base::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
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
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI false
#define BITSIZE 21
namespace {}
inline void solve() {
  int n,k;cin>>n>>k;
  vector<wint>cnt(n+2),bn(n+1);
  for(int i=1;i<=n;++i){cin>>bn[i];}
  using node=struct{wint a,b;};
  auto g=[](node f,node s){return node{f.a+s.a,f.b+s.b};};
  auto eg=[]{return node{0,0};};
  algo::lazy_segtree lsg(n+1,g,g,eg);
  wint ans=0;
  for(int i=n;i>0;--i){
    auto[a,b]=lsg.get(i);
    wint v=i*a+b;
    bn[i]-=v;
    if(bn[i]>0){
      int dl=algo::max(i-k+1,1);
      wint p=(bn[i]+i-dl)/(i-dl+1);
      lsg.apply_commutative(dl,i,node{p,-p*(dl-1)});
      ans+=p;
    }
  }
  print(ans);
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
