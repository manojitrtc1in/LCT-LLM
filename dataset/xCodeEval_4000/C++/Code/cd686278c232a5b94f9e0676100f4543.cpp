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
#include <inttypes.h>
#include <iostream>
#include <map>
#include <optional>
#include <queue>
#include <random>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>







using std::swap;
using std::vector;

class DisjointSet {
  public:
    DisjointSet(int size) : rank_(size, 0), parent_(size), compSize_(size, 1) {
        for (int i = 0; i < size; ++i)
            parent_[i] = i;

        componentsCount_ = size;
    }

    int rep(int elt) {
        if (parent_[elt] == elt) {
            return elt;
        } else {
            parent_[elt] = rep(parent_[elt]);
            return parent_[elt];
        }
    }

    bool inSameSet(int elt1, int elt2) { return (rep(elt1) == rep(elt2)); }

    void unionSets(int elt1, int elt2) {
        auto rep1 = rep(elt1);
        auto rep2 = rep(elt2);
        if (rep1 != rep2) {
            if (rank_[rep1] < rank_[rep2])
                swap(rep1, rep2);
            parent_[rep2] = rep1;
            if (rank_[rep1] == rank_[rep2])
                rank_[rep1]++;
            compSize_[rep1] += compSize_[rep2];
            compSize_[rep2] = 0;
            --componentsCount_;
        }
    }

    int getComponentsCount() const { return componentsCount_; }

    int componentSize(int elt) { return compSize_[rep(elt)]; }

  private:
    vector<int> rank_;
    vector<int> parent_;
    vector<int> compSize_;
    int componentsCount_;
};






template <typename T>
void relax_max(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::max(relaxWhat, relaxBy);
}

template <typename T>
void relax_min(T& relaxWhat, const T& relaxBy) {
    relaxWhat = std::min(relaxWhat, relaxBy);
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































template <typename DirectedGraphT, typename VertexListT>
std::vector<int> topological_sort_reachable_optimistic(const DirectedGraphT& graph,
                                                       const VertexListT& starting_vertices) {
    std::vector<int> result;
    dfs(graph, starting_vertices, [&result](const GraphTraversalState&, int v) {
        result.push_back(v);
        return IterationControl::Proceed;
    });
    std::reverse(begin(result), end(result));
    return result;
}

template <typename DirectedGraphT>
std::vector<int> topological_sort_reachable_optimistic(const DirectedGraphT& graph,
                                                       const std::initializer_list<int>& starting_vertices) {
    return topological_sort_reachable_optimistic<DirectedGraphT, std::initializer_list<int>>(graph, starting_vertices);
}

template <typename DirectedGraphT>
std::vector<int> topological_sort_optimistic(const DirectedGraphT& graph) {
    return topological_sort_reachable_optimistic(graph, range(graph.num_vertices()));
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

#ifndef LOCAL_PC
#define DEFINE_SIMPLE_READ_AND_PRINT(TYPE_NAME, FORMAT) \
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

DEFINE_SIMPLE_READ_AND_PRINT(int, "%d");
DEFINE_SIMPLE_READ_AND_PRINT(unsigned int, "%u");
DEFINE_SIMPLE_READ_AND_PRINT(int64_t, "%lld");
DEFINE_SIMPLE_READ_AND_PRINT(float, "%f");
DEFINE_SIMPLE_READ_AND_PRINT(double, "%lf");
DEFINE_SIMPLE_READ_AND_PRINT(char, "%c");

#endif







template <typename T>
std::vector<T> readVector(size_t size) {
    std::vector<T> res(size);
    for (auto& elt : res)
        elt = read<T>();
    return res;
}





using namespace std;



class Solver650C
{
public:
    void run();
    int h, w;

    int pack(int x, int y) {
        return x + w * y;
    }

    vector<vector<int>> divideToBuckets(vector<pair<int, int>> rowData) const {
        sort(begin(rowData), end(rowData));
        vector<vector<int>> res(1);
        int currV = rowData[0].first;
        for (const auto& p : rowData) {
            if (p.first != currV) {
                res.push_back({});
                currV = p.first;
            }
            res.back().push_back(p.second);
        }
        return res;
    }
};

void Solver650C::run() {
    cin >> h >> w;
    vector<int> m = readVector<int>(h * w);

    vector<vector<vector<int>>> perColumnBuckets(w), perRowbuckets(h);
    for (int y : range(h)) {
        vector<pair<int, int>> vp(w);
        for (int x : range(w)) {
            auto ind = pack(x, y);
            vp[x] = make_pair(m[ind], ind);
        }
        perRowbuckets[y] = divideToBuckets(move(vp));
    }

    for (int x : range(w)) {
        vector<pair<int, int>> vp(h);
        for (int y : range(h)) {
            auto ind = pack(x, y);
            vp[y] = make_pair(m[ind], ind);
        }
        perColumnBuckets[x] = divideToBuckets(move(vp));
    }

    DisjointSet ds(h * w);
    for (auto perDirectionBuckets : { &perColumnBuckets, &perRowbuckets })
        for (const auto& buckets : *perDirectionBuckets)
            for (const auto& bucket : buckets)
                for (auto elt : bucket)
                    ds.unionSets(bucket.front(), elt);

    DirectedGraph<> g(h * w);

    for (auto perDirectionBuckets : { &perColumnBuckets, &perRowbuckets })
        for (const auto& buckets : *perDirectionBuckets)
            for (int i : range<int>(1, buckets.size()))
                g.add_directed_edge(ds.rep(buckets[i].front()), ds.rep(buckets[i - 1].front()));

    auto topsortorder = topological_sort_optimistic(g);
    reverse(begin(topsortorder), end(topsortorder));
    vector<int> mArchived(m.size(), 1);
    for (auto ind : topsortorder)
        for (auto pNei : g.out_nbrs(ind))
            relax_max(mArchived[ind], mArchived[pNei.first] + 1);

    for (int y : range(h)) {
        for (int x : range(w)) {
            print(mArchived[ds.rep(pack(x, y))]);
            print(' ');
        }
        print('\n');
    }
}


int main() {
    Solver650C solver;
    solver.run();
}

