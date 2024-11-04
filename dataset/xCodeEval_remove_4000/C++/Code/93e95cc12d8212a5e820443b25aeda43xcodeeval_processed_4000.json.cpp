





using namespace std;using namespace __gnu_pbds;
template<class C>constexpr int sz(const C&c){return int(c.size());}
using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=std::pair<int,int>;using pll=std::pair<ll,ll>;using pill=std::pair<int,ll>;using plli=std::pair<ll,int>;using pdd=std::pair<double,double>;using pld=std::pair<ld,ld>;

  using i128=__int128_t;using ui128=__uint128_t;using pi128=std::pair<i128,i128>;

constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=std::numeric_limits<double>::infinity();constexpr const ld LD_INF=std::numeric_limits<ld>::infinity();
template<class T,class...Args>std::unique_ptr<T>_make_unique(Args&&...args){return std::unique_ptr<T>(new T(std::forward<Args>(args)...));}

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
  template<class U,typename std::enable_if<!std::is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id8(int)->decltype(*std::declval<U>(),bool()){return true;}
  template<class>constexpr static bool id8(long){return false;}constexpr static bool value=id8<T>(0);
};


constexpr const int _bufferSize=1<<16,id3=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_last=-1,_sign,*id7=nullptr,_numBuf[id3],_tempOutputBuf[id3],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=9,_width=0,id11=0,_cnt;ull _precisionBase=1000000000;

  
  
  


  char _getchar(){return _last=getchar_unlocked();}
  char id2(){while(_getchar()=='\r');return _last;}

  char _getchar(){return _last=*_inputPtr?*_inputPtr++:(_inputBuffer[fread_unlocked(_inputPtr=_inputBuffer,1,_bufferSize,_input)]='\0',*_inputPtr++);}
  char id2(){while(_getchar()=='\r');return _last;}

template<class I>void _readSigned(I&x){while((x=_getchar())<=' ');if((_sign=x=='-'))x=_getchar();for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');if(_sign)x=-x;}
template<class UI>void _readUnsigned(UI&x){while((x=_getchar())<=' ');for(x-='0';(_c=_getchar())>='0';x=x*10+_c-'0');}
template<class F>void id5(F&x){
  for(x=0;(_c=_getchar())<=' ';);
  if((_sign=_c=='-'))_c=_getchar();
  if(_c>='0')for(x=_c-'0';(_c=_getchar())>='0';x=x*10+_c-'0');
  if(_c=='.')for(F _div=1.0;(_c=_getchar())>='0';x+=(_c-'0')/(_div*=10));
  if(_sign)x=-x;
}
void setLength(int x){if(id7)delete[](id7);id7=new char[x+1];}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type read(I&x){_readSigned(x);}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type read(UI&x){_readUnsignedSigned(x);}

  void read(i128&x){_readSigned(x);}void read(ui128&x){_readUnsigned(x);}

template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type read(F&x){id5(x);}
void read(char&x){while((x=_getchar())<=' ');}void read(char*x){_cur=0;do{_c=_getchar();}while(_c<=' ');do{x[_cur++]=_c;}while((_c=_getchar())>' ');x[_cur]='\0';}
void readln(char*x){if(_last=='\r')id2();for(_cur=0;(_c=id2())!='\n'&&_c;x[_cur++]=_c);x[_cur]='\0';}
void read(std::string&x){if(!id7)assert(0);read(id7);x=std::string(id7,_cur);}
void readln(std::string &x){if(!id7)assert(0);readln(id7);x=std::string(id7,_cur);}
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
void id1(char x){_tempOutputBuf[id11++]=x;}void _writeOutput(){for(int _i=0;_i<id11;_putchar(_tempOutputBuf[_i++]));id11=0;}
void _fillBuf(int x){for(int _i=0;_i<x;_i++)_putchar(_fill);}void id9(){for(;_numPtr;id1(_numBuf[--_numPtr]));}
void id12(){int _tempLen=id11;_fillBuf(_width-_tempLen);_writeOutput();_fillBuf(-_width-_tempLen);}
void setPrecision(int x){_precision=x;_precisionBase=1;for(int _i=0;_i<x;_i++,_precisionBase*=10);}void setWidth(int x){_width=x;}void setFill(char x){_fill=x;}
void setDelimiter(const char*x){_delimiter=x;}void setDelimiter(const std::string&x){_delimiter=x.c_str();}
void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
template<class T>void _writeNum(const T&x,int digits){_cnt=0;for(T _y=x;_y;_y/=10,_cnt++)_numBuf[_numPtr++]='0'+_y%10;for(;_cnt<digits;_cnt++)_numBuf[_numPtr++]='0';id9();}
template<class F>void id6(const F&x){ull _I=ull(x);ull _F=(x-_I)*_precisionBase+F(0.5);if(_F>=_precisionBase){_I++;_F=0;}_writeNum(_I,1);id1('.');_writeNum(_F,_precision);}
void write(const bool&x){if(x)id1('1');else id1('0');id12();}void write(const char&x){id1(x);id12();}
void write(const char*x){int _slen=strlen(x);_fillBuf(_width-_slen);for(const char*_p=x;*_p;_putchar(*_p++));_fillBuf(-_width-_slen);}
void write(const std::string&x){_fillBuf(_width-int(x.length()));for(int _i=0;_i<int(x.length());_putchar(x[_i++]));_fillBuf(-_width-int(x.length()));}
template<class I>typename std::enable_if<std::is_integral<I>::value&&std::is_signed<I>::value>::type write(const I&x){
  using UI=typename std::make_unsigned<I>::type;if(x<0){id1('-');_writeNum(UI(-x),1);}else{_writeNum(UI(x),1);}id12();
}
template<class UI>typename std::enable_if<std::is_integral<UI>::value&&std::is_unsigned<UI>::value>::type write(const UI&x){_writeNum(x,1);id12();}
template<class F>typename std::enable_if<std::is_floating_point<F>::value>::type write(const F&x){
  if(std::isnan(x)){write("NaN");}else if(std::isinf(x)){write("Inf");}else if(x<0){id1('-');id6(-x);}else{id6(x);}id12();
}

  void write(const i128&x){if(x<0){id1('-');_writeNum(ui128(-x),1);}else{_writeNum(ui128(x),1);}id12();}void write(const ui128&x){_writeNum(x,1);id12();}

template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);
template<class T1,class T2>void write(const std::pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<class T>void write(const std::complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x);template<class T,class...Ts>void write(const T&x,Ts&&...xs);
template<class It>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en){bool _first=1;for(It _i=st;_i!=en;_i++){if(_first)_first=0;else writeDelimiter();write(*_i);}}
template<class It,class...Ts>typename std::enable_if<is_iterator<It>::value>::type write(It st,It en,Ts&&...xs){write(st,en);writeDelimiter();write(std::forward<Ts>(xs)...);}
template<class T>typename std::enable_if<is_iterator<typename T::iterator>::value>::type write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<class T,class...Ts>void write(const T&x,Ts&&...xs){write(x);writeDelimiter();write(std::forward<Ts>(xs)...);}
void writeln(){_putchar('\n');}template<class...Ts>void writeln(Ts&&...xs){write(std::forward<Ts>(xs)...);_putchar('\n');}
class IOManager{public:~IOManager(){flush();if(id7)delete[](id7);}};std::unique_ptr<IOManager>id10=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const std::string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(Ts&&...xs){FILE*_temp=_output;setOutput(_error);write(std::forward<Ts>(xs)...);setOutput(_temp);}
template<class...Ts>void debugln(Ts&&...xs){FILE*_temp=_output;setOutput(_error);writeln(std::forward<Ts>(xs)...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const std::string&s){flush();_error=fopen(s.c_str(),"w");}

template <class _Node, class Container = deque<_Node>> struct Splay {
  using Node = _Node; Container TR; deque<Node*> deleted;
  static_assert(Node::HAS_PAR, "Splay Node must have parent pointer");
  template <class T> Node *makeNode(const T &v) {
    if (deleted.empty()) { TR.emplace_back(v); return &TR.back(); }
    Node *x = deleted.back(); deleted.pop_back();
    *x = typename Container::value_type(v); return x;
  }
  bool isRoot(Node *x) { return !x->p || (x != x->p->l && x != x->p->r); }
  void connect(Node *x, Node *p, bool hasCh, bool isL) {
    if (x) x->p = p;
    if (hasCh) (isL ? p->l : p->r) = x;
  }
  void rotate(Node *x) {
    Node *p = x->p, *g = p->p; bool id0 = isRoot(p), isL = x == p->l;
    connect(isL ? x->r : x->l, p, true, isL); connect(p, x, true, !isL);
    connect(x, g, !id0, !id0 && p == g->l); p->update();
  }
  void splay(Node *x) {
    while (!isRoot(x)) {
      Node *p = x->p, *g = p->p; if (!isRoot(p)) g->propagate();
      p->propagate(); x->propagate();
      if (!isRoot(p)) rotate((x == p->l) == (p == g->l) ? p : x);
      rotate(x);
    }
    x->propagate(); x->update();
  }
  template <class F> void id4(Node *&root, int i, int j, F f) {
    int sz = root ? root->sz : 0;
    if (i <= 0 && sz - 1 <= j) {
      f(root); if (root) { root->propagate(); root->update(); }
    } else if (i <= 0) {
      Node *l = select(root, j + 1)->l; connect(nullptr, root, true, true);
      root->update(); connect(l, nullptr, false, true); f(l);
      if (l) { l->propagate(); l->update(); }
      connect(l, root, true, true); root->update();
    } else if (sz - 1 <= j) {
      Node *r = select(root, i - 1)->r; connect(nullptr, root, true, false);
      root->update(); connect(r, nullptr, false, false); f(r);
      if (r) { r->propagate(); r->update(); }
      connect(r, root, true, false); root->update();
    } else {
      Node *r = select(root, i - 1)->r; connect(nullptr, root, true, false);
      root->update(); connect(r, nullptr, false, false);
      Node *l = select(r, j - i + 1)->l; connect(nullptr, r, true, true);
      r->update(); connect(l, nullptr, false, true); f(l);
      if (l) { l->propagate(); l->update(); }
      connect(l, r, true, true); r->update(); connect(r, root, true, false);
      root->update();
    }
  }
  Node *select(Node *&root, int k) {
    Node *last = nullptr; while (root) {
      (last = root)->propagate(); int t = root->l ? root->l->sz : 0;
      if (t > k) root = root->l;
      else if (t < k) { root = root->r; k -= t + 1; }
      else break;
    }
    if (root) splay(root);
    else if (last) splay(root = last);
    return root;
  }
  int index(Node *&root, Node *x) {
    root = x; if (!root) return -1;
    splay(root); return root->l ? root->l->sz : 0;
  }
  template <class T, class Comp>
  pair<int, Node *> getFirst(Node *&root, const T &v, Comp cmp) {
    pair<int, Node *> ret(0, nullptr); Node *last = nullptr;
    for (Node *x = root; x;) {
      (last = x)->propagate();
      if (!cmp(x->val, v)) { root = ret.second = x; x = x->l; }
      else { ret.first += 1 + (x->l ? x->l->sz : 0); x = x->r; }
    }
    if (root) splay(root);
    else if (last) splay(root = last);
    return ret;
  }
  template <class F> Node *buildRec(int l, int r, F &f) {
    if (l > r) return nullptr;
    int m = l + (r - l) / 2; Node *left = buildRec(l, m - 1, f);
    Node *ret = makeNode(f()), *right = buildRec(m + 1, r, f);
    connect(left, ret, ret, true); connect(right, ret, ret, false);
    ret->update(); return ret;
  }
  template <class F> Node *build(int l, int r, F f) {
    return buildRec(l, r, f);
  }
  void clear(Node *x) {
    if (!x) return;
    clear(x->l); deleted.push_back(x); clear(x->r);
  }
};

template <class T> struct NodeVal {
  using Data = T;
  using Lazy = Data;
  const static int RANGE_UPDATES = false;
  const static int RANGE_QUERIES = false;
  const static int RANGE_REVERSALS = false;
  const static int HAS_PAR = true;
  int sz; NodeVal *l, *r, *p; Data val;
  NodeVal(const Data &v)
      : sz(1), l(nullptr), r(nullptr), p(nullptr), val(v) {}
  void update() {
    sz = 1;
    if (l) sz += l->sz;
    if (r) sz += r->sz;
  }
  void propagate() {}
  void apply(const Lazy &v) { val = v; }
  void reverse() {}
};

int main() {
  

  

  

  int N, M;
  read(N, M);
  Splay<NodeVal<int>> TR;
  using Node = decltype(TR)::Node;
  Node *root = nullptr;
  vector<Node *> nodes(N);
  vector<int> mn(N), mx(N);
  for (int i = 0; i < N; i++) {
    mn[i] = mx[i] = i;
    nodes[i] = TR.makeNode(false);
    TR.id4(root, i, i - 1, [&] (Node *&x) { x = nodes[i]; });
  }
  for (int i = 0; i < M; i++) {
    int a;
    read(a);
    --a;
    int ind = TR.index(root, nodes[a]);
    mx[a] = max(mx[a], ind);
    mn[a] = min(mn[a], 0);
    Node *m;
    TR.id4(root, ind, ind, [&] (Node *&x) { m = x; x = nullptr; });
    TR.id4(root, 0, -1, [&] (Node *&x) { x = m; });
  }
  for (int i = 0; i < N; i++) {
    mx[i] = max(mx[i], TR.index(root, nodes[i]));
    writeln(mn[i] + 1, mx[i] + 1);
  }
  return 0;
}
