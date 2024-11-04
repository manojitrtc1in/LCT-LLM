#include <map>
#include <vector>
#include <utility>
#include <array>
#include <cstdio>
#include <functional>
#include <stack>
#include <new>
#include <iterator>
namespace XX
{
    int mmReset = 0;
    
    void resetMemory(){++mmReset;}


    template<int BLOCKSIZE, int INITBUF = 1 << 24>
    class MemoryManager
    {
        public:
            static constexpr const int INIT = INITBUF / BLOCKSIZE;

            static MemoryManager* inst()
            {
                static MemoryManager ret;
                return &ret;
            }
            
            void reset()
            {
                if(mmReset != _cnt)
                {
                    _cnt = mmReset;
                    _ptr = nullptr;
                    _size = INIT * BLOCKSIZE;
                    _pos = _idx = 0;
                }
            }
            void* alloc()
            {
                reset();


                void* ret;
                if(_ptr)
                {
                    ret = _ptr;
                    _ptr = *static_cast<void**>(_ptr);
                }
                else 
                {
                    if(_pos == _size) 
                    {
                        _pos = 0;
                        ++_idx;
                        _size <<= 1;
                        if(!_buf[_idx])
                            _buf[_idx] = new char[std::max(_size, 1)];
                    }

                    ret = _buf[_idx] + _pos;
                    _pos += BLOCKSIZE;
                }

                return ret;
            }

            void dealloc(void* p)
            {
                *static_cast<void**>(p) = _ptr;
                _ptr = p;
            }

            ~MemoryManager()
            {




            }

        private:

            MemoryManager() { _buf[0] = _init; }

            char _init[INIT * BLOCKSIZE];
            int _size = INIT * BLOCKSIZE;
            int _idx = 0;
            int _pos = 0;
            char* _buf[32] = {};
            void* _ptr = nullptr;
            int _cnt = 0;
    };

    template<typename T>
    struct BlockAllocater
    {
        void* operator new(std::size_t count) { return MemoryManager<sizeof(T)>::inst()->alloc(); }
        void operator delete(void* ptr) { return MemoryManager<sizeof(T)>::inst()->dealloc(ptr); }
    };
    template<typename T>
    struct NullNode
    {
        static T nullnode;
        static T* null() { return &nullnode; }
        bool isNull(){return this == null();}
    };

    template<typename T>
    T NullNode<T>::nullnode;
}




template<typename T> struct ScanfSpecifier{};
#define DEF(T,V) template<> struct ScanfSpecifier<T>{static constexpr const char* value = V;};
DEF(char*,"%s")DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(unsigned int, "%u")
#ifdef _MSC_VER
DEF(long long int,"%I64d")
#else
DEF(long long int,"%lld")
#endif
#undef DEF
template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
int RD(char* arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename T> void WT(T arg) {std::printf(ScanfSpecifier<T>::value, arg); }
template<typename T, typename U> void WT(std::pair<T, U> arg) {std::printf("("); WT(arg.first); std::printf(", "); WT(arg.second); std::printf(")");}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), WT(args), 0)...}; }

template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void WTVL(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void WTVL(const C& c) {WTVL(std::begin(c), std::end(c));}

#define _M_VARGS_NUM_IMPL(_1, _2, _3, _4, _5, _6, _7, _8, _9, _10, N, ...) N
#define _M_VARGS_NUM(...) _M_VARGS_NUM_IMPL(__VA_ARGS__, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1)
#define _W1(_1) (#_1[0] == '"' || #_1[0] == '\''? WT("", _1, ""): WT('[', #_1, '=', _1, ']'))
#define _W2(_1, _2) (_W1(_1), _W1(_2))
#define _W3(_1, _2, _3) (_W1(_1), _W2(_2, _3))
#define _W4(_1, _2, _3, _4) (_W1(_1), _W3(_2, _3, _4))
#define _W5(_1, _2, _3, _4, _5) (_W1(_1), _W4(_2, _3, _4, _5))
#define _W6(_1, _2, _3, _4, _5, _6) (_W1(_1), _W5(_2, _3, _4, _5, _6))
#define _W7(_1, _2, _3, _4, _5, _6, _7) (_W1(_1), _W6(_2, _3, _4, _5, _6, _7))
#define _W8(_1, _2, _3, _4, _5, _6, _7, _8) (_W1(_1), _W7(_2, _3, _4, _5, _6, _7, _8))
#define _WW_IMPL2(num, ...) _W ## num(__VA_ARGS__)
#define _WW_IMPL(num, ...) _WW_IMPL2(num, __VA_ARGS__)
#define WW(...) (std::printf("(%03d) ", __LINE__), _WW_IMPL(_M_VARGS_NUM(__VA_ARGS__), __VA_ARGS__), WTL(""))


namespace XX
{
    template<typename... EdgeTs>
    struct Graph
    {    
        public:
            struct Edge: public EdgeTs...
            {
                int from, to;
                Edge(int f, int t, EdgeTs... args) :from(f), to(t), EdgeTs(args)...  {}
                Edge(){}
            };

            struct Node:public Edge, BlockAllocater<Node>
            {
                Node* next;
                template<typename... Args> Node(Node* nn, Args... args) :next(nn),Edge(args...) {}
            };

            typedef Node* EdgeIdx;

            std::vector<Node*> adjlist;
            int numVertex;

            void _dealloc(Node* node) { if(node) { _dealloc(node->next); delete node; } }

            Graph(int v = 0) :adjlist(v) {}



            int size(){return adjlist.size();}
            void resize(int size){adjlist.resize(size);}
            EdgeIdx add(int from, int to, EdgeTs... args) { return adjlist[from] = new Node{adjlist[from], from, to, args...}; }

            Node& operator[](EdgeIdx idx){return idx->e;}
            struct Enumerator
            {
                struct It
                {
                    Node* ptr;
                    Node& operator*(){return *ptr;}
                    void operator++(){ptr = ptr->next;}
                    bool operator!=(const It& other){return ptr != other.ptr;}
                }b, e;
                It begin(){return b;}
                It end(){return e;}
            };
            struct AllEnumerator
            {
                struct It
                {
                    Node* ptr;
                    int v;
                    Graph& g;
                    Node& operator*(){return *ptr;}
                    void operator++()
                    {
                        ptr = ptr->next; 
                        while(!ptr && ++v < g.size())
                            ptr = g.adjlist[v];
                    }
                    bool operator!=(const It& other){return ptr != other.ptr;}
                };
                Graph& g;
                It begin()
                {
                    for(int i = 0; i < g.size(); i++)
                        if(g.adjlist[i])
                            return {g.adjlist[i], i, g};
                    return end();
                }
                It end(){return {nullptr, 0, g};}
            };
            Enumerator adj(int v) { return {adjlist[v], nullptr}; }
            Enumerator adj(EdgeIdx idx) { return {idx, nullptr}; }
            AllEnumerator edges() { return {*this}; }
            Enumerator operator[](int idx){return adj(idx);}
    };
}





struct Range
{   
    struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
    Range(int ee):b(0),e(ee){}
    Range(int bb, int ee):b(bb), e(ee){}
    It begin(){return {b, (b < e? 1: -1)};}
    It end(){return {e, 0};}
    int b, e;
};

template<typename T> inline T& UMAX(T& x, T y){if(x < y)x = y; return x;}
template<typename T> inline T& UMIN(T& x, T y){if(y < x)x = y; return x;}
template<typename T, typename... Args> struct ArithmiticPromotion { typedef decltype(T() + typename ArithmiticPromotion<Args...>::type()) type; };
template<typename T, typename U> struct ArithmiticPromotion<T, U> { typedef decltype(T() + U()) type; };
template<typename T> struct ArithmiticPromotion<T, T> { typedef T type; };
template<typename T> struct ArithmiticPromotion<T> { typedef T type; };
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MAX(T a, U b) { return a < b? b: a; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MAX(T a, Args... args) { return MAX(a, MAX(args...)); }
template<typename T, typename U> typename ArithmiticPromotion<T, U>::type MIN(T a, U b) { return a < b? a: b; }
template<typename T, typename... Args> typename ArithmiticPromotion<T, Args...>::type MIN(T a, Args... args) { return MIN(a, MIN(args...)); }




namespace XX
{

    template<typename... EdgeTs>
    struct TreePathDecomposition
    {
            struct Data
            {
                int up;
                int down;
                int top;
                int bot;
                int pos;
                int deep;
                int size;
                int end;
            };
            std::vector<Data> data;


            int operator()(int a, int b) { return std::max(data[a].pos, data[b].pos); }
            int operator[](typename Graph<EdgeTs...>::Edge& e) { return std::max(data[e.from].pos, data[e.to].pos); }
            Data& operator[](int idx) { return data[idx]; }

            int lca(int u, int v)
            {
                while(data[u].top != data[v].top)
                {
                    if(data[u].pos < data[v].pos)
                        std::swap(u, v);
                    u = data[data[u].top].up;
                }
                return data[u].pos < data[v].pos? u: v;
            }

            template<typename F>
            void applyOrder(int from, int to, const F& func)
            {
                if(data[from].top == data[to].top)
                    func(from, to, false);
                else if(data[from].pos > data[to].pos)
                {
                    func(from, data[from].top, true);
                    applyOrder(data[data[from].top].up, to, func);
                }
                else
                {
                    applyOrder(from, data[data[to].top].up, func);
                    func(data[to].top, to, true);
                }
            }

            template<typename F>
            void apply(int from, int to, const F& func)
            {
                if(data[from].top == data[to].top)
                {
                    if(data[from].pos < data[to].pos)
                        func(from, to, false);
                    else
                        func(to, from, false);
                }
                else if(data[from].pos > data[to].pos)
                {
                    func(data[from].top, from, true);
                    apply(data[data[from].top].up, to, func);
                }
                else
                {
                    apply(from, data[data[to].top].up, func);
                    func(data[to].top, to, true);
                }
            }

            void dfs1(Graph<EdgeTs...>& g, int u, int p)
            {
                data[u].size = 1;
                data[u].up = p;
                data[u].down = -1;
                for(auto& e: g[u])
                    if(e.to != p)
                    {
                        dfs1(g, e.to, u);
                        data[u].size += data[e.to].size;
                        if(data[u].down == -1 || data[data[u].down].size < data[e.to].size)
                            data[u].down = e.to;
                    }
            };
                void dfs2(Graph<EdgeTs...>& g, int u, int p, int top, int deep, int& timestamp)
                {
                    data[u].top = top;
                    data[u].deep = deep;
                    data[u].pos = timestamp++;

                    if(data[u].down == -1)
                        data[u].bot = u;
                    else
                    {
                        dfs2(g, data[u].down, u, top, deep + 1, timestamp);
                        data[u].bot = data[data[u].down].bot;
                    }

                    for(auto& e: g[u])
                        if(e.to != p && e.to != data[u].down)
                            dfs2(g, e.to, u, e.to, deep + 1, timestamp);

                    data[u].end = timestamp;
                };
            void decompose(Graph<EdgeTs...>& g, int root, int& timestamp)
            {
                dfs1(g, root, -1);
                dfs2(g, root, -1, root, 0, timestamp);
            }

            TreePathDecomposition(Graph<EdgeTs...>& g, int root)
                :data(g.size())
            {
                int timestamp = 0;
                decompose(g, root, timestamp);
            }
            TreePathDecomposition(Graph<EdgeTs...>& g)
                :data(g.size())
            {
                int timestamp = 0;
                int N = g.size();
                for(int i = 0; i < N; i++)
                    if(!data[i].size)
                        decompose(g, i, timestamp);
            }

    };

    template<typename... EdgeTs>
    TreePathDecomposition<EdgeTs...> TPD(Graph<EdgeTs...>& g, int root) { return TreePathDecomposition<EdgeTs...>(g, root); }
    template<typename... EdgeTs>
    TreePathDecomposition<EdgeTs...> TPD(Graph<EdgeTs...>& g) { return TreePathDecomposition<EdgeTs...>(g); }
}









using XX::Graph;
using RG = Range;
using XX::TPD;




#include <vector>
#include <string>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <functional>
using namespace std;

typedef long long int ll;

struct Edge
{
    int type;
};


const int SIZE = 100009;
bool pass[SIZE];

int jump[SIZE][2];
Graph<Edge> tree;

void dfs(int u, int p, int t)
{
    pass[u] = true;
    jump[u][1 - t] = u;
    if(p == -1)
        jump[u][t] = u;
    else
        jump[u][t] = jump[p][t];
    for(auto e: tree[u])
        if(!pass[e.to])
            dfs(e.to, u, e.type);

}

int main()
{
    int N;
    RD(N);

    tree.resize(N);

    for(int i: RG(N))
    {
        int p, t;
        RD(p, t);

        if(p != -1)
        {
            tree.add(i, p - 1, {t});
            tree.add(p - 1, i, {t});
        }
    }

    auto tpd = TPD(tree);

    for(int i: RG(N))
        if(!pass[i])
            dfs(i, -1, 0);

    auto getroot = [&](int u)
    {
        u = tpd[u].top;
        while(tpd[u].up != -1)
            u = tpd[tpd[u].up].top;
        return u;
    };


    int Q;
    RD(Q);
    while(Q--)
    {
        int t, u, v;
        RD(t, u, v);
        u--, v--;

        if(u == v)
            WTL("NO");
        else if(getroot(u) != getroot(v))
            WTL("NO");
        else if(t == 1)
        {
            if(tpd[v].deep > tpd[u].deep && tpd.lca(u, v) == u && tpd[jump[v][0]].deep <= tpd[u].deep)
                WTL("YES");
            else
                WTL("NO");
        }
        else
        {
            int lca = tpd.lca(u, v);

            if(lca != v && tpd[jump[u][0]].deep <= tpd[lca].deep && tpd[jump[v][1]].deep <= tpd[lca].deep)
                WTL("YES");
            else
                WTL("NO");


        }
    }

}




