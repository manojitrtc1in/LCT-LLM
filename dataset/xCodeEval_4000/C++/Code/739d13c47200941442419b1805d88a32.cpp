
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
const int Maxn=100005;
inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') { if (ch == '-') f = -1; ch = getchar(); }
	while (ch >= '0' && ch <= '9') { x = x * 10 + ch - '0'; ch = getchar(); }
	return x * f;
}
int n,m;
vector<int> G[Maxn];
vector<int> t;
int vis[Maxn][2];
int pre[Maxn][2];
bool cyc;
void dfs(int x,int f){
	if (vis[x][f]==1 || vis[x][1-f]==1) cyc=true;
	if (vis[x][f]) return;
	vis[x][f]=1;
	for (int i=0;i<G[x].size();i++){
		if (pre[G[x][i]][1-f]==0) pre[G[x][i]][1-f]=x;
		dfs(G[x][i],1-f);
	}
	vis[x][f]=2;
}
int main(){
	scanf("%d %d",&n,&m);
	for (int i=1;i<=n;i++){
		int x;
		x=read();if (!x) t.pb(i);
		while (x--){
			int y;
			y=read();
			G[i].pb(y);
		}
		
	}
	int s;
	scanf("%d",&s);
	dfs(s,0);
	for (int i=0;i<t.size();i++){
	

		if (vis[t[i]][1]){
			printf("Win\n");
			vector<int> ans;
			int nx=t[i];
			int ff=1; 
			while (nx!=s || ff!=0){
				ans.pb(nx);
				nx=pre[nx][ff];
				ff=1-ff;
			}
			ans.pb(s);
			reverse(ans.begin(),ans.end());
			for (int i=0;i<ans.size();i++){
				printf("%d ",ans[i]);
			} 
			printf("\n");
			return 0;
		}
	}
	if (cyc){
		printf("Draw\n");
		return 0;
	}
	printf("Lose\n");
	return 0;
}

