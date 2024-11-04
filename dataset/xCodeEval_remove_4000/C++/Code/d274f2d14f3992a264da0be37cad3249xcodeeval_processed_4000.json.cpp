





















using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
template<class T> void read(T &x)
{
    char ch;
    while ((ch=getchar()) && !isdigit(ch));x=ch-'0';
    while ((ch=getchar()) && isdigit(ch)) x=x*10+ch-'0';
}
struct point
{
    int x,y;
    point() {}
    point(int _x,int _y) : x(_x),y(_y) {}
} ;
const int N=310000;
struct seg
{
	int l,r,col,flag;
}t[N<<2];
struct lj
{
	int x1,y1,x2,y2,ty,id,ok;
} P[N],QQ[N];
int n,m,nxt[N],rd[N],Q,Tree[N];
LL len[N],cirlen[N],g[N][22];
int f[N][22];
queue<int> Qu;
inline int cmp1(const lj &a,const lj &b){return min(a.x1,a.x2)<min(b.x1,b.x2)||(min(a.x1,a.x2)==min(b.x1,b.x2) && a.ok<b.ok);}
inline int cmp2(const lj &a,const lj &b){return max(a.x1,a.x2)>max(b.x1,b.x2)||(max(a.x1,a.x2)==max(b.x1,b.x2) && a.ok<b.ok);}
inline int cmp3(const lj &a,const lj &b){return min(a.y1,a.y2)<min(b.y1,b.y2)||(min(a.y1,a.y2)==min(b.y1,b.y2) && a.ok<b.ok);}
inline int cmp4(const lj &a,const lj &b){return max(a.y1,a.y2)>max(b.y1,b.y2)||(max(a.y1,a.y2)==max(b.y1,b.y2) && a.ok<b.ok);}
inline int cmp5(const lj &a,const lj &b){return a.id<b.id;}
void build(int w,int l,int r)
{
	t[w].l=l;t[w].r=r;t[w].col=t[w].flag=0;
	if (l==r) return;
	int mid=l+r>>1;
	build(w<<1,l,mid);build(w<<1|1,mid+1,r);
}
void push(int w)
{
	if (t[w].flag && t[w].l!=t[w].r)
	{
		t[w<<1].col=t[w<<1|1].col=t[w<<1].flag=t[w<<1|1].flag=t[w].flag;
		t[w].flag=0;
	}
	t[w].flag=0;
}
void add(int w,int l,int r,int c)
{
	int ll=l,rr=r;
	l=min(ll,rr);r=max(ll,rr);
	if (t[w].l==l && t[w].r==r)
	{
		t[w].col=t[w].flag=c;
		return;
	}
	push(w);
	int mid=t[w].l+t[w].r>>1;
	if (r<=mid) add(w<<1,l,r,c);
	else if (l>mid) add(w<<1|1,l,r,c);
	else add(w<<1,l,mid,c),add(w<<1|1,mid+1,r,c);
}
int ask(int w,int l)
{
	push(w);
	if (t[w].l==t[w].r) return t[w].col;
	int mid=t[w].l+t[w].r>>1;
	if (l<=mid) return ask(w<<1,l);
	else return ask(w<<1|1,l);
}
void id0()
{
	sort(P+1,P+m+1,cmp5);
	rep(i,1,m) if (!nxt[i]) nxt[i]=i;
	

	rep(i,1,m) rd[nxt[i]]++;
	rep(i,1,m)
	if (!rd[i]) Qu.push(i);
	while (Qu.size())
	{
		int x=Qu.front();Qu.pop();
		Tree[x]=1;
		rd[nxt[x]]--;
		if (rd[nxt[x]]==0) Qu.push(nxt[x]);
	}
	rep(i,1,m)
	if (!Tree[i])
	{
		int x=i;LL sum=0;
		while (nxt[x]!=i) {sum+=len[x];x=nxt[x];}
		sum+=len[x];
		x=i;
		cirlen[x]=sum;
		while (nxt[x]!=i) {cirlen[x]=sum;x=nxt[x];}
	}
	rep(i,1,m) f[i][0]=nxt[i],g[i][0]=len[i];
	rep(j,1,20) rep(i,1,m) f[i][j]=f[f[i][j-1]][j-1],g[i][j]=g[i][j-1]+g[f[i][j-1]][j-1];
}
void Init()
{
	int c;
	

	sort(P+1,P+m+Q+1,cmp1);
	build(1,0,n);
	

	
	rep(i,1,m+Q)
	{
		if (P[i].ok && P[i].ty==0)
		{
			

			nxt[P[i].id]=c=ask(1,P[i].y1);
			

			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok && P[i].x1>P[i].x2)
		{
			nxt[P[i].id]=c=ask(1,P[i].y1);
			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok) add(1,P[i].y1,P[i].y2,P[i].id);
	}
	
	
	

	sort(P+1,P+m+Q+1,cmp2);
	


	

		

	

	
	build(1,0,n);
	rep(i,1,m+Q)
	{
		if (P[i].ok && P[i].ty==1)
		{
			nxt[P[i].id]=c=ask(1,P[i].y1);
			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok && P[i].x1<P[i].x2)
		{
			nxt[P[i].id]=c=ask(1,P[i].y1);


			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok) add(1,P[i].y1,P[i].y2,P[i].id);
	}
	
	

	sort(P+1,P+m+Q+1,cmp3);
	
	
	
	
	build(1,0,n);
	rep(i,1,m+Q)
	{
		if (P[i].ok && P[i].ty==2)
		{
			

			nxt[P[i].id]=c=ask(1,P[i].x1);
			

			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok && P[i].y1>P[i].y2)
		{
			nxt[P[i].id]=c=ask(1,P[i].x1);
			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok) add(1,P[i].x1,P[i].x2,P[i].id);
	}
	
	

	sort(P+1,P+m+Q+1,cmp4);
	build(1,0,n);
	rep(i,1,m+Q)
	{
		if (P[i].ok && P[i].ty==3)
		{
			nxt[P[i].id]=c=ask(1,P[i].x1);
			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok && P[i].y1<P[i].y2)
		{
			nxt[P[i].id]=c=ask(1,P[i].x1);
			if (c==0) len[P[i].id]=0;else len[P[i].id]=abs(QQ[c].x2-P[i].x2)+abs(QQ[c].y2-P[i].y2);
		}
		if (!P[i].ok) add(1,P[i].x1,P[i].x2,P[i].id);
	}
	id0();
}
int In(int x,int y,int x1,int y1,int x2,int y2)
{
	if (x1==x2)
	{
		if (x==x1 && y>=min(y1,y2) && y<=max(y1,y2)) return 1;
		else return 0;
	}
	if (y1==y2)
	{
		if (y==y1 && x>=min(x1,x2) && x<=max(x1,x2)) return 1;
		else return 0;
	}
}
int solve(int x,int y,int Nxt,LL Len,LL t,int ty)
{
	if (In(x,y,P[Nxt].x1,P[Nxt].y1,P[Nxt].x2,P[Nxt].y2)) ty=P[Nxt].ty;
	if (t<=Len)
	{
		if (ty==0 || ty==1)
		{
			if (t<=abs(x-P[Nxt].x2))
			{
				if (ty==0) x-=t;
				else x+=t;
				printf("%d %d\n",x,y);
				return 1;
			}
			else
			{
				t-=abs(x-P[Nxt].x2);
				x=P[Nxt].x2;
				if (P[Nxt].ty==2) y-=t;
				else y+=t;
				printf("%d %d\n",x,y);
				return 1;
			}
		}
		if (ty==2 || ty==3)
		{
			if (t<=abs(y-P[Nxt].y2))
			{
				if (ty==2) y-=t;
				else y+=t;
				printf("%d %d\n",x,y);
				return 1;
			}
			else
			{
				t-=abs(y-P[Nxt].y2);
				y=P[Nxt].y2;
				if (P[Nxt].ty==0) x-=t;
				else x+=t;
				printf("%d %d\n",x,y);
				return 1;
			}
		}
	}
	return 0;
}
char ch[10];
LL ti[N];
int main()
{
	

	scanf("%d%d",&m,&n);
	rep(i,1,m)
	{
		scanf("%d%d%d%d",&P[i].x1,&P[i].y1,&P[i].x2,&P[i].y2),P[i].id=i;
		if (P[i].x1>P[i].x2) P[i].ty=0;
		else if (P[i].x1<P[i].x2) P[i].ty=1;
		else if (P[i].y1>P[i].y2) P[i].ty=2;
		else P[i].ty=3;
		QQ[i]=P[i];
	}
	scanf("%d",&Q);
	rep(i,1,Q)
	{
		scanf("%d%d%s%lld",&P[m+i].x1,&P[m+i].y1,ch,&ti[i]);
		
		P[m+i].id=m+i;
		P[m+i].x2=P[m+i].x1;
		P[m+i].y2=P[m+i].y1;
		P[m+i].ok=1;
		if (ch[0]=='L') P[m+i].ty=0;
		else if (ch[0]=='R') P[m+i].ty=1;
		else if (ch[0]=='U') P[m+i].ty=3;
		else P[m+i].ty=2;
		

	}
	

	Init();
	sort(P+1,P+m+Q+1,cmp5);
	

	

	rep(i,1,Q)
	{
		int x=P[m+i].x1,y=P[m+i].y1,ty=P[m+i].ty,Nxt=nxt[m+i];
		LL t=ti[i],Len=len[m+i];
		

		
		int id=m+i;
		if (Nxt==0)
		{
			if (P[id].ty==0)
			{
				if (t<=x) x-=t;
				else x=0;
			}
			else
			if (P[id].ty==1)
			{
				if (t<=n-x) x+=t;
				else x=n;
			}
			else
			if (P[id].ty==2)
			{
				if (t<=y) y-=t;
				else y=0;
			}
			else
			{
				if (t<=n-y) y+=t;
				else y=n;
			}
			printf("%d %d\n",x,y);
			continue;
		}
		
		
		if (solve(x,y,Nxt,Len,t,ty)) continue;
		
		
		
		t-=Len;id=Nxt;
		x=P[Nxt].x2,y=P[Nxt].y2;
		
		drep(j,20,0)
		if (Tree[f[id][j]] && g[id][j]<=t)
		{
			t-=g[id][j];
			id=f[id][j];
		}
		
		x=P[id].x2,y=P[id].y2;
		

		if (Tree[id])
		{
			if (g[id][0]>=t) {solve(x,y,f[id][0],g[id][0],t,P[id].ty);continue;}
			t-=g[id][0];id=f[id][0];
			x=P[id].x2,y=P[id].y2;
		}
		

		

		if (cirlen[id]==0)
		{
			if (P[id].ty==0)
			{
				if (t<=x) x-=t;
				else x=0;
			}
			else
			if (P[id].ty==1)
			{
				if (t<=n-x) x+=t;
				else x=n;
			}
			else
			if (P[id].ty==2)
			{
				if (t<=y) y-=t;
				else y=0;
			}
			else
			{
				if (t<=n-y) y+=t;
				else y=n;
			}
			printf("%d %d\n",x,y);
			continue;
		}
		
		
		t%=cirlen[id];
		

		drep(j,20,0)
		if (g[id][j]<=t)
		{
			t-=g[id][j];
			id=f[id][j];
		}
		

		x=P[id].x2,y=P[id].y2;
		solve(x,y,f[id][0],g[id][0],t,P[id].ty);
	}
}