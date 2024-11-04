

















using namespace std;




















typedef long long ll;

typedef pair<ll,ll> pl;
typedef pair<string,ll> ps;
typedef pair<pl,ll> ppl;

typedef vector<ll> vl;
typedef vector<pl> vpl;
typedef vector<string> vs;
typedef vector<ps> vps;

typedef set<ll> sl;
typedef set<string> ss;

typedef queue<ll> ql;
typedef queue<string>qs;

typedef stack<ll> stl;
typedef stack<string> sts;

typedef map<ll,ll> ml;
typedef map<string,ll> ms;









  






  








  






  




ll mod=1000000007;
ll pow(ll x,ll y)
{
	if(y==0)
		return 1;
	ll z=pow(x,y/2);
	if(y%2)
		return z*z*x;
	return z*z;
}
ll fpow(ll a,ll b)
{
    ll p=a,ans=1;
    while(b){
        if(b&1) ans=(ans*p)%mod;
        p=(p*p)%mod;
        b>>=1;
    }
    return ans;
}
ll mpow(ll x,ll y)
{
	if(y==0)
		return 1;
	ll z=mpow(x,y/2)%mod;
	if(y%2)
		return (((z*z)%mod)*x)%mod;
	return (z*z)%mod;
}
ll mod_inv(ll x)
{
	return mpow(x,mod-2)%mod;
}
ll gcd(ll x,ll y)
{
	if(x==0)
		return y;
	return gcd(y%x,x);
}




































ll gcm(ll x,ll y)
{
	return (x*y)/(gcd(x,y));
}
















  






  













  























































































  




















  






  






  




















  




  















































































































































	        





















































	


ll no_factor(ll x)
{
	ll i,count=0;
	for(i=1;i*i<=x;i++)
	    if(x%i==0 && i*i != x)
	        count+=2;
	    else if(x%i==0)
	        count++;
	return count;
}






















































































































































































































































































ll n,m,a[200001];
ll bs()
{
	ll i,s=1,e=n,mid,ans=n+1,count,lvl,t=0;
	while(s<=e)
	{
		mid=s+(e-s)/2;
		count=0;
		lvl=0;
		ll cnt=0;
		f0(i,n)
		{
			count+=max(t,a[i]-lvl);
			if(count>=m)
				break;
			cnt++;
			if(cnt==mid)
			{
				cnt=0;
				lvl++;
			}
		}
		if(count>=m)
		{
			ans=min(ans,mid);
			e=mid-1;
		}
		else
			s=mid+1;
		


	}
	if(ans!=n+1)
	    return ans;
    return -1;
}
bool comp(ll p,ll q)
{
	return p>q;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	cin>>n>>m;
	ll i;
	

	f0(i,n)
		cin>>a[i];

	if(n==1)
	{
		if(a[0]>=m)
			cout<<"1\n";
		else
			cout<<"-1\n";
	}
	else
	{
	    sort(a,a+n,comp);
	 

		

		

	    cout<<bs()<<"\n";
	}
	return 0;
}