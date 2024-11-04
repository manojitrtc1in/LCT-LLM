










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
  tpl(){}
  tpl(std::tuple<As...> const& b) { std::tuple<As...>::operator=(b); }

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

using lli   = long long int;
using llu   = long long unsigned;

using pii   = tpl<int, int>;
using piii  = tpl<int, int, int>;
using piiii = tpl<int, int, int, int>;
using vi    = vector<int>;
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
    inline void id1(size_t& seed, T const& v) {
      seed ^= hash<T>()(v) + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }
    template <class Tuple, size_t Index = tuple_size<Tuple>::value - 1>
    struct HashValueImpl {
      static void apply(size_t& seed, Tuple const& tuple) {
        HashValueImpl<Tuple, Index-1>::apply(seed, tuple);
        id1(seed, get<Index>(tuple));
      }
    };
    template <class Tuple>
    struct HashValueImpl<Tuple, 0> {
      static void apply(size_t& seed, Tuple const& tuple) {
        id1(seed, get<0>(tuple));
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










































































































































































































































struct id0 {
  int lo=0, hi=0;
  id0 *l = 0, *r = 0;
  vector<int> b;

  vector<int> ac;
  BIT         ab;


  id0() = default;

  ~id0(){
    if(l) delete l;
    if(r) delete r;
  }

  id0(vector<int> A) : id0(begin(A),end(A),*min_element(all(A)),*max_element(all(A))) { }
  id0(vector<lli> A) : id0(begin(A),end(A),*min_element(all(A)),*max_element(all(A))) { }

  template<typename IT>
  id0(IT from, IT to, int lo_, int hi_) {
    lo=lo_; hi=hi_;
    int mi = lo + (hi-lo)/2;
    auto f = [&](int x) { return x <= mi; };
    b.reserve(distance(from,to)+1); b.pb(0);
    for(auto it = from; it != to; ++it) b.pb(b.back() + f(*it));

    ac.assign(distance(from,to)+1,1);
    ab = BIT(distance(from,to)+2); FOR(i,distance(from,to)) ab.add(1+i,f(*(from+i)));

    auto mit = stable_partition(from,to,f);
    if(lo == hi || from == to) return;
    l = new id0(from,mit,lo,mi);
    r = new id0(mit,to,mi+1,hi);
  }

  
  void swap(int i, int si, int sj) {
    if(si==sj) return;
    if(lo == hi) {
      return;
      assert(0);
    }else{
      int mi = lo + (hi-lo)/2;
      if(si<=mi&&sj<=mi){

        if(ac[i]&&!ac[i+1]) { ab.add(1+i,-1); ab.add(1+(i+1),1); }
        else if(!ac[i]&&ac[i+1]) { ab.add(1+i,1); ab.add(1+(i+1),-1); }
        ::swap(ac[i],ac[i+1]);

        l->swap(b[i],si,sj);
      }else if(si>mi&&sj>mi){

        ::swap(ac[i],ac[i+1]);

        r->swap(i-b[i],si,sj);
      }else if(si<=mi){

        if(ac[i]) { ab.add(1+i,-1); ab.add(1+(i+1),1); }
        ::swap(ac[i],ac[i+1]);

        b[i+1] -= 1;
      }else{

        if(ac[i+1]){ ab.add(1+(i+1),-1); ab.add(1+i, 1); }
        ::swap(ac[i],ac[i+1]);

        b[i+1] += 1;
      }
    }
  }

  

  void toogle(int i, int si) {
    ac[i] ^= 1;
    if(ac[i]) ab.add(1+i,1);
    else ab.add(1+i,-1);
    if(lo==hi) {
    }else{
      int mi = lo + (hi-lo)/2;
      if(si<=mi){
        l->toogle(b[i],si);
      }else{
        r->toogle(i-b[i],si);
      }
    }
  }


  
  int kth(int l, int r, int k) {
    assert(l <= r);
    assert(k < r-l+1);
    if(lo == hi) return lo;

    int inleft = ab.getR(l+1,r+1);

    int inleft = b[r+1]-b[l];

    if(k < inleft) return this->l->kth(b[l],b[r+1]-1,k);
    else return this->r->kth(l-b[l],r-b[r+1],k-inleft);
  }

  
  int cnt(int l, int r, int y) {
    if(l>r) return 0;
    if(lo == hi) {
      if(lo == y) {

        return ab.getR(1+l,1+r);

        return b[r+1]-b[l];

      }else{
        return 0;
      }
    }else{
      int mi = lo + (hi-lo)/2;
      if(y<=mi) {
        return this->l->cnt(b[l],b[r+1]-1,y);
      }else{
        return this->r->cnt(l-b[l],r-b[r+1],y);
      }
    }
  }

  int allR(int l, int r) {
    if(l>r) return 0;
    return r-l+1;
  }

  int cntR(int l, int r, int y) {
    if(l>r) return 0;
    if(hi<=y) return r-l+1;
    if(y<lo) return 0;
    int mi = lo + (hi-lo)/2;
    if(y<=mi) {
      return this->l->cntR(b[l],b[r+1]-1,y);
    }else{
      return this->l->allR(b[l],b[r+1]-1)+this->r->cntR(l-b[l],r-b[r+1],y);
    }
  }

};




int main(){
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q; cin>>n>>q;
  map<int,map<int,int>> data;
  vi ps;
  FOR(i,n) {
    int p; cin>>p;
    

    ps.pb(p-1);
  }
  id0 wt(ps);
  auto q0 = [&](int x, int y) -> int {
    if(x<0||y<0) return 0;
    return wt.cntR(0,x,y);
  };
  auto query = [&](int x1,int y1,int x2,int y2) -> int {
    if(x2<x1) return 0;
    if(y2<y1) return 0;
    return wt.cntR(x1,x2,y2) - (y1==0?0:wt.cntR(x1,x2,y1-1));
  };
  

  set<tpl<int,int,int,int>> ss;
  FOR(i,3) FOR(j,3) FOR(i2,3) FOR(j2,3) if(mt(i,j)!=mt(i2,j2)){
    if((i<=1&&1<=i2)||(i2<=1&&1<=i)) {
      if((j<=1&&1<=j2)) {
        if(!ss.count(mt(i2,j2,i,j)))
          ss.insert(mt(i,j,i2,j2));
      }
    }
  }
  FOR(q_,q) {
    int x1,y1,x2,y2; cin>>x1>>y1>>x2>>y2;
    --x1; --y1; --x2; --y2;
    int T[3][3] = {{0,0,0},{0,0,0},{0,0,0}};
    FOR(i,3) { FOR(j,3) {
        int a,b,c,d;
        if(i==0) { a=0; b=x1-1; }
        if(i==1) { a=x1; b=x2; }
        if(i==2) { a=x2+1; b=n-1; }
        if(j==0) { c=0; d=y1-1; }
        if(j==1) { c=y1; d=y2; }
        if(j==2) { c=y2+1; d=n-1; }
        T[i][j] = query(a,c,b,d);
      }
    }
    lli inside = T[1][1];
    lli ans = (inside*(inside-1))/2;
    for(auto s:ss) {
      int i,j,i2,j2;
      tie(i,j,i2,j2)=s;
      ans += (lli)((lli)T[i][j]*(lli)T[i2][j2]);
    }

    cout << ans << '\n';
  }
  cout << flush;
  return 0;
}
