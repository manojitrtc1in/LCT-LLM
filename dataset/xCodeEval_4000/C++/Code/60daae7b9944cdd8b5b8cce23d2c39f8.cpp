#include <bits/stdc++.h>
#ifndef _LIB_MAX_FLOW
#define _LIB_MAX_FLOW
#include <bits/stdc++.h>
#ifndef _LIB_GRAPH
#define _LIB_GRAPH
#include <bits/stdc++.h>
#ifndef _LIB_TRAITS
#define _LIB_TRAITS
#include <bits/stdc++.h>

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

#endif
#ifndef _LIB_WRAPPERS
#define _LIB_WRAPPERS
#include <bits/stdc++.h>

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
}  

}  


#endif

namespace lib {
  using namespace std;
namespace graph {
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

    void add_2edge(int u, int v) {
      add_edge(u, v);
      add_edge(v, u);
    }

    template<typename S = E, typename enable_if<!is_void<S>::value>::type* = nullptr>
    inline void add_2edge(int u, int v, const S& data) {
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
  struct RootedTree : public RootedForest<V, E> {
    using typename RootedForest<V, E>::adj_list;
    int root;

    RootedTree(int n, int root) : RootedForest<V, E>(n) {
      assert(n > 0);
      assert(root < n);
      this->root = root;
    }

    RootedTree(const adj_list& adj, int root) : RootedForest<V, E>(adj) {
      assert(adj.size() > 0);
      assert(root < adj.size());
      this->root = root;
    }
  };

  namespace builders {
    namespace {
      template<typename F, typename G>
      void dfs_rooted_forest(F& forest, const G& graph, int u, vector<bool>& vis) {
        vis[u] = true;
        for(const auto& ed : graph.n_edges(u)) {
          int v = ed.to;
          if(!vis[v]) {
            forest.add_edge(u, v);
            dfs_rooted_forest(forest, graph, v, vis);
          }
        }
      }

      template<typename A, typename B>
      RootedForest<A, B> make_rooted_forest(const Graph<A, B>& graph,
                                            const vector<int>& roots) {
        RootedForest<A, B> res(graph.size());
        vector<bool> vis(graph.size());
        for(int i : roots)
          if(!vis[i])
            dfs_rooted_forest(res, graph, i, vis);
        for(int i = 0; i < graph.size(); i++)
          if(!vis[i])
            dfs_rooted_forest(res, graph, i, vis);
        return res;
      }
    }
  }  

}  

}  


#endif



namespace lib {
  using namespace std;
namespace flow {
  template<typename T, typename E>
  struct Edge {
    T cap;
    bool original;
    E label;
  };
  template<typename T>
  struct Edge<T, void> {
    T cap;
    bool original;
  };

  template<typename T, typename E = void>
  struct Maxflow {
    typedef Maxflow<T, E> type;
    typedef Edge<T, E> flow_edge_type;
    typedef lib::graph::Graph<void, flow_edge_type> graph;
    using edge_type = typename graph::edge_type;

    graph g;
    int source, sink;
    vector<bool> visited;
    vector<int> dist;
    vector<size_t> used;

    explicit Maxflow(int n) : g(n), source(n-2), sink(n-1) {
      assert(n >= 2);
    }
    void setup(int a, int b) { source = a, sink = b; }
    void add_fake_edge(int u, int v, T weight) {
      g.add_edge(u, v) = {weight, false};
      g.add_edge(v, u) = {0, false};
    }
    template<typename S = E,
             typename enable_if<is_void<S>::value>::type* = nullptr>
    void add_edge(int u, int v, T weight = 1) {
      g.add_edge(u, v) = {weight, true};
      g.add_edge(v, u) = {0, true};
    }
    template<typename S = E,
             typename enable_if<!is_void<S>::value>::type* = nullptr>
    void add_edge(int u, int v, T weight = 1, S data = S()) {
      g.add_edge(u, v) = {weight, true, data};
      g.add_edge(v, u) = {0, true, S()};
    }
    inline int size() const { return g.size(); }
    inline int edge_size() const { return g.edge_size(); }
    edge_type reverse(int i) const { return g.edge(i^1); }
    edge_type edge(int i) const { return g.edge(i); }
    flow_edge_type& flow_edge(int i) { return g.edge(i).data; }
    flow_edge_type& reverse_flow_edge(int i) { return g.edge(i^1).data; }

    bool layered_bfs() {
      int n = size();
      dist.assign(n, -1);
      dist[source] = 0;
      vector<int> q;
      q.reserve(n);
      q.push_back(source);

      for(size_t i = 0; i < q.size(); i++) {
        int u = q[i];
        if(u == sink) break;
        for(const auto& e : g.n_edges(u)) {
          if(dist[e.to] == -1 && e.data.cap > 0) {
            dist[e.to] = dist[u] + 1;
            q.push_back(e.to);
          }
        }
      }

      return dist[sink] != -1;
    }

    T augmenting_path(const int u, const T bottle) {
      if(!bottle) return 0;
      if(u == sink) return bottle;
      for(size_t& i = used[u]; i < g.adj[u].size(); i++) {
        int x = g.adj[u][i];
        auto& e = g.edge(x);
        if(dist[e.to] != dist[u] + 1) continue;
        T cf = augmenting_path(e.to, min(bottle, e.data.cap));
        e.data.cap -= cf;
        g.edge(x^1).data.cap += cf;
        if(cf) return cf;
      }
      return 0;
    }

    T blocking_flow() {
      if(!layered_bfs()) return 0;
      used.assign(size(), 0);
      T aug, flow = 0;
      while((aug = augmenting_path(source, numeric_limits<T>::max())))
        flow += aug;
      return flow;
    }

    T maxflow() {
      T aug, flow = 0;
      while((aug = blocking_flow())) flow += aug;
      return flow;
    }

    vector<bool> mincut() const {
      int n = size();
      vector<bool> vis(n);
      vector<int> q;
      q.reserve(n);
      q.push_back(source);
      vis[source] = true;
      for(size_t i = 0; i < q.size(); i++) {
        int u = q[i];
        for(const auto& e : g.n_edges(u)) {
          if(e.data.cap > 0 && !vis[e.to]) {
            q.push_back(e.to);
            vis[e.to] = true;
          }
        }
      }
      return vis;
    }
  };
}  

}  


#endif
#define int long long
using namespace std;
 
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define ms(v, x) memset((v), (x), sizeof(v))
#define all(v) (v).begin(), (v).end()
#define ff first
#define ss second
#define iopt ios::sync_with_stdio(false); cin.tie(0)
 
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

struct Edge {
    int u, v, d;
};

int32_t main(){
    iopt;

    int n; cin >> n;
    int m; cin >> m;

    vector<Edge> ed(m);
    for(int i = 0; i < m; i++) {
        cin >> ed[i].u >> ed[i].v >> ed[i].d;
        ed[i].u--, ed[i].v--;
    }

    auto check = [&](int mid) {
        lib::flow::Maxflow<int> flow(2*n+2);
        for(int i = 0; i < n; i++) {
            flow.add_edge(flow.source, i, 1);
            flow.add_edge(n+i, flow.sink, 1);
        }
        for(Edge& e : ed) {
            if(e.d <= mid)
                flow.add_edge(e.u, n+e.v, 1);
        }
        return flow.maxflow() == n;
    };

    int l = 0, r = (int)1e9+10;
    while(l < r) {
        int mid = (l+r)/2;
        if(check(mid))
             r = mid;
        else l = mid+1;
    }

    if(l == (int)1e9+10) cout << -1 << endl;
    else cout << l << endl;
}
