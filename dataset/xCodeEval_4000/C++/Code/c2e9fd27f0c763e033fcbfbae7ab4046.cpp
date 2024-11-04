
#include <cstdio>
#include <cmath>
#include <climits>      

#include <cfloat>       

#include <cstring>      

#include <cstdlib>      

#include <cstdint>      

#include <cinttypes>    

#include <ctime>        

#include <cassert>      

#include <limits>       

#include <vector>
#include <deque>
#include <map>
#include <set>
#include <tuple>        

#include <iostream>     

                        

                        

#include <sstream>
#include <algorithm>
using namespace std;    

#ifdef LOCAL_JUDGE
#  define pr_debug(...) fprintf(stderr, __VA_ARGS__)
#  define pr_line() fprintf(stderr, "%s: %d\n", __FILE__, __LINE__)
#else
#  define pr_debug(...)
#  define pr_line()
#endif
template <typename T>
bool chmax(T &m, const T &v) { if (v > m) return m = v, true; return false; }
template <typename T>
bool chmin(T &m, const T &v) { if (v < m) return m = v, true; return false; }
template <typename T>
bool chinc(T &v1, T &v2) { if (v1 > v2) return swap(v1, v2), true; return false; }
template <typename T>
bool chdec(T &v1, T &v2) { if (v1 < v2) return swap(v1, v2), true; return false; }
#define ALL(x) begin(x), end(x)
#define FOR0(i,n) for(int i=0,i##end=n;i<i##end;i++)
#define FOR1(i,n) for(int i=1,i##end=n;i<=i##end;i++)
#define FOR(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define FOD0(i,n) for(int i=(n)-1;~i;i--)
#define FOD1(i,n) for(int i=n;i;i--)
#define FOD(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
#define FORE(i,x)for(__typeof(x.end())i=x.begin();i!=x.end();++i)
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pair<int, int>> vii;
typedef vector<vector<int>> vvi;
namespace fio {
static const char eof = '\xff';
#define LL long long
#define I inline
#define OP operator
#define RT return*this;
#define ALL_INT(mcr) mcr(int)mcr(long)mcr(LL)mcr(unsigned)mcr(unsigned long)mcr(unsigned LL)
#define ALL_FLT(mcr) mcr(float)mcr(double)mcr(long double)
#define S2D x=0;int c=P();while((c<'0'||c>'9')&&c!='-')c=P();bool h=false;if(c=='-')h=true,c=P()
#define R2D for(;c>='0'&&c<='9';c=P())x=x*10+c-'0'
#define R2F if(c=='.'){double u=0.1;for(c=P();c>='0'&&c<='9';c=P(),u*=0.1)x+=u*(c-'0');}
#define RD_INT(Int) I Fr&OP,(Int&x){S2D;R2D;if(h)x=-x;RT}
#define RD_FLT(Flt) I Fr&OP,(Flt&x){S2D;R2D;R2F;if(h)x=-x;RT}
struct Cg{I char OP()(){char c=(char)getchar();if(c == eof)valid=false;return c;};bool valid=true;};
struct Cp{I void OP()(int x){putchar(x);}};
struct Ce{I void OP()(int x){putc(x,stderr);}};
I bool IS(char x){return x==' '||x=='\r'||x=='\n'||x=='\t';}
template<class T>struct Fr{T P;ALL_INT(RD_INT)ALL_FLT(RD_FLT)I Fr&OP,(char&x){for(x=P();IS(x);)x=P();RT}
I Fr&OP,(char*s){for(*s=P();IS(*s)&&P.valid;)*s=P();for(;!IS(*s)&&P.valid;)*++s=P();*s=0;RT}
I Fr&OP,(string &s){s.clear();char c=P();for(;IS(c)&&P.valid;)c=P();for(;!IS(c)&&P.valid;)s.push_back(c),c=P();RT}
I OP bool() { return P.valid; }
};
#define W4D if(x){if(x<0)P('-'),x=-x;int p=0;while(x)B[p++]=x%10+'0',x/=10;while(p--)P(B[p]);}else P('0')
#define WR_INT(Int) I Fw&OP,(Int x){W4D;RT}
#define WR_FLT(Flt) I Fw&OP()(Flt g,int d){if(d){double t=0.5;for(int i=d;i--;)t*=0.1;if(g<0)P('-'),g=-g;g+=t;*this,(LL)(g);P('.');g-=floor(g);while(d--){g*=10;int i=(int)floor(g);P(i+'0');g-=i;}}else*this,(g>0?(LL)(g+0.5):(LL)(g-0.5));RT}
template<class T>struct Fw{T P;char B[32];ALL_INT(WR_INT)ALL_FLT(WR_FLT)I Fw&OP,(char x){P(x);RT}typedef char_traits<char>CT;typedef basic_ostream<char,CT>&OS;typedef basic_istream<char,CT>&IS;I Fw&OP,(OS&(*func)(OS)){if(func==static_cast<OS&(*)(OS)>(endl<char,CT>))P('\n');RT}I Fw&OP,(IS&(*func)(IS)){if(func==static_cast<IS&(*)(IS)>(ws<char,CT>))P(' ');RT}
I Fw&OP,(const char*s){for(;*s;++s)P(*s);RT}
I Fw&OP,(const string&s){(*this),s.c_str();RT}
template<class C>I Fw&all(const C &v, char sep=' ', char nl='\n'){auto it=v.begin();for(int i=0;i<(int)v.size();++i,++it){if(i&&sep)P(sep);(*this),*it;}if(nl)P(nl);RT}
template<class U>I Fw&print(U x){(*this),x;P('\n');RT}
template<class U,class...Us>I Fw&print(U x,Us...args){(*this),x;P(' ');print(args...);RT}
};
#undef LL
#undef I
#undef OP
#undef RT
#undef ALL_INT
#undef ALL_FLT
#undef S2D
#undef R2D
#undef R2F
#undef RD_INT
#undef RD_FLT
#undef W4D
#undef WR_INT
#undef WR_FLT
}
fio::Fr<fio::Cg>fin;
fio::Fw<fio::Cp>fout;
fio::Fw<fio::Ce>ferr;


#include <utility>


static inline unsigned all_ones(unsigned x) {
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    return x;
}
static inline int floor_log2(unsigned x) {
    int ans = 0;
    while (x >>= 1)
	++ans;
    return ans;
}
static inline bool is_pow2(unsigned x) {
    return !(x & (x - 1));
}
static inline unsigned next_pow2(unsigned x) {
    return all_ones(x) + 1;
}
static inline unsigned ceil_pow2(unsigned x) {
    if (is_pow2(x)) return x;
    return next_pow2(x);
}


static inline int msb32(unsigned int x) {
    x = all_ones(x);
    return x & ~(x >> 1);
}
static inline int lsb32(unsigned int x) {
    return x & -x;
}


template <typename T>
struct binary_plus {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 + t2; }
    T negate(const T &t) { return -t; }
};

template <typename T>
struct binary_xor {
    T identity() const { return T(); }
    T operator()(const T &t1, const T &t2) const { return t1 ^ t2; }
    T negate(const T &t) { return t; }
};
template <typename T>
struct binary_max {
    T identity() const { return std::numeric_limits<T>::min(); }
    T operator()(const T &t1, const T &t2) const { return std::max(t1, t2); }
};
template <typename T>
struct binary_min {
    T identity() const { return std::numeric_limits<T>::max(); }
    T operator()(const T &t1, const T &t2) const { return std::min(t1, t2); }
};
#define COMMON_CODE \
    Op op; \
    std::vector<T> vec; \
    int size;  \
    int offset; \
    segtree(int n) { \
        size = n; \
        offset = ceil_pow2(n); \
        vec.resize(size + offset + 1, op.identity());  \
    } \
    T &operator[](int i) { \
        return vec[offset + i]; \
    }
template <typename T, typename Op = binary_plus<T>, bool flavour_one = true>
struct segtree;
template <typename T, typename Op>
struct segtree<T, Op, true>
{
    

    

    

    COMMON_CODE
    void rebuild() {
        for (int i = (offset + size - 1) / 2; i > 0; --i)
            vec[i] = op(vec[i + i], vec[i + i + 1]);
    }
    void increase_element(int p, const T &n) {
        for (p += offset; p; p >>= 1)
            vec[p] = op(n, vec[p]);
    }
    void update_element(int p, const T &n) {
        p += offset;
        vec[p] = n;
        while (p >>= 1)
            vec[p] = op(vec[p + p], vec[p + p + 1]);
    }
    T query_range(int s, int t) {
        return query_include(s, t - 1);
    }
    T query_include(int s, int t) {
        

        if (s > t) return op.identity();
        s += offset;
        t += offset;
        T left_acc = vec[s];
        if (s == t) return left_acc;
        T right_acc = vec[t];
        

        for (; s^t^1; s>>=1, t>>=1) {
            if (~s & 1) left_acc = op(left_acc, vec[s^1]);
            if (t & 1) right_acc = op(vec[t^1], right_acc);
        }
        return op(left_acc, right_acc);
    }
};
template <typename T, typename Op>
struct segtree<T, Op, false>
{
    

    

    

    COMMON_CODE
    T query_element(int p){
        T ret = op.identity();
        for (p += offset; p; p >>= 1)
            ret = op(vec[p], ret);
        return ret;
    }
    void increase_range(int s, int t, const T &inc) {
        return increase_include(s, t - 1, inc);
    }
    void increase_include(int s, int t, const T &inc) {
        if (s > t) return;
        s += offset;
        t += offset;
        vec[s] = op(inc, vec[s]);
        if (s == t) return;
        vec[t] = op(inc, vec[t]);
        

        for (; s^t^1; s>>=1, t>>=1) {
            if (~s & 1) vec[s^1] = op(inc, vec[s^1]);
            if (t & 1) vec[t^1] = op(inc, vec[t^1]);
        }
        return;
    }
    

    void flatten() {
        for (int i = 1; i < offset; ++i) {
            if (i + i < offset + size) {
                vec[i + i] = op(vec[i], vec[i + i]);
                vec[i + i + 1] = op(vec[i], vec[i + i + 1]); 

            } else break;
            vec[i] = op.identity();
        }
    }
};
#undef COMMON_CODE
struct empty_type { };
#include <iterator>
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

        target_iter(const list_iter_type &base): list_iter_type(base) { }
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





static const int maxn = 200005;
int n;
struct attr { int64_t w; };
graph<attr> g(maxn);
bool onstack[maxn], visit[maxn];
int64_t same;
vector<int64_t> dep;
vector<int64_t> edg;
vector<int> cyc;
int64_t dfs_dep(int u, int p) {
    int64_t r = 0;
    int64_t m = 0;
    for (auto e : g.edges[u]) if (e.to != p && !onstack[e.to]) {
        int64_t cur = dfs_dep(e.to, u) + e.w;
        chmax(r, cur);
        chmax(same, cur + m);
        chmax(m, cur);
    }
    chmax(same, r);
    return r;
}
int dfs(int u, int p) { 

    pr_debug("dfs %d\n", u);
    assert(!visit[u]);
    visit[u] = true;
    onstack[u] = true;
    for (auto e : g.edges[u]) if (e.to != p) {
        if (visit[e.to]) {
            cyc.push_back(u);
            edg.push_back(e.w);
            return e.to;
        }
        int root = dfs(e.to, u);
        if (root == -1) {
            onstack[u] = false;
            return -1;
        } else if (root) {
            cyc.push_back(u);
            edg.push_back(e.w);
            return (root == u) ? -1 : root;
        }
    }
    onstack[u] = false;
    return 0;
}
struct node_t {
    int64_t ans, add, sub; 

    node_t() { }
    node_t(int64_t ans, int64_t add, int64_t sub) : ans(ans), add(add), sub(sub) { }
    node_t operator+(const node_t &that) const {
        node_t ret;
        ret.ans = max(ans, that.ans);
        chmax(ret.ans, sub + that.add);
        ret.add = max(add, that.add);
        ret.sub = max(sub, that.sub);
        return ret;
    }
};
segtree<node_t> seg(maxn * 2);
int main() {
    fin, n;
    FOR0(i, n) {
        int u, v; int64_t w; fin, u, v, w;
        g.add(u, v, {w});
        g.add(v, u, {w});
    }
    dfs(1, -1);
    {
        int r = 0;
        FOR0(i, maxn) if (onstack[i]) ++r;
        assert(r == (int)cyc.size());
    }
    FOR0(i, (int)cyc.size()) {
        dep.push_back(dfs_dep(cyc[i], -1));
    }
    reverse(ALL(cyc));
    reverse(ALL(dep));
    reverse(ALL(edg));
    FOR0(i, (int)cyc.size()) {
        pr_debug("%d -> d %lld e %lld\n", cyc[i], dep[i], edg[i]);
    }
    int64_t sum = 0;
    FOR0(i, (int)dep.size()) {
        seg[i] = node_t{ dep[i], dep[i] + sum, dep[i] - sum};
        sum += edg[i];
    }
    FOR0(i, (int)dep.size()) {
        seg[i + (int)dep.size()] = node_t{ dep[i], dep[i] + sum, dep[i] - sum};
        sum += edg[i];
    }
    seg.rebuild();
    pr_debug("sum = %lld same=%lld\n", sum, same);
    int64_t ans = LLONG_MAX;
    FOR0(i, (int)dep.size()) {
        chmin(ans, max(same, seg.query_range(i, i + (int)dep.size()).ans));
        pr_debug("query %d = %lld\n", i, seg.query_range(i, i + (int)dep.size()).ans);
    }
    fout, ans, endl;
    return 0;
}
