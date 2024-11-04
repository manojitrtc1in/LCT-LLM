#include <bits/stdc++.h>
constexpr bool Interactive = false;

namespace Narut {

  struct {
    template <class T> auto operator<<(const T& t) const -> decltype((void) (std::cerr << t), *this) { std::cerr << "\033[0;31m" << t << "\033[0m"; return *this; }
    auto operator<< (std::ostream& (*f)(std::ostream&)) const { std::cerr << f; return *this; }
  } Cerr_red;
  #define CAN_(f) template <class, class=void> struct Can##f : std::false_type {}; template <class T> struct Can##f<T, decltype((void)f(std::declval<T&>())) > : std::true_type {};

  template <class T, class=void> struct IsIterable : std::false_type {}; template <class T> struct IsIterable<T, decltype((void)std::begin(std::declval<T&>()), (void)std::end(std::declval<T&>())) > : std::true_type {};

  template <decltype(auto) os, bool Flush = false, decltype(auto) PairSep = ' ', decltype(auto) PairEnd = '\n'>
  struct Writer {
    static constexpr char Sep = ' ', Sep2D = '\n';
    template <class, class = void> struct Osable : std::false_type {};
    template <class T> struct Osable<T, decltype((void)(os << std::declval<T&>())) > : std::true_type {};
    template <class Tuple, std::size_t... Is> static void TupleImpl(const Tuple& t, std::index_sequence<Is...>) { (void) (int[]) {0, (Write(PairSep), Write(std::get<Is+1>(t)), 0)... }; }
    template <class First, class... Ts> static void TupleImpl(const std::tuple<First, Ts...> &t) { Write(std::get<0>(t)); if constexpr (sizeof...(Ts) != 0) TupleImpl(t, std::index_sequence_for<Ts...>{}); }
    static void TupleImpl(const std::tuple<>&) {}
    template <class F, class S> static void PairImpl(const std::pair<F,S>& p) { Write(p.first), Write(PairSep), Write(p.second); }
    CAN_(PairImpl) CAN_(TupleImpl)
    template <class T> static void SepImpl (const T&) {
      if constexpr ( Osable<T>::value ) os << Sep;
      else if constexpr ( CanPairImpl<T>::value or CanTupleImpl<T>::value ) os << PairEnd;
      else os << Sep2D;
    }
    template <class T> static void IterableImpl(const T& t) {
      using std::begin, std::end;
      auto it = begin(t);
      if (it != end(t)) Write(*it++);
      while (it != end(t)) SepImpl(*it), Write(*it++);
    }
    template <class T> static void Write(const T& t) {
      if constexpr ( Osable<T>::value ) os << t;
      else if constexpr ( CanPairImpl<T>::value ) PairImpl(t);
      else if constexpr ( CanTupleImpl<T>::value ) TupleImpl(t);
      else if constexpr ( IsIterable<T>::value ) IterableImpl(t);
      else static_assert( IsIterable<T>::value, "No Matching Write Call!");
    }
    auto operator() () const { if constexpr (Flush) os << std::endl; else os << '\n'; return *this; }
    template <class First, class... Args> auto operator() (const First& f, const Args&... args) const { Write(f); (void) (int[]) {0, (Write(Sep), Write(args), 0)... }; return (*this)(); }
  };

  template <decltype(auto) is>
  struct Reader {
    template <class, class = void> struct Isable : std::false_type {}; template <class T> struct Isable<T, decltype((void)(is >> std::declval<T&>()))  > : std::true_type {};
    template <class T, class S> static void PairImpl(std::pair<T, S> &p) { Read(p.first); Read(p.second); }
    template <class Tuple, std::size_t... Is> static void TupleImpl(Tuple &t, std::index_sequence<Is...>) { (void) (int[]) {0, ( Read(std::get<Is>(t)), 0)... }; }
    template <class... Ts> static void TupleImpl(std::tuple<Ts...> &t) { TupleImpl(t, std::index_sequence_for<Ts...>{}); }
    template <class T> static void IterableImpl(T& t) { for (auto && x : t) Read(x); }
    CAN_(PairImpl) CAN_(TupleImpl)
    template <class T> static void Read(T& x) {
      if constexpr ( Isable<T>::value ) is >> x;
      else if constexpr ( CanPairImpl<T>::value ) PairImpl(x);
      else if constexpr ( CanTupleImpl<T>::value ) TupleImpl(x);
      else if constexpr ( IsIterable<T>::value ) IterableImpl(x);
      else static_assert ( IsIterable<T>::value, "No Matching Read!");
    }
    template <class T> operator T() const { T x; Read(x); return x; }
    template <class... Ts> auto operator() (Ts&... ts) const { (void) (int[]) { 0, (Read(ts), 0)... }; return *this; }
  };

  #ifdef NARUT_LOCAL
  Writer<(Cerr_red), false, ':', ' '> Debug;
  #else
  struct { template <class... Args> void operator()(Args&&...) const {} } Debug;
  #endif

  template <class T, int off=1> struct Offset : T {
    using T::T;
    Offset(const T& other) : T(other) {}
    Offset(T&& other) noexcept : T(std::move(other)) {}
    decltype(auto) operator[] (int i) { return T::operator[](i-off); }
    decltype(auto) operator[] (int i) const { return T::operator[](i-off); }
    decltype(auto) at (int i) { return T::at(i-off); }
    decltype(auto) at (int i) const { return T::at(i-off); }
  };

  template <class T> struct Vec : std::vector<T> {
    using std::vector<T>::vector;
    Vec(const std::vector<T>& other) : std::vector<T>(other) {}
    Vec(std::vector<T>&& other) noexcept : std::vector<T> (std::move(other)) {}
    Vec& operator() (int n) { this->resize(n); return *this; }
    Vec& operator()(int n, const T& t) { this->assign(n,t); return *this; }
  };

  template <class T, template <class Elem> class Base> struct MatBase : Base<Base<T> > {
    MatBase() = default;
    MatBase(int n) : Base<Base<T> >(n) {}
    MatBase(int n, int m, const T& t = {}) : Base<Base<T> >(n) { for (auto &v : *this) v.assign(m, t); }
    MatBase& operator() (int n) { this->resize(n); return *this; }
    MatBase& operator() (int n, int m, const T& t = {}) { this->resize(n); for (auto &v : *this) v.assign(m, t); return *this; }
  };

  template <template<class Elem, int S> class Base, class T, int NF, int... Ns>
  struct ArrRec : Base<ArrRec<Base, T, Ns...>, NF> {
    using Base<ArrRec<Base, T, Ns...>, NF>::Base;
    ArrRec& operator() (const T& t) { for (auto &a : *this) a(t); return *this; }
  };
  template <template<class Elem, int S> class Base, class T, int NF> struct ArrRec<Base, T, NF> : Base<T, NF> { using Base<T, NF>::Base; };

  template <class T, int N> struct ArrBase : std::array<T, N> {
    constexpr ArrBase() : std::array<T, N>{} {}
    constexpr ArrBase (std::initializer_list<T> il) { int i = 0; for (auto a : il) (*this)[i++] = a; }
    constexpr ArrBase(const std::array<T, N>& other) : std::array<T, N>(other) {}
    constexpr ArrBase(std::array<T, N>&& other) : std::array<T, N>(std::move(other)) {}
    ArrBase& operator() (const T& t) { this->fill(t); return *this; }
  };
  template <class T, int N> using ArrBase1 = Offset<ArrBase<T, N> >;

  template <class T, class = void> struct Greater { constexpr bool operator() (const T& lhs, const T& rhs) const { return rhs < lhs; } };
  template <class T> struct Greater<T, decltype((void)(std::declval<T&>() > std::declval<T&>()))> : std::greater<T> {};

  template <class T> using MaxPQ = std::priority_queue<T>;
  template <class T> using MinPQ = std::priority_queue<T, std::vector<T>, Greater<T> >;

  template <class T, class Cmp = std::less<void> > void Sort(T& t, Cmp cmp = {}) { std::sort(std::begin(t), std::end(t), cmp); }
  template <class T> void Unique(T& t) { t.erase(std::unique(std::begin(t), std::end(t)), std::end(t)); }
  template <class T> void PartialSum(T& t) { std::partial_sum(std::begin(t), std::end(t), std::begin(t)); }
  template <class T=int> auto Iota(int n, const T& t = {}) { Vec<T> v(n); std::iota(v.begin(), v.end(), t); return v; }
  template <class T, class U = typename T::value_type> auto Sum (const T& t, U u = {}) { return std::accumulate(std::begin(t), std::end(t), u); }
  struct Infinity { template <class T> operator T() const { return std::numeric_limits<T>::max(); } } Inf;
  struct BigNumber { operator int() const { return 0x3f3f3f3f;} operator long long() const{ return 0x3f3f3f3f3f3f3f3f; } } BigNum;

  

  void IO() {
    #ifdef NARUT_LOCAL
    #define NAME "io/test"
    if (!Interactive and !freopen(NAME ".in", "r", stdin)) Debug("freopen failed");
    

    std::cerr << std::fixed << std::setprecision(10) << std::boolalpha;
    #endif
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(10);
  }

  namespace Export {
    Writer<(std::cout), Interactive> Cout;
    Reader<(std::cin)> Cin;
    using Narut::Debug, Narut::MaxPQ, Narut::MinPQ, Narut::Offset, Narut::Vec;
    using Narut::Sort, Narut::PartialSum, Narut::Unique, Narut::Iota, Narut::Sum, Narut::Inf, Narut::BigNum;
    using ll = long long;
    using Pii = std::pair<int, int>; using Pll = std::pair<ll, ll>;
    template <class T> using Vec1 = Offset<Vec<T> >;
    using Vi = Vec<int>; using Vi1 = Vec1<int>; using Vl = Vec<ll>; using Vc = Vec<char>;
    template <class T> using Mat = MatBase<T, Vec>;
    template <class T> using Mat1 = MatBase<T, Vec1>;
    template <class T, int N, int... Ns> using Arr = ArrRec<Narut::ArrBase, T, N, Ns...>;
    template <class T, int N, int... Ns> using Arr1 = ArrRec<Narut::ArrBase1, T, N, Ns...>;

    using std::abs, std::accumulate, std::acos, std::acosh, std::array, std::asin, std::asinh, std::atan, std::atanh, std::binary_search, std::bitset, std::cbrt, std::ceil, std::cin, std::cos, std::cosh, std::cout, std::deque, std::div, std::equal_range, std::exp, std::floor, std::gcd, std::get, std::getline, std::greater, std::hypot, std::iota, std::istringstream, std::lcm, std::ldexp, std::log, std::lower_bound, std::map, std::max, std::max_element, std::min, std::min_element, std::minmax, std::minmax_element, std::multimap, std::multiset, std::nearbyint, std::nth_element, std::next_permutation, std::optional, std::ostringstream, std::pair, std::partial_sum, std::pow, std::prev_permutation, std::queue, std::reverse, std::rint, std::round, std::runtime_error, std::set, std::shared_ptr, std::sin, std::sinh, std::sort, std::sqrt, std::stable_sort, std::stack, std::stod, std::stof, std::stoi, std::stol, std::stold, std::stoll, std::string, std::string_view, std::stringstream, std::swap, std::tan, std::tanh, std::to_string, std::trunc, std::tuple, std::unique, std::unique_ptr, std::unordered_map, std::unordered_multimap, std::unordered_multiset, std::unordered_set, std::upper_bound, std::vector;
  }
}
using namespace Narut::Export;

int n,m;

Mat1<Pii> G;
Mat1<Pii> MST;


int timer, l;
Vi1 tin, tout;
Vec1<Vec<Pii> > up;

void DFS(int v, int p, int w)
{
  tin[v] = ++timer;
  up[v][0] = {p,w};
  for (int i = 1; i <= l; i++) {
    up[v][i].first = up[up[v][i-1].first][i-1].first;
    up[v][i].second = max(up[v][i-1].second, up[up[v][i-1].first][i-1].second);
  }  
  for (auto [u, x]:MST[v]) DFS(u, v, x);
  tout[v] = ++timer;
}

void BuildLCA()
{
  tin(n), tout(n);
  l = ceil(log2(n));
  up(n, Vec<Pii>(l+1));
  DFS(1,1,0);
}

bool IsAnc(int u, int v) { return tin[u] <= tin[v] and tout[u] >= tout[v]; }

int LCA(int u, int v) {
  if (IsAnc(u, v)) return u;
  if (IsAnc(v, u)) return v;
  for (int i = l; i >= 0; i--) {
    if(!IsAnc(up[u][i].first, v)) u = up[u][i].first;
  }
  return up[u][0].first;
}

int AncWeight(int lca, int u) {
  if (u == lca) return 0;
  int w = 0;
  for (int i = l; i >= 0; i--) {
    if (!IsAnc(up[u][i].first, lca)) {
      w = max(up[u][i].second, w);        
      u = up[u][i].first;
    }
  }   
  return max(w, up[u][0].second);
}

int MaxEdge(int u, int v) {
  int lca = LCA(u,v);
  return max(AncWeight(lca, u), AncWeight(lca, v));
}

auto Solve()
{
  BuildLCA();

  int ans = 0;
  for (int u = 1; u <= n; u++) {
    for (auto [v, w]: G[u]) {
      auto e = MaxEdge(u, v);
      

      if (e==w) ans++;      
    }
  }
  return ans;
}

void BuildMST()
{
  MST(n);
  MinPQ<array<int,3> > pq;

  Vec1<char> vis(n);
  for(auto [v,w]: G[1]) pq.push({w,1,v});
  vis[1] = 1;

  while (pq.size()) {
    auto [w, u, v] = pq.top();
    pq.pop();
    if (vis[v]) continue;
    vis[v]=1;

    MST[u].push_back({v,w});
    for(auto [x, w]:G[v]) pq.push({w, v, x});
  }
}














auto Run()
{
  cin>>n>>m;
  G(n);
  for (int i = 0; i < m; i++) {
    int u, v, w; cin>>u>>v>>w;
    G[u].push_back({v, w}), G[v].push_back({u, w});
  }
  BuildMST();
  

  auto s = Solve();
  cout << (s/2 - n + 1);
}

int main() {
  Narut::IO();
  Run();
}