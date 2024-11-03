	









	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	






	#include<bits/stdc++.h>
	#include <ctime>
	using namespace std;
	typedef unsigned long long ll;
	

	typedef long double ld;
	#define pb push_back
	#define mp make_pair
	#define mod 1000000007 
	#define MxN 100000
	#define pi acos(-1.0)

	

	

	

	


	ll gcd(ll a, ll b)
	{ 
	    if (a == 0) 
	        return b;  
	    return gcd(b % a, a);
	}  

	ll findLcm(ll a, ll b)  
	 {  
	    return (a*b)/gcd(a, b);  
	 }  

	int gcd(int a, int b)
	{ 
	    if (a == 0) 
	        return b;  
	    return gcd(b % a, a);
	}  

	int findLcm(int a, int b)  
	 {  
	    return (a*b)/gcd(a, b);  
	 }  

	

	 


	

	
	int main()
	{
		ios_base::sync_with_stdio(false);
	    cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
	#endif
		

	    

		

		
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
			ll totalBullets=0;
			if(p1.second>=p2.first)
			{
				ans.pb(val);
			}
			else
			{
				ans.pb(p2.first-p1.second);
				totalBullets = totalBullets + (p2.first-p1.second);
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
					totalBullets = totalBullets + (p1.first-p2.second);
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
			cout<<totalBullets+extra<<endl;

		}
	    return(0);	
	}












	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	








	