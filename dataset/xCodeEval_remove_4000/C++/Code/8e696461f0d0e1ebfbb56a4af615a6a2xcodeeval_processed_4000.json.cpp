



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
    template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id7(int)->decltype(*std::declval<U>(),bool()){return true;}
    template<class>constexpr static bool id7(long){return false;}constexpr static bool value=id7<T>(0);
};


constexpr const int _bufferSize=1<<16,id3=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last,_sign,*id6=nullptr,_numBuf[id3],_tempOutputBuf[id3],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=9,_width=0,id10=0,_cnt;ull _precisionBase=1000000000;

    
    
    


    char _getchar(){return _last=getchar_unlocked();}
    char id2(){while(_getchar()=='\r');return _last;}

    char id13(){return*_inputPtr?*_inputPtr:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr);}
    char id12(){while(id13()=='\r')_last=*_inputPtr++;return id13();}
    char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
    char id2(){while(_getchar()=='\r');return _last;}
    bool hasNext(){return (_last&&id12())||!feof(_input);}bool id0(){while(hasNext()&&id13()<=' ')_getchar();return hasNext();}

template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');_sign=x=='-';if(_sign)x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void id4(F&x){for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));}
void setLength(int x){if(id6)delete[](id6);id6=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);if(_sign)x=-x;}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}

    void read(i128&x){_readSigned(x);if(_sign)x=-x;}void read(ui128&x){_readUnsigned(x);}

template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){_readSigned(x);if(_c=='.')id4(x);if(_sign)x=-x;}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')id2();for(_cur=0;(_c=id2())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!id6)assert(0);read(id6);x=std::string(id6,_cur);}
void readln(std::string &x){if(!id6)assert(0);readln(id6);x=std::string(id6,_cur);}
template<class T1,class T2>void read(std::pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(std::complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type read(T&x){for(auto&&_i:x)read(_i);}
template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(std::forward<Ts>(xs)...);}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const std::string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}
int _flushBuf(){fwrite_unlocked(_outputBuffer,1,_outputPtr,_output);return _outputPtr=0;}void flush(){_flushBuf();fflush(_output);}
int _putchar(char x){return _outputBuffer[_outputPtr==_bufferSize?_flushBuf():_outputPtr]=x,_outputPtr++;}
void id1(char x){_tempOutputBuf[id10++]=x;}void _writeOutput(){for(int _i=0;_i<id10;_putchar(_tempOutputBuf[_i++]));id10=0;}
void _fillBuf(int x){for(int _i=0;_i<x;_i++)_putchar(_fill);}void id8(){for(;_numPtr;id1(_numBuf[--_numPtr]));}
void id11(){int _tempLen=id10;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen);}
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const std::string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
template<class T>void _writeNum(const T&x,int digits){_cnt=0;for(T _y=x;_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';id8();}
template<class F>void id5(const F&x){ull _I=ull(x);ull _F=(x-_I)*_precisionBase+F(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,1);id1('.');_writeNum(_F,_precision);}
void write(const bool&x){if(x)id1('1');else id1('0');id11();}void write(const char&x){id1(x);id11();}
void write(const char*x){int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=x;*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}
void write(const std::string&x){_fillBuf(_width-int(x.length()));for(int _i=0;_i<int(x.length());_putchar(x[_i++]));_fillBuf(-_width-int(x.length()));}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type write(const I&x){
    using UI=typename std::make_unsigned<I>::type;if(x<0){id1('-');_writeNum(UI(-x),1);}else{_writeNum(UI(x),1);}id11();
}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type write(const UI&x){_writeNum(x,1);id11();}
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type write(const F&x){
    if(std::isnan(x)){write("NaN");}else if(std::isinf(x)){write("Inf");}else if(x<0){id1('-');id5(-x);}else{id5(x);}id11();
}

    void write(const i128&x){if(x<0){id1('-');_writeNum(ui128(-x),1);}else{_writeNum(ui128(x),1);}id11();}void write(const ui128&x){_writeNum(x,1);id11();}

template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(id6)delete[](id6);}};std::unique_ptr<IOManager>id9=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXN, const bool id14> struct UnionFindUndo {
    int UF[MAXN], cnt; vector<pair<pair<int, int>, int>> history;
    void init(int N) { cnt = N; fill(UF, UF + N + id14, -1); }
    void clearHistory() { history.clear(); }
    int find(int v) { return UF[v] < 0 ? v : find(UF[v]); }
    bool join(int v, int w) {
        if ((v = find(v)) == (w = find(w))) return false;
        if (UF[v] > UF[w]) swap(v, w);
        history.emplace_back(make_pair(v, w), UF[w]); UF[v] += UF[w]; UF[w] = v; cnt--; return true;
    }
    void undo() {
        int v = history.back().first.first, w = history.back().first.second, ufw = history.back().second;
        history.pop_back(); UF[w] = ufw; UF[v] -= UF[w]; cnt++;
    }
    bool connected(int v, int w) { return find(v) == find(w); }
    int getSize(int v) { return -UF[find(v)]; }
};

const int MAXNM = 2e5 + 5, BSZ = 1000;

int N, M, type[MAXNM], eind[MAXNM * 2], aind[MAXNM];
bool active[MAXNM * 2], changed[MAXNM * 2];
pii E[MAXNM * 2], F[MAXNM * 2], A[MAXNM];
UnionFindUndo<MAXNM, 0> uf;

int main() {
    

    

    

    read(N, M);
    for (int i = 0; i < M; i++) {
        read(type[i], E[i * 2]);
        --E[i * 2].first;
        --E[i * 2].second;
        E[i * 2 + 1] = make_pair((E[i * 2].first + 1) % N, (E[i * 2].second + 1) % N);
        for (int j = 0; j < 2; j++) if (E[i * 2 + j].first > E[i * 2 + j].second) swap(E[i * 2 + j].first, E[i * 2 + j].second);
    }
    copy(E, E + M * 2, F);
    sort(F, F + M * 2);
    int U = unique(F, F + M * 2) - F;
    for (int i = 0; i < M * 2; i++) eind[i] = lower_bound(F, F + U, E[i]) - F;
    int last = 0;
    uf.init(N);
    for (int st = 0; st < M; st += BSZ) {
        int en = min(M, st + BSZ);
        fill(active, active + U, false);
        fill(changed, changed + U, false);
        for (int i = 0; i < st; i++) if (type[i] == 1) active[aind[i]] ^= true;
        for (int i = st; i < en; i++) if (type[i] == 1) changed[eind[i * 2]] = changed[eind[i * 2 + 1]] = true;
        vector<int> changedInd;
        for (int i = 0; i < U; i++) {
            if (changed[i]) changedInd.push_back(i);
            else if (active[i]) uf.join(F[i].first, F[i].second);
        }
        for (int i = st; i < en; i++) {
            A[i] = E[i * 2 + last];
            if (type[i] == 1) {
                aind[i] = eind[i * 2 + last];
                active[aind[i]] ^= true;
            } else {
                int curSize = uf.history.size();
                for (int j : changedInd) if (active[j]) uf.join(F[j].first, F[j].second);
                write(last = uf.connected(A[i].first, A[i].second));
                while (int(uf.history.size()) > curSize) uf.undo();
            }
        }
        while (!uf.history.empty()) uf.undo();
    }
    writeln();
    return 0;
}
