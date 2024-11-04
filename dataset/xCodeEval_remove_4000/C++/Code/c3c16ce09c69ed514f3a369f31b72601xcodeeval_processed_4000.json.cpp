
using namespace std;







ll mod=1000000007;
const ll inf=1000000000000000000;
long double pi=3.1415926535897932384626433832795;

ll infn=-inf;


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
string binary(ll n){
if(n==0){
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
if(n==0)
return 1;
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
ll id9(string &str){
for(int i=0; i<str.length()/2; i++){
if(str[i]!=str[str.length()-1-i])
return 0;
}
return 1;
}
ll euler(ll n){
ll ans=n;
for(ll i=2; i*i<=n; i++){
if(n%i==0){
ans/=i;
ans*=(i-1);
while(n%i==0)
n/=i;
}
}
if(n>1)
ans/=n,ans*=(n-1);
return ans;
}
ll id10(ll n){


if(n%4==0)
return n;
if(n%4==1)
return 1;
if(n%4==3)
return 0;
return n+1;
}
ll power(ll x,ll n){
ll ans=1;
while(n){
if(n&1)
ans*=x,n-=1;
else
x=x*x,n/=2;
}
return ans;
}
ll id7(vector<ll>&vec){
for(int i=1; i<vec.size(); i++)
if(vec[i]<=vec[i-1])
return 0;
return 1;
}
ll is_sorted(vector<ll>&vec){
for(int i=1; i<vec.size(); i++)
if(vec[i]<vec[i-1])
return 0;
return 1;
}
ll id4(ll n){
return __builtin_popcountll(n);
}
void id11(vector<ll>&vec,ll k){
rotate(vec.begin(), vec.begin()+k, vec.end());

}
void id1(vector<ll>&vec,ll k){
rotate(vec.begin(), vec.begin()+vec.size()-k, vec.end());

}
void to_lower(string &str){
transform(str.begin(),str.end(),str.begin(),::tolower);

}
void to_upper(string &str){
transform(str.begin(),str.end(),str.begin(),::toupper);

}
void to_lower(char &c){
if(!(c>=97&&c<=122))
c+=32;
}
void to_upper(char &c){
if(c>=97&&c<=122)
c-=32;
}
ll id8(char c){
to_lower(c);
if(c=='a'||c=='e'||c=='i'||c=='o'||c=='u')
return 1;
return 0;
}






class id0{
vector<vector<ll>>dp;
public:
id0(vector<vector<ll>>&num){
ll n=num.size();
ll m=num[0].size();
dp.assign(n+1,vector<ll>(m+1,0));
for(int i=1; i<=n; i++){
for(int j=1; j<=m; j++){
dp[i][j]=num[i-1][j-1]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
}
}
}
ll query(ll x1,ll y1,ll x2,ll y2){
x1+=1,y1+=1,x2+=1,y2+=1;
return dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
}
};

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
private:
vector<ll>par,size;
public:
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
return size[find(n)];
}
};
ll id6(vector<ll>&vec){
osp s;
ll ans=0;
for(int i=vec.size()-1; i>=0; i--){
ll d=s.order_of_key({vec[i],infn});
ans+=d;
s.insert({vec[i],s.size()});
}
return ans;
}
class id5{
public:
vector<ll>seg,lazy;
id5(ll n){
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
class id2{
public:
vector<ll>seg;
id2(ll n){
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
void id3(string txt, vector<int>&Lps){
    Lps[0] = 0;                   
    int len = 0;
    int i=1;
    while (i<txt.length()){
        if(txt[i]==txt[len]){   
            len++;
            Lps[i] = len;
            i++;
            continue;
        }
        else{                   
            if(len==0){         
                Lps[i] = 0;
                i++;
                continue;
            }
            else{              
                len = Lps[len-1];
                continue;
            }
        }
    }
}
ll kmp(string pattern,string text){
    int n = text.length();
    int m = pattern.length();
    vector<int>Lps(m);
    
    id3(pattern,Lps); 

    
    int i=0,j=0;
    while(i<n){
        if(pattern[j]==text[i]){i++;j++;} 

        if (j == m) { 
            return i-m;   

                    

            j = Lps[j - 1]; 
        } 
        else if (i < n && pattern[j] != text[i]) {  

            if (j == 0)          

                i++;
            else
                j = Lps[j - 1];  

        }
    }
    return -1;
}
























ll n; 




















int main(){
ios_base::sync_with_stdio(false);
cin.tie(NULL),cout.tie(NULL);
cout.precision(10);
cout<<fixed;




































ll t,m,l,r,x;
cin>>t;
while(t--){
cin>>n>>m;
vector<vector<ll>>vec(m,vector<ll>(3,0));


for(int i=0; i<m; i++){
for(int j=0; j<3; j++){
cin>>vec[i][j];
}




}
ll vis[m]={0};
ll ans=(1ll<<33)-1;
for(ll i=32; i>=0; i--){






















dsu d(n);

vector<vector<ll>>g;
for(int j=0; j<m; j++){
if(vis[j]==0){
ll x=vec[j][2];
if(((1ll<<i)&x)==0)
d.merge(vec[j][0],vec[j][1]);


}
}

map<ll,ll>mp;


for(int i=1; i<=n; i++){
mp[d.find(i)]+=1;
}

if(mp.size()==1){
for(int j=0; j<m; j++){
if(vis[j]==0){
ll x=vec[j][2];
if(((1ll<<i)&x)!=0)
vis[j]=1;
}
}
ans^=(1ll<<i);
}


































}

cout<<ans<<"\n";


}



















return 0;
}