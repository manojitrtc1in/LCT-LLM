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
typedef          long long    vt;
typedef unsigned long long   vt2;
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fa(x)    for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;++i)
#define fj(x,y) for(int j=x;j<y;++j)
#define fk(x,y) for(int k=x;k<y;++k)
#define fl(x,y) for(int l=x;l<y;++l)
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



int main()
{
	char str[MAXN];
	cin >> str;
	int len = strlen(str), cnt = 0, cans[MAXN], co = 0;
	cans[0] = 0;
	fi(0, len + 1)
	{
		if (str[i] == 'v')
			cnt++;
		else
		{
			if (cnt > 1)
				cans[co + 1] = cnt - 1 + cans[co];
			else
				cans[co + 1] = cans[co];
			co++;
			cnt = 0;
		}
	}
	vt ans = 0;
	fi(2, co + 1)
		ans += (vt)(cans[co] - cans[i - 1]) * cans[i - 1];
	cout << ans << endl;
}




