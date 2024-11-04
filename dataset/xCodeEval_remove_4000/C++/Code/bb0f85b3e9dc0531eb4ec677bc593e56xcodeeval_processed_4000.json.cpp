
using namespace std;













typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> pii;

const int inf = 0x3f3f3f3f;
const ll inff = 4557430888798830399ll;
const double pi = acos(-1.0);
ll mod = 1e9+7;







struct CF{

	CF(){init(0,0);}
	int N[maxn],vt[maxm],ne[maxm],cap[maxm],wei[maxm],dis[maxn],pre[maxn],h[maxn];
	int cnt,s,t,flow,cost;priority_queue<pii,vector<pii>,greater<pii> > q;
	void init(int _s,int _t){s=_s;t=_t;cnt=2;flow=cost=0;mst(N,0);}
	void link(int u,int v,int c,int w){vt[cnt]=v;cap[cnt]=c;wei[cnt]=w;ne[cnt]=N[u];N[u]=cnt++;}
	void build(int u,int v,int c,int w){link(u,v,c,w);link(v,u,0,-w);}
	bool dijk(){
		mst(dis,inf);q.push({0,s});dis[s]=0;
		while(!q.empty()){
			int u=q.top().se,d=q.top().fi;q.pop();
			if(d>dis[u])continue;
			for(int e=N[u];e;e=ne[e])if(cap[e]&&dis[u]+wei[e]+h[u]-h[vt[e]]<dis[vt[e]])
				pre[vt[e]]=e^1,q.push({dis[vt[e]]=dis[u]+wei[e]+h[u]-h[vt[e]],vt[e]});}
		return dis[t]<inf;}
	int add(int u,int f=inf){
		for(int v=u;v!=s;v=vt[pre[v]])f=min(f,cap[pre[v]^1]);
		for(int v=u;v!=s;v=vt[pre[v]])cap[pre[v]]+=f,cap[pre[v]^1]-=f;
		return f;}
	void run(){
		mst(pre,0);mst(h,0);
		for(int f=0;dijk();f=add(t),flow+=f,cost+=f*dis[t])
			repb(u,s,t)h[u]+=dis[u];}};



CF cf;

int main()
{
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,s[2000],t[2000],c[2000],z[2000],a,b;vector<int> v;
	cin>>n>>k;
	rep(i,0,n)
	{
		cin>>s[i]>>t[i]>>c[i];
		v.pb(s[i]);v.pb(s[i]+t[i]);
	}
	v.pb(0);sort(all(v));v.erase(unique(all(v)),v.end());
	cf.init(0,sz(v));
	rep(i,0,sz(v))cf.build(i,i+1,k,0);
	rep(i,0,n)
	{
		a=lower_bound(all(v),s[i])-v.begin();
		b=lower_bound(all(v),s[i]+t[i])-v.begin();
		s[i]=a;t[i]=b;
		cf.build(s[i],t[i],1,-c[i]);
		z[i]=cf.cnt-2;
	}
	cf.run();
	rep(i,0,n)cout<<!cf.cap[z[i]]<<" \n"[i==n-1];

}