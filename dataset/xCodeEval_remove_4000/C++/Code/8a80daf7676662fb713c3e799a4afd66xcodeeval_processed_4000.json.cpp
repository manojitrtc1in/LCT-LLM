
using namespace std;












 






 
 
typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;
typedef std::pair<char, char> pcc;
typedef std::pair<double, double> pdd;
typedef std::pair<std::string, std::string> pss;
typedef std::pair<long, long> pll;
typedef std::pair<ll, ll> pLL;
typedef std::vector<int> vint;
typedef std::vector<pii> vpii;
typedef std::vector<long> vlong;
typedef std::vector<long long> vll;
typedef std::vector<std::string> vstr;
typedef std::vector<bool> vbool;












inline int countBits(uint v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int countBits(ull v){uint t=v>>32;uint p=(v & ((1ULL << 32) - 1)); return countBits(t) + countBits(p); }
inline int countBits(ll v){return countBits((ull)v); }
inline int countBits(int v){return countBits((uint)v); }
unsigned int reverseBits(uint x){ x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1)); x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2)); x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4)); x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8)); return((x >> 16) | (x << 16)); }
inline bool id3(int x){ return (x != 0 && (x&(x - 1)) == 0); }





TT1T2 inline PT1T2 operator+(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first + p2.first, p1.second + p2.second); }
TT1T2 inline PT1T2& operator+=(PT1T2 &p1 , const PT1T2 &p2) { p1.first += p2.first, p1.second += p2.second; return p1; }
TT1T2 inline PT1T2 operator-(const PT1T2 &p1 , const PT1T2 &p2) { return PT1T2(p1.first - p2.first, p1.second - p2.second); }
TT1T2 inline PT1T2& operator-=(PT1T2 &p1 , const PT1T2 &p2) { p1.first -= p2.first, p1.second -= p2.second; return p1; }

template<class T> inline T _gcd(T a, T b) { while (b) { T t = a % b; a = b; b = t; } return a; }
template<class T> inline T _gcd(T a, T b, T c){ return _gcd(_gcd(a, b), c); }
template<class T>
T id9(T u, T v) {
    int shl = 0; while ( u && v && u != v) { T eu = u & 1; u >>= eu ^ 1; T ev = v & 1; v >>= ev ^ 1;
        shl += (~(eu | ev) & 1); T d = u & v & 1 ? (u + v) >> 1 : 0; T dif = (u - v) >> (sizeof(T) * 8 - 1); u -= d & ~dif; v -= d & dif;
    } return std::max(u, v) << shl;
}

ll id5(ll a, ll b, ll& x, ll& y) {
    if (!a) { x = 0; y = 1; return b; }
    ll y1; ll d = id5(b % a, a, y, y1); x = y1 - (b / a) * y;
    return d;
}
template<class T> bool isPrime(T x) { if (x <= 4 || x % 2 == 0 || x % 3 == 0) return x == 2 || x == 3;
    for (T i = 5; i * i <= x; i += 6) if (x % i == 0 || x % (i + 2) == 0) return 0; return 1; }

template<class T> inline void normmod(T &x, T m) { x %= m; if (x < 0) x += m; }

inline ll mulmod(ll x, ll n, ll m){ ll r = 0; normmod(x, m); normmod(n, m); while (n) { if (n & 1) r += x; x += x; if (r >= m) r -= m; if (x >= m) x -= m; n /= 2; } return r; }

using int128 = __int128;
inline ll mulmod(ll x, ll n, ll m){ return __int128(x) * n % m; }

inline ll powmod(ll x, ll n, ll m){ ll r = 1; normmod(x, m); while (n){ if (n & 1) r *= x; x *= x; r %= m; x %= m; n /= 2; }return r; }
inline ll id2(ll x, ll n, ll m) { ll res = 1; normmod(x, m); while (n){ if (n & 1)res = mulmod(res, x, m); x = mulmod(x, x, m); n /= 2; } return res; }
bool id7(long long n) {
    if (n <= 1000) return isPrime(n);
    long long s = n - 1; int t = 0; while (s % 2 == 0) s /= 2, ++t;
    for (int a : {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) { if (!(a %= n)) return true;
        long long f = id2(a, s, n); if (f == 1 || f == n - 1) continue;
        for (int i = 1; i < t; ++i) if ((f = mulmod(f, f, n)) == n - 1) goto nextp;
        return false; nextp:;
    } return true;
}
                        
                        template<class T>
                        T mod(T a, T b) {
                            if (a<0){   
                                a=(-a)%b ;
                                if (a!=0){
                                   a=b-a ;
                                }
                            }else{
                                a=a%b ;
                            }
                            return a ;
                        }

                        template<class T>
                        T mul(T a, T b, T mm) {
                            return (mod(a, mm) * mod(b, mm))%mm ;
                        }
 
                        template<class T>
                        T add(T a, T b, T mm) {
                            return (mod(a, mm) + mod(b, mm))%mm ;
                        }
                        

                        template<class T>
                        T gcd (T a, T b){                       
                            if (a==-1||b==-1)return -1 ;
                            if (a==0||b==0)return b|a ;
                            return (std::__gcd(a,b)) ;
                        }
 
 
                        template<class T>
                        T lcm (T a, T b){
                            if(a==0 && b==0) return 0;
                            return (a*b)/(std::__gcd(a,b)) ;
                        }

           

                      
                        void fastscan(int &number){
                            bool negative = false;
                            register int c;
                            number = 0;
                            c = getchar();
                            if (c=='-')
                            {
                              negative = true;
                              c = getchar();
                            }
                            for (; (c>47 && c<58); c=getchar())
                            number = number *10 + c - 48;
                             if (negative)
                            number *= -1;
                        }

                        bool *is_prime;
                        void sieve(void){
                            const int MAX_N = 1e5 + 5;
                            is_prime = new bool[MAX_N];
                            memset(is_prime, true, MAX_N);
                         
                            for (int p=1<<1; p*p<=MAX_N; ++p){
                                if (is_prime[p]){
                                    for (int i=p<<1; i<=MAX_N; i += p)
                                        is_prime[i] = false;
                                }
                            }
                        }


                        int* ni(int n){                       
                            int *arr = new int[n];
                            for(int i=0; i<n; ++i){
                                cin>>arr[i];
                            }
                           return arr;  
                        }

                        long* nl(int n){                       
                            long *arr = new long[n];
                            for(int i=0; i<n; ++i){
                                cin>>arr[i];
                            }
                           return arr;  
                        }

                        long long* nll(int n){                       
                            long long *arr = new long long[n];
                            for(int i=0; i<n; ++i){
                                cin>>arr[i];
                            }
                           return arr;  
                        }
 







































int32_t __(void);
int32_t main(int argc, char** argv){
    boost;
    clock_t clk;
    clk = clock();
    int32_t _ = __();
    clk = clock() - clk;
    

    

return _;
}
                        




const int N = 5e5+ 10;
const int inf = 1e9;
const ll MOD = 5;

const int LOG = 21;
int ans[N];
int parentDp[N][LOG];
vector<int> tree[N], centroidTree[N];
bool centroidMarked[N];
int level[N], parent[N];
int subtree_size[N];

void addEdge(int u, int v){
    tree[u].push_back(v);
    tree[v].push_back(u);
}

void DFS(int u, int par){
    subtree_size[u] = 1;
    for(int v : tree[u]){
        if( v == par or centroidMarked[v] ){
            continue;
        }
        DFS(v, u);
        subtree_size[u] += subtree_size[v];
    }
}

int id10(int u, int par, int n){
    bool id12 = true;
    int id11 = 0;
    for (int v : tree[u]){
        if( v == par or centroidMarked[v] ){
            continue;
        }
        if(subtree_size[v] > n>>1){
           id12 = false;
        }
        if(id11==0 or subtree_size[v] > subtree_size[id11]){
           id11 = v;
        }
    }
    if(id12 and n - subtree_size[u] <= n>>1){
        return u;
    }
    return id10(id11, u, n);
}

int id10(int u){
    DFS(u, -1);
    int centroid = id10(u, -1, subtree_size[u]);
    centroidMarked[centroid] = true;
    return centroid;
}

int id6(int u){
    int id13 = id10(u);
    

    

    for (int v : tree[id13]){
        if(centroidMarked[v]){
            continue;
        }
        int id1 = id6(v);
        centroidTree[id13].push_back(id1);
        centroidTree[id1].push_back(id13);
    }
    return id13;
}





int LCA(int u, int v){
    if (level[v] < level[u]){
        swap(u, v);
    }
    int diff = level[v] - level[u];
 
    for (int i=0; i<LOG; i++){
        if ((diff>>i)&1){
            v = parentDp[v][i];
        }
    }
 
    

    if (u == v){
        return u; 
    }
 
    for (int i=LOG-1; i>=0; i--){
        if (parentDp[u][i] != parentDp[v][i]){
            u = parentDp[u][i];
            v = parentDp[v][i];
        }
    }
    return parentDp[u][0];
}


int dist(int a, int b) {
        int l = LCA(a, b);
        return level[a] - level[l] + level[b] - level[l];
}


void id14(){
        for (int level = 1; level < LOG; ++level) {
                for (int node = 0; node <N; ++node) {

                        if(parentDp[node][level-1] != -1){
                                parentDp[node][level] = parentDp[parentDp[node][level-1]][level-1];
                        }
                }
        }
}

int32_t __(void){
    mem(parentDp, -1);
    int n, qq;
    cin>>n>>qq;
    int m = n-1;
    while(m--){
        int u, v;
        cin>>u>>v;
        addEdge(u, v);
    }
    function<void(int, int)> id8;
    id8 = [&] (int u, int par) -> void{
        parent[u] = par;
        for(int v : centroidTree[u]){
            if(v == par){
                continue;
            }
            id8(v, u);
        }
    };
    function<void(int, int)> id0;
    id0 = [&] (int u, int par) -> void{
        parentDp[u][0] = par;
        for(int v : tree[u]){
            if(v == par){
                continue;
            }
            level[v] = level[u] + 1;
            id0(v, u);
        }
    };
    function<void(int)> paintBlue;
    paintBlue = [&] (int u) -> void{
        int curr = u;
        while(curr != -1){
            ans[curr] = min(ans[curr], dist(u, curr));
            curr = parent[curr];
        }
    };
    function<int(int)> nearestRed;
    nearestRed = [&] (int u) -> int{
        int mn = inf;;
        int curr = u;
        while(curr != -1){
            mn = min(mn, ans[curr] + dist(u, curr));
            curr = parent[curr];
        }
        return mn;
    };
    level[1] = 0;
    id0(1, -1);
    id14();
    int id4 = id6(1);
    id8(id4, -1);
    for(int i=0; i<N; ++i){
        ans[i] = inf;
    }
    paintBlue(1);
    while(qq--){
        int type, u;
        cin>>type>>u;
        if(type == 1){
            paintBlue(u);
        }else{
            cout<<nearestRed(u)<<"\n" ;
        }
    }
    return 0;
}