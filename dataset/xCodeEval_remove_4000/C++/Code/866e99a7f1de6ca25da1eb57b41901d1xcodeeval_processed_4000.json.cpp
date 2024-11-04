





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
    template<class U,typename enable_if<!is_convertible<U,const char*>::value,int>::type=0>constexpr static auto id2(int)->decltype(*declval<U>(),bool()){return true;}
    template<class>constexpr static bool id2(long){return false;}constexpr static bool value=id2<T>(0);
};


constexpr const int _bufferSize=1<<16,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*id1=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id4=0,_cnt;ull _precisionBase=1000000;

    
    
    


    

    
    
    
    bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}bool id6(){while(_hasNext()&&_peekchar()=='\r')_getchar();return _hasNext();}











void setLength(int x){if(id1)delete[](id1);id1=new char[x+1];}
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
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(id1)delete[](id1);}};unique_ptr<IOManager>id3=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<class...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<class...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXV, const bool id7> struct SubtreeQueries {
    using Data = int; int st[MAXV], en[MAXV], vert[MAXV], curInd, size[MAXV]; vector<int> adj[MAXV];
    void update(int i, Data val); 

    void update(int l, int r, Data val); 

    Data query(int l, int r); 

    void dfs(int v, int prev) {
        vert[st[v] = ++curInd] = v; size[v] = 1;
        for (int w : adj[v]) if (w != prev) {
            dfs(w, v);
            size[v] += size[w];
        }
        en[v] = curInd;
    }
    void clear(int V = MAXV) { for (int i = 0; i < V; i++) adj[i].clear(); }
    void run(int V, int root = 0) {
        curInd = int(id7) - 1; fill(st, st + V, -1); dfs(root, -1);
        for (int v = 0; v < V; v++) if (st[v] == -1) dfs(v, -1);
    }
    void addEdge(int a, int b) { adj[a].push_back(b); adj[b].push_back(a); }
    void updateVertex(int v, Data val) { update(st[v], val); }
    void updateSubtree(int v, Data val) { update(st[v], en[v], val); }
    Data querySubtree(int v) { return query(st[v], en[v]); }
};

template <const int MAXM, const int MAXN, class F> struct Simplex {
    int M, N, IN[MAXM], OUT[MAXN]; F EPS, A[MAXM][MAXN], b[MAXM], c[MAXN], x[MAXN], T[MAXM][MAXN]; Simplex(F EPS) : EPS(EPS) {}
    void pivot(int r, int s) {
        auto &a1 = T[r]; F inv = 1 / a1[s];
        for (int i = 0; i <= M + 1; i++) if (i != r) {
            auto &a2 = T[i]; F inv2 = a2[s] * inv;
            for (int j = 0; j <= N + 1; j++) a2[j] -= a1[j] * inv2;
            a2[s] = a1[s] * inv2;
        }
        for (int j = 0; j <= N + 1; j++) if (j != s) a1[j] *= inv;
        for (int i = 0; i <= M + 1; i++) if (i != r) T[i][s] *= -inv;
        a1[s] = inv; swap(IN[r], OUT[s]);
    }
    bool simplex(int phase) {
        int x = M + phase - 1;
        while (true) {
            int s = -1;
            for (int j = 0; j <= N; j++) if (OUT[j] != -phase && (s == -1 || make_pair(T[x][j], OUT[j]) < make_pair(T[x][s], OUT[s]))) s = j;
            if (T[x][s] >= -EPS) return true;
            int r = -1;
            for (int i = 0; i < M; i++)
                if (T[i][s] > EPS && (r == -1 || make_pair(T[i][N + 1] / T[i][s], IN[i]) < make_pair(T[r][N + 1] / T[r][s], IN[r]))) r = i;
            if (r == -1) return false;
            pivot(r, s);
        }
    }
    F solve(int m, int n) {
        M = m; N = n;
        for (int i = 0; i <= M + 1; i++) fill(T[i], T[i] + N + 1, 0);
        for (int i = 0; i < M; i++) for (int j = 0; j < N; j++) T[i][j] = A[i][j];
        for (int i = 0; i < M; i++) { IN[i] = N + i; T[i][N] = -1; T[i][N + 1] = b[i]; }
        for (int j = 0; j < N; j++) { OUT[j] = j; T[M][j] = -c[j]; }
        OUT[N] = -1; T[M + 1][N] = 1;
        int r = 0;
        for (int i = 1; i < M; i++) if (T[i][N + 1] < T[r][N + 1]) r = i;
        if (T[r][N + 1] < -EPS) {
            pivot(r, N);
            if (!simplex(2) || T[M + 1][N + 1] < -EPS) return -numeric_limits<F>::infinity(); 

            for (int i = 0; i < M; i++) if (IN[i] == -1) {
                int s = 0;
                for (int j = 1; j <= N; j++) if (s == -1 || make_pair(T[i][j], OUT[j]) < make_pair(T[i][s], OUT[s])) s = j;
                pivot(i, s);
            }
        }
        bool unbounded = !simplex(1); fill(x, x + N, 0);
        for (int i = 0; i < M; i++) if (IN[i] < N) x[IN[i]] = T[i][N + 1];
        return unbounded ? numeric_limits<F>::infinity() : T[M][N + 1];
    }
};

const int MAXN = 505;
const double EPS = 1e-9;

int N, X, Y, Q1, Q2;
SubtreeQueries<MAXN, 0> T[2];
Simplex<MAXN * 5, MAXN, double> LP(EPS); 

int main() {
    

    

    

    read(N, X, Y);
    read(LP.c, LP.c + N);
    --X;
    --Y;
    FOR(i, 2 * (N - 1)) {
        int a, b;
        read(a, b);
        T[i >= N - 1].addEdge(--a, --b);
    }
    T[0].run(N, X);
    T[1].run(N, Y);
    read(Q1);
    int Q = Q1;
    FOR(i, Q) {
        int k, x;
        read(k, x);
        --k;
        FOR(j, N) {
            bool id5 = T[i >= Q1].st[k] <= T[i >= Q1].st[j] && T[i >= Q1].en[j] <= T[i >= Q1].en[k];
            LP.A[i * 2][j] = id5 ? 1 : 0;
            LP.A[i * 2 + 1][j] = id5 ? -1 : 0;
        }
        LP.b[i * 2] = x;
        LP.b[i * 2 + 1] = -x;
        if (i == Q1 - 1) {
            read(Q2);
            Q += Q2;
        }
    }
    FOR(i, N) {
        fill(LP.A[2 * Q + i], LP.A[2 * Q + i] + N, 0);
        LP.A[2 * Q + i][i] = 1;
        LP.b[2 * Q + i] = 1;
    }
    double ans = LP.solve(2 * Q + N, N);
    writeln(ans == -D_INF ? -1 : ll(round(ans)));
    return 0;
}
