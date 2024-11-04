




using namespace std;





























ll pow_mod(ll nn, ll pp, ll mm) { ll res = 1; while(pp > 0) { if(pp&1) res = (res * nn) % mm; pp = pp >> 1; nn = (nn * nn) % mm; } return res; }


vector<string>id0(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,
__attribute__((unused))int LINE_NUM){cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << ") ";stringstream ss;ss<<H;
cerr<<args[idx]<<" = "<<ss.str();dbg_out(args,idx+1,LINE_NUM, T...);}














void olium();

int main()
{
    in_file;
    

    fast;
    int t = 1;
    

    forr(i,1,t)
    {
        

        olium();
    }
    return 0;
}

void olium()
{
    int n;
    cin >> n;
    ll a[n+1];
    bool b[n+1], c[n+1];
    forr(i,1,n)
    {
    	cin >> a[i] >> b[i] >> c[i];
    }
    list<int> adj[n+1];
    forr(i,1,n-1)
    {
    	int u,v;
    	cin >> u >> v;
    	adj[u].pb(v);
    	adj[v].pb(u);
    }

    stack<int> dfs;

    ll mncst[n+1];
    bool visited[n+1] = {0};
    mset0(visited);
    dfs.push(1);
    mncst[1] = a[1];
    visited[1] = true;
    int oc[n+1] = {0}, zc[n+1] = {0};
    ll ans = 0;
    while(!dfs.empty())
    {
    	int top = dfs.top();
    	bool found = false;
    	for(auto node : adj[top])
    	{
    		if(visited[node]) continue;
    		found = true;
    		dfs.push(node);
    		visited[node] = true;
    		adj[top].erase(adj[top].begin());
    		mncst[node] = min(a[node], mncst[top]);
    		break;
    	}
    	if(!found)
    	{
    		dfs.pop();
    	    oc[top] += (b[top] == 0 && c[top] == 1);
    		zc[top] += (b[top] == 1 && c[top] == 0);
    		int cng = min(oc[top],zc[top]);
    		ans += cng * 2 * mncst[top];
    		

    		oc[top] -= cng;
    		zc[top] -= cng;
    		if(!dfs.empty())
    		{
    			oc[dfs.top()] += oc[top];
    			zc[dfs.top()] += zc[top];
    		}
    	}
    }
    if(oc[1] || zc[1]) cout << -1 << nl;
    else cout << ans << nl;
}