#ifdef stderr_path
    #define LOCAL
    #define _GLIBCXX_DEBUG
#endif
#pragma GCC optimize("Ofast")
#include <cassert>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <functional>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#include <iomanip>
#include <bitset>
#include <random>
#include <chrono>

#define debug_stream std::cerr
#define iostream_untie true
#define __precision__ 10

#define rep(i, n) for(int i = 0; i < int(n); ++i)
#define all(v) begin(v), end(v)
#define rall(v) rbegin(v), rend(v)
#define __odd(n) ((n) & 1)
#define __even(n) (__odd(n) ^ 1)
#define __popcount(n) __builtin_popcountll(n)

using i64 = int_fast64_t;
using pii = std::pair<int, int>;
using pll = std::pair<int_fast64_t, int_fast64_t>;
template <class T> using heap = std::priority_queue<T>;
template <class T> using minheap = std::priority_queue<T, std::vector<T>, std::greater<T>>;
template <class T> constexpr T inf = std::numeric_limits<T>::max() / (T)2 - (T)1123456;
constexpr int dx[9] = {1, 0, -1, 0, 1, -1, -1, 1, 0};
constexpr int dy[9] = {0, 1, 0, -1, 1, 1, -1, -1, 0};

namespace execution
{
    std::chrono::system_clock::time_point start_time, end_time;
    void print_elapsed_time()
    {
        end_time = std::chrono::system_clock::now();
        std::cerr << "\n----- Exec time : ";
        std::cerr << std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
        std::cerr << " ms -----\n\n";
    }
    struct setupper
    {
        setupper()
        {
            if(iostream_untie)
            {
                std::ios::sync_with_stdio(false);
                std::cin.tie(nullptr);
            }
            std::cout << std::fixed << std::setprecision(__precision__);
#ifdef stderr_path
            if(freopen(stderr_path, "a", stderr))
            {
                std::cerr << std::fixed << std::setprecision(__precision__);
            }
            else fclose(stderr);
#endif
#ifdef stdout_path
            if(not freopen(stdout_path, "w", stdout))
            {
                freopen("CON", "w", stdout);
                std::cerr << "Failed to open the stdout file\n\n";
            }
            std::cout << "";
#endif
#ifdef stdin_path
            if(not freopen(stdin_path, "r", stdin))
            {
                freopen("CON", "r", stdin);
                std::cerr << "Failed to open the stdin file\n\n";
            }
#endif
#ifdef LOCAL
            atexit(print_elapsed_time);
            start_time = std::chrono::system_clock::now();
#endif
        }
    } __setupper;
}

struct myclock_t
{
    std::chrono::system_clock::time_point built_pt, last_pt;
    int built_ln, last_ln;
    std::string built_func, last_func;
    bool is_built;
    myclock_t() : is_built(false) {}
    void build(int crt_ln, const std::string &crt_func)
    {
        is_built = true;
        last_pt = built_pt = std::chrono::system_clock::now();
        last_ln = built_ln = crt_ln, last_func = built_func = crt_func;
    }
    void set(int crt_ln, const std::string &crt_func)
    {
        if(is_built)
        {
            last_pt = std::chrono::system_clock::now();
            last_ln = crt_ln, last_func = crt_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::set failed (yet to be built clock!)\n";
        }
    }
    void get(int crt_ln, const std::string &crt_func) {
        if(is_built) 
        {
            std::chrono::system_clock::time_point crt_pt(std::chrono::system_clock::now());
            int64_t diff = std::chrono::duration_cast<std::chrono::milliseconds>(crt_pt - last_pt).count();
            debug_stream << diff << " ms elapsed from" << " [ " <<  last_ln << " : " << last_func << " ]";
            if(last_ln == built_ln) debug_stream << " (when built)";
            debug_stream << " to" << " [ " << crt_ln << " : " << crt_func << " ]" << "\n";
            last_pt = built_pt, last_ln = built_ln, last_func = built_func;
        }
        else
        {
            debug_stream << "[ " << crt_ln << " : " << crt_func << " ] " << "myclock_t::get failed (yet to be built clock!)\n";
        }
    }
};
#ifdef LOCAL
    myclock_t myclock;
    #define build_clock() myclock.build(__LINE__, __func__)
    #define set_clock() myclock.set(__LINE__, __func__)
    #define get_clock() myclock.get(__LINE__, __func__)
#else
    #define build_clock()
    #define set_clock()
    #define get_clock()
#endif

namespace std
{
    template <class RAitr> void rsort(RAitr __first, RAitr __last) { sort(__first, __last, greater<>()); }
    template <class T> size_t hash_combine(size_t seed, T const &key) { return seed ^ (hash<T>()(key) + 0x9e3779b9 + (seed << 6) + (seed >> 2)); }
    template <class T, class U> struct hash<pair<T,U>> { size_t operator()(pair<T,U> const &pr) const { return hash_combine(hash_combine(0, pr.first), pr.second); } };
    template <class tuple_t, size_t index = tuple_size<tuple_t>::value - 1>
    struct tuple_hash_calc { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(tuple_hash_calc<tuple_t, index - 1>::apply(seed, t), get<index>(t)); } };
    template <class tuple_t> struct tuple_hash_calc<tuple_t, 0> { static size_t apply(size_t seed, tuple_t const &t) { return hash_combine(seed, get<0>(t)); } };
    template <class ...T> struct hash<tuple<T...>> { size_t operator()(tuple<T...> const &t) const { return tuple_hash_calc<tuple<T...>>::apply(0, t); } };
    template <class T, class U> istream &operator>> (std::istream &s, pair<T,U> &p) { return s >> p.first >> p.second; }
    template <class T, class U> ostream &operator<< (std::ostream &s, const pair<T,U> p) { return s << p.first << " " << p.second; }
    template <class T> istream &operator>> (istream &s, vector<T> &v) { for(T &e : v) { s >> e; } return s; }
    template <class T> ostream &operator<< (ostream &s, const vector<T> &v) { for(size_t i = 0; i < v.size(); ++i) { s << (i ? " " : "") << v[i]; } return s; }
    template <class tuple_t, size_t index>
    struct tupleos
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            tupleos<tuple_t,index - 1>::apply(s,t);
            return s << " " << get<index>(t);
        }
    };
    template <class tuple_t>
    struct tupleos<tuple_t, 0>
    {
        static ostream &apply(ostream &s, const tuple_t &t)
        {
            return s << get<0>(t);
        }
    };
    template <class ...T> ostream &operator<< (ostream &s, const tuple<T...> &t)
    {
        return tupleos<tuple<T...>, tuple_size<tuple<T...>>::value - 1>::apply(s,t);
    }
    template <> ostream &operator<< (ostream &s, const tuple<> &t) { return s; }
}


#ifdef LOCAL
    #define dump(...) debug_stream << " [ " << __LINE__ << " : " << __FUNCTION__ << " ] " << #__VA_ARGS__ << " : ", dump_func(__VA_ARGS__)
#else
    #define dump(...)
#endif
template <class T> void dump_func(const T &x) { debug_stream << x << '\n'; }
template <class T,class ...Rest> void dump_func(const T &x, Rest ... rest) { debug_stream << x << ", "; dump_func(rest...); }
template <class T> void write(const T &x) { std::cout << x << '\n'; }
template <class T, class ...Rest> void write(const T &x, Rest ... rest) { std::cout << x << ' '; write(rest...); }
void writeln() {}
template <class T, class ...Rest> void writeln(const T &x, Rest ... rest) { std::cout << x << '\n'; writeln(rest...); }
#define esc(...) writeln(__VA_ARGS__), exit(0)
template <class P> void read_range(P __first, P __second) { for(P i = __first; i != __second; ++i) std::cin >> *i; }

template <class T> bool chmin(T &x, const T &y) { return x > y ? x = y, true : false; }
template <class T> bool chmax(T &x, const T &y) { return x < y ? x = y, true : false; }
template <class T> constexpr T minf(const T &x, const T &y) { return std::min(x,y); }
template <class T> constexpr T maxf(const T &x, const T &y) { return std::max(x,y); }
template <class int_t, class F>
int_t bin(int_t ok, int_t ng, const F &f)
{
    while (std::abs(ok - ng) > 1)
    {
        int_t mid = (ok + ng) / 2;
        (f(mid) ? ok : ng) = mid;
    }
    return ok;
}
template <class A, size_t N, class T> void init(A (&array)[N], const T &val) { std::fill((T*)array, (T*)(array + N), val); }
template <class A, size_t N> void init(A (&array)[N]) { memset(array, 0, sizeof(array)); }
void for_subset(int_fast64_t s, const std::function<void(int_fast64_t)> &fn) { int_fast64_t t = s; do { fn(t); } while((--t &= s) != s); }

namespace math
{
    template <class int_t>
    constexpr int_t gcd(int_t x, int_t y)
    {
        x = x > 0 ? x : -x, y = y > 0 ? y : -y;
        while(y) y ^= x ^= y ^= x %= y;
        return x;
    }
    template <class int_t>
    constexpr int_t lcm(int_t x, int_t y)
    {
        return x ? x / gcd(x, y) * y : 0;
    }
    template <class int_t>
    constexpr std::tuple<int_t, int_t, int_t> ext_gcd(int_t a, int_t b)
    {
        int_t sgn_a = a >= 0 ? 1 : (a = -a, 0), sgn_b = b >= 0 ? 1 : (b = -b, 0);
        int_t p = 1, q = 0, r = 0, s = 1;
        while(b)
        {
            int_t t = a / b;
            r ^= p ^= r ^= p -= t * r;
            s ^= q ^= s ^= q -= t * s;
            b ^= a ^= b ^= a %= b;
        }
        return std::tuple<int_t, int_t, int_t>(a, sgn_a ? p : -p, sgn_b ? q : -q);
    }
    template <class int_t>
    constexpr std::pair<int_t, int_t> mod_comp(int_t k, int_t m, int_t l, int_t n)
    {
        assert(m > 0 and n > 0);
        int_t g, x, y; std::tie(g, x, y) = ext_gcd(m, n);
        k += ((k %= m) < 0) * m, l += ((l %= n) < 0) * n;
        int_t s = k / g, t = l / g, r = k % g;
        if(r != l % g) return std::pair<int_t, int_t>(-1, -1);
        int_t lcm = m / g * n;
        return std::pair<int_t, int_t>((m * x % lcm * t % lcm + n * y % lcm * s % lcm + r + lcm * 2) % lcm, lcm);
    }
}



signed main()
{
    void solve();
    void input();
    void init();

    int t = 1;

    


    while(t--)
    {
        init();
        input();
        solve();
    }
}


using namespace std;
using namespace math;

template <class cap_t, class cost_t>
struct Flow {
    struct edge_t {
        int from, to; cap_t cap; cost_t cost; size_t rev;
        edge_t(int _from, int _to, cap_t _cap, cost_t _cost, size_t _rev)
            : from(_from), to(_to), cap(_cap), cost(_cost), rev(_rev)
        {}
    };

    size_t V,E;
    vector<vector<size_t>> adj;
    vector<edge_t> edge;
    bool neg_edge_exist;

    Flow(size_t _V)
        : V(_V), E(), edge(), neg_edge_exist()
    {
        adj.resize(V);
    }

    void add_edge(int from, int to, cap_t cap, cost_t cost) {
        assert(cap >= 0);
        size_t pos = edge.size();
        size_t rpos = pos + 1;
        edge.emplace_back(from, to, cap, cost, rpos);
        adj[from].emplace_back(pos);
        edge.emplace_back(to, from, 0, -cost, pos);
        adj[to].emplace_back(rpos); 
        ++E; if(cost < 0) neg_edge_exist = true;
    }

    vector<cost_t> Dijkstra(int s) {
        vector<cost_t> dist(V, inf<cost_t>);
        priority_queue<pair<cost_t,int>, vector<pair<cost_t,int>>, greater<pair<cost_t,int>>> que;
        que.emplace(dist[s] = 0, s);
        while(!que.empty()) {
            auto p = que.top(); que.pop();
            int v = p.second;
            if(dist[v] < p.first) continue;
            for(size_t i : adj[v]) {
                edge_t &e = edge[i];
                if(e.cap > 0 && dist[v] + e.cost < dist[e.to]) que.emplace(dist[e.to] = dist[v] + e.cost, e.to);
            } 
        }
        return dist;
    }

    struct Fold_Fulkerson_exe {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;  
        vector<bool> used;

        Fold_Fulkerson_exe(Flow &_F) : edge(_F.edge), adj(_F.adj)
        {
            used.resize(_F.V);
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            used[v] = true;
            for(size_t i : adj[v]) {
                edge_t &e = edge[i];
                if(!used[e.to] && e.cap > 0) {
                    cap_t d = dfs(e.to,t,min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        edge[e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        cap_t max_flow(int s, int t) {
            cap_t flow = 0,f;
            while(true) {
                fill(begin(used),end(used),false);
                if((f = dfs(s,t,numeric_limits<cap_t>::max())) > 0) flow += f;
                else break;
            }
            return flow;
        }
    };

    cap_t Fold_Fulkerson(int s, int t) { return Fold_Fulkerson_exe(*this).max_flow(s,t); }
    
    struct Dinic_exe {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;
        vector<int> level,itr;

        Dinic_exe(Flow &_F) : edge(_F.edge), adj(_F.adj)
        {
            level.resize(_F.V), itr.resize(_F.V);
        }

        void bfs(int s) {
            fill(begin(level),end(level),-1);
            queue<int> que;
            level[s] = 0;
            que.emplace(s);
            while(!que.empty()) {
                int v = que.front(); que.pop();
                for(size_t i : adj[v]) {
                    edge_t &e = edge[i];
                    if(e.cap > 0 && level[e.to] < 0) {
                        level[e.to] = level[v] + 1;
                        que.emplace(e.to);
                    }
                } 
            }
        }

        cap_t dfs(int v, int t, cap_t f) {
            if(v == t) return f;
            for(int &i = itr[v]; i < (int)adj[v].size(); ++i) {
                edge_t &e = edge[adj[v][i]];
                if(e.cap > 0 && level[v] < level[e.to]) {
                    cap_t d = dfs(e.to, t, min(f,e.cap));
                    if(d > 0) {
                        e.cap -= d;
                        edge[e.rev].cap += d;
                        return d;
                    }
                }
            }
            return 0;
        }

        cap_t max_flow(int s, int t) {
            cap_t flow = 0, f;
            while(bfs(s), level[t] >= 0) {
                fill(begin(itr), end(itr), 0);
                while((f = dfs(s, t, numeric_limits<cap_t>::max())) > 0) flow += f;
            }
            return flow;
        }
    };

    cap_t Dinic(int s, int t) { return Dinic_exe(*this).max_flow(s, t); }

    struct Primal_Dual_exe {
        vector<edge_t> &edge;
        vector<vector<size_t>> &adj;
        size_t &V;
        vector<cost_t> dist, h;
        vector<int> prev_v;
        vector<edge_t*> prev_e;

        Primal_Dual_exe(Flow &_F)
            : edge(_F.edge), adj(_F.adj), V(_F.V)
        {
            dist.resize(_F.V), h.resize(_F.V), prev_v.resize(_F.V), prev_e.resize(_F.V);
        }

        bool Dijkstra(int s, int t) {
            priority_queue<pair<cost_t,int>, vector<pair<cost_t,int>>, greater<pair<cost_t,int>>> que;
            fill(begin(dist), end(dist), inf<cost_t>);
            que.emplace(dist[s] = 0, s);
            while(!que.empty()) {
                cost_t _cost; int v;
                tie(_cost, v) = que.top();
                que.pop();
                if(_cost != dist[v]) continue;
                for(size_t i : adj[v]) {
                    edge_t &e = edge[i];
                    if(e.cap > 0 && dist[v] + h[v] + e.cost < dist[e.to] + h[e.to]) {
                        que.emplace(dist[e.to] = dist[v] + h[v] - h[e.to] + e.cost, e.to);
                        prev_v[e.to] = v;
                        prev_e[e.to] = &e;
                    }
                }
            } 
            if(dist[t] >= inf<cost_t>) return false;
            for(size_t v = 0; v < V; ++v) {
                h[v] += dist[v];
                if(h[v] > inf<cost_t>) h[v] = inf<cost_t>;
            }
            return true;
        }

        cost_t min_cost_flow(int s, int t, cap_t f) {
            cost_t res = 0;
            fill(begin(h), end(h), 0);
            while(f > 0) {
                if(!Dijkstra(s, t)) return inf<cost_t>;
                cap_t d = f;
                for(int v = t; v != s; v = prev_v[v]) d = min(d, prev_e[v]->cap);
                f -= d;
                res += h[t] * d;
                for(int v = t; v != s; v = prev_v[v]) {
                    prev_e[v]->cap -= d;
                    edge[prev_e[v]->rev].cap += d;
                }
            }
            return res;
        }
    };

    cost_t Primal_Dual(int s, int t, cap_t f) {
        cost_t corr = 0;
        if(neg_edge_exist) {
            int _s = V++;
            int _t = V++;
            adj.resize(V);
            add_edge(_s, s, f, 0);
            add_edge(t, _t, f, 0);
            s = _s, t = _t;
            vector<pair<int, cap_t>> s_addv, t_addv;
            for(edge_t &e : edge) {
                if(e.cap > 0 and e.cost <  0) {
                    f += e.cap;
                    s_addv.emplace_back(e.to, e.cap);
                    t_addv.emplace_back(e.from, e.cap);
                    corr += e.cost * e.cap;
                    edge[e.rev].cap += e.cap;
                    e.cap = 0;
                }
            }
            for(auto &p : s_addv) add_edge(s, p.first, p.second, 0);
            for(auto &p : t_addv) add_edge(p.first, t, p.second, 0);
            neg_edge_exist = false;
        }
        return Primal_Dual_exe(*this).min_cost_flow(s, t, f) + corr;
    } 
};

int n,m;
string g[1<<20];

void init()
{}

void input()
{
    std::cin >> n >> m;
    read_range(g, g+n);
}

int in(int i,int j)
{
    return (i*m+j)*2;
}

int out(int i,int j)
{
    return (i*m+j)*2+1;
}

void solve()
{
    Flow<int,int> flow(n*m*2);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j]!='#') flow.add_edge(in(i,j),out(i,j),1,0);
            if(i+1<n)
            {
                flow.add_edge(out(i,j),in(i+1,j),inf<int>,0);
            }
            if(j+1<m)
            {
                flow.add_edge(out(i,j),in(i,j+1),inf<int>,0);
            }
        }
    }
    std::cout << flow.Fold_Fulkerson(out(0,0),in(n-1,m-1)) << "\n";
}