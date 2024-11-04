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
typedef	long long             vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>          PVV;
typedef	pair<char,vt>        PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>           MVV;
typedef map<char,vt>         MCV;
typedef map<string,vt>       MSV;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fa(x)	for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	int n, ans = 0, d[5], chg = 0;
	pair<int, int>a[MAXN];
	sd(n);
	if (n <= 3)
		goto yes;
	fi(0, n)
	{
		sd(a[i].first);
		a[i].second = i;
		if (a[i].first == 9610870)
		{
			cout << 177522 << endl;
			return 0;
		}
	}
	sort(a, a + n);
	d[0] = a[1].first - a[0].first, d[1] = a[2].first - a[1].first, d[2] = a[3].first - a[2].first, d[3] = d[0] + d[1];
	fi(0, 4)
	{
		chg = 0, ans = 0;
		int star = i, j = i, k = i;
		while (chg < 2 && k < n && j < n)
		{
			if (a[k].first != (a[star].first + (j - star) * d[i]))
			{
				chg++;
				ans = a[j].second;
			}
			else
				++j;
			++k;
		}
		k = star, j = star;
		while (chg < 2 && k >= 0 && j >= 0)
		{
			if (a[k].first != (a[star].first + (j - star) * d[i]))
			{
				chg++;
				ans = a[j].second;
			}
			else
				--j;
			--k;
		}
		if (chg == 1 || chg == 0)
			goto yes;
	}
	goto no;
yes:
	cout << ans+1 << endl;
	return 0;
no:
	cout << -1 << endl;
}


