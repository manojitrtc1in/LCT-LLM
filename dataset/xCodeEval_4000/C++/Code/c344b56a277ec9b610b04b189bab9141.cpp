
#include<bits/stdc++.h>
#include<set>
#include<unordered_map>
using namespace std;


#define inc(i,l,r) for(int i=l;i<=r;i++)
#define dec(i,l,r) for(int i=l;i>=r;i--)
#define link(x) for(edge *j=h[x];j;j=j->next)
#define mem(a) memset(a,0,sizeof(a))
#define ll long long


#define eps 1e-8
#define succ(x) (1ll<<(x))
#define lowbit(x) (x&(-x))
#define sqr(x) ((x)*(x))
#define mid ((x+y)/2)
#define pi 3.1415926535897931
typedef pair<int, int> PII;
#define IOS ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#pragma warning(disable :4996)
#define mod 998244353  
ll inf;
ll qpow(ll x, ll t) { return t ? qpow(sqr(x) % inf, t >> 1) * (t & 1 ? x : 1) % inf : 1ll; }
inline int gcd(int a, int b) { while (b ^= a ^= b ^= a %= b); return a; }


PII m[200100];
int n;
int check(int k)
{
	int  y = 0;
	inc(i, 0, n - 1)
	{
		if (m[i].first>=k-1&& m[i].second >= y)
		{
			k--;
			y++;
		}
		if (k==0)return 1;
	}
	return 0;
}
signed main()
{
	IOS;
	int _;
	cin >> _;
	while (_--) {
		cin >> n;
		inc(i, 0, n - 1)
			cin >> m[i].first >> m[i].second;
		int z = 0, y = 2e5+1;
		while (z < y)
		{
			int mi = (z + y) >> 1;
			if (check(mi))
				z = mi + 1;
			else y = mi;
		}
		cout << y-1 << endl;
	}
	
	return 0;
}  

		  	 	 	   	  		 		     	 		 	