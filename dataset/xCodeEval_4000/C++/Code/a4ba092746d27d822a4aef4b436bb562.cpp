

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
template<class T,class...Args>std::unique_ptr<T>_make_unique(Args&&...args){return std::unique_ptr<T>(new T(std::forward<Args>(args)...));}
#define make_unique _make_unique
std::seed_seq seq{
  (uint64_t)std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count(),
  (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
std::mt19937 rng(seq);std::mt19937_64 rng64(seq);const std::size_t RANDOM=std::uniform_int_distribution<std::size_t>(0,std::numeric_limits<std::size_t>::max())(rng64);
template<class T,class H=std::hash<T>>struct rand_hash{
  static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
  std::size_t operator()(const T&x)const{return splitmix64(H()(x)+RANDOM);}
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
  std::size_t operator()(const std::pair<T1,T2>&p)const{return 31*H1()(p.first)+H2()(p.second);}
};
template<class T>struct is_iterator{
  template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*std::declval<U>(),bool()){return true;}
  template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
};

#define INTERACTIVE_INPUT 1
constexpr const int _bufferSize=1<<16,_maxNumLength=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last=-1,_sign,*_tempInputBuf=nullptr,_numBuf[_maxNumLength],_tempOutputBuf[_maxNumLength],_fill=' ';
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
  char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
  char _getcharskipr(){while(_getchar()=='\r');return _last;}
#endif
template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');if((_sign=x=='-'))x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');if(_sign)x=-x;}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void _readFloatingPoint(F&x){
  for(x=0;(_c=_getchar())<=' ';);
  if((_sign=_c=='-'))_c=_getchar();
  if(_c>='0')for(x=_c-'0';(_c=_getchar())>='0';x=x*10+_c-'0');
  if(_c=='.')for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));
  if(_sign)x=-x;
}
void setLength(int x){if(_tempInputBuf)delete[](_tempInputBuf);_tempInputBuf=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}
#if __SIZEOF_INT128__
  void read(i128&x){_readSigned(x);}void read(ui128&x){_readUnsigned(x);}
#endif
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){_readFloatingPoint(x);}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')_getcharskipr();for(_cur=0;(_c=_getcharskipr())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!_tempInputBuf)assert(0);read(_tempInputBuf);x=std::string(_tempInputBuf,_cur);}
void readln(std::string &x){if(!_tempInputBuf)assert(0);readln(_tempInputBuf);x=std::string(_tempInputBuf,_cur);}
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
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);
template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};std::unique_ptr<IOManager>iomanager=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(Ts&&...xs){FILE*_temp=_output;setOutput(_error);write(std::forward<Ts>(xs)...);setOutput(_temp);}
template<class...Ts>void debugln(Ts&&...xs){FILE*_temp=_output;setOutput(_error);writeln(std::forward<Ts>(xs)...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}

template <class IndexType, const bool LAZY, const bool PERSISTENT,
          class Combine> struct DynamicSegmentTree {
#define lazy_def template <const bool _ = LAZY> typename enable_if<_>::type
#define agg_def template <const bool _ = LAZY> typename enable_if<!_>::type
  static_assert(is_integral<IndexType>::value, "IndexType must be integeral");
  using Data = typename Combine::Data; using Lazy = typename Combine::Lazy;
  template <const bool _, const int __ = 0> struct Node {
    Data val; int l, r; Node(const Data &val) : val(val), l(-1), r(-1) {}
  };
  template <const int __> struct Node<true, __> {
    Data val; Lazy lz; int l, r;
    Node(const Data &val) : val(val), lz(Combine().ldef), l(-1), r(-1) {}
  };
  Combine C; IndexType N; vector<int> roots; vector<Node<LAZY>> TR;
  int makeNode(int cp, IndexType tl, IndexType tr) {
    if (~cp) TR.push_back(TR[cp]);
    else TR.emplace_back(C.getSegmentVdef(tr - tl + 1));
    return int(TR.size()) - 1;
  }
  lazy_def apply(int x, IndexType tl, IndexType tr, const Lazy &v) {
    TR[x].val = C.applyLazy(TR[x].val, C.getSegmentVal(v, tr - tl + 1));
    TR[x].lz = C.mergeLazy(TR[x].lz, v);
  }
  agg_def apply(int x, IndexType, IndexType, const Lazy &v) {
    TR[x].val = C.applyLazy(TR[x].val, v);
  }
  lazy_def propagate(int x, IndexType tl, IndexType tr) {
    if (TR[x].lz != C.ldef) {
      IndexType m = tl + (tr - tl) / 2; if (!~TR[x].l || PERSISTENT) {
        int nl = makeNode(TR[x].l, tl, m); TR[x].l = nl;
      }
      if (!~TR[x].r || PERSISTENT) {
        int nr = makeNode(TR[x].r, m + 1, tr); TR[x].r = nr;
      }
      apply(TR[x].l, tl, m, TR[x].lz); apply(TR[x].r, m + 1, tr, TR[x].lz);
      TR[x].lz = C.ldef;
    }
  }
  agg_def propagate(int, IndexType, IndexType) {}
  template <class F> int build(IndexType tl, IndexType tr, F &f) {
    int x = makeNode(-1, tl, tr);
    if (tl == tr) { TR[x].val = f(); return x; }
    IndexType m = tl + (tr - tl) / 2; int nl = build(tl, m, f); TR[x].l = nl;
    int nr = build(m + 1, tr, f); TR[x].r = nr;
    TR[x].val = C.merge(TR[TR[x].l].val, TR[TR[x].r].val); return x;
  }
  int update(int y, IndexType tl, IndexType tr, IndexType l, IndexType r,
             const Lazy &v, int trSz) {
    int x = !~y || (PERSISTENT && y < trSz) ? makeNode(y, tl, tr) : y;
    if (l <= tl && tr <= r) { apply(x, tl, tr, v); return x; }
    propagate(x, tl, tr); IndexType m = tl + (tr - tl) / 2;
    if (tl <= r && l <= m) {
      int nl = update(TR[x].l, tl, m, l, r, v, trSz); TR[x].l = nl;
    }
    if (m + 1 <= r && l <= tr) {
      int nr = update(TR[x].r, m + 1, tr, l, r, v, trSz); TR[x].r = nr;
    }
    TR[x].val = C.merge(~TR[x].l ? TR[TR[x].l].val
                                 : C.getSegmentVdef(m - tl + 1),
                        ~TR[x].r ? TR[TR[x].r].val : C.getSegmentVdef(tr - m));
    return x;
  }
  Data query(int x, IndexType tl, IndexType tr, IndexType l, IndexType r) {
    if (r < tl || tr < l) return C.qdef;
    if (!~x) return C.getSegmentVdef(tr - tl + 1);
    if (l <= tl && tr <= r) return TR[x].val;
    propagate(x, tl, tr); IndexType m = tl + (tr - tl) / 2;
    return C.merge(query(TR[x].l, tl, m, l, r),
                   query(TR[x].r, m + 1, tr, l, r));
  }
  template <class F> DynamicSegmentTree(IndexType N, F f) : N(N) {
    if (N > 0) {
      reserveNodes(N * 2 - 1); roots.push_back(build(0, N - 1, f));
    }
  }
  template <class It> DynamicSegmentTree(It st, It en)
      : DynamicSegmentTree(en - st, [&] { return *st++; }) {}
  DynamicSegmentTree(IndexType N) : N(N) { roots.push_back(-1); }
  lazy_def update(IndexType l, IndexType r, const Lazy &v, bool newRoot) {
    int nr = update(roots.back(), 0, N - 1, l, r, v, TR.size());
    if (newRoot) roots.push_back(nr);
    else roots.back() = nr;
  }
  void update(IndexType i, const Lazy &v, bool newRoot) {
    int nr = update(roots.back(), 0, N - 1, i, i, v, TR.size());
    if (newRoot) roots.push_back(nr);
    else roots.back() = nr;
  }
  Data query(IndexType l, IndexType r, int rootInd = -1) {
    return query(~rootInd ? roots[rootInd] : roots.back(), 0, N - 1, l, r);
  }
  void revert(int rootInd) { roots.push_back(roots[rootInd]); }
  void reserveNodes(int k) { TR.reserve(k); }
#undef lazy_def
#undef agg_def
};

struct Combine {
  using Data = int;
  using Lazy = int;
  const Data qdef = 0;
  Data merge(const Data &l, const Data &r) const { return max(l, r); }
  Data applyLazy(const Data &l, const Lazy &r) const { return min(l, r); }
  template <class IndexType> Data getSegmentVdef(IndexType k) const { return INT_INF; }
};

int main() {
  

  

  

  int N, M, K;
  read(N, M, K);
  vector<pair<pii, int>> seg(K);
  DynamicSegmentTree<int, false, true, Combine> ST(N);
  read(seg);
  sort(seg.begin(), seg.end(), greater<pair<pii, int>>());
  for (auto &&s : seg) {
    --s.second;
    ST.update(s.second, s.first.second, true);
  }
  for (int i = 0; i < M; i++) {
    int a, b, x, y;
    read(a, b, x, y);
    writeln(ST.query(--a, --b, upper_bound(seg.begin(), seg.end(), make_pair(make_pair(x, 0), 0), greater<pair<pii, int>>()) - seg.begin()) <= y ? "yes" : "no");
    flush();
  }
  return 0;
}
