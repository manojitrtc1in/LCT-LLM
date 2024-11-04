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
#include				<complex>
#include				<numeric>
using   namespace            std;
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;



int main()
{
	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int t, ans;
	for (cin >> t; t--;)
	{
		ans = 1;
		int n, hp, maxd = -INF, maxdelta = -INF;
		pair<int, int>attact[MAXN];
		cin >> n >> hp;
		for (int i = 0; i < n; ++i)
		{
			cin >> attact[i].first >> attact[i].second;
			maxd = max(attact[i].first, maxd);
			maxdelta = max(attact[i].first - attact[i].second, maxdelta);
		}
		hp -= maxd;
		if (maxdelta <= 0 && hp > 0)
			cout << -1 << endl;
		else if (hp > 0)
		{
			ans += (int)ceil((double)hp / maxdelta);
			cout << ans << endl;
		}
		else
			cout << ans << endl;
	}
}

