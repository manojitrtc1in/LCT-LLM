
using namespace std;







const ll mod=1000000007;
const ll inf=1000000000000000000;

const ll infn=-inf;


using namespace __gnu_pbds;


ll ncr(ll n,ll r){if(r>n)return 0;if(r > n - r) r = n - r;ll ans = 1;
ll i;for(i = 1; i <= r; i++){ans *= n - r + i;ans /= i;}return ans;}
ll power(ll x,ll n,ll m){if(n==0)return 1;else if(n%2==0)return (power(((x%m)*(x%m))%m,n/2,m))%m;else return ((x%m)*(power(x,n-1,m)%m))%m;}
ll dx[] = {1,-1,0,0}; 
ll dy[] = {0,0,1,-1};
ll modInverse(ll a,ll m){ll m0=m;ll y=0,x=1;if(m==1)return 0;while(a>1){ 
ll q=a/m;ll t=m;m=a%m,a=t;t=y;y=x-q*y;x=t;}if(x<0)x+=m0;return x;} 
string binary(ll n,ll k){
if(n==0){
string ans;
for(int i=1; i<=k; i++)
ans.pb('0');
return ans;
return "0";
}
string ans;
while(n>0){
if(n&1)
ans.pb('1');
else
ans.pb('0');
n=n>>1;
}
ll l=ans.length();
for(int j=1; j<=k-l; j++)
ans.pb('0');
reverse(ans.begin(),ans.end());
return ans;
}
bool is_prime(ll n){
if(n==1)
return 0;
for(ll i=2; i*i<=n; i++){
if(n%i==0)
return 0;
}
return 1;
}
ll sum_digit(ll n){
ll ans=0;
while(n>0){
ans+=(n%10);
n/=10;
}
return ans;
}
ll len_digit(ll n){
ll ans=0;
while(n>0){
ans+=1;
n/=10;
}
return ans;
}
ll to_decimal(string &str,ll k){
ll ans=0,d=1;
for(int i=str.length()-1; i>=0; i--){
ans+=d*(str[i]-48);
d*=k;
}
return ans;
}
ld round(ld var){
ld value = (ll)(var * 100 + .5);
return (ld)value / 100;
}




































































































































































































































































































































































































































































































































































































































































class sptable{
vector<vector<ll>>dp; 

vector<ll>num;
vector<ll>log_sp;

public:
sptable(ll jum[],ll n){
for(int i=0; i<n; i++)
num.pb(jum[i]);
log_sp.assign(n+1,0);
dp.assign(n,vector<ll>(20,0));
build(n);
}
void build(ll n){
log_sp[1]=0;
for(int i=2; i<=n; i++)
log_sp[i]=log_sp[i/2]+1;

for(int i=0; i<n; i++)
dp[i][0]=num[i];  



for(int j=1; j<20; j++){
for(int i=0; i+(1<<j)-1<n; i++){ 

dp[i][j]=__gcd(dp[i][j-1],dp[i+(1<<(j-1))][j-1]);

}
}
}
ll query(ll l,ll r){




 
 


 
 






 




 


 


 
 
 




 
ll d=log_sp[r-l+1];
 


 
return __gcd(dp[l][d],dp[r-(1<<d)+1][d]);  

 
}
};
class dsu{
public:
vector<ll>par,size;
dsu(ll n){
par.assign(n+1,0);
size.assign(n+1,0);
for(int i=1; i<=n; i++){
par[i]=i;
size[i]=1;
}
}
ll find(ll n){
if(par[n]==n)
return n;
ll p=find(par[n]);
par[n]=p;
return p;
}
void merge(ll a,ll b){
a=find(a);
b=find(b);
if(a==b)
return;
if(size[b]>size[a])
swap(a,b);
size[a]+=size[b];
par[b]=a;
}
ll siz(ll n){
return size[n];
}
};
ll id2(vector<ll>&vec){
osp s;
ll ans=0;
for(int i=vec.size()-1; i>=0; i--){
ll d=s.order_of_key({vec[i],infn});
ans+=d;
s.insert({vec[i],s.size()});
}
return ans;
}
class id1{
public:
vector<ll>seg,lazy;
id1(ll n){
seg.assign(4*n,0);
lazy.assign(4*n,0);


}




















 
void push_down(ll ind,ll l,ll r){
seg[ind]=(r-l+1)*lazy[ind]+seg[ind];
if(l!=r)
lazy[2*ind]+=lazy[ind],lazy[2*ind+1]+=lazy[ind];
lazy[ind]=0;
}
 
void set_value(ll ind,ll val,ll l,ll r){
seg[ind]=(r-l+1)*val+seg[ind];
if(l!=r)
lazy[2*ind]+=val,lazy[2*ind+1]+=val;
}
 
ll query(ll ql,ll qr,ll l,ll r,ll ind){
 
push_down(ind,l,r);
 
if(ql<=l&&qr>=r)
return seg[ind];
if(ql>r||qr<l)
return 0;
ll mid=(l+r)/2;
ll k1=query(ql,qr,l,mid,2*ind);
ll k2=query(ql,qr,mid+1,r,(2*ind)+1);
return k1+k2;
}
void update(ll ql,ll qr,ll ind,ll l,ll r,ll val){
push_down(ind,l,r);
if(ql<=l&&qr>=r){
set_value(ind,val,l,r);
return;
}
if(ql>r||qr<l)
return;
ll mid=(l+r)/2;
update(ql,qr,2*ind,l,mid,val);
update(ql,qr,2*ind+1,mid+1,r,val);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
};
class id0{
public:
vector<ll>seg;
id0(ll n){
seg.assign(4*n,0);
build(1,1,n);
}
void build(ll ind,ll l,ll r){
if(l==r){
seg[ind]=0;
return;
}
ll mid=(l+r)/2;
build(2*ind,l,mid);
build((2*ind)+1,mid+1,r);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
ll query(ll ql,ll qr,ll l,ll r,ll ind){
if(ql<=l&&qr>=r)
return seg[ind];
if(ql>r||qr<l)
return 0;
ll mid=(l+r)/2;
ll k1=query(ql,qr,l,mid,2*ind);
ll k2=query(ql,qr,mid+1,r,(2*ind)+1);
return k1+k2;
}
void update(ll q,ll ind,ll l,ll r,ll val){
if(l==r){
seg[ind]+=val;
return;
}
if(q>r||q<l)
return;
ll mid=(l+r)/2;
if(mid>=q)
update(q,2*ind,l,mid,val);
else
update(q,(2*ind)+1,mid+1,r,val);
seg[ind]=seg[2*ind]+seg[(2*ind)+1];
}
};
ll t,n;
ll dp[100005][505];
ll num[100005];
ll pref[100005];
ll fun(ll i,ll k){
if(k==0)
return inf;
if(i==n){
if(k==0)
return inf;
return infn;
}
if(dp[i][k]!=-1)
return dp[i][k];
ll l=i,r=i+k-1;
if(r>=n){
dp[i][k]=infn;
return infn;
}
ll f=0;
if(l-1>=0)
f=pref[l-1];
ll sum=pref[r]-f;
ll ans=infn;
if(sum<fun(i+k,k-1))
ans=max(ans,sum);
ll d=fun(i+1,k);
ans=max(ans,d);
dp[i][k]=ans;
return ans;
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);



















 
 
 




 
 
 




 
 
 


 










cin>>t;
while(t--){
cin>>n;
for(int i=0; i<n; i++)
cin>>num[i],pref[i]=0;
ll sum=0;
for(int i=0; i<n; i++){
sum+=num[i];
pref[i]=sum;
}
for(int i=0; i<=n; i++){
for(int j=0; j<=450; j++){
dp[i][j]=infn;
}
}

for(int i=n-1; i>=0; i--){
for(int j=1; j<=450; j++){
dp[i][j]=max(dp[i][j],dp[i+1][j]);
if(i+j-1<n){
ll f=0;
if(i-1>=0)
f=pref[i-1];
ll sum=pref[i+j-1]-f;
if((i+j<n&&sum<dp[i+j][j-1])||(j==1))
dp[i][j]=max(dp[i][j],sum);
}
}
}




ll ans=0;


















for(int i=450; i>=1; i--){
if(dp[0][i]!=infn){
ans=i;
break;
}
}

cout<<ans<<"\n";

}
return 0;
}