
























using namespace std;


using namespace std;

const long long INF = 1LL << 60;


class id0 {
    public:
        id0(int n) : N(n), data(N, 0) {
            h = 0;
            while (1 << (h + 1) <= N) {
                ++h;
            }
        }

        void reset() {
            fill(data.begin(), data.end(), 0);
        }

        void put(int x, long long v) {
            assert(x >= 0);
            for (; x < N; x |= x + 1) {
                data[x] += v;
            }
        }

        long long get(int x) {
            assert(x < N);
            long long res = 0;
            for (; x >= 0; x = (x & (x + 1)) - 1) {
                res += data[x];
            }
            return res;
        }


        long long get(int l, int r) {
            if (l > r) {
                return 0;
            }
            return get(r) - get(l - 1);
        }

    private:
        int N;
        int h;
        vector<long long> data;
};

class SegmentTree {
public:
    SegmentTree(int sz = 4) : n(sz), N(n << 1), h(0), data(N, INF), chg(N, INF) {
        

        while (1 << h < N) {
            ++h;
        }
    }

    void update(int x, long long v) {
        data[x] = min(data[x], v);

        if (x < n) {
            chg[x] = min(chg[x], v);

        }
    }

    void pull(int x) {
        for (int p = x >> 1; p > 0; p >>= 1) {
            if (chg[p] == INF) {
                data[p] = min(data[p << 1], data[p << 1 | 1]);
            }
        }
    }

    void push(int x) {
        for (int i = h; i >= 0; --i) {
            int p = x >> i;
            if (chg[p] < INF) {
                update(p << 1, chg[p]);
                update(p << 1 | 1, chg[p]);
                chg[p] = INF;
            }
        }
    }

    void put(int l, int r, long long v) {
        l += n;
        r += n;
        auto ll = l, rr = r;
        push(ll);
        if (ll != rr) {
            push(rr);
        }
        while (l <= r) {
            if (l & 0x1) {
                update(l++, v);
            }
            if ((r & 0x1) == 0) {
                update(r--, v);
            }
            l >>= 1;
            r >>= 1;
        }

        pull(ll);
        if (ll != rr) {
            pull(rr);
        }
    }

    void put(int x, long long v) {
        x += n;
        push(x);
        update(x, v);
        pull(x);
    }

    long long get(int l, int r) {
        long long res = INF;
        l += n;
        r += n;
        push(l);
        if (l != r)  {
            push(r);
        }

        while (l <= r) {
            if (l & 0x1) {
                res = min(res, data[l++]);
            }
            if ((r & 0x1) == 0) {
                res = min(res, data[r--]);
            }
            l >>= 1;
            r >>= 1;
        }
        return res;
    }

private:
    int n;
    int N;
    int h;
    vector<long long> data;
    vector<long long> chg;
};



class HLD {
    public:
        HLD(const vector<vector<int>>& _G = {}, int _rt = 0) : N(_G.size()), rt(_rt), graph(_G) {
            if (N == 0) {
                return;
            }
            indices.clear(), indices.resize(N, {-1,-1});
            depths.clear(), depths.resize(N, 0);
            sizes.clear(), sizes.resize(N, 0);
         
            h = 0;
            while (1 << (h + 1) <= N) {
                ++h;
            }
            pars.clear(),pars.resize(N, vector<int>(h + 1, -1));
            
            ins.clear(), ins.resize(N, 0);
            outs.clear(), outs.resize(N, 0);

            int clk = 0;
            dfs0(rt, -1, 0, clk); 

            int pidx = 0, idx = 0;
            paths.clear();
            paths.emplace_back();
            acc.clear();
            acc.resize(N + 1, 0);
            dfsBuild(rt, -1, pidx, idx); 

            acc[pidx + 1] = acc[pidx] + paths[pidx].size();
            assert(acc[pidx+1] == N);

            st = SegmentTree(N + 10);
        }

        

        int index(int u) {
            return acc[indices[u].first] + indices[u].second;
        }

        

        int indexE(int u) {
            return ins[u];
        }

        bool isAncestor(int u, int v) {
            return ins[u] <= ins[v] && outs[v] <= outs[u];
        }

        int kthAncestor(int u, int K) {
            if (K > depths[u]) {
                return rt;
            }
            for (int i = h; i >= 0; --i) {
                if (K >> i & 1) {
                    u = pars[u][i];
                }
            }
            return u;
        }

        int parent(int u) {
            return u == rt ? -1 : pars[u][0];
        }

        int LCA(int u, int v) {
            if (u == -1 || v == -1) { return u == -1 ? v : u; }
            if (u == v) { return u; }
            if (depths[u] > depths[v]) { swap(u, v); }
            if (isAncestor(u, v)) { return u; }
            int diff = depths[v] - depths[u];
            for (int i = h; i >= 0; --i) {
                if ((diff >> i) & 1) {
                    v = pars[v][i];
                }
            }
            for (int i = h; i >= 0; --i) {
                if (pars[u][i] != pars[v][i]) {
                    u = pars[u][i], v = pars[v][i];
                }
            }
            return pars[u][0];
        }

        int distanceBetween(int u, int v) {
            int p = LCA(u, v);
            return depths[u] + depths[v] - 2 * depths[p];
        }
        
        

        

        void update(int u, int v, long long val, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }

            

            updatePath(u, p, val);
            updatePath(v, p, val);

        }



        

        

        void updatePath(int u, int t, long long val) {
            

            int cp = indices[u].first, ci = indices[u].second;
            int tp = indices[t].first, ti = indices[t].second;
            

            while (cp != tp) {
                int l = acc[cp], r = l + ci;
                st.put(l, r, val);
                u = paths[cp][0];
                u = pars[u][0];
                cp = indices[u].first, ci = indices[u].second;
            }
            if (ci > ti) {

                int l = acc[tp] + ti + 1, r = acc[tp] + ci;
                st.put(l, r, val);
            }
        }

        

        long long query(int v) {
            v = acc[indices[v].first] + indices[v].second;
            return st.get(v, v);
        }

        

        long long query(int u, int v, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }
            assert(0);


            long long res = INF;
            res = min(res, queryPath(u, p));
            res = min(res, queryPath(v, p));

            return res;
        }

        

        long long queryPath(int u, int t) {
            assert(isAncestor(t, u));
            assert(0); 

            long long res = INF;
            int cp = indices[u].first, ci = indices[u].second;
            int tp = indices[t].first, ti = indices[t].second;
            

            while (cp != tp) {
                int l = acc[cp], r = l + ci;
                res = min(res, st.get(l, r));
                u = paths[cp][0];
                u = pars[u][0];
                cp = indices[u].first, ci = indices[u].second;
            }
            if (ci > ti) {

                int l = acc[tp] + ti + 1, r = acc[tp] + ci;
                res = min(res, st.get(l, r));
            }
            return res;
        }

        vector<pair<int,int>> querySegments(int u, int v, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }
            vector<pair<int,int>> res;
            for (auto& P : querySegmentsOnPath(u, p)) {
                res.push_back(P);
            }
            for (auto& P : querySegmentsOnPath(v, p)) {
                res.push_back(P);
            }
            return res;
        }

        vector<pair<int,int>> querySegmentsOnPath(int u, int t) {
            assert(isAncestor(t, u));
            vector<pair<int,int>> res;
            int cp = indices[u].first, ci = indices[u].second;
            int tp = indices[t].first, ti = indices[t].second;
            

            while (cp != tp) {
                int l = acc[cp], r = l + ci;
                res.emplace_back(l, r);
                u = paths[cp][0];
                u = pars[u][0];
                cp = indices[u].first, ci = indices[u].second;
            }
            if (ci > ti) {

                int l = acc[tp] + ti + 1, r = acc[tp] + ci;
                res.emplace_back(l, r);
            }
            return res;

        }

        

        long long querySubtree(int u) {
            int l = acc[indices[u].first] + indices[u].second;
            int r = l + sizes[u] - 1;
            return st.get(l + 1, r); 

        }

        

        void updateSubtree(int u, long long val) {
            int l = acc[indices[u].first] + indices[u].second;
            int r = l + sizes[u] - 1;
            st.put(l + 1, r, val);
        }

        

        

        void initSparseTable(vector<long long>& A) {
            values.clear(),values.resize(N, vector<long long>(h + 1, -INF));    
            function<void(int,int)> DFS = [&](int u, int p) {
                values[u][0] = A[u];
                for (int i = 1; i <= h; ++i) {
                    values[u][i] = values[u][i - 1];
                    if (pars[u][i - 1] >= 0) {
                        values[u][i] = max(values[u][i], values[pars[u][i - 1]][i - 1]);
                    }
                }
                for (auto v : graph[u]) {
                    if (v == p) { continue; }
                    DFS(v, u);
                }
            };
            DFS(rt, -1);
        }

        

        

        long long querySparseTable(int u, int K) {
            long long res = -INF;
            for (int i = h; i >= 0; --i) {
                if (K >> i & 1) {
                    res = max(res, values[u][i]);
                    u = pars[u][i];
                } 
            }
            return res;
        }

        

        

        long long queryPathSparseTable(int u, int v, int p = -1) {
            if (p < 0) {
                p = LCA(u, v);
            } else {
                assert(isAncestor(p, u));
                assert(isAncestor(p, v));
            }
            long long res = -INF;
            if (depths[p] < depths[u]) {
                res = max(res, querySparseTable(u, depths[u] - depths[p]));
            }
            if (depths[p] < depths[v]) {
                res = max(res, querySparseTable(v, depths[v] - depths[p]));
            }
            return res;
        }

    private:
        int N;
        int rt;
        int h;
        vector<vector<int>> graph;
        vector<pair<int,int>> indices;
        vector<int> depths;
        vector<int> sizes;
        vector<vector<int>> pars;
        vector<int> ins;
        vector<int> outs;
        vector<vector<int>> paths;
        vector<int> acc;

        vector<vector<long long>> values;
        SegmentTree st;

        

        void dfs0(int u, int p, int d, int& clock) {
            ins[u] = ++clock;
            pars[u][0] = p;
            for (int i = 0; i < h; ++i) {
                if (pars[u][i] < 0) { break; }
                pars[u][i + 1] = pars[pars[u][i]][i];
            }

            depths[u] = d;
            sizes[u] = 1;
            for (auto v : graph[u]) {
                if (v == p) { continue; }
                dfs0(v, u, d + 1, clock);
                sizes[u] += sizes[v];
            }

            outs[u] = clock;
        }

        

        void dfsBuild(int u, int p, int& pidx, int& idx) {
            indices[u] = {pidx, idx};
            assert((int)paths[pidx].size() == idx);
            paths[pidx].push_back(u);
            int w = -1;
            for (auto v : graph[u]) {
                if (v == p) { continue; }
                if (w == -1 || sizes[w] < sizes[v]) {
                    w = v;
                }
            }
            if (w >= 0) {
                ++idx;
                dfsBuild(w, u, pidx, idx);
            }
            for (auto v : graph[u]) {
                if (v == p || v == w) { continue; }
                ++pidx;
                acc[pidx] = acc[pidx - 1] + paths[pidx - 1].size();
                idx = 0;
                paths.emplace_back();
                dfsBuild(v, u, pidx, idx);
            }
        }
};



class Solution {
public:
    void init(vector<pair<int,int>>& edges, int maxDistance = 20) {
        N = (int) edges.size() + 1;
        rt = 0;
        graph.clear();
        graph.resize(N);
        MAXD = maxDistance;
        for (auto& e : edges) {
            int u = e.first, v = e.second;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        hld = HLD(graph, rt);
        bits.resize(MAXD + 1, N + 10);
        sums.clear();
        sums.resize(MAXD + 1, vector<int>(N + 1, 0));

    }

    void update(int u, int v, int K, int d) {
        auto p = hld.LCA(u, v);
        auto P = hld.querySegments(u, v, p);
        for (auto [l, r] : P) {
            bits[d].put(l, K);
            bits[d].put(r + 1, -K);
        }
        int cur = p;
        for (int i = 0; i <= d && cur >= 0; ++i) {
            sums[d - i][cur] += K;
            cur = hld.parent(cur);
        }
    }

    int query(int v) {
        int res = 0;
        int cur = v;
        for (int i = 0; i <= MAXD; ++i) {
            if (cur == rt) {
                for (int j = i; j <= MAXD; ++j) {
                    res += bits[j].get(hld.index(rt));
                    res += sums[j][rt];
                }
                break;
            } else {
                res += bits[i].get(hld.index(cur));
                res += sums[i][cur];
                if (i + 1 <= MAXD) {
                    res += sums[i + 1][cur];
                }
            }
            cur = hld.parent(cur);
        }

        return res;
    }

private:
    int N;
    int rt;
    int MAXD;
    vector<vector<int>> graph;
    HLD hld;
    vector<id0> bits;
    vector<vector<int>> sums;
};

int main(int argc, char** argv) {
    ios::sync_with_stdio(false);
    cin.tie(0);

    Solution sol;
    int n;
    cin >> n;
    vector<pair<int,int>> edges;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        edges.emplace_back(u, v);
    }

    sol.init(edges);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int t;
        cin >> t;
        if (t == 1) {
            int v;
            cin >> v;
            --v;
            cout << sol.query(v) << '\n';
        } else {
            int u, v, K, d;
            cin >> u >> v >> K >> d;
            --u, --v;
            sol.update(u, v, K, d);
        }
    }

    return 0;
}