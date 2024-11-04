#include <bits/stdc++.h>
#ifdef LOCAL
#include "code/formatting.hpp"
#else
#define debug(...) (void)0
#endif

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

#define FOR_EACH_IN_LINKED_LIST(i, l, lists) \
    for (int z##i = l, i = lists.head(z##i); i != lists.rep(z##i); i = lists.next[i])

template <typename Flow = int64_t, typename Cost = int64_t>
struct network_simplex {
    explicit network_simplex(int V) : V(V), node(V + 1) {}

    int add(int u, int v, Flow lower, Flow upper, Cost cost) {
        assert(0 <= u && u < V && 0 <= v && v < V && lower <= upper);
        return edge.push_back({{u, v}, lower, upper, cost}), E++;
    }
    int add_node() { return node.emplace_back(), V++; }

    void add_supply(int u, Flow supply) { node[u].supply += supply; }
    void add_demand(int u, Flow demand) { node[u].supply -= demand; }
    void set_supply(int u, Flow supply) { node[u].supply = supply; }

    void update_edge(int e, Flow lower, Flow upper, Cost cost) {
        edge[e].lower = lower, edge[e].upper = upper, edge[e].cost = cost;
    }

    auto get_supply(int u) const { return node[u].supply; }
    auto get_potential(int u) const { return node[u].pi; }
    auto get_flow(int e) const { return edge[e].flow; }

    auto reduced_cost(int e) const {
        auto [u, v] = edge[e].node;
        return edge[e].cost + node[u].pi - node[v].pi;
    }

    

    auto get_excesses() const {
        vector<Flow> excess(V);
        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            excess[u] += edge[e].flow;
            excess[v] -= edge[e].flow;
        }
        return excess;
    }

    template <typename CostSum = int64_t>
    auto get_circulation_cost() const {
        CostSum sum = 0;
        for (int e = 0; e < E; e++) {
            sum += edge[e].flow * CostSum(edge[e].cost);
        }
        return sum;
    }

    void verify() const {
        for (int e = 0; e < E; e++) {
            assert(edge[e].lower <= edge[e].flow && edge[e].flow <= edge[e].upper);
            assert(edge[e].flow == edge[e].lower || reduced_cost(e) <= 0);
            assert(edge[e].flow == edge[e].upper || reduced_cost(e) >= 0);
        }
    }

    

    

    bool mincost_circulation() {
        static constexpr bool INFEASIBLE = false, OPTIMAL = true;

        

        Flow sum_supply = 0;
        for (int u = 0; u < V; u++) {
            sum_supply += node[u].supply;
        }
        if (sum_supply != 0) {
            return INFEASIBLE;
        }

        run();

        

        for (int e = E; e < E + V; e++) {
            if (edge[e].flow != 0) {
                edge.resize(E);
                return INFEASIBLE;
            }
        }
        edge.resize(E);
        return OPTIMAL;
    }

    

    

    

    

    Flow mincost_flow() {
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

    

    enum ArcState : int8_t { STATE_UPPER = -1, STATE_TREE = 0, STATE_LOWER = 1 };
    auto signed_reduced_cost(int e) const { return edge[e].state * reduced_cost(e); }

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
        ArcState state = STATE_LOWER;
    };
    int V, E = 0;
    vector<Node> node;
    vector<Edge> edge;
    linked_lists children;

    int next_arc = 0, block_size = 0;
    vector<int> bfs, perm; 


    void run() {
        

        Cost artif_cost = 1;
        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            edge[e].flow = 0;
            edge[e].state = STATE_LOWER;
            edge[e].upper -= edge[e].lower;
            node[u].supply -= edge[e].lower;
            node[v].supply += edge[e].lower;
            artif_cost += edge[e].cost < 0 ? -edge[e].cost : edge[e].cost;
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
                node[u].pi = -artif_cost;
                edge[e] = {{u, root}, 0, supply, artif_cost, supply, STATE_TREE};
            } else {
                node[u].pi = artif_cost;
                edge[e] = {{root, u}, 0, -supply, artif_cost, -supply, STATE_TREE};
            }
        }

        

        

        

        block_size = max(int(ceil(sqrt(E + V))), min(5, V + 1));
        next_arc = 0;

        

        static mt19937 rng(random_device{}());
        perm.resize(E + V);
        iota(begin(perm), end(perm), 0);
        shuffle(begin(perm), end(perm), rng);

        

        int in_arc = select_pivot_edge();
        while (in_arc != -1) {
            pivot(in_arc);
            in_arc = select_pivot_edge();
        }

        

        for (int e = 0; e < E; e++) {
            auto [u, v] = edge[e].node;
            edge[e].flow += edge[e].lower;
            edge[e].upper += edge[e].lower;
            node[u].supply += edge[e].lower;
            node[v].supply -= edge[e].lower;
        }
    }

    int select_pivot_edge() {
        

        Cost minimum = 0;
        int in_arc = -1;
        int count = block_size, seen_edges = E + V;
        for (int& e = next_arc; seen_edges-- > 0; e = e + 1 == E + V ? 0 : e + 1) {
            int x = perm[e];
            if (minimum > signed_reduced_cost(x)) {
                minimum = signed_reduced_cost(x);
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

        

        int source = edge[in_arc].state == STATE_LOWER ? u_in : v_in;
        int target = edge[in_arc].state == STATE_LOWER ? v_in : u_in;

        enum OutArcSide { SAME_EDGE, SOURCE_SIDE, TARGET_SIDE };
        Flow flow_delta = edge[in_arc].upper;
        OutArcSide side = SAME_EDGE;
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

        if (side == SAME_EDGE) {
            edge[in_arc].state = ArcState(-edge[in_arc].state);
            return;
        }

        

        int out_arc = node[u_out].pred;
        edge[in_arc].state = STATE_TREE;
        edge[out_arc].state = edge[out_arc].flow ? STATE_UPPER : STATE_LOWER;

        

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

        

        Cost current_pi = reduced_cost(in_arc);
        Cost pi_delta = u_in == edge[in_arc].node[0] ? -current_pi : +current_pi;

        bfs[0] = u_in;
        for (i = 0, S = 1; i < S; i++) {
            int u = bfs[i];
            node[u].pi += pi_delta;
            FOR_EACH_IN_LINKED_LIST (v, u, children) { bfs[S++] = v; }
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

    network_simplex<int, int> ns(2 * D);
    vector<vector<int>> edges(2 * D + 1);

    for (int m = 0; m < D; m++) {
        for (int b = 0; b < d; b++) {
            if ((m >> b & 1) == 0) {
                edges[m + D].push_back(ns.add(m + D, m | (1 << b), 0, N, 1));
            }
        }
        ns.add(m, m + D, seen[m], N, 0);                   

        edges[m + D].push_back(ns.add(m + D, 0, 0, N, 1)); 

    }

    ns.mincost_circulation();
    int K = ns.get_circulation_cost() - 1;
    cout << K << '\n';

    vector<int> path;
    int S = 0, u = D;
    while (S < K) {
        for (int e : edges[u]) {
            if (ns.edge[e].flow-- > 0) {
                u = ns.edge[e].node[1];
                path.push_back(u), S++;
                u += D;
                break;
            }
        }
    }

    for (int i = 0; i < K; i++) {
        if (path[i] == 0) {
            cout << "R" << ' ';
        } else {
            int p = i ? path[i - 1] : 0;
            int b = __builtin_ctz(p ^ path[i]);
            cout << b << " \n"[i + 1 == K];
        }
    }

    return 0;
}