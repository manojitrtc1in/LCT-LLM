 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

int num[2005];
int n,m;
int a[2005][2005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			char x;
			cin>>x;
			a[i][j]=int(x-'0');
			num[j]+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			if(num[j]-a[i][j]<=0)
			break;
			if(j==m)
			{
				cout<<"YES";
				return 0;
			}
		}
	}
	cout<<"NO";
	return 0;
}
