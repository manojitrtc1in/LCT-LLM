#include <cstdio>
#include <set>
#include <vector>
#include <cassert>
#include <algorithm>



#include <set>
#include <vector>
#include <cassert>
#include <algorithm>
using std::vector;
using std::set;

typedef long long cost_t;
typedef long long cap_t;

struct CapacityCostPair {
  CapacityCostPair(cap_t capacity, cost_t cost) :
    capacity(capacity), cost(cost) {}

  cap_t capacity;
  cost_t cost;
};



















struct MojMinCostMaxFlow {
  

  

  

  

  

  

  

  

  

  

  

  

  


  static const cost_t kInfCost = std::numeric_limits<cost_t>::max();
  static const cap_t kInfCapacity = std::numeric_limits<cap_t>::max();

  

  MojMinCostMaxFlow() {}

  

  

  

  int num_nodes;
  int source_id;
  int sink_id;

  

  

  vector<vector<cap_t>> capacity;
  

  vector<vector<cost_t>> cost;
  

  

  vector<vector<int>> graph;

  

  vector<cost_t> distance;
  

  

  vector<cost_t> phi;
  

  vector<int> parent;
  

  

  vector<bool> settled;

  

  cost_t total_edges_cost_so_far;
  cap_t max_edge_capacity;

  int stats_num_searches;
  int stats_dijkstra_num_edges_considered;

  void Init(int new_num_nodes, int new_source_id, int new_sink_id) {
    num_nodes = new_num_nodes;
    assert(IsValidNode(new_source_id));
    assert(IsValidNode(new_sink_id));
    source_id = new_source_id;
    sink_id = new_sink_id;

    capacity = vector<vector<cap_t>>(num_nodes, vector<cap_t>(num_nodes, 0));
    cost = vector<vector<cost_t>>(num_nodes, vector<cost_t>(num_nodes, kInfCost));
    graph = vector<vector<int>>(num_nodes, vector<int>());

    distance = vector<cost_t>(num_nodes, kInfCost);
    phi = vector<cost_t>(num_nodes, 0);
    parent = vector<int>(num_nodes, -1);
    settled = vector<bool>(num_nodes, false);
    total_edges_cost_so_far = 0;
    max_edge_capacity = 0;

    stats_num_searches = 0;
    stats_dijkstra_num_edges_considered = 0;
  }

  void AddEdge(int u, int v, CapacityCostPair spec) {
    assert(IsValidNode(u) && IsValidNode(v));
    assert(cost[u][v] == kInfCost);
    assert(spec.cost != kInfCost);
    assert(capacity[u][v] == 0);
    assert(kInfCost - spec.cost > total_edges_cost_so_far);

    capacity[u][v] = spec.capacity;
    capacity[v][u] = 0;
    cost[u][v] = spec.cost;
    cost[v][u] = -spec.cost;
    graph[u].push_back(v);
    graph[v].push_back(u);
    total_edges_cost_so_far += spec.cost;
    if (spec.capacity != kInfCapacity) {
      max_edge_capacity = std::max(max_edge_capacity, spec.capacity);
    }
  }

  void AddZeroCostEdgeWithCapacity(int u, int v, cap_t capacity) {
    AddEdge(u, v, CapacityCostPair(capacity, 0));
  }

  void AddInfiniteCapacityEdgeWithCost(int u, int v, cost_t cost) {
    AddEdge(u, v, CapacityCostPair(kInfCapacity, cost));
  }

  

  cap_t LeadingBit(cap_t x) {
    assert(max_edge_capacity > 0);
    assert(max_edge_capacity != kInfCapacity);
    cap_t sol;
    for (sol = 1; sol < x; sol <<= 1);
    assert(sol >= x);
    assert(!((sol / 2) >= x));
    return sol;
  }

  CapacityCostPair Run() {
    assert(source_id != sink_id);
    vector<int> path;
    cap_t max_flow = 0;
    cost_t min_cost = 0;

    


    

    for (
        cap_t capacity_multiplier = LeadingBit(max_edge_capacity);
        capacity_multiplier;
        capacity_multiplier /= 2)
    {
      while (FindPath(&path, capacity_multiplier)) {
        const cap_t delta_flow = GetMinCapacity(path);
        assert(delta_flow > 0);
        assert(delta_flow >= capacity_multiplier);
        min_cost += AugmentPath(path, delta_flow);
        max_flow += delta_flow;
        ++stats_num_searches;
      }
    }

    return CapacityCostPair(max_flow, min_cost);
  }

  

  cap_t GetFlow(int u, int v) {
    return capacity[v][u];
  }

  bool IsValidNode(int u) const { return u >= 0 && u < num_nodes; }

  bool Reconstruct(vector<int> *path) {
    int goal = sink_id;
    if (distance[goal] == kInfCost) {
      return false;
    }
    path->clear();
    int guard = 0;
    while (parent[goal] != -1) {
      assert(guard++ <= num_nodes);
      path->push_back(goal);
      goal = parent[goal];
    }
    path->push_back(source_id);
    std::reverse(path->begin(), path->end());
    assert(path->front() == source_id);
    assert(path->back() == sink_id);
    return true;
  }

  

  struct Cmp {
    Cmp (int num_nodes, vector<cost_t>* distance) :
      num_nodes(num_nodes), distance(*distance) {}

    bool operator() (int lhs, int rhs) const {
      assert(lhs >= 0 && lhs < num_nodes);
      assert(rhs >= 0 && rhs < num_nodes);
      return distance[lhs] == distance[rhs] ?
        lhs < rhs :
        distance[lhs] < distance[rhs];
    }

    int num_nodes;
    const vector<cost_t>& distance;
  };

  

  

  

  

  bool FindPath(vector<int> *path, cap_t capacity_multiplier = -1) {
    set<int, Cmp> Q(Cmp(num_nodes, &distance));

    for (int i = 0; i < num_nodes; ++i) {
      distance[i] = kInfCost;
      parent[i] = -1;
      settled[i] = false;
    }

    distance[source_id] = 0;
    Q.insert(source_id);

    while (Q.size()) {
      int u = *Q.begin();
      Q.erase(Q.begin());

      assert(u == source_id || parent[u] != -1);
      assert(distance[u] != kInfCost);
      assert(!settled[u]);
      settled[u] = true;

      for (int v : graph[u]) {
        if (capacity_multiplier == -1) {
          if (capacity[u][v] == 0) {
            continue;
          }
        } else {
          if (capacity[u][v] < capacity_multiplier) {
            continue;
          }
        }
        ++stats_dijkstra_num_edges_considered;
        assert(phi[u] != kInfCost);
        assert(phi[v] != kInfCost);
        const cost_t new_dist = (
            distance[u] + cost[u][v] + (phi[u] - phi[v]));
        

        assert(cost[u][v] + (phi[u] - phi[v]) >= 0);

        if (new_dist < distance[v]) {
          

          auto it = Q.find(v);
          if (it != Q.end()) {
            Q.erase(it);
          }
          

          distance[v] = new_dist;
          parent[v] = u;
          Q.insert(v);
        }
      }
    }

    

    for (int i = 0; i < num_nodes; ++i) {
      if (distance[i] != kInfCost) {
        phi[i] += distance[i];
      }
    }

    return Reconstruct(path);
  }

  

  

  bool BelmanFordNegativeCostCycleExists() {
    vector<cost_t> dist(num_nodes, kInfCost);
    dist[source_id] = 0;

    int iter = 0;
    bool relaxed = false;

    for (iter = 0; iter <= num_nodes; ++iter) {
      relaxed = false;
      

      for (int u = 0; u < (int) graph.size(); ++u) {
        for (int v : graph[u]) {
          if (capacity[u][v] <= 0) {
            continue;
          }
          if (dist[u] == kInfCost || cost[u][v] == kInfCost) {
            continue;
          }
          if (dist[u] + cost[u][v] < dist[v]) {
            relaxed = true;
            dist[v] = dist[u] + cost[u][v];
          }
        }
      }
    }

    for (int i = 0; i < num_nodes; ++i) {
      phi[i] = dist[i];
    }

    

    

    return relaxed;
  }

  

  cap_t GetMinCapacity(const vector<int>& nodes) {
    assert(nodes.size() > 1);
    int u = nodes[0];
    int v = nodes[1];
    cap_t sol = capacity[u][v];
    for (int i = 0; i < (int) nodes.size() - 1; ++i) {
      u = nodes[i];
      v = nodes[i + 1];
      sol = std::min(sol, capacity[u][v]);
    }
    return sol;
  }

  

  

  cost_t AugmentPath(const vector<int>& nodes, cap_t delta_flow) {
    assert(nodes.size() > 1);
    cost_t path_cost = 0;
    for (int i = 0; i < (int) nodes.size() - 1; ++i) {
      int u = nodes[i];
      int v = nodes[i + 1];
      path_cost += cost[u][v] * delta_flow;
      capacity[u][v] -= delta_flow;
      capacity[v][u] += delta_flow;
      assert(capacity[u][v] >= 0);
      assert(capacity[v][u] >= 0);
    }
    return path_cost;
  }

  void PrintGraph() {
    printf("******\n");
    printf("source: %d\nsink: %d\n", source_id, sink_id);
    for (int i = 0; i < num_nodes; ++i) {
      for (int j = 0; j < num_nodes; ++j) {
        if (capacity[i][j]) {
          if (cost[i][j] != kInfCost) {
            printf("%d -> %d, cap: %lld cost: %lld\n", i, j, capacity[i][j], cost[i][j]);
          } else {
            printf("%d -> %d, cap: %lld cost: kInfCost\n", i, j, capacity[i][j]);
          }
        }
      }
    }
    printf("******\n");
  }
};























struct MojWeightedMatching {
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  MojWeightedMatching() {}

  

  int left_size, right_size;

  

  

  vector<int> left_to;
  

  

  vector<int> right_from;

  

  MojMinCostMaxFlow network;

  void Init(int new_left_size, int new_right_size) {
    left_size = new_left_size;
    right_size = new_right_size;
    int num_nodes = 1 + left_size + right_size + 1;
    network.Init(num_nodes, 0, num_nodes - 1);

    for (int i = 0; i < left_size; ++i) {
      network.AddZeroCostEdgeWithCapacity(network.source_id, get_left_id(i), 1);
    }
    for (int i = 0; i < right_size; ++i) {
      network.AddZeroCostEdgeWithCapacity(get_right_id(i), network.sink_id, 1);
    }
  }

  void AddEdge(int left_id, int right_id) {
    network.AddZeroCostEdgeWithCapacity(
        get_left_id(left_id),
        get_right_id(right_id),
        1);
  }

  void AddEdgeWithCost(int left_id, int right_id, cost_t cost) {
    network.AddInfiniteCapacityEdgeWithCost(
        get_left_id(left_id),
        get_right_id(right_id),
        cost);
  }

  CapacityCostPair Run() {
    CapacityCostPair result = network.Run();

    

    left_to = vector<int>(left_size, -1);
    right_from = vector<int>(right_size, -1);
    for (int i = 0; i < left_size; ++i) {
      for (int j = 0; j < right_size; ++j) {
        cap_t flow = network.GetFlow(get_left_id(i), get_right_id(j));
        if (flow) {
          assert(left_to[i] == -1);
          assert(right_from[j] == -1);
          left_to[i] = j;
          right_from[j] = i;
        }
      }
    }

    return result;
  }

  int get_left_id(int left_index) const {
    assert(left_index >= 0 && left_index < left_size);
    return 1 + left_index;
  }

  int get_right_id(int right_index) const {
    assert(right_index >= 0 && right_index < right_size);
    return 1 + left_size + right_index;
  }
};





struct MojAssigmentProblem {
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  MojAssigmentProblem() {}

  int N;
  

  

  vector<int> assigned_col;
  

  vector<int> assigned_row;
  

  vector<std::pair<int, int>> assigments;

  MojWeightedMatching matching;

  typedef std::pair<cost_t, cost_t> Pair;
  Pair original_range;
  bool is_maximizing = false;

  void InitForMaximize(const vector<vector<cost_t>>& matrix) {
    InitShared(matrix);
    is_maximizing = true;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        matching.AddEdgeWithCost(i, j, TransformMax(matrix[i][j]));
      }
    }
  }

  void InitForMinimize(const vector<vector<cost_t>>& matrix) {
    InitShared(matrix);
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        matching.AddEdgeWithCost(i, j, TransformMin(matrix[i][j]));
      }
    }
  }

  

  

  cost_t Run() {
    CapacityCostPair result = matching.Run();
    assert(result.capacity == N);

    

    assigned_col.resize(N);
    assigned_row.resize(N);
    for (int i = 0; i < N; ++i) {
      assigned_col[i] = matching.left_to[i];
      assigned_row[i] = matching.right_from[i];
      assert(assigned_col[i] != -1);
      assert(assigned_row[i] != -1);
      assigments.emplace_back(assigned_row[i], assigned_col[i]);
    }

    return is_maximizing ?
      (original_range.second * N) - result.cost :
      (original_range.first * N) + result.cost;
  }

  

  void InitShared(const vector<vector<cost_t>>& matrix) {
    Pair range;
    N = matrix.size();
    matching.Init(N, N);
    assert(matrix.size() > 0 && matrix[0].size() > 0);
    range.first = matrix[0][0];
    range.second = matrix[0][0];
    for (int i = 0; i < N; ++i) {
      assert((int) matrix[i].size() == N);
      for (int j = 0; j < N; ++j) {
        range.first = std::min(range.first, matrix[i][j]);
        range.second = std::max(range.second, matrix[i][j]);
      }
    }
    original_range = range;
  }

  cost_t TransformMin(cost_t x) {
    return x + original_range.first;
  }

  cost_t TransformMax(cost_t long x) {
    return (original_range.second - x);
  }
};

MojAssigmentProblem solver;
int N;

int main() {
  scanf("%d", &N);

  {
    std::vector<std::vector<long long>> profit(N, std::vector<long long>(N, 0));
    for (int i = 0; i < N; ++i) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      for (int j = 0; j < N && a > 0; ++j) {
        profit[i][j] = a;
        if (j < c) {
          a -= b;
        }
      }
    }
    solver.InitForMaximize(profit);
  }

  printf("%lld\n", solver.Run());
  return 0;
}