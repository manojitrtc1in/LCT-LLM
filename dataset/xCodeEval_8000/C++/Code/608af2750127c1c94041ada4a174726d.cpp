	









	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	






	#include<bits/stdc++.h>
	#include <ctime>
	using namespace std;
	typedef long long ll;
	

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
			ll totalBullets=0ll;
			ll k = 0ll;
			ll extra = 1e12;

			

			ll v2 = max(k,(p2.first-p1.second));
			ans.pb(v2);
			totalBullets = totalBullets+v2;
			extra = min(extra,min(p2.first,p1.second));
			

			for(int i=1;i<n;i++)
			{
				pair<ll,ll> p2 = v[i];
				pair<ll,ll> p1 = v[i-1];
				

				ll v2 = max(k,p2.first-p1.second);
				ans.pb(v2);
				totalBullets = totalBullets+v2;
				extra = min(extra,min(p2.first,p1.second));
			}

			

			cout<<totalBullets+extra<<endl;

		}
	    return(0);	
	}












	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	

	








	