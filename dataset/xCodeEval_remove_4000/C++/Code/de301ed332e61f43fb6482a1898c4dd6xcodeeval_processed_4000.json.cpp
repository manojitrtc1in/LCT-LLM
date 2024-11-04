




























                        

                        



using namespace std;    








template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }








typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
namespace fio {
typedef unsigned int uint;
typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef long double llf;
template<typename T> inline T abs(T a){return a>0?a:-a;}
struct Cg{inline char operator()(){return (char)getchar();}};
struct Cp{inline void operator()(char x){putchar(x);}};
struct Cpe{inline void operator()(char x){putc(x,stderr);}};
inline bool IS(char x){return x==10||x==13||x==' ';}template<typename T>struct Fr{T P;inline Fr&operator,(int &x)
{x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator int(){int x;*this,x;return x;}inline Fr&operator,(ll &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(f)x=-x;return *this;}inline operator ll(){ll x;*this,x;return x;}inline Fr&operator,(char &x)
{for(x=P();IS(x);x=P())continue;return *this;}inline operator char(){char x;*this,x;return x;}inline Fr&operator,(char *x){char t=P();for(;IS(t);t=P())continue;if(~t){for(;!IS(t)&&~t;t=P())*x++=t;}*x++=0;return *this;}inline Fr&operator,(lf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator lf(){lf x;*this,x;return x;}inline Fr&operator,(llf &x){x=0;char t=P();while((t<'0'||t>'9')&&t!='-')t=P();bool f=0;if(t=='-')t=P(),f=1;x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';if(t=='.'){lf u=0.1;for(t=P();t>='0'&&t<='9';t=P(),u*=0.1)x+=u*(t-'0');}if(f)x=-x;return *this;}inline operator llf()
{llf x;*this,x;return x;}inline Fr&operator,(uint &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator uint(){uint x;*this,x;return x;}inline Fr&operator,(ull &x){x=0;char t=P();while(t<'0'||t>'9')t=P();x=t-'0';for(t=P();t>='0'&&t<='9';t=P())x=x*10+t-'0';return *this;}inline operator ull(){ull x;*this,x;return x;}};
template<typename T>struct Fw{T P;inline Fw&operator,(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(int x){if(x){if(x<0)P('-'),x=-x;char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}
inline Fw&operator()(uint x){if(x){char s[10];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()(ll x){if(x){if(x<0)P('-'),x=-x;char s[19];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator()
(ull x){if(x){char s[20];int c=0;while(x)s[c++]=x%10+'0',x/=10;while(c--)P(s[c]);}else P('0');return *this;}inline Fw&operator,(char x){P(x);return *this;}inline Fw&operator()(char x){P(x);return *this;}inline Fw&operator,(const char *x){while(*x)P(*x++);return *this;}
inline Fw&operator()(const char *x){while(*x)P(*x++);return *this;}inline Fw&operator()(lf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}inline Fw&operator()(llf x,int y){if(y){lf t=0.5;for(int i=y;i--;)t*=0.1;if(x>=0)x+=t;else x-=t,P('-');*this,(ll)(abs(x));P('.');if(x<0)x=-x;while(y--){x*=10;x-=floor(x*0.1)*10;P(((int)x)%10+'0');}}else if(x>=0)*this,(ll)(x+0.5);else *this,(ll)(x-0.5);;return *this;}};
}
fio::Fw<fio::Cp> fout;
fio::Fw<fio::Cpe> ferr;
fio::Fr<fio::Cg> fin;
template <typename T>
struct identity_visitor { 
    static T &get(T &value) { return value; }
    static T get(const T &value) { return value; }
};
struct empty_type { };


template <typename It>
struct iter_range : std::pair<It, It> {
    typedef std::pair<It, It> base_t;
    typedef It iterator;
    using base_t::base_t;
    It begin() { return base_t::first; }
    It end() { return base_t::second; }
};
template <typename It>
iter_range<It> make_range(It b, It e) {
    return iter_range<It>(b, e);
}
template <typename It>
iter_range<std::reverse_iterator<It>> rev(const iter_range<It> &origin) {
    using rev_t = std::reverse_iterator<It>;
    return {rev_t(origin.second), rev_t(origin.first)};
}


template <typename EAttr = empty_type>
struct graph {
    typedef int Index;
    struct E : EAttr {
        Index from, to;
        E() { }
        E(Index from, Index to, const EAttr &attr)
            : EAttr(attr), from(from), to(to) { }
    };
    typedef typename std::deque<E> list_type;
    typedef typename list_type::iterator list_iter_type;
    struct target_iter : list_iter_type { 

        using list_iter_type::list_iter_type;
        Index operator*() { return (*this)->to; }
    };
    graph(int n) : edges(n) { }
    void assign(int n) { edges.assign(n); }
    int size() { return (int)edges.size(); }
    void add(int u, int v, EAttr attr = EAttr()) {
        edges[u].push_back({u, v, attr});
    }
    iter_range<target_iter> operator[](int u) {
        return make_range(target_iter(edges[u].begin()), target_iter(edges[u].end()));
    }
    std::vector<list_type> edges; 

};


template <typename Flow>
struct id1 {
    typedef int Index;
    struct attr {
        Flow f;
        Index rev;
    };
    graph<attr> g;
    id1(int max_vertex) : g(max_vertex) { }
    void add(Index from, Index to, Flow cap, Flow rev_cap = 0) { 

        if (from == to) return;
        attr e1 = {cap, (int)g.edges[to].size()};
        attr e2 = {rev_cap, (int)g.edges[from].size()};
        g.add(from, to, e1);
        g.add(to, from, e2);
    }
    bool dinic_bfs(Index s, Index t, std::vector<int> &level) {
        std::vector<int> q(g.size()); 

        int qh = 0, qt = 0;
        level[s] = 1;
        q[qt++] = s;
        while (qh < qt && !level[t]) {
            int u = q[qh++];
            for (auto &e : g.edges[u]) {
                int v = e.to;
                if (!level[v] && e.f > 0) {
                    level[v] = level[u] + 1;
                    q[qt++] = v;
                }
            }
        }
        return level[t];
    }
    Flow dinic_dfs(Index u, Index t, Flow flow, const std::vector<int> &level) {
        if (u == t) return flow;
        Flow pushed = 0;
        for (auto &e : g.edges[u]) {
            if (!flow) break;
            int v = e.to;
            Flow w = e.f;
            if (level[v] == level[u] + 1 && w) {
                Flow f = dinic_dfs(v, t, std::min(flow, w), level);
                e.f -= f;
                g.edges[v][e.rev].f += f;
                flow -= f;
                pushed += f;
                

            }
        }
        return pushed;
    }
    Flow max_flow(int s, int t) {
        Flow flow = 0;
        std::vector<int> level(g.size()); 

        while (dinic_bfs(s, t, level)) {
            

            

            

            flow += dinic_dfs(s, t, std::numeric_limits<Flow>::max(), level);
            fill(level.begin(), level.end(), 0);
        }
        return flow;
    }
};


struct prime_list {
    prime_list(int n) {
        size = std::max(n, 2);
        prime_factor.resize(size);
        for (int p = 2; p < size; ++p) if (!prime_factor[p]) {
            primes.push_back(p);
            for (int pp = p; pp < size; pp += p)
                prime_factor[pp] = p;
        }
    }
    bool is_prime(int n) {
        return n > 1 && prime_factor[n] == n;
    }
    int size;
    std::vector<int> prime_factor; 

    std::vector<int> primes;
};
template <typename Int = int>
using prime_factor_t = std::vector<std::pair<Int, int>>; 







template <typename Int>
prime_factor_t<Int> prime_factor(Int x) {
    prime_factor_t<Int> ret;
    if (x <= 1) return ret;
    for (int p = 2; Int(p) * p <= x; ++p) {
        int m = 0;
        while (x % p == 0) ++m, x /= p;
        if (m) ret.push_back(std::make_pair(p, m));
    }
    if (x > 1) 
        ret.push_back(std::make_pair(x, 1)); 

    return ret;
}
template <typename Int>
static bool id0(Int x) {
    if (x <= 1) return false;
    for (Int p = 2; p * p <= x; ++p) {
        while (x % p == 0) return false;
    }
    return true;
}




template <typename Int>
prime_factor_t<Int> prime_factor(Int x, const prime_list &plist) {
    prime_factor_t<Int> ret;
    if (x <= 1) return ret;
    for (int p : plist.primes) {
        if (x < Int(p) * p) break;
        int m = 0;
        while (x % p == 0) ++m, x /= p;
        if (m) ret.push_back(std::make_pair(p, m));
    }
    if (x > 1) 
        ret.push_back(std::make_pair(x, 1));
    return ret;
}



























int n;
prime_list PL(100005);
int main() {
    fin, n;
    vector<int> arr(n);
    int even = 0, odd = 0;
    FOR0(i, n) {
        fin, arr[i];
        if (arr[i] % 2 == 0) ++even;
        else ++odd;
    }
    if (even != odd) {
        puts("Impossible");
        return 0;
    }
    id1<int> mf(2 * n + 2);
    FOR0(i, n) {
        mf.add(2 * n, i, 2);
        mf.add(n + i, 2 * n + 1, 2);
    }
    FOR0(i, n) FOR0(j, n) if (arr[i] % 2 == 0 && arr[j] % 2 == 1 && i != j) {
        if (PL.is_prime(arr[i] + arr[j])) {
            mf.add(i, n + j, 1);
            pr_debug("%d -> %d\n", arr[i], arr[j]);
        }
    }
    if (mf.max_flow(2 * n, 2 * n + 1) == n) {
        vvi ans;
        vi visit(n);
        FOR0(i, n) if (arr[i] % 2 == 0 && !visit[i]) {
            vi cnn = {};
            vi stk = {i};
            while (stk.size()) {
                assert(stk.size() == 1);
                int j = stk.back(); stk.pop_back();
                if (visit[j % n]) continue;
                visit[j % n] = true;
                cnn.push_back(j % n);
                for (auto &e : mf.g.edges[j]) {
                    if (!visit[e.to % n] && ((n <= e.to && e.to < 2 * n && e.f == 0) || 
                                            ((0 <= e.to && e.to < n && e.f == 1)))) {
                        stk.push_back(e.to);
                        pr_debug("ins %d -> %d\n", j, e.to);
                        break;
                    }
                }
            }
            pr_debug("fin\n");
            ans.push_back(cnn);
        }
        printf("%d\n", (int)ans.size());
        for (vi &v : ans) {
            printf("%d ", (int)v.size());
            for (int ix = 0; ix < (int)v.size(); ++ix) {
                printf("%d ", v[ix] + 1);
                int i = v[ix];
                int j = v[(ix + 1) % (int)v.size()];
                if (!PL.is_prime(arr[i] + arr[j])) {
                    pr_debug("i = %d j = %d sum = %d\n", i, j, arr[i] + arr[j]);
                    throw 0;
                }
            }
            printf("\n");
        }
    } else {
        puts("Impossible");
    }
    return 0;
}
