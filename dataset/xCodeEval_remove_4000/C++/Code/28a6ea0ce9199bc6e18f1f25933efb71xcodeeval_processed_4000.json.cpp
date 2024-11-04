










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



using llu   = long long unsigned;



using piii  = tpl<int, int, int>;
using piiii = tpl<int, int, int, int>;
using vi    = vector<int>;
using vii   = vector<tpl<int, int>>;
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

int read_positive(){
  char c; int x=0;
  do { c = getchar(); } while(c<'0' || c>'9');
  while(c>='0'&&c<='9') {
    x=10*x+(c-'0');
    c = getchar();
  }
  return x;
}

struct MaxFlow {
  struct edge {
    int from, to, cap, flow, index;
    edge(int from, int to, int cap, int flow, int index) :
      from(from), to(to), cap(cap), flow(flow), index(index) {}
  };

  int N;
  

  vector<vector<edge> > Graph;
  vector<int> excess;
  vector<int> dist, active, count;
  queue <int> Queue;

  MaxFlow(int N = 0) : N(N), Graph(N), excess(N), dist(N), active(N), count(2*N) { }

  int addNode() {
    N += 1;
    

    Graph.emplace_back(); excess.emplace_back(); dist.emplace_back(); active.emplace_back(); count.emplace_back(); count.emplace_back();
    

    return N-1;
  }

  

  tpl<int, int> addedge(int from, int to, int cap) {
    

    

    Graph[from].push_back( edge( from, to, cap, 0, Graph[to].size() ) );
    if (from == to) 
      Graph[from].back().index++;
    

    

    Graph[to].push_back( edge( to, from, 0, 0, Graph[from].size() - 1) );
    

    return make_tuple( from, Graph[from].size() - 1 );
  }

  void enqueue(int v) {
    if (!active[v] && excess[v] > 0) { 
      active[v] = true; 
      Queue.push(v); }
  }

  void push(edge &e) {
    int amt = min(excess[e.from], e.cap - e.flow);
    if(dist[e.from] <= dist[e.to] || amt == 0) return;
    e.flow += amt;
    Graph[e.to][e.index].flow -= amt;
    excess[e.to] += amt;
    excess[e.from] -= amt;
    enqueue(e.to);
  }

  void gap(int k) {
    FOR(v, N) {
      if(dist[v] < k) continue;
      count[dist[v]]--;
      dist[v] = max(dist[v], N+1);
      count[dist[v]]++;
      enqueue(v);
    }
  }

  void relabel(int v) {
    count[dist[v]]--;
    dist[v] = 2*N;
    for(edge& e : Graph[v]) if(e.cap - e.flow > 0) {
        dist[v] = min(dist[v], dist[e.to] + 1);
      }
    count[dist[v]]++;
    enqueue(v);
  }

  void discharge(int v) {
    for(int i = 0; excess[v] > 0 && i < (int)Graph[v].size(); ++i) push(Graph[v][i]);
    if(excess[v] > 0) {
      if(count[dist[v]] == 1) {
        gap(dist[v]);
      } else {
        relabel(v);
      }
    }
  }

  int flow(int s, int t) {
    count[0] = N-1;
    count[N] = 1;
    dist[s] = N;
    active[s] = active[t] = true;
    for(edge& e : Graph[s]) {
      excess[s] += e.cap;
      push(e);
    }
    while (!Queue.empty()) {
      int v = Queue.front();
      Queue.pop();
      active[v] = false;
      discharge(v);
    }
    int totflow = 0;
    for(edge& e : Graph[s]) totflow += e.flow;
    return totflow;
  }

  vector<tpl<int, int>> get_minimum_cut(int S){
    int n=Graph.size();
    vector<int> E(n);
    function<void(int)> dfs = [&](int i){
      if(E[i]) return;
      E[i]=1;
      for(edge const& e : Graph[i]) if(e.flow<e.cap) dfs(e.to);
    };
    dfs(S);
    vector<tpl<int, int>> R;
    FOR(i,n) 
      if(E[i]) 
        FOR(j,Graph[i].size()) 
          if(!E[Graph[i][j].to]) 
            R.push_back(make_tuple(i,j));
    return R;
  }


};





const int K=15;
int A[(1<<K)][K];
int depth[1<<K]; 

int parent[1<<K][K]; 


int main(){
  ios::sync_with_stdio(0); cin.tie(0);

  int n,m; cin>>n>>m;
  

  vector < vector < int > >  Graph(n);
  

  map<tpl<int, int>,int> ixs;
  

  

  

  FOR(i,n-1) {
    int u,v; cin>>u>>v; --u; --v; Graph[u].push_back(v); Graph[v].push_back(u);
    ixs[make_tuple(u,v)] = i;
    ixs[make_tuple(v,u)] = i;
  }
  function<void(int,int,int)> dfs = [&](int i, int p_parent, int p_depth){
    depth[i]=p_depth;
    parent[i][0]=p_parent;
    for(int j : Graph[i]) if(j!=p_parent) dfs(j,i,p_depth+1);
  };
  

  

  

  dfs(0,-1,0);
  

  

  FOR(i,K-1) 
    FOR(j,n) 
      if(depth[j] >= (1<<(i+1))) 
        parent[j][i+1] = parent[ parent[j][i] ] [i];

  MaxFlow flow; 
  

  

  int S = flow.addNode(), T = flow.addNode();
  

  

  FOR(i,n) 
    FOR(j,K) 
      A[i][j] = flow.addNode();
  
  

  map<tpl<int, int>, int> ANS0;
  map<tpl<int, int>, int> ANS1;
  

  

  

  

  

  

 

  

  

  

  for( int i = 1; i < n; i++){  
      auto e = flow.addedge( A[i][0], T ,1 ); 
      ANS0[e] = ixs[ make_tuple( i, parent[i][0] ) ]; 
  }
  

  

  

  FOR( i, K-1 ) 
    FOR( j, n )
      if( depth[j] >= ( 1 << (i + 1) ) ){
        flow.addedge( A[j][i+1], A[j][i], (1 << 26));
        flow.addedge( A[j][i+1], A[ parent[j][i] ][i], (1 << 26) );
      }

  FOR(i,m) {
    

    int x = 0, y = 0; cin>>x>>y; --x; --y;
    

    int no = flow.addNode();
    

    auto e = flow.addedge(S,no,1);
    

    ANS1[e]=i;
    
    

    if( depth[x] < depth[y] ) 
      swap( x, y );

    

    

    

    

    for(int i = K-1; i >= 0; --i) 
      

      if( depth[x] >= depth[y] + ( 1<<i ) ) {
        flow.addedge( no, A[x][i], ( 1<<26 ) );
        x = parent[x][i];
    }
    
    

    if( x == y ) 
      continue;
    
    

    for(int i = K-1; i >= 0; --i)
      if( depth[x] >= ( 1<<i ) && parent[x][i] != parent[y][i] ){
        flow.addedge(no,A[x][i],(1<<26));
        flow.addedge(no,A[y][i],(1<<26));
        x = parent[x][i];
        y = parent[y][i];
      }
    
    

    

    flow.addedge( no, A[x][0], ( 1<<26 ) );
    flow.addedge( no, A[y][0], ( 1<<26 ) );
  }

  

  int f = flow.flow( S, T );
  cout << f << endl;
  

  auto ct = flow.get_minimum_cut(S);
  vector<int> a0,a1;
  
  for(auto e : ct) {
    

    

    if(ANS0.count(e)) a0.push_back(ANS0[e]);
    

    

    if(ANS1.count(e)) a1.push_back(ANS1[e]);
  }

  sort(all(a0));
  sort(all(a1));
  
  cout << a1.size(); for(int i : a1) cout << ' ' << i+1; cout << endl;
  cout << a0.size(); for(int i : a0) cout << ' ' << i+1; cout << endl;

  return 0;
}