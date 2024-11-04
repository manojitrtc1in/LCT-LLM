
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





















































































































































const int N = 110;
int n;
char s[4][N];
int main(){
    scanf("%d",&n);
    if(n==1){
        puts("a");
        puts("a");
        puts("b");
        puts("b");
        return 0;
    }else if(n==2){
        puts("aa");
        puts("dd");
        puts("cc");
        puts("bb");
        return 0;
    }
    if(n%2 == 0){        
        for(int i=0;i<n/2;i++){
            s[0][i+i] = s[0][i+i+1] = 'a'+i%2;
            s[3][i+i] = s[3][i+i+1] = 'c'+i%2;
        }
        for(int i=0;i<n/2-1;i++){
            s[1][i+i+2] = s[1][i+i+1] = 'e'+i%2;
            s[2][i+i+2] = s[2][i+i+1] = 'g'+i%2;
        }
        s[1][0] = s[2][0] = 'x';
        s[1][n-1] = s[2][n-1] = 'y';
    }else{
        for(int i=0;i<n/2;i++){
            s[0][i+i] = s[0][i+i+1] = 'a'+i%2;
            s[1][i+i] = s[1][i+i+1] = 'c'+i%2;
            s[2][i+i+2] = s[2][i+i+1] = 'e'+i%2;
            s[3][i+i+2] = s[3][i+i+1] = 'g'+i%2;
        }
        s[2][0] = s[3][0] = 'x';
        s[0][n-1] = s[1][n-1]='y';
    }   
    for(int i=0;i<4;++i){
        puts(s[i]);
    }
    return 0;
}



























































































































































































































        












        








 



































        































































































































































































































































































































































































































































