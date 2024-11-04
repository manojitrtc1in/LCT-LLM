












using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	char src[3] = { 'a','b','c' };
	string s, t, sr[6] = { "abc","acb","bac","bca","cab","cba" };
	cin >> n >> s >> t;
	int cnt = 0;
	for (int i = 0; i < 6; ++i)
	{
		string temp;
		for (int j = 0; j < 6; ++j)
		{
			temp.clear();
			temp += sr[i];
			temp += sr[j];
			temp += sr[i];
			if (temp.find(s) == -1 && temp.find(t) == -1)
			{
				cout << "YES" << endl;
				for (int k = 1; k <= n; k++)
				{
					if (k % 2 == 1)
						cout << sr[i];
					else
						cout << sr[j];
				}
				cout << endl;
				return 0;
			}
		}
	}
	for (int i = 0; i < 6; ++i)
		if (sr[i].find(s) == -1 && sr[i].find(t) == -1)
		{
			cout << "YES" << endl;
			for (int k = 0; k < 3; ++k)
				for (int j = 0; j < n; ++j)
					cout << sr[i][k];
			return 0;
		}
	cout << "NO" << endl;
	return 0;
}
