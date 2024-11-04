
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
const int Maxn=10005;
char c[Maxn];
vector<int> G[Maxn];
bool dop;
vector<pair<int,int> > solve(int lo,int hi){
	if (lo==hi){
		vector<pair<int,int> > ret;
		ret.resize(101,mp(-1e9,1e9));
		ret[0]=mp(c[lo]-'0',c[lo]-'0');
		return ret;
	}
	int cur=0,pos;
	for (int i=lo+1;i<hi;i++){
		if (!cur && c[i]=='?'){
			pos=i;
			break;
		}
		if (c[i]=='(') cur++;
		else if (c[i]==')') cur--;
	}
	vector<pair<int,int> > lans=solve(lo+1,pos-1),rans=solve(pos+1,hi-1),fans;
	fans.resize(101,mp(-1e9,1e9));
	for (int i=0;i<=100;i++){
		for (int uu=0;uu<2;uu++){
			for (int j=0;j<=i-uu;j++){
				if (dop^uu)
					fans[i].first=max(fans[i].first,lans[j].first-rans[i-j-uu].second),
					fans[i].second=min(fans[i].second,lans[j].second-rans[i-j-uu].first);
				else
					fans[i].first=max(fans[i].first,lans[j].first+rans[i-j-uu].first),
					fans[i].second=min(fans[i].second,lans[j].second+rans[i-j-uu].second);
			}
		}
	}
	return fans;
}
int main(){
	scanf("%s",c);
	int l=strlen(c);
	int P,M;
	scanf("%d %d",&P,&M);
	if (P<=100) dop=true;
	vector<pair<int,int> > ans=solve(0,l-1);
	int lp=(dop)?P:M;
	printf("%d\n",ans[lp].first);
	return 0;
}



