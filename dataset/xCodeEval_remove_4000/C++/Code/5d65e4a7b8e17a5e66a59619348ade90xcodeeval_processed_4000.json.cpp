
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
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
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};














































template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < b){ a = b; return 1; } return 0; }
vector<ll> iota(ll n){ vector<ll> a(n); iota(a.begin(), a.end(), 0); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
map<ll,ll> factor_map(ull x){ map<ll,ll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans[i] = 1; while((x /= i) % i == 0) ans[i]++; } if(x != 1) ans[x] = 1; return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> map<T, ll> press_map(vector<T> a){ Uniq(a); map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
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
template<class T> void print(const complex<T>& a){ if(a.real() >= 0) print('+'); print(a.real()); if(a.imag() >= 0) print('+'); print(a.imag()); print('i'); }
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

inline ll __lg(ull __n){ return sizeof(ull) * __CHAR_BIT__  - 1 - __builtin_clzll(__n); }




int first(bool i = true){ return out(i?"first":"second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int id0(bool i = true){ return out(i?"id0":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case 


void solve(){
    ll min=LINF;
    VEC(pll,a,4);
    vector<pll>ans;
    auto check=[&](const vector<pll>&b)->ll{
        ll cnt=0;
        rep(4){
            if(a[i].first!=b[i].first&&a[i].second!=b[i].second)return 0;
            chmax(cnt,abs(a[i].first-b[i].first)+abs(a[i].second-b[i].second));
        }
        if(chmin(min,cnt))ans=b;
        return cnt;
    };
    rep(4)rep(j,4)rep(k,4){
        const ll x=a[i].first,x2=a[j].first,y=a[k].second;
        if(x>=x2)continue;
        const ll d=x2-x;
        {
            vector<pll>a={{x,y},{x,y+d},{x+d,y},{x+d,y+d}};
            Sort(a);
            do{
                if(check(a)){
                    each(i,a)i.second++;
                    if(check(a)){
                        each(i,a)i.second--;
                        ll l=-1e8,r=1e8;
                        while(r-l>=3){
                            ll cen1=(l+l+r)/3,cen2=(l+r+r)/3;
                            each(i,a)i.second+=cen1;
                            ll res1=check(a);
                            each(i,a)i.second-=cen1;
                            each(i,a)i.second+=cen2;
                            ll res2=check(a);
                            each(i,a)i.second-=cen2;
                            if(res1<res2)r=cen2;
                            else l=cen1;
                        }
                    }
                    else each(i,a)i.second--;
                }
            }while(next_permutation(all(a)));
        }
        {
            vector<pll>a={{x,y},{x,y-d},{x+d,y},{x+d,y-d}};
            Sort(a);
            do{
                if(check(a)){
                    each(i,a)i.second++;
                    if(check(a)){
                        each(i,a)i.second--;
                        ll l=-1e8,r=1e8;
                        while(r-l>=3){
                            ll cen1=(l+l+r)/3,cen2=(l+r+r)/3;
                            each(i,a)i.second+=cen1;
                            ll res1=check(a);
                            each(i,a)i.second-=cen1;
                            each(i,a)i.second+=cen2;
                            ll res2=check(a);
                            each(i,a)i.second-=cen2;
                            if(res1<res2)r=cen2;
                            else l=cen1;
                        }
                    }
                    else each(i,a)i.second--;
                }
            }while(next_permutation(all(a)));
        }
    }
    rep(4)rep(j,4)rep(k,4){
        const ll y=a[i].second,y2=a[j].second,x=a[k].first;
        if(y>=y2)continue;
        const ll d=y2-y;
        {
            vector<pll>a={{x,y},{x,y+d},{x+d,y},{x+d,y+d}};
            Sort(a);
            do{
                if(check(a)){
                    each(i,a)i.first++;
                    if(check(a)){
                        each(i,a)i.first--;
                        ll l=-1e8,r=1e8;
                        while(r-l>=3){
                            ll cen1=(l+l+r)/3,cen2=(l+r+r)/3;
                            each(i,a)i.first+=cen1;
                            ll res1=check(a);
                            each(i,a)i.first-=cen1;
                            each(i,a)i.first+=cen2;
                            ll res2=check(a);
                            each(i,a)i.first-=cen2;
                            if(res1<res2)r=cen2;
                            else l=cen1;
                        }
                    }
                    else each(i,a)i.first--;
                }
            }while(next_permutation(all(a)));
        }
        {
            vector<pll>a={{x,y},{x,y+d},{x-d,y},{x-d,y+d}};
            Sort(a);
            do{
                if(check(a)){
                    each(i,a)i.first++;
                    if(check(a)){
                        each(i,a)i.first--;
                        ll l=-1e8,r=1e8;
                        while(r-l>=3){
                            ll cen1=(l+l+r)/3,cen2=(l+r+r)/3;
                            each(i,a)i.first+=cen1;
                            ll res1=check(a);
                            each(i,a)i.first-=cen1;
                            each(i,a)i.first+=cen2;
                            ll res2=check(a);
                            each(i,a)i.first-=cen2;
                            if(res1<res2)r=cen2;
                            else l=cen1;
                        }
                    }
                    else each(i,a)i.first--;
                }
            }while(next_permutation(all(a)));
        }
    }
    rep(4)rep(j,4)rep(k,4){
        const ll x=a[i].first,x2=a[j].first,y=a[k].second;
        if(x>=x2)continue;
        const ll d=x2-x;
        {
            vector<pll>a={{x,y},{x,y+d},{x+d,y},{x+d,y+d}};
            Sort(a);
            do{
                check(a);
            }while(next_permutation(all(a)));
        }
        {
            vector<pll>a={{x,y},{x,y-d},{x+d,y},{x+d,y-d}};
            Sort(a);
            do{
                check(a);
            }while(next_permutation(all(a)));
        }
    }
    if(min==LINF)out(-1);
    else{
        out(min);
        each(i,ans)out(i);
    }
}
signed main(){
    LL(t);
    rep(t)solve();
}

