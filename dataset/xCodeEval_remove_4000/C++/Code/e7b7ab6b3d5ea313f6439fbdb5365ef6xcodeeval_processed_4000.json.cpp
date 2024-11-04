
































































































using namespace std;
typedef pair<int,int> pii;
typedef unsigned long long UINT;
typedef unsigned int uint;
typedef long long INT;
typedef long double ldouble;
typedef pair<INT,INT> PII;
typedef stringstream sst;
typedef istringstream iss;
typedef vector<int> vint;
typedef vector<INT> VINT;
typedef vector<pii> vpii;
typedef vector<PII> VPII;
typedef priority_queue<int> pqi;
typedef priority_queue<INT> PQI;
typedef priority_queue<pii> pqp;
typedef priority_queue<PII> PQP;
typedef priority_queue<int,vint,greater<int> > xqi;
typedef priority_queue<INT,VINT,greater<INT> > XQI;
typedef priority_queue<pii,vpii,greater<pii> > xqp;
typedef priority_queue<PII,VPII,greater<PII> > XQP;
inline int read()
{
	int num=0;
	char c=getchar();
	if(c=='-')return -read();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}
inline INT READ()
{
	INT num=0;
	char c=getchar();
	if(c=='-')return -READ();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}





struct SegTree
{
	int dt[1600007],wpa[1600007],wpb[1600007];
	inline void init()
	{
		for(int i=0;i<1600007;i++)
		{
			dt[i]=0;
			wpa[i]=1;
			wpb[i]=0;
		}
	}
	inline void pushdown(int now,int l,int r)
	{
		int m=(l+r)>>1;
		int nwpa=1LL*wpa[now<<1]*wpa[now]%Mod;
		int id0=(1LL*wpa[now]*wpb[now<<1]%Mod+wpb[now])%Mod;
		wpa[now<<1]=nwpa;
		wpb[now<<1]=id0;
		nwpa=1LL*wpa[now<<1|1]*wpa[now]%Mod;
		id0=(1LL*wpa[now]*wpb[now<<1|1]%Mod+wpb[now])%Mod;
		wpa[now<<1|1]=nwpa;
		wpb[now<<1|1]=id0;
		dt[now<<1]=(1LL*dt[now<<1]*wpa[now]%Mod+1LL*wpb[now]*(m-l+1)%Mod)%Mod;
		dt[now<<1|1]=(1LL*dt[now<<1|1]*wpa[now]%Mod+1LL*wpb[now]*(r-m)%Mod)%Mod;
		wpa[now]=1;
		wpb[now]=0;
	}
	inline void plus1(int now,int l,int r,int nl,int nr)
	{
		if(l>r)return;
		int m=(nl+nr)>>1;
		pushdown(now,nl,nr);
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)
		{
			dt[now]+=(nr-nl+1);
			dt[now]%=Mod;
			wpb[now]=(wpb[now]+1)%Mod;
			return;
		}
		plus1(now<<1,l,r,nl,m);
		plus1(now<<1|1,l,r,m+1,nr);
		dt[now]=(dt[now<<1]+dt[now<<1|1])%Mod;
	}
	inline void times2(int now,int l,int r,int nl,int nr)
	{
		if(l>r)return;
		int m=(nl+nr)>>1;
		pushdown(now,nl,nr);
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)
		{
			dt[now]<<=1;
			dt[now]%=Mod;
			wpa[now]=2*wpa[now]%Mod;
			wpb[now]=2*wpb[now]%Mod;
			return;
		}
		times2(now<<1,l,r,nl,m);
		times2(now<<1|1,l,r,m+1,nr);
		dt[now]=(dt[now<<1]+dt[now<<1|1])%Mod;
	}
	inline int Qhe(int now,int l,int r,int nl,int nr)
	{
		int m=(nl+nr)>>1;
		pushdown(now,nl,nr);
		if(nl>r||nr<l)return 0;
		if(nl>=l&&nr<=r)return dt[now];
		return (Qhe(now<<1,l,r,nl,m)+Qhe(now<<1|1,l,r,m+1,nr))%Mod;
	}
}seg;

set<pii> sgs[200007];
int n,m;






int main()
{
	scanf("%d%d",&n,&m);
	seg.init();
	for(int i=1;i<=n;i++)
	{
		sgs[i].insert(mp(0,0));
		sgs[i].insert(mp(n+1,n+1));
	}
	while(m--)
	{
		int mode=0;
		scanf("%d",&mode);
		if(mode==1)
		{
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			auto xxx=sgs[z].lower_bound(mp(x,y));
			if(xxx!=sgs[z].begin())xxx--;
			auto eee=sgs[z].lower_bound(mp(y+1,0));
			auto ee2=eee--;
			if(xxx->second<x)
				xxx++;
			for(auto it=xxx;it!=ee2;it++)
			{
				seg.times2(1,max(x,it->first),min(y,it->second),1,n);
				auto it2=it;
				it2++;
				if(it!=eee)
					seg.plus1(1,it->second+1,min(y,it2->first-1),1,n);
			}
			if(xxx==ee2)
				seg.plus1(1,x,y,1,n);
			else
			{
				if(x<xxx->first)
					seg.plus1(1,x,min(y,xxx->first-1),1,n);
				if(y>eee->second)
					seg.plus1(1,max(x,eee->second+1),y,1,n);
			}
			int ld=xxx->first,rd=eee->second;
			for(auto it=xxx;it!=ee2;)
			{
				auto it2=it++;
				sgs[z].erase(it2);
			}
			sgs[z].insert(mp(min(ld,x),max(rd,y)));
		}
		else
		{
			int x,y;
			scanf("%d%d",&x,&y);
			printf("%d\n",seg.Qhe(1,x,y,1,n));
		}
	}
	return 0;
}
