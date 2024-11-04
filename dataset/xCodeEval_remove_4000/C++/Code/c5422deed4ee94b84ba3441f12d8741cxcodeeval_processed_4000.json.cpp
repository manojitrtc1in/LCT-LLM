





using namespace std;using namespace __gnu_pbds;











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





seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);const size_t RANDOM=uniform_int_distribution<size_t>(0,(numeric_limits<size_t>::max)())(rng64);
template<class T,class H=hash<T>>struct rand_hash{
    static uint64_t splitmix64(uint64_t x){x+=0x9e3779b97f4a7c15;x=(x^(x>>30))*0xbf58476d1ce4e5b9;x=(x^(x>>27))*0x94d049bb133111eb;return x^(x>>31);}
    size_t operator()(const T&x)const{return splitmix64(H{}(x)+RANDOM);}
};
template<class K,class H=rand_hash<K>,class...Ts>using hashset=gp_hash_table<K,null_type,H,Ts...>;
template<class K,class V,class H=rand_hash<K>,class...Ts>using hashmap=gp_hash_table<K,V,H,Ts...>;
template<class K,class C=less<K>,class...Ts>using treeset=tree<K,null_type,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
template<class K,class V,class C=less<K>,class...Ts>using treemap=tree<K,V,C,rb_tree_tag,tree_order_statistics_node_update,Ts...>;
template<class K,class H=rand_hash<K>,class...Ts>using uset=unordered_set<K,H,Ts...>;template<class K,class V,class H=rand_hash<K>,class...Ts>using umap=unordered_map<K,V,H,Ts...>;
template<class T>using minpq=std::priority_queue<T,vector<T>,greater<T>>;template<class T>using maxpq=std::priority_queue<T,vector<T>,less<T>>;
template<class T>using minpairingheap=__gnu_pbds::priority_queue<T,greater<T>,pairing_heap_tag>;template<class T>using maxpairingheap=__gnu_pbds::priority_queue<T,less<T>,pairing_heap_tag>;
template<class T1,class T2,class H1=rand_hash<T1>,class H2=rand_hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
template<class T>struct is_iterator {
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id3(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id3(long){return false;}constexpr static bool value=id3<T>(0);
};


constexpr const int _bufferSize=1<<16,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id2=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id5=0,_cnt;ull _precisionBase=1000000;

    
    
    


    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id6(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











void setLength(int x){if(id2)delete[](id2);id2=new char[x+1];}
void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<class T1,class T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<class T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<class T>void read(T&x);template<class T,class...Ts>void read(T&x,Ts&&...xs);
template<class It>typename enable_if<is_iterator<It>::value>::type read(It st,It en){for(It _i=st;_i!=en;_i++)read(*_i);}
template<class It,class...Ts>typename enable_if<is_iterator<It>::value>::type read(It st,It en,Ts&&...xs){read(st,en);read(forward<Ts>(xs)...);}
template<class T>void read(T&x){for(auto&&_i:x)read(_i);}template<class T,class...Ts>void read(T&x,Ts&&...xs){read(x);read(forward<Ts>(xs)...);}
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

template <class Ret, class T1, class T2> struct IncrementalSkewHeapPlus {
    Ret operator () (const T1 &l, const T2 &r) const { return l + r; }
};

template <class Value, class Comparator = less<Value>, class Delta = Value,
        class ApplyDelta = IncrementalSkewHeapPlus<Value, Value, Delta>, class MergeDelta = IncrementalSkewHeapPlus<Delta, Delta, Delta>>
        struct id1 {
    Comparator cmp; Delta ddef; ApplyDelta applyDelta; MergeDelta mergeDelta;
    struct Node { Value val; Delta delta; unique_ptr<Node> left, right; Node(const Value &v, const Delta &d) : val(v), delta(d) {} };
    int cnt = 0; unique_ptr<Node> root;
    void propagate(unique_ptr<Node> &a) {
        a->val = applyDelta(a->val, a->delta);
        if (a->left) a->left->delta = mergeDelta(a->left->delta, a->delta);
        if (a->right) a->right->delta = mergeDelta(a->right->delta, a->delta);
        a->delta = ddef;
    }
    unique_ptr<Node> merge(unique_ptr<Node> a, unique_ptr<Node> b) {
        if (!a || !b) return a ? move(a) : move(b);
        propagate(a); propagate(b);
        if (cmp(a->val, b->val)) a.swap(b);
        a->right = merge(move(b), move(a->right)); a->left.swap(a->right); return a;
    }
    id1(const Delta &ddef) : ddef(ddef) {}
    bool empty() const { return !root; }
    Value top() { propagate(root); return root->val; }
    Value pop() {
        propagate(root); Value ret = root->val; root = merge(move(root->left), move(root->right)); cnt--;
        return ret;
    }
    void push(const Value &val) { root = merge(move(root), make_unique<Node>(val, ddef)); cnt++; }
    void increment(const Delta &delta) { if (root) root->delta = mergeDelta(root->delta, delta); }
    void merge(id1 &h) { root = merge(move(root), move(h.root)); cnt += h.cnt; }
    int size() const { return cnt; }
};

int N;
ll V[100005], T[100005];

int main() {
    

    

    

    read(N);
    read(V, V + N, T, T + N);
    setDelimiter("");
    id1<ll, greater<ll>> heap(0);
    FOR(i, N) {
        ll sum = 0;
        heap.push(V[i]);
        while (!heap.empty() && heap.top() - T[i] <= 0) sum += heap.pop();
        heap.increment(-T[i]);
        sum += heap.size() * T[i];
        write(sum, " \n"[i == N - 1]);
    }
    return 0;
}
