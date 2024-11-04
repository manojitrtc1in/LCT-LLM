




#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>

using namespace std;

#define f0(i,n) for(i=0;i<n;i++)
#define f1(i,n) for(i=1;i<n;i++)
#define f2(i,n) for(i=2;i<n;i++)
#define f0n(i,n) for(i=0;i<=n;i++)
#define f1n(i,n) for(i=1;i<=n;i++)
#define f2n(i,n) for(i=2;i<=n;i++)

#define fitr(v) for(auto itr=v.begin();itr != v.end();itr++)

#define pb(i) push_back(i);
#define pf(i) push_front(i);
#define ppb() pop_back();
#define ppf() pop_front();
#define lb(i) lower_bound(i);
#define ub(i) upper_bound(i);

#define np(s) next_permutation(st.begin(),st.end())

typedef  int ll;

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














































































































































































































































































































ll main()
{
	ios_base::sync_with_stdio(false); 
    cin.tie(NULL); cout.tie(NULL);
	ll t;
	

	

	ll n,i,j;
	
	t=1;
	while(t--)
	{
		ll tempa,tempb;
		cin>>n;
		bool flag=false;
		ll a[n-1],b[n-1];
		ll c[n];
		f0(i,n-1)
			cin>>a[i];
		f0(i,n-1)
			cin>>b[i];
		ll count=0;
		vpl v;
		pl p;
		for(ll i=0;i<4;i++)
			for(ll j=0;j<4;j++)
			{
				tempa=i|j ;
				tempb=i&j;
				if(tempb==b[0] && tempa==a[0])
				{
					p.first=i;
					p.second=j;
					v.pb(p);
					flag=true;
					

				}
			}
		


		

		

		

		

		

		if(count<v.size())
		{
			c[0]=v[count].first;
			c[1]=v[count].second;
			count++;
		}

		for(i=1;i<n-1;i++)
		{	
			

			flag=false;
			for(j=0;j<4;j++)
			{
				tempa=c[i]|j;
				tempb=c[i]&j;
				if(tempb==b[i] && tempa==a[i])
				{
					c[i+1]=j;
					flag=true;
					break;
				}
				


			}
			if(flag==false)
				{
					break;
				}
			
			
		}
		while(flag==false && count<v.size())
		{
			c[0]=v[count].first;
			c[1]=v[count].second;
			flag=true;
			
			for(i=1;i<n-1;i++)
			{
				flag=false;			
				for(j=0;j<4;j++)
				{
					tempa=c[i]|j;
					tempb=c[i]&j;
					if(tempb==b[i] && tempa==a[i])
					{
						c[i+1]=j;
						flag=true;
						break;
					}
					

				}
				if(flag==false)
					break;
				
				
			}
			count++;
		}
		if(flag==true)
		{
			cout<<"YES\n";
			f0(i,n)
				cout<<c[i]<<" ";
			cout<<"\n";
		}
		else
			cout<<"NO\n";

		

	}
    

	return 0;
}