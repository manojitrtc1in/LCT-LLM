










  auto a = get<0>(p);                           \
  auto b = get<1>(p);


  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);


  auto a = get<0>(p);                           \
  auto b = get<1>(p);                           \
  auto c = get<2>(p);                           \
  auto d = get<3>(p);














using namespace std;

template<typename... As>
struct tpl : public std::tuple<As...> {
  using std::tuple<As...>::tuple;

  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type const&
  x() const { return get<0>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<0, T>::type&
  x() { return get<0>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type const&
  y() const { return get<1>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<1, T>::type&
  y() { return get<1>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type const&
  z() const { return get<2>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<2, T>::type&
  z() { return get<2>(*this); }

  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type const&
  w() const { return get<3>(*this); }
  template<typename T = tuple<As...> >
  typename tuple_element<3, T>::type&
  w() { return get<3>(*this); }
};

using lli   = int;
using llu   = long long unsigned;

using pii   = tpl<lli, lli>;
using piii  = tpl<lli, lli, lli>;
using piiii = tpl<lli, lli, lli, lli>;
using vi    = vector<lli>;
using vii   = vector<pii>;
using viii  = vector<piii>;
using vvi   = vector<vi>;
using vvii  = vector<vii>;
using vviii = vector<viii>;

template<class T>
using min_queue = priority_queue<T, vector<T>, greater<T> >;
template<class T>
using max_queue = priority_queue<T>;

template<size_t... I>
struct my_index_sequence {
  using type = my_index_sequence;
  static constexpr array<size_t, sizeof...(I)> value = { {I...} };
};

namespace my_index_sequence_detail {
  template<typename I, typename J> struct concat;
  template<size_t... I, size_t... J>
  struct concat<my_index_sequence<I...>, my_index_sequence<J...> > :
    my_index_sequence<I..., (sizeof...(I)+J)...> { };
  template<size_t N> struct make_index_sequence :
    concat<typename make_index_sequence<N/2>::type, typename make_index_sequence<N-N/2>::type>::type { };
  template <> struct make_index_sequence<0> : my_index_sequence<>{};
  template <> struct make_index_sequence<1> : my_index_sequence<0>{};
}

template<class... A>
using my_index_sequence_for = typename my_index_sequence_detail::make_index_sequence<sizeof...(A)>::type;

template<class T, size_t... I>
void print_tuple(ostream& s, T const& a, my_index_sequence<I...>){
  using swallow = int[];
  (void)swallow{0, (void(s << (I == 0? "" : ", ") << get<I>(a)), 0)...};
}

template<class T>
ostream& print_collection(ostream& s, T const& a);
template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a);
template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a);
template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a);

template<class T, size_t I>
ostream& operator<<(ostream& s, array<T, I> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, vector<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, multimap<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, multiset<T> const& a) { return print_collection(s, a); }
template<class T, class U>
ostream& operator<<(ostream& s, map<T, U> const& a) { return print_collection(s, a); }
template<class T>
ostream& operator<<(ostream& s, set<T> const& a) { return print_collection(s, a); }

template<class T>
ostream& print_collection(ostream& s, T const& a){
  s << '[';
  for(auto it = begin(a); it != end(a); ++it){
    s << *it;
    if(it != prev(end(a))) s << " ";
  }
  return s << ']';
}

template<class... A>
ostream& operator<<(ostream& s, tpl<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class... A>
ostream& operator<<(ostream& s, tuple<A...> const& a){
  s << '(';
  print_tuple(s, a, my_index_sequence_for<A...>{});
  return s << ')';
}

template<class A, class B>
ostream& operator<<(ostream& s, pair<A, B> const& a){
  return s << "(" << get<0>(a) << ", " << get<1>(a) << ")";
}

namespace std {
  namespace {
    template <class T>
    inline void id0(size_t& seed, T const& v) {
      seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
    struct HashValueImpl {
      static void apply(size_t& seed, Tuple const& tuple) {
        HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
        id0(seed, get<Index>(tuple));
      }
    };
    template <class Tuple>
    struct HashValueImpl<Tuple, 0> {
      static void apply(size_t& seed, Tuple const& tuple) {
        id0(seed, get<0>(tuple));
      }
    };
  }
  template <typename ... TT>
  struct hash<tuple<TT...>> {
    size_t operator()(tuple<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
  template <typename ... TT>
  struct hash<tpl<TT...>> {
    size_t operator()(tpl<TT...> const& tt) const {
      size_t seed = 0;
      HashValueImpl<tuple<TT...> >::apply(seed, tt);
      return seed;
    }
  };
}

lli read_positive(){
  char c; lli x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}







struct treap;
using treap_ptr = treap*;

struct treap {
  treap(pii x_) : l(0), r(0), heap(rand()+RAND_MAX*rand()), x(x_), value(numeric_limits<int>::max()), size(1){ }
  treap_ptr l, r;
  lli heap;

  pii x;
  lli value;
  lli nvalue=numeric_limits<int>::max();

  lli size;

  static inline lli get_size(treap_ptr a){ return a?a->size:0; }

  static inline void update(treap_ptr a){
    if(a){
      a->size = 1;
      if(a->l) a->size += a->l->size;
      if(a->r) a->size += a->r->size;
    }
  }

  static inline void push(treap_ptr a){
    if(a && a->nvalue!=numeric_limits<int>::max()) {
      setMin(a->l,a->nvalue);
      setMin(a->r,a->nvalue);
      a->nvalue=numeric_limits<int>::max();
    }
  }

  static inline void setMin(treap_ptr a, lli v) {
    if(a) {
      a->value = min(a->value,v);
      a->nvalue = min(a->nvalue,v);
    }
  }

  static treap_ptr merge(treap_ptr a, treap_ptr b){
    if(a == 0) return b;
    if(b == 0) return a;
    push(a); push(b);
    if(a->heap < b->heap){
      a->r = merge(a->r, b);
      update(a);
      return a;
    }else{
      b->l = merge(a, b->l);
      update(b);
      return b;
    }
  }

  static tpl<treap_ptr, treap_ptr> split_key(treap_ptr a, pii x){
    if(a == 0) return mt(nullptr, nullptr);
    push(a);
    if(x <= a->x){
      auto p = split_key(a->l, x);
      a->l = p.y();
      update(a);
      return mt(p.x(), a);
    }else{
      auto p = split_key(a->r, x);
      a->r = p.x();
      update(a);
      return mt(a, p.y());
    }
  }

  static tpl<treap_ptr, treap_ptr> split_pos(treap_ptr a, lli i){
    if(a == 0) return mt(nullptr, nullptr);
    push(a);
    if(i <= get_size(a->l)){
      auto p = split_pos(a->l, i);
      a->l = p.y();
      update(a);
      return mt(p.x(), a);
    }else{
      auto p = split_pos(a->r, i - get_size(a->l) - 1);
      a->r = p.x();
      update(a);
      return mt(a, p.y());
    }
  }

  static treap_ptr insert_key(treap_ptr a, pii x){
    auto p = split_key(a, x);
    return merge(merge(p.x(), new treap(x)), p.y());
  }

  static treap_ptr insert_pos(treap_ptr a, lli i, pii x){
    auto p = split_pos(a, i);
    return merge(merge(p.x(), new treap(x)), p.y());
  }
};







struct segment_tree {

  struct node {
    node(){}
    lli value=-1;

    void combine(node &a, node& b) {
      value=max(a.value,b.value);
    }
  };

  int n;
  vector<node> A;
  segment_tree(int n_) : n((int)1<<(int)(log2(n_)+1)), A(2*n) { }

  void update(int i) {
    if(i < n) {
      A[i].combine(A[2*i],A[2*i+1]);
    }
  }

  void set__(int i, int, int, lli v){
    A[i].value = max(A[i].value,v);
  }

  void set_(int i, int a, int b, int l, int r, lli v) {
    if(l > b) return;
    if(r < a) return;
    if(l <= a && b <= r){
      set__(i, a, b, v);
      return;
    }
    int c = (a+b)/2;
    set_(2*i  , a  , c, l, r, v);
    set_(2*i+1, c+1, b, l, r, v);
    update(i);
  }

  void set(int l, int r, lli v){
    set_(1, 0, n-1, l, r, v);
  }

  node get_(int i, int a, int b, int l, int r) {
    if(l > b) return node();
    if(r < a) return node();
    if(l <= a && b <= r){
      return A[i];
    }
    int c = (a+b)/2;
    node ar = get_(2*i  , a  , c, l, r);
    node br = get_(2*i+1, c+1, b, l, r);
    node res;
    res.combine(ar,br);
    return res;
  }

  lli get(int l, int r){
    node a = get_(1, 0, n-1, l, r);
    return a.value;
  }
};









struct BIT {
  vi A;
  BIT(lli n) : A(n+1,numeric_limits<int>::max()){ }

  lli get(lli i){
    i += 1;
    lli r = numeric_limits<int>::max();
    for(; i > 0; i -= i &-i){
      r = min(r,A[i]);
    }
    return r;
  }

  void add(lli i, lli v){
    i += 1;
    for(; i < (lli)A.size(); i += i & -i){
      A[i] = min(A[i],v);
    }
  }
};





const int N=1e5;
int A[N];
int ANS[3*N];

int main(){
  ios::sync_with_stdio(0); cin.tie(0);


  lli n;
  cin >> n;
  

  FOR(i,n) cin >> A[i];
  

  lli m;
  cin>>m;
  

  vii Q(m); FOR(i, m) { lli l=0, r=0;
    

    

    

    

    cin >> l >> r;
    Q[i] = mt(l-1, r-1);
  };

  lli n;
  n=N;
  FOR(i,n) A[i]=rand()%((lli)1e7);
  lli m;
  m=3e5;
  vii Q(m); FOR(i, m) { lli l=0, r=0;
    while(l>=r){
      l=1+rand()%n;
      r=1+rand()%n;
    }
    Q[i] = mt(l-1, r-1);
  };


  vector<vector<pii >> RL(n);
  FOR(i,m) RL[Q[i].y()].pb(mt(Q[i].x(),i));

  set<lli> ALLX; ALLX.insert(-(numeric_limits<int>::max())); ALLX.insert(numeric_limits<int>::max());
  FOR(i,n) ALLX.insert(A[i]);
  vi FROMX; map<lli,lli> TOX;
  for(lli i : ALLX) { TOX[i] = FROMX.size(); FROMX.pb(i); }

  segment_tree st(TOX.size());
   BIT bit(n+10);
  FOR(i,n) {
    int bdt=numeric_limits<int>::max();
    lli x = A[i]; lli x0 = TOX[x];
    lli l = 0, r = TOX.size()-1;
    while(1) {
      lli j = st.get(l,r);
      if(j==-1) break;
      lli y = A[j];

      lli dt=abs(x-y);
      if(dt<bdt) { bdt=dt; bit.add(n-j,dt); }
      

      

      

      

      


      if(y == x) break;
      if(y > x) {
        lli z = (x+y-1)/2;
        r = prev(TOX.upper_bound(z))->second;
      }else{
        lli z = (x+y+2)/2;
        l = TOX.lower_bound(z)->second;
      }
    }
    st.set(x0,x0,i);

    for(auto l : RL[i]) {
      ANS[l.y()] = bit.get(n-l.x());
    }
    

    

    

    

    

    

    

    

  }

  FOR(i,m) {
    cout << ANS[i] << endl;
  }

  return 0;
}
