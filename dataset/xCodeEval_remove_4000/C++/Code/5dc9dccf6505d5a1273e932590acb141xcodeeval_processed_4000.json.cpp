






















using namespace std;








using namespace std::tr1;



























double __begin;



typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<long long,long long> pll;
typedef vector<int> vi;
typedef vector<long long> vll;

template<typename T1,typename T2,typename T3>
struct triple{T1 a;T2 b;T3 c;triple(){};triple(T1 _a,T2 _b, T3 _c):a(_a),b(_b),c(_c){}};


template<typename T1,typename T2,typename T3>
bool operator<(const triple<T1,T2,T3> &t1,const triple<T1,T2,T3> &t2){if (t1.a!=t2.a) return t1.a<t2.a; else if (t1.b != t2.b) return t1.b<t2.b; else return t1.c < t2.c; }
template<typename T1, typename T2, typename T3>
inline std::ostream& operator << (std::ostream& os, const triple<T1, T2, T3>& t){ return os << "(" << t.a << ", " << t.b << ", " << t.c << ")"; }




















inline int bits_count(int v){v=v-((v>>1)&0x55555555);v=(v&0x33333333)+((v>>2)&0x33333333);return((v+(v>>4)&0xF0F0F0F)*0x1010101)>>24;}
inline int bits_count(ll v){ int t = v >> 32; int p = (v & ((1LL << 32) - 1)); return bits_count(t) + bits_count(p); }
unsigned int reverse_bits(register unsigned int x){x = (((x & 0xaaaaaaaa) >> 1) | ((x & 0x55555555) << 1));x = (((x & 0xcccccccc) >> 2) | ((x & 0x33333333) << 2));x = (((x & 0xf0f0f0f0) >> 4) | ((x & 0x0f0f0f0f) << 4));x = (((x & 0xff00ff00) >> 8) | ((x & 0x00ff00ff) << 8));return((x >> 16) | (x << 16));}
inline int sign(int x){return (x >> 31) | (-x >> 31);}
inline bool id0(int x){return (x!=0 && (x&(x-1))==0);}







template<typename T1,typename T2>inline std::ostream& operator << (std::ostream& os, const std::pair<T1, T2>& p){return os << "(" << p.first << ", " << p.second << ")";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::vector<T>& v){bool first=true;os<<"[";for(unsigned int i=0;i<v.size();i++){if(!first)os<<", ";os<<v[i];first=false;}return os<<"]";}
template<typename T>inline std::ostream &operator<<(std::ostream &os,const std::set<T>&v){bool first=true;os << "[";for(typename std::set<T>::const_iterator ii=v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T1, typename T2>inline std::ostream &operator << (std::ostream & os,const std::map<T1, T2>& v){bool first = true; os << "[";for (typename std::map<T1,T2>::const_iterator ii =v.begin();ii!=v.end();++ii){if(!first)os<<", ";os<<*ii;first=false;}return os<<"]";}
template<typename T,typename T2>void printarray(T  a[],T2 sz,T2 beg=0){for(T2 i=beg;i<sz;i++) cout<<a[i]<<" ";cout<<endl;}








inline ll powmod(ll x,ll n, ll _mod){ll res=1;while(n){if(n&1)res=(res*x)%_mod;x=(x*x)%_mod;n>>=1;}return res;}
inline ll gcd(ll a,ll b){ll t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline int gcd(int a,int b){int t;while(b){a=a%b;t=a;a=b;b=t;}return a;}
inline ll lcm(int a,int b){return a/gcd(a,b)*(ll)b;}
inline ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
inline ll gcd(ll a,ll b,ll c){return gcd(gcd(a,b),c);}
inline int gcd(int a,int b,int c){return gcd(gcd(a,b),c);}
inline ll lcm(ll a,ll b,ll c){return lcm(lcm(a,b),c);}
inline ll lcm(int a,int b,int c){return lcm(lcm(a,b),(ll)c);}

inline ll max(ll a,ll b){return (a>b)?a:b;}
inline int max(int a,int b){return (a>b)?a:b;}
inline double max(double a,double b){return (a>b)?a:b;}
inline ll max(ll a,ll b,ll c){return max(a,max(b,c));}
inline int max(int a,int b,int c){return max(a,max(b,c));}
inline double max(double a,double b,double c){return max(a,max(b,c));}
inline ll min(ll a,ll b){return (a<b)?a:b;}
inline int min(int a,int b){return (a<b)?a:b;}
inline double min(double a,double b){return (a<b)?a:b;}
inline ll min(ll a,ll b,ll c){return min(a,min(b,c));}
inline int min(int a,int b,int c){return min(a,min(b,c));}
inline double min(double a,double b,double c){return min(a,min(b,c));}

template<class T>
inline void getar(T a, int n, int m){ for (int i = 0; i < n; i++) for (int j = 0; j < m;++j) { scanf("%d", &a[i][j]); } }
inline void getar(int *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d", a + ii); } }
inline void getar(pii *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%d%d", &a[ii].first, &a[ii].second); } }
inline void getar(ll *a, int n){ for (int ii = 0; ii < n; ii++){ scanf("%I64d", a + ii); } }
template<class T>
inline void cinarr(T &a, int n){ for (int i=0;i<n;++i) cin >> a[i];}











bool voc[10010];
vector<pii> v[201][2];
bool isbad[201][2];
bool used[201][2];
int w[201][2];
bool way[201][2][201][2];
bool canbe[201][2][201][2];
bool isb = false;
bool wentb[201];
bool mustb[201];
int sx, sa;
void go(int x, int a) {
    used[x][a] = true;
    way[sx][sa][x][a] = true;
    for (auto to : v[x][a]) {
        if (!used[to.first][to.second]) {
            go(to.first, to.second);
        }
    }
}
void DIE() {
    cout << -1 << endl;
    exit(0);
}
string s;
int n;
int l;
int ans[202];
int iter = 0;
bool place(int cur, bool can = false) {
    ++iter;
    if (cur == n) return true;
    for (int i = cur; i < n; ++i) {
        int t = (w[i][0] == cur) + (w[i][1] == cur);
        if (t == 0) return false;
    }
    if (can) {
        ans[cur] = 0;
    } else {
        ans[cur] = s[cur];
    }
    int curt = voc[ans[cur]];
    if (w[cur][curt] == cur) {
        for (int x = cur + 1; x < n; ++x) {
            for (int a = 0; a < 2; ++a) {
                w[x][a] += canbe[cur][curt][x][a];
            }
        }
        bool res = place(cur + 1, can);
        for (int x = cur + 1; x < n; ++x) {
            for (int a = 0; a < 2; ++a) {
                w[x][a] -= canbe[cur][curt][x][a];
            }
        }
        if (res) {
            return true;
        }
    }
    ++ans[cur];
    if (ans[cur] == l) return false;
    while(can == false)
    {
        curt = voc[ans[cur]];
        if (w[cur][curt] < cur) break;
        for (int x = cur + 1; x < n; ++x) {
            for (int a = 0; a < 2; ++a) {
                w[x][a] += canbe[cur][curt][x][a];
            }
        }
        bool res = place(cur + 1, true);
        for (int x = cur + 1; x < n; ++x) {
            for (int a = 0; a < 2; ++a) {
                w[x][a] -= canbe[cur][curt][x][a];
            }
        }
        if (res) {
            return true;
        }
        break;
    }
    while (voc[ans[cur]] == curt && ans[cur] < l) {
        ++ans[cur];
    }
    if (ans[cur] == l) return false;
    
    curt = voc[ans[cur]];
    if (w[cur][curt] < cur) return false;
    for (int x = cur + 1; x < n; ++x) {
        for (int a = 0; a < 2; ++a) {
            w[x][a] += canbe[cur][curt][x][a];
        }
    }
    bool res = place(cur + 1, true);
    for (int x = cur + 1; x < n; ++x) {
        for (int a = 0; a < 2; ++a) {
            w[x][a] -= canbe[cur][curt][x][a];
        }
    }
    if (res) {
        return true;
    }
    
    return false;
}
int main() {


    cin >> s;
    l = (int) s.size();
    FI(l) {
        voc[i] = (s[i] == 'V');
    }
    int m;
    cin >> n >> m;
    FI(m) {
        int x, y;
        char a, b;
        cin >> x >> a >> y >> b;
        --x; --y;
        a = (a == 'V');
        b = (b == 'V');
        v[x][a].push_back({y, b});
    }
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        s[i] -= 'a';
    }
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < 2; ++k) {
            memset(used, 0, sizeof(used));
            sx = i;
            sa = k;
            go(i, k);
            bool b = false;
            for (int j = 0; j < n; ++j) {
                if (used[j][0] && used[j][1]) { b = true; break; }
                if (used[j][0] && isbad[j][0]) { b = true; break; }
                if (used[j][1] && isbad[j][1]) { b = true; break; }
            }
            if (b) {
                isbad[i][k] = true;
            }
        }
        if (isbad[i][0] && isbad[i][1]) {
            DIE();
        }
        
        ans[i] = s[i];
    }
    for (int x = 0; x < n; ++x) {
        for (int a = 0; a < 2; ++a) {
            if (isbad[x][a]) {
                continue;
            }
            for (int y = 0; y < n; ++y) {
                for (int b = 0; b < 2; ++b) {
                    if (isbad[y][b]) { continue;};
                    if (way[x][a][y][1 - b]) continue;
                    canbe[x][a][y][b] = true;
                    for (int z = 0; z < n; ++z) {
                        canbe[x][a][y][b] &= !((way[x][a][z][0] && way[y][b][z][1]) ||
                                              (way[x][a][z][1] && way[y][b][z][0]));
                    }
                }
            }
        }
        for (int y = 0; y < n; ++y) {
            int t = canbe[x][0][y][0] + canbe[x][1][y][0] + canbe[x][1][y][1] + canbe[x][0][y][1];
            if (t == 0) {
                DIE();
            }
        }
    }






















    
    
    
    for (int i = 0; i < n; ++i) {
        if (i == -1) {
            DIE();
        }
        if (mustb[i]) {
            int curt = voc[ans[i]];
            bool ok = true;
            while (voc[ans[i]] == curt) {
                if (ans[i] == l) {
                    ok = false;
                    break;
                }
            }
        }
    }
    
    bool res = place(0);
    if (!res) {
        DIE();
    }
    if (iter > 200 * 50) {
        throw "LOL";
    }
    
    for (int i = 0; i < n; ++i) {
        s[i] = ans[i] + 'a';
    }
    cout << s << endl;
    return 0;
}

