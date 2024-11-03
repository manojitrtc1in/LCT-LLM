	









	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	






	
	
	using namespace std;
	typedef unsigned long long ll;
	

	typedef long double ld;
	
	
	
	
	

	

	

	

	


	ll gcd(ll a, ll b)
	{ 
	    if (a == 0) 
	        return b;  
	    return gcd(b % a, a);
	}  

	ll id0(ll a, ll b)  
	 {  
	    return (a*b)/gcd(a, b);  
	 }  

	int gcd(int a, int b)
	{ 
	    if (a == 0) 
	        return b;  
	    return gcd(b % a, a);
	}  

	int id0(int a, int b)  
	 {  
	    return (a*b)/gcd(a, b);  
	 }  

	

	 


	

	
	int main()
	{
		ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	
		

	    

		

		
		ll t;
		cin>>t;
		int testcase=1;
		while(t--)
		{
			ll n;
			cin>>n;
			vector<pair<ll,ll>> v;
			for(int i=0;i<n;i++)
			{
				ll a,b;
				cin>>a>>b;
				v.pb(mp(a,b));
			}
			vector<ll> ans;
			pair<ll,ll> p1 = v[n-1];
			pair<ll,ll> p2 = v[0];
			ll val = 0ll;
			ll id1=0;
			if(p1.second>=p2.first)
			{
				ans.pb(val);
			}
			else
			{
				ans.pb(p2.first-p1.second);
				id1 = id1 + (p2.first-p1.second);
			}
			for(int i=1;i<n;i++)
			{
				pair<ll,ll> p1 = v[i];
				pair<ll,ll> p2 = v[i-1];
				ll val = 0;
				if(p1.first<=p2.second)
				{
					ans.pb(val);
				}
				else
				{
					ans.pb(p1.first-p2.second);
					id1 = id1 + (p1.first-p2.second);
				}
			}
			ll extra = 1e12;
			for(int i=0;i<n;i++)
			{
				pair<ll,ll> p = v[i];
				

				if(ans[i]>0)
				{
					extra = min(extra,p.first-ans[i]);
				}
				else
				{
					extra = min(extra,p.first);
				}
			}
			cout<<id1+extra<<endl;

		}
	    return(0);	
	}












	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	








	