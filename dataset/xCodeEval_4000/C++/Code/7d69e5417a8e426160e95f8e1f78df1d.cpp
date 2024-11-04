#pragma comment(linker, "/STACK:1024000000,1024000000")
#ifndef ONLINE_JUDGE
#include "stdafx.h"
#else
#include<bits/stdc++.h>
#endif
using namespace std;
#pragma region
void makedata() {
    FILE* file;
    freopen_s(&file, "input.txt", "w", stdout);
    for (int i = 0; i <= 200001; i++) cout << 200000 << ' ';
    fclose(stdout);

}
void TLE() {
    for (int i = 0;; i++) {
        if (i % 1234567 == 0) cout << i << endl;
    }
}
void MLE(string s = "") {
    MLE(s + ' ');
}
#pragma endregion

#pragma region
template <typename T> void check_memory(T& vec, int mem_sz) {
    if (vec.size() < mem_sz) vec.resize(mem_sz);
}


template<typename T> vector<int> prefix_function(vector<T>& p) {
    vector<int> prefix(p.size());
    prefix[0] = -1;
    int k = -1;
    for (int i = 0; i < p.size(); i++) {
        while (k != -1 && p[k] != p[i]) k = prefix[k];
        prefix[i] = ++k;
    }
    return prefix;
}


template<typename T> vector<int> z_function(vector<T>& p) {
    vector<int> z(p.size());
    for (int i = 1, l = 0, r = 0; i < p.size(); ++i) {
        if (i <= r && z[i - l] < r - i + 1) z[i] = z[i - l];
        else {
            z[i] = (r - i + 1 > 0 ? r - i + 1 : 0);
            while (i + z[i] < p.size() && p[z[i]] == p[i + z[i]]) ++z[i];
        }
        if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
    }
    return z;
}

template <typename T> class Aho_Corasick_Automaton {
public:
    int sz, key;
    Aho_Corasick_Automaton<T>* father, * fail, * last, * root;
    multiset<T> dataset;
    map<int, Aho_Corasick_Automaton<T>*> subs;

    Aho_Corasick_Automaton() : sz(0), father(NULL), fail(NULL), root(this) {}
    ~Aho_Corasick_Automaton() {
        dataset.clear();
        for (auto i = subs.begin(); i != subs.end(); i++) delete i->second;
        subs.clear();
    }
    bool insert(const vector<int>& indexes, T dat) {
        auto r = this;
        for (int i = 0; i < indexes.size(); i++) {
            int x = indexes[i];
            if (r->subs.find(x) == r->subs.end()) {
                r->subs[x] = new Aho_Corasick_Automaton<T>;
                r->subs[x]->father = r;
                r->subs[x]->key = x;
                r->subs[x]->root = root;
            }
            r->sz++;
            r = r->subs[x];
        }
        r->sz++;
        r->dataset.insert(dat);
        return true;
    }
    bool erase(T dat) {
        if (dataset.find(dat) == dataset.end()) return false;
        else {
            dataset.erase(dat);
            auto r = this;
            while (r != NULL) {
                r->sz--;
                if (r->sz == 0 && r->father != NULL) {
                    auto i = r->father->subs.find(r->key);
                    r = r->father;
                    delete i->second;
                    r->subs.erase(i);
                }
                else r = r->father;
            }
            return true;
        }
    }
    bool erase(const vector<int>& indexes, T dat) {
        auto r = get_pointer(indexes);
        if (r == NULL) return false;
        return r->erase(dat);
    }
    void build() {
        if (this != root) {
            root->build();
            return;
        }
        queue<Aho_Corasick_Automaton*> q;
        fail = root;
        for (auto i = subs.begin(); i != subs.end(); i++) {
            i->second->fail = i->second->last = root;
            q.push(i->second);
        }
        while (!q.empty()) {
            auto r = q.front();
            q.pop();
            for (auto i = r->subs.begin(); i != r->subs.end(); i++) {
                q.push(i->second);
                auto w = r->fail;
                while (w != root && w->subs.find(i->first) == w->subs.end()) w = w->fail;
                i->second->fail = (w->subs.find(i->first) != w->subs.end() ? w->subs[i->first] : root);
            }
        }
    }
    void query(const vector<int>& indexes) {
        auto r = this;
        for (int i = 0; i < indexes.size(); i++) {
            int x = indexes[i];
            while (r != root && r->subs.find(x) != r->subs.end()) r = r->fail;
            if (r->subs.find(x) != r->subs.end()) r = r->subs[x];
            else continue;
            if (r->dataset.size() > 0) {
                ;
            }
        }
    }
    Aho_Corasick_Automaton* get_pointer(const vector<int>& indexes) {
        auto r = this;
        for (int i = 0; i < indexes.size(); i++) {
            int x = indexes[i];
            if (r->sz == 0) return NULL;
            if (r->subs.find(x) == r->subs.end()) return NULL;
            r = r->subs[x];
        }
        return r;
    }
    Aho_Corasick_Automaton* get_kth_min_pointer(int k) {
        if (sz < k) return NULL;
        if (dataset.size() >= k) return this;
        else k -= dataset.size();
        for (auto i = subs.begin(); i != subs.end(); i++) {
            if (i->second->sz >= k) return i->second->get_kth_min_pointer(k);
            k -= i->second->sz;
        }
        return NULL;
    }
    Aho_Corasick_Automaton* get_kth_max_pointer(int k) {
        if (sz < k) return NULL;
        for (auto i = subs.rbegin(); i != subs.rend(); i++) {
            if (i->second->sz >= k) return i->second->get_kth_max_pointer(k);
            k -= i->second->sz;
        }
        if (dataset.size() >= k) return this;
        else return NULL;
    }
};

class DisjointSetUnion {
public:
    int n, root;
    vector<int> father;
    void reset(int sz) {
        check_memory(father, sz);
        for (int i = 0; i < sz; i++) father[i] = i;
        root = sz;
    }
    int getFather(int x) {
        int ret = x, tmp;
        while (ret != father[ret]) ret = father[ret];
        while (x != father[x]) {
            tmp = father[x];
            father[x] = ret;
            x = tmp;
        }
        return ret;
    }
    bool merge(int a, int b) {
        a = getFather(a);
        b = getFather(b);
        if (a == b) return false;
        father[a] = b;
        root--;
        return true;
    }
    ~DisjointSetUnion() {
        father.clear();
    }
};

class Combination {
public:
    vector<long long> fac, inv, f;
    long long mod;
    Combination(long long m, int n) {
        mod = m;
        fac.resize(n);
        inv.resize(n);
        f.resize(n);
        fac[0] = fac[1] = inv[0] = inv[1] = f[0] = f[1] = 1;
        for (int i = 2; i < n; i++) {
            fac[i] = fac[i - 1] * i % mod;
            f[i] = (mod - mod / i) * f[mod % i] % mod;
            inv[i] = inv[i - 1] * f[i] % mod;
        }
    }
    long long permutation(int a, int b) {
        return fac[a] * inv[a - b] % mod;
    }
    long long combination(int a, int b) {
        return fac[a] * inv[b] % mod * inv[a - b] % mod;
    }
    

    long long combination_subsum(int r, int k) {
        return combination(r + k + 1, r + 1);
    }
};


template <typename T> class SegmentTree {
public:
    vector<T> lazy_col, lazy_mul, lazy_add;
    vector<T> sum, maxi, mini, gcd;
    vector<bool> col;
    T e;
    bool gcd_enable;
private:
    int L, R;

public:
    SegmentTree() : gcd_enable(false) {}
    ~SegmentTree() {
        lazy_col.clear();
        lazy_mul.clear();
        lazy_add.clear();
        sum.clear();
        maxi.clear();
        mini.clear();
        col.clear();
    }
    

    void build(int l, int r, T* src) {
        int sz = (r - l) << 2;
        L = l, R = r;
        check_memory(col, sz);
        check_memory(lazy_col, sz);
        check_memory(lazy_mul, sz);
        check_memory(lazy_add, sz);
        check_memory(sum, sz);
        check_memory(maxi, sz);
        check_memory(mini, sz);
        if (gcd_enable) check_memory(gcd, sz);
        do_build(1, l, r, src);
    }
    void build(int l, int r, const vector<T>& src) {
        int sz = (r - l) << 2;
        L = l, R = r;
        check_memory(col, sz);
        check_memory(lazy_col, sz);
        check_memory(lazy_mul, sz);
        check_memory(lazy_add, sz);
        check_memory(sum, sz);
        check_memory(maxi, sz);
        check_memory(mini, sz);
        if (gcd_enable) check_memory(gcd, sz);
        do_build(1, l, r, src);
    }
    void update_col(int l, int r, T u) {
        do_update_col(1, L, R, l, r, u);
    }
    void update_mul(int l, int r, T u) {
        do_update_mul(1, L, R, l, r, u);
    }
    void update_add(int l, int r, T u) {
        do_update_add(1, L, R, l, r, u);
    }
    T query_sum(int l, int r) {
        return do_query_sum(1, L, R, l, r);
    }
    T query_max(int l, int r) {
        return do_query_max(1, L, R, l, r);
    }
    T query_min(int l, int r) {
        return do_query_min(1, L, R, l, r);
    }
    T query_gcd(int l, int r) {
        return do_query_gcd(1, L, R, l, r);
    }

private:
    T euclid(T a, T b) {
        if (b == 0) return a;
        else return euclid(b, a % b);
    }
    void do_build(int rt, int l, int r, T* src) {
        if (l + 1 == r) {
            sum[rt] = maxi[rt] = mini[rt] = src[l];
            if (gcd_enable) gcd[rt] = src[l];
            return;
        }
        int mid = (l + r) >> 1;
        do_build(rt << 1, l, mid, src);
        do_build(rt << 1 | 1, mid, r, src);
        push_up(rt);
        col[rt] = false;
        lazy_mul[rt] = 1;
        lazy_add[rt] = 0;
    }
    void do_build(int rt, int l, int r, const vector<T>& src) {
        if (l + 1 == r) {
            sum[rt] = maxi[rt] = mini[rt] = src[l];
            if (gcd_enable) gcd[rt] = src[l];
            return;
        }
        int mid = (l + r) >> 1;
        do_build(rt << 1, l, mid, src);
        do_build(rt << 1 | 1, mid, r, src);
        push_up(rt);
        col[rt] = false;
        lazy_mul[rt] = 1;
        lazy_add[rt] = 0;
    }
    void do_update_col(int rt, int L, int R, int l, int r, T u) {
        if (l >= r) return;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) {
            col[rt] = true;
            lazy_col[rt] = u;
            lazy_mul[rt] = 1;
            lazy_add[rt] = 0;
            sum[rt] = u * (r - l);
            maxi[rt] = mini[rt] = u;
            return;
        }
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (l < mid) do_update_col(rt << 1, L, mid, l, r, u);
        if (mid < r) do_update_col(rt << 1 | 1, mid, R, l, r, u);
        push_up(rt);
    }
    void do_update_mul(int rt, int L, int R, int l, int r, T u) {
        if (l >= r) return;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) {
            lazy_mul[rt] *= u;
            lazy_add[rt] *= u;
            sum[rt] *= u;
            maxi[rt] *= u;
            mini[rt] *= u;
            return;
        }
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (l < mid) do_update_mul(rt << 1, L, mid, l, r, u);
        if (mid < r) do_update_mul(rt << 1 | 1, mid, R, l, r, u);
        push_up(rt);
    }
    void do_update_add(int rt, int L, int R, int l, int r, T u) {
        if (l >= r) return;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) {
            lazy_add[rt] += u;
            sum[rt] += u * (r - l);
            maxi[rt] += u;
            mini[rt] += u;
            return;
        }
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (l < mid) do_update_add(rt << 1, L, mid, l, r, u);
        if (mid < r) do_update_add(rt << 1 | 1, mid, R, l, r, u);
        push_up(rt);
    }
    T do_query_sum(int rt, int L, int R, int l, int r) {
        if (l >= r) return e;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) return sum[rt];
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        T ans = 0;
        if (l < mid) ans += do_query_sum(rt << 1, L, mid, l, r);
        if (mid < r) ans += do_query_sum(rt << 1 | 1, mid, R, l, r);
        return ans;
    }
    T do_query_max(int rt, int L, int R, int l, int r) {
        if (l >= r) return e;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) return maxi[rt];
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (r <= mid) return do_query_max(rt << 1, L, mid, l, r);
        if (mid <= l) return do_query_max(rt << 1 | 1, mid, R, l, r);
        T al = do_query_max(rt << 1, L, mid, l, r), ar = do_query_max(rt << 1 | 1, mid, R, l, r);
        return al < ar ? ar : al;
    }
    T do_query_min(int rt, int L, int R, int l, int r) {
        if (l >= r) return e;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) return mini[rt];
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (r <= mid) return do_query_min(rt << 1, L, mid, l, r);
        if (mid <= l) return do_query_min(rt << 1 | 1, mid, R, l, r);
        T al = do_query_min(rt << 1, L, mid, l, r), ar = do_query_min(rt << 1 | 1, mid, R, l, r);
        return al < ar ? al : ar;
    }
    T do_query_gcd(int rt, int L, int R, int l, int r) {
        if (l >= r) return e;
        if (l < L) l = L;
        if (R < r) r = R;
        if (l == L && r == R) return gcd[rt];
        push_down(rt, L, R);
        int mid = (L + R) >> 1;
        if (r <= mid) return do_query_gcd(rt << 1, L, mid, l, r);
        if (mid <= l) return do_query_gcd(rt << 1 | 1, mid, R, l, r);
        T al = do_query_gcd(rt << 1, L, mid, l, r), ar = do_query_gcd(rt << 1 | 1, mid, R, l, r);
        return euclid(al, ar);
    }
    void push_up(int rt) {
        sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
        maxi[rt] = maxi[rt << 1] < maxi[rt << 1 | 1] ? maxi[rt << 1 | 1] : maxi[rt << 1];
        mini[rt] = mini[rt << 1] < mini[rt << 1 | 1] ? mini[rt << 1] : mini[rt << 1 | 1];
        if (gcd_enable) gcd[rt] = euclid(gcd[rt << 1], gcd[rt << 1 | 1]);
    }
    void push_down(int rt, int l, int r) {
        int mid = (l + r) >> 1;
        if (col[rt]) {
            col[rt << 1] = true;
            col[rt << 1 | 1] = true;
            lazy_col[rt << 1] = lazy_col[rt << 1 | 1] = lazy_col[rt];
            col[rt] = false;
            lazy_mul[rt << 1] = lazy_mul[rt << 1 | 1] = 1;
            lazy_add[rt << 1] = lazy_add[rt << 1 | 1] = 0;
            sum[rt << 1] = lazy_col[rt] * (mid - l);
            sum[rt << 1 | 1] = lazy_col[rt] * (r - mid);
            maxi[rt << 1] = maxi[rt << 1 | 1] = lazy_col[rt];
            mini[rt << 1] = mini[rt << 1 | 1] = lazy_col[rt];
        }
        if (lazy_mul[rt] != 1) {
            T u = lazy_mul[rt];
            lazy_mul[rt] = 1;
            lazy_mul[rt << 1] *= u;
            lazy_mul[rt << 1 | 1] *= u;
            lazy_add[rt << 1] *= u;
            lazy_add[rt << 1 | 1] *= u;
            sum[rt << 1] *= u;
            sum[rt << 1 | 1] *= u;
            maxi[rt << 1] *= u;
            maxi[rt << 1 | 1] *= u;
            mini[rt << 1] *= u;
            mini[rt << 1 | 1] *= u;
        }
        if (lazy_add[rt]) {
            T u = lazy_add[rt];
            lazy_add[rt] = 0;
            lazy_add[rt << 1] += u;
            lazy_add[rt << 1 | 1] += u;
            sum[rt << 1] += u * (mid - l);
            sum[rt << 1 | 1] += u * (r - mid);
            maxi[rt << 1] += u;
            maxi[rt << 1 | 1] += u;
            mini[rt << 1] += u;
            mini[rt << 1 | 1] += u;
        }
    }
};

template <typename Twv, typename Twe> class Graph {
public:
    

    int graph_sz, bias, mem_sz;
    vector<Twv> weights;
    struct Edge {
        int u, v;
        Twe w;
        bool directed, vaild;
        Edge() {}
        Edge(int uu, int vv, Twe ww, bool dd, bool va) : u(uu), v(vv), w(ww), directed(dd), vaild(va) {}
    };
    vector<Edge> edges;
    vector<vector<pair<int, int> > > concerned_edges;
    

    int root;
    vector<int> father;
    vector<vector<int>> ancestor;
    vector<int> depth, subtree_sz;
    

    vector<int> heavy_son, heavy_path_top, subtree_last_index, vertex_to_index, index_to_vertex;
    vector<Twv> feed_for_segment_tree;
    SegmentTree<Twv> segment_tree;

    

    stack<int> pStack;
    vector<int> dfn, low, inStack;

    vector<pair<int, int> > bridges;
    vector<int> articulation_points;
    vector<int> strongly_connected_component_colour;
    vector<pair<int, int> > dag_edges;
    Graph<Twv, Twe>* dag;

    Graph<Twv, Twe>* mst;

    vector<Twe> shortest_path;

private:
    int top_index, tarjan_dep, tarjan_scc_sz, tarjan_dfs_root;

public:
    Graph() : bias(1) {}
    Graph(int b) : bias(b), mem_sz(0) {}
    ~Graph() {
        weights.clear();
        edges.clear();
        concerned_edges.clear();

        father.clear();
        ancestor.clear();
        depth.clear();
        subtree_sz.clear();

        heavy_son.clear();
        heavy_path_top.clear();
        subtree_last_index.clear();
        vertex_to_index.clear();
        index_to_vertex.clear();
        feed_for_segment_tree.clear();

        dfn.clear();
        low.clear();
        inStack.clear();

        bridges.clear();
        articulation_points.clear();
        strongly_connected_component_colour.clear();

        dag_edges.clear();
        delete dag;

        delete mst;

        shortest_path.clear();
    }
    void reset_graph_sz(int sz) {
        graph_sz = sz;
        mem_sz = graph_sz + bias;
        edges.clear();
        check_memory(concerned_edges, mem_sz);
        for (int i = bias; i < mem_sz; i++) concerned_edges[i].clear();
        check_memory(weights, mem_sz);
    }
    void reset_bias(int b) {
        bias = b;
        mem_sz = graph_sz + bias;
        edges.clear();
        check_memory(concerned_edges, mem_sz);
        for (int i = bias; i < mem_sz; i++) concerned_edges[i].clear();
        check_memory(weights, mem_sz);
    }
    void add_edge(int x, int y, Twe w, bool d) {
        if (x >= mem_sz || y >= mem_sz) return;
        Edge edge(x, y, w, d, true);
        edges.push_back(edge);
        concerned_edges[x].push_back({ y, edges.size() - 1 });
        if (!d) concerned_edges[y].push_back({ x, edges.size() - 1 });
    }
    bool reroot(int x) {
        check_memory(father, mem_sz);
        check_memory(depth, mem_sz);
        for (int i = 0; i < mem_sz; i++) father[i] = -1;
        root = x;
        depth[root] = 0;
        queue<pair<int, int> > q;
        q.push({ x, x });
        while (!q.empty()) {
            auto z = q.front();
            q.pop();
            int u = z.first, v = z.second;
            if (u != v) depth[u] = depth[v] + 1;
            if (father[u] != -1 && father[u] != v) return false;
            if (father[u] == -1) {
                father[u] = v;
                for (int i = 0; i < concerned_edges[u].size(); i++) {
                    auto ce = concerned_edges[u][i];
                    if (!edges[ce.second].vaild) continue;
                    if (ce.first != father[u]) q.push({ ce.first, u });
                }
            }
        }
        for (int i = bias; i < mem_sz; i++) {
            if (father[i] == -1) return false;
        }
        check_memory(subtree_sz, mem_sz);
        get_subtree_size(root);
        return true;
    }
    void initialize_for_least_common_ancestor() {
        check_memory(ancestor, mem_sz);
        int sz = mem_sz, p = 1;
        while (sz) {
            sz >>= 1;
            p++;
        }
        for (int i = bias; i < mem_sz; i++) check_memory(ancestor[i], p);
        for (int i = bias; i < mem_sz; i++) ancestor[i][0] = father[i];
        for (int i = 0; i < p; i++) ancestor[root][i] = -1;
        for (int i = 1; i < p; i++) {
            for (int j = bias; j < mem_sz; j++) {
                if (ancestor[j][i - 1] == -1) ancestor[j][i] = -1;
                else ancestor[j][i] = ancestor[ancestor[j][i - 1]][i - 1];
            }
        }
    }
    int query_least_common_ancestor(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int d = 0;
        while (depth[u] != depth[v]) {
            if ((depth[v] - depth[u]) & (1 << d)) v = ancestor[v][d];
            d++;
        }
        if (u == v) return u;
        for (int i = ancestor[bias].size() - 1; i >= 0; i--) {
            if (ancestor[u][i] != ancestor[v][i]) {
                u = ancestor[u][i];
                v = ancestor[v][i];
            }
        }
        return ancestor[u][0];
    }
    void heavy_light_decomposition() {
        check_memory(heavy_son, mem_sz);
        check_memory(heavy_path_top, mem_sz);
        check_memory(subtree_last_index, mem_sz);
        check_memory(vertex_to_index, mem_sz);
        check_memory(index_to_vertex, mem_sz);
        check_memory(feed_for_segment_tree, mem_sz);
        top_index = 1;
        heavy_light_decomposition_dfs1(root);
        heavy_light_decomposition_dfs2(root, root, 1);
        for (int i = bias; i < mem_sz; i++) feed_for_segment_tree[i] = weights[index_to_vertex[i]];
        segment_tree.build(bias, mem_sz, feed_for_segment_tree);
    }
    void hld_update_path_col(int u, int v, Twv k) {
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            segment_tree.update_col(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1, k);
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        segment_tree.update_col(vertex_to_index[u], vertex_to_index[v] + 1, k);
    }
    void hld_update_path_mul(int u, int v, Twv k) {
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            segment_tree.update_mul(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1, k);
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        segment_tree.update_mul(vertex_to_index[u], vertex_to_index[v] + 1, k);
    }
    void hld_update_path_add(int u, int v, Twv k) {
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            segment_tree.update_add(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1, k);
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        segment_tree.update_add(vertex_to_index[u], vertex_to_index[v] + 1, k);
    }
    void hld_update_subtree_col(int u, Twv k) {
        segment_tree.update_col(vertex_to_index[u], subtree_last_index[u], k);
    }
    void hld_update_subtree_mul(int u, Twv k) {
        segment_tree.update_mul(vertex_to_index[u], subtree_last_index[u], k);
    }
    void hld_update_subtree_add(int u, Twv k) {
        segment_tree.update_add(vertex_to_index[u], subtree_last_index[u], k);
    }
    Twv hld_query_path_sum(int u, int v) {
        bool b = false;
        Twv ret;
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            Twv tmp = segment_tree.query_sum(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1);
            if (b) ret += tmp;
            else {
                ret = tmp;
                b = true;
            }
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        ret += segment_tree.query_sum(vertex_to_index[u], vertex_to_index[v] + 1);
        return ret;
    }
    Twv hld_query_path_max(int u, int v) {
        Twv ret = weights[u];
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            Twv tmp = segment_tree.query_max(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1);
            if (ret < tmp) ret = tmp;
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        Twv tmp = segment_tree.query_max(vertex_to_index[u], vertex_to_index[v] + 1);
        if (ret < tmp) ret = tmp;
        return ret;
    }
    Twv hld_query_path_min(int u, int v) {
        Twv ret = weights[u];
        while (heavy_path_top[u] != heavy_path_top[v]) {
            if (depth[heavy_path_top[u]] < depth[heavy_path_top[v]]) swap(u, v);
            Twv tmp = segment_tree.query_max(vertex_to_index[heavy_path_top[u]], vertex_to_index[u] + 1);
            if (ret > tmp) ret = tmp;
            u = father[heavy_path_top[u]];
        }
        if (vertex_to_index[u] > vertex_to_index[v]) swap(u, v);
        Twv tmp = segment_tree.query_max(vertex_to_index[u], vertex_to_index[v] + 1);
        if (ret > tmp) ret = tmp;
        return ret;
    }
    Twv hld_query_subtree_sum(int u) {
        return segment_tree.query_sum(vertex_to_index[u], subtree_last_index[u]);
    }
    Twv hld_query_subtree_max(int u) {
        return segment_tree.query_max(vertex_to_index[u], subtree_last_index[u]);
    }
    Twv hld_query_subtree_min(int u) {
        return segment_tree.query_min(vertex_to_index[u], subtree_last_index[u]);
    }
    void tarjan() {
        check_memory(dfn, mem_sz);
        check_memory(low, mem_sz);
        check_memory(inStack, mem_sz);
        check_memory(strongly_connected_component_colour, mem_sz);
        bridges.clear();
        articulation_points.clear();
        for (int i = bias; i < mem_sz; i++) dfn[i] = low[i] = inStack[i] = strongly_connected_component_colour[i] = 0;
        while (!pStack.empty()) pStack.pop();
        tarjan_dep = tarjan_scc_sz = 0;
        for (int i = bias; i < mem_sz; i++) {
            if (!dfn[i]) tarjan_dfs(i, i, -1);
        }
        for (int i = bias; i < mem_sz; i++) {
            for (int j = 0; j < concerned_edges[i].size(); j++) {
                auto ce = concerned_edges[i][j];
                if (!edges[ce.second].vaild) continue;
                if (strongly_connected_component_colour[i] != strongly_connected_component_colour[ce.first]) dag_edges.push_back({ strongly_connected_component_colour[i], strongly_connected_component_colour[ce.first] });
            }
        }
        sort(dag_edges.begin(), dag_edges.end());
        if (dag == NULL) dag = new Graph<Twv, Twe>;
        dag->reset_graph_sz(tarjan_scc_sz);
        Twe* twe = new Twe;
        if (dag_edges.size()) dag->add_edge(dag_edges[0].first, dag_edges[0].second, *twe, true);
        for (int i = 1; i < dag_edges.size(); i++) {
            if (dag_edges[i] == dag_edges[i - 1]) continue;
            dag->add_edge(dag_edges[i].first, dag_edges[i].second, *twe, true);
        }
        delete twe;
    }
    
    void dijkstra() {
        vector<bool> vis(mem_sz, false);
        priority_queue<pair<Twe, int>> q;
        for (int i = bias; i < mem_sz; i++) q.push({ -shortest_path[i],i });
        while (!q.empty()) {
            int u = q.top().second;
            q.pop();
            if (vis[u]) continue;
            vis[u] = true;
            for (int i = 0; i < concerned_edges[u].size(); i++) {
                auto& ce = concerned_edges[u][i];
                if (shortest_path[ce.first] > shortest_path[u] + edges[ce.second].w) {
                    shortest_path[ce.first] = shortest_path[u] + edges[ce.second].w;
                    q.push({ -shortest_path[ce.first],ce.first });
                }
            }
        }

    }

private:
    void get_subtree_size(int u) {
        subtree_sz[u] = 1;
        for (int i = 0; i < concerned_edges[u].size(); i++) {
            auto ce = concerned_edges[u][i];
            if (!edges[ce.second].vaild) continue;
            if (ce.first == father[u]) continue;
            get_subtree_size(ce.first);
            subtree_sz[u] += subtree_sz[ce.first];
        }
    }
    void heavy_light_decomposition_dfs1(int u) {
        heavy_son[u] = -1;
        for (int i = 0; i < concerned_edges[u].size(); i++) {
            auto ce = concerned_edges[u][i];
            if (!edges[ce.second].vaild) continue;
            if (ce.first != father[u]) {
                heavy_light_decomposition_dfs1(u);
                if (heavy_son[u] == -1) heavy_son[u] = ce.first;
                else if (subtree_sz[ce.first] > subtree_sz[heavy_son[u]]) heavy_son[u] = ce.first;
            }
        }
    }
    void heavy_light_decomposition_dfs2(int u, int top_vertex) {
        heavy_path_top[u] = top_vertex;
        vertex_to_index[u] = top_index++;
        index_to_vertex[vertex_to_index[u]] = u;
        if (heavy_son[u] == -1) return;
        heavy_light_decomposition_dfs2(heavy_son[u], top_vertex);
        for (int i = 0; i < edges[u].size(); i++) {
            auto ce = concerned_edges[u][i];
            if (!edges[ce.second].vaild) continue;
            if (ce.first != father[u] && ce.first != heavy_son[u]) heavy_light_decomposition_dfs2(ce.first, ce.first);
        }
        subtree_last_index[u] = top_index;
    }
    void tarjan_dfs(int x, int r, int eid) {
        inStack[x] = 1;
        dfn[x] = low[x] = ++tarjan_dep;
        pStack.push(x);
        int child = 0;
        bool is_articulation = false;
        for (int i = 0; i < concerned_edges[x].size(); i++) {
            auto ce = concerned_edges[x][i];
            if (!edges[ce.second].vaild) continue;
            if (ce.second == eid) continue;
            if (dfn[ce.first] == 0) {
                tarjan_dfs(ce.first, r, ce.second);
                child++;
                low[x] = low[x] < low[ce.first] ? low[x] : low[ce.first];
                if (dfn[x] < low[ce.first]) bridges.push_back({ x, i });
                if (dfn[x] <= low[ce.first] && x != r) is_articulation = true;
            }
            else if (inStack[ce.first]) low[x] = low[x] < dfn[ce.first] ? low[x] : dfn[ce.first];
        }
        if (x == r && child > 1) is_articulation = true;
        if (is_articulation) articulation_points.push_back(x);
        if (low[x] == dfn[x]) {
            ++tarjan_scc_sz;
            while (!pStack.empty()) {
                int u = pStack.top();
                pStack.pop();
                inStack[u] = 0;
                strongly_connected_component_colour[u] = tarjan_scc_sz;
                if (u == x) break;
            }
        }
    }
};

class Machine_2_SAT {
public:
    int machine_sz;
    Graph<int, int> graph;
    vector<int> result, conflict;
private:
    int bias, mem_sz;

public:
    Machine_2_SAT() : bias(1), mem_sz(0) {}
    Machine_2_SAT(int b) : bias(b), mem_sz(0) {}
    void reset_machine_sz(int sz) {
        machine_sz = sz;
        mem_sz = machine_sz + bias;
        graph.reset_graph_sz(sz << 1);
        check_memory(result, mem_sz);
        check_memory(conflict, mem_sz);
    }
    void reset_bias(int b) {
        bias = b;
        mem_sz = machine_sz + bias;
        graph.reset_bias(b << 1);
        check_memory(result, mem_sz);
        check_memory(conflict, mem_sz);
    }
    void add_constraint_must_not_choose(int u) {
        graph.add_edge(u << 1 | 1, u << 1, 1, true);
    }
    void add_constraint_must_choose(int u) {
        graph.add_edge(u << 1, u << 1 | 1, 1, true);
    }
    void add_constraint_must_on_same_side(int u, int v) {
        graph.add_edge(u << 1, v << 1, 1, true);
        graph.add_edge(u << 1 | 1, v << 1 | 1, 1, true);
        graph.add_edge(v << 1, u << 1, 1, true);
        graph.add_edge(v << 1 | 1, u << 1 | 1, 1, true);
    }
    void add_constraint_must_on_different_side(int u, int v) {
        graph.add_edge(u << 1, v << 1 | 1, 1, true);
        graph.add_edge(u << 1 | 1, v << 1, 1, true);
        graph.add_edge(v << 1, u << 1 | 1, 1, true);
        graph.add_edge(v << 1 | 1, u << 1, 1, true);
    }
    void add_constraint_choose_at_least_one(int u, int v) {
        graph.add_edge(u << 1, v << 1 | 1, 1, true);
        graph.add_edge(v << 1, u << 1 | 1, 1, true);
    }
    void run() {
        for (int i = bias; i < mem_sz; i++) conflict[i] = -1;
        for (int i = bias; i < mem_sz; i++) {
            if (conflict[i] == -1) conflict[i] = dfs(i);
        }
    }
private:
    int dfs(int u) {
    }
};


template <typename T> class Convex_Hull_Trick {
public:
    vector<pair<T, T> > lines;
    map<T, T> slope2intercept;
    vector<pair<pair<T, T>, double> > extremum;
    ~Convex_Hull_Trick() { clear(); }
    void clear() {
        lines.clear();
        slope2intercept.clear();
        extremum.clear();
    }
    void minimize() {
        slope2intercept.clear();
        for (int i = 0; i < lines.size(); i++) {
            auto& line = lines[i];
            if (slope2intercept.find(line.first) != slope2intercept.end()) slope2intercept[line.first] = slope2intercept[line.first] < line.second ? slope2intercept[line.first] : line.second;
            else slope2intercept[line.first] = line.second;
        }
        extremum.clear();
        for (auto i = slope2intercept.rbegin(); i != slope2intercept.rend(); i++) {
            while (extremum.size() > 1) {
                auto ex = extremum[extremum.size() - 2];
                if ((double)(ex.first.second - i->second) / (double)(i->first - ex.first.first) <= ex.second) extremum.pop_back();
                else break;
            }
            if (!extremum.empty()) {
                auto& ex = extremum.back();
                ex.second = (double)(ex.first.second - i->second) / (double)(i->first - ex.first.first);
            }
            extremum.push_back({ {i->first,i->second}, 1e18 });
        }
    }
    void maximize() {
        slope2intercept.clear();
        for (int i = 0; i < lines.size(); i++) {
            auto& line = lines[i];
            if (slope2intercept.find(line.first) != slope2intercept.end()) slope2intercept[line.first] = slope2intercept[line.first] > line.second ? slope2intercept[line.first] : line.second;
            else slope2intercept[line.first] = line.second;
        }
        extremum.clear();
        for (auto i = slope2intercept.begin(); i != slope2intercept.end(); i++) {
            while (extremum.size() > 1) {
                auto ex = extremum[extremum.size() - 2];
                if ((double)(ex.first.second - i->second) / (double)(i->first - ex.first.first) <= ex.second) extremum.pop_back();
                else break;
            }
            if (!extremum.empty()) {
                auto& ex = extremum.back();
                ex.second = (double)(ex.first.second - i->second) / (double)(i->first - ex.first.first);
            }
            extremum.push_back({ {i->first,i->second}, 1e18 });
        }
    }
    T query(T x) {
        if (extremum.empty()) return 0;
        int l = -1, r = extremum.size() - 1;
        while (l + 1 < r) {
            int mid = (l + r) >> 1;
            if (extremum[mid].second < x) l = mid;
            else r = mid;
        }
        return extremum[r].first.first * x + extremum[r].first.second;
    }
};
#pragma endregion

int TestCase, epoch;












int main() {
    

#ifndef ONLINE_JUDGE
    FILE* file;
    freopen_s(&file, "input.txt", "r", stdin);
    

#endif
    std::ios::sync_with_stdio(0), cin.tie(0);

    TestCase = 1;
    cin >> TestCase;

    for (epoch = 1; epoch <= TestCase; epoch++) {
        long long n;
        cin >> n;
        cout << n + n / 3 * 2 + n / 2 * 2 << endl;
    }

    return 0;
}
