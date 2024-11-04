











































using namespace __gnu_pbds;




using namespace std;























































    std::string _s = 
    replace(_s.begin(), _s.end(), ',', ' ');\
    std::stringstream _ss(_s);\
    std::istream_iterator <std::string> _it(_ss);\
    err(_it, args);\
}

    bool first = true; os << "[";\
    for (auto x : v) {\
        if (!first) os << ", "; os << x; first = false;\
    }\
    return os << "]";\
}
void err (std::istream_iterator <std::string> it) {}
template <typename T, typename... Args>
void err (std::istream_iterator <std::string> it, T a, Args... args) {
    std::cerr << *it << " = " << a << std::endl;
    err(++it, args...);
}
template <typename T1, typename T2> inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p) { return os << "(" << p.first << ", " << p.second << ")"; }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::vector<T>& v) { print_container(v); }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::set<T>& v) { print_container(v); }
template <typename T1, typename T2> inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v) { print_container(v); }
template <typename T1, typename T2, class C> inline std::ostream &operator << (std::ostream & os, const unordered_map<T1, T2, C>& v) { print_container(v); }
template <typename T, class C> inline std::ostream &operator << (std::ostream & os, const unordered_set<T, C>& v) { print_container(v); }
template <typename T1, typename T2> inline std::ostream &operator << (std::ostream & os, const std::multimap<T1, T2>& v) { print_container(v); }
template <typename T> inline std::ostream &operator << (std::ostream & os, const std::multiset<T>& v) { print_container(v); }




namespace IO {
    const int BUFFER_SIZE = 1 << 15;
    char input_buffer[BUFFER_SIZE];
    size_t input_pos = 0, input_len = 0;
    char output_buffer[BUFFER_SIZE];
    int output_pos = 0;
    char number_buffer[100];
    uint8_t lookup[100];
    void id2() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin); input_pos = 0;
        if (input_len == 0) input_buffer[0] = EOF;
    }
    inline char next_char(bool advance = true) {
        if (input_pos >= input_len) id2();
        return input_buffer[advance ? input_pos++ : input_pos];
    }
    inline bool isspace(char c) {
        return (unsigned char) (c - '\t') < 5 || c == ' ';
    }
    inline void read_char(char &c) {
        while (isspace(next_char(false))) next_char();
        c = next_char();
    }
    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;
        while (!isdigit(next_char(false))) if (next_char() == '-') negative = true;
        do {number = 10 * number + (next_char() - '0');} while (isdigit(next_char(false)));
        if (negative) number = -number;
    }
    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
    inline void read_str(string &str) {
        while (isspace(next_char(false))) next_char();
        str.clear();
        do {str += next_char();} while (!isspace(next_char(false)));
    }
    void _flush_output() {
        fwrite(output_buffer, sizeof(char), output_pos, stdout);
        output_pos = 0;
    }
    inline void write_char(char c) {
        if (output_pos == BUFFER_SIZE) _flush_output();
        output_buffer[output_pos++] = c;
    }
    template<typename T>
    inline void write_int(T number, char after = '\0') {
        if (number < 0) {
            write_char('-');
            number = -number;
        }
        int length = 0;
        while (number >= 10) {
            uint8_t lookup_value = lookup[number % 100];
            number /= 100;
            number_buffer[length++] = char((lookup_value & 15) + '0');
            number_buffer[length++] = char((lookup_value >> 4) + '0');
        }
        if (number != 0 || length == 0) write_char(char(number + '0'));
        for (int i = length - 1; i >= 0; i--) write_char(number_buffer[i]);
        if (after) write_char(after);
    }
    inline void write_str(const string &str, char after = '\0') {
        for (char c : str) write_char(c);
        if (after) write_char(after);
    }
    void IOinit() {
        

        bool exit_success = atexit(_flush_output) == 0;
        assert(exit_success);
        for (int i = 0; i < 100; i++) lookup[i] = uint8_t((i / 10 << 4) + i % 10);
    }
}

using namespace IO;

struct custom_hash {
    

    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + id0);
    }
    size_t operator()(pair<int, int> x) const { 
        static const uint64_t id0 = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(id0 + 31 * x.first + x.second);
    }
};






typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree <int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;

const int INF = 1e9;
const int LINF = INF * INF;
const double EPS = 1e-9;
const double PI = acosl(-1);

template <class T, class F = multiplies<T>>
T pwr(T a, long long n, F op = multiplies<T>(), T e = {1}) {
    assert(n >= 0);
    T res = e;
    while (n) {
        if (n & 1) res = op(res, a);
        if (n >>= 1) a = op(a, a);
    }
    return res;
}

template <unsigned Mod = 998244353> 
struct Modular {
    using M = Modular;
    unsigned v;
    Modular(long long a = 0) : v((a %= Mod) < 0 ? a + Mod : a) {}
    M operator-() const { return M() -= *this; }
    M& operator+=(M r) { if ((v += r.v) >= Mod) v -= Mod; return *this; }
    M& operator-=(M r) { if ((v += Mod - r.v) >= Mod) v -= Mod; return *this; }
    M& operator*=(M r) { v = (uint64_t)v * r.v % Mod; return *this; }
    M& operator/=(M r) { return *this *= pwr(r, Mod - 2); }
    friend M operator+(M l, M r) { return l += r; }
    friend M operator-(M l, M r) { return l -= r; }
    friend M operator*(M l, M r) { return l *= r; }
    friend M operator/(M l, M r) { return l /= r; }
    friend bool operator==(M l, M r) { return l.v == r.v; }
    friend bool operator!=(M l, M r) { return l.v != r.v; }
    friend ostream& operator<<(ostream& os, M a) { return os << a.v; }
    friend istream& operator>>(istream& is, M &a) { int64_t w; is >> w; a = M(w); return is; }
};

const int mod = 1e9 + 7;

using mint = Modular<mod>;

const int maxn = 5e5 + 5;
const int maxa = 1e6 + 5;
const int logmax = 25;

void setIO(string name = "") {
    ios_base::sync_with_stdio(0); cin.tie(0);
    if (name.size() == 0) return;
    FILE* fin = freopen((name+".in").c_str(), "r", stdin);
    FILE* fout = freopen((name+".out").c_str(), "w", stdout);
}

void solve(int case_no) {
    
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n);
    vector<int> U(m), V(m);

    rep(i, m) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        g[u].pb(i);
        g[v].pb(i);
        U[i] = u;
        V[i] = v;
    }

    auto adj = [&](int u, int i) {
        return u == U[i] ? V[i] : U[i];
    };

    

    
    vector<int> level(n), dp(n, -1);
    vector<char> is_bridge(m);
    
    function<void(int, int)> dfs_b = [&] (int u, int idx) {
    
        for (auto i : g[u]) {
            int v = adj(u, i);
            if (level[v] == 0) {
                level[v] = level[u] + 1;
                dfs_b(v, i);
                dp[u] += dp[v];
            } else if (level[u] < level[v]) {
                dp[u]--;
            } else if (level[u] > level[v]) {
                dp[u]++;
            }
        }
        
        if (level[u] > 1 && dp[u] == 0) {
            assert(idx != -1);
            is_bridge[idx] = true;
        }
    };
    
    level[0] = 1;
    dfs_b(0, -1);
    
    vector<int> num(n); 

    
    vector<vector<int>> tree(1);
    int comp = 0;
    vector<char> visited(n);
    vector<int> component_of(n);

    function<void(int)> dfs_t = [&] (int u) {
    
        int curcomp = comp;
        visited[u] = true;
        queue<int> q;
        q.emplace(u);
        
        while (!q.empty()) {
            int v = q.front();
            component_of[v] = curcomp;
            q.pop();
            for (auto i : g[v]) {
                int w = adj(v, i);
                if (visited[w]) continue;
                if (is_bridge[i]) {
                    ++comp;
                    tree.push_back(vector<int>());
                    tree[comp].push_back(curcomp);
                    tree[curcomp].push_back(comp);
                    dfs_t(w);
                } else {
                    visited[w] = true;
                    q.push(w);
                }
            }
        }
    };

    dfs_t(0);


    for (int i = 0; i < n; ++i) {
        num[component_of[i]]++;
    }

    for (int i = 0; i < n; ++i) {
        num[i] = (num[i] > 1); 

    }

    


    int nn = tree.size();
    
    assert(nn == comp + 1);
    
    vector<int> cnt(nn), tin(nn), tout(nn);
    int timer = 0;
    vector<vector<int>> st(nn, vector<int>(20));

    function<void(int, int, int)> dfs = [&] (int v, int p, int acc) {

        st[v][0] = p;
        for (int j = 1; j < 20; ++j) st[v][j] = st[st[v][j - 1]][j - 1];
        
        tin[v] = timer++;
    
        acc += num[v];
        cnt[v] = acc;
        
        for (auto u : tree[v]) {
            if (u != p) {
                dfs(u, v, acc);
            }
        }
        
        tout[v] = timer++;
    };

    dfs(0, 0, 0);

    auto id1 = [&] (int u, int v) {
        return tin[u] <= tin[v] && tout[v] <= tout[u];
    };

    auto lca = [&] (int u, int v) {
        if (id1(u, v)) return u;
        if (id1(v, u)) return v;
        for (int i = 19; i >= 0; --i) {
            if (!id1(st[u][i], v)) u = st[u][i];
        }
        return st[u][0];
    };

    int k;
    cin >> k;
    while (k--) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        u = component_of[u];
        v = component_of[v];
        int l = lca(u, v);
        cout << pwr(mint(2), (cnt[u] + cnt[v] - (2 * cnt[l]) + num[l])) << '\n';
    }


}

signed main(){
    

    setIO();
    

    int t = 1;
    

    

    for (int _t = 1; _t <= t; _t++) {
        

        solve(_t);
    }
    return 0;
}
