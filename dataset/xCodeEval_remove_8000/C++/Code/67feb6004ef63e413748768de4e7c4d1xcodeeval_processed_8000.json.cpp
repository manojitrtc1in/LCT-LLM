

using namespace std;
typedef long long ll;



























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































const int N = 2e5 + 10;
int b[11];
bool check()
{
	int mx = -1;
	int num = 0;
	for (int i = 0; i < 10; i++)
	{
		if (b[i] > 0) num++;
		if (b[i] > mx)
		{
			mx = b[i];
		}
	}
	return mx <= num;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;

	while (tt--)
	{
		int n;
		cin >> n;
		string s;
		cin >> s;
		ll ans = 0;
		
		for (int k = 1; k <= n && k < 110; k++)
		{
			memset(b, 0, sizeof b);
			for (int j = 0; j < k; j++)
			{
				int x = s[j] - '0';
				b[x]++;
			}
			if (check()) ans++;
			for (int i = k; i < n; i++)
			{
				int x = s[i] - '0';
				int y = s[i - k] - '0';
				b[x]++;
				b[y]--;
				if (check()) ans++;
			}
		}
	
		 
		cout << ans << endl;

	}
	
	return 0;
}





















































































































