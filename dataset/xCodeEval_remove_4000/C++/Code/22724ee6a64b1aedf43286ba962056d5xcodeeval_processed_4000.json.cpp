 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

int n,m;
priority_queue<ll> q;
int a[500005],l[500005];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	cin>>a[i]>>l[i];
	for(int i=1;i<=n;i++)
	{
		while(!q.empty() and -q.top() <=a[i])
		q.pop() ;
		if(q.size() <m)
		{
			ll ans=a[i]+l[i];
			cout<<ans<<endl;
			q.push(-ans); 
		}
		else
		{
			ll ans=-q.top() +l[i];
			cout<<ans<<endl;
			q.pop() ;
			q.push(-ans); 
		}
	}
	return 0;
}
