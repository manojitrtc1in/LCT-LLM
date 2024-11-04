
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
const int mod = 1e9+7;  
const int ini = -1e9;

const int N = 1e5+10;
struct player{
    string name;
    int a;
};
inline bool operator<(const player& p1, const player& p2)
{
    if (p1.a != p2.a) return p1.a > p2.a;
    return p1.name < p2.name;
}
int n,m;player p[N];
int b[N];player vasya;
int solve1(){
    int score = vasya.a + b[n-1];
    int cur = n-2;
    int bad = 0;
    for(int i=n-2;i>=0;--i){
        while(cur>=0 && (p[i].a + b[cur]>score || (p[i].a + b[cur]==score && p[i].name<vasya.name)))cur--;
        if(cur<0)break;
        cur--;
        bad++;
    }
    return (n-bad);
}   
int solve2(){
    int score = vasya.a + b[0];
    int cur = 1;
    int good = 0;
    for(int i=0;i<n;++i){
        while(cur<n && (p[i].a + b[cur]<score ||(p[i].a + b[cur]==score && p[i].name>vasya.name)))cur++;
        if(cur==n)break;
        cur++;
        good++;
    }
    return (good+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        char tmp[50];
        scanf("%s%d",&tmp,&p[i].a);
        p[i].name = tmp;
    }      
    scanf("%d",&m);
    for(int i=0;i<m;++i){
        scanf("%d",&b[i]);
    }
    for(int i=m;i<n;++i){
        b[i] = 0;
    }
    sort(b,b+n);
    cin>>vasya.name;
    for(int i=0;i<n;++i){
        if(p[i].name == vasya.name){
            vasya.a = p[i].a;
            for(int j=i+1;j<n;++j){
                p[j-1] = p[j];
            }break;
        }
    }
    sort(p,p+n-1);
    cout<<solve1()<<" "<<solve2()<<"\n";
    return 0;
}






















































































































































































































        












        








 



































        
































































































































































































































































































































































































































































    