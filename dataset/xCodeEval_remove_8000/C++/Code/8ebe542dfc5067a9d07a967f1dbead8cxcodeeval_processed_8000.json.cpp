








namespace dbg {

}
namespace algo {
namespace base {
template <typename _Tp>
concept integer = std::integral<_Tp> && !std::same_as<_Tp, bool>;
template <typename _Tp>
concept addable = requires(std::remove_reference_t<_Tp> &a,
                           const std::remove_reference_t<_Tp> &b) {
  { a += b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
template <typename _Tp>
concept multipliable = requires(std::remove_reference_t<_Tp> &a,
                                const std::remove_reference_t<_Tp> &b) {
  { a *= b }
  ->std::same_as<std::remove_reference_t<_Tp> &>;
};
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
using extract_return_t = typename function_traits<_Fn>::result_type;
template <typename _Fn, typename _Ret, typename... _Args>
concept callable = std::invocable<_Fn, _Args...>
    &&std::same_as<std::invoke_result_t<_Fn, _Args...>, _Ret>;
template <typename _Fn, typename _Arg>
concept unary_op = callable<_Fn, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept binary_op = callable<_Fn, _Arg, _Arg, _Arg>;
template <typename _Fn, typename _Arg>
concept unary_predicate = callable<_Fn, bool, _Arg>;
template <typename _Tp>
concept less_than_comparable = requires(const std::remove_reference_t<_Tp> &a,
                                        const std::remove_reference_t<_Tp> &b) {
  { a < b }
  ->std::convertible_to<bool>;
  { !(a < b) }
  ->std::convertible_to<bool>;
};
template <typename _Tp>
concept equality_comparable = std::equality_comparable<_Tp>;
template <typename _From, typename _To>
concept constructible = std::constructible_from<_To, _From>;
template <typename _Iter, typename _Value>
concept input_iterator =
    std::input_iterator<_Iter> &&std::same_as<std::iter_value_t<_Iter>, _Value>;
template <typename _Tp>
concept qword_fittable = integer<_Tp> && sizeof(_Tp) <= 8UL;
template <typename _Tp>
concept dword_fittable = qword_fittable<_Tp> && sizeof(_Tp) <= 4UL;
template <typename _Tp>
concept word_fittable = dword_fittable<_Tp> && sizeof(_Tp) <= 2UL;
template <typename _Tp>
concept byte_fittable = word_fittable<_Tp> && sizeof(_Tp) == 1UL;
template <integer _Tp>
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
template <typename _Tp>
using safe_mul_t = typename safely_multipliable<_Tp>::type;
}
}
namespace algo {
namespace base {
template <typename _Tp>
constexpr _Tp
id7(const _Tp &a, const _Tp &b) {
  return a < b ? b : a;
}
template <typename _Tp>
constexpr _Tp
__mini(const _Tp &a, const _Tp &b) {
  return a < b ? a : b;
}
template <typename _Tp>
constexpr void
__swap(_Tp &a, _Tp &b) {
  _Tp tp = a;
  a = b;
  b = tp;
}
template <typename _Tp>
constexpr void
__swap(_Tp *a, _Tp *b) {
  _Tp tp = *a;
  *a = *b;
  *b = tp;
}
}
}
namespace algo {
namespace base {
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
template <base::less_than_comparable _Tp>
constexpr _Tp
max(const _Tp &a, const _Tp &b) {
  return base::id7(a, b);
}
template <base::less_than_comparable _Tp>
constexpr _Tp
min(const _Tp &a, const _Tp &b) {
  return base::__mini(a, b);
}
template <base::less_than_comparable _Tp>
std::vector<int>
argsort(const std::vector<_Tp> &v) {
  std::vector<int> ind(v.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&v](int a, int b) -> bool { return v[a] < v[b]; });
  return ind;
}
template <base::less_than_comparable _Tp>
void
id10(std::vector<_Tp> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <base::less_than_comparable _Tp>
int
argmin(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::less_than_comparable _Tp>
int
argmax(const std::vector<_Tp> &v) {
  const int n = (int)v.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || v[j] < v[i])) { j = i; }
  }
  return j;
}
template <base::integer _Tp, base::unary_predicate<_Tp> _Pred>
constexpr _Tp
bisect(_Tp low, _Tp high, _Pred &&pred) {
  while (low < high) {
    _Tp mid = low + high >> 1;
    pred(mid) ? low = mid + 1 : high = mid;
  }
  return low;
}
template <base::less_than_comparable _Tp>
int
lower_bound(const std::vector<_Tp> &vec, const _Tp &x) {
  return (int)std::distance(vec.begin(),
                            std::lower_bound(vec.begin(), vec.end(), x));
}
template <base::less_than_comparable _Tp>
int
upper_bound(const std::vector<_Tp> &vec, const _Tp &x) {
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
template <typename _Tp>
void
permute(std::vector<_Tp> &vec, const std::vector<int> &perm) {
  std::vector<_Tp> out(vec.size());
  const int n = (int)vec.size();
  for (int i = 0; i < n; ++i) { out[perm[i]] = vec[i]; }
  vec = std::move(out);
}
constexpr auto
id3(base::integer auto n) {
  return -(n & 1) | 1;
}
constexpr int
id3(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
namespace base {
template <dword_fittable _Tp>
constexpr int
id14(_Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable _Tp>
constexpr int
id14(_Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable _Tp>
constexpr int
id0(_Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable _Tp>
constexpr int
id0(_Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable _Tp>
constexpr int
id6(_Tp n) {
  return 32 - id14(n);
}
template <qword_fittable _Tp>
constexpr int
id6(_Tp n) {
  return 64 - id14(n);
}
template <dword_fittable _Tp>
constexpr _Tp
id11(_Tp n) {
  return 1u << (31 - id14(n));
}
template <qword_fittable _Tp>
constexpr _Tp
id11(_Tp n) {
  return 1ull << (63 - id14(n));
}
template <integer _Tp>
constexpr _Tp
id13(_Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return id11(n - 1) << 1;
}
template <dword_fittable _Tp>
constexpr int
id5(_Tp n) {
  return 31 - id14(n);
}
template <qword_fittable _Tp>
constexpr int
id5(_Tp n) {
  return 63 - id14(n);
}
template <integer _Tp>
constexpr int
id15(_Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id5(n - 1) + 1;
}
template <dword_fittable _Tp>
constexpr int
id2(_Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable _Tp>
constexpr int
id2(_Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
template <typename _Monoid, typename _X, base::binary_op<_Monoid> _F,
          base::binary_op<_X> _G, base::callable<_Monoid, _Monoid, _X> _Map,
          base::callable<_Monoid> _EF, base::callable<_X> _EG>
class id12 {
public:
  id12(int n, _F &&f, _G &&g, _Map &&mapping, _EF &&ef, _EG &&eg)
      : _n(n),
        id4(base::id15(_n)),
        _size(1 << id4),
        _tree(_size << 1, ef()),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {}
  id12(int n, const _Monoid &init, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : _n(n),
        id4(base::id15(_n)),
        _size(1 << id4),
        _tree(_size << 1, init),
        _lazy(_size, eg()),
        _f(f),
        _g(g),
        _map(mapping),
        _ef(ef),
        _eg(eg) {
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  id12(const std::vector<_Monoid> &vec, _F &&f, _G &&g, _Map &&mapping,
               _EF &&ef, _EG &&eg)
      : id12((int)vec.size(), std::forward<_F>(f), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EF>(ef),
                     std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  void
  set(int pos, const _Monoid &val) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = val;
    for (int i = 1; i <= id4; ++i) { _update(pos >> i); }
  }
  _Monoid
  get(int pos) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos];
  }
  void
  apply(int pos, const _X &arg) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id4; ++i) { _update(pos >> i); }
  }
  void
  apply_commutative(int pos, const _X &arg) {
    pos += _size;
    _tree[pos] = _map(_tree[pos], arg);
    for (int i = 1; i <= id4; ++i) { _update(pos >> i); }
  }
  void
  apply(int l, int r, const _X &arg) {
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id0(l);
      const int tz_r = base::id0(r);
      for (int i = id4; i > tz_l; --i) { _push(l >> i); }
      for (int i = id4; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id4; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id4; ++i) { _update((r - 1) >> i); }
    }
  }
  void
  apply_commutative(int l, int r, const _X &arg) {
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id0(l);
      const int tz_r = base::id0(r);
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
      for (int i = tz_l + 1; i <= id4; ++i) { _update(l >> i); }
      for (int i = tz_r + 1; i <= id4; ++i) { _update((r - 1) >> i); }
    }
  }
  _Monoid
  query(int l, int r) {
    _Monoid resl = _ef(), resr = _ef();
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id0(l);
      const int tz_r = base::id0(r);
      for (int i = id4; i > tz_l; --i) { _push(l >> i); }
      for (int i = id4; i > tz_r; --i) { _push((r - 1) >> i); }
      do {
        if (l & 0x01) { resl = _f(resl, _tree[l++]); }
        if (r & 0x01) { resr = _f(_tree[--r], resr); }
        l >>= 1;
        r >>= 1;
      } while (l < r);
    }
    return _f(resl, resr);
  }
  _Monoid
  query() const noexcept {
    return _tree[1];
  }
  template <base::unary_predicate<_Monoid> _Pred>
  int
  id8(int l, _Pred &&pred) {
    if (base::likely(l < _n)) {
      l += _size;
      for (int i = id4; i >= 1; --i) { _push(l >> i); }
      _Monoid cur = _ef();
      do {
        l >>= base::id0(l);
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
  template <base::unary_predicate<_Monoid> _Pred>
  int
  id1(int r, _Pred &&pred) {
    if (base::likely(r > 0)) {
      r += _size;
      for (int i = id4; i >= 1; --i) { _push(r - 1 >> i); }
      _Monoid cur = _ef();
      do {
        r >>= base::id0(r);
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
  void
  _update(int v) {
    _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]);
  }
  void
  _apply_subtree(int v, const _X &arg) {
    _tree[v] = _map(_tree[v], arg);
    if (base::likely(v < _size)) { _lazy[v] = _g(_lazy[v], arg); }
  }
  void
  _push(int v) {
    _apply_subtree(v << 1, _lazy[v]);
    _apply_subtree(v << 1 | 1, _lazy[v]);
    _lazy[v] = _eg();
  }
  int _n, id4, _size;
  std::vector<_Monoid> _tree;
  std::vector<_X> _lazy;
  _F _f;
  _G _g;
  _Map _map;
  _EF _ef;
  _EG _eg;
};
template <typename _Tp, typename _X, base::binary_op<_X> _G,
          base::callable<_Tp, _Tp, _X> _Map, base::callable<_X> _EG>
class id12<_Tp, _X, void, _G, _Map, void, _EG> {
public:
  id12(int n, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        id4(base::id15(_n)),
        _size(1 << id4),
        _tree(_size),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  id12(int n, const _Tp &init, _G &&g, _Map &&mapping, _EG &&eg)
      : _n(n),
        id4(base::id15(_n)),
        _size(1 << id4),
        _tree(_size, init),
        _lazy(_size, eg()),
        _g(g),
        _map(mapping),
        _eg(eg) {}
  id12(const std::vector<_Tp> &vec, _G &&g, _Map &&mapping, _EG &&eg)
      : id12(vec.size(), std::forward<_G>(g),
                     std::forward<_Map>(mapping), std::forward<_EG>(eg)) {
    std::copy(vec.begin(), vec.end(), _tree.begin());
  }
  void
  set(int pos, const _Tp &val) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = val;
  }
  _Tp
  get(int pos) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    return _tree[pos - _size];
  }
  void
  apply(int pos, const _X &arg) {
    pos += _size;
    for (int i = id4; i >= 1; --i) { _push(pos >> i); }
    _tree[pos - _size] = _map(_tree[pos - _size], arg);
  }
  void
  apply_commutative(int pos, const _X &arg) {
    _tree[pos] = _map(_tree[pos], arg);
  }
  void
  apply(int l, int r, const _X &arg) {
    if (base::likely(l < r)) {
      l += _size;
      r += _size;
      const int tz_l = base::id0(l);
      const int tz_r = base::id0(r);
      for (int i = id4; i > tz_l; --i) { _push(l >> i); }
      for (int i = id4; i > tz_r; --i) { _push((r - 1) >> i); }
      for (int _l = l, _r = r; _l < _r; _l >>= 1, _r >>= 1) {
        if (_l & 0x01) { _apply_subtree(_l++, arg); }
        if (_r & 0x01) { _apply_subtree(--_r, arg); }
      }
    }
  }
  void
  apply_commutative(int l, int r, const _X &arg) {
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { _apply_subtree(l++, arg); }
      if (r & 0x01) { _apply_subtree(--r, arg); }
    }
  }
private:
  void
  _apply_subtree(int v, const _X &arg) {
    if (base::unlikely(v >= _size)) {
      _tree[v - _size] = _map(_tree[v - _size], arg);
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
  int _n, id4, _size;
  std::vector<_Tp> _tree;
  std::vector<_X> _lazy;
  _G _g;
  _Map _map;
  _EG _eg;
};
template <typename _F, typename _G, typename _Map, typename _EF, typename _EG>
id12(int, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> id12<std::invoke_result_t<_EF>, std::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
id12(int, const _Monoid &, _F &&, _G &&, _Map &&, _EF &&, _EG &&)
    -> id12<_Monoid, std::invoke_result_t<_EG>, _F, _G, _Map, _EF, _EG>;
template <typename _Monoid, typename _F, typename _G, typename _Map,
          typename _EF, typename _EG>
id12(const std::vector<_Monoid> &, _F &&, _G &&, _Map &&, _EF &&,
             _EG &&)
    -> id12<std::invoke_result_t<_EF>, std::invoke_result_t<_EG>, _F,
                    _G, _Map, _EF, _EG>;
template <typename _G, typename _Map, typename _EG>
id12(int, _G &&, _Map &&, _EG &&)
    -> id12<base::extract_return_t<_Map>, std::invoke_result_t<_EG>,
                    void, _G, _Map, void, _EG>;
template <typename _Tp, typename _G, typename _Map, typename _EG>
id12(int, const _Tp &, _G &&, _Map &&, _EG &&)
    -> id12<_Tp, std::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
template <typename _Tp, typename _G, typename _Map, typename _EG>
id12(const std::vector<_Tp> &vec, _G &&, _Map &&, _EG &&)
    -> id12<_Tp, std::invoke_result_t<_EG>, void, _G, _Map, void, _EG>;
}
namespace algo {
template <typename _Monoid, base::binary_op<_Monoid> _F,
          base::callable<_Monoid> _E>
class id9 {
public:
  id9(int n, _F &&f, _E &&e)
      : _n(n),
        id4(base::id15(n)),
        _size(1 << id4),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {}
  id9(int n, const _Monoid &init, _F &&f, _E &&e)
      : _n(n),
        id4(base::id15(_n)),
        _size(1 << id4),
        _tree(_size << 1, init),
        _f(f),
        _ef(e) {
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  id9(const std::vector<_Monoid> &vec, _F &&f, _E &&e)
      : id9(vec.size(), std::forward<_F>(f), std::forward<_E>(e)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <base::input_iterator<_Monoid> _Iter>
  id9(_Iter first, _Iter last, _F &&f, _E &&e)
      : id9((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    std::copy(first, last, _tree.begin() + _size);
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <std::input_iterator _Iter,
            base::callable<_Monoid, std::iter_value_t<_Iter>> _Gen>
  id9(_Iter first, _Iter last, _F &&f, _E &&e, _Gen &&gen)
      : id9((int)std::distance(first, last), std::forward<_F>(f),
                std::forward<_E>(e)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (int i = _size - 1; i > 0; --i) { _update(i); }
  }
  void
  set(int pos, const _Monoid &val) {
    _tree[pos += _size] = val;
    for (int i = 1; i <= id4; ++i) { _update(pos >> i); }
  }
  _Monoid
  get(int pos) const {
    return _tree[pos + _size];
  }
  _Monoid
  query(int l, int r) const {
    _Monoid resl = _ef(), resr = _ef();
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = _f(resl, _tree[l++]); }
      if (r & 0x01) { resr = _f(_tree[--r], resr); }
    }
    return _f(resl, resr);
  }
  _Monoid
  query() const {
    return _tree[1];
  }
  template <base::unary_predicate<_Monoid> _Pred>
  int
  id8(int l, _Pred &&pred) const {
    if (base::likely(l < _n)) {
      l += _size;
      _Monoid cur = _ef();
      do {
        l >>= base::id0(l);
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
  template <base::unary_predicate<_Monoid> _Pred>
  int
  id1(int r, _Pred &&pred) const {
    if (base::likely(r > 0)) {
      r += _size;
      _Monoid cur = _ef();
      do {
        r >>= base::id0(r);
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
  void
  _update(int v) {
    _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]);
  }
  int _n, id4, _size;
  std::vector<_Monoid> _tree;
  _F _f;
  _E _ef;
};
template <typename _F, typename _E>
id9(int, _F &&, _E &&) -> id9<std::invoke_result_t<_E>, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id9(int, const _Monoid &, _F &&, _E &&) -> id9<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id9(const std::vector<_Monoid> &, _F &&, _E &&) -> id9<_Monoid, _F, _E>;
template <typename _Iter, typename _F, typename _E>
id9(_Iter, _Iter, _F &&, _E &&)
    -> id9<std::iter_value_t<_Iter>, _F, _E>;
template <typename _Iter, typename _F, typename _E, typename _Gen>
id9(_Iter, _Iter, _F &&, _E &&, _Gen &&)
    -> id9<std::invoke_result_t<_Gen, std::iter_value_t<_Iter>>, _F, _E>;
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
inline void solve() noexcept {
  int n,q;cin>>n>>q;
  auto f=[](int x,int y){return x+y;};
  auto g=[](int x,int y){return y==-1?x:y;};
  auto ef=[]{return 0;};
  auto eg=[]{return -1;};
  algo::id12 lsg(n,1,f,g,g,ef,eg);
  vector ans(n,false);
  algo::id9 sg(n,[](int x,int y){return algo::min(x,y);},[&]{return n;});
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
      if(ans[p-1]){cout<<"YES\n";}
      else if(lsg.get(p-1)==0){cout<<"NO\n";}
      else{
        int lb=lsg.id1(p-1,[](int x){return x<1;});
        int rb=lsg.id8(p,[](int x){return x<1;});
        if(sg.query(lb,p)<rb){ans[p-1]=true;cout<<"YES\n";}
        else{cout<<"N/A\n";}
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
