












using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;



int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, str, in, exp;
	for (cin >> t; t--;)
	{
		cin >> str >> in >> exp;
		if (exp == 0)
			cout << (str>in) << endl;
		else
		{
			double ans;
			if (str > in + exp)
				ans = exp + 1;
			else
				ans = ceil((double)exp - (double)(exp + in - str) / 2);
			int ans_ = ans;
			cout << max(0, ans_) << endl;
		}
	}
}

