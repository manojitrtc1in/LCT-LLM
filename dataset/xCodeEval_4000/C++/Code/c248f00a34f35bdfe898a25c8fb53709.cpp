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
#define fa(x)	for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
const int MAXN = 1e6 + 99, INF = 0x3f3f3f3f;
vt HASHprime = 1333331;



int vis1[MAXN], vis2[MAXN];
int main()
{
	int n;
	sd(n);
	while (n--)
	{
		string a, b;
		cin >> a >> b;
		int lena = a.size(), lenb = b.size();
		if (lena >lenb)
		{
			cout << "NO" << endl;
			continue;
		}
		int j = 0, i = 0, flag = 1;
		while (1)
		{
			if (a[i] != b[j])
			{
				flag = 0;
				break;
			}
			int s1 = 1, s2 = 1;
			while (a[i] == a[i + s1])
				s1++;
			while (b[j] == b[j + s2])
				s2++;
			if (s2 < s1)
			{
				flag = 0;
				break;
			}
			if (i + s1 < lena && j + s2 < lenb)
				i += s1, j += s2;
			else
			{
				i += s1 - 1, j += s2 - 1;
				break;
			}
		}
		if (flag&&i==lena-1&&j==lenb-1)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
