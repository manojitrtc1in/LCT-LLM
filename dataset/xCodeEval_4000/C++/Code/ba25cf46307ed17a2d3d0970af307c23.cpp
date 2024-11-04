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
typedef long long             vt;
typedef unsigned long long   vt2;
#define fa(x)   for(auto &it:x)
#define fi(x,y) for(int i=x;i<y;++i)
#define fj(x,y) for(int j=x;j<y;++j)
#define fk(x,y) for(int k=x;k<y;++k)
#define fl(x,y) for(int l=x;l<y;++l)
#define sync_off ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
const long long MAXN = 1e6 + 9, INF = 1e18, MAXP = 1e4;
vt HASHprime = 1333331;


int main()
{
	sync_off;
	int n, k, a[MAXN], cnt[MAXN], q;
	cin >> q;
	while (q--)
	{
		cnt[0] = 0;
		cin >> n >> k;
		fi(1, n + 1)
		{
			cin >> a[i];
			cnt[i] = a[i] % 2 == 0 ? cnt[i - 1] : cnt[i - 1] + 1;
		}
		if ((cnt[n] - k + 1) % 2 == 0 && cnt[n] > k && k != 1 || cnt[n] < k || k == 1 && cnt[n] % 2 == 0)
			cout << "NO" << endl;
		else
		{
			cout << "YES" << endl;
			int cntans = 0;
			fi(2, n + 1)
			{
				if (cntans == k - 1)
					break;
				if (cnt[i] - cnt[i - 1] == 1 && cnt[i - 1] != 0)
				{
					cout << i - 1 << ' ';
					cntans++;
				}
			}
			cout << n << endl;
		}
	}
	return 0;
}

