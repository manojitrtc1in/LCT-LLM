

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
  uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count()),
  uint64_t(__builtin_ia32_rdtsc()),uint64_t(uintptr_t(make_unique<char>().get()))
};
std::mt19937 rng(seq);std::mt19937_64 rng64(seq);const std::size_t RANDOM=std::uniform_int_distribution<std::size_t>(0,std::numeric_limits<std::size_t>::max())(rng64);
struct rand_hash{
  static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
  template<class T>std::size_t operator()(const T&x)const{return splitmix64(std::hash<T>()(x)+RANDOM);}
  template<class T1,class T2>std::size_t operator()(const pair<T1,T2>&p)const{return 31*operator()(p.first)+operator()(p.second);}
};
template<class K,class H=rand_hash,class...Ts>using hashset=__gnu_pbds::gp_hash_table<K,__gnu_pbds::null_type,H,Ts...>;
template<class K,class V,class H=rand_hash,class...Ts>using hashmap=__gnu_pbds::gp_hash_table<K,V,H,Ts...>;
template<class K,class C=std::less<K>,class...Ts>using treeset=__gnu_pbds::tree<K,__gnu_pbds::null_type,C,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update,Ts...>;
template<class K,class V,class C=std::less<K>,class...Ts>using treemap=__gnu_pbds::tree<K,V,C,__gnu_pbds::rb_tree_tag,__gnu_pbds::tree_order_statistics_node_update,Ts...>;
template<class K,class H=rand_hash,class...Ts>using uset=std::unordered_set<K,H,Ts...>;
template<class K,class V,class H=rand_hash,class...Ts>using umap=std::unordered_map<K,V,H,Ts...>;
template<class T>using minpq=std::priority_queue<T,std::vector<T>,std::greater<T>>;template<class T>using maxpq=std::priority_queue<T,std::vector<T>,std::less<T>>;
template<class T,class C=less<T>,class Tag=pairing_heap_tag>using pbdsheap=__gnu_pbds::priority_queue<T,C,Tag>;
template<class T,class Tag=pairing_heap_tag>using minpbdsheap=pbdsheap<T,greater<T>,Tag>;template<class T,class Tag=pairing_heap_tag>using maxpbdsheap=pbdsheap<T,less<T>,Tag>;
template<class T>struct is_iterator{
  template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto has_indirection(int)->decltype(*std::declval<U>(),bool()){return true;}
  template<class>constexpr static bool has_indirection(long){return false;}constexpr static bool value=has_indirection<T>(0);
};

#define INTERACTIVE_INPUT 0
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

template <class T, class Cmp = less<T>, class mask_t = uint32_t>
struct FischerHeunStructure {
  static_assert(is_integral<mask_t>::value, "mask_t must be integral");
  static_assert(is_unsigned<mask_t>::value, "mask_t must be unsigned");
  static constexpr int B = __lg(numeric_limits<mask_t>::max()) + 1;
  int N, M; vector<T> A; vector<mask_t> mask; vector<vector<int>> ST; Cmp cmp;
  int cmpInd(int i, int j) { return cmp(A[i], A[j]) ? j : i; }
  int small(int r, int sz = B) {
    return r - __lg(sz == B ? mask[r] : mask[r] & ((mask_t(1) << sz) - 1));
  }
  template <class F> FischerHeunStructure(int N, F f, Cmp cmp = Cmp())
      : N(N), M(N / B), mask(N), ST(M == 0 ? 0 : __lg(M) + 1, vector<int>(M)),
        cmp(cmp) {
    A.reserve(N); mask_t k = 0; for (int i = 0; i < N; mask[i++] = k |= 1)
      for (A.push_back(f()), k <<= 1; k && cmpInd(i - __lg(k & -k), i) == i;)
        k ^= k & -k;
    for (int i = 0; i < M; i++) ST[0][i] = small(B * (i + 1) - 1);
    for (int i = 0; i < int(ST.size()) - 1; i++) for (int j = 0; j < M; j++)
      ST[i + 1][j] = cmpInd(ST[i][j], ST[i][min(j + (1 << i), M - 1)]);
  }
  template <class It> FischerHeunStructure(It st, It en, Cmp cmp = Cmp())
      : FischerHeunStructure(en - st, [&] { return *st++; }, cmp) {}
  int queryInd(int l, int r) {
    if (r - l + 1 <= B) return small(r, r - l + 1);
    int ql = small(l + B - 1), qr = small(r); l = l / B + 1; r = r / B - 1;
    if (l <= r) {
      int i = __lg(r - l + 1);
      ql = cmpInd(ql, cmpInd(ST[i][l], ST[i][r - (1 << i) + 1]));
    }
    return cmpInd(ql, qr);
  }
  T query(int l, int r) { return A[queryInd(l, r)]; }
};

struct LCA {
  using RMQ = FischerHeunStructure<int, function<bool(int, int)>>;
  int ind; vector<int> root, pre, vert, dep; RMQ FHS;
  template <class Graph>
  void dfs(const Graph &G, int v, int prev, int r, int d) {
    root[v] = r; dep[v] = d; vert[pre[v] = ind++] = v; for (int w : G[v])
      if (w != prev) { dfs(G, w, v, r, d + 1); vert[ind++] = v; }
  }
  template <class Graph> RMQ init(const Graph &G, const vector<int> &roots) {
    ind = 0; if (roots.empty()) {
      for (int v = 0; v < G.V; v++) if (root[v] == -1) dfs(G, v, -1, v, 0);
    } else for (int rt : roots) dfs(G, rt, -1, rt, 0);
    return RMQ(vert.begin(), vert.begin() + ind, [&] (int v, int w) {
                 return dep[v] > dep[w];
               });
  }
  template <class Graph>
  LCA(const Graph &G, const vector<int> &roots = vector<int>())
      : root(G.V, -1), pre(G.V), vert(max(0, G.V * 2 - 1)), dep(G.V),
        FHS(init(G, roots)) {}
  template <class Graph> LCA(const Graph &G, int rt)
      : LCA(G, vector<int>(1, rt)) {}
  int lca(int v, int w) {
    if (pre[v] > pre[w]) swap(v, w);
    return FHS.query(pre[v], pre[w]);
  }
  bool connected(int v, int w) { return root[v] == root[w]; }
  int getDist(int v, int w) { return dep[v] + dep[w] - 2 * dep[lca(v, w)]; }
};

struct GraphStatic {
  int V; vector<int> ST, TO, A, B; GraphStatic(int V) : V(V), ST(V + 1, 0) {}
  void reserveEdges(int maxEdges) {
    TO.reserve(maxEdges); A.reserve(maxEdges); B.reserve(maxEdges);
  }
  void addDiEdge(int from, int to) {
    ST[from]++; A.push_back(from); B.push_back(to);
  }
  void build() {
    partial_sum(ST.begin(), ST.end(), ST.begin()); TO = B;
    for (int e = 0; e < int(A.size()); e++) TO[--ST[A[e]]] = B[e];
  }
  struct Iterator {
    const GraphStatic &G; int i;
    Iterator(const GraphStatic &G, int i) : G(G), i(i) {}
    Iterator &operator ++ () { i++; return *this; }
    int operator * () const { return G.TO[i]; }
    bool operator != (const Iterator &it) const { return i != it.i; }
  };
  struct Adj {
    const GraphStatic &G; int v;
    Adj(const GraphStatic &G, int v) : G(G), v(v) {}
    const Iterator begin() const { return Iterator(G, G.ST[v]); }
    const Iterator end() const { return Iterator(G, G.ST[v + 1]); }
  };
  const Adj operator [] (int v) const { return Adj(*this, v); }
};

int main() {
  

  

  

  int N, Q;
  read(N, Q);
  GraphStatic G(N);
  for (int i = 1; i < N; i++) {
    int p;
    read(p);
    G.addDiEdge(--p, i);
  }
  G.build();
  LCA lca(G, 0);
  auto query = [&] (auto &fhs, int l, int r) {
    return l > r ? -1 : fhs.queryInd(l, r);
  };
  FischerHeunStructure<int, less<int>> preMax(N, [&, i = 0] () mutable {
    return lca.pre[i++];
  });
  FischerHeunStructure<int, greater<int>> preMin(N, [&, i = 0] () mutable {
    return lca.pre[i++];
  });
  for (int i = 0; i < Q; i++) {
    int l, r;
    read(l, r);
    --l; --r;
    int v = query(preMin, l, r), w = query(preMax, l, r);
    int vl = query(preMin, l, v - 1), vr = query(preMin, v + 1, r);
    int vv = vl == -1 ? vr : (vr == -1 ? vl : preMin.cmpInd(vl, vr));
    int wl = query(preMax, l, w - 1), wr = query(preMax, w + 1, r);
    int ww = wl == -1 ? wr : (wr == -1 ? wl : preMax.cmpInd(wl, wr));
    int remv = lca.dep[lca.lca(vv, w)], remw = lca.dep[lca.lca(v, ww)];
    if (remv > remw) writeln(v + 1, remv);
    else writeln(w + 1, remw);
  }
  return 0;
}
