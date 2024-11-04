
using namespace std;













typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const int inf_ = 0x7fffffff;
const ll inff = 4557430888798830399ll;
const double pi = acos(-1.0);
ll mod = 1e9+7;








struct id0
{
	id0(){init(0,0);};
	int n,m,to[maxn],vt[maxn];bool vis[maxn];
	vector<int> N[maxn];
	void init(int _n,int _m)
	{
		n=_n;m=_m;repb(i,1,n)N[i].clear();mst(to,0);mst(vt,0);
	}
	void link(int u,int v){N[u].pb(v);}
	bool dfs(int u)
	{
		for(auto v:N[u])if(!vis[v])
		{
			vis[v]=1;
			if(!to[v]||dfs(to[v]))
			{
				to[v]=u,vt[u]=v;
				return 1;
			}
		}
		return 0;
	}
	void run()
	{
		repb(i,1,n)if(!vt[i])
		{
			mst(vis,0);
			dfs(i);
		}
	}
	set<int> A,B;
	void dfsc(int u)
	{
		A.erase(u);
		for(auto v:N[u])if(!vis[v])
		{
			vis[v]=1;B.insert(v);
			if(to[v]&&A.count(to[v]))
				dfsc(to[v]);
		}
	}
	void cover()
	{
		mst(vis,0);A.clear();B.clear();
		repb(i,1,n)A.insert(i);
		repb(i,1,n)if(!vt[i])dfsc(i);
	}
}h;

map<int,vector<int> > X,Y;
vector<pair<pii,pii> > V,H,A,B;
void pt(pii p){cout<<"("<<p.fi<<","<<p.se<<")";}
bool cross(pair<pii,pii> p,pair<pii,pii> q)
{


	return q.fi.fi<p.fi.fi&&p.fi.fi<q.se.fi&&p.fi.se<q.se.se&&q.se.se<p.se.se;
}


int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x,y;vector<pii> z;int o[maxn];
	cin>>n;
	rep(i,0,n)
	{
		cin>>x>>y;
		X[x].pb(y);Y[y].pb(x);z.pb(mp(x,y));
	}
	for(auto z:X)
	{
		sort(all(z.se));
		rep(i,0,sz(z.se)-1)V.pb(mp(mp(z.fi,z.se[i]),mp(z.fi,z.se[i+1])));
	}
	for(auto z:Y)
	{
		sort(all(z.se));
		rep(i,0,sz(z.se)-1)H.pb(mp(mp(z.se[i],z.fi),mp(z.se[i+1],z.fi)));
	}
	h.init(sz(V),sz(H));
	rep(i,0,sz(V))rep(j,0,sz(H))if(cross(V[i],H[j]))h.link(i+1,j+1);
	
	h.run();h.cover();
	rep(i,0,sz(V))if(!h.A.count(i+1))
	{
		if(!sz(A)||A.back().se!=V[i].fi)A.pb(V[i]);
		else A[sz(A)-1].se=V[i].se;
	}
	rep(i,0,sz(H))if(!h.B.count(i+1))
	{
		if(!sz(B)||B.back().se!=H[i].fi)B.pb(H[i]);
		else B[sz(B)-1].se=H[i].se;
	}
	mst(o,0);
	rep(i,0,sz(z))
	{
		rep(j,0,sz(A))if(A[j].fi.fi==z[i].fi&&A[j].fi.se<=z[i].se&&z[i].se<=A[j].se.se)o[i]|=1;		
		rep(j,0,sz(B))if(B[j].se.se==z[i].se&&B[j].fi.fi<=z[i].fi&&z[i].fi<=B[j].se.fi)o[i]|=2;		
	}
	rep(i,0,sz(z))
	{
		if((o[i]&1)==0)A.pb(mp(z[i],z[i]));
		if((o[i]&2)==0)B.pb(mp(z[i],z[i]));
	}
	swap(A,B);
	cout<<sz(A)<<endl;
	for(auto z:A)cout<<z.fi.fi<<" "<<z.fi.se<<" "<<z.se.fi<<" "<<z.se.se<<endl;
	cout<<sz(B)<<endl;
	for(auto z:B)cout<<z.fi.fi<<" "<<z.fi.se<<" "<<z.se.fi<<" "<<z.se.se<<endl;
}