
























clock_t id2 = clock();













using namespace std;


static struct id5 {
    string what;
    id5(const char* what) : what(what){};
    id5(const string& what) : what(what){};
    ~id5(){
        TIMESTAMPf("%s", what.data());
    }
} id1("end");

struct id5 {};

const int INF = 1e9;

typedef long long ll;
typedef long double ld;

template<typename cap_t, typename excess_t, bool id4 = true, bool id0 = false, bool shuffle_edges = false>
class id6{
public:
    struct Edge{
        int to, rev;
        cap_t f, pushed{0};
    };

    id6(int n_):n(n_), m(0){}

    void add_edge(int u, int v, cap_t c, cap_t c_rev = 0){
        edge_pool.emplace_back(u, v, c, c_rev);
        ++m;
    }
    excess_t max_flow(int s_, int t_){
        s = s_; t = t_;
        run_pr();
        return excess[t]-1;
    }

private:
    void compile_g(){
        g_pos.resize(n+1);
        if(shuffle_edges) random_shuffle(edge_pool.begin(), edge_pool.end());
        for(auto &e:edge_pool){
            ++g_pos[get<0>(e)];
            ++g_pos[get<1>(e)];
        }
        for(int i=0;i<n;++i){
            g_pos[i+1]+=g_pos[i];
        }
        g.resize(g_pos.back());
        for(auto &e:edge_pool){
            int u, v; cap_t c, c_rev;
            tie(u, v, c, c_rev) = e;
            const int i = --g_pos[u], j = --g_pos[v];
            g[i] = Edge{v, j, c, 0};
            g[j] = Edge{u, i, c_rev, 0};
        }
    }
    void global_relabel(){
        q.reserve(n);
        fill(h.begin(), h.end(), n);
        fill(h_cnt.begin(), h_cnt.end(), 0);
        h_cnt[n] = 1;
        q.push_back(t);
        h[t] = 0;
        for(auto &e:buck) e.clear();
        for(auto &e:buck_all) e.clear();
        for(auto it = q.begin();it<q.end();++it){
            const int u = *it;
            if(u != t && excess[u]){
                hi = h[u];
                buck[h[u]].push_back(u);
            }
            if(u != t) buck_all[h[u]].push_back(u);
            ++h_cnt[h[u]];
            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                Edge const&e = g[i];
                if(g[e.rev].f && h[e.to] == n){
                    h[e.to] = h[u]+1;
                    q.push_back(e.to);
                }
            }
        }
        hi_all = h[q.back()];
        assert(h[s] == n);
        q.clear();
    }
    void push(int u, Edge &e, excess_t f){
        if(!excess[e.to]){
            buck[h[e.to]].push_back(e.to);
        }
        Edge&back = g[e.rev];
        e.f-=f;
        e.pushed += f;
        back.f+=f;
        back.pushed -= f;
        excess[e.to]+=f;
        excess[u]-=f;
    }
    void init_pr(){
        compile_g();
        cur.assign(n, 0);
        copy(g_pos.begin(), prev(g_pos.end()), cur.begin());
        h.resize(n);
        excess.assign(n, 0);
        buck.resize(2*n);
        buck_all.resize(n+1);
        h_cnt.assign(2*n, 0);
        h[s] = n;
        h_cnt[n] = 1;
        h_cnt[0] = n-1;
        excess[t] = 1;
    }
    void run_pr(){
        init_pr();
        for(int i = g_pos[s],i_end = g_pos[s+1];i < i_end;++i){
            push(s, g[i], g[i].f);
        }
        hi = hi_all = 0;
        if(id4) global_relabel();
        if(!buck[hi].empty())
            for(;hi>=0;){
                int u = buck[hi].back(); buck[hi].pop_back();
                int u_cur = cur[u];
                

                if(!id0 || h[u] < n)
                    while(excess[u] > 0){
                        if(__builtin_expect(u_cur == g_pos[u+1], false)){
                            int new_h = 1e9;
                            for(int i = g_pos[u],i_end = g_pos[u+1];i < i_end;++i){
                                auto const&e = g[i];
                                if(e.f && new_h > h[e.to]+1){
                                    new_h = h[e.to]+1;
                                    u_cur = i;
                                }
                            }
                            ++h_cnt[new_h];
                            h[u] = new_h;
                            if(__builtin_expect(!--h_cnt[hi] && hi < n, false)){
                                

                                for(int j = hi;j <= hi_all;++j){
                                    for(auto &f:buck_all[j]) if(!id0 || h[f] < n){
                                            --h_cnt[h[f]];
                                            h[f] = n+1;
                                        }
                                    buck_all[j].clear();
                                }
                            }
                            hi = h[u];
                        } else {
                            Edge &e_cur = g[u_cur];
                            if(e_cur.f && h[u] == h[e_cur.to]+1){
                                push(u, e_cur, min<excess_t>(excess[u], e_cur.f));
                            } else ++u_cur;
                        }
                    }
                if(h[u] < n) {
                    hi_all = max(hi_all, h[u]);
                    buck_all[h[u]].push_back(u);
                }
                cur[u] = u_cur;
                while(hi>=0 && buck[hi].empty()) --hi;
            }
    }

    int n, m, s, t, hi, hi_all;
    vector<tuple<int, int, cap_t, cap_t> > edge_pool;
    vector<int> g_pos;
    vector<Edge> g;
    vector<int> q, cur, h, h_cnt;
    vector<excess_t> excess;
    vector<vector<int> > buck, buck_all;

    vector<int> vct;
    vector<int> ptr;
    bool dfs(int v) {
        vct.push_back(v);
        if (v == n - 1) {
            return true;
        }
        while (ptr[v] < g_pos[v + 1]) {
            auto &e = g[ptr[v]];
            if (e.pushed > 0) {
                if (dfs(e.to)) {
                    e.pushed--;
                    g[e.rev].pushed++;
                    return true;
                }
            }
            ptr[v]++;
        }
        vct.pop_back();
        return false;
    }

public:
    void dump() {
        for (int i = 0; i < n; i++) {
            for (int j = g_pos[i]; j < g_pos[i + 1]; j++ ){
                auto &e = g[j];
                auto &re = g[e.rev];
                db2(i, e.to);
                db2(e.f, re.f);
            }
        }
        db("");
    }
    vector<vector<int>> restore() {

        ptr.assign(n, 0);
        for (int i = 0; i < n; i++) ptr[i] = g_pos[i];

        vector<vector<int>> ans;
        while (dfs(0)) {


            ans.push_back(vct);
            vct.clear();
        }
        return ans;
    }
};

id6<int, int> gr(2);





const int N = 1 << 18;
int vert[N];

struct id3 {
    int n, N;

    id3() {}
    id3(int _n) {
        n = _n;
        N = 1;
        while (N < n) N <<= 1;




        gr = id6<int, int>(1 + n + 2*N + n + 1);


        for (int v = N - 1; v >= 1; v--) {
            gr.add_edge(1 + n + v, 1 + n + v * 2, INF);
            gr.add_edge(1 + n + v, 1 + n + v * 2 + 1, INF);
        }
        for (int i = 0; i < n; i++) {
            gr.add_edge(1 + n + N + i, 1 + n + N*2 + vert[i], 1);
        }
        for (int i = 0; i < n; i++) {
            gr.add_edge(0, 1 + i, 1);
            gr.add_edge(1 + n + N*2 + i, 1 + n + N*2 + n, 1);
        }
    }

    void get(int v, int from) {
        gr.add_edge(1 + from, 1 + n + v, 1);
    }

    void get(int l, int r, int from) {
        l += N;
        r += N;
        while (l <= r) {
            if (l & 1) get(l, from);
            if (!(r & 1)) get(r, from);
            l = (l + 1) >> 1;
            r = (r - 1) >> 1;
        }
    }
};

namespace hld {
    int par[N], heavy[N], h[N];
    int root[N], pos[N];
    int n;
    vector<vector<int> > e;
    id3 tree;

    int dfs(int v) {
        int sz = 1, mx = 0;
        for (int to : e[v]) {
            if (to == par[v]) continue;
            par[to] = v;
            h[to] = h[v] + 1;
            int cur = dfs(to);
            if (cur > mx) heavy[v] = to, mx = cur;
            sz += cur;
        }
        return sz;
    }

    template <typename T>
    void path(int u, int v, T op) {
        for (; root[u] != root[v]; v = par[root[v]]) {
            if (h[root[u]] > h[root[v]]) swap(u, v);
            op(pos[root[v]], pos[v]);
        }
        if (h[u] > h[v]) swap(u, v);
        op(pos[u] + 1, pos[v]);
    }

    void init(vector<vector<int> > _e) {
        e = _e;
        n = e.size();
        memset(heavy, -1, sizeof(heavy[0]) * n);
        par[0] = -1;
        h[0] = 0;
        dfs(0);
        for (int i = 0, cpos = 0; i < n; i++) {
            if (par[i] == -1 || heavy[par[i]] != i) {
                for (int j = i; j != -1; j = heavy[j]) {
                    root[j] = i;
                    vert[cpos] = j;
                    pos[j] = cpos++;
                }
            }
        }
        tree = id3(n);
    }

    void get(int u, int v, int from) {
        path(u, v, [&](int l, int r) {
            tree.get(l, r, from);
        });
    }
}


vector<pair<pair<int, int>, pair<int, int>>> solve(vector<pair<int, int>> e1, vector<pair<int, int>> e2) {
    int n = e1.size() + 1;

    vector<vector<int>> e(n);
    for (auto o : e1) {
        e[o.first].push_back(o.second);
        e[o.second].push_back(o.first);
    }
    hld::init(e);

    vector<pair<pair<int, int>, pair<int, int>>> ans;
    for (int i = 0; i < n - 1; i++) {
        hld::get(e2[i].first, e2[i].second, i);
    }
    int res = gr.max_flow(0, 1 + n + 2*hld::tree.N + n);
    auto tmp = gr.restore();


    assert(tmp.size() == res);
    for (auto v : tmp) {
        int v1 = v[1] - 1;
        int v2 = v[(int)v.size() - 2] - 1 - n - 2 * hld::tree.N;
        ans.push_back({{v2, hld::par[v2]}, e2[v1]});
    }
    return ans;
}

void print(vector<pair<pair<int, int>, pair<int, int>>> a) {
    printf("%d\n", (int)a.size());
    for (auto o : a) {
        printf("%d %d %d %d\n", o.first.first + 1, o.first.second + 1, o.second.first + 1, o.second.second + 1);
    }
}

void test() {
    int n = 2e5;
    mt19937 rnd;
    auto gen = [&](int n) {
        vector<pair<int, int>> e;
        for (int i = 1; i < n; i++) {
            e.push_back({rnd() % i, i});
        }
        return e;
    };
    auto e1 = gen(n);
    auto e2 = gen(n);
    solve(e1, e2);

}

int main() {

    freopen("in", "r", stdin);




    int n;
    while (scanf("%d", &n) == 1) {
        vector<pair<int, int>> e1(n - 1), e2(n - 1);
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &e1[i].first, &e1[i].second);
            e1[i].first--; e1[i].second--;
        }
        for (int i = 0; i < n - 1; i++) {
            scanf("%d%d", &e2[i].first, &e2[i].second);
            e2[i].first--; e2[i].second--;
        }

        print(solve(e1, e2));
    }

    return 0;
}
