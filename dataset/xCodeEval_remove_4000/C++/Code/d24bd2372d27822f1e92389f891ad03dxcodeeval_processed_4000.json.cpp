








namespace XX
{

    template<typename T, typename I, template<typename> class NodeManager, bool Persistent, typename... Infos>
    class SegmentTree
    {
        public:
            template<typename U = T, void(U::*P)(I, I, T&) = &U::lazy>
            static constexpr bool id1(void(T::*p)(I, I, T&) = P){return true;}
            static constexpr bool id1(...){return false;}
            static const constexpr bool id8 = id1(0);
            struct LazyNodeData:public T
            {
                bool hasLazy = false;
            };
            using NodeData = typename std::conditional<id8, LazyNodeData, T>::type;

            using PT = typename NodeManager<NodeData>::ParameterType;
            using Index = typename NodeManager<NodeData>::Index;
            T& operator[](Index idx) { return _nm[idx]; }
            Index left(Index idx){return _nm.left(idx);}
            Index right(Index idx){return _nm.right(idx);}

            

            



            Index root(){return _nm.root();}
            SegmentTree(I beg, I end, Infos&... infos)
                :_nm(beg, end), _beg(beg), _end(end), _info(infos...)
            {}



            template<typename Modifier>
            Index update(I l, I r, const Modifier& mod) { return update(_nm.root(), l, r, mod); }
            template<typename Modifier>
            Index update(Index root, I l, I r, const Modifier& mod)
            {
                if(l >= r || r <= _beg || l >= _end)
                    return root;
                _update(root, _beg, _end, l, r, mod);
                return root;
            }

            T query(I l, I r){return query(_nm.root(), l, r);}
            T query(Index root, I l, I r)
            {
                if(l >= r || r <= _beg || l >= _end)
                    return T();
                return _query(root, _beg, _end, l, r);
            }

            template<typename Modifier>
            void queryEach(I l, I r, const Modifier& mod){queryEach(_nm.root(), l, r, mod);}
            template<typename Modifier>
            void queryEach(Index root, I l, I r, const Modifier& mod)
            {
                if(l >= r || r <= _beg || l >= _end)
                    return;
                _queryEach(root, _beg, _end, l, r, mod);
            }
            template<typename Modifier>
            Index updateEach(I l, I r, const Modifier& mod){return updateEach(_nm.root(), l, r, mod);}
            template<typename Modifier>
            Index updateEach(Index root, I l, I r, const Modifier& mod)
            {
                if(l >= r || r <= _beg || l >= _end)
                    return root;
                _updateEach(root, _beg, _end, l, r, mod);
                return root;
            }
            template<typename Visitor>
            void travelEach(I l, I r, const Visitor& mod){travelEach(_nm.root(), l, r, mod);}
            template<typename Visitor>
            void travelEach(Index root, I l, I r, const Visitor& mod)
            {
                if(l >= r || r <= _beg || l >= _end)
                    return;
                id2(root, _beg, _end, l, r, mod);
            }

            template<typename Modifier>
            void build(const Modifier& mod)
            {
                _build(_nm.root(), _beg, _end, mod);
            }
            template<typename Modifier>
            void buildEach(const Modifier& mod)
            {
                _buildEach(_nm.root(), _beg, _end, mod);
            }

        private:

            template<bool P = Persistent> typename std::enable_if<P, void>::type write(Index& idx) { if(!idx->isNull()){auto n = _nm.newnode(); *n = *idx; idx = n;}}
            template<bool P = Persistent> typename std::enable_if<!P, void>::type write(Index idx) {}

            template<bool L = id8>
            typename std::enable_if<L, void>::type _checkLazy(Index idx, I sl, I sr)
            {
                if(_nm[idx].hasLazy)
                {
                    write(_nm.left(idx));
                    write(_nm.right(idx));
                    auto& l = _nm[_nm.left(idx)];
                    auto& r = _nm[_nm.right(idx)];
                    I m = (sl + sr) >> 1;
                    l.lazy(sl, m, _nm[idx]);
                    r.lazy(m, sr, _nm[idx]);
                    _nm[idx].clear();
                    _nm[idx].hasLazy = false;
                    l.hasLazy = r.hasLazy = true;
                }
            }
            template<bool L = id8>
            typename std::enable_if<!L, void>::type _checkLazy(Index idx, I sl, I sr, ...)
            {}

            template<bool LAZY = id8>
            typename std::enable_if<LAZY, void>::type write_lazy(NodeData& data) { data.hasLazy = true; }
            template<bool LAZY = id8>
            typename std::enable_if<!LAZY, void>::type write_lazy(NodeData&, ...){ } 

            template<int... Index>
            struct Seq{};
            template<int R, int... S>
            struct GenSeq{using Type = typename GenSeq<R - 1, R - 1, S...>::Type;};
            template<int ... S> 
            struct GenSeq<0, S...>{using Type = Seq<S...>;};

            template<int... Index>
            void _update(I l, I m, I r, T& node, T& lc, T& rc, Seq<Index...>)
            {
                node(l, m, r, lc, rc, std::get<Index>(_info)...);
            }
            void _update(I l, I m, I r, T& node, T& lc, T& rc)
            {
                _update(l, m, r, node, lc, rc, typename GenSeq<sizeof...(Infos)>::Type());
            }
            template<typename Modifier>
            void _buildEach(Index idx, I sl, I sr, const Modifier& mod)
            {
                if(sr - sl == 1)
                    mod(sl, sr, _nm[idx]);
                else
                {
                    I m = (sl + sr) >> 1;
                    _buildEach(_nm.left(idx), sl, m, mod);
                    _buildEach(_nm.right(idx), m, sr, mod);
                    mod(sl, sr, _nm[idx]);
                }
            }
            template<typename Modifier>
            void _build(Index idx, I sl, I sr, const Modifier& mod)
            {
                if(sr - sl == 1)
                    mod(sl, sr, _nm[idx]);
                else
                {
                    I m = (sl + sr) >> 1;
                    _build(_nm.left(idx), sl, m, mod);
                    _build(_nm.right(idx), m, sr, mod);
                    _update(sl, m, sr, _nm[idx], _nm[_nm.left(idx)], _nm[_nm.right(idx)]);
                }
            }
            template<typename Visitor>
            void id2(Index idx, I sl, I sr, I l, I r, const Visitor& mod)
            {
                if(l <= sl && sr <= r)
                    mod(sl, sr, idx);
                else
                {
                    _checkLazy(idx, sl, sr);
                    I m = (sl + sr) >> 1;
                    if(l < m)
                        id2(_nm.left(idx), sl, m, l, r, mod);
                    if(r > m)
                        id2(_nm.right(idx), m, sr, l, r, mod);
                }
            }
            template<typename Modifier>
            void _queryEach(Index idx, I sl, I sr, I l, I r, const Modifier& mod)
            {
                if(l <= sl && sr <= r)
                    mod(sl, sr, _nm[idx]);
                else
                {
                    _checkLazy(idx, sl, sr);
                    I m = (sl + sr) >> 1;
                    if(l < m && _nm.hasLeft(idx))
                        _queryEach(_nm.left(idx), sl, m, l, r, mod);
                    if(r > m && _nm.hasRight(idx))
                        _queryEach(_nm.right(idx), m, sr, l, r, mod);
                }
            }

            T _query(Index idx, I sl, I sr, I l, I r)
            {
                if(l <= sl && sr <= r)
                    return _nm[idx];
                else
                {
                    _checkLazy(idx, sl, sr);
                    I m = (sl + sr) >> 1;
                    if(l >= m && _nm.hasRight(idx))
                        return _query(_nm.right(idx), m, sr, l, r);
                    else if(r <= m && _nm.hasLeft(idx))
                        return _query(_nm.left(idx), sl, m, l, r);
                    else
                    {
                        T ret;
                        T lt = _nm.hasLeft(idx)? _query(_nm.left(idx), sl, m, l, m): T();
                        T rt = _nm.hasRight(idx)? _query(_nm.right(idx), m, sr, m, r): T();
                        _update(l, m, r, ret, lt, rt);
                        return ret;
                    }
                }
            }

            template<typename Modifier>
            void _updateEach(PT idx, I sl, I sr, I l, I r, const Modifier& mod)
            {
                write(idx);
                if(l <= sl && sr <= r)
                {
                    mod(sl, sr, _nm[idx]);
                    if(sr - sl > 1)
                        write_lazy(_nm[idx]);
                }
                else
                {
                    _checkLazy(idx, sl, sr);
                    I m = (sl + sr) >> 1;
                    if(l < m)
                        _updateEach(_nm.left(idx), sl, m, l, r, mod);
                    if(r > m)
                        _updateEach(_nm.right(idx), m, sr, l, r, mod);

                    mod(sl, sl, _nm[idx]);
                }
            }

            template<typename Modifier>
            void _update(PT idx, I sl, I sr, I l, I r, const Modifier& mod)
            {
                write(idx);
                if(l <= sl && sr <= r)
                {
                    mod(sl, sr, _nm[idx]);
                    if(sr - sl > 1)
                        write_lazy(_nm[idx]);
                }
                else
                {
                    _checkLazy(idx, sl, sr);
                    I m = (sl + sr) >> 1;
                    if(l < m)
                        _update(_nm.left(idx), sl, m, l, r, mod);
                    if(r > m)
                        _update(_nm.right(idx), m, sr, l, r, mod);

                    _update(sl, m, sr, _nm[idx], _nm[_nm.left(idx)], _nm[_nm.right(idx)]);
                }
            }

            std::tuple<Infos&...> _info;
            NodeManager<NodeData> _nm;
            I _beg, _end;
    };
}





namespace XX
{
    template<typename T>
    class id3
    {
        public:
            typedef int Index;
            typedef Index ParameterType;
        private:

            std::vector<T> _nodes;
        public:
            id3(int beg, int end)
                :_nodes((end - beg) * 4)
            {}

            int root(){return 1;}
            int left(int idx){return idx << 1;}
            int right(int idx){return (idx << 1) + 1;}
            static constexpr bool hasLeft(int idx){return true;}
            static constexpr bool hasRight(int idx){return true;}
            T& operator[](int idx) {return _nodes[idx];}
    };
}





namespace XX
{
    template<typename T, typename I = int, typename... Infos>
    using StaticSegmentTree = XX::SegmentTree<T, I, XX::id3, false, Infos...>;
}



template<typename T> struct ScanfSpecifier{};

DEF(char*,"%s")DEF(int,"%d")DEF(double,"%lf")DEF(float,"%f")DEF(char,"%c")DEF(const char*,"%s")DEF(unsigned long,"%lu")DEF(unsigned int, "%u")

DEF(long long int,"%I64d")

DEF(long long int,"%lld")


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
template<typename It> void id4(It begin, It end) { WTV(begin, end); std::printf("\n"); }
template<typename C> void id4(const C& c) {id4(std::begin(c), std::end(c));}




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






inline int CLZ(int n){unsigned long ret; _BitScanForward(&ret, n); return ret;}


inline int CTZ(int n){unsigned long ret; _BitScanReverse( &ret, n); return 31 - ret;} 


inline int id0(int n){return __popcnt(n);}





inline int CLZ(int n){return __builtin_clz(n);}
inline int id7(long long int n){return __builtin_clzll(n);}
inline int CTZ(int n){return __builtin_ctz(n);}
inline int id5(long long int n){return __builtin_ctzll(n);}
inline int id0(int n){return __builtin_popcount(n);}
inline int id6(long long int n){return __builtin_popcountll(n);}

























using RG = Range;










using namespace std;

const int SIZE = 100009;
typedef long long int ll;
const ll INF = 1ll << 60;
struct Plan
{
    int v, u;
    int l, r;
    ll w;
};
struct Data
{
    ll mn = INF;
    vector<Plan> t3;
    int idx;
    ll cover = INF;

    void clear()
    {
    }

    void set(ll v)
    {
        UMIN(cover, v);
        if(v < mn)
            mn = v;
    }
    void lazy(int, int, Data& up)
    {
        set(up.cover);
    }
    void operator()(int, int, int, Data& lc, Data& rc)
    {
        if(rc.mn == -1 || (lc.mn != -1 && lc.mn < rc.mn))
        {
            mn = lc.mn;
            idx = lc.idx;
        }
        else
        {
            mn = rc.mn;
            idx = rc.idx;
        }
    }
};

ll ans[SIZE];
int N, Q, S;
typedef long long int ll;
vector<Plan> t2[SIZE];

int main()
{
    RD(N, Q, S);
    S--;
    XX::StaticSegmentTree<Data> sgt(0, N);

    for(int i: RG(N))
        ans[i] = -1;

    sgt.build([&](int l, int r, Data& data)
    {
        data.idx = l;
        if(l == S)
            data.mn = 0;
    });

    while(Q--)
    {
        int t;
        RD(t);

        if(t == 1)
        {
            int v, u;
            ll w;
            RD(v, u, w);

            v--, u--;

            t2[v].push_back({0, 0, u, u, w});
        }
        else 
        {
            int v, l, r;
            ll w;
            RD(v, l, r, w);
            v--, l--, r--;
            if(t == 2)
                t2[v].push_back({0, 0, l, r, w});
            else
                sgt.update(l, r + 1, [&](int, int, Data& data)
                {
                    data.t3.push_back({0, 0, v, v, w});
                });
        }

    }


    while(true)
    {
        auto res = sgt.query(0, N);

        if(res.mn == -1 || res.mn == INF)
            break;

        ans[res.idx] = res.mn;

        for(auto t: t2[res.idx])
            sgt.update(t.l, t.r + 1, [&](int, int, Data& data)
            {
                data.set(res.mn + t.w);
            });

        sgt.updateEach(res.idx, res.idx + 1, [&](int, int, Data& data)
        {
            for(auto t: data.t3)
                sgt.update(t.l, t.r + 1, [&](int, int, Data& data)
                {
                    data.set(res.mn + t.w);
                });
            data.t3.clear();
            
        });

        sgt.update(res.idx, res.idx + 1, [&](int, int, Data& data)
                {
                    data.mn = -1;
                });
    }
    

    id4(ans, ans + N);


}




