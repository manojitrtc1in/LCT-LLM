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
	int m, n;
	cin >> n >> m;
	int a[MAXN], b[MAXN + 2];
	pair<int, int> R[MAXN];
	int cnt = 0;
	a[1] = n;
	memset(b, -1, sizeof(b));
	fi(0, m)
	{
		int t, l, r;
		cin >> t >> l >> r;
		if (t)
			fj(l + 1, r + 1)
			b[j] = 0;
		else
			R[cnt].first = l, R[cnt++].second = r;
	}
	fi(2, n + 1)
		a[i] = a[i - 1] + b[i];
	fi(0, cnt)
	{
		int l = R[i].first, r = R[i].second,flag;
		flag = 0;
		fj(l+1, r + 1)
		{
			if (a[j] < a[j - 1])
			{
				flag = 1;
				break;
			}
		}
		if (!flag)
		{
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES" << endl;
	fi(1, n + 1)
		cout << a[i] << ' ';
}
