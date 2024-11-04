











































namespace algo::detail {
template <typename Tp>
concept integer = std::integral<Tp> && !std::same_as<Tp, bool>;
template <typename Tp>
concept signed_integer = integer<Tp> &&(Tp(-1) < Tp(0));
template <typename Tp>
concept unsigned_integer = integer<Tp> &&(Tp(-1) > Tp(0));
template <typename From, typename To>
concept sign_compatible_with = integer<From> &&
    ((std::is_signed_v<From> && std::is_signed_v<To>) ||
     (std::is_unsigned_v<From> && std::is_unsigned_v<To>));
template <typename Tp>
concept qword_fittable = sizeof(Tp) <= 8UL;
template <typename Tp>
concept dword_fittable = qword_fittable<Tp> && sizeof(Tp) <= 4UL;
template <typename Tp>
concept word_fittable = dword_fittable<Tp> && sizeof(Tp) <= 2UL;
template <typename Tp>
concept byte_fittable = word_fittable<Tp> && sizeof(Tp) == 1UL;
template <typename Tp>
struct imul_result {
  static_assert(integer<Tp>);
};
template <qword_fittable Tp>
struct imul_result<Tp> {
  using type =
      std::conditional_t<std::is_signed_v<Tp>, __int128_t, __uint128_t>;
};
template <dword_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int64_t, uint64_t>;
};
template <word_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int32_t, uint32_t>;
};
template <byte_fittable Tp>
struct imul_result<Tp> {
  using type = std::conditional_t<std::is_signed_v<Tp>, int16_t, uint16_t>;
};
template <typename Tp>
using imul_result_t = typename imul_result<Tp>::type;
template <typename Sig>
struct function_traits;
template <typename Ret, typename... Args>
struct function_traits<Ret(Args...)> {
  using return_type = Ret;
  template <typename Fn>
  static inline constexpr bool same_as =
      std::is_invocable_r_v<return_type, Fn, Args...>;
};
template <typename Fn, typename Sig>
concept function = function_traits<Sig>::template same_as<Fn>;
template <typename IIter, typename Value>
concept input_iterator =
    std::input_iterator<IIter> && std::same_as<std::iter_value_t<IIter>, Value>;
}
namespace algo::detail {
template <typename Tp>
constexpr int
id3(Tp n) {
  return std::countl_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
id10(Tp n) {
  return std::countr_zero<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr int
bit_width(Tp n) {
  return std::bit_width<std::make_unsigned_t<Tp>>(n);
}
template <typename Tp>
constexpr Tp
id4(Tp n) {
  return static_cast<Tp>(std::bit_floor<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr Tp
id1(Tp n) {
  return static_cast<Tp>(std::bit_ceil<std::make_unsigned_t<Tp>>(n));
}
template <typename Tp>
constexpr int
id2(Tp n) {
  return bit_width(n) - 1;
}
template <typename Tp>
constexpr int
id9(Tp n) {
  return bit_width(n - (n != 0));
}
template <typename Tp>
constexpr Tp
blsr(Tp n) {
  if (std::is_constant_evaluated()) { return n & (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsr_u64(n));
  } else {
    return n & (n - 1);
  }
}
template <typename Tp>
constexpr Tp
blsi(Tp n) {
  if (std::is_constant_evaluated()) { return n & -n; }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsi_u64(n));
  } else {
    return n & -n;
  }
}
template <typename Tp>
constexpr Tp
id11(Tp n) {
  if (std::is_constant_evaluated()) { return n ^ (n - 1); }
  if constexpr (dword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u32(n));
  } else if constexpr (qword_fittable<Tp>) {
    return static_cast<Tp>(_blsmsk_u64(n));
  } else {
    return n ^ (n - 1);
  }
}
template <typename Tp>
constexpr int
popcount(Tp n) {
  return std::popcount<std::make_unsigned_t<Tp>>(n);
}
}
namespace algo {
template <detail::integer Tp>
constexpr int
id3(Tp n) {
  return detail::id3(n);
}
template <detail::integer Tp>
constexpr int
id10(Tp n) {
  return detail::id10(n);
}
template <detail::integer Tp>
constexpr int
bit_width(Tp n) {
  return detail::bit_width(n);
}
template <detail::integer Tp>
constexpr Tp
id4(Tp n) {
  return detail::id4(n);
}
template <detail::integer Tp>
constexpr Tp
id1(Tp n) {
  return detail::id1(n);
}
template <detail::integer Tp>
constexpr int
id2(Tp n) {
  return detail::id2(n);
}
template <detail::integer Tp>
constexpr int
id9(Tp n) {
  return detail::id9(n);
}
template <detail::integer Tp>
constexpr Tp
popcount(Tp n) {
  return detail::popcount(n);
}
}
namespace dbg {

}
namespace algo::detail {
constexpr void
assume(bool expr) {
  if (!expr) { __builtin_unreachable(); }
}
}
namespace algo::detail {
template <typename Tp>
constexpr Tp
sqrt(Tp n) {
  if (n <= 1) { return n; }
  Tp ans = 0;
  for (int i = id2(n) - 1; i >= 0; --i) {
    const Tp tmp = (n - ans * ans) >> i;
    if ((ans << 1) + (Tp(1) << i) <= tmp) { ans |= Tp(1) << i; }
  }
  return ans;
}
template <typename Tp>
constexpr Tp
abs(Tp n) {
  return n < 0 ? -n : n;
}
template <typename Tp>
constexpr Tp
floor_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return x / y - ((x ^ y) < 0 && x % y != 0);
  } else {
    return x / y;
  }
}
template <typename Tp>
constexpr Tp
ceil_div(Tp x, Tp y) {
  if constexpr (std::is_signed_v<Tp>) {
    return y > 0 ? floor_div(x + y - 1, y) : -floor_div(x, -y);
  } else {
    return floor_div(x + y - 1, y);
  }
}
template <typename Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return -(n & 1) | 1;
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
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
floor_div(T1 x, T2 y) {
  assert(y != 0);
  return detail::floor_div<std::common_type_t<T1, T2>>(x, y);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2>
constexpr std::common_type_t<T1, T2>
ceil_div(T1 x, T2 y) {
  assert(y != 0);
  return detail::ceil_div<std::common_type_t<T1, T2>>(x, y);
}
template <std::integral Tp>
constexpr std::make_signed_t<std::common_type_t<Tp, char>>
alt(Tp n) {
  return detail::alt(n);
}
template <detail::integer T1, detail::sign_compatible_with<T1> T2,
          detail::sign_compatible_with<T2> T3,
          detail::sign_compatible_with<T3> T4>
constexpr std::common_type_t<T1, T2, T3, T4>
floor_sum(T1 a, T2 b, T3 c, T4 n) {
  assert(n >= 0);
  assert(c > 0);
  assert(a >= 0);
  detail::assume(n >= 0);
  detail::assume(c > 0);
  detail::assume(a >= 0);
  typedef std::common_type_t<T1, T2, T3, T4> Tp;
  Tp res = 0, a0 = a, b0 = b, c0 = c, n0 = n;
  bool neg = false;
  while (a0 != 0) {
    if (a0 < c0 && b0 < c0) {
      const Tp m = (a0 * n0 + b0) / c0;
      const Tp tmp = a0;
      res += alt(neg) * m * n0;
      b0 = c0 - b0 - 1, a0 = c0, c0 = tmp, n0 = m - 1;
      neg ^= true;
    } else {
      const Tp tmp = (n0 * (n0 + 1) >> 1) * (a0 / c0) + (n0 + 1) * (b0 / c0);
      res += alt(neg) * tmp;
      a0 %= c0, b0 %= c0;
    }
  }
  res += alt(neg) * (b0 / c0) * (n0 + 1);
  return res;
}
}
namespace algo {
struct id8 {
  constexpr id8() = default;
  constexpr id8(int n) : id6(detail::id9(n)), dim_(1 << id6) {}
  constexpr int64_t
  order(int x, int y) const {
    assert(0 <= x && x < dim_);
    assert(0 <= y && y < dim_);
    int64_t res = 0;
    for (int i = id6; i-- > 0;) {
      const bool rx = (x >> i) & 1;
      const bool ry = (y >> i) & 1;
      res += (static_cast<int64_t>(1) << (i + i)) * Rot[rx][ry];
      if (!rx) {
        x = ry ? dim_ - 1 - x : x;
        y = ry ? dim_ - 1 - y : y;
        std::swap(x, y);
      }
    }
    return res;
  }
private:
  static constexpr int Rot[2][2]{{0, 3}, {1, 2}};
  int id6, dim_;
};
struct custom_hash {
  static inline const uint64_t fx =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  static inline uint64_t
  hash64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }
  static inline uint32_t
  hash32(uint32_t x) {
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = ((x >> 16) ^ x) * 0x45d9f3b;
    x = (x >> 16) ^ x;
    return x;
  }
  inline size_t
  operator()(detail::qword_fittable auto x) const {
    return hash64(x ^ fx);
  }
  inline size_t
  operator()(detail::dword_fittable auto x) const {
    return hash32(x ^ fx);
  }
};
}
namespace algo {
class dsu {
public:
  dsu() : n_(0), fa_{} {}
  explicit dsu(int n) : n_(n), fa_(n, -1) {}
  int
  merge(int a, int b) {
    assert(0 <= a && a < n_);
    assert(0 <= b && b < n_);
    int sa = leader(a), sb = leader(b);
    if (sa != sb) {
      if (-fa_[sa] < -fa_[sb]) { std::swap(sa, sb); }
      fa_[sa] += fa_[sb];
      fa_[sb] = sa;
    }
    return sa;
  }
  int
  leader(int a) {
    assert(0 <= a && a < n_);
    if (fa_[a] >= 0) {
      fa_[a] = leader(fa_[a]);
      return fa_[a];
    }
    return a;
  }
  int
  size(int a) {
    assert(0 <= a && a < n_);
    return -fa_[leader(a)];
  }
  bool
  is_same(int a, int b) {
    assert(0 <= a && a < n_);
    assert(0 <= b && b < n_);
    return leader(a) == leader(b);
  }
private:
  int n_;
  std::vector<int> fa_;
};
}
namespace algo {
template <std::semiregular Monoid,
          detail::function<Monoid(Monoid, Monoid)> BinOp,
          detail::function<Monoid()> Id>
class id7 {
public:
  id7() = default;
  id7(int n, BinOp binop, Id id)
      : n_(n),
        id6(detail::id9(n)),
        size_(1 << id6),
        tree_(size_ << 1, id()),
        binop_(std::move(binop)),
        id_(std::move(id)) {}
  id7(int n, const Monoid& init, BinOp binop, Id id)
      : n_(n),
        id6(detail::id9(n)),
        size_(1 << id6),
        tree_(size_ << 1, init),
        binop_(std::move(binop)),
        id_(std::move(id)) {
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <detail::input_iterator<Monoid> IIter>
  id7(IIter first, IIter last, BinOp binop, Id id)
      : id7(std::distance(first, last), std::move(binop), std::move(id)) {
    std::copy(first, last, tree_.begin() + size_);
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  template <std::input_iterator IIter,
            detail::function<Monoid(std::iter_value_t<IIter>)> Gen>
  id7(IIter first, IIter last, BinOp binop, Id id, Gen gen)
      : id7(std::distance(first, last), std::move(binop), std::move(id)) {
    std::transform(first, last, tree_.begin() + size_, std::move(gen));
    for (int i = size_ - 1; i > 0; --i) { update(i); }
  }
  void
  set(int pos, Monoid new_val) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = std::move(new_val);
    for (int i = 1; i <= id6; ++i) { update(pos >> i); }
  }
  Monoid
  get(int pos) const {
    assert(0 <= pos && pos < size());
    return tree_[pos + size_];
  }
  void
  apply(int pos, Monoid z) {
    assert(0 <= pos && pos < size());
    pos += size_;
    tree_[pos] = binop_(std::move(tree_[pos]), std::move(z));
    for (int i = 1; i <= id6; ++i) { update(pos >> i); }
  }
  Monoid
  query(int l, int r) const {
    assert(0 <= l && l <= r && r <= size());
    Monoid resl = id_(), resr = id_();
    l += size_;
    r += size_;
    const int mask = (1 << detail::id2(--l ^ r)) - 1;
    for (int v = mask & ~l; v != 0; v = detail::blsr(v)) {
      resl = binop_(std::move(resl), tree_[(l >> detail::id10(v)) + 1]);
    }
    for (int v = mask & r; v != 0; v = detail::blsr(v)) {
      resr = binop_(tree_[(r >> detail::id10(v)) - 1], std::move(resr));
    }
    return binop_(std::move(resl), std::move(resr));
  }
  Monoid
  query() const {
    return tree_[1];
  }
  template <std::predicate<Monoid> Pred>
  int
  id5(int l, const Pred& pred) const {
    assert(0 <= l && l <= size());
    assert(pred(id_()));
    if (l < n_) [[likely]] {
      l += size_;
      Monoid cur = id_();
      do {
        l >>= detail::id10(l);
        if (!pred(binop_(cur, tree_[l]))) {
          while (l < size_) {
            l <<= 1;
            if (Monoid tmp = binop_(cur, tree_[l]); pred(tmp)) {
              cur = std::move(tmp), ++l;
            }
          }
          return l - size_;
        }
        cur = binop_(std::move(cur), tree_[l++]);
      } while (detail::popcount(l) != 1);
    }
    return n_;
  }
  template <std::predicate<Monoid> Pred>
  int
  id0(int r, const Pred& pred) const {
    assert(0 <= r && r <= size());
    if (r > 0) [[likely]] {
      r += size_ - 1;
      Monoid cur = id_();
      do {
        r >>= detail::id10(~r);
        if (!pred(binop_(tree_[r], cur))) {
          while (r < size_) {
            r <<= 1;
            r |= 1;
            if (Monoid tmp = binop_(tree_[r], cur); pred(tmp)) {
              cur = std::move(tmp), --r;
            }
          }
          return r + 1 - size_;
        }
        cur = binop_(tree_[r], std::move(cur));
      } while (detail::popcount(r--) != 1);
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
  int n_, id6, size_;
  std::vector<Monoid> tree_;
  BinOp binop_;
  Id id_;
};
}

using std::array;
using std::bitset;
using std::cin;
using std::complex;
using std::cout;
using std::deque;
using std::endl;
using std::gcd;
using std::lcm;
using std::map;
using std::max;
using std::min;
using std::move;
using std::multimap;
using std::multiset;
using std::pair;
using std::queue;
using std::set;
using std::stack;
using std::string;
using std::swap;
using std::tie;
using std::to_string;
using std::tuple;
using std::vector;
using wint = int64_t;
using uint = uint32_t;
template <typename Key, typename Value, typename Hash = std::hash<Key>>
using umap = std::unordered_map<Key, Value, Hash>;
template <typename Value, typename Hash = std::hash<Value>>
using uset = std::unordered_set<Value, Hash>;
template <typename Tp, typename Comp = std::less<Tp>>
using max_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;
template <typename Tp, typename Comp = std::greater<Tp>>
using min_heap = std::priority_queue<Tp, std::vector<Tp>, Comp>;





namespace {
}
void solve() noexcept {
  int n,m,q;cin>>n>>m>>q;
  struct edge{
    int to,k;
  };
  vector<vector<edge>>adj(n);
  algo::dsu uf(n);
  for(int i=0;i<m;++i){
    int u,v;cin>>u>>v;
    --u,--v;
    if(!uf.is_same(u,v)){
      uf.merge(u,v);
      adj[u].emplace_back(v,i+1);
      adj[v].emplace_back(u,i+1);
    }
  }
  vector<int>tour,pos(n);
  tour.reserve(2*n-1);
  auto dfs=[&](auto dfs,int u,int p)->void{
    pos[u]=ssize(tour);
    for(const auto[v,k]:adj[u]){
      if(v!=p){
        tour.emplace_back(k);
        dfs(dfs,v,u);
        tour.emplace_back(k);
      }
    }
  };
  dfs(dfs,0,0);
  struct query{
    int l,r,u;
    wint ord;
    bool operator<(query q)const{return ord<q.ord;}
  };
  algo::id8 ord(2*n-1);
  vector<query>cq(n-1);
  for(int u=0;u<n-1;++u){
    int l=min(pos[u],pos[u+1]),r=max(pos[u],pos[u+1]);
    cq[u]={l,r-1,u,ord.order(l,r)};
  }
  sort(cq.begin(),cq.end());
  constexpr int M=algo::sqrt(MAXN)+5;
  vector<int>cb(M),cnt(m+1);
  vector<int>xn(n-1);
  int cl=0,cr=-1;
  auto upd=[&](int x){
    cb[x/M]-=cnt[x];
    cnt[x]^=1;
    cb[x/M]+=cnt[x];
  };
  for(const auto[l,r,u,_]:cq){
    while(cl>l){
      cl--;
      upd(tour[cl]);
    }
    while(cr<r){
      ++cr;
      upd(tour[cr]);
    }
    while(cl<l){
      upd(tour[cl]);
      ++cl;
    }
    while(cr>r){
      upd(tour[cr]);
      --cr;
    }
    int blk=m/M;
    while(blk>=0&&cb[blk]==0){--blk;}
    blk=min(m,(blk+1)*M-1);
    while(cnt[blk]==0){--blk;}
    xn[u]=blk;
  }
  auto f=[](int x,int y){return max(x,y);};
  auto ef=[]{return 0;};
  algo::id7<int,decltype(f),decltype(ef)>seg(xn.begin(),xn.end(),f,ef);
  while(q--){
    int l,r;cin>>l>>r;
    cout<<seg.query(--l,--r)<<' ';
  }
  cout<<'\n';
}
int main() {
  std::ios_base::sync_with_stdio(0);
  std::cin.tie(0);
  std::cout.tie(0);
  std::cout.precision(15);
  int tc;
  std::cin >> tc;
  while (tc--) { solve(); }
  return 0;
}
