



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


constexpr const int _bufferSize=1<<16,id1=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id2=nullptr,_numBuf[id1],_tempOutputBuf[id1],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id5=0,_cnt;ull _precisionBase=1000000;

    
    
    


    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id7(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











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

template <const int MAXV, const int id6, class unit> struct APSPTree {
    int ind, head[MAXV], dep[MAXV], root[MAXV], rmq[id6][2 * MAXV]; unit dist[MAXV]; vector<pair<int, unit>> adj[MAXV];
    void addEdge(int v, int w, unit weight) { adj[v].emplace_back(w, weight); adj[w].emplace_back(v, weight); }
    void dfs(int v, int prev, int r, int d, unit dd) {
        dep[v] = d; dist[v] = dd; root[v] = r; rmq[0][head[v] = ind++] = v;
        for (auto &&e : adj[v]) if (e.first != prev) { dfs(e.first, v, r, d + 1, dd + e.second); rmq[0][ind++] = v; }
    }
    int minDep(int v, int w) { return dep[v] < dep[w] ? v : w; }
    int RMQ(int l, int r) { int i = 31 - __builtin_clz(r - l + 1); return minDep(rmq[i][l], rmq[i][r - (1 << i) + 1]); }
    void clear(int V = MAXV) { for (int i = 0; i < V; i++) adj[i].clear(); }
    void run(int V) {
        ind = 0; int lg = 32 - __builtin_clz(V * 2 - 1); assert(lg < id6); fill(root, root + V, -1);
        for (int i = 0; i < V; i++) if (root[i] == -1) dfs(i, -1, i, 0, 0);
        for (int i = 0; i < lg - 1; i++) for (int j = 0; j < ind; j++) rmq[i + 1][j] = minDep(rmq[i][j], rmq[i][min(j + (1 << i), ind - 1)]);
    }
    int lca(int v, int w) {
        if (head[v] > head[w]) swap(v, w);
        return RMQ(head[v], head[w]);
    }
    unit getDist(int v, int w) { return root[v] == root[w] ? dist[v] + dist[w] - 2 * dist[lca(v, w)] : -1; }
};

template <const int MAXM, const int MAXN, class F> struct Simplex {
    F EPS, A[MAXM][MAXN], b[MAXM], c[MAXN], x[MAXN], T[MAXM][MAXN + MAXM]; int IN[MAXM], OUT[MAXN + MAXM]; Simplex(F EPS) : EPS(EPS) {}
    bool cmp(F a, int b, F c, int d) { return abs(a - c) > EPS ? a < c : b < d; }
    F solve(int M, int N) {
        for (int i = 0; i <= M; i++) fill(T[i], T[i] + N + M + 1, 0);
        fill(IN, IN + M + 1, N); fill(OUT, OUT + N + M + 1, N); fill(x, x + N, 0);
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) T[i][j] = A[i][j];
            T[i][N + i] = 1;
            T[i][N + M] = b[i];
        }
        for (int j = 0; j < N; j++) T[M][OUT[j] = j] = -c[j];
        while (true) {
            int p = 0, q = 0;
            for (int i = 0; i < M; i++) if (T[i][N + M] <= T[p][N + M]) p = i;
            for (int j = 0; j < N + M; j++) if (T[M][j] <= T[M][q]) q = j;
            F t = min(T[p][N + M], T[M][q]);
            if (t >= -EPS) break; 

            if (t < T[p][N + M]) {
                for (int i = 0; i < M; i++) if (T[i][q] >= EPS && T[p][q] * (T[i][N + M] - t) <= T[i][q] * (T[p][N + M] - t)) p = i;
                if (T[p][q] <= EPS) return numeric_limits<F>::infinity(); 

            } else {
                for (int j = 0; j <= N + M; j++) T[p][j] *= -1;
                for (int j = 0; j < N + M; j++) if (T[p][j] >= EPS && T[p][q] * (T[M][j] - t) <= T[p][j] * (T[M][q] - t)) q = j;
                if (T[p][q] <= EPS) return -numeric_limits<F>::infinity(); 

            }
            for (int j = 0; j <= N + M; j++) if (j != q) T[p][j] /= T[p][q];
            T[p][q] = 1; swap(IN[p], OUT[q]);
            for (int i = 0; i <= M; i++) if (i != p) {
                F alpha = T[i][q];
                if (abs(alpha) > EPS) for (int j = 0; j <= N + M; j++) T[i][j] -= T[p][j] * alpha;
            }
        }
        for (int i = 0; i < M; i++) if (IN[i] < N) x[IN[i]] = T[i][N + M];
        F checkVal = 0;
        for (int i = 0; i < N; i++) checkVal += c[i] * x[i];
        assert(abs(checkVal - T[M][N + M]) <= EPS); return T[M][N + M];
        return T[M][N + M];
    }
};

const int MAXN = 505, id0 = 12;
const double EPS = 1e-9;

int N, X;
APSPTree<MAXN, id0, ll> APSP;
Simplex<MAXN, MAXN, double> LP(EPS);

int main() {
    

    

    

    read(N, X);
    int B = 0;
    FOR(i, N) {
        int c;
        read(c);
        B += c;
        LP.c[i] = c - 1;
    }
    FOR(i, N - 1) {
        int a, b;
        ll c;
        read(a, b, c);
        APSP.addEdge(--a, --b, c);
    }
    APSP.run(N);
    FOR(i, N) {
        FOR(j, N) LP.A[i][j] = APSP.getDist(i, j) <= X ? -1 : 0;
        LP.b[i] = -1;
    }
    fill(LP.A[N], LP.A[N] + N, 1);
    LP.b[N] = B;
    double ans = LP.solve(N + 1, N);
    writeln(ans == -D_INF ? -1 : -ll(round(ans)));
    return 0;
}
