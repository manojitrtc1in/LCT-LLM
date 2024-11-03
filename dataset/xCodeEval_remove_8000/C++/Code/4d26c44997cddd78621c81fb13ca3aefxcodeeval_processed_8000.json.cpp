
using namespace std; 


























using ll=long long int;
using ld=long double;





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










constexpr ll inf=2223372036854775807;
constexpr int mod1=(1e9+7);
constexpr int mod2=(998244353);
constexpr int MAX=(1e5+3);
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

PRINT_PART(6,1000000) PRINT_PART(3,1000) PRINT_PART(1,10) 

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
ll id7(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod2; b>>=1;a=(a*2)%mod2; } return res; }
ll id8(ll a,ll b){ ll res=0; while(b) { if(b&1) res=(res+a)%mod1; b>>=1;a=(a*2)%mod1; } return res; }
ll multiply(ll a,ll b){ ll res=0; while(b) { if(b&1) res+=a; b>>=1;a=(a<<1); } return res; }
ll id1(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod2; a=(a*a)%mod2; b>>=1; } return res; }
ll id4(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a)%mod1; a=(a*a)%mod1; b>>=1; } return res; }
ll power(ll a,ll b){ ll res=1; while(b) { if(b&1) res=(res*a); a=(a*a); b>>=1; } return res; }
ll fact[MAX+7];
void fac(){ fact[0]=1; fact[1]=1; rep(i,2,MAX-1) fact[i]=(fact[i-1]*i)%mod1; }
ll modInv(int n){ return power(n,mod1-2); }
int ncr(int n,int r){ if (r==0) return 1; return (fact[n]*modInv(fact[r])%mod1*modInv(fact[n-r])%mod1)%mod1; }
template<typename T,typename V>
int id9(T n,V a){ T res=1; int p=-1; while(n%res==0){ p++; res*=a; } return p; }
template<typename T,typename V> T id3(T n,V p){ T x=0; while(n){ n/=p; x+=n; } return x; }
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
template<typename T> int id6(T n){repr(i,60,0) { if(bit(n,i)) return i; } }
vector<int> divisor[MAX+7];void sieve(){ rep(i,1,MAX){ for(int j=i;j<=MAX;j+=i) divisor[j].eb(i); } }
template <typename T> bool id11 (T x) { return x&&(!(x&(x-1))); }
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
void id2(string str,vector<int>&Z)
{
    int n=str.length(),L,R,k; L=R=0;
    for(int i=1;i<n;++i){ if(i>R){ L=R=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;}
    else{ k=i-L; if(Z[k]<R-i+1) Z[i]=Z[k]; else{L=i; while(R<n && str[R-L]==str[R]) R++; Z[i]=R-L; R--;} } }
}
void zfunc(string text,string pattern,vector<int>&index)
{
    string concat=pattern+"$"+text; int l=concat.length(); vector<int>Z(l); id2(concat,Z);
    rep(i,0,l-1){ if(Z[i]==(int)pattern.length()) index.eb(i-pattern.length()-1); }
}
template<typename A,typename B> B id13(A n,B a){ A res=1; B p=-1; while(n>res){ res*=a; p++; } return p; } 
template<typename A,typename B> B id10(A n,B a){ A res=1; B p=-1; while(n>=res){ res*=a; p++; } return p; } 
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x+=0x9e3779b97f4a7c15; x=(x^(x>>30))*0xbf58476d1ce4e5b9; x=(x^(x>>27))*0x94d049bb133111eb; return x^(x>>31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t id5=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+id5);
    }
};
int spf[MAX]; 
void spf_compute() 
{ 
    spf[1]=1; for(int i=2;i<MAX;i++) spf[i]=i; for(int i=4;i<MAX;i+=2)spf[i]=2; 
    for(int i=3;i*i<MAX;i++){ if(spf[i]==i){ for(int j=i*i;j<MAX;j+=i)if(spf[j]==j)spf[j]=i; } } 
} 
vector<int>getPF(int x)
{ 
  vector<int>ret; um<int,int,custom_hash>repeat; 
  while(x!=1){ if(!repeat[spf[x]]){ ret.eb(spf[x]); repeat[spf[x]]=1; } x=x/spf[x]; } return ret; 
} 
template<typename T>ll sumy(vector<T>&v){ ll s=0; for(auto i:v)s+=i; return s; }
template<typename T>T max_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=max(m,v[i]); } return m; }
template<typename T>T min_ele(vector<T>v){ T m=v[0]; int n=sz(v); if(n>1){ rep(i,1,n-1)m=min(m,v[i]); } return m; }
template<typename T>int id0(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(m<v[i]){ m=v[i]; ind=i;} } } return ind; }
template<typename T>int id12(vector<T>v){ T m=v[0]; int ind=0,n=sz(v); if(n>1){ rep(i,1,n-1){if(v[i]<m){ m=v[i]; ind=i; }} } return ind; }
ll cal(int n,int x,vector<ll>a)
{ 
 vector<ll>ps(n),ss(n); ps[0]=a[0]; ss[n-1]=a[n-1]; 
 rep(i,1,n-1){ ps[i]=max(ps[i-1]+a[i],a[i]); } repr(i,n-2,0){ ss[i]=max(ss[i+1]+a[i],a[i]); } 
 vector<ll>v(n); v[0]=a[0]; 
 rep(i,1,n-1){ v[i]=v[i-1]+a[i]; } 
 ll res=ps[0]-x*v[0]; int idx=0; ll ans=-1e18; 
 rep(i,0,n-1)
 {
  if(i==0){ ans=max(ans,a[0]*x+ss[i+1]); continue; }
  if(i!=n-1)
  {
    ans=max(ss[i+1]+x*v[i]+ps[idx]-x*v[idx],ans); 
  }
  else
  {
    ans=max(ans,x*v[i]+ps[idx]-x*v[idx]); 
  }
  if(res<ps[i]-x*v[i]) 
  {
    res=ps[i]-x*v[i]; idx=i; 
  }
 }
 ll k=-1e18; 
 rep(i,0,n-1){ k=max(k,ps[i]); }
 return (max({ans,k*x,k,0ll}));  
}
void solve()
{ 
 int n,x; rd(n,x); vector<ll>a(n); input(a,n); 
 if(n==1)
 {
  print(max({0ll,a[0],a[0]*x})); F2; return; 
 }
 vector<ll>dp1(n),dp2(n); dp1[0]=a[0]; vector<pii>idx(n),idxm(n); idxm[0]={0,0};  
 if(n>1){ rep(i,1,n-1){ dp1[i]=max(a[i],dp1[i-1]+a[i]);  if(dp1[i]==a[i]){ idxm[i]={i,i}; } else{ idxm[i]={idxm[i-1].fir,i}; } } }
 vector<ll>b(n); rep(i,0,n-1){ b[i]=-a[i]; } idx[0]={0,0}; 
 dp2[0]=b[0]; if(n>1){ rep(i,1,n-1){ dp2[i]=max(b[i],dp2[i-1]+b[i]); if(dp2[i]==b[i]){ idx[i]={i,i}; } else { idx[i]={idx[i-1].fir,i}; } } }
 ll maxs=-1e18,mins=1e18; int i3=-1,i4=-1; 
 rep(i,0,n-1){ if(maxs<dp1[i]){ maxs=dp1[i]; i3=idxm[i].fir; i4=idxm[i].sec; }    dp2[i]=-dp2[i]; }
 int i1=-1,i2=-1; 
 rep(i,0,n-1){ if(dp2[i]<mins){ mins=dp2[i]; i1=idx[i].fir; i2=idx[i].sec; } }
 ll res=0; if(i1!=0){ res+=dp1[i1-1]; }
 if(i2!=n-1)
 {
  ll p=a[n-1]; 
  repr(i,n-2,i2+1){ p=max(a[i],p+a[i]); }
  res=max({res,res+p,p,0ll}); 
 }
 ll res1=0; 
 if(i3!=0){ res1=max(res1,dp2[i3-1]*x); }
 if(i4!=n-1){ ll p=a[n-1]; repr(i,n-2,i4+1){ p=min(p+a[i],a[i]); }  res1=max(res1,p*x); }
  vector<ll>dp(n); vector<pii>idx1(n); dp[0]=a[0]*x; idx1[0]={0,0};  
 rep(i,1,n-1){ dp[i]=max(a[i]*x,dp[i-1]+a[i]*x); if(dp[i]==a[i]*x){ idx1[i]={i,i}; } else { idx1[i]={idx1[i-1].fir,i}; } }
 vector<ll>ps(n),ss(n); ps[0]=a[0]; ss[n-1]=a[n-1]; 
 rep(i,1,n-1){ ps[i]=max(ps[i-1]+a[i],a[i]); } repr(i,n-2,0){ ss[i]=max(ss[i+1]+a[i],a[i]); }
 ll ans=0; 
 rep(i,0,n-1)
 {
  ll res=dp[i]; int i1=idx1[i].fir,i2=idx1[i].sec;
  

  if(i1!=0){ res=max(res,res+ps[i1-1]); }
  if(i2!=n-1){ res=max(res,res+ss[i2+1]); }
  ans=max(res,ans); 
 }
 ll k=-1e18; rep(i,0,n-1){ k=max(k,ps[i]); } 
 rep(i,0,n-1){ k=max(k,ss[i]*x); } 
 print(max({maxs+res1,mins*x+res,maxs*x,0ll,k,ans,cal(n,x,a)})); F2; return; 
}
int main() 
{
  FastIO::Reader cin; FastIO::Writer cout; cout.setprecision(9);
  
  clock_t start=clock();
  
  
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  
  int t=1,c=1;
  while(t--)
  { 
    
    pc('T');pc('e');pc('s');pc('t');pc('c');pc('a'); pc('s'); pc('e'); pc(' ');
    pc('
    
    solve(); c++; 
  }
  
  clock_t end=clock();
  double time_taken=double(end-start)/double(CLOCKS_PER_SEC); 
  cout<<"Time taken: "<<time_taken; 
  cout<<" sec \n"; 
  
  return 0;
}     
