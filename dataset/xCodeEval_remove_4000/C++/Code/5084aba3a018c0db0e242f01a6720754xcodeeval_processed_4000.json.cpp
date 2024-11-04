










































using namespace std;

inline int read() {
	int X=0; bool flag=1; char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') flag=0; ch=getchar();}
	while(ch>='0'&&ch<='9') {X=(X<<1)+(X<<3)+ch-'0'; ch=getchar();}
	if(flag) return X;
	return ~(X-1);
}
inline void write(int X) {
	if(X<0) {X=~(X-1); putchar('-');}
	if(X>9) write(X/10);
	putchar(X%10+'0');
}




int T,n;
bool color[N];
vector<int> adj[N];

DFS(int now,int fa){
	color[now]=color[fa]^1;
	for(int i:adj[now]){
		if(i==fa)continue;
		DFS(i,now);
	}
}

void solve(){
	

	T=read();
	while(T--){
		n=read();
		rep(i,1,n)adj[i].clear();
		rep(i,1,n-1){
			int x=read(),y=read();
			adj[x].pb(y);
			adj[y].pb(x);
		}
		DFS(1,0);
		rep(i,1,n)write(color[i]?(int)adj[i].size():-(int)adj[i].size()),fak;
		fan;
	}
}

signed main(){
	solve();
	return 0;
}
