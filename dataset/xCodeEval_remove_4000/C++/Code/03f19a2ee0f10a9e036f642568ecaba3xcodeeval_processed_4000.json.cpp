





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
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id4(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id4(long){return false;}constexpr static bool value=id4<T>(0);
};


constexpr const int _bufferSize=4096,id2=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id3=nullptr,_numBuf[id2],_tempOutputBuf[id2],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id6=0,_cnt;ull _precisionBase=1000000;

    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id8(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











void setLength(int x){if(id3)delete[](id3);id3=new char[x+1];}
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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(id3)delete[](id3);}};unique_ptr<IOManager>id5=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXN, const int id1, class T> struct RMQSparseTable {
    T A[MAXN]; int ST[id1][MAXN];
    int minInd(int l, int r) { return A[l] <= A[r] ? l : r; }
    void init(int N) {
        int lg = 32 - __builtin_clz(N); assert(lg < id1); iota(ST[0], ST[0] + N, 0);
        for (int i = 0; i < lg - 1; i++) for (int j = 0; j + (1 << i) < N; j++)
            ST[i + 1][j] = minInd(ST[i][j], ST[i][j + (1 << i)]);
    }
    int query(int l, int r) { 

        int i = 31 - __builtin_clz(r - l + 1);
        return minInd(ST[i][l], ST[i][r - (1 << i) + 1]);
    }
};

using Data = int; const Data vdef = 0;
struct Node {
    Node *l, *r, *p; int size; Data val; bool rev;
    Node(Data val) : l(nullptr), r(nullptr), p(nullptr), size(1), val(val), rev(false) {}
    void propagate();
    void update();
    void rotate(Node *rootP);
    void splay(Node *rootP);
};
int Size(Node *x) { return x ? x->size : 0; }
void Node::propagate() {
    if (rev) {
        swap(l, r);
        if (l) l->rev = !l->rev;
        if (r) r->rev = !r->rev;
        rev = false;
    }
}
void Node::update() {
    size = 1;
    if (l) size += Size(l);
    if (r) size += Size(r);
}
void connect(Node *ch, Node *par, bool isL) {
    if (ch) ch->p = par;
    if (par) {
        if (isL) par->l = ch;
        else par->r = ch;
    }
}
void Node::rotate(Node *rootP) {
    Node *p = this->p, *g = p->p; bool id0 = g == rootP, isL = this == p->l;
    connect(isL ? r : l, p, isL); connect(p, this, !isL); connect(this, g, id0 ? false : p == g->l); p->update();
}
void Node::splay(Node *rootP) {
    while (p != rootP) {
        Node *p = this->p, *g = p->p;
        if (g != rootP) g->propagate();
        p->propagate(); propagate();
        if (g != rootP) ((this == p->l) == (p == g->l) ? p : this)->rotate(rootP);
        rotate(rootP);
    }
    propagate(); update();
}
struct id9 {
    Node *root = nullptr; int cur = 0; vector<Node> T;
    Node *select(Node *x, int k) {
        if (!x) return nullptr;
        x->propagate(); int t = Size(x->l);
        if (t > k) return select(x->l, k);
        else if (t < k) return select(x->r, k - t - 1);
        return x;
    }
    Node *build(int l, int r, vector<Data> &A) {
        if (l > r) return nullptr;
        int m = l + (r - l) / 2, i = int(T.size()); T.emplace_back(A[m]);
        Node *left = build(l, m - 1, A), *right = build(m + 1, r, A), *x = &(T[i]);
        connect(left, x, true); connect(right, x, false); x->update();
        return x;
    }
    

    void slice(int l, int r) { (root = select(root, l - 1))->splay(nullptr); select(root, r + 1)->splay(root); }
    void updateToRoot() { if (root->r->l) { root->r->l->propagate(); root->r->l->update(); root->r->update(); root->update(); } }
    

    void reverseRange(int l, int r) {
        slice(l, r);
        if (root->r->l) root->r->l->rev = !root->r->l->rev;
        updateToRoot();
    }
    Data getValue(int ind) { slice(ind, ind); return root->r->l->val; }
    id9(int N) { T.reserve(N + 2); vector<Data> A(N + 2, vdef); root = build(0, A.size() - 1, A); }
    template <class It> id9(It st, It en) {
        T.reserve(en - st + 2); vector<Data> A; A.push_back(vdef); A.insert(A.end(), st, en); A.push_back(vdef);
        root = build(0, A.size() - 1, A);
    }
};

const int MAXNM = 2e5 + 5, id7 = 20;

int N, M, A[MAXNM], T[MAXNM];
RMQSparseTable<MAXNM, id7, int> ST;

int main() {
    

    

    

    read(N, M);
    read(A, A + N);
    FOR(i, M) {
        read(T[i], ST.A[i]);
        ST.A[i]--;
        ST.A[i] = -ST.A[i];
    }
    ST.init(M);
    int cur = ST.query(0, M - 1);
    sort(A, A + (-ST.A[cur]) + 1);
    id9 TR(A, A + N);
    while (true) {
        if ((T[cur] == 1 && TR.getValue(1) > TR.getValue(-ST.A[cur] + 1)) || (T[cur] == 2 && TR.getValue(1) < TR.getValue(-ST.A[cur] + 1))) TR.reverseRange(1, -ST.A[cur] + 1);
        if (cur == M - 1) break;
        cur = ST.query(cur + 1, M - 1);
    }
    setDelimiter("");
    FOR(i, N) write(TR.getValue(i + 1), " \n"[i == N - 1]);
    return 0;
}
