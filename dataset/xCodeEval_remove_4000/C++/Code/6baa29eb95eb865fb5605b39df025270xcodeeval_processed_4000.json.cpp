






































const ll INF = 1ll<<60;


using namespace std;




int main(){

ios_base::sync_with_stdio(false);
cin.tie(NULL);
ll t;
cin>>t;
ll a,b;
while(t--)
{
	ll n,x;
	cin>>n>>x;
	vi g[n+1];
	

	

	repi(1,n)
	{
		cin>>a>>b;
		g[a].pb(b);
		g[b].pb(a);
	}
	if(g[x].size()<=1)print("Ayush");
	else
	{
		ll c=0;
		ll cn=0;
		ll turn=0;
		c=g[x].size();
		cn=n-1-g[x].size();
		if(cn%2==0)turn=0;
		else turn=1;
		ll ans;
		if(c%2==1)
		{
			ans=turn;
		}
		else ans=!turn;
		if(ans==0)print("Ayush");
		else print("Ashish");
	}
}
  return 0;
}
