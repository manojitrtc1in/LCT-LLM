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
typedef    long long             vt;
typedef unsigned long long   vt2;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fa(x)    for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;++i)
#define fj(x,y) for(int j=x;j<y;++j)
#define fk(x,y) for(int k=x;k<y;++k)
#define fl(x,y) for(int l=x;l<y;++l)
const int MAXN = 3e3 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



int main()
{
	vt k, n, a, b,q;
	scanf("%lld", &q);
	while (q--)
	{
		scanf("%lld%lld%lld%lld", &k, &n, &a, &b);
		vt minv = k - 1 - n * b, base = a - b;
		vt ans = minv /( a - b);
		if ((k - 1) / b < n)
		{
			cout << -1 << endl;
			continue;
		}
		cout << min(n, ans) << endl;
	}
	return 0;
}
