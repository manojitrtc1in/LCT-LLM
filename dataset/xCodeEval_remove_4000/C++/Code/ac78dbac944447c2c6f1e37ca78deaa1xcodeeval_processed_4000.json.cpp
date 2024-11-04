



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
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id2(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id2(long){return false;}constexpr static bool value=id2<T>(0);
};


constexpr const int _bufferSize=1<<16,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id1=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id4=0,_cnt;ull _precisionBase=1000000;

    
    
    


    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id6(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











void setLength(int x){if(id1)delete[](id1);id1=new char[x+1];}
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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(id1)delete[](id1);}};unique_ptr<IOManager>id3=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

vector<pair<long long, int>> id5(long long x) {
    vector<pair<long long, int>> ret;
    for (long long i = 2; i * i <= x; i++) if (x % i == 0) {
        ret.emplace_back(i, 0);
        while (x % i == 0) { ret.back().second++; x /= i; }
    }
    if (x > 1) ret.emplace_back(x, 1);
    return ret;
}

template <class T> T gcd(T a, T b) { return b == 0 ? abs(a) : gcd(b, a % b); }

template <class T> T lcm(T a, T b) { return abs(a / gcd(a, b) * b); }

template <class T> T EEA(T a, T b, T &x, T &y) {
    if (b == 0) { x = 1; y = 0; return abs(a); }
    T x1, y1, g = EEA(b, a % b, x1, y1); y = x1 - (a / b) * y1; x = y1; return g;
}

template <class T> T multInv(T a, T n) {
    T x, y;
    if (EEA(a, n, x, y) != 1) return -1; 

    return (x % n + n) % n;
}

template <class T> pair<T, T> CRT(pair<T, T> a, pair<T, T> b) {
    T g = gcd(a.second, b.second), l = a.second / g * b.second;
    if ((b.first - a.first) % g != 0) return make_pair(-1, l); 

    T A = a.second / g, B = b.second / g, mul = (b.first - a.first) / g * multInv(A % B, B) % B;
    return make_pair(((mul * a.second + a.first) % l + l) % l, l);
}

const int MAXN = 1e5 + 5, MAXPF = 10;

int N, Q, mod, A[MAXN];
plli B[MAXPF][MAXN];
vector<plli> PF;
vector<vector<ll>> POW;

template <const int MAXN, const bool id7> struct LazySegmentTree {
    using Data = plli; using Lazy = plli; const Data vdef = mp(1, 0), qdef = mp(0, 0); const Lazy ldef = mp(1, 0); int pfInd; Data T[MAXN * 2], A[MAXN]; Lazy L[MAXN * 2]; int N;
    Data merge(const Data &l, const Data &r) {
        Data ret;
        ret.f = (l.s >= PF[pfInd].s ? 0 : l.f * POW[pfInd][l.s] % POW[pfInd].back()) + (r.s >= PF[pfInd].s ? 0 : r.f * POW[pfInd][r.s] % POW[pfInd].back());
        ret.s = 0;
        if (ret.f >= POW[pfInd].back()) ret.f -= POW[pfInd].back();
        return ret;
    }
    Lazy getSegmentVal(const Lazy &v, int k) { return v; }
    Lazy mergeLazy(const Lazy &l, const Lazy &r) { return mp(l.f * r.f % POW[pfInd].back(), l.s + r.s); }
    Data applyLazy(const Data &l, const Lazy &r) { return mp(l.f * r.f % POW[pfInd].back(), l.s + r.s); }
    void propagate(int cur, int cL, int cR) {
        if (L[cur] != ldef) {
            int m = cL + (cR - cL) / 2, rc = cur + (m - cL + 1) * 2;
            T[cur + 1] = applyLazy(T[cur + 1], getSegmentVal(L[cur], m - cL + 1)); L[cur + 1] = mergeLazy(L[cur + 1], L[cur]);
            T[rc] = applyLazy(T[rc], getSegmentVal(L[cur], cR - m)); L[rc] = mergeLazy(L[rc], L[cur]);
            L[cur] = ldef;
        }
    }
    void build(int cur, int cL, int cR) {
        if (cL == cR) { T[cur] = A[cL]; L[cur] = ldef; return; }
        int m = cL + (cR - cL) / 2, rc = cur + (m - cL + 1) * 2; build(cur + 1, cL, m); build(rc, m + 1, cR);
        T[cur] = merge(T[cur + 1], T[rc]); L[cur] = ldef;
    }
    void update(int cur, int cL, int cR, int l, int r, const Lazy &val) {
        if (cL > r || cR < l) return;
        if (cL >= l && cR <= r) { T[cur] = applyLazy(T[cur], getSegmentVal(val, cR - cL + 1)); L[cur] = mergeLazy(L[cur], val); return; }
        int m = cL + (cR - cL) / 2, rc = cur + (m - cL + 1) * 2; propagate(cur, cL, cR);
        update(cur + 1, cL, m, l, r, val); update(rc, m + 1, cR, l, r, val); T[cur] = merge(T[cur + 1], T[rc]);
    }
    Data query(int cur, int cL, int cR, int l, int r) {
        if (cL > r || cR < l) return qdef;
        if (cL >= l && cR <= r) return T[cur];
        int m = cL + (cR - cL) / 2, rc = cur + (m - cL + 1) * 2; propagate(cur, cL, cR);
        return merge(query(cur + 1, cL, m, l, r), query(rc, m + 1, cR, l, r));
    }
    template <class It> void init(It st, It en, int pfInd) {
        N = en - st; this->pfInd = pfInd;
        for (int i = 0; i < N; i++) A[i + id7] = *(st + i);
        build(0, id7, N - !id7);
    }
    void init(int size, int pfInd) { N = size; this->pfInd = pfInd; fill(A + id7, A + N + id7, vdef); build(0, id7, N - !id7); }
    void update(int l, int r, const Lazy &val) { update(0, id7, N - !id7, l, r, val); }
    Data query(int l, int r) { return query(0, id7, N - !id7, l, r); }
};

LazySegmentTree<MAXN, 1> ST[MAXPF];

int main() {
    

    

    

    read(N, mod);
    PF = id5(mod);
    assert(sz(PF) < MAXPF);
    FOR(i, sz(PF)) {
        POW.eb();
        POW.back().pb(1);
        FOR(j, PF[i].s) POW.back().pb(POW.back().back() * PF[i].f);
    }
    read(A, A + N, Q);
    FOR(j, N) FOR(i, sz(POW)) {
        int y = A[j], cnt = 0;
        for (; y % PF[i].f == 0; y /= PF[i].f) cnt++;
        B[i][j] = mp(y %= POW[i].back(), cnt);
    }
    FOR(i, sz(POW)) ST[i].init(B[i], B[i] + N, i);
    FOR(q, Q) {
        int t;
        read(t);
        if (t == 1) {
            int l, r, x;
            read(l, r, x);
            FOR(i, sz(POW)) {
                int y = x, cnt = 0;
                for (; y % PF[i].f == 0; y /= PF[i].f) cnt++;
                ST[i].update(l, r, mp(y %= POW[i].back(), cnt));
            }
        } else if (t == 2) {
            int p, x;
            read(p, x);
            FOR(i, sz(POW)) {
                int y = x, cnt = 0;
                for (; y % PF[i].f == 0; y /= PF[i].f) cnt++;
                int z = multInv(ll(y %= POW[i].back()), POW[i].back());
                assert(z != -1);
                ST[i].update(p, p, mp(z, -cnt));
            }
        } else {
            int l, r;
            read(l, r);
            pll ans(0, 1);
            FOR(i, sz(POW)) {
                plli res = ST[i].query(l, r);
                ans = CRT(ans, mp<ll, ll>(res.s >= POW[i].back() ? 0 : res.f * POW[i][res.s] % POW[i].back(), ll(POW[i].back())));
            }
            writeln(ans.f);
        }
    }
    return 0;
}
