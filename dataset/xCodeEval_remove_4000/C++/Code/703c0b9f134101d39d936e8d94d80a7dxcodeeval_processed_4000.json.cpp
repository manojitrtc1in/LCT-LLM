





using namespace std;using namespace __gnu_pbds;











template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}





seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);const size_t RANDOM=uniform_int_distribution<size_t>(0,(numeric_limits<size_t>::max)())(rng64);
template<class T,class H=hash<T>>struct rand_hash{
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
};
template<class K,class H=rand_hash<K>,class...Ts>using hashset=gp_hash_table<K,null_type,H,Ts...>;
template<class K,class V,class H=rand_hash<K>,class...Ts>using hashmap=gp_hash_table<K,V,H,Ts...>;
template<class K,class C=less<K>,class...Ts>using treeset=tree<K,null_type,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
template<class K,class V,class C=less<K>,class...Ts>using treemap=tree<K,V,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
template<class K,class H=rand_hash<K>,class...Ts>using uset=unordered_set<K,H,Ts...>;template<class K,class V,class H=rand_hash<K>,class...Ts>using umap=unordered_map<K,V,H,Ts...>;
template<class T>using minpq=std::priority_queue<T,vector<T>,greater<T>>;template<class T>using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T>using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
template<class T1,class T2,class H1=rand_hash<T1>,class H2=rand_hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id3(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id3(long){return false;}constexpr static bool value=id3<T>(0);
};


constexpr const int _bufferSize=1<<16,id1=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id2=nullptr,_numBuf[id1],_tempOutputBuf[id1],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id5=0,_cnt;ull _precisionBase=1000000;

    
    
    


    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id6(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











void setLength(int x){if(id2)delete[](id2);id2=new char[x+1];}
void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}



















void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
template<class T1,class T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>void write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(forward<Ts>(xs)...);}
template<class T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(forward<Ts>(xs)...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(id2)delete[](id2);}};unique_ptr<IOManager>id4=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

using Data = int; using Lazy = int; const Data vdef = 0, qdef = 0; const Lazy ldef = -1;
template <const int id0, const int id7, const bool id8> struct DynamicSegmentTree {
    Data merge(const Data &l, const Data &r) { return l + r; }
    Data applyLazy(const Data &x, const Lazy &v) { return v; }
    Lazy getSegmentVal(const Lazy &v, int len) { return v * len; }
    Lazy mergeLazy(const Lazy &l, const Lazy &r) { return r; }
    int N, curNode = 0, curRoot = 0, roots[id7], L[id0], R[id0]; Data VAL[id0]; Lazy LZ[id0];
    int makeNode(int cp = 0) {
        assert(curNode < id0); L[curNode] = curNode ? L[cp] : 0; R[curNode] = curNode ? R[cp] : 0;
        VAL[curNode] = curNode ? VAL[cp] : vdef; LZ[curNode] = curNode ? LZ[cp] : ldef; return curNode++;
    }
    void propagate(int cur, int cL, int cR) {
        if (LZ[cur] != ldef) {
            int m = cL + (cR - cL) / 2;
            if (!L[cur]) L[cur] = makeNode();
            VAL[L[cur]] = applyLazy(VAL[L[cur]], getSegmentVal(LZ[cur], m - cL + 1)); LZ[L[cur]] = mergeLazy(LZ[L[cur]], LZ[cur]);
            if (!R[cur]) R[cur] = makeNode();
            VAL[R[cur]] = applyLazy(VAL[R[cur]], getSegmentVal(LZ[cur], cR - m)); LZ[R[cur]] = mergeLazy(LZ[R[cur]], LZ[cur]);
            LZ[cur] = ldef;
        }
    }
    template <class It> int build(int cL, int cR, It st) {
        int ret = makeNode();
        if (cL == cR) { VAL[ret] = *(st + cL - id8); return ret; }
        int m = cL + (cR - cL) / 2; L[ret] = build(cL, m, st); R[ret] = build(m + 1, cR, st);
        VAL[ret] = merge(VAL[L[ret]], VAL[R[ret]]); return ret;
    }
    int update(int cur, int cL, int cR, int l, int r, const Lazy &val, bool persistent) {
        int ret = persistent ? makeNode(cur) : cur;
        if (cL >= l && cR <= r) {
            VAL[ret] = applyLazy(VAL[ret], getSegmentVal(val, cR - cL + 1));
            LZ[ret] = mergeLazy(LZ[ret], val); return ret;
        }
        int m = cL + (cR - cL) / 2; propagate(ret, cL, cR);
        if (cL <= r && l <= m) L[ret] = update(L[ret] ? L[ret] : makeNode(), cL, m, l, r, val, persistent);
        if (m + 1 <= r && l <= cR) R[ret] = update(R[ret] ? R[ret] : makeNode(), m + 1, cR, l, r, val, persistent);
        if (L[ret] && R[ret]) VAL[ret] = merge(VAL[L[ret]], VAL[R[ret]]);
        else if (L[ret]) VAL[ret] = merge(VAL[L[ret]], Data(vdef));
        else if (R[ret]) VAL[ret] = merge(VAL[R[ret]], Data(vdef));
        return ret;
    }
    Data query(int cur, int cL, int cR, int l, int r) {
        if (cL > r || cR < l) return qdef;
        if (!cur) return vdef;
        if (cL >= l && cR <= r) return VAL[cur];
        int m = cL + (cR - cL) / 2; propagate(cur, cL, cR); return merge(query(L[cur], cL, m, l, r), query(R[cur], m + 1, cR, l, r));
    }
    template <class It> void init(It st, It en) { N = en - st; makeNode(); roots[curRoot++] = build(id8, N - !id8, st); }
    void init(int size) { N = size; makeNode(); roots[curRoot++] = makeNode(); }
    void update(int l, int r, Lazy val, bool persistent) {
        int nr = update(roots[curRoot - 1], id8, N - !id8, l, r, val, persistent);
        if (persistent) roots[curRoot++] = nr;
        else roots[curRoot - 1] = nr;
    }
    Data query(int l, int r, int rootInd = -1) {
        return query((rootInd == -1 ? roots[curRoot - 1] : roots[rootInd]), id8, N - !id8, l, r);
    }
    void revert(int x) { roots[curRoot++] = roots[x]; }
    void clear() { curNode = curRoot = 0; }
};

int N, Q;
DynamicSegmentTree<15000005, 5, 1> TR;

int main() {
    

    

    

    read(N, Q);
    TR.init(N);
    int l, r, k;
    FOR(i, Q) {
        read(l, r, k);
        TR.update(l, r, k % 2, false);
        writeln(N - TR.query(1, N));
    }
    return 0;
}