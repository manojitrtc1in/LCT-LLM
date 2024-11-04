#include			  <algorithm>
#include			   <iostream>
#include				<cstring>
#include				<stdio.h>
#include				 <string>
#include			     <vector>
#include				 <time.h>
#include				  <queue>
#include				  <cmath>
#include				    <map>
#include				    <set>
using	namespace	    	 std;
typedef	long long    		  vt;
typedef unsigned long long   vt2;
typedef	pair<vt,vt>		     PVV;
typedef	pair<char,vt>	     PCV;
typedef	pair<string, vt>     PSV;
typedef	map<vt,vt>			 MVV;
typedef map<char,vt>	     MCV;                                                                                   
typedef map<string,vt>	     MSV;
#define	T true
#define F false
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
#define MAXP 2000010
#define LL __int64
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int a[MAXN], n;
int main()
{
	vt2 n, k;
	int t;
	cin >> t;
	while (t--)
	{
		cin >> n >> k;
		vt2 ans = 0;
		if (k > n)
		{
			cout << n << endl;
			continue;
		}
		while (n)
		{
			if (n % k == 0)
			{
				n /= k;
				ans++;
			}
			else
			{
				vt2 t = n % k;
				ans += t;
				n -= t;
			}
		}
		cout << ans << endl;
	}
	return 0;
}
