#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <stdio.h>
#include   <string>
#include   <vector>
#include   <time.h>
#include    <queue>
#include    <cmath>
#include      <map>
#include      <set>
using	namespace	    	 std;
typedef	 __int64			  vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>		     PVV;
typedef	pair<char,vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>			 MVV;
typedef map<char,vt>	     MCV;
typedef map<string,vt>	     MSV;
#define	T true;
#define F false;
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 2e5 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int main()
{	
	std::ios::sync_with_stdio(false);
	int n,ans=0;
	cin >> n;
	int k[MAXN];
	fi(0, n)
		cin>>k[i];
	sort(k, k + n);
	for (int i = 1, j = 0; i <= n; i++)
	{
		if (i <= k[j])
		{
			ans++;
			while (j++ || 1)
			{
				if (k[j] > i)
					break;
			}
		}
		if (j >= n)
			break;
	}
	cout << ans << endl;
	return 0;
}
