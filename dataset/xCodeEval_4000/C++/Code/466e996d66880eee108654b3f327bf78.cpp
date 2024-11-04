



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

template <class T, class C, class Cmp>
T pop(priority_queue<T, C, Cmp>& v) {
    T ret = v.top();
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

    bool operator<(const Node o) const { return id < o.id; }

    
  };

  struct Arc {
    int id;

    explicit Arc(int id_ = -1) : id(id_) {}

    
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

  
 public:

  graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_> inArcs(Node a) const {
    assert(valid(a));
    return graph_impl::GenListIterable<Arc, Graph, &Graph::nextInArc_>(*this,
                                                                       firstInArc(a),
                                                                       Arc{});
  }

  
  graph_impl::GenRangeIterable<Arc> arcs() const {
    return graph_impl::GenRangeIterable<Arc>(0, arcsCount());
  }

  
 private:
  vector<graph_impl::NodeT> nodes_;
  vector<graph_impl::ArcT> arcs_;
};














template <class Cap = int32_t, class Excess = int64_t>
struct KarzanovFlow {
    using Node = Graph::Node;
    using Arc = Graph::Arc;
    

    KarzanovFlow(const Graph& g_, const Graph::ArcMap<Cap>& cap_): g(g_), cap(cap_) {}

    Excess run(Node s, Node t) {
        residual = cap;
        label = g.nodeMap<int>(g.nodesCount());
        inFlows = g.nodeMap<vector<pair<Cap, Arc>>>();
        excess = g.nodeMap<Excess>();
        excess(s) = numeric_limits<Excess>::max();
        currentArc = g.nodeMap<Arc>();
        while (buildNet(s, t)) {
            int maxDist = label(s);
            int curActive = maxDist;
            priority_queue<pair<int, Node>> inactives;
            while (countActives > 0 || !inactives.empty()) {
                if (countActives == 0) {
                    int l0 = -inactives.top().first;
                    while (!inactives.empty() && -inactives.top().first <= l0 + 1) {
                        auto u = pop(inactives).second;
                        inactive(u) = 1;
                        curActive = label(u) + 1;
                        auto& in = inFlows(u);
                        while (excess(u) > 0) {
                            assert(!in.empty());
                            auto p = pop_back(in);
                            auto a = p.second;
                            auto v = g.to(a);
                            Cap delta = mn(p.first, excess(u));
                            if (excess(v) == 0 && v != s) {
                                activeNodesByLabel[label(v)].push_back(v);
                                countActives++;
                            }
                            excess(u) -= delta;
                            excess(v) += delta;
                            residual(a) -= delta;
                            residual(g.dual(a)) += delta;
                            p.first -= delta;
                            if (p.first > 0) {
                                in.push_back(p);
                            }
                        }
                    }
                }
                if (activeNodesByLabel[curActive].empty()) {
                    curActive--;
                    continue;
                }
                Node u = pop_back(activeNodesByLabel[curActive]);
                if (discharge(u) && u != s) {
                    inactives.emplace(-label(u), u);
                }
            }
        }
        flow = g.arcMap<Cap>();
        for (auto a : g.arcs()) {
            flow(a) = cap(a) - residual(a);
        }
        return value = excess(t);
    }

    bool buildNet(Node s, Node t) {
        label.clear();
        label(t) = 0;
        queue<Node> q;
        q.push(t);
        while (!q.empty()) {
            auto u = pop(q);
            currentArc(u) = g.firstOutArc(u);
            inactive(u) = 0;
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
        inFlows.clear();
        activeNodesByLabel.clear();
        activeNodesByLabel.resize(label(s) + 1);
        activeNodesByLabel[label(s)].push_back(s);
        countActives = 1;
        return true;
    }

    bool push(Arc a, Node u, Node v) {
        if (residual(a) == 0) {
            return false;
        }
        Cap delta = (Cap)mn(excess(u), residual(a));
        if (excess(v) == 0 && label(v) > 0) {
            activeNodesByLabel[label(v)].push_back(v);
            countActives++;
        }
        excess(u) -= delta;
        excess(v) += delta;
        residual(a) -= delta;
        residual(g.dual(a)) += delta;
        inFlows(v).emplace_back(delta, g.dual(a));
        return excess(u) == 0;
    }

    bool discharge(Node u) {
        assert(excess(u) > 0);
        countActives--;
        while (currentArc(u) != Arc{}) {
            auto a = currentArc(u);
            auto v = g.to(a);
            if (label(u) == label(v) + 1 && !inactive(v) && push(a, u, v)) {
                return false;
            }
            currentArc(u) = g.nextOutArc(a);
        }
        return true;
    }

    

    Excess value;
    Graph::ArcMap<Cap> flow, residual;

private:
    

    const Graph& g;
    const Graph::ArcMap<Cap>& cap;

    

    Graph::NodeMap<Excess> excess;
    Graph::NodeMap<int> label, inactive;
    Graph::NodeMap<vector<pair<Cap, Arc>>> inFlows;
    Graph::NodeMap<Arc> currentArc;

    vector<vector<Node>> activeNodesByLabel;
    int countActives;
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
    KarzanovFlow<> mf(g, cap);


    out(total - mf.run(*S, *T));
}





int main() {








    solve(cin, cout);


    return 0;
}

