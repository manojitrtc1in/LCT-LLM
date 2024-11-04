










namespace atcoder {

namespace internal {

int id3(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

int bsf(unsigned int n) {

    unsigned long index;
    _BitScanForward(&index, n);
    return index;

    return __builtin_ctz(n);

}

}  


}  



namespace atcoder {

template <class S, S (*op)(S, S), S (*e)()> struct id1 {
  public:
    id1() : id1(0) {}
    explicit id1(int n) : id1(std::vector<S>(n, e())) {}
    explicit id1(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id3(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
};

}  









namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id5 {
  public:
    id5() : id5(0) {}
    explicit id5(int n) : id5(std::vector<S>(n, e())) {}
    explicit id5(const std::vector<S>& v) : _n(int(v.size())) {
        log = internal::id3(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    template <bool (*g)(S)> int max_right(int l) {
        return max_right(l, [](S x) { return g(x); });
    }
    template <class G> int max_right(int l, G g) {
        assert(0 <= l && l <= _n);
        assert(g(e()));
        if (l == _n) return _n;
        l += size;
        for (int i = log; i >= 1; i--) push(l >> i);
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!g(op(sm, d[l]))) {
                while (l < size) {
                    push(l);
                    l = (2 * l);
                    if (g(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*g)(S)> int min_left(int r) {
        return min_left(r, [](S x) { return g(x); });
    }
    template <class G> int min_left(int r, G g) {
        assert(0 <= r && r <= _n);
        assert(g(e()));
        if (r == 0) return 0;
        r += size;
        for (int i = log; i >= 1; i--) push((r - 1) >> i);
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!g(op(d[r], sm))) {
                while (r < size) {
                    push(r);
                    r = (2 * r + 1);
                    if (g(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  







namespace atcoder {

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    std::vector<int> parent_or_size;
};

}  


using namespace std;
using namespace atcoder;


struct edge {
    int from, to;
};

namespace atcoder {

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct id4 {
  public:
    id4() : id4(0) {}
    explicit id4(int n, vector<vector<edge>>& _G) : id4(std::vector<S>(n, e()), _G) {}
    explicit id4(const std::vector<S>& v, vector<vector<edge>>& _G) : _n(int(v.size())) {

        

        N = _n;
        G = _G;
        parent = vector<int>(N, -1);
        id0 = vector<int>(N);
        dfs_size(0, -1);

        depth = vector<int>(N);
        dfs_depth(0, -1);

        pre = vector<int>(N);
        A = vector<int>(N);
        HLD(0, -1, 0);
        


        log = internal::id3(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + pre[i]] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    

    int N;
    vector<vector<edge>> G;
    vector<int> parent;
    vector<int> id0;
    vector<int> depth;

    vector<int> pre;
    vector<int> hld_vec;
    

    vector<int> A;

    void dfs_size(int idx, int par) {
        parent[idx] = par;
        id0[idx] = 1;
        for (auto ee : G[idx]) {
            if (ee.to == par) continue;
            dfs_size(ee.to, idx);
            id0[idx] += id0[ee.to];
        }
    }

    void dfs_depth(int idx, int par) {
        depth[idx] = ((par==-1)?0:(depth[par]+1));
        for (auto ee : G[idx]) {
            if (ee.to == par) continue;
            dfs_depth(ee.to, idx);
        }
    }

    void HLD(int idx, int par, int a) {
        pre[idx] = hld_vec.size();
        hld_vec.push_back(idx);
        A[idx] = a;

        int max_size = 0;
        int max_idx = -1;
        for (auto ee : G[idx]) {
            if (ee.to == par) continue;
            if (id0[ee.to] > max_size) {
                max_size = id0[ee.to];
                max_idx = ee.to;
            }
        }
        if (max_idx == -1) return;
        HLD(max_idx, idx, a);

        for (auto ee : G[idx]) {
            if (ee.to == par) continue;
            if (ee.to != max_idx) HLD(ee.to, idx, ee.to);
        }
    }
    


    void set(int p, S x) {
        

        p = pre[p];
        

        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) {
        

        p = pre[p];
        

        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S prod(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return e();

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        S sml = e(), smr = e();
        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }

        return op(sml, smr);
    }

    

    

    S prod_path(int l, int r) {
        S s_l = e();
        S s_r = e();
        while (A[l] != A[r]) {
            if (depth[A[l]] <= depth[A[r]]) {
                s_r = op(prod(pre[A[r]], pre[r]+1), s_r);
                r = parent[A[r]];
            } else {
                s_l = op(prod(pre[A[l]], pre[l]+1), s_l);
                l = parent[A[l]];
            }
        }
        if (pre[l] <= pre[r]) {
            s_l.reverse();
            return op(op(s_l, prod(pre[l], pre[r]+1)), s_r);
        } else {
            assert(pre[r] < pre[l]);
            s_r.reverse();
            return op(op(s_r, prod(pre[r], pre[l]+1)), s_l);
        }
    }
    

    

    

    

    

    

    

    

    

    

    

    

    

    


    S prod_subtree(int p) {
        return prod(pre[p], pre[p]+id0[p]);
    }
    


    S all_prod() { return d[1]; }

    void apply(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) update(p >> i);
    }
    void apply(int l, int r, F f) {
        assert(0 <= l && l <= r && r <= _n);
        if (l == r) return;

        l += size;
        r += size;

        for (int i = log; i >= 1; i--) {
            if (((l >> i) << i) != l) push(l >> i);
            if (((r >> i) << i) != r) push((r - 1) >> i);
        }

        {
            int l2 = l, r2 = r;
            while (l < r) {
                if (l & 1) all_apply(l++, f);
                if (r & 1) all_apply(--r, f);
                l >>= 1;
                r >>= 1;
            }
            l = l2;
            r = r2;
        }

        for (int i = 1; i <= log; i++) {
            if (((l >> i) << i) != l) update(l >> i);
            if (((r >> i) << i) != r) update((r - 1) >> i);
        }
    }

    

    

    void apply_path(int l, int r, F f) {
        while (A[l] != A[r]) {
            if (depth[A[l]] <= depth[A[r]]) {
                apply(pre[A[r]], pre[r]+1, f);
                r = parent[A[r]];
            } else {
                apply(pre[A[l]], pre[l]+1, f);
                l = parent[A[l]];
            }
        }
        apply(min(pre[l], pre[r]), max(pre[l], pre[r])+1, f);
    }

    void apply_subtree(int p, F f) {
        apply(pre[p], pre[p]+id0[p], f);
    }
    


  private:
    int _n, size, log;
    std::vector<S> d;
    std::vector<F> lz;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
    void all_apply(int k, F f) {
        d[k] = mapping(f, d[k]);
        if (k < size) lz[k] = composition(f, lz[k]);
    }
    void push(int k) {
        all_apply(2 * k, lz[k]);
        all_apply(2 * k + 1, lz[k]);
        lz[k] = id();
    }
};

}  


struct LCA {
    int N;
    int MAX_LOG_N = 60;
    vector<vector<edge>> G;
    vector<vector<int>> parent;
    vector<int> depth;

    LCA(int &N, vector<vector<edge>> &G) {
        this->N = N;
        this->G = G;
        parent = vector<vector<int>>(MAX_LOG_N, vector<int>(N));
        depth = vector<int>(N);
        dfs(0, -1, 0);
        for (int k=0;k+1<MAX_LOG_N;k++) {
            for (int v=0;v<N;v++) {
                if (parent[k][v] < 0) parent[k+1][v] = -1;
                else parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }

    void dfs(int idx, int par, int d) {
        depth[idx] = d;
        parent[0][idx] = par;
        for (auto e : G[idx]) {
            if (e.to == par) continue;
            dfs(e.to, idx, d+1);
        }
    }

    int lca(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        int diff = depth[v]-depth[u];
        for (int k=0;k<MAX_LOG_N;k++) {
            if (diff%2 == 1) v = parent[k][v];
            diff /= 2;
        }

        if (u == v) return u;
        for (int k=MAX_LOG_N-1;k>=0;k--) {
            if (parent[k][u] != parent[k][v]) {
                u = parent[k][u];
                v = parent[k][v];
            }
        }
        return parent[0][u];
    }

    int dist(int u, int v) {
        return depth[u]+depth[v]-2*depth[lca(u, v)];
    }
};


struct S {
    ll sum_val, sz;
};

S op(S a, S b) {
    return S{a.sum_val+b.sum_val, a.sz+b.sz};
}
S e() {
    return S{0, 0};
}

using F = long long;

S mapping(F f, S a) {
    return S{a.sum_val+f*a.sz, a.sz};
}

F composition(F a, F b) {
    return a+b;
}

F id() {
    return 0LL;
}

int n, m;
vector<vector<edge>> G;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    G = vector<vector<edge>>(n, vector<edge>());
    
    dsu d(n);

    vector<pair<int, int>> edges;
    for (int i=0;i<m;i++) {
        int u, v;
        cin >> u >> v;
        u--;v--;
        if (!d.same(u, v)) {
            G[u].push_back(edge{u, v});
            G[v].push_back(edge{v, u});
            d.merge(u, v);
        } else {
            edges.push_back(make_pair(u, v));
        }
    }

    id4<S, op, e, F, mapping, composition, id> seg(n, G);
    for (int i=0;i<n;i++) seg.set(i, S{0, 1});

    LCA id2(n, G);

    for (auto p : edges) {
        int u = p.first;
        int v = p.second;
        int id6 = id2.lca(u, v);
        int dep_u = id2.depth[u];
        int dep_v = id2.depth[v];
        if (id6 == u) {
            int ind = v;
            int dep_rem = dep_v-dep_u-1;
            for (int j=28;j>=0;j--) {
                if ((1<<j)&dep_rem) {
                    ind = id2.parent[j][ind];
                }
            }

            seg.apply_subtree(ind, 1LL);
            seg.apply_subtree(v, -1LL);
        } else if (id6 == v) {

            int ind = u;
            int dep_rem = dep_u-dep_v-1;
            for (int j=28;j>=0;j--) {
                if ((1<<j)&dep_rem) {
                    ind = id2.parent[j][ind];
                }
            }
            seg.apply_subtree(ind, 1LL);
            seg.apply_subtree(u, -1LL);
        } else {
            seg.apply_subtree(0, 1LL);
            seg.apply_subtree(u, -1LL);
            seg.apply_subtree(v, -1LL);
        }
    }

    string ans = "";
    for (int i=0;i<n;i++) {
        if (seg.get(i).sum_val == 0LL) {
            ans += '1';
        } else {
            ans += '0';
        }
        

    }
    cout << ans << "\n";

    return 0;
}