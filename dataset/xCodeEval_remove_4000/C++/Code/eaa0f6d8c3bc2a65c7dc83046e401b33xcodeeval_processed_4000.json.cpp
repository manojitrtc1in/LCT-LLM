



using namespace std;












namespace XYL_DEBUG_NAMESPACE {
    char tem[100007];
    int st;

    template<typename T, typename ...T2>
    void prt(const T &t, const T2 &...t2) {
        while (tem[st] == ' ' || tem[st] == ',')st++;
        int u = 0, v = 0, x = 0;
        while (u || (tem[st] != ',' && tem[st] != ' ')) {
            if (!v && !x) {
                if (tem[st] == '(')u++;
                if (tem[st] == ')')u--;
            }
            if (tem[st] == '"' && !x)v = !v;
            if (tem[st] == '\'' && !v)x = !x;
            cerr << tem[st], st++;
        }
        cerr << " = " << t;
        if constexpr (sizeof...(t2) > 0)cerr << " , ", prt(t2...);
        else cerr << endl;
    }
}










struct clock_node {

    void start_clock() {
        id1 = chrono::system_clock::now();
    }

    void end_clock() const {
        auto ends = chrono::system_clock::now();
        cerr << "timeit : " <<
             (long double) chrono::duration_cast<chrono::microseconds>(ends - id1).count() / 1000.00l
             << "ms\n";
    }

    void reset_clock() {
        auto ends = chrono::system_clock::now();
        cerr << "timeit : " <<
             (long double) chrono::duration_cast<chrono::microseconds>(ends - id1).count() / 1000.00l
             << "ms\n";
        id1 = ends;
    }

private:
    chrono::time_point<chrono::system_clock, chrono::nanoseconds> id1 = chrono::system_clock::now();
}clockNode;


struct clock_node{
    void start_clock(){}
    void end_clock(){}
    void reset_clock(){}
};

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef double db;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ull, ull> pull;
typedef pair<db, db> pdd;
typedef pair<ld, ld> pld;

template<class T>
bool updmax(T &a, T b) { return a < b ? a = b, 1 : 0; }

template<class T>
bool updmin(T &a, T b) { return a > b ? a = b, 1 : 0; }

constexpr int px4[]{0, 1, 0, -1};
constexpr int py4[]{1, 0, -1, 0};
constexpr int px8[]{0, 1, 0, -1, 1, 1, -1, -1};
constexpr int py8[]{1, 0, -1, 0, 1, -1, 1, -1};



namespace XYL_FAST_IO {








    constexpr int Q = (1 << 10) + 1;
    int QQ = Q - 10;
    char in[Q], *is = in, *it = in, ou[Q], *os = ou;

    void out() {
        *os = 0;
        fwrite(ou, 1, os - ou, stdout);
        os = ou, QQ = Q - 10;
    }

    constexpr long double double_p() {
        long double as = 1;
        fo(i, 0, double_precision)as *= 10;
        return as;
    }

    template<class T>
    void output(T x, int num = 0) {
        if (x / 10)output(x / 10, num - 1);
        else while (num-- > 1)pc('0');
        pc(x % 10 + '0');
    }

    namespace impl {
        bool eof() {
            return is == it && feof(stdin);
        }

        template<class T, typename enable_if<is_integral<T>::value, T>::type * = nullptr>
        void ot(T x) {
            if (x < 0)pc('-'), output(-x);
            else output(x);
        }

        void ot(char x) {
            pc(x);
        }

        template<class T, typename enable_if<is_floating_point<T>::value, T>::type * = nullptr>
        void ot(T x) {
            if (x < 0)pc('-'), x *= -1.0l;
            long double zs = fmodl(x, 1.0l);
            zs *= double_p();
            ot((long long) x), pc('.');
            output((long long) zs, double_precision);
        }

        template<typename T, typename enable_if<is_pointer<T>::value, T>::type * = nullptr>
        void ot(T x) { while (*x)pc(*x++); }


        template<class Tx, class...T>
        void ot(Tx x, T...x1) {
            ot(x), ot(x1...);
        }

        template<char dem = '\n', class T>
        void otl(T x) { ot(x), dem ? pc(dem), 0 : 0; }

        template<char dem = '\n', class Tx, class ...T>
        void otl(Tx x, T... xx) { ot(x), dem ? pc(dem), 0 : 0, otl < dem >(xx...); }

        template<class ...T>
        void otb(T... xx) { otl<' '>(xx...); }

        template<char dem = ' ', class T>
        void ota(T x1, T x2) {
            while (x1 != x2)ot(*x1++), pc(dem);
            pc('\n');
        }

        template<char dem = '\0', class ...T>
        void otf(T ...x) {
            otl<dem>(x...), out(), fflush(stdout);
        }

        template<class T, typename enable_if<is_integral<T>::value, T>::type * = nullptr>
        void rd(T &x) {
            char ch;
            x = 0;
            bool fl = false;
            while (!isdigit(ch = gc()))(ch == '-') && (fl = true);
            for (x = (ch - '0'); isdigit(ch = gc()); x = x * 10 + (ch - '0'));
            fl && (x = -x);
        }

        template<class T, typename enable_if<is_floating_point<T>::value, T>::type * = nullptr>
        void rd(T &x) {
            bool sign = false;
            x = 0;
            char ch;
            while (!isdigit(ch = gc()))(ch == '-') && (sign = true);
            for (; isdigit(ch); ch = gc())x = x * 10 + (ch - '0');
            if (ch == '.') {
                T tmp = 1.0l;
                ch = gc();
                for (; isdigit(ch); ch = gc())tmp /= 10.0l, x += tmp * (ch - '0');
            }
            if (sign)x = -x;
        }

        void rd(char &t) {
            t = gc();
            while (t == ' ' || t == '\n')t = gc();
        }

        void rd(char *t) {
            char *p = t;
            while ((*p = gc()) != ' ' && *p != '\n' && *p != EOF)p++;
            *p = 0;
        }

        template<typename T1, typename T2>
        void rd(pair<T1, T2> &p) {
            rd(p.first), rd(p.second);
        }

        template<class Tx, class...T>
        void rd(Tx &x, T &...x1) {
            rd(x), rd(x1...);
        }

        template<class T>
        void rda(T x1, T x2) {
            while (x1 != x2)rd(*x1++);
        }

        void rdl(char *t) {
            char *p = t;
            while ((*p = gc()) != EOF)p++;
            *p = 0;
        }
    }







}

template<int mod>
struct modint {
    int val;
    constexpr modint(int val_ = 0) : val(val_) {}
    modint &operator=(int val_) { return val = val_, *this; }
    modint &operator+=(const modint &k) { return val = val + k.val >= mod ? val + k.val - mod : val + k.val, *this; }
    modint &operator-=(const modint &k) { return val = val - k.val < 0 ? val - k.val + mod : val - k.val, *this; }
    modint &operator*=(const modint &k) { return val = 1ull * val * k.val % mod, *this; }
    modint &operator^=(int k) {
        modint ret = 1, tmp = *this;
        for (; k; k >>= 1, tmp *= tmp)if (k & 1)ret *= tmp;
        return val = ret.val, *this;
    }
    modint &operator/=(modint k) { return *this *= (k ^= mod - 2); }
    modint &operator+=(int k) { return val = val + k >= mod ? val + k - mod : val + k, *this; }
    modint &operator-=(int k) { return val = val < k ? val - k + mod : val - k, *this; }
    modint &operator*=(int k) { return val = 1ull * val * k % mod, *this; }
    modint &operator/=(int k) { return *this *= ((modint(k)) ^= mod - 2); }
    template<class T>friend modint operator+(modint a, T b) { return a += b; }
    template<class T>friend modint operator-(modint a, T b) { return a -= b; }
    template<class T>friend modint operator*(modint a, T b) { return a *= b; }
    template<class T>friend modint operator^(modint a, T b) { return a /= b; }
    template<class T>friend modint operator/(modint a, T b) { return a /= b; }
    friend modint operator^(modint a, int b) { return a ^= b; }
    friend bool operator==(modint a, int b) { return a.val == b; }
    friend bool operator!=(modint a, int b) { return a.val != b; }
    bool operator!() { return !val; }
    modint operator-() { return val ? mod - val : 0; }
    modint &operator++() { return *this += 1; }
};
struct Dinic {
    struct Edge {
        int v, to;
        int cap;

        Edge() : v(), to(), cap() {}
        Edge (int _v, int _to, int _cap) : v(_v), to(_to), cap(_cap) {}
    };
    static constexpr int INF = 0x3f3f3f;
    vector<Edge> ed;
    vector<vector<int>> g;
    int S, T;
    int n;
    vector<int> dist;
    vector<int> idx;
    Dinic() : ed(), g(), S(), T() {}
    Dinic(int n, int S, int T):S(S),n(n),T(T) {
        g.resize(n);
        for (int i = 0; i < n; i++)g[i].clear();
        ed = vector<Edge>();
    }
    void addEdge(int v, int to, int cap) {
        g[v].push_back((int)ed.size());
        ed.emplace_back(v, to, cap);
        g[to].push_back((int)ed.size());
        ed.emplace_back(to, v, 0);
    }
    bool BFS() {
        dist.resize(n);
        vector<int> q;
        for (int i = 0; i < n; i++)
            dist[i] = n;
        q.push_back(S);
        dist[S] = 0;
        for (int i = 0; i < (int)q.size(); i++) {
            int v = q[i];
            for (int id : g[v]) {
                Edge e = ed[id];
                if (e.cap <= 0) continue;
                int u = e.to;
                if (dist[u] <= dist[v] + 1) continue;
                dist[u] = dist[v] + 1;
                q.push_back(u);
            }
        }
        return dist[T] < n;
    }

    ll dfs(int v, int flow) {
        if (v == T || flow == 0) return flow;
        int res = 0;
        for (int &i = idx[v]; i < (int)g[v].size(); i++) {
            int id = g[v][i];
            Edge e = ed[id];
            int to = e.to;
            if (dist[to] != dist[v] + 1) continue;
            ll df = dfs(to, min(flow, e.cap));
            flow -= df;
            res += df;
            ed[id].cap -= df;
            ed[id ^ 1].cap += df;
            if (flow == 0) return res;
        }
        return res;
    }

    int Flow() {
        idx.resize(n);
        int res = 0;
        while(BFS()) {
            for (int i = 0; i < n; i++)
                idx[i] = 0;
            res += dfs(S, INF);
        }
        return res;
    }
} dinic;
bool id0 = true;
namespace solve{
    using namespace XYL_FAST_IO::impl;
    int n, m, k, g;
    const int maxn = 5e4,maxm = 1047450+10;
    const ll mod = 998244353;
    using mint = modint<mod>;
    using pmm = pair<mint,mint>;
    pair<int, int> pp[maxm];

    int match() {
        int u, v;
        int s = 2*n+5, t = 2 * n + 6;
        dinic = Dinic(2*n+7,s,t);
        for (int i = 1; i <= n; ++i) {
            dinic.addEdge(s, i, 1);
        }
        for (int i = 1; i <= m; ++i) {
            u = pp[i].first, v = pp[i].second;
            dinic.addEdge(u, v + n, 1);
        }
        for (int i = 1; i <= n; ++i) {
            dinic.addEdge(i + n, t, 1);
        }
        int mxmatch = dinic.Flow();
        return mxmatch - n / 2;
    }

    int arr[maxn];
    int nums[maxn];
    void solve() {
        m = 0;
        rd(n);
        for (int i = 1; i <= n; i++) {
            int t;
            rd(t);
            arr[t] = i;
            nums[i] = t;
            pp[++m] = make_pair(i + n, i);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 2 * nums[i]; j <= 5e4; j += nums[i]) {
                if (arr[j]) {
                    pp[++m] = make_pair(i, arr[j]);
                    pp[++m] = make_pair(i + n, arr[j] + n);
                }
            }
        }
        for (int i = 1; i <= n; i++)arr[nums[i]]=0,nums[i]=0;
        n *= 2;
        otl(match());
    }
}

signed main() {

    freopen("1.in", "r", stdin);
    freopen("1.out", "w", stdout);

    int t = 1;
    srand(time(nullptr));
    if (id0)XYL_FAST_IO::impl::rd(t);
    for (int i = 1; i <= t; i++) {
        solve::solve();
    }
    XYL_FAST_IO::out();

    clockNode.end_clock();
    freopen("CON", "w", stdout);
    freopen("1.out", "r", stdin);
    char seq[(1u << 20u) + 7];
    while (!feof(stdin))fwrite(seq, 1, fread(seq, 1, 1u << 20u, stdin), stdout);

    return 0;
}
 	 			 	  	 		  		 			 				 			