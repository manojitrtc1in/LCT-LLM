#include<bits/stdc++.h>


#define rep(i,n) for(int i=0;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) x.begin(),x.end()
#define inf 10000000000000
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define endl '\n'
using namespace std;
int power(int x, unsigned int y){int res = 1;while (y > 0){ if (y & 1){res = res*x;} y = y>>1;x = x*x;}return res;}
int powermod(int x, unsigned int y, int p){int res = 1;x = x % p;while (y > 0){if (y & 1){res = (res*x) % p;}y = y>>1; x = (x*x) % p;}return res;}
int Mod(int x, int m){ return (x%m+m)%m;}
int min(int a,int b){return a<b?a:b;}
int max(int a,int b){return a>b?a:b;}
























































int n;
int mmm = 0;
const int mxn = 2e5+5;
int st[mxn];
int val[mxn];
vector<int>g[mxn];
int one,two,three;
int maxi;
int maxd;
void dfs(int node,int par,int d){
   if(d>maxi){
		maxi = d;
		one = node;
	}
   for(auto x:g[node]){
   	  if(x!=par){
   	  	 dfs(x,node,d+1);
   	  }
   }
}
int par[mxn];
int vis[mxn];
void dfs2(int node,int pari,int d){
	par[node]=pari;
	if(d>maxd){
		maxd = d;
		two = node;
	}
	for(auto x:g[node]){
   	  if(x!=pari){
   	  	 dfs2(x,node,d+1);
   	  }
    }
}
void up(int node){
	vis[node]=1;
	if(node==par[node]){
		return;
	}
	up(par[node]);
}
int dd;
void dfs4(int node,int d){
    if(d > dd){
    	dd = d;
    	three = node;
    }
    vis[node]=1;
    for(auto x:g[node]){
    	if(!vis[x]){
           dfs4(x,d+1);
    	}
    }
}
int32_t main()
{

    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif

    fastio;
    cin>>n;
    for(int i=0;i<n;i++){
    	val[i] =0;
    	st[i]  =0;
    	vis[i] =0;
    }
    for(int i=0;i<n-1;i++){
    	int a,b;
    	cin>>a>>b;
    	a--;
    	b--;
    	g[a].pb(b);
    	g[b].pb(a);
    }
    maxi=0;
    dfs(0,0,0);
    maxd = 0;
    dfs2(one,one,0);
    up(two);
    int mmm = -1;
    int final3;
    for(int i=0;i<n;i++){
    	if(vis[i]==true){
    	    dd = 0;
    	    for(auto x:g[i]){
    	    	if(!vis[x]){
    	    		dfs4(x,1);
    	    	}
    	    }
    	    if(dd>mmm){
	    	    if(dd==0 && one!=i && two!=i){
	    	      final3 = i;
	    	      mmm=dd;
	    	      continue;
	    	    }
	    	    else if(dd==0){
                  continue;
	    	    }
    	    	final3  = three;
	    	    mmm=dd;
    	    }
    	}
    }
    cout<<maxd+mmm<<endl;
    cout<<one+1<<" "<<two+1<<" "<<final3+1<<endl;
    return 0;


}



