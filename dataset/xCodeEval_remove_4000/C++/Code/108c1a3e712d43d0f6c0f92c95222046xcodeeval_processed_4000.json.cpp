



































using namespace std;




















typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> sti;
typedef set<int> jihe;
typedef queue<int> qi;
typedef vector<pair<int,int> > vp;
typedef priority_queue<int,vector<int>,greater<int> > pqi;
typedef priority_queue<pii,vector<pii>,greater<pii> > pqpi;
const int inf=1e9+7;
const int maxn=200005;
const int maxm=400005;

ll Read(){
    ll x=0,t=1;char c=getchar();
    if(c=='-') {t=-1;c=getchar();}
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return t*x;
}



struct edge{
	ll u,v,w;
}e[maxm];
ll v[maxn];
ll n,m;
ll fa[maxn];



bool cmp(const edge &a,const edge &b)
{
	return a.w<b.w;
}

ll find(ll v)
{
	if(v==fa[v]) return v;
	else return fa[v]=find(fa[v]);
}


int main()
{
	ios_base::sync_with_stdio(false);
    n=Read(),m=Read();
    ll max1=1,maxi=v[max1]=Read();
    for(int i=2;i<=n;i++)
    {
    	v[i]=Read();
    	if(maxi>v[i])
    	{
    		maxi=v[i];
    		max1=i;
		}
	}
    for(int i=1;i<=m;i++)
    {
    	e[i].u=Read(),e[i].v=Read(),e[i].w=Read(); 
	}
	for(int i=1;i<=n;i++)
    {
    	fa[i]=i;
    	if(i!=max1)
    	{
    		m++;
    		e[m].u=max1;
    		e[m].v=i;
    		e[m].w=v[max1]+v[i];
		}
	}
	sort(e+1,e+m+1,cmp);
	ll cnt=n,ans=0;
	for(int i=1;i<=m;i++)
	{
		ll x=e[i].u,y=e[i].v;
		ll fx=find(x),fy=find(y);
		if(fx!=fy)
		{
			ans+=e[i].w;
			cnt--;
			fa[fx]=fy;
		}
	}
	cout<<ans<<endl; 
	return 0;
}





