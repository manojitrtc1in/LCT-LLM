









typedef long long ll;
using namespace std;

















































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































const int N = 130;
int a[N];
int b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		memset(a, 0, sizeof a);
		memset(b, 0, sizeof b);

		string s;
		cin >> s;
		int n = s.size();
		for (int i = 0; i < n; i++)
		{
			a[s[i]]++;
		}
		for (int k = 0; k <= 8; k++)
		{
			int num = 0;
			for (int j = 0; j < n; j++)
			{
				if (s[j] == k + '0') num++;
				if (num == a[k + '0']) break;
				 if(s[j]>k+'0')
				{
					 if (s[j] != '9') a[s[j]]--, b[s[j]+1]++, s[j] = '0' - 15;
				}
			}
		}
		for (int i = 0; i <= 9; i++)
		{
			for (int j = 1; j <= a[i + '0']+b[i+'0']; j++)
				cout << i;
		}
		cout << endl;
	}

	return 0;
}





















































































































































