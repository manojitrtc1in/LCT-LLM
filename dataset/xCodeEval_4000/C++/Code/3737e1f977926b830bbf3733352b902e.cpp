
%:pragma GCC           target  ("sse3","sse2","sse")
%:pragma GCC           target  ("avx","sse4","sse4.1","sse4.2","ssse3")
%:pragma GCC           target  ("f16c")
%:pragma GCC         optimize  ("Ofast")
%:pragma GCC         optimize  ("inline","fast-math","unroll-loops","no-stack-protector")
%:pragma GCC diagnostic error  "-fwhole-program"
%:pragma GCC diagnostic error  "-fcse-skip-blocks"
%:pragma GCC diagnostic error  "-funsafe-loop-optimizations"
%:pragma GCC optimize(2)
#pragma comment(linker, "/STACK:102400000,102400000")

#include <functional>
#include  <algorithm>
#include   <iostream>
#include    <cstring>
#include    <cstdlib>
#include     <vector>
#include     <cstdio>
#include     <cctype>
#include     <bitset>
#include      <stack>
#include      <queue>
#include      <cmath>
#include      <ctime>
#include       <list>
#include        <map>
#include        <set>

using namespace std;

#define int          long long
#define pb           push_back
#define sd(n)        scanf("%d",&n)
#define sdd(n,m)     scanf("%d %d",&n,&m)
#define sddd(n,m,k)  scanf("%d %d %d",&n,&m,&k)
#define sld(n)       scanf("%lld",&n)
#define sldd(n,m)    scanf("%lld %lld",&n,&m)
#define slddd(n,m,k) scanf("%lld %lld %lld",&n,&m,&k)
#define sf(n)        scanf("%lf",&n)
#define sff(n,m)     scanf("%lf %lf",&n,&m)
#define sfff(n,m,k)  scanf("%lf %lf %lf",&n,&m,&k)
#define ss(str)      scanf("%s",str)
#define ansn()       printf("%d\n",ans)
#define lansn()      printf("%lld\n",ans)
#define r0(i,n)      for(i=0;i<(n);++i)
#define r1(i,n)      for(i=1;i<=(n);++i)
#define rn(i,n)      for(i=(n);i>=1;--i)
#define mem(a,b)     memset(a,b,sizeof(a))

typedef unsigned long long ULL;
typedef long long LL;
const LL mod = 1e9+7;
const double eps = 1e-9;
const int inf = 0x3f3f3f3f;

const int maxn = 105;
char buffer[maxn],*S,*T;
inline char Get_Char()
{
    if(S==T)
    {
        T=(S=buffer)+fread(buffer,1,maxn,stdin);
        if(S==T) return EOF;
    }
    return *S++;
}

inline int read()
{
    char c;
    int re=0;
    for(c=Get_Char();c<'0'|c>'9';c=Get_Char());
    while(c>='0'&&c<='9')
           re=(re<<1)+(re<<3)+(c-'0'),c=Get_Char();
    return re;
}
const int MAXN = 1e5 + 100;

int mark[MAXN];
struct node{
    int a,b;
    int id;
}a[MAXN],b[MAXN];
bool cmpa(node a,node b){
    if(a.a == b.a) return a.b > b.b;
    return a.a > b.a;
}
bool cmpb(node a,node b){
    if(a.b == b.b) return a.a > b.a;
    return a.b > b.b;
}
vector<int>ve;
signed main(){
    int i,j,k,n,m;
    int _;
    int suma = 0,sumb = 0;
    sld(n);
    for(i = 0;i < n;i++) {
        sld(a[i].a),
        suma += a[i].a,
        b[i].a = a[i].a,
        a[i].id = b[i].id = i;
    }
    for(i = 0;i < n;i++) {
        sld(b[i].b),
        sumb += b[i].b,
        a[i].b = b[i].b;
    }
    sort(a,a+n,cmpa);
    sort(b,b+n,cmpb);
    k = n / 2 + 1;
    int aima = 0,aimb = 0;
    int tt = 0;
    ve.pb(a[0].id);
    mark[a[0].id] = 1;
    for(i = 1;i < n;i+=2){
        if(a[i].b > a[i + 1].b)
            ve.pb(a[i].id),mark[a[i].id] = 1;
        else ve.pb(a[i + 1].id),mark[a[i].id] = 1;
    }
   
    if((n - 1) & 1){
        for(i = 0;i < n;i++){
            if(mark[a[i].id]){
                aima += a[i].a;
                aimb += a[i].b;
            }
        }
        for(i = 0;i < n;i++){
            if(mark[a[i].id] == 0){
                if(aima + a[i].a * 2 > suma && aimb + a[i].b * 2 > sumb){
                    ve.pb(a[i].id);
                    break;
                }
            }
        }
    }
    cout << k << endl;
    for(i = 0;i < ve.size();i++)
        cout << ve[i] + 1 << " " ;
}



