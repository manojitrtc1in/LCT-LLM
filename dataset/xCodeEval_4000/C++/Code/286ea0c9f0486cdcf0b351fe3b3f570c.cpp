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
#define	T true
#define F false
#define sd(x)   scanf("%d",&x)
#define sl(x)   scanf("%lld",&x)
#define ss(x)   scanf("%s",&x)
#define fi(x,y) for(int i=x;i<y;i++)
#define fj(x,y) for(int j=x;j<y;j++)
#define fk(x,y) for(int k=x;k<y;k++)
#define MAXP 2000010
const int MAXN = 6e6 + 99, INF = 0x3f3f3f3f;
const int MAXR = 1e5 + 99, MAXC = 1e5 + 99;
vt HASHprime = 13331;



int main()
{
	int ai[MAXN];
	int n;
	sd(n);
	fi(0, n)
		sd(ai[i]);
	int j=0, k=0, l=0, m=0,v=0;
	int ans = 0;
	int first = 0;
	int flag = 0;
	fi(0, n)
	{
		if (ai[i] == 4)
		{
			if (first == 0)
				j = i+1;
			for (; j < n; j++)
				if (ai[j] == 8 && j > i)
					break;
			if (j >= n)
				break;
			if (first == 0)
				k = j+1;
			for (; k < n; k++)
				if (ai[k] == 15 && k > j)
					break;
			if (k >= n)
				break;
			if (first == 0)
				l = k+1;
			for (; l < n; l++)
				if (ai[l] == 16 && l > k)
					break;
			if (l >= n)
				break;
			if (first == 0)
				m = l+1;
			for (; m < n; m++)
				if (ai[m] == 23 && m > l)
					break;
			if (m >= n)
				break;
			if (first == 0)
				v = m+1;
			for (; v < n; v++)
				if (ai[v] == 42 && v > m)
					break;
			if (v >= n)
				break;
			ans++;
			j++, l++, k++, m++, v++;
			first = 1;
		}
	}
	cout << n-ans*6 << endl;
	return 0;
}




