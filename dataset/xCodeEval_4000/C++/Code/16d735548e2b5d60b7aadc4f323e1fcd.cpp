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
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fa(x)	for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;++i)
#define fj(x,y) for(int j=x;j<y;++j)
#define fk(x,y) for(int k=x;k<y;++k)
#define fl(x,y) for(int l=x;l<y;++l)
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int main()
{
	int n, a[MAXN],last=INF,ln;
	sd(n);
	fi(0, n)
	{
		sd(a[i]);
		if (a[i] >= 0)
			a[i] = -a[i] - 1;
		last = min(last, a[i]);
		if (last == a[i])
			ln = i;
	}
	if (n % 2 == 1)
		a[ln] = -a[ln] - 1;
	fi(0, n)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}