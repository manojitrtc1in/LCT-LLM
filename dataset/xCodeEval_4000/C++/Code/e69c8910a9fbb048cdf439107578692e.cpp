


































#include <bits/stdc++.h>
using namespace std;
#define fro for
#define itn int
#define mp make_pair
#define pb push_back
#define one first
#define two second
#define fi(n) n.begin()
#define se(n) n.end()
#define all(n) (n).begin(),(n).end()
#define po(n) n.pop()
#define PI 3.141592653
#define son(n) int lf=2*(n),ri=2*(n)+1
#define qm(n) int mid=(n)>>1
#define pr (int prime[]={0,2,3,5,7,11,13,17,19,23,29,31,37})
#define sz(n) n.size()
#define big int maxi=-1
#define rep(i,n) for(int (i)=1;(i)<=(n);(i)++)
#define small int mini=1e9+7
#define op(x) freopen(x,"r",stdin)
#define wr(x) freopen(x,"w",stdout)
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
const int maxn=105;
const int maxm=10005;
int top=1,head[maxn];
struct PRE{
	int v,edge;
}pre[maxn];
struct NODE{
	int v,val,next;
}node[maxm];
void addedge(int u,int v,int val)
{
	node[++top].v=v;
	node[top].val=val;
	node[top].next=head[u];
	head[u]=top;
}
int Read(){
    int x=0,t=1;char c=getchar();
    if(c=='-') {t=-1;c=getchar();}
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return t*x;
}



int n,m;
int dp[maxn][maxn][30];



bool dfs(int u,int v,int last)
{
	if(dp[u][v][last]!=-1) return dp[u][v][last];
	dp[u][v][last]=0;
	for(int i=head[u];i;i=node[i].next)
	{
		int va=node[i].v;
		if(node[i].val<last) continue;
		if(dfs(v,va,node[i].val)==0) return dp[u][v][last]=1;
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin>>n>>m;
	memset(dp,-1,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		int u,v;
		char w;
		cin>>u>>v>>w;
		addedge(u,v,int(w+1-'a'));
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(dfs(i,j,0)==1)cout<<'A';
			else cout<<'B';
		}
		cout<<endl;
	}
    return 0;
}



