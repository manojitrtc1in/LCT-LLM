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
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 6e5 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



vt n, mp[MAXN];
vt mod= 998244353;
int main()
{
	sl(n);
	vt ans = n;
	fi(0, n-1)
	{
		vt v, u;
		scanf("%lld%lld", &v, &u);
		ans = ans * (++mp[u]) % mod * (++mp[v]) % mod;
	}
	printf("%lld\n", ans);
	return 0;
}
