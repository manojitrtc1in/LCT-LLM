#include              <algorithm>
#include               <iostream>
#include                <cstring>
#include                <stdio.h>
#include                 <string>
#include                 <vector>
#include                 <time.h>
#include                  <queue>
#include                  <cmath>
#include                    <map>
#include                    <set>
using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
const long long MAXN = 1e7 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int main()
{
	int n, x, y, a[MAXN];
	memset(a, INF, sizeof(a));
	cin >> n >> x >> y;
	for (int i = 8; i <= n + 7; i++)
		scanf("%d", &a[i]);
	for (int i = 8; i <= n + 7; i++)
	{
		int minv=INF;
		for (int j = i - x; j <= i + y; j++)
			minv = min(a[j], minv);
		if (a[i] == minv)
		{
			cout << i-7 << endl;
			return 0;
		}
	}
	return 0;
}
