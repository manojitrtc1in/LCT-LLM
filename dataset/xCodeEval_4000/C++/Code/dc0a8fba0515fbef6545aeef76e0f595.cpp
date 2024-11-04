#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <deque>
#include <queue>
#include <algorithm>
#include <cassert>
#include <cmath>
#include <ctime>
#include <sstream>
#include <unordered_set>
#include <unordered_map>
#include <functional>
#include <bitset>
#include <valarray>
#include <utility>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

#ifdef LOCAL_RUN
#define debug(x) cerr << #x << ": "  << (x) << "\n";
#else
#define debug(x) ;
#endif

#define all(v) (v).begin(), (v).end()
#define MP make_pair

template<class T>
class IsIterable__ {static void f(...); template<class U> static typename U::const_iterator f(const U&);
public:const static bool value = !std::is_same<void, decltype(f(std::declval<T>()))>::value;};

template <class F, class S> ostream& operator << (ostream& o, const pair<F,S>& p) {
return o << "(" << p.first << ", " << p.second << ")";}

template<class C>void O__(ostream& o, const C& c) {
bool f = 1; for(const auto& x: c) {if (!f) o << ", "; if (IsIterable__<decltype(x)>::value) o << "\n"; f = 0; o << x;}}

template <class T>
ostream& operator << (ostream& o, const vector<T>& v) {o << "[";O__(o, v);o << "]";return o;}

template <class T, class V>
ostream& operator << (ostream& o, const map<T, V>& v) {o << "{";O__(o, v);o << "}"; return o;}

template <class T>
ostream& operator << (ostream& o, const set<T>& v) {o << "{";O__(o, v);o << "}";return o;}

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<vii> viii;

const double PI = 3.1415926535897932384626433832795;
const double EPS = 1e-9;
const int INF = std::numeric_limits<int>::max();
const long long LLINF = std::numeric_limits<ll>::max();

#if GCC_VERSION > 40900


template<class Key, class Value>
using MapWithOrderStatistics = tree<Key, Value,
      std::less<Key>, rb_tree_tag ,
      tree_order_statistics_node_update>;
#endif



#define REQUIRE(cond, text) do { \
    if (!(cond)) { \
        stringstream o; \
        o << text; \
        throw std::logic_error(o.str()); \
    } \
} while (0)






template<class Iterator>
class IteratorRange {
public:
    IteratorRange(Iterator begin, Iterator end):
        begin_(begin), end_(end) {}

    Iterator begin() const {
        return begin_;
    }
    Iterator end() const {
        return end_;
    }
private:
    Iterator begin_, end_;
};






class Visitor {
public:
    virtual void discoverVertex(size_t ) {}
    virtual void examineVertex(size_t ) {}
    virtual void finishVertex(size_t ) {}
    virtual ~Visitor() {}
};

template<class F>
class OnDiscoverVertex_: public Visitor {
public:
    explicit OnDiscoverVertex_(F f):
        f_(f) {
    }
    void discoverVertex(size_t vertex) override {
        f_(vertex);
    }
private:
    F f_;
};

template<class F>
OnDiscoverVertex_<F> onDiscoverVertex(F f) {
    return OnDiscoverVertex_<F>(f);
}

template<class Graph, class Visitor>
void depthFirstSearch(size_t vertex, const Graph& graph, std::vector<bool>& used, Visitor visitor) {
    if (used[vertex])
        return;
    visitor.discoverVertex(vertex);
    used[vertex] = true;
    for (const auto& edge: graph.outgoingEdges(vertex)) {
        visitor.examineVertex(target(edge));
        depthFirstSearch(target(edge), graph, used, visitor);
    }
    visitor.finishVertex(vertex);
}





size_t UNDEFINED_VERTEX = static_cast<size_t>(-1);

struct SimpleEdge {
    SimpleEdge(size_t source, size_t target):
        source(source), target(target) {
    }

    SimpleEdge():
        source(UNDEFINED_VERTEX),
        target(UNDEFINED_VERTEX) {
    }
    size_t source;
    size_t target;
};

template<class W = long long>
struct Edge{
    typedef W WeightType;

    Edge(size_t source, size_t target, W weight):
        source(source), target(target), weight(weight) {
    }

    Edge():
        source(UNDEFINED_VERTEX),
        target(UNDEFINED_VERTEX) {
    }

    size_t source;
    size_t target;
    W weight;
};

template<class E>
size_t source(const E& edge) {
    return edge.source;
}

template<class E>
size_t target(const E& edge) {
    return edge.target;
}

template<class E>
typename E::WeightType weight(const E& edge) {
    return edge.weight;
}






template<class EdgeType_>
class MutableForest {
public:
    typedef EdgeType_ EdgeType;
    typedef typename std::list<EdgeType>::const_iterator EdgeIterator;

    explicit MutableForest(size_t vertices):
            adjacentEdges_(vertices),
            position_(vertices),
            parent_(vertices, UNDEFINED_VERTEX) {
    }

    size_t numberOfVertices() const {
        return adjacentEdges_.size();
    }

    IteratorRange<EdgeIterator> outgoingEdges(size_t vertex) const {
        return IteratorRange<EdgeIterator>(
                adjacentEdges_[vertex].begin(),
                adjacentEdges_[vertex].end());
    }

    void addEdge(const EdgeType& edge) {
        REQUIRE(parent_[target(edge)] == UNDEFINED_VERTEX,
            "Edge " << source(edge) << "->" << target(edge) <<
            " can not be added, " << target(edge) << " has already " <<
            " parent " << parent_[target(edge)]);
        parent_[target(edge)] = source(edge);
        position_[target(edge)] = adjacentEdges_[source(edge)].insert(
            adjacentEdges_[source(edge)].begin(), edge);
    }

    size_t parent(size_t vertex) const {
        return parent_[vertex];
    }

    void cutSubtree(size_t vertex) {
        REQUIRE(parent_[vertex] != UNDEFINED_VERTEX,
            "Vertex " << vertex << " can not be cut, it has no parent");
        adjacentEdges_[parent_[vertex]].erase(position_[vertex]);
        parent_[vertex] = UNDEFINED_VERTEX;
    }

private:
    std::vector<std::list<EdgeType>> adjacentEdges_;
    std::vector<typename std::list<EdgeType>::iterator > position_;
    std::vector<size_t> parent_;
};






template<class EdgeType_>
class SingleSourceShortestPathInfoBuilder;

template<class EdgeType_>
class SingleSourceShortestPathInfo {
public:
    typedef EdgeType_ EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    size_t source() const {
        return source_;
    }

    WeightType distanceTo(size_t target) const {
        return distances_[target];
    }

    bool isReachable(size_t target) const {
        return distances_[target] != std::numeric_limits<WeightType>::max();
    }

    bool isShortestPathTo(size_t target) const {
        return distances_[target] != -std::numeric_limits<WeightType>::max();
    }

    std::vector<EdgeType> pathTo(size_t target) const {
        size_t vertex = target;
        std::vector<EdgeType> path;
        while(vertex != source_) {
            size_t p = ::source(previousEdge_[vertex]);
            REQUIRE(p != UNDEFINED_VERTEX,
                    "There is no path from " << source_ << " to"
                    " " << target);
            path.push_back(previousEdge_[vertex]);
            vertex = p;
        }
        reverse(all(path));
        return path;
    }
private:

    SingleSourceShortestPathInfo(size_t source,
            std::vector<EdgeType> prevEdge,
            std::vector<WeightType> distances):
        source_(source),
        previousEdge_(prevEdge),
        distances_(distances) {
    }

    size_t source_;
    std::vector<EdgeType> previousEdge_;
    std::vector<WeightType> distances_;
    friend SingleSourceShortestPathInfoBuilder<EdgeType>;
};

template<class EdgeType_>
class SingleSourceShortestPathInfoBuilder {
public:
    typedef EdgeType_ EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    SingleSourceShortestPathInfoBuilder(size_t vertices, size_t source):
            distances_(vertices, Infinity),
            previousEdge_(vertices),
            source_(source) {
        distances_[source] = WeightType(0);
    }

    

    template<class Callback>
    void relax(const EdgeType& e, Callback onRelax) {
        if (distances_[e.source] + weight(e) < distances_[e.target]) {
            WeightType oldDist = distances_[e.target];
            distances_[e.target] = distances_[e.source] + weight(e);
            onRelax(oldDist, distances_[e.target]);
            previousEdge_[e.target] = e;
        }
    }

    SingleSourceShortestPathInfo<EdgeType> build() const {
        return SingleSourceShortestPathInfo<EdgeType>(
                source_,
                previousEdge_,
                distances_);
    }

    void thereIsNoShortestPathTo(size_t vertex) {
        distances_[vertex] = -Infinity;
    }

    const std::vector<WeightType>& distances() const {
        return distances_;
    }

    const std::vector<WeightType>& previousEdges() const {
        return previousEdge_;
    }

private:
    static const WeightType Infinity =
        std::numeric_limits<WeightType>::max();

    std::vector<WeightType> distances_;
    std::vector<EdgeType> previousEdge_;
    size_t source_;
};






template<class EdgeType_>
class DirectedGraph {
public:
    typedef EdgeType_ EdgeType;
    typedef typename std::vector<EdgeType>::const_iterator EdgeItarator;

    explicit DirectedGraph(size_t verticesNumber):
        adjacentEdges_(verticesNumber) {
    }

    size_t verticesNumber() const {
        return adjacentEdges_.size();
    }

    void addEdge(const EdgeType& edge) {
        REQUIRE(source(edge) < adjacentEdges_.size(), "Source of edge (" <<
                source(edge) << ") should lie in [0, " << adjacentEdges_.size() <<
                ")");
        adjacentEdges_[source(edge)].push_back(edge);
    }

    IteratorRange<EdgeItarator> outgoingEdges(size_t vertex) const {
        return IteratorRange<EdgeItarator>(
                adjacentEdges_[vertex].begin(),
                adjacentEdges_[vertex].end());
    }

private:
    std::vector<std::vector<EdgeType>> adjacentEdges_;
};



template<class Graph>
SingleSourceShortestPathInfo<typename Graph::EdgeType> dijkstra(
        size_t source, const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    SingleSourceShortestPathInfoBuilder<EdgeType> builder(graph.verticesNumber(),
            source);

    std::set<std::pair<WeightType, size_t>> verticesToProces;
    verticesToProces.insert({WeightType(0), source});

    while(!verticesToProces.empty()) {
        size_t v = verticesToProces.begin()->second;
        verticesToProces.erase(verticesToProces.begin());
        for (const auto& edge: graph.outgoingEdges(v)) {
            REQUIRE(weight(edge) >= WeightType(0),
                "All edges weights should be nonnegative");

            builder.relax(edge, [&] (WeightType oldDist, WeightType newDist) {
                verticesToProces.erase({oldDist, edge.target});
                verticesToProces.insert({newDist, edge.target});
            });
        }
    }
    return builder.build();
}






template<class Graph>
SingleSourceShortestPathInfo<typename Graph::EdgeType> fordBellman(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    SingleSourceShortestPathInfoBuilder<EdgeType> builder(vertices,
            source);
    std::queue<size_t> verticesToProces;
    std::vector<size_t> insertionsInQueue(vertices);
    std::vector<bool> inQueue(vertices);

    auto push = [&](size_t v) {
        if (inQueue[v]) return;
        if (insertionsInQueue[v] == 1 + vertices) return;
        ++insertionsInQueue[v];
        inQueue[v] = true;
        verticesToProces.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = verticesToProces.front();
        verticesToProces.pop();
        inQueue[r] = false;
        return r;
    };

    push(source);

    while(!verticesToProces.empty()) {
        size_t v = pop();
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (insertionsInQueue[v] > vertices) {
            depthFirstSearch(v, graph, used, onDiscoverVertex([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}






template<class Graph>
SingleSourceShortestPathInfo<typename Graph::EdgeType> tarjan(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    SingleSourceShortestPathInfoBuilder<EdgeType> builder(vertices,
            source);
    std::queue<size_t> verticesToProces;
    std::vector<size_t> insertionsInQueue(vertices);
    std::vector<bool> inQueue(vertices);

    vector<std::list<int>::iterator> where(vertices);
    vector<std::list<int>> childs(vertices);
    vector<bool> skip(vertices);

    auto push = [&](size_t v) {
        skip[v] = false;
        if (inQueue[v]) return;
        if (insertionsInQueue[v] == 1 + vertices) return;
        ++insertionsInQueue[v];
        inQueue[v] = true;
        verticesToProces.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = verticesToProces.front();
        verticesToProces.pop();
        inQueue[r] = false;
        return r;
    };

    MutableForest<SimpleEdge> prevLinksForest(vertices);

    push(source);
    while(!verticesToProces.empty()) {
        size_t v = pop();
        if (skip[v])
            continue;
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                depthFirstSearch(::source(e),
                    prevLinksForest, skip, onDiscoverVertex(
                    [&](size_t vertex) {
                        skip[vertex] = true;
                }));
                if (prevLinksForest.parent(target(e)) != UNDEFINED_VERTEX) {
                    prevLinksForest.cutSubtree(target(e));
                }
                if (prevLinksForest.parent(::target(e)) == UNDEFINED_VERTEX) {
                    prevLinksForest.addEdge(SimpleEdge(::source(e), target(e)));
                }
                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (insertionsInQueue[v] > vertices) {
            depthFirstSearch(v, graph, used, onDiscoverVertex([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}




int dijkstraSubmit() {
    

    

    std::ios_base::sync_with_stdio(false);
    freopen("dijkstra.in", "r", stdin);
    freopen("dijkstra.out", "w", stdout);
    int n;
    cin >> n;
    DirectedGraph<Edge<ll>> graph(n);
    int s, t;
    cin >> s >> t;
    --s;--t;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x;
            if (x >= 0)
                graph.addEdge(Edge<ll>(i, j, x));
        }
    }

    auto info = dijkstra(s, graph);
    ll x = info.distanceTo(t);
    if (x == std::numeric_limits<ll>::max())
        x = -1;
    cout << x << "\n";
    return 0;
}

int dijkstraSubmit2() {
    

    

    std::ios_base::sync_with_stdio(false);
    freopen("distance.in", "r", stdin);
    freopen("distance.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    DirectedGraph<Edge<ll>> graph(n);
    int s, t;
    cin >> s >> t;
    --s;--t;
    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        graph.addEdge(Edge<ll>(x,y,z));
        graph.addEdge(Edge<ll>(y,x,z));
    }
    auto info = dijkstra(s, graph);
    if (info.isReachable(t)) {
        auto path = info.pathTo(t);
        cout << info.distanceTo(t)<< "\n";
        cout << s + 1 << " ";
        for (const auto& e: path) {
            cout << e.target + 1 << " ";
        }
    } else {
        cout << -1 << "\n";
    }
    return 0;
}

int fordBellmanSubmit() {
    

    

    std::ios_base::sync_with_stdio(false);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    DirectedGraph<Edge<ll>> graph(n);
    size_t s;
    cin >> s;
    --s;

    for (int i = 0; i < m; ++i) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        --x;
        --y;
        graph.addEdge(Edge<ll>(x,y,z));
    }
    auto info = fordBellman(s, graph);
    for (size_t i = 0; i < n; ++i) {
        if (info.isReachable(i)) {
            if (info.isShortestPathTo(i)) {
                cout << info.distanceTo(i) << "\n";
            } else {
                cout << "-\n";
            }
        } else {
            cout << "*\n";
        }
    }
    return 0;
}

int tarjanSubmit() {
    

    

    std::ios_base::sync_with_stdio(false);
    freopen("path.in", "r", stdin);
    freopen("path.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    DirectedGraph<Edge<ll>> graph(n);
    size_t s;
    cin >> s;
    --s;

    for (int i = 0; i < m; ++i) {
        int x, y;
        ll z;
        cin >> x >> y >> z;
        --x;
        --y;
        graph.addEdge(Edge<ll>(x,y,z));
    }
    auto info = tarjan(s, graph);
    for (size_t i = 0; i < n; ++i) {
        if (info.isReachable(i)) {
            if (info.isShortestPathTo(i)) {
                cout << info.distanceTo(i) << "\n";
            } else {
                cout << "-\n";
            }
        } else {
            cout << "*\n";
        }
    }
    return 0;
}

int anyShortestPathSubmit() {
    

    std::ios_base::sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    DirectedGraph<Edge<ll>> graph(n);

    for (int i = 0; i < m; ++i) {
        int x, y, z;
        cin >> x >> y >> z;
        --x;
        --y;
        graph.addEdge(Edge<ll>(x,y,z));
        graph.addEdge(Edge<ll>(y,x,z));
    }
    auto info = dijkstra(0, graph);
    size_t t = n - 1;
    if (info.isReachable(t)) {
        auto path = info.pathTo(t);
        cout << 1 << " ";
        for (const auto& e: path) {
            cout << e.target + 1 << " ";
        }
    } else {
        cout << -1 << "\n";
    }
    return 0;
}

int main() {
    return anyShortestPathSubmit();
}

