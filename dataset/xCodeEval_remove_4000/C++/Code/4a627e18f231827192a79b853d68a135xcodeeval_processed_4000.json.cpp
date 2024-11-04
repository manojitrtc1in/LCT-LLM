










using namespace std;
const double eps = 1e-8;
double dpa[2500][2500];
int gb[2500][2500];
int n, a, b;
double va[2500], vb[2500];
void dpp(double k)
{
	for (int i = 0; i <= n; i++)
	{
		for (int j = 0; j <= a; j++)
		{
			gb[i][j] = 0;
			dpa[i][j] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= a; j++)
		{
			dpa[i][j] = dpa[i - 1][j];
			gb[i][j] = gb[i - 1][j];
			if ((j - 1) >= 0)
			{
				double last1,last2;
				last1 = 0;
				last2 = 0;
				last1 = dpa[i - 1][j - 1] + va[i];
				last2 = dpa[i - 1][j - 1] + va[i] + vb[i] - k - va[i] * vb[i];
				if (last1 > dpa[i][j])
				{
					dpa[i][j] = last1;
					gb[i][j] = gb[i - 1][j - 1];
				}
				if (last2 > dpa[i][j])
				{
					dpa[i][j] = last2;
					gb[i][j] = gb[i - 1][j - 1] + 1;
				}
			}
			double last3;
			last3 = dpa[i - 1][j] + vb[i] - k;
			if (last3 > dpa[i][j])
			{
				dpa[i][j] = last3;
				gb[i][j] = gb[i - 1][j] + 1;
			}
		}
	}
}
int main()
{
	scanf("%d%d%d", &n, &a, &b);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &va[i]);
	}
	for (int i = 1; i <= n; i++)
	{
		scanf("%lf", &vb[i]);
	}
	double l = -20;
	double r =20;
	while ((r - l) > eps)
	{
		double mid = (l + r) / 2;
		dpp(mid);
		if (gb[n][a] > b)
			l= mid;
		else
			r = mid;
	}
	dpp(r);
	printf("%llf\n", dpa[n][a] + b*r);
}