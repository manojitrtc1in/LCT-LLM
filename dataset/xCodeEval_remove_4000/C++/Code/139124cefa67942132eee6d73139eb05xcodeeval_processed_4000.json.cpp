
































































































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











int a[30];
string cmd[30];

inline string id0(int what)
{
	string ans="eax";
	ans[1]+=what;
	return ans;
}




inline bool dfs(int mxv,int now,int num)
{
	if(a[now]>num)return 0;
	if(now==mxv)
	{
		if(a[now]!=num)return 0;
		cout<<mxv<<endl;
		for(int i=0;i<mxv;i++)
			cout<<cmd[i]<<endl;
		return 1;
	}
	

	for(int i=0;i<=now;i++)
		for(int j=1;j<=8;j<<=1)
		{
			a[now+1]=a[i]*j;
			if(a[now+1]>num)continue;
			if(now+1==mxv&&a[now+1]!=num)continue;
			cmd[now]="lea "+id0(now+1)+", ["+(char)('0'+j)+"*"+id0(i)+"]";
			if(!dfs(mxv,now+1,num))continue;
			return 1;
		}
	

	for(int i=0;i<=now;i++)
		for(int j=0;j<=now;j++)
			for(int k=1;k<=8;k<<=1)
			{
				a[now+1]=a[i]+k*a[j];
				if(a[now+1]>num)continue;
				if(now+1==mxv&&a[now+1]!=num)continue;
				cmd[now]="lea "+id0(now+1)+", ["+id0(i)+" + "+(char)('0'+k)+"*"+id0(j)+"]";
				if(!dfs(mxv,now+1,num))continue;
				return 1;
			}
	return 0;
}

int main()
{
	int n;
	cin>>n;
	a[0]=1;
	for(int i=0;i<30;i++)
		if(dfs(i,0,n))
			return 0;
}
