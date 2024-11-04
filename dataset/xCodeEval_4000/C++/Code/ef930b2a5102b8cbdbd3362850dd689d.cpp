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



int a[MAXN], n;
int main()
{
	cin >> n;
	fi(2, n+1)
		if (i % 2 == 0)
			a[i] = 1;
	int cnt = 2;
	for (int i = 3; i <= n; i++)
	{
		if (a[i] != 0)
			continue;
		for (int j = i; j <= n; j += i)
		{
			if (a[j] != 0)
				continue;
			if (j % 2 != 0)
				a[j] = cnt;
		}
		cnt++;
	}
	fi(2, n + 1)
		printf("%d ", a[i]);
	return 0;
}
