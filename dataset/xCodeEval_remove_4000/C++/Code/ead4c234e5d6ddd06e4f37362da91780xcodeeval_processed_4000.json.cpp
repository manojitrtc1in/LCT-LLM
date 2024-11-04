
























using namespace std;

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
template <class T>
inline bool scan_d(T &ret) {
   char c; int sgn;
   if(c = getchar(),c == EOF) return 0; 

   while(c != '-' && (c < '0' || c > '9')) c = getchar();
   sgn = (c == '-') ? -1 : 1;
   ret = (c == '-') ? 0 : (c - '0');
   while(c = getchar(),c >= '0' && c <= '9') ret = ret * 10 + (c - '0');
   ret *= sgn;
   return 1;
}

inline void out(int x) {
   if(x > 9) out(x / 10);
   putchar(x % 10 + '0');
}














int n,m,k,t,all,from;
int v[M],ans[N];
bool vis[N],Dvis[N];
vector<int> p[N];
queue<int> q;
void BFS(){
    while(!q.empty()){
        int top = q.front();
        q.pop();
        FI(p[top].size()){
            int g = p[top][i];
            int gx = v[g];
            if(ans[g] == -1 && ans[m + m - g] == -1){
                ans[g] = 1;ans[m + m - g] = 0;
                if(!vis[gx]){
                    

                    q.push(gx);
                    vis[gx] = true;
                }
            }
        }
    }
}
bool DFS(int x,int fa){
    all++;
    Dvis[x] = true;
    FI(p[x].size()){
        int g = p[x][i];
        int gx = v[g];
        if((g != fa && g != m + m - fa) && ans[g] == -1 && ans[m + m - g] == -1){
            if(Dvis[gx] || vis[gx]){
                from = g;
                return true;
            }
            else if(DFS(gx,g))
            return true;
        }
    }
    return false;
}
int main()
{
    

    

     while(S2(n,m)!=EOF)
    {
        FI(2 * m + 2) v[i] = -1,ans[i] = -1;
        fill(vis,false);
        fill(Dvis,false);
        FI(n){
            S(k);
            FJ(k){
                S(t);
                if(v[t+m] != -1){
                    vis[v[t+m]] = 1;
                    vis[i] = 1;
                    ans[t+m] = 1;
                }
                else
                    v[t + m] = i;
            }
        }
        For(i,m + 1,m + m + 1){
            

            if(v[i] >= 0 && v[m + m - i] >= 0){
                int s = v[i],e = v[m + m -i];
                p[s].push_back(m + m - i);
                p[e].push_back(i);
                

            }
            else if(v[i] >= 0 && v[m + m - i] == -1){
                ans[i] = 1;ans[m + m - i] = 0;vis[v[i]] = true;
            }
            else if(v[i] == -1 && v[m + m - i] >= 0){
                ans[m + m - i] = 1;ans[i] = 0;vis[v[m + m - i]] = true;
            }
        }
        while(!q.empty()) q.pop();
        FI(n){
            if(vis[i]){
                q.push(i);
            }
        }
        BFS();
        bool flag = true;
        FI(n){
            if(!vis[i] && !Dvis[i]){
                from = -1;all = 0;
                DFS(i,-1);
                

                if(all >= 2 && from == -1)
                {
                    flag = false;
                    break;
                }
                if(from != -1){
                    ans[from] = 1;ans[m + m - from] = 0;
                    while(!q.empty()) q.pop();
                    q.push(v[from]);
                    BFS();
                }
            }
        }
        if(flag){
            printf("YES\n");
            For(i,m+1,m+m+1)
                if(ans[i] == 1)  printf("1");
                else printf("0");
            printf("\n");
        }
        else {
            printf("NO\n");
        }
    }
    

    

    return 0;
}