












using namespace std;

const int maxn=100000+15;
struct Node
{
	int x0,y0,x1,y1;
	int num;
	int nex;
	int x,y;
	int tim;
	Node() {x0=y0=x1=y1=num=nex=tim=x=y=0;}
	Node(int x0,int y0,int x1,int y1,int num):x0(x0),y0(y0),x1(x1),y1(y1),num(num) {}
	int clear()
	{
		nex=x=y=tim=0;
		return 0;
	}
}sz[maxn];
struct Que
{
	int x0,y0;
	long long tt;
	int dx,dy;
	int nex,x,y,tim;
	Que() {x0=y0=tt=dx=dy=nex=x=y=tim=0;}
	Que(int x0,int y0,int dx,int dy,long long tt):x0(x0),y0(y0),dx(dx),dy(dy),tt(tt) {}
	int clear()
	{
		nex=x=y=tim=0;
		return 0;
	}
}que[maxn];
struct Bj
{
	int key1,key2;
	int num;
	int sy;
}bj[2*maxn],bj2[2*maxn];
int sum,ss;
int n,bod,m;
struct TT
{
	int wz;
	int x,y;
	long long tim;
}lca[52][maxn];
int abs(int x)
{
	if (x<0) return -x;
	return x;
}
bool cmp(Bj a,Bj b)
{
	if (a.key1==b.key1) return a.key2<b.key2;
	return a.key1<b.key1;
}
bool sam(int x,int y)
{
	if (x==0 && y==0) return true;
	if (x==0 || y==0) return false;
	return 1ll*x*y>0;
}
int tree[maxn*4];
int down(int root)
{
	if (tree[root]==0) return 0;
	int x=tree[root];
	tree[root<<1]=tree[root<<1|1]=x;
	tree[root]=0;
	return 0;
}
int ins(int root,int l,int r,int x,int y,int z)
{
	if (l>y || r<x) return 0;
	if (x<=l && r<=y)
	{
		tree[root]=z;
		return 0;
	}
	down(root);
	int mid=(l+r)>>1;
	ins(root<<1,l,mid,x,y,z);
	ins(root<<1|1,mid+1,r,x,y,z);
	return 0;
}
int found(int root,int l,int r,int x)
{
	if (l>x || r<x) return 0;
	if (l==r) return tree[root];
	down(root);
	int mid=(l+r)>>1;
	if (mid>=x) return found(root<<1,l,mid,x);
	return found(root<<1|1,mid+1,r,x);
}
int done(int ddx,int ddy)
{
	sum=0;
	memset(tree,0,sizeof(tree));
	for (int i=1;i<=n;i++)
	 if (!sam(ddx,sz[i].x1-sz[i].x0) && !sam(ddy,sz[i].y1-sz[i].y0))
	  {
	  	sum++;
	  	bj[sum].sy=0;
	  	bj[sum].num=i;
	  	bj[sum].key1=-ddx*sz[i].x0;
	  	bj[sum].key2=-ddy*sz[i].y0;
	  }
	sort(bj+1,bj+sum+1,cmp);
	ss=0;
	for (int i=1;i<=n;i++)
	if (sam(ddx,sz[i].x1-sz[i].x0) && sam(ddy,sz[i].y1-sz[i].y0))
	{
		ss++;
		bj2[ss].sy=0;
		bj2[ss].num=i;
		bj2[ss].key1=-ddx*sz[i].x0;
		bj2[ss].key2=-ddy*sz[i].y0;
	}
	for (int i=1;i<=m;i++)
	if (sam(ddx,que[i].dx) && sam(ddy,que[i].dy))
	{
		ss++;
		bj2[ss].sy=1;
		bj2[ss].num=i;
		bj2[ss].key1=-ddx*que[i].x0;
		bj2[ss].key2=-ddy*que[i].y0;
	}
	sort(bj2+1,bj2+ss+1,cmp);
	int kk=1;
	for (int i=1;i<=ss;i++)
	{
		while (kk<=sum && (bj[kk].key1<=bj2[i].key1 && bj[kk].key2<=bj2[i].key2))
		{
			int ge=bj[kk].num;
			if (ddx==0) ins(1,0,bod,min(sz[ge].x1,sz[ge].x0),max(sz[ge].x1,sz[ge].x0),ge);
			 else ins(1,0,bod,min(sz[ge].y1,sz[ge].y0),max(sz[ge].y1,sz[ge].y0),ge);
			kk++;
		}
	    int ge=bj2[i].num,gs=bj2[i].sy;
	    if (gs==0)
	    {
	    	if (ddx==0)
	    	{
	    		sz[ge].nex=found(1,0,bod,sz[ge].x0);
	    		if (sz[ge].nex==0) continue;
	    		sz[ge].x=sz[ge].x0;
	    		sz[ge].y=sz[sz[ge].nex].y0;
	    		sz[ge].tim=abs(sz[ge].y-sz[ge].y1);
	    	}
	    	else
	    	{
	    		sz[ge].nex=found(1,0,bod,sz[ge].y0);
	    		if (sz[ge].nex==0) continue;
	    		sz[ge].x=sz[sz[ge].nex].x0;
	    		sz[ge].y=sz[ge].y0;
	    		sz[ge].tim=abs(sz[ge].x-sz[ge].x1);
	    	}
	    }
	    else
	    {
	    	if (ddx==0)
	    	{
	    		que[ge].nex=found(1,0,bod,que[ge].x0);
	    		if (que[ge].nex==0) continue;
	    		que[ge].x=que[ge].x0;
	    		que[ge].y=sz[que[ge].nex].y0;
	    		que[ge].tim=abs(que[ge].y-que[ge].y0);
	    	}
	    	else
	    	{
	    		que[ge].nex=found(1,0,bod,que[ge].y0);
	    		if (que[ge].nex==0) continue;
	    		que[ge].x=sz[que[ge].nex].x0;
	    		que[ge].y=que[ge].y0;
	    		que[ge].tim=abs(que[ge].x-que[ge].x0);
	    	}
	    }
	}
	return 0;
}
int pre[maxn*2],nex[maxn*2];
int done2()
{
	sum=0;
	for (int i=1;i<=n;i++)
	if (sz[i].x0==sz[i].x1)
	{
		sum++;
		bj[sum].key1=sz[i].x0;
		bj[sum].key2=sz[i].y0;
		bj[sum].num=i;
		bj[sum].sy=0;
	}
	for (int i=1;i<=m;i++)
	if (que[i].dx==0)
	{
		sum++;
		bj[sum].key1=que[i].x0;
		bj[sum].key2=que[i].y0;
		bj[sum].num=i;
		bj[sum].sy=1;
	}
	sort(bj+1,bj+sum+1,cmp);
	for (int i=1;i<=sum;i++)
      if (i!=1 && bj[i].key1==bj[i-1].key1)
      {
      	if (bj[i-1].sy==0) pre[i]=i-1;
      	 else pre[i]=pre[i-1];
      } else pre[i]=0;
    for (int i=sum;i>=1;i--)
     if (i!=sum && bj[i].key1==bj[i+1].key1)
       {
       	if (bj[i+1].sy==0) nex[i]=i+1;
       	 else nex[i]=nex[i+1];
       } else nex[i]=0;
    for (int i=1;i<=sum;i++)
     if (bj[i].sy==0)
     {
     	int q=bj[i].num,pr=bj[pre[i]].num,ne=bj[nex[i]].num;
     	if (sz[q].y1>sz[q].y0 && ne!=0 && (min(sz[ne].y0,sz[ne].y1)-sz[q].y1<sz[q].tim || sz[q].nex==0))
		  {
		  	sz[q].tim=min(sz[ne].y0,sz[ne].y1)-sz[q].y1;
		  	sz[q].nex=ne;
		  	sz[q].y=min(sz[ne].y0,sz[ne].y1);
		  	sz[q].x=sz[q].x0;
		  } 
		if (sz[q].y1<sz[q].y0 && pr!=0 && (sz[q].y1-max(sz[pr].y0,sz[pr].y1)<sz[q].tim || sz[q].nex==0))
		{
			sz[q].tim=sz[q].y1-max(sz[pr].y0,sz[pr].y1);
			sz[q].nex=pr;
			sz[q].y=max(sz[pr].y0,sz[pr].y1);
			sz[q].x=sz[q].x0;
		}
     }
     else
     {
     	int q=bj[i].num,pr=bj[pre[i]].num,ne=bj[nex[i]].num;
     	if (ne!=0 && que[q].y0>=min(sz[ne].y0,sz[ne].y1) && que[q].y0<=max(sz[ne].y0,sz[ne].y1))
     	{
     		que[q].tim=0;
		  	que[q].nex=ne;
		  	que[q].y=que[q].y0;
		  	que[q].x=que[q].x0;
     	}
		else
		if (pr!=0 && que[q].y0>=min(sz[pr].y0,sz[pr].y1) && que[q].y0<=max(sz[pr].y0,sz[pr].y1))
		{
			que[q].tim=0;
			que[q].nex=pr;
			que[q].y=que[q].y0;
			que[q].x=que[q].x0;
		}
     	else
     	if (que[q].dy==1 && ne!=0 && (min(sz[ne].y0,sz[ne].y1)-que[q].y0<que[q].tim || que[q].nex==0))
		  {
		  	que[q].tim=min(sz[ne].y0,sz[ne].y1)-que[q].y0;
		  	que[q].nex=ne;
		  	que[q].y=min(sz[ne].y0,sz[ne].y1);
		  	que[q].x=que[q].x0;
		  } 
		
		else
		if (que[q].dy==-1 && pr!=0 && (que[q].y0-max(sz[pr].y0,sz[pr].y1)<que[q].tim || que[q].nex==0))
		{
			que[q].tim=que[q].y0-max(sz[pr].y0,sz[pr].y1);
			que[q].nex=pr;
			que[q].y=max(sz[pr].y0,sz[pr].y1);
			que[q].x=que[q].x0;
		}
     }
    sum=0;
	for (int i=1;i<=n;i++)
	if (sz[i].y0==sz[i].y1)
	{
		sum++;
		bj[sum].key1=sz[i].y0;
		bj[sum].key2=sz[i].x0;
		bj[sum].num=i;
		bj[sum].sy=0;
	}
	for (int i=1;i<=m;i++)
	if (que[i].dy==0)
	{
		sum++;
		bj[sum].key1=que[i].y0;
		bj[sum].key2=que[i].x0;
		bj[sum].num=i;
		bj[sum].sy=1;
	}
	sort(bj+1,bj+sum+1,cmp);
	for (int i=1;i<=sum;i++)
      if (i!=1 && bj[i].key1==bj[i-1].key1)
      {
      	if (bj[i-1].sy==0) pre[i]=i-1;
      	 else pre[i]=pre[i-1];
      } else pre[i]=0;
    for (int i=sum;i>=1;i--)
     if (i!=sum && bj[i].key1==bj[i+1].key1)
       {
       	if (bj[i+1].sy==0) nex[i]=i+1;
       	 else nex[i]=nex[i+1];
       } else nex[i]=0;
    for (int i=1;i<=sum;i++)
     if (bj[i].sy==0)
     {
     	int q=bj[i].num,pr=bj[pre[i]].num,ne=bj[nex[i]].num;
     	if (sz[q].x1>sz[q].x0 && ne!=0 && (min(sz[ne].x0,sz[ne].x1)-sz[q].x1<sz[q].tim || sz[q].nex==0))
		  {
		  	sz[q].tim=min(sz[ne].x0,sz[ne].x1)-sz[q].x1;
		  	sz[q].nex=ne;
		  	sz[q].x=min(sz[ne].x0,sz[ne].x1);
		  	sz[q].y=sz[q].y0;
		  } 
		if (sz[q].x1<sz[q].x0 && pr!=0 && (sz[q].x1-max(sz[pr].x0,sz[pr].x1)<sz[q].tim || sz[q].nex==0))
		{
			sz[q].tim=sz[q].x1-max(sz[pr].x0,sz[pr].x1);
			sz[q].nex=pr;
			sz[q].x=max(sz[pr].x0,sz[pr].x1);
			sz[q].y=sz[q].y0;
		}
     }
     else
     {
     	int q=bj[i].num,pr=bj[pre[i]].num,ne=bj[nex[i]].num;
     	if (ne!=0 && que[q].x0>=min(sz[ne].x0,sz[ne].x1) && que[q].x0<=max(sz[ne].x0,sz[ne].x1))
     	{
     		que[q].tim=0;
		  	que[q].nex=ne;
		  	que[q].x=que[q].x0;
		  	que[q].y=que[q].y0;
     	}
     	else
		if (pr!=0 && que[q].x0>=min(sz[pr].x0,sz[pr].x1) && que[q].x0<=max(sz[pr].x0,sz[pr].x1))
		{
			que[q].tim=0;
			que[q].nex=pr;
			que[q].x=que[q].x0;
			que[q].y=que[q].y0;
		}
     	else
     	if (que[q].dx==1 && ne!=0 && (min(sz[ne].x0,sz[ne].x1)-que[q].x0<que[q].tim || que[q].nex==0))
		  {
		  	que[q].tim=min(sz[ne].x0,sz[ne].x1)-que[q].x0;
		  	que[q].nex=ne;
		  	que[q].x=min(sz[ne].x0,sz[ne].x1);
		  	que[q].y=que[q].y0;
		  } 
		else
		if (que[q].dx==-1 && pr!=0 && (que[q].x0-max(sz[pr].x0,sz[pr].x1)<que[q].tim || que[q].nex==0))
		{
			que[q].tim=que[q].x0-max(sz[pr].x0,sz[pr].x1);
			que[q].nex=pr;
			que[q].x=max(sz[pr].x0,sz[pr].x1);
			que[q].y=que[q].y0;
		}
     }
	return 0;
}
const long long oo=10000000000000000ll;
int ycl()
{
	for (int i=1;i<=n;i++) 
	 lca[0][i].wz=sz[i].nex,lca[0][i].x=sz[i].x,lca[0][i].y=sz[i].y,lca[0][i].tim=sz[i].tim;
	for (int i=1;i<=50;i++)
	 for (int j=1;j<=n;j++)
	  if (lca[i-1][j].wz!=0 && lca[i-1][lca[i-1][j].wz].wz!=0)
	   {
	   	lca[i][j].wz=lca[i-1][lca[i-1][j].wz].wz;
	   	lca[i][j].x=lca[i-1][lca[i-1][j].wz].x;
	   	lca[i][j].y=lca[i-1][lca[i-1][j].wz].y;
	   	int g=lca[i-1][j].wz;
	   	int x1=lca[i-1][j].x,y1=lca[i-1][j].y,x2=sz[g].x1,y2=sz[g].y1;
	   	lca[i][j].tim=lca[i-1][j].tim+lca[i-1][g].tim+abs(x1-x2)+abs(y1-y2);
	   	if (lca[i][j].tim>=oo) lca[i][j].wz=0;
	   }
	return 0;
}
int main()
{
	scanf("%d%d",&n,&bod);
	for (int i=1;i<=n;i++)
	{
		int x0,y0,x1,y1;
		scanf("%d%d%d%d",&x0,&y0,&x1,&y1);
		sz[i]=Node(x0,y0,x1,y1,i);
		sz[i].clear();
	}
	scanf("%d",&m);
	for (int i=1;i<=m;i++)
	{
		int x,y;
		long long t;
		char ch[2];
		scanf("%d%d%s%I64d",&x,&y,ch,&t);
		int dx,dy;
		if (ch[0]=='L') dx=-1,dy=0;
		if (ch[0]=='R') dx=1,dy=0;
		if (ch[0]=='U') dx=0,dy=1;
		if (ch[0]=='D') dx=0,dy=-1;
		que[i]=Que(x,y,dx,dy,t);
		que[i].clear();
	}
	done(0,1);done(0,-1);done(1,0);done(-1,0);
	done2();
	ycl();
	for (int i=1;i<=m;i++)
	{
		int x=que[i].x0,y=que[i].y0;
		long long tt=que[i].tt;
		if (que[i].nex==0)
		{
			int dx=que[i].dx,dy=que[i].dy;
			tt=min(tt,(long long)bod);
			if (dx==0)
			{
				if (dy>0) y=min(bod,y+(int)tt);
				 else y=max(0,y-(int)tt);
			}
			else if (dx>0) x=min(bod,x+(int)tt);
			 else x=max(0,x-(int)tt);
			printf("%d %d\n",x,y);
			continue;
		}
		int xx=que[i].x,yy=que[i].y;
	    if (tt<que[i].tim)	
	    {
	    	if (x==xx) printf("%d ",x);
	    	 else if (x<xx) printf("%d ",x+(int)tt);
	    	  else printf("%d ",x-(int)tt);
	    	if (y==yy) printf("%d\n",y);
	    	 else if (y<yy) printf("%d\n",y+(int)tt);
	    	  else printf("%d\n",y-(int)tt);
	    	continue;
	    }
	    else
	    {
	    	tt-=que[i].tim;
	    	x=xx;y=yy;
	    }
	    int sy=que[i].nex;
	    for (int i=50;i>=0;i--)
	     if (lca[i][sy].wz!=0)
	     {
	     	long long degt=lca[i][sy].tim+abs(x-sz[sy].x1)+abs(y-sz[sy].y1);
	     	if (degt>tt) continue;
	     	tt-=degt;
	     	x=lca[i][sy].x;
	     	y=lca[i][sy].y;
	     	sy=lca[i][sy].wz;
	     }
	    tt=min(tt,(long long)bod);
		if (sz[sy].x0==sz[sy].x1)
		{
			if (sz[sy].y0>sz[sy].y1)
				y=max(0,y-(int)tt);
			else
				y=min(bod,y+(int)tt);
		}
		else
		if (sz[sy].x0>sz[sy].x1)
		   x=max(0,x-(int)tt);
		else
		  x=min(bod,x+(int)tt);
		printf("%d %d\n",x,y);
	}
	return 0;
}
