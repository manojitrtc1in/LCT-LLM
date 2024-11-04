


using namespace std;











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





template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;
template<class T>using minpq=priority_queue<T,vector<T>,greater<T>>;template<class T>using maxpq=priority_queue<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id3(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id3(long){return false;}constexpr static bool value=id3<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id1=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id2=nullptr,_numBuf[id1],_tempOutputBuf[id1],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id5=0,_cnt;ull _precisionBase=1000000;













void setLength(int x){if(id2)delete[](id2);id2=new char[x+1];}
void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id6(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}
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

using T = long long; const int id0 = 150;

template <class T> T powMod(T base, T pow, T mod) {
    T x = 1, y = base % mod;
    for (; pow > 0; pow /= 2, y = y * y % mod) if (pow % 2 == 1) x = x * y % mod;
    return x;
}

template <class T> T multInv(T i, T p) {
    return powMod(i % p, p - 2, p);
}

T primitiveRoot(T p) {
    vector<T> fact; T phi = p - 1, n = phi;
    for (T i = 2; i * i <= n; i++) {
        if (n % i == 0) fact.push_back(i);
        while(n % i == 0) n /= i;
    }
    if (n > 1) fact.push_back(n);
    for (T res = 2; res <= p; res++) {
        bool ok = true;
        for (int i = 0; i < int(fact.size()) && ok; i++) ok &= powMod(res, phi / fact[i], p) != 1;
        if (ok) return res;
    }
    assert(false); return -1;
}

















const T C = 483, K = 21, PK = 1 << K, MOD = C * PK + 1, ROOT = powMod(primitiveRoot(MOD), C, MOD);

vector<int> ord; vector<T> roots;

void computeRoots(int N) {
    if (int(roots.size()) >= N) return;
    if (roots.empty()) roots = {0, 1};
    int len = __builtin_ctz(int(roots.size())); roots.resize(N);
    for (; (1 << len) < N; len++) {
        T z = powMod(ROOT, PK >> (len + 1), MOD);
        for (int i = 1 << (len - 1); i < (1 << len); i++) {
            roots[2 * i] = roots[i]; roots[2 * i + 1] = roots[i] * z % MOD;
        }
    }
}

void reorder(vector<T> &a) {
    int N = int(a.size());
    if (int(ord.size()) != N) {
        ord.assign(N, 0); int len = __builtin_ctz(N);
        for (int i = 0; i < N; i++) ord[i] = (ord[i >> 1] >> 1) + ((i & 1) << (len - 1));
    }
    for (int i = 0; i < N; i++) if (i < ord[i]) swap(a[i], a[ord[i]]);
}

void ntt(vector<T> &a) {
    int N = int(a.size()); computeRoots(N), reorder(a);
    for (int len = 1; len < N; len <<= 1) for (int i = 0; i < N; i += len << 1) for (int j = 0; j < len; j++) {
        T u = a[i + j], v = a[len + i + j] * roots[len + j] % MOD;
        a[i + j] = u + v < MOD ? u + v : u + v - MOD; a[len + i + j] = u - v >= 0 ? u - v : u - v + MOD;
    }
}



template <class T> void multiplyPolynomial(vector<T> &a, vector<T> &b, vector<T> &res, bool eq = false) {
    static_assert(is_integral<T>::value, "T must be an integral type");
    if (max(int(a.size()), int(b.size())) <= id0) {
        vector<T> c(int(a.size()) + int(b.size()) - 1, 0);
        for (int i = 0; i < int(a.size()); i++) for (int j = 0; j < int(b.size()); j++) {
            c[i + j] += a[i] * b[j] % MOD;
            if (c[i + j] >= MOD) c[i + j] -= MOD;
            else if (c[i + j] < 0) c[i + j] += MOD;
        }
        res.resize(int(a.size()) + int(b.size()) - 1, 0); copy(c.begin(), c.end(), res.begin());
        while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
        return;
    }
    int N = int(a.size()) + int(b.size()) - 1;
    while (N & (N - 1)) N++;
    vector<T> fa(N, 0), fb; copy(a.begin(), a.end(), fa.begin());
    ntt(fa);
    if (eq) fb = fa;
    else { fb.assign(N, 0); copy(b.begin(), b.end(), fb.begin()); ntt(fb); }
    res.resize(N); T invN = multInv(T(N), MOD); res[0] = fa[0] * fb[0] % MOD * invN % MOD;
    for (int i = 1; i < N; i++) res[N - i] = fa[i] * fb[i] % MOD * invN % MOD;
    ntt(res);
    while (int(res.size()) > 1 && res.back() == 0) res.pop_back();
}

int n, k;

int main() {
    

    

    

    read(n, k);
    vector<ll> x(1, 1), y(1001, 0);
    int a;
    FOR(i, n) {
        read(a);
        y[a] = 1;
    }
    int p = k;
    while (p > 0) {
        if (p % 2 == 1) multiplyPolynomial(x, y, x);
        p /= 2;
        if (p > 0) multiplyPolynomial(y, y, y, true);
    }
    vector<int> ans;
    FOR(i, sz(x)) if (x[i]) ans.pb(i);
    writeln(ans);
    return 0;
}
