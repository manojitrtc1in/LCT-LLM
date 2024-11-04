
     
    #pragma comment(linker, "/stack:20000000")
    #pragma GCC optimize("Ofast")
    #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
     
    #define _CRT_SECURE_NO_WARNINGS
    # include <climits>
    # include <iostream>
    # include <cmath>
    # include <algorithm>
    # include <stdio.h>
    # include <cstdint>
    # include <cstring>
    # include <string>
    # include <cstdlib>
    # include <vector>
    # include <bitset>
    # include <map>
    # include <queue>
    # include <ctime>
    # include <stack>
    # include <set>
    # include <list>
    # include <random>
    # include <deque>
    # include <functional>
    # include <iomanip>
    # include <sstream>
    # include <fstream>
    # include <complex>
    # include <numeric>
    # include <immintrin.h>
    # include <cassert>
    # include <array>
    # include <tuple>
    # include <unordered_set> 

    # include <ext/pb_ds/assoc_container.hpp>
    # include <ext/pb_ds/tree_policy.hpp>
    

    using namespace std;
     
    

    # ifdef __GNUC__
    # if __cplusplus > 199711L
    # include <unordered_set>
    # include <unordered_map>
    # else
    # include <tr1/unordered_map>
    # include <tr1/unordered_set>
    using namespace tr1;
    # endif
    # else
    # include <unordered_map>
    # include <unordered_set>
    # endif
 
    

    using namespace __gnu_pbds;
     
    #define fi first
    #define se second
    #define mp make_pair
    #define pb push_back
    #define fbo find_by_order
    #define ook order_of_key
    #define minus minu
    #define lgn 20
    

    

      
    

 
    #define TRACE
    #ifdef TRACE
    #define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
        template <typename Arg1>
        void __f(const char* name, Arg1&& arg1){
            cout << name << " : " << arg1 << std::endl;
            

        }
        template <typename Arg1, typename... Args>
        void __f(const char* names, Arg1&& arg1, Args&&... args){
            const char* comma = strchr(names + 1, ','); cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
        }
    #else
    #define trace(...)
    #endif
 
 
 
    #define VA_NUM_ARGS(...) VA_NUM_ARGS_IMPL_((0,__VA_ARGS__, 6,5,4,3,2,1))
    #define VA_NUM_ARGS_IMPL_(tuple) VA_NUM_ARGS_IMPL tuple
    #define VA_NUM_ARGS_IMPL(_0,_1,_2,_3,_4,_5,_6,N,...) N
    #define macro_dispatcher(macro, ...) macro_dispatcher_(macro, VA_NUM_ARGS(__VA_ARGS__))
    #define macro_dispatcher_(macro, nargs) macro_dispatcher__(macro, nargs)
    #define macro_dispatcher__(macro, nargs) macro_dispatcher___(macro, nargs)
    #define macro_dispatcher___(macro, nargs) macro ## nargs
    #define DBN1(a)           cerr<<#a<<"="<<(a)<<"\n"
    #define DBN2(a,b)         cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<"\n"
    #define DBN3(a,b,c)       cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
    #define DBN4(a,b,c,d)     cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"
    #define DBN5(a,b,c,d,e)   cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<"\n"
    #define DBN6(a,b,c,d,e,f) cerr<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<", "<<#e<<"="<<(e)<<", "<<#f<<"="<<(f)<<"\n"
    #define DBN(...) macro_dispatcher(DBN, __VA_ARGS__)(__VA_ARGS__)
    #define DA(a,n) cerr<<#a<<"=["; printarray(a,n); cerr<<"]\n"
    #define DAR(a,n,s) cerr<<#a<<"["<<s<<"-"<<n-1<<"]=["; printarray(a,n,s); cerr<<"]\n"
     
    #ifdef _MSC_VER
    #define PREFETCH(ptr, rw, level) ((void)0)
    #else
    #define PREFETCH(ptr, rw, level) __builtin_prefetch(ptr, rw, level)
    #endif
     
    #ifdef LOCAL
    #define CURTIME() cerr << clock() * 1.0 / CLOCKS_PER_SEC << endl
    #else
    #define CURTIME()
    #endif
    typedef long long ll;
    typedef unsigned int uint;
    typedef unsigned long long ull;
    typedef double d;
    typedef float f;
    typedef pair<int, int> pii;
    typedef pair<long long, long long> pll;
    typedef vector<int> vi;
    typedef vector<long long> vll;
    typedef int itn;
    typedef long l;
    typedef long double ld; 
 
 
    

    typedef priority_queue<ll, vector<ll> > max_pq;
    

    ll toint(const string &s) {stringstream ss; ss << s; ll x; ss >> x; return x;}
    string tostring ( ll number ){stringstream ss; ss<< number; return ss.str();}
     
    typedef priority_queue<pair < ll , pair < pii , ll > >  , vector<pair < ll , pair < pii , ll > >  > ,greater<pair < ll , pair < pii , ll > >  > > min_pq;
 
    typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> pbds;
    

 
    typedef tree< ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update > OST;
    

    

 
 
 
 
 
    typedef set<ll>::iterator sit;
    typedef map<ll,ll>::iterator mit;
    
    

    template<class T1, class T2, class T3>
    struct triple{ T1 a; T2 b; T3 c; triple() : a(T1()), b(T2()), c(T3()) {}; triple(T1 _a, T2 _b, T3 _c) :a(_a), b(_b), c(_c){} };
    template<class T1, class T2, class T3>
    bool operator<(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a<t2.a;else if(t1.b!=t2.b)return t1.b<t2.b;else return t1.c<t2.c;}
    template<class T1, class T2, class T3>
    bool operator>(const triple<T1,T2,T3>&t1,const triple<T1,T2,T3>&t2){if(t1.a!=t2.a)return t1.a>t2.a;else if(t1.b!=t2.b)return t1.b>t2.b;else return t1.c>t2.c;}
    #define tri triple<int,int,int>
    #define trll triple<ll,ll,ll>
     
     
    

     
    #define FI2(n) for(int i=1;i<=(n);++i)
    #define FJ2(n) for(int j=1;j<=(n);++j)
    #define FK2(n) for(int k=1;k<=(n);++k)
    

    #define FI(n) for(long i=0;i<(n);i++)
    #define FJ(n) for(long long j=0;j<(n);j++)
    #define FK(n) for(int k=0;k<(n);++k)
    #define FL(n) for(int l=0;l<(n);++l)
    #define FQ(n) for(int q=0;q<(n);++q)
    #define FOR(i,a,b) for(int i = (a), __e = (int) (b); i < __e; ++i)
    

    #define revp(i,n) for(i=(n-1);i>=0;i--)
    #define myrep1(i,a,b) for(i=a;i<=b;i++)
    #define myrep2(i,a,b) for(i=b;i>=a;i--)
 
    #define all(a) std::begin(a), std::end(a)
    #define reunique(v) v.resize(std::unique(v.begin(), v.end()) - v.begin())
     
    #define sqr(x) ((x) * (x))
    #define sqrt(x) sqrt(1.0 * (x))
    #define pow(x, n) pow(1.0 * (x), n)
     
    #define COMPARE(obj) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b)
    #define COMPARE_BY(obj, field) [&](const std::decay_t<decltype(obj)>& a, const std::decay_t<decltype(obj)>& b) { return a.field < b.field; }
     
    #define checkbit(n, b) (((n) >> (b)) & 1)
    #define setbit(n, b) ((n) | (static_cast<std::decay_t<decltype(n)>>(1) << (b)))
    #define removebit(n, b) ((n) & ~(static_cast<std::decay_t<decltype(n)>>(1) << (b)))
    #define flipbit(n, b) ((n) ^ (static_cast<std::decay_t<decltype(n)>>(1) << (b)))
  
     
     
    

     
     
    const int mod = 1e9 + 7 ;
    ll powmod(ll a,ll b) {ll res=1;if(a>=mod)a%=mod;for(;b;b>>=1){if(b&1)res=res*a;if(res>=mod)res%=mod;a=a*a;if(a>=mod)a%=mod;}return res;}
    ll gcd(ll a , ll b){return a==0?b:gcd(b%a,a);}
    

     
     int some_primes[7] = {24443, 100271, 1000003, 1000333, 5000321, 98765431, 1000000123};
     
     
     
     
    #define T9          1000000000
    #define T18         1000000000000000000LL
    #define INF         1011111111
    #define LLINF       1000111000111000111LL
     
    #define EPS         (double)1e-10
    #define PI          3.14159265358979323846264
    #define link        asaxlajrewqwe
    #define rank        wahayawehasdakw
    

    #define mod %
    #define NUM  1000000007
    #define NUM1 1000000009
    

    #define s(n) scanf("%d", &n)
    #define sl(n) scanf("%ld", &n)
    #define sl3(n1,n2,n3) scanf("%lld %lld %lld ", &n1, &n2, &n3)
    #define sl4(n1,n2,n3,n4) scanf("%ld %ld %ld %ld", &n1, &n2, &n3, &n4)
    #define sll(n) scanf("%I64d", &n)
    #define sll2(n) scanf("%lld", &n)
    

    #define p(n) printf("%d\n", n)
    #define pl(n) printf("%ld\n",n)
    #define pl3(n1,n2,n3) printf("%lld %lld %lld\n ", n1, n2, n3)
    #define pl4(n1,n2,n3,n4) printf("%ld %ld %ld %ld\n ", n1, n2, n3, n4)
    #define pll(n) printf("%I64d\n",n)
    #define pll2(n) printf("%lld\n",n)
    

    #define ct1(n1) cout<<n1<<"\n"
    #define ct2(n1,n2) cout<<n1<<" "<<n2<<"\n"
    #define ct3(n1,n2,n3) cout<<n1<<"\n"<<n2<<"\n"<<n3<<"\n"
    #define ct4(n1,n2,n3,n4) cout<<n1<<"\n"<<n2<<"\n"<<n3<<"\n"<<n4<<"\n"
    #define ci1(n1) cin>>n1
    #define ci2(n1,n2) cin>>n1>>n2
    #define ci3(n1,n2,n3) cin>>n1>>n2>>n3
    #define ci4(n1,n2,n3,n4) cin>>n1>>n2>>n3>>n4
    
     


    int32_t solve();   
    

    

    

    

 
    int isPowerOfTwo(unsigned n)
    {  return n && (! (n & (n-1)) ); }

    

    
    

    

    ll expower(ll x, ll y, ll m)
    {
    if (y == 0)
        return 1;
    ll p = expower(x, y/2, m) % m;
    p = (p * p) % m;
 
    return (y%2 == 0)? p : (x * p) % m;
    }
    

    
    
ll mypower(ll x,ll y)
{
    ll res = 1;      

 
    

                


    while (y > 0)
    {
        

        if (y & 1)
            

 res=res*x;
        

        y = y>>1; 

        

        x*=x;
    }
    return res;
}
 ll mypower2(ll x,ll y, ll p)
{
    ll res = 1;      

 
    x = x % p;  

                


    while (y > 0)
    {
        

        if (y & 1)
            res = (res*x) % p;
        

        y = y>>1; 

        x = (x*x) % p; 
    }
    return res;
}
 
    
    
     


ll mymod(string num, ll a)
{
    

    ll res = 0;
 
    

    for (ll i = 0; i < num.length(); i++)
         res = (res*10 + (ll)num[i] - '0') %a;
 
    return res;
}
    
    
    
















 






 












    




 


















 


























 














    














 










 
















    






































    
    






 
 
    int32_t main(int argc, char** argv) {
       
    ios_base::sync_with_stdio(0);cin.tie(0);
    #ifdef LOCAL
              FREIN("input.txt");
              

    #endif
 
    

 
    

    

    

    

 
 
        return solve();
    }
    int32_t solve(){
        int t,n,i,j;
        ci1(t);
        while(t--){
           ci1(n);i=0;
           int seconds=0;
           int l[n+1],r[n+1];
           list<int> myl,lo;
           FI2(n){
                               
               ci2(l[i],r[i]);
           }
           int counter=0;
           int v[n+1];
           memset(v,-1,sizeof(v));
        

           bool flag[n+1];memset(flag,false,sizeof(flag));
           seconds++;

           int start=0;
           
           while(1){
           for (i = 1; i <= n; i++) {
               
                if(seconds==l[i]){
                    myl.pb(i);    
                }      
                else if(l[i]>seconds )break;
           
           }
           
           std::list<int>:: iterator lit=myl.begin(),mit=lit;
           
           for (; lit != myl.end(); lit++) {
               
               if(lit==mit){
                   v[*lit]=seconds;lo.pb(seconds );lit=myl.erase(lit);lit--;
               }
               else {
                   if(r[*lit]==seconds){
                       v[*lit]=0;lo.pb(0);
                       lit=myl.erase(lit);lit--;
                   }
               }
           }
           
           
          if(lo.size()==n) break; 
           
           seconds++;
           }
           
        

                
        

        

                
        

                    
        

        

        

        

        

        

                
        

        

        

        

        

        

        

            

            

            

            

            

            

            

                    
                    
                    
                    
            

            

            

            

            

            

        

        

         
         for (i = 1; i <= n; i++) {
             
             cout<<v[i]<<" ";
         }
         cout<<"\n";
         
            

        }
            
            
            
            
            
            
               
        return 0;
    }