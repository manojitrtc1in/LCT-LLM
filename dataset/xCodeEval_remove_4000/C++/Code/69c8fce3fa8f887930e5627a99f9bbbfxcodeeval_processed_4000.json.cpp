
using namespace std;












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





template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;template<class...Ts>using pq=priority_queue<Ts...>;
template<class T>using minpq=pq<T,vector<T>,greater<T>>;template<class T>using maxpq=pq<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id1(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id1(long){return false;}constexpr static bool value=id1<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id3=0,_cnt;ull _precisionBase=1000000;














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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>id2=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

struct id4 {
    using Data = int; static const Data vdef = INT_INF, qdef = 0;
    Data merge(const Data &l, const Data &r) { return max(l, r); }
    Data apply(const Data &x, const Data &v) { return min(x, v); }
    struct Node {
        Node *left = nullptr, *right = nullptr;
        Data val = id4::vdef;
    };
    int N; vector<Node*> roots = {new Node()};
    Node *update(Node *cur, int cL, int cR, int ind, const Data &val) {
        if (cL > ind || cR < ind) return cur;
        Node *ret = new Node();
        if (cur) { ret->left = cur->left; ret->right = cur->right; ret->val = cur->val; }
        if (cL == cR) { ret->val = apply(ret->val, val); return ret; }
        int m = cL + (cR - cL) / 2;
        ret->left = update(ret->left, cL, m, ind, val);
        ret->right = update(ret->right, m + 1, cR, ind, val);
        if (ret->left && ret->right) ret->val = merge(ret->left->val, ret->right->val);
        else if (ret->left) ret->val = merge(ret->left->val, Data(vdef));
        else if (ret->right) ret->val = merge(ret->right->val, Data(vdef));
        return ret;
    }
    Data query(Node *cur, int cL, int cR, int l, int r) {
        if (cL > r || cR < l) return qdef;
        if (!cur) return vdef;
        if (cL >= l && cR <= r) return cur->val;
        int m = cL + (cR - cL) / 2;
        return merge(query(cur->left, cL, m, l, r), query(cur->right, m + 1, cR, l, r));
    }
    id4(int size) : N(size) {}
    void update(int ind, int val) { roots.push_back(update(roots.back(), 1, N, ind, val)); }
    Data query(int rootInd, int l, int r) { return query(roots[rootInd], 1, N, l, r); }
};

const int MAXK = 3e5 + 5;

int N, M, K;
pair<pii, int> seg[MAXK];

int main() {
    

    

    

    read(N, M, K);
    id4 ST(N);
    read(seg, seg + K);
    sort(seg, seg + K, greater<pair<pii, int>>());
    FOR(i, K) ST.update(seg[i].s, seg[i].f.s);
    int a, b, x, y;
    FOR(i, M) {
        read(a, b, x, y);
        writeln(ST.query(upper_bound(seg, seg + K, mp(mp(x, 0), 0), greater<pair<pii, int>>()) - seg, a, b) <= y ? "yes" : "no");
        flush();
    }
    return 0;
}
