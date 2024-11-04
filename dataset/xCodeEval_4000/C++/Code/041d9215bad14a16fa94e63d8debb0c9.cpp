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
#define	T true;
#define F false;
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
#define MAXP 2000010
#define LL __int64
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 13331;



int main()
{
	int n;
	int a[MAXN];
	bool flag1 = false;
	bool flag2 = false;
	scanf("%d", &n);
	fi(0, n)
	{
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0)
			flag1 = true;
		else
			flag2 = T;
	}
	if (flag1 && flag2)
		sort(a, a + n);
	fi(0, n)
		printf("%d ", a[i]);
	return 0;
}
