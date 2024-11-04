
using namespace std;












using ll=long long;using ld=long double;using uint=unsigned int;using ull=unsigned long long;
using pii=pair<int,int>;using pll=pair<ll,ll>;using pill=pair<int,ll>;using plli=pair<ll,int>;using pdd=pair<double,double>;using pld=pair<ld,ld>;
constexpr const char nl='\n',sp=' ';constexpr const int INT_INF=0x3f3f3f3f;constexpr const ll LL_INF=0x3f3f3f3f3f3f3f3f;
constexpr const double D_INF=numeric_limits<double>::infinity();constexpr const ld LD_INF=numeric_limits<ld>::infinity();constexpr const double EPS=1e-9;
template<typename T>constexpr bool flt(const T&x,const T&y){return x<y-EPS;}template<typename T>constexpr bool fgt(const T&x,const T&y){return x>y+EPS;}
template<typename T>constexpr bool feq(const T&x,const T&y){return abs(x-y)<=EPS;}template<typename T>constexpr bool in(const T&v,const T&lo,const T&hi){return!(v<lo||hi<v);}
template<typename T>constexpr const T&_min(const T&x,const T&y){return x<y?x:y;}template<typename T>constexpr const T&_max(const T&x,const T&y){return x<y?y:x;}
template<typename T,typename...Ts>constexpr const T&_min(const T&x,const Ts&...xs){return _min(x,_min(xs...));}
template<typename T,typename...Ts>constexpr const T&_max(const T&x,const Ts&...xs){return _max(x,_max(xs...));}
template<typename T,typename...Ts>void MIN(T&x,const Ts&...xs){x=_min(x,xs...);}template<typename T,typename...Ts>void MAX(T&x,const Ts&...xs){x=_max(x,xs...);}
template<typename T>constexpr const T&_clamp(const T&v,const T&lo,const T&hi){return v<lo?lo:hi<v?hi:v;}template<typename T>void CLAMP(T&v,const T&lo,const T&hi){v=_clamp(v,lo,hi);}
template<typename T,typename...Args>unique_ptr<T>_make_unique(Args&&...args){return unique_ptr<T>(new T(forward<Args>(args)...));}
template<typename T,typename...Args>shared_ptr<T>_make_shared(Args&&...args){return shared_ptr<T>(new T(forward<Args>(args)...));}





template<typename...Ts>using uset=unordered_set<Ts...>;template<typename...Ts>using umap=unordered_map<Ts...>;template<typename...Ts>using pq=priority_queue<Ts...>;
template<typename T>using minpq=pq<T,vector<T>,greater<T>>;template<typename T>using maxpq=pq<T,vector<T>,less<T>>;
template<typename T1,typename T2,typename H1=hash<T1>,typename H2=hash<T2>>struct pair_hash{size_t operator()(const pair<T1,T2>&p)const{return 31*H1{}(p.first)+H2{}(p.second);}};
seed_seq seq {
    (uint64_t)chrono::duration_cast<chrono::nanoseconds>(chrono::high_resolution_clock::now().time_since_epoch()).count(),
    (uint64_t)__builtin_ia32_rdtsc(),(uint64_t)(uintptr_t)make_unique<char>().get()
};
mt19937 rng(seq);mt19937_64 rng64(seq);

constexpr const int _bufferSize=4096,id0=128;
char _inputBuffer[_bufferSize+1],*_inputPtr=_inputBuffer,_outputBuffer[_bufferSize],_c,_sign,*_tempInputBuf=nullptr,_numBuf[id0],_tempOutputBuf[id0],_fill=' ';
FILE*_input=stdin,*_output=stdout,*_error=stderr;const char*_delimiter=" ";int _cur,_outputPtr=0,_numPtr=0,_precision=6,_width=0,id2=0,_cnt;ull _precisionBase=1000000;














void read(int&x){ri(x);}void read(uint&x){ri(x);}void read(ll&x){ri(x);}void read(ull&x){ri(x);}void read(double&x){rd(x);}void read(ld&x){rld(x);}
void read(char&x){rc(x);}void read(char*x){rcs(x);}void read(string&x){rs(x);}void readln(char*x){rcln(x);}void readln(string&x){rln(x);}
template<typename T1,typename T2>void read(pair<T1,T2>&x){read(x.first);read(x.second);}template<typename T>void read(complex<T>&x){T _re,_im;read(_re);read(_im);x.real(_re);x.imag(_im);}
template<typename T>void read(T&x){for(auto&&_i:x)read(_i);}template<typename T,typename...Ts>void read(T&x,Ts&...xs){read(x);read(xs...);}
bool hasNext(){while(_hasNext()&&_peekchar()<=' ')_getchar();return _hasNext();}
void setInput(FILE*file){*_inputPtr='\0';_input=file;}void setInput(const char*s){*_inputPtr='\0';_input=fopen(s,"r");}void setInput(const string&s){*_inputPtr='\0';_input=fopen(s.c_str(),"r");}























void writeDelimiter(){for(const char*_p=_delimiter;*_p;_putchar(*_p++));}
void write(const bool&x){wb(x);}void write(const int&x){wi(x);}void write(const uint&x){wi(x);}void write(const ll&x){wll(x);}void write(const ull&x){wll(x);}
void write(const double&x){wd(x);}void write(const ld&x){wld(x);}void write(const char&x){wc(x);}void write(const char*x){wcs(x);}void write(const string&x){ws(x);}
template<typename T1,typename T2>void write(const pair<T1,T2>&x){write(x.first);writeDelimiter();write(x.second);}
template<typename T>void write(const complex<T>&x){write(x.real());writeDelimiter();write(x.imag());}
template<typename T>void write(const T&x){bool _first=1;for(auto&&_i:x){if(_first)_first=0;else writeDelimiter();write(_i);}}
template<typename T,typename...Ts>void write(const T&x,const Ts&...xs){write(x);writeDelimiter();write(xs...);}
void writeln(){_putchar('\n');}template<typename...Ts>void writeln(const Ts&...xs){write(xs...);_putchar('\n');}
void flush(){_flush();}class IOManager{public:~IOManager(){flush();if(_tempInputBuf)delete[](_tempInputBuf);}};unique_ptr<IOManager>id1=make_unique<IOManager>();
void setOutput(FILE*file){flush();_output=file;}void setOutput(const char*s){flush();_output=fopen(s,"w");}void setOutput(const string&s){flush();_output=fopen(s.c_str(),"w");}
template<typename...Ts>void debug(const Ts&...xs){FILE*_temp=_output;setOutput(_error);write(xs...);setOutput(_temp);}
template<typename...Ts>void debugln(const Ts&...xs){FILE*_temp=_output;setOutput(_error);writeln(xs...);setOutput(_temp);}
void setError(FILE*file){flush();_error=file;}void setError(const char*s){flush();_error=fopen(s,"w");}void setError(const string&s){flush();_error=fopen(s.c_str(),"w");}

template <const int MAXV> struct TarjanSCC {
    int id[MAXV], low[MAXV], pre; bool vis[MAXV]; vector<int> adj[MAXV]; vector<vector<int>> components; stack<int> s;
    void addEdge(int v, int w) { adj[v].push_back(w); }
    void dfs(int v) {
        vis[v] = true; int mn = low[v] = pre++; s.push(v);
        for (int w : adj[v]) {
            if (!vis[w]) dfs(w);
            if (low[w] < mn) mn = low[w];
        }
        if (mn < low[v]) { low[v] = mn; return; }
        int w; components.emplace_back();
        do {
            w = s.top(); s.pop();
            id[w] = components.size() - 1; components.back().push_back(w); low[w] = INT_MAX;
        } while (w != v);
    }
    void clear() { components.clear(); for (int i = 0; i < MAXV; i++) adj[i].clear(); }
    void run(int V) {
        fill(vis, vis + V, false); pre = 0;
        for (int v = 0; v < V; v++) if (!vis[v]) dfs(v);
    }
};

template <const int MAXN> struct TwoSat {
    TarjanSCC<MAXN * 2> scc; bool vis[MAXN * 2], x[MAXN * 2]; int post[MAXN], cur; vector<int> DAG[MAXN * 2];
    

    void addEquation(bool affI, int i, bool affJ, int j) { 
        i = i * 2 + !affI; j = j * 2 + !affJ;
        scc.addEdge(i ^ 1, j); scc.addEdge(j ^ 1, i);
    }
    void dfs(int v) {
        vis[v] = true;
        for (int w : DAG[v]) if (!vis[w]) dfs(w);
        post[v] = cur++;
    }
    bool solve(int N) {
        scc.run(2 * N);
        for (int i = 0; i < N; i++) if (scc.id[i * 2] == scc.id[i * 2 + 1]) return false;
        fill(vis, vis + scc.components.size(), false); cur = 0;
        for (int i = 0; i < 2 * N; i++) for (int j : scc.adj[i]) if (scc.id[i] != scc.id[j]) DAG[scc.id[i]].push_back(scc.id[j]);
        for (int i = 0; i < int(scc.components.size()); i++) if (!vis[i]) dfs(i);
        for (int i = 0; i < N; i++) x[i] = post[scc.id[i * 2]] < post[scc.id[i * 2 + 1]];
        return true;
    }
    void clear() { scc.clear(); for (int i = 0; i < MAXN * 2; i++) DAG[i].clear(); }
};

const int MAXN = 105;

int N, M;
TwoSat<MAXN> ts;
vector<int> ans;

int main() {
    

    

    

    read(N, M);
    int a, b, c;
    FOR(i, M) {
        read(a, b, c);
        --a; --b;
        if (c) {
            ts.addEquation(true, a, false, b);
            ts.addEquation(false, a, true, b);
        } else {
            ts.addEquation(true, a, true, b);
            ts.addEquation(false, a, false, b);
        }
    }
    if (ts.solve(N)) {
        FOR(i, N) if (ts.x[i]) ans.pb(i + 1);
        writeln(sz(ans));
        writeln(ans);
    } else writeln("Impossible");
    return 0;
}
