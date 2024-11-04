

























using namespace __gnu_pbds;
using namespace std;










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




template<class Key, class Value>
using MapWithOrderStatistics = tree<Key, Value,
      std::less<Key>, rb_tree_tag ,
      tree_order_statistics_node_update>;


size_t G;




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
class id15: public Visitor {
public:
    explicit id15(F f):
        f_(f) {
    }
    void discoverVertex(size_t vertex) override {
        f_(vertex);
    }
private:
    F f_;
};

template<class F>
id15<F> id26(F f) {
    return id15<F>(f);
}

template<class Graph, class Visitor>
void id25(size_t vertex, const Graph& graph, std::vector<bool>& used, Visitor visitor) {
    if (used[vertex])
        return;
    visitor.discoverVertex(vertex);
    used[vertex] = true;
    for (const auto& edge: graph.outgoingEdges(vertex)) {
        visitor.examineVertex(target(edge));
        id25(target(edge), graph, used, visitor);
    }
    visitor.finishVertex(vertex);
}





size_t id20 = static_cast<size_t>(-1);

struct SimpleEdge {
    SimpleEdge(size_t source, size_t target):
        source(source), target(target) {
    }

    SimpleEdge():
        source(id20),
        target(id20) {
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
        source(id20),
        target(id20) {
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

class id11;
size_t source(const id11&);
size_t target(const id11&);







template<class EdgeType_>
class MutableForest {
public:
    typedef EdgeType_ EdgeType;
    typedef typename std::list<EdgeType>::const_iterator EdgeIterator;

    explicit MutableForest(size_t vertices):
            adjacentEdges_(vertices),
            position_(vertices),
            parent_(vertices, id20) {
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
        REQUIRE(parent_[target(edge)] == id20,
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
        REQUIRE(parent_[vertex] != id20,
            "Vertex " << vertex << " can not be cut, it has no parent");
        adjacentEdges_[parent_[vertex]].erase(position_[vertex]);
        parent_[vertex] = id20;
    }

private:
    std::vector<std::list<EdgeType>> adjacentEdges_;
    std::vector<typename std::list<EdgeType>::iterator > position_;
    std::vector<size_t> parent_;
};






template<class EdgeType_>
class id5;

template<class EdgeType_>
class id17 {
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
            REQUIRE(p != id20,
                    "There is no path from " << source_ << " to"
                    " " << target);
            path.push_back(previousEdge_[vertex]);
            vertex = p;
        }
        reverse(all(path));
        return path;
    }
private:

    id17(size_t source,
            std::vector<EdgeType> prevEdge,
            std::vector<WeightType> distances):
        source_(source),
        previousEdge_(prevEdge),
        distances_(distances) {
    }

    size_t source_;
    std::vector<EdgeType> previousEdge_;
    std::vector<WeightType> distances_;
    friend id5<EdgeType>;
};

template<class EdgeType_>
class id5 {
public:
    typedef EdgeType_ EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    id5(size_t vertices, size_t source):
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

    id17<EdgeType> build() const {
        return id17<EdgeType>(
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
id17<typename Graph::EdgeType> dijkstra(
        size_t source, const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    id5<EdgeType> builder(graph.verticesNumber(),
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
            size_t v = id20;
            for (size_t i = 0; i < graph.verticesNumber(); ++i) {
                if (alive[i] && (v == id20 || d[i] < d[v])) {
                    v = i;
                }
            }
            if (v == id20 || d[v] == LLINF) {
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
        std::set<std::pair<WeightType, size_t>> id12;
        id12.insert({WeightType(0), source});

        while(!id12.empty()) {
            size_t v = id12.begin()->second;
            id12.erase(id12.begin());
            for (const auto& edge: graph.outgoingEdges(v)) {
                REQUIRE(weight(edge) >= WeightType(0),
                    "All edges weights should be nonnegative");

                builder.relax(edge, [&] (WeightType oldDist, WeightType newDist) {
                    id12.erase({oldDist, target(edge)});
                    id12.insert({newDist, target(edge)});
                });
            }
        }
        return builder.build();
    }
}






template<class Graph>
id17<typename Graph::EdgeType> id13(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    id5<EdgeType> builder(vertices,
            source);
    std::queue<size_t> id12;
    std::vector<size_t> id9(vertices);
    std::vector<bool> inQueue(vertices);

    auto push = [&](size_t v) {
        if (inQueue[v]) return;
        if (id9[v] == 1 + vertices) return;
        ++id9[v];
        inQueue[v] = true;
        id12.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = id12.front();
        id12.pop();
        inQueue[r] = false;
        return r;
    };

    push(source);

    while(!id12.empty()) {
        size_t v = pop();
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (id9[v] > vertices) {
            id25(v, graph, used, id26([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}





template<class Graph>
id17<typename Graph::EdgeType> tarjan(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    id5<EdgeType> builder(vertices,
            source);
    std::queue<size_t> id12;
    std::vector<size_t> id9(vertices);
    std::vector<bool> inQueue(vertices);

    vector<std::list<int>::iterator> where(vertices);
    vector<std::list<int>> childs(vertices);
    vector<bool> skip(vertices);

    auto push = [&](size_t v) {
        skip[v] = false;
        if (inQueue[v]) return;
        if (id9[v] == 1 + vertices) return;
        ++id9[v];
        inQueue[v] = true;
        id12.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = id12.front();
        id12.pop();
        inQueue[r] = false;
        return r;
    };

    

    MutableForest<EdgeType> id21(vertices);

    push(source);
    while(!id12.empty()) {
        size_t v = pop();
        if (skip[v])
            continue;
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                id25(::target(e),
                    id21, skip, id26(
                    [&](size_t vertex) {
                        skip[vertex] = true;
                }));
                if (id21.parent(target(e)) != id20) {
                    id21.cutSubtree(target(e));
                }
                id21.addEdge(e);


                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (id9[v] > vertices) {
            id25(v, graph, used, id26([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}







struct id10 {
    id10():
        source(id20),
        target(id20),
        cost(0),
        capacity(0),
        flow(0) {
    }

    id10(size_t source, size_t target, long long cost, size_t capacity):
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



struct id11{
    typedef long long WeightType;

    id11():
        edge(nullptr),
        weight(0) {
    }

    id11(const id10* edge, long long weight):
        edge(edge), weight(weight) {
    }

    const id10* edge;
    long long weight;
};

size_t source(const id11& edge) {
    return edge.edge->source;
}

size_t target(const id11& edge) {
    return edge.edge->target;
}

class id2 {
public:
    explicit id2(size_t vertices):
        net_(vertices),
        id19(0),
        id6(0),
        source_(id20),
        sink_(id20) {
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
        net_[from].push_back(id10(from, to, cost, cap));
        net_[to].push_back(id10(to, from, -cost, 0));

        net_[from].back().backEdgeIndex = net_[to].size() - 1;
        net_[to].back().backEdgeIndex = net_[from].size() - 1;
    }

    template<class It>
    void pushFlow(It pathBegin,
            It pathEnd,
            size_t id1 = std::numeric_limits<size_t>::max()) {
        size_t add = id1;
        for (const auto& id7: IteratorRange<It>(pathBegin, pathEnd)) {
            add = std::min(add, getFlowEdge(id7).capacity);
        }
        REQUIRE(add > 0, "Path should has positive resitual capacity");
        for (auto& id7: IteratorRange<It>(pathBegin, pathEnd)) {
            id10& edge = getFlowEdge(id7);
            id10& revEdge = net_[edge.target][edge.backEdgeIndex];

            edge.capacity -= add;
            revEdge.capacity += add;

            edge.flow += add;
            revEdge.flow -= add;

            id6 += add * edge.cost;

            assert(edge.flow == -revEdge.flow);
        }
        id19 += add;
    }

    long long totalCost() const {
        return id6;
    }

    size_t totalFlow() const {
        return id19;
    }

    IteratorRange<std::vector<id10>::const_iterator> outgoingEdges(
            size_t vertex) const {
        return  IteratorRange<std::vector<id10>::const_iterator>(
            net_[vertex].begin(), net_[vertex].end());
    }

private:
    id10& getFlowEdge(const id11 edge) {
        return *const_cast<id10*>(edge.edge);
    }

    std::vector<std::vector<id10>> net_;
    size_t id19;
    long long id6;
    size_t source_;
    size_t sink_;
};

class ResidualNet {
public:
    typedef id11 EdgeType;

    explicit ResidualNet(const id2* costFlowNet):
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

    const std::vector<id11>& outgoingEdges(size_t vertex) const {
        if (!cache_valid_[vertex]) {
            std::vector<id11> &edges = cache_[vertex];
            edges.clear();
            size_t index = 0;
            for (const id10& edge: costFlowNet_->outgoingEdges(vertex)) {
                if (edge.capacity > 0) {
                    
                    edges.push_back(id11(
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
    void id14(Range additions) {
        auto it = potentials_.begin();
        std::transform(additions.begin(), additions.end(), it, it, std::plus<long long>());
    }

private:
    const id2* costFlowNet_;
    std::vector<long long> potentials_;
    mutable std::vector<std::vector<id11>> cache_;
    mutable std::vector<bool> cache_valid_;
};








id2 id8(id2 net,
        size_t id16 = std::numeric_limits<size_t>::max()) {
    ResidualNet id22(&net);
    debug(net.totalFlow());
    if (1) {
        auto info = tarjan(net.source(), id22);
        auto distances = info.distances();
        id22.id14(distances);
    }
    while(net.totalFlow() < id16) {
        debug(net.totalFlow());
        id22.up();
        auto info = dijkstra(net.source(), id22);
        if (!info.isReachable(net.sink())) {
            break;
        }
        auto path = info.pathTo(net.sink());
        net.pushFlow(path.begin(), path.end(), id16 - net.totalFlow());

        auto distances = info.distances();
        id22.id14(distances);
    }
    return net;
}



int id3() {
    

    

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

int id18() {
    

    

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

int id4() {
    

    

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
    auto info = id13(s, graph);
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

int id24() {
    

    

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

int id0() {
    

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

int id23() {
    std::ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<int> s(n);
    vector<int> t(n);
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> s[i] >> t[i] >> c[i];
    }
    
    id2 net(n + n + 2);
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
    net = id8(net, k);
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
    return id0();
    return id23();
}

