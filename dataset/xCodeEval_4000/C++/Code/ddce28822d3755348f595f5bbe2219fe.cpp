
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
const int Maxn=55;
const int Maxc=27;
char s1[Maxn],s2[Maxn];
bool dp2[Maxn][Maxn][Maxc];
bool dp3[Maxn][Maxn][Maxc];
int dp[Maxn][Maxn];
vector<pair<int,int> > trans[Maxc];

int main(){
	scanf("%s",s1);
	scanf("%s",s2);
	int p;
	scanf("%d",&p);
	getchar();
	for (int i=0;i<p;i++){
		char a,b,c;
		scanf("%c->%c%c",&a,&b,&c);
		getchar();
		trans[a-'a'].pb(mp(b-'a',c-'a'));
	}
	int n=strlen(s1),m=strlen(s2);
	for (int i=0;i<n;i++){
		dp2[i][i][s1[i]-'a']=true;
	}
	for (int l=2;l<=n;l++){
		for (int i=0;i<n;i++){
			int j=i+l-1;
			if (j>=n) continue;
			for (int ch=0;ch<26;ch++){
				for (int k=i;k<j;k++){
					for (int q=0;q<trans[ch].size();q++){
						int fr=trans[ch][q].first,ed=trans[ch][q].second;
						dp2[i][j][ch]|=(dp2[i][k][fr]&dp2[k+1][j][ed]);
					}
				}
			}
		}
	}
	for (int i=0;i<m;i++){
		dp3[i][i][s2[i]-'a']=true;
	}
	for (int l=2;l<=m;l++){
		for (int i=0;i<m;i++){
			int j=i+l-1;
			if (j>=m) continue;
			for (int ch=0;ch<26;ch++){
				for (int k=i;k<j;k++){
					for (int q=0;q<trans[ch].size();q++){
						int fr=trans[ch][q].first,ed=trans[ch][q].second;
						dp3[i][j][ch]|=(dp3[i][k][fr]&dp3[k+1][j][ed]);
					}
				}
			}
		}
	}
	for (int i=0;i<Maxn;i++){
		for (int j=0;j<Maxn;j++){
			dp[i][j]=1e9;
		}
	}
	dp[0][0]=0;
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			for (int k=1;k<=i;k++){
				for (int l=1;l<=j;l++){
					bool c=false;
					for (int ch=0;ch<26;ch++){
						if (dp2[k-1][i-1][ch] && dp3[l-1][j-1][ch]){
							c=true;
						}
					}
					if (c){
						dp[i][j]=min(dp[i][j],dp[k-1][l-1]+1);
					}
				}
			}
		

		}
	}
	if (dp[n][m]==1e9){
		printf("-1\n");
		return 0;
	}
	printf("%d\n",dp[n][m]);
	return 0;
}