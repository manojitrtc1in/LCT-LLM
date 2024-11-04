
#include <bits/stdc++.h>
using namespace std;
typedef int ALL_OF_YOU_ARE_HANZHONGBALLS;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;
#define IN inline
#define RE register
#define FI first
#define SE second
#define F first
#define S second
#define random(x) (rand()%x)
#define maxn 1005
int h[maxn][maxn],bb[maxn][maxn];
ii dq[maxn];
ll sum[maxn][maxn];

struct Node{
	ll val;
	int x,y;
	Node(){}
	Node(int X,int Y,ll VAL){x=X;y=Y;val=VAL;}
	inline bool operator>(const Node &n)const{
		if(val!=n.val) return val>n.val;
		if(x!=n.x) return x>n.x;
		return y>n.y;
	}
};
vector<Node> ans;
int main(){
	
	int n,m,a,b,hd=1,tl=0;
	priority_queue<Node,vector<Node>,greater<Node> > pq;
	scanf("%d%d%d%d",&n,&m,&a,&b);
	for(int i=1;i<=n;i++){
		hd=1;tl=0;
		for(int j=1;j<=m;j++){
			scanf("%d",h[i]+j);
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+h[i][j];
			if(hd<=tl&&dq[hd].S<=j-b) ++hd;
			while(hd<=tl&&dq[tl].F>h[i][j]) --tl;
			dq[++tl]=ii(h[i][j],j);
			if(j>=b) h[i][j]=dq[hd].F;
		};
	}
	for(int i=b;i<=m;i++){
		hd=1;tl=0;
		for(int j=1;j<=n;j++){
			if(hd<=tl&&dq[hd].S<=j-a) ++hd;
			while(hd<=tl&&dq[tl].F>h[j][i]) --tl;
			dq[++tl]=ii(h[j][i],j);
			if(j>=a) h[j][i]=dq[hd].F;
		}
	}
	for(int i=a;i<=n;i++){
		for(int j=b;j<=m;j++){
			

			pq.push(Node(i,j,sum[i][j]+sum[i-a][j-b]-sum[i-a][j]-sum[i][j-b]-1ll*h[i][j]*a*b));
		}

	}
	while(!pq.empty()){
		Node u=pq.top();
		pq.pop();
		if(bb[u.x][u.y]||bb[u.x-a+1][u.y]||bb[u.x][u.y-b+1]||bb[u.x-a+1][u.y-b+1]) continue;
		ans.push_back(Node(u.x-a+1,u.y-b+1,u.val));
		for(int i=u.x-a+1;i<=u.x;i++){
			for(int j=u.y-b+1;j<=u.y;j++){
				bb[i][j]=1;
			}
		}
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++){
		printf("%d %d %lld\n",ans[i].x,ans[i].y,ans[i].val);
	}
	return 0;
}

