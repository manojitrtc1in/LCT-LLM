#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <list>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdint>
#include <functional>
#include <array>
#include <valarray>
#include <iomanip>
#include <cassert>
#include <memory>
#include <complex>
#include <regex>
#include <optional>

using namespace std;

#include <algorithm>
#include <cstdlib>
#include <functional>
#include <limits>
#include <map>
#include <optional>
#include <queue>
#include <random>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>








































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

    IterableRange(ValueT begin__, ValueT end__) : begin_value_(std::min(begin__, end__)), end_value_(end__) {}

    iterator begin() const { return {begin_value_}; }
    iterator end() const { return {end_value_}; }

  private:
    ValueT begin_value_ = {};
    ValueT end_value_ = {};
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







#define COMMA ,

#define NOOP() \
    do {       \
    } while (false)

#define STRINGIFY(x) #x
























































namespace internal {
bool library_tests__enable_checks();
}  




#define CHECK(EXPRESSION)  \
    do {                   \
        if (!(EXPRESSION)) \
            abort();       \
    } while (false)

#define INTERNAL_CHECK_CONDITIONALLY(EXPRESSION) \
    do {                                         \
        if (library_tests__enable_checks())      \
            CHECK(EXPRESSION);                   \
    } while (false)




#ifndef CHECK_LEVEL
#  if defined LIBRARY_TEST
#    define CHECK_LEVEL 3
#  elif defined LOCAL_PC
#    define CHECK_LEVEL 2
#  else
#    define CHECK_LEVEL 1
#  endif
#endif





#if CHECK_LEVEL == 0
#  define CHECK_DEFAULT(EXPRESSION)   NOOP()
#  define CHECK_DEBUG(EXPRESSION)     NOOP()
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 1
#  define CHECK_DEFAULT(EXPRESSION)   CHECK(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     NOOP()
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 2
#  define CHECK_DEFAULT(EXPRESSION)   CHECK(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     CHECK(EXPRESSION)
#  define CHECK_INTERNAL(EXPRESSION)  NOOP()
#elif CHECK_LEVEL == 3
#  define CHECK_DEFAULT(EXPRESSION)   INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#  define CHECK_DEBUG(EXPRESSION)     INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#  define CHECK_INTERNAL(EXPRESSION)  INTERNAL_CHECK_CONDITIONALLY(EXPRESSION)
#endif































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







constexpr int kInvalidGraphVertex = -1;

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
    void add_directed_edge(int from, int to, PerEdgeData data = {}) {
        edges_[from].insert({to, data});
    }

    const PerVertexData& get_vertex_data(int vInd) const { return vertexData_[vInd]; }

    PerVertexData& get_vertex_data(int vInd) { return vertexData_[vInd]; }

    int num_vertices() const { return edges_.size(); }

    void expand_to_num_vertices(int new_num_vertices) {
        if (new_num_vertices <= num_vertices())
            return;
        edges_.resize(new_num_vertices);
        vertexData_.resize(new_num_vertices);
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
    int starting_vertex = kInvalidGraphVertex;
    int previous_vertex = kInvalidGraphVertex;
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







#define graph_traversal_noop_continue [](const GraphTraversalState&, int) { return IterationControl::Proceed; }

template <typename GraphT>
struct GraphTraversalExecutionItem {
    explicit GraphTraversalExecutionItem(int v, const GraphT& graph)
        : vertex(v), neighbour_it(graph.out_nbrs(v).begin()) {}

    int vertex;
    typename GraphT::NeighborMap::const_iterator neighbour_it;
};






template <typename ExecutionControllerT, typename GraphT, typename VertexListT, typename OnSeeT, typename OnEnterT,
          typename OnExitT>
IterationResult traverse_graph(const GraphT& graph, const VertexListT& starting_vertices, const OnSeeT& on_see,
                               const OnEnterT& on_enter, const OnExitT& on_exit) {
    GraphTraversalState state;
    const GraphTraversalState& const_state = state;
    state.visited.resize(graph.num_vertices(), false);
    for (int start : starting_vertices) {
        ExecutionControllerT execution_controller;
        state.starting_vertex = start;
        state.previous_vertex = kInvalidGraphVertex;
        if (state.visited[start])
            continue;

        switch (on_enter(const_state, start)) {
            case IterationControl::Proceed:
                state.visited[start] = true;
                execution_controller.push(GraphTraversalExecutionItem<GraphT>{start, graph});
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
            bool we_need_to_go_deeper = false;
            if (!state.aborting) {
                while (top.neighbour_it != graph.out_nbrs(top.vertex).end()) {
                    int neighbour = top.neighbour_it->first;
                    switch (on_see(const_state, neighbour)) {
                        case IterationControl::Proceed:
                            break;
                        case IterationControl::AbortGently:
                            we_need_to_go_deeper = false;
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
                                execution_controller.push(GraphTraversalExecutionItem<GraphT>{neighbour, graph});
                                we_need_to_go_deeper = true;
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
            if (!we_need_to_go_deeper) {
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
IterationResult dfs(const GraphT& graph, const VertexListT& starting_vertices, const OnSeeT& on_see,
                    const OnEnterT& on_enter, const OnExitT& on_exit) {
    using GraphTraversalStack =
        std::stack<GraphTraversalExecutionItem<GraphT>, std::vector<GraphTraversalExecutionItem<GraphT>>>;
    return traverse_graph<GraphTraversalStack, GraphT, VertexListT, OnSeeT, OnEnterT, OnExitT>(
        graph, starting_vertices, on_see, on_enter, on_exit);
}

template <typename GraphT, typename OnSeeT, typename OnEnterT, typename OnExitT>
IterationResult dfs(const GraphT& graph, const std::initializer_list<int>& starting_vertices, const OnSeeT& on_see,
                    const OnEnterT& on_enter, const OnExitT& on_exit) {
    return dfs<GraphT, std::initializer_list<int>, OnSeeT, OnEnterT, OnExitT>(graph, starting_vertices, on_see,
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









class RootedGraph {
  public:
    

    explicit RootedGraph(const UndirectedGraph<>& g, int root_vertex)
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
        auto on_vertice_enter = [&](const GraphTraversalState& state, int v) {
            enter_time_[v] = step++;
            if (state.previous_vertex != kInvalidGraphVertex) {
                parents_[v] = state.previous_vertex;
                childs_[state.previous_vertex].push_back(v);
                depths_[v] = depths_[state.previous_vertex] + 1;
            }
            if (vertices_with_depth_.size() <= depths_[v])
                vertices_with_depth_.emplace_back();
            vertices_with_depth_[depths_[v]].push_back(v);
            return IterationControl::Proceed;
        };

        auto on_vertice_leave = [&](const GraphTraversalState& state, int v) {
            subtree_sizes_[v] = step - enter_time_[v];
            if (subtree_sizes_[v] == 1)
                leaves_.push_back(v);
            return IterationControl::Proceed;
        };

        auto on_vertice_see = [&](const GraphTraversalState& state, int v) {
            if (state.visited[v] && parent(state.previous_vertex) != v)
                back_edges_[state.previous_vertex].push_back(v);
            return IterationControl::Proceed;
        };

        dfs(g, {root_vertex}, on_vertice_see, on_vertice_enter, on_vertice_leave);

        

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


class DepthFirstSearcher {
  public:
    typedef function<bool(int, int, bool)> EdgeCallback;
    typedef function<bool(int)> VertexCallback;

  public:
    DepthFirstSearcher(const UndirectedGraph<>& graph)
        : graph_(graph),
          edgeProcessCallback_([](int, int, bool) -> bool { return false; }),
          vertexPreprocessCallback_([](int) -> bool { return false; }),
          vertexPostprocessCallback_([](int) -> bool { return false; }) {}

    void setVertexPreprocessCallback(VertexCallback callback) { vertexPreprocessCallback_ = callback; }

    void setVertexPostprocessCallback(VertexCallback callback) { vertexPostprocessCallback_ = callback; }

    void setEdgePostprocessCallback(EdgeCallback callback) { edgeProcessCallback_ = callback; }

    bool search(int vertex) {
        auto resetArray = [&](vector<int>& arr) {
            arr.clear();
            arr.resize(graph_.num_vertices());
            fill(begin(arr), end(arr), numeric_limits<int>::max());
        };
        resetArray(inTime_);
        resetArray(outTime_);
        resetArray(parent_);

        currProccessTime_ = 0;
        parent_[vertex] = -1;
        return processVertex_(vertex);
    }

    int getParent(int vertex) const { return parent_[vertex]; }

    int getInTime(int vertex) const { return inTime_[vertex]; }

    int getOutTime(int vertex) const { return outTime_[vertex]; }

  private:
    bool processVertex_(const int vertex) {
        inTime_[vertex] = currProccessTime_++;

        if (vertexPreprocessCallback_(vertex))
            return true;

        bool stop = false;
        for (auto& edge : graph_.out_nbrs(vertex)) {
            auto neighbor = edge.first;
            if (neighbor == parent_[vertex])
                continue;  


            if (inTime_[neighbor] == numeric_limits<int>::max()) {
                

                parent_[neighbor] = vertex;
                stop = stop || edgeProcessCallback_(vertex, neighbor, true);
                stop = stop || processVertex_(neighbor);
            } else                                        

                if (inTime_[neighbor] < inTime_[vertex])  

                stop = stop || edgeProcessCallback_(vertex, neighbor, false);
        }

        outTime_[vertex] = currProccessTime_++;
        stop = stop || vertexPostprocessCallback_(vertex);
        return stop;
    }

  private:
    const UndirectedGraph<>& graph_;
    EdgeCallback edgeProcessCallback_;
    VertexCallback vertexPreprocessCallback_;
    VertexCallback vertexPostprocessCallback_;

    vector<int> inTime_;
    vector<int> outTime_;
    vector<int> parent_;
    int currProccessTime_;
};











static bool hasCycle(const UndirectedGraph<>& graph, vector<int>* cycle = nullptr, int startVertex = 0) {
    DepthFirstSearcher searcher(graph);

    int backEdgeFrom = 0;
    int backEdgeTo = 0;

    searcher.setEdgePostprocessCallback([&](int from, int to, bool discovery) -> bool {
        if (!discovery) {
            backEdgeFrom = from;
            backEdgeTo = to;
            return true;
        }
        return false;
    });

    bool result = searcher.search(startVertex);

    if (result && cycle) {
        cycle->clear();
        cycle->push_back(backEdgeTo);
        for (int vertex = backEdgeFrom; vertex != backEdgeTo; vertex = searcher.getParent(vertex))
            cycle->push_back(vertex);
    }

    return result;
}








class Solver580C
{
public:
    void run();
};

void Solver580C::run()
{
    size_t nVertices, maxCatsAllowed;
    cin >> nVertices >> maxCatsAllowed;

    vector<int> hasCat(nVertices);
    for (auto& h : hasCat)
        cin >> h;

    UndirectedGraph<> g(nVertices);
    for (size_t i = 0; i < nVertices - 1; ++i)
    {
        size_t a, b;
        cin >> a >> b;
        g.add_edge(a - 1, b - 1);
    }

    RootedGraph rooted(g, 0);

    int currentCats = 0;
    vector<size_t> nCatsInARow(nVertices);

    for (int depth = 0; rooted.vertices_with_depth(depth).size() > 0; ++depth) {
        for (int vInd : rooted.vertices_with_depth(depth)) {
            auto parentCatsInARow = (vInd == 0) ? 0 : nCatsInARow[*rooted.parent(vInd)];
            nCatsInARow[vInd] = (hasCat[vInd] == 1) ? parentCatsInARow + 1 :
                (parentCatsInARow > maxCatsAllowed ? parentCatsInARow : 0);
        }
    }

    int canVisit = 0;
    for (size_t i = 1; i < nVertices; ++i)
    {
        bool isLeaf = g.out_nbrs(i).size() == 1;
        bool notToManyCats = nCatsInARow[i] <= maxCatsAllowed;
        if (isLeaf && notToManyCats)
            canVisit++;
    }

    cout << canVisit;
}


int main() {
    Solver580C solver;
    solver.run();
}

