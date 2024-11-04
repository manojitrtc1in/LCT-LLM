





using namespace std;using namespace __gnu_pbds;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=std::pair<int,int>;using pll=std::pair<ll,ll>;using pill=std::pair<int,ll>;using plli=std::pair<ll,int>;using pdd=std::pair<double,double>;using pld=std::pair<ld,ld>;

    using i128=__int128_t;using ui128=__uint128_t;using pi128=std::pair<i128,i128>;

constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=std::numeric_limits<double>::infinity();constexpr const ld LD_INF=std::numeric_limits<ld>::infinity();
template<class T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<class T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<class T,class...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<class T,class...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<class T,class...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<class T,class...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<class T,class...Args>std::unique_ptr<T>_make_unique(Args&&...args){return std::unique_ptr<T>(new T(std::forward<Args>(args)...));}
template<class T,class...Args>std::shared_ptr<T>_make_shared(Args&&...args){return std::shared_ptr<T>(new T(std::forward<Args>(args)...));}




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
    template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id9(int)->decltype(*std::declval<U>(),bool()){return true;}
    template<class>constexpr static bool id9(long){return false;}constexpr static bool value=id9<T>(0);
};


constexpr const int _bufferSize=1<<16,id4=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last,_sign,*id8=nullptr,_numBuf[id4],_tempOutputBuf[id4],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=9,_width=0,id12=0,_cnt;ull _precisionBase=1000000000;

    
    
    


    char _getchar(){return _last=getchar_unlocked();}
    char id3(){while(_getchar()=='\r');return _last;}

    char id15(){return*_inputPtr?*_inputPtr:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr);}
    char id14(){while(id15()=='\r')_last=*_inputPtr++;return id15();}
    char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
    char id3(){while(_getchar()=='\r');return _last;}
    bool hasNext(){return (_last&&id14())||!feof(_input);}bool id0(){while(hasNext()&&id15()<=' ')_getchar();return hasNext();}

template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');_sign=x=='-';if(_sign)x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void id5(F&x){for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));}
void setLength(int x){if(id8)delete[](id8);id8=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);if(_sign)x=-x;}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}

    void read(i128&x){_readSigned(x);if(_sign)x=-x;}void read(ui128&x){_readUnsigned(x);}

template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){_readSigned(x);if(_c=='.')id5(x);if(_sign)x=-x;}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')id3();for(_cur=0;(_c=id3())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!id8)assert(0);read(id8);x=std::string(id8,_cur);}
void readln(std::string &x){if(!id8)assert(0);readln(id8);x=std::string(id8,_cur);}
template<class T1,class T2>void read(std::pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(std::complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x){for(auto&&_i:x)read(_i);}
template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(std::forward<Ts>(xs)...);}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const std::string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
int _flushBuf(){fwrite_unlocked(_outputBuffer,1,_outputPtr,_output);return _outputPtr=0;}void flush(){_flushBuf();fflush(_output);}
int _putchar(char x){return _outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=x,_outputPtr++;}
void id2(char x){_tempOutputBuf[id12++]=x;}void _writeOutput(){for(int _i=0;_i<id12;_putchar(_tempOutputBuf[_i++]));id12=0;}
void _fillBuf(int x){for(int _i=0;_i<x;_i++)_putchar(_fill);}void id10(){for(;_numPtr;id2(_numBuf[--_numPtr]));}
void id13(){int _tempLen=id12;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen);}
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const std::string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
template<class T>void _writeNum(const T&x,int digits){_cnt=0;for(T _y=x;_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';id10();}
template<class F>void id7(const F&x){ull _I=ull(x);ull _F=(x-_I)*_precisionBase+F(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,1);id2('.');_writeNum(_F,_precision);}
void write(const bool&x){if(x)id2('1');else id2('0');id13();}void write(const char&x){id2(x);id13();}
void write(const char*x){int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=x;*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}
void write(const std::string&x){_fillBuf(_width-int(x.length()));for(int _i=0;_i<int(x.length());_putchar(x[_i++]));_fillBuf(-_width-int(x.length()));}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type write(const I&x){
    using UI=typename std::make_unsigned<I>::type;if(x<0){id2('-');_writeNum(UI(-x),1);}else{_writeNum(UI(x),1);}id13();
}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type write(const UI&x){_writeNum(x,1);id13();}
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type write(const F&x){
    if(std::isnan(x)){write("NaN");}else if(std::isinf(x)){write("Inf");}else if(x<0){id2('-');id7(-x);}else{id7(x);}id13();
}

    void write(const i128&x){if(x<0){id2('-');_writeNum(ui128(-x),1);}else{_writeNum(ui128(x),1);}id13();}void write(const ui128&x){_writeNum(x,1);id13();}

template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(id8)delete[](id8);}};std::unique_ptr<IOManager>id11=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}

template <class T> T posMod(T a, T mod) { T ret = -mod < a && a < mod ? a : a % mod; return 0 <= ret ? ret : ret + mod; }

template <class T> T addMod(T a, T b, T mod) { T ret = a + b; return ret < mod ? ret : ret - mod; }

template <class T> T subMod(T a, T b, T mod) { T ret = a - b; return 0 <= ret ? ret : ret + mod; }

template <class T> T mulMod(T a, T b, T mod) { return a * b % mod; }

template <class T, class U> T powMod(T base, U pow, T mod) {
    T x = 1;
    for (; pow > 0; pow >>= 1, base = mulMod(base, base, mod)) if (pow & 1) x = mulMod(x, base, mod);
    return x;
}

template <class T> T id6(T i, T p) { return powMod(i, p - 2, p); }

template <class T> T id1(T i, T j, T p) { return mulMod(i, id6(j, p), p); }

template <const int MAXN, class T> struct Combinatorics {
    T fact[MAXN], invFact[MAXN];
    void init(int N) { 

        fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i;
    }
    void init(int N, T P) { 

        assert(N < P); fact[0] = 1;
        for (int i = 1; i <= N; i++) fact[i] = mulMod(fact[i - 1], T(i), P);
        invFact[N] = id6(fact[N], P);
        for (int i = N - 1; i >= 0; i--) invFact[i] = mulMod(invFact[i + 1], T(i + 1), P);
    }
    T factorial(int N) { return fact[N]; }
    T invFactorial(int N) { return invFact[N]; }
    T permute(int N, int K) { return fact[N] / fact[N - K]; }
    T permute(int N, int K, T P) { return mulMod(fact[N], invFact[N - K], P); }
    T choose(int N, int K) { return fact[N] / fact[K] / fact[N - K]; }
    T choose(int N, int K, T P) { return mulMod(mulMod(fact[N], invFact[K], P), invFact[N - K], P); }
    T multiChoose(int N, int K) { return choose(N + K - 1, K); }
    T multiChoose(int N, int K, T P) { return choose(N + K - 1, K, P); }
};

const ll MOD = 998244353;
const int MAXN = 2e5 + 5;

int N;
ll K, A[MAXN];
Combinatorics<MAXN, ll> comb;

int main() {
    

    

    

    read(N, K);
    read(A + 1, A + N + 1);
    A[0] = A[N];
    if (K == 1) {
        writeln(0);
        return 0;
    }
    comb.init(N, MOD);
    ll cnt = 0;
    for (int i = 0; i < N; i++) cnt += A[i] != A[i + 1];
    ll ans = 0;
    for (int i = 0; i * 2 <= cnt; i++) {
        ll add = mulMod(comb.choose(cnt, i, MOD), comb.choose(cnt - i, i, MOD), MOD);
        add = mulMod(add, powMod(K, N - cnt, MOD), MOD);
        add = mulMod(add, powMod(K - 2, cnt - 2 * i, MOD), MOD);
        ans = addMod(ans, add, MOD);
    }
    ans = subMod(powMod(K, N, MOD), ans, MOD);
    ans = id1(ans, 2LL, MOD);
    writeln(ans);
    return 0;
}