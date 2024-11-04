#include <stdio.h>
#include <math.h>

#define cst 1000000007
#define nor_rad(x) ( ( M_PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

const ll mod = 1e9 + 7;
const ld error = 2e-6;
const ld PI = acosl(-1); 

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))

inline ll MOD(ll x, ll m = mod){
    ll y = x % m;
    return (y >= 0) ? y: y+m;
}

const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;

int main()
{
    ll n,p;
    scanf("%lld %lld", &n, &p);
    if(p==0){
        printf("%d\n", __builtin_popcountll(n));
        return 0;
    }
    if(p>0){
        ll i;
        for(i=1;i<=35;i++){
            n-=p;
            if(n<0){
                printf("-1\n");
                return 0;
            }
            if( __builtin_popcountll(n)<=i && __builtin_popcountll(n)!=0 ){
                if( __builtin_popcountll(n) ==1 && i> log(n)/log(2)+1 ){
                    printf("-1\n");
                    return 0;
                }
                printf("%lld\n", i);
                return 0;
            }
        }
        printf("-1\n");
        return 0;
    }
    if(p<0){
        ll i;
        for(i=1;i<=35;i++){
            n+=-p;
            if(n<0){
                continue;
            }
            if( __builtin_popcountll(n)<=i && __builtin_popcountll(n)!=0  ){
                if(  __builtin_popcountll(n) ==1 && i> log(n)/log(2)+1 ){
                    printf("-1\n");
                    return 0;
                }
                printf("%lld\n", i);
                return 0;
            }
        }
        printf("-1\n");
        return 0;
    }
    return 0;
}
