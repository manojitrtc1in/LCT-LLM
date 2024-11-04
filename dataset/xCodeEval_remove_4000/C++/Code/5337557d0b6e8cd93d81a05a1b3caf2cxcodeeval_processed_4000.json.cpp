






using namespace std;

struct linked_lists {
    int L, N;
    vector<int> next, prev;

    

    explicit linked_lists(int L = 0, int N = 0) { assign(L, N); }

    int rep(int l) const { return l + N; }
    int head(int l) const { return next[rep(l)]; }
    int tail(int l) const { return prev[rep(l)]; }
    bool empty(int l) const { return next[rep(l)] == rep(l); }

    int add_list() { return next.push_back(rep(L)), prev.push_back(rep(L)), L++; }
    void clear(int l) { assert(0 <= l && l < L), next[rep(l)] = prev[rep(l)] = rep(l); }

    void init(int l, int n) { meet(rep(l), n, rep(l)); }
    void push_front(int l, int n) { meet(rep(l), n, head(l)); }
    void push_back(int l, int n) { meet(tail(l), n, rep(l)); }
    void insert_before(int i, int n) { meet(prev[i], n, i); }
    void insert_after(int i, int n) { meet(i, n, next[i]); }
    void erase(int n) { meet(prev[n], next[n]); }
    void pop_front(int l) { meet(rep(l), next[head(l)]); }
    void pop_back(int l) { meet(prev[tail(l)], rep(l)); }

    void splice_front(int l, int b) {
        assert(0 <= l && l < L && 0 <= b && b < L && l != b);
        if (!empty(b))
            meet(tail(b), head(l)), meet(rep(l), head(b)), clear(b);
    }
    void splice_back(int l, int b) {
        assert(0 <= l && l < L && 0 <= b && b < L && l != b);
        if (!empty(b))
            meet(tail(l), head(b)), meet(tail(b), rep(l)), clear(b);
    }

    void clear() {
        iota(begin(next) + N, end(next), N);
        iota(begin(prev) + N, end(prev), N);
    }
    void assign(int L, int N) {
        this->L = L, this->N = N;
        next.resize(N + L), prev.resize(N + L), clear();
    }

  private:
    inline void meet(int u, int v) { next[u] = v, prev[v] = u; }
    inline void meet(int u, int v, int w) { meet(u, v), meet(v, w); }
};


    for (int z

template <typename Flow = int64_t, typename Cost = int64_t>
struct network_simplex {
    explicit network_simplex(int V) : V(V), node(V + 1) {}

    int add(int u, int v, Flow lower, Flow upper, Cost cost) {
        assert(0 <= u && u < V && 0 <= v && v < V && lower <= upper);
        return edge.push_back({{u, v}, lower, upper, cost}), E++;
    }
    int add_node() { return node.emplace_back(), V++; }

    void add_supply(int u, Flow supply) { node[u].supply += supply; }
    void id6(int u, Flow demand) { node[u].supply -= demand; }
    void set_supply(int u, Flow supply) { node[u].supply = supply; }

    void update_edge(int e, Flow lower, Flow upper, Cost cost) {
        edge[e].lower = lower, edge[e].upper = upper, edge[e].cost = cost;
    }

    auto get_supply(int u) const { return node[u].supply; }
    auto id0(int u) const { return node[u].pi; }
    auto get_flow(int e) const { return edge[e].flow; }

    auto id5(int e) const {
        auto [u, v] = edge[e].node;
        return edge[e].cost + node[u].pi - node[v].pi;
    }

    

    auto id1() const {
        vector<Flow> excess(V);
        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            excess[u] += edge[e].flow;
            excess[v] -= edge[e].flow;
        }
        return excess;
    }

    template <typename CostSum = int64_t>
    auto id8() const {
        CostSum sum = 0;
        for (int e = 0; e < E; e++) {
            sum += edge[e].flow * CostSum(edge[e].cost);
        }
        return sum;
    }

    void verify() const {
        for (int e = 0; e < E; e++) {
            assert(edge[e].lower <= edge[e].flow && edge[e].flow <= edge[e].upper);
            assert(edge[e].flow == edge[e].lower || id5(e) <= 0);
            assert(edge[e].flow == edge[e].upper || id5(e) >= 0);
        }
    }

    

    

    bool id3() {
        static constexpr bool id7 = false, OPTIMAL = true;

        

        Flow sum_supply = 0;
        for (int u = 0; u < V; u++) {
            sum_supply += node[u].supply;
        }
        if (sum_supply != 0) {
            return id7;
        }

        run();

        

        for (int e = E; e < E + V; e++) {
            if (edge[e].flow != 0) {
                edge.resize(E);
                return id7;
            }
        }
        edge.resize(E);
        return OPTIMAL;
    }

    

    

    

    

    Flow id10() {
        run();

        Flow maxflow = 0;
        for (int e = E; e < E + V; e++) {
            if (edge[e].node[1] == V) {
                maxflow += edge[e].upper - edge[e].flow;
            }
        }

        edge.resize(E);
        return maxflow;
    }

    

    enum ArcState : int8_t { STATE_UPPER = -1, STATE_TREE = 0, id2 = 1 };
    auto id12(int e) const { return edge[e].state * id5(e); }

    struct Node {
        int parent, pred;
        Flow supply;
        Cost pi;
    };
    struct Edge {
        int node[2];
        Flow lower, upper;
        Cost cost;
        Flow flow = 0;
        ArcState state = id2;
    };
    int V, E = 0;
    vector<Node> node;
    vector<Edge> edge;
    linked_lists children;

    int next_arc = 0, block_size = 0;
    vector<int> bfs, perm; 


    void run() {
        

        Cost id11 = 1;
        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            edge[e].flow = 0;
            edge[e].state = id2;
            edge[e].upper -= edge[e].lower;
            node[u].supply -= edge[e].lower;
            node[v].supply += edge[e].lower;
            id11 += edge[e].cost < 0 ? -edge[e].cost : edge[e].cost;
        }

        edge.resize(E + V);
        bfs.resize(V + 1);
        children.assign(V + 1, V + 1);

        

        int root = V;
        node[root] = {-1, -1, 0, 0};

        for (int u = 0, e = E; u < V; u++, e++) {
            node[u].parent = root, node[u].pred = e;
            children.push_back(root, u);
            auto supply = node[u].supply;
            if (supply >= 0) {
                node[u].pi = -id11;
                edge[e] = {{u, root}, 0, supply, id11, supply, STATE_TREE};
            } else {
                node[u].pi = id11;
                edge[e] = {{root, u}, 0, -supply, id11, -supply, STATE_TREE};
            }
        }

        

        

        

        block_size = max(int(ceil(sqrt(E + V))), min(5, V + 1));
        next_arc = 0;

        

        static mt19937 rng(random_device{}());
        perm.resize(E + V);
        iota(begin(perm), end(perm), 0);
        shuffle(begin(perm), end(perm), rng);

        

        int in_arc = id9();
        while (in_arc != -1) {
            pivot(in_arc);
            in_arc = id9();
        }

        

        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            edge[e].flow += edge[e].lower;
            edge[e].upper += edge[e].lower;
            node[u].supply += edge[e].lower;
            node[v].supply -= edge[e].lower;
        }
    }

    int id9() {
        

        Cost minimum = 0;
        int in_arc = -1;
        int count = block_size, seen_edges = E + V;
        for (int& e = next_arc; seen_edges-- > 0; e = e + 1 == E + V ? 0 : e + 1) {
            int x = perm[e];
            if (minimum > id12(x)) {
                minimum = id12(x);
                in_arc = x;
            }
            if (--count == 0 && minimum < 0) {
                break;
            } else if (count == 0) {
                count = block_size;
            }
        }
        return in_arc;
    }

    void pivot(int in_arc) {
        

        auto [u_in, v_in] = edge[in_arc].node;
        int a = u_in, b = v_in;
        while (a != b) {
            a = node[a].parent == -1 ? v_in : node[a].parent;
            b = node[b].parent == -1 ? u_in : node[b].parent;
        }
        int join = a;

        

        int source = edge[in_arc].state == id2 ? u_in : v_in;
        int target = edge[in_arc].state == id2 ? v_in : u_in;

        enum OutArcSide { id13, SOURCE_SIDE, TARGET_SIDE };
        Flow flow_delta = edge[in_arc].upper;
        OutArcSide side = id13;
        int u_out = -1;

        

        for (int u = source; u != join && flow_delta; u = node[u].parent) {
            int e = node[u].pred;
            bool edge_down = u == edge[e].node[1];
            Flow d = edge_down ? edge[e].upper - edge[e].flow : edge[e].flow;
            if (flow_delta > d) {
                flow_delta = d;
                u_out = u;
                side = SOURCE_SIDE;
            }
        }

        

        for (int u = target; u != join && (flow_delta || side != TARGET_SIDE);
             u = node[u].parent) {
            int e = node[u].pred;
            bool edge_up = u == edge[e].node[0];
            Flow d = edge_up ? edge[e].upper - edge[e].flow : edge[e].flow;
            if (flow_delta >= d) {
                flow_delta = d;
                u_out = u;
                side = TARGET_SIDE;
            }
        }

        

        if (flow_delta) {
            auto delta = edge[in_arc].state * flow_delta;
            edge[in_arc].flow += delta;
            for (int u = edge[in_arc].node[0]; u != join; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? -delta : +delta;
            }
            for (int u = edge[in_arc].node[1]; u != join; u = node[u].parent) {
                int e = node[u].pred;
                edge[e].flow += u == edge[e].node[0] ? +delta : -delta;
            }
        }

        if (side == id13) {
            edge[in_arc].state = ArcState(-edge[in_arc].state);
            return;
        }

        

        int out_arc = node[u_out].pred;
        edge[in_arc].state = STATE_TREE;
        edge[out_arc].state = edge[out_arc].flow ? STATE_UPPER : id2;

        

        u_in = side == SOURCE_SIDE ? source : target;
        v_in = side == SOURCE_SIDE ? target : source;

        

        int i = 0, S = 0;
        for (int u = u_in; u != u_out; u = node[u].parent) {
            bfs[S++] = u;
        }
        for (i = S - 1; i >= 0; i--) {
            int u = bfs[i], p = node[u].parent;
            children.erase(p);
            children.push_back(u, p);
            node[p].parent = u;
            node[p].pred = node[u].pred;
        }
        children.erase(u_in);
        children.push_back(v_in, u_in);
        node[u_in].parent = v_in;
        node[u_in].pred = in_arc;

        

        Cost current_pi = id5(in_arc);
        Cost pi_delta = u_in == edge[in_arc].node[0] ? -current_pi : +current_pi;

        bfs[0] = u_in;
        for (i = 0, S = 1; i < S; i++) {
            int u = bfs[i];
            node[u].pi += pi_delta;
            id4 (v, u, children) { bfs[S++] = v; }
        }
    }
};

int main() {
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int d, N;
    cin >> d >> N;
    int D = 1 << d;

    vector<int> seen(D);
    for (int i = 0; i < N; i++) {
        string s;
        cin >> s;
        int mask = 0;
        for (int b = 0; b < d; b++) {
            mask |= (s[b] - '0') << b;
        }
        seen[mask] = true;
    }

    network_simplex<int, int> ns(2 * D + 2);
    int s = 2 * D, t = 2 * D + 1;

    ns.add(t, s, 0, N, 1); 


    vector<vector<int>> edges(2 * D + 1);

    for (int m = 0; m < D; m++) {
        for (int b = 0; b < d; b++) {
            if ((m >> b & 1) == 0) {
                edges[m + D].push_back(ns.add(m + D, m | (1 << b), 0, N, 1));
            }
        }
        ns.add(m, m + D, seen[m], N, 0);                   

        edges[m + D].push_back(ns.add(m + D, t, 0, N, 0)); 

    }
    for (int b = 0; b < d; b++) {
        edges[s].push_back(ns.add(s, 1 << b, 0, N, 1)); 

    }

    ns.id3();
    int K = ns.id8() - 1;
    cout << K << '\n';

    vector<int> path;
    int S = 0;
    while (S < K) {
        int u = s;
        while (u != t) {
            for (int e : edges[u]) {
                if (ns.edge[e].flow-- > 0) {
                    u = ns.edge[e].node[1];
                    path.push_back(u), S++;
                    u += u == t ? 0 : D;
                    break;
                }
            }
        }
    }

    for (int i = 0; i < K; i++) {
        if (path[i] == t) {
            cout << "R" << ' ';
        } else {
            int p = i == 0 || path[i - 1] == t ? 0 : path[i - 1];
            int b = __builtin_ctz(p ^ path[i]);
            cout << b << " \n"[i + 1 == K];
        }
    }

    return 0;
}