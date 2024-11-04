































































































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





struct event13
{
	int id;
	int y;
	int x1,x2;
	int tp;

	event13(int tp,int id,int y,int x1,int x2):id(id),y(y),x1(x1),x2(x2),tp(tp){}
	event13(){}
	bool operator<(const event13& id2)const
	{
		if(y!=id2.y)return y<id2.y;
		if(tp!=id2.tp)return !tp;
		if(!tp)return id>id2.id;
		else return id<id2.id;
	}
};

struct id3
{
	set<int> ids;
	int unbig,sml;
	id3():unbig(-1),sml(-1){}
};

int n,m;

vector<int> lissan;
map<int,int> fls;
bool sig[200007];

struct segtree
{
	id3 dt[800007];
	void calc(int now,int l,int r)
	{


		if(l!=r)
		{
			int m=(l+r)>>1;


			if(dt[now<<1].unbig!=-1&&sig[dt[now<<1].unbig])
				calc(now<<1,l,m);


			if(dt[now<<1|1].unbig!=-1&&sig[dt[now<<1|1].unbig])
				calc(now<<1|1,m+1,r);


			dt[now].unbig=max(dt[now<<1].unbig,dt[now<<1|1].unbig);
			dt[now].sml=min(dt[now<<1].sml,dt[now<<1|1].sml);
		}
		else
			dt[now].unbig=dt[now].sml=-1;
		if(SZ(dt[now].ids))
		{
			int id1=*dt[now].ids.rbegin();

			dt[now].sml=max(dt[now].sml,id1);
			if(dt[now].unbig<id1)
			{
				dt[now].unbig=-1;
				if(!sig[id1]&&dt[now].sml==id1)
					dt[now].unbig=id1;
			}
		}
	}
	void update(int now,int nl,int nr,int l,int r,int tp,int id)
	{
		if(lissan[nr+1]<=l||lissan[nl]>=r)return;
		if(lissan[nl]>=l&&lissan[nr+1]<=r)
		{
			if(!tp)dt[now].ids.insert(id);
			else dt[now].ids.erase(id);
			calc(now,nl,nr);
			return;
		}
		int m=(nl+nr)>>1;
		update(now<<1,nl,m,l,r,tp,id);
		update(now<<1|1,m+1,nr,l,r,tp,id);
		calc(now,nl,nr);
	}
	void upd(int tp,int frm,int to,int id)
	{
		update(1,0,m-2,frm,to,tp,id);
		while(calc(1,0,m-2),dt[1].unbig!=-1)
			sig[dt[1].unbig]=1;
	}
}seg;

int id0()
{
	int cnt=0;
	for(int i=0;i<n;i++)
		cnt+=(sig[i]==1);
	return cnt;
}

vector<event13> evs;

int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		evs.pb(event13(0,i,b,a,c));
		evs.pb(event13(1,i,d,a,c));
		lissan.pb(a);
		lissan.pb(c);
	}
	sort(ALL(evs));
	sort(ALL(lissan));
	lissan.erase(unique(lissan.begin(),lissan.end()),lissan.end());
	m=SZ(lissan);
	for(int i=0;i<2*n;i++)
		seg.upd(evs[i].tp,evs[i].x1,evs[i].x2,evs[i].id);
	printf("%d\n",id0()+1);
	return 0;
}
