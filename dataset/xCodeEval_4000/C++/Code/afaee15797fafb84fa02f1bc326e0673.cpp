



#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>
#include <iostream>
#include <vector>
#include <array>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <bitset>
#include <string>
#include <algorithm>
#include <type_traits>
#include <limits>
#include <cmath>

#define ll long long

#pragma region Utils
namespace Utils
{
template<typename T1, typename T2>
using pair = std::pair<T1, T2>;

template<typename T>
struct ArrayIterator {
    T* pos;
    ArrayIterator(T* pos_ = nullptr) : pos(pos_) {}
    bool operator!=(const ArrayIterator& r) const 
    { return pos != r.pos; }
    bool operator==(const ArrayIterator& r) const 
    { return pos == r.pos; }
    ArrayIterator& operator++() { ++pos; return *this; }
    ArrayIterator& operator--() { --pos; return *this; }
    T& operator*() const { return *pos; }
    T* operator->() const { return pos; }
};

template<typename T>
struct Array {
    Array(T* start_ = nullptr, T* finish_ = nullptr)
        : start(start_), finish(finish_) {}
    ArrayIterator<T> begin() const { return ArrayIterator<T>(start); }
    ArrayIterator<T> end() const { return ArrayIterator<T>(finish); }
private:
    T *start, *finish;
};

template<typename T>
void swap(T& a, T& b) { T t; t = a, a = b, b = t; }	

template<typename T>
T gcd(const T& a, const T& b) { return b ? gcd(b, a % b) : a; }
template<typename T, typename... Rest>
T gcd(const T& first, const Rest& ...rest) {
    return gcd(first, gcd(rest...));
}
template<typename T>
T lcm(const T& a, const T& b) { return a / gcd(a, b) * b; }
template<typename T, typename... Rest>
T lcm(const T& first, const Rest& ...rest) {
    return lcm(first, lcm(rest...));
}

template<typename T, typename... Rest>
T& ugcd(T& first, const Rest& ...rest) {
    return first = gcd(first, gcd(rest...));
}
template<typename T, typename... Rest>
T& ulcm(T& first, const Rest& ...rest) {
    return first = lcm(first, lcm(rest...));
}
template<typename T>
T gcd(const Array<T>& arr) {
    T res = 0;
    for (auto i : arr) ugcd(res, i);
    return res;
}
template<typename T>
T lcm(const Array<T>& arr) {
    if (arr.begin() == arr.end()) return 0;
    T res = *(arr.begin());
    for (auto i : arr) ulcm(res, i);
    return res;
}
template<typename T>
T& ugcd(T& first, const Array<T>& arr) {
    return first = gcd(first, gcd(arr));
}
template<typename T>
T& ulcm(T& first, const Array<T>& arr) {
    return first = lcd(first, lcm(arr));
}

namespace Compares
{
template<typename T>
T max(const T& a) { return a; }
template<typename T>
T max(const T& a, const T& b) { return a >= b ? a : b; }
template<typename T, typename... Rest>
T max(const T& first, const Rest& ...rest) {
    return max(first, max(rest...));
}
template<typename T>
T min(const T& a) { return a; }
template<typename T>
T min(const T& a, const T& b) { return a <= b ? a : b; }
template<typename T, typename... Rest>
T min(const T& first, const Rest& ...rest) {
    return min(first, min(rest...));
}

template<typename T, typename... Rest>
T& umax(T& first, const Rest& ...rest) {
    return first = max(first, max(rest...));
}
template<typename T, typename... Rest>
T& umin(T& first, const Rest& ...rest) {
    return first = min(first, min(rest...));
}

template<typename T>
T max(const Array<T>& arr) {
    T res = std::numeric_limits<T>::min();
    for (auto i : arr) umax(res, i);
    return res;
}
template<typename T>
T min(const Array<T>& arr) {
    T res = std::numeric_limits<T>::max();
    for (auto i : arr) umin(res, i);
    return res;
}
template<typename T>
T& umax(T& first, const Array<T>& arr) {
    return first = max(first, max(arr));
}
template<typename T>
T& umin(T& first, const Array<T>& arr) {
    return first = min(first, min(arr));
}
}

namespace DS
{
template<std::size_t siz>
struct DSU {
    int fa[siz], si[siz];
    DSU() {
        for (int i = 0; i < siz; ++i) fa[i] = i, si[i] = 1;
    }
    int fd(const int& u) { return fa[u] == u ? u : fa[u] = fd(fa[u]); }
    void mg(const int& u, const int& v) {
        u = fd(u), v = fd(v);
        if (u == v) return;
        if (si[u] < si[v]) swap(u, v);
        fa[v] = u, si[u] += si[v];
    }
    bool eq(const int& u, const int& v) { return fd(u) == fd(v); }
};

template<std::size_t siz, typename T = int>
struct BIT {
    inline static int lowbit(int x) { return x & -x; }
    std::array<T, siz> s;
    void add(int p, const T& v = 1) {
        while (p < siz) {
            s[p] += v;
            p += lowbit(p);
        }
    }
    void del(const int& p, const T& v = 1) { add(p, -v); }
    T ask(int p) const {
        T res = 0;
        while (p) {
            res += s[p];
            p -= lowbit(p);
        }
        return res;
    }
};

struct LowerId {
    static const std::size_t maxSize = 26;
    bool operator()(const char& c) const
    { return islower(c) ? c - 'a' : 0; }
};
struct UpperId {
    static const std::size_t maxSize = 26;
    bool operator()(const char& c) const
    { return isupper(c) ? c - 'A' : 0; }
};
struct AlphaId {
    static const std::size_t maxSize = 26;
    bool operator()(const char& c) const
    { return isalpha(c) ? toupper(c) - 'A' + islower(c) * 26 : 0; }
};

template<std::size_t siz, typename idObject = LowerId>
struct Trie {
    idObject idGetter;
    std::size_t tr[idObject::maxSize][siz];
    std::size_t tot;
    Trie() {
        tot = 0;
        for (std::size_t i = 0; i < idObject::maxSize; ++i)
            for (std::size_t j = 0; j < siz; ++j)
                tr[i][j] = 0;
    }
    void add(const char* s) {
        std::size_t u = 0;
        while (*s) {
            std::size_t id = idGetter(*s);
            if (tr[id][u] == 0)
                tr[id][u] = ++tot;
            u = tr[id][u];
            ++s;
        }
    }
};

}

#pragma region Graph
namespace GRAPH
{


struct Edge { 
    Edge(const int& to_ = 0, const int& ne_ = 0) : to(to_), ne(ne_) {}
    Edge(const Edge& e) : to(e.to), ne(e.ne) {}
    int to, ne; 
};
template<typename T = int>
struct WEdge : public Edge { 
    WEdge(const int& to_ = 0, const int& ne_ = 0, const T& vl_ = 0) : Edge(to_, ne_), vl(vl_) {}
    WEdge(const Edge& e, const T& vl_ = 0) : Edge(e), vl(vl_) {}
    WEdge(const WEdge& e) : Edge(e.to, e.ne), vl(e.vl) {}
    T vl;
};



template<typename GraphType, typename EdgeType>
struct GraphRange;

template<std::size_t maxn, std::size_t maxm>
struct Graph {
    using GraphType = Graph<maxn, maxm>;
    using EdgeType = Edge;
    using RangeType = GraphRange<GraphType, EdgeType>;
    std::array<int, maxn> hd; int tot; std::array<EdgeType, maxm> e;
    Graph() {
        tot = 0;
        for (std::size_t i = 0; i < maxn; ++i) hd[i] = 0;
    }
    int getTot() const { return tot; }
    int getHead(const int& start) const { return hd[start]; }
    int getNext(const int& id) const { return e[id].ne; }
    EdgeType getEdge(const int& id) const { return e[id]; }
    virtual void add(const int& u, const int& v)
    { e[++tot] = EdgeType(v, hd[u]), hd[u] = tot; }
    RangeType operator()(const int&);
};

template<typename GraphType, typename EdgeType>
struct EdgeIterator {
    GraphType* g; int start, edgeId;
    EdgeIterator(GraphType* g_ = nullptr, const int& start_ = 0) : 
        g(g_), start(start_) { edgeId = g->getHead(start); }
    bool operator!=(const EdgeIterator& rhs) const { return edgeId != rhs.edgeId; }
    EdgeType operator*() const { return g->getEdge(edgeId); }
    const EdgeIterator& operator++() { 
        edgeId = g->getNext(edgeId); return *this;
    }
};

template<typename GraphType, typename EdgeType>
struct GraphRange {
    using IteratorType = EdgeIterator<GraphType, EdgeType>;
    GraphType* g; int start;
    GraphRange(GraphType* g_ = nullptr, const int& start_ = 0) : 
        g(g_), start(start_) {}
    IteratorType begin() const { return IteratorType(g, start); }
    IteratorType end() const { return IteratorType(g, 0); }
};

template<std::size_t maxn, std::size_t maxm>
GraphRange<Graph<maxn, maxm>, typename Graph<maxn, maxm>::EdgeType> Graph<maxn, maxm>::operator()(const int& start)
{ return GraphRange<GraphType, EdgeType>(this, start); }



template<std::size_t maxn, std::size_t maxm, typename T = int>
struct WGraph {
    using GraphType = WGraph<maxn, maxm, T>;
    using EdgeType = WEdge<T>;
    using RangeType = GraphRange<GraphType, EdgeType>;
    Graph<maxn, maxm> g_impl;
    std::array<T, maxm> vl;
    WGraph() {
        for (std::size_t i = 0; i < maxm; ++i) vl[i] = 0;
    }
    int getTot() const { return g_impl.getTot(); }
    int getHead(const int& start) const { return g_impl.getHead(start); }
    int getNext(const int& id) const { return g_impl.getNext(id); }
    EdgeType getEdge(const int& id) const { 
        Edge e = g_impl.getEdge(id); 
        return EdgeType(e, vl[id]);
    }
    virtual void add(const int& u, const int& v, const T& w)
    { g_impl.add(u, v); vl[g_impl.getTot()] = w; }
    RangeType operator()(const int& start)
    { return RangeType(this, start); }
};

template<int maxn, int maxm>
using DGraph = Graph<maxn, maxm>;

template<int maxn, int maxm, typename T = int>
using DWGraph = WGraph<maxn, maxm, T>;



template<int maxn, int maxm>
struct UGraph : public Graph<maxn, maxm * 2> {
    void add(const int& u, const int& v) override { 
        Graph<maxn, maxm * 2>::add(u, v);
        Graph<maxn, maxm * 2>::add(v, u);
    }
};



template<int maxn, int maxm, typename T = int>
struct UWGraph : public WGraph<maxn, maxm * 2, T> {
    void add(const int& u, const int& v, const T& w) override { 
        WGraph<maxn, maxm * 2, T>::add(u, v, w);
        WGraph<maxn, maxm * 2, T>::add(v, u, w);
    }
};
}
#pragma endregion

namespace ALGO
{
template<std::size_t maxn, typename GraphType, typename T = int>
struct Dij : GraphType {
    T inf;
    std::array<T, maxn> d; std::bitset<maxn> bs;
    Dij() : inf(std::numeric_limits<T>::max()) {}
    Dij(T inf_) : inf(inf_) {}
    void run(int s) {
        for (std::size_t i = 1; i < maxn; ++i) d[i] = inf;
        std::priority_queue<pair<T, int> > Q;
        d[s] = 0; Q.push(std::make_pair(0, s)); bs.set(s);
        while (!Q.empty()) {
            int u = Q.top().second; Q.pop(); bs.reset(u);
            for (auto e : GraphType::operator()(u)) {
                int v = e.to; T w = e.vl;
                if (d[v] > d[u] + w) {
                    d[v] = d[u] + w;
                    if (!bs[v]) {
                        Q.push(std::make_pair(-d[v], v));
                        bs.set(v);
                    }
                }
            }
        }
    }
};
}

namespace _IO
{
struct IO {
    static const unsigned R = 1e6, W = 1e6;
    char *a, *b, *i, *o, *c, *d, h[40], *p, y;
    bool s;
    FILE *in, *out;
    

    void r(char& x) {
        x = a == b && (b = (a = i) + fread(i, 1, R, in), a == b) ? EOF : *a++;
    } void f() {
        fwrite(o, 1, c - o, out); c = o;
    } IO(FILE* _in, FILE* _out) : in(_in), out(_out) {
        i = new char[R]; o = new char[W];
        c = o; d = o + W; p = h;
        b = (a = i) + fread(i, 1, R, in);
    } ~IO() {
        f();
        delete[] i; delete[] o; 
    }
    

    void w(const char& x) {
        *(c++) = x;
        if (c == o + W) f();
    } IO& operator>>(char& x) {
        do { r(x); } while (x <= 32);
        return *this;
    } IO& operator>>(char* x) {
        do { r(*x); } while(*x <= 32); 
        while (*x > 32) r(*++x);
        *x = 0; return *this;
    } template<typename _Tp> IO& operator>>(_Tp& x) {
        for (r(y), s = 0; !isdigit(y); r(y)) s |= y == '-';
        if (s) for (x = 0; isdigit(y); r(y)) x = x * 10 - (y ^ 48);
        else for (x = 0; isdigit(y); r(y)) x = x * 10 + (y ^ 48); 
        return *this;
    } template<typename _Tp> IO& operator>>(std::vector<_Tp>& v) {
        typename std::vector<_Tp>::iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter) (*this) >> (*iter);
        return *this;
    } template<typename _Tp> IO& operator>>(Array<_Tp> arr) {
        for (auto p = arr.begin(); p != arr.end(); ++p) (*this) >> (*p);
        return *this;
    }
    

    IO& operator<<(char x) {
        w(x); return *this;
    } IO& operator<<(char *x) {
        while (*x) w(*x++);
        return *this;
    }  IO& operator<<(const char *x) {
        while (*x) w(*x++);
        return *this;
    } template<typename _Tp> IO& operator<<(const _Tp& x) {
        _Tp tx = x;
        if(!tx) (*this) << '0';
        else {
            if (tx < 0) w('-'), tx = -tx;
            for(; tx; tx /= 10) *p++ = '0' | tx % 10;
        }
        while (p != h) w(*--p);
        return *this;
    } template<typename _Tp> IO& operator<(const _Tp& x) {
        (*this) << x << '\n';
        return *this;
    } template<typename _Tp> IO& operator<=(const _Tp& x) {
        (*this) << x << ' ';
        return *this;
    } template<typename _Tp> IO& operator<(const std::vector<_Tp>& v) {
        typename std::vector<_Tp>::const_iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter) (*this) < (*iter);
        return *this;
    } template<typename _Tp> IO& operator<(Array<_Tp> arr) {
        for (auto p = arr.begin(); p != arr.end(); ++p) (*this) < (*p);
        return *this;
    } template<typename _Tp> IO& operator<=(const std::vector<_Tp>& v) {
        typename std::vector<_Tp>::const_iterator iter;
        for (iter = v.begin(); iter != v.end(); ++iter) (*this) <= (*iter);
        return *this;
    } template<typename _Tp> IO& operator<=(Array<_Tp> arr) {
        for (auto p = arr.begin(); p != arr.end(); ++p) (*this) <= (*p);
        return *this;
    }
};
#define fo(f) IO io(fopen(#f".in", "r"), fopen(#f".out", "w"))
}

using namespace Compares;
using namespace DS;
using namespace GRAPH;
using namespace ALGO;

using namespace _IO;




















}
#pragma endregion
using namespace Utils;

IO io(stdin, stdout);



const int maxn = 1e5 + 5;
const int maxsqn = 6e2 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;

int n;
int a[maxn];
ll s[maxn];
ll f[maxn][maxsqn];

void solve() {
    int k = 1;
    io >> n;
    io >> Array<int>(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i)
        s[i] = s[i - 1] + a[i];
    std::fill(f[n], f[n] + maxsqn, 0);
    f[n][1] = a[n];
    for (int i = n - 1; i; --i) {
        std::fill(f[i], f[i] + maxsqn, 0);
        f[i][1] = std::max(f[i + 1][1], (ll)a[i]);
        for (int j = 2; j * (j + 1) / 2 <= n - i + 1; ++j) {
            f[i][j] = f[i + 1][j];
            if (i == n || s[i + j - 1] - s[i - 1] < f[i + j][j - 1]) {
                umax(k, j);
                umax(f[i][j], s[i + j - 1] - s[i - 1]);
            }
            

        }
        

    }
    io < k;
}


int main()
{
	int T;
    io >> T;
    while (T--) solve();
	return 0;
}
