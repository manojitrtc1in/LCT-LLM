



using namespace std;



 








int main()
{
	ll t=1;
	cin>>t;
	while(t--)
	{
		ll n,m;
		cin>>n>>m;
		ll s=0;
		ll k=INT_MAX;
		ll c=0;
		ll a[n][m];
		for(ll i=0;i<n;++i)
			for(ll j=0;j<m;++j)
			{
				cin>>a[i][j];
				if(a[i][j]<0)
					c++;
				k=min(k,abs(a[i][j]));
				s+=abs(a[i][j]);
			}
		if(c%2==0)
			cout<<s<<endl;
		else
			cout<<s-2*k<<endl;


	}
}  