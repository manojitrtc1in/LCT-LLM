#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false),cin.tie(NULL)
#define f first
#define s second
#define  all(d) d.begin(),d.end()
typedef long long ll;
typedef long double ld;
using namespace std;
const int maxn=3e5+12;
const int MOD=998244353;
int  n,q,d,m,x[maxn+3],y[maxn+3],l[maxn+3],r[maxn+3];
int dem[maxn+3];
int t,k;
string  s[2003];
map<ll,ll> ma;

int main()
{
	IOS;
	scanf("%d",&n);
	int maxx,maxy,minx,miny;
	maxx = maxy = -1e8,minx = miny = 1e8;
	for (int i=1;i<=n;i++) 
	{
		scanf("%d%d",x+i,y+i);
		maxx = max(maxx,x[i]);
		minx = min(minx,x[i]);
		maxy = max(maxy,y[i]);
		miny = min(miny,y[i]);		
	}
	int ans = 0;
	for (int i=1;i<=n;i++){
		ans = max({ans,maxx-x[i] + maxy-y[i],x[i]-minx + maxy-y[i]});
		ans = max({ans,maxx-x[i] + y[i]-miny,x[i]-minx + y[i]-miny});
	}
	cout<<ans * 2<<' ';
	for (int i=4 ; i <= n ;++i) cout<<((maxx - minx + maxy - miny)<<1)<<' '; 
}


