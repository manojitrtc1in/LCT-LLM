



using namespace std;


 







ll ubs(ll a[],ll l,ll r,ll x)
{

	
	ll res=-1;
	while(l<=r)
	{
		ll m=l+(r-l)/2;
		if(a[m]<=x)
		{
			res=m;
			l=m+1;
		}
		else
		{
			r=m-1;
		}
	}
	return res;
}
int main()
{    
    ll t=1;
    cin>>t;
    while(t--)
    {
    	ll n;
    	cin>>n;
    	cout<<n<<endl;
    	for(ll i=0;i<n;++i)
    	{
    		cout<<i+1<<" ";
    	}
    	cout<<endl;
    }
}