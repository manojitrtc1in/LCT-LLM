
















using namespace std;




int main()
{
	std::ios::sync_with_stdio(false);
	int n,m,q;
	cin>>n>>m>>q;
	int a[45][45];
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			char ch;
			cin>>ch;
			if (ch == '0')
				a[i+1][j+1] = 1;
		}
	}
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			a[i][j] += a[i-1][j] + a[i][j-1] - a[i-1][j-1];
		}
	}
	int s[45][45][45][45] = {0};
	for (int i = 1; i <=n; i++)
	{
		for (int j = 1; j <=m; j++)
		{
			for (int x = i; x <=n; x++)
			{
				for (int y = j; y <=m; y++)
				{
					int ar = (x-i+1)*(y-j+1);
					int z = a[x][y]-a[x][j-1]-a[i-1][y]+a[i-1][j-1];
					if (ar == z)
						s[i][j][x][y] = 1;
					s[i][j][x][y] += s[i][j][x][y-1] + s[i][j][x-1][y] - (s[i][j][x-1][y-1]);
				}
			}
		}
	}
	while (q--)
	{
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		long long r = 0;
		for (int i = a; i<=c;  i++)
		{
			for (int j = b; j <= d; j++)
			{


				r+= s[i][j][c][d];
			}
		}
		cout<<r<<endl;
	}


}