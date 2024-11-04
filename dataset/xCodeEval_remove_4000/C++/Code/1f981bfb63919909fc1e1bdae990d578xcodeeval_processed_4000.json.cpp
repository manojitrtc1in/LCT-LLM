 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

unsigned long long n,t,total;
ll a[444444];
ll ans[4444444];
bool check;
priority_queue<pair<ll,ll> > q;
pair<ll,ll> tmp;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>t;
	for(int i=1;i<=n+t;i++)
	{
		if(i>t)
		check=true;
		if(i<=n)
		{
			cin>>a[i];
			q.push(mp(a[i],i)); 
		}
		if(check)
		{
			tmp=q.top() ;
			q.pop() ;
			total+=tmp.first *(i-tmp.second );
			ans[tmp.second ]=i;
		}
	}
	cout<<total<<endl;
	for(int i=1;i<=n;i++)
	cout<<ans[i]<<' ';
	return 0;
}
