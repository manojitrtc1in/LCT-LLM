
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
const int Maxn=5005;
char c[Maxn];
int cnt[27];
vector<int> pos[27];
int cc[27];
int main(){
	scanf("%s",c);
	int n=strlen(c);
	for (int i=0;i<n;i++){
		cnt[c[i]-'a']++;
		pos[c[i]-'a'].pb(i);
	}
	double res=0.0;
	for (int i=0;i<26;i++){
		double P=1.0*cnt[i]/n;
		if (!P) continue;
		double Mx=0.0;
		for (int j=1;j<n;j++){
			memset(cc,0,sizeof(cc));
			for (int k=0;k<pos[i].size();k++){
				cc[c[(pos[i][k]+j)%n]-'a']++;
			}
			int cnt2=0;
			for (int k=0;k<26;k++){
				if (cc[k]==1){
					cnt2++;
				}
			}
			Mx=max(Mx,1.0*cnt2/(double)(pos[i].size()));
		}
		res=res+Mx*P;
	}
	printf("%.10lf\n",res);
	
	return 0;
}

