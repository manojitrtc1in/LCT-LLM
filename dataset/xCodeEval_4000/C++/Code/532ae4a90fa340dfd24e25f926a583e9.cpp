   
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
typedef struct{ int sum,suf,pre,max;} Node;
int toint(const string &s) { stringstream ss; ss << s; int x; ss >> x; return x; }
const int MAXN = 2e5+100;
const int UP = 31;


const int mod = 1e9+7;
const ll highest = 1e18;    




const double pi = acos(-1);
const double Phi =  1.618033988749894;
const int logn = 20;
const ll inf = 1e18;
const double root5 = 2.236067977;   
const ll inf64=1e16;


const int ini = -1e9;

int n;
int l[110],r[110],ord[110];
int ans[110];
bool cmp(int &a,int &b){
    return l[a]<l[b];
}
struct Cmp{
    bool operator()(const int &a,const int &b)const{
        return r[a]>r[b];
    }
};
priority_queue<int,std::vector<int>,Cmp> q;
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;++i){
        scanf("%d%d",l+i,r+i);
    }
    for(int i=0;i<n;++i)ord[i] = i;
    sort(ord,ord+n,cmp);
    for(int beg = 0;beg<n;){
        int end = beg + 1;
        while(end<n && l[ord[beg]]==l[ord[end]]){++end;}
        int curt = l[ord[beg]];
        for(int i=beg;i<end;++i){
            q.push(ord[i]);
        }
        while(!q.empty()){
            int v = q.top();
            q.pop();
            ans[v] = curt++;
            while(end<n && l[ord[end]] == curt){
                q.push(ord[end]);
                ++end;
            }
        }
        beg = end;
    }
    for(int i=0;i<n;++i){
        cout<<ans[i]<<" ";
    }
    cout<<"\n";
    return 0;
}






















































































































































































































        












        








 



































        
































































































































































































































































































































































































































































