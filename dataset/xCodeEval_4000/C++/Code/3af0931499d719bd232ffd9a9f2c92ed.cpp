

































#include <bits/stdc++.h>
using namespace std;



const long long inf=2e9;
typedef long long ll;
ll n,H;



bool check(ll x)
{
	ll r=min(H,x);
	ll t=x*x-r*(r-1)/2;
	if(t<=n) return 1;
	else return 0;
}

int main()
{
	cin>>n>>H;
	ll ans=inf;
	ll l=1,r=inf,mid;
	while(l<r-1)
	{
		mid=(l+r)/2;
		int f=check(mid);


		if(f==1)
		{
			ans=min(ans,mid);
			l=mid;
		}
		else
		{
			r=mid;
		}
	}
	ll answer;
	if(check(l)) answer=((2*l-1)-(min(H,l)-1))+(n-(l*l-min(H,l)*(min(H,l)-1)/2)+l-1)/l;
	else answer=((2*r-1)-(min(H,r)-1))+(n-(r*r-min(H,r)*(min(H,r)-1)/2)+r-1)/r;
	cout<<answer<<endl;
    return 0;
}

