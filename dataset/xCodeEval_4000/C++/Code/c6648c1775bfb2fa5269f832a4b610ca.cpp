#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pair<int,int> > vpi;
typedef pair<int,int> ii;
typedef long long ll;
typedef unsigned long long ull;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update > pbds;

#define ft               first
#define sd               second
#define sf1(c)           scanf("%d",&c)
#define sf2(c1,c2)       scanf("%d%d",&c1,&c2)
#define sf3(c1,c2,c3)    scanf("%d%d%lld",&c1,&c2,&c3)
#define pf(c)            printf("%lld ",c)
#define pof              pop_front
#define pob              pop_back
#define sz(a)            int((a).size())
#define pb               push_back
#define all(c)           (c).begin(),(c).end()
#define tr(c,i)          for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,x)     ((c).find(x) != (c).end())
#define cpresent(c,x)    (find(all(c),x) != (c).end())
#define rep(i,a,b)       for(int i=a;i<=b;i++)
#define mp               make_pair
#define mod              1000000007ll
#define hot              ios_base::sync_with_stdio(false);cin.tie(NULL)
#define err2(x,y)		 cout<<#x"="<<x<<" "#y"="<<y<<endl
#define err3(x,y,z) 	 cout<<#x"="<<x<<" "#y"="<<y<<" "#z"="<<z<<endl

































































































 


						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

						

 
 













































































































































































































































const int N = 1e5+5;
int n,u,v,ans;
vi g[N],p(N),lev(N),val(N),goal(N),final;    


void dfs(int curr,int par)
{
	p[curr]=par;
	for(int i=0;i<(int)g[curr].size();i++)
	{
		if(g[curr][i]!=par)
			dfs(g[curr][i],curr);
	}
}

void dfs2(int curr,int even,int odd,int par)
{
	if(lev[curr]%2==0)
	{
		val[curr] = (val[curr]+even)%2;
		if(val[curr]!=goal[curr])
		{
			ans++;
			even++;
			final.pb(curr);
		}
	}
	else
	{
		val[curr] = (val[curr]+odd)%2;
		if(val[curr]!=goal[curr])
		{
			ans++;
			odd++;
			final.pb(curr);
		}
	}
	for(int x:g[curr])
	{
		if(x!=par)dfs2(x,even,odd,curr);
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	dfs(1,0);
	

	lev[0]=0;
	for(int i=1;i<=n;i++)
	{
		lev[i] = lev[p[i]]+1;
	}
	

	

	for(int i=1;i<=n;i++){
		cin>>val[i];
	}
	for(int i=1;i<=n;i++)
	{
		cin>>goal[i];
	}
	dfs2(1,0,0,0);
	cout<<ans<<"\n";
	for(int x:final)cout<<x<<'\n';
	return 0;
}