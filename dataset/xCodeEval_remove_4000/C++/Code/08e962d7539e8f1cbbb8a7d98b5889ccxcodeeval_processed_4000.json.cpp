

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
typedef pair<ll,pll> plll;
typedef pair<ll,int> pli;









using namespace std;
char s[N][N];
int n,mxf=0,mnc=0,a[N],tc[26],ls[N],dis[N],ff[N];
int tot=1,hd[N],cur[N],t[M],nxt[M],f[M],w[M];
inline void add(int u,int v,int tf,int tw){
	t[++tot]=v;
	nxt[tot]=hd[u];
	f[tot]=tf;
	w[tot]=tw;
	hd[u]=tot;
}
inline bool spfa(){
	int u,v;
	queue<int> q;
	memset(dis,63,sizeof(dis));
	dis[26]=0;
	q.push(26);
	while(!q.empty()){
		u=q.front();
		q.pop();
		ff[u]=0;
		for(int i=hd[u];i;i=nxt[i]){
			v=t[i];
			if(f[i]&&dis[v]>dis[u]+w[i]){
				dis[v]=dis[u]+w[i];
				if(!ff[v]) q.push(v),ff[v]=u;
			}
		}
	}
	return dis[27]!=INF;
}
inline int dfs(int u,int fl){
	if(u==27){mxf+=fl;return fl;}
	int v,gt,sum=0;
	ff[u]=1;
	for(int i=cur[u];i;i=nxt[i]){
		v=t[i];
		if(!ff[v]&&f[i]&&dis[v]==dis[u]+w[i]){
			cur[u]=i;
			gt=dfs(v,min(f[i],fl-sum));
			if(gt){
				sum+=gt;
				f[i]-=gt;
				f[i^1]+=gt;
				mnc+=gt*w[i];
				if(fl==sum) break;
			}
		}
	}
	ff[u]=0;
	return sum;
}
inline void dinic(){
	while(spfa()){
		memcpy(cur,hd,sizeof(hd));
		dfs(26,INF);
		
	}
}
int main(){
	scanf("%s%d",s[0],&n);
	ls[0]=strlen(s[0]);
	for(int i=0;i<ls[0];++i) ++tc[s[0][i]-'a'];
	for(int i=0;i<26;++i) if(tc[i]){
		add(26,i,tc[i],0);
		add(i,26,0,0);
		tc[i]=0;
	}
	for(int i=1;i<=n;++i){
		scanf("%s%d",s[i],a+i);
		add(27+i,27,a[i],i);
		add(27,27+i,0,-i);
		ls[i]=strlen(s[i]);
		for(int j=0;j<ls[i];++j) ++tc[s[i][j]-'a'];
		for(int j=0;j<26;++j) if(tc[j]){
			add(j,27+i,tc[j],0);
			add(27+i,j,0,0);
			tc[j]=0;
		}
	}
	
	dinic();
	if(mxf==ls[0]) printf("%d\n",mnc);
	else puts("-1");
	return 0;
}