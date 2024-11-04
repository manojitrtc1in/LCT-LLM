#ifdef _DEBUG
#define _GLIBCXX_DEBUG 1
#else
#undef _GLIBCXX_DEBUG
#pragma GCC optimize("Ofast,inline,unroll-loops")
#pragma GCC target("movbe")
#pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("avx,avx2,f16c,fma,sse3,ssse3,sse4.1,sse4.2")
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


namespace algo {
template <typename _Tp, typename = void> struct is_multipliable {
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

template <typename _Tp> constexpr bool is_integral_v = std::is_integral_v<_Tp>;
template <typename T>
struct function_traits : public function_traits<decltype(&T::operator())> {};





template <typename _Fn, typename _Ret, typename... _Args>
struct function_traits<_Ret (_Fn::*)(_Args...) const>


{
  enum { arity = sizeof...(_Args) };
  


  typedef _Ret result_type;

  template <size_t i> struct arg {
    typedef typename std::tuple_element<i, std::tuple<_Args...>>::type type;
    

    

  };
};
template <typename _Tp, typename = void> struct less_than_comparable {
  enum { value = 0 };
};
template <typename _Tp>
struct less_than_comparable<
    _Tp, std::void_t<decltype(std::declval<const _Tp &>() <
                              std::declval<const _Tp &>())>> {
  enum { value = 1 };
};
} 


namespace algo {
constexpr int __count_lz(int n) { return __builtin_clz(n); };
constexpr int __count_tz(int n) { return __builtin_ctz(n); };


constexpr int __bit_width(int n) { return 32 - __builtin_clz(n); };
constexpr int __bit_width_ceil(int n) {
  return n ? __bit_width(n - 1) + 1 : 0;
};
constexpr int __bit_floor(int n) { return 1u << (31 - __count_lz(n)); };
constexpr int __bit_ceil(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  return __bit_floor(n - 1) << 1;
};
constexpr int __log2_floor(int n) { return 31 - __count_lz(n); };
constexpr int __log2_ceil(int n) {
  if (n == 0 || n == 1) {
    return 0;
  }
  return __log2_floor(n - 1) + 1;
}
constexpr int __popcount(int n) { return __builtin_popcount(n); };
constexpr int __bit_parity(int n) { return __builtin_parity(n); };
} 

namespace algo {
template <typename _Monoid, typename _F, typename _E> class segtree {
public:
  segtree() = delete;
  

  

  segtree(int n, _F &&f, _E &&e)
      : _n(n), _lg2(__log2_ceil(n)), _size(1 << _lg2), _tree(_size << 1, e()),
        _f(f), _ef(e) {}
  segtree(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : segtree(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  segtree(std::vector<_Monoid> &&vec, _F &&f, _E &&e) noexcept
      : segtree(int(vec.size()), std::forward<_F>(f), std::forward<_E>(e)) {
    static_assert(
        std::is_same_v<std::invoke_result_t<_E>, _Monoid>,
        "return type of _E must be compatible to value type of the array!");
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
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
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator, typename _Gen>
  segtree(_InputIterator first, _InputIterator last, _F &&f, _E &&e, _Gen &&gen)
      : segtree((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    static_assert(std::is_same_v<std::invoke_result_t<_E>, _Monoid>);
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  ~segtree() = default;
  void set_val(int pos, const _Monoid &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    _tree[pos += _size] = val;
    for (int i = 1; i <= _lg2; ++i) {
      _update(pos >> i);
    }
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
      if (l & 0x01) {
        resl = _f(resl, _tree[l++]);
      }
      if (r & 0x01) {
        resr = _f(_tree[--r], resr);
      }
    }
    return _f(resl, resr);
  }
  

  _Monoid query() const { return _tree[1]; }
  template <typename _Pred> int max_right(int l, _Pred &&pred) const {
#ifdef _DEBUG
    assert(0 <= l && l <= _n);
    assert(pred(_ef()));
#endif
    if (l < _n) {
      l += _size;
      _Monoid cur = _ef();
      do {
        while (!(l & 0x01))
          l >>= 1;
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            l <<= 1;
            if (pred(_f(cur, _tree[l]))) {
              cur = _f(cur, _tree[l++]);
            }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) - l);
    }
    return _n;
  }
  template <typename Pred> int min_left(int r, Pred &&pred) const {
#ifdef _DEBUG
    assert(0 <= r && r <= _n);
#endif
    if (r > 0) {
      r += _size;
      _Monoid cur = _ef();
      do {
        --r;
        while (r > 1 && (r & 0x01))
          r >>= 1;
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            r <<= 1;
            r |= 1;
            if (pred(_f(_tree[r], cur))) {
              cur = _f(_tree[r--], cur);
            }
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
















template <typename _Monoid, typename _X, typename _F, typename _Map,
          typename _G, typename _EF>
class lazy_segtree {
public:
  lazy_segtree(int n, _F &&f, _Map &&mapping, _G &&g, _EF &&ef)
      : _n(n), _lg2(__log2_ceil(_n)), _size(1 << _lg2), _tree(_size << 1, ef()),
        _lazy(_size), _marked(_size, false), _f(f), _map(mapping), _g(g),
        _ef(ef) {}
  lazy_segtree(const std::vector<_Monoid> &vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef)
      : lazy_segtree((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  lazy_segtree(std::vector<_Monoid> &&vec, _F &&f, _Map &&mapping, _G &&g,
               _EF &&ef) noexcept
      : lazy_segtree((int)vec.size(), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::move(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator>
  lazy_segtree(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef)
      : lazy_segtree((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  template <typename _InputIterator, typename _Gen>
  lazy_segtree(_InputIterator first, _InputIterator last, _F &&f,
               _Map &&mapping, _G &&g, _EF &&ef, _Gen &&gen)
      : lazy_segtree((int)std::distance(first, last), std::forward<_F>(f),
                     std::forward<_Map>(mapping), std::forward<_G>(g),
                     std::forward<_EF>(ef)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) {
      _update(i);
    }
  }
  ~lazy_segtree() = default;
  void set_val(int pos, const _Monoid &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) {
      _push(pos >> i);
    }
    _tree[pos] = val;
    for (int i = 1; i <= _lg2; ++i) {
      _update(pos >> i);
    }
  }
  _Monoid get_val(int pos) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) {
      _push(pos >> i);
    }
    return _tree[pos];
  }
  void apply(int pos, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _n);
#endif
    pos += _size;
    for (int i = _lg2; i >= 1; --i) {
      _push(pos >> i);
    }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= _lg2; ++i) {
      _update(pos >> i);
    }
  }
  void apply(int l, int r, const _X &arg) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    if (l < r) {
      l += _size;
      r += _size;
      for (int i = _lg2; i >= 1; --i) {
        if (((l >> i) << i) != l) {
          _push(l >> i);
        }
        if (((r >> i) << i) != r) {
          _push((r - 1) >> i);
        }
      }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) {
          _apply_subtree(_l++, arg);
        }
        if (_r & 0x01) {
          _apply_subtree(--_r, arg);
        }
      }
      for (int i = 1; i <= _lg2; ++i) {
        if (((l >> i) << i) != l) {
          _update(l >> i);
        }
        if (((r >> i) << i) != r) {
          _update((r - 1) >> i);
        }
      }
    }
  }
  _Monoid query(int l, int r) {
#ifdef _DEBUG
    assert(0 <= l && l <= r && r <= _n);
#endif
    _Monoid resl = _ef(), resr = _ef();
    if (l < r) {
      l += _size, r += _size;
      for (int i = _lg2; i >= 1; --i) {
        if (((l >> i) << i) != l) {
          _push(l >> i);
        }
        if (((r >> i) << i) != r) {
          _push((r - 1) >> i);
        }
      }
      while (l < r) {
        if (l & 0x01) {
          resl = _f(resl, _tree[l++]);
        }
        if (r & 0x01) {
          resr = _f(_tree[--r], resr);
        }
        l >>= 1;
        r >>= 1;
      }
    }
    return _f(resl, resr);
  }
  _Monoid query() const { return _tree[1]; }
  template <typename _Pred> int max_right(int l, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= l && l <= _n);
    assert(pred(_ef()));
#endif
    if (l < _n) {
      l += _size;
      for (int i = _lg2; i >= 1; --i) {
        _push(l >> i);
      }
      _Monoid cur = _ef();
      do {
        while (!(l & 0x01))
          l >>= 1;
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            _push(l);
            l <<= 1;
            if (pred(_f(cur, _tree[l]))) {
              cur = _f(cur, _tree[l++]);
            }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) != l);
    }
    return _n;
  }
  template <typename _Pred> int min_left(int r, _Pred &&pred) {
#ifdef _DEBUG
    assert(0 <= r && r <= _n);
    assert(pred(_ef()));
#endif
    if (r > 0) {
      r += _size;
      for (int i = _lg2; i >= 1; --i) {
        _push(r - 1 >> i);
      }
      _Monoid cur = _ef();
      do {
        --r;
        while (r > 1 && (r & 0x01))
          r >>= 1;
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            _push(r);
            r <<= 1;
            r |= 1;
            if (pred(_f(_tree[r], cur))) {
              cur = _f(_tree[r--], cur);
            }
          }
          return r + 1 - _size;
        }
        cur = _f(_tree[r], cur);
      } while ((r & -r) != r);
    }
    return 0;
  }

private:
  void _update(int v) { _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]); }
  void _apply_subtree(int v, const _X &arg) {
    _tree[v] = _map(_tree[v], arg);
    if (v < _size && _marked[v]) {
      _lazy[v] = _g(_lazy[v], arg);
    }
    if (v < _size && !_marked[v]) {
      _lazy[v] = arg;
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
    typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
    _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(const std::vector<_Monoid> &, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<
        std::invoke_result_t<_EF>,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _Monoid, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(std::vector<_Monoid> &&, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<
        _Monoid,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _InputIterator, typename _F, typename _Map, typename _G,
          typename _EF>
lazy_segtree(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&)
    -> lazy_segtree<
        typename std::iterator_traits<_InputIterator>::value_type,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;
template <typename _InputIterator, typename _Gen, typename _F, typename _Map,
          typename _G, typename _EF>
lazy_segtree(_InputIterator, _InputIterator, _F &&, _Map &&, _G &&, _EF &&,
             _Gen &&)
    -> lazy_segtree<
        std::invoke_result_t<
            _Gen, typename std::iterator_traits<_InputIterator>::value_type>,
        typename function_traits<std::remove_reference_t<_G>>::result_type, _F,
        _Map, _G, _EF>;


template <typename _T> class bitree {
public:
  bitree() = delete;
  explicit bitree(int n) : _size(n), _bit(_size + 1) {}
  void add(int pos, const _T &val) {
#ifdef _DEBUG
    assert(0 <= pos && pos < _size);
#endif
    for (++pos; pos <= _size; pos += pos & -pos) {
      _bit[pos] += val;
    }
  }
  

  _T sum(int r) const {
    _T res{};
    for (++r; r > 0; r -= r & -r) {
      res += _bit[r];
    }
    return res;
  }
  

  _T sum(int l, int r) const { return sum(r) - sum(l - 1); }
  int lower_bound(const _T &val) const {
    _T sum = 0;
    int pos = 0;
    for (int i = __log2_floor(_size); i >= 0; --i) {
      if (pos + (1 << i) <= _size && sum + _bit[pos + (1 << i)] < val) {
        pos |= 1 << i;
        sum += _bit[pos];
      }
    }
    return pos;
  }
  int upper_bound(const _T &val) const {
    _T sum = 0;
    int pos = 0;
    for (int i = __log2_floor(_size); i >= 0; --i) {
      if (pos + (1 << i) <= _size && sum + _bit[pos + (1 << i)] <= val) {
        pos |= 1 << i;
        sum += _bit[pos];
      }
    }
    return pos;
  }

private:
  int _size;
  std::vector<_T> _bit;
};








template <typename _T, typename _Fn> class sparse_table {
public:
  sparse_table(const std::vector<_T> &vec, _Fn &&f)
      : _size((int)vec.size()), _lg_size(__log2_floor(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), _lg2(_size), _f(f) {
    std::copy(vec.begin(), vec.end(), _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      _lg2[i] = _lg2[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  sparse_table(std::vector<_T> &&vec, _Fn &&f) noexcept
      : _size((int)vec.size()), _lg_size(__log2_floor(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), _lg2(_size), _f(f) {
    std::move(vec.begin(), vec.end(), _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      _lg2[i] = _lg2[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  template <typename _InputIterator>
  sparse_table(_InputIterator first, _InputIterator last, _Fn &&f)
      : _size((int)std::distance(first, last)), _lg_size(__log2_floor(_size)),
        _spt(_lg_size + 1, std::vector<_T>(_size)), _lg2(_size), _f(f) {
    std::copy(first, last, _spt.front().begin());
    for (int i = 1; i < _size; ++i) {
      _lg2[i] = _lg2[i - 1 >> 1] + 1;
    }
    for (int j = 1; j <= _lg_size; ++j) {
      for (int i = 0; i + (1 << j) <= _size; ++i) {
        _spt[j][i] = _f(_spt[j - 1][i], _spt[j - 1][i + (1 << j - 1)]);
      }
    }
  }
  _T query(int l, int r) const {
#ifdef _DEBUG
    assert(l <= r);
#endif
    const int lgl = _lg2[r - l];
    return _f(_spt[lgl][l], _spt[lgl][r - (1 << lgl) + 1]);
  }

private:
  int _size, _lg_size;
  std::vector<std::vector<_T>> _spt;
  std::vector<int> _lg2;
  _Fn _f;
};
template <typename _T, typename _Fn>
sparse_table(const std::vector<_T> &, _Fn &&) -> sparse_table<_T, _Fn>;
template <typename _T, typename _Fn>
sparse_table(std::vector<_T> &&, _Fn &&) -> sparse_table<_T, _Fn>;
template <typename _InputIterator, typename _Fn>
sparse_table(_InputIterator, _InputIterator, _Fn &&)
    -> sparse_table<typename std::iterator_traits<_InputIterator>::value_type,
                    _Fn>;
} 


using namespace std;
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
#define REP(n) for (int _i = 0; _i < n; ++_i)
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define MAXN 200001
#define MULTI false
#define BITSIZE 21



namespace {} 


struct query{
  int l,r,i;
};



void solve() {
  int n,q;cin>>n>>q;
  auto f=[](int x,int y)->int{return x+y;};
  auto g=[](int x,int y)->int{return 0;};
  auto ef=[](){return 0;};
  algo::lazy_segtree lsg(n,f,g,g,ef);
  for(int i=0;i<n;++i){
    lsg.set_val(i,1);
  }
  vector<bool>ans(n);
  algo::segtree sg(n,[](int x,int y){return min(x,y);},[&](){return n;});
  for(int i=0;i<q;++i){
    int t;cin>>t;
    if(t==0){
      int l,r,x;cin>>l>>r>>x;
      if(x==0){
        lsg.apply(l-1,r,0);
      }else{
        int v=sg.get_val(l-1);
        sg.set_val(l-1,min(v,r-1));
      }
    }else{
      int p;cin>>p;
      if(ans[p-1]){cout<<"YES\n";}
      else if(lsg.get_val(p-1)==0){
        cout<<"NO\n";
      }else{
        int lb=lsg.min_left(p-1,[](int x){return x<1;});
        int rb=lsg.max_right(p,[](int x){return x<1;});
        if(sg.query(lb,p)<rb){
          ans[p-1]=true;
          cout<<"YES\n";
        }else{
          cout<<"N/A\n";
        }
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
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
