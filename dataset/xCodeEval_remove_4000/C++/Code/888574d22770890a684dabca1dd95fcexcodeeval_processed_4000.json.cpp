










namespace algo {
namespace detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename Tp>
concept multipliable = requires(std::remove_reference_t<Tp> &a,
                                const std::remove_reference_t<Tp> &b) {
  { a *= b } -> std::same_as<std::remove_reference_t<Tp> &>;
};
template <typename Function, typename ReturnType, typename... Args>
concept callable = std::invocable<Function, Args...> &&
    std::same_as<std::invoke_result_t<Function, Args...>, ReturnType>;
template <typename Function, typename Arg>
concept unary_op = callable<Function, Arg, Arg>;
template <typename Function, typename Arg>
concept binary_op = callable<Function, Arg, Arg, Arg>;
template <typename Tp>
concept less_than_comparable = requires(const std::remove_reference_t<Tp> &a,
                                        const std::remove_reference_t<Tp> &b) {
  { a < b } -> std::convertible_to<bool>;
  { !(a < b) } -> std::convertible_to<bool>;
};
template <typename Tp>
concept equality_comparable = std::equality_comparable<Tp>;
template <typename From, typename To>
concept constructible = std::constructible_from<To, From>;
template <typename InputIterator, typename ValueType>
concept input_iterator = std::input_iterator<InputIterator> &&
    std::same_as<std::iter_value_t<InputIterator>, ValueType>;
template <typename Tp>
concept qword_fittable = integer<Tp> && sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename From, typename To>
concept sign_compatible = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <integer Tp>
struct imul_result;
template <>
struct imul_result<char> {
  using type = int16_t;
};
template <>
struct imul_result<unsigned char> {
  using type = uint16_t;
};
template <>
struct imul_result<short> {
  using type = int32_t;
};
template <>
struct imul_result<int> {
  using type = int64_t;
};
template <>
struct imul_result<unsigned int> {
  using type = uint64_t;
};
template <>
struct imul_result<long> {
  using type = __int128_t;
};
template <>
struct imul_result<unsigned long> {
  using type = __uint128_t;
};
template <>
struct imul_result<long long> {
  using type = __int128_t;
};
template <>
struct imul_result<unsigned long long> {
  using type = __uint128_t;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
template <typename Function>
struct function_traits
    : public function_traits<
          decltype(&std::remove_reference_t<Function>::operator())> {};
template <typename Function, typename ReturnType, typename... Args>
struct function_traits<ReturnType (Function::*)(Args...) const> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType (*)(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
template <typename ReturnType, typename... Args>
struct function_traits<ReturnType(Args...)> {
  static constexpr size_t arity = sizeof...(Args);
  using result_type = ReturnType;
  template <size_t I>
  struct arg {
    using type = std::tuple_element_t<I, std::tuple<Args...>>;
  };
};
}
}
namespace algo {
namespace detail {
template <dword_fittable Tp>
constexpr int
id7(Tp n) {
  return __builtin_clz(n);
}
template <qword_fittable Tp>
constexpr int
id7(Tp n) {
  return __builtin_clzll(n);
}
template <dword_fittable Tp>
constexpr int
id12(Tp n) {
  return __builtin_ctz(n);
}
template <qword_fittable Tp>
constexpr int
id12(Tp n) {
  return __builtin_ctzll(n);
}
template <dword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 32 - id7(n);
}
template <qword_fittable Tp>
constexpr int
bit_width(Tp n) {
  return 64 - id7(n);
}
template <dword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1u << (31 - id7(n));
}
template <qword_fittable Tp>
constexpr Tp
bit_floor(Tp n) {
  return 1ull << (63 - id7(n));
}
template <integer Tp>
constexpr Tp
id0(Tp n) {
  if (n == 0 || n == 1) { return 1; }
  return bit_floor(n - 1) << 1;
}
template <dword_fittable Tp>
constexpr int
id9(Tp n) {
  return 31 - id7(n);
}
template <qword_fittable Tp>
constexpr int
id9(Tp n) {
  return 63 - id7(n);
}
template <integer Tp>
constexpr int
id10(Tp n) {
  if (n == 0 || n == 1) { return 0; }
  return id9(n - 1) + 1;
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
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id7(n);
}
template <detail::integer Tp>
constexpr int
id6(Tp n) {
  return detail::id7(~n);
}
template <detail::integer Tp>
constexpr int
id5(Tp n) {
  return detail::id12(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id12(~n & (n + 1));
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
bit_floor(Tp n) {
  return detail::bit_floor(n);
}
template <detail::integer Tp>
constexpr Tp
id0(Tp n) {
  return detail::id0(n);
}
template <detail::integer Tp>
constexpr int
id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr int
id10(Tp n) {
  return detail::id10(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo {

  do { \
    if (!(expr)) __builtin_unreachable(); \
  } while (false)


}
namespace algo {
namespace detail {
template <integer Tp>
constexpr Tp
sqrt(Tp n) {
  if (n == 0) { return 0; }
  if (n == 1) { return 1; }
  Tp ans = 0;
  for (int i = id9(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <integer Tp>
constexpr Tp
abs(Tp n) {
  if constexpr (std::is_signed_v<Tp>) {
    return n < 0 ? -n : n;
  } else {
    return n;
  }
}
template <integer Tp>
constexpr Tp
cdiv(Tp x, Tp y) {
  if constexpr (std::is_unsigned_v<Tp>) {
    return x / y + (x % y != 0);
  } else {
    return x / y + (x % y != 0 && (x ^ y) >= 0);
  }
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
id4(Tp n) {
  return -(n & 1) | 1;
}
}
}
namespace algo {
template <detail::integer Tp>
constexpr Tp
sqrt(Tp n) {
  assert(n >= 0);
  return detail::sqrt(n);
}
template <detail::integer Tp>
constexpr Tp
abs(Tp n) {
  return detail::abs(n);
}
template <detail::integer T1, detail::sign_compatible<T1> T2>
constexpr std::common_type_t<T1, T2>
cdiv(T1 x, T2 y) {
  assert(y != 0);
  return detail::cdiv<std::common_type_t<T1, T2>>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, int>>
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer T1, detail::sign_compatible<T1> T2,
          detail::sign_compatible<T2> T3, detail::sign_compatible<T3> T4,
          typename Tp = std::common_type_t<T1, T2, T3, T4>>
constexpr Tp
floor_sum(T1 a, T2 b, T3 c, T4 n) {
  assert(n >= 0);
  assert(c > 0);
  assert(a >= 0);
  assume(n >= 0);
  assume(c > 0);
  assume(a >= 0);
  Tp res = 0, a0 = a, b0 = b, c0 = c, n0 = n;
  bool neg = false;
  while (a0 != 0) {
    if (a0 < c0 && b0 < c0) {
      const Tp m = (a0 * n0 + b0) / c0;
      const Tp tmp = a0;
      res += id4(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += id4(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += id4(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
template <std::semiregular Monoid, detail::binary_op<Monoid> Operation,
          detail::callable<Monoid> Identity>
class id11 {
public:
  id11() = default;
  id11(int n, const Operation &f, const Identity &e)
      : n_(n),
        lg2_(detail::id10(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, e()),
        binop_(f),
        id_(e) {}
  id11(int n, const Monoid &init, const Operation &f, const Identity &e)
      : n_(n),
        lg2_(detail::id10(n)),
        size_(1 << lg2_),
        tree_(size_ << 1, init),
        binop_(f),
        id_(e) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> InputIterator>
  id11(InputIterator first, InputIterator last, const Operation &f,
          const Identity &e)
      : id11(std::distance(first, last), f, e) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator InputIterator,
            detail::callable<Monoid, std::iter_value_t<InputIterator>> Gen>
  id11(InputIterator first, InputIterator last, const Operation &f,
          const Identity &e, const Gen &gen)
      : id11(std::distance(first, last), f, e) {
    std::transform(first, last, tree_.begin() + size_, gen);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, const Monoid &new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = new_val;
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) const {
    assert(0 <= pos && pos < size());
    return tree_[pos + size_];
  }
  void
  apply(int pos, const Monoid &z) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = binop_(tree_[pos], z);
    for (int i = 1; i <= lg2_; ++i) { update(pos >> i); }
  }
  Monoid
  query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = id_(), resr = id_();
    for (l += size_, r += size_; l < r; l >>= 1, r >>= 1) {
      if (l & 0x01) { resl = binop_(resl, tree_[l++]); }
      if (r & 0x01) { resr = binop_(tree_[--r], resr); }
    }
    return binop_(resl, resr);
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Predicate>
  int
  id8(int l, const Predicate &pred) const {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (likely(l < n_)) {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id12(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            l <<= 1;
            if (const Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = tmp, l += 1;
            }
          }
          return l - size_;
        }
        cur = binop_(cur, tree_[l++]);
      } while ((l & -l) - l != 0);
    }
    return n_;
  }
  template <std::predicate<Monoid> Predicate>
  int
  id1(int r, const Predicate &pred) const {
    assert(0 <= r && r <= size());
    if (likely(r > 0)) {
      r += size_;
      Monoid cur = id_();
      do {
        r >>= detail::id12(r);
        if (r > 1) { r -= 1; }
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            r <<= 1;
            r += 1;
            if (const Monoid tmp = binop_(tree_[r], cur); pred(tmp)) {
              cur = tmp, r -= 1;
            }
          }
          return (r + 1) - size_;
        }
        cur = binop_(tree_[r], cur);
      } while ((r & -r) - r != 0);
    }
    return 0;
  }
  int
  size() const {
    return n_;
  }
  std::vector<Monoid>
  data() const {
    return tree_;
  }
private:
  void
  update(int v) {
    tree_[v] = binop_(tree_[v << 1], tree_[v << 1 | 1]);
  }
  int n_, lg2_, size_;
  std::vector<Monoid> tree_;
  Operation binop_;
  Identity id_;
};
}

using std::array;
using std::vector;
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
using std::pair;
using std::tuple;
using std::cin;
using std::cout;
using std::endl;
using std::gcd;
using std::tie;
using std::lcm;
using std::max;
using std::min;
using std::move;
using std::swap;
using std::to_string;
template <typename Tp, typename Function>
using ordered_set = __gnu_pbds::tree<Tp,
__gnu_pbds::null_type, Function, __gnu_pbds::rb_tree_tag,
__gnu_pbds::tree_order_statistics_node_update>;
using wint = int64_t;
template <typename KeyType, typename ValueType>
using umap = std::unordered_map<KeyType, ValueType>;
template <typename ValueType> using uset = std::unordered_set<ValueType>;
template <typename Tp, typename Function = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;
template <typename Tp, typename Function = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Function>;





template <typename Tp>
constexpr void chmax(Tp &x, const Tp &y) { x = max(x, y); }
template <typename Tp>
constexpr void chmin(Tp &x, const Tp &y) { x = min(x, y); }
namespace {
}
void solve() noexcept {
  struct point{
    int t,id;
  };
  int n;cin>>n;
  vector<wint>pref(n+1);
  vector<wint>vs(n+1);
  for(int i=1;i<=n;++i){
    int v;cin>>v;
    pref[i]=pref[i-1]+v;
    vs[i]=algo::cdiv(pref[i],i);
  }
  auto f=[](wint x,wint y){return max(x,y);};
  auto ef=[]{return wint(0);};
  algo::id11<wint,decltype(f),decltype(ef)>
  seg(vs.begin(),vs.end(),f,ef);
  auto opt=[pref=move(pref),n,&seg](int t){
    int lo=1,hi=n+1;
    while(lo<hi){
      const int k=(lo+hi)>>1;
      const wint fx=max(seg.query(1,k),algo::cdiv(pref[n],k));
      if(t<fx){
        lo=k+1;
      }else{
        hi=k;
      }
    }
    return lo==n+1?-1:lo;
  };
  int q;cin>>q;
  while(q--){
    int t;cin>>t;
    cout<<opt(t)<<'\n';
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
