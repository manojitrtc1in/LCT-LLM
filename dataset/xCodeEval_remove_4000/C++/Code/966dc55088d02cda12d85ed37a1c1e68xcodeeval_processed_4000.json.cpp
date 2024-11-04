
using namespace std;









using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}


template<::std::uint_fast64_t mod>
class ModInt{
private:
  using value_type = ::std::uint_fast64_t;
  value_type n;
public:
  ModInt() : n(0) {}
  ModInt(value_type n_) : n(n_ % mod) {}
  ModInt(const ModInt& m) : n(m.n) {}

  template<typename T>
  explicit operator T() const { return static_cast<T>(n); }
  value_type get() const { return n; }

  friend ::std::ostream& operator<<(::std::ostream &os, const ModInt<mod> &a) {
    return os << a.n;
  }

  friend ::std::istream& operator>>(::std::istream &is, ModInt<mod> &a) {
    value_type x;
    is >> x;
    a = ModInt<mod>(x);
    return is;
  }

  bool operator==(const ModInt& m) const { return n == m.n; }
  bool operator!=(const ModInt& m) const { return n != m.n; }
  ModInt& operator*=(const ModInt& m){ n = n * m.n % mod; return *this; }

  ModInt pow(value_type b) const{
    ModInt ans = 1, m = ModInt(*this);
    while(b){
      if(b & 1) ans *= m;
      m *= m;
      b >>= 1;
    }
    return ans;
  }

  ModInt inv() const { return (*this).pow(mod-2); }
  ModInt& operator+=(const ModInt& m){ n += m.n; n = (n < mod ? n : n - mod); return *this; }
  ModInt& operator-=(const ModInt& m){ n += mod - m.n; n = (n < mod ? n : n - mod); return *this; }
  ModInt& operator/=(const ModInt& m){ *this *= m.inv(); return *this; }
  ModInt operator+(const ModInt& m) const { return ModInt(*this) += m; }
  ModInt operator-(const ModInt& m) const { return ModInt(*this) -= m; }
  ModInt operator*(const ModInt& m) const { return ModInt(*this) *= m; }
  ModInt operator/(const ModInt& m) const { return ModInt(*this) /= m; }
  ModInt& operator++(){ n += 1; return *this; }
  ModInt& operator--(){ n -= 1; return *this; }
  ModInt operator++(int){
    ModInt old(n);
    n += 1;
    return old;
  }
  ModInt operator--(int){
    ModInt old(n);
    n -= 1;
    return old;
  }
  ModInt operator-() const { return ModInt(mod-n); }
};
template<::std::size_t size, ::std::uint_fast64_t mod=1000000007>
class Factorial{
private:
  using value_type = ModInt<mod>;
  ::std::vector<value_type> fact, inv;
public:
  Factorial() : fact(size+1, 1), inv(size+1, 1){
    for(::std::size_t i = 1; i <= size; ++i){
      fact[i] = fact[i-1] * value_type(i);
      inv[i] = fact[i].inv();
    }
  }

  value_type comb(::std::int64_t a, ::std::int64_t b){
    assert(a >= b);
    assert(b >= 0);
    return fact[a]*inv[b]*inv[a-b];
  }

  value_type& operator[](::std::size_t k){ return fact[k]; }
};

class UnionFind{
private:
  ::std::vector<int32_t> par;
  size_t n;

public:
  UnionFind(){}
  UnionFind(size_t n):n(n){
    par.resize(n, -1);
  }

  uint32_t find(uint32_t x){
    return par[x] < 0 ? x : par[x] = find(par[x]);
  }

  size_t size(uint32_t x){
    return -par[find(x)];
  }

  bool unite(uint32_t x, uint32_t y){
    x = find(x);
    y = find(y);
    if(x == y) return false;
    if(size(x) < size(y)) std::swap(x, y);
    par[x] += par[y];
    par[y] = x;
    return true;
  }

  bool same(uint32_t x, uint32_t y){
    return find(x) == find(y);
  }
};


template<class ValueMonoid, class OperatorMonoid, class Modifier,
  template<class...> class Container=::std::vector>
class id0{
public:
  using value_structure = ValueMonoid;
  using value_type = typename value_structure::value_type;
  using operator_structure = OperatorMonoid;
  using operator_type = typename operator_structure::value_type;
  using modifier = Modifier;
  using const_reference = const value_type &;
  using container_value_type = Container<value_type>;
  using container_operator_type = Container<operator_type>;
  using size_type = typename container_value_type::size_type;

private:
  container_value_type tree;
  container_operator_type lazy;
  size_type size_, height;

  static size_type getsize(const size_type x){
    size_type ret = 1;
    while(ret < x)
      ret <<= 1;
    return ret;
  }

  static size_type getheight(const size_type x){
    size_type ret = 0;
    while((static_cast<size_type>(1) << ret) < x){
      ret++;
    }
    return ret;
  }

  inline static value_type calc(const value_type a, const value_type b){
    return value_structure::operation(a, b);
  }

  inline static void apply(operator_type &data, const operator_type a){
    data = operator_structure::operation(data, a);
  }

  inline static value_type reflect(const value_type v, const operator_type o){
    return modifier::operation(v, o);
  }

  void push(const size_type index){
    tree[index] = reflect(tree[index], lazy[index]);
    apply(lazy[index << 1], lazy[index]);
    apply(lazy[index << 1 | 1], lazy[index]);
    lazy[index] = operator_structure::identity();
  }

  void calc_node(const size_type index){
    if(tree.size() <= (index << 1 | 1)) return;
    assert(0 < index);
    tree[index] = calc(reflect(tree[index << 1],  lazy[index << 1]),
                       reflect(tree[index << 1 | 1], lazy[index << 1 | 1]));
  }

  void build(size_type index){
    while(index >>= 1){
      calc_node(index);
    }
  }

  void propagate(const size_type index){
    for(size_type shift = height; shift ; --shift){
      push(index >> shift);
    }
  }

  void rebuild(){
    for(size_type i = size_-1;i > 0;--i){
      calc_node(i);
    }
  }
public:
  id0() : size_(0), height(0), tree(), lazy(){}
  id0(const size_type size)
    : size_(size), height(getheight(size)),
      tree(size << 1, value_structure::initializer()),
      lazy(size << 1, operator_structure::identity()){
    rebuild();
  }
  template<class InputIterator>
  id0(InputIterator first, InputIterator last)
    : size_(::std::distance(first, last)){
    height = getheight(size_);
    tree = container_value_type(size_, value_structure::identity());
    lazy = container_operator_type(size_ << 1, operator_structure::identity());
    tree.insert(tree.end(), first, last);
    rebuild();
  }

  size_type size() const { return size_; }
  const_reference operator[](const size_type k){
    assert(k < size_);
    propagate(k+size_);
    tree[k+size_] = reflect(tree[k+size_], lazy[k+size_]);
    lazy[k+size_] = operator_structure::identity();
    return tree[k+size_];
  }

  value_type query(size_type l, size_type r){
    assert(l <= r);
    assert(0 <= l && l < size_);
    assert(0 <= r && r <= size_);
    value_type retl = value_structure::identity(),
      retr = value_structure::identity();
    l += size_;
    r += size_;
    propagate(l);
    propagate(r-1);
    build(l);
    build(r-1);
    for(; l < r ; l >>= 1, r >>= 1){
      if(l&1){
        retl = calc(retl, reflect(tree[l], lazy[l]));
        l++;
      }
      if(r&1){
        r--;
        retr = calc(reflect(tree[r], lazy[r]), retr);
      }
    }
    return calc(retl, retr);
  }

  void update(size_type l, size_type r, const operator_type& data){
    assert(l <= r);
    assert(0 <= l && l < size_);
    assert(0 <= r && r <= size_);
    l += size_;
    r += size_;
    propagate(l);
    propagate(r - 1);
    for(size_type l_ = l, r_ = r; l_ < r_ ; l_ >>= 1, r_ >>= 1){
      if(l_ & 1) apply(lazy[l_++], data);
      if(r_ & 1) apply(lazy[--r_], data);
    }
    build(l);
    build(r - 1);
  }

  template<class F>
  void update(size_type index, const F& f){
    assert(0 <= index && index < size());
    index += size_;
    propagate(index);
    tree[index] = f(::std::move(tree[index]));
    lazy[index] = operator_structure::identity();
    build(index);
  }

  void dump() {
    REP(i, tree.size()) {
      cout << "(" << tree[i] << " " << lazy[i] << ") ";
    }
    cout << endl;
  }

  
};

class v_monoid {
public:
  using value_type = int64;
  static value_type identity() { return INF_LL; }
  static value_type initializer() { return INF_LL; }
  static value_type operation(const value_type& a, const value_type& b) {
    return min(a, b);
  }
};

class o_monoid {
public:
  using value_type = int64;
  static value_type identity() { return INF_LL; }
  static value_type operation(const value_type& a, const value_type& b) {
    return min(a, b);
  }
};

class modifier {
public:
  static int64 operation(const int64& a, const int64& b) {
    return min(a, b);
  }
};


template<class ValueMonoid, template<class...> class Container=::std::vector>
class SegTree{
public:
  using value_structure = ValueMonoid;
  using value_type = typename value_structure::value_type;
  using const_reference = const value_type &;
  using container_type = Container<value_type>;
  using size_type = typename container_type::size_type;

private:
  ::std::vector<value_type> tree;
  size_type size_;

  static size_type getsize(const size_type x){
    size_type ret = 1;
    while(ret < x)
      ret <<= 1;
    return ret;
  }

  inline value_type calc(const value_type a, const value_type b){
    return value_structure::operation(a, b);
  }

  inline void calc_node(const size_type index){
    if(tree.size() <= (index << 1 | 1)) return;
    tree[index] = value_structure::operation(tree[index<<1], tree[index<<1 | 1]);
  }
public:
  SegTree() : size_(0), tree(){}
  SegTree(const size_type size)
    : size_(size), tree(size << 1, value_structure::identity()){}
  template<class InputIterator>
  SegTree(InputIterator first, InputIterator last)
    : size_(::std::distance(first, last)){
    tree = container_type(size_, value_structure::identity());
    tree.insert(tree.end(), first, last);
    for(size_type i = size_;i > 0;i--){
      calc_node(i);
    }
  }

  size_type size() const { return size_; }
  const_reference operator[](const size_type k) const {
    assert(k < size_);
    return tree[k+size_];
  }

  value_type query(size_type l, size_type r){
    assert(l <= r);
    assert(0 <= l && l < size_);
    assert(0 <= r && r <= size_);
    value_type retl = value_structure::identity(), retr = value_structure::identity();
    for(l += size_, r += size_; l < r ; l >>= 1, r >>= 1){
      if(l&1) retl = calc(retl, tree[l++]);
      if(r&1) retr = calc(tree[--r], retr);
    }
    return calc(retl, retr);
  }

  template<class F>
  void update(size_type index, const F& f){
    assert(0 <= index && index < size());
    index += size_;
    tree[index] = f(::std::move(tree[index]));
    while(index >>= 1)
      calc_node(index);
  }

  
};

class c_monoid {
public:
  using value_type = tuple<int64, int64, int64>;
  static value_type identity() { return value_type(INF_LL, 0, 0); }
  static value_type initializer() { return value_type(INF_LL, 0, 0); }
  static value_type operation(const value_type& a, const value_type& b) {
    return min(a, b);
  }
};

constexpr int64 mod = 1e9+7;
using Mint = ModInt<mod>;



using T = tuple<int64, int64, int64>;

int64 n, m;

int main(void) {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cin >> n >> m;
  vector<T> f(n), mos(m);
  map<int64, int64> mp;
  vector<int64> xs;
  REP(i, n) {
    int64 x, t;
    cin >> x >> t;
    f[i] = T(x, t, i);
    xs.push_back(x);
  }
  REP(i, m) {
    int64 p, b;
    cin >> p >> b;
    mos[i] = T(p, b, i);
    xs.push_back(p);
  }
  sort(all(xs)); xs.erase(unique(all(xs)), xs.end());
  REP(i, m) {
    get < 0 > (mos[i]) = lower_bound(all(xs), get < 0 > (mos[i])) - xs.begin();
  }
  sort(all(f));
  id0<v_monoid, o_monoid, modifier> lsg(xs.size()+1);

  vector<int64> t(n),res(n, 0), fx(n);
  for (int64 i = n-1; i >= 0; i--) {
    int64 x, t_, id;
    tie(x, t_, id) = f[i];
    t[id] = t_;
    int64 r = upper_bound(all(xs), x+t_) - xs.begin();
    fx[id] = x;
    mp[x] = id;
    x = lower_bound(all(xs), x) - xs.begin();
    lsg.update(x, r, fx[id]);
  }

  SegTree<c_monoid> sg(xs.size()+1);
  REP(i, m) {
    int64 p, b, id;
    tie(p, b, id) = mos[i];
    int64 f_x = lsg.query(p, p+1);
    if (f_x == INF_LL) {
      sg.update(p, [&](const T& x) { return T(p, get<1>(x) + 1, get<2>(x) + b); });
      T tap = sg.query(p, p+1);
    } else {
      int64 id_f = mp[f_x];
      int64 l = upper_bound(all(xs), f_x+t[id_f]) - xs.begin();
      int64 r = upper_bound(all(xs), f_x+t[id_f]+b) - xs.begin();
      t[id_f] += b;
      res[id_f] += 1;
      lsg.update(l, r, f_x);
      int64 rx, rcnt, rsz;
      tie(rx, rcnt, rsz) = sg.query(l, r);
      while (rx != INF_LL) {
        sg.update(rx, [](const T& luz) { return T(INF_LL, 0, 0); });
        res[id_f] += rcnt;
        t[id_f] += rsz;
        r = upper_bound(all(xs), f_x+t[id_f]) - xs.begin();
        lsg.update(l, r, f_x);
        tie(rx, rcnt, rsz) = sg.query(l, r);
      }
    }
  }
  REP(i, n) {
    cout << res[i] << " " << t[i] << endl;
  }
}

