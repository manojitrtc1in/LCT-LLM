




























































































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





struct segtree
{
	INT dt[1600007];
	INT wp[1600007];
	int len;
	void turn(int now,int to,int nl,int nr,INT num)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>to||nr<to)return;
		if(nl==to&&nr==to)
		{
			dt[now]=num;
			return;
		}
		int m=(nl+nr)>>1;
		turn(now<<1,to,nl,m,num);
		turn(now<<1|1,to,m+1,nr,num);
		dt[now]=dt[now*2]+dt[now*2+1];
	}
	void plus(int now,int l,int r,int nl,int nr,INT num)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>r||nr<l)return;
		if(nl>=l&&nr<=r)
		{
			dt[now]+=num*(nr-nl+1);
			wp[now*2]+=num;
			wp[now*2+1]+=num;
			return;
		}
		int m=(nl+nr)>>1;
		plus(now<<1,l,r,nl,m,num);
		plus(now<<1|1,l,r,m+1,nr,num);
		dt[now]=dt[now*2]+dt[now*2+1];
	}
	INT sum(int now,int l,int r,int nl,int nr)
	{
		dt[now]+=wp[now]*(nr-nl+1);
		wp[now*2]+=wp[now];
		wp[now*2+1]+=wp[now];
		wp[now]=0;
		if(nl>r||nr<l)return 0;
		if(nl>=l&&nr<=r)
			return dt[now];
		int m=(nl+nr)>>1;
		return sum(now<<1,l,r,nl,m)+sum(now<<1|1,l,r,m+1,nr);
	}
}sg;

int n;

int main()
{
	sg.len=1;
	n=read();
	int mode;
	for(int i=0;i<n;i++)
	{
		mode=read();
		if(mode==1)
		{
			int a=read();
			INT b=READ();
			sg.plus(1,1,a,1,200007,b);
		}
		else if(mode==2)
		{
			INT a=READ();
			sg.len++;
			sg.turn(1,sg.len,1,200007,a);
		}
		else
		{
			sg.turn(1,sg.len,1,200007,0);
			sg.len--;
		}
		printf("%.10lf\n",1.00*sg.sum(1,1,sg.len,1,200007)/sg.len);
	}
	return 0;
}