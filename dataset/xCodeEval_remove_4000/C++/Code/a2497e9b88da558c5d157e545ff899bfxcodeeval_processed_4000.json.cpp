
NDEBUG































using namespace std;





bool __hack = std::ios::sync_with_stdio(false);


auto id10 = cin.tie(nullptr);








namespace template_util {
    

    constexpr int bytecount(uint64_t x) {
        return x ? 1 + bytecount(x >> 8) : 0;
    }

    template<int N>
    struct bytetype {
        
    };

    
    

    template<uint64_t N>
    struct minimal_uint : bytetype<bytecount(N)> {
    };
}


template<class T>
T next(istream& in) {
    T ret;
    in >> ret;
    return ret;
}

template<class T>
vector<T> next_vector(istream& in, size_t n) {
    vector<T> ret(n);
    for (size_t i = 0; i < n; ++i) {
        ret[i] = next<T>(in);
    }
    return ret;
}




namespace graph_impl {

    template<class T, class G, T next(const G&, T)>
    struct id3 {
        id3(const G& g_, T t_): g(g_), t(t_) {}

        T operator*() const {
            return t;
        }

        id3& operator++() {
            t = next(g, t);
            return *this;
        }

        
        bool operator!=(const id3& o) const {
            assert(&g == &o.g);
            return t != o.t;
        }
    private:
        const G& g;
        T t;
    };

    template<class T, class G, T next(const G&, T)>
    struct id2 {
        id2(const G& g_, T from_, T to_): g(g_), from(from_), to(to_) {}

        id3<T, G, next> begin() {
            return {g, from};
        };

        id3<T, G, next> end() {
            return {g, to};
        };
    private:
        const G& g;
        T from, to;
    };

    template<class T>
    struct id8 {
        explicit id8(int at_): at(at_) {}

        T operator*() const {
            return T{at};
        }

        id8& operator++() {
            at++;
            return *this;
        }

        
        bool operator!=(const id8& o) const {
            return at != o.at;
        }
    private:
        int at;
    };

    template<class T>
    struct id4 {
        id4(int from_, int to_):  from(from_), to(to_) {}

        id8<T> begin() {
            return id8<T>{from};
        };

        id8<T> end() {
            return id8<T>{to};
        };
    private:
        int from, to;
    };

    template<class K, class V>
    struct GenMap {
        

        explicit GenMap(V v_ = V{}): v(v_) {
        }

        
        GenMap& clear() {
            impl_.clear();
            return *this;
        }

        V& operator()(K k) {
            if (impl_.size() <= k.id) {
                impl_.resize(k.id + 1, v);
            }
            return impl_[k.id];
        }

        const V& operator()(K k) const {
            if (impl_.size() <= k.id) {
                return v;
            }
            return impl_[k.id];
        }
        vector<V> impl_;
    private:
        V v;
    };


    struct NodeT {
        int firstOut = -1;
        int degree = 0;
    };

    struct ArcT {
        int to, nextOut;
    };
}

struct Graph {
    struct Node {
        int id;
        explicit Node(int id_ = -1): id(id_) {}
        bool operator==(const Node o) const {return id == o.id;}
        
        bool operator<(const Node o) const {return id < o.id;}

        
    };

    struct Arc {
        int id;
        explicit Arc(int id_ = -1): id(id_) {}
        
        bool operator!=(const Arc o) const {return id != o.id;}

        
    };

    struct Edge {
        int id;
        explicit Edge(int id_ = -1): id(id_) {}
        bool operator==(const Edge o) const {return id == o.id;}
        
        
    };

    template<class V>
    using NodeMap = graph_impl::GenMap<Node, V>;

    
    template<class V>
    using EdgeMap = graph_impl::GenMap<Edge, V>;

    
    Graph& clear() {
        arcs_.clear();
        nodes_.clear();
        return *this;
    }

    Node addNode() {
        int n = (int)nodes_.size();
        nodes_.push_back({});
        return Node{n};
    }

    
    Edge addEdge(Node u, Node v) {
        assert(valid(u));
        assert(valid(v));
        int n = (int)arcs_.size();
        arcs_.push_back({});
        arcs_[n].to = v.id;
        arcs_[n].nextOut = nodes_[u.id].firstOut;
        nodes_[u.id].firstOut = n;
        arcs_.push_back({});
        arcs_[n + 1].to = u.id;
        arcs_[n + 1].nextOut = nodes_[v.id].firstOut;
        nodes_[v.id].firstOut = n + 1;
        nodes_[u.id].degree++;
        nodes_[v.id].degree++;
        return Edge{n >> 1};
    }

    Edge toEdge(Arc a) const {
        assert(valid(a));
        return Edge{a.id >> 1};
    }

    
    int nodesCount() const {
        return (int)nodes_.size();
    }

    
    Arc firstOutArc(Node a) const {
        assert(valid(a));
        return Arc{nodes_[a.id].firstOut};
    }

    
    Arc nextOutArc(Arc a) const {
        assert(valid(a));
        return Arc{arcs_[a.id].nextOut};
    }

    
    Node to(Arc a) const {
        assert(valid(a));
        return Node{arcs_[a.id].to};
    }

    
private:

    
    static Arc nextOutArc_(const Graph& g, Arc a) {
        return g.nextOutArc(a);
    }

public:

    
    graph_impl::id2<Arc, Graph, &Graph::nextOutArc_> outArcs(Node a) const {
        assert(valid(a));
        return graph_impl::id2<Arc, Graph, &Graph::nextOutArc_>(*this, firstOutArc(a), Arc{});
    }

    graph_impl::id4<Node> nodes() const {
        return graph_impl::id4<Node>(0, nodesCount());
    }

    
private:
    vector<graph_impl::NodeT> nodes_;
    vector<graph_impl::ArcT> arcs_;
};





struct id11 {

    id11() {}

    id11(const Graph& g) {
        this->g = &g;
    }

    void points(bool with_colors = false) {
        t_in.clear();
        t_up.clear();
        mark.clear();
        is_articulation.clear();
        if (!with_colors) {
            for (auto v : this->g->nodes()) {
                if (!mark(v)) {
                    timer = 0;
                    dfsPoints(v);
                }
            }
        } else {
            component_id = 0;
            vertex_color.clear();
            edge_color.clear();
            depth.clear();
            for (auto v : this->g->nodes()) {
                depth(v) = -2;
            }
            for (auto v : this->g->nodes()) {
                if (!mark(v)) {
                    timer = 0;
                    stack.clear();
                    dfsPointsComplex(v);
                }
            }
            for (auto v : this->g->nodes()) {
                if (!is_articulation(v)) {
                    for (auto a : g->outArcs(v)) {
                        auto e = g->toEdge(a);
                        vertex_color(v) = edge_color(e);
                        break;
                    }
                } else {
                    vertex_color(v) = component_id;
                    ++component_id;
                }
            }
        }
    }

    
    int component_id;
    Graph::EdgeMap<int> is_bridge;
    Graph::NodeMap<int> is_articulation;
    Graph::EdgeMap<int> edge_color;
    Graph::NodeMap<int> vertex_color;

private:
    const Graph* g;
    Graph::NodeMap<int> mark;
    Graph::NodeMap<int> t_in;
    Graph::NodeMap<int> t_up;
    int timer;

    deque<Graph::Edge> stack;
    Graph::NodeMap<int> depth;

    
    void dfsPoints(Graph::Node v, Graph::Node p = Graph::Node()) {
        mark(v) = 1;
        t_in(v) = t_up(v) = timer++;
        int children = 0;
        for (auto a : g->outArcs(v)) {
            auto to = g->to(a);
            if (to == p) continue;
            if (mark(to)) {
                t_up(v) = min(t_up(v), t_in(to));
            } else {
                dfsPoints(to, v);
                t_up(v) = min(t_up(v), t_up(to));
                if (t_up(to) >= t_in(v) && p.id != -1) {
                    is_articulation(v) = 1;
                }
                ++children;
            }
        }
        if (p.id == -1 && children > 1) {
            is_articulation(v) = 1;
        }
    }

    void dfsPointsComplex(Graph::Node v) {
        mark(v) = 1;
        t_in(v) = t_up(v) = timer++;
        int children = 0;
        for (auto a : g->outArcs(v)) {
            ++children;
            auto to = g->to(a);
            if (!mark(to)) {
                depth(to) = depth(v) + 1;
                auto cur_edge = g->toEdge(a);
                stack.push_back(cur_edge);
                dfsPointsComplex(to);
                t_up(v) = min(t_up(v), t_up(to));
                if (t_in(v) == 0 || t_up(to) >= t_in(v)) {
                    if (t_in(v) != 0 || children > 1) {
                        is_articulation(v) = 1;
                    }
                    while(!stack.empty()) {
                        auto e = stack.back();
                        stack.pop_back();
                        edge_color(e) = component_id;
                        if (e == cur_edge) {
                            break;
                        }
                    }
                    ++component_id;
                }
            } else if (depth(to) < depth(v) - 1) {
                t_up(v) = min(t_up(v), t_in(to));
                stack.push_back(g->toEdge(a));
            }
        }
    }

    
};


struct LCA {

    LCA() {}

    LCA(const Graph& tree, const vector<Graph::Node>& dfs_order, const Graph::NodeMap<int>& height) {
        this->tree = &tree;
        this->height = &height;
        this->dfs_order = &dfs_order;
        id5 = (int)this->dfs_order->size();

        n = this->tree->nodesCount();
        pos_in_dfs_order.clear();
        for (auto v : this->tree->nodes()) {
            pos_in_dfs_order(v) = -1;
        }
        FOR(i, id5) {
            if (pos_in_dfs_order((*this->dfs_order)[i]) == -1) {
                pos_in_dfs_order((*this->dfs_order)[i]) = i;
            }
        }
        log2 = vector<int>(2 * n);
        id7 = log(id5);
        buildLCA();
    }

    Graph::Node lca(const Graph::Node v, const Graph::Node u) {
        int l = pos_in_dfs_order(v), r = pos_in_dfs_order(u);
        if (l > r) {
            int t = l;
            l = r;
            r = t;
        }
        int left_block = l / block, right_block = r / block;
        if (left_block == right_block) {
            return (*this->dfs_order)[lcaInBlocks(left_block, l % block, r % block)];
        }
        int ans1 = lcaInBlocks(left_block, l % block, block - 1);
        int ans2 = lcaInBlocks(right_block, 0, r % block);
        int ans = minHeight(ans1, ans2);
        if (left_block < right_block - 1) {
            int pw2 = log2[right_block - left_block - 1];
            int ans3 = block_table[left_block + 1][pw2];
            int ans4 = block_table[right_block - (1 << pw2)][pw2];
            ans = minHeight(ans, minHeight(ans3, ans4));
        }
        return (*this->dfs_order)[ans];
    }

private:
    const Graph* tree;
    const vector<Graph::Node>* dfs_order;
    const Graph::NodeMap<int>* height;

    Graph::NodeMap<int> pos_in_dfs_order;
    int id5;
    int block;
    vector<vector<int>> block_table;
    int id7;
    vector<int> block_hash;
    vector<vector<vector<int>>> id6;
    vector<int> log2;
    int n;

    int log(int n) {
        int res = 1;
        while ((1 << res) < n)  ++res;
        return res;
    }

    

    int minHeight(int i, int j) {
        return (*height)((*this->dfs_order)[i]) < (*height)((*this->dfs_order)[j]) ? i : j;
    }

    

    void buildLCA() {
        block = (id7 + 1) / 2;
        int blocks = id5 / block + ((id5 % block > 0) ? 1 : 0);
        int maxBlocks = ((2 * n) / block) + 2;
        block_hash = vector<int>(maxBlocks + 1, 0);
        block_table = vector<vector<int>>(maxBlocks + 1, vector<int>(id7 + 1, -1));
        id6 = vector<vector<vector<int>>>((int) (sqrt(2*n) + 2), vector<vector<int>>(block + 2, vector<int>(block + 2, -1)));

        

        for (int i = 0, blockId = 0, j = 0; i < id5; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (block_table[blockId][0] == -1 || minHeight(i, block_table[blockId][0]) == i) {
                block_table[blockId][0] = i;
            }
        }

        for (int j = 1; j <= id7; ++j) {
            for (int i = 0; i < blocks; ++i) {
                int ni = i + (1 << (j - 1));
                if (ni >= blocks) {
                    block_table[i][j] = block_table[i][j - 1];
                } else {
                    block_table[i][j] = minHeight(block_table[i][j - 1], block_table[ni][j - 1]);
                }
            }
        }

        

        for (int i = 0, blockId = 0, j = 0; i < id5 || j < block; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (j > 0 && (i >= id5 || minHeight(i - 1, i) == i - 1)) {
                block_hash[blockId] += (1 << (j - 1));
            }
        }

        

        for (int i = 0; i < blocks; ++i) {
            int id = block_hash[i];
            if (id6[id][0][0] != -1) continue;
            for (int l = 0; l < block; ++l) {
                id6[id][l][l] = l;
                for (int r = l + 1; r < block; ++r) {
                    id6[id][l][r] = id6[id][l][r-1];
                    if (i * block + r < id5) {
                        id6[id][l][r] = minHeight(i * block + id6[id][l][r], i * block + r) - i * block;
                    }
                }
            }
        }

        

        for (int i = 0, j = 0; i < id5; ++i) {
            if (1 << (j + 1) <= i) ++j;
            log2[i] = j;
        }
    }

    int lcaInBlocks(int block_id, int left, int right) {
        return id6[block_hash[block_id]][left][right] + block_id * block;
    }
};


struct TreeData {

    TreeData() {}

    TreeData(const Graph& tree, Graph::Node root = Graph::Node()) {
        this->tree = &tree;
        this->root = root.id == -1 ? *tree.nodes().begin() : root;
    }

    
    void buildDfsOrder() {
        timer = 0;
        height.clear();
        dfs_order.clear();
        dfs_order.reserve(2 * tree->nodesCount() - 1);
        t_in.clear();
        t_out.clear();
        for (auto v : tree->nodes()) {
            height(v) = -1;
        }
        internalBuildDfsOrder(root, 0);
    }

    
    void buildSubtreeSizes() {
        subtree_size.clear();
        parent.clear();
        vector<Graph::Node> q;
        q.reserve(tree->nodesCount());
        q.push_back(root);
        parent(root) = Graph::Node();
        FOR(qi, q.size()) {
            auto cur = q[qi];
            for (auto a : tree->outArcs(cur)) {
                auto to = tree->to(a);
                if (to == parent(cur)) continue;
                q.push_back(to);
                parent(to) = cur;
            }
        }
        reverse(all(q));
        for (auto v : q) {
            subtree_size(v) = 1;
            for (auto a : tree->outArcs(v)) {
                auto to = tree->to(a);
                if (to == parent(v)) continue;
                subtree_size(v) += subtree_size(to);
            }
        }
    }

    Graph::NodeMap<int> height;
    vector<Graph::Node> dfs_order;
    Graph::NodeMap<int> t_in;
    Graph::NodeMap<int> t_out;
    Graph::NodeMap<int> subtree_size;
    Graph::NodeMap<Graph::Node> parent;
    Graph::NodeMap<vector<Graph::Node>> parent2;

private:
    const Graph* tree;
    Graph::Node root;
    int timer;

    void internalBuildDfsOrder(Graph::Node v, int h) {
        height(v) = h;
        dfs_order.push_back(v);
        t_in(v) = timer++;
        for (auto a : tree->outArcs(v)) {
            auto to = tree->to(a);
            if (height(to) != -1) {
                continue;
            }
            internalBuildDfsOrder(to, h + 1);
            dfs_order.push_back(v);
        }
        t_out(v) = timer - 1;
    }
};


struct HeavyLight {

    HeavyLight(Graph& tree_, const Graph::NodeMap<Graph::Node>& parents_,
               const Graph::NodeMap<int>& id9, Graph::Node root_ = Graph::Node()) :
    tree(tree_), parents(parents_), subtree_size(id9) {
        this->root = root_.id == -1 ? *tree.nodes().begin() : root_;

        dfs_index.clear();
        chain_parent.clear();
        chain_length.clear();
        timer = 0;
        dfs(root, root);
    }

    Graph::NodeMap<int> dfs_index;
    Graph::NodeMap<Graph::Node> chain_parent;
    Graph::NodeMap<int> chain_length;

    bool inSameChain(const Graph::Node& v, const Graph::Node& u) const {
        return chain_parent(v) == chain_parent(u);
    }

    int getPos(const Graph::Node& v) const {
        return dfs_index(v);
    }

    
    pair<int, int> getIndices(const Graph::Node& v) const {
        auto p = chain_parent(v);
        return {dfs_index(p), dfs_index(v)};
    }

private:
    Graph& tree;
    Graph::Node root;
    const Graph::NodeMap<Graph::Node>& parents;
    const Graph::NodeMap<int>& subtree_size;
    int timer;

    void dfs(const Graph::Node& v, const Graph::Node& chain_p) {
        chain_parent(v) = chain_p;
        dfs_index(v) = timer++;

        Graph::Arc heavy_arc;
        int sz = -1;
        for (auto a : tree.outArcs(v)) {
            auto to = tree.to(a);
            if (to == parents(v)) continue;
            if (sz == -1 || sz < subtree_size(to)) {
                sz = subtree_size(to);
                heavy_arc = a;
            }
        }
        

        

        bool first = true;
        for (auto a : tree.outArcs(v)) {
            auto to = tree.to(a);
            if (to == parents(v)) continue;
            dfs(to, first ? chain_p : to);
            first = false;
        }
    }
};


namespace segment_tree_impl {
    size_t calc_size(size_t n) {
        size_t ret = 1;
        while (ret < n) {
            ret *= 2;
        }
        return ret;
    }
}

template <class T>
struct NoPropagateDown {
    static inline void propagate_down(size_t, size_t, size_t, T&, T&, T&) {}

    
};


template <class T>
struct SimpleFixUp {
    static inline void fix_up(size_t, size_t, size_t, T& p, T& l, T& r) {
        p = T::compose(l, r);
    }
};


template <class T>
struct stree {
    

    template<class F>
    stree(size_t n, F f): n_(n), size(segment_tree_impl::calc_size(n)), ar(2 * size - 1) {
        for (int i = 0; i < n; ++i) {
            ar[size - 1 + i] = f(i);
        }
        init(0, 0, size);
    }

    
    template <class T1 = T>
    T1 sum_range(size_t l, size_t r, T1 v = {}) {
        assert(l <= r && r <= n_);
        if (l == r) {
            return {};
        }
        sum_range(0, 0, size, l, r, v);
        return v;
    }

    
    template <class U>
    void set_value(size_t at, U u) {
        assert(at < n_);
        set_value(0, 0, size, at, u);
    }

    
protected:

    void init(size_t n, size_t nl, size_t nr) {
        if (nl + 1 == nr) {
            return;
        }
        size_t mid = (nl + nr) / 2;
        init(2 * n + 1, nl, mid);
        init(2 * n + 2, mid, nr);
        T::fix_up(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    inline void fix_up(size_t n, size_t nl, size_t mid, size_t nr) {
        T::fix_up(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    inline void propagate_down(size_t n, size_t nl, size_t mid, size_t nr) {
        if (nl + 1 == nr) {
            return;
        }
        T::propagate_down(nl, mid, nr, ar[n], ar[2 * n + 1], ar[2 * n + 2]);
    }

    template <class T1>
    void sum_range(size_t n, size_t nl, size_t nr, size_t l, size_t r, T1& out) {
        assert(l < nr && nl < r);
        size_t mid = (nl + nr) / 2;
        propagate_down(n, nl, mid, nr);
        if (l <= nl && nr <= r) {
            out.compose(ar[n]);
            return;
        }
        if (l < mid) {
            sum_range(2 * n + 1, nl, mid, l, r, out);
        }
        if (mid < r) {
            sum_range(2 * n + 2, mid, nr, l, r, out);
        }
    }

    
    template <class U>
    void set_value(size_t n, size_t nl, size_t nr, size_t at, U u) {
        assert(nl <= at && at < nr);
        if (nl + 1 == nr) {
            ar[n] = {u};
            return;
        }
        size_t mid = (nl + nr) / 2;
        propagate_down(n, nl, mid, nr);
        if (at < mid) {
            set_value(2 * n + 1, nl, mid, at, u);
        } else {
            set_value(2 * n + 2, mid, nr, at, u);
        }
        fix_up(n, nl, mid, nr);
    }

    
    const size_t n_, size;
    vector<T> ar;
};

const int INF = 1000000000;

Graph g;
vector<Graph::Node> nodes;
id11 bcc;
Graph tree;
vector<Graph::Node> tree_nodes;
Graph::NodeMap<int> single_vertex;
LCA lca;
TreeData tree_data;

struct Node : NoPropagateDown<Node>, SimpleFixUp<Node> {
    int mi;
    Node() { mi = INF; }
    Node(int x) : mi(x) {}

    void compose(const Node& o) {
        mi = min(mi, o.mi);
    }

    static Node compose(const Node& le, const Node& ri) {
        return Node(min(le.mi, ri.mi));
    }
};

void changeColor(Graph::Node v, int with_color, const HeavyLight& heavy_light, stree<Node>& segment_tree) {
    segment_tree.set_value(heavy_light.getPos(v), Node(with_color));
}

int id1(Graph::Node from, Graph::Node to, const HeavyLight& heavy_light, stree<Node>& segment_tree) {
    int res = INF;
    while (true) {
        if (heavy_light.inSameChain(from, to)) {
            res = min(res, segment_tree.sum_range(heavy_light.getPos(from), heavy_light.getPos(to) + 1).mi);
            break;
        }
        auto ids = heavy_light.getIndices(to);
        res = min(res, segment_tree.sum_range(ids.first, ids.second + 1).mi);
        to = tree_data.parent(heavy_light.chain_parent(to));
    }
    if (!single_vertex(from)) {
        auto p = tree_data.parent(from);
        if (p.id != -1) {
            res = min(res, id1(p, p, heavy_light, segment_tree));
        }
    }
    return res;
}

int ask(Graph::Node v, Graph::Node u, const HeavyLight& heavy_light, stree<Node>& segment_tree) {
    auto l = lca.lca(u, v);
    if (l == u) return id1(l, v, heavy_light, segment_tree);
    if (l == v) return id1(l, u, heavy_light, segment_tree);
    return min(id1(l, v, heavy_light, segment_tree), id1(l, u, heavy_light, segment_tree));
}

vector<set<pair<int, Graph::Node>>> vertices;

void solve(istream& in, ostream& out) {
    g.clear();
    int n = next<int>(in);
    nodes.clear();
    nodes.resize(n);
    FOR(i, n) nodes[i] = g.addNode();
    int m = next<int>(in);
    int count_q = next<int>(in);
    auto w = next_vector<int>(in, n);
    while (m--) {
        int a = next<int>(in) - 1;
        int b = next<int>(in) - 1;
        g.addEdge(nodes[a], nodes[b]);
    }
    bcc = id11(g);
    bcc.points(true);

    

    n = bcc.component_id;
    tree.clear();
    tree_nodes.clear();
    tree_nodes.resize(n);
    FOR(i, n) {
        tree_nodes[i] = tree.addNode();
    }
    vertices.clear();
    vertices.resize(n);
    single_vertex.clear();
    for (auto v : nodes) {
        vertices[bcc.vertex_color(v)].insert({w[v.id], v});
        if (bcc.is_articulation(v)) {
            set<int> to_edges;
            for (auto a : g.outArcs(v)) {
                to_edges.insert(bcc.edge_color(g.toEdge(a)));
            }
            for (int to : to_edges) {
                tree.addEdge(tree_nodes[bcc.vertex_color(v)], tree_nodes[to]);
            }
        }
    }

    tree_data = TreeData(tree, tree_nodes[0]);
    tree_data.buildSubtreeSizes();
    tree_data.buildDfsOrder();

    for (auto v : nodes) {
        if (bcc.is_articulation(v)) {
            single_vertex(tree_nodes[bcc.vertex_color(v)]) = 1;
            auto p = tree_data.parent(tree_nodes[bcc.vertex_color(v)]);
            if (p.id != -1) {
                vertices[p.id].insert({w[v.id], v});
            }
        }
    }
    lca = LCA(tree, tree_data.dfs_order, tree_data.height);
    HeavyLight heavy_light(tree, tree_data.parent, tree_data.subtree_size);
    stree<Node> id0(n, F1(INF));
    FOR(i, n) {
        id0.set_value(heavy_light.getPos(tree_nodes[i]), vertices[i].begin()->first);
    }
    while (count_q--) {
        string t = next<string>(in);
        int v = next<int>(in) - 1;
        int other = next<int>(in);
        if (t[0] == 'C') {
            int cc = bcc.vertex_color(nodes[v]);
            int prev_weight = w[nodes[v].id];
            vertices[cc].erase({prev_weight, nodes[v]});
            w[nodes[v].id] = other;
            vertices[cc].insert({w[nodes[v].id], nodes[v]});
            int min_color = vertices[cc].begin()->first;
            changeColor(tree_nodes[cc], min_color, heavy_light, id0);

            if (bcc.is_articulation(nodes[v])) {
                auto p = tree_data.parent(tree_nodes[bcc.vertex_color(nodes[v])]);
                if (p.id != -1) {
                    vertices[p.id].erase({prev_weight, nodes[v]});
                    vertices[p.id].insert({w[nodes[v].id], nodes[v]});
                    min_color = vertices[p.id].begin()->first;
                    changeColor(p, min_color, heavy_light, id0);
                }
            }
        } else {
            --other;
            if (v == other) {
                out << w[nodes[v].id] << endl;
                continue;
            }
            out << ask(tree_nodes[bcc.vertex_color(nodes[v])], tree_nodes[bcc.vertex_color(nodes[other])],
                       heavy_light, id0) << endl;
        }
    }

}


int main() {
    solve(cin, cout);
    return 0;
}

