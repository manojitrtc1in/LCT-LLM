

#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define f first
#define s second
#define all(a) (a).begin(),(a).end()
#define For(i,a,b) for(auto i=(a);i<(b);i++)
#define FOR(i,b) For(i,0,b)
#define Rev(i,a,b) for(auto i=(a);i>(b);i--)
#define REV(i,a) Rev(i,a,-1)
#define FORE(i,a) for(auto&&i:a)
#define sz(a) (int((a).size()))
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
#define min(...) _min(__VA_ARGS__)
#define max(...) _max(__VA_ARGS__)
#define clamp(...) _clamp(__VA_ARGS__)
#define make_unique _make_unique
#define make_shared _make_shared
template<class...Ts>using uset=unordered_set<Ts...>;template<class...Ts>using umap=unordered_map<Ts...>;template<class...Ts>using pq=priority_queue<Ts...>;
template<class T>using minpq=pq<T,vector<T>,greater<T>>;template<class T>using maxpq=pq<T,vector<T>,less<T>>;
template<class T1,class T2,class H1=hash<T1>,class H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,_maxNumLength=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,_tempOutputPtr=0,_cnt;ull _precisionBase=1000000;
#define _peekchar() (*_inputPtr?*_inputPtr:(_inputBuffer[fread(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr))
#define _getchar() (*_inputPtr?*_inputPtr++:(_inputBuffer[fread(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++))
#define _hasNext() (*_inputPtr||!feof(_input))
#define _readSignAndNum(x) do{(x)=_getchar();}while((x)<=' ');_sign=(x)=='-';if(_sign)(x)=_getchar();for((x)-='0';(_c=_getchar())>='0';(x)=(x)*10+_c-'0')
#define _readFloatingPoint(x,T) for(T _div=1.0;(_c=_getchar())>='0';(x)+=(_c-'0')/(_div*=10))
#define rc(x) do{do{(x)=_getchar();}while((x)<=' ');}while(0)
#define ri(x) do{_readSignAndNum(x);if(_sign)(x)=-(x);}while(0)
#define rd(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,double);if(_sign)(x)=-(x);}while(0)
#define rld(x) do{_readSignAndNum(x);if(_c=='.')_readFloatingPoint(x,ld);if(_sign)(x)=-(x);}while(0)
#define rcs(x) do{_cur=0;do{_c=_getchar();}while(_c<=' ');do{(x)[_cur++]=_c;}while((_c=_getchar())>' ');(x)[_cur]='\0';}while(0)
#define rs(x) do{if(!_tempInputBuf)assert(0);rcs(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
#define rcln(x) do{_cur=0;do{_c=_getchar();}while(_c<=' ');do{(x)[_cur++]=_c;}while((_c=_getchar())>=' ');(x)[_cur]='\0';}while(0)
#define rln(x) do{if(!_tempInputBuf)assert(0);rcln(_tempInputBuf);(x)=string(_tempInputBuf,_cur);}while(0)
#define setLength(x) do{if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[(x)+1];}while(0)
void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
#define _flush() do{_flushBuf();fflush(_output);}while(0)
#define _flushBuf() (fwrite(_outputBuffer,1,_outputPtr,_output),_outputPtr=0)
#define _putchar(x) (_outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=(x),_outputPtr++)
#define _writeTempBuf(x) (_tempOutputBuf[_tempOutputPtr++]=(x))
#define _writeOutput() for(int _i=0;_i<_tempOutputPtr;_putchar(_tempOutputBuf[_i++]));_tempOutputPtr=0
#define _writeNum(x,T,digits) _cnt=0;for(T _y=(x);_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';_flushNumBuf();
#define _writeFloatingPoint(x,T) ull _I=(ull)(x);ull _F=((x)-_I)*_precisionBase+(T)(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,ull,1);_writeTempBuf('.');_writeNum(_F,ull,_precision)
#define _checkFinite(x) if(std::isnan(x)){wcs("NaN");}else if(std::isinf(x)){wcs("Inf");}
#define _flushNumBuf() for(;_numPtr;_writeTempBuf(_numBuf[--_numPtr]))
#define _fillBuf(x) for(int _i=0;_i<(x);_i++)_putchar(_fill)
#define _flushTempBuf() int _tempLen=_tempOutputPtr;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen)
#define wb(x) do{if(x)_writeTempBuf('1');else _writeTempBuf('0');_flushTempBuf();}while(0)
#define wc(x) do{_writeTempBuf(x); _flushTempBuf();}while(0)
#define wi(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),uint,1);}else{_writeNum(x,uint,1);}_flushTempBuf();}while(0)
#define wll(x) do{if((x)<0){_writeTempBuf('-');_writeNum(-(x),ull,1);}else{_writeNum(x,ull,1);}_flushTempBuf();}while(0)
#define wd(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),double);}else{_writeFloatingPoint(x,double);}_flushTempBuf();}while(0)
#define wld(x) do{_checkFinite(x)else if((x)<0){_writeTempBuf('-');_writeFloatingPoint(-(x),ld);}else{_writeFloatingPoint(x,ld);}_flushTempBuf();}while(0)
#define wcs(x) do{int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=(x);*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}while(0)
#define ws(x) do{_fillBuf(_width-int((x).length()));for(int _i=0;_i<int((x).length());_putchar(x[_i++]));_fillBuf(-_width-int((x).length()));}while(0)
#define setPrecision(x) do{_precision=(x);_precisionBase=1;for(int _i=0;_i<(x);_i++,_precisionBase*=10);}while(0)
#define setDelimiter(x) do{_delimiter=(x);}while(0)
#define setWidth(x) do{_width=(x);}while(0)
#define setFill(x) do{_fill=(x);}while(0)
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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>iomanager=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

const int MAXN = 3e5 + 5;

int N, M, ord[MAXN], ind[MAXN];
pll A[MAXN], sum[MAXN];
ll tot[MAXN];

pll operator + (const pll &a, const pll &b) {
    return mp(a.f + b.f, a.s + b.s);
}

pll operator - (const pll &a, const pll &b) {
    return mp(a.f - b.f, a.s - b.s);
}

pll getSum(int l, int r) {
    if (l > r) return mp(0, 0);
    else return sum[r + 1] - sum[l];
}

int main() {
    

    

    

    read(N, M);
    read(A, A + N);
    iota(ord, ord + N, 0);
    sort(ord, ord + N, [&] (const int &i, const int &j) {
        return A[i].f + A[j].s < A[i].s + A[j].f;
    });
    FOR(i, N) ind[ord[i]] = i;
    sum[0] = {0, 0};
    FOR(i, N) sum[i + 1] = sum[i] + A[ord[i]];
    fill(tot, tot + N, 0);
    FOR(i, N) tot[i] = (N - ind[i] - 1) * A[i].f + getSum(ind[i] + 1, N - 1).s + ind[i] * A[i].s + getSum(0, ind[i] - 1).f;
    int a, b;
    FOR(i, M) {
        read(a, b);
        --a; --b;
        ll v = min(A[a].f + A[b].s, A[a].s + A[b].f);
        tot[a] -= v;
        tot[b] -= v;
    }
    writeln(tot, tot + N);
    return 0;
}