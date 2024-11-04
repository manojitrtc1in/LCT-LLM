

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;using namespace __gnu_pbds;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=std::pair<int,int>;using pll=std::pair<ll,ll>;using pill=std::pair<int,ll>;using plli=std::pair<ll,int>;using pdd=std::pair<double,double>;using pld=std::pair<ld,ld>;
#if __SIZEOF_INT128__
    using i128=__int128_t;using ui128=__uint128_t;using pi128=std::pair<i128,i128>;
#endif
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=std::numeric_limits<double>::infinity();constexpr const ld LD_INF=std::numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T,class...Args>std::unique_ptr<T>_make_unique(Args&&...args){return std::unique_ptr<T>(new T(std::forward<Args>(args)...));}
template<class T,class...Args>std::shared_ptr<T>_make_shared(Args&&...args){return std::shared_ptr<T>(new T(std::forward<Args>(args)...));}
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
#define make_unique _make_unique
#define make_shared _make_shared
std::seed_seq seq{
    (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
std::mt19937 rng(seq);std::mt19937_64 rng64(seq);const size_t RANDOM=std::uniform_int_distribution<std::size_t>(0,(std::numeric_limits<std::size_t>::max)())(rng64);
template<class T,class H=std::hash<T>>struct rand_hash{
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
};
template<class K,class H=rand_hash<K>,class...Ts>using hashset=__gnu_pbds::gp_hash_table<K,__gnu_pbds::null_type,H,Ts...>;
template<class K,class V,class H=rand_hash<K>,class...Ts>using hashmap=__gnu_pbds::gp_hash_table<K,V,H,Ts...>;
template<class K,class C=std::less<K>,class...Ts>using treeset=__gnu_pbds::tree<K,__gnu_pbds::null_type,C,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update,Ts...>;
template<class K,class V,class C=std::less<K>,class...Ts>using treemap=__gnu_pbds::tree<K,V,C,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update,Ts...>;
template<class K,class H=rand_hash<K>,class...Ts>using uset=std::unordered_set<K,H,Ts...>;
template<class K,class V,class H=rand_hash<K>,class...Ts>using umap=std::unordered_map<K,V,H,Ts...>;
template<class T>using minpq=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using maxpq=std::priority_queue<T,std::vector<T>,std::less<T>>;
template<class T>using minpairingheap=__gnu_pbds::priority_queue<T,std::greater<T>,__gnu_pbds::pairing_heap_tag>;
template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,std::less<T>,__gnu_pbds::pairing_heap_tag>;
template<class T1,class T2,class H1=rand_hash<T1>,class H2=rand_hash<T2>>struct pair_hash{
    size_t operator()(const std::pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}
};
template<class T>struct is_iterator{
    template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*std::declval<U>(),bool()){return true;}
    template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
};

#define INTERACTIVE_INPUT 0
constexpr const int _bufferSize=1<<16,_maxNumLength=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=9,_width=0,_tempOutputPtr=0,_cnt;ull _precisionBase=1000000000;
#ifdef _WIN32
    #define getchar_unlocked getchar
    #define fread_unlocked fread
    #define fwrite_unlocked fwrite
#endif
#if INTERACTIVE_INPUT
    char _getchar(){return _last=getchar_unlocked();}
    char _getcharskipr(){while(_getchar()=='\r');return _last;}
#else
    char _peekchar(){return*_inputPtr?*_inputPtr:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr);}
    char _peekcharskipr(){while(_peekchar()=='\r')_last=*_inputPtr++;return _peekchar();}
    char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
    char _getcharskipr(){while(_getchar()=='\r');return _last;}
    bool hasNext(){return (_last&&_peekcharskipr())||!feof(_input);}bool hasNextToken(){while(hasNext()&&_peekchar()<=' ')_getchar();return hasNext();}
#endif
template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');_sign=x=='-';if(_sign)x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void _readFloatingPoint(F&x){for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));}
void setLength(int x){if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);if(_sign)x=-x;}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}
#if __SIZEOF_INT128__
    void read(i128&x){_readSigned(x);if(_sign)x=-x;}void read(ui128&x){_readUnsigned(x);}
#endif
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){_readSigned(x);if(_c=='.')_readFloatingPoint(x);if(_sign)x=-x;}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')_getcharskipr();for(_cur=0;(_c=_getcharskipr())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!_tempInputBuf)assert(0);read(_tempInputBuf);x=std::string(_tempInputBuf,_cur);}
void readln(std::string &x){if(!_tempInputBuf)assert(0);readln(_tempInputBuf);x=std::string(_tempInputBuf,_cur);}
template<class T1,class T2>void read(std::pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(std::complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x){for(auto&&_i:x)read(_i);}
template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(std::forward<Ts>(xs)...);}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const std::string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
int _flushBuf(){fwrite_unlocked(_outputBuffer,1,_outputPtr,_output);return _outputPtr=0;}void flush(){_flushBuf();fflush(_output);}
int _putchar(char x){return _outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=x,_outputPtr++;}
void _writeTempBuf(char x){_tempOutputBuf[_tempOutputPtr++]=x;}void _writeOutput(){for(int _i=0;_i<_tempOutputPtr;_putchar(_tempOutputBuf[_i++]));_tempOutputPtr=0;}
void _fillBuf(int x){for(int _i=0;_i<x;_i++)_putchar(_fill);}void _flushNumBuf(){for(;_numPtr;_writeTempBuf(_numBuf[--_numPtr]));}
void _flushTempBuf(){int _tempLen=_tempOutputPtr;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen);}
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const std::string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
template<class T>void _writeNum(const T&x,int digits){_cnt=0;for(T _y=x;_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';_flushNumBuf();}
template<class F>void _writeFloatingPoint(const F&x){ull _I=ull(x);ull _F=(x-_I)*_precisionBase+F(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,1);_writeTempBuf('.');_writeNum(_F,_precision);}
void write(const bool&x){if(x)_writeTempBuf('1');else _writeTempBuf('0');_flushTempBuf();}void write(const char&x){_writeTempBuf(x);_flushTempBuf();}
void write(const char*x){int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=x;*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}
void write(const std::string&x){_fillBuf(_width-int(x.length()));for(int _i=0;_i<int(x.length());_putchar(x[_i++]));_fillBuf(-_width-int(x.length()));}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type write(const I&x){
    using UI=typename std::make_unsigned<I>::type;if(x<0){_writeTempBuf('-');_writeNum(UI(-x),1);}else{_writeNum(UI(x),1);}_flushTempBuf();
}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type write(const UI&x){_writeNum(x,1);_flushTempBuf();}
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type write(const F&x){
    if(std::isnan(x)){write("NaN");}else if(std::isinf(x)){write("Inf");}else if(x<0){_writeTempBuf('-');_writeFloatingPoint(-x);}else{_writeFloatingPoint(x);}_flushTempBuf();
}
#if __SIZEOF_INT128__
    void write(const i128&x){if(x<0){_writeTempBuf('-');_writeNum(ui128(-x),1);}else{_writeNum(ui128(x),1);}_flushTempBuf();}void write(const ui128&x){_writeNum(x,1);_flushTempBuf();}
#endif
template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};std::unique_ptr<IOManager>iomanager=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXV, const bool ONE_INDEXED> struct SubtreeQueries {
    using Data = int; int st[MAXV], en[MAXV], vert[MAXV], curInd, size[MAXV]; vector<int> adj[MAXV];
    void update(int i, Data val); 

    void update(int l, int r, Data val); 

    Data query(int l, int r); 

    void dfs(int v, int prev) {
        vert[st[v] = ++curInd] = v; size[v] = 1;
        for (int w : adj[v]) if (w != prev) {
            dfs(w, v);
            size[v] += size[w];
        }
        en[v] = curInd;
    }
    void clear(int V = MAXV) { for (int i = 0; i < V; i++) adj[i].clear(); }
    void run(int V, int root = 0) {
        curInd = int(ONE_INDEXED) - 1; fill(st, st + V, -1); dfs(root, -1);
        for (int v = 0; v < V; v++) if (st[v] == -1) dfs(v, -1);
    }
    void addEdge(int a, int b) { adj[a].push_back(b); adj[b].push_back(a); }
    void updateVertex(int v, Data val) { update(st[v], val); }
    void updateSubtree(int v, Data val) { update(st[v], en[v], val); }
    Data querySubtree(int v) { return query(st[v], en[v]); }
};

template <const int MAXM, const int MAXN, class F> struct TwoPhaseSimplex {
    int M, N, IN[MAXM], OUT[MAXN]; F INF, EPS, A[MAXM][MAXN], b[MAXM], c[MAXN], x[MAXN], T[MAXM][MAXN];
    TwoPhaseSimplex(F INF, F EPS) : INF(INF), EPS(EPS) {}
    bool cmp(F a, int b, F c, int d) { return abs(a - c) > EPS ? a < c : b < d; }
    void pivot(int r, int s) {
        auto &a1 = T[r]; F inv1 = 1 / a1[s];
        for (int i = 0; i <= M + 1; i++) if (i != r && abs(T[i][s]) > EPS) {
            auto &a2 = T[i]; F inv2 = a2[s] * inv1;
            for (int j = 0; j <= N + 1; j++) a2[j] -= a1[j] * inv2;
            a2[s] = a1[s] * inv2;
        }
        for (int j = 0; j <= N + 1; j++) if (j != s) a1[j] *= inv1;
        for (int i = 0; i <= M + 1; i++) if (i != r) T[i][s] *= -inv1;
        a1[s] = inv1; swap(IN[r], OUT[s]);
    }
    bool simplex(int phase) {
        int x = M + phase - 1;
        while (true) {
            int s = -1;
            for (int j = 0; j <= N; j++) if (OUT[j] != -phase && (s == -1 || cmp(T[x][j], OUT[j], T[x][s], OUT[s]))) s = j;
            if (T[x][s] >= -EPS) return true;
            int r = -1;
            for (int i = 0; i < M; i++) if (T[i][s] > EPS && (r == -1 || cmp(T[i][N + 1] * T[r][s], IN[i], T[r][N + 1] * T[i][s], IN[r]))) r = i;
            if (r == -1) return false;
            pivot(r, s);
        }
    }
    F solve(int m, int n) {
        M = m; N = n;
        for (int i = 0; i <= M + 1; i++) fill(T[i], T[i] + N + 2, 0);
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) T[i][j] = A[i][j];
        for (int i = 0; i < M; i++) { IN[i] = N + i; T[i][N] = -1; T[i][N + 1] = b[i]; }
        for (int j = 0; j < N; j++) { OUT[j] = j; T[M][j] = -c[j]; }
        OUT[N] = -1; T[M + 1][N] = 1; int r = 0;
        for (int i = 1; i < M; i++) if (T[i][N + 1] < T[r][N + 1]) r = i;
        if (T[r][N + 1] < -EPS) {
            pivot(r, N);
            if (!simplex(2) || T[M + 1][N + 1] < -EPS) return -INF; 

            for (int i = 0; i < M; i++) if (IN[i] == -1) {
                int s = 0;
                for (int j = 1; j <= N; j++) if (s == -1 || cmp(T[i][j], OUT[j], T[i][s], OUT[s])) s = j;
                pivot(i, s);
            }
        }
        bool unbounded = !simplex(1); fill(x, x + N, 0);
        for (int i = 0; i < M; i++) if (IN[i] < N) x[IN[i]] = T[i][N + 1];
        return unbounded ? INF : T[M][N + 1];
    }
};

const int MAXN = 505;
const ld EPS = 1e-9;

int N, X, Y, Q1, Q2;
SubtreeQueries<MAXN, 0> T[2];
TwoPhaseSimplex<MAXN * 5, MAXN, ld> LP(LD_INF, EPS); 

int main() {
    

    

    

    read(N, X, Y);
    read(LP.c, LP.c + N);
    --X;
    --Y;
    for (int i = 0; i < 2 * (N - 1); i++) {
        int a, b;
        read(a, b);
        T[i >= N - 1].addEdge(--a, --b);
    }
    T[0].run(N, X);
    T[1].run(N, Y);
    read(Q1);
    int Q = Q1;
    for (int i = 0; i < Q; i++) {
        int k, x;
        read(k, x);
        --k;
        for (int j = 0; j < N; j++) {
            bool inSbtr = T[i >= Q1].st[k] <= T[i >= Q1].st[j] && T[i >= Q1].en[j] <= T[i >= Q1].en[k];
            LP.A[i * 2][j] = inSbtr ? 1 : 0;
            LP.A[i * 2 + 1][j] = inSbtr ? -1 : 0;
        }
        LP.b[i * 2] = x;
        LP.b[i * 2 + 1] = -x;
        if (i == Q1 - 1) {
            read(Q2);
            Q += Q2;
        }
    }
    for (int i = 0; i < N; i++) {
        fill(LP.A[2 * Q + i], LP.A[2 * Q + i] + N, 0);
        LP.A[2 * Q + i][i] = 1;
        LP.b[2 * Q + i] = 1;
    }
    ld ans = LP.solve(2 * Q + N, N);
    writeln(ans == -LD_INF ? -1 : ll(round(ans)));
    return 0;
}
