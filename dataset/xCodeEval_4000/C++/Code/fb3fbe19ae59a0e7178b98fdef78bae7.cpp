
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
int l[Maxn],r[Maxn];
int n,m;
int sum[Maxn];
int dp1[Maxn],dp2[Maxn];
int bit[Maxn];
void modify(int pos,int val){
	while (pos<Maxn){
		bit[pos]=max(bit[pos],val);
		pos+=pos&-pos;
	}
}
int query(int pos){
	int ans=0;
	while (pos){
		ans=max(ans,bit[pos]);
		pos-=pos&-pos;
	}
	return ans;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=0;i<n;i++){
		scanf("%d%d",&l[i],&r[i]);
		sum[l[i]]++;
		sum[r[i]+1]--;
	}
	for (int i=1;i<=m;i++){
		sum[i]+=sum[i-1];
	}
	dp1[0]=0;
	for (int i=1;i<=m;i++){
		dp1[i]=query(sum[i]+1)+1;
		modify(sum[i]+1,dp1[i]);
	}
	memset(bit,0,sizeof(bit));
	for (int i=m;i>=1;i--){
		dp2[i]=query(sum[i]+1)+1;
		modify(sum[i]+1,dp2[i]);
	}
	int ans=0;
	for (int i=1;i<=m;i++){
		ans=max(ans,dp1[i]+dp2[i]-1);
	}
	printf("%d\n",ans);
	return 0;
}

