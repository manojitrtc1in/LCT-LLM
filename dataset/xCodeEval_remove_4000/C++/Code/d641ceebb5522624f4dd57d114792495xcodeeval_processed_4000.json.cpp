




using namespace std;using namespace __gnu_pbds;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=std::pair<int,int>;using pll=std::pair<ll,ll>;using pill=std::pair<int,ll>;using plli=std::pair<ll,int>;using pdd=std::pair<double,double>;using pld=std::pair<ld,ld>;

    using i128=__int128_t;using ui128=__uint128_t;using pi128=std::pair<i128,i128>;

constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=std::numeric_limits<double>::infinity();constexpr const ld LD_INF=std::numeric_limits<ld>::infinity();
template<class T,class...Args>std::unique_ptr<T>_make_unique(Args&&...args){return std::unique_ptr<T>(new T(std::forward<Args>(args)...));}
template<class T,class...Args>std::shared_ptr<T>_make_shared(Args&&...args){return std::shared_ptr<T>(new T(std::forward<Args>(args)...));}


std::seed_seq seq{
    (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
std::mt19937 rng(seq);std::mt19937_64 rng64(seq);const std::size_t RANDOM=std::uniform_int_distribution<std::size_t>(0,std::numeric_limits<std::size_t>::max())(rng64);
template<class T,class H=std::hash<T>>struct rand_hash{
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    std::size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
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
    std::size_t operator()(const std::pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}
};
template<class T>struct is_iterator{
    template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id12(int)->decltype(*std::declval<U>(),bool()){return true;}
    template<class>constexpr static bool id12(long){return false;}constexpr static bool value=id12<T>(0);
};


constexpr const int _bufferSize=1<<16,id6=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last,_sign,*id11=nullptr,_numBuf[id6],_tempOutputBuf[id6],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=9,_width=0,id15=0,_cnt;ull _precisionBase=1000000000;

    
    
    


    char _getchar(){return _last=getchar_unlocked();}
    char id5(){while(_getchar()=='\r');return _last;}

    char id19(){return*_inputPtr?*_inputPtr:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr);}
    char id17(){while(id19()=='\r')_last=*_inputPtr++;return id19();}
    char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
    char id5(){while(_getchar()=='\r');return _last;}
    bool hasNext(){return (_last&&id17())||!feof(_input);}bool id1(){while(hasNext()&&id19()<=' ')_getchar();return hasNext();}

template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');if((_sign=x=='-'))x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');if(_sign)x=-x;}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void id8(F&x){
    for(x=0;(_c=_getchar())<=' ';);
    if((_sign=_c=='-'))_c=_getchar();
    if(_c>='0')for(x=_c-'0';(_c=_getchar())>='0';x=x*10+_c-'0');
    if(_c=='.')for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));
    if(_sign)x=-x;
}
void setLength(int x){if(id11)delete[](id11);id11=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}

    void read(i128&x){_readSigned(x);}void read(ui128&x){_readUnsigned(x);}

template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){id8(x);}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')id5();for(_cur=0;(_c=id5())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!id11)assert(0);read(id11);x=std::string(id11,_cur);}
void readln(std::string &x){if(!id11)assert(0);readln(id11);x=std::string(id11,_cur);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x);
template<class T1,class T2>void read(std::pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(std::complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x){for(auto&&_i:x)read(_i);}
template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(std::forward<Ts>(xs)...);}
void setInput(FILE*file){*(_inputPtr=_inputBuffer)=0;_input=file;}void setInput(const std::string&s){*(_inputPtr=_inputBuffer)=0;_input=fopen(s.c_str(),"r");}
int _flushBuf(){fwrite_unlocked(_outputBuffer,1,_outputPtr,_output);return _outputPtr=0;}void flush(){_flushBuf();fflush(_output);}
int _putchar(char x){return _outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=x,_outputPtr++;}
void id4(char x){_tempOutputBuf[id15++]=x;}void _writeOutput(){for(int _i=0;_i<id15;_putchar(_tempOutputBuf[_i++]));id15=0;}
void _fillBuf(int x){for(int _i=0;_i<x;_i++)_putchar(_fill);}void id13(){for(;_numPtr;id4(_numBuf[--_numPtr]));}
void id16(){int _tempLen=id15;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen);}
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const std::string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
template<class T>void _writeNum(const T&x,int digits){_cnt=0;for(T _y=x;_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';id13();}
template<class F>void id10(const F&x){ull _I=ull(x);ull _F=(x-_I)*_precisionBase+F(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,1);id4('.');_writeNum(_F,_precision);}
void write(const bool&x){if(x)id4('1');else id4('0');id16();}void write(const char&x){id4(x);id16();}
void write(const char*x){int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=x;*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}
void write(const std::string&x){_fillBuf(_width-int(x.length()));for(int _i=0;_i<int(x.length());_putchar(x[_i++]));_fillBuf(-_width-int(x.length()));}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type write(const I&x){
    using UI=typename std::make_unsigned<I>::type;if(x<0){id4('-');_writeNum(UI(-x),1);}else{_writeNum(UI(x),1);}id16();
}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type write(const UI&x){_writeNum(x,1);id16();}
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type write(const F&x){
    if(std::isnan(x)){write("NaN");}else if(std::isinf(x)){write("Inf");}else if(x<0){id4('-');id10(-x);}else{id10(x);}id16();
}

    void write(const i128&x){if(x<0){id4('-');_writeNum(ui128(-x),1);}else{_writeNum(ui128(x),1);}id16();}void write(const ui128&x){_writeNum(x,1);id16();}

template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);
template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(id11)delete[](id11);}};std::unique_ptr<IOManager>id14=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(Ts&&...xs){FILE*_temp=_output;setOutput(_error);write(std::forward<Ts>(xs)...);setOutput(_temp);}
template<class...Ts>void debugln(Ts&&...xs){FILE*_temp=_output;setOutput(_error);writeln(std::forward<Ts>(xs)...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}







template <class T> T addMod(T a, T b, T mod) { T ret = a + b; return ret < mod ? ret : ret - mod; }







template <class T> T subMod(T a, T b, T mod) { T ret = a - b; return 0 <= ret ? ret : ret + mod; }







template <class T> T mulMod(T a, T b, T mod) { return a * b % mod; }

template <const int MAXN, class T, const T MOD, const int OFFSET> struct Hashing {
    T H[MAXN], POW[MAXN], BASE = uniform_int_distribution<T>(MOD / 2, MOD - 2)(rng64);
    void compute(const string &s, T base = -1) {
        if (base == -1) base = BASE;
        int N = int(s.length()); POW[0] = 1; H[N] = 0;
        for (int i = 1; i <= N; i++) POW[i] = mulMod(POW[i - 1], base, MOD);
        for (int i = N - 1; i >= 0; i--) H[i] = addMod(mulMod(H[i + 1], base, MOD), T(s[i] - OFFSET + 1), MOD);
    }
    

    T getHash(int l, int r) { return subMod(H[l], mulMod(H[r], POW[r - l], MOD), MOD); }
    T concat(int l1, int r1, int l2, int r2) { return addMod(getHash(l1, r1), mulMod(getHash(l2, r2), POW[r1 - l1], MOD), MOD); }
};

const int MAXS = 1e6 + 5;
const ll MOD1 = 1e9 + 7, MOD2 = 998244353, MOD3 = 1004535809;

int T;
string S, R, U;
Hashing<MAXS * 2, ll, MOD1, 'a'> H1;
Hashing<MAXS * 2, ll, MOD2, 'a'> H2;
Hashing<MAXS * 2, ll, MOD3, 'a'> H3;

pii getRev(int l, int r) {
    return make_pair(sz(S) + sz(S) - r, sz(S) + sz(S) - l);
}

bool isPal(int l, int r) {
    int l2, r2;
    tie(l2, r2) = getRev(l, r);
    ll id2 = H1.getHash(l, r), id7 = H1.getHash(l2, r2);
    ll id18 = H2.getHash(l, r), id0 = H2.getHash(l2, r2);
    ll id9 = H3.getHash(l, r), id3 = H3.getHash(l2, r2);
    return make_tuple(id2, id18, id9) == make_tuple(id7, id0, id3);
}

int main() {
    

    

    

    setLength(MAXS);
    read(T);
    for (int ti = 0; ti < T; ti++) {
        read(S);
        R = S;
        reverse(R.begin(), R.end());
        U = S + R;
        H1.compute(U);
        H2.compute(U);
        H3.compute(U);
        int len = 0;
        for (int i = 0; i < sz(S) / 2; i++) {
            if (S[i] == S[sz(S) - i - 1]) len++;
            else break;
        }
        int maxLen = len + len, l = len, r = sz(S) - len;
        for (int len2 = 0; len + len + len2 <= sz(S); len2++) if (isPal(len, len + len2) && len + len + len2 > maxLen) {
            maxLen = len + len + len2;
            l = len + len2;
            r = sz(S) - len;
        }
        for (int len2 = 0; len + len + len2 <= sz(S); len2++) if (isPal(sz(S) - len - len2, sz(S) - len) && len + len + len2 > maxLen) {
            maxLen = len + len + len2;
            l = len;
            r = sz(S) - len - len2;
        }
        writeln(S.substr(0, l) + S.substr(r));
    }
    return 0;
}