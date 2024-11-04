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
inline void cmax(int &a,int b){
	a=max(a,b);
}
inline void cmin(int &a,int b){
	a=min(a,b);
}
const int Maxn=100005;
bitset<100005> bs[26];
char c[Maxn],ch[Maxn];
int main(){
	scanf("%s",c);
	int n=strlen(c);
	for (int i=0;i<n;i++){
		bs[c[i]-'a'][i]=1;
	}
	int q;
	scanf("%d",&q);
	for (int i=0;i<q;i++){
		int tp;
		scanf("%d",&tp);
		if (tp==1){
			int pos;
			char cc;
			scanf("%d %c",&pos,&cc);
			pos--;
			bs[c[pos]-'a'][pos]=0;
			c[pos]=cc;
			bs[c[pos]-'a'][pos]=1;
		}
		else{
			int l,r;
			scanf("%d %d",&l,&r);
			l--;
			scanf("%s",ch);
			int len=strlen(ch);
			if (r-l+1<len){
				printf("0\n");continue;
			}
			r-=len;
			r++;
			bitset<Maxn> ans;
			ans=~ans;
			for (int i=0;i<len;i++){
				ans&=(bs[ch[i]-'a']>>i);
			}
			printf("%d\n",(ans>>l).count()-(ans>>r).count());
		}
	}
} 
