#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
using namespace std;using namespace std::placeholders;using namespace __gnu_pbds;
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
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,_tempOutputPtr=0,_cnt;ull _precisionBase=1000000;
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
template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');_sign=x=='-';if(_sign)x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');if(_sign)x=-x;}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void _readFloatingPoint(F&x){for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));}
void setLength(int x){if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}
#if __SIZEOF_INT128__
    void read(i128&x){_readSigned(x);}void read(ui128&x){_readUnsigned(x);}
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

using T = double; using F = double; const F EPS = 1e-9;
static_assert(is_floating_point<F>::value, "F must be a a floating point type");

struct Point {
    T x, y;
    Point(T x = 0, T y = 0) : x(x), y(y) {}
    F polarRadius() const { return sqrt(x * x + y * y); }
    F theta() const { return atan2(y, x); }
    F angleTo(const Point &that) const { return atan2(that.y - y, that.x - x); }
    static int ccw(const Point &a, const Point &b, const Point &c) { 

        T area2 = (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
        if (area2 < -T(EPS)) return -1;
        else if (area2 > T(EPS)) return +1;
        else return 0;
    }
    static T area2(const Point &a, const Point &b, const Point &c) { return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x); }
    Point rotate(const Point &that, F theta) const { 

        T x = that.x + (this->x - that.x) * cos(theta) - (this->y - that.y) * sin(theta);
        T y = that.y + (this->x - that.x) * sin(theta) + (this->y - that.y) * cos(theta);
        return Point(x, y);
    }
    F distanceTo(const Point &that) const { T dx = x - that.x, dy = y - that.y; return sqrt(dx * dx + dy * dy); }
    T distanceSquaredTo(const Point &that) const { T dx = x - that.x, dy = y - that.y; return dx * dx + dy * dy; }
    bool onSegment(const Point &p, const Point &q) const {
        return abs(distanceTo(p) + distanceTo(q) - p.distanceTo(q)) <= EPS;
    }
    static bool lineSegmentIntersects(const Point &p1, const Point &q1, const Point &p2, const Point &q2) {
        int o1 = Point::ccw(p1, q1, p2), o2 = Point::ccw(p1, q1, q2), o3 = Point::ccw(p2, q2, p1), o4 = Point::ccw(p2, q2, q1);
        if (o1 != o2 && o3 != o4) return true;
        if (o1 == 0 && p2.onSegment(p1, q1)) return true;
        if (o2 == 0 && q2.onSegment(p1, q1)) return true;
        if (o3 == 0 && p1.onSegment(p2, q2)) return true;
        if (o4 == 0 && q1.onSegment(p2, q2)) return true;
        return false;
    }
    static Point lineIntersection(const Point &p1, const Point &q1, const Point &p2, const Point &q2) {
        T A1 = q1.y - p1.y, B1 = p1.x - q1.x, C1 = A1 * p1.x + B1 * p1.y;
        T A2 = q2.y - p2.y, B2 = p2.x - q2.x, C2 = A2 * p2.x + B2 * p2.y, det = A1 * B2 - A2 * B1;
        if (abs(det) <= T(EPS)) throw runtime_error("The lines do not intersect or are collinear");
        return Point((B2 * C1 - B1 * C2) / det, (A1 * C2 - A2 * C1) / det);
    }
    int compareXThenY(const Point &that) const {
        if (x < that.x - T(EPS)) return -1;
        if (x > that.x + T(EPS)) return +1;
        if (y < that.y - T(EPS)) return -1;
        if (y > that.y + T(EPS)) return +1;
        return 0;
    }
    int compareYThenX(const Point &that) const {
        if (y < that.y - T(EPS)) return -1;
        if (y > that.y + T(EPS)) return +1;
        if (x < that.x - T(EPS)) return -1;
        if (x > that.x + T(EPS)) return +1;
        return 0;
    }
    bool operator == (const Point &that) const { return abs(x - that.x) <= T(EPS) && abs(y - that.y) <= T(EPS); }
    bool operator != (const Point &that) const { return !(*this == that); }
    static bool xOrderLt(const Point &p, const Point &q) { return p.x < q.x - T(EPS); }
    static bool xOrderLe(const Point &p, const Point &q) { return !xOrderLt(q, p); }
    static bool xOrderGt(const Point &p, const Point &q) { return xOrderLt(q, p); }
    static bool xOrderGe(const Point &p, const Point &q) { return !xOrderLt(p, q); }
    static bool yOrderLt(const Point &p, const Point &q) { return p.y < q.y - T(EPS); }
    static bool yOrderLe(const Point &p, const Point &q) { return !yOrderLt(q, p); }
    static bool yOrderGt(const Point &p, const Point &q) { return yOrderLt(q, p); }
    static bool yOrderGe(const Point &p, const Point &q) { return !yOrderLt(p, q); }
    static bool rOrderLt(const Point &p, const Point &q) { return (p.x * p.x + p.y * p.y) < (q.x * q.x + q.y * q.y) - T(EPS); }
    static bool rOrderLe(const Point &p, const Point &q) { return !rOrderLt(q, p); }
    static bool rOrderGt(const Point &p, const Point &q) { return rOrderLt(q, p); }
    static bool rOrderGe(const Point &p, const Point &q) { return !rOrderLt(p, q); }
    bool polarOrderLt(const Point &p, const Point &q) const { return ccw(*this, p, q) > 0; }
    bool polarOrderLe(const Point &p, const Point &q) const { return !polarOrderLt(q, p); }
    bool polarOrderGt(const Point &p, const Point &q) const { return polarOrderLt(q, p); }
    bool polarOrderGe(const Point &p, const Point &q) const { return !polarOrderLt(p, q); }
    bool atan2OrderLt(const Point &p, const Point &q) const { return angleTo(p) < angleTo(q) - T(EPS); }
    bool atan2OrderLe(const Point &p, const Point &q) const { return !atan2OrderLe(q, p); }
    bool atan2OrderGt(const Point &p, const Point &q) const { return atan2OrderLe(q, p); }
    bool atan2OrderGe(const Point &p, const Point &q) const { return !atan2OrderLe(p, q); }
    bool distanceToOrderLt(const Point &p, const Point &q) const { return distanceSquaredTo(p) < distanceSquaredTo(q) - T(EPS); }
    bool distanceToOrderLe(const Point &p, const Point &q) const { return !distanceToOrderLt(q, p); }
    bool distanceToOrderGt(const Point &p, const Point &q) const { return distanceToOrderLt(q, p); }
    bool distanceToOrderGe(const Point &p, const Point &q) const { return !distanceToOrderLt(p, q); }
};

template <const int MAXN, const bool ONE_INDEXED> struct SegmentTree_SAM_RQ {
    using Data = pair<Point, ld>; using Lazy = pair<Point, ld>; int N; Data T[2 * MAXN];
    const Data vdef = make_pair(Point(0, 0), 0); 

    const Data qdef = make_pair(Point(0, 0), 0); 

    

    Data merge(const Data &l, const Data &r) {
        return make_pair(Point(l.first.x + r.first.x, l.first.y + r.first.y).rotate(l.first, l.second), l.second + r.second);
    }
    Data applyLazy(const Data &l, const Lazy &r) {
        return r;
    }
    template <class It> void init(It st, It en) {
        N = en - st; for (int i = 0; i < N; i++) T[N + i] = *(st + i);
        for (int i = N - 1; i > 0; i--) T[i] = merge(T[i << 1], T[i << 1 | 1]);
    }
    void init(int size) {
        N = size; for (int i = 0; i < N; i++) T[N + i] = vdef;
        for (int i = N - 1; i > 0; i--) T[i] = merge(T[i << 1], T[i << 1 | 1]);
    }
    void update(int i, const Lazy &v) { for (i += N - ONE_INDEXED, T[i] = applyLazy(T[i], v); i >>= 1;) T[i] = merge(T[i << 1], T[i << 1 | 1]); }
    Data query(int l, int r) {
        Data ql = qdef, qr = qdef;
        for (l += N - ONE_INDEXED, r += N - ONE_INDEXED; l <= r; l >>= 1, r >>= 1) {
            if (l & 1) ql = merge(ql, T[l++]);
            if (!(r & 1)) qr = merge(T[r--], qr);
        }
        return merge(ql, qr);
    }
};

const int MAXN = 3e5 + 5;
const ld PI = acos(-1);

int N, M;
SegmentTree_SAM_RQ<MAXN, 0> ST;
pair<Point, ld> D[MAXN];

int main() {
    

    

    

    read(N, M);
    setPrecision(9);
    for (int i = 0; i < N; i++) {
        D[i].first.x = 1;
        D[i].first.y = 0;
        D[i].second = 0;
    }
    ST.init(D, D + N);
    for (int i = 0; i < M; i++) {
        int t, j;
        ld v;
        read(t, j, v);
        --j;
        ld len = D[j].first.polarRadius();
        ld ang = D[j].first.theta();
        if (t == 1) len += v;
        else ang -= v * PI / 180.0;
        D[j].first.x = len * cos(ang);
        D[j].first.y = len * sin(ang);
        D[j].second = ang;
        ST.update(j, D[j]);
        Point ans = ST.query(0, N - 1).first;
        writeln(ans.x, ans.y);
    }
    return 0;
}
