
using namespace std;












using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();constexpr const double EPS=1e-9;
template<class T>constexpr bool flt(const T&x,const T&y){return x<y-EPS;}template<class T>constexpr bool fgt(const T&x,const T&y){return x>y+EPS;}
template<class T>constexpr bool feq(const T&x,const T&y){return abs(x-y)<=EPS;}template<class T>constexpr bool in(const T&v,const T&lo,const T&hi){return!(v<lo||hi<v);}
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<class T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<class T,class...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<class T,class...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}





template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;template<class...Ts>using pq=priority_queue<Ts...>;
template<class T>using minpq=pq<T,vector<T>,greater<T>>;template<class T>using maxpq=pq<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id2(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id2(long){return false;}constexpr static bool value=id2<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id1=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[id1],_tempOutputBuf[id1],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id4=0,_cnt;ull _precisionBase=1000000;














void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}























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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>id3=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXN, const bool id5> struct SegmentTree_SAM_RQ {
    using Data = pii; int N; Data T[2 * MAXN];
    const Data def = mp(INT_INF, -INT_INF); 

    const Data qdef = mp(INT_INF, -INT_INF); 

    

    Data merge(Data l, Data r) { return mp(min(l.f, r.f), max(l.s, r.s)); }
    Data applyVal(Data l, Data r) { return r; }
    template <class it> void init(it st, it en) {
        N = en - st; for (int i = 0; i < N; i++) T[N + i] = *(st + i);
        for (int i = N - 1; i > 0; i--) T[i] = merge(T[i << 1], T[i << 1 | 1]);
    }
    void init(int size) { N = size; for (int i = 1; i < 2 * N; i++) T[i] = def; }
    void update(int i, Data v) { for (i += N - id5, T[i] = applyVal(T[i], v); i >>= 1;) T[i] = merge(T[i << 1], T[i << 1 | 1]); }
    Data query(int l, int r) {
        Data ql = qdef, qr = qdef;
        for (l += N - id5, r += N - id5; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ql = merge(ql, T[l++]);
            if (!(r & 1)) qr = merge(T[r--], qr);
        }
        return merge(ql, qr);
    }
};

const int MAXN = 1e5 + 5, id0 = 20;

int N, R[MAXN], ans[MAXN];
SegmentTree_SAM_RQ<MAXN * 3, false> T[id0];
pii RANGE[id0][MAXN * 3];

int main() {
    

    

    

    read(N);
    read(R, R + N);
    if (N == 1) {
        writeln(0);
        return 0;
    }
    FOR(i, id0) T[i].init(3 * N);
    FOR(j, 3 * N) T[0].update(j, RANGE[0][j] = mp(max(0, j - R[j % N]), min(3 * N - 1, j + R[j % N])));
    For(i, 1, id0) FOR(j, 3 * N) T[i].update(j, RANGE[i][j] = T[i - 1].query(RANGE[i - 1][j].f, RANGE[i - 1][j].s));
    FOR(i, N) {
        ans[i] = 1;
        pii cur = mp(N + i, N + i);
        REV(j, id0 - 1) {
            pii nxt = T[j].query(cur.f, cur.s);
            if (nxt.s - nxt.f + 1 < N) {
                ans[i] += 1 << j;
                cur = nxt;
            }
        }
    }
    writeln(ans, ans + N);
    return 0;
}
