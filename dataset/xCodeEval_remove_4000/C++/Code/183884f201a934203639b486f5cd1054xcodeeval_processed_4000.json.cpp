









typedef long long ll;
using namespace std;




























































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































































const int N = 1e5 + 10;
double a[N];
double b[N];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> b[i];
	   
		double l = 0, r = 1e8;
		double ans = 0.0;
		double mid = (l + r) / 2;

		for(int k=1;k<=60;k++)
		{
			mid = (l + r) / 2;
			double max1 = -1, max2 = -1;
			for (int i = 1; i <= n; i++)
			{
				if (abs(a[i] - l) + b[i] > max1) max1 = abs(a[i] - l) + b[i];
				if (abs(a[i] - r) + b[i] > max2) max2 = abs(a[i] - r) + b[i];
			}
			if (max1 > max2) l = mid;
			else r = mid;
		}
		printf("%.7lf\n", mid);
	}

	return 0;
}


















































































































































































































































