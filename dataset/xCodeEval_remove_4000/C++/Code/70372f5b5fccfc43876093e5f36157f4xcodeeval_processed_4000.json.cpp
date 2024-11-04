 















































using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<pair<int,int>,int> piii;
typedef vector<int> vi;
const int INF=1e9+7;

ll n,ans=0;
ll front[100005];
ll back[100005];
vector<ll> ba;
vector<ll> fro;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	for(int i=1;i<=100000;i++)
	{
		back[i]=-1;
		front[i]=INF;
	}
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll x;
		cin>>x;
		front[x]=min(front[x],i);
		back[x]=max(back[x],i);
	}
	for(int i=1;i<=100000;i++)
	{
		if(back[i]!=-1)
		ba.push_back(back[i]);
		if(front[i]!=INF)
		fro.push_back(front[i]); 
	}
	sort(fro.begin() ,fro.end() );
	sort(ba.begin() ,ba.end() );
	
	for(int i=ba.size()-1 ;i>=0 ;i--)
	{
		ans+=lower_bound(fro.begin() ,fro.end() ,ba[i])-fro.begin() ;
	}
	cout<<ans;
	return 0;
}
