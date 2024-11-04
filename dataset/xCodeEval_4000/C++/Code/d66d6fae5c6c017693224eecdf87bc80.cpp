 bool TEST = false;

using namespace std;
#include<bits/stdc++.h>
#include<fstream>

#define rep(i,n) for(int (i)=0;(i)<(ll)(n);i++)
#define rrep(i,n) for(int (i)=(ll)(n)-1;(i)>=0;i--)
#define range(i,start,end,step) for(int (i)=start;(i)<(ll)(end);(i)+=(step))
#define rrange(i,start,end,step) for(int (i)=start;(i)>(ll)(end);(i)+=(step))

#define dump(x)  cerr << "Line " << __LINE__ << ": " <<  #x << " = " << (x) << "\n";
#define spa << " " <<
#define fi first
#define se second
#define all(a)  (a).begin(),(a).end()
#define allr(a)  (a).rbegin(),(a).rend()

using ld = long double;
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
 
template<typename T> using V = vector<T>;
template<typename T> using VV = V<V<T>>;
template<typename T, typename T2> using P = pair<T, T2>;
template<typename T, typename T2> using M = map<T, T2>;
template<typename T> using S = set<T>;
template<typename T, typename T2> using UM = unordered_map<T, T2>;
template<typename T> using PQ = priority_queue<T, V<T>, greater<T>>;
template<typename T> using rPQ = priority_queue<T, V<T>, less<T>>;
template<class T>vector<T> make_vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto make_vec(size_t a, Ts... ts){return vector<decltype(make_vec<T>(ts...))>(a, make_vec<T>(ts...));}
template<class SS, class T> ostream& operator << (ostream& os, const pair<SS, T> v){os << "(" << v.first << ", " << v.second << ")"; return os;}
template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { for (auto &e : v) os << e << ' '; return os; }
template<class T> ostream& operator<<(ostream& os, const vector<vector<T>> &v){ for(auto &e : v){os << e << "\n";} return os;}
struct fast_ios { fast_ios(){ cin.tie(nullptr); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; } fast_ios_;
 
template <class T> void UNIQUE(vector<T> &x) {sort(all(x));x.erase(unique(all(x)), x.end());}
template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
void fail() { cout << -1 << '\n'; exit(0); }
inline int popcount(const int x) { return __builtin_popcount(x); }
inline int popcount(const ll x) { return __builtin_popcountll(x); }
template<typename T> void debug(vector<vector<T>>&v){for(ll i=0;i<v.size();i++)
{cerr<<v[i][0];for(ll j=1;j<v[i].size();j++)cerr spa v[i][j];cerr<<"\n";}};
template<typename T> void debug(vector<T>&v){if(v.size()!=0)cerr<<v[0];
for(ll i=1;i<v.size();i++)cerr spa v[i];
cerr<<"\n";};
template<typename T, typename T2> void debug(map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n"; cerr<<"\n";}
template<typename T, typename T2> void debug(unordered_map<T,T2>&v){for(auto [k,v]: v) cerr << k spa v << "\n";cerr<<"\n";}
V<int> listrange(int n) {V<int> res(n); rep(i,n) res[i]=i; return res;}

template<typename T> P<T,T> divmod(T a, T b) {return make_pair(a/b, a%b);}

const ll INF = (1ll<<62);









struct HeavyLightDecomposition {
    int V;
    int k;
    int nb_heavy_path;
    std::vector<std::vector<int>> e;
    std::vector<int> par;         

    std::vector<int> depth;       

    std::vector<int> subtree_sz;  

    std::vector<int> heavy_child; 

    std::vector<int> tree_id;     

    std::vector<int> aligned_id, aligned_id_inv; 

    std::vector<int> head;          

    std::vector<int> head_ids;      

    std::vector<int> heavy_path_id; 

 
    HeavyLightDecomposition(int sz = 0)
        : V(sz), k(0), nb_heavy_path(0), e(sz), par(sz), depth(sz), subtree_sz(sz), heavy_child(sz), tree_id(sz, -1), aligned_id(sz), aligned_id_inv(sz), head(sz), heavy_path_id(sz, -1) {}
    void add_edge(int u, int v) {
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
 
    void _build_dfs(int root) {
        std::stack<std::pair<int, int>> st;
        par[root] = -1;
        depth[root] = 0;
        st.emplace(root, 0);
        while (!st.empty()) {
            int now = st.top().first;
            int& i = st.top().second;
            if (i < (int)e[now].size()) {
                int nxt = e[now][i++];
                if (nxt == par[now]) continue;
                par[nxt] = now;
                depth[nxt] = depth[now] + 1;
                st.emplace(nxt, 0);
            } else {
                st.pop();
                int max_sub_sz = 0;
                subtree_sz[now] = 1;
                heavy_child[now] = -1;
                for (auto nxt : e[now]) {
                    if (nxt == par[now]) continue;
                    subtree_sz[now] += subtree_sz[nxt];
                    if (max_sub_sz < subtree_sz[nxt]) max_sub_sz = subtree_sz[nxt], heavy_child[now] = nxt;
                }
            }
        }
    }
 
    void _build_bfs(int root, int tree_id_now) {
        std::queue<int> q({root});
        while (!q.empty()) {
            int h = q.front();
            q.pop();
            head_ids.emplace_back(h);
            for (int now = h; now != -1; now = heavy_child[now]) {
                tree_id[now] = tree_id_now;
                aligned_id[now] = k++;
                aligned_id_inv[aligned_id[now]] = now;
                heavy_path_id[now] = nb_heavy_path;
                head[now] = h;
                for (int nxt : e[now])
                    if (nxt != par[now] and nxt != heavy_child[now]) q.push(nxt);
            }
            nb_heavy_path++;
        }
    }
 
    void build(std::vector<int> roots = {0}) {
        int tree_id_now = 0;
        for (auto r : roots) {
            _build_dfs(r);
            _build_bfs(r, tree_id_now++);
        }
    }
 
    template <typename Monoid> std::vector<Monoid> segtree_rearrange(const std::vector<Monoid>& data) const {
        assert(int(data.size()) == V);
        std::vector<Monoid> ret;
        ret.reserve(V);
        for (int i = 0; i < V; i++) ret.emplace_back(data[aligned_id_inv[i]]);
        return ret;
    }
 
    

    void for_each_vertex(int u, int v, const std::function<void(int ancestor, int descendant)>& f) const {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            f(std::max(aligned_id[head[v]], aligned_id[u]), aligned_id[v]);
            if (head[u] == head[v]) break;
            v = par[head[v]];
        }
    }

    void for_subtree(int u, const std::function<void(int ancestor, int descendant)>& f) const {
        f(aligned_id[u], aligned_id[u]+subtree_sz[u]);
    }
 
    void for_each_vertex_noncommutative(int from, int to, const std::function<void(int ancestor, int descendant)>& fup, const std::function<void(int ancestor, int descendant)>& fdown) const {
        int u = from, v = to;
        const int lca = lowest_common_ancestor(u, v), dlca = depth[lca];
        while (u >= 0 and depth[u] > dlca) {
            const int p = (depth[head[u]] > dlca ? head[u] : lca);
            fup(aligned_id[p] + (p == lca), aligned_id[u]), u = par[p];
        }
        std::vector<std::pair<int, int>> lrs;
        while (v >= 0 and depth[v] >= dlca) {
            const int p = (depth[head[v]] >= dlca ? head[v] : lca);
            lrs.emplace_back(p, v), v = par[p];
        }
        std::reverse(lrs.begin(), lrs.end());
        for (const auto& lr : lrs) fdown(aligned_id[lr.first], aligned_id[lr.second]);
    }
 
    

    void for_each_edge(int u, int v, const std::function<void(int, int)>& f) const {
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] != head[v]) {
                f(aligned_id[head[v]], aligned_id[v]);
                v = par[head[v]];
            } else {
                if (u != v) f(aligned_id[u] + 1, aligned_id[v]);
                break;
            }
        }
    }
 
    

    int lowest_common_ancestor(int u, int v) const {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        while (true) {
            if (aligned_id[u] > aligned_id[v]) std::swap(u, v);
            if (head[u] == head[v]) return u;
            v = par[head[v]];
        }
    }
 
    int distance(int u, int v) const {
        assert(tree_id[u] == tree_id[v] and tree_id[u] >= 0);
        return depth[u] + depth[v] - 2 * depth[lowest_common_ancestor(u, v)];
    }
};

int ceil_pow2(int n) {
    int x = 0;
    while ((1U << x) < (unsigned int)(n)) x++;
    return x;
}

template <class S,
          S (*op)(S, S),
          S (*e)(),
          class F,
          S (*mapping)(F, S),
          F (*composition)(F, F),
          F (*id)()>
struct LSG {
  public:
    LSG() : LSG(0) {}
    explicit LSG(int n) : LSG(std::vector<S>(n, e())) {}
    explicit LSG(const std::vector<S>& v) : _n(int(v.size())) {
        log = ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        lz = std::vector<F>(size, id());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            _update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = x;
        for (int i = 1; i <= log; i++) _update(p >> i);
    }

    S get(int p) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        return d[p];
    }

    S query(int l, int r) {
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

    S query_all() { return d[1]; }

    void check() {
      rep(i,_n) cout << get(i) << " ";
      cout << endl;
    }

    void update(int p, F f) {
        assert(0 <= p && p < _n);
        p += size;
        for (int i = log; i >= 1; i--) push(p >> i);
        d[p] = mapping(f, d[p]);
        for (int i = 1; i <= log; i++) _update(p >> i);
    }
    void update(int l, int r, F f) {
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
            if (((l >> i) << i) != l) _update(l >> i);
            if (((r >> i) << i) != r) _update((r - 1) >> i);
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

    void _update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
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
















using T = int;
using F = int;
T op (T l, T r) {
    return l+r;
}
T e () {
    return 0;
}
T mapping(F f, T v) {
    return f+v;
}


F composition(F f1, F f2) {
    return f1+f2;
}
F id() {
    return 0;
}

    



void preorder(VV<int> &ns, V<int> &order, V<int> &ls, V<int> &rs, V<int> &par) {
    int start = 0;
    stack<int> q;
    q.push(start);
    par[start] = start;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (u<0) {
            u = ~u;
            rs[u] = order.size();
            order.push_back(u);
            for (auto v : ns[u]) {
                if (v==par[u]) continue;
                

            }
        } else {
            ls[u] = order.size();
            order.push_back(u);
            q.push(~u);
            for (auto v : ns[u]) {
                if (~par[v]) continue;
                q.push(v);
                par[v] = u;
                

            }
        }
    }
}









void Main(){
    int t;
    cin >> t;
    rep(i,t) {
        ll n;
        cin >> n;
        V<int> a(n-1);
        V<int> b(n-1);
        VV<int> ns(n, V<int>());
        VV<int> ns2(n, V<int>());
        HeavyLightDecomposition graph(n);
        rep(i,n-1) {
            cin >> a[i];
            ns[i+1].emplace_back(a[i]-1);
            ns[a[i]-1].emplace_back(i+1);
        }
        rep(i,n-1) {
            cin >> b[i];
            ns2[i+1].emplace_back(b[i]-1);
            ns2[b[i]-1].emplace_back(i+1);
        }
        
        

        LSG<T,op,e,F,mapping,composition,id> sg(V<T>(2*n,0));
        V<int> order, ls(n), rs(n), ppar(n,-1);
        preorder(ns2, order, ls, rs, ppar);
        int B = 20;
        VV<int> ps(B, V<int>(n,-1));
        rep(u,n) ps[0][u] = ppar[u];
        rep(i,B-1) rep(u,n) {
            if (ps[i][u]>=0) ps[i+1][u] = ps[i][ps[i][u]];
        }
        

        

        

        

        int start = 0;
        stack<int> q;
        q.push(start);
        V<int> par(n,-1);
        par[start] = start;
        int ans = 0;
        int val = 0;
        S<int> se;
        map<int,int> ma;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (u<0) {
                u = ~u;
                bool is_leaf = 1;
                for (auto v : ns[u]) {
                    if (v==par[u]) continue;
                    

                    is_leaf = 0;
                }
                if (is_leaf) {
                    chmax(ans, (int)se.size());
                    

                    

                    

                }
                if (se.find(u)!=se.end()) {
                    sg.update(ls[u], rs[u] , -1);
                    se.erase(u);
                    if (ma.find(u)!=ma.end()) {
                        se.insert(ma[u]);
                        sg.update(ls[ma[u]], rs[ma[u]], 1);
                    }
                }
            } else {
                

                if (sg.query(ls[u], rs[u])==0) {
                    sg.update(ls[u], rs[u], 1);
                    se.insert(u);
                } else {
                    if (sg.get(ls[u])==0) ;
                    else {
                        int c = u;
                        rrep(i,B) if (ps[i][c]>=0 and sg.get(ls[ps[i][c]])) c = ps[i][c];
                        assert(sg.get(ls[c])==1);
                        sg.update(ls[c], rs[c], -1);
                        sg.update(ls[u], rs[u], 1);
                        se.erase(c);
                        se.insert(u);
                        ma[u] = c;
                    }
                }
                q.push(~u);
                for (auto v : ns[u]) {
                    if (~par[v]) continue;
                    q.push(v);
                    par[v] = u;
                    

                }
            }
        }
        cout << ans << endl;
        

    }
}

int main(void){
    std::ifstream in("tmp_in");
    if (TEST) {
        std::cin.rdbuf(in.rdbuf());
        std::cout << std::fixed << std::setprecision(15);
    } else {
        std::cin.tie(nullptr);
        std::ios_base::sync_with_stdio(false);
        std::cout << std::fixed << std::setprecision(15);
    }
    Main();
}
