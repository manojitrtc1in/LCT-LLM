#include"bits/stdc++.h"
using namespace std; 
#define pb push_back
#define eb emplace_back
#define ins insert
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define lb lower_bound
#define ub upper_bound
#ifndef ONLINE_JUDGE
#define _getchar_nolock getchar_unlocked
#define pc putchar_unlocked
#else 
#define pc _putchar_nolock
#endif
#define F1 Flusher(); pc(' ');
#define F2 Flusher(); pc('\n');
#define sz(x) (int)x.size()
#define pii pair<int,int>
#define fir first
#define sec second
#define popcount __builtin_popcount 
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using ll=long long int;
using ld=long double;
#define mp make_pair
#define mt make_tuple
#define bit(x,j) (((ll)x>>j)&1)
#define um unordered_map 
#define mem(a,val) memset(a,val,sizeof(a))
void __print(int x) {cerr << x;} 
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;} 
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x){cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;} 
void __print(double x) {cerr << x;}
void __print(ld x){cerr << x;} 
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x){cerr<<'\"'<<x<<'\"';}
void __print(const string &x) {cerr<<'\"'<<x<<'\"';}
void __print(bool x){cerr<<(x?"true":"false");}
template<typename T, typename V>
void __print(const pair<T, V> &x){cerr<<'{'; __print(x.first);cerr<<','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) 
{ return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) 
{ return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")"; } 
void debug_out() { cerr << endl; } 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) 
{
  cerr << " " << to_string(H);
  debug_out(T...);
}
#ifndef ONLINE_JUDGE 
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
#ifndef ONLINE_JUDGE 
#define debugt(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debugt(...) 42
#endif
constexpr ll inf=2223372036854775807;
constexpr int mod1=(1e9+7);
constexpr int mod2=(998244353);
constexpr int MAX=(2e5+3);
namespace FastIO {
struct Reader {
private: FILE* file; std::vector<char> buffer; int pos; bool was;
void read(){ if(!buffer.empty()) {buffer.resize(fread(&buffer[0],1,(int)buffer.size(),file));pos=0;}}
public:
Reader(FILE* file_=stdin,const int size_=1<<16):file(file_),buffer(size_,'\0'),pos(size_),was(true){ }
operator bool() const {return was;}
char getChar(){ if(pos==(int)buffer.size()) { read();}
if(pos==(int)buffer.size()) { was=false; return EOF; } 
else{ was=true; return buffer[pos++]; } }
string getStr() {char c=' '; while(std::isspace(c)){ c=getChar(); }
string answ; while(c!=EOF&&!std::isspace(c)){answ.push_back(c); c= getChar();}
was=!answ.empty(); return answ; }
string getLine() { char c='\n'; string answ; 
while(c=='\n'){c=getChar();} 
while(c!='\n'&& c!=EOF){ answ.push_back(c);c=getChar(); }
was=!answ.empty(); return answ; }
template<typename T> T getInt(){char c='?'; 
while(!(c=='-'||('0'<=c&&c<='9')||c==EOF)){c=getChar();} bool positive=true; 
if(c=='-'){ positive=false; c=getChar(); } T answ(0); bool flag=false;
while('0'<=c && c<='9'){ flag=true;(answ*=10)+=(c-'0'); c= getChar(); }
was=flag; return positive?answ:-answ;}
template<typename T> T getReal(){ bool flag=false; char c='?';
while(!(c=='-'||('0'<=c&&c<='9')||c==EOF)){ c=getChar(); }
bool positive=(c!='-'); if(c=='-'){ c=getChar(); } ll first=0;
while('0'<=c&&c<='9'){ flag=true; (first*=10)+=(c-'0'); c= getChar(); }
was=flag; if(c!='.'){ return T(positive?first:-first); }
c=getChar(); ll second=0,pow=1;
while('0'<=c&&c<='9') { (second*=10)+=(c-'0'); c=getChar(); pow*=10; }
T answ=first+(T)second/(T)pow; return positive?answ:-answ; }    
};
Reader& operator>>(Reader& reader, char& c) { return c = reader.getChar(), reader; }
Reader& operator>>(Reader& reader, std::string& s) { return s = reader.getStr(), reader; }
template<class T> typename std::enable_if<std::is_floating_point<T>::value, Reader&>::type
operator>>(Reader& reader, T& t) { return t = reader.getReal<T>(), reader; }
template<class T> typename std::enable_if<std::is_integral<T>::value, Reader&>::type
operator>>(Reader& reader, T& t) { return t = reader.getInt<T>(), reader; }
template<class T> Reader& operator>>(Reader& reader, std::vector<T>& vec) {
for (auto &it : vec) { reader >> it; } return reader; }
struct Writer {
private: FILE* file; std::vector<char> buffer; int pos,defaultPrecision,defaultWidth; char defaultFill;
public: Writer(FILE* file_ = stdout, const int size_ = 1 << 16) 
: file(file_), buffer(size_, '\0'), pos(0), defaultPrecision(6), defaultWidth(0), defaultFill(' ') { }
~Writer() { flush(); }
void flush() { putChar(EOF); }
void setprecision(int precision) { defaultPrecision = precision; }
void setw(int width) { defaultWidth = width; }
void setfill(char fill) { defaultFill = fill; }
int getPrecision() const { return defaultPrecision; }
int getWidth() const { return defaultWidth; }
char getFill() const { return defaultFill; }
void putChar(char c) { if(pos==(int)buffer.size()||c==EOF){fwrite(&buffer[0],1,pos,file);pos=0;}
if(c!=EOF){ buffer[pos++]=c; } } void putStr(const std::string& s) { for (auto it : s) putChar(it); }
template<typename T> void putInt(T value, int width = 0, char fill = ' ') {
bool positive=!(value<0); if(value<0) { value=-value; } char buf[24]; int p=0;
do {buf[p++]=char(value % 10 + '0'); value /= 10; } while(value>0);
if(!positive){buf[p++]='-';} while(p<width) buf[p++]=fill; 
while(p>0)putChar(buf[--p]); }
template<typename T> void putReal(T value,int precision=6,int width=0,char fill=' ') {
putInt((long long)value,width-precision-1,fill); value=std::abs(value-(long long)value);
if (precision==0){ return; } putChar('.');
#define PRINT_PART(cnt, pow) while(precision>=cnt){value*=pow; putInt((int)value,cnt,'0'); value-=(int)value; precision-=cnt; }
PRINT_PART(6,1000000) PRINT_PART(3,1000) PRINT_PART(1,10) 
#undef PRINT_PART 
} };
Writer& operator<<(Writer& writer, const char c) { return writer.putChar(c), writer; }
Writer& operator<<(Writer& writer, const std::string& s) { return writer.putStr(s), writer; }
template<class T> typename std::enable_if<std::is_floating_point<T>::value, Writer&>::type
operator<<(Writer& writer, const T& t){writer.putReal(t,writer.getPrecision(),writer.getWidth(),writer.getFill());
return writer; }
template<class T> typename std::enable_if<std::is_integral<T>::value, Writer&>::type
operator<<(Writer& writer, const T& t){writer.putInt(t,writer.getWidth(),writer.getFill());
return writer; } }
template<typename V>
inline void rd(V &x) { char c; while(c=_getchar_nolock(),c<=' '); bool sign(c=='-');
if(sign){ c=_getchar_nolock(); } x=(c-'0');
while(c=_getchar_nolock(),!((c<'0')|(c>'9'))) {x=10*x+c-'0';} if(sign) x=-x; }
template<typename H,typename... T>
void rd(H& h, T&... t) { rd(h); rd(t...); }
static const int buf_len=(1<<14); static const int buf_max=(1<<04);
static char buf_out[buf_len]; static char buf_num[buf_max];
static int buf_pos = 0;
template <typename T>
inline void writeChar(T x){ if(buf_pos==buf_len)fwrite(buf_out,1,buf_len,stdout),buf_pos=0;
buf_out[buf_pos++]=x; }
template <typename L>
inline void print(L x, char end=0){  if(abs(x)>1000000000000000){ cout<<x; return; }  if(x<0) writeChar('-'), x=-x; int n=0;
do buf_num[n++]=x%10+'0'; while(x/=10); while (n--) writeChar(buf_num[n]); if(end) writeChar(end);}
struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out,1,buf_pos,stdout),buf_pos=0;}}flusher;
template<typename H,typename... T> void print(H h, T... t) { print(h); F1; print(t...); }
template<typename T> void print(vector<T>v){ for(auto i:v){ print(i); F1; } }
template<typename T> void print(set<T>v){ for(auto i:v){ print(i); F1; } }
template<typename R> void input(vector<R>&a,int n){ rep(i,0,n-1) rd(a[i]); }
template<typename T,typename V> T ce(T a,V b){ if(a<0) return a/b; T res;if(a%b==0)res=a/b; else res=a/b+1; return res; }
template<typename W,typename F> W fl(W a,F b){ if(abs(a)%abs(b)==0) return a/b; if(a<0) return a/b-1; return a/b; }
ll multiplym2(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod2; b>>=1;a=(a*2)%mod2; } return res; }
ll multiplym1(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod1; b>>=1;a=(a*2)%mod1; } return res; }
ll multiply(ll a,ll b){ ll res=0; while(b) { if(b&1) res+=a; b>>=1;a=(a<<1); } return res; }
ll powerm2(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod2; a=(a*a)%mod2; b>>=1; } return res; }
ll powerm1(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod1; a=(a*a)%mod1; b>>=1; } return res; }
ll power(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a); a=(a*a); b>>=1; } return res; }
ll fact[MAX+7];
void fac(){ fact[0]=1; fact[1]=1; rep(i,2,MAX-1) fact[i]=(fact[i-1]*i)%mod1; }
ll modInv(int n){ return powerm1(n,mod1-2); }
int ncr(int n,int r){ if (r==0) return 1; return (fact[n]*modInv(fact[r])%mod1*modInv(fact[n-r])%mod1)%mod1; }
template<typename T,typename V>
int find_divisor_power(T n,V a){ T res=1; int p=-1; while(n%res==0){ p++; res*=a; } return p; }
template<typename T,typename V> T find_exponent(T n,V p){ T x=0; while(n){ n/=p; x+=n; } return x; }
template<typename L>void factorise(L a,vector<L>&f){ int limit=sqrt(a); rep(i,1,limit) { if(a%i==0) { f.push_back(i); if(i!=a/i) f.push_back(a/i); } } }
vector<int>prime; 
void sieve(int limit){prime.eb(2);prime.eb(3);bool sieve[limit];for(int i=0;i<limit;i++)sieve[i]=false; 
for(int x=1; x*x<limit;x++) 
{ 
    for(int y=1;y*y<limit;y++){int n=(4*x*x)+(y*y);
    if(n<=limit&&(n%12==1||n%12==5)){sieve[n]^=true;}n=(3*x*x)+(y*y);if(n<=limit&&n%12==7){ sieve[n]^=true; }
    n=(3*x*x)-(y*y);if(x>y&&n<=limit&&n%12==11){sieve[n]^=true;} } } 
    for(int r=5;r*r<limit;r++){ if(sieve[r]) { for(int i=r*r;i<limit;i+=r*r) sieve[i]=false; } } 
    for(int a=5;a<limit;a++) { if(sieve[a]) prime.eb(a); }
} 
void dfs(int s,vector<vector<int>>v,vector<int>f)
{
    stack<int>q; q.push(s); while(!q.empty()){ int m=q.top(); q.pop(); f[m]=1; 
    for(auto i=v[m].begin();i!=v[m].end();++i){ if(!f[*i]) { q.push(*i); f[*i]=1; } } }
}
void bfs(int s,vector<vector<int>>v,vector<int>f)
{
    queue<int>q; q.push(s); f[s]=1; while(!q.empty()) { int m=q.front(); q.pop();
    for(auto i=v[m].begin();i!=v[m].end();++i){ if(!f[*i]) { f[*i]=1; q.push(*i); } } }
}
template<typename G>void primeFactors(G n,vector<G>&pf){if(n%2==0) pf.eb(2); while(n%2==0)n=n/2;
int limit=sqrt(n);for(int i=3;i<=limit;i=i+2){ if(n%i==0) pf.eb(i); while(n%i==0) n=n/i;}if(n>2) pf.eb(n);}  
template<typename T> int find_highest_set_bit(T n){repr(i,60,0) { if(bit(n,i)) return i; } }
vector<int> divisor[MAX+7];void sieve(){ rep(i,1,MAX){ for(int j=i;j<=MAX;j+=i) divisor[j].eb(i); } }
template <typename T> bool ispowertwo (T x) { return x&&(!(x&(x-1))); }
template <typename T> bool isPrime(T n){ if(n<=1) return false; if(n<=3) return true; 
if(n%2==0||n%3==0) {return false;} for(int i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) {return false;} return true; }
template<typename T> int lbd(vector<T>&v,T p)
{
  if(v[0]>=p) {return 0;} if(v[sz(v)-1]<p) return -1;
  auto it=lb(all(v),p); return it-v.begin();  
}
template<typename T> int ubd(vector<T>&v,T p)
{
  if(v[0]>p) {return 0;} if(v[sz(v)-1]<p) return -1;
  auto it=ub(all(v),p); return it-v.begin();  
}
void getZarr(string str,vector<int>&Z)
{
    int n=str.length(),L,R,k; L=R=0;
    for(int i=1;i<n;++i){ if(i>R){ L=R=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;}
    else{ k=i-L; if(Z[k]<R-i+1) Z[i]=Z[k]; else{L=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;} } }
}
void zfunc(string text,string pattern,vector<int>&index)
{
    string concat=pattern+"$"+text; int l=concat.length(); vector<int>Z(l); getZarr(concat,Z);
    rep(i,0,l-1){ if(Z[i]==(int)pattern.length()) index.eb(i-pattern.length()-1); }
}
template<typename A,typename B> B largest_power_less_than(A n,B a){ A res=1; B p=-1; while(n>res){ res*=a; p++; } return p; } 
template<typename A,typename B> B largest_power_less_or_equal_to(A n,B a){ A res=1; B p=-1; while(n>=res){ res*=a; p++; } return p; } 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
int spf[MAX]; 
void spf_compute() 
{ 
    spf[1]=1; for(int i=2;i<MAX;i++) spf[i]=i; for(int i=4;i<MAX;i+=2)spf[i]=2; 
    for(int i=3;i*i<MAX;i++){ if(spf[i]==i){ for(int j=i*i;j<MAX;j+=i)if(spf[j]==j)spf[j]=i; } } 
} 
constexpr int N=2*100010; 
int n; vector<int>v[N]; vector<int>g[N]; vector<int>cnt[N]; int a[N]; 
void getPF(int x,int i)
{ 
  um<int,int,custom_hash>repeat; 
  while(x!=1){ if(!repeat[spf[x]]){ cnt[spf[x]].eb(i);  repeat[spf[x]]=1; } x=x/spf[x]; }  
} 
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll a, ll b) { return uniform_int_distribution<ll>(a, b)(rng); }
 
template<class T> bool ckmin(T& a, const T& b) { return b < a ? a = b, 1 : 0; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a = b, 1 : 0; }
template<class T> void uni(vector<T>& v) { sor(v); v.erase(unique(all(v)), end(v)); }
int cdiv(const ll& a, const ll& b) { return a / b + ((a ^ b) > 0 && a % b); } 

int fdiv(const ll& a, const ll& b) { return a / b - ((a ^ b) < 0 && a % b); } 

int pct(int x) { x = (x & 0x5555555555555555LL) + ((x >> 1) & 0x5555555555555555LL); x = (x & 0x3333333333333333LL) + ((x >> 2) & 0x3333333333333333LL); x = (x & 0x0F0F0F0F0F0F0F0FLL) + ((x >> 4) & 0x0F0F0F0F0F0F0F0FLL); return (x * 0x0101010101010101LL) >> 56; }


 


#define ts to_string
string ts(char c) { return string(1, c); }
string ts(bool b) { return b ? "true" : "false"; }
string ts(const char* s) { return (string)s; }
string ts(string s) { return s; }
template<size_t SZ> string ts(bitset<SZ> b) { string res = ""; for(int i = 0; i < (ll)SZ; i++) { res += char('0' + b[i]); } return res; }
template<class A, class B> string ts(pair<A, B> p) { return "(" + ts(p.f) + ", " + ts(p.s) + ")"; }
template<class T> string ts(T v) { bool fst = 1; string res = "{"; for(const auto& x: v) { if(!fst) { res += ", "; } fst = 0; res += ts(x); } res += "}"; return res; }
void DBG() { cerr << "]" << endl; }
template<class H, class... T> void DBG(H h, T... t) { cerr << ts(h); if(sizeof...(t)) { cerr << ", "; } DBG(t...); }
void EDBG(string names) { names = names; } 
#ifdef LOCAL 

#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]: [", DBG(__VA_ARGS__)
#define edbg(...) EDBG(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 42
#define edbg(...) 7
#endif
 
const int MX = 2e5 + 5;
const long long INF = 1e18;
const long long MOD = 1e9 + 7; 

const long double PI = acos((ld)-1);
const long double EPS = 1e-18;
 
namespace NT{
    template<typename T>
    struct bigger_type{};
    template<typename T> using bigger_type_t = typename bigger_type<T>::type;
    template<> struct bigger_type<int>{using type = long long;};
    template<> struct bigger_type<unsigned int>{using type = unsigned long long;};

    template<typename int_t = unsigned long long>
    struct Mod_Int{
        static inline int_t add(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = a+b;
            if(ret>=mod) ret-=mod;
            return ret;
        }
        static inline int_t sub(int_t const&a, int_t const&b, int_t const&mod){
            return add(a, mod-b);
        }
        static inline int_t mul(int_t const&a, int_t const&b, int_t const&mod){
            uint64_t ret = a * (uint64_t)b - (uint64_t)((long double)a * b / mod - 1.1) * mod;
      if(-ret < ret){
        ret = mod-1-(-ret-1)%mod;
      } else {
        ret%=mod;
      }
      int64_t out = ret;
      return out;
        }
        static inline int_t pow(int_t const&a, int_t const&b, int_t const&mod){
            int_t ret = 1;
            int_t base = a;
            for(int i=0;b>>i;++i){
                if((b>>i)&1) ret = mul(ret, base, mod);
                base = mul(base, base, mod);
            }
            return ret;
        }
    };
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type is_prime(T x){
        if(x<T(4)) return x>T(1);
        for(T i=2;i*i<=x;++i){
            if(x%i == 0) return false;
        }
        return true;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_single(T const&x, T base){
        if(x<T(4)) return x>T(1);
        if(x%2 == 0) return false;
        base%=x;
        if(base == 0) return true;
 
        T xm1 = x-1;
        int j = 1;
        T d = xm1/2;
        while(d%2 == 0){ 

            d/=2;
            ++j;
        }
        T t = Mod_Int<T>::pow(base, d, x);
        if(t==T(1) || t==T(xm1)) return true;
        for(int k=1;k<j;++k){
            t = Mod_Int<T>::mul(t, t, x);
            if(t == xm1) return true;
            if(t<=1) break;
        }
        return false;
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&){return true;}
    template<typename T, typename... S>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin_multi(T const&x, T const&base, S const&...bases){
        if(!miller_rabin_single(x, base)) return false;
        return miller_rabin_multi(x, bases...);
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, bool>::type miller_rabin(T const&x){
        if(x < 316349281) return miller_rabin_multi(x, T(11000544), T(31481107));
        if(x < 4759123141ull) return miller_rabin_multi(x, T(2), T(7), T(61));
        return miller_rabin_multi(x, T(2), T(325), T(9375), T(28178), T(450775), T(9780504), T(1795265022));
    }
 
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type isqrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(sqrtl(x));
        while(ret>0 && ret*ret>x) --ret;
        while(x-ret*ret>2*ret)
            ++ret;
        return ret;
    }
    template<typename T>
    typename enable_if<is_integral<T>::value, T>::type icbrt(T const&x){
        assert(x>=T(0));
        T ret = static_cast<T>(cbrt(x));
        while(ret>0 && ret*ret*ret>x) --ret;
        while(x-ret*ret*ret>3*ret*(ret+1))
            ++ret;
        return ret;
    }
    vector<uint16_t> saved;
    uint64_t squfof_iter_better(uint64_t const&x, uint64_t const&k, uint64_t const&it_max, uint32_t cutoff_div){
        if(__gcd((uint64_t)k, x)!=1) return __gcd((uint64_t)k, x);
        

        saved.clear();
        uint64_t scaledn = k*x;
        if(scaledn>>62) return 1;
        uint32_t sqrtn = isqrt(scaledn);
        uint32_t cutoff = isqrt(2*sqrtn)/cutoff_div;
        uint32_t q0 = 1;
        uint32_t p1 = sqrtn;
        uint32_t q1 = scaledn-p1*p1;
 
        if(q1 == 0){
            uint64_t factor = __gcd(x, (uint64_t)p1);
            return factor==x ? 1:factor;
        }
 
        uint32_t multiplier = 2*k;
        uint32_t coarse_cutoff = cutoff * multiplier;
        

 
        uint32_t i, j;
        uint32_t p0 = 0;
        uint32_t sqrtq = 0;
 
        for(i=0;i<it_max;++i){
            uint32_t q, bits, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (q1 < coarse_cutoff) {
                tmp = q1 / __gcd(q1, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t)tmp);
                }
            }
 
            bits = 0;
            tmp = q0;
            while(!(tmp & 1)) {
                bits++;
                tmp >>= 1;
            }
            if (!(bits & 1) && ((tmp & 7) == 1)) {
 
                sqrtq = (uint32_t)isqrt(q0);
 
                if (sqrtq * sqrtq == q0) {
                    for(j=0;j<saved.size();++j){
                        if(saved[j] == sqrtq) break;
                    }
                    if(j == saved.size()) break;
                    

                }
            }
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (q0 < coarse_cutoff) {
                tmp = q0 / __gcd(q0, multiplier);
 
                if (tmp < cutoff) {
                    saved.push_back((uint16_t) tmp);
                }
            }
        }
 
        if(sqrtq == 1) { return 1;}
        if(i == it_max) { return 1;}
 
        q0 = sqrtq;
        p1 = p0 + sqrtq * ((sqrtn - p0) / sqrtq);
        q1 = (scaledn - (uint64_t)p1 * (uint64_t)p1) / (uint64_t)q0;
 
        for(j=0;j<it_max;++j) {
            uint32_t q, tmp;
 
            tmp = sqrtn + p1 - q1;
            q = 1;
            if (tmp >= q1)
                q += tmp / q1;
 
            p0 = q * q1 - p1;
            q0 = q0 + (p1 - p0) * q;
 
            if (p0 == p1) {
                q0 = q1;
                break;
            }
 
            tmp = sqrtn + p0 - q0;
            q = 1;
            if (tmp >= q0)
                q += tmp / q0;
 
            p1 = q * q0 - p0;
            q1 = q1 + (p0 - p1) * q;
 
            if (p0 == p1)
                break;
        }
        if(j==it_max) {cerr << "RNG\n"; return 1;} 

 
        uint64_t factor = __gcd((uint64_t)q0, x);
        if(factor == x) factor=1;
        return factor;
    }
    uint64_t squfof(uint64_t const&x){
        static array<uint32_t, 16> multipliers{1, 3, 5, 7, 11, 3*5, 3*7, 3*11, 5*7, 5*11, 7*11, 3*5*7, 3*5*11, 3*7*11, 5*7*11, 3*5*7*11};
 
        uint64_t cbrt_x = icbrt(x);
        if(cbrt_x*cbrt_x*cbrt_x == x) return cbrt_x;
 
        

        uint32_t iter_lim = 300;
        for(uint32_t iter_fact = 1;iter_fact<20000;iter_fact*=4){
            for(uint32_t const&k : multipliers){
                if(numeric_limits<uint64_t>::max()/k<=x) continue; 

                uint32_t const it_max = iter_fact*iter_lim;
                uint64_t factor = squfof_iter_better(x, k, it_max, 1);
                if(factor==1 || factor==x) continue;
                return factor;
            }
        }
        cerr << "failed to factor: " << x << "\n";
        assert(0);
        assert(0);
        return 1;
    }
    template<typename T>
    void factorize(T x,int idx){
      um<int,int,custom_hash>done; 
        const uint32_t trial_limit = 5000;
    auto trial = [&](uint32_t const&i){
      while(x%i == 0){
                x/=i;
                if(!done[i]){ cnt[i].eb(idx); done[i]=1; }
            }
    };
    trial(2);
    trial(3);
        for(uint32_t i=5, j=2;i<trial_limit && i*i <= x;i+=j, j=6-j){
            trial(i);
        }
        if(x>1){
            static stack<T> s;
            s.push(x);
            while(!s.empty()){
                x = s.top(); s.pop();
                if(!miller_rabin(x)){
                    T factor = squfof(x);
                    if(factor == 1 || factor == x){assert(0); return ;}
                    

                    s.push(factor);
                    s.push(x/factor);
                } else {
                    if(!done[x]){ cnt[x].eb(idx); done[x]=1; }
                }
            }
        }
        
    }
}
template<typename T>ll sumy(vector<T>&v){ ll s=0; for(auto i:v)s+=i; return s; }
template<typename T>T max_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=max(m,v[i]); } return m; }
template<typename T>T min_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=min(m,v[i]); } return m; }
template<typename T>int max_ele_ind(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(m<v[i]){ m=v[i]; ind=i;} } } return ind; }
template<typename T>int min_ele_ind(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(v[i]<m){ m=v[i]; ind=i; }} } return ind; }
int ans=0; int cc=0; int used[N],d[N]; 
pii bfs(int x,set<int>& used_vertices)
{
    cc++;
    queue<int>q; q.push(x); d[x]=1;
    used[x]=cc;
    pii ans={x,d[x]};
    while(!q.empty())
    {
        int k=q.front();
        used_vertices.ins(k);
        q.pop(); ans={k,d[k]};
        for(auto y:g[k])
        {
            if(used[y]!=cc)
            {
                used[y]=cc; d[y]=d[k]+1;
                q.push(y);
            }
        }
    }
    return ans;
}
void solve(int p)
{
  for(auto i:cnt[p])
  {
   g[i].clear(); 
   for(auto j:v[i])
   {
     if(a[j]%p==0) { g[i].eb(j); }
   }
  }
  set<int>f; 
  for(auto x:cnt[p])
  {
    if(f.count(x)) continue; 
      pii z=bfs(x,f);
      pii z2=bfs(z.first,f);
      ans=max(ans, z2.second);
  }
}
void solve()
{ 
 rd(n); rep(i,1,n){ rd(a[i]); NT::factorize(a[i],i); } int x,y; 
 rep(i,0,n-2){ rd(x,y); v[x].eb(y); v[y].eb(x); }
 rep(i,0,sz(prime)-1)
 {
  if(sz(cnt[prime[i]])!=0)
  {
    solve(prime[i]); 
  }
 }
 print(ans); F2; return; 
}
int main() 
{
  FastIO::Reader cin; FastIO::Writer cout; cout.setprecision(9);
  #ifndef ONLINE_JUDGE
  clock_t start=clock();
  #endif
  #ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  #endif
  spf_compute(); sieve(2*100003); 
  int t=1,c=1; 
  while(t--)
  { 
    #ifndef ONLINE_JUDGE
    pc('T');pc('e');pc('s');pc('t');pc('c');pc('a'); pc('s'); pc('e'); pc(' ');
    pc('#');pc(' '); print(c); F2;
    #endif 
    solve(); c++; 
  }
  #ifndef ONLINE_JUDGE
  clock_t end=clock();
  double time_taken=double(end-start)/double(CLOCKS_PER_SEC); 
  cout<<"Time taken: "<<time_taken; 
  cout<<" sec \n"; 
  #endif
  return 0;
}     
