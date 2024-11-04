



































using namespace std;



















typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pair<int,int> > pipi;
typedef vector<int> vi;
typedef map<int,int> mii;
typedef map<string,int> msi;
typedef stack<int> sti;
typedef set<int> jihe;
typedef queue<int> qi;
typedef vector<pair<int,int> > vp;
const int inf=1e9+7;
const int maxn=5005;
const int maxm=200005;
int Read(){
    int x=0;char c=getchar();
    while(c>'9'||c<'0')c=getchar();
    while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
    return x;
}






int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin>>n>>m>>k;
	int a[n+5];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	int x=n;
	while(x && m)
	{
		int l=k;
		while(l>=a[x] && x)
		{
			l-=a[x];
			x--;
		}
		m--;
	}
	cout<<n-x<<endl;
    return 0;
}

