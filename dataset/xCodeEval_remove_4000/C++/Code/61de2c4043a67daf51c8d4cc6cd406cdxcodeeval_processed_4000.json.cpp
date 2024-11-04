
























using namespace std;








using namespace std::tr1;


































double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<long long, long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1, typename T2, typename T3>
struct triple{ T1 a; T2 b; T3 c; triple(){}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };


template<typename T1, typename T2, typename T3>
bool operator<(const triple<T1, T2, T3> &t1, const triple<T1, T2, T3> &t2){ if (t1.a != t2.a) return t1.a < t2.a; else return t1.b < t2.b; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }






















































inline int bits_count(int v){ v = v - ((v >> 1) & 0x55555555); v = (v & 0x33333333) + ((v >> 2) & 0x33333333); return((v + (v >> 4) & 0xF0F0F0F) * 0x1010101) >> 24; }
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline int sign(int x){ return (x >> 31) | (-x >> 31); }
inline bool id0(int x){ return (x != 0 && (x&(x - 1)) == 0); }







template<typename T1, typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){ return os << "(" << p.first << ", " << p.second << ")"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::vector<T>& v){ bool first = true; os << "["; for (unsigned int i = 0; i < v.size(); i++){ if (!first)os << ", "; os << v[i]; first = false; }return os << "]"; }
template<typename T>inline std::ostream &operator<<(std::ostream &os, const std::set<T>&v){ bool first = true; os << "["; for (typename std::set<T>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os, const std::map<T1, T2>& v){ bool first = true; os << "["; for (typename std::map<T1, T2>::const_iterator ii = v.begin(); ii != v.end(); ++ii){ if (!first)os << ", "; os << *ii; first = false; }return os << "]"; }
template<typename T, typename T2>void printarray(T  a[], T2 sz, T2 beg = 0){ for (T2 i = beg; i < sz; i++) cout << a[i] << " "; cout << endl; }








inline ll binpow(ll x, ll n){ ll res = 1; while (n){ if (n & 1)res *= x; x *= x; n >>= 1; }return res; }
inline ll powmod(ll x, ll n, ll _mod){ ll res = 1; while (n){ if (n & 1)res = (res*x) % _mod; x = (x*x) % _mod; n >>= 1; }return res; }
inline ll gcd(ll a, ll b){ ll t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline int gcd(int a, int b){ int t; while (b){ a = a%b; t = a; a = b; b = t; }return a; }
inline ll lcm(int a, int b){ return a / gcd(a, b)*(ll)b; }
inline ll lcm(ll a, ll b){ return a / gcd(a, b)*b; }
inline ll gcd(ll a, ll b, ll c){ return gcd(gcd(a, b), c); }
inline int gcd(int a, int b, int c){ return gcd(gcd(a, b), c); }
inline ll lcm(ll a, ll b, ll c){ return lcm(lcm(a, b), c); }
inline ll lcm(int a, int b, int c){ return lcm(lcm(a, b), (ll)c); }

inline ll max(ll a, ll b){ return (a > b) ? a : b; }
inline int max(int a, int b){ return (a > b) ? a : b; }
inline double max(double a, double b){ return (a > b) ? a : b; }
inline ll max(ll a, ll b, ll c){ return max(a, max(b, c)); }
inline int max(int a, int b, int c){ return max(a, max(b, c)); }
inline double max(double a, double b, double c){ return max(a, max(b, c)); }
inline ll min(ll a, ll b){ return (a < b) ? a : b; }
inline int min(int a, int b){ return (a < b) ? a : b; }
inline double min(double a, double b){ return (a < b) ? a : b; }
inline ll min(ll a, ll b, ll c){ return min(a, min(b, c)); }
inline int min(int a, int b, int c){ return min(a, min(b, c)); }
inline double min(double a, double b, double c){ return min(a, min(b, c)); }

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m; ++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T a, int n){ for (int i = 0; i < n; ++i) cin >> a[i]; }













int n,pri[N],ansNum;
bool vis[N],prime[M];
vector<int> ans[N];
struct Edge{
    int from,to,cap,flow;
    Edge(int u,int v,int c,int f):from(u),to(v),cap(c),flow(f){}
};
struct EdmondsKarp{
    int n,m;
    vector<Edge> edges;

    vector<int> G[maxn];

    int a[maxn];

    int p[maxn];

    void init(int n){
        FI(n) G[i].clear();
        edges.clear();
    }
    void AddEdge(int from,int to,int cap){
        edges.push_back(Edge(from,to,cap,0));
        edges.push_back(Edge(to,from,0,0));

        m = edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    int Maxflow(int s,int t){
        int flow = 0;
        for(;;){
            memset(a,0,sizeof(a));
            queue<int> Q;
            Q.push(s);
            a[s] = INF;
            while(!Q.empty()){
                int x = Q.front();Q.pop();
                FI(G[x].size()){
                    Edge & e = edges[G[x][i]];
                    if(!a[e.to]&&e.cap > e.flow){
                        p[e.to] = G[x][i];
                        a[e.to] = min(a[x],e.cap - e.flow);
                        Q.push(e.to);
                    }
                }
                if(a[t]) break;
            }
            if(!a[t]) break;
            for(int u = t;u !=s;u = edges[p[u]].from){
                edges[p[u]].flow += a[t];
                edges[p[u] ^ 1].flow -= a[t];
            }
            flow += a[t];
        }
        return flow;
    }
};
EdmondsKarp Ek;
void InitPrime(){
    memset(prime,true,sizeof(prime));
    prime[0] = prime[1] = false;
    for(int i=2;i<M;i++){
        if(prime[i]){
            for(int j=i+i;j<M;j+=i){
                prime[j] = false;
            }
        }
    }
}
void FindPath(int s,int isOdd,int ansi){
    vis[s] = true;
    ans[ansi].push_back(s);
    for(int i=0;i<Ek.G[s].size();i++){
            Edge e = Ek.edges[Ek.G[s][i]];
            

            if(e.to != (n+1) && e.to != (n)&& !vis[e.to] && (e.cap == isOdd)&& (abs(e.flow) == 1)){
                FindPath(e.to,isOdd ^ 1,ansi);
                return ;
            }
    }
}
int main()
{
    InitPrime();
    

    while(S(n)!=EOF)
    {
        FI(n){
            S(pri[i]);
        }
        Ek.init(n+2);
        FI(n){
            if(pri[i] & 1)
                Ek.AddEdge(n,i,2);
            else
                Ek.AddEdge(i,n+1,2);
            for(int j=0;j<n;j++){
                if( j != i && (pri[i] & 1) && prime[pri[i] + pri[j]])
                    Ek.AddEdge(i,j,1);
            }
        }
        Ek.Maxflow(n,n+1);

        





















        bool flag = true;
        for(int i=0;i<Ek.G[n].size() && flag;i++){
            Edge e = Ek.edges[Ek.G[n][i]];
            

            if(e.cap && abs(e.flow) != 2){
                flag = false;
            }
        }
        for(int i=0;i<Ek.G[n+1].size() && flag;i++){
            Edge e = Ek.edges[Ek.G[n+1][i]];
            

            if(!e.cap && abs(e.flow) != 2){
                flag = false;
            }
        }
        if(flag){
            ansNum = 0;
            memset(vis,false,sizeof(vis));
            for(int i=0;i<Ek.G[n].size();i++){
                Edge e = Ek.edges[Ek.G[n][i]];
                if(!vis[e.to]){
                    ans[ansNum].clear();
                    FindPath(e.to,1,ansNum);
                    if(ans[ansNum].size()<=2){
                        ansNum = 0;
                        break;
                    }
                    ansNum++;
                }
            }
            if(ansNum == 0){
                printf("Impossible\n");
                continue;
            }
            printf("%d\n",ansNum);
            FI(ansNum){










                printf("%d",ans[i].size());
                FJ(ans[i].size()){
                    printf(" %d",ans[i][j]+1);
                    

                }
                printf("\n");












            }
        }
        else {
            printf("Impossible\n");
        }
    }
    return 0;
}
