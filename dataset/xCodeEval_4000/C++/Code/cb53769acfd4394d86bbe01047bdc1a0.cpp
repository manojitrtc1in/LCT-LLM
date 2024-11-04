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





template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

using m17 = ModInt<1'000'000'007>;
using m98 = ModInt<998'244'353>;
using MOD = m17;
ll mod = 1'000'000'007;






const int _B = 500500;
MOD g1[_B];
MOD g2[_B];
MOD inverse[_B];
void prepare() {
  g1[0] = g1[1] = g2[0] = g2[1] = 1;
  inverse[0] = 0;
  inverse[1] = 1;
  range(i,2,_B,1) {
    g1[i] = g1[i-1]*i;
    inverse[i] = -inverse[mod%i]*(mod/i);
    g2[i] = g2[i-1]*inverse[i];
  }
}
template<typename T>
MOD cmb(T n, T r) {
  assert(g1[0]==1);
  if (r<0 || r>n) return 0;
  r = min(r, n-r);
  return g1[n]*g2[r]*g2[n-r];
}
template<typename T>
MOD perm(T n, T r) {
  if (r<0 || r>n) return 0;
  return g1[n]*g2[n-r];
}





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

void Main(){
    

    ll n,u,v;
    cin >> n;
    

    

    VV<int> ns(n, V<int>());
    rep(i,n-1) {
        cin >> u >> v;
        u--;
        v--;
        

        ns[u].push_back(v);
        ns[v].push_back(u);
    }
    

    int m = 300;
    if (TEST) m = 5;
    MOD inv2 = MOD(2).pow(mod-2);
    VV<MOD> dp(m, V<MOD>(m)); 

    range(i, 1, m, 1) dp[0][i] = 1;
    range(i, 1, m, 1) range(j, 1, m, 1) {
        dp[i][j] = inv2 * dp[i-1][j] + inv2 * dp[i][j-1];
    }
    MOD ans = 0;
    rep(start, n) {
        stack<int> q;
        q.push(start);
        V<int> par(n,-1);
        V<int> d(n);
        VV<P<int,int>> ds(n);
        par[start] = start;
        while (!q.empty()) {
            int u = q.top();
            q.pop();
            if (u<0) {
                u = ~u;
                V<P<int,int>> vals;
                vals.push_back({u,d[u]});
                for (auto v : ns[u]) {
                    if (v==par[u]) continue;
                    

                    for (auto [vv,dv] : ds[v]) for (auto [uu,du] : vals) {
                        

                        if (vv<uu) ans += dp[du-d[u]][dv-d[u]];
                        else ans += dp[dv-d[u]][du-d[u]];
                    }
                    for (auto vv : ds[v]) {
                        vals.push_back(vv);
                    }
                }
                ds[u] = vals;
            } else {
                q.push(~u);
                for (auto v : ns[u]) {
                    if (~par[v]) continue;
                    q.push(v);
                    par[v] = u;
                    d[v] = d[u] + 1;
                    

                }
            }
        }
    }
    

    MOD invn = MOD(1) / MOD(n);
    ans *= invn;
    

    

    

    

    

    

    

    

    

    

    

    

    

    cout << ans << endl;
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
