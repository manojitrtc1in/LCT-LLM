










namespace lib {
  using namespace std;
namespace traits {

  

  template<typename Iterator>
  using IteratorCategory =
    typename iterator_traits<Iterator>::iterator_category;

  

  template<typename Container>
  using IteratorCategoryOf = IteratorCategory<typename Container::iterator>;

  

  template<typename Iterator>
  using IsRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Iterator>
  using IsInputIterator =
    is_base_of<input_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Iterator>
  using IsBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategory<Iterator>>;

  

  template<typename Container>
  using HasRandomIterator =
    is_base_of<random_access_iterator_tag, IteratorCategoryOf<Container>>;

  

  template<typename Container>
  using HasInputIterator =
    is_base_of<input_iterator_tag, IteratorCategoryOf<Container>>;

  

  template<typename Container>
  using HasBidirectionalIterator =
    is_base_of<bidirectional_iterator_tag, IteratorCategoryOf<Container>>;
}
}



namespace lib {
  using namespace std;
namespace graph {
  template<typename T>
  struct Edge {
    const int from, to;
    T data;
  };

  template<>
  struct Edge<void> { const int from, to; };

  template<typename T>
  struct VertexWrapper { T data; };

  template<>
  struct VertexWrapper<void> {};

  template<typename V = void, 
           typename E = void>
  struct Graph {
    typedef Graph<V, E> self_type;
    typedef vector<vector<int>> adj_list;
    typedef Edge<E> edge_type;
    typedef VertexWrapper<V> vertex_type;

    vector<edge_type> edges;
    adj_list adj;

    vector<vertex_type> vertices;

    class iterator
    {
      public:
            typedef iterator self_type;
            typedef edge_type value_type;
            typedef edge_type& reference;
            typedef edge_type* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            iterator(vector<int>* adj, vector<edge_type>* edges, int ptr = 0)
              : adj_(adj), edges_(edges), ptr_(ptr) { }
            self_type operator++() { ptr_++; return *this; }
            self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
            reference operator*() { return (*edges_)[(*adj_)[ptr_]]; }
            pointer operator->() { return &(*edges_)[(*adj_)[ptr_]]; }
            bool operator==(const self_type& rhs) const { 
              return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type& rhs) const { return !(*this == rhs); }
        private:
            vector<int>* adj_;
            vector<edge_type>* edges_;
            int ptr_;
    };

    class const_iterator
    {
      public:
            typedef const_iterator self_type;
            typedef edge_type value_type;
            typedef edge_type& reference;
            typedef edge_type* pointer;
            typedef std::forward_iterator_tag iterator_category;
            typedef int difference_type;
            const_iterator(vector<int>* adj, vector<edge_type>* edges, int ptr = 0) 
              : adj_(adj), edges_(edges), ptr_(ptr) { }
            self_type operator++() { ptr_++; return *this; }
            self_type operator++(int junk) { self_type i = *this; ptr_++; return i; }
            const value_type& operator*() { return (*edges_)[(*adj_)[ptr_]]; }
            const value_type* operator->() { return &(*edges_)[(*adj_)[ptr_]]; }
            bool operator==(const self_type& rhs) const { 
              return adj_ == rhs.adj_ && ptr_ == rhs.ptr_;
            }
            bool operator!=(const self_type& rhs) const { return !(*this == rhs); }
        private:
            vector<int>* adj_;
            vector<edge_type>* edges_;
            int ptr_;
    };

    struct iterable {
      vector<int>* adj_;
      vector<edge_type>* edges_;

      iterable(vector<int>* adj, vector<edge_type>* edges)
        : adj_(adj), edges_(edges) {}

      inline iterator begin() { return iterator(adj_, edges_); }
      inline iterator end() { return iterator(adj_, edges_, adj_->size()); }

      inline const_iterator cbegin() const { return const_iterator(adj_, edges_); }
      inline const_iterator cend() const { return const_iterator(adj_, edges_, adj_->size()); }

      inline const_iterator begin() const { return cbegin(); }
      inline const_iterator end() const { return cend(); }

      inline edge_type& operator[](int i) { return (*edges_)[(*adj_)[i]]; }
      inline const edge_type& operator[](int i) const { return (*edges_)[(*adj_)[i]]; }

      inline int size() const { return adj_->size(); }
    };

    Graph() {}

    template<typename S = V, typename enable_if<is_void<S>::value>::type* = nullptr>
    Graph(size_t n) : adj(n) {}

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    Graph(size_t n) : adj(n), vertices(n) {}

    inline iterable n_edges(int i) { return iterable(&adj[i], &edges); }
    inline const iterable n_edges(int i) const { 
      return iterable(const_cast<vector<int>*>(&adj[i]), 
                      const_cast<vector<edge_type>*>(&edges)); 
    }

    inline int size() const { return adj.size(); }
    inline int edge_size() const { return edges.size(); }
    inline edge_type& edge(int i) { return edges[i]; }
    inline edge_type edge(int i) const { return edges[i]; }

    inline vector<edge_type> all_edges() const { return edges; }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& vertex(int i) { return vertices[i]; }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline V vertex(int i) const { return vertices[i]; }

    template<typename S = V, typename enable_if<is_void<S>::value>::type* = nullptr>
    inline void add_vertex() { adj.emplace_back(); }

    template<typename S = V, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& add_vertex() {
      adj.emplace_back();
      return vertices.emplace_back().data;
    }

    template<typename S = E, typename enable_if<is_void<S>::value>::type* = nullptr>
    inline void add_edge(int u, int v) {
      adj[u].push_back(edges.size());
      edges.push_back({u, v});
    }
    
    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline S& add_edge(int u, int v) {
      adj[u].push_back(edges.size());
      edges.push_back({u, v});
      return edges.back().data;
    }

    void id13(int u, int v) {
      add_edge(u, v);
      add_edge(v, u);
    }

    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline void id13(int u, int v, const S& data) {
      add_edge(u, v) = data;
      add_edge(v, u) = data;
    }
  };

  template<typename V = void, typename E = void>
  struct RootedForest : public Graph<V, E> {
    typedef RootedForest<V, E> self_type;
    using typename Graph<V, E>::adj_list;
    using typename Graph<V, E>::edge_type;
    using Graph<V, E>::Graph;
    using Graph<V, E>::adj;
    using Graph<V, E>::edge;
    vector<int> p, pe;

    void build_parents() {
      if((int)p.size() == this->size()) return;

      int n = this->size();
      stack<int> st;
      vector<bool> vis(n);
      p.assign(n, -1), pe.assign(n, -1);
      for(int i = 0; i < n; i++) {
        if(!vis[i]) {
          st.push(i);
          vis[i] = true;
          while(!st.empty()) {
            int u = st.top();
            st.pop();

            for(int k : adj[u]) {
              int v = edge(k).to;
              vis[v] = true;
              st.push(v), pe[v] = k, p[v] = u;
            }
          }
        }
      }
    }

    inline int parent(int i) const {
      const_cast<self_type*>(this)->build_parents();
      return p[i]; 
    }

    inline bool is_root(int i) const { return parent(i) != -1; }

    inline edge_type& parent_edge(int i) { 
      build_parents();
      return edge(pe[i]); 
    }
    inline edge_type& parent_edge(int i) const { 
      const_cast<self_type*>(this)->build_parents();
      return edge(pe[i]); 
    }

    vector<int> roots() const {
      vector<int> res;
      const_cast<self_type*>(this)->build_parents();
      int n = this->size();

      for(int i = 0; i < n; i++)
        if(p[i] == -1) res.push_back(i);
      return res;
    }
  };

  template<typename V = void, typename E = void>
  struct id4 : public RootedForest<V, E> {
    using typename RootedForest<V, E>::adj_list;
    int root;

    id4(int n, int root) : RootedForest<V, E>(n) {
      assert(n > 0);
      assert(root < n);
      this->root = root;
    }

    id4(const adj_list& adj, int root) : RootedForest<V, E>(adj) {
      assert(adj.size() > 0);
      assert(root < adj.size());
      this->root = root;
    }
  };

  namespace builders {
    namespace {
      template<typename F, typename G>
      void id6(F& forest, const G& graph, int u, vector<bool>& vis) {
        vis[u] = true;
        for(const auto& ed : graph.n_edges(u)) {
          int v = ed.to;
          if(!vis[v]) {
            forest.add_edge(u, v);
            id6(forest, graph, v, vis);
          }
        }
      }

      template<typename A, typename B>
      RootedForest<A, B> id8(const Graph<A, B>& graph,
                                            const vector<int>& roots) {
        RootedForest<A, B> res(graph.size());
        vector<bool> vis(graph.size());
        for(int i : roots)
          if(!vis[i])
            id6(res, graph, i, vis);
        for(int i = 0; i < graph.size(); i++)
          if(!vis[i])
            id6(res, graph, i, vis);
        return res;
      }
    }
  }  

}  

}  







namespace lib {
  using namespace std;
namespace seg {
  struct LeafBuilder {
    template<typename Node>
    void operator()(Node& no, int i) const {}
    inline pair<int, int> range() const { return {0, 0}; }
  };

  struct id14 : LeafBuilder {
    int n;
    explicit id14(int n) : n(n) {}
    inline pair<int, int> range() const { return {0, n-1}; }
  };

  template<typename RandomIterator>
  struct id2 : LeafBuilder {
    RandomIterator begin, end;
    explicit id2(RandomIterator begin, RandomIterator end)
      : begin(begin), end(end) {}

    template<typename Node>
    inline void operator()(Node& no, int i) const { no = *(begin + i); }

    inline pair<int, int> range() const { return {0, end-begin-1}; }
  };

  id14 make_builder(int n) { return id14(n); }

  template<typename RandomIterator>
  id2<RandomIterator> make_builder(RandomIterator begin, 
                                                RandomIterator end) {
    return id2<RandomIterator>(begin, end);
  }

  template<typename T>
  id2<typename vector<T>::const_iterator>
  make_builder(const vector<T>& v) {
    return id2<typename vector<T>::const_iterator>(v.begin(), 
                                                                v.end());
  }

  template<typename T>
  struct CombineFolder {
    inline T operator()() const { return T(); }

    template<typename Node>
    inline T operator()(const Node& no) const { return T(no); }

    inline T operator()(const T& a, const T& b) const { return a + b; }
  };

  template<typename T>
  struct EmptyFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();

    template<typename Node>
    inline T operator()(const Node& no) const { return T(); }
    inline T operator()(const T& a, const T& b) const { return T(); }
  };

  template<typename T>
  struct SumFolder : CombineFolder<T> {};
  
  template<typename T>
  struct MaxFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::min(); }
    inline T operator()(const T& a, const T& b) const { return max(a, b); }
  };

  template<typename T>
  struct MinFolder : CombineFolder<T> {
    using CombineFolder<T>::operator();
    inline T operator()() const { return numeric_limits<T>::max(); }
    inline T operator()(const T& a, const T& b) const { return min(a, b); }
  };

  template<typename T>
  struct id11 {
    T value;
    explicit id11(T val) : value(val) {}
  };

  template<typename T>
  struct SetUpdater : id11<T> {
    using id11<T>::id11;

    template<typename Node>
    inline void operator()(Node& no) const { no = this->value; }
  };

  template<typename T>
  struct AddUpdater: id11<T> {
    using id11<T>::id11;

    template<typename Node>
    inline void operator()(Node& no) const { no += this->value; }
  };

  struct EmptyPushdown {
    template<typename Node>
    inline void operator()(Node& no, int l, int r, 
                    Node* ln, Node* rn) const {}
  };
}  

}  




namespace lib {
  using namespace std;
namespace graph {
  namespace {
    void id5(int a, int b, bool inv) {}
  }

  template<typename G>
  struct HLD {
    G graph;
    vector<int> in, out, rin;
    vector<int> L, sz, ch;
    int tempo;

    HLD(const G& g) 
      : graph(g), in(g.size()), out(g.size()), rin(g.size()), L(g.size()),
        sz(g.size()), ch(g.size()) {
        build();
    }

    inline int size() const { return graph.size(); }

    void dfs0(int u) {
      sz[u] = 1;
      for(auto& k : graph.adj[u]) {
        int v = graph.edge(k).to;
        L[v] = L[u] + 1;
        dfs0(v);
        if(sz[v] > sz[graph.edge(graph.adj[u][0]).to])
          swap(k, graph.adj[u][0]);
        sz[u] += sz[v];
      }
    }

    void dfs1(int u) {
      in[u] = tempo++;
      rin[in[u]] = u;

      if(graph.adj[u].size() > 0) {
        int v = graph.edge(graph.adj[u][0]).to;
        ch[v] = ch[u];
        dfs1(v);
        for(size_t i = 1; i < graph.adj[u].size(); i++) {
          v = graph.edge(graph.adj[u][i]).to;
          ch[v] = v;
          dfs1(v);
        }
      }
      out[u] = tempo;
    }

    void build() {
      vector<int> roots = graph.roots();
      for(int i : roots) dfs0(i);
      tempo = 0;
      for(int i : roots) dfs1(i);
    }

    template<typename Lifter>
    inline void id1(int u, Lifter& lifter) {
      lifter(in[u], out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline T id16(int u, const QueryIssuer& issuer) {
      return issuer(in[u], out[u]-1);
    }

    template<typename Lifter>
    inline void id7(int u, Lifter& lifter) {
      if(in[u]+2 <= out[u]) lifter(in[u]+1, out[u]-1, false);
    }

    template<typename T, typename QueryIssuer>
    inline void id12(int u, const QueryIssuer& issuer) {
      assert(in[u]+2 <= out[u]);
      return issuer(in[u]+1, out[u]-1);
    }

    template<bool is_edge, typename Lifter>
    int _query_path(int u, int v, Lifter& lifter) {
      int inv = 0;
      for(; ch[u] != ch[v]; u = graph.parent(ch[u])) {
        if(L[ch[u]] < L[ch[v]])
          swap(u, v), inv ^= 1;
        lifter(in[ch[u]], in[u], (bool)inv);
      }
      if(L[u] > L[v]) swap(u, v), inv ^= 1;
      inv ^= 1;
      if(is_edge && in[u]+1 <= in[v])
        lifter(in[u]+1, in[v], (bool)inv);
      else if(!is_edge)
        lifter(in[u], in[v], (bool)inv);
      return u;
    }

    template<typename Lifter>
    inline int id3(int u, int v, Lifter& lifter) {
      return _query_path<false>(u, v, lifter);
    }

    template<typename Lifter>
    inline int id10(int u, int v, Lifter& lifter) {
      return _query_path<true>(u, v, lifter);
    }

    template<typename Op>
    inline void id0(int u, Op& op) {
      op(in[u]);
    }

    template<typename T, typename QueryIssuer>
    inline T id15(int u, const QueryIssuer& issuer) {
      return issuer(in[u]);
    }

    inline int lca(int u, int v) {
      return _query_path<false>(u, v, id5);
    }

    inline int dist(int u, int v) {
      int uv = lca(u, v);
      return L[u] + L[v] - 2*L[uv];
    }
  };

  template<typename G>
  HLD<G> id9(const G& graph) {
    return HLD<G>(graph);
  }
}  

}  



using namespace std;










int gcd(int a, int b) { return b == 0 ? a : gcd(b, a%b); }
int power(int x, int p, int MOD) {
    if(p == 0) return 1%MOD;
    if(p == 1) return x%MOD;
    int res = power(x, p/2, MOD);
    res = (long long)res*res%MOD;
    if(p&1) res = (long long)res*x%MOD;
    return res;
}

typedef pair<int, int> ii;
typedef long double LD;
typedef vector<int> vi;

using G = lib::graph::Graph<>;
const int N = 2e5+500;

int vis[N], low[N];
int tempo, nz;
int seen[10*N];
vi edges;
vi adj[N];
stack<int> st;
G g;

void tarjan(int u, int p){
  vis[u] = low[u] = ++tempo;
  for(int k : adj[u]){
    int v = edges[k];
    if(v == p) continue;

    if(!seen[k]){
      seen[k] = seen[k^1] = 1;
      st.push(k);
    }

    if(!vis[v]){
      tarjan(v, u);
      low[u] = min(low[u], low[v]);

      

      if(low[v] >= vis[u]){
        vector<int> e;
        int cur;
        do{
          cur = st.top(); st.pop();
          e.push_back(cur);
        } while(cur != k);

        vector<int> comp;
        for(int kk : e)
          comp.push_back(edges[kk]), comp.push_back(edges[kk^1]);

        sort(comp.begin(), comp.end());
        comp.erase(unique(comp.begin(), comp.end()), comp.end());

        g.add_vertex();
        for(int w : comp){
          g.id13(nz, w);
        }

        nz++;
      }
    } else low[u] = min(low[u], vis[v]);
  }
}


int32_t main(){
  iopt;
  int n, m, Q;
  cin >> n >> m >> Q;

  for(int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    --a, --b;
    adj[a].pb(edges.size());
    edges.pb(b);
    adj[b].pb(edges.size());
    edges.pb(a);
  }

  g = G(n);
  nz = n;
  tarjan(0, -1);

  auto f = lib::graph::builders::id8(g, {0});
  auto hld = lib::graph::id9(f);

  for(int i = 0; i < Q; i++) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    cout << hld.dist(u, v)/2 << "\n";
  }
}
