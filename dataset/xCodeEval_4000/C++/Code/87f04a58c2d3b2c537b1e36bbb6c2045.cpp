
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
#include<tr1\unordered_map>
using namespace std;
using namespace tr1;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
const int Maxn=500005;
vector<int> M[30];
int n,m;
char tmp[20];
vector<string> pr[15];
string Gt(){
	scanf("%s",&tmp);
	return (string)tmp;
}
string p[16];
int dp[50000][107];
void Cl(){
	for (int i=0;i<(1<<n);i++){
		for (int j=0;j<=n*(n-1)/2;j++){
			dp[i][j]=1e6;
		}
	}
}
int FindNxt(int pos,int v){
	

	if (M[pos].empty()||M[pos].back()<v) return 1e6;
	int ans=M[pos][lower_bound(M[pos].begin(),M[pos].end(),v)-M[pos].begin()];
	return ans;
}
int main(){
	scanf("%d",&n);
	for (int i=0;i<n;i++){
		p[i]=Gt();
	}
	scanf("%d",&m);
	int id=-1,ans=1e9;
	for (int ii=0;ii<m;ii++){
		for (int j=0;j<n;j++){
			M[j].clear();
		}
		int k;
		scanf("%d",&k);
		for (int j=1;j<=k;j++){
			string tt=Gt();
			pr[ii].pb(tt);
			for (int l=0;l<n;l++){
				if (tt==p[l]){
					M[l].pb(j);
				}
			}
		}
	

		Cl();
		dp[0][0]=0;
		for (int i=0;i<(1<<n);i++){
			int cur=0;
			for (int j=0;j<n;j++){
				if (i & (1<<j)) cur++;
			}
			for (int j=0;j<=n*(n-1)/2;j++){
				if (dp[i][j]==1e6) continue;
				if (i==(1<<n)-1){
					if (j<ans){
						ans=j;
						id=ii;
					}
					continue;
				}
				int td=cur;
				for (int k=0;k<n;k++){
					if (i & (1<<k)){
						td--;
						continue;
					}
					dp[i|(1<<k)][j+td]=min(dp[i|(1<<k)][j+td],FindNxt(k,dp[i][j]+1));
				}
			}
		}
	}
	if (id==-1){
		printf("Brand new problem!\n");
	}
	else{
		printf("%d\n[:",id+1);
		for (int i=0;i<(n*(n-1)/2)-ans+1;i++){
			printf("|");
		}
		printf(":]\n");
	}
	return 0;
}
