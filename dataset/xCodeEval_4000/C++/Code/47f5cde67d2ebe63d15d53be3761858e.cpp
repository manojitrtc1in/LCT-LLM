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
typedef long long             ll;
typedef unsigned long long   llu;
typedef pair<int, int>       pii;
const long long MAXN = 2e5 + 99, INF = 0x3f3f3f3f, MAXP = 1e4;
ll HASHprime = 1333331;


ll cn2(ll n)
{
	return (n * (n - 1)) / 2;
}
int main()
{
	int t;
	for (cin >> t; t--;)
	{
		int n;
		scanf("%d", &n);
		ll tre=0;
		for (tre = (ll)sqrt(n); cn2(tre) <= n; tre++)
			;
		tre--;
		ll sev = n - cn2(tre);
		printf("133");
		for (int i = sev; i > 0; i--)
			printf("7");
		for (int i = tre-2; i > 0; i--)
			printf("3");
		printf("7\n");
	}
	return 0;
}
