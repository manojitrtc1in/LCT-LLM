   
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




const double pi = acos(-1);
const double Phi =  1.618033988749894;
const int logn = 20;
const double root5 = 2.236067977;   
const ll inf=1e16;
const int mod = 1e9+7;
const int ini = -1e9;

int n,m;
char s[1010];
string board[1010];
int sum[1010][1010];
int k;
string ds = "NSEW";
int dx[] = {-1,1,0,0},dy[] = {0,0,1,-1};
int dir[100010],len[100010];
bool chk(int x1,int y1,int x2,int y2){
    if(!inrange(x1,y1,n,m) || !inrange(x2,y2,n,m))return false;
    if(x1>x2)swap(x1,x2);
    if(y1>y2)swap(y1,y2);
    x2++,y2++;
    return (sum[x1][y1] + sum[x2][y2] == sum[x1][y2] + sum[x2][y1]); 
}
bool func(int x,int y){
    int x2,y2;
    int i;
    for(i=0;i<k;++i){
        x2 = x + len[i]*dx[dir[i]];
        y2 = y + len[i]*dy[dir[i]];
        if(!chk(x,y,x2,y2))return false;
        x = x2,y = y2;
    }
    return 1;
}   
int main(){ 
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;++i){
        scanf("%s",s);
        board[i] = s;
    }
    scanf("%d",&k);
    for(int i=0;i<k;++i){
        scanf("%s",s);
        int j=0;
        for(;j<4;++j){
            if(ds[j]==s[0])break;
        }
        dir[i] = j;
        scanf("%d",&len[i]);
    }
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            sum[i+1][j+1] = sum[i+1][j] + sum[i][j+1] - sum[i][j] + ((board[i][j]=='#'?1:0));
        }
    }
    string ans;
    for(int i=0;i<n;++i){
        for(int j=0;j<m;++j){
            if(board[i][j]>='A' && board[i][j]<='Z'){
                char ch = board[i][j];
                if(func(i,j))ans += ch;
            }
        }
    }
    if(ans.empty()){
        cout<<"no solution\n";
    }else{
        sort(ans.begin(),ans.end());
        cout<<ans<<"\n";
    }
    return 0;
}






















































































































































































































        












        








 



































        
































































































































































































































































































































































































































































