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
const int MAXN = 1e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
vt HASHprime = 1333331;



int main()
{
	int m, n, stu, cnt = 0;
	cin >> m >> n;
	map<int, int> k;
	fi(0, m)
	{
		cin >> stu;
		k[stu]++;
		if (!(k[stu] % 2))
			cnt++;
	}
	if (cnt == (m + 1) / 2)
		cout << m << endl;
	else
		cout << (m + 1) / 2 + cnt << endl;
}
