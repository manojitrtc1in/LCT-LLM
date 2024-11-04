







#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
#define exp 1e-6
const int maxn = 12;
struct Info
{
	double x;
	double v;
	double m;
	int index;
};
bool comp1(const Info&p, const Info&q)
{
	if (fabs(p.x - q.x) > exp )
	{
		return (p.x - q.x < exp);
	}
	return  p.v - q.v < exp;
}
bool comp2(const Info&p, const Info&q)
{
	return p.index < q.index;
}
int s[maxn];
Info a[maxn];
int main()
{
	int i;
	int n;
	int j;
	double t;
	scanf("%d%lf", &n, &t);
	for (i = 0; i < n; i++)
	{
		scanf("%lf%lf%lf", &a[i].x, &a[i].v, &a[i].m);
		a[i].index = i;
	}
	double c = 0;
	double Min = 100000000.0;
	sort(a, a + n, comp1);
	while (c <= t)
	{
		j = 0;
		Min = 10000000.0;
		

		for (i = 1; i < n; i++)
		{
			if (a[i].v >= exp && a[i - 1].v >= exp && a[i].v >= a[i - 1].v)
			{
				continue;
			}
			if (a[i - 1].v <= exp && a[i].v <= exp && a[i].v >= a[i - 1].v)
			{
				continue;
			}
			if (a[i].v >= exp && a[i - 1].v <= exp)
			{
				continue;
			}
			if (a[i].v >= exp && a[i - 1].v >= exp && a[i].v < a[i - 1].v)
			{
				double cur = (a[i].x - a[i - 1].x) / (a[i - 1].v - a[i].v);
				if (Min > cur)
				{
					j = 0;
					s[j++] = i;
					Min = cur;
				}
				else
				{
					if (Min == cur)
					{
						Min = cur;
						s[j++] = i;
					}
				}
				continue;
			}
			if (a[i - 1].v <= exp && a[i].v <= exp &&  a[i - 1].v > a[i].v)
			{
				double cur = (a[i].x - a[i - 1].x) / (a[i - 1].v - a[i].v);
				if (Min > cur)
				{
					j = 0;
					s[j++] = i;
					Min = cur;
				}
				else
				{
					if (Min == cur)
					{
						Min = cur;
						s[j++] = i;
					}
				}
				continue;
			}
			if (a[i - 1].v > exp && a[i].v < exp)
			{
				double cur = (a[i].x - a[i - 1].x) / (a[i - 1].v - a[i].v);
				if (Min > cur)
				{
					j = 0;
					s[j++] = i;
					Min = cur;
				}
				else
				{
					if (Min == cur)
					{
						Min = cur;
						s[j++] = i;
					}
				}
				continue;
			}
		}
		if (c + Min >= t)
		{
			Min = t - c;
			for (i = 0; i < n; i++)
			{
				a[i].x = a[i].x + a[i].v * Min;
			}
			break;
		}
		for (i = 0; i < n; i++)
		{
			a[i].x = a[i].x + a[i].v * Min;
		}
		for (int k = 0; k < j; k++)
		{
			double temp = a[s[k] - 1].v;
			a[s[k] - 1].v = ((a[s[k] - 1].m - a[s[k]].m) * a[s[k] - 1].v + 2 * a[s[k]].m * a[s[k]].v) / (a[s[k] - 1].m + a[s[k]].m);				
			a[s[k]].v = ((a[s[k]].m - a[s[k] - 1].m) * a[s[k]].v + 2 * a[s[k] - 1].m * temp) / (a[s[k] - 1].m + a[s[k]].m);
		}
		c += Min;
	}
	sort(a, a + n, comp2);
	for (i = 0; i < n; i++)
	{
		printf("%.9lf\n", a[i].x);
	}
	return 0;
}