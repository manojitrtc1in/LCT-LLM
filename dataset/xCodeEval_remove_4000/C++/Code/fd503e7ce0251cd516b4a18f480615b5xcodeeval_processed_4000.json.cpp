








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
std::vector<int>
argsort(const std::vector<_Tp> &vec) {
  std::vector<int> ind(vec.size());
  std::iota(ind.begin(), ind.end(), 0);
  std::sort(ind.begin(), ind.end(),
            [&](int a, int b) -> bool { return vec[a] < vec[b]; });
  return ind;
}
template <base::less_than_comparable _Tp>
void
id4(std::vector<_Tp> &vec) noexcept {
  std::sort(vec.begin(), vec.end());
  vec.erase(std::unique(vec.begin(), vec.end()), vec.end());
}
template <base::less_than_comparable _Tp>
int
argmin(const std::vector<_Tp> &vec) {
  const int n = (int)vec.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
  }
  return j;
}
template <base::less_than_comparable _Tp>
int
argmax(const std::vector<_Tp> &vec) {
  const int n = (int)vec.size();
  int j = -1;
  for (int i = 0; i < n; ++i) {
    if (base::unlikely(j == -1 || vec[j] < vec[i])) { j = i; }
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
template <base::integer _Tp>
constexpr _Tp
id10(_Tp n) {
  return -(n & 1) | 1;
}
constexpr int
id10(bool n) {
  return -(int)(n) | 1;
}
}
namespace algo {
template <typename _Fn>
struct rec_lambda {
  constexpr rec_lambda(_Fn &&f) : _f(f) {}
  template <typename... _Args>
  constexpr decltype(auto)
  operator()(_Args &&... args) const {
    return _f(*this, std::forward<_Args>(args)...);
  }
private:
  _Fn _f;
};
constexpr long
likely(bool x) {
  return base::likely(x);
}
constexpr long
unlikely(bool x) {
  return base::unlikely(x);
}
constexpr void
assume(bool x) {
  base::assume(x);
}
}
namespace algo {
namespace base {
template <dword_fittable _Tp>
constexpr int
id9(_Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable _Tp>
constexpr int
id9(_Tp n) {
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
id7(_Tp n) {
  return 32 - id9(n);
}
template <qword_fittable _Tp>
constexpr int
id7(_Tp n) {
  return 64 - id9(n);
}
template <dword_fittable _Tp>
constexpr _Tp
id5(_Tp n) {
  return 1u << (31 - id9(n));
}
template <qword_fittable _Tp>
constexpr _Tp
id5(_Tp n) {
  return 1ull << (63 - id9(n));
}
template <integer _Tp>
constexpr _Tp
id8(_Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return id5(n - 1) << 1;
}
template <dword_fittable _Tp>
constexpr int
id3(_Tp n) {
  return 31 - id9(n);
}
template <qword_fittable _Tp>
constexpr int
id3(_Tp n) {
  return 63 - id9(n);
}
template <integer _Tp>
constexpr int
id12(_Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id3(n - 1) + 1;
}
template <dword_fittable _Tp>
constexpr int
id6(_Tp n) {
  return __builtin_popcount(n);
}
template <qword_fittable _Tp>
constexpr int
id6(_Tp n) {
  return __builtin_popcountll(n);
}
}
}
namespace algo {
template <typename _Monoid, base::binary_op<_Monoid> _F,
          base::callable<_Monoid> _E>
class id1 {
public:
  using value_type = _Monoid;
  using size_type = int;
  using action_func = _F;
  using identity_func = _E;
  id1(size_type n, action_func &&f, identity_func &&e)
      : _n(n),
        _lg2(base::id12(n)),
        _size(1 << _lg2),
        _tree(_size << 1, e()),
        _f(f),
        _ef(e) {}
  id1(size_type n, const value_type &init, action_func &&f,
          identity_func &&e)
      : _n(n),
        _lg2(base::id12(_n)),
        _size(1 << _lg2),
        _tree(_size << 1, init),
        _f(f),
        _ef(e) {
    for (size_type i = _size - 1; i > 0; --i) { _update(i); }
  }
  id1(const std::vector<value_type> &vec, action_func &&f,
          identity_func &&e)
      : id1(vec.size(), std::forward<action_func>(f),
                std::forward<identity_func>(e)) {
    std::copy(vec.begin(), vec.end(), _tree.begin() + _size);
    for (size_type i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <base::input_iterator<value_type> _Iter>
  id1(_Iter first, _Iter last, action_func &&f, identity_func &&e)
      : id1((size_type)std::distance(first, last),
                std::forward<action_func>(f), std::forward<identity_func>(e)) {
    std::copy(first, last, _tree.begin() + _size);
    for (size_type i = _size - 1; i > 0; --i) { _update(i); }
  }
  template <std::input_iterator _Iter,
            base::callable<value_type, std::iter_value_t<_Iter>> _Gen>
  id1(_Iter first, _Iter last, action_func &&f, identity_func &&e,
          _Gen &&gen)
      : id1((size_type)std::distance(first, last),
                std::forward<action_func>(f), std::forward<identity_func>(e)) {
    std::transform(first, last, _tree.begin() + _size, std::forward<_Gen>(gen));
    for (size_type i = _size - 1; i > 0; --i) { _update(i); }
  }
  void
  set(size_type pos, const value_type &val) {
    _tree[pos += _size] = val;
    for (size_type i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  value_type
  get(size_type pos) const {
    return _tree[pos + _size];
  }
  void
  apply(size_type pos, const value_type &z) {
    pos += _size;
    _tree[pos] = _f(_tree[pos], z);
    for (size_type i = 1; i <= _lg2; ++i) { _update(pos >> i); }
  }
  value_type
  query(size_type l, size_type r) const {
    value_type resl = _ef(), resr = _ef();
    for (l += _size, r += _size; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = _f(resl, _tree[l++]); }
      if (r & 0x01) { resr = _f(_tree[--r], resr); }
    }
    return _f(resl, resr);
  }
  value_type
  query() const {
    return _tree[1];
  }
  template <std::predicate<value_type> _Pred>
  size_type
  id11(size_type l, _Pred &&pred) const {
    if (base::likely(l < _n)) {
      l += _size;
      value_type cur = _ef();
      do {
        l >>= base::id0(l);
        if (!pred(_f(cur, _tree[l]))) {
          while (l < _size) {
            l <<= 1;
            if (value_type tmp = _f(cur, _tree[l]); pred(tmp)) {
              cur = tmp, ++l;
            }
          }
          return l - _size;
        }
        cur = _f(cur, _tree[l++]);
      } while ((l & -l) - l);
    }
    return _n;
  }
  template <std::predicate<value_type> _Pred>
  size_type
  id2(size_type r, _Pred &&pred) const {
    if (base::likely(r > 0)) {
      r += _size;
      value_type cur = _ef();
      do {
        r >>= base::id0(r);
        r ^= (r > 1);
        if (!pred(_f(_tree[r], cur))) {
          while (r < _size) {
            r <<= 1;
            r |= 1;
            if (value_type tmp = _f(_tree[r], cur); pred(tmp)) {
              cur = tmp, --r;
            }
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
  _update(size_type v) {
    _tree[v] = _f(_tree[v << 1], _tree[v << 1 | 1]);
  }
  size_type _n, _lg2, _size;
  std::vector<value_type> _tree;
  action_func _f;
  identity_func _ef;
};
template <typename _F, typename _E>
id1(int, _F &&, _E &&) -> id1<std::invoke_result_t<_E>, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id1(int, const _Monoid &, _F &&, _E &&) -> id1<_Monoid, _F, _E>;
template <typename _Monoid, typename _F, typename _E>
id1(const std::vector<_Monoid> &, _F &&, _E &&) -> id1<_Monoid, _F, _E>;
template <typename _Iter, typename _F, typename _E>
id1(_Iter, _Iter, _F &&, _E &&)
    -> id1<std::iter_value_t<_Iter>, _F, _E>;
template <typename _Iter, typename _F, typename _E, typename _Gen>
id1(_Iter, _Iter, _F &&, _E &&, _Gen &&)
    -> id1<std::invoke_result_t<_Gen, std::iter_value_t<_Iter>>, _F, _E>;
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
  int n;cin>>n;
  vector<wint>pref(n+1);
  for(int i=1;i<=n;++i){
    int x;cin>>x;
    pref[i]=pref[i-1]+x;
  }
  auto ind=algo::argsort(pref);
  vector<int>cord(n+1);
  for(int i=0,c=0;i<=n;++c){
    int j=i;
    do{
      cord[ind[j]]=c;
    }while(++j<=n&&pref[ind[j]]==pref[ind[i]]);
    i=j;
  }
  using node=struct{
    int x1,x2,x3;
  };
  algo::id1 sg(n+1,[](node x,node y){return node{max(x.x1,y.x1),max(x.x2,y.x2),max(x.x3,y.x3)};},[]{return node{-INF,-INF,-INF};});
  sg.set(cord[0],{0,0,0});
  for(int i=1;i<=n;++i){
    int c=sg.get(cord[i]).x3;
    c=max(c,sg.query(0,cord[i]).x1+i);
    c=max(c,sg.query(cord[i]+1,n+1).x2-i);
    sg.apply(cord[i],{c-i,c+i,c});
    if(i==n){cout<<c<<'\n';}
  }
}
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cout.precision(15);
  int tc;
  cin >> tc;
  while (tc--) {
    solve();
  }
  return 0;
}
