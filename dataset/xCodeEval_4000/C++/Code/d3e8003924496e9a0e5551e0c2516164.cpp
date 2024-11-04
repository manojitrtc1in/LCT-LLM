
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


#define isset(x,i) (x>>i)&1
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
#define inrange(x,y,n,m) ((x>=1 && y>=1 && x<=n && y<=m))
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
const double Phi =  1.618033988749894;
const int logn = 20;
const double root5 = 2.236067977;   



















































































































































const int N = 3e6+100;
int child[N][2],val[N];
int q,sz = 1;






string op;
void _insert(int x){
	int pos = 0;  
    for (int i=29; i>=0; --i){  
        int id = (x>>i)&1;  
        if (!child[pos][id])  
            child[pos][id] = sz++;  
        pos = child[pos][id];  
        ++val[pos];  
    }  
}
void _delete(int x){
	int pos = 0;  
    for (int i=29; i>=0; --i){  
        int id = (x>>i)&1;  
        pos = child[pos][id];  
        --val[pos];  
    }  
}
int qry(int x){
	int ans = 0,pos = 0;
	for(int i=29;i>=0;--i){
		int id = (x>>i)&1;
		if(id==1){
			if (child[pos][0] && val[child[pos][0]])
			{	
				pos = child[pos][0];
			}else{
				pos = child[pos][1];
				ans |= (1<<i);
			}
		}else{
			if(child[pos][1] && val[child[pos][1]]){
				pos = child[pos][1];
				ans |= (1<<i);
			}else{
				pos = child[pos][0];
			}
		}
	}
	return ans^x;
}
int main(){
	scanf("%d",&q);
	int num;
	_insert(0);
	while(q--){
		cin>>op>>num;
		if(op=="+"){
			_insert(num);
		}else if(op=="-"){
			_delete(num);
		}else{
			cout<<(qry(num))<<"\n";
		}
	}
	return 0;
}



























































































































































































































        












        








 



































        































































































































































































































































































































































































































































