
using namespace std;
using ll = long long;
using ld = long double;























    
    
    
    template<class T> void debug_line(const vector<T>& ans, int l, int r, int L = 0) { cerr << "l." << L << " :"; for (int i = l; i < r; i++) { cerr << ' ' << ans[i]; } cerr << '\n'; }

    
    
    
    
    template<class T> void debug_line([[maybe_unused]] const vector<T>& ans, [[maybe_unused]] int l, [[maybe_unused]] int r, [[maybe_unused]] int L = 0) {}

template<class... T> void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
template<class T> void print(const T& a) { cout << a << '\n'; }
template<class T, class... Ts> void print(const T& a, const Ts&... b) { cout << a; (cout << ... << (cout << ' ', b)); cout << '\n'; }
template<class T> void cout_line(const vector<T>& ans, int l, int r) { for (int i = l; i < r; i++) { if (i != l) { cout << ' '; } cout << ans[i]; } cout << '\n'; }
template<class T> bool chmin(T& a, const T b) { if (b < a) { a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> T SUM(const vector<T>& A) { return accumulate(ALL(A), T(0)); }
template<class T> vector<T> cumsum(const vector<T>& A, bool offset = true) { int N = A.size(); vector<T> S(N+1, 0); for (int i = 0; i < N; i++) { S[i+1] = S[i] + A[i]; } if (not offset) { S.erase(S.begin()); } return S; }
ll mod(ll x, ll m) { assert(m != 0); return (x % m + m) % m; }
ll ceil(ll a, ll b) { if (b < 0) { return ceil(-a, -b); } assert(b > 0); return (a < 0 ? a / b : (a + b - 1) / b); }
ll floor(ll a, ll b) { if (b < 0) { return floor(-a, -b); } assert(b > 0); return (a > 0 ? a / b : (a - b + 1) / b); }
ll powint(ll x, ll n) { assert(n >= 0); if (n == 0) { return 1; }; ll res = powint(x, n>>1); res *= res; if (n & 1) { res *= x; } return res; }
pair<ll,ll> divmod(ll a, ll b) { assert(b != 0); ll q = floor(a, b); return make_pair(q, a - q * b); }
ll bitlen(ll b) { if (b <= 0) { return 0; } return (64LL - __builtin_clzll(b)); }
ll digit_len(ll n) { assert(n >= 0); if (n == 0) { return 1; } ll sum = 0; while (n > 0) { sum++; n /= 10; } return sum; }
ll digit_sum(ll n) { assert(n >= 0); ll sum = 0; while (n > 0) { sum += n % 10; n /= 10; } return sum; }
ll digit_prod(ll n) { assert(n >= 0); if (n == 0) { return 0; } ll prod = 1; while (n > 0) { prod *= n % 10; n /= 10; } return prod; }
ll xor_sum(ll x) { assert(0 <= x); switch (x % 4) { case 0: return x; case 1: return 1; case 2: return x ^ 1; case 3: return 0; } assert(false); }
string toupper(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = toupper(T[i]); } return T; }
string tolower(const string& S) { string T(S); for (int i = 0; i < (int)T.size(); i++) { T[i] = tolower(T[i]); } return T; }
int id5(const char& c) { assert(islower(c)); return (c - 'a'); }
int id0(const char& c) { assert(isupper(c)); return (c - 'A'); }
int id7(const char& d) { assert(isdigit(d)); return (d - '0'); }
char id6(const int& i) { assert(0 <= i && i < 26); return ('a' + i); }
char id3(const int& i) { assert(0 <= i && i < 26); return ('A' + i); }
char id4(const int& i) { assert(0 <= i && i <= 9); return ('0' + i); }
using P = pair<ll,ll>;
using VP = vector<P>;
using VVP = vector<VP>;
using VS = vector<string>;
using VVS = vector<VS>;
using VI = vector<int>;
using VVI = vector<VI>;
using VVVI = vector<VVI>;
using VLL = vector<ll>;
using VVLL = vector<VLL>;
using VVVLL = vector<VVLL>;
using VB = vector<bool>;
using VVB = vector<VB>;
using VVVB = vector<VVB>;
using VD = vector<double>;
using VVD = vector<VD>;
using VVVD = vector<VVD>;
using VLD = vector<ld>;
using VVLD = vector<VLD>;
using VVVLD = vector<VVLD>;
const ld EPS = 1e-10;
const ld PI  = acosl(-1.0);
constexpr ll MOD = 1000000007;


constexpr int inf = (1 << 30) - 1;   

constexpr ll INF = (1LL << 62) - 1;  









template<class T = ll>
vector<T> compress(vector<T>& X) {
    int N = X.size();
    vector<T> XS(X);  


    

    sort(XS.begin(), XS.end());
    XS.erase(unique(XS.begin(), XS.end()), XS.end());

    

    for (int i = 0; i < N; i++) {
        X[i] = lower_bound(XS.begin(), XS.end(), X[i]) - XS.begin();
    }
    return XS;
}













struct dsu {
  public:
    dsu() : N(0) {}
    explicit dsu(int n) : N(n), parent_or_size(n, -1), n_edge(n, 0) {}

    

    bool merge(int a, int b) {
        assert(0 <= a && a < N);
        assert(0 <= b && b < N);
        int x = leader(a), y = leader(b);
        if (x == y) { n_edge[x]++; return false; }
        if (-parent_or_size[x] < -parent_or_size[y]) { swap(x, y); }
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        n_edge[x] += n_edge[y] + 1;
        return true;
    }

    

    bool same(int a, int b) {
        assert(0 <= a && a < N);
        assert(0 <= b && b < N);
        return leader(a) == leader(b);
    }

    

    int leader(int a) {
        assert(0 <= a && a < N);
        if (parent_or_size[a] < 0) { return a; }
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    

    int size(int a) {
        assert(0 <= a && a < N);
        return -parent_or_size[leader(a)];
    }

    

    int size_e(int a) {
        assert(0 <= a && a < N);
        return n_edge[leader(a)];
    }

    

    vector<vector<int>> groups() {
        vector<int> leader_buf(N), group_size(N);
        for (int i = 0; i < N; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        vector<vector<int>> result(N);
        for (int i = 0; i < N; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < N; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            remove_if(result.begin(), result.end(),
                      [&](const vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int N;
    

    

    vector<int> parent_or_size;
    vector<int> n_edge;
};















struct id2 {
  public:
    vector<vector<pair<int,int>>> G;  


    id2(int n, bool id1) : N(n), directed(id1) {
        G.resize(N);
        indeg.resize(N,0);
        outdeg.resize(N,0);
    }

    

    

    

    void add_edge(int u, int v) {
        assert(0 <= u && u < N);
        assert(0 <= v && v < N);
        if (directed) {
            G[u].push_back({v, k});
        } else {
            G[u].push_back({v, k});
            G[v].push_back({u, k});
        }
        k++;
    }

    void build() {
        for (int u = 0; u < N; u++) {
            for (const auto& [v, _] : G[u]) {
                outdeg[u]++; indeg[v]++;
            }
        }
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    

    

    

    

    

    

    

    

    

    

    

    

    

    vector<vector<int>> construct_cycle() {
        if (not _validate_cycle()) { return vector<vector<int>>(0); }
        return _construct_core();
    }


  private:
    int N;
    bool directed;
    vector<int> indeg, outdeg;
    vector<bool> used_edge;
    int k = 0;  


    bool _validate_semi(int& s) {
        if (directed) {
            int v_start = -1, v_end = -1;
            for (int u = 0; u < N; u++) {
                if (indeg[u] == outdeg[u]) { continue; }
                if (outdeg[u] - indeg[u] == 1) {
                    if (v_start != -1) { return false; }
                    v_start = u;
                } else if (indeg[u] - outdeg[u] == 1) {
                    if (v_end != -1) { return false; }
                    v_end = u;
                } else {
                    return false;
                }
            }
            if (v_start == -1 || v_end == -1) { return false; }
            s = v_start;
        } else {
            vector<int> odd_node;
            for (int u = 0; u < N; u++) {
                if (indeg[u] % 2 == 1) {
                    if (odd_node.size() == 2) { return false; }
                    odd_node.push_back(u);
                }
            }
            if (odd_node.size() != 2) { return false; }
            s = odd_node[0];
        }
        return true;
    }

    bool _validate_cycle() {
        if (directed) {
            for (int u = 0; u < N; u++) {
                if (indeg[u] != outdeg[u]) { return false; }
            }
        } else {
            for (int u = 0; u < N; u++) {
                if (indeg[u] % 2 == 1) { return false; }
            }
        }
        return true;
    }

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    

    


    vector<vector<int>> _construct_core() {
        vector<vector<pair<int,int>>> g(G);  

        vector<bool> vis(N);
        vector<vector<int>> paths;
        used_edge.resize(k, false);
        for (int s = 0; s < N; s++) if (not vis[s]) {
            vector<int> path;
            auto dfs = [&](auto&& self, int u) -> void {
                vis[u] = true;
                while (not g[u].empty()) {
                    auto [v, edge_id] = g[u].back(); g[u].pop_back();
                    if (not used_edge[edge_id]) {
                        used_edge[edge_id] = true;
                        self(self, v);
                        path.push_back(v);
                    }
                }
            };
            dfs(dfs, s);
            path.push_back(s);
            reverse(path.begin(), path.end());

            paths.push_back(path);
        }
        return paths;
    }
};


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(15);

    int N; input(N);
    VI K(N);
    VVI A(N);
    REP(i,N) {
        input(K[i]);
        A[i].resize(K[i]);
        REP(j,K[i]) input(A[i][j]);
    }

    VI A_all;
    REP(i,N) REP(j,K[i]) A_all.push_back(A[i][j]);
    auto ZA = compress(A_all);
    int M = SZ(ZA);
    int idx = 0;
    REP(i,N) REP(j,K[i]) A[i][j] = A_all[idx++];

    VI cnt(M);
    REP(i,N) for (const auto& a : A[i]) cnt[a]++;
    for (const auto& c : cnt) if (P1(c)) { print("NO"); return 0; }

    dsu uf(N + M);
    id2 ep(N + M, false);
    REP(i,N) for (const auto& a : A[i]) {
        uf.merge(i, N + a);
        ep.add_edge(i, N + a);
    }
    ep.build();

    auto Cs = ep.construct_cycle();
    if (SZ(Cs) == 0) {
        print("NO");
    } else {
        print("YES");
        vector<map<int,int>> memo(N);
        for (const auto& C : Cs) REP(i,SZ(C)-1) {
            int u = C[i];
            int v = C[i+1];
            if (u < v) {
                memo[u][v - N]++;
            }
        }
        REP(i,N) {
            auto& mp = memo[i];
            string ans = "";
            REP(j,K[i]) {
                auto it = mp.find(A[i][j]);
                if (it != mp.end() && it->second > 0) {
                    it->second--;
                    ans += "L";
                } else {
                    ans += "R";
                }
            }
            print(ans);
        }
    }

    return 0;
}
