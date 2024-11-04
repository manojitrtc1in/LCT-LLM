

























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
class id7: public Visitor {
public:
    explicit id7(F f):
        f_(f) {
    }
    void discoverVertex(size_t vertex) override {
        f_(vertex);
    }
private:
    F f_;
};

template<class F>
id7<F> id14(F f) {
    return id7<F>(f);
}

template<class Graph, class Visitor>
void id10(size_t vertex, const Graph& graph, std::vector<bool>& used, Visitor visitor) {
    if (used[vertex])
        return;
    visitor.discoverVertex(vertex);
    used[vertex] = true;
    for (const auto& edge: graph.outgoingEdges(vertex)) {
        visitor.examineVertex(target(edge));
        id10(target(edge), graph, used, visitor);
    }
    visitor.finishVertex(vertex);
}





size_t id4 = static_cast<size_t>(-1);

struct SimpleEdge {
    SimpleEdge(size_t source, size_t target):
        source(source), target(target) {
    }

    SimpleEdge():
        source(id4),
        target(id4) {
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
        source(id4),
        target(id4) {
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
            parent_(vertices, id4) {
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
        REQUIRE(parent_[target(edge)] == id4,
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
        REQUIRE(parent_[vertex] != id4,
            "Vertex " << vertex << " can not be cut, it has no parent");
        adjacentEdges_[parent_[vertex]].erase(position_[vertex]);
        parent_[vertex] = id4;
    }

private:
    std::vector<std::list<EdgeType>> adjacentEdges_;
    std::vector<typename std::list<EdgeType>::iterator > position_;
    std::vector<size_t> parent_;
};






template<class EdgeType_>
class id3;

template<class EdgeType_>
class id8 {
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
            REQUIRE(p != id4,
                    "There is no path from " << source_ << " to"
                    " " << target);
            path.push_back(previousEdge_[vertex]);
            vertex = p;
        }
        reverse(all(path));
        return path;
    }
private:

    id8(size_t source,
            std::vector<EdgeType> prevEdge,
            std::vector<WeightType> distances):
        source_(source),
        previousEdge_(prevEdge),
        distances_(distances) {
    }

    size_t source_;
    std::vector<EdgeType> previousEdge_;
    std::vector<WeightType> distances_;
    friend id3<EdgeType>;
};

template<class EdgeType_>
class id3 {
public:
    typedef EdgeType_ EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    id3(size_t vertices, size_t source):
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

    id8<EdgeType> build() const {
        return id8<EdgeType>(
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
id8<typename Graph::EdgeType> dijkstra(
        size_t source, const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;

    id3<EdgeType> builder(graph.verticesNumber(),
            source);

    std::set<std::pair<WeightType, size_t>> id11;
    id11.insert({WeightType(0), source});

    while(!id11.empty()) {
        size_t v = id11.begin()->second;
        id11.erase(id11.begin());
        for (const auto& edge: graph.outgoingEdges(v)) {
            REQUIRE(weight(edge) >= WeightType(0),
                "All edges weights should be nonnegative");

            builder.relax(edge, [&] (WeightType oldDist, WeightType newDist) {
                id11.erase({oldDist, edge.target});
                id11.insert({newDist, edge.target});
            });
        }
    }
    return builder.build();
}






template<class Graph>
id8<typename Graph::EdgeType> id1(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    id3<EdgeType> builder(vertices,
            source);
    std::queue<size_t> id11;
    std::vector<size_t> id6(vertices);
    std::vector<bool> inQueue(vertices);

    auto push = [&](size_t v) {
        if (inQueue[v]) return;
        if (id6[v] == 1 + vertices) return;
        ++id6[v];
        inQueue[v] = true;
        id11.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = id11.front();
        id11.pop();
        inQueue[r] = false;
        return r;
    };

    push(source);

    while(!id11.empty()) {
        size_t v = pop();
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (id6[v] > vertices) {
            id10(v, graph, used, id14([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}






template<class Graph>
id8<typename Graph::EdgeType> tarjan(
        size_t source,
        const Graph& graph) {
    typedef typename Graph::EdgeType EdgeType;
    typedef typename EdgeType::WeightType WeightType;
    size_t vertices = graph.verticesNumber();

    id3<EdgeType> builder(vertices,
            source);
    std::queue<size_t> id11;
    std::vector<size_t> id6(vertices);
    std::vector<bool> inQueue(vertices);

    vector<std::list<int>::iterator> where(vertices);
    vector<std::list<int>> childs(vertices);
    vector<bool> skip(vertices);

    auto push = [&](size_t v) {
        skip[v] = false;
        if (inQueue[v]) return;
        if (id6[v] == 1 + vertices) return;
        ++id6[v];
        inQueue[v] = true;
        id11.push(v);
    };
    auto pop = [&] ()->size_t {
        size_t r = id11.front();
        id11.pop();
        inQueue[r] = false;
        return r;
    };

    MutableForest<SimpleEdge> id2(vertices);

    push(source);
    while(!id11.empty()) {
        size_t v = pop();
        if (skip[v])
            continue;
        for (const EdgeType& e: graph.outgoingEdges(v)) {
            builder.relax(e, [&](WeightType, WeightType) {
                id10(::target(e),
                    id2, skip, id14(
                    [&](size_t vertex) {
                        skip[vertex] = true;
                }));
                if (id2.parent(target(e)) != id4) {
                    id2.cutSubtree(target(e));
                }
                if (id2.parent(::target(e)) == id4) {
                    id2.addEdge(SimpleEdge(::source(e), target(e)));
                }
                push(target(e));
            });
        }
    }

    std::vector<bool> used(vertices);
    for (size_t v = 0; v < vertices; ++v) {
        if (id6[v] > vertices) {
            id10(v, graph, used, id14([&](size_t v) {
                builder.thereIsNoShortestPathTo(v);
            }));
        }
    }
    return builder.build();
}




int id12() {
    

    

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

int id13() {
    

    

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

int id0() {
    

    

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
    auto info = id1(s, graph);
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

int id9() {
    

    

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

int id5() {
    

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

int main() {
    return id5();
}

