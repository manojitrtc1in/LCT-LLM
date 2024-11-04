#include <iostream>
#include <algorithm>
#include <string.h>
#include <queue>
#include <map>
#include <vector>
#include <math.h>


using namespace std;
typedef long long ll;
#define pa pair<int,int>
inline int read() {
	char ch = getchar();int x = 0, f = 1;
	while (ch < '0' || ch>'9') { if (ch == '-')f = -1;ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0';ch = getchar(); }
	return x * f;
}

















































const int N = 1e7+5,maxx=1e7+5;
ll prime[N],d[N], num[N],vis[N],c[maxx];
int t, n;
void euler()
{
	vis[0] = vis[1] = 1;d[1] = 1;
	int cnt = 0;
	for (ll i = 2;i <= N;i++)
	{
		if (vis[i] == 0)
		{
			prime[++cnt] = i, num[i] = i + 1, d[i] = i + 1;
			if (c[i + 1] != 0)
				c[i + 1] = min(c[i + 1], i );
			else
				c[i + 1] = i ;
		}
		for (int j = 1;j <= cnt && i * prime[j] <= N;j++)
		{
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0)
			{
				

				num[i * prime[j]] = num[i] * prime[j] + 1;
				d[i * prime[j]] = d[i] / num[i] * num[i * prime[j]];
				if (d[i * prime[j]] <= maxx)
					if (c[d[i * prime[j]]] != 0)
						c[d[i * prime[j]]] = min(i * prime[j], c[d[i * prime[j]]]);
					else
						c[d[i * prime[j]]] = i * prime[j];
				break;
			}
			d[i * prime[j]] = d[i] * d[prime[j]];
			num[i * prime[j]] = num[prime[j]];
			if (d[i * prime[j]] <= maxx)
				if (c[d[i * prime[j]]] != 0)
					c[d[i * prime[j]]] = min(i * prime[j], c[d[i * prime[j]]]);
				else
					c[d[i * prime[j]]] = i * prime[j];
		}
	}
}
int main()
{
	t = read();
	euler();
	c[1] = 1;
	while (t--)
	{
		n = read();
		if (c[n] )
			cout <<c[n] << endl;
		else
			cout << "-1\n";
	}
}