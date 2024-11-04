
NDEBUG
























using namespace std;

template<class T>
using vec = std::vector<T>;

















































































































































































































































































































































































































































































































































































































bool __hack = std::ios::sync_with_stdio(false);


auto id9 = cin.tie(nullptr);



















namespace graph_impl {

    template<class T, class G, T next(const G&, T)>
    struct id2 {
        id2(const G& g_, T t_): g(g_), t(t_) {}

        T operator*() const {
            return t;
        }

        id2& operator++() {
            t = next(g, t);
            return *this;
        }

        
        bool operator!=(const id2& o) const {
            assert(&g == &o.g);
            return t != o.t;
        }
    private:
        const G& g;
        T t;
    };

    template<class T, class G, T next(const G&, T)>
    struct id0 {
        id0(const G& g_, T from_, T to_): g(g_), from(from_), to(to_) {}

        id2<T, G, next> begin() {
            return {g, from};
        };

        id2<T, G, next> end() {
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
    struct id3 {
        id3(int from_, int to_):  from(from_), to(to_) {}

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
        
        bool operator!=(const Node o) const {return id != o.id;}
        

    };

    struct Arc {
        int id;
        explicit Arc(int id_ = -1): id(id_) {}
        
        bool operator!=(const Arc o) const {return id != o.id;}

        
    };

    struct Edge {
        int id;
        explicit Edge(int id_ = -1): id(id_) {}
        
        
    };

    template<class V>
    using NodeMap = graph_impl::GenMap<Node, V>;

    
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

    vector<Node> addNodes(int count) {
        vector<Node> ret(count);
        forn (int, i, count) {
            ret[i] = addNode();
        }
        return ret;
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

    
    graph_impl::id0<Arc, Graph, &Graph::nextOutArc_> outArcs(Node a) const {
        assert(valid(a));
        return graph_impl::id0<Arc, Graph, &Graph::nextOutArc_>(*this, firstOutArc(a), Arc{});
    }

    graph_impl::id3<Node> nodes() const {
        return graph_impl::id3<Node>(0, nodesCount());
    }

    
private:
    vector<graph_impl::NodeT> nodes_;
    vector<graph_impl::ArcT> arcs_;
};


struct LCA {

    
    LCA(const Graph& tree, const vector<Graph::Node>& dfs_order, const Graph::NodeMap<int>& height) {
        this->tree = &tree;
        this->height = &height;
        this->dfs_order = &dfs_order;
        id4 = (int)this->dfs_order->size();

        n = this->tree->nodesCount();
        pos_in_dfs_order.clear();
        for (auto v : this->tree->nodes()) {
            pos_in_dfs_order(v) = -1;
        }
        FOR(i, id4) {
            if (pos_in_dfs_order((*this->dfs_order)[i]) == -1) {
                pos_in_dfs_order((*this->dfs_order)[i]) = i;
            }
        }
        log2 = vector<int>(2 * n);
        id6 = log(id4);
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
    int id4;
    int block;
    vector<vector<int>> block_table;
    int id6;
    vector<int> block_hash;
    vector<vector<vector<int>>> id5;
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
        block = (id6 + 1) / 2;
        int blocks = id4 / block + ((id4 % block > 0) ? 1 : 0);
        int maxBlocks = ((2 * n) / block) + 2;
        block_hash = vector<int>(maxBlocks + 1, 0);
        block_table = vector<vector<int>>(maxBlocks + 1, vector<int>(id6 + 1, -1));
        id5 = vector<vector<vector<int>>>((int) (sqrt(2*n) + 2), vector<vector<int>>(block + 2, vector<int>(block + 2, -1)));

        

        for (int i = 0, blockId = 0, j = 0; i < id4; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (block_table[blockId][0] == -1 || minHeight(i, block_table[blockId][0]) == i) {
                block_table[blockId][0] = i;
            }
        }

        for (int j = 1; j <= id6; ++j) {
            for (int i = 0; i < blocks; ++i) {
                int ni = i + (1 << (j - 1));
                if (ni >= blocks) {
                    block_table[i][j] = block_table[i][j - 1];
                } else {
                    block_table[i][j] = minHeight(block_table[i][j - 1], block_table[ni][j - 1]);
                }
            }
        }

        

        for (int i = 0, blockId = 0, j = 0; i < id4 || j < block; ++i, ++j) {
            if (j == block) {
                j = 0;
                ++blockId;
            }
            if (j > 0 && (i >= id4 || minHeight(i - 1, i) == i - 1)) {
                block_hash[blockId] += (1 << (j - 1));
            }
        }

        

        for (int i = 0; i < blocks; ++i) {
            int id = block_hash[i];
            if (id5[id][0][0] != -1) continue;
            for (int l = 0; l < block; ++l) {
                id5[id][l][l] = l;
                for (int r = l + 1; r < block; ++r) {
                    id5[id][l][r] = id5[id][l][r-1];
                    if (i * block + r < id4) {
                        id5[id][l][r] = minHeight(i * block + id5[id][l][r], i * block + r) - i * block;
                    }
                }
            }
        }

        

        for (int i = 0, j = 0; i < id4; ++i) {
            if (1 << (j + 1) <= i) ++j;
            log2[i] = j;
        }
    }

    int lcaInBlocks(int block_id, int left, int right) {
        return id5[block_hash[block_id]][left][right] + block_id * block;
    }
};


namespace tree {

Graph::NodeMap<Graph::Node> buildParent(const Graph& tree, Graph::Node root = Graph::Node()) {
  root = root.id == -1 ? *tree.nodes().begin() : root;
  Graph::NodeMap<Graph::Node> parent;
  parent.clear();
  parent(root) = Graph::Node();
  vector<Graph::Node> q;
  q.reserve(tree.nodesCount());
  q.push_back(root);
  FOR(qi, q.size()) {
    auto curV = q[qi];
    for (auto a : tree.outArcs(curV)) {
      auto to = tree.to(a);
      if (to != parent(curV)) {
        parent(to) = curV;
        q.push_back(to);
      }
    }
  }
  return parent;
}


void id1(
    const Graph& tree,
    Graph::NodeMap<int>& height,
    Graph::NodeMap<int>& tIn,
    Graph::NodeMap<int>& tOut,
    vector<Graph::Node>& dfsOrder,
    Graph::Node root = Graph::Node()
) {
  root = root.id == -1 ? *tree.nodes().begin() : root;
  int timer = 0;
  height.clear();
  dfsOrder.clear();
  dfsOrder.reserve(2 * tree.nodesCount() - 1);
  tIn.clear();
  tOut.clear();
  for (auto v : tree.nodes()) {
    height(v) = -1;
  }
  std::function<void(const Graph::Node&, int)> dfs = [&](const Graph::Node& v, int h) {
    height(v) = h;
    dfsOrder.push_back(v);
    tIn(v) = timer++;
    for (auto a : tree.outArcs(v)) {
      auto to = tree.to(a);
      if (height(to) != -1) {
        continue;
      }
      dfs(to, h + 1);
      dfsOrder.push_back(v);
    }
    tOut(v) = timer - 1;
  };
  dfs(root, 0);
}


}


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





Graph g;
vec<Graph::Node> nodes;
Graph::NodeMap<Graph::Node> parent;
Graph::NodeMap<int> height;
Graph::NodeMap<int> tIn;
Graph::NodeMap<int> tOut;

void solve(istream& in, ostream& out) {
  auto n = next<int>(in);
  auto k = next<int>(in);

  g.clear();
  nodes = g.addNodes(n);
  FOR(i, n - 1) {
    auto x = next<int>(in) - 1;
    auto y = next<int>(in) - 1;
    g.addEdge(nodes[x], nodes[y]);
  }

  parent = tree::buildParent(g);
  vec<Graph::Node> dfsOrder;
  tree::id1(g, height, tIn, tOut, dfsOrder);
  vec<int> revOrder(n);
  FOR(i, n) {
    revOrder[tIn(nodes[i])] = i;
  }
  dbg(revOrder);
  LCA lca(g, dfsOrder, height);

  auto get = [&] (int v, int u) -> int {
    v = revOrder[v];
    u = revOrder[u];
    auto l = lca.lca(nodes[v], nodes[u]);
    return height(nodes[u]) - height(l);
  };

  int res = 1, ptrRight = -1, total = 1;
  set<int> positions;

  auto id7 = [&] (int i) -> pair<int, int> {
    if (positions.empty()) {
      return {i, i};
    }
    auto it = positions.lower_bound(i);
    int left, right;

    if (it == positions.begin()) {
      left = *positions.rbegin();
    } else {
      --it;
      left = *it;
      ++it;
    }

    if (it != positions.end()) {
      right = *it;
    } else {
      right = *positions.begin();
    }

    return {left, right};
  };

  auto add = [&] (int idx) {
    idx = tIn(nodes[idx]);
    auto lr = id7(idx);
    positions.insert(idx);

    total -= get(lr.first, lr.second);
    total += get(lr.first, idx);
    total += get(idx, lr.second);
  };

  auto remove = [&] (int idx) {
    idx = tIn(nodes[idx]);
    positions.erase(idx);
    auto lr = id7(idx);
    total += get(lr.first, lr.second);
    total -= get(lr.first, idx);
    total -= get(idx, lr.second);
  };

  FOR(i, n) {
    while (ptrRight + 1 < n) {
      add(ptrRight + 1);
      dbg("add", ptrRight + 1, "total =", total);
      if (total <= k) {
        ++ptrRight;
      } else {
        remove(ptrRight + 1);
        dbg("remove", ptrRight + 1, "total = ", total);
        break;
      }
    }
    res = max(res, ptrRight - i + 1);
    remove(i);
    dbg("remove", i, "total = ", total);
  }
  out << res << "\n";
}





int main() {




    solve(cin, cout);


    return 0;
}

