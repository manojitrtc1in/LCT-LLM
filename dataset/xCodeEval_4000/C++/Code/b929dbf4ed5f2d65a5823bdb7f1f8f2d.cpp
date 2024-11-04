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
	

	char a[MAXN];
	int len, ans = 0;
	scanf("%d", &len);
	scanf("%s", &a);
	char b[3];
	char c[MAXN];
	int p = 0;
	for (int i = 0, j = 0; i < len; i++)
	{
		if (j == 0)
		{
			b[2] = '\0';
			b[j++] = a[i];
			continue;
		}
		else if (b[j - 1] != a[i])
		{
			b[j] = a[i];
			int h;
			for (h = 0; h < 2;h++)
				c[p++] = b[h];
			j = 0;
		}
	}
	c[p] = '\0';
	printf("%d\n", len - strlen(c));
	puts(c);
	return 0;
}
