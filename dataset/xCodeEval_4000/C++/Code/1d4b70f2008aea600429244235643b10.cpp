#include<bits/stdc++.h>
using namespace std;
#define ll long long int 
#define ld long double
#define pb push_back
#define ss second
#define ff first 
#define ub upper_bound
#define lb lower_bound
const ll mod=1000000007;
const ll inf=1000000000000000000;
#define all(X) (X).begin(),(X).end()
const ll infn=-1000000000000000000;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define os tree<ll, null_type,less<ll>, rb_tree_tag,tree_order_statistics_node_update>
#define osp tree<pair<ll,ll>, null_type,less<pair<ll,ll>>, rb_tree_tag,tree_order_statistics_node_update>
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
ll x=find(a);
ll y=find(b);
if(x==y)
return;
if(size[x]>size[y]){
size[x]+=size[y];
par[y]=x;
}else{
size[y]+=size[x];
par[x]=y;
}
}
ll siz(ll n){
return size[n];
}
};
ll inversion_count(vector<ll>&vec){
osp s;
ll ans=0;
for(int i=vec.size()-1; i>=0; i--){
ll d=s.order_of_key({vec[i],infn});
ans+=d;
s.insert({vec[i],s.size()});
}
return ans;
}
class segtreel{
public:
vector<ll>seg,lazy;
segtreel(ll n){
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
class segtree{
public:
vector<ll>seg;
segtree(ll n){
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
ll n,m,k;
ll num[1004][1004];
ll dp[1004][1004];
ll fun(ll i,ll j){
if(i<0||j<0||i>=n||j>=m)
return j+1;
ll x=num[i][j];
num[i][j]=2;
if(x==1){
return fun(i,j+1);
}else if(x==2){
ll f=0;
for(int k=i+dp[i][j]; k<n; k++){
if(num[k][j]!=2)
break;
f+=1;
}
dp[i][j]+=f;
return fun(i+dp[i][j],j);
}else{
return fun(i,j-1);
}
}
int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);


















 
 
 




 
 
 




 
 
 


 









cin>>n>>m>>k;
for(int i=0; i<n; i++){
for(int j=0; j<m; j++){
cin>>num[i][j];
}
}
ll x;
for(int i=0; i<k; i++){
cin>>x;
x-=1;
cout<<fun(0,x)<<" ";
}
return 0;
}