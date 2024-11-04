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

size_t G;



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
inline size_t source(const E& edge) {
    return edge.source;
}

template<class E>
inline size_t target(const E& edge) {
    return edge.target;
}

template<class E>
inline typename E::WeightType weight(const E& edge) {
    return edge.weight;
}

class ResidualNetEdge;
size_t source(const ResidualNetEdge&);
size_t target(const ResidualNetEdge&);







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

    IteratorRange<typename std::vector<WeightType>::const_iterator> distances() const {
        return IteratorRange<typename std::vector<WeightType>::const_iterator>(
                distances_.begin(), distances_.end());
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
        if (distances_[::source(e)] == Infinity)
            return;
        if (distances_[::source(e)] + weight(e) < distances_[target(e)]) {
            WeightType oldDist = distances_[target(e)];
            distances_[target(e)] = distances_[::source(e)] + weight(e);
            onRelax(oldDist, distances_[target(e)]);
            previousEdge_[target(e)] = e;
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

    size_t E = 0;
    size_t V = graph.verticesNumber();
    for (size_t v = 0; v < V; ++v) {
        auto edges = graph.outgoingEdges(v);
        E += std::distance(edges.begin(), edges.end());
    }

    if (0 && E / 5 >= V * V) {

        std::vector<long long> d(graph.verticesNumber(), LLINF);
        d[source] = 0;
        std::vector<bool> alive(source, true);

        while(true) {
            size_t v = UNDEFINED_VERTEX;
            for (size_t i = 0; i < graph.verticesNumber(); ++i) {
                if (alive[i] && (v == UNDEFINED_VERTEX || d[i] < d[v])) {
                    v = i;
                }
            }
            if (v == UNDEFINED_VERTEX || d[v] == LLINF) {
                break;
            }
            alive[v] = false;

            for (const auto& edge: graph.outgoingEdges(v)) {
                REQUIRE(weight(edge) >= WeightType(0),
                    "All edges weights should be nonnegative");

                builder.relax(edge, [&] (WeightType , WeightType newDist) {
                    d[target(edge)] = newDist;
                });
            }
        }
        return builder.build();
    } else {
        std::set<std::pair<WeightType, size_t>> verticesToProces;
        verticesToProces.insert({WeightType(0), source});

        while(!verticesToProces.empty()) {
            size_t v = verticesToProces.begin()->second;
            verticesToProces.erase(verticesToProces.begin());
            for (const auto& edge: graph.outgoingEdges(v)) {
                REQUIRE(weight(edge) >= WeightType(0),
                    "All edges weights should be nonnegative");

                builder.relax(edge, [&] (WeightType oldDist, WeightType newDist) {
                    verticesToProces.erase({oldDist, target(edge)});
                    verticesToProces.insert({newDist, target(edge)});
                });
            }
        }
        return builder.build();
    }
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
                depthFirstSearch(::target(e),
                    prevLinksForest, skip, onDiscoverVertex(
                    [&](size_t vertex) {
                        skip[vertex] = true;
                }));
                if (prevLinksForest.parent(target(e)) != UNDEFINED_VERTEX) {
                    prevLinksForest.cutSubtree(target(e));
                }
                

                    prevLinksForest.addEdge(SimpleEdge(::source(e), target(e)));
                

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







struct CostFlowNetEdge {
    CostFlowNetEdge():
        source(UNDEFINED_VERTEX),
        target(UNDEFINED_VERTEX),
        cost(0),
        capacity(0),
        flow(0) {
    }

    CostFlowNetEdge(size_t source, size_t target, long long cost, size_t capacity):
        source(source),
        target(target),
        cost(cost),
        capacity(capacity),
        flow(0) {
    }

    size_t source;
    size_t target;
    long long cost;
    size_t capacity;
    long long flow;
    size_t backEdgeIndex;
};



struct ResidualNetEdge{
    typedef long long WeightType;

    ResidualNetEdge():
        edge(nullptr),
        weight(0) {
    }

    ResidualNetEdge(const CostFlowNetEdge* edge, long long weight):
        edge(edge), weight(weight) {
    }

    const CostFlowNetEdge* edge;
    long long weight;
};

size_t source(const ResidualNetEdge& edge) {
    return edge.edge->source;
}

size_t target(const ResidualNetEdge& edge) {
    return edge.edge->target;
}

class CostFlowNet {
public:
    explicit CostFlowNet(size_t vertices):
        net_(vertices),
        totalFlow_(0),
        totalCost_(0),
        source_(UNDEFINED_VERTEX),
        sink_(UNDEFINED_VERTEX) {
    }

    size_t verticesNumber() const {
        return net_.size();
    }

    void setSource(size_t source) {
        source_ = source;
    }

    size_t source() const {
        return source_;
    }

    void setSink(size_t sink) {
        sink_ = sink;
    }

    size_t sink() const {
        return sink_;
    }

    void addEdge(size_t from, size_t to, size_t cap, long long cost) {
        net_[from].push_back(CostFlowNetEdge(from, to, cost, cap));
        net_[to].push_back(CostFlowNetEdge(to, from, -cost, 0));

        net_[from].back().backEdgeIndex = net_[to].size() - 1;
        net_[to].back().backEdgeIndex = net_[from].size() - 1;
    }

    template<class It>
    void pushFlow(It pathBegin,
            It pathEnd,
            size_t maxPushValue = std::numeric_limits<size_t>::max()) {
        size_t add = maxPushValue;
        for (const auto& residualEdge: IteratorRange<It>(pathBegin, pathEnd)) {
            add = std::min(add, getFlowEdge(residualEdge).capacity);
        }
        REQUIRE(add > 0, "Path should has positive resitual capacity");
        for (auto& residualEdge: IteratorRange<It>(pathBegin, pathEnd)) {
            CostFlowNetEdge& edge = getFlowEdge(residualEdge);
            CostFlowNetEdge& revEdge = net_[edge.target][edge.backEdgeIndex];

            edge.capacity -= add;
            revEdge.capacity += add;

            edge.flow += add;
            revEdge.flow -= add;

            totalCost_ += add * edge.cost;

            assert(edge.flow == -revEdge.flow);
        }
        totalFlow_ += add;
    }

    long long totalCost() const {
        return totalCost_;
    }

    size_t totalFlow() const {
        return totalFlow_;
    }

    IteratorRange<std::vector<CostFlowNetEdge>::const_iterator> outgoingEdges(
            size_t vertex) const {
        return  IteratorRange<std::vector<CostFlowNetEdge>::const_iterator>(
            net_[vertex].begin(), net_[vertex].end());
    }

private:
    CostFlowNetEdge& getFlowEdge(const ResidualNetEdge edge) {
        return *const_cast<CostFlowNetEdge*>(edge.edge);
    }

    std::vector<std::vector<CostFlowNetEdge>> net_;
    size_t totalFlow_;
    long long totalCost_;
    size_t source_;
    size_t sink_;
};

class ResidualNet {
public:
    typedef ResidualNetEdge EdgeType;

    explicit ResidualNet(const CostFlowNet* costFlowNet):
        costFlowNet_(costFlowNet),
        potentials_(costFlowNet->verticesNumber()) {
            cache_.resize(verticesNumber());
            up();
    }

    size_t verticesNumber() const {
        return costFlowNet_->verticesNumber();
    }

    void up() {
        cache_valid_.assign(verticesNumber(), false);
    }

    const std::vector<ResidualNetEdge>& outgoingEdges(size_t vertex) const {
        if (!cache_valid_[vertex]) {
            std::vector<ResidualNetEdge> &edges = cache_[vertex];
            edges.clear();
            size_t index = 0;
            for (const CostFlowNetEdge& edge: costFlowNet_->outgoingEdges(vertex)) {
                if (edge.capacity > 0) {
                    
                    edges.push_back(ResidualNetEdge(
                        &edge,
                        edge.cost + potentials_[edge.source] - potentials_[edge.target]));

                }
                ++index;
            }
            

            

        }
        cache_valid_[vertex] = 1;
        return cache_[vertex];

    }

    template<class Range>
    void updatePotentials(Range additions) {
        auto it = potentials_.begin();
        std::transform(additions.begin(), additions.end(), it, it, std::plus<long long>());
    }

private:
    const CostFlowNet* costFlowNet_;
    std::vector<long long> potentials_;
    mutable std::vector<std::vector<ResidualNetEdge>> cache_;
    mutable std::vector<bool> cache_valid_;
};








CostFlowNet findMinCostMaxFlow(CostFlowNet net,
        size_t maxFlowValue = std::numeric_limits<size_t>::max()) {
    ResidualNet residualNet(&net);
    debug(net.totalFlow());
    if (1) {
        auto info = tarjan(net.source(), residualNet);
        auto distances = info.distances();
        residualNet.updatePotentials(distances);
    }
    while(net.totalFlow() < maxFlowValue) {
        debug(net.totalFlow());
        residualNet.up();
        auto info = dijkstra(net.source(), residualNet);
        if (!info.isReachable(net.sink())) {
            break;
        }
        auto path = info.pathTo(net.sink());
        net.pushFlow(path.begin(), path.end(), maxFlowValue - net.totalFlow());

        auto distances = info.distances();
        residualNet.updatePotentials(distances);
    }
    return net;
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
    auto info = tarjan(0, graph);
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

int findMinCostMaxFlowSubmit() {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> t(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i] >> c[i];
    }
    
    CostFlowNet net(n + n + 2);
    net.setSource(2 * n);
    net.setSink(2 * n + 1);
    G = 2 * n + 1;
    for (int i = 0; i < n; ++i) {
        net.addEdge(net.source(), 2 * i, 1, 0);
        net.addEdge(i * 2, i * 2 + 1, 1, -c[i]);
        net.addEdge(2 * i + 1, net.sink(), 1, 0);

        for (int j = 0; j < n; ++j) {
            if (s[i] + t[i] <= s[j]) {
                net.addEdge(i * 2 + 1, j * 2, 1, 0);
            }
        }
    }
    net = findMinCostMaxFlow(net, k);
    for (int i = 0; i < n; ++i) {
        int ans = 0;
        for (const auto& edge: net.outgoingEdges(2 * i)) {
            if (edge.target == 2 * i + 1 && edge.flow == 1) {
                ans = 1;
            }
        }
        cout << ans << " ";
    }
    return 0;
}

int main() {
    return anyShortestPathSubmit();
    return findMinCostMaxFlowSubmit();
}

