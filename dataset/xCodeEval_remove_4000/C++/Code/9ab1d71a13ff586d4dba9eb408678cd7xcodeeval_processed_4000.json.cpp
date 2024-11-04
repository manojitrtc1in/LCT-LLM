 
















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
typedef pair<pii,pii > piiii;
const int INF=1e9+7;

int g[555][555];
int n,m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>g[i][j];
		}
	}
	
	int best=-1;
	vector<int> best1,best2;
	for(int x=0;x<=555;x++)
	{
		vector<int> a(n),b(m);
		a[0]=x;
		for(itn j=0;j<m;j++)
		b[j]=g[0][j]-x;
		for(int i=0;i<n;i++)
		a[i]=g[i][0]-b[0];
		bool ok=true;
		for(int i=0;i<n;i++)
		ok&=a[i]>=0;
		for(int j=0;j<m;j++)
		ok&=b[j]>=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				ok&=(a[i]+b[j]==g[i][j]);
			}
		}
		if(ok)
		{
			int total=accumulate(a.begin() ,a.end() ,0 )+accumulate(b.begin() ,b.end() ,0);
			if(best==-1 or total<best)
			{
				best=total;
				best1=a;
				best2=b;
			}
		}
	}
	cout<<best<<endl;
	if(best!=-1)
	{
		for(int i=0;i<n;i++)
		for(int j=0;j<best1[i];j++)
		cout<<"row "<<i+1<<endl;
		for(int i=0;i<m;i++)
		for(int j=0;j<best2[i];j++)
		cout<<"col "<<i+1<<endl;
	}
	return 0;
}
