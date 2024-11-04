
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
const int Maxn=2005;
string s,t;
int n;
int v[27];
vector<int> ans;
void shift(int vv){
	ans.pb(n-vv);
	string ss=s.substr(0,vv),s2=s.substr(vv);
	reverse(s2.begin(),s2.end());
	s=s2+ss;
}
int main(){
	cin>>n;
	cin>>s>>t;
	for (int i=0;i<n;i++){
		v[s[i]-'a']++;
		v[t[i]-'a']--;
	}
	for (int i=0;i<26;i++){
		if (v[i]!=0){
			printf("-1\n");
			return 0;
		}
	}

	for (int pos=0;pos<n;pos++){
		char c=t[pos];
		int gg;
		for (int i=0;i<n-pos;i++){
			if (s[i]==c){
				gg=i;
				break;
			}
		}
		shift(gg+1);
	

		shift(n-1);
	

		shift(0);
		

	}
	printf("%d\n",ans.size());
	for (int i=0;i<ans.size();i++){
		printf("%d ",ans[i]);
	}
	return 0;
}

