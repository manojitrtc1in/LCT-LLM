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
typedef unsigned long long   ull;
const long long MAXN = 1e6 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


int main()
{
	char rgb[4] = "RGB";
	int q;
	scanf("%d", &q);
	while (q--)
	{
		int n, k, sum[MAXN][3];
		sum[0][0] = sum[0][1] = sum[0][2] = 0;
		char s[MAXN];
		scanf("%d%d", &n, &k);
		scanf("%s", &s);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < 3; j++)
				sum[i + 1][j] = (s[i] != rgb[(i % 3 + j)%3]) ? sum[i][j] + 1 : sum[i][j];
		int ans = INF;
		for (int i = 0; i < 3; i++) 
			for (int j = 1; j + k - 1 <= n; j++)
				ans = min(ans, sum[j + k - 1][i] - sum[j - 1][i]);
		cout << ans << endl;
	}
	return 0;
}
