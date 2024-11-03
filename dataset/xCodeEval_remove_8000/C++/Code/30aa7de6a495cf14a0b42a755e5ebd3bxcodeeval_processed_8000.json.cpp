


































































































































































































































































































































using namespace std;
struct node{
	int s,d;
};
void solve()
{
	int n;
	cin >> n;
	bool vis[11] = {};
	vector < node > a( n + 1 );
	for( int i = 1; i <= n; i ++)
	{
		cin >> a[i].s >> a[i].d;
	}
	int res = 0, sum = 0;
	sort( a.begin()+1, a.end(), [](node a,node b)
	{
		return a.s>b.s;
	});
	for( int i = 1; i <= n ;i ++ )
	{
		if( !vis[a[i].d] )
		{
			sum ++;
			res += a[i].s;
			vis[a[i].d] = 1;
		}
	}
	if( sum < 10)
	{
		cout << "MOREPROBLEMS" << endl;
	}
	else cout << res << endl;
	
}
int main()
{
	int t;
	cin >> t;
	while( t -- )
	{
		solve();
	}
}