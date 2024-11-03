



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define llu unsigned long long
#define elif else if
#define pb push_back
#define mp make_pair
#define nl '\n'
#define forr(i,b,e) for(int i=b;i<=e;i++)
#define forrv(i,b,e) for(int i=b;i>=e;i--)
#define fors(i,x) for(auto i=x.begin(); i!=x.end(); i++)
#define F first
#define S second
#define mset0(x) memset(x, 0, sizeof x);
#define mset1(x) memset(x, -1, sizeof x);
#define all(x) x.begin(),x.end()
#define pqmin(x) priority_queue<x, vector<x>, greater<x> >
#define pqmax(x) priority_queue<x>
#define sortdsc(x) sort(all(x)); reverse(all(x));
#define fast ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define vi vector<int>
#define pii pair<int,int>
#define mpii map<int,int>
#define pi 3.14159265358979323846D
#define gcd(x,y) __gcd(x,y)
#define lcm(x,y) (x*(y/__gcd(x,y)))
#define chkbit(x,p) ((x&(1LL<<p))?1:0)
#define setbit(x,p) x|=(1LL<<p)
#define clrbit(x,p) x=x&(~(1LL<<p))
#define revbit(x,p) (chkbit(x,p)?clrbit(x,p):setbit(x,p))
#define runtime() cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n"
ll pow_mod(ll nn, ll pp, ll mm) { ll res = 1; while(pp > 0) { if(pp&1) res = (res * nn) % mm; pp = pp >> 1; nn = (nn * nn) % mm; } return res; }

#ifndef ONLINE_JUDGE
vector<string>vec_spltr(string s){s+=',';vector<string>res;while(!s.empty())
res.push_back(s.substr(0, s.find(','))),s=s.substr(s.find(',')+1);return res;}
void dbg_out(vector<string>__attribute__((unused))args,__attribute__((unused))int idx,
__attribute__((unused))int LINE_NUM){cerr<<endl;}template<typename Head,typename... Tail>
void dbg_out ( vector <string> args, int idx, int LINE_NUM, Head H, Tail... T)
{if(idx>0)cerr<<", ";else cerr << "Line(" << LINE_NUM << ") ";stringstream ss;ss<<H;
cerr<<args[idx]<<" = "<<ss.str();dbg_out(args,idx+1,LINE_NUM, T...);}
#define debug(...) dbg_out(vec_spltr(#__VA_ARGS__), 0, __LINE__, __VA_ARGS__)
#define in_file freopen("input.c", "r", stdin)
#define out_file freopen("output.c", "w", stdout)
#else
#define debug(...) 0
#define in_file 0
#define out_file 0
#endif




#define MOD 10000007
#define MAX 100010
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