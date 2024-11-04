
















































































using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=200005;
const LL mod=1e9+7;
vector<int> G[Maxn];
LL va[Maxn];
bool ban[Maxn];
int siz[Maxn];
LL ans;
void dfs1(int x,int p){
	siz[x]=1;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v] && v!=p){
			dfs1(v,x);
			siz[x]+=siz[v];
		}
	}
}
int findc(int x,int p,int lim){
	int Mx=0,Mxid=-1;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v] && v!=p){
			if (siz[v]>Mx){
				Mx=siz[v];
				Mxid=v;
			}
		}
	}
	if (Mx*2<=lim){
		return x;
	}
	return findc(Mxid,x,lim);
}
void dfs2(int x,int p,LL di,LL &t,LL &c,bool fl){
	if (fl) di+=va[x]; else di-=va[x];
	di%=mod;
	t+=di;t%=mod;
	c++;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v!=p && !ban[v]){
			dfs2(v,x,di,t,c,1-fl);
		}
	}
}
void dfs3(int x,int p,LL di,vector<pair<LL,int> > &ve,bool fl){
	if (!fl) di+=va[x]; else di-=va[x];
	di%=mod;
	ve.pb(mp(di,(int)fl));
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (v!=p && !ban[v]){
			dfs3(v,x,di,ve,1-fl);
		}
	}
}
void solve(int x){
	dfs1(x,-1);
	int root=findc(x,-1,siz[x]);
	x=root;
	ban[x]=true;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			solve(v);
		}
	}
	ban[x]=false;
	LL tot=0,cnt=0;
	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		if (!ban[v]){
			dfs2(v,x,0,tot,cnt,1);
		}
	}
	
	ans+=va[x]*cnt%mod;
	ans-=tot;
	ans=(ans%mod+mod)%mod;
	cnt++;
	

	ans+=va[x];
	ans%=mod;
	tot%=mod;


	for (int i=0;i<G[x].size();i++){
		int v=G[x][i];
		vector<pair<LL,int> > ve;
		if (!ban[v]){
			dfs3(v,x,va[x],ve,1);
			LL nt=tot,nc=cnt;
			for (int j=0;j<ve.size();j++){
				

				nt+=ve[j].first-va[x];
				nc--;
			}
			nt=(nt%mod+mod)%mod; 
		

			for (int j=0;j<ve.size();j++){
				if (ve[j].second){
					ans+=-ve[j].first*nc%mod;
					ans+=nt;
				}
				else{
					

					ans+=ve[j].first*nc%mod;
					ans-=nt;
				}
				ans=(ans%mod+mod)%mod;
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&va[i]);
		va[i]+=mod;
		va[i]%=mod;
	}
	for (int i=0;i<n-1;i++){
		int u,v;
		scanf("%d %d",&u,&v);
		G[u].pb(v);
		G[v].pb(u); 
	}
	solve(1);
	printf("%I64d\n",ans);
	return 0;
}
