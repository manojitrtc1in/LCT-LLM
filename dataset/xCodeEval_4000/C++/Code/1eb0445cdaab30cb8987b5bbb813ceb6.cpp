
#ifndef _GLIbCXX_NO_ASSERT
#include <cassert>
#endif
#include <cctype>
#include <cerrno>
#include <cfloat>
#include <ciso646>
#include <climits>
#include <clocale>
#include <cmath>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
 
#if __cplu >= 201103L
#include <ccomplex>
#include <cfenv>
#include <cinttypes>
#include <cstdalign>
#include <cstdbool>
#include <cstdint>
#include <ctgmath>
#include <cwchar>
#include <cwctype>
#include <cstring>
#endif
 


#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include<random>
#include <chrono>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
 
#if __cplu >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <time.h>
#endif
#define __ ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;


#define ull unsigned long long int
#define pii pair<int,int>
#define ll long long int
#define ld long double
#define MSET(x,y) memset(x,y,sizeof(x))


#define se second
#define AlphaSize 26
#define fi first
#define NIL 0
#define UNVISITED -1
#define EXPOLORED 0
#define mk make_pair
#define pb push_back
#define sc(n) scanf("%d",&n)
#define NIL 0
#define db double
#define pii pair<int,int>
#define eps 1e-8
#define inrange(x,y,n,m) ((x>=0 && y>=0 && x<n && y<m))
#define all(x) x.begin(),x.end()
#define me(u,v,w) make_pair(w,make_pair(u,v))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define foreach(e, x) for(__typeof(x.begin()) e = x.begin(); e != x.end(); ++ e)


#define hs(c1,c2) (256*min(c1,c2) + max(c1,c2))
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
typedef struct{ int sum,suf,pre,max;} Node;
int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
const int MAXN = 2e5+100;
const int UP = 31;




const ll highest = 1e18;    




const double pi = acos(-1);
const double Phi =  1.618033988749894;
const int logn = 20;
const double root5 = 2.236067977;   


const int mod = 1e9+7;
const int ini = -1e9;
const int inf = 1e9;

double p[20][20];
double dp[(1<<20)][20];
int n,m;
double solve(int n,int mask){
	if(mask == (1<<m)-1){
		if(n==0)return 1;
		return 0;
	}	
	if(fabs(dp[mask][n]+1)>0.1){
		return dp[mask][n];
	}
	double ans = -1;
	for(int i=0;i<m;++i){
		if(!(mask & (1<<i))){
			ans = max(ans,p[i][n]*solve(i,mask+(1<<i)) + p[n][i]*solve(n,mask+(1<<i)));
		}
	}
	return dp[mask][n] = ans;
}
int main(){
	int n;scanf("%d",&n);
	m = n;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%lf",&p[i][j]);
		}
	}
	for(int i=0;i<=18;++i){
		for(int j=0;j<(1<<18);++j){
			dp[j][i] = -1;
		}
	}
	double ans = -1;
	for(int i=0;i<n;++i){
		ans = max(ans,solve(i,(1<<i)));
	}
	printf("%.9lf\n", ans);
	return 0;
}






 






 






 






 




















 






 
























 


































 


























 










 












 






















 












 








 


        












        








 




















 














        






 






 






 




















 










 
















 
























 




















 






























 












 






 










 










 












 












 


































 












 
















 












































 


 


















 










 




 








 










 
















 















































