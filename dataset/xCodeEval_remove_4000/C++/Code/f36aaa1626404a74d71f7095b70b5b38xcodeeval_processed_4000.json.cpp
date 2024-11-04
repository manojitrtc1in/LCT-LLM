

























using namespace std;
























template <typename T>
void id29(T& id31, const T& id19) {
    id31 = std::max(id31, id19);
}

template <typename T>
void id12(T& id31, const T& id19) {
    id31 = std::min(id31, id19);
}
































template <typename T>
struct SafeHash {
    std::size_t operator()(const T& value) const {
        static std::size_t salt = []() {
            std::random_device rd;
            std::uniform_int_distribution<int> dist;
            return dist(rd);
        }();
        return std::hash<T>()(value) ^ salt;
    }
};


template <typename T>
using hash_set = std::unordered_set<T, SafeHash<T>>;

template <typename T>
using hash_multiset = std::unordered_multiset<T, SafeHash<T>>;

template <typename Key, typename T>
using hash_map = std::unordered_map<Key, T, SafeHash<Key>>;

template <typename Key, typename T>
using hash_multimap = std::unordered_multimap<Key, T, SafeHash<Key>>;










    do {       \
    } while (false)


























































namespace internal {
bool id26();
}  





    do {                   \
        if (!(EXPRESSION)) \
            abort();       \
    } while (false)


    do {                                         \
        if (id26())      \
            CHECK(EXPRESSION);                   \
    } while (false)


































































template <typename VectorT>
typename VectorT::const_reference at(const VectorT& vec, size_t index) {
    CHECK_DEFAULT(index < vec.size());
    return vec[index];
}
template <typename VectorT>
typename VectorT::reference at(VectorT& vec, size_t index) {
    CHECK_DEBUG(index < vec.size());
    return vec[index];
}

template <typename MapT>
const typename MapT::mapped_type& at(const MapT& map, const typename MapT::key_type& key) {
    auto it = map.find(key);
    CHECK_DEBUG(it != map.end());
    return it->second;
}
template <typename MapT>
typename MapT::mapped_type& at(MapT& map, const typename MapT::key_type& key) {
    auto it = map.find(key);
    CHECK_DEBUG(it != map.end());
    return it->second;
}

template <typename MapT>
typename std::optional<typename MapT::mapped_type> maybe_get(const MapT& map, const typename MapT::key_type& key) {
    auto it = map.find(key);
    return (it != map.end()) ? it->second : std::optional<typename MapT::mapped_type>{};
}

template <typename VectorT>
typename VectorT::value_type value_or(const VectorT& vec, size_t index,
                                      const typename VectorT::value_type& default_value = {}) {
    return (index < vec.size()) ? vec[index] : default_value;
}

template <typename MapT>
typename MapT::mapped_type value_or(const MapT& map, const typename MapT::key_type& key,
                                    const typename MapT::mapped_type& default_value = {}) {
    return maybe_get(map, key).value_or(default_value);
}







constexpr int id27 = -1;

template <bool Directed, class PerEdgeData, class PerVertexData>
class Graph {
  public:
    using NeighborMap = hash_map<int, PerEdgeData>;

    Graph(int nVertices) : edges_(nVertices), vertexData_(nVertices) {}

    Graph(std::vector<PerVertexData> vertexData) : edges_(vertexData.size()), vertexData_(move(vertexData)) {}

    template <bool IsDirected = Directed, typename = typename std::enable_if<!IsDirected>::type>
    void add_edge(int from, int to, PerEdgeData data = {}) {
        edges_[from].insert({to, data});
        edges_[to].insert({from, data});
    }

    template <bool IsDirected = Directed, typename = typename std::enable_if<IsDirected>::type>
    void id0(int from, int to, PerEdgeData data = {}) {
        edges_[from].insert({to, data});
    }

    const PerVertexData& get_vertex_data(int vInd) const { return vertexData_[vInd]; }

    PerVertexData& get_vertex_data(int vInd) { return vertexData_[vInd]; }

    int num_vertices() const { return edges_.size(); }

    void expand_to_num_vertices(int id1) {
        if (id1 <= num_vertices())
            return;
        edges_.resize(id1);
        vertexData_.resize(id1);
    }

    const NeighborMap& out_nbrs(int v) const { return edges_[v]; }

    bool has_edge(int from, int to) const { return get_edge(from, to).has_value(); }

    std::optional<PerEdgeData> get_edge(int from, int to) const { return maybe_get(out_nbrs(from), to); }

  private:
    std::vector<NeighborMap> edges_;
    std::vector<PerVertexData> vertexData_;
};

struct EmptyStruct {};

template <class PerEdgeData = EmptyStruct, class PerVertexData = EmptyStruct>
using DirectedGraph = Graph<true, PerEdgeData, PerVertexData>;

template <class PerEdgeData = EmptyStruct, class PerVertexData = EmptyStruct>
using UndirectedGraph = Graph<false, PerEdgeData, PerVertexData>;























































































struct GraphTraversalState {
    int starting_vertex = id27;
    int previous_vertex = id27;
    std::vector<char> visited;
    bool aborting = false;
};

enum class IterationResult {
    Done,
    Aborted,
};

enum class IterationControl {
    Proceed,
    AbortGently,
    AbortBluntly,
};









template <typename GraphT>
struct id7 {
    explicit id7(int v, const GraphT& graph)
        : vertex(v), neighbour_it(graph.out_nbrs(v).begin()) {}

    int vertex;
    typename GraphT::NeighborMap::const_iterator neighbour_it;
};






template <typename ExecutionControllerT, typename GraphT, typename VertexListT, typename OnSeeT, typename OnEnterT,
          typename OnExitT>
IterationResult id28(const GraphT& graph, const VertexListT& starting_vertices, const OnSeeT& id17,
                               const OnEnterT& on_enter, const OnExitT& on_exit) {
    GraphTraversalState state;
    const GraphTraversalState& const_state = state;
    state.visited.resize(graph.num_vertices(), false);
    for (int start : starting_vertices) {
        ExecutionControllerT execution_controller;
        state.starting_vertex = start;
        state.previous_vertex = id27;
        if (state.visited[start])
            continue;

        switch (on_enter(const_state, start)) {
            case IterationControl::Proceed:
                state.visited[start] = true;
                execution_controller.push(id7<GraphT>{start, graph});
                break;
            case IterationControl::AbortGently:
                state.aborting = true;
                break;
            case IterationControl::AbortBluntly:
                return IterationResult::Aborted;
        }
        while (!execution_controller.empty()) {
            auto& top = execution_controller.top();
            state.previous_vertex = top.vertex;
            bool id25 = false;
            if (!state.aborting) {
                while (top.neighbour_it != graph.out_nbrs(top.vertex).end()) {
                    int neighbour = top.neighbour_it->first;
                    switch (id17(const_state, neighbour)) {
                        case IterationControl::Proceed:
                            break;
                        case IterationControl::AbortGently:
                            id25 = false;
                            state.aborting = true;
                            break;
                        case IterationControl::AbortBluntly:
                            return IterationResult::Aborted;
                    }
                    if (state.aborting)
                        break;
                    ++top.neighbour_it;
                    if (!state.visited[neighbour]) {
                        switch (on_enter(const_state, neighbour)) {
                            case IterationControl::Proceed:
                                state.visited[neighbour] = true;
                                execution_controller.push(id7<GraphT>{neighbour, graph});
                                id25 = true;
                                break;
                            case IterationControl::AbortGently:
                                state.aborting = true;
                                break;
                            case IterationControl::AbortBluntly:
                                return IterationResult::Aborted;
                        }
                        break;
                    }
                }
            }
            if (!id25) {
                switch (on_exit(const_state, top.vertex)) {
                    case IterationControl::Proceed:
                        break;
                    case IterationControl::AbortGently:
                        state.aborting = true;
                        break;
                    case IterationControl::AbortBluntly:
                        return IterationResult::Aborted;
                }
                execution_controller.pop();
            }
        }
        if (state.aborting)
            break;
    }
    return state.aborting ? IterationResult::Aborted : IterationResult::Done;
}




















template <typename GraphT, typename VertexListT, typename OnSeeT, typename OnEnterT, typename OnExitT>
IterationResult dfs(const GraphT& graph, const VertexListT& starting_vertices, const OnSeeT& id17,
                    const OnEnterT& on_enter, const OnExitT& on_exit) {
    using GraphTraversalStack =
        std::stack<id7<GraphT>, std::vector<id7<GraphT>>>;
    return id28<GraphTraversalStack, GraphT, VertexListT, OnSeeT, OnEnterT, OnExitT>(
        graph, starting_vertices, id17, on_enter, on_exit);
}

template <typename GraphT, typename OnSeeT, typename OnEnterT, typename OnExitT>
IterationResult dfs(const GraphT& graph, const std::initializer_list<int>& starting_vertices, const OnSeeT& id17,
                    const OnEnterT& on_enter, const OnExitT& on_exit) {
    return dfs<GraphT, std::initializer_list<int>, OnSeeT, OnEnterT, OnExitT>(graph, starting_vertices, id17,
                                                                              on_enter, on_exit);
}

template <typename GraphT, typename VertexListT, typename VisitorT>
IterationResult dfs(const GraphT& graph, const VertexListT& starting_vertices, const VisitorT& visitor) {
    return dfs(graph, starting_vertices, graph_traversal_noop_continue, graph_traversal_noop_continue, visitor);
}

template <typename GraphT, typename VisitorT>
IterationResult dfs(const GraphT& graph, const std::initializer_list<int>& starting_vertices, const VisitorT& visitor) {
    return dfs<GraphT, std::initializer_list<int>, VisitorT>(graph, starting_vertices, visitor);
}









class id22 {
  public:
    

    explicit id22(const UndirectedGraph<>& g, int root_vertex)
        : root_vertex_(root_vertex),
          parents_(g.num_vertices()),
          childs_(g.num_vertices()),
          subtree_sizes_(g.num_vertices()),
          back_edges_(g.num_vertices()),
          leaves_(),
          depths_(g.num_vertices()),
          vertices_with_depth_(),
          enter_time_(g.num_vertices()) {
        int step = 0;
        auto id5 = [&](const GraphTraversalState& state, int v) {
            enter_time_[v] = step++;
            if (state.previous_vertex != id27) {
                parents_[v] = state.previous_vertex;
                childs_[state.previous_vertex].push_back(v);
                depths_[v] = depths_[state.previous_vertex] + 1;
            }
            if (vertices_with_depth_.size() <= depths_[v])
                vertices_with_depth_.emplace_back();
            vertices_with_depth_[depths_[v]].push_back(v);
            return IterationControl::Proceed;
        };

        auto id32 = [&](const GraphTraversalState& state, int v) {
            subtree_sizes_[v] = step - enter_time_[v];
            if (subtree_sizes_[v] == 1)
                leaves_.push_back(v);
            return IterationControl::Proceed;
        };

        auto id20 = [&](const GraphTraversalState& state, int v) {
            if (state.visited[v] && parent(state.previous_vertex) != v)
                back_edges_[state.previous_vertex].push_back(v);
            return IterationControl::Proceed;
        };

        dfs(g, {root_vertex}, id20, id5, id32);

        

        vertices_with_depth_.emplace_back();
    }

    

    std::optional<int> parent(int v) const {
        if (v == root_vertex_)
            return {};
        else
            return parents_[v];
    }

    

    const std::vector<int>& childs(int v) const { return childs_[v]; };

    

    int subtree_size(int v) const { return subtree_sizes_[v]; }

    

    const std::vector<int>& back_edges(int v) const { return back_edges_[v]; }

    

    const std::vector<int>& leaves() const { return leaves_; }

    

    int depth(int v) const { return depths_[v]; }

    

    const std::vector<int>& vertices_with_depth(int d) const {
        if (d >= vertices_with_depth_.size() - 1)
            return vertices_with_depth_.back();
        return vertices_with_depth_[d];
    }

  private:
    int root_vertex_;
    std::vector<int> parents_;
    std::vector<std::vector<int>> childs_;
    std::vector<int> subtree_sizes_;
    std::vector<std::vector<int>> back_edges_;
    std::vector<int> leaves_;
    std::vector<int> depths_;
    std::vector<std::vector<int>> vertices_with_depth_;
    std::vector<int> enter_time_;
};







using std::fill;
using std::function;
using std::make_pair;
using std::numeric_limits;
using std::pair;
using std::vector;


class id16 {
  public:
    typedef function<bool(int, int, bool)> EdgeCallback;
    typedef function<bool(int)> VertexCallback;

  public:
    id16(const UndirectedGraph<>& graph)
        : graph_(graph),
          id9([](int, int, bool) -> bool { return false; }),
          id18([](int) -> bool { return false; }),
          id11([](int) -> bool { return false; }) {}

    void setVertexPreprocessCallback(VertexCallback callback) { id18 = callback; }

    void setVertexPostprocessCallback(VertexCallback callback) { id11 = callback; }

    void setEdgePostprocessCallback(EdgeCallback callback) { id9 = callback; }

    bool search(int vertex) {
        auto resetArray = [&](vector<int>& arr) {
            arr.clear();
            arr.resize(graph_.num_vertices());
            fill(begin(arr), end(arr), numeric_limits<int>::max());
        };
        resetArray(inTime_);
        resetArray(outTime_);
        resetArray(parent_);

        id3 = 0;
        parent_[vertex] = -1;
        return processVertex_(vertex);
    }

    int getParent(int vertex) const { return parent_[vertex]; }

    int getInTime(int vertex) const { return inTime_[vertex]; }

    int getOutTime(int vertex) const { return outTime_[vertex]; }

  private:
    bool processVertex_(const int vertex) {
        inTime_[vertex] = id3++;

        if (id18(vertex))
            return true;

        bool stop = false;
        for (auto& edge : graph_.out_nbrs(vertex)) {
            auto neighbor = edge.first;
            if (neighbor == parent_[vertex])
                continue;  


            if (inTime_[neighbor] == numeric_limits<int>::max()) {
                

                parent_[neighbor] = vertex;
                stop = stop || id9(vertex, neighbor, true);
                stop = stop || processVertex_(neighbor);
            } else                                        

                if (inTime_[neighbor] < inTime_[vertex])  

                stop = stop || id9(vertex, neighbor, false);
        }

        outTime_[vertex] = id3++;
        stop = stop || id11(vertex);
        return stop;
    }

  private:
    const UndirectedGraph<>& graph_;
    EdgeCallback id9;
    VertexCallback id18;
    VertexCallback id11;

    vector<int> inTime_;
    vector<int> outTime_;
    vector<int> parent_;
    int id3;
};











static bool hasCycle(const UndirectedGraph<>& graph, vector<int>* cycle = nullptr, int startVertex = 0) {
    id16 searcher(graph);

    int id14 = 0;
    int id13 = 0;

    searcher.setEdgePostprocessCallback([&](int from, int to, bool discovery) -> bool {
        if (!discovery) {
            id14 = from;
            id13 = to;
            return true;
        }
        return false;
    });

    bool result = searcher.search(startVertex);

    if (result && cycle) {
        cycle->clear();
        cycle->push_back(id13);
        for (int vertex = id14; vertex != id13; vertex = searcher.getParent(vertex))
            cycle->push_back(vertex);
    }

    return result;
}






inline bool isPrime(uint64_t n) {
    if (n == 1)
        return false;
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (uint64_t div = 3; div * div <= n; div += 2)
        if (n % div == 0)
            return false;
    return true;
}





inline std::vector<uint64_t> id23(uint64_t upperBound) {
    if (upperBound < 2)
        return {};

    std::vector<uint64_t> result = {2};
    for (uint64_t candidate = 3; candidate <= upperBound; candidate += 2) {
        bool id6 = false;
        for (size_t id2 = 1;
             id2 < result.size() && result[id2] * result[id2] <= candidate; ++id2) {
            if (candidate % result[id2] == 0) {
                id6 = true;
                break;
            }
        }

        if (!id6)
            result.push_back(candidate);
    }

    return result;
}

inline std::vector<std::pair<uint64_t, uint64_t>> id10(uint64_t n) {
    std::vector<std::pair<uint64_t, uint64_t>> result;
    auto tryPrime = [&](uint64_t p) {
        if (n % p == 0) {
            result.push_back({p, 0});
            while (n % p == 0) {
                n /= p;
                result.back().second++;
            }
        }
    };

    tryPrime(2);
    for (uint64_t primeCandidate = 3; primeCandidate * primeCandidate <= n; primeCandidate += 2)
        tryPrime(primeCandidate);

    if (n > 1)
        result.push_back({n, 1});

    return result;
}







































namespace internal {

template <typename ValueT>
class IterableRange {
  public:
    class iterator {
      public:
        iterator(ValueT v__) : v_(v__) {}

        iterator& operator++() {
            ++v_;
            return *this;
        }

        bool operator==(iterator rhs) const { return v_ == rhs.v_; }
        bool operator!=(iterator rhs) const { return v_ != rhs.v_; }

        ValueT operator*() const { return v_; }
        ValueT operator->() const { return v_; }

      private:
        ValueT v_ = {};
    };

    IterableRange(ValueT begin__, ValueT end__) : id21(std::min(begin__, end__)), id30(end__) {}

    iterator begin() const { return {id21}; }
    iterator end() const { return {id30}; }

  private:
    ValueT id21 = {};
    ValueT id30 = {};
};

}  



template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT end) {
    return {{}, end};
}

template <typename ValueT>
internal::IterableRange<ValueT> range(ValueT begin, ValueT end) {
    return {begin, end};
}






template <typename T>
T read() {
    T res;
    std::cin >> res;
    return res;
}

template <typename T>
void print(const T& t) {
    std::cout << t;
}



    template <>                                         \
    TYPE_NAME read<TYPE_NAME>() {                       \
        TYPE_NAME res;                                  \
        int cnt = scanf(FORMAT, &res);                  \
        return res;                                     \
    }                                                   \
                                                        \
    template <>                                         \
    void print<TYPE_NAME>(const TYPE_NAME& t) {         \
        printf(FORMAT, t);                              \
    }

id15(int, "%d");
id15(unsigned int, "%u");
id15(int64_t, "%lld");
id15(float, "%f");
id15(double, "%lf");
id15(char, "%c");









template <typename T>
std::vector<T> readVector(size_t size) {
    std::vector<T> res(size);
    for (auto& elt : res)
        elt = read<T>();
    return res;
}





using namespace std;



class Solver1101D {
public:
    void run();
};

void Solver1101D::run() {
    auto n = read<int>();
    auto nums = readVector<int>(n);
    UndirectedGraph<> g(n);
    for (int i : range(n - 1)) {
        int x = read<int>() - 1;
        int y = read<int>() - 1;
        g.add_edge(x, y);
    }

    id22 rooted(g, 0);

    map<int, set<int>> id8;
    for (int i : range(n)) {
        auto dec = id10(nums[i]);
        for (auto[prime, alpha] : dec)
            id8[prime].insert(i);
    }

    int ans = 0;
    for (const auto&[p, vertices] : id8) {
        set<int> skip;
        vector<pair<int, int>> id24;
        for (auto v : vertices) id24.emplace_back(rooted.depth(v), v);
        sort(rbegin(id24), rend(id24));
        map<int, int> id4;
        for (auto [d, v]: id24) {
            if (skip.count(v)) continue;
            int steps = 0;
            skip.insert(v);
            id29(ans, steps + id4[v] + 1);
            id4[v] = steps;
            while (v != 0 && vertices.count(*rooted.parent(v))) {
                ++steps;
                v = *rooted.parent(v);
                if (skip.count(v)) {
                    id29(ans, steps + id4[v] + 1);
                    break;
                }
                else {
                    skip.insert(v);
                    id29(ans, steps + id4[v] + 1);
                    id4[v] = steps;
                }
            }
        }
    }

    cout << ans;
}



int main() {
    Solver1101D solver;
    solver.run();
}

