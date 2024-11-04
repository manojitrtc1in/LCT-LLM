#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#pragma GCC optimize("O3,inline,unroll-loops")
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
  std::cout<<'\n';
}
void flush() noexcept { std::cout.flush(); }
#define debug(x) \
  std::cerr << "Line " << __LINE__ << ":: " \
            << "\033[1;32m" << #x << "\033[0m = "; \
  dbg::view(x); \
  std::cerr << '\n';
namespace algo {
namespace base {
template <typename _Tp>
concept Integral = std::is_integral_v<_Tp>;
template <typename _Tp>
concept SignedIntegral = std::is_signed_v<_Tp>;
template <typename _Tp>
concept UnsignedIntegral = std::is_unsigned_v<_Tp>;
template <typename _Tp>
concept Addable = requires(_Tp &a, const _Tp &b) {
  a += b;
};
template <typename _Tp>
concept Multipliable = requires(_Tp &a, const _Tp &b) {
  a *= b;
};
template <typename _Tp, typename _Up>
concept ConvertibleTo = std::is_convertible_v<_Tp, _Up>;
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
template <typename _Ret, typename... _Args>
struct function_traits<_Ret(_Args...)> {
  static constexpr size_t arity = sizeof...(_Args);
  using result_type = _Ret;
  template <size_t I>
  struct arg {
    using type = typename std::tuple_element<I, std::tuple<_Args...>>::type;
  };
};
template <typename _Fn>
using invoke_result_t = typename function_traits<_Fn>::result_type;
template <typename _Fn, typename... _Args>
concept Callable = std::invocable<_Fn, _Args...>;
template <typename _Fn, typename _Arg>
concept UnaryOp = std::invocable<_Fn, _Arg>
    &&std::is_same_v<std::invoke_result_t<_Fn, _Arg>, _Arg>;
template <typename _Fn, typename _Arg>
concept BinaryOp = std::invocable<_Fn, _Arg, _Arg>
    &&std::is_same_v<std::invoke_result_t<_Fn, _Arg, _Arg>, _Arg>;
template <typename _Fn, typename _Arg>
concept UnaryPredicate = std::invocable<_Fn, _Arg>
    &&std::is_same_v<std::invoke_result_t<_Fn, _Arg>, bool>;
template <typename _Tp>
concept LessThanComparable = requires(_Tp a, _Tp b) {
  { a < b }
  ->ConvertibleTo<bool>;
  { b < a }
  ->ConvertibleTo<bool>;
};
template <typename _Tp>
concept EqualityComparable = requires(_Tp a, _Tp b) {
  { a == b }
  ->ConvertibleTo<bool>;
  { a != b }
  ->ConvertibleTo<bool>;
};
template <typename _Tp>
concept InputIterator = std::input_iterator<_Tp>;
}
}
namespace algo {
namespace base {
template <typename _Tp>
constexpr _Tp __maxi(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
constexpr _Tp __mini(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
constexpr void __swap(_Tp &a, _Tp &b) {
  _Tp tp = a;
  a = b;
  b = tp;
}
template <typename _Tp>
constexpr void __swap(_Tp *a, _Tp *b) {
  _Tp tp = *a;
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
template <base::LessThanComparable _Tp>
constexpr _Tp max(const _Tp &a, const _Tp &b) {
  return base::__maxi(a, b);
}
template <base::LessThanComparable _Tp>
constexpr _Tp min(const _Tp &a, const _Tp &b) {
  return base::__mini(a, b);
}
template <typename _Tp>
constexpr void swap(_Tp &a, _Tp &b) {
  base::__swap(a, b);
}
template <typename _Tp>
constexpr void swap(_Tp *a, _Tp *b) {
  base::__swap(a, b);
}
template <base::LessThanComparable _Tp>
std::vector<int> argsort(const std::vector<_Tp> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <base::LessThanComparable _Tp>
void sort_unique_erase(std::vector<_Tp> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <base::LessThanComparable _Tp>
int argmin(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::LessThanComparable _Tp>
int argmax(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::Integral _Tp, base::UnaryPredicate<_Tp> _Pred>
constexpr _Tp bisect(_Tp low, _Tp high, _Pred &&pred) {
  while (low < high) {
    _Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <base::LessThanComparable _Tp>
int lower_bound(const std::vector<_Tp> &vec, const _Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <base::LessThanComparable _Tp>
int upper_bound(const std::vector<_Tp> &vec, const _Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::upper_bound(vec.begin(), vec.end(), x));
}
void inverse(std::vector<int> &perm) {
  const int n = (int)perm.size();
  std::vector<int> out(n);
  for (int i = 0; i < n; ++i) { out[perm[i]] = i; }
  perm = std::move(out);
}
template <typename _Tp>
void permute(std::vector<_Tp> &vec, const std::vector<int> &perm) {
  std::vector<_Tp> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
template <base::Integral _Tp>
constexpr int pow_m1(_Tp n) {
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
template <typename _Monoid, typename _X, base::BinaryOp<_Monoid> _F,
          base::BinaryOp<_X> _G, base::Callable<_Monoid, _X> _Map,
          base::Callable<> _EF, base::Callable<> _EG>
requires std::is_same_v<std::invoke_result_t<_Map, _Monoid, _X>, _Monoid>
    &&std::is_same_v<std::invoke_result_t<_EF>, _Monoid>
        &&std::is_same_v<std::invoke_result_t<_EG>, _X> class lazy_segtree {
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
        _eg(eg) {
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
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
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = val;
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  _Monoid get(int pos) {
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos];
  }
  void apply(int pos, const _X &arg) {
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  void apply_commutative(int pos, const _X &arg) {
    pos += _size;
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  void apply(int l, int r, const _X &arg) {
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
  template <base::UnaryPredicate<_Monoid> _Pred>
  int bisect_right(int l, _Pred &&pred) {
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
  template <base::UnaryPredicate<_Monoid> _Pred>
  int bisect_left(int r, _Pred &&pred) {
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
          return r + 1 - _size;
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
template <typename _Tp, typename _X, base::BinaryOp<_X> _G,
          base::Callable<_Tp, _X> _Map, base::Callable<> _EG>
requires std::is_same_v<std::invoke_result_t<_Map, _Tp, _X>, _Tp> &&
    std::is_same_v<std::invoke_result_t<_EG>,
                   _X> class lazy_segtree<_Tp, _X, void, _G, _Map, void, _EG> {
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
  lazy_segtree(int n, const _Tp &init, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size, init),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  lazy_segtree(const std::vector<_Tp> &vec, _G &&g, _Map &&mapping, _EG &&eg)
      : lazy_segtree(vec.size(), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  void set(int pos, const _Tp &val) {
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  _Tp get(int pos) {
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos - _size];
  }
  void apply(int pos, const _X &arg) {
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = _map(_tree[pos - _size], arg);
  }
  void apply_commutative(int pos, const _X &arg) {
    _tree[pos] = _map(_tree[pos], arg);
  }
  void apply(int l, int r, const _X &arg) {
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
  std::vector<_Tp> _tree;
  std::vector<_X> _lazy;
  _G _g;
  _Map _map;
  _EG _eg;
};
template <typename _F, typename _G, typename _Map, typename _EF, typename _EG>
lazy_segtree(int, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> lazy_segtree<std::invoke_result_t<_EF>, std::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
lazy_segtree(int, const _Monoid &, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> lazy_segtree<_Monoid, std::invoke_result_t<_EG>, _F, _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
lazy_segtree(const std::vector<_Monoid> &, _F &&, _G &&, _Map &&, _EF &&,
             _EG &&)
    -> lazy_segtree<std::invoke_result_t<_EF>, std::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _G, typename _Map, typename _EG>
lazy_segtree(int, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<base::invoke_result_t<_Map>, std::invoke_result_t<_EG>,
                    void, _G, _Map, void, _EG>;
template <typename _Tp, typename _G, typename _Map, typename _EG>
lazy_segtree(int, const _Tp &, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<_Tp, std::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
template <typename _Tp, typename _G, typename _Map, typename _EG>
lazy_segtree(const std::vector<_Tp> &vec, _G &&, _Map &&, _EG &&)
    -> lazy_segtree<_Tp, std::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
}
namespace algo {
template <typename _Monoid, base::BinaryOp<_Monoid> _F, base::Callable<> _E>
requires std::is_same_v<std::invoke_result_t<_E>, _Monoid> class segtree {
public:
  segtree() = delete;
  segtree(int n, _F &&f, _E &&e)
      : _n(n),
        _lg2(base::__log2_ceil(n)),
        _size(1 << _lg2),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {}
  segtree(int n, const _Monoid &init, _F &&f, _E &&e)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size << 1, init),
        _f(f),
        _ef(e) {
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  segtree(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : segtree(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <base::InputIterator Iter>
  segtree(Iter first, Iter last, _F &&f, _E &&e)
      : segtree((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~segtree() = default;
  void set(int pos, const _Monoid &val) {
    _tree[pos += _size] = val;
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  _Monoid get(int pos) const {
    return _tree[pos + _size];
  }
  _Monoid query(int l, int r) const {
    _Monoid resl = _ef(), resr = _ef();
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = _f(resl, _tree[l++]); }
      if (r & 0x01) { resr = _f(_tree[--r], resr); }
    }
    return _f(resl, resr);
  }
  _Monoid query() const { return _tree[1]; }
  template <base::UnaryPredicate<_Monoid> _Pred>
  int bisect_right(int l, _Pred &&pred) const {
    if (base::likely(l < _n)) {
      l += _size;
      _Monoid cur = _ef();
      do {
        l >>= base::__count_tz(l);
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
  template <base::UnaryPredicate<_Monoid> _Pred>
  int bisect_left(int r, _Pred &&pred) const {
    if (base::likely(r > 0)) {
      r += _size;
      _Monoid cur = _ef();
      do {
        r >>= base::__count_tz(r);
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
  int _n, _lg2, _size;
  std::vector<_Monoid> _tree;
  _F _f;
  _E _ef;
};
template <typename _F, typename _E>
segtree(int, _F &&, _E &&) -> segtree<std::invoke_result_t<_E>, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
segtree(int, const _Monoid &, _F &&, _E &&) -> segtree<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
segtree(const std::vector<_Monoid> &, _F &&, _E &&) -> segtree<_Monoid, _F, _E>;
template <typename _Iter, typename _F, typename _E>
segtree(_Iter, _Iter, _F &&, _E &&)
    -> segtree<typename std::iterator_traits<_Iter>::value_type, _F, _E>;
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
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI 0
namespace {}
inline void solve() noexcept {
  int n,q;cin>>n>>q;
  auto f=[](int x,int y){return x+y;};
  auto g=[](int x,int y){return y==-1?x:y;};
  auto ef=[]{return 0;};
  auto eg=[]{return -1;};
  algo::lazy_segtree lsg(n,1,f,g,g,ef,eg);
  vector ans(n,false);
  algo::segtree sg(n,[](int x,int y){return algo::min(x,y);},[&]{return n;});
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
        int lb=lsg.bisect_left(p-1,[](int x){return x<1;});
        int rb=lsg.bisect_right(p,[](int x){return x<1;});
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
  solve();
  return 0;
}
