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
#include				<fstream>
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
	vt a[3];
	vt q;
	cin >> q;
	while (q--)
	{
		fi(0, 3)
			cin >> a[i];
		cout << (a[0] + a[1] + a[2]) / 2 << endl;
	}
}
