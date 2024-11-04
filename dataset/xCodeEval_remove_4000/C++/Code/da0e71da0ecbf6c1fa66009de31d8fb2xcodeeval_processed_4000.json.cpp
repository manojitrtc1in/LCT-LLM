








using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int id0(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}























































const int mxn = 1005;
int vis[mxn];
vector<int>g[mxn];
int ans = 0;
int d[mxn];
int dfs(int node,int num){
   vis[node] = 1;
   if(d[node]!=-1){
     return d[node];
   }
   int res = 1;
   for(auto x:g[node]){
       res+=dfs(x,num+1);
   }
   return d[node] = res;
}

queue<int> order; 

bool id1(int n) 

{	
	queue<int> q;
	vector<int> indeg(n + 1, 0);
	for(int i = 0; i < n; i++)
		for(auto &it:g[i])
			indeg[it]++;
	for(int i = 0; i < n; i++)
	{
		if(!indeg[i])
			q.push(i);
	}
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		order.push(u);
		for(auto &v:g[u])
		{
			indeg[v]--;
			if(!indeg[v])
				q.push(v);
		}
	}
	return (order.size() == n);
}
int32_t main()
{

    
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    

    fastio;
    int n,q;
    cin>>n>>q;
    memset(vis,0,sizeof(vis));
    int arr[n];
    int adj[n][n];
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		adj[i][j] = 0;
    	}
    }
    while(q--){
        for(int i=0;i<n;i++){
        	cin>>arr[i];
        	arr[i]--;
        }
        for(int i=0;i<n;i++){
        	for(int j=i+1;j<n;j++){
        		int u = arr[i];
        		int v = arr[j];
                adj[u][v] = 1;
        	}
        }
    }

    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(adj[i][j]==1 && adj[j][i]==1){
    			adj[i][j]=adj[j][i]=0;
    		}
    	}
    }
    for(int i=0;i<n;i++){
    	for(int j=0;j<n;j++){
    		if(adj[i][j]){
    			g[i].pb(j);
    		}
    	}
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
    	    	d[j] =INT_MIN;
        }
        d[i] = 0;
		while(!order.empty()){
			order.pop();
		}
		id1(n);
		while(!order.empty()){
		int node = order.front();
		order.pop();
		if(d[node]!=-1){
			ans = max(ans,d[node]);
			for(auto x:g[node]){
				    if(d[x] < d[node]+1){
				        d[x] = d[node]+1;
				        ans = max(ans,d[x]);
				    }
			   }
		   }
	   }
    }
   cout<<ans+1<<endl;
   return 0;


}



