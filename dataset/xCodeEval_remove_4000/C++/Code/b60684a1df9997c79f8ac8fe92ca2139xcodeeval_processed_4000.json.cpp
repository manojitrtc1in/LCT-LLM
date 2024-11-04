
using namespace std;

typedef pair<int,int> pii ;























const db PI = 3.141592653589793238462643383;
const long long INF = 1e9+7;
const long long mod = 998244353;
int getID(char c)
{
	if(c == ' ') return 0;
	return c - 'a' + 1 ;
}

ll pw(ll a,ll b)
{
ll res=1ll;
while(b)
{
if(b&1ll) res=(res*a);
a=(a*a);
b>>=1;
}
return res;
}










void solve()
{

int n,m; cin>>n>>m;
int a[m] , b[n];
char v[n][m];
rep(i,0,n)
{
	rep(j,0,m)
	{
		cin>>v[i][j];
	}
}
rep(i,0,n)
{
	b[i]=0;
	rep(j,0,m)
	{
		if(v[i][j]=='*')
		b[i]++;
	}
}
rep(i,0,m)
{
	a[i]=0;
	rep(j,0,n)
	{
		if(v[j][i]=='*')
		a[i]++;
	}
}
ll ans=0;
rep(i,0,n)
{
	rep(j,0,m)
	{
		if(v[i][j]=='*')
		{
			ans+= 1ll*(b[i]-1) * 1ll*(a[j]-1);
		}
	}
}
cout<<ans;
return;
}
int main()
{
ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t=1;


while(t--)
{
solve();
}
return 0;
}








































































































