



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

template <const int MAXN, const bool id7> struct SegmentTree_RAM_RQ {
    using Data = pll; using Lazy = pll; int N, H; Data T[2 * MAXN]; Lazy L[MAXN]; 

    const Data vdef = mp(0, 0); 

    const Data qdef = mp(0, 0); 

    const Lazy ldef = mp(0, 0); 

    

    Data merge(const Data &l, const Data &r) { return mp(l.f + r.f, l.s + r.s); }
    Lazy getSegmentVal(const Lazy &v, int k) { return v; }
    Lazy mergeLazy(const Lazy &l, const Lazy &r) { return mp(l.f + r.f, l.s + r.s); }
    Data applyLazy(const Data &l, const Lazy &r) { return mp(l.f + r.f * (l.s + r.s), l.s + r.s); }
    void apply(int i, const Lazy &v, int k) {
        T[i] = applyLazy(T[i], getSegmentVal(v, k));
        if (i < N) L[i] = mergeLazy(L[i], v);
    }
    void pushup(int i) {
        for (int k = 2; i >>= 1; k <<= 1) {
            T[i] = L[i] == ldef ? merge(T[i << 1], T[i << 1 | 1]) : applyLazy(merge(T[i << 1], T[i << 1 | 1]), getSegmentVal(L[i], k));
        }
    }
    void propagate(int i) {
        for (int h = H, k = 1 << (H - 1), ii = i >> h; h > 0; ii = i >> --h, k >>= 1) if (L[ii] != ldef) {
            apply(ii << 1, L[ii], k); apply(ii << 1 | 1, L[ii], k); L[ii] = ldef;
        }
    }
    template <class It> void init(It st, It en) {
        N = en - st; H = 0; for (int i = 1; i <= N; H++) i <<= 1;
        for (int i = 0; i < N; i++) { T[N + i] = *(st + i); L[i] = ldef; }
        for (int i = N - 1; i > 0; i--) T[i] = merge(T[i << 1], T[i << 1 | 1]);
    }
    void init(int size) {
        N = size; H = 0;
        for (int i = 1; i <= N; H++) i <<= 1;
        for (int i = 1; i < 2 * N; i++) T[i] = vdef;
        for (int i = 0; i < N; i++) L[i] = ldef;
    }
    void update(int l, int r, const Lazy &v) {
        int l0 = l += N - id7, r0 = r += N - id7, k = 1; propagate(l); propagate(r);
        for (; l <= r; l >>= 1, r >>= 1, k <<= 1) {
            if (l & 1) apply(l++, v, k);
            if (!(r & 1)) apply(r--, v, k);
        }
        pushup(l0); pushup(r0);
    }
    Data query(int l, int r) {
        propagate(l += N - id7); propagate(r += N - id7); Data ql = qdef, qr = qdef;
        for (; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ql = merge(ql, T[l++]);
            if (!(r & 1)) qr = merge(T[r--], qr);
        }
        return merge(ql, qr);
    }
};

template <const int MAXN, const int id0, class T, const bool IS_MAX> struct RMQSparseTable {
    T A[MAXN]; int ST[id0][MAXN];
    int cmpInd(int l, int r) { return (A[l] <= A[r]) ^ IS_MAX ? l : r; }
    void init(int N) {
        int lg = 32 - __builtin_clz(N); assert(lg < id0); iota(ST[0], ST[0] + N, 0);
        for (int i = 0; i < lg - 1; i++) for (int j = 0; j + (1 << i) < N; j++) ST[i + 1][j] = cmpInd(ST[i][j], ST[i][j + (1 << i)]);
    }
    

    int query(int l, int r) { int i = 31 - __builtin_clz(r - l + 1); return cmpInd(ST[i][l], ST[i][r - (1 << i) + 1]); }
};

const int MAXN = 1e6 + 5, MAXQ = 1e6 + 5;

int N, Q, L[MAXQ], R[MAXQ], LEN[MAXN];
pii QL[MAXQ], QR[MAXQ], TL[MAXN], TR[MAXN];
ll ans[MAXQ];
RMQSparseTable<MAXN, 22, int, 1> ST;
SegmentTree_RAM_RQ<MAXN, 0> SegTree;

void build(int l, int r) {
    if (l > r) return;
    int m = ST.query(l, r);
    LEN[m] = r - l + 1;
    TL[m] = mp(l, m);
    TR[m] = mp(r, m);
    build(l, m - 1);
    build(m + 1, r);
}

int main() {
    

    

    

    read(N, Q);
    read(ST.A, ST.A + N, L, L + Q, R, R + Q);
    FOR(i, Q) {
        ans[i] = 0;
        QL[i] = mp(--L[i], i);
        QR[i] = mp(--R[i], i);
    }
    sort(QL, QL + Q);
    sort(QR, QR + Q);
    ST.init(N);
    SegTree.init(N);
    build(0, N - 1);
    sort(TL, TL + N);
    sort(TR, TR + N);
    int ql = 0, tl = 0, qr = 0, tr = 0;
    FOR(i, N) {
        for (; ql < Q && QL[ql].f == i; ql++) ans[QL[ql].s] -= SegTree.query(L[QL[ql].s], R[QL[ql].s]).f;
        for (; tl < N && TL[tl].f == i; tl++) SegTree.update(TL[tl].s, TL[tl].s, mp(0, 1));
        SegTree.update(0, N - 1, mp(1, 0));
        for (; qr < Q && QR[qr].f == i; qr++) ans[QR[qr].s] += SegTree.query(L[QR[qr].s], R[QR[qr].s]).f;
        for (; tr < N && TR[tr].f == i; tr++) SegTree.update(TR[tr].s, TR[tr].s, mp(-LEN[TR[tr].s], -1));
    }
    writeln(ans, ans + Q);
    return 0;
}
