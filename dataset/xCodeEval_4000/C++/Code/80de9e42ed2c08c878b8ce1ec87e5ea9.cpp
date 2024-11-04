


#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define pb push_back
 
#define G G.O.K.U_Instinct
#define R REX27
#define C C-_-Devil_Code 
#define Y Yashwant_170301
#define L All the above are living Gods 


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