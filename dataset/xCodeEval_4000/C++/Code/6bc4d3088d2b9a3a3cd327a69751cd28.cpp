
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
const int Maxn=400005;
int p[Maxn][20];
int pp[Maxn][20];
LL W[Maxn][20],ww[Maxn][20];
int main(){
	int q;
	scanf("%d",&q);
	int lst=0;
	int cur=1;
	for (int i=0;i<=19;i++)p[1][i]=pp[1][i]=-1;
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int R;
			LL w;
			scanf("%d %I64d",&R,&w);
			R^=lst;
			w^=(LL)lst;
			cur++;
			p[cur][0]=R;
			W[cur][0]=w;
			for (int j=1;j<20;j++){
				if (p[cur][j-1]==-1){
					p[cur][j]=-1;
					W[cur][j]=W[cur][j-1];
				}
				else{
					p[cur][j]=p[p[cur][j-1]][j-1];
					W[cur][j]=max(W[cur][j-1],W[p[cur][j-1]][j-1]);
				}
			}
			int ux=R;
			for (int j=19;j>=0;j--){
				

				

				if (ux!=-1 && W[ux][j]<w){
					ux=p[ux][j];
				}
			}
			

			pp[cur][0]=ux;
			ww[cur][0]=w;
			for (int j=1;j<20;j++){
				if (pp[cur][j-1]==-1) pp[cur][j]=-1,ww[cur][j]=ww[cur-1][j];
				else {
					pp[cur][j]=pp[pp[cur][j-1]][j-1];
					ww[cur][j]=ww[cur][j-1]+ww[pp[cur][j-1]][j-1];
				}
			}
		}
		else{
			int R;
			LL lim;
			scanf("%d %I64d",&R,&lim);
			R^=lst;
			lim^=(LL)lst;
			

			int ans=0;
			for (int j=19;j>=0;j--){
				if (pp[R][j]==-1) continue;
				if (lim>=ww[R][j]){
					lim-=ww[R][j];
					ans+=(1<<j);
					

					R=pp[R][j];
				}
			}
			

			

			if (lim>=ww[R][0]){
				ans++;
			}
			printf("%d\n",ans);
			lst=ans;
		}
	}
	return 0;
}



