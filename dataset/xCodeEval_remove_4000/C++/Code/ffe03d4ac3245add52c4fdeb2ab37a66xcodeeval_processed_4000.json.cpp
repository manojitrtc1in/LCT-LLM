









namespace XX
{
    template<typename T>
    using Modifier = std::function<void(int,int,T&)>;

    template<typename T, template<typename> class NodeManager, typename... Infos>
    class SegmentTree
    {
        public:
            struct NodeData:public T
            {
                bool hasLazy = false;
            };
            using Index = typename NodeManager<NodeData>::Index;
            T& operator[](Index idx) { return _nm[idx]; }
            Index left(Index idx){return _nm.left(idx);}
            Index right(Index idx){return _nm.right(idx);}

            SegmentTree(int beg, int end, Infos&... infos)
                :_nm(beg, end), _beg(beg), _end(end), _info(infos...)
            {}

            void update(int l, int r, const Modifier<T>& mod)
            {
                if(l >= r)
                    return;
                _update(_nm.root(), _beg, _end, l, r, mod);
            }

            T query(int l, int r)
            {
                if(l >= r)
                    return T();
                return _query(_nm.root(), _beg, _end, l, r);
            }

        private:

            void _checkLazy(Index idx, int sl, int sr)
            {
                if(_nm[idx].hasLazy)
                {
                    auto& l = _nm[_nm.left(idx)];
                    auto& r = _nm[_nm.right(idx)];
                    int m = (sl + sr) >> 1;
                    l.lazy(sl, m, _nm[idx]);
                    r.lazy(m, sr, _nm[idx]);
                    _nm[idx].clear();
                    _nm[idx].hasLazy = false;
                    l.hasLazy = r.hasLazy = true;
                }
            }

            template<int... Index>
            struct Seq{};
            template<int R, int... S>
            struct GenSeq{using Type = typename GenSeq<R - 1, R - 1, S...>::Type;};
            template<int ... S> 
            struct GenSeq<0, S...>{using Type = Seq<S...>;};

            template<int... Index>
            void _update(int l, int m, int r, T& node, T& lc, T& rc, Seq<Index...>)
            {
                node(l, m, r, lc, rc, std::get<Index>(_info)...);
            }
            void _update(int l, int m, int r, T& node, T& lc, T& rc)
            {
                _update(l, m, r, node, lc, rc, typename GenSeq<sizeof...(Infos)>::Type());
            }

            T _query(Index idx, int sl, int sr, int l, int r)
            {
                if(l <= sl && sr <= r)
                    return _nm[idx];
                else
                {
                    _checkLazy(idx, sl, sr);
                    int m = (sl + sr) >> 1;
                    if(l >= m)
                        return _query(_nm.right(idx), m, sr, l, r);
                    else if(r <= m)
                        return _query(_nm.left(idx), sl, m, l, r);
                    else
                    {
                        T ret;
                        T lt = _query(_nm.left(idx), sl, m, l, m);
                        T rt = _query(_nm.right(idx), m, sr, m, r);
                        _update(l, m, r, ret, lt, rt);
                        return ret;
                    }
                }
            }


            void _update(Index idx, int sl, int sr, int l, int r, const Modifier<T>& mod)
            {
                if(l <= sl && sr <= r)
                {
                    mod(sl, sr, _nm[idx]);
                    if(sr - sl > 1)
                      _nm[idx].hasLazy = true;
                }
                else
                {
                    _checkLazy(idx, sl, sr);
                    int m = (sl + sr) >> 1;
                    if(l < m)
                        _update(_nm.left(idx), sl, m, l, r, mod);
                    if(r > m)
                        _update(_nm.right(idx), m, sr, l, r, mod);

                    _update(sl, m, sr, _nm[idx], _nm[_nm.left(idx)], _nm[_nm.right(idx)]);
                }
            }

            std::tuple<Infos&...> _info;
            NodeManager<NodeData> _nm;
            int _beg, _end;
    };
}





namespace XX
{
    template<typename T>
    class id0
    {
        public:
            typedef int Index;
        private:

            std::vector<T> _nodes;
        public:
            id0(int beg, int end)
                :_nodes((end - beg) * 4)
            {}

            int root(){return 1;}
            int left(int idx){return idx << 1;}
            int right(int idx){return (idx << 1) + 1;}
            T& operator[](int idx) {return _nodes[idx];}
    };
}



namespace XX
{
    template<typename T, typename... Infos>
    SegmentTree<T, id0, Infos...> SGT(int beg, int end, Infos&... infos)
    {
        return SegmentTree<T, id0, Infos...>(beg, end, infos...);
    }
}



template<typename T> struct ScanfSpecifier{};

DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(char*,"%s")DEF(unsigned int, "%u")

DEF(long long int,"%I64d")

DEF(long long int,"%lld")


template<typename T> int RD(T& arg){return std::scanf(ScanfSpecifier<T>::value, &arg);}
template<int S> int RD(char (&arg)[S]){return std::scanf("%s", arg);}
template<> int RD<char*>(char*& arg){return std::scanf("%s", arg);}
template<> int RD<char>(char& arg){return std::scanf(" %c", &arg);}
template<typename T, typename... Args> int RD(T& arg1, Args&... args) {return RD(arg1) + RD(args...);}
template<typename T> T RD(){T ret; RD(ret); return ret;}
template<typename It> void RDV(It begin, It end) { while(begin != end) RD(*begin++); }
template<typename C> void RDV(C& c) {RDV(std::begin(c), std::end(c));}
template<typename... Args> void WT(Args... args) { int alc = 0; int dummy[] = {((alc++? std::printf(" "): 0), std::printf(ScanfSpecifier<Args>::value, args), 0)...}; }
template<typename... Args> void WTL(Args... args) { WT(args...); std::printf("\n"); }
template<typename It> void WTV(It begin, It end) { int alc = 0; while(begin != end) (alc++? std::printf(" "): 0), WT(*begin++); }
template<typename C> void WTV(const C& c) {WTV(std::begin(c), std::end(c));}
template<typename It> void id1(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void id1(const C& c) {id1(std::begin(c), std::end(c));}


namespace XX
{   
    template<template<typename> class Compare, typename T>
    inline T& UP(T& x, const T& y){if(Compare<T>()(y, x)) x = y; return x;}
    template<typename Compare, typename T>
    inline T& UP(T& x, const T& y, Compare comp){if(comp(y, x)) x = y; return x;}

    template<typename T> inline T& GT(T& x, const T& y){return UP<std::greater>(x, y);}
    template<typename T> inline T& LS(T& x, const T& y){return UP<std::less>(x, y);}

    template<typename T>
    struct Mapper
    {
        int operator[](const T& v) { int& ret = table[v]; if(!ret) rtable[ret = table.size()] = v; return ret - 1; }
        template<typename... Args> int operator()(Args... args) { return (*this)[T(args...)]; }
        T rev(int idx){return rtable[idx + 1];}
        std::map<T, int> table;
        std::map<int, T> rtable;
    };

    template<typename T, int S>
    struct ReferenceArray
    {
        struct It {typename std::array<T*, S>::iterator it; T& operator*(){return **it;} void operator++(){it++;} bool operator!=(const It& other){return it != other.it;} };
        int size()const{return _ptr.size();}
        It begin()const{return {_ptr.begin()};}
        It end()const{return {_ptr.end()};}
        T& operator[](int idx)const{return *_ptr[idx];}
        mutable std::array<T*, S> _ptr;
    };
    template<typename T, typename... Args> 
    ReferenceArray<T, sizeof...(Args) + 1> MAKEV(T& arg1, Args&... args) {return {&arg1, &args...};}

    struct Range
    {   
        struct It {   int num, step; int operator*(){return num;} void operator++(){num += step;} bool operator!=(const It& other){return num != other.num;} };
        Range(int ee):b(0),e(ee){}
        Range(int bb, int ee):b(bb), e(ee){}
        It begin(){return {b, (b < e? 1: -1)};}
        It end(){return {e, 0};}
        int b, e;
    };

}



namespace XX
{

    template<int BLOCKSIZE>
    class MemoryManager
    {
        public:
            static constexpr const int INIT = 1024 * 1024 / BLOCKSIZE? 1024 * 1024 / BLOCKSIZE: 1;

            static MemoryManager* inst()
            {
                static MemoryManager ret;
                return &ret;
            }
            
            void* alloc()
            {
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
                        _buf[++_idx] = new char[_size <<= 1];
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
                for(int i = 1; i <= _idx; i++)
                    delete []_buf[i];
            }

        private:

            MemoryManager()
            {
                _buf[0] = _init;
            }

            char _init[INIT * BLOCKSIZE];
            int _size = INIT * BLOCKSIZE;
            int _idx = 0;
            int _pos = 0;
            char* _buf[32] = {};
            void* _ptr = nullptr;
    };

    template<typename T>
    struct BlockAllocater
    {
        void* operator new(std::size_t count)
        {
            return MemoryManager<sizeof(T)>::inst()->alloc();
        }

        void operator delete(void* ptr)
        {
            return MemoryManager<sizeof(T)>::inst()->dealloc(ptr);
        }
    };
    template<typename T>
    struct NullNode
    {
        static T nullnode;
        static T* null()
        {
            return &nullnode;
        }
        bool isNull(){return this == null();}
    };

    template<typename T>
    T NullNode<T>::nullnode;
}



namespace XX
{
    template<typename... EdgeTs>
    class Graph
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

        private:
            std::vector<Node*> _adj;
            int _numVertex;

            void _dealloc(Node* node) { if(node) { _dealloc(node->next); delete node; } }

        public:
            Graph(int v = 0) :_adj(v) {}

            int size(){return _adj.size();}
            void resize(int size){_adj.resize(size);}
            EdgeIdx add(int from, int to, EdgeTs... args) { return _adj[from] = new Node{_adj[from], from, to, args...}; }

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
                            ptr = g._adj[v];
                    }
                    bool operator!=(const It& other){return ptr != other.ptr;}
                };
                Graph& g;
                It begin()
                {
                    for(int i = 0; i < g.size(); i++)
                        if(g._adj[i])
                            return {g._adj[i], i, g};
                    return end();
                }
                It end(){return {nullptr, 0, g};}
            };
            Enumerator adj(int v) { return {_adj[v], nullptr}; }
            Enumerator adj(EdgeIdx idx) { return {idx, nullptr}; }
            AllEnumerator edges() { return {*this}; }
            Enumerator operator[](int idx){return adj(idx);}
    };
}




namespace XX
{

    template<typename... EdgeTs>
    struct id2
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
                    if(data[u].deep < data[v].deep)
                        std::swap(u, v);
                    u = data[data[u].top].up;
                }
                return data[u].pos < data[v].pos? u: v;
            }
            void applyOrder(int from, int to, const std::function<void(int,int,bool)>& func)
            {
                if(data[from].top == data[to].top)
                    func(from, to, false);
                else if(data[from].deep > data[to].deep)
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
            void apply(int from, int to, const std::function<void(int,int,bool)>& func)
            {
                if(data[from].top == data[to].top)
                {
                    if(data[from].pos < data[to].pos)
                        func(from, to, false);
                    else
                        func(to, from, false);
                }
                else if(data[from].deep > data[to].deep)
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
            id2(Graph<EdgeTs...>& g, int root)
                :data(g.size())
            {
                auto& data = this->data;
                std::function<void(int,int)> dfs1 = [&](int u, int p)
                {
                    data[u].size = 1;
                    data[u].up = p;
                    data[u].down = -1;
                    for(auto& e: g[u])
                        if(e.to != p)
                        {
                            dfs1(e.to, u);
                            data[u].size += data[e.to].size;
                            if(data[u].down == -1 || data[data[u].down].size < data[e.to].size)
                                data[u].down = e.to;
                        }
                };
                dfs1(root, -1);
                int timestamp = 0;
                std::function<void(int,int,int,int)> dfs2 = [&](int u, int p, int top, int deep)
                {
                    data[u].top = top;
                    data[u].deep = deep;
                    data[u].pos = timestamp++;

                    if(data[u].down != -1)
                        dfs2(data[u].down, u, top, deep);
                    for(auto& e: g[u])
                        if(e.to != p && e.to != data[u].down)
                            dfs2(e.to, u, e.to, deep + 1);

                    data[u].end = timestamp;
                };
                dfs2(root, -1, root, 0);
            }

    };

    template<typename... EdgeTs>
    id2<EdgeTs...> TPD(Graph<EdgeTs...>& g, int root) { return id2<EdgeTs...>(g, root); }
}









using XX::Graph;













using XX::SGT;
template<typename T> T& UMAX(T& x, T y){return XX::UP<std::greater>(x, y);}
template<typename T> T& UMIN(T& x, T y){return XX::UP<std::less>(x, y);}
using XX::UP; 

using RG = XX::Range;
using XX::MAKEV;
using XX::Mapper;
using XX::TPD;











using namespace std;

typedef long long ll;
const int SIZE = 100009;
typedef pair<ll, int> GL;
set<pair<ll, int>> gs[SIZE];
const GL INF = {1ll << 60, 0};

int main()
{
    int N, M, Q;
    RD(N, M, Q);

    Graph<> tree(N);

    for(int i: RG(N - 1))
    {
        int u, v;
        RD(u, v);
        u--, v--;

        tree.add(u, v);
        tree.add(v, u);
    }

    for(int i: RG(M))
    {
        int u;
        RD(u);
        gs[u - 1].emplace(i + 1, i + 1);
    }


    struct Data
    {
        GL mn = INF;
        ll add = 0;
        ll lz = 0;
        void clear(){lz = 0;}
        void lazy(int sl, int sr, Data& up){add += up.lz; lz += up.lz; if(mn != INF) mn.first += up.lz;}
        void operator()(int l, int m, int r, Data& lc, Data& rc)
        {
            mn = min(lc.mn, rc.mn);
        }
    };

    auto tpd = TPD(tree, 0);
    auto sgt = SGT<Data>(0, N);

    for(int i = 0; i < N; i++)
        if(gs[i].size())
            sgt.update(tpd[i].pos, tpd[i].pos + 1, [&](int,int, Data& data){data.mn = {gs[i].begin()->first, i};});

    while(Q--)
    {
        int t;
        RD(t);
        if(t != 1)
        {
            int v, k;
            RD(v, k);
            v--;

            sgt.update(tpd[v].pos, tpd[v].end, [&](int,int, Data& data){data.lz += k, data.add += k; if(data.mn != INF)data.mn.first += k;});
        }
        else
        {
            int v, u, k;
            RD(v, u, k);
            v--, u--;

            vector<ll> ans;

            while(k--)
            {
                GL mn = INF;

                tpd.apply(v, u, [&](int a, int b, bool)
                        {
                            UMIN(mn, sgt.query(tpd[a].pos, tpd[b].pos + 1).mn);
                        });
                if(mn == INF)
                    break;

                ans.push_back(gs[mn.second].begin()->second);

                gs[mn.second].erase(gs[mn.second].begin());

                sgt.update(tpd[mn.second].pos, tpd[mn.second].pos + 1, [&](int,int, Data& data)
                        {
                            if(!gs[mn.second].size())
                                data.mn = INF;
                            else
                                data.mn = {gs[mn.second].begin()->first + data.add, mn.second};
                        });
            }
            WT(ans.size(), "");
            id1(ans);
        }
    }



}



