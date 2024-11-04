










using namespace std;
typedef __int64 vt;
const int MAXM = 5e2+99;
using namespace std;
vt id0[600][600], id1[600][600];
int main()
{
	int n, m;
	cin >> n >> m;
	int cnt1 = 0;
	memset(id0, -1, sizeof(id0));
	memset(id1, -1, sizeof(id1));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			cin >>id0[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
		{
			cin >> id1[i][j];
			if (id1[i][j] < id0[i][j])
				swap(id1[i][j], id0[i][j]);
		}
	for (int x = 1; x <= n; x++)
		for (int y = 1; y <= m; y++)
		{
			if (id0[x][y] <= id0[x - 1][y] || id0[x][y] <= id0[x][y - 1] || id1[x][y] <= id1[x - 1][y] || id1[x][y] <= id1[x][y - 1])
			{
				cout << "Impossible" << endl;
				return 0;
			}
		}
	cout << "Possible" << endl;
	return 0;
}
