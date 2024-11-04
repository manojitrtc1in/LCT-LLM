







using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int id0(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}




const int mxn = 5001;
int par[mxn][mxn];
int dist[mxn][mxn];
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int n,m,t;
    cin>>n>>m>>t;
    vector<pair<pair<int,int>,int>>edges;
    for(int i=0;i<m;i++){
    	int a,b,c;
    	cin>>a>>b>>c;
    	a--;
    	b--;
    	edges.pb(mp(mp(a,b),c));
    }
    for(int i=0;i<=n;i++){
    	for(int j=0;j<=n;j++){
    		dist[i][j] =t+1;
    	}
    }
    dist[0][0] = 0;
    int ans = 0;
    for(int i=0;i<n;i++){
    	ans=ans;
    	 for(auto x:edges){
    	 	int u = x.first.first;
    	 	int v = x.first.second;
    	 	int w = x.second;
    	 	if(dist[i+1][v]>=dist[i][u]+w){
    	 		dist[i+1][v] = dist[i][u] + w;
    	 		par[i+1][v] = u;
    	 	}
    	 }
    	 if(dist[i+1][n-1]<=t){
    	 	ans = i+1;
    	 }
    }
    cout<<ans+1<<endl;
    int pos = n-1;
    vector<int>res;
    res.pb(pos);
    while(pos!=0){
    	pos = par[ans--][pos];
    	res.pb(pos);
    }
    reverse(all(res));
    for(auto x:res)cout<<x+1<<" ";
    return 0;


}



