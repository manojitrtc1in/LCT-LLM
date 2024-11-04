#include"bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define repr(i,a,b) for(int i=a;i>=b;i--)
#define lb lower_bound
#define ub upper_bound
#define F1 Flusher(); pc(' ');
#define F2 Flusher(); pc('\n');
#define sz(x) (int)x.size()
#define pii pair<int,int>
#define fir first
#define sec second
#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
using namespace std;
using namespace std::chrono;
using namespace __gnu_pbds;
using ll=long long int;
using ld=long double;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> vecset;
#define pc _putchar_nolock
#define mp make_pair
#define mt make_tuple
#define um unordered_map
#define find_ind order_of_key
#define find_ele find_by_order 
#define inf (ll)9223372036854775807
#define mod (ll)(1e9+7)
#define MAX (int)(1e5+3)
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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
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
inline void read(V &x) { char c; while(c=_getchar_nolock(),c<=' '); bool sign(c=='-');
if(sign)c=_getchar_nolock(); x=(c-'0');
while(c=_getchar_nolock(),!(c<'0'|c>'9')) x=10*x+c-'0'; if(sign) x=-x; }
template<typename H,typename... T>
void read(H& h, T&... t) { read(h); read(t...); }
static const int buf_len=(1<<14); static const int buf_max=(1<<04);
static char buf_out[buf_len]; static char buf_num[buf_max];
static int buf_pos = 0;
template <typename T>
inline void writeChar(T x){ if(buf_pos==buf_len)fwrite(buf_out,1,buf_len,stdout),buf_pos=0;
buf_out[buf_pos++]=x; }
template <typename L>
inline void print(L x, char end=0){ if(x<0) writeChar('-'), x=-x; int n=0;
do buf_num[n++]=x%10+'0'; while(x/=10); while (n--) writeChar(buf_num[n]); if(end) writeChar(end);}
struct Flusher{~Flusher(){if(buf_pos)fwrite(buf_out,1,buf_pos,stdout),buf_pos=0;}}flusher;
template<typename R> void input(vector<R>&a,int n){ rep(i,0,n-1) read(a[i]); }
template<typename T,typename V> T ce(T a,V b){  T res;if(a%b==0)res=a/b; else res=a/b+1; return res; }
ll power(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod; a=(a*a)%mod; b>>=1; } return res; }
ll multiply(ll a,ll b){ ll res=0; while(b) { if(b&1) res+=a; b>>=1;a=(a<<1); } return res; }
ll fact[MAX];
void fac(){ fact[0]=1; fact[1]=1; rep(i,2,MAX-1) fact[i]=(fact[i-1]*i)%mod; }
ll modInv(int n){ return power(n,mod-2); }
int ncr(int n,int r){ if (r==0) return 1; return (fact[n]*modInv(fact[r])%mod*modInv(fact[n-r])%mod)%mod; }
template<typename T,typename V>
int find_divisor_power(T n,V a){ T res=1; int p=-1; while(n%res==0){ p++; res*=a; } return p; }
template<typename T,typename V>
T find_exponent(T n,V a){ T res=0; T p=a; T add=n/p; while(add>0) { res+=add; p*=a;  add=n/p; } return res; }
void factorise(int a,vector<int>&f){ rep(i,1,sqrt(a)){ if(a%i==0) { f.push_back(i); if(i!=a/i) f.push_back(a/i); } } }
vector<int>prime;
void sieve(int limit){prime.eb(2);prime.eb(3);bool sieve[limit];for(int i=0;i<limit;i++)sieve[i]=false; 
for(int x=1; x*x<limit;x++) 
{ 
    for(int y=1;y*y<limit;y++){int n=(4*x*x)+(y*y);
    if(n<=limit&&(n%12==1||n%12==5))sieve[n]^=true;n=(3*x*x)+(y*y);if(n<=limit&&n%12==7) sieve[n]^=true; 
    n=(3*x*x)-(y*y);if(x>y&&n<=limit&&n%12==11)sieve[n]^=true; } } 
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
vector<int>pf; void primeFactors(int n){if(n%2==0) pf.eb(2); while(n%2==0)n=n/2;
int limit=sqrt(n);for(int i=3;i<=limit;i=i+2){ if(n%i==0) pf.eb(i); while(n%i==0) n=n/i;}if(n>2) pf.eb(n);}  
template<typename T> int find_highest_set_bit(T n){repr(i,64,0) { if(n&(1<<i)) return i; } }
vector<int> divisor[MAX];void sieve(){ rep(i,1,MAX){ for(int j=i;j<=MAX;j+=i) divisor[j].eb(i); } }
template <typename T> bool ispowertwo (T x) { return x&&(!(x&(x-1))); }
template <typename T> bool isPrime(T n){ if(n<=1) return false; if(n<=3) return true; 
if(n%2==0||n%3==0) return false; for(int i=5;i*i<=n;i=i+6) if(n%i==0||n%(i+2)==0) return false; return true; }
void getZarr(string str,vector<int>&Z)
{
    int n=str.length(),L,R,k; L=R=0;
    for(int i=1;i<n;++i)
    {
       if(i>R){ L=R=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L;  R--;}
        else
        {
            k=i-L; if(Z[k]<R-i+1) Z[i]=Z[k]; else{ L=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--; }
        }
    }
}
void zfunc(string text,string pattern,vector<int>&index)
{
    string concat = pattern + "$" + text; int l=concat.length(); vector<int>Z(l); getZarr(concat,Z);
    rep(i,0,l-1){ if(Z[i]==pattern.length()) index.eb(i-pattern.length()-1); }
}
template<typename T,typename V>
V largest_power_less_than(T n,V a){ T res=1; V p=-1; while(n>res){ res*=a; p++; } return p; } 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
void solve()
{
 int n; read(n); if(n==1){ print(1); F2; return; }
 if(n==2){ print(1); F1; print(2); F2; return; }
 if(n==3){print(2); F1; print(3); F1; print(1); F2; return; }
 int l=floor(sqrt((ld)n)); um<int,int,custom_hash>g;   
 for(int c=n;c>=1;c-=l)
 { 
  rep(i,c-l+1,c)
  { 
   if(i>0 and g[i]==0)
   { print(i); F1 g[i]=1; }
  }
 }
}
int main() 
{
  FastIO::Reader cin; FastIO::Writer cout; cout.setprecision(9);
  #ifndef ONLINE_JUDGE
  auto start=high_resolution_clock::now();
  #endif
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
  auto stop=high_resolution_clock::now();
  auto duration=duration_cast<microseconds>(stop-start);
  cout<<"duration-> "<<duration.count()<<" microseconds\n";
  #endif
  return 0;
}      