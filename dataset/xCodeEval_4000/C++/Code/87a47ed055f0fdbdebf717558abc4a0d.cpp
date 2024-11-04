
#include<cmath>
#include<math.h>
#include<ctype.h>
#include<algorithm>
#include<bitset>
#include<cassert>
#include<cctype>
#include<cerrno>
#include<cfloat>
#include<ciso646>
#include<climits>
#include<clocale>
#include<complex>
#include<csetjmp>
#include<csignal>
#include<cstdarg>
#include<cstddef>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<ctime>
#include<cwchar>
#include<cwctype>
#include<deque>
#include<exception>
#include<fstream>
#include<functional>
#include<iomanip>
#include<ios>
#include<iosfwd>
#include<iostream>
#include<istream>
#include<iterator>
#include<limits>
#include<list>
#include<locale>
#include<map>
#include<memory>
#include<new>
#include<numeric>
#include<ostream>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<stdexcept>
#include<streambuf>
#include<string>
#include<typeinfo>
#include<utility>
#include<valarray>
#include<vector>
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
#define LL long long
#define ll   long long
#define ull unsigned long long
#define ULL ull
#define mp make_pair
#define pii pair<int,int>
#define piii pair<int, pii >
#define pll pair <ll,ll>
#define pb push_back
#define PB pop_back
#define p push
#define P pop
#define INF 2147483647
#define ull unsigned long long
#define vi vector < int >
#define vpii vector < pii >
#define pq priority_queue
#define rep(i,n) for (int (i)=0;(i)<n;(i)++)
#define End return 0
#define mi multiset <int>
#define si set <int>
#define sll set<ll>
#define mll multiset<ll>
#define vll vector <ll>
#define Rep(i,a,b) for (int (i)=(a);(i)<=(b);(i)++)
using namespace std;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=100005;
LL v[Maxn],t[Maxn];
LL sum[Maxn],sum2[Maxn];
LL ans1[Maxn],ans2[Maxn];
LL res[Maxn];
int main(){
	int n;
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%I64d",&v[i]);
		sum2[i]=sum2[i-1]+v[i];
	}
	for (int i=1;i<=n;i++){
		scanf("%I64d",&t[i]);
		sum[i]=sum[i-1]+t[i];
	}
	for (int i=1;i<=n;i++){
		int lo=i-1,hi=n+1;
		while (hi-lo>1){
			int mid=lo+hi>>1;
			if (sum[mid]-sum[i-1]>v[i]){
				hi=mid;
			}
			else{
				lo=mid;
			}
		}
		

	

		ans1[i]++;
		ans1[lo+1]--;
		ans2[i]+=sum[i-1]+v[i];
		ans2[lo+1]-=sum[i-1];
		ans2[lo+1]-=v[i];
	}
	for (int i=1;i<=n;i++){
		

		ans1[i]+=ans1[i-1];
		ans2[i]+=ans2[i-1];
		res[i]=sum2[i]-(ans2[i]-ans1[i]*sum[i]);
	}
	for (int i=1;i<=n;i++){
		printf("%I64d ",res[i]-res[i-1]);
	}
	printf("\n");
	return 0;
}

