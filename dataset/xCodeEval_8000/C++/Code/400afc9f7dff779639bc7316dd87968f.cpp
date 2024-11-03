#ifdef _DEBUG
#define _GLIBCXX_DEBUG 1
#else
#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target(                                                            \
    "avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#endif


#include <immintrin.h> 



#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>


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
template <typename _Tp>
constexpr bool is_multipliable_v = is_multipliable<_Tp>::value;

template <typename _Tp>
constexpr bool is_integral_v = std::is_integral_v<_Tp>;
template <typename _Tp>
constexpr bool is_signed_v = std::is_signed_v<_Tp>;
template <typename _Tp, typename _U>
constexpr bool is_convertible_v = std::is_convertible_v<_Tp, _U>;
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
struct less_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp, typename = void>
struct greater_than_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct greater_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() >
                              std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool is_less_than_comparable_v = less_than_comparable<_Tp>::value;
template <typename _Tp>
constexpr bool is_greater_than_comparable_v = greater_than_comparable<_Tp>::value;
template <typename _Tp, typename = void>
struct equality_comparable {
  static constexpr bool value = false;
};
template <typename _Tp>
struct equality_comparable<_Tp,
                           std::void_t<decltype(std::declval<const _Tp &>() ==
                                                std::declval<const _Tp &>())>> {
  static constexpr bool value = true;
};
template <typename _Tp>
constexpr bool is_equality_comparable_v = equality_comparable<_Tp>::value;
}  

}  


namespace algo {
namespace base {


constexpr int __count_lz(int n) { return __builtin_clz(n); };
constexpr int __count_lz(long long n) { return __builtin_clzl(n); };


constexpr int __count_tz(int n) { return __builtin_ctz(n); };
constexpr int __count_tz(long long n) { return __builtin_ctzl(n); }


constexpr int __bzhi(int n, int i) {
  if (std::is_constant_evaluated()) {
    return n & ((1u << i) - 1);
  } else {
    return _bzhi_u32((unsigned)n, (unsigned)i);
  }
}
constexpr long long __bzhi(long long n, int i) {
  if (std::is_constant_evaluated()) {
    return n & ((1ull << i) - 1);
  } else {
    return _bzhi_u64((unsigned long long)n, (unsigned)i);
  }
}


constexpr int __blsmsk(int n) {
  if (std::is_constant_evaluated()) {
    return n ^ (n - 1);
  } else {
    return _blsmsk_u32((unsigned int)n);
  }
}
constexpr long long __blsmsk(long long n) {
  if (std::is_constant_evaluated()) {
    return n ^ (n - 1);
  } else {
    return _blsmsk_u64((unsigned long long)n);
  }
}


constexpr int __bit_width(int n) { return 32 - __count_lz(n); };
constexpr int __bit_width(long long n) { return 64 - __count_lz(n); };


constexpr int __bit_floor(int n) { return 1u << (31 - __count_lz(n)); };
constexpr long long __bit_floor(long long n) {
  return 1ull << (63 - __count_lz(n));
}


constexpr int __bit_ceil(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return __bit_floor(n - 1) << 1;
};
constexpr long long __bit_ceil(long long n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return __bit_floor(n - 1) << 1;
}


constexpr int __log2_floor(int n) { return 31 - __count_lz(n); };
constexpr int __log2_floor(long long n) { return 63 - __count_lz(n); };


constexpr int __log2_ceil(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return __log2_floor(n - 1) + 1;
}
constexpr int __log2_ceil(long long n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return __log2_floor(n - 1) + 1;
}


constexpr int __popcount(int n) { return __builtin_popcount(n); };
constexpr int __popcount(long long n) { return __builtin_popcountl(n); }


constexpr int __bit_parity(int n) { return __builtin_parity(n); };
} 

} 

namespace algo {
namespace base {
#define _LIKELY(x)   __builtin_expect(!!(x), 1)
#define _UNLIKELY(x) __builtin_expect(!!(x), 0)
}  

}  

namespace algo {

template <typename _Monoid, typename _X, typename _F, typename _Map,
          typename _G, typename _EF>
class lazy_segtree {
public:
  lazy_segtree(int n, _F &&f, _Map &&mapping, _G &&g, _EF &&ef)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size << 1, ef()),
        _lazy(_size),
        _marked(_size, false),
        _f(f),
        _map(mapping),
        _g(g),
        _ef(ef) {}
  lazy_segtree(const std::vector<_Monoid> &vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef)
      : lazy_segtree((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  lazy_segtree(std::vector<_Monoid> &&vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef) noexcept
      : lazy_segtree((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator>
  lazy_segtree(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef)
      : lazy_segtree((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator, typename _Gen>
  lazy_segtree(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef, _Gen &&gen)
      : lazy_segtree((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~lazy_segtree() = default;
  
  void set_val(int pos, const _Monoid &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = val;
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  
  _Monoid get_val(int pos) {
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
  void apply(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (_LIKELY(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i >= 1; --i) {
        if (i > tz_l) { _push(l >> i); }
        if (i > tz_r) { _push((r - 1) >> i); }
      }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = 1; i <= _lg2; ++i) {
        if (i > tz_l) { _update(l >> i); }
        if (i > tz_r) { _update((r - 1) >> i); }
      }
    }
  }
  _Monoid query(int l, int r) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    _Monoid resl = _ef(), resr = _ef();
    if (_LIKELY(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i >= 1; --i) {
        if (i > tz_l) { _push(l >> i); }
        if (i > tz_r) { _push((r - 1) >> i); }
      }
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
  int max_right(int l, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= l && l <= _n);
    assert(pred(_ef()));
#endif
    if (_LIKELY(l < _n)) {
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
  int min_left(int r, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= r && r <= _n);
    assert(pred(_ef()));
#endif
    if (_LIKELY(r > 0)) {
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
  int _n, _lg2, _size;
  std::vector<_Monoid> _tree;
  std::vector<_X> _lazy;
  std::vector<bool> _marked;
  _F _f;
  _Map _map;
  _G _g;
  _EF _ef;
};

template <typename _F, typename _Map, typename _G, typename _EF>
lazy_segtree(int, _F &&, _Map &&, _G &&, _EF &&) -> lazy_segtree<
    std::invoke_result_t<_EF>,
    typename base::function_traits<std::remove_reference_t<_G>>::result_type,
    _F, _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(const std::vector<_Monoid> &, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<std::invoke_result_t<_EF>,
                    typename base::function_traits<
                        std::remove_reference_t<_G>>::result_type,
                    _F, _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(std::vector<_Monoid> &&, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<_Monoid,
                    typename base::function_traits<
                        std::remove_reference_t<_G>>::result_type,
                    _F, _Map, _G, _EF>;
template <typename _InputIterator, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<typename std::iterator_traits<_InputIterator>::value_type,
                    typename base::function_traits<
                        std::remove_reference_t<_G>>::result_type,
                    _F, _Map, _G, _EF>;
template <typename _InputIterator, typename _Gen, typename _F, typename _Map,
          typename _G, typename _EF>
lazy_segtree(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&,
             _Gen &&)
    -> lazy_segtree<std::invoke_result_t<_Gen, typename std::iterator_traits<
                                                   _InputIterator>::value_type>,
                    typename base::function_traits<
                        std::remove_reference_t<_G>>::result_type,
                    _F, _Map, _G, _EF>;
}  

namespace algo {

template <typename _Monoid, typename _F, typename _E>
class segtree {
public:
  segtree() = delete;
  

  

  segtree(int n, _F &&f, _E &&e)
      : _n(n),
        _lg2(base::__log2_ceil(n)),
        _size(1 << _lg2),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {}
  segtree(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : segtree(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  segtree(std::vector<_Monoid> &&vec, _F &&f, _E &&e) noexcept
      : segtree(int(vec.size()), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <typename _InputIterator>
  segtree(_InputIterator first, _InputIterator last, _F &&f, _E &&e)
      : segtree((int)std::distance(first, last), std::forward<_F>(f),
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
  segtree(_InputIterator first, _InputIterator last, _F &&f, _E &&e, _Gen &&gen)
      : segtree((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(std::is_same_v<std::invoke_result_t<_E>, _Monoid>);
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  ~segtree() = default;
  
  void set_val(int pos, const _Monoid &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    _tree[pos += _size] = val;
    for (int i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  
  _Monoid get_val(int pos) const {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    return _tree[pos + _size];
  }
  
  _Monoid query(int l, int r) const {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
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
#ifdef _DEBUG
    assert(0 <= l && l <= _n);
    assert(pred(_ef()));
#endif
    if (_LIKELY(l < _n)) {
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
  
  template <typename Pred>
  int min_left(int r, Pred &&pred) const {
#ifdef _DEBUG
    assert(0 <= r && r <= _n);
#endif
    if (_LIKELY(r > 0)) {
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
          return r + 1 - _size;
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
segtree(const std::vector<_Monoid> &, _F &&, _E &&) -> segtree<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
segtree(std::vector<_Monoid> &&, _F &&, _E &&) -> segtree<_Monoid, _F, _E>;
template <typename _InputIterator, typename _F, typename _E>
segtree(_InputIterator, _InputIterator, _F &&, _E &&)
    -> segtree<typename std::iterator_traits<_InputIterator>::value_type, _F,
               _E>;
template <typename _InputIterator, typename _Gen, typename _F, typename _E>
segtree(_InputIterator, _InputIterator, _F &&, _E &&, _Gen &&)
    -> segtree<std::invoke_result_t<_Gen, typename std::iterator_traits<
                                              _InputIterator>::value_type>,
               _F, _E>;

template <typename _T, typename _X, typename _Map, typename _G>
class segtree_range_update {
public:
  segtree_range_update(int n, _Map &&mapping, _G &&g)
      : _n(n),
        _lg2(base::__log2_ceil(_n)),
        _size(1 << _lg2),
        _tree(_size),
        _lazy(_size),
        _marked(_size, false),
        _map(mapping),
        _g(g) {}
  segtree_range_update(const std::vector<_T> &vec, _Map &&mapping, _G &&g)
      : segtree_range_update((int)vec.size(), std::forward<_Map>(mapping),
                             std::forward<_G>(g)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  segtree_range_update(std::vector<_T> &&vec, _Map &&mapping, _G &&g) noexcept
      : segtree_range_update((int)vec.size(), std::forward<_Map>(mapping),
                             std::forward<_G>(g)) {
    std::move(vec.begin(), vec.end(), _tree.begin());
  }
  template <typename _InputIterator>
  segtree_range_update(_InputIterator first, _InputIterator last,
                       _Map &&mapping, _G &&g)
      : segtree_range_update((int)std::distance(first, last),
                             std::forward<_Map>(mapping), std::forward<_G>(g)) {
    std::copy(first, last, _tree.begin());
  }
  template <typename _InputIterator, typename _Gen>
  segtree_range_update(_InputIterator first, _InputIterator last,
                       _Map &&mapping, _G &&g, _Gen &&gen)
      : segtree_range_update((int)std::distance(first, last),
                             std::forward<_Map>(mapping), std::forward<_G>(g)) {
    std::transform(first, last, _tree.begin(), std::forward<_Gen>(gen));
  }
  ~segtree_range_update() = default;
  
  void set_val(int pos, const _T &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  
  _T query(int pos) {
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
  
  void apply(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (_LIKELY(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::__count_tz(l);
      const int tz_r = base::__count_tz(r);
      for (int i = _lg2; i >= 1; --i) {
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
  int _n, _lg2, _size;
  std::vector<_T> _tree;
  std::vector<_X> _lazy;
  std::vector<bool> _marked;
  _Map _map;
  _G _g;
};

template <typename _Map, typename _G>
segtree_range_update(int, _Map &&, _G &&)
    -> segtree_range_update<typename base::function_traits<_Map>::result_type,
                            typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _T, typename _Map, typename _G>
segtree_range_update(const std::vector<_T> &, _Map &&, _G &&)
    -> segtree_range_update<_T, typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _T, typename _Map, typename _G>
segtree_range_update(std::vector<_T> &&, _Map &&, _G &&)
    -> segtree_range_update<_T, typename base::function_traits<_G>::result_type,
                            _Map, _G>;
template <typename _InputIterator, typename _Map, typename _G>
segtree_range_update(_InputIterator, _InputIterator, _Map &&, _G &&)
    -> segtree_range_update<
        typename std::iterator_traits<_InputIterator>::value_type,
        typename base::function_traits<_G>::result_type, _Map, _G>;
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

template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
std::vector<int> argsort(const std::vector<_T> &v) {
  std::vector<int> ind(v.size(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}

template <typename _T,
          std::enable_if_t<base::is_less_than_comparable_v<_T>, bool> = true>
int argmin(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (_UNLIKELY(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}

template <typename _T,
          std::enable_if_t<base::is_greater_than_comparable_v<_T>, bool> = true>
int argmax(const std::vector<_T> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (_UNLIKELY(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}

template <typename _T, typename _Pred,
          std::enable_if_t<base::is_integral_v<_T>, bool> = true>
constexpr _T bisect(_T low, _T high, _Pred &&pred) {
#ifdef _DEBUG
  assert(low <= high);
#endif
  _T base = low, len = high - low;
  while (len > 1) {
    _T half = len >> 1;
    base += pred(base + half) ? half : 0;
    len -= half;
  }
  return base + pred(base);
}

void inverse_inplace(std::vector<int> &perm) {
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
#define DBG(x)                                                                 \
  cerr << "\033[1;32m" << #x << "\033[0m = "                                   \
       << "\033[1;34m" << x << "\033[0m\n";
#define EPS 1e-9
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI false
#define BITSIZE 21



namespace {} 




void solve() {
  int n, q;
  cin >> n >> q;
  auto f = [](int x, int y) { return x + y; };
  auto g = [](int x, int y) { return y; };
  auto ef = [] { return 0; };
  algo::lazy_segtree lsg(n, f, g, g, ef);
  for (int i = 0; i < n; ++i) {
    lsg.set_val(i, 1);
  }
  vector ans(n, false);
  algo::segtree sg(
      n, [](int x, int y) { return algo::min(x, y); }, [&] { return n; });
  for (int i = 0; i < q; ++i) {
    int t;
    cin >> t;
    if (t == 0) {
      int l, r, x;
      cin >> l >> r >> x;
      if (x == 0) {
        lsg.apply(l - 1, r, 0);
      } else {
        int v = sg.get_val(l - 1);
        sg.set_val(l - 1, algo::min(v, r - 1));
      }
    } else {
      int p;
      cin >> p;
      if (ans[p - 1]) {
        cout << "YES\n";
      } else if (lsg.get_val(p - 1) == 0) {
        cout << "NO\n";
      } else {
        int lb = lsg.min_left(p - 1, [](int x) { return x < 1; });
        int rb = lsg.max_right(p, [](int x) { return x < 1; });
        if (sg.query(lb, p) < rb) {
          ans[p - 1] = true;
          cout << "YES\n";
        } else {
          cout << "N/A\n";
        }
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
