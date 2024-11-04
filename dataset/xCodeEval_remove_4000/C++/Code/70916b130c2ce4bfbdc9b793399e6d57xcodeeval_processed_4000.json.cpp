




























































































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





char ins[2007],s[2007];
int szins,n=0;
int num[2007],pos[2007],cntnum=0;
int chr[2007],cpos[2007],cntchr=0;
int dp[2007][2007];

inline bool id0(char c){return c=='+'||c=='-';}
inline bool chengchu(char c){return c=='*'||c=='/';}
inline bool jjcc(char c){return id0(c)||chengchu(c);}

int main()
{
	scanf("%s",ins+1);
	ins[0]='+';
	szins=strlen(ins);
	if(!isdigit(ins[szins-1]))
		OVER("0");
	for(int i=0;i<szins-1;i++)
		if(jjcc(ins[i])&&chengchu(ins[i+1]))
			OVER("0");
	FILL1(num);
	FILL1(chr);
	for(int i=0;i<szins;i++)
	{
		if(i&&isdigit(ins[i-1])&&isdigit(ins[i]))continue;
		if(isdigit(ins[i]))s[n]='0',num[n]=cntnum,pos[cntnum]=n,n++,cntnum++;
		else s[n]=ins[i],chr[n]=cntchr,cpos[cntchr]=n,n++,cntchr++;
	}
	for(int i=1;i<n;i++)
		if(num[i]!=-1)
			dp[chr[i-1]][num[i]]=1;
	INT fxck;
	for(int i=cntchr-1;i>=0;i--)
		for(int j=0;j<cntnum;j++)
		{
			if(pos[j]<=cpos[i]+1)continue;
			if(jjcc(s[cpos[i]+1]))
				dp[i][j]=dp[i+1][j];
			else
				dp[i][j]=0;
			fxck=0;
			for(int k=j-1;pos[k]>cpos[i]&&k>=0;k--)
				fxck+=(INT)dp[i][k]*dp[chr[pos[k]+1]][j];
			dp[i][j]=(dp[i][j]+fxck)%Mod;
		}
	OVER("%d\n",dp[0][cntnum-1]);
}