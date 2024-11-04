 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

ll n,m;
pair<ll,pii > a[100005];
vector<ll> check;
ll ans[100005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first ;
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i].second.first;
		a[i].second .second=i;
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	{
		ans[a[i].second .second]=a[i].second .first;
		for(int j=0;j<check.size() ;j++)
		{
			ans[a[i].second .second]+=check[j];
		}
		check.pb(a[i].second .first);
		sort(check.begin() ,check.end(),greater<ll>() );
		if(check.size() >m)
		check.pop_back() ;
	}
	for(int i=0;i<n;i++)
	cout<<ans[i]<<' ';
	return 0;
}
