
























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
inline bool id1(int x){ return (x != 0 && (x&(x - 1)) == 0); }







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













int n,m,p1,p2,n2,xi,st[N],sn,sp[30],len;
char str[N],s1[10],s2[10],strc,strv,ans[N];
vector<int> p[N];
bool vis[N];
void id4(char & sc,char & sv,int tc){
    sc = sv = '\0';
    for(;tc < len;tc++){
        if( sp[tc] && sc == '\0') sc = 'a' + tc;
        if(!sp[tc] && sv == '\0') sv = 'a' + tc;
    }
}
bool DFS(int x){
    

    if(vis[x^1]) return false;
    if(vis[x]) return true;
    int tx = x/2;
    if(tx < xi){
        if((x & 1) != sp[str[tx] - 'a']) return false;
    }
    else if(tx == xi){
        int tc = str[tx] - 'a' + 1;
        char sc[2];
        id4(sc[1],sc[0],tc);
        

        if(sc[x & 1] != '\0'){
            ans[tx] = sc[x & 1];
        }
        else return false;
    }
    else {
        if((x & 1) && strc == '\0') return false;
        if(!(x & 1) && strv == '\0') return false;
    }
    vis[x] = true;
    st[sn++] = x;
    FI(p[x].size()){
        if(!DFS(p[x][i])) return false;
    }
    return true;
}
bool id2(int ti,int xi1,int xi2,char sv,char sc){
    ans[ti] = sv;
    sn = 0;
    if(!DFS(xi1)){
        FJ(sn) vis[st[j]] = false;
        sn = 0;
        ans[ti] = sc;
        if(!DFS(xi2)) return false;
    }
    return true;
}
bool id0(char sv,char sc,int ti){
    if(sv == '\0' && sc == '\0') return false;
    sn = 0;
    if(sv == '\0'){
       ans[ti] = sc;
       if(!DFS(2 * ti + 1)) return false;
    }
    else if(sc == '\0'){
        ans[ti] = sv;
        if(!DFS(2 * ti)) return false;
    }
    else {
        int xi1,xi2;
        if(sv < sc){
            if(!id2(ti,ti * 2, ti * 2 + 1,sv,sc)) return false;
        }
        else {
            if(!id2(ti,ti * 2 + 1, ti * 2,sc,sv)) return false;
        }
    }
    return true;
}
bool id3(){
    fill(vis,false);
    for(int i = 0;i<n2;i++){
        if(!vis[i] && !vis[i^1]){
            int ti = i / 2;
            if(ti < xi){
                if(!DFS(2 * ti + sp[str[ti] - 'a']))
                return false;
            }
            else if(ti == xi){
                int tc = str[ti] - 'a' + 1;
                char sv = '\0',sc = '\0';
                id4(sc,sv,tc);
                if(!id0(sv,sc,ti)) return false;
            }
            else {
                if(!id0(strv,strc,ti)) return false;
            }
        }
    }
    return true;
}
void add_edge(int a,int b){
    

    p[a].push_back(b);
    p[b^1].push_back(a^1);
}
int main()
{
     while(SS(str)!=EOF)
    {
        len = strlen(str);
        for(int i = 0;i < len;i++){
            sp[i] = str[i] == 'C' ? 1:0;
        }
        id4(strc,strv,0);
        

        S2(n,m);
        n2 = n + n;
        FI(n2) p[i].clear();
        FI(m){
            S(p1);SS(s1);
            S(p2);SS(s2);
            p1--;p2--;
            p1 *= 2;p2 *= 2;
            p1 = s1[0] == 'C'? p1^1:p1;
            p2 = s2[0] == 'C'? p2^1:p2;
            add_edge(p1,p2);
        }
        SS(str);
        bool flag = true;
        for(int i = n;i>=0 && flag;i--){
            xi = i;
            if(id3()){
                flag = false;
                for(int j = 0;j < i + i;j++){
                    ans[j/2] = str[j/2];
                }
                for(int j = i + i + 2;j<n2;j++){
                    if(vis[j]){
                        ans[j/2] = (j&1)? strc:strv;
                    }
                }
                ans[n] = '\0';
                
                {
                    printf("%s\n",ans);
                }

            }
        }
        if(flag)
            printf("-1\n");
    }
    return 0;
}
