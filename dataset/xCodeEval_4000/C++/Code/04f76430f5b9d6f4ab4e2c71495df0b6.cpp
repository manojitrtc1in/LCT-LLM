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
#define	T true
#define F false
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
#define MAXP 2000010
const int MAXN = 2e5 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



int a[MAXN], b[MAXN], order[MAXN];
int main()
{
	int n, ans = 0;
	sd(n);
	fi(1, n + 1)
		sd(a[i]);
	fi(1, n + 1)
	{
		sd(b[i]);
		order[b[i]] = i;
	}
	if (order[1])
	{
		int i, j;
		for (i = 2; order[i] == order[1] + i - 1; i++)
			;
		if (order[i - 1] == n)
		{
			for (j = i; j <= n && order[j] <= j - i; j++)
				;
			if (j > n)
			{
				printf("%d", n - i + 1);
				return 0;
			}
		}
	}
	fi(1, n + 1)
		ans = max(ans, order[i] - i + 1 + n);
	printf("%d\n", ans);
	return 0;
}
