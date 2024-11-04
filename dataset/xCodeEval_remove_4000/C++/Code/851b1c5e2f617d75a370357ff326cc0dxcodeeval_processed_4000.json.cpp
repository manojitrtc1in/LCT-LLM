
































































































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








struct matrix
{
	INT m[2][2];
	inline matrix(){}
	inline matrix(int a){m[0][0]=m[0][1]=m[1][0]=m[1][1]=a;}
	inline matrix(int a,int b,int c,int d)
	{
		m[0][0]=a;
		m[0][1]=b;
		m[1][0]=c;
		m[1][1]=d;
	}
};

inline matrix Plus(matrix a,matrix b)

{
	return matrix((a.m[0][0]+b.m[0][0])%Mod,(a.m[0][1]+b.m[0][1])%Mod,(a.m[1][0]+b.m[1][0])%Mod,(a.m[1][1]+b.m[1][1])%Mod);
}

inline void Plusto(matrix& a,matrix b)

{
	a.m[0][0]=(a.m[0][0]+b.m[0][0])%Mod;
	a.m[0][1]=(a.m[0][1]+b.m[0][1])%Mod;
	a.m[1][0]=(a.m[1][0]+b.m[1][0])%Mod;
	a.m[1][1]=(a.m[1][1]+b.m[1][1])%Mod;
}

inline matrix times(matrix a,matrix b)

{
	return matrix((a.m[0][0]*b.m[0][0]%Mod+a.m[0][1]*b.m[1][0]%Mod)%Mod,
			(a.m[0][0]*b.m[0][1]%Mod+a.m[0][1]*b.m[1][1]%Mod)%Mod,
			(a.m[1][0]*b.m[0][0]%Mod+a.m[1][1]*b.m[1][0]%Mod)%Mod,
			(a.m[1][0]*b.m[0][1]%Mod+a.m[1][1]*b.m[1][1]%Mod)%Mod);
}

inline void id1(matrix& a,matrix b)

{
	tie(a.m[0][0],a.m[0][1])=mp((a.m[0][0]*b.m[0][0]%Mod+a.m[0][1]*b.m[1][0]%Mod)%Mod,(a.m[0][0]*b.m[0][1]%Mod+a.m[0][1]*b.m[1][1]%Mod)%Mod);
	tie(a.m[1][0],a.m[1][1])=mp((a.m[1][0]*b.m[0][0]%Mod+a.m[1][1]*b.m[1][0]%Mod)%Mod,(a.m[1][0]*b.m[0][1]%Mod+a.m[1][1]*b.m[1][1]%Mod)%Mod);
}

matrix fibs[200007]={matrix(1,0,0,1),matrix(1,1,1,0)},fibq[200007]={matrix(0),matrix(1,0,0,1)};
matrix dt[2000007],ic[2000007];

int n,k;

inline void LiSimon()
{
	for(int i=2;i<200007;i++)
		fibs[i]=times(fibs[i-1],fibs[1]);
	for(int i=2;i<200007;i++)
		fibq[i]=Plus(fibq[i-1],fibs[i-1]);
}


inline void id4(int now,int nl,int nr,int djg,int what)
{
	int m=(nl+nr)/2;
	

	if(ic[now].m[0][0])
	{
		Plusto(dt[now*2],times(fibq[m-nl+1],ic[now]));
		Plusto(dt[now*2+1],times(fibq[nr-m],ic[now]));
		Plusto(ic[now*2],ic[now]);
		Plusto(ic[now*2+1],ic[now]);
		ic[now]=matrix(0);
	}
	

	if(nl==djg&&nr==djg)
	{
		dt[now].m[0][0]=what;
		dt[now].m[1][0]=what;
		return;
	}
	if(m>=djg)id4(now*2,nl,m,djg,what);
	else id4(now*2+1,m+1,nr,djg,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now*2+1]),dt[now*2]);
}

inline matrix id2(int now,int nl,int nr,int l,int r)
{
	if(nl>r||nr<l)return matrix(0);
	int m=(nl+nr)/2;
	

	if(ic[now].m[0][0])
	{
		Plusto(dt[now*2],times(fibq[m-nl+1],ic[now]));
		Plusto(dt[now*2+1],times(fibq[nr-m],ic[now]));
		Plusto(ic[now*2],ic[now]);
		Plusto(ic[now*2+1],ic[now]);
		ic[now]=matrix(0);
	}
	

	if(nl>=l&&nr<=r)
	{
		return times(fibs[nl-l],dt[now]);
	}
	return Plus(id2(now*2,nl,m,l,r),id2(now*2+1,m+1,nr,l,r));
}


inline void id3(int now,int nl,int nr,int l,int r,int what)

{
	if(nl>r||nr<l)return;
	int m=(nl+nr)/2;
	

	if(ic[now].m[0][0])
	{
		Plusto(dt[now*2],times(fibq[m-nl+1],ic[now]));
		Plusto(dt[now*2+1],times(fibq[nr-m],ic[now]));
		Plusto(ic[now*2],ic[now]);
		Plusto(ic[now*2+1],ic[now]);
		ic[now]=matrix(0);
	}
	

	if(nl>=l&&nr<=r)
	{
		ic[now].m[0][0]+=what;
		ic[now].m[1][0]+=what;
		Plusto(dt[now],times(fibq[nr-nl+1],ic[now]));
		return;
	}
	id3(now*2,nl,m,l,r,what);
	id3(now*2+1,m+1,nr,l,r,what);
	dt[now]=Plus(times(fibs[m-nl+1],dt[now*2+1]),dt[now*2]);
}

inline void LiAmy()
{
	int a,b;
	scanf("%d%d",&a,&b);
	a--,b--;
	printf("%I64d\n",id2(1,0,n-1,a,b).m[1][0]);
}


inline void SunTom()
{
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	a--,b--;
	id3(1,0,n-1,a,b,c);
}

inline void id0()
{
	int a,b;
	scanf("%d%d",&a,&b);
	a--;
	id4(1,0,n-1,a,b);
}


inline void id5()
{
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		id4(1,0,n-1,i,a);
	}
	for(int i=0;i<k;i++)
	{
		int mode;
		scanf("%d",&mode);
		if(mode==1)id0();
		else if(mode==2)LiAmy();
		else SunTom();
	}
}

int main()

{
	
	LiSimon();
	id5();
	

	return 0;
}