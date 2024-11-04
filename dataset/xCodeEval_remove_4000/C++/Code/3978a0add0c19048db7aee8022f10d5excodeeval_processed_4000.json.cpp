










using namespace std;
typedef __int64 vt;
const int MAXN = 3e7 + 9, INF = 0x3f3f3f3f;

bool notprime[MAXP];
vt primes[MAXP];
int dx[] = { 1,0,0 };
int dy[] = { 0,-1,1 };
char gmap[2500][2500];
int n;
bool mys()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (gmap[i][j] == '.')
			{
				gmap[i][j] = '
				if (gmap[i + 1][j] == '.')
				{
					gmap[i + 1][j] = '
					int x = i + 1, y = j;
					for (int k = 0; k < 3; k++)
					{
						if (gmap[x + dx[k]][y + dy[k]] == '.')
							gmap[x + dx[k]][y + dy[k]] = '
						else
							return false;
					}
				}
				else
					return false;
			}
		}
	}
	return true;
}
int main()
{
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin>>gmap[i][j];
	if (mys())
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}
