































































































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






struct matrix
{
	INT mat[77][77];
	matrix(){for(int i=0;i<77;i++)for(int j=0;j<77;j++)mat[i][j]=INF;}
	matrix operator*(const matrix& ma)
	{
		matrix mat2;
		for(int i=0;i<77;i++)
			for(int j=0;j<77;j++)
				for(int k=0;k<77;k++)
					mat2.mat[i][k]=min(mat2.mat[i][k],mat[i][j]+ma.mat[j][k]);
		return mat2;
	}
};

matrix id0(matrix x,int y)
{
	if(y==1)return x;
	matrix mat2=id0(x,y/2);
	mat2=mat2*mat2;
	if(y%2)mat2=mat2*x;
	return mat2;
}

matrix zyj,id1;

int x,k,n,q;


int c[15];
int dy[257],cntdy=0;
int yd[77];
int p[27],wp[27];
map<int,int> wpp;
pii ws_[27];

int main()
{
	id1.mat[0][0]=0;
	scanf("%d%d%d%d",&x,&k,&n,&q);
	for(int i=1;i<=k;i++)
		scanf("%d",c+i);
	for(int i=0;i<q;i++)
		scanf("%d%d",&ws_[i].first,&ws_[i].second);
	sort(ws_,ws_+q);
	for(int i=0;i<q;i++)
	{
		p[i]=ws_[i].first;
		wp[i]=ws_[i].second;
		wpp[p[i]]=wp[i];
	}
	for(int i=0;i<MASK(k);i++)
		if(__builtin_popcount(i)==x)
		{
			yd[cntdy]=i;
			dy[i]=cntdy++;
		}
	for(int ii=0;ii<cntdy;ii++)
	{
		int j=yd[ii];
		if(j&1)
		{
			for(int l=1;l<=k;l++)
				if(!BIT(j,l))
					zyj.mat[ii][dy[(j+MASK(l))>>1]]=c[l];
		}
		else
			zyj.mat[ii][dy[j>>1]]=0;
	}
	int nowpos=1;
	for(int i=0;i<q;i++)
	{
		int to=min(n-x+1,p[i]-k-1);
		if(to-nowpos>0)id1=id1*id0(zyj,to-nowpos);
		

		matrix nm=zyj;
		for(int j=max(nowpos,to);j<min(n-x+1,p[i]);j++)
		{
			for(int ii=0;ii<cntdy;ii++)
			{
				int jj=yd[ii];
				if(jj&1)
				{
					for(int l=1;l<=k;l++)
						if(!BIT(jj,l))
							nm.mat[ii][dy[(jj+MASK(l))>>1]]+=wpp[j+l];
				}
			}
			id1=id1*nm;
			nm=zyj;
		}
		nowpos=min(n-x+1,p[i]);
	}
	if(n-x+1-nowpos>0)id1=id1*id0(zyj,n-x+1-nowpos);
	

	
	printf("%lld\n",id1.mat[0][0]);
	
	printf("%I64d\n",id1.mat[0][0]);
	
	return 0;
}