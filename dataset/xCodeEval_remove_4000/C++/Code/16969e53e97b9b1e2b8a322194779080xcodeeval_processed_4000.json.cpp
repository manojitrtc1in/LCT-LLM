











using std::vector;
using std::set;

typedef long long cost_t;
typedef long long cap_t;

struct id11 {
  id11(cap_t capacity, cost_t cost) :
    capacity(capacity), cost(cost) {}

  cap_t capacity;
  cost_t cost;
};



















struct id8 {
  

  

  

  

  

  

  

  

  

  

  

  

  


  static const cost_t id4 = std::numeric_limits<cost_t>::max();
  static const cap_t kInfCapacity = std::numeric_limits<cap_t>::max();

  

  id8() {}

  

  

  

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

  

  cost_t id9;
  cap_t id12;

  int id2;
  int id13;

  void Init(int id6, int id10, int id14) {
    num_nodes = id6;
    assert(IsValidNode(id10));
    assert(IsValidNode(id14));
    source_id = id10;
    sink_id = id14;

    capacity = vector<vector<cap_t>>(num_nodes, vector<cap_t>(num_nodes, 0));
    cost = vector<vector<cost_t>>(num_nodes, vector<cost_t>(num_nodes, id4));
    graph = vector<vector<int>>(num_nodes, vector<int>());

    distance = vector<cost_t>(num_nodes, id4);
    phi = vector<cost_t>(num_nodes, 0);
    parent = vector<int>(num_nodes, -1);
    settled = vector<bool>(num_nodes, false);
    id9 = 0;
    id12 = 0;

    id2 = 0;
    id13 = 0;
  }

  void AddEdge(int u, int v, id11 spec) {
    assert(IsValidNode(u) && IsValidNode(v));
    assert(cost[u][v] == id4);
    assert(spec.cost != id4);
    assert(capacity[u][v] == 0);
    assert(id4 - spec.cost > id9);

    capacity[u][v] = spec.capacity;
    capacity[v][u] = 0;
    cost[u][v] = spec.cost;
    cost[v][u] = -spec.cost;
    graph[u].push_back(v);
    graph[v].push_back(u);
    id9 += spec.cost;
    if (spec.capacity != kInfCapacity) {
      id12 = std::max(id12, spec.capacity);
    }
  }

  void AddZeroCostEdgeWithCapacity(int u, int v, cap_t capacity) {
    AddEdge(u, v, id11(capacity, 0));
  }

  void AddInfiniteCapacityEdgeWithCost(int u, int v, cost_t cost) {
    AddEdge(u, v, id11(kInfCapacity, cost));
  }

  

  cap_t LeadingBit(cap_t x) {
    assert(id12 > 0);
    assert(id12 != kInfCapacity);
    cap_t sol;
    for (sol = 1; sol < x; sol <<= 1);
    assert(sol >= x);
    assert(!((sol / 2) >= x));
    return sol;
  }

  id11 Run() {
    assert(source_id != sink_id);
    vector<int> path;
    cap_t max_flow = 0;
    cost_t min_cost = 0;

    


    

    for (
        cap_t capacity_multiplier = LeadingBit(id12);
        capacity_multiplier;
        capacity_multiplier /= 2)
    {
      while (FindPath(&path, capacity_multiplier)) {
        const cap_t delta_flow = GetMinCapacity(path);
        assert(delta_flow > 0);
        assert(delta_flow >= capacity_multiplier);
        min_cost += AugmentPath(path, delta_flow);
        max_flow += delta_flow;
        ++id2;
      }
    }

    return id11(max_flow, min_cost);
  }

  

  cap_t GetFlow(int u, int v) {
    return capacity[v][u];
  }

  bool IsValidNode(int u) const { return u >= 0 && u < num_nodes; }

  bool Reconstruct(vector<int> *path) {
    int goal = sink_id;
    if (distance[goal] == id4) {
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
      distance[i] = id4;
      parent[i] = -1;
      settled[i] = false;
    }

    distance[source_id] = 0;
    Q.insert(source_id);

    while (Q.size()) {
      int u = *Q.begin();
      Q.erase(Q.begin());

      assert(u == source_id || parent[u] != -1);
      assert(distance[u] != id4);
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
        ++id13;
        assert(phi[u] != id4);
        assert(phi[v] != id4);
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
      if (distance[i] != id4) {
        phi[i] += distance[i];
      }
    }

    return Reconstruct(path);
  }

  

  

  bool BelmanFordNegativeCostCycleExists() {
    vector<cost_t> dist(num_nodes, id4);
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
          if (dist[u] == id4 || cost[u][v] == id4) {
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
          if (cost[i][j] != id4) {
            printf("%d -> %d, cap: %lld cost: %lld\n", i, j, capacity[i][j], cost[i][j]);
          } else {
            printf("%d -> %d, cap: %lld cost: id4\n", i, j, capacity[i][j]);
          }
        }
      }
    }
    printf("******\n");
  }
};























struct id5 {
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  id5() {}

  

  int left_size, right_size;

  

  

  vector<int> left_to;
  

  

  vector<int> right_from;

  

  id8 network;

  void Init(int id1, int id7) {
    left_size = id1;
    right_size = id7;
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

  id11 Run() {
    id11 result = network.Run();

    

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





struct id3 {
  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  

  id3() {}

  int N;
  

  

  vector<int> assigned_col;
  

  vector<int> assigned_row;
  

  vector<std::pair<int, int>> assigments;

  id5 matching;

  typedef std::pair<cost_t, cost_t> Pair;
  Pair original_range;
  bool id0 = false;

  void InitForMaximize(const vector<vector<cost_t>>& matrix) {
    InitShared(matrix);
    id0 = true;
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
    id11 result = matching.Run();
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

    return id0 ?
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

id3 solver;
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