
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned int;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<double, double>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, 1, -1, -1};
const ll dy[] = {1, 0, -1, 0, 1, -1, 1, -1};










































template<class T> auto max(const T& a){ return *max_element(all(a)); }
template<class T> auto min(const T& a){ return *min_element(all(a)); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
vector<pll> factor(ull x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ll i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); unordered_map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
template<class T> map<T, ll> press_map(vector<T>& a){ auto b = a; sort(all(b)); b.erase(unique(all(b)), b.end()); map<T,ll> ans; rep(b.size()) ans[b[i]] = i; each(i, a) i = ans[i]; return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class Head, class... Tail> void in(Head& head, Tail&... tail){ scan(head); in(tail...); }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }

void err(){ putchar('\n'); }
template<class T> void err(const T& t){ print(t); putchar('\n'); }
template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }

template<class... T> void err(const T&...){}

int first(bool i = true){ return out(i?"first":"second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int id1(bool i = true){ return out(i?"id1":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case 


uint mod = MOD;
struct Modint{
    uint num = 0;
    Modint() noexcept {}
    Modint(const Modint &x) noexcept : num(x.num){}
    inline operator ll() const noexcept { return num; }
    inline Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    inline Modint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    inline Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    inline Modint operator-() const noexcept { return Modint(0) -= *this; }
    inline Modint operator-(Modint x) const noexcept { return Modint(*this) -= x; }
    inline Modint& operator-=(Modint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    inline Modint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    inline Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    inline Modint& operator*=(Modint x) noexcept { num = ull(num) * x.num % mod; return *this; }
    inline Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = uint(y);
    }
    template<class T> inline Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> inline Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> inline Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> inline Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> inline Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> inline Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> inline Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> inline Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    inline Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static inline ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    inline Modint pow(ull x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
    };
    std::istream& operator>>(std::istream& is, Modint& x){ ll a; in(a); x = a; return is; }
    inline Modint operator""_M(ull x) noexcept { return Modint(x); }
    std::vector<Modint> fac(1, 1), inv(1, 1);
    inline void reserve(ll a){
        if(fac.size() >= a) return;
        if(a < fac.size() * 2) a = fac.size() * 2;
        if(a >= mod) a = mod;
        while(fac.size() < a) fac.push_back(fac.back() * Modint(fac.size()));
        inv.resize(fac.size());
        inv.back() = fac.back().inv();
        for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
    }
    inline Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
    inline Modint perm(ll n, ll r){
        if(r < 0 || n < r) return 0;
        if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
        reserve(n + 1); return fac[n] * inv[n - r];
    }
    inline Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(r + 1); return perm(n, r) * inv[r]; }
    inline Modint Mcomb(ll n, ll r){ return comb(n + r - 1, n - 1); } 

    inline Modint id0(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
signed main(){
    LL(n,m);
    mod=m;
    vector<bool>can_use(m+1,1);
    can_use[0]=0;
    rep(n){
        LL(a);
        if(!a)a=m;
        can_use[a]=0;
    }
    vector<ll>p;
    each(i,factor(m))p.push_back(i.first);
    vector<vector<ll>>candidate(m+1);
    rep(i,1,m+1)if(can_use[i])candidate[gcd(m,i)].push_back(i);
    vector<ll>dp(m+1,-LINF),back(m+1,-1);
    dp[m]=0;
    rrep(i,1,m+1){
        each(j,p)if(i*j<=m&&chmax(dp[i],dp[i*j]))back[i]=j;
        dp[i]+=candidate[i].size();
    }
    vector<ll>ans;
    ll at=1;
    while(1){
        each(i,candidate[at])ans.push_back(i);
        if(at==m)break;
        at*=back[at];
    }
    rrep(i,1,ans.size()){
        ll a=ans[i-1],b=ans[i],g=gcd(a,m);
        mod=m/g;
        a/=g;
        b/=g;
        ans[i]=Modint(b)/Modint(a);
    }
    each(i,ans)i%=m;
    out(ans.size());
    out(ans);
}
