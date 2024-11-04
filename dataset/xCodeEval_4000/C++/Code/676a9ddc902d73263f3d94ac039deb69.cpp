#include<bits/stdc++.h>
using namespace std;

typedef struct Node
{
	bool rev;
	int l,r;
	int sum;
	int mxl,mxr,mnl,mnr,mxlto,mxrto,mnlto,mnrto;

	int mxv,mnv;
	int mxvl,mxvr;
	int mnvl,mnvr;
	Node *lch;
	Node *rch;
} *pnode;
Node node[202000];
pnode p=node,root=0;

void update(pnode now)
{
	if(!now)
		return;
	
	
	
	now->sum=now->lch->sum+now->rch->sum;
	
	

	now->mxv =now->lch->mxv;
	now->mxvl=now->lch->mxvl;
	now->mxvr=now->lch->mxvr;
	if(now->mxv < now->rch->mxv)
	{
		now->mxv =now->rch->mxv;
		now->mxvl=now->rch->mxvl;
		now->mxvr=now->rch->mxvr;
	}
	if(now->mxv < now->lch->mxr+now->rch->mxl)
	{
		now->mxv =now->lch->mxr+now->rch->mxl;
		now->mxvl=now->lch->mxrto;
		now->mxvr=now->rch->mxlto;
	}
	
	

	now->mnv =now->lch->mnv;
	now->mnvl=now->lch->mnvl;
	now->mnvr=now->lch->mnvr;
	if(now->mnv > now->rch->mnv)
	{
		now->mnv =now->rch->mnv;
		now->mnvl=now->rch->mnvl;
		now->mnvr=now->rch->mnvr;
	}
	if(now->mnv > now->lch->mnr+now->rch->mnl)
	{
		now->mnv =now->lch->mnr+now->rch->mnl;
		now->mnvl=now->lch->mnrto;
		now->mnvr=now->rch->mnlto;
	}
	
	

	now->mxl  =now->lch->mxl;
	now->mxlto=now->lch->mxlto;
	if(now->mxl < now->lch->sum+now->rch->mxl)
	{
		now->mxl  =now->lch->sum+now->rch->mxl;
		now->mxlto=now->rch->mxlto;
	}
	
	

	now->mxr  =now->rch->mxr;
	now->mxrto=now->rch->mxrto;
	if(now->mxr < now->rch->sum+now->lch->mxr)
	{
		now->mxr  =now->rch->sum+now->lch->mxr;
		now->mxrto=now->lch->mxrto;
	}
	
	

	now->mnl  =now->lch->mnl;
	now->mnlto=now->lch->mnlto;
	if(now->mnl > now->lch->sum+now->rch->mnl)
	{
		now->mnl  =now->lch->sum+now->rch->mnl;
		now->mnlto=now->rch->mnlto;
	}
	
	

	now->mnr  =now->rch->mnr;
	now->mnrto=now->rch->mnrto;
	if(now->mnr > now->rch->sum+now->lch->mnr)
	{
		now->mnr  =now->rch->sum+now->lch->mnr;
		now->mnrto=now->lch->mnrto;
	}
	
	
}
int n;
int a[101000];

pnode build(int l,int r)
{
	if(l==r)
	{
		pnode now=p++;
		now->rev=false;
		now->l=l,now->r=r;
		now->sum=now->mxv=now->mnv=now->mxl=now->mxr=now->mnl=now->mnr=a[l];
		now->mxvl=now->mxvr=now->mnvl=now->mnvr=l;
		now->mxlto=now->mxrto=now->mnlto=now->mnrto=l;
		now->lch=now->rch=0;
		return now;
	}
	else
	{
		int mid=(l+r)/2;
		pnode now=p++;
		now->rev=false;
		now->l=l,now->r=r;
		now->lch=build(l,mid);
		now->rch=build(mid+1,r);
		update(now);
		return now;
	}
}
void rev(pnode now)
{

	if(!now)	return;
	now->rev^=1;
	swap(now->mxl,now->mnl);
	swap(now->mxlto,now->mnlto);
	swap(now->mxr,now->mnr);
	swap(now->mxrto,now->mnrto);
	swap(now->mxv,now->mnv);
	swap(now->mxvl,now->mnvl);
	swap(now->mxvr,now->mnvr);
	now->sum*=-1;
	now->mxl*=-1;
	now->mnl*=-1;
	now->mxr*=-1;
	now->mnr*=-1;
	now->mxv*=-1;
	now->mnv*=-1;
}
void pushdown(pnode now)
{
	if(!now->rev||!now)	return;
	now->rev=false;
	rev(now->lch);
	rev(now->rch);
}
void change(pnode now,int l,int r,int i,int val)
{
	if(!now)	return;
	if(now->l==now->r)
	{
		now->sum=now->mxv=now->mnv=now->mxl=now->mxr=now->mnl=now->mnr=val;
		now->mxvl=now->mxvr=now->mnvl=now->mnvr=l;
		now->mxlto=now->mxrto=now->mnlto=now->mnrto=l;
		return;
	}
	pushdown(now);
	int mid=(l+r)/2;
	if(i<=mid)	change(now->lch,l,mid,i,val);
	else	change(now->rch,mid+1,r,i,val);
	update(now);
}

void print(pnode now)
{
	if(!now)	return;
	

	print(now->lch);
	cout<<now->sum<<" "<<now->l<<"-"<<now->r<<endl;
	cout<<now->mxlto<<"-"<<now->mxrto<<endl;
	print(now->rch);
}

int opl[101000],opr[101000];
int to;
int ans,ansl,str;
void query(pnode now,int l,int r,int ll,int rr)
{
	

	if(ll<=l&&rr>=r)
	{
		

		if(ans<now->mxv)
		{
			ans=now->mxv;
			opl[to]=now->mxvl;
			opr[to]=now->mxvr;
		}
		if(ans<now->mxl+ansl)
		{
			ans=now->mxl+ansl;
			opl[to]=str;
			opr[to]=now->mxlto;
		}
		if(now->mxr>ansl+now->sum)
		{
			ansl=now->mxr;
			str=now->mxrto;
		}
		else
			ansl+=now->sum;
		

		return;
	}
	pushdown(now);
	int mid=(l+r)/2;
	if(ll<=mid)
	{
		query(now->lch,l,mid,ll,rr);
	}
	if(rr>=mid+1)
	{
		query(now->rch,mid+1,r,ll,rr);
	}
}
void rev(pnode now,int l,int r,int ll,int rr)
{
	

	if(!now)	return;
	if(ll<=l&&rr>=r)	
	{
		rev(now);
		

		return;
	}
	int mid=(l+r)/2;
	pushdown(now);
	if(ll<=mid)
	{
		rev(now->lch,l,mid,ll,rr);
	}
	if(rr>=mid+1)
	{
		rev(now->rch,mid+1,r,ll,rr);
	}
	update(now);
}

void solve()
{
	

	

	int type,l,r,k;
	cin>>type;
	if(type==0)
	{
		cin>>l>>r;
		change(root,1,n,l,r);
		return;
	}
	cin>>l>>r>>k;
	to=0;
	int sum=0;
	while(to<k)
	{
		

		

		to++;
		ans=-1e9;
		ansl=-1e9;
		query(root,1,n,l,r);
		if(ans<=0)
		{
			to--;
			break;
		}
		sum+=ans;
		rev(root,1,n,opl[to],opr[to]);
		

		

		

	}
	cout<<sum<<endl;
	

	while(to)
	{
		

		rev(root,1,n,opl[to],opr[to]);
		

		to--;
	}
}

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	root=build(1,n);
	int m;
	cin>>m;
	while(m--)
	{
		solve();
	}
	return 0;
}



