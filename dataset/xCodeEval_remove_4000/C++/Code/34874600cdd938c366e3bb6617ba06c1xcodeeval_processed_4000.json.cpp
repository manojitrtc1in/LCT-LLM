












using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t;
	for (cin >> t; t--;)
	{
		string s;
		int ans = 0;
		cin >> s;
		for (int i = 0, cnt = 0; i < s.size(); i++)
		{
			if (s[i] == '1')
			{
				int sum = 0;
				for (int j = i; j < s.size() && j <= i + 19; j++)
				{
					sum = ((sum << 1) + s[j] - '0');
					if (sum <= cnt + j - i + 1 && sum >= j - i + 1)
						ans++;
					else
						break;
				}
				cnt = 0;
			}
			else
				cnt++;
		}
		cout << ans << endl;
	}
}

