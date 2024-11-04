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

int n,m;
string g[1<<20];

void init()
{}

void input()
{
    std::cin >> n >> m;
    read_range(g, g+n);
}

void solve()
{
    vector<vector<int>> ok(n);
    for(int i=0; i<n; i++)
    {
        ok[i].resize(m);
    }
    auto ok2=ok;

    queue<pii> que;
    que.emplace(0,0);
    while(not que.empty())
    {
        int x,y; tie(x,y)=que.front();
        que.pop();
        ok[x][y]=1;
        for(int i=0; i<2; i++)
        {
            int xx,yy;
            xx=x+dx[i],yy=y+dy[i];
            if(min(xx,yy)>=0 and xx<n and yy<m and g[xx][yy]!='#' and not ok[xx][yy])
            {
                que.emplace(xx,yy);
                ok[xx][yy]=1;
            }
        }
    }
    if(not ok[n-1][m-1])
    {
        std::cout << 0 << "\n";
        return;
    }

    int ans=0;
    if(n>1 and ok[n-2][m-1])
    {
        ans++;
    }
    if(m>1 and ok[n-1][m-2])
    {
        ans++;
    }

    que.emplace(n-1,m-1);
    while(not que.empty())
    {
        int x,y; tie(x,y)=que.front();
        que.pop();
        ok2[x][y]=1;
        for(int i=0; i<2; i++)
        {
            int xx,yy;
            xx=x-dx[i],yy=y-dy[i];
            if(min(xx,yy)>=0 and xx<n and yy<m and g[xx][yy]!='#' and not ok2[xx][yy])
            {
                que.emplace(xx,yy);
                ok2[xx][yy]=1;
            }
        }
    }

    int ans3=2;
    for(int j=0; j<m; j++)
    {
        vector<int> ve;
        int cnt=0;
        bool cont=1;
        for(int i=0; i<n; i++)
        {
            if(ok[i][j] and ok2[i][j])
            {
                ve.emplace_back(i);
                cnt++;
            }
        }

        for(int i=1; i<ve.size(); ++i)
        {
            if(ve[i]!=ve[i-1]+1)
            {
                cont=false;
            }
        }

        if(cont)
        {
            vector<int> up(n);
            vector<int> low(n);

            int a=ve.front(),b=ve.back();

            up[a]=1;
            low[b]=1;

            for(int i=a+1; i<=b; ++i)
            {
                if(j+1==m or not ok2[i-1][j+1])
                {
                    up[i]=up[i-1];
                }
                else
                {
                    up[i]=0;
                }
            }

            

            for(int i=b-1; i>=a; --i)
            {
                if(not j or not ok[i+1][j-1])
                {
                    low[i]=low[i+1];
                }
                else
                {
                    low[i]=0;
                }
            }
            
            for(int i=a; i<=b; ++i)
            {
                if(up[i] and low[i])
                {
                    if(i==0 and j==0) continue;
                    if(i+1==n and j+1==m) continue;
                    std::cout << 1 << "\n";
                    return;
                }
            }
        }
    }
    
    

    int ans2=0;

    if(n>1 and g[1][0]!='#')
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ok[i][j]=0;
            }
        }
        queue<pii> que;
        que.emplace(1,0);
        while(not que.empty())
        {
            int x,y; tie(x,y)=que.front();
            que.pop();
            ok[x][y]=1;
            for(int i=0; i<2; i++)
            {
                int xx,yy;
                xx=x+dx[i],yy=y+dy[i];
                if(min(xx,yy)>=0 and xx<n and yy<m and not ok[xx][yy])
                {
                    que.emplace(xx,yy);
                    ok[xx][yy]=1;
                }
            }
        }
        if(ok[n-1][m-1])
        {
            ans2++;
        }
    }

    if(m>1 and g[0][1]!='#')
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ok[i][j]=0;
            }
        }
        queue<pii> que;
        que.emplace(0,1);
        while(not que.empty())
        {
            int x,y; tie(x,y)=que.front();
            que.pop();
            for(int i=0; i<2; i++)
            {
                int xx,yy;
                xx=x+dx[i],yy=y+dy[i];
                if(min(xx,yy)>=0 and xx<n and yy<m and ok[xx][yy]!=1)
                {
                    que.emplace(xx,yy);
                    ok[xx][yy]=1;
                }
            }
        }
        if(ok[n-1][m-1])
        {
            ans2++;
        }
    }


    

    std::cout << min({ans,ans2,ans3}) << "\n";

}