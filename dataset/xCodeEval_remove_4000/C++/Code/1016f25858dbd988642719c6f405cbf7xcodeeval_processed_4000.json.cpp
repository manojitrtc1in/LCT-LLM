





























































using namespace std;


ll M=1e9+7;
const int sz=1e5+10;
const int OO=0x3f3f3f3f;
ll gcd(ll a,ll b){
    while(b!=0)
    {
        ll a2=a;
        a=b;
        b=a2%b;
    }
    return a;
}
ll lcm(ll a,ll b)
{
    return a/ gcd(a,b)*b;
}
ll mul(ll a,ll b,ll m)
{
    return ((a%m)*(b%m))%m;
}
int id1(int x,int n)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=result*x;}
        x=x*x;
        n=n/2;
    }
    return result;
}
int id2(int x,int n,int m)
{
    int result=1;
    while(n>0)
    {
        if(n%2==1){result=(result*x)%m;}
        x=(x*x)%m;
        n=n/2;
    }
    return result;
}
ll id0(ll x,ll n,ll m)
{
    ll result=1;
    while(n>0)
    {
        if(n%2==1){result=mul(result,x,m);}
        x=mul(x,x,m);
        n=n/2;
    }
    return result;
}
const int NMAX=105;





const int MAX = 1000001;
bool prime[MAX];
void solve(){
    prime[0]=prime[1]=true;
    for(int i=4;i<MAX;i+=2)prime[i]=true;

    for(int i=3;i*i<=MAX;i++)
        if(!prime[i])
            for(int j=i*i;j<MAX;j+=2*i)
                prime[j]= true;
}
const int N=3005;
ll isprime[N];
void sieve(ll n){
    for(int i=2;i<=n;++i)
    {
        if(!isprime[i]) cout<<i<<" ";
            for(int j=i;j<=n;j+=i) {
                isprime[j]++;
             

            }

    }
}
int main() {

    fast
    int t;
    cin >> t;
    while (t--) {
int n,k;cin>>n>>k;
vector<int>v(n);
for(auto &i:v)cin>>i;
for(int i=0;k&&i+1<n;i++)
{
    while(k&&v[i]) v[i]--,k--,v.back()++;
    if(v[i]<=k)k-=v[i],v.back()+=v[i],v[i]=0;
    else v[i]-=k,v.back()+=k,k=0;
}
for(auto &i:v)cout<<i<<" ";
cout<<"\n";
    }
}
  		       	 			   	    	  		 	