



 

























using namespace std;
 
typedef long long ll;
typedef double db;
int xx[4] = {1,-1,0,0};
int yy[4] = {0,0,1,-1};
const double eps = 1e-9;
typedef pair<int,int>  P;
typedef pair<ll,ll>  Pl;
typedef pair<double,double>  PP;
const int maxn = 2e6 + 5000;
const ll mod = 1e9 + 7;
const int INF(0x3f3f3f3f);
const ll INFL(0x3f3f3f3f3f3f3f3fll);
inline int sign(db a) { return a < -eps ? -1 : a > eps;}


 
ll mul(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll mulll(ll a,ll b,ll c) { ll res = 1; while(b) {  if(b & 1) res *= a,res %= c;  a *= a,a %= c,b >>= 1;  }  return res;}
ll phi(ll x) {  ll res = x;  for(ll i = 2; i * i <= x; i++) { if(x % i == 0) res = res / i * (i - 1);   while(x % i == 0) x /= i;   }  if(x > 1) res = res / x  * (x - 1);    return res;}
template <typename A, typename B> inline bool chmin(A &a, B b){if(a > b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline bool chmax(A &a, B b){if(a < b) {a = b; return 1;} return 0;}
template <typename A, typename B> inline ll add(A x, B y) {if(x + y < 0) return x + y + mod; return x + y >= mod ? x + y - mod : x + y;}
template <typename A, typename B> inline void add2(A &x, B y) {if(x + y < 0) x = x + y + mod; else x = (x + y >= mod ? x + y - mod : x + y);}
template <typename A, typename B> inline ll mul1(A x, B y) {return 1ll * x * y % mod;} 

template <typename A, typename B> inline void mul2(A &x, B y) {x = (1ll * x * y % mod + mod) % mod;} 

template <typename A> inline void debug(A a){cout << a << '\n';}
template <typename A> inline ll sqr(A x){return 1ll * x * x;}
template <typename A> A inv(A x) {return mulll(x, mod - 2,mod);}
template <typename A> void bugl(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template <typename A> void bug(A a[],int l,int r) { for(int i = l;i <= r;i++) cout << a[i] << " "; cout << endl;  }
template<class T>void wt(const T& x){cout << x << endl;}
template<class T>void wt(const T& x, char c){cout << x << c;}
template<class T>void wt(const T& x, const string& s){cout << x << s;}
template<class T>void wt(const T& x, int rnd){  cout << fixed << setprecision(rnd) << x << endl;}
template<class T> inline void read(T &x){  x=0; char c=getchar(); int f=1;  while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();} while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;}
inline ll lowbit(ll x){ return (x & (-x)); }
inline void debug(){  cout << "




 ll n;
 int vis[5050];
 vector<int>v[maxn];
 void dfs(int x){
    vis[x] = 1;
    for(auto &d:v[x]) if(!vis[d]) dfs(d);
    return ;
 }
 bool check(int x,int y){
    MS0(vis);
     dfs(x);
     return vis[y];
 }
int main() {
    int m;ios;
    while(cin >> n >> m) {
        vector<int>vv;
        int flag = 0;
        for(int i = 1; i <= m; i++) {
            int x,y;
            cin >> x >>y;
            if(check(y,x)) vv.pb(2),flag = 1;
            else vv.pb(1),
            v[x].pb(y);
        }
        wt(flag + 1);
        for(auto d:vv) cout << d << " ";
        cout << endl;
    }
    return 0;
}

