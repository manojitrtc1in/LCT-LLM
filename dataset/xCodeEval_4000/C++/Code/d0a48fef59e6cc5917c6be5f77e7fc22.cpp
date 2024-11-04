
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef pair<ll,ll> pll;

#define abs(x) (x>=0?x:-x)
#define IN inline
#define RE register
#define F first
#define S second 
#define FF fflush(stdout)
#define random(x) (rand()%x)
#define LOG(m,n) 1.0*log(n)/log(m)
using namespace std;
#define INF 0x3f3f3f3f
#define cb(x,y) (x>=0&&x<n&&y>=0&&y<m)
const int dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};
char g[15][15];
int len=0,vis[15][15][66666],b[15][15],Clen;
struct Pos{
	int x,y,msk,s;
	Pos(){x=0;y=0;msk=0;s=0;}
	Pos(int X,int Y,int M,int V){x=X;y=Y;msk=M;s=V;}
	inline bool operator <(const Pos &p)const{return s<p.s;}
};
inline bool chck(int vx,int vy,int msk,int lv){
	if(lv==0) return 0;
	int tx=vx+dx[(msk>>(lv*2-2))^3],ty=vy+dy[(msk>>(lv*2-2))^3];
	

	if(b[tx][ty]) return 1;
	b[tx][ty]=1;
	bool res=chck(tx,ty,msk&((1<<(lv*2-2))-1),lv-1);
	b[tx][ty]=0;
	return res;
}
int main(){
	int n,m,sx=-1,sy=-1,vx,vy,tx,ty,sc=0;
	Pos u,v;
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%s",g[i]);
		for(int j=0;j<m;j++){
			if(g[i][j]=='1') sx=i,sy=j;
			if(g[i][j]>='0'&&g[i][j]<='9') len=max(len,g[i][j]-'0'-1);
		}
	}
	vx=sx;vy=sy;
	for(int i=0;i<len;i++){
		for(int k=0;k<4;k++){
			tx=vx+dx[k],ty=vy+dy[k];
			if(cb(tx,ty)&&g[tx][ty]==g[vx][vy]+1){sc=(sc<<2)+(k^3);vx=tx;vy=ty;break;}
		}
	}
	queue<Pos> q;
	q.push(Pos(sx,sy,sc,0));
	memset(vis,-1,sizeof(vis));
	vis[sx][sy][sc]=0;
	while(!q.empty()){
		u=q.front();
		q.pop();
		

		if(g[u.x][u.y]=='@'){printf("%d\n",u.s);return 0;}
		for(int k=0;k<4;++k){
			v=Pos(u.x+dx[k],u.y+dy[k],(u.msk>>2)+k*(1<<(len*2-2)),u.s+1);
			

			vx=v.x;vy=v.y;
			if(!cb(vx,vy)) continue;
			if(g[vx][vy]=='#') continue;
			if(~vis[vx][vy][v.msk]) continue;
			b[vx][vy]=1;
			if(chck(vx,vy,v.msk,len)){b[vx][vy]=0;continue;}
			b[vx][vy]=0;
			q.push(v);
			vis[vx][vy][v.msk]=v.s;
		}
	}
	puts("-1");
    return 0;
}