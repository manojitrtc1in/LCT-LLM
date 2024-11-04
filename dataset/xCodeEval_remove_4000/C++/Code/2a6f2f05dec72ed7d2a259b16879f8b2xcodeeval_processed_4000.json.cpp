
































































































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








inline int readint()
{
	int num=0;
	char c=getchar();
	while(c>='0'&&c<='9')
	{
		num=(num<<3)+(num<<1)+c-'0';
		c=getchar();
	}
	return num;
}

struct matrix
{
	int m[2][2];
	inline matrix(){}
	inline matrix(int a){m[0][0]=m[0][1]=m[1][0]=m[1][1]=a;}
	inline matrix(int a,int b,int c,int d)
	{
		m[0][0]=a;
		m[0][1]=b;
		m[1][0]=c;
		m[1][1]=d;
	}
	inline matrix(int a,int b)
	{
		m[0][0]=a;
		m[1][0]=b;
	}
};

inline matrix Plus(const matrix& a,const matrix& b,int mode)

{
	if(mode==2)return matrix((a.m[0][0]+b.m[0][0])%Mod,(a.m[0][1]+b.m[0][1])%Mod,(a.m[1][0]+b.m[1][0])%Mod,(a.m[1][1]+b.m[1][1])%Mod);
	else return matrix((a.m[0][0]+b.m[0][0])%Mod,(a.m[1][0]+b.m[1][0])%Mod);
}

inline void Plusto(matrix& a,const matrix& b,int mode)

{
	if(mode==2)
	{
		a.m[0][0]=(a.m[0][0]+b.m[0][0])%Mod;
		a.m[0][1]=(a.m[0][1]+b.m[0][1])%Mod;
		a.m[1][0]=(a.m[1][0]+b.m[1][0])%Mod;
		a.m[1][1]=(a.m[1][1]+b.m[1][1])%Mod;
	}
	else
	{
		a.m[0][0]=(a.m[0][0]+b.m[0][0])%Mod;
		a.m[1][0]=(a.m[1][0]+b.m[1][0])%Mod;
	}
}

inline matrix times(const matrix& a,const matrix& b,int mode)

{
	if(mode==2)return matrix((1LL*a.m[0][0]*b.m[0][0]+1LL*a.m[0][1]*b.m[1][0])%Mod,
							(1LL*a.m[0][0]*b.m[0][1]+1LL*a.m[0][1]*b.m[1][1])%Mod,
							(1LL*a.m[1][0]*b.m[0][0]+1LL*a.m[1][1]*b.m[1][0])%Mod,
							(1LL*a.m[1][0]*b.m[0][1]+1LL*a.m[1][1]*b.m[1][1])%Mod);
	else return matrix((1LL*a.m[0][0]*b.m[0][0]+1LL*a.m[0][1]*b.m[1][0])%Mod,
						(1LL*a.m[1][0]*b.m[0][0]+1LL*a.m[1][1]*b.m[1][0])%Mod);
}

matrix fibs[200007]={matrix(1,0,0,1),matrix(1,1,1,0)},fibq[200007]={matrix(0),matrix(1,0,0,1)};
matrix dt[2000007],ic[2000007];

int n,k;

inline void LiSimon()
{
	for(int i=2;i<200007;i++)
		fibs[i]=times(fibs[i-1],fibs[1],2);
	for(int i=2;i<200007;i++)
		fibq[i]=Plus(fibq[i-1],fibs[i-1],2);
}

inline void id3(int now,int nl,int nr,int djg,int what)
{
	int m=(nl+nr)>>1;
	

	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now].m[0][0]=0;
	}
	

	if(nl==djg&&nr==djg)
	{
		dt[now].m[0][0]=what;
		return;
	}
	if(m>=djg)id3(now<<1,nl,m,djg,what);
	else id3(now<<1|1,m+1,nr,djg,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now<<1|1],1),dt[now<<1],1);
}

inline matrix id1(int now,int nl,int nr,int l,int r)
{
	int m=(nl+nr)>>1;
	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now]=matrix(0,0);
	}
	if(nl>r||nr<l)return matrix(0);
	

	if(nl>=l&&nr<=r)
	{
		return times(fibs[nl-l],dt[now],1);
	}
	return Plus(id1(now<<1,nl,m,l,r),id1(now<<1|1,m+1,nr,l,r),1);
}

inline void id2(int now,int nl,int nr,int l,int r,int what)

{
	int m=(nl+nr)>>1;
	if(ic[now].m[0][0])
	{
		Plusto(dt[now<<1],times(fibq[m-nl+1],ic[now],1),1);
		Plusto(dt[now<<1|1],times(fibq[nr-m],ic[now],1),1);
		Plusto(ic[now<<1],ic[now],1);
		Plusto(ic[now<<1|1],ic[now],1);
		ic[now].m[0][0]=0;
	}
	if(nl>r||nr<l)return;
	

	if(nl>=l&&nr<=r)
	{
		ic[now].m[0][0]=what;
		Plusto(dt[now],times(fibq[nr-nl+1],ic[now],1),1);
		return;
	}
	id2(now<<1,nl,m,l,r,what);
	id2(now<<1|1,m+1,nr,l,r,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now<<1|1],1),dt[now<<1],1);
}

inline void LiAmy()
{
	int a=readint(),b=readint();
	a--,b--;
	printf("%d\n",id1(1,0,n-1,a,b).m[0][0]);
}

inline void SunTom()
{
	int a=readint(),b=readint(),c=readint();
	a--,b--;
	id2(1,0,n-1,a,b,c);
}

inline void id0()
{
	int a=readint(),b=readint();
	a--;
	id3(1,0,n-1,a,b);
}

inline void id4()
{
	n=readint();
	k=readint();
	for(int i=0;i<n;i++)
	{
		int a=readint();
		id3(1,0,n-1,i,a);
	}
	for(int i=0;i<k;i++)
	{
		int mode=readint();
		if(mode==1)id0();
		else if(mode==2)LiAmy();
		else SunTom();
	}
}

int main()

{
	
	freopen("R:/TEMP/Xu13virus.out","r",stdin);
	freopen("R:/TEMP/Xudu.out","w",stdout);
	
	LiSimon();
	id4();
	
	prtime;
	
	return 0;
}