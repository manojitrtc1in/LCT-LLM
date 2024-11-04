









using namespace std;
using namespace __gnu_pbds;



typedef long long ll;
typedef short unsigned su;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<ld> vld;
typedef pair<double,double> pdd;
typedef vector<ll> vll;
typedef vector<int> vii;
typedef vector<vii> vvii;
typedef vector<vll> vvll;
typedef vector<pll> vpll;
typedef vector<pii> vpii;
typedef vector<vpll> vvpll;
typedef vector<string> vss;
typedef vector<vector<string>> vvss;

const ll MOD=ll(1e9+7);
const double pi= 3.141592653589;
const double eps = 1e-12;






















































inline int gc(){
  static char buf[1048576];
  static int s = 1048576;
  static int e = 1048576;
  if(s==e&&e==1048576){
    e=fread(buf, 1, 1048576, stdin);
    s=0;
  }
  if(s == e)return EOF;
  return buf[s++];
}
template<class T=int>
inline T read(){
    T c=gc(),t=1,n=0;
    if(c==' '||c=='\n'||c=='\r'||c=='\t'||c==EOF)c=gc();
    if(c=='-'){t=-1,c=gc();}
    while(isdigit(c)){n=n*10+c-'0',c=gc();}
    return n*t;
}
template<class T=int>
inline void write(T x){
    if (x<0){
        pc('-');
        x*=-1;
    }
    if(x<10)pc(x+'0');
    else{
        write(x/10);
        pc(x%10+'0');
    }
}
template<class T=int>
inline void print(T x,char c='\n'){
    write(x);
    pc(c);
}
int getSum(int BITree[], int index){
    int sum = 0;
    while (index > 0)
    {
        sum += BITree[index];
        index -= index & (-index);
    }
    return sum;
}
void updateBIT(int BITree[],int n,int index,int val){
    while (index <= n)
    {
       BITree[index] += val;
       index += index & (-index);
    }
}
template<class T>
ostream& operator<<(ostream& out,vv<T>&v){
    fv(i,v)out<<i<<" ";
    out<<ln;
    return out;
}
template<class T>
istream& operator>>(istream& inp,vv<T>&v){
    if(sz(v))fv(i,v)inp>>i;
    else{
        T t;
        string l;
        inp>>t;
        v.pb(t);
        getline(inp,l);
        istringstream iss(l);
        while(iss>>t)v.pb(t);
    }
    return inp;
}
template<class T>
istream& operator>>(istream& inp,vv<vv<T>>&A){
    fv(i,A)inp>>i;
    return inp;
}
template<class A,class B>
ostream& operator<<(ostream& out,pair<A,B>p){
    out<<"("<<p.ff<<","<<p.ss<<")";
    return out;
}
template<class A,class B>
istream& operator>>(istream& inp,pair<A,B>&p){
    inp>>p.ff>>p.ss;
    return inp;
}
template<class T>
ostream& operator<<(ostream& out,vv<vv<T>>A){
    fv(i,A)out<<i;
    return out;
}
int len(ll n){
    int l=0;
    while(n>0)l++,n/=10;
    return l;
}
ll gcd(ll u,ll v){
    ll sft;
    if(u==0)return v;
    if(v==0)return u;
    sft=czr(u|v);
    u>>=czr(u);
    do{
        v>>=czr(v);
        if(u > v)swap(u, v);
        v-= u;
    }while(v!=0);
    return u<<sft;
}
ll lcm(ll u,ll v){return (u/gcd(u,v))*v;}
int id4(int &k, int n)
{
    if (n == 1) 
    {
        return 0;
    }
    n--;
    int id5;
    int id1 = n;
 
    while (k >= id1 && n > 1) {
        id1 *= (n - 1);
        n--;
    }
    id5 = k / id1;
    k %= id1;
 
    return id5;
}
vii id6(int n, int k)
{
    vector <int> Ans;
    set <int> S;
    for (int i = 1; i <= n; i++) 
    {
        S.insert(i);
    }
    auto itr = S.begin();
    k -= 1;
    for (int i = 0; i < n; i++) 
    {
        int index = id4(k, n - i);
        advance(itr, index);
        Ans.push_back((*itr));
        S.erase(itr);
        itr = S.begin();
    }   
    return Ans;
}
int sum(vvii aux,int i,int j,int a,int b){
    int res=aux[i+a-1][j+b-1];
    if(i>0)res-=aux[i-1][j+b-1];
    if(j>0)res-=aux[i+a-1][j-1];
    if(i>0&&j>0)res+=aux[i-1][j-1];
    return res;
}
vll vec(ll x){
    vll y;
    while(x){
        y.pb(x%10);
        x/=10;
    }
    return y;
} 
ll pow10(int n){
    ll t=1;
    f(i,0,n)t*=10;
    return t;
}
ll MSB(ll x){
    ll l=64-czl(x);
    return 1<<(l-1);
}
ll mpdt(ll a,ll b,ll mod=MOD){
    ll res=0;
    a%=mod;
    while(b){
        if(b&1)res=(res + a)%mod;
        a=(2*a)%mod;
        b>>=1;
    }
    return res;
}
ll egcd(ll a, ll b,ll&x,ll&y){
    if(a==0){
        x=0,y=1;
        return b;
    }
    ll x1,y1;
    ll gcd=egcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return gcd;
}
ll modi(ll b, ll m=MOD){
    ll x,y; 
    ll g=egcd(b,m,x,y);
    if (g!=1)return -1;
    return (x % m + m) % m;
}
ll mdiv(ll a, ll b,ll m=MOD){
    a=a%m;
    ll inv=modi(b,m);
    if(inv==-1)return 0;
    else return(inv*a)%m;
}
ll C(ll n,ll r,ll p){
    if(r>n)return 0;
    if(r>n-r)r=n-r;
    ll x=1;
    f(i,1,r+1){
        x=mpdt(x, (n + 1 - i), p);
        x=mdiv(x,i,p);
    }
    return x;
}
ll id0(ll b, ll p,ll m=MOD){
  if (p==0)return 1;
  ll t=id0(b,p/2);
  t=(t*t)%m;
  if (p%2==1)t*=b;
  return t%m;
}
ll fpow(ll b, ll p){
  if (p==0)return 1;
  ll t=fpow(b,p>>1);
  t*=t;
  if(p%2==1)t*=b;
  return t;
}
ll id3(ll p){
  if (p==0)return 1;
  ll t=id3(p>>1);
  t*=t;
  if (p&1)t<<1;
  return t;
}
ll id2(ll p,ll m=MOD){
  if (p==0)return 1;
  ll t=id2(p>>1);
  t=(t*t)%m;
  if (p&1)t<<1;
  return t%m;
}
ll fmod(const ll x,const ll M=MOD){
    return x>=M?x-M:x;
}
ll mod(ll a,ll b){return ((a%b)+b)%b; }
pll crt(ll a1,ll m1,ll a2,ll m2){
    ll s,t,g=egcd(m1,m2,s,t);
    if(a1%g!=a2% g)return pll(0,-1);
    s=mod(s*a2,m2);t=mod(t*a1,m1);
    ll r=mod(s*(m1/g)+t*(m2/g),m1/g*m2),M=m1/g*m2;
    return pll(r,M);
}
pll crt(const vll&a,const vll&m){
    if(sz(a)==1)return pll(a[0],m[0]);
    pll r=crt(a[0],m[0],a[1],m[1]);
    f(i,2,sz(a))r=crt(r.ff,r.ss,a[i],m[i]);
    return r;
}
template<class T>
struct Node{
    ll sum,lazy;
    bool mark;
    Node(){
        lazy=mark=sum=0;
    }
    Node(T x){
        sum=x;
    }
    Node operator+(const Node &Y)const{
        Node X;
        X.sum=sum+Y.sum;
        return X;
    }
};
template<class T,class Arr=vv<T>,class Node=Node<T>>
struct STree{
    

    ll N;
    vv<Node>tree;
    Arr A;
    STree(int n=0){
        N=n;
        if(N)rez(tree,2*N-1);
    }
    STree(Arr a){
        A=a;
        N=sz(a);
        rez(tree,2*N-1);
        build(0,0,N-1);
    }
    

    

    

    

    

    

    

    

    

    

    void build(int i,int l,int r){
        if(l==r){tree[i]=Node(A[l]);return;}
        int m=(l+r)>>1,lf=i+1,rt=i+((m-l+1)<<1);
        build(lf,l,m);
        build(rt,m+1,r);
        tree[i]=tree[lf]+tree[rt];
    }
    void upd(int k,T x){
        update(0,0,N-1,k,x);
    }
    void update(int i,int l,int r,int k,T x){
        if(l==r){tree[i]=Node(x);return;}
        int m=(l+r)>>1,lf=i+1,rt=i+((m-l+1)<<1);
        if(k<=m)update(lf,l,m,k,x);
        else update(rt,m+1,r,k,x);
        tree[i]=tree[lf]+tree[rt];
    }
    Node q(int s,int e){
        if(s<=e)return query(0,0,N-1,s,e);
        return query(0,0,N-1,s,N-1)+query(0,0,N-1,0,e);
    }
    Node query(int i,int l,int r,int s,int e){
        if(s>e)return Node();
        int m=(l+r)>>1,lf=i+1,rt=i+((m-l+1)<<1);
        if(s==l&&e==r)return tree[i];
        else if(e<=m)return query(lf,l,m,s,e);
        else if(s>m)return query(rt,m+1,r,s,e);
        else return query(lf,l,m,s,m)+query(rt,m+1,r,m+1,e);
    }
    STree operator+(const STree &Y)const{
        STree X(N);
        f(i,0,sz(tree))X.tree[i]=tree[i]+Y.tree[i];
        return X;
    }
};
void grey(ll x){
    ll n=64-czl(x);
    if (n <= 0)return;
    vll arr({0,1});
    int i,j;
    for (i = 2; i < (1<<n); i = i<<1){
        for (j = i-1 ; j >= 0 ; j--)
            arr.pb(arr[j]);
        for(j = i ; j < 2*i ; j++)
            arr[j]+=(1<<(64-czl(arr[j])));
    }
    fv(i,arr)if(i<=x)cout<<i<<" ";
    cout<<ln;
}
ll dp[int(1e3+1)];
void solve(){
    ll n,k,ans=0,m=0;
    vll b,c;
    cin>>n>>k>>b>>c;
    vll s(n);
     if(k>12*n){
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=c[i];
        }
        cout<<ans<<ln;
        return;
    }
    f(i,0,n)s[i]=dp[b[i]];
    f(i,0,n)b[i]=dp[b[i]];
    vvll dp1(n+1,vll(k+1));
    f(i,1,n+1)f(j,0,k+1)
    if(j>=b[i-1])dp1[i][j]=max(dp1[i-1][j-b[i-1]]+c[i-1],dp1[i-1][j]);
    else dp1[i][j]=dp1[i-1][j];
    f(j,0,k+1)ans=max(ans,dp1[n][j]);
    cout<<ans<<ln;
}     
int main(){
    
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    
    

    fv(i,dp)i=1e18;
    dp[1]=0;
    f(i,1,1e3+1){
        if(dp[i]<1e17)f(j,1,i+1){
            ll t=i+ll(i/j);
            if(t<1e3+1)dp[t]=min(dp[t],dp[i]+1);
        }
    }
    fast_cin();
    int u;

    cin>>u;
    while(u--)
    solve();
    return 0;
}