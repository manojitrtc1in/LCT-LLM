



#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")


#define NDEBUG
NDEBUG


#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cstring>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <memory>
#include <queue>
#include <random>


using namespace std;

template<class T>
using vec = std::vector<T>;


#define FOR(i, n) for (int i = 0; i < (n); ++i)


#define forn(t, i, n) for (t i = 0; i < (n); ++i)


#define all(c) c.begin(), c.end()






bool __hack = std::ios::sync_with_stdio(false);


auto __hack1 = cin.tie(nullptr);



template<class T>
inline T mn(T arg) {
    return arg;
}

template<class T, class... Ts>
inline typename common_type<T, Ts...>::type mn(T arg, Ts... args) {
    auto arg1 = mn(args...);
    return arg < arg1 ? arg : arg1;
}

template<class T>
inline T mx(T arg) {
    return arg;
}


template<class T, class... Args>
inline bool rmn(T &to, Args... args) {
    auto v = mn(args...);
    if (to > v) {
        to = v;
        return true;
    }
    return false;
}

template<class T, class... Args>
inline bool rmx(T &to, Args... args) {
    auto v = mx(args...);
    if (to < v) {
        to = v;
        return true;
    }
    return false;
}


template <class T>
T pop_back(vector<T>& v) {
    T ret = v.back();
    v.pop_back();
    return ret;
}

template <class T>
T pop(queue<T>& v) {
    T ret = v.front();
    v.pop();
    return ret;
}





















struct Input {

    Input(istream &in) : in(&in) {}

    template<class T>
    T next() const {
        T x;
        *in >> x;
        return x;
    }

    int ni() const {
        return next<int>();
    }

    
    template<class T>
    vec<T> nVec(int n) const {
        vec<T> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = next<T>();
        }
        return v;
    }

    vec<int> nvi(int n) const {
        return nVec<int>(n);
    }

    
    istream *in;
};

Input in(cin);


class Output {

private:
ostream *out;

template<typename T>
void printSingle(const T &value) {
    *out << value;
}


public:
Output(ostream &out) : out(&out) {}


inline void print() {}

template<typename T, typename...Ts>
inline void print(const T &f, const Ts&... args) {
    printSingle(f);
    if (sizeof...(args) != 0) {
        *out << ' ';
        print(args...);
    }
}

template<typename...Ts>
inline void println(const Ts&... args) {
    print(args...);
    (*out) << '\n';
}

template<typename...Ts>
inline void operator() (const Ts&... args) {
    println(args...);
}


};

Output out(cout);


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




namespace graph_impl {

    template<class T, class G, T next(const G&, T)>
    struct GenListIterator {
        GenListIterator(const G& g_, T t_): g(g_), t(t_) {}

        T operator*() const {
            return t;
        }

        GenListIterator& operator++() {
            t = next(g, t);
            return *this;
        }

        
        bool operator!=(const GenListIterator& o) const {
            assert(&g == &o.g);
            return t != o.t;
        }
    private:
        const G& g;
        T t;
    };

    template<class T, class G, T next(const G&, T)>
    struct GenListIterable {
        GenListIterable(const G& g_, T from_, T to_): g(g_), from(from_), to(to_) {}

        GenListIterator<T, G, next> begin() {
            return {g, from};
        };

        GenListIterator<T, G, next> end() {
            return {g, to};
        };
    private:
        const G& g;
        T from, to;
    };

    template<class T>
    struct GenRangeIterator {
        explicit GenRangeIterator(int at_): at(at_) {}

        T operator*() const {
            return T{at};
        }

        GenRangeIterator& operator++() {
            at++;
            return *this;
        }

        
        bool operator!=(const GenRangeIterator& o) const {
            return at != o.at;
        }
    private:
        int at;
    };

    template<class T>
    struct GenRangeIterable {
        GenRangeIterable(int from_, int to_):  from(from_), to(to_) {}

        GenRangeIterator<T> begin() {
            return GenRangeIterator<T>{from};
        };

        GenRangeIterator<T> end() {
            return GenRangeIterator<T>{to};
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

    explicit Node(int id_ = -1) : id(id_) {}

    bool operator==(const Node o) const { return id == o.id; }

    bool operator!=(const Node o) const { return id != o.id; }

    
  };

  struct Arc {
    int id;

    explicit Arc(int id_ = -1) : id(id_) {}

    bool operator==(const Arc o) const { return id == o.id; }

    bool operator!=(const Arc o) const { return id != o.id; }

    
  };

  struct Edge {
    int id;

    explicit Edge(int id_ = -1) : id(id_) {}

    
    template<class C>
    Edge& withUV(C& c, typename C::Value v) {
      c(Arc{2 * id}) = v;
      return *this;
    };

    
  };

  template<class V>
  using NodeMap = graph_impl::GenMap<Node, V>;

  template<class V>
  using ArcMap = graph_impl::GenMap<Arc, V>;

  
  Node addNode() {
    int n = (int) nodes_.size();
    nodes_.push_back({});
    return Node{n};
  }

  vector<Node> addNodes(int count) {
    vector<Node> ret(count);
    forn (int, i, count) {
      ret[i] = addNode();
    }
    return ret;
  }

  Edge addEdge(Node u, Node v) {
    assert(valid(u));
    assert(valid(v));
    int n = (int) arcs_.size();
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
    return (int) nodes_.size();
  }

  int arcsCount() const {
    return (int) arcs_.size();
  }

  int edgesCount() const {
    return (int) arcs_.size() / 2;
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

  
  template<class T>
  NodeMap<T> nodeMap(T v0 = T{}) const {
    NodeMap<T> ret(v0);
    ret.reserve(nodesCount());
    return ret;
  }

  template<class T>
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

  graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_> inArcs(Node a) const {
    assert(valid(a));
    return graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_>(*this,
                                                                       firstInArc(a),
                                                                       Arc{});
  }

  graph_impl::GenListIterable<Arc, Graph, &Graph::nextOutArc_> outArcs(Node a) const {
    assert(valid(a));
    return graph_impl::GenListIterable<Arc, Graph, &Graph::nextOutArc_>(*this,
                                                                        firstOutArc(a),
                                                                        Arc{});
  }

  graph_impl::GenRangeIterable<Node> nodes() const {
    return graph_impl::GenRangeIterable<Node>(0, nodesCount());
  }

  graph_impl::GenRangeIterable<Arc> arcs() const {
    return graph_impl::GenRangeIterable<Arc>(0, arcsCount());
  }

  
 private:
  vector<graph_impl::NodeT> nodes_;
  vector<graph_impl::ArcT> arcs_;
};










template <class Cap = int32_t, class Excess = int64_t>
struct PushRelabel {
    using Node = Graph::Node;
    using Arc = Graph::Arc;
    

    PushRelabel(const Graph& g_, const Graph::ArcMap<Cap>& cap_): g(g_), cap(cap_) {}

    Excess run(Node s, Node t) {
        flow = g.arcMap<Cap>();
        residual = cap;
        label = g.nodeMap<int>(g.nodesCount());
        excess = g.nodeMap<Excess>();
        excess(s) = numeric_limits<Excess>::max();
        currentArc = g.nodeMap<Arc>();
        for (auto v : g.nodes()) {
            currentArc(v) = g.firstOutArc(v);
        }
        fullRelabel(t);
        while (currentActiveLabel > 0) {
            if (activeNodesByLabel[currentActiveLabel].empty()) {
                currentActiveLabel--;
                continue;
            }
            auto u = pop_back(activeNodesByLabel[currentActiveLabel]);
            currentActiveLabel = discharge(u);
            if (stepsCount >= g.edgesCount()) {
                fullRelabel(t);
                stepsCount = 0;
            }
        }
        Graph::NodeMap<Node> parent;
        Graph::NodeMap<char> color;
        vector<Node> order;
        for (auto root : g.nodes()) {
            if (root != t && color(root) == 0 && excess(root) > 0) {
                currentArc(root) = g.firstInArc(root);
                color(root) = 1;
                auto u = root;
                while (u != Node{-1}) {
                    auto a = currentArc(u);
                    if (a == Arc{}) {
                        order.push_back(u);
                        color(u) = 2;
                        u = parent(u);
                        continue;
                    }
                    auto v = g.from(a);
                    if (residual(a) < cap(a)) {
                        if (color(v) == 0) {
                            currentArc(v) = g.firstInArc(v);
                            color(v) = 1;
                            parent(v) = u;
                            u = v;
                        } else if (color(v) == 1) {
                            Cap delta = cap(a) - residual(a);
                            for (auto w = v; w != u; w = g.from(currentArc(w))) {
                                auto b = currentArc(w);
                                rmn(delta, cap(b) - residual(b));
                            }
                            auto restartFrom = u;
                            for (auto w = v; ; w = g.from(currentArc(w))) {
                                auto b = currentArc(w);
                                residual(b) += delta;
                                residual(g.dual(b)) -= delta;
                                if (w != u && (color(w) == 0 || residual(b) == cap(b))) {
                                    color(g.from(b)) = 0;
                                    if (color(w) != 0) {
                                        restartFrom = w;
                                    }
                                }
                                if (w == u) {
                                    break;
                                }
                            }
                            u = restartFrom;
                        } else {
                            currentArc(u) = g.nextInArc(a);
                        }
                    } else {
                        currentArc(u) = g.nextInArc(a);
                    }
                }
            }
        }
        reverse(all(order));
        for (auto u : order) {
            if (excess(u) > 0) {
                for (auto a : g.inArcs(u)) {
                    if (residual(a) < cap(a)) {
                        auto v = g.from(a);
                        Cap delta = mn(excess(u), cap(a) - residual(a));
                        excess(u) -= delta;
                        excess(v) += delta;
                        residual(a) += delta;
                        residual(g.dual(a)) -= delta;
                        if (excess(u) == 0) {
                            break;
                        }
                    }
                }
            }
        }
        for (auto a : g.arcs()) {
            flow(a) = cap(a) - residual(a);
        }
        assert(checkFlow(s, t, excess(t)));
        return value = excess(t);
    }

    
    void fullRelabel(Node t) {
        label.clear();
        label(t) = 0;
        queue<Node> q;
        q.push(t);
        while (!q.empty()) {
            auto u = pop(q);
            for (auto a : g.inArcs(u)) {
                auto v = g.from(a);
                if (residual(a) > 0 && label(v) == g.nodesCount()) {
                    label(v) = label(u) + 1;
                    q.push(v);
                }
            }
        }
        activeNodesByLabel.clear();
        activeNodesByLabel.resize(g.nodesCount());
        currentActiveLabel = 0;
        for (auto u : g.nodes()) {
            if (u != t && excess(u) > 0 && label(u) < g.nodesCount()) {
                activeNodesByLabel[label(u)].push_back(u);
                rmx(currentActiveLabel, label(u));
            }
        }
    }

    void relabel(Node u) {
        label(u) = g.nodesCount();
        for (auto a : g.outArcs(u)) {
            if (residual(a) > 0) {
                rmn(label(u), label(g.to(a)) + 1);
            }
            stepsCount++;
        }
    }

    Cap discharge(Node u) {
        int ret;
        while (label(u) < g.nodesCount()) {
            ret = label(u);
            stepsCount++;
            auto a = currentArc(u);
            auto v = g.to(a);
            

            if (residual(a) > 0 && label(u) == label(v) + 1) {
                Cap delta = mn(excess(u), residual(a));
                if (excess(v) == 0) {
                    activeNodesByLabel[label(v)].push_back(v);
                }
                excess(u) -= delta;
                excess(v) += delta;
                residual(a) -= delta;
                residual(g.dual(a)) += delta;
                if (excess(u) == 0) {
                    break;
                }
            }
            currentArc(u) = g.nextOutArc(a);
            if (currentArc(u) == Arc{}) {
                relabel(u);
                currentArc(u) = g.firstOutArc(u);
            }
        }
        return ret;
    }

    

    Excess value;
    Graph::ArcMap<Cap> flow, residual;

private:
    

    const Graph& g;
    const Graph::ArcMap<Cap>& cap;

    

    Graph::NodeMap<Excess> excess;
    Graph::NodeMap<int> label;
    Graph::NodeMap<Arc> currentArc;
    int stepsCount = 0;

    vector<vector<Node>> activeNodesByLabel;
    int currentActiveLabel;
};

































































const int INF = numeric_limits<int>::max() / 2;

void solve(istream& inStream, ostream& outStream) {
    in = Input(inStream);
    out = Output(outStream);
    auto n = in.ni();
    auto a = in.nvi(n);
    auto b = in.nvi(n);
    Graph g;
    auto nodes = g.addNodes(n + 2);
    auto S = &nodes.end()[-2];
    auto T = &nodes.end()[-1];
    auto cap = g.arcMap<int>();
    int total = 0;
    FOR(i, n) {
        if (b[i] > 0) {
            total += b[i];
            g.addEdge(*S, nodes[i]).withUV(cap, b[i]);
        } else {
            g.addEdge(nodes[i], *T).withUV(cap, -b[i]);
        }
        vec<bool> was(100, false);
        for (int j = i - 1; j >= 0; --j) {
            if (a[i] % a[j] == 0 && !was[a[j]]) {
                was[a[j]] = true;
                g.addEdge(nodes[i], nodes[j]).withUV(cap, INF);
            }
        }
    }
    PushRelabel<> mf(g, cap);


    out(total - mf.run(*S, *T));
}





int main() {








    solve(cin, cout);


    return 0;
}

