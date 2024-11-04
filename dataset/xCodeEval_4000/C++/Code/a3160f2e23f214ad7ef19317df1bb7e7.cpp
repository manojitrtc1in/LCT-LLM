
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
const int Maxn=65;
LL r[Maxn];
int main(){
	int q;
	scanf("%d",&q);
	while (q--){
		int tp;
		scanf("%d",&tp);
		if (tp==3){
			LL x;
			scanf("%I64d",&x);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			

			x+=r[lvl];
			if (x>=(1ll<<lvl)) x-=(1ll<<(lvl-1));
			LL ans=0;
			for (int i=lvl;i>=1;i--){
				LL nd=x-r[i];
				if (nd>=(1ll<<i)){
					nd-=(1ll<<(i-1));
				}
				if (nd<(1ll<<(i-1)))nd+=1ll<<(i-1);
				printf("%I64d ",nd);
				x>>=1;
			}
			printf("\n");
		}
		else if (tp==1){
			LL x,k;
			scanf("%I64d %I64d",&x,&k);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			r[lvl]+=k;
			LL siz=1ll<<(lvl-1);
			r[lvl]=(r[lvl]%siz+siz)%siz;
		}
		else if (tp==2){
			LL x,k;
			scanf("%I64d %I64d",&x,&k);
			int lvl=0;
			for (int i=0;i<63;i++){
				if((1ll<<i)>x){
					lvl=i;
					break;
				}
			}
			k%=1ll<<(lvl-1);
			if (k<0) k+=(1ll<<(lvl-1));
			for (int i=lvl;i<=63;i++){
				r[i]+=k;
				LL siz=1ll<<(i-1);
				k*=2;
				r[i]=(r[i]%siz+siz)%siz;
			}
		}
	}
}
