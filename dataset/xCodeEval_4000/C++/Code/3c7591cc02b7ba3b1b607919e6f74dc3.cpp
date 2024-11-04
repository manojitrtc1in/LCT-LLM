 





  






#include "bits/stdc++.h"


#define pb(x) push_back(x)
#define XX first
#define YY second
#define cst 1000000007
#define nor_rad(x) ( ( PI*x )/180)
#define rad_nor(x)  ( (x/IP)*180 )
#define all(x) x.begin(),x.end()
#define mem(x,y) memset(x,y,sizeof(x));
#define eps 1e-9
#define rev reverse
#define READ(f) freopen(f, "r", stdin)
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;


const ll mod = 1e9+7;
const ll mod2= 998244353;
const ll n_mod= 4294967296;
const ld error = 2e-6;
const ld PI = acosl(-1); 


#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL); cout.tie(NULL);
#define eq(x, y) (fabs((x)-(y))<error)
#define bt(i) (1LL<<(i))













inline ll MOD(ll x, ll m = mod){
    ll y = x % m; 

    return (y >= 0) ? y: y+m;
}


const int inf = 1e9;
const ll infl = 1061109567;
const int nmax = 1000+10;
#define pii pair<int,int>
#define vii vector<int>
#define pLL pair<ll,ll>
#define vLL vector<ll>




















ll bigmod(ll a, ll b){
    if(b==0) return 1;
    ll x= bigmod(a,b/2);
    x= x*x;
    if(b%2==1) x*=a;
    return x;
}



void solve(){




}




int main()
{

   
  

    int n; cin>>n; int lo=1, hi=n, mid;
    int car1,car2,car3; int left= -1, right=-1;
   cout<<"? "<<1<<" "<<n<<"\n"; fflush(stdout);  cin>>car1;
   if(car1==1){ left=1;  }
   else{
   cout<<"? "<<1<<" "<<car1<<"\n"; fflush(stdout);  cin>>car2; 
   if(car1==car2){ right=car1; }
   else left=car1; 
}
    int ans;

    if(left==-1){
        lo=1; hi= right;
        ans=1;
        while(hi-lo>1){
            mid= (lo+hi)/2;
           

            if(right-mid==0) break;
            cout<<"? "<<mid<<" "<<right<<"\n"; fflush(stdout);  cin>>car3;
            if(car3==car1){ ans= mid;  lo= mid; }
            else hi= mid;
        }
    }

    else{
        lo= left; hi=n; ans=n;
        while(hi-lo>1){
            mid= (lo+hi)/2;
           

            if(mid-left==0){ break; }
            cout<<"? "<<left<<" "<<mid<<"\n"; fflush(stdout);  cin>>car3;
            if(car3==car1){ ans= mid; hi=mid; }
            else lo= mid; 
        }

    }






    cout<<"! "<<ans<<endl; fflush(stdout);
    










}


















































