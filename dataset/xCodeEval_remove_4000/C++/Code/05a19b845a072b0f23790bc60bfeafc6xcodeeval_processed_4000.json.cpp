
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

template<class T>
using vec2d = std::vector<std::vector<T>>;












bool __hack = std::ios::sync_with_stdio(false);


auto id5 = cin.tie(nullptr);



template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}


template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}

















namespace graph_impl {

    template<class T, class G, T next(const G&, T)>
    struct id1 {
        id1(const G& g_, T t_): g(g_), t(t_) {}

        T operator*() const {
            return t;
        }

        id1& operator++() {
            t = next(g, t);
            return *this;
        }

        
        bool operator!=(const id1& o) const {
            assert(&g == &o.g);
            return t != o.t;
        }
    private:
        const G& g;
        T t;
    };

    template<class T, class G, T next(const G&, T)>
    struct id0 {
        id0(const G& g_, T from_, T to_): g(g_), from(from_), to(to_) {}

        id1<T, G, next> begin() {
            return {g, from};
        };

        id1<T, G, next> end() {
            return {g, to};
        };
    private:
        const G& g;
        T from, to;
    };

    template<class T>
    struct id4 {
        explicit id4(int at_): at(at_) {}

        T operator*() const {
            return T{at};
        }

        id4& operator++() {
            at++;
            return *this;
        }

        
        bool operator!=(const id4& o) const {
            return at != o.at;
        }
    private:
        int at;
    };

    template<class T>
    struct id2 {
        id2(int from_, int to_):  from(from_), to(to_) {}

        id4<T> begin() {
            return id4<T>{from};
        };

        id4<T> end() {
            return id4<T>{to};
        };
    private:
        int from, to;
    };

    template<class K, class V>
    struct GenMap {
        using Value = V;

        explicit GenMap(V v_ = V{}): v(v_) {
        }

        GenMap& reserve(int n) {
            impl_.reserve(n);
            return *this;
        }

        GenMap& clear() {
            impl_.clear();
            return *this;
        }

        V& operator()(K k) {
            if (impl_.size() <= k.id) {
                impl_.resize(k.id + 1, v);
            }
            return impl_[k.id];
        }

        const V& operator()(K k) const {
            if (impl_.size() <= k.id) {
                return v;
            }
            return impl_[k.id];
        }
        vector<V> impl_;
    private:
        V v;
    };


    struct NodeT {
        int firstOut = -1;
        int degree = 0;
    };

    struct ArcT {
        int to, nextOut;
    };
}

struct Graph {
    struct Node {
        int id;
        explicit Node(int id_ = -1): id(id_) {}
        bool operator==(const Node o) const {return id == o.id;}
        
        
    };

    struct Arc {
        int id;
        explicit Arc(int id_ = -1): id(id_) {}
        
        bool operator!=(const Arc o) const {return id != o.id;}

        
    };

    struct Edge {
        int id;
        explicit Edge(int id_ = -1): id(id_) {}
        
        
        template<class C>
        Edge& withUV(C& c, typename C::Value v) {
            c(Arc{2 * id}) = v;
            return *this;
        };

        template<class C>
        Edge& withVU(C& c, typename C::Value v) {
            c(Arc{2 * id + 1}) = v;
            return *this;
        };

        
    };

    template<class V>
    using NodeMap = graph_impl::GenMap<Node, V>;

    template<class V>
    using ArcMap = graph_impl::GenMap<Arc, V>;

    
    Node addNode() {
        int n = (int)nodes_.size();
        nodes_.push_back({});
        return Node{n};
    }

    
    Edge addEdge(Node u, Node v) {
        assert(valid(u));
        assert(valid(v));
        int n = (int)arcs_.size();
        arcs_.push_back({});
        arcs_[n].to = v.id;
        arcs_[n].nextOut = nodes_[u.id].firstOut;
        nodes_[u.id].firstOut = n;
        arcs_.push_back({});
        arcs_[n + 1].to = u.id;
        arcs_[n + 1].nextOut = nodes_[v.id].firstOut;
        nodes_[v.id].firstOut = n + 1;
        nodes_[u.id].degree++;
        nodes_[v.id].degree++;
        return Edge{n >> 1};
    }

    
    int nodesCount() const {
        return (int)nodes_.size();
    }

    int arcsCount() const {
        return (int)arcs_.size();
    }

    
    Arc dual(Arc a) const {
        if (a.id == -1) {
            return a;
        }
        assert(valid(a));
        return Arc{a.id ^ 1};
    }

    Arc firstInArc(Node a) const {
        assert(valid(a));
        return dual(Arc{nodes_[a.id].firstOut});
    }

    Arc firstOutArc(Node a) const {
        assert(valid(a));
        return Arc{nodes_[a.id].firstOut};
    }

    Arc nextInArc(Arc a) const {
        assert(valid(a));
        return dual(Arc{arcs_[dual(a).id].nextOut});
    }

    Arc nextOutArc(Arc a) const {
        assert(valid(a));
        return Arc{arcs_[a.id].nextOut};
    }

    Node from(Arc a) const {
        assert(valid(a));
        return Node{arcs_[dual(a).id].to};
    }

    Node to(Arc a) const {
        assert(valid(a));
        return Node{arcs_[a.id].to};
    }

    
    template <class T>
    NodeMap<T> nodeMap(T v0 = T{}) const {
        NodeMap<T> ret(v0);
        ret.reserve(nodesCount());
        return ret;
    }

    template <class T>
    ArcMap<T> arcMap(T v0 = T{}) const {
        ArcMap<T> ret(v0);
        ret.reserve(arcsCount());
        return ret;
    }

    
private:

    static Arc nextInArc_(const Graph& g, Arc a) {
        return g.nextInArc(a);
    }

    static Arc nextOutArc_(const Graph& g, Arc a) {
        return g.nextOutArc(a);
    }

public:

    graph_impl::id0<Arc, Graph, &Graph::nextInArc_> inArcs(Node a) const {
        assert(valid(a));
        return graph_impl::id0<Arc, Graph, &Graph::nextInArc_>(*this, firstInArc(a), Arc{});
    }

    graph_impl::id0<Arc, Graph, &Graph::nextOutArc_> outArcs(Node a) const {
        assert(valid(a));
        return graph_impl::id0<Arc, Graph, &Graph::nextOutArc_>(*this, firstOutArc(a), Arc{});
    }

    
    graph_impl::id2<Arc> arcs() const {
        return graph_impl::id2<Arc>(0, arcsCount());
    }

    
private:
    vector<graph_impl::NodeT> nodes_;
    vector<graph_impl::ArcT> arcs_;
};



























template<class T>
bool isPrime(T x) {
    if (x == 1) {
        return false;
    }
    if (x == 2) {
        return true;
    }
    if (x % 2 == 0) {
        return false;
    }
    for (T i = 3; i * i <= x; i += 2) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}










































template <class Cap = int32_t, class Excess = int64_t>
struct id3 {
    using Node = Graph::Node;
    using Arc = Graph::Arc;
    

    id3(const Graph& g_, const Graph::ArcMap<Cap>& cap_): g(g_), cap(cap_) {}

    Excess run(Node s, Node t) {
        residual = cap;
        label = g.nodeMap<int>(g.nodesCount());
        currentArc = g.nodeMap<Arc>();
        value = 0;
        while (buildNet(s, t)) {
            Cap inf = numeric_limits<Cap>::max();
            Cap cur;
            while ((cur = flowDfs(s, t, inf)) > 0) {
                value += cur;
            }
        }
        flow = g.arcMap<Cap>();
        for (auto a : g.arcs()) {
            flow(a) = cap(a) - residual(a);
        }
        return value;
    }

    bool buildNet(Node s, Node t) {
        label.clear();
        label(t) = 0;
        queue<Node> q;
        q.push(t);
        while (!q.empty()) {
            auto u = pop(q);
            currentArc(u) = g.firstOutArc(u);
            if (u == s) {
                break;
            }
            for (auto a : g.inArcs(u)) {
                auto v = g.from(a);
                if (residual(a) > 0 && label(v) == g.nodesCount()) {
                    label(v) = label(u) + 1;
                    q.push(v);
                }
            }
        }
        if (label(s) == g.nodesCount()) {
            return false;
        }
        return true;
    }

    Cap flowDfs(Node u, Node t, Cap max) {
        if (u == t) {
            return max;
        }
        Cap ret = 0;
        auto& a = currentArc(u);
        for (; a != Arc{}; a = g.nextOutArc(a)) {
            auto v = g.to(a);
            Cap cur;
            if (label(u) == label(v) + 1 && residual(a) > 0 && (cur = flowDfs(v, t, mn(residual(a), max))) > 0) {
                ret += cur;
                max -= cur;
                residual(a) -= cur;
                residual(g.dual(a)) += cur;
                if (max == 0) {
                    break;
                }
            }
        }
        return ret;
    }

    

    Excess value;
    Graph::ArcMap<Cap> flow, residual;

private:
    

    const Graph& g;
    const Graph::ArcMap<Cap>& cap;

    

    Graph::NodeMap<int> label;
    Graph::NodeMap<Arc> currentArc;
};


namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}


template<class T>
vector<pair<T, int>> id6(istream& in, size_t n) {
  vector<pair<T, int>> ret(n);
  for (size_t i = 0; i < n; ++i) {
    ret[i] = {next<T>(in), i};
  }
  return ret;
}





void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto a = id6<int>(in, n);
  int countEven = std::count_if(all(a), [] (pair<int, int> x) -> bool { return x.first % 2 == 0; });
  if (countEven * 2 != n) {
    out << "Impossible\n";
    return;
  }
  Graph g;
  auto S = g.addNode();
  vec<Graph::Node> leftSide, rightSide;
  Graph::ArcMap<int> cap;
  FOR(i, countEven) {
    leftSide.push_back(g.addNode());
    g.addEdge(S, leftSide.back()).withUV(cap, 2).withVU(cap, 0);
  }
  FOR(i, countEven) {
    rightSide.push_back(g.addNode());
  }
  auto T = g.addNode();
  FOR(i, countEven) {
    g.addEdge(rightSide[i], T).withUV(cap, 2).withVU(cap, 0);
  }
  vec<pair<int, int>> leftNumber, rightNumber;
  FOR(i, n) {
    if (a[i].first % 2 == 1) {
      leftNumber.push_back(a[i]);
    } else {
      rightNumber.push_back(a[i]);
    }
  }

  FOR(i, countEven) {
    FOR(j, countEven) {
      if (isPrime(leftNumber[i].first + rightNumber[j].first)) {
        g.addEdge(leftSide[i], rightSide[j]).withUV(cap, 1).withVU(cap, 0);
      }
    }
  }
  id3<> mf(g, cap);
  auto fl = mf.run(S, T);
  if (fl != n) {
    out << "Impossible\n";
    return;
  }
  vec2d<int> result;
  int inResult = 0;
  vec<bool> used(countEven);
  while (inResult < n) {

    int startV = -1, toV = -1;
    FOR(i, countEven) {
      if (used[i]) continue;
      for (auto ar : g.outArcs(leftSide[i])) {
        if (g.to(ar) == S) continue;
        if (mf.flow(ar)) {
          startV = i;
          toV = g.to(ar).id - countEven - 1;
          break;
        }
      }
      if (startV != -1) {
        break;
      }
    }

    if (startV == -1) throw 42;

    vec<int> r;
    int v = startV, u = toV;

    used[v] = true;
    while (true) {
      r.push_back(leftNumber[v].second);
      r.push_back(rightNumber[u].second);
      used[v] = true;

      int nv = -1, nu = -1;
      for (auto ar : g.inArcs(rightSide[u])) {
        if (g.from(ar) == T) continue;
        if (mf.flow(ar)) {
          if (g.from(ar).id - 1 != v) {
            nv = g.from(ar).id - 1;
            break;
          }
        }
      }

      if (nv == startV) break;

      for (auto ar : g.outArcs(leftSide[nv])) {
        if (g.to(ar) == S) continue;
        if (mf.flow(ar)) {
          if (g.to(ar).id - countEven - 1 != u) {
            nu = g.to(ar).id - countEven - 1;
            break;
          }
        }
      }

      v = nv;
      u = nu;
    }

    result.push_back(r);
    inResult += r.size();

  }

  for (auto& v : result) {
    FOR(i, v.size()) {
      int j = (i + 1) % v.size();
      if (!isPrime(a[v[i]].first + a[v[j]].first)) {
        dbg("NO!");
        throw 42;
      }
    }
  }

  out << result.size() << "\n";
  for (auto& v : result) {
    out << v.size();
    for (auto& x : v) {
      out << " " << (x + 1);
    }
    out << "\n";
  }

}





int main() {




    solve(cin, cout);


    return 0;
}

